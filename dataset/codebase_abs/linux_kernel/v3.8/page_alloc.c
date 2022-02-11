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
if ( F_7 ( F_28 ( V_5 ) != V_27 ) ) {
F_17 ( V_5 ) ;
V_32 ++ ;
}
F_36 ( V_5 ) ;
for ( V_28 = 1 ; V_28 < V_29 ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
if ( F_7 ( ! F_37 ( V_30 ) || ( V_30 -> V_31 != V_5 ) ) ) {
F_17 ( V_5 ) ;
V_32 ++ ;
}
F_38 ( V_30 ) ;
}
return V_32 ;
}
static inline void F_39 ( struct V_5 * V_5 , int V_27 , T_1 V_33 )
{
int V_28 ;
F_40 ( ( V_33 & V_34 ) && F_41 () ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_42 ( V_5 + V_28 ) ;
}
static int T_2 F_43 ( char * V_35 )
{
unsigned long V_36 ;
if ( F_44 ( V_35 , 10 , & V_36 ) < 0 || V_36 > V_37 / 2 ) {
F_21 ( V_38 L_3 ) ;
return 0 ;
}
V_39 = V_36 ;
F_21 ( V_40 L_4 , V_36 ) ;
return 0 ;
}
static inline void F_45 ( struct V_5 * V_5 )
{
F_46 ( V_41 , & V_5 -> V_42 ) ;
}
static inline void F_47 ( struct V_5 * V_5 )
{
F_48 ( V_41 , & V_5 -> V_42 ) ;
}
static inline void F_45 ( struct V_5 * V_5 ) { }
static inline void F_47 ( struct V_5 * V_5 ) { }
static inline void F_49 ( struct V_5 * V_5 , int V_27 )
{
F_50 ( V_5 , V_27 ) ;
F_51 ( V_5 ) ;
}
static inline void F_52 ( struct V_5 * V_5 )
{
F_53 ( V_5 ) ;
F_50 ( V_5 , 0 ) ;
}
static inline unsigned long
F_54 ( unsigned long V_43 , unsigned int V_27 )
{
return V_43 ^ ( 1 << V_27 ) ;
}
static inline int F_55 ( struct V_5 * V_5 , struct V_5 * V_44 ,
int V_27 )
{
if ( ! F_14 ( F_10 ( V_44 ) ) )
return 0 ;
if ( F_56 ( V_5 ) != F_56 ( V_44 ) )
return 0 ;
if ( F_57 ( V_44 ) && F_58 ( V_44 ) == V_27 ) {
F_40 ( F_59 ( V_44 ) != 0 ) ;
return 1 ;
}
if ( F_60 ( V_44 ) && F_58 ( V_44 ) == V_27 ) {
F_40 ( F_59 ( V_44 ) != 0 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_61 ( struct V_5 * V_5 ,
struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned long V_43 ;
unsigned long V_45 ;
unsigned long V_46 ( V_47 ) ;
struct V_5 * V_44 ;
if ( F_7 ( F_62 ( V_5 ) ) )
if ( F_7 ( F_35 ( V_5 , V_27 ) ) )
return;
F_40 ( V_6 == - 1 ) ;
V_43 = F_10 ( V_5 ) & ( ( 1 << V_37 ) - 1 ) ;
F_40 ( V_43 & ( ( 1 << V_27 ) - 1 ) ) ;
F_40 ( F_16 ( V_11 , V_5 ) ) ;
while ( V_27 < V_37 - 1 ) {
V_47 = F_54 ( V_43 , V_27 ) ;
V_44 = V_5 + ( V_47 - V_43 ) ;
if ( ! F_55 ( V_5 , V_44 , V_27 ) )
break;
if ( F_57 ( V_44 ) ) {
F_47 ( V_44 ) ;
F_50 ( V_5 , 0 ) ;
F_63 ( V_11 , 1 << V_27 ,
V_6 ) ;
} else {
F_64 ( & V_44 -> V_48 ) ;
V_11 -> V_49 [ V_27 ] . V_50 -- ;
F_52 ( V_44 ) ;
}
V_45 = V_47 & V_43 ;
V_5 = V_5 + ( V_45 - V_43 ) ;
V_43 = V_45 ;
V_27 ++ ;
}
F_49 ( V_5 , V_27 ) ;
if ( ( V_27 < V_37 - 2 ) && F_14 ( F_10 ( V_44 ) ) ) {
struct V_5 * V_51 , * V_52 ;
V_45 = V_47 & V_43 ;
V_51 = V_5 + ( V_45 - V_43 ) ;
V_47 = F_54 ( V_45 , V_27 + 1 ) ;
V_52 = V_51 + ( V_47 - V_45 ) ;
if ( F_55 ( V_51 , V_52 , V_27 + 1 ) ) {
F_65 ( & V_5 -> V_48 ,
& V_11 -> V_49 [ V_27 ] . V_53 [ V_6 ] ) ;
goto V_21;
}
}
F_66 ( & V_5 -> V_48 , & V_11 -> V_49 [ V_27 ] . V_53 [ V_6 ] ) ;
V_21:
V_11 -> V_49 [ V_27 ] . V_50 ++ ;
}
static inline int F_67 ( struct V_5 * V_5 )
{
if ( F_7 ( F_68 ( V_5 ) |
( V_5 -> V_54 != NULL ) |
( F_69 ( & V_5 -> V_55 ) != 0 ) |
( V_5 -> V_56 & V_57 ) |
( F_70 ( V_5 ) ) ) ) {
F_17 ( V_5 ) ;
return 1 ;
}
F_71 ( V_5 ) ;
if ( V_5 -> V_56 & V_58 )
V_5 -> V_56 &= ~ V_58 ;
return 0 ;
}
static void F_72 ( struct V_11 * V_11 , int V_59 ,
struct V_60 * V_61 )
{
int V_6 = 0 ;
int V_62 = 0 ;
int V_63 = V_59 ;
F_73 ( & V_11 -> V_64 ) ;
V_11 -> V_65 = 0 ;
V_11 -> V_66 = 0 ;
while ( V_63 ) {
struct V_5 * V_5 ;
struct V_67 * V_68 ;
do {
V_62 ++ ;
if ( ++ V_6 == V_69 )
V_6 = 0 ;
V_68 = & V_61 -> V_70 [ V_6 ] ;
} while ( F_74 ( V_68 ) );
if ( V_62 == V_69 )
V_62 = V_63 ;
do {
int V_71 ;
V_5 = F_75 ( V_68 -> V_72 , struct V_5 , V_48 ) ;
F_64 ( & V_5 -> V_48 ) ;
V_71 = F_76 ( V_5 ) ;
F_61 ( V_5 , V_11 , 0 , V_71 ) ;
F_77 ( V_5 , 0 , V_71 ) ;
if ( F_78 ( F_79 ( V_5 ) != V_73 ) ) {
F_80 ( V_11 , V_74 , 1 ) ;
if ( F_81 ( V_71 ) )
F_80 ( V_11 , V_75 , 1 ) ;
}
} while ( -- V_63 && -- V_62 && ! F_74 ( V_68 ) );
}
F_82 ( & V_11 -> V_64 ) ;
}
static void F_83 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_27 ,
int V_6 )
{
F_73 ( & V_11 -> V_64 ) ;
V_11 -> V_65 = 0 ;
V_11 -> V_66 = 0 ;
F_61 ( V_5 , V_11 , V_27 , V_6 ) ;
if ( F_7 ( V_6 != V_73 ) )
F_63 ( V_11 , 1 << V_27 , V_6 ) ;
F_82 ( & V_11 -> V_64 ) ;
}
static bool F_84 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
int V_32 = 0 ;
F_85 ( V_5 , V_27 ) ;
F_86 ( V_5 , V_27 ) ;
if ( F_87 ( V_5 ) )
V_5 -> V_54 = NULL ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
V_32 += F_67 ( V_5 + V_28 ) ;
if ( V_32 )
return false ;
if ( ! F_88 ( V_5 ) ) {
F_89 ( F_90 ( V_5 ) , V_76 << V_27 ) ;
F_91 ( F_90 ( V_5 ) ,
V_76 << V_27 ) ;
}
F_92 ( V_5 , V_27 ) ;
F_93 ( V_5 , 1 << V_27 , 0 ) ;
return true ;
}
static void F_27 ( struct V_5 * V_5 , unsigned int V_27 )
{
unsigned long V_56 ;
int V_6 ;
if ( ! F_84 ( V_5 , V_27 ) )
return;
F_94 ( V_56 ) ;
F_95 ( V_77 , 1 << V_27 ) ;
V_6 = F_79 ( V_5 ) ;
F_96 ( V_5 , V_6 ) ;
F_83 ( F_15 ( V_5 ) , V_5 , V_27 , V_6 ) ;
F_97 ( V_56 ) ;
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
F_15 ( V_5 ) -> V_79 += 1 << V_27 ;
F_101 ( V_5 ) ;
F_102 ( V_5 , V_27 ) ;
}
void T_2 F_103 ( struct V_5 * V_5 )
{
unsigned V_28 = V_80 ;
struct V_5 * V_30 = V_5 ;
do {
F_100 ( V_30 ) ;
F_34 ( V_30 , 0 ) ;
} while ( ++ V_30 , -- V_28 );
F_101 ( V_5 ) ;
F_6 ( V_5 , V_81 ) ;
F_102 ( V_5 , V_82 ) ;
V_83 += V_80 ;
#ifdef F_104
if ( F_88 ( V_5 ) )
V_84 += V_80 ;
#endif
}
static inline void F_105 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_85 , int V_86 , struct V_49 * V_87 ,
int V_6 )
{
unsigned long V_88 = 1 << V_86 ;
while ( V_86 > V_85 ) {
V_87 -- ;
V_86 -- ;
V_88 >>= 1 ;
F_40 ( F_16 ( V_11 , & V_5 [ V_88 ] ) ) ;
#ifdef F_106
if ( V_86 < F_107 () ) {
F_108 ( & V_5 [ V_88 ] . V_48 ) ;
F_45 ( & V_5 [ V_88 ] ) ;
F_50 ( & V_5 [ V_88 ] , V_86 ) ;
F_63 ( V_11 , - ( 1 << V_86 ) ,
V_6 ) ;
continue;
}
#endif
F_66 ( & V_5 [ V_88 ] . V_48 , & V_87 -> V_53 [ V_6 ] ) ;
V_87 -> V_50 ++ ;
F_49 ( & V_5 [ V_88 ] , V_86 ) ;
}
}
static inline int F_109 ( struct V_5 * V_5 )
{
if ( F_7 ( F_68 ( V_5 ) |
( V_5 -> V_54 != NULL ) |
( F_69 ( & V_5 -> V_55 ) != 0 ) |
( V_5 -> V_56 & V_58 ) |
( F_70 ( V_5 ) ) ) ) {
F_17 ( V_5 ) ;
return 1 ;
}
return 0 ;
}
static int F_110 ( struct V_5 * V_5 , int V_27 , T_1 V_33 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
if ( F_7 ( F_109 ( V_30 ) ) )
return 1 ;
}
F_50 ( V_5 , 0 ) ;
F_101 ( V_5 ) ;
F_111 ( V_5 , V_27 ) ;
F_93 ( V_5 , 1 << V_27 , 1 ) ;
if ( V_33 & V_89 )
F_39 ( V_5 , V_27 , V_33 ) ;
if ( V_27 && ( V_33 & V_90 ) )
F_29 ( V_5 , V_27 ) ;
return 0 ;
}
static inline
struct V_5 * F_112 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned int V_91 ;
struct V_49 * V_87 ;
struct V_5 * V_5 ;
for ( V_91 = V_27 ; V_91 < V_37 ; ++ V_91 ) {
V_87 = & ( V_11 -> V_49 [ V_91 ] ) ;
if ( F_74 ( & V_87 -> V_53 [ V_6 ] ) )
continue;
V_5 = F_75 ( V_87 -> V_53 [ V_6 ] . V_92 ,
struct V_5 , V_48 ) ;
F_64 ( & V_5 -> V_48 ) ;
F_52 ( V_5 ) ;
V_87 -> V_50 -- ;
F_105 ( V_11 , V_5 , V_27 , V_91 , V_87 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_113 ( struct V_11 * V_11 ,
struct V_5 * V_93 , struct V_5 * V_94 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_27 ;
int V_95 = 0 ;
#ifndef F_114
F_115 ( F_15 ( V_93 ) != F_15 ( V_94 ) ) ;
#endif
for ( V_5 = V_93 ; V_5 <= V_94 ; ) {
F_40 ( F_116 ( V_5 ) != F_117 ( V_11 ) ) ;
if ( ! F_14 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_60 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_27 = F_58 ( V_5 ) ;
F_118 ( & V_5 -> V_48 ,
& V_11 -> V_49 [ V_27 ] . V_53 [ V_6 ] ) ;
F_96 ( V_5 , V_6 ) ;
V_5 += 1 << V_27 ;
V_95 += 1 << V_27 ;
}
return V_95 ;
}
int F_119 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_96 , V_97 ;
struct V_5 * V_93 , * V_94 ;
V_96 = F_10 ( V_5 ) ;
V_96 = V_96 & ~ ( V_80 - 1 ) ;
V_93 = F_120 ( V_96 ) ;
V_94 = V_93 + V_80 - 1 ;
V_97 = V_96 + V_80 - 1 ;
if ( V_96 < V_11 -> V_15 )
V_93 = V_5 ;
if ( V_97 >= V_11 -> V_15 + V_11 -> V_16 )
return 0 ;
return F_113 ( V_11 , V_93 , V_94 , V_6 ) ;
}
static void F_121 ( struct V_5 * V_98 ,
int V_99 , int V_6 )
{
int V_100 = 1 << ( V_99 - V_82 ) ;
while ( V_100 -- ) {
F_6 ( V_98 , V_6 ) ;
V_98 += V_80 ;
}
}
static inline struct V_5 *
F_122 ( struct V_11 * V_11 , int V_27 , int V_101 )
{
struct V_49 * V_87 ;
int V_91 ;
struct V_5 * V_5 ;
int V_6 , V_28 ;
for ( V_91 = V_37 - 1 ; V_91 >= V_27 ;
-- V_91 ) {
for ( V_28 = 0 ; ; V_28 ++ ) {
V_6 = V_102 [ V_101 ] [ V_28 ] ;
if ( V_6 == V_103 )
break;
V_87 = & ( V_11 -> V_49 [ V_91 ] ) ;
if ( F_74 ( & V_87 -> V_53 [ V_6 ] ) )
continue;
V_5 = F_75 ( V_87 -> V_53 [ V_6 ] . V_92 ,
struct V_5 , V_48 ) ;
V_87 -> V_50 -- ;
if ( ! F_81 ( V_6 ) &&
( F_7 ( V_91 >= V_82 / 2 ) ||
V_101 == V_104 ||
V_7 ) ) {
int V_105 ;
V_105 = F_119 ( V_11 , V_5 ,
V_101 ) ;
if ( V_105 >= ( 1 << ( V_82 - 1 ) ) ||
V_7 )
F_6 ( V_5 ,
V_101 ) ;
V_6 = V_101 ;
}
F_64 ( & V_5 -> V_48 ) ;
F_52 ( V_5 ) ;
if ( V_91 >= V_82 &&
! F_81 ( V_6 ) )
F_121 ( V_5 , V_91 ,
V_101 ) ;
F_105 ( V_11 , V_5 , V_27 , V_91 , V_87 ,
F_81 ( V_6 )
? V_6 : V_101 ) ;
F_123 ( V_5 , V_27 , V_91 ,
V_101 , V_6 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_124 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
struct V_5 * V_5 ;
V_106:
V_5 = F_112 ( V_11 , V_27 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_103 ) {
V_5 = F_122 ( V_11 , V_27 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_103 ;
goto V_106;
}
}
F_125 ( V_5 , V_27 , V_6 ) ;
return V_5 ;
}
static int F_126 ( struct V_11 * V_11 , unsigned int V_27 ,
unsigned long V_59 , struct V_67 * V_68 ,
int V_6 , int V_107 )
{
int V_71 = V_6 , V_28 ;
F_73 ( & V_11 -> V_64 ) ;
for ( V_28 = 0 ; V_28 < V_59 ; ++ V_28 ) {
struct V_5 * V_5 = F_124 ( V_11 , V_27 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_78 ( V_107 == 0 ) )
F_66 ( & V_5 -> V_48 , V_68 ) ;
else
F_65 ( & V_5 -> V_48 , V_68 ) ;
if ( F_127 ( V_108 ) ) {
V_71 = F_79 ( V_5 ) ;
if ( ! F_81 ( V_71 ) && V_71 != V_73 )
V_71 = V_6 ;
}
F_96 ( V_5 , V_71 ) ;
V_68 = & V_5 -> V_48 ;
if ( F_81 ( V_71 ) )
F_80 ( V_11 , V_75 ,
- ( 1 << V_27 ) ) ;
}
F_80 ( V_11 , V_74 , - ( V_28 << V_27 ) ) ;
F_82 ( & V_11 -> V_64 ) ;
return V_28 ;
}
void F_128 ( struct V_11 * V_11 , struct V_60 * V_61 )
{
unsigned long V_56 ;
int V_109 ;
F_94 ( V_56 ) ;
if ( V_61 -> V_59 >= V_61 -> V_110 )
V_109 = V_61 -> V_110 ;
else
V_109 = V_61 -> V_59 ;
if ( V_109 > 0 ) {
F_72 ( V_11 , V_109 , V_61 ) ;
V_61 -> V_59 -= V_109 ;
}
F_97 ( V_56 ) ;
}
static void F_129 ( unsigned int V_111 )
{
unsigned long V_56 ;
struct V_11 * V_11 ;
F_130 (zone) {
struct V_112 * V_113 ;
struct V_60 * V_61 ;
F_94 ( V_56 ) ;
V_113 = F_131 ( V_11 -> V_114 , V_111 ) ;
V_61 = & V_113 -> V_61 ;
if ( V_61 -> V_59 ) {
F_72 ( V_11 , V_61 -> V_59 , V_61 ) ;
V_61 -> V_59 = 0 ;
}
F_97 ( V_56 ) ;
}
}
void F_132 ( void * V_115 )
{
F_129 ( F_133 () ) ;
}
void F_134 ( void )
{
int V_111 ;
struct V_112 * V_61 ;
struct V_11 * V_11 ;
static T_4 V_116 ;
F_135 (cpu) {
bool V_117 = false ;
F_130 (zone) {
V_61 = F_131 ( V_11 -> V_114 , V_111 ) ;
if ( V_61 -> V_61 . V_59 ) {
V_117 = true ;
break;
}
}
if ( V_117 )
F_136 ( V_111 , & V_116 ) ;
else
F_137 ( V_111 , & V_116 ) ;
}
F_138 ( & V_116 , F_132 , NULL , 1 ) ;
}
void F_139 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_118 ;
unsigned long V_56 ;
int V_27 , V_119 ;
struct V_67 * V_120 ;
if ( ! V_11 -> V_16 )
return;
F_140 ( & V_11 -> V_64 , V_56 ) ;
V_118 = V_11 -> V_15 + V_11 -> V_16 ;
for ( V_14 = V_11 -> V_15 ; V_14 < V_118 ; V_14 ++ )
if ( F_141 ( V_14 ) ) {
struct V_5 * V_5 = F_120 ( V_14 ) ;
if ( ! F_142 ( V_5 ) )
F_143 ( V_5 ) ;
}
F_144 (order, t) {
F_145 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_28 ;
V_14 = F_10 ( F_75 ( V_120 , struct V_5 , V_48 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1UL << V_27 ) ; V_28 ++ )
F_146 ( F_120 ( V_14 + V_28 ) ) ;
}
}
F_147 ( & V_11 -> V_64 , V_56 ) ;
}
void F_148 ( struct V_5 * V_5 , int V_107 )
{
struct V_11 * V_11 = F_15 ( V_5 ) ;
struct V_60 * V_61 ;
unsigned long V_56 ;
int V_6 ;
if ( ! F_84 ( V_5 , 0 ) )
return;
V_6 = F_79 ( V_5 ) ;
F_96 ( V_5 , V_6 ) ;
F_94 ( V_56 ) ;
F_149 ( V_77 ) ;
if ( V_6 >= V_69 ) {
if ( F_7 ( V_6 == V_73 ) ) {
F_83 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_21;
}
V_6 = V_121 ;
}
V_61 = & F_150 ( V_11 -> V_114 ) -> V_61 ;
if ( V_107 )
F_65 ( & V_5 -> V_48 , & V_61 -> V_70 [ V_6 ] ) ;
else
F_66 ( & V_5 -> V_48 , & V_61 -> V_70 [ V_6 ] ) ;
V_61 -> V_59 ++ ;
if ( V_61 -> V_59 >= V_61 -> V_86 ) {
F_72 ( V_11 , V_61 -> V_110 , V_61 ) ;
V_61 -> V_59 -= V_61 -> V_110 ;
}
V_21:
F_97 ( V_56 ) ;
}
void F_151 ( struct V_67 * V_68 , int V_107 )
{
struct V_5 * V_5 , * V_92 ;
F_152 (page, next, list, lru) {
F_153 ( V_5 , V_107 ) ;
F_148 ( V_5 , V_107 ) ;
}
}
void F_154 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
F_40 ( F_62 ( V_5 ) ) ;
F_40 ( ! F_59 ( V_5 ) ) ;
#ifdef F_155
if ( F_156 ( V_5 ) )
F_154 ( F_157 ( V_5 [ 0 ] . V_122 ) , V_27 ) ;
#endif
for ( V_28 = 1 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_101 ( V_5 + V_28 ) ;
}
static int F_158 ( struct V_5 * V_5 , unsigned int V_27 )
{
unsigned long V_123 ;
struct V_11 * V_11 ;
int V_71 ;
F_115 ( ! F_60 ( V_5 ) ) ;
V_11 = F_15 ( V_5 ) ;
V_71 = F_79 ( V_5 ) ;
if ( V_71 != V_73 ) {
V_123 = F_159 ( V_11 ) + ( 1 << V_27 ) ;
if ( ! F_160 ( V_11 , 0 , V_123 , 0 , 0 ) )
return 0 ;
F_63 ( V_11 , - ( 1UL << V_27 ) , V_71 ) ;
}
F_64 ( & V_5 -> V_48 ) ;
V_11 -> V_49 [ V_27 ] . V_50 -- ;
F_52 ( V_5 ) ;
if ( V_27 >= V_82 - 1 ) {
struct V_5 * V_124 = V_5 + ( 1 << V_27 ) - 1 ;
for (; V_5 < V_124 ; V_5 += V_80 ) {
int V_71 = F_79 ( V_5 ) ;
if ( V_71 != V_73 && ! F_81 ( V_71 ) )
F_6 ( V_5 ,
V_121 ) ;
}
}
return 1UL << V_27 ;
}
int F_161 ( struct V_5 * V_5 )
{
unsigned int V_27 ;
int V_29 ;
V_27 = F_58 ( V_5 ) ;
V_29 = F_158 ( V_5 , V_27 ) ;
if ( ! V_29 )
return 0 ;
F_101 ( V_5 ) ;
F_154 ( V_5 , V_27 ) ;
return V_29 ;
}
static inline
struct V_5 * F_162 ( struct V_11 * V_125 ,
struct V_11 * V_11 , int V_27 , T_1 V_33 ,
int V_6 )
{
unsigned long V_56 ;
struct V_5 * V_5 ;
int V_107 = ! ! ( V_33 & V_126 ) ;
V_127:
if ( F_78 ( V_27 == 0 ) ) {
struct V_60 * V_61 ;
struct V_67 * V_68 ;
F_94 ( V_56 ) ;
V_61 = & F_150 ( V_11 -> V_114 ) -> V_61 ;
V_68 = & V_61 -> V_70 [ V_6 ] ;
if ( F_74 ( V_68 ) ) {
V_61 -> V_59 += F_126 ( V_11 , 0 ,
V_61 -> V_110 , V_68 ,
V_6 , V_107 ) ;
if ( F_7 ( F_74 ( V_68 ) ) )
goto V_128;
}
if ( V_107 )
V_5 = F_75 ( V_68 -> V_72 , struct V_5 , V_48 ) ;
else
V_5 = F_75 ( V_68 -> V_92 , struct V_5 , V_48 ) ;
F_64 ( & V_5 -> V_48 ) ;
V_61 -> V_59 -- ;
} else {
if ( F_7 ( V_33 & V_129 ) ) {
F_163 ( V_27 > 1 ) ;
}
F_140 ( & V_11 -> V_64 , V_56 ) ;
V_5 = F_124 ( V_11 , V_27 , V_6 ) ;
F_82 ( & V_11 -> V_64 ) ;
if ( ! V_5 )
goto V_128;
F_63 ( V_11 , - ( 1 << V_27 ) ,
F_79 ( V_5 ) ) ;
}
F_164 ( V_130 , V_11 , 1 << V_27 ) ;
F_165 ( V_125 , V_11 , V_33 ) ;
F_97 ( V_56 ) ;
F_40 ( F_16 ( V_11 , V_5 ) ) ;
if ( F_110 ( V_5 , V_27 , V_33 ) )
goto V_127;
return V_5 ;
V_128:
F_97 ( V_56 ) ;
return NULL ;
}
static int T_2 F_166 ( char * V_131 )
{
return F_167 ( & V_132 . V_133 , V_131 ) ;
}
static bool F_168 ( T_1 V_134 , unsigned int V_27 )
{
if ( V_27 < V_132 . V_135 )
return false ;
if ( V_134 & V_129 )
return false ;
if ( V_132 . V_136 && ( V_134 & V_34 ) )
return false ;
if ( V_132 . V_137 && ( V_134 & V_138 ) )
return false ;
return F_169 ( & V_132 . V_133 , 1 << V_27 ) ;
}
static int T_2 F_170 ( void )
{
T_5 V_139 = V_140 | V_141 | V_142 ;
struct V_143 * V_144 ;
V_144 = F_171 ( L_5 , NULL ,
& V_132 . V_133 ) ;
if ( F_172 ( V_144 ) )
return F_173 ( V_144 ) ;
if ( ! F_174 ( L_6 , V_139 , V_144 ,
& V_132 . V_137 ) )
goto V_145;
if ( ! F_174 ( L_7 , V_139 , V_144 ,
& V_132 . V_136 ) )
goto V_145;
if ( ! F_175 ( L_8 , V_139 , V_144 ,
& V_132 . V_135 ) )
goto V_145;
return 0 ;
V_145:
F_176 ( V_144 ) ;
return - V_146 ;
}
static inline bool F_168 ( T_1 V_134 , unsigned int V_27 )
{
return false ;
}
static bool F_177 ( struct V_11 * V_147 , int V_27 , unsigned long V_148 ,
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
#ifdef V_108
if ( ! ( V_150 & V_157 ) )
V_151 -= F_178 ( V_147 , V_75 ) ;
#endif
if ( V_151 <= V_152 + V_153 )
return false ;
for ( V_154 = 0 ; V_154 < V_27 ; V_154 ++ ) {
V_151 -= V_147 -> V_49 [ V_154 ] . V_50 << V_154 ;
V_152 >>= 1 ;
if ( V_151 <= V_152 )
return false ;
}
return true ;
}
bool F_160 ( struct V_11 * V_147 , int V_27 , unsigned long V_148 ,
int V_149 , int V_150 )
{
return F_177 ( V_147 , V_27 , V_148 , V_149 , V_150 ,
F_178 ( V_147 , V_74 ) ) ;
}
bool F_179 ( struct V_11 * V_147 , int V_27 , unsigned long V_148 ,
int V_149 , int V_150 )
{
long V_151 = F_178 ( V_147 , V_74 ) ;
if ( V_147 -> V_158 && V_151 < V_147 -> V_158 )
V_151 = F_180 ( V_147 , V_74 ) ;
return F_177 ( V_147 , V_27 , V_148 , V_149 , V_150 ,
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
V_162 = ! F_41 () && ( V_150 & V_167 ) ?
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
static bool F_190 ( struct V_11 * V_175 , struct V_11 * V_11 )
{
return F_185 ( V_175 -> V_176 , V_11 -> V_177 -> V_178 ) ;
}
static void T_7 F_191 ( int V_179 )
{
int V_28 ;
F_192 (i)
if ( F_193 ( V_179 , V_28 ) <= V_180 )
F_194 ( V_28 , F_195 ( V_179 ) -> V_178 ) ;
else
V_181 = 1 ;
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
static bool F_190 ( struct V_11 * V_175 , struct V_11 * V_11 )
{
return true ;
}
static inline void F_191 ( int V_179 )
{
}
static struct V_5 *
F_196 ( T_1 V_134 , T_6 * V_182 , unsigned int V_27 ,
struct V_159 * V_159 , int V_183 , int V_150 ,
struct V_11 * V_125 , int V_6 )
{
struct V_171 * V_147 ;
struct V_5 * V_5 = NULL ;
int V_149 ;
struct V_11 * V_11 ;
T_6 * V_162 = NULL ;
int V_184 = 0 ;
int V_185 = 0 ;
V_149 = F_197 ( V_125 ) ;
V_186:
F_198 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( F_127 ( V_187 ) && V_184 &&
! F_184 ( V_159 , V_147 , V_162 ) )
continue;
if ( ( V_150 & V_167 ) &&
! F_199 ( V_11 , V_134 ) )
continue;
if ( ( V_150 & V_188 ) &&
( V_134 & V_189 ) && ! F_200 ( V_11 ) )
goto V_190;
F_201 ( V_191 < V_192 ) ;
if ( ! ( V_150 & V_191 ) ) {
unsigned long V_148 ;
int V_12 ;
V_148 = V_11 -> V_123 [ V_150 & V_193 ] ;
if ( F_160 ( V_11 , V_27 , V_148 ,
V_149 , V_150 ) )
goto V_194;
if ( F_127 ( V_187 ) &&
! V_185 && V_195 > 1 ) {
V_162 = F_181 ( V_159 , V_150 ) ;
V_184 = 1 ;
V_185 = 1 ;
}
if ( V_181 == 0 ||
! F_190 ( V_125 , V_11 ) )
goto V_190;
if ( F_127 ( V_187 ) && V_184 &&
! F_184 ( V_159 , V_147 , V_162 ) )
continue;
V_12 = F_202 ( V_11 , V_134 , V_27 ) ;
switch ( V_12 ) {
case V_196 :
continue;
case V_197 :
continue;
default:
if ( ! F_160 ( V_11 , V_27 , V_148 ,
V_149 , V_150 ) )
goto V_190;
}
}
V_194:
V_5 = F_162 ( V_125 , V_11 , V_27 ,
V_134 , V_6 ) ;
if ( V_5 )
break;
V_190:
if ( F_127 ( V_187 ) )
F_187 ( V_159 , V_147 ) ;
}
if ( F_7 ( F_127 ( V_187 ) && V_5 == NULL && V_184 ) ) {
V_184 = 0 ;
goto V_186;
}
if ( V_5 )
V_5 -> V_198 = ! ! ( V_150 & V_191 ) ;
return V_5 ;
}
static inline bool F_203 ( void )
{
bool V_12 = false ;
#if V_199 > 8
V_12 = F_41 () ;
#endif
return V_12 ;
}
void F_204 ( T_1 V_134 , int V_27 , const char * V_200 , ... )
{
unsigned int V_201 = V_202 ;
if ( ( V_134 & V_203 ) || ! F_205 ( & V_204 ) ||
F_107 () > 0 )
return;
if ( ! ( V_134 & V_205 ) )
if ( F_206 ( V_206 ) ||
( V_24 -> V_56 & ( V_207 | V_208 ) ) )
V_201 &= ~ V_202 ;
if ( F_41 () || ! ( V_134 & V_138 ) )
V_201 &= ~ V_202 ;
if ( V_200 ) {
struct V_209 V_210 ;
T_8 args ;
va_start ( args , V_200 ) ;
V_210 . V_200 = V_200 ;
V_210 . V_211 = & args ;
F_207 ( L_9 , & V_210 ) ;
va_end ( args ) ;
}
F_207 ( L_10 ,
V_24 -> V_25 , V_27 , V_134 ) ;
F_24 () ;
if ( ! F_203 () )
F_208 ( V_201 ) ;
}
static inline int
F_209 ( T_1 V_134 , unsigned int V_27 ,
unsigned long V_212 ,
unsigned long V_213 )
{
if ( V_134 & V_214 )
return 0 ;
if ( V_134 & V_129 )
return 1 ;
if ( ! V_212 && F_5 () )
return 0 ;
if ( V_27 <= V_215 )
return 1 ;
if ( V_134 & V_216 && V_213 < ( 1 << V_27 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_210 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , struct V_11 * V_125 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_211 ( V_159 , V_134 ) ) {
F_212 ( 1 ) ;
return NULL ;
}
V_5 = F_196 ( V_134 | V_218 , V_182 ,
V_27 , V_159 , V_183 ,
V_219 | V_167 ,
V_125 , V_6 ) ;
if ( V_5 )
goto V_21;
if ( ! ( V_134 & V_129 ) ) {
if ( V_27 > V_215 )
goto V_21;
if ( V_183 < V_220 )
goto V_21;
if ( V_134 & V_221 )
goto V_21;
}
F_213 ( V_159 , V_134 , V_27 , V_182 , false ) ;
V_21:
F_214 ( V_159 , V_134 ) ;
return V_5 ;
}
static struct V_5 *
F_215 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , int V_150 , struct V_11 * V_125 ,
int V_6 , bool V_222 ,
bool * V_223 , bool * V_224 ,
unsigned long * V_212 )
{
if ( ! V_27 )
return NULL ;
if ( F_216 ( V_125 , V_27 ) ) {
* V_224 = true ;
return NULL ;
}
V_24 -> V_56 |= V_207 ;
* V_212 = F_217 ( V_159 , V_27 , V_134 ,
V_182 , V_222 ,
V_223 ) ;
V_24 -> V_56 &= ~ V_207 ;
if ( * V_212 != V_225 ) {
struct V_5 * V_5 ;
F_129 ( F_218 () ) ;
F_219 () ;
V_5 = F_196 ( V_134 , V_182 ,
V_27 , V_159 , V_183 ,
V_150 & ~ V_191 ,
V_125 , V_6 ) ;
if ( V_5 ) {
V_125 -> V_226 = false ;
V_125 -> V_227 = 0 ;
V_125 -> V_228 = 0 ;
if ( V_27 >= V_125 -> V_229 )
V_125 -> V_229 = V_27 + 1 ;
F_220 ( V_230 ) ;
return V_5 ;
}
F_220 ( V_231 ) ;
if ( V_222 )
F_221 ( V_125 , V_27 ) ;
F_222 () ;
}
return NULL ;
}
static inline struct V_5 *
F_215 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , int V_150 , struct V_11 * V_125 ,
int V_6 , bool V_222 ,
bool * V_223 , bool * V_224 ,
unsigned long * V_212 )
{
return NULL ;
}
static int
F_223 ( T_1 V_134 , unsigned int V_27 , struct V_159 * V_159 ,
T_6 * V_182 )
{
struct V_232 V_232 ;
int V_233 ;
F_222 () ;
F_224 () ;
V_24 -> V_56 |= V_207 ;
F_225 ( V_134 ) ;
V_232 . V_234 = 0 ;
V_24 -> V_232 = & V_232 ;
V_233 = F_226 ( V_159 , V_27 , V_134 , V_182 ) ;
V_24 -> V_232 = NULL ;
F_227 () ;
V_24 -> V_56 &= ~ V_207 ;
F_222 () ;
return V_233 ;
}
static inline struct V_5 *
F_228 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , int V_150 , struct V_11 * V_125 ,
int V_6 , unsigned long * V_212 )
{
struct V_5 * V_5 = NULL ;
bool V_235 = false ;
* V_212 = F_223 ( V_134 , V_27 , V_159 ,
V_182 ) ;
if ( F_7 ( ! ( * V_212 ) ) )
return NULL ;
if ( F_127 ( V_187 ) )
F_189 ( V_159 ) ;
V_236:
V_5 = F_196 ( V_134 , V_182 , V_27 ,
V_159 , V_183 ,
V_150 & ~ V_191 ,
V_125 , V_6 ) ;
if ( ! V_5 && ! V_235 ) {
F_134 () ;
V_235 = true ;
goto V_236;
}
return V_5 ;
}
static inline struct V_5 *
F_229 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , struct V_11 * V_125 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_196 ( V_134 , V_182 , V_27 ,
V_159 , V_183 , V_191 ,
V_125 , V_6 ) ;
if ( ! V_5 && V_134 & V_129 )
F_230 ( V_125 , V_237 , V_23 / 50 ) ;
} while ( ! V_5 && ( V_134 & V_129 ) );
return V_5 ;
}
static inline
void F_231 ( unsigned int V_27 , struct V_159 * V_159 ,
enum V_217 V_183 ,
enum V_217 V_149 )
{
struct V_171 * V_147 ;
struct V_11 * V_11 ;
F_232 (zone, z, zonelist, high_zoneidx)
F_233 ( V_11 , V_27 , V_149 ) ;
}
static inline int
F_234 ( T_1 V_134 )
{
int V_150 = V_238 | V_167 ;
const T_1 V_239 = V_134 & V_138 ;
F_201 ( V_240 != ( V_241 T_1 ) V_155 ) ;
V_150 |= ( V_241 int ) ( V_134 & V_240 ) ;
if ( ! V_239 ) {
if ( ! ( V_134 & V_205 ) )
V_150 |= V_156 ;
V_150 &= ~ V_167 ;
} else if ( F_7 ( F_235 ( V_24 ) ) && ! F_41 () )
V_150 |= V_156 ;
if ( F_78 ( ! ( V_134 & V_205 ) ) ) {
if ( V_134 & V_242 )
V_150 |= V_191 ;
else if ( F_236 () && ( V_24 -> V_56 & V_207 ) )
V_150 |= V_191 ;
else if ( ! F_41 () &&
( ( V_24 -> V_56 & V_207 ) ||
F_7 ( F_206 ( V_206 ) ) ) )
V_150 |= V_191 ;
}
#ifdef V_108
if ( F_237 ( V_134 ) == V_121 )
V_150 |= V_157 ;
#endif
return V_150 ;
}
bool F_238 ( T_1 V_134 )
{
return ! ! ( F_234 ( V_134 ) & V_191 ) ;
}
static inline struct V_5 *
F_239 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , struct V_11 * V_125 ,
int V_6 )
{
const T_1 V_239 = V_134 & V_138 ;
struct V_5 * V_5 = NULL ;
int V_150 ;
unsigned long V_213 = 0 ;
unsigned long V_212 ;
bool V_222 = false ;
bool V_224 = false ;
bool V_223 = false ;
if ( V_27 >= V_37 ) {
F_163 ( ! ( V_134 & V_203 ) ) ;
return NULL ;
}
if ( F_127 ( V_187 ) &&
( V_134 & V_243 ) == V_243 )
goto V_244;
V_245:
if ( ! ( V_134 & V_246 ) )
F_231 ( V_27 , V_159 , V_183 ,
F_197 ( V_125 ) ) ;
V_150 = F_234 ( V_134 ) ;
if ( ! ( V_150 & V_167 ) && ! V_182 )
F_240 ( V_159 , V_183 , NULL ,
& V_125 ) ;
V_247:
V_5 = F_196 ( V_134 , V_182 , V_27 , V_159 ,
V_183 , V_150 & ~ V_191 ,
V_125 , V_6 ) ;
if ( V_5 )
goto V_248;
if ( V_150 & V_191 ) {
V_159 = F_241 ( F_242 () , V_134 ) ;
V_5 = F_229 ( V_134 , V_27 ,
V_159 , V_183 , V_182 ,
V_125 , V_6 ) ;
if ( V_5 ) {
goto V_248;
}
}
if ( ! V_239 )
goto V_244;
if ( V_24 -> V_56 & V_207 )
goto V_244;
if ( F_206 ( V_206 ) && ! ( V_134 & V_129 ) )
goto V_244;
V_5 = F_215 ( V_134 , V_27 ,
V_159 , V_183 ,
V_182 ,
V_150 , V_125 ,
V_6 , V_222 ,
& V_223 ,
& V_224 ,
& V_212 ) ;
if ( V_5 )
goto V_248;
V_222 = true ;
if ( ( V_224 || V_223 ) &&
( V_134 & V_246 ) )
goto V_244;
V_5 = F_228 ( V_134 , V_27 ,
V_159 , V_183 ,
V_182 ,
V_150 , V_125 ,
V_6 , & V_212 ) ;
if ( V_5 )
goto V_248;
if ( ! V_212 ) {
if ( ( V_134 & V_249 ) && ! ( V_134 & V_214 ) ) {
if ( V_250 )
goto V_244;
if ( ( V_24 -> V_56 & V_251 ) &&
! ( V_134 & V_129 ) )
goto V_244;
V_5 = F_210 ( V_134 , V_27 ,
V_159 , V_183 ,
V_182 , V_125 ,
V_6 ) ;
if ( V_5 )
goto V_248;
if ( ! ( V_134 & V_129 ) ) {
if ( V_27 > V_215 )
goto V_244;
if ( V_183 < V_220 )
goto V_244;
}
goto V_245;
}
}
V_213 += V_212 ;
if ( F_209 ( V_134 , V_27 , V_212 ,
V_213 ) ) {
F_230 ( V_125 , V_237 , V_23 / 50 ) ;
goto V_247;
} else {
V_5 = F_215 ( V_134 , V_27 ,
V_159 , V_183 ,
V_182 ,
V_150 , V_125 ,
V_6 , V_222 ,
& V_223 ,
& V_224 ,
& V_212 ) ;
if ( V_5 )
goto V_248;
}
V_244:
F_204 ( V_134 , V_27 , NULL ) ;
return V_5 ;
V_248:
if ( V_252 )
F_243 ( V_5 , V_27 , V_134 ) ;
return V_5 ;
}
struct V_5 *
F_244 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , T_6 * V_182 )
{
enum V_217 V_183 = F_245 ( V_134 ) ;
struct V_11 * V_125 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_237 ( V_134 ) ;
unsigned int V_253 ;
int V_150 = V_188 | V_167 ;
struct V_254 * V_255 = NULL ;
V_134 &= V_3 ;
F_246 ( V_134 ) ;
F_247 ( V_134 & V_138 ) ;
if ( F_168 ( V_134 , V_27 ) )
return NULL ;
if ( F_7 ( ! V_159 -> V_173 -> V_11 ) )
return NULL ;
if ( ! F_248 ( V_134 , & V_255 , V_27 ) )
return NULL ;
V_256:
V_253 = F_249 () ;
F_240 ( V_159 , V_183 ,
V_182 ? : & V_168 ,
& V_125 ) ;
if ( ! V_125 )
goto V_21;
#ifdef V_108
if ( F_237 ( V_134 ) == V_121 )
V_150 |= V_157 ;
#endif
V_5 = F_196 ( V_134 | V_218 , V_182 , V_27 ,
V_159 , V_183 , V_150 ,
V_125 , V_6 ) ;
if ( F_7 ( ! V_5 ) )
V_5 = F_239 ( V_134 , V_27 ,
V_159 , V_183 , V_182 ,
V_125 , V_6 ) ;
F_250 ( V_5 , V_27 , V_134 , V_6 ) ;
V_21:
if ( F_7 ( ! F_251 ( V_253 ) && ! V_5 ) )
goto V_256;
F_252 ( V_5 , V_255 , V_27 ) ;
return V_5 ;
}
unsigned long F_253 ( T_1 V_134 , unsigned int V_27 )
{
struct V_5 * V_5 ;
F_40 ( ( V_134 & V_34 ) != 0 ) ;
V_5 = F_254 ( V_134 , V_27 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_90 ( V_5 ) ;
}
unsigned long F_255 ( T_1 V_134 )
{
return F_253 ( V_134 | V_89 , 0 ) ;
}
void F_102 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( F_256 ( V_5 ) ) {
if ( V_27 == 0 )
F_148 ( V_5 , 0 ) ;
else
F_27 ( V_5 , V_27 ) ;
}
}
void V_151 ( unsigned long V_257 , unsigned int V_27 )
{
if ( V_257 != 0 ) {
F_40 ( ! F_257 ( ( void * ) V_257 ) ) ;
F_102 ( F_157 ( ( void * ) V_257 ) , V_27 ) ;
}
}
void F_258 ( struct V_5 * V_5 , unsigned int V_27 )
{
F_259 ( V_5 , V_27 ) ;
F_102 ( V_5 , V_27 ) ;
}
void F_260 ( unsigned long V_257 , unsigned int V_27 )
{
if ( V_257 != 0 ) {
F_40 ( ! F_257 ( ( void * ) V_257 ) ) ;
F_258 ( F_157 ( ( void * ) V_257 ) , V_27 ) ;
}
}
static void * F_261 ( unsigned long V_257 , unsigned V_27 , T_9 V_88 )
{
if ( V_257 ) {
unsigned long V_258 = V_257 + ( V_76 << V_27 ) ;
unsigned long V_259 = V_257 + F_262 ( V_88 ) ;
F_154 ( F_157 ( ( void * ) V_257 ) , V_27 ) ;
while ( V_259 < V_258 ) {
F_263 ( V_259 ) ;
V_259 += V_76 ;
}
}
return ( void * ) V_257 ;
}
void * F_264 ( T_9 V_88 , T_1 V_134 )
{
unsigned int V_27 = F_265 ( V_88 ) ;
unsigned long V_257 ;
V_257 = F_253 ( V_134 , V_27 ) ;
return F_261 ( V_257 , V_27 , V_88 ) ;
}
void * F_266 ( int V_179 , T_9 V_88 , T_1 V_134 )
{
unsigned V_27 = F_265 ( V_88 ) ;
struct V_5 * V_30 = F_267 ( V_179 , V_134 , V_27 ) ;
if ( ! V_30 )
return NULL ;
return F_261 ( ( unsigned long ) F_90 ( V_30 ) , V_27 , V_88 ) ;
}
void F_268 ( void * V_260 , T_9 V_88 )
{
unsigned long V_257 = ( unsigned long ) V_260 ;
unsigned long V_261 = V_257 + F_262 ( V_88 ) ;
while ( V_257 < V_261 ) {
F_263 ( V_257 ) ;
V_257 += V_76 ;
}
}
static unsigned int F_269 ( int V_262 )
{
struct V_171 * V_147 ;
struct V_11 * V_11 ;
unsigned int V_263 = 0 ;
struct V_159 * V_159 = F_241 ( F_242 () , V_264 ) ;
F_232 (zone, z, zonelist, offset) {
unsigned long V_88 = V_11 -> V_265 ;
unsigned long V_86 = F_270 ( V_11 ) ;
if ( V_88 > V_86 )
V_263 += V_88 - V_86 ;
}
return V_263 ;
}
unsigned int F_271 ( void )
{
return F_269 ( F_245 ( V_266 ) ) ;
}
unsigned int F_272 ( void )
{
return F_269 ( F_245 ( V_267 ) ) ;
}
static inline void F_273 ( struct V_11 * V_11 )
{
if ( F_127 ( V_187 ) )
F_21 ( L_11 , F_117 ( V_11 ) ) ;
}
void F_274 ( struct V_268 * V_269 )
{
V_269 -> V_270 = V_83 ;
V_269 -> V_271 = 0 ;
V_269 -> V_272 = F_275 ( V_74 ) ;
V_269 -> V_273 = F_276 () ;
V_269 -> V_274 = V_84 ;
V_269 -> V_275 = F_277 () ;
V_269 -> V_276 = V_76 ;
}
void F_278 ( struct V_268 * V_269 , int V_179 )
{
T_10 * V_277 = F_195 ( V_179 ) ;
V_269 -> V_270 = V_277 -> V_278 ;
V_269 -> V_272 = F_279 ( V_179 , V_74 ) ;
#ifdef F_104
V_269 -> V_274 = V_277 -> V_279 [ V_280 ] . V_265 ;
V_269 -> V_275 = F_178 ( & V_277 -> V_279 [ V_280 ] ,
V_74 ) ;
#else
V_269 -> V_274 = 0 ;
V_269 -> V_275 = 0 ;
#endif
V_269 -> V_276 = V_76 ;
}
bool F_280 ( unsigned int V_56 , int V_179 )
{
bool V_12 = false ;
unsigned int V_253 ;
if ( ! ( V_56 & V_202 ) )
goto V_21;
do {
V_253 = F_249 () ;
V_12 = ! F_185 ( V_179 , V_168 ) ;
} while ( ! F_251 ( V_253 ) );
V_21:
return V_12 ;
}
static void F_281 ( unsigned char type )
{
static const char V_281 [ V_282 ] = {
[ V_8 ] = 'U' ,
[ V_104 ] = 'E' ,
[ V_121 ] = 'M' ,
[ V_103 ] = 'R' ,
#ifdef V_108
[ V_81 ] = 'C' ,
#endif
[ V_73 ] = 'I' ,
} ;
char V_283 [ V_282 + 1 ] ;
char * V_30 = V_283 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_282 ; V_28 ++ ) {
if ( type & ( 1 << V_28 ) )
* V_30 ++ = V_281 [ V_28 ] ;
}
* V_30 = '\0' ;
F_21 ( L_12 , V_283 ) ;
}
void F_282 ( unsigned int V_201 )
{
int V_111 ;
struct V_11 * V_11 ;
F_130 (zone) {
if ( F_280 ( V_201 , F_117 ( V_11 ) ) )
continue;
F_273 ( V_11 ) ;
F_21 ( L_13 , V_11 -> V_284 ) ;
F_135 (cpu) {
struct V_112 * V_114 ;
V_114 = F_131 ( V_11 -> V_114 , V_111 ) ;
F_21 ( L_14 ,
V_111 , V_114 -> V_61 . V_86 ,
V_114 -> V_61 . V_110 , V_114 -> V_61 . V_59 ) ;
}
}
F_21 ( L_15
L_16
L_17
L_18
L_19
L_20
L_21 ,
F_275 ( V_285 ) ,
F_275 ( V_286 ) ,
F_275 ( V_287 ) ,
F_275 ( V_288 ) ,
F_275 ( V_289 ) ,
F_275 ( V_290 ) ,
F_275 ( V_291 ) ,
F_275 ( V_292 ) ,
F_275 ( V_293 ) ,
F_275 ( V_294 ) ,
F_275 ( V_74 ) ,
F_275 ( V_295 ) ,
F_275 ( V_296 ) ,
F_275 ( V_297 ) ,
F_275 ( V_298 ) ,
F_275 ( V_299 ) ,
F_275 ( V_300 ) ,
F_275 ( V_75 ) ) ;
F_130 (zone) {
int V_28 ;
if ( F_280 ( V_201 , F_117 ( V_11 ) ) )
continue;
F_273 ( V_11 ) ;
F_21 ( L_22
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
L_47
L_48
L_49
L_50
L_51 ,
V_11 -> V_284 ,
F_283 ( F_178 ( V_11 , V_74 ) ) ,
F_283 ( F_284 ( V_11 ) ) ,
F_283 ( F_159 ( V_11 ) ) ,
F_283 ( F_270 ( V_11 ) ) ,
F_283 ( F_178 ( V_11 , V_285 ) ) ,
F_283 ( F_178 ( V_11 , V_286 ) ) ,
F_283 ( F_178 ( V_11 , V_288 ) ) ,
F_283 ( F_178 ( V_11 , V_289 ) ) ,
F_283 ( F_178 ( V_11 , V_291 ) ) ,
F_283 ( F_178 ( V_11 , V_287 ) ) ,
F_283 ( F_178 ( V_11 , V_290 ) ) ,
F_283 ( V_11 -> V_265 ) ,
F_283 ( V_11 -> V_79 ) ,
F_283 ( F_178 ( V_11 , V_301 ) ) ,
F_283 ( F_178 ( V_11 , V_292 ) ) ,
F_283 ( F_178 ( V_11 , V_293 ) ) ,
F_283 ( F_178 ( V_11 , V_297 ) ) ,
F_283 ( F_178 ( V_11 , V_298 ) ) ,
F_283 ( F_178 ( V_11 , V_295 ) ) ,
F_283 ( F_178 ( V_11 , V_296 ) ) ,
F_178 ( V_11 , V_302 ) *
V_303 / 1024 ,
F_283 ( F_178 ( V_11 , V_299 ) ) ,
F_283 ( F_178 ( V_11 , V_294 ) ) ,
F_283 ( F_178 ( V_11 , V_300 ) ) ,
F_283 ( F_178 ( V_11 , V_75 ) ) ,
F_283 ( F_178 ( V_11 , V_304 ) ) ,
V_11 -> V_66 ,
( V_11 -> V_65 ? L_52 : L_53 )
) ;
F_21 ( L_54 ) ;
for ( V_28 = 0 ; V_28 < V_305 ; V_28 ++ )
F_21 ( L_55 , V_11 -> V_153 [ V_28 ] ) ;
F_21 ( L_51 ) ;
}
F_130 (zone) {
unsigned long V_306 [ V_37 ] , V_56 , V_27 , V_307 = 0 ;
unsigned char V_281 [ V_37 ] ;
if ( F_280 ( V_201 , F_117 ( V_11 ) ) )
continue;
F_273 ( V_11 ) ;
F_21 ( L_56 , V_11 -> V_284 ) ;
F_140 ( & V_11 -> V_64 , V_56 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
struct V_49 * V_87 = & V_11 -> V_49 [ V_27 ] ;
int type ;
V_306 [ V_27 ] = V_87 -> V_50 ;
V_307 += V_306 [ V_27 ] << V_27 ;
V_281 [ V_27 ] = 0 ;
for ( type = 0 ; type < V_282 ; type ++ ) {
if ( ! F_74 ( & V_87 -> V_53 [ type ] ) )
V_281 [ V_27 ] |= 1 << type ;
}
}
F_147 ( & V_11 -> V_64 , V_56 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
F_21 ( L_57 , V_306 [ V_27 ] , F_283 ( 1UL ) << V_27 ) ;
if ( V_306 [ V_27 ] )
F_281 ( V_281 [ V_27 ] ) ;
}
F_21 ( L_58 , F_283 ( V_307 ) ) ;
}
F_21 ( L_59 , F_275 ( V_308 ) ) ;
F_285 () ;
}
static void F_286 ( struct V_11 * V_11 , struct V_171 * V_171 )
{
V_171 -> V_11 = V_11 ;
V_171 -> F_197 = F_197 ( V_11 ) ;
}
static int F_287 ( T_10 * V_277 , struct V_159 * V_159 ,
int V_309 , enum V_217 V_217 )
{
struct V_11 * V_11 ;
F_115 ( V_217 >= V_305 ) ;
V_217 ++ ;
do {
V_217 -- ;
V_11 = V_277 -> V_279 + V_217 ;
if ( F_288 ( V_11 ) ) {
F_286 ( V_11 ,
& V_159 -> V_173 [ V_309 ++ ] ) ;
F_289 ( V_217 ) ;
}
} while ( V_217 );
return V_309 ;
}
static int F_290 ( char * V_310 )
{
if ( * V_310 == 'd' || * V_310 == 'D' ) {
V_311 = V_312 ;
} else if ( * V_310 == 'n' || * V_310 == 'N' ) {
V_311 = V_313 ;
} else if ( * V_310 == 'z' || * V_310 == 'Z' ) {
V_311 = V_314 ;
} else {
F_21 ( V_315
L_60
L_61 , V_310 ) ;
return - V_316 ;
}
return 0 ;
}
static T_2 int F_291 ( char * V_310 )
{
int V_12 ;
if ( ! V_310 )
return 0 ;
V_12 = F_290 ( V_310 ) ;
if ( V_12 == 0 )
F_292 ( V_317 , V_310 , V_318 ) ;
return V_12 ;
}
int F_293 ( T_11 * V_319 , int V_320 ,
void T_12 * V_321 , T_9 * V_322 ,
T_13 * V_323 )
{
char V_324 [ V_318 ] ;
int V_12 ;
static F_294 ( V_325 ) ;
F_295 ( & V_325 ) ;
if ( V_320 )
strcpy ( V_324 , ( char * ) V_319 -> V_326 ) ;
V_12 = F_296 ( V_319 , V_320 , V_321 , V_322 , V_323 ) ;
if ( V_12 )
goto V_21;
if ( V_320 ) {
int V_327 = V_311 ;
if ( F_290 ( ( char * ) V_319 -> V_326 ) ) {
strncpy ( ( char * ) V_319 -> V_326 , V_324 ,
V_318 ) ;
V_311 = V_327 ;
} else if ( V_327 != V_311 ) {
F_295 ( & V_328 ) ;
F_297 ( NULL , NULL ) ;
F_298 ( & V_328 ) ;
}
}
V_21:
F_298 ( & V_325 ) ;
return V_12 ;
}
static int F_299 ( int V_176 , T_6 * V_329 )
{
int V_172 , V_269 ;
int V_330 = V_331 ;
int V_332 = - 1 ;
const struct V_333 * V_283 = F_300 ( 0 ) ;
if ( ! F_185 ( V_176 , * V_329 ) ) {
F_194 ( V_176 , * V_329 ) ;
return V_176 ;
}
F_301 (n, N_MEMORY) {
if ( F_185 ( V_172 , * V_329 ) )
continue;
V_269 = F_193 ( V_176 , V_172 ) ;
V_269 += ( V_172 < V_176 ) ;
V_283 = F_300 ( V_172 ) ;
if ( ! F_302 ( V_283 ) )
V_269 += V_334 ;
V_269 *= ( V_335 * V_336 ) ;
V_269 += V_337 [ V_172 ] ;
if ( V_269 < V_330 ) {
V_330 = V_269 ;
V_332 = V_172 ;
}
}
if ( V_332 >= 0 )
F_194 ( V_332 , * V_329 ) ;
return V_332 ;
}
static void F_303 ( T_10 * V_277 , int V_176 )
{
int V_338 ;
struct V_159 * V_159 ;
V_159 = & V_277 -> V_339 [ 0 ] ;
for ( V_338 = 0 ; V_159 -> V_173 [ V_338 ] . V_11 != NULL ; V_338 ++ )
;
V_338 = F_287 ( F_195 ( V_176 ) , V_159 , V_338 ,
V_305 - 1 ) ;
V_159 -> V_173 [ V_338 ] . V_11 = NULL ;
V_159 -> V_173 [ V_338 ] . F_197 = 0 ;
}
static void F_304 ( T_10 * V_277 )
{
int V_338 ;
struct V_159 * V_159 ;
V_159 = & V_277 -> V_339 [ 1 ] ;
V_338 = F_287 ( V_277 , V_159 , 0 , V_305 - 1 ) ;
V_159 -> V_173 [ V_338 ] . V_11 = NULL ;
V_159 -> V_173 [ V_338 ] . F_197 = 0 ;
}
static void F_305 ( T_10 * V_277 , int V_340 )
{
int V_341 , V_338 , V_176 ;
int V_217 ;
struct V_11 * V_147 ;
struct V_159 * V_159 ;
V_159 = & V_277 -> V_339 [ 0 ] ;
V_341 = 0 ;
for ( V_217 = V_305 - 1 ; V_217 >= 0 ; V_217 -- ) {
for ( V_338 = 0 ; V_338 < V_340 ; V_338 ++ ) {
V_176 = V_342 [ V_338 ] ;
V_147 = & F_195 ( V_176 ) -> V_279 [ V_217 ] ;
if ( F_288 ( V_147 ) ) {
F_286 ( V_147 ,
& V_159 -> V_173 [ V_341 ++ ] ) ;
F_289 ( V_217 ) ;
}
}
}
V_159 -> V_173 [ V_341 ] . V_11 = NULL ;
V_159 -> V_173 [ V_341 ] . F_197 = 0 ;
}
static int F_306 ( void )
{
int V_179 , V_217 ;
unsigned long V_343 , V_344 ;
struct V_11 * V_147 ;
int V_345 ;
V_343 = 0 ;
V_344 = 0 ;
F_192 (nid) {
for ( V_217 = 0 ; V_217 < V_305 ; V_217 ++ ) {
V_147 = & F_195 ( V_179 ) -> V_279 [ V_217 ] ;
if ( F_288 ( V_147 ) ) {
if ( V_217 < V_220 )
V_343 += V_147 -> V_265 ;
V_344 += V_147 -> V_265 ;
} else if ( V_217 == V_220 ) {
return V_313 ;
}
}
}
if ( ! V_343 ||
V_343 > V_344 / 2 )
return V_313 ;
V_345 = V_344 /
( F_307 ( V_169 [ V_170 ] ) + 1 ) ;
F_192 (nid) {
V_343 = 0 ;
V_344 = 0 ;
for ( V_217 = 0 ; V_217 < V_305 ; V_217 ++ ) {
V_147 = & F_195 ( V_179 ) -> V_279 [ V_217 ] ;
if ( F_288 ( V_147 ) ) {
if ( V_217 < V_220 )
V_343 += V_147 -> V_265 ;
V_344 += V_147 -> V_265 ;
}
}
if ( V_343 &&
V_344 > V_345 &&
V_343 > V_344 * 70 / 100 )
return V_313 ;
}
return V_314 ;
}
static void F_308 ( void )
{
if ( V_311 == V_312 )
V_346 = F_306 () ;
else
V_346 = V_311 ;
}
static void F_309 ( T_10 * V_277 )
{
int V_338 , V_176 , V_347 ;
enum V_217 V_28 ;
T_6 V_348 ;
int V_349 , V_350 ;
struct V_159 * V_159 ;
int V_27 = V_346 ;
for ( V_28 = 0 ; V_28 < V_351 ; V_28 ++ ) {
V_159 = V_277 -> V_339 + V_28 ;
V_159 -> V_173 [ 0 ] . V_11 = NULL ;
V_159 -> V_173 [ 0 ] . F_197 = 0 ;
}
V_349 = V_277 -> V_352 ;
V_347 = V_195 ;
V_350 = V_349 ;
F_310 ( V_348 ) ;
memset ( V_342 , 0 , sizeof( V_342 ) ) ;
V_338 = 0 ;
while ( ( V_176 = F_299 ( V_349 , & V_348 ) ) >= 0 ) {
if ( F_193 ( V_349 , V_176 ) !=
F_193 ( V_349 , V_350 ) )
V_337 [ V_176 ] = V_347 ;
V_350 = V_176 ;
V_347 -- ;
if ( V_27 == V_313 )
F_303 ( V_277 , V_176 ) ;
else
V_342 [ V_338 ++ ] = V_176 ;
}
if ( V_27 == V_314 ) {
F_305 ( V_277 , V_338 ) ;
}
F_304 ( V_277 ) ;
}
static void F_311 ( T_10 * V_277 )
{
struct V_159 * V_159 ;
struct V_160 * V_161 ;
struct V_171 * V_147 ;
V_159 = & V_277 -> V_339 [ 0 ] ;
V_159 -> V_163 = V_161 = & V_159 -> V_353 ;
F_183 ( V_161 -> V_165 , V_166 ) ;
for ( V_147 = V_159 -> V_173 ; V_147 -> V_11 ; V_147 ++ )
V_161 -> V_174 [ V_147 - V_159 -> V_173 ] = F_312 ( V_147 ) ;
}
int F_313 ( int V_176 )
{
struct V_11 * V_11 ;
( void ) F_240 ( F_241 ( V_176 , V_264 ) ,
F_245 ( V_264 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_176 ;
}
static void F_308 ( void )
{
V_346 = V_314 ;
}
static void F_309 ( T_10 * V_277 )
{
int V_176 , V_349 ;
enum V_217 V_338 ;
struct V_159 * V_159 ;
V_349 = V_277 -> V_352 ;
V_159 = & V_277 -> V_339 [ 0 ] ;
V_338 = F_287 ( V_277 , V_159 , 0 , V_305 - 1 ) ;
for ( V_176 = V_349 + 1 ; V_176 < V_336 ; V_176 ++ ) {
if ( ! F_314 ( V_176 ) )
continue;
V_338 = F_287 ( F_195 ( V_176 ) , V_159 , V_338 ,
V_305 - 1 ) ;
}
for ( V_176 = 0 ; V_176 < V_349 ; V_176 ++ ) {
if ( ! F_314 ( V_176 ) )
continue;
V_338 = F_287 ( F_195 ( V_176 ) , V_159 , V_338 ,
V_305 - 1 ) ;
}
V_159 -> V_173 [ V_338 ] . V_11 = NULL ;
V_159 -> V_173 [ V_338 ] . F_197 = 0 ;
}
static void F_311 ( T_10 * V_277 )
{
V_277 -> V_339 [ 0 ] . V_163 = NULL ;
}
static int F_315 ( void * V_326 )
{
int V_179 ;
int V_111 ;
T_10 * V_354 = V_326 ;
#ifdef V_187
memset ( V_337 , 0 , sizeof( V_337 ) ) ;
#endif
if ( V_354 && ! F_314 ( V_354 -> V_352 ) ) {
F_309 ( V_354 ) ;
F_311 ( V_354 ) ;
}
F_192 (nid) {
T_10 * V_277 = F_195 ( V_179 ) ;
F_309 ( V_277 ) ;
F_311 ( V_277 ) ;
}
F_316 (cpu) {
F_317 ( & F_318 ( V_355 , V_111 ) , 0 ) ;
#ifdef F_319
if ( F_320 ( V_111 ) )
F_321 ( V_111 , F_313 ( F_322 ( V_111 ) ) ) ;
#endif
}
return 0 ;
}
void T_14 F_297 ( T_10 * V_277 , struct V_11 * V_11 )
{
F_308 () ;
if ( V_356 == V_357 ) {
F_315 ( NULL ) ;
F_323 () ;
F_324 () ;
} else {
#ifdef F_325
if ( V_11 )
F_326 ( V_11 ) ;
#endif
F_327 ( F_315 , V_277 , NULL ) ;
}
V_358 = F_272 () ;
if ( V_358 < ( V_80 * V_282 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_21 ( L_62
L_63 ,
V_195 ,
V_359 [ V_346 ] ,
V_7 ? L_64 : L_65 ,
V_358 ) ;
#ifdef V_187
F_21 ( L_66 , V_360 [ V_361 ] ) ;
#endif
}
static inline unsigned long F_328 ( unsigned long V_105 )
{
unsigned long V_88 = 1 ;
V_105 /= V_362 ;
while ( V_88 < V_105 )
V_88 <<= 1 ;
V_88 = V_152 ( V_88 , 4096UL ) ;
return F_329 ( V_88 , 4UL ) ;
}
static inline unsigned long F_328 ( unsigned long V_105 )
{
return 4096UL ;
}
static inline unsigned long F_330 ( unsigned long V_88 )
{
return F_331 ( ~ V_88 ) ;
}
static int F_332 ( unsigned long V_96 , unsigned long V_97 )
{
unsigned long V_14 ;
for ( V_14 = V_96 ; V_14 < V_97 ; V_14 ++ ) {
if ( ! F_14 ( V_14 ) || F_333 ( F_120 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_334 ( struct V_11 * V_11 )
{
unsigned long V_96 , V_14 , V_97 , V_363 ;
struct V_5 * V_5 ;
unsigned long V_364 ;
int V_365 ;
V_96 = V_11 -> V_15 ;
V_97 = V_96 + V_11 -> V_16 ;
V_96 = F_335 ( V_96 , V_80 ) ;
V_365 = F_335 ( F_284 ( V_11 ) , V_80 ) >>
V_82 ;
V_365 = V_152 ( 2 , V_365 ) ;
for ( V_14 = V_96 ; V_14 < V_97 ; V_14 += V_80 ) {
if ( ! F_141 ( V_14 ) )
continue;
V_5 = F_120 ( V_14 ) ;
if ( F_116 ( V_5 ) != F_117 ( V_11 ) )
continue;
V_364 = F_79 ( V_5 ) ;
if ( V_365 > 0 ) {
V_363 = V_152 ( V_14 + V_80 , V_97 ) ;
if ( F_332 ( V_14 , V_363 ) )
continue;
if ( V_364 == V_103 ) {
V_365 -- ;
continue;
}
if ( V_364 == V_121 ) {
F_6 ( V_5 ,
V_103 ) ;
F_119 ( V_11 , V_5 ,
V_103 ) ;
V_365 -- ;
continue;
}
}
if ( V_364 == V_103 ) {
F_6 ( V_5 , V_121 ) ;
F_119 ( V_11 , V_5 , V_121 ) ;
}
}
}
void T_3 F_336 ( unsigned long V_88 , int V_179 , unsigned long V_11 ,
unsigned long V_96 , enum V_366 V_367 )
{
struct V_5 * V_5 ;
unsigned long V_97 = V_96 + V_88 ;
unsigned long V_14 ;
struct V_11 * V_147 ;
if ( V_368 < V_97 - 1 )
V_368 = V_97 - 1 ;
V_147 = & F_195 ( V_179 ) -> V_279 [ V_11 ] ;
for ( V_14 = V_96 ; V_14 < V_97 ; V_14 ++ ) {
if ( V_367 == V_369 ) {
if ( ! F_337 ( V_14 ) )
continue;
if ( ! F_338 ( V_14 , V_179 ) )
continue;
}
V_5 = F_120 ( V_14 ) ;
F_339 ( V_5 , V_11 , V_179 , V_14 ) ;
F_340 ( V_5 , V_11 , V_179 , V_14 ) ;
F_341 ( V_5 ) ;
F_19 ( V_5 ) ;
F_71 ( V_5 ) ;
F_342 ( V_5 ) ;
if ( ( V_147 -> V_15 <= V_14 )
&& ( V_14 < V_147 -> V_15 + V_147 -> V_16 )
&& ! ( V_14 & ( V_80 - 1 ) ) )
F_6 ( V_5 , V_121 ) ;
F_108 ( & V_5 -> V_48 ) ;
#ifdef F_343
if ( ! F_344 ( V_11 ) )
F_345 ( V_5 , F_346 ( V_14 << V_370 ) ) ;
#endif
}
}
static void T_3 F_347 ( struct V_11 * V_11 )
{
int V_27 , V_119 ;
F_144 (order, t) {
F_108 ( & V_11 -> V_49 [ V_27 ] . V_53 [ V_119 ] ) ;
V_11 -> V_49 [ V_27 ] . V_50 = 0 ;
}
}
static int T_3 F_348 ( struct V_11 * V_11 )
{
#ifdef F_349
int V_110 ;
V_110 = V_11 -> V_265 / 1024 ;
if ( V_110 * V_76 > 512 * 1024 )
V_110 = ( 512 * 1024 ) / V_76 ;
V_110 /= 4 ;
if ( V_110 < 1 )
V_110 = 1 ;
V_110 = F_350 ( V_110 + V_110 / 2 ) - 1 ;
return V_110 ;
#else
return 0 ;
#endif
}
static void F_317 ( struct V_112 * V_30 , unsigned long V_110 )
{
struct V_60 * V_61 ;
int V_6 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_61 = & V_30 -> V_61 ;
V_61 -> V_59 = 0 ;
V_61 -> V_86 = 6 * V_110 ;
V_61 -> V_110 = F_329 ( 1UL , 1 * V_110 ) ;
for ( V_6 = 0 ; V_6 < V_69 ; V_6 ++ )
F_108 ( & V_61 -> V_70 [ V_6 ] ) ;
}
static void F_351 ( struct V_112 * V_30 ,
unsigned long V_86 )
{
struct V_60 * V_61 ;
V_61 = & V_30 -> V_61 ;
V_61 -> V_86 = V_86 ;
V_61 -> V_110 = F_329 ( 1UL , V_86 / 4 ) ;
if ( ( V_86 / 4 ) > ( V_370 * 8 ) )
V_61 -> V_110 = V_370 * 8 ;
}
static void T_3 F_326 ( struct V_11 * V_11 )
{
int V_111 ;
V_11 -> V_114 = F_352 ( struct V_112 ) ;
F_316 (cpu) {
struct V_112 * V_61 = F_131 ( V_11 -> V_114 , V_111 ) ;
F_317 ( V_61 , F_348 ( V_11 ) ) ;
if ( V_371 )
F_351 ( V_61 ,
( V_11 -> V_265 /
V_371 ) ) ;
}
}
void T_2 F_353 ( void )
{
struct V_11 * V_11 ;
F_130 (zone)
F_326 ( V_11 ) ;
}
static T_15 T_16
int F_354 ( struct V_11 * V_11 , unsigned long V_372 )
{
int V_28 ;
struct V_373 * V_277 = V_11 -> V_177 ;
T_9 V_374 ;
V_11 -> F_328 =
F_328 ( V_372 ) ;
V_11 -> F_330 =
F_330 ( V_11 -> F_328 ) ;
V_374 = V_11 -> F_328
* sizeof( V_375 ) ;
if ( ! F_355 () ) {
V_11 -> V_376 = ( V_375 * )
F_356 ( V_277 , V_374 ) ;
} else {
V_11 -> V_376 = F_357 ( V_374 ) ;
}
if ( ! V_11 -> V_376 )
return - V_146 ;
for( V_28 = 0 ; V_28 < V_11 -> F_328 ; ++ V_28 )
F_358 ( V_11 -> V_376 + V_28 ) ;
return 0 ;
}
static T_3 void F_359 ( struct V_11 * V_11 )
{
V_11 -> V_114 = & V_355 ;
if ( V_11 -> V_265 )
F_21 ( V_377 L_67 ,
V_11 -> V_284 , V_11 -> V_265 ,
F_348 ( V_11 ) ) ;
}
int T_3 F_360 ( struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_88 ,
enum V_366 V_367 )
{
struct V_373 * V_277 = V_11 -> V_177 ;
int V_12 ;
V_12 = F_354 ( V_11 , V_88 ) ;
if ( V_12 )
return V_12 ;
V_277 -> V_309 = F_197 ( V_11 ) + 1 ;
V_11 -> V_15 = V_15 ;
F_361 ( V_378 , L_68 ,
L_69 ,
V_277 -> V_352 ,
( unsigned long ) F_197 ( V_11 ) ,
V_15 , ( V_15 + V_88 ) ) ;
F_347 ( V_11 ) ;
return 0 ;
}
int T_3 F_362 ( unsigned long V_14 )
{
unsigned long V_96 , V_97 ;
int V_28 , V_179 ;
F_363 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
if ( V_96 <= V_14 && V_14 < V_97 )
return V_179 ;
return - 1 ;
}
int T_3 F_364 ( unsigned long V_14 )
{
int V_179 ;
V_179 = F_362 ( V_14 ) ;
if ( V_179 >= 0 )
return V_179 ;
return 0 ;
}
bool T_3 F_338 ( unsigned long V_14 , int V_176 )
{
int V_179 ;
V_179 = F_362 ( V_14 ) ;
if ( V_179 >= 0 && V_179 != V_176 )
return false ;
return true ;
}
void T_2 F_365 ( int V_179 , unsigned long V_379 )
{
unsigned long V_96 , V_97 ;
int V_28 , V_380 ;
F_363 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_96 = V_152 ( V_96 , V_379 ) ;
V_97 = V_152 ( V_97 , V_379 ) ;
if ( V_96 < V_97 )
F_366 ( F_195 ( V_380 ) ,
F_367 ( V_96 ) ,
( V_97 - V_96 ) << V_370 ) ;
}
}
void T_2 F_368 ( int V_179 )
{
unsigned long V_96 , V_97 ;
int V_28 , V_380 ;
F_363 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_369 ( V_380 , V_96 , V_97 ) ;
}
void T_3 F_370 ( unsigned int V_179 ,
unsigned long * V_96 , unsigned long * V_97 )
{
unsigned long V_381 , V_382 ;
int V_28 ;
* V_96 = - 1UL ;
* V_97 = 0 ;
F_363 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_96 = V_152 ( * V_96 , V_381 ) ;
* V_97 = F_329 ( * V_97 , V_382 ) ;
}
if ( * V_96 == - 1UL )
* V_96 = 0 ;
}
static void T_2 F_371 ( void )
{
int V_383 ;
for ( V_383 = V_305 - 1 ; V_383 >= 0 ; V_383 -- ) {
if ( V_383 == V_384 )
continue;
if ( V_385 [ V_383 ] >
V_386 [ V_383 ] )
break;
}
F_40 ( V_383 == - 1 ) ;
V_387 = V_383 ;
}
static void T_3 F_372 ( int V_179 ,
unsigned long V_217 ,
unsigned long V_388 ,
unsigned long V_389 ,
unsigned long * V_15 ,
unsigned long * V_390 )
{
if ( V_391 [ V_179 ] ) {
if ( V_217 == V_384 ) {
* V_15 = V_391 [ V_179 ] ;
* V_390 = V_152 ( V_389 ,
V_385 [ V_387 ] ) ;
} else if ( * V_15 < V_391 [ V_179 ] &&
* V_390 > V_391 [ V_179 ] ) {
* V_390 = V_391 [ V_179 ] ;
} else if ( * V_15 >= V_391 [ V_179 ] )
* V_15 = * V_390 ;
}
}
static unsigned long T_3 F_373 ( int V_179 ,
unsigned long V_217 ,
unsigned long * V_392 )
{
unsigned long V_388 , V_389 ;
unsigned long V_15 , V_390 ;
F_370 ( V_179 , & V_388 , & V_389 ) ;
V_15 = V_386 [ V_217 ] ;
V_390 = V_385 [ V_217 ] ;
F_372 ( V_179 , V_217 ,
V_388 , V_389 ,
& V_15 , & V_390 ) ;
if ( V_390 < V_388 || V_15 > V_389 )
return 0 ;
V_390 = V_152 ( V_390 , V_389 ) ;
V_15 = F_329 ( V_15 , V_388 ) ;
return V_390 - V_15 ;
}
unsigned long T_3 F_374 ( int V_179 ,
unsigned long V_393 ,
unsigned long V_394 )
{
unsigned long V_395 = V_394 - V_393 ;
unsigned long V_96 , V_97 ;
int V_28 ;
F_363 (i, nid, &start_pfn, &end_pfn, NULL) {
V_96 = F_375 ( V_96 , V_393 , V_394 ) ;
V_97 = F_375 ( V_97 , V_393 , V_394 ) ;
V_395 -= V_97 - V_96 ;
}
return V_395 ;
}
unsigned long T_2 F_376 ( unsigned long V_96 ,
unsigned long V_97 )
{
return F_374 ( V_336 , V_96 , V_97 ) ;
}
static unsigned long T_3 F_377 ( int V_179 ,
unsigned long V_217 ,
unsigned long * V_392 )
{
unsigned long V_396 = V_386 [ V_217 ] ;
unsigned long V_397 = V_385 [ V_217 ] ;
unsigned long V_388 , V_389 ;
unsigned long V_15 , V_390 ;
F_370 ( V_179 , & V_388 , & V_389 ) ;
V_15 = F_375 ( V_388 , V_396 , V_397 ) ;
V_390 = F_375 ( V_389 , V_396 , V_397 ) ;
F_372 ( V_179 , V_217 ,
V_388 , V_389 ,
& V_15 , & V_390 ) ;
return F_374 ( V_179 , V_15 , V_390 ) ;
}
static inline unsigned long T_3 F_373 ( int V_179 ,
unsigned long V_217 ,
unsigned long * V_398 )
{
return V_398 [ V_217 ] ;
}
static inline unsigned long T_3 F_377 ( int V_179 ,
unsigned long V_217 ,
unsigned long * V_399 )
{
if ( ! V_399 )
return 0 ;
return V_399 [ V_217 ] ;
}
static void T_3 F_378 ( struct V_373 * V_277 ,
unsigned long * V_398 , unsigned long * V_399 )
{
unsigned long V_400 , V_401 = 0 ;
enum V_217 V_28 ;
for ( V_28 = 0 ; V_28 < V_305 ; V_28 ++ )
V_401 += F_373 ( V_277 -> V_352 , V_28 ,
V_398 ) ;
V_277 -> V_402 = V_401 ;
V_400 = V_401 ;
for ( V_28 = 0 ; V_28 < V_305 ; V_28 ++ )
V_400 -=
F_377 ( V_277 -> V_352 , V_28 ,
V_399 ) ;
V_277 -> V_278 = V_400 ;
F_21 ( V_377 L_70 , V_277 -> V_352 ,
V_400 ) ;
}
static unsigned long T_2 F_379 ( unsigned long V_15 , unsigned long V_403 )
{
unsigned long V_404 ;
V_403 += V_15 & ( V_80 - 1 ) ;
V_404 = F_335 ( V_403 , V_80 ) ;
V_404 = V_404 >> V_82 ;
V_404 *= V_405 ;
V_404 = F_335 ( V_404 , 8 * sizeof( unsigned long ) ) ;
return V_404 / 8 ;
}
static void T_2 F_380 ( struct V_373 * V_277 ,
struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_403 )
{
unsigned long V_404 = F_379 ( V_15 , V_403 ) ;
V_11 -> V_406 = NULL ;
if ( V_404 )
V_11 -> V_406 = F_356 ( V_277 ,
V_404 ) ;
}
static inline void F_380 ( struct V_373 * V_277 , struct V_11 * V_11 ,
unsigned long V_15 , unsigned long V_403 ) {}
void T_2 F_381 ( void )
{
unsigned int V_27 ;
if ( V_82 )
return;
if ( V_407 > V_370 )
V_27 = V_408 ;
else
V_27 = V_37 - 1 ;
V_82 = V_27 ;
}
void T_2 F_381 ( void )
{
}
static unsigned long T_7 F_382 ( unsigned long V_16 ,
unsigned long V_265 )
{
unsigned long V_105 = V_16 ;
if ( V_16 > V_265 + ( V_265 >> 4 ) &&
F_127 ( V_409 ) )
V_105 = V_265 ;
return F_262 ( V_105 * sizeof( struct V_5 ) ) >> V_370 ;
}
static void T_7 F_383 ( struct V_373 * V_277 ,
unsigned long * V_398 , unsigned long * V_399 )
{
enum V_217 V_338 ;
int V_179 = V_277 -> V_352 ;
unsigned long V_15 = V_277 -> V_388 ;
int V_12 ;
F_384 ( V_277 ) ;
#ifdef F_385
F_386 ( & V_277 -> V_410 ) ;
V_277 -> V_411 = 0 ;
V_277 -> V_412 = V_20 ;
#endif
F_358 ( & V_277 -> V_413 ) ;
F_358 ( & V_277 -> V_414 ) ;
F_387 ( V_277 ) ;
for ( V_338 = 0 ; V_338 < V_305 ; V_338 ++ ) {
struct V_11 * V_11 = V_277 -> V_279 + V_338 ;
unsigned long V_88 , V_415 , V_416 , V_417 ;
V_88 = F_373 ( V_179 , V_338 , V_398 ) ;
V_415 = V_416 = V_88 - F_377 ( V_179 , V_338 ,
V_399 ) ;
V_417 = F_382 ( V_88 , V_415 ) ;
if ( V_416 >= V_417 ) {
V_416 -= V_417 ;
if ( V_417 )
F_21 ( V_377
L_71 ,
V_360 [ V_338 ] , V_417 ) ;
} else
F_21 ( V_315
L_72 ,
V_360 [ V_338 ] , V_417 , V_416 ) ;
if ( V_338 == 0 && V_416 > V_418 ) {
V_416 -= V_418 ;
F_21 ( V_377 L_73 ,
V_360 [ 0 ] , V_418 ) ;
}
if ( ! F_344 ( V_338 ) )
V_419 += V_416 ;
else if ( V_419 > V_417 * 2 )
V_419 -= V_417 ;
V_420 += V_416 ;
V_11 -> V_16 = V_88 ;
V_11 -> V_265 = V_416 ;
V_11 -> V_79 = F_344 ( V_338 ) ? V_415 : V_416 ;
#ifdef V_187
V_11 -> V_176 = V_179 ;
V_11 -> V_421 = ( V_416 * V_422 )
/ 100 ;
V_11 -> V_423 = ( V_416 * V_424 ) / 100 ;
#endif
V_11 -> V_284 = V_360 [ V_338 ] ;
F_386 ( & V_11 -> V_64 ) ;
F_386 ( & V_11 -> V_425 ) ;
F_388 ( V_11 ) ;
V_11 -> V_177 = V_277 ;
F_359 ( V_11 ) ;
F_389 ( & V_11 -> V_426 ) ;
if ( ! V_88 )
continue;
F_381 () ;
F_380 ( V_277 , V_11 , V_15 , V_88 ) ;
V_12 = F_360 ( V_11 , V_15 ,
V_88 , V_369 ) ;
F_115 ( V_12 ) ;
F_390 ( V_88 , V_179 , V_338 , V_15 ) ;
V_15 += V_88 ;
}
}
static void T_16 F_391 ( struct V_373 * V_277 )
{
if ( ! V_277 -> V_402 )
return;
#ifdef F_392
if ( ! V_277 -> V_427 ) {
unsigned long V_88 , V_428 , V_261 ;
struct V_5 * V_429 ;
V_428 = V_277 -> V_388 & ~ ( V_430 - 1 ) ;
V_261 = V_277 -> V_388 + V_277 -> V_402 ;
V_261 = F_393 ( V_261 , V_430 ) ;
V_88 = ( V_261 - V_428 ) * sizeof( struct V_5 ) ;
V_429 = F_394 ( V_277 -> V_352 , V_88 ) ;
if ( ! V_429 )
V_429 = F_356 ( V_277 , V_88 ) ;
V_277 -> V_427 = V_429 + ( V_277 -> V_388 - V_428 ) ;
}
#ifndef F_395
if ( V_277 == F_195 ( 0 ) ) {
V_431 = F_195 ( 0 ) -> V_427 ;
#ifdef F_396
if ( F_10 ( V_431 ) != V_277 -> V_388 )
V_431 -= ( V_277 -> V_388 - V_432 ) ;
#endif
}
#endif
#endif
}
void T_7 F_397 ( int V_179 , unsigned long * V_398 ,
unsigned long V_388 , unsigned long * V_399 )
{
T_10 * V_277 = F_195 ( V_179 ) ;
F_2 ( V_277 -> V_309 || V_277 -> V_149 ) ;
V_277 -> V_352 = V_179 ;
V_277 -> V_388 = V_388 ;
F_191 ( V_179 ) ;
F_378 ( V_277 , V_398 , V_399 ) ;
F_391 ( V_277 ) ;
#ifdef F_392
F_21 ( V_377 L_74 ,
V_179 , ( unsigned long ) V_277 ,
( unsigned long ) V_277 -> V_427 ) ;
#endif
F_383 ( V_277 , V_398 , V_399 ) ;
}
static void T_2 F_398 ( void )
{
unsigned int V_176 ;
unsigned int V_433 = 0 ;
F_399 (node, node_possible_map)
V_433 = V_176 ;
V_434 = V_433 + 1 ;
}
static inline void F_398 ( void )
{
}
unsigned long T_2 F_400 ( void )
{
unsigned long V_435 = 0 , V_436 = 0 ;
unsigned long V_428 , V_261 , V_437 ;
int V_438 = - 1 ;
int V_28 , V_179 ;
F_363 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_428 || V_438 < 0 || V_438 == V_179 ) {
V_438 = V_179 ;
V_436 = V_261 ;
continue;
}
V_437 = ~ ( ( 1 << F_401 ( V_428 ) ) - 1 ) ;
while ( V_437 && V_436 <= ( V_428 & ( V_437 << 1 ) ) )
V_437 <<= 1 ;
V_435 |= V_437 ;
}
return ~ V_435 + 1 ;
}
static unsigned long T_2 F_402 ( int V_179 )
{
unsigned long V_439 = V_440 ;
unsigned long V_96 ;
int V_28 ;
F_363 (i, nid, &start_pfn, NULL, NULL)
V_439 = V_152 ( V_439 , V_96 ) ;
if ( V_439 == V_440 ) {
F_21 ( V_315
L_75 , V_179 ) ;
return 0 ;
}
return V_439 ;
}
unsigned long T_2 F_403 ( void )
{
return F_402 ( V_336 ) ;
}
static unsigned long T_2 F_404 ( void )
{
unsigned long V_401 = 0 ;
unsigned long V_96 , V_97 ;
int V_28 , V_179 ;
F_363 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_105 = V_97 - V_96 ;
V_401 += V_105 ;
if ( V_105 )
F_405 ( V_179 , V_170 ) ;
}
return V_401 ;
}
static void T_2 F_406 ( void )
{
int V_28 , V_179 ;
unsigned long V_441 ;
unsigned long V_442 , V_443 ;
T_6 V_444 = V_169 [ V_170 ] ;
unsigned long V_401 = F_404 () ;
int V_445 = F_307 ( V_169 [ V_170 ] ) ;
if ( V_446 ) {
unsigned long V_447 ;
V_446 =
F_335 ( V_446 , V_430 ) ;
V_447 = V_401 - V_446 ;
V_448 = F_329 ( V_448 , V_447 ) ;
}
if ( ! V_448 )
goto V_21;
F_371 () ;
V_441 = V_386 [ V_387 ] ;
V_245:
V_442 = V_448 / V_445 ;
F_301 (nid, N_MEMORY) {
unsigned long V_96 , V_97 ;
if ( V_448 < V_442 )
V_442 = V_448 / V_445 ;
V_443 = V_442 ;
F_363 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_449 ;
V_96 = F_329 ( V_96 , V_391 [ V_179 ] ) ;
if ( V_96 >= V_97 )
continue;
if ( V_96 < V_441 ) {
unsigned long V_450 ;
V_450 = V_152 ( V_97 , V_441 )
- V_96 ;
V_443 -= V_152 ( V_450 ,
V_443 ) ;
V_448 -= V_152 ( V_450 ,
V_448 ) ;
if ( V_97 <= V_441 ) {
V_391 [ V_179 ] = V_97 ;
continue;
}
V_96 = V_441 ;
}
V_449 = V_97 - V_96 ;
if ( V_449 > V_443 )
V_449 = V_443 ;
V_391 [ V_179 ] = V_96 + V_449 ;
V_448 -= V_152 ( V_448 ,
V_449 ) ;
V_443 -= V_449 ;
if ( ! V_443 )
break;
}
}
V_445 -- ;
if ( V_445 && V_448 > V_445 )
goto V_245;
for ( V_179 = 0 ; V_179 < V_336 ; V_179 ++ )
V_391 [ V_179 ] =
F_335 ( V_391 [ V_179 ] , V_430 ) ;
V_21:
V_169 [ V_170 ] = V_444 ;
}
static void F_407 ( T_10 * V_277 , int V_179 )
{
enum V_217 V_217 ;
if ( V_170 == V_451 )
return;
for ( V_217 = 0 ; V_217 <= V_384 - 1 ; V_217 ++ ) {
struct V_11 * V_11 = & V_277 -> V_279 [ V_217 ] ;
if ( V_11 -> V_265 ) {
F_405 ( V_179 , V_452 ) ;
if ( V_451 != V_452 &&
V_217 <= V_220 )
F_405 ( V_179 , V_451 ) ;
break;
}
}
}
void T_2 F_408 ( unsigned long * V_118 )
{
unsigned long V_96 , V_97 ;
int V_28 , V_179 ;
memset ( V_386 , 0 ,
sizeof( V_386 ) ) ;
memset ( V_385 , 0 ,
sizeof( V_385 ) ) ;
V_386 [ 0 ] = F_403 () ;
V_385 [ 0 ] = V_118 [ 0 ] ;
for ( V_28 = 1 ; V_28 < V_305 ; V_28 ++ ) {
if ( V_28 == V_384 )
continue;
V_386 [ V_28 ] =
V_385 [ V_28 - 1 ] ;
V_385 [ V_28 ] =
F_329 ( V_118 [ V_28 ] , V_386 [ V_28 ] ) ;
}
V_386 [ V_384 ] = 0 ;
V_385 [ V_384 ] = 0 ;
memset ( V_391 , 0 , sizeof( V_391 ) ) ;
F_406 () ;
F_21 ( L_76 ) ;
for ( V_28 = 0 ; V_28 < V_305 ; V_28 ++ ) {
if ( V_28 == V_384 )
continue;
F_21 ( V_453 L_77 , V_360 [ V_28 ] ) ;
if ( V_386 [ V_28 ] ==
V_385 [ V_28 ] )
F_21 ( V_453 L_78 ) ;
else
F_21 ( V_453 L_79 ,
V_386 [ V_28 ] << V_370 ,
( V_385 [ V_28 ]
<< V_370 ) - 1 ) ;
}
F_21 ( L_80 ) ;
for ( V_28 = 0 ; V_28 < V_336 ; V_28 ++ ) {
if ( V_391 [ V_28 ] )
F_21 ( L_81 , V_28 ,
V_391 [ V_28 ] << V_370 ) ;
}
F_21 ( L_82 ) ;
F_363 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_21 ( L_83 , V_179 ,
V_96 << V_370 , ( V_97 << V_370 ) - 1 ) ;
F_409 () ;
F_398 () ;
F_192 (nid) {
T_10 * V_277 = F_195 ( V_179 ) ;
F_397 ( V_179 , NULL ,
F_402 ( V_179 ) , NULL ) ;
if ( V_277 -> V_278 )
F_405 ( V_179 , V_170 ) ;
F_407 ( V_277 , V_179 ) ;
}
}
static int T_2 F_410 ( char * V_30 , unsigned long * V_454 )
{
unsigned long long V_455 ;
if ( ! V_30 )
return - V_316 ;
V_455 = F_411 ( V_30 , & V_30 ) ;
* V_454 = V_455 >> V_370 ;
F_2 ( ( V_455 >> V_370 ) > V_440 ) ;
return 0 ;
}
static int T_2 F_412 ( char * V_30 )
{
return F_410 ( V_30 , & V_448 ) ;
}
static int T_2 F_413 ( char * V_30 )
{
return F_410 ( V_30 , & V_446 ) ;
}
void T_2 F_414 ( unsigned long V_456 )
{
V_418 = V_456 ;
}
void T_2 F_415 ( unsigned long * V_398 )
{
F_397 ( 0 , V_398 ,
F_416 ( V_457 ) >> V_370 , NULL ) ;
}
static int F_417 ( struct V_458 * V_354 ,
unsigned long V_459 , void * V_460 )
{
int V_111 = ( unsigned long ) V_460 ;
if ( V_459 == V_461 || V_459 == V_462 ) {
F_418 ( V_111 ) ;
F_129 ( V_111 ) ;
F_419 ( V_111 ) ;
F_420 ( V_111 ) ;
}
return V_463 ;
}
void T_2 F_421 ( void )
{
F_422 ( F_417 , 0 ) ;
}
static void F_423 ( void )
{
struct V_373 * V_277 ;
unsigned long V_464 = 0 ;
enum V_217 V_28 , V_338 ;
F_424 (pgdat) {
for ( V_28 = 0 ; V_28 < V_305 ; V_28 ++ ) {
struct V_11 * V_11 = V_277 -> V_279 + V_28 ;
unsigned long F_329 = 0 ;
for ( V_338 = V_28 ; V_338 < V_305 ; V_338 ++ ) {
if ( V_11 -> V_153 [ V_338 ] > F_329 )
F_329 = V_11 -> V_153 [ V_338 ] ;
}
F_329 += F_270 ( V_11 ) ;
if ( F_329 > V_11 -> V_265 )
F_329 = V_11 -> V_265 ;
V_464 += F_329 ;
V_11 -> V_465 = F_329 ;
}
}
V_465 = V_464 ;
V_466 = V_464 ;
}
static void F_425 ( void )
{
struct V_373 * V_277 ;
enum V_217 V_338 , V_467 ;
F_424 (pgdat) {
for ( V_338 = 0 ; V_338 < V_305 ; V_338 ++ ) {
struct V_11 * V_11 = V_277 -> V_279 + V_338 ;
unsigned long V_265 = V_11 -> V_265 ;
V_11 -> V_153 [ V_338 ] = 0 ;
V_467 = V_338 ;
while ( V_467 ) {
struct V_11 * V_468 ;
V_467 -- ;
if ( V_469 [ V_467 ] < 1 )
V_469 [ V_467 ] = 1 ;
V_468 = V_277 -> V_279 + V_467 ;
V_468 -> V_153 [ V_338 ] = V_265 /
V_469 [ V_467 ] ;
V_265 += V_468 -> V_265 ;
}
}
}
F_423 () ;
}
static void F_426 ( void )
{
unsigned long V_470 = V_471 >> ( V_370 - 10 ) ;
unsigned long V_472 = 0 ;
struct V_11 * V_11 ;
unsigned long V_56 ;
F_427 (zone) {
if ( ! F_428 ( V_11 ) )
V_472 += V_11 -> V_265 ;
}
F_427 (zone) {
T_17 V_283 ;
F_140 ( & V_11 -> V_64 , V_56 ) ;
V_283 = ( T_17 ) V_470 * V_11 -> V_265 ;
F_429 ( V_283 , V_472 ) ;
if ( F_428 ( V_11 ) ) {
int V_473 ;
V_473 = V_11 -> V_265 / 1024 ;
if ( V_473 < V_474 )
V_473 = V_474 ;
if ( V_473 > 128 )
V_473 = 128 ;
V_11 -> V_123 [ V_475 ] = V_473 ;
} else {
V_11 -> V_123 [ V_475 ] = V_283 ;
}
V_11 -> V_123 [ V_476 ] = F_284 ( V_11 ) + ( V_283 >> 2 ) ;
V_11 -> V_123 [ V_477 ] = F_284 ( V_11 ) + ( V_283 >> 1 ) ;
F_334 ( V_11 ) ;
F_147 ( & V_11 -> V_64 , V_56 ) ;
}
F_423 () ;
}
void F_430 ( void )
{
F_295 ( & V_328 ) ;
F_426 () ;
F_298 ( & V_328 ) ;
}
static void T_3 F_431 ( struct V_11 * V_11 )
{
unsigned int V_478 , V_479 ;
V_478 = V_11 -> V_265 >> ( 30 - V_370 ) ;
if ( V_478 )
V_479 = F_432 ( 10 * V_478 ) ;
else
V_479 = 1 ;
V_11 -> V_480 = V_479 ;
}
static void T_3 F_433 ( void )
{
struct V_11 * V_11 ;
F_427 (zone)
F_431 ( V_11 ) ;
}
int T_3 F_434 ( void )
{
unsigned long V_481 ;
V_481 = F_271 () * ( V_76 >> 10 ) ;
V_471 = F_432 ( V_481 * 16 ) ;
if ( V_471 < 128 )
V_471 = 128 ;
if ( V_471 > 65536 )
V_471 = 65536 ;
F_430 () ;
F_435 () ;
F_425 () ;
F_433 () ;
return 0 ;
}
int F_436 ( T_11 * V_319 , int V_320 ,
void T_12 * V_321 , T_9 * V_322 , T_13 * V_323 )
{
F_437 ( V_319 , V_320 , V_321 , V_322 , V_323 ) ;
if ( V_320 )
F_430 () ;
return 0 ;
}
int F_438 ( T_11 * V_319 , int V_320 ,
void T_12 * V_321 , T_9 * V_322 , T_13 * V_323 )
{
struct V_11 * V_11 ;
int V_482 ;
V_482 = F_439 ( V_319 , V_320 , V_321 , V_322 , V_323 ) ;
if ( V_482 )
return V_482 ;
F_427 (zone)
V_11 -> V_421 = ( V_11 -> V_265 *
V_422 ) / 100 ;
return 0 ;
}
int F_440 ( T_11 * V_319 , int V_320 ,
void T_12 * V_321 , T_9 * V_322 , T_13 * V_323 )
{
struct V_11 * V_11 ;
int V_482 ;
V_482 = F_439 ( V_319 , V_320 , V_321 , V_322 , V_323 ) ;
if ( V_482 )
return V_482 ;
F_427 (zone)
V_11 -> V_423 = ( V_11 -> V_265 *
V_424 ) / 100 ;
return 0 ;
}
int F_441 ( T_11 * V_319 , int V_320 ,
void T_12 * V_321 , T_9 * V_322 , T_13 * V_323 )
{
F_439 ( V_319 , V_320 , V_321 , V_322 , V_323 ) ;
F_425 () ;
return 0 ;
}
int F_442 ( T_11 * V_319 , int V_320 ,
void T_12 * V_321 , T_9 * V_322 , T_13 * V_323 )
{
struct V_11 * V_11 ;
unsigned int V_111 ;
int V_12 ;
V_12 = F_439 ( V_319 , V_320 , V_321 , V_322 , V_323 ) ;
if ( ! V_320 || ( V_12 < 0 ) )
return V_12 ;
F_130 (zone) {
F_316 (cpu) {
unsigned long V_86 ;
V_86 = V_11 -> V_265 / V_371 ;
F_351 (
F_131 ( V_11 -> V_114 , V_111 ) , V_86 ) ;
}
}
return 0 ;
}
static int T_2 F_443 ( char * V_131 )
{
if ( ! V_131 )
return 0 ;
V_483 = F_444 ( V_131 , & V_131 , 0 ) ;
return 1 ;
}
void * T_2 F_445 ( const char * V_484 ,
unsigned long V_485 ,
unsigned long V_486 ,
int V_487 ,
int V_56 ,
unsigned int * V_488 ,
unsigned int * V_489 ,
unsigned long V_490 ,
unsigned long V_491 )
{
unsigned long long F_329 = V_491 ;
unsigned long V_492 , V_88 ;
void * V_319 = NULL ;
if ( ! V_486 ) {
V_486 = V_419 ;
V_486 += ( 1UL << ( 20 - V_370 ) ) - 1 ;
V_486 >>= 20 - V_370 ;
V_486 <<= 20 - V_370 ;
if ( V_487 > V_370 )
V_486 >>= ( V_487 - V_370 ) ;
else
V_486 <<= ( V_370 - V_487 ) ;
if ( F_7 ( V_56 & V_493 ) ) {
F_2 ( ! ( V_56 & V_494 ) ) ;
if ( ! ( V_486 >> * V_488 ) ) {
V_486 = 1UL << * V_488 ;
F_115 ( ! V_486 ) ;
}
} else if ( F_7 ( ( V_486 * V_485 ) < V_76 ) )
V_486 = V_76 / V_485 ;
}
V_486 = F_446 ( V_486 ) ;
if ( F_329 == 0 ) {
F_329 = ( ( unsigned long long ) V_420 << V_370 ) >> 4 ;
F_429 ( F_329 , V_485 ) ;
}
F_329 = V_152 ( F_329 , 0x80000000ULL ) ;
if ( V_486 < V_490 )
V_486 = V_490 ;
if ( V_486 > F_329 )
V_486 = F_329 ;
V_492 = F_447 ( V_486 ) ;
do {
V_88 = V_485 << V_492 ;
if ( V_56 & V_494 )
V_319 = F_448 ( V_88 ) ;
else if ( V_483 )
V_319 = F_449 ( V_88 , V_495 , V_496 ) ;
else {
if ( F_265 ( V_88 ) < V_37 ) {
V_319 = F_264 ( V_88 , V_495 ) ;
F_450 ( V_319 , V_88 , 1 , V_495 ) ;
}
}
} while ( ! V_319 && V_88 > V_76 && -- V_492 );
if ( ! V_319 )
F_451 ( L_84 , V_484 ) ;
F_21 ( V_40 L_85 ,
V_484 ,
( 1UL << V_492 ) ,
F_447 ( V_88 ) - V_370 ,
V_88 ) ;
if ( V_488 )
* V_488 = V_492 ;
if ( V_489 )
* V_489 = ( 1 << V_492 ) - 1 ;
return V_319 ;
}
static inline unsigned long * F_452 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef V_409
return F_453 ( V_14 ) -> V_406 ;
#else
return V_11 -> V_406 ;
#endif
}
static inline int F_454 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef V_409
V_14 &= ( V_497 - 1 ) ;
return ( V_14 >> V_82 ) * V_405 ;
#else
V_14 = V_14 - F_455 ( V_11 -> V_15 , V_80 ) ;
return ( V_14 >> V_82 ) * V_405 ;
#endif
}
unsigned long F_456 ( struct V_5 * V_5 ,
int V_498 , int V_499 )
{
struct V_11 * V_11 ;
unsigned long * V_500 ;
unsigned long V_14 , V_501 ;
unsigned long V_56 = 0 ;
unsigned long V_502 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_500 = F_452 ( V_11 , V_14 ) ;
V_501 = F_454 ( V_11 , V_14 ) ;
for (; V_498 <= V_499 ; V_498 ++ , V_502 <<= 1 )
if ( F_186 ( V_501 + V_498 , V_500 ) )
V_56 |= V_502 ;
return V_56 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_56 ,
int V_498 , int V_499 )
{
struct V_11 * V_11 ;
unsigned long * V_500 ;
unsigned long V_14 , V_501 ;
unsigned long V_502 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_500 = F_452 ( V_11 , V_14 ) ;
V_501 = F_454 ( V_11 , V_14 ) ;
F_40 ( V_14 < V_11 -> V_15 ) ;
F_40 ( V_14 >= V_11 -> V_15 + V_11 -> V_16 ) ;
for (; V_498 <= V_499 ; V_498 ++ , V_502 <<= 1 )
if ( V_56 & V_502 )
F_46 ( V_501 + V_498 , V_500 ) ;
else
F_48 ( V_501 + V_498 , V_500 ) ;
}
bool F_457 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_59 ,
bool V_503 )
{
unsigned long V_14 , V_504 , V_505 ;
int V_71 ;
if ( F_197 ( V_11 ) == V_384 )
return false ;
V_71 = F_79 ( V_5 ) ;
if ( V_71 == V_121 || F_81 ( V_71 ) )
return false ;
V_14 = F_10 ( V_5 ) ;
for ( V_505 = 0 , V_504 = 0 ; V_504 < V_80 ; V_504 ++ ) {
unsigned long V_506 = V_14 + V_504 ;
if ( ! F_14 ( V_506 ) )
continue;
V_5 = F_120 ( V_506 ) ;
if ( ! F_69 ( & V_5 -> V_55 ) ) {
if ( F_60 ( V_5 ) )
V_504 += ( 1 << F_58 ( V_5 ) ) - 1 ;
continue;
}
if ( V_503 && F_18 ( V_5 ) )
continue;
if ( ! F_458 ( V_5 ) )
V_505 ++ ;
if ( V_505 > V_59 )
return true ;
}
return false ;
}
bool F_459 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_314 ( F_116 ( V_5 ) ) )
return false ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( V_11 -> V_15 > V_14 ||
V_11 -> V_15 + V_11 -> V_16 <= V_14 )
return false ;
return ! F_457 ( V_11 , V_5 , 0 , true ) ;
}
static unsigned long F_460 ( unsigned long V_14 )
{
return V_14 & ~ ( F_461 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_462 ( unsigned long V_14 )
{
return F_393 ( V_14 , F_461 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_463 ( struct V_507 * V_508 ,
unsigned long V_428 , unsigned long V_261 )
{
unsigned long V_509 ;
unsigned long V_14 = V_428 ;
unsigned int V_510 = 0 ;
int V_12 = 0 ;
F_464 () ;
while ( V_14 < V_261 || ! F_74 ( & V_508 -> V_511 ) ) {
if ( F_465 ( V_24 ) ) {
V_12 = - V_512 ;
break;
}
if ( F_74 ( & V_508 -> V_511 ) ) {
V_508 -> V_513 = 0 ;
V_14 = F_466 ( V_508 -> V_11 , V_508 ,
V_14 , V_261 , true ) ;
if ( ! V_14 ) {
V_12 = - V_512 ;
break;
}
V_510 = 0 ;
} else if ( ++ V_510 == 5 ) {
V_12 = V_12 < 0 ? V_12 : - V_514 ;
break;
}
V_509 = F_467 ( V_508 -> V_11 ,
& V_508 -> V_511 ) ;
V_508 -> V_513 -= V_509 ;
V_12 = F_468 ( & V_508 -> V_511 ,
V_515 ,
0 , false , V_516 ,
V_517 ) ;
}
F_469 ( & V_508 -> V_511 ) ;
return V_12 > 0 ? 0 : V_12 ;
}
int F_470 ( unsigned long V_428 , unsigned long V_261 ,
unsigned V_6 )
{
unsigned long V_518 , V_519 ;
int V_12 = 0 , V_27 ;
struct V_507 V_508 = {
. V_513 = 0 ,
. V_27 = - 1 ,
. V_11 = F_15 ( F_120 ( V_428 ) ) ,
. V_520 = true ,
. V_521 = true ,
} ;
F_108 ( & V_508 . V_511 ) ;
V_12 = F_471 ( F_460 ( V_428 ) ,
F_462 ( V_261 ) , V_6 ,
false ) ;
if ( V_12 )
return V_12 ;
V_12 = F_463 ( & V_508 , V_428 , V_261 ) ;
if ( V_12 )
goto V_522;
F_472 () ;
F_134 () ;
V_27 = 0 ;
V_518 = V_428 ;
while ( ! F_60 ( F_120 ( V_518 ) ) ) {
if ( ++ V_27 >= V_37 ) {
V_12 = - V_514 ;
goto V_522;
}
V_518 &= ~ 0UL << V_27 ;
}
if ( F_473 ( V_518 , V_261 , false ) ) {
F_207 ( L_86 ,
V_518 , V_261 ) ;
V_12 = - V_514 ;
goto V_522;
}
V_519 = F_474 ( & V_508 , V_518 , V_261 ) ;
if ( ! V_519 ) {
V_12 = - V_514 ;
goto V_522;
}
if ( V_428 != V_518 )
F_475 ( V_518 , V_428 - V_518 ) ;
if ( V_261 != V_519 )
F_475 ( V_261 , V_519 - V_261 ) ;
V_522:
F_476 ( F_460 ( V_428 ) ,
F_462 ( V_261 ) , V_6 ) ;
return V_12 ;
}
void F_475 ( unsigned long V_14 , unsigned V_29 )
{
unsigned int V_59 = 0 ;
for (; V_29 -- ; V_14 ++ ) {
struct V_5 * V_5 = F_120 ( V_14 ) ;
V_59 += F_59 ( V_5 ) != 1 ;
F_477 ( V_5 ) ;
}
F_478 ( V_59 != 0 , L_87 , V_59 ) ;
}
static int T_3 F_479 ( void * V_326 )
{
struct V_11 * V_11 = V_326 ;
int V_111 ;
unsigned long V_110 = F_348 ( V_11 ) , V_56 ;
F_316 (cpu) {
struct V_112 * V_113 ;
struct V_60 * V_61 ;
V_113 = F_131 ( V_11 -> V_114 , V_111 ) ;
V_61 = & V_113 -> V_61 ;
F_94 ( V_56 ) ;
if ( V_61 -> V_59 > 0 )
F_72 ( V_11 , V_61 -> V_59 , V_61 ) ;
F_480 ( V_11 , V_113 ) ;
F_317 ( V_113 , V_110 ) ;
F_97 ( V_56 ) ;
}
return 0 ;
}
void T_3 F_481 ( struct V_11 * V_11 )
{
F_327 ( F_479 , V_11 , NULL ) ;
}
void F_482 ( struct V_11 * V_11 )
{
unsigned long V_56 ;
int V_111 ;
struct V_112 * V_113 ;
F_94 ( V_56 ) ;
if ( V_11 -> V_114 != & V_355 ) {
F_135 (cpu) {
V_113 = F_131 ( V_11 -> V_114 , V_111 ) ;
F_480 ( V_11 , V_113 ) ;
}
F_483 ( V_11 -> V_114 ) ;
V_11 -> V_114 = & V_355 ;
}
F_97 ( V_56 ) ;
}
void
F_484 ( unsigned long V_96 , unsigned long V_97 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_27 , V_28 ;
unsigned long V_14 ;
unsigned long V_56 ;
for ( V_14 = V_96 ; V_14 < V_97 ; V_14 ++ )
if ( F_141 ( V_14 ) )
break;
if ( V_14 == V_97 )
return;
V_11 = F_15 ( F_120 ( V_14 ) ) ;
F_140 ( & V_11 -> V_64 , V_56 ) ;
V_14 = V_96 ;
while ( V_14 < V_97 ) {
if ( ! F_141 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_120 ( V_14 ) ;
if ( F_7 ( ! F_60 ( V_5 ) && F_18 ( V_5 ) ) ) {
V_14 ++ ;
F_342 ( V_5 ) ;
continue;
}
F_115 ( F_59 ( V_5 ) ) ;
F_115 ( ! F_60 ( V_5 ) ) ;
V_27 = F_58 ( V_5 ) ;
#ifdef F_485
F_21 ( V_40 L_88 ,
V_14 , 1 << V_27 , V_97 ) ;
#endif
F_64 ( & V_5 -> V_48 ) ;
F_52 ( V_5 ) ;
V_11 -> V_49 [ V_27 ] . V_50 -- ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_342 ( ( V_5 + V_28 ) ) ;
V_14 += ( 1 << V_27 ) ;
}
F_147 ( & V_11 -> V_64 , V_56 ) ;
}
bool F_486 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_15 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_56 ;
int V_27 ;
F_140 ( & V_11 -> V_64 , V_56 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
struct V_5 * V_523 = V_5 - ( V_14 & ( ( 1 << V_27 ) - 1 ) ) ;
if ( F_60 ( V_523 ) && F_58 ( V_523 ) >= V_27 )
break;
}
F_147 ( & V_11 -> V_64 , V_56 ) ;
return V_27 < V_37 ;
}
static void F_487 ( unsigned long V_56 )
{
const char * V_524 = L_89 ;
unsigned long V_437 ;
int V_28 ;
F_201 ( F_488 ( V_525 ) != V_526 ) ;
F_21 ( V_22 L_90 , V_56 ) ;
V_56 &= ( 1UL << V_527 ) - 1 ;
for ( V_28 = 0 ; V_28 < F_488 ( V_525 ) && V_56 ; V_28 ++ ) {
V_437 = V_525 [ V_28 ] . V_437 ;
if ( ( V_56 & V_437 ) != V_437 )
continue;
V_56 &= ~ V_437 ;
F_21 ( L_91 , V_524 , V_525 [ V_28 ] . V_284 ) ;
V_524 = L_92 ;
}
if ( V_56 )
F_21 ( L_93 , V_524 , V_56 ) ;
F_21 ( L_94 ) ;
}
void F_22 ( struct V_5 * V_5 )
{
F_21 ( V_22
L_95 ,
V_5 , F_69 ( & V_5 -> V_55 ) , F_68 ( V_5 ) ,
V_5 -> V_54 , V_5 -> V_528 ) ;
F_487 ( V_5 -> V_56 ) ;
F_489 ( V_5 ) ;
}
