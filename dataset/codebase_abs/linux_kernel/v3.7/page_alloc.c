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
F_64 ( V_11 , 1 << V_27 ,
V_6 ) ;
} else {
F_65 ( & V_44 -> V_48 ) ;
V_11 -> V_49 [ V_27 ] . V_50 -- ;
F_53 ( V_44 ) ;
}
V_45 = V_47 & V_43 ;
V_5 = V_5 + ( V_45 - V_43 ) ;
V_43 = V_45 ;
V_27 ++ ;
}
F_50 ( V_5 , V_27 ) ;
if ( ( V_27 < V_37 - 2 ) && F_14 ( F_10 ( V_44 ) ) ) {
struct V_5 * V_51 , * V_52 ;
V_45 = V_47 & V_43 ;
V_51 = V_5 + ( V_45 - V_43 ) ;
V_47 = F_55 ( V_45 , V_27 + 1 ) ;
V_52 = V_51 + ( V_47 - V_45 ) ;
if ( F_56 ( V_51 , V_52 , V_27 + 1 ) ) {
F_66 ( & V_5 -> V_48 ,
& V_11 -> V_49 [ V_27 ] . V_53 [ V_6 ] ) ;
goto V_21;
}
}
F_67 ( & V_5 -> V_48 , & V_11 -> V_49 [ V_27 ] . V_53 [ V_6 ] ) ;
V_21:
V_11 -> V_49 [ V_27 ] . V_50 ++ ;
}
static inline int F_68 ( struct V_5 * V_5 )
{
if ( F_7 ( F_69 ( V_5 ) |
( V_5 -> V_54 != NULL ) |
( F_70 ( & V_5 -> V_55 ) != 0 ) |
( V_5 -> V_56 & V_57 ) |
( F_71 ( V_5 ) ) ) ) {
F_17 ( V_5 ) ;
return 1 ;
}
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
F_65 ( & V_5 -> V_48 ) ;
V_71 = F_76 ( V_5 ) ;
F_62 ( V_5 , V_11 , 0 , V_71 ) ;
F_77 ( V_5 , 0 , V_71 ) ;
if ( F_78 ( V_71 ) )
F_79 ( V_11 , V_73 , 1 ) ;
} while ( -- V_63 && -- V_62 && ! F_74 ( V_68 ) );
}
F_79 ( V_11 , V_74 , V_59 ) ;
F_80 ( & V_11 -> V_64 ) ;
}
static void F_81 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_27 ,
int V_6 )
{
F_73 ( & V_11 -> V_64 ) ;
V_11 -> V_65 = 0 ;
V_11 -> V_66 = 0 ;
F_62 ( V_5 , V_11 , V_27 , V_6 ) ;
if ( F_7 ( V_6 != V_75 ) )
F_64 ( V_11 , 1 << V_27 , V_6 ) ;
F_80 ( & V_11 -> V_64 ) ;
}
static bool F_82 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
int V_32 = 0 ;
F_83 ( V_5 , V_27 ) ;
F_84 ( V_5 , V_27 ) ;
if ( F_85 ( V_5 ) )
V_5 -> V_54 = NULL ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
V_32 += F_68 ( V_5 + V_28 ) ;
if ( V_32 )
return false ;
if ( ! F_86 ( V_5 ) ) {
F_87 ( F_88 ( V_5 ) , V_76 << V_27 ) ;
F_89 ( F_88 ( V_5 ) ,
V_76 << V_27 ) ;
}
F_90 ( V_5 , V_27 ) ;
F_91 ( V_5 , 1 << V_27 , 0 ) ;
return true ;
}
static void F_27 ( struct V_5 * V_5 , unsigned int V_27 )
{
unsigned long V_56 ;
int V_6 ;
if ( ! F_82 ( V_5 , V_27 ) )
return;
F_92 ( V_56 ) ;
F_93 ( V_77 , 1 << V_27 ) ;
V_6 = F_94 ( V_5 ) ;
F_95 ( V_5 , V_6 ) ;
F_81 ( F_15 ( V_5 ) , V_5 , V_27 , V_6 ) ;
F_96 ( V_56 ) ;
}
void T_3 F_97 ( struct V_5 * V_5 , unsigned int V_27 )
{
unsigned int V_29 = 1 << V_27 ;
unsigned int V_78 ;
F_98 ( V_5 ) ;
for ( V_78 = 0 ; V_78 < V_29 ; V_78 ++ ) {
struct V_5 * V_30 = & V_5 [ V_78 ] ;
if ( V_78 + 1 < V_29 )
F_98 ( V_30 + 1 ) ;
F_99 ( V_30 ) ;
F_34 ( V_30 , 0 ) ;
}
F_100 ( V_5 ) ;
F_101 ( V_5 , V_27 ) ;
}
void T_2 F_102 ( struct V_5 * V_5 )
{
unsigned V_28 = V_79 ;
struct V_5 * V_30 = V_5 ;
do {
F_99 ( V_30 ) ;
F_34 ( V_30 , 0 ) ;
} while ( ++ V_30 , -- V_28 );
F_100 ( V_5 ) ;
F_6 ( V_5 , V_80 ) ;
F_101 ( V_5 , V_81 ) ;
V_82 += V_79 ;
}
static inline void F_103 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_83 , int V_84 , struct V_49 * V_85 ,
int V_6 )
{
unsigned long V_86 = 1 << V_84 ;
while ( V_84 > V_83 ) {
V_85 -- ;
V_84 -- ;
V_86 >>= 1 ;
F_41 ( F_16 ( V_11 , & V_5 [ V_86 ] ) ) ;
#ifdef F_104
if ( V_84 < F_105 () ) {
F_106 ( & V_5 [ V_86 ] . V_48 ) ;
F_46 ( & V_5 [ V_86 ] ) ;
F_51 ( & V_5 [ V_86 ] , V_84 ) ;
F_64 ( V_11 , - ( 1 << V_84 ) ,
V_6 ) ;
continue;
}
#endif
F_67 ( & V_5 [ V_86 ] . V_48 , & V_85 -> V_53 [ V_6 ] ) ;
V_85 -> V_50 ++ ;
F_50 ( & V_5 [ V_86 ] , V_84 ) ;
}
}
static inline int F_107 ( struct V_5 * V_5 )
{
if ( F_7 ( F_69 ( V_5 ) |
( V_5 -> V_54 != NULL ) |
( F_70 ( & V_5 -> V_55 ) != 0 ) |
( V_5 -> V_56 & V_58 ) |
( F_71 ( V_5 ) ) ) ) {
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
F_100 ( V_5 ) ;
F_109 ( V_5 , V_27 ) ;
F_91 ( V_5 , 1 << V_27 , 1 ) ;
if ( V_33 & V_87 )
F_40 ( V_5 , V_27 , V_33 ) ;
if ( V_27 && ( V_33 & V_88 ) )
F_29 ( V_5 , V_27 ) ;
return 0 ;
}
static inline
struct V_5 * F_110 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned int V_89 ;
struct V_49 * V_85 ;
struct V_5 * V_5 ;
for ( V_89 = V_27 ; V_89 < V_37 ; ++ V_89 ) {
V_85 = & ( V_11 -> V_49 [ V_89 ] ) ;
if ( F_74 ( & V_85 -> V_53 [ V_6 ] ) )
continue;
V_5 = F_75 ( V_85 -> V_53 [ V_6 ] . V_90 ,
struct V_5 , V_48 ) ;
F_65 ( & V_5 -> V_48 ) ;
F_53 ( V_5 ) ;
V_85 -> V_50 -- ;
F_103 ( V_11 , V_5 , V_27 , V_89 , V_85 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_111 ( struct V_11 * V_11 ,
struct V_5 * V_91 , struct V_5 * V_92 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_27 ;
int V_93 = 0 ;
#ifndef F_112
F_113 ( F_15 ( V_91 ) != F_15 ( V_92 ) ) ;
#endif
for ( V_5 = V_91 ; V_5 <= V_92 ; ) {
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
F_116 ( & V_5 -> V_48 ,
& V_11 -> V_49 [ V_27 ] . V_53 [ V_6 ] ) ;
F_95 ( V_5 , V_6 ) ;
V_5 += 1 << V_27 ;
V_93 += 1 << V_27 ;
}
return V_93 ;
}
int F_117 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_94 , V_95 ;
struct V_5 * V_91 , * V_92 ;
V_94 = F_10 ( V_5 ) ;
V_94 = V_94 & ~ ( V_79 - 1 ) ;
V_91 = F_118 ( V_94 ) ;
V_92 = V_91 + V_79 - 1 ;
V_95 = V_94 + V_79 - 1 ;
if ( V_94 < V_11 -> V_15 )
V_91 = V_5 ;
if ( V_95 >= V_11 -> V_15 + V_11 -> V_16 )
return 0 ;
return F_111 ( V_11 , V_91 , V_92 , V_6 ) ;
}
static void F_119 ( struct V_5 * V_96 ,
int V_97 , int V_6 )
{
int V_98 = 1 << ( V_97 - V_81 ) ;
while ( V_98 -- ) {
F_6 ( V_96 , V_6 ) ;
V_96 += V_79 ;
}
}
static inline struct V_5 *
F_120 ( struct V_11 * V_11 , int V_27 , int V_99 )
{
struct V_49 * V_85 ;
int V_89 ;
struct V_5 * V_5 ;
int V_6 , V_28 ;
for ( V_89 = V_37 - 1 ; V_89 >= V_27 ;
-- V_89 ) {
for ( V_28 = 0 ; ; V_28 ++ ) {
V_6 = V_100 [ V_99 ] [ V_28 ] ;
if ( V_6 == V_101 )
break;
V_85 = & ( V_11 -> V_49 [ V_89 ] ) ;
if ( F_74 ( & V_85 -> V_53 [ V_6 ] ) )
continue;
V_5 = F_75 ( V_85 -> V_53 [ V_6 ] . V_90 ,
struct V_5 , V_48 ) ;
V_85 -> V_50 -- ;
if ( ! F_78 ( V_6 ) &&
( F_7 ( V_89 >= V_81 / 2 ) ||
V_99 == V_102 ||
V_7 ) ) {
int V_103 ;
V_103 = F_117 ( V_11 , V_5 ,
V_99 ) ;
if ( V_103 >= ( 1 << ( V_81 - 1 ) ) ||
V_7 )
F_6 ( V_5 ,
V_99 ) ;
V_6 = V_99 ;
}
F_65 ( & V_5 -> V_48 ) ;
F_53 ( V_5 ) ;
if ( V_89 >= V_81 &&
! F_78 ( V_6 ) )
F_119 ( V_5 , V_89 ,
V_99 ) ;
F_103 ( V_11 , V_5 , V_27 , V_89 , V_85 ,
F_78 ( V_6 )
? V_6 : V_99 ) ;
F_121 ( V_5 , V_27 , V_89 ,
V_99 , V_6 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_122 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
struct V_5 * V_5 ;
V_104:
V_5 = F_110 ( V_11 , V_27 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_101 ) {
V_5 = F_120 ( V_11 , V_27 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_101 ;
goto V_104;
}
}
F_123 ( V_5 , V_27 , V_6 ) ;
return V_5 ;
}
static int F_124 ( struct V_11 * V_11 , unsigned int V_27 ,
unsigned long V_59 , struct V_67 * V_68 ,
int V_6 , int V_105 )
{
int V_71 = V_6 , V_28 ;
F_73 ( & V_11 -> V_64 ) ;
for ( V_28 = 0 ; V_28 < V_59 ; ++ V_28 ) {
struct V_5 * V_5 = F_122 ( V_11 , V_27 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_125 ( V_105 == 0 ) )
F_67 ( & V_5 -> V_48 , V_68 ) ;
else
F_66 ( & V_5 -> V_48 , V_68 ) ;
if ( F_126 ( V_106 ) ) {
V_71 = F_94 ( V_5 ) ;
if ( ! F_78 ( V_71 ) && V_71 != V_75 )
V_71 = V_6 ;
}
F_95 ( V_5 , V_71 ) ;
V_68 = & V_5 -> V_48 ;
if ( F_78 ( V_71 ) )
F_79 ( V_11 , V_73 ,
- ( 1 << V_27 ) ) ;
}
F_79 ( V_11 , V_74 , - ( V_28 << V_27 ) ) ;
F_80 ( & V_11 -> V_64 ) ;
return V_28 ;
}
void F_127 ( struct V_11 * V_11 , struct V_60 * V_61 )
{
unsigned long V_56 ;
int V_107 ;
F_92 ( V_56 ) ;
if ( V_61 -> V_59 >= V_61 -> V_108 )
V_107 = V_61 -> V_108 ;
else
V_107 = V_61 -> V_59 ;
if ( V_107 > 0 ) {
F_72 ( V_11 , V_107 , V_61 ) ;
V_61 -> V_59 -= V_107 ;
}
F_96 ( V_56 ) ;
}
static void F_128 ( unsigned int V_109 )
{
unsigned long V_56 ;
struct V_11 * V_11 ;
F_129 (zone) {
struct V_110 * V_111 ;
struct V_60 * V_61 ;
F_92 ( V_56 ) ;
V_111 = F_130 ( V_11 -> V_112 , V_109 ) ;
V_61 = & V_111 -> V_61 ;
if ( V_61 -> V_59 ) {
F_72 ( V_11 , V_61 -> V_59 , V_61 ) ;
V_61 -> V_59 = 0 ;
}
F_96 ( V_56 ) ;
}
}
void F_131 ( void * V_113 )
{
F_128 ( F_132 () ) ;
}
void F_133 ( void )
{
int V_109 ;
struct V_110 * V_61 ;
struct V_11 * V_11 ;
static T_4 V_114 ;
F_134 (cpu) {
bool V_115 = false ;
F_129 (zone) {
V_61 = F_130 ( V_11 -> V_112 , V_109 ) ;
if ( V_61 -> V_61 . V_59 ) {
V_115 = true ;
break;
}
}
if ( V_115 )
F_135 ( V_109 , & V_114 ) ;
else
F_136 ( V_109 , & V_114 ) ;
}
F_137 ( & V_114 , F_131 , NULL , 1 ) ;
}
void F_138 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_116 ;
unsigned long V_56 ;
int V_27 , V_117 ;
struct V_67 * V_118 ;
if ( ! V_11 -> V_16 )
return;
F_139 ( & V_11 -> V_64 , V_56 ) ;
V_116 = V_11 -> V_15 + V_11 -> V_16 ;
for ( V_14 = V_11 -> V_15 ; V_14 < V_116 ; V_14 ++ )
if ( F_140 ( V_14 ) ) {
struct V_5 * V_5 = F_118 ( V_14 ) ;
if ( ! F_141 ( V_5 ) )
F_142 ( V_5 ) ;
}
F_143 (order, t) {
F_144 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_28 ;
V_14 = F_10 ( F_75 ( V_118 , struct V_5 , V_48 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1UL << V_27 ) ; V_28 ++ )
F_145 ( F_118 ( V_14 + V_28 ) ) ;
}
}
F_146 ( & V_11 -> V_64 , V_56 ) ;
}
void F_147 ( struct V_5 * V_5 , int V_105 )
{
struct V_11 * V_11 = F_15 ( V_5 ) ;
struct V_60 * V_61 ;
unsigned long V_56 ;
int V_6 ;
if ( ! F_82 ( V_5 , 0 ) )
return;
V_6 = F_94 ( V_5 ) ;
F_95 ( V_5 , V_6 ) ;
F_92 ( V_56 ) ;
F_148 ( V_77 ) ;
if ( V_6 >= V_69 ) {
if ( F_7 ( V_6 == V_75 ) ) {
F_81 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_21;
}
V_6 = V_119 ;
}
V_61 = & F_149 ( V_11 -> V_112 ) -> V_61 ;
if ( V_105 )
F_66 ( & V_5 -> V_48 , & V_61 -> V_70 [ V_6 ] ) ;
else
F_67 ( & V_5 -> V_48 , & V_61 -> V_70 [ V_6 ] ) ;
V_61 -> V_59 ++ ;
if ( V_61 -> V_59 >= V_61 -> V_84 ) {
F_72 ( V_11 , V_61 -> V_108 , V_61 ) ;
V_61 -> V_59 -= V_61 -> V_108 ;
}
V_21:
F_96 ( V_56 ) ;
}
void F_150 ( struct V_67 * V_68 , int V_105 )
{
struct V_5 * V_5 , * V_90 ;
F_151 (page, next, list, lru) {
F_152 ( V_5 , V_105 ) ;
F_147 ( V_5 , V_105 ) ;
}
}
void F_153 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
F_41 ( F_63 ( V_5 ) ) ;
F_41 ( ! F_60 ( V_5 ) ) ;
#ifdef F_154
if ( F_155 ( V_5 ) )
F_153 ( F_156 ( V_5 [ 0 ] . V_120 ) , V_27 ) ;
#endif
for ( V_28 = 1 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_100 ( V_5 + V_28 ) ;
}
int F_157 ( struct V_5 * V_5 , int V_121 , int V_6 )
{
unsigned int V_27 ;
unsigned long V_122 ;
struct V_11 * V_11 ;
int V_71 ;
F_113 ( ! F_61 ( V_5 ) ) ;
V_11 = F_15 ( V_5 ) ;
V_27 = F_59 ( V_5 ) ;
V_122 = F_158 ( V_11 ) + ( 1 << V_27 ) ;
if ( ! F_159 ( V_11 , 0 , V_122 , 0 , 0 ) )
return 0 ;
F_65 ( & V_5 -> V_48 ) ;
V_11 -> V_49 [ V_27 ] . V_50 -- ;
F_53 ( V_5 ) ;
V_71 = F_94 ( V_5 ) ;
if ( F_7 ( V_71 != V_75 ) )
F_64 ( V_11 , - ( 1UL << V_121 ) , V_71 ) ;
if ( V_121 != V_27 )
F_103 ( V_11 , V_5 , V_121 , V_27 ,
& V_11 -> V_49 [ V_27 ] , V_6 ) ;
if ( V_27 >= V_81 - 1 ) {
struct V_5 * V_123 = V_5 + ( 1 << V_27 ) - 1 ;
for (; V_5 < V_123 ; V_5 += V_79 ) {
int V_71 = F_94 ( V_5 ) ;
if ( V_71 != V_75 && ! F_78 ( V_71 ) )
F_6 ( V_5 ,
V_119 ) ;
}
}
return 1UL << V_121 ;
}
int F_160 ( struct V_5 * V_5 )
{
unsigned int V_27 ;
int V_29 ;
F_113 ( ! F_61 ( V_5 ) ) ;
V_27 = F_59 ( V_5 ) ;
V_29 = F_157 ( V_5 , V_27 , 0 ) ;
if ( ! V_29 )
return 0 ;
F_100 ( V_5 ) ;
F_153 ( V_5 , V_27 ) ;
return V_29 ;
}
static inline
struct V_5 * F_161 ( struct V_11 * V_124 ,
struct V_11 * V_11 , int V_27 , T_1 V_33 ,
int V_6 )
{
unsigned long V_56 ;
struct V_5 * V_5 ;
int V_105 = ! ! ( V_33 & V_125 ) ;
V_126:
if ( F_125 ( V_27 == 0 ) ) {
struct V_60 * V_61 ;
struct V_67 * V_68 ;
F_92 ( V_56 ) ;
V_61 = & F_149 ( V_11 -> V_112 ) -> V_61 ;
V_68 = & V_61 -> V_70 [ V_6 ] ;
if ( F_74 ( V_68 ) ) {
V_61 -> V_59 += F_124 ( V_11 , 0 ,
V_61 -> V_108 , V_68 ,
V_6 , V_105 ) ;
if ( F_7 ( F_74 ( V_68 ) ) )
goto V_127;
}
if ( V_105 )
V_5 = F_75 ( V_68 -> V_72 , struct V_5 , V_48 ) ;
else
V_5 = F_75 ( V_68 -> V_90 , struct V_5 , V_48 ) ;
F_65 ( & V_5 -> V_48 ) ;
V_61 -> V_59 -- ;
} else {
if ( F_7 ( V_33 & V_128 ) ) {
F_162 ( V_27 > 1 ) ;
}
F_139 ( & V_11 -> V_64 , V_56 ) ;
V_5 = F_122 ( V_11 , V_27 , V_6 ) ;
F_80 ( & V_11 -> V_64 ) ;
if ( ! V_5 )
goto V_127;
F_64 ( V_11 , - ( 1 << V_27 ) ,
F_94 ( V_5 ) ) ;
}
F_163 ( V_129 , V_11 , 1 << V_27 ) ;
F_164 ( V_124 , V_11 , V_33 ) ;
F_96 ( V_56 ) ;
F_41 ( F_16 ( V_11 , V_5 ) ) ;
if ( F_108 ( V_5 , V_27 , V_33 ) )
goto V_126;
return V_5 ;
V_127:
F_96 ( V_56 ) ;
return NULL ;
}
static int T_2 F_165 ( char * V_130 )
{
return F_166 ( & V_131 . V_132 , V_130 ) ;
}
static bool F_167 ( T_1 V_133 , unsigned int V_27 )
{
if ( V_27 < V_131 . V_134 )
return false ;
if ( V_133 & V_128 )
return false ;
if ( V_131 . V_135 && ( V_133 & V_34 ) )
return false ;
if ( V_131 . V_136 && ( V_133 & V_137 ) )
return false ;
return F_168 ( & V_131 . V_132 , 1 << V_27 ) ;
}
static int T_2 F_169 ( void )
{
T_5 V_138 = V_139 | V_140 | V_141 ;
struct V_142 * V_143 ;
V_143 = F_170 ( L_5 , NULL ,
& V_131 . V_132 ) ;
if ( F_171 ( V_143 ) )
return F_172 ( V_143 ) ;
if ( ! F_173 ( L_6 , V_138 , V_143 ,
& V_131 . V_136 ) )
goto V_144;
if ( ! F_173 ( L_7 , V_138 , V_143 ,
& V_131 . V_135 ) )
goto V_144;
if ( ! F_174 ( L_8 , V_138 , V_143 ,
& V_131 . V_134 ) )
goto V_144;
return 0 ;
V_144:
F_175 ( V_143 ) ;
return - V_145 ;
}
static inline bool F_167 ( T_1 V_133 , unsigned int V_27 )
{
return false ;
}
static bool F_176 ( struct V_11 * V_146 , int V_27 , unsigned long V_147 ,
int V_148 , int V_149 , long V_150 )
{
long V_151 = V_147 ;
long V_152 = V_146 -> V_152 [ V_148 ] ;
int V_153 ;
V_150 -= ( 1 << V_27 ) - 1 ;
if ( V_149 & V_154 )
V_151 -= V_151 / 2 ;
if ( V_149 & V_155 )
V_151 -= V_151 / 4 ;
#ifdef V_106
if ( ! ( V_149 & V_156 ) )
V_150 -= F_177 ( V_146 , V_73 ) ;
#endif
if ( V_150 <= V_151 + V_152 )
return false ;
for ( V_153 = 0 ; V_153 < V_27 ; V_153 ++ ) {
V_150 -= V_146 -> V_49 [ V_153 ] . V_50 << V_153 ;
V_151 >>= 1 ;
if ( V_150 <= V_151 )
return false ;
}
return true ;
}
static inline unsigned long F_178 ( struct V_11 * V_11 )
{
if ( F_7 ( V_11 -> V_157 ) )
return V_11 -> V_157 * V_79 ;
return 0 ;
}
static inline unsigned long F_178 ( struct V_11 * V_11 )
{
return 0 ;
}
bool F_159 ( struct V_11 * V_146 , int V_27 , unsigned long V_147 ,
int V_148 , int V_149 )
{
return F_176 ( V_146 , V_27 , V_147 , V_148 , V_149 ,
F_177 ( V_146 , V_74 ) ) ;
}
bool F_179 ( struct V_11 * V_146 , int V_27 , unsigned long V_147 ,
int V_148 , int V_149 )
{
long V_150 = F_177 ( V_146 , V_74 ) ;
if ( V_146 -> V_158 && V_150 < V_146 -> V_158 )
V_150 = F_180 ( V_146 , V_74 ) ;
V_150 -= F_178 ( V_146 ) ;
return F_176 ( V_146 , V_27 , V_147 , V_148 , V_149 ,
V_150 ) ;
}
static T_6 * F_181 ( struct V_159 * V_159 , int V_149 )
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
V_162 = ! F_42 () && ( V_149 & V_167 ) ?
& V_168 :
& V_169 [ V_170 ] ;
return V_162 ;
}
static int F_184 ( struct V_159 * V_159 , struct V_171 * V_146 ,
T_6 * V_162 )
{
struct V_160 * V_161 ;
int V_28 ;
int V_172 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return 1 ;
V_28 = V_146 - V_159 -> V_173 ;
V_172 = V_161 -> V_174 [ V_28 ] ;
return F_185 ( V_172 , * V_162 ) && ! F_186 ( V_28 , V_161 -> V_165 ) ;
}
static void F_187 ( struct V_159 * V_159 , struct V_171 * V_146 )
{
struct V_160 * V_161 ;
int V_28 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return;
V_28 = V_146 - V_159 -> V_173 ;
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
static T_6 * F_181 ( struct V_159 * V_159 , int V_149 )
{
return NULL ;
}
static int F_184 ( struct V_159 * V_159 , struct V_171 * V_146 ,
T_6 * V_162 )
{
return 1 ;
}
static void F_187 ( struct V_159 * V_159 , struct V_171 * V_146 )
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
F_196 ( T_1 V_133 , T_6 * V_182 , unsigned int V_27 ,
struct V_159 * V_159 , int V_183 , int V_149 ,
struct V_11 * V_124 , int V_6 )
{
struct V_171 * V_146 ;
struct V_5 * V_5 = NULL ;
int V_148 ;
struct V_11 * V_11 ;
T_6 * V_162 = NULL ;
int V_184 = 0 ;
int V_185 = 0 ;
V_148 = F_197 ( V_124 ) ;
V_186:
F_198 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( V_187 && V_184 &&
! F_184 ( V_159 , V_146 , V_162 ) )
continue;
if ( ( V_149 & V_167 ) &&
! F_199 ( V_11 , V_133 ) )
continue;
if ( ( V_149 & V_188 ) &&
( V_133 & V_189 ) && ! F_200 ( V_11 ) )
goto V_190;
F_201 ( V_191 < V_192 ) ;
if ( ! ( V_149 & V_191 ) ) {
unsigned long V_147 ;
int V_12 ;
V_147 = V_11 -> V_122 [ V_149 & V_193 ] ;
if ( F_159 ( V_11 , V_27 , V_147 ,
V_148 , V_149 ) )
goto V_194;
if ( V_187 && ! V_185 && V_195 > 1 ) {
V_162 = F_181 ( V_159 , V_149 ) ;
V_184 = 1 ;
V_185 = 1 ;
}
if ( V_181 == 0 ||
! F_190 ( V_124 , V_11 ) )
goto V_190;
if ( V_187 && V_184 &&
! F_184 ( V_159 , V_146 , V_162 ) )
continue;
V_12 = F_202 ( V_11 , V_133 , V_27 ) ;
switch ( V_12 ) {
case V_196 :
continue;
case V_197 :
continue;
default:
if ( ! F_159 ( V_11 , V_27 , V_147 ,
V_148 , V_149 ) )
goto V_190;
}
}
V_194:
V_5 = F_161 ( V_124 , V_11 , V_27 ,
V_133 , V_6 ) ;
if ( V_5 )
break;
V_190:
if ( V_187 )
F_187 ( V_159 , V_146 ) ;
}
if ( F_7 ( V_187 && V_5 == NULL && V_184 ) ) {
V_184 = 0 ;
goto V_186;
}
if ( V_5 )
V_5 -> V_198 = ! ! ( V_149 & V_191 ) ;
return V_5 ;
}
static inline bool F_203 ( void )
{
bool V_12 = false ;
#if V_199 > 8
V_12 = F_42 () ;
#endif
return V_12 ;
}
void F_204 ( T_1 V_133 , int V_27 , const char * V_200 , ... )
{
unsigned int V_201 = V_202 ;
if ( ( V_133 & V_203 ) || ! F_205 ( & V_204 ) ||
F_105 () > 0 )
return;
if ( ! ( V_133 & V_205 ) )
if ( F_206 ( V_206 ) ||
( V_24 -> V_56 & ( V_207 | V_208 ) ) )
V_201 &= ~ V_202 ;
if ( F_42 () || ! ( V_133 & V_137 ) )
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
V_24 -> V_25 , V_27 , V_133 ) ;
F_24 () ;
if ( ! F_203 () )
F_208 ( V_201 ) ;
}
static inline int
F_209 ( T_1 V_133 , unsigned int V_27 ,
unsigned long V_212 ,
unsigned long V_213 )
{
if ( V_133 & V_214 )
return 0 ;
if ( V_133 & V_128 )
return 1 ;
if ( ! V_212 && F_5 () )
return 0 ;
if ( V_27 <= V_215 )
return 1 ;
if ( V_133 & V_216 && V_213 < ( 1 << V_27 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_210 ( T_1 V_133 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , struct V_11 * V_124 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_211 ( V_159 , V_133 ) ) {
F_212 ( 1 ) ;
return NULL ;
}
V_5 = F_196 ( V_133 | V_218 , V_182 ,
V_27 , V_159 , V_183 ,
V_219 | V_167 ,
V_124 , V_6 ) ;
if ( V_5 )
goto V_21;
if ( ! ( V_133 & V_128 ) ) {
if ( V_27 > V_215 )
goto V_21;
if ( V_183 < V_220 )
goto V_21;
if ( V_133 & V_221 )
goto V_21;
}
F_213 ( V_159 , V_133 , V_27 , V_182 , false ) ;
V_21:
F_214 ( V_159 , V_133 ) ;
return V_5 ;
}
static struct V_5 *
F_215 ( T_1 V_133 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , int V_149 , struct V_11 * V_124 ,
int V_6 , bool V_222 ,
bool * V_223 , bool * V_224 ,
unsigned long * V_212 )
{
struct V_5 * V_5 = NULL ;
if ( ! V_27 )
return NULL ;
if ( F_216 ( V_124 , V_27 ) ) {
* V_224 = true ;
return NULL ;
}
V_24 -> V_56 |= V_207 ;
* V_212 = F_217 ( V_159 , V_27 , V_133 ,
V_182 , V_222 ,
V_223 , & V_5 ) ;
V_24 -> V_56 &= ~ V_207 ;
if ( V_5 ) {
F_108 ( V_5 , V_27 , V_133 ) ;
goto V_225;
}
if ( * V_212 != V_226 ) {
F_128 ( F_218 () ) ;
F_219 () ;
V_5 = F_196 ( V_133 , V_182 ,
V_27 , V_159 , V_183 ,
V_149 & ~ V_191 ,
V_124 , V_6 ) ;
if ( V_5 ) {
V_225:
V_124 -> V_227 = false ;
V_124 -> V_228 = 0 ;
V_124 -> V_229 = 0 ;
if ( V_27 >= V_124 -> V_230 )
V_124 -> V_230 = V_27 + 1 ;
F_220 ( V_231 ) ;
return V_5 ;
}
F_220 ( V_232 ) ;
if ( V_222 )
F_221 ( V_124 , V_27 ) ;
F_222 () ;
}
return NULL ;
}
static inline struct V_5 *
F_215 ( T_1 V_133 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , int V_149 , struct V_11 * V_124 ,
int V_6 , bool V_222 ,
bool * V_223 , bool * V_224 ,
unsigned long * V_212 )
{
return NULL ;
}
static int
F_223 ( T_1 V_133 , unsigned int V_27 , struct V_159 * V_159 ,
T_6 * V_182 )
{
struct V_233 V_233 ;
int V_234 ;
F_222 () ;
F_224 () ;
V_24 -> V_56 |= V_207 ;
F_225 ( V_133 ) ;
V_233 . V_235 = 0 ;
V_24 -> V_233 = & V_233 ;
V_234 = F_226 ( V_159 , V_27 , V_133 , V_182 ) ;
V_24 -> V_233 = NULL ;
F_227 () ;
V_24 -> V_56 &= ~ V_207 ;
F_222 () ;
return V_234 ;
}
static inline struct V_5 *
F_228 ( T_1 V_133 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , int V_149 , struct V_11 * V_124 ,
int V_6 , unsigned long * V_212 )
{
struct V_5 * V_5 = NULL ;
bool V_236 = false ;
* V_212 = F_223 ( V_133 , V_27 , V_159 ,
V_182 ) ;
if ( F_7 ( ! ( * V_212 ) ) )
return NULL ;
if ( V_187 )
F_189 ( V_159 ) ;
V_237:
V_5 = F_196 ( V_133 , V_182 , V_27 ,
V_159 , V_183 ,
V_149 & ~ V_191 ,
V_124 , V_6 ) ;
if ( ! V_5 && ! V_236 ) {
F_133 () ;
V_236 = true ;
goto V_237;
}
return V_5 ;
}
static inline struct V_5 *
F_229 ( T_1 V_133 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , struct V_11 * V_124 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_196 ( V_133 , V_182 , V_27 ,
V_159 , V_183 , V_191 ,
V_124 , V_6 ) ;
if ( ! V_5 && V_133 & V_128 )
F_230 ( V_124 , V_238 , V_23 / 50 ) ;
} while ( ! V_5 && ( V_133 & V_128 ) );
return V_5 ;
}
static inline
void F_231 ( unsigned int V_27 , struct V_159 * V_159 ,
enum V_217 V_183 ,
enum V_217 V_148 )
{
struct V_171 * V_146 ;
struct V_11 * V_11 ;
F_232 (zone, z, zonelist, high_zoneidx)
F_233 ( V_11 , V_27 , V_148 ) ;
}
static inline int
F_234 ( T_1 V_133 )
{
int V_149 = V_239 | V_167 ;
const T_1 V_240 = V_133 & V_137 ;
F_201 ( V_241 != ( V_242 T_1 ) V_154 ) ;
V_149 |= ( V_242 int ) ( V_133 & V_241 ) ;
if ( ! V_240 ) {
if ( ! ( V_133 & V_205 ) )
V_149 |= V_155 ;
V_149 &= ~ V_167 ;
} else if ( F_7 ( F_235 ( V_24 ) ) && ! F_42 () )
V_149 |= V_155 ;
if ( F_125 ( ! ( V_133 & V_205 ) ) ) {
if ( V_133 & V_243 )
V_149 |= V_191 ;
else if ( F_236 () && ( V_24 -> V_56 & V_207 ) )
V_149 |= V_191 ;
else if ( ! F_42 () &&
( ( V_24 -> V_56 & V_207 ) ||
F_7 ( F_206 ( V_206 ) ) ) )
V_149 |= V_191 ;
}
#ifdef V_106
if ( F_237 ( V_133 ) == V_119 )
V_149 |= V_156 ;
#endif
return V_149 ;
}
bool F_238 ( T_1 V_133 )
{
return ! ! ( F_234 ( V_133 ) & V_191 ) ;
}
static inline struct V_5 *
F_239 ( T_1 V_133 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_217 V_183 ,
T_6 * V_182 , struct V_11 * V_124 ,
int V_6 )
{
const T_1 V_240 = V_133 & V_137 ;
struct V_5 * V_5 = NULL ;
int V_149 ;
unsigned long V_213 = 0 ;
unsigned long V_212 ;
bool V_222 = false ;
bool V_224 = false ;
bool V_223 = false ;
if ( V_27 >= V_37 ) {
F_162 ( ! ( V_133 & V_203 ) ) ;
return NULL ;
}
if ( V_187 && ( V_133 & V_244 ) == V_244 )
goto V_245;
V_246:
if ( ! ( V_133 & V_247 ) )
F_231 ( V_27 , V_159 , V_183 ,
F_197 ( V_124 ) ) ;
V_149 = F_234 ( V_133 ) ;
if ( ! ( V_149 & V_167 ) && ! V_182 )
F_240 ( V_159 , V_183 , NULL ,
& V_124 ) ;
V_248:
V_5 = F_196 ( V_133 , V_182 , V_27 , V_159 ,
V_183 , V_149 & ~ V_191 ,
V_124 , V_6 ) ;
if ( V_5 )
goto V_249;
if ( V_149 & V_191 ) {
V_159 = F_241 ( F_242 () , V_133 ) ;
V_5 = F_229 ( V_133 , V_27 ,
V_159 , V_183 , V_182 ,
V_124 , V_6 ) ;
if ( V_5 ) {
goto V_249;
}
}
if ( ! V_240 )
goto V_245;
if ( V_24 -> V_56 & V_207 )
goto V_245;
if ( F_206 ( V_206 ) && ! ( V_133 & V_128 ) )
goto V_245;
V_5 = F_215 ( V_133 , V_27 ,
V_159 , V_183 ,
V_182 ,
V_149 , V_124 ,
V_6 , V_222 ,
& V_223 ,
& V_224 ,
& V_212 ) ;
if ( V_5 )
goto V_249;
V_222 = true ;
if ( ( V_224 || V_223 ) &&
( V_133 & V_247 ) )
goto V_245;
V_5 = F_228 ( V_133 , V_27 ,
V_159 , V_183 ,
V_182 ,
V_149 , V_124 ,
V_6 , & V_212 ) ;
if ( V_5 )
goto V_249;
if ( ! V_212 ) {
if ( ( V_133 & V_250 ) && ! ( V_133 & V_214 ) ) {
if ( V_251 )
goto V_245;
if ( ( V_24 -> V_56 & V_252 ) &&
! ( V_133 & V_128 ) )
goto V_245;
V_5 = F_210 ( V_133 , V_27 ,
V_159 , V_183 ,
V_182 , V_124 ,
V_6 ) ;
if ( V_5 )
goto V_249;
if ( ! ( V_133 & V_128 ) ) {
if ( V_27 > V_215 )
goto V_245;
if ( V_183 < V_220 )
goto V_245;
}
goto V_246;
}
}
V_213 += V_212 ;
if ( F_209 ( V_133 , V_27 , V_212 ,
V_213 ) ) {
F_230 ( V_124 , V_238 , V_23 / 50 ) ;
goto V_248;
} else {
V_5 = F_215 ( V_133 , V_27 ,
V_159 , V_183 ,
V_182 ,
V_149 , V_124 ,
V_6 , V_222 ,
& V_223 ,
& V_224 ,
& V_212 ) ;
if ( V_5 )
goto V_249;
}
V_245:
F_204 ( V_133 , V_27 , NULL ) ;
return V_5 ;
V_249:
if ( V_253 )
F_243 ( V_5 , V_27 , V_133 ) ;
return V_5 ;
}
struct V_5 *
F_244 ( T_1 V_133 , unsigned int V_27 ,
struct V_159 * V_159 , T_6 * V_182 )
{
enum V_217 V_183 = F_245 ( V_133 ) ;
struct V_11 * V_124 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_237 ( V_133 ) ;
unsigned int V_254 ;
int V_149 = V_188 | V_167 ;
V_133 &= V_3 ;
F_246 ( V_133 ) ;
F_247 ( V_133 & V_137 ) ;
if ( F_167 ( V_133 , V_27 ) )
return NULL ;
if ( F_7 ( ! V_159 -> V_173 -> V_11 ) )
return NULL ;
V_255:
V_254 = F_248 () ;
F_240 ( V_159 , V_183 ,
V_182 ? : & V_168 ,
& V_124 ) ;
if ( ! V_124 )
goto V_21;
#ifdef V_106
if ( F_237 ( V_133 ) == V_119 )
V_149 |= V_156 ;
#endif
V_5 = F_196 ( V_133 | V_218 , V_182 , V_27 ,
V_159 , V_183 , V_149 ,
V_124 , V_6 ) ;
if ( F_7 ( ! V_5 ) )
V_5 = F_239 ( V_133 , V_27 ,
V_159 , V_183 , V_182 ,
V_124 , V_6 ) ;
F_249 ( V_5 , V_27 , V_133 , V_6 ) ;
V_21:
if ( F_7 ( ! F_250 ( V_254 ) && ! V_5 ) )
goto V_255;
return V_5 ;
}
unsigned long F_251 ( T_1 V_133 , unsigned int V_27 )
{
struct V_5 * V_5 ;
F_41 ( ( V_133 & V_34 ) != 0 ) ;
V_5 = F_252 ( V_133 , V_27 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_88 ( V_5 ) ;
}
unsigned long F_253 ( T_1 V_133 )
{
return F_251 ( V_133 | V_87 , 0 ) ;
}
void F_101 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( F_254 ( V_5 ) ) {
if ( V_27 == 0 )
F_147 ( V_5 , 0 ) ;
else
F_27 ( V_5 , V_27 ) ;
}
}
void V_150 ( unsigned long V_256 , unsigned int V_27 )
{
if ( V_256 != 0 ) {
F_41 ( ! F_255 ( ( void * ) V_256 ) ) ;
F_101 ( F_156 ( ( void * ) V_256 ) , V_27 ) ;
}
}
static void * F_256 ( unsigned long V_256 , unsigned V_27 , T_9 V_86 )
{
if ( V_256 ) {
unsigned long V_257 = V_256 + ( V_76 << V_27 ) ;
unsigned long V_258 = V_256 + F_257 ( V_86 ) ;
F_153 ( F_156 ( ( void * ) V_256 ) , V_27 ) ;
while ( V_258 < V_257 ) {
F_258 ( V_258 ) ;
V_258 += V_76 ;
}
}
return ( void * ) V_256 ;
}
void * F_259 ( T_9 V_86 , T_1 V_133 )
{
unsigned int V_27 = F_260 ( V_86 ) ;
unsigned long V_256 ;
V_256 = F_251 ( V_133 , V_27 ) ;
return F_256 ( V_256 , V_27 , V_86 ) ;
}
void * F_261 ( int V_179 , T_9 V_86 , T_1 V_133 )
{
unsigned V_27 = F_260 ( V_86 ) ;
struct V_5 * V_30 = F_262 ( V_179 , V_133 , V_27 ) ;
if ( ! V_30 )
return NULL ;
return F_256 ( ( unsigned long ) F_88 ( V_30 ) , V_27 , V_86 ) ;
}
void F_263 ( void * V_259 , T_9 V_86 )
{
unsigned long V_256 = ( unsigned long ) V_259 ;
unsigned long V_260 = V_256 + F_257 ( V_86 ) ;
while ( V_256 < V_260 ) {
F_258 ( V_256 ) ;
V_256 += V_76 ;
}
}
static unsigned int F_264 ( int V_261 )
{
struct V_171 * V_146 ;
struct V_11 * V_11 ;
unsigned int V_262 = 0 ;
struct V_159 * V_159 = F_241 ( F_242 () , V_263 ) ;
F_232 (zone, z, zonelist, offset) {
unsigned long V_86 = V_11 -> V_264 ;
unsigned long V_84 = F_265 ( V_11 ) ;
if ( V_86 > V_84 )
V_262 += V_86 - V_84 ;
}
return V_262 ;
}
unsigned int F_266 ( void )
{
return F_264 ( F_245 ( V_265 ) ) ;
}
unsigned int F_267 ( void )
{
return F_264 ( F_245 ( V_266 ) ) ;
}
static inline void F_268 ( struct V_11 * V_11 )
{
if ( V_187 )
F_21 ( L_11 , F_115 ( V_11 ) ) ;
}
void F_269 ( struct V_267 * V_268 )
{
V_268 -> V_269 = V_82 ;
V_268 -> V_270 = 0 ;
V_268 -> V_271 = F_270 ( V_74 ) ;
V_268 -> V_272 = F_271 () ;
V_268 -> V_273 = V_274 ;
V_268 -> V_275 = F_272 () ;
V_268 -> V_276 = V_76 ;
}
void F_273 ( struct V_267 * V_268 , int V_179 )
{
T_10 * V_277 = F_195 ( V_179 ) ;
V_268 -> V_269 = V_277 -> V_278 ;
V_268 -> V_271 = F_274 ( V_179 , V_74 ) ;
#ifdef F_275
V_268 -> V_273 = V_277 -> V_279 [ V_280 ] . V_264 ;
V_268 -> V_275 = F_177 ( & V_277 -> V_279 [ V_280 ] ,
V_74 ) ;
#else
V_268 -> V_273 = 0 ;
V_268 -> V_275 = 0 ;
#endif
V_268 -> V_276 = V_76 ;
}
bool F_276 ( unsigned int V_56 , int V_179 )
{
bool V_12 = false ;
unsigned int V_254 ;
if ( ! ( V_56 & V_202 ) )
goto V_21;
do {
V_254 = F_248 () ;
V_12 = ! F_185 ( V_179 , V_168 ) ;
} while ( ! F_250 ( V_254 ) );
V_21:
return V_12 ;
}
void F_277 ( unsigned int V_201 )
{
int V_109 ;
struct V_11 * V_11 ;
F_129 (zone) {
if ( F_276 ( V_201 , F_115 ( V_11 ) ) )
continue;
F_268 ( V_11 ) ;
F_21 ( L_12 , V_11 -> V_281 ) ;
F_134 (cpu) {
struct V_110 * V_112 ;
V_112 = F_130 ( V_11 -> V_112 , V_109 ) ;
F_21 ( L_13 ,
V_109 , V_112 -> V_61 . V_84 ,
V_112 -> V_61 . V_108 , V_112 -> V_61 . V_59 ) ;
}
}
F_21 ( L_14
L_15
L_16
L_17
L_18
L_19
L_20 ,
F_270 ( V_282 ) ,
F_270 ( V_283 ) ,
F_270 ( V_284 ) ,
F_270 ( V_285 ) ,
F_270 ( V_286 ) ,
F_270 ( V_287 ) ,
F_270 ( V_288 ) ,
F_270 ( V_289 ) ,
F_270 ( V_290 ) ,
F_270 ( V_291 ) ,
F_270 ( V_74 ) ,
F_270 ( V_292 ) ,
F_270 ( V_293 ) ,
F_270 ( V_294 ) ,
F_270 ( V_295 ) ,
F_270 ( V_296 ) ,
F_270 ( V_297 ) ,
F_270 ( V_73 ) ) ;
F_129 (zone) {
int V_28 ;
if ( F_276 ( V_201 , F_115 ( V_11 ) ) )
continue;
F_268 ( V_11 ) ;
F_21 ( L_21
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
L_47
L_48
L_49 ,
V_11 -> V_281 ,
F_278 ( F_177 ( V_11 , V_74 ) ) ,
F_278 ( F_279 ( V_11 ) ) ,
F_278 ( F_158 ( V_11 ) ) ,
F_278 ( F_265 ( V_11 ) ) ,
F_278 ( F_177 ( V_11 , V_282 ) ) ,
F_278 ( F_177 ( V_11 , V_283 ) ) ,
F_278 ( F_177 ( V_11 , V_285 ) ) ,
F_278 ( F_177 ( V_11 , V_286 ) ) ,
F_278 ( F_177 ( V_11 , V_288 ) ) ,
F_278 ( F_177 ( V_11 , V_284 ) ) ,
F_278 ( F_177 ( V_11 , V_287 ) ) ,
F_278 ( V_11 -> V_264 ) ,
F_278 ( F_177 ( V_11 , V_298 ) ) ,
F_278 ( F_177 ( V_11 , V_289 ) ) ,
F_278 ( F_177 ( V_11 , V_290 ) ) ,
F_278 ( F_177 ( V_11 , V_294 ) ) ,
F_278 ( F_177 ( V_11 , V_295 ) ) ,
F_278 ( F_177 ( V_11 , V_292 ) ) ,
F_278 ( F_177 ( V_11 , V_293 ) ) ,
F_177 ( V_11 , V_299 ) *
V_300 / 1024 ,
F_278 ( F_177 ( V_11 , V_296 ) ) ,
F_278 ( F_177 ( V_11 , V_291 ) ) ,
F_278 ( F_177 ( V_11 , V_297 ) ) ,
F_278 ( F_177 ( V_11 , V_73 ) ) ,
F_278 ( F_177 ( V_11 , V_301 ) ) ,
V_11 -> V_66 ,
( V_11 -> V_65 ? L_50 : L_51 )
) ;
F_21 ( L_52 ) ;
for ( V_28 = 0 ; V_28 < V_302 ; V_28 ++ )
F_21 ( L_53 , V_11 -> V_152 [ V_28 ] ) ;
F_21 ( L_49 ) ;
}
F_129 (zone) {
unsigned long V_303 [ V_37 ] , V_56 , V_27 , V_304 = 0 ;
if ( F_276 ( V_201 , F_115 ( V_11 ) ) )
continue;
F_268 ( V_11 ) ;
F_21 ( L_54 , V_11 -> V_281 ) ;
F_139 ( & V_11 -> V_64 , V_56 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
V_303 [ V_27 ] = V_11 -> V_49 [ V_27 ] . V_50 ;
V_304 += V_303 [ V_27 ] << V_27 ;
}
F_146 ( & V_11 -> V_64 , V_56 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ )
F_21 ( L_55 , V_303 [ V_27 ] , F_278 ( 1UL ) << V_27 ) ;
F_21 ( L_56 , F_278 ( V_304 ) ) ;
}
F_21 ( L_57 , F_270 ( V_305 ) ) ;
F_280 () ;
}
static void F_281 ( struct V_11 * V_11 , struct V_171 * V_171 )
{
V_171 -> V_11 = V_11 ;
V_171 -> F_197 = F_197 ( V_11 ) ;
}
static int F_282 ( T_10 * V_277 , struct V_159 * V_159 ,
int V_306 , enum V_217 V_217 )
{
struct V_11 * V_11 ;
F_113 ( V_217 >= V_302 ) ;
V_217 ++ ;
do {
V_217 -- ;
V_11 = V_277 -> V_279 + V_217 ;
if ( F_283 ( V_11 ) ) {
F_281 ( V_11 ,
& V_159 -> V_173 [ V_306 ++ ] ) ;
F_284 ( V_217 ) ;
}
} while ( V_217 );
return V_306 ;
}
static int F_285 ( char * V_307 )
{
if ( * V_307 == 'd' || * V_307 == 'D' ) {
V_308 = V_309 ;
} else if ( * V_307 == 'n' || * V_307 == 'N' ) {
V_308 = V_310 ;
} else if ( * V_307 == 'z' || * V_307 == 'Z' ) {
V_308 = V_311 ;
} else {
F_21 ( V_312
L_58
L_59 , V_307 ) ;
return - V_313 ;
}
return 0 ;
}
static T_2 int F_286 ( char * V_307 )
{
int V_12 ;
if ( ! V_307 )
return 0 ;
V_12 = F_285 ( V_307 ) ;
if ( V_12 == 0 )
F_287 ( V_314 , V_307 , V_315 ) ;
return V_12 ;
}
int F_288 ( T_11 * V_316 , int V_317 ,
void T_12 * V_318 , T_9 * V_319 ,
T_13 * V_320 )
{
char V_321 [ V_315 ] ;
int V_12 ;
static F_289 ( V_322 ) ;
F_290 ( & V_322 ) ;
if ( V_317 )
strcpy ( V_321 , ( char * ) V_316 -> V_323 ) ;
V_12 = F_291 ( V_316 , V_317 , V_318 , V_319 , V_320 ) ;
if ( V_12 )
goto V_21;
if ( V_317 ) {
int V_324 = V_308 ;
if ( F_285 ( ( char * ) V_316 -> V_323 ) ) {
strncpy ( ( char * ) V_316 -> V_323 , V_321 ,
V_315 ) ;
V_308 = V_324 ;
} else if ( V_324 != V_308 ) {
F_290 ( & V_325 ) ;
F_292 ( NULL , NULL ) ;
F_293 ( & V_325 ) ;
}
}
V_21:
F_293 ( & V_322 ) ;
return V_12 ;
}
static int F_294 ( int V_176 , T_6 * V_326 )
{
int V_172 , V_268 ;
int V_327 = V_328 ;
int V_329 = - 1 ;
const struct V_330 * V_331 = F_295 ( 0 ) ;
if ( ! F_185 ( V_176 , * V_326 ) ) {
F_194 ( V_176 , * V_326 ) ;
return V_176 ;
}
F_296 (n, N_HIGH_MEMORY) {
if ( F_185 ( V_172 , * V_326 ) )
continue;
V_268 = F_193 ( V_176 , V_172 ) ;
V_268 += ( V_172 < V_176 ) ;
V_331 = F_295 ( V_172 ) ;
if ( ! F_297 ( V_331 ) )
V_268 += V_332 ;
V_268 *= ( V_333 * V_334 ) ;
V_268 += V_335 [ V_172 ] ;
if ( V_268 < V_327 ) {
V_327 = V_268 ;
V_329 = V_172 ;
}
}
if ( V_329 >= 0 )
F_194 ( V_329 , * V_326 ) ;
return V_329 ;
}
static void F_298 ( T_10 * V_277 , int V_176 )
{
int V_336 ;
struct V_159 * V_159 ;
V_159 = & V_277 -> V_337 [ 0 ] ;
for ( V_336 = 0 ; V_159 -> V_173 [ V_336 ] . V_11 != NULL ; V_336 ++ )
;
V_336 = F_282 ( F_195 ( V_176 ) , V_159 , V_336 ,
V_302 - 1 ) ;
V_159 -> V_173 [ V_336 ] . V_11 = NULL ;
V_159 -> V_173 [ V_336 ] . F_197 = 0 ;
}
static void F_299 ( T_10 * V_277 )
{
int V_336 ;
struct V_159 * V_159 ;
V_159 = & V_277 -> V_337 [ 1 ] ;
V_336 = F_282 ( V_277 , V_159 , 0 , V_302 - 1 ) ;
V_159 -> V_173 [ V_336 ] . V_11 = NULL ;
V_159 -> V_173 [ V_336 ] . F_197 = 0 ;
}
static void F_300 ( T_10 * V_277 , int V_338 )
{
int V_339 , V_336 , V_176 ;
int V_217 ;
struct V_11 * V_146 ;
struct V_159 * V_159 ;
V_159 = & V_277 -> V_337 [ 0 ] ;
V_339 = 0 ;
for ( V_217 = V_302 - 1 ; V_217 >= 0 ; V_217 -- ) {
for ( V_336 = 0 ; V_336 < V_338 ; V_336 ++ ) {
V_176 = V_340 [ V_336 ] ;
V_146 = & F_195 ( V_176 ) -> V_279 [ V_217 ] ;
if ( F_283 ( V_146 ) ) {
F_281 ( V_146 ,
& V_159 -> V_173 [ V_339 ++ ] ) ;
F_284 ( V_217 ) ;
}
}
}
V_159 -> V_173 [ V_339 ] . V_11 = NULL ;
V_159 -> V_173 [ V_339 ] . F_197 = 0 ;
}
static int F_301 ( void )
{
int V_179 , V_217 ;
unsigned long V_341 , V_342 ;
struct V_11 * V_146 ;
int V_343 ;
V_341 = 0 ;
V_342 = 0 ;
F_192 (nid) {
for ( V_217 = 0 ; V_217 < V_302 ; V_217 ++ ) {
V_146 = & F_195 ( V_179 ) -> V_279 [ V_217 ] ;
if ( F_283 ( V_146 ) ) {
if ( V_217 < V_220 )
V_341 += V_146 -> V_264 ;
V_342 += V_146 -> V_264 ;
} else if ( V_217 == V_220 ) {
return V_310 ;
}
}
}
if ( ! V_341 ||
V_341 > V_342 / 2 )
return V_310 ;
V_343 = V_342 /
( F_302 ( V_169 [ V_170 ] ) + 1 ) ;
F_192 (nid) {
V_341 = 0 ;
V_342 = 0 ;
for ( V_217 = 0 ; V_217 < V_302 ; V_217 ++ ) {
V_146 = & F_195 ( V_179 ) -> V_279 [ V_217 ] ;
if ( F_283 ( V_146 ) ) {
if ( V_217 < V_220 )
V_341 += V_146 -> V_264 ;
V_342 += V_146 -> V_264 ;
}
}
if ( V_341 &&
V_342 > V_343 &&
V_341 > V_342 * 70 / 100 )
return V_310 ;
}
return V_311 ;
}
static void F_303 ( void )
{
if ( V_308 == V_309 )
V_344 = F_301 () ;
else
V_344 = V_308 ;
}
static void F_304 ( T_10 * V_277 )
{
int V_336 , V_176 , V_345 ;
enum V_217 V_28 ;
T_6 V_346 ;
int V_347 , V_348 ;
struct V_159 * V_159 ;
int V_27 = V_344 ;
for ( V_28 = 0 ; V_28 < V_349 ; V_28 ++ ) {
V_159 = V_277 -> V_337 + V_28 ;
V_159 -> V_173 [ 0 ] . V_11 = NULL ;
V_159 -> V_173 [ 0 ] . F_197 = 0 ;
}
V_347 = V_277 -> V_350 ;
V_345 = V_195 ;
V_348 = V_347 ;
F_305 ( V_346 ) ;
memset ( V_340 , 0 , sizeof( V_340 ) ) ;
V_336 = 0 ;
while ( ( V_176 = F_294 ( V_347 , & V_346 ) ) >= 0 ) {
if ( F_193 ( V_347 , V_176 ) !=
F_193 ( V_347 , V_348 ) )
V_335 [ V_176 ] = V_345 ;
V_348 = V_176 ;
V_345 -- ;
if ( V_27 == V_310 )
F_298 ( V_277 , V_176 ) ;
else
V_340 [ V_336 ++ ] = V_176 ;
}
if ( V_27 == V_311 ) {
F_300 ( V_277 , V_336 ) ;
}
F_299 ( V_277 ) ;
}
static void F_306 ( T_10 * V_277 )
{
struct V_159 * V_159 ;
struct V_160 * V_161 ;
struct V_171 * V_146 ;
V_159 = & V_277 -> V_337 [ 0 ] ;
V_159 -> V_163 = V_161 = & V_159 -> V_351 ;
F_183 ( V_161 -> V_165 , V_166 ) ;
for ( V_146 = V_159 -> V_173 ; V_146 -> V_11 ; V_146 ++ )
V_161 -> V_174 [ V_146 - V_159 -> V_173 ] = F_307 ( V_146 ) ;
}
int F_308 ( int V_176 )
{
struct V_11 * V_11 ;
( void ) F_240 ( F_241 ( V_176 , V_263 ) ,
F_245 ( V_263 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_176 ;
}
static void F_303 ( void )
{
V_344 = V_311 ;
}
static void F_304 ( T_10 * V_277 )
{
int V_176 , V_347 ;
enum V_217 V_336 ;
struct V_159 * V_159 ;
V_347 = V_277 -> V_350 ;
V_159 = & V_277 -> V_337 [ 0 ] ;
V_336 = F_282 ( V_277 , V_159 , 0 , V_302 - 1 ) ;
for ( V_176 = V_347 + 1 ; V_176 < V_334 ; V_176 ++ ) {
if ( ! F_309 ( V_176 ) )
continue;
V_336 = F_282 ( F_195 ( V_176 ) , V_159 , V_336 ,
V_302 - 1 ) ;
}
for ( V_176 = 0 ; V_176 < V_347 ; V_176 ++ ) {
if ( ! F_309 ( V_176 ) )
continue;
V_336 = F_282 ( F_195 ( V_176 ) , V_159 , V_336 ,
V_302 - 1 ) ;
}
V_159 -> V_173 [ V_336 ] . V_11 = NULL ;
V_159 -> V_173 [ V_336 ] . F_197 = 0 ;
}
static void F_306 ( T_10 * V_277 )
{
V_277 -> V_337 [ 0 ] . V_163 = NULL ;
}
static int F_310 ( void * V_323 )
{
int V_179 ;
int V_109 ;
T_10 * V_352 = V_323 ;
#ifdef F_311
memset ( V_335 , 0 , sizeof( V_335 ) ) ;
#endif
if ( V_352 && ! F_309 ( V_352 -> V_350 ) ) {
F_304 ( V_352 ) ;
F_306 ( V_352 ) ;
}
F_192 (nid) {
T_10 * V_277 = F_195 ( V_179 ) ;
F_304 ( V_277 ) ;
F_306 ( V_277 ) ;
}
F_312 (cpu) {
F_313 ( & F_314 ( V_353 , V_109 ) , 0 ) ;
#ifdef F_315
if ( F_316 ( V_109 ) )
F_317 ( V_109 , F_308 ( F_318 ( V_109 ) ) ) ;
#endif
}
return 0 ;
}
void T_14 F_292 ( T_10 * V_277 , struct V_11 * V_11 )
{
F_303 () ;
if ( V_354 == V_355 ) {
F_310 ( NULL ) ;
F_319 () ;
F_320 () ;
} else {
#ifdef F_321
if ( V_11 )
F_322 ( V_11 ) ;
#endif
F_323 ( F_310 , V_277 , NULL ) ;
}
V_356 = F_267 () ;
if ( V_356 < ( V_79 * V_357 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_21 ( L_60
L_61 ,
V_195 ,
V_358 [ V_344 ] ,
V_7 ? L_62 : L_63 ,
V_356 ) ;
#ifdef F_311
F_21 ( L_64 , V_359 [ V_360 ] ) ;
#endif
}
static inline unsigned long F_324 ( unsigned long V_103 )
{
unsigned long V_86 = 1 ;
V_103 /= V_361 ;
while ( V_86 < V_103 )
V_86 <<= 1 ;
V_86 = V_151 ( V_86 , 4096UL ) ;
return F_325 ( V_86 , 4UL ) ;
}
static inline unsigned long F_324 ( unsigned long V_103 )
{
return 4096UL ;
}
static inline unsigned long F_326 ( unsigned long V_86 )
{
return F_327 ( ~ V_86 ) ;
}
static int F_328 ( unsigned long V_94 , unsigned long V_95 )
{
unsigned long V_14 ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 ++ ) {
if ( ! F_14 ( V_14 ) || F_329 ( F_118 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_330 ( struct V_11 * V_11 )
{
unsigned long V_94 , V_14 , V_95 , V_362 ;
struct V_5 * V_5 ;
unsigned long V_363 ;
int V_364 ;
V_94 = V_11 -> V_15 ;
V_95 = V_94 + V_11 -> V_16 ;
V_94 = F_331 ( V_94 , V_79 ) ;
V_364 = F_331 ( F_279 ( V_11 ) , V_79 ) >>
V_81 ;
V_364 = V_151 ( 2 , V_364 ) ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 += V_79 ) {
if ( ! F_140 ( V_14 ) )
continue;
V_5 = F_118 ( V_14 ) ;
if ( F_114 ( V_5 ) != F_115 ( V_11 ) )
continue;
V_363 = F_94 ( V_5 ) ;
if ( V_364 > 0 ) {
V_362 = V_151 ( V_14 + V_79 , V_95 ) ;
if ( F_328 ( V_14 , V_362 ) )
continue;
if ( V_363 == V_101 ) {
V_364 -- ;
continue;
}
if ( V_363 == V_119 ) {
F_6 ( V_5 ,
V_101 ) ;
F_117 ( V_11 , V_5 ,
V_101 ) ;
V_364 -- ;
continue;
}
}
if ( V_363 == V_101 ) {
F_6 ( V_5 , V_119 ) ;
F_117 ( V_11 , V_5 , V_119 ) ;
}
}
}
void T_3 F_332 ( unsigned long V_86 , int V_179 , unsigned long V_11 ,
unsigned long V_94 , enum V_365 V_366 )
{
struct V_5 * V_5 ;
unsigned long V_95 = V_94 + V_86 ;
unsigned long V_14 ;
struct V_11 * V_146 ;
if ( V_367 < V_95 - 1 )
V_367 = V_95 - 1 ;
V_146 = & F_195 ( V_179 ) -> V_279 [ V_11 ] ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 ++ ) {
if ( V_366 == V_368 ) {
if ( ! F_333 ( V_14 ) )
continue;
if ( ! F_334 ( V_14 , V_179 ) )
continue;
}
V_5 = F_118 ( V_14 ) ;
F_335 ( V_5 , V_11 , V_179 , V_14 ) ;
F_336 ( V_5 , V_11 , V_179 , V_14 ) ;
F_337 ( V_5 ) ;
F_19 ( V_5 ) ;
F_338 ( V_5 ) ;
if ( ( V_146 -> V_15 <= V_14 )
&& ( V_14 < V_146 -> V_15 + V_146 -> V_16 )
&& ! ( V_14 & ( V_79 - 1 ) ) )
F_6 ( V_5 , V_119 ) ;
F_106 ( & V_5 -> V_48 ) ;
#ifdef F_339
if ( ! F_340 ( V_11 ) )
F_341 ( V_5 , F_342 ( V_14 << V_369 ) ) ;
#endif
}
}
static void T_3 F_343 ( struct V_11 * V_11 )
{
int V_27 , V_117 ;
F_143 (order, t) {
F_106 ( & V_11 -> V_49 [ V_27 ] . V_53 [ V_117 ] ) ;
V_11 -> V_49 [ V_27 ] . V_50 = 0 ;
}
}
static int T_3 F_344 ( struct V_11 * V_11 )
{
#ifdef F_345
int V_108 ;
V_108 = V_11 -> V_264 / 1024 ;
if ( V_108 * V_76 > 512 * 1024 )
V_108 = ( 512 * 1024 ) / V_76 ;
V_108 /= 4 ;
if ( V_108 < 1 )
V_108 = 1 ;
V_108 = F_346 ( V_108 + V_108 / 2 ) - 1 ;
return V_108 ;
#else
return 0 ;
#endif
}
static void F_313 ( struct V_110 * V_30 , unsigned long V_108 )
{
struct V_60 * V_61 ;
int V_6 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_61 = & V_30 -> V_61 ;
V_61 -> V_59 = 0 ;
V_61 -> V_84 = 6 * V_108 ;
V_61 -> V_108 = F_325 ( 1UL , 1 * V_108 ) ;
for ( V_6 = 0 ; V_6 < V_69 ; V_6 ++ )
F_106 ( & V_61 -> V_70 [ V_6 ] ) ;
}
static void F_347 ( struct V_110 * V_30 ,
unsigned long V_84 )
{
struct V_60 * V_61 ;
V_61 = & V_30 -> V_61 ;
V_61 -> V_84 = V_84 ;
V_61 -> V_108 = F_325 ( 1UL , V_84 / 4 ) ;
if ( ( V_84 / 4 ) > ( V_369 * 8 ) )
V_61 -> V_108 = V_369 * 8 ;
}
static void T_3 F_322 ( struct V_11 * V_11 )
{
int V_109 ;
V_11 -> V_112 = F_348 ( struct V_110 ) ;
F_312 (cpu) {
struct V_110 * V_61 = F_130 ( V_11 -> V_112 , V_109 ) ;
F_313 ( V_61 , F_344 ( V_11 ) ) ;
if ( V_370 )
F_347 ( V_61 ,
( V_11 -> V_264 /
V_370 ) ) ;
}
}
void T_2 F_349 ( void )
{
struct V_11 * V_11 ;
F_129 (zone)
F_322 ( V_11 ) ;
}
static T_15 T_16
int F_350 ( struct V_11 * V_11 , unsigned long V_371 )
{
int V_28 ;
struct V_372 * V_277 = V_11 -> V_177 ;
T_9 V_373 ;
V_11 -> F_324 =
F_324 ( V_371 ) ;
V_11 -> F_326 =
F_326 ( V_11 -> F_324 ) ;
V_373 = V_11 -> F_324
* sizeof( V_374 ) ;
if ( ! F_351 () ) {
V_11 -> V_375 = ( V_374 * )
F_352 ( V_277 , V_373 ) ;
} else {
V_11 -> V_375 = F_353 ( V_373 ) ;
}
if ( ! V_11 -> V_375 )
return - V_145 ;
for( V_28 = 0 ; V_28 < V_11 -> F_324 ; ++ V_28 )
F_354 ( V_11 -> V_375 + V_28 ) ;
return 0 ;
}
static T_3 void F_355 ( struct V_11 * V_11 )
{
V_11 -> V_112 = & V_353 ;
if ( V_11 -> V_264 )
F_21 ( V_376 L_65 ,
V_11 -> V_281 , V_11 -> V_264 ,
F_344 ( V_11 ) ) ;
}
int T_3 F_356 ( struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_86 ,
enum V_365 V_366 )
{
struct V_372 * V_277 = V_11 -> V_177 ;
int V_12 ;
V_12 = F_350 ( V_11 , V_86 ) ;
if ( V_12 )
return V_12 ;
V_277 -> V_306 = F_197 ( V_11 ) + 1 ;
V_11 -> V_15 = V_15 ;
F_357 ( V_377 , L_66 ,
L_67 ,
V_277 -> V_350 ,
( unsigned long ) F_197 ( V_11 ) ,
V_15 , ( V_15 + V_86 ) ) ;
F_343 ( V_11 ) ;
return 0 ;
}
int T_3 F_358 ( unsigned long V_14 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_179 ;
F_359 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
if ( V_94 <= V_14 && V_14 < V_95 )
return V_179 ;
return - 1 ;
}
int T_3 F_360 ( unsigned long V_14 )
{
int V_179 ;
V_179 = F_358 ( V_14 ) ;
if ( V_179 >= 0 )
return V_179 ;
return 0 ;
}
bool T_3 F_334 ( unsigned long V_14 , int V_176 )
{
int V_179 ;
V_179 = F_358 ( V_14 ) ;
if ( V_179 >= 0 && V_179 != V_176 )
return false ;
return true ;
}
void T_2 F_361 ( int V_179 , unsigned long V_378 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_379 ;
F_359 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_94 = V_151 ( V_94 , V_378 ) ;
V_95 = V_151 ( V_95 , V_378 ) ;
if ( V_94 < V_95 )
F_362 ( F_195 ( V_379 ) ,
F_363 ( V_94 ) ,
( V_95 - V_94 ) << V_369 ) ;
}
}
void T_2 F_364 ( int V_179 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_379 ;
F_359 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_365 ( V_379 , V_94 , V_95 ) ;
}
void T_3 F_366 ( unsigned int V_179 ,
unsigned long * V_94 , unsigned long * V_95 )
{
unsigned long V_380 , V_381 ;
int V_28 ;
* V_94 = - 1UL ;
* V_95 = 0 ;
F_359 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_94 = V_151 ( * V_94 , V_380 ) ;
* V_95 = F_325 ( * V_95 , V_381 ) ;
}
if ( * V_94 == - 1UL )
* V_94 = 0 ;
}
static void T_2 F_367 ( void )
{
int V_382 ;
for ( V_382 = V_302 - 1 ; V_382 >= 0 ; V_382 -- ) {
if ( V_382 == V_383 )
continue;
if ( V_384 [ V_382 ] >
V_385 [ V_382 ] )
break;
}
F_41 ( V_382 == - 1 ) ;
V_386 = V_382 ;
}
static void T_3 F_368 ( int V_179 ,
unsigned long V_217 ,
unsigned long V_387 ,
unsigned long V_388 ,
unsigned long * V_15 ,
unsigned long * V_389 )
{
if ( V_390 [ V_179 ] ) {
if ( V_217 == V_383 ) {
* V_15 = V_390 [ V_179 ] ;
* V_389 = V_151 ( V_388 ,
V_384 [ V_386 ] ) ;
} else if ( * V_15 < V_390 [ V_179 ] &&
* V_389 > V_390 [ V_179 ] ) {
* V_389 = V_390 [ V_179 ] ;
} else if ( * V_15 >= V_390 [ V_179 ] )
* V_15 = * V_389 ;
}
}
static unsigned long T_3 F_369 ( int V_179 ,
unsigned long V_217 ,
unsigned long * V_391 )
{
unsigned long V_387 , V_388 ;
unsigned long V_15 , V_389 ;
F_366 ( V_179 , & V_387 , & V_388 ) ;
V_15 = V_385 [ V_217 ] ;
V_389 = V_384 [ V_217 ] ;
F_368 ( V_179 , V_217 ,
V_387 , V_388 ,
& V_15 , & V_389 ) ;
if ( V_389 < V_387 || V_15 > V_388 )
return 0 ;
V_389 = V_151 ( V_389 , V_388 ) ;
V_15 = F_325 ( V_15 , V_387 ) ;
return V_389 - V_15 ;
}
unsigned long T_3 F_370 ( int V_179 ,
unsigned long V_392 ,
unsigned long V_393 )
{
unsigned long V_394 = V_393 - V_392 ;
unsigned long V_94 , V_95 ;
int V_28 ;
F_359 (i, nid, &start_pfn, &end_pfn, NULL) {
V_94 = F_371 ( V_94 , V_392 , V_393 ) ;
V_95 = F_371 ( V_95 , V_392 , V_393 ) ;
V_394 -= V_95 - V_94 ;
}
return V_394 ;
}
unsigned long T_2 F_372 ( unsigned long V_94 ,
unsigned long V_95 )
{
return F_370 ( V_334 , V_94 , V_95 ) ;
}
static unsigned long T_3 F_373 ( int V_179 ,
unsigned long V_217 ,
unsigned long * V_391 )
{
unsigned long V_395 = V_385 [ V_217 ] ;
unsigned long V_396 = V_384 [ V_217 ] ;
unsigned long V_387 , V_388 ;
unsigned long V_15 , V_389 ;
F_366 ( V_179 , & V_387 , & V_388 ) ;
V_15 = F_371 ( V_387 , V_395 , V_396 ) ;
V_389 = F_371 ( V_388 , V_395 , V_396 ) ;
F_368 ( V_179 , V_217 ,
V_387 , V_388 ,
& V_15 , & V_389 ) ;
return F_370 ( V_179 , V_15 , V_389 ) ;
}
static inline unsigned long T_3 F_369 ( int V_179 ,
unsigned long V_217 ,
unsigned long * V_397 )
{
return V_397 [ V_217 ] ;
}
static inline unsigned long T_3 F_373 ( int V_179 ,
unsigned long V_217 ,
unsigned long * V_398 )
{
if ( ! V_398 )
return 0 ;
return V_398 [ V_217 ] ;
}
static void T_3 F_374 ( struct V_372 * V_277 ,
unsigned long * V_397 , unsigned long * V_398 )
{
unsigned long V_399 , V_400 = 0 ;
enum V_217 V_28 ;
for ( V_28 = 0 ; V_28 < V_302 ; V_28 ++ )
V_400 += F_369 ( V_277 -> V_350 , V_28 ,
V_397 ) ;
V_277 -> V_401 = V_400 ;
V_399 = V_400 ;
for ( V_28 = 0 ; V_28 < V_302 ; V_28 ++ )
V_399 -=
F_373 ( V_277 -> V_350 , V_28 ,
V_398 ) ;
V_277 -> V_278 = V_399 ;
F_21 ( V_376 L_68 , V_277 -> V_350 ,
V_399 ) ;
}
static unsigned long T_2 F_375 ( unsigned long V_402 )
{
unsigned long V_403 ;
V_403 = F_331 ( V_402 , V_79 ) ;
V_403 = V_403 >> V_81 ;
V_403 *= V_404 ;
V_403 = F_331 ( V_403 , 8 * sizeof( unsigned long ) ) ;
return V_403 / 8 ;
}
static void T_2 F_376 ( struct V_372 * V_277 ,
struct V_11 * V_11 , unsigned long V_402 )
{
unsigned long V_403 = F_375 ( V_402 ) ;
V_11 -> V_405 = NULL ;
if ( V_403 )
V_11 -> V_405 = F_352 ( V_277 ,
V_403 ) ;
}
static inline void F_376 ( struct V_372 * V_277 ,
struct V_11 * V_11 , unsigned long V_402 ) {}
void T_2 F_377 ( void )
{
unsigned int V_27 ;
if ( V_81 )
return;
if ( V_406 > V_369 )
V_27 = V_407 ;
else
V_27 = V_37 - 1 ;
V_81 = V_27 ;
}
void T_2 F_377 ( void )
{
}
static void T_7 F_378 ( struct V_372 * V_277 ,
unsigned long * V_397 , unsigned long * V_398 )
{
enum V_217 V_336 ;
int V_179 = V_277 -> V_350 ;
unsigned long V_15 = V_277 -> V_387 ;
int V_12 ;
F_379 ( V_277 ) ;
F_354 ( & V_277 -> V_408 ) ;
F_354 ( & V_277 -> V_409 ) ;
F_380 ( V_277 ) ;
for ( V_336 = 0 ; V_336 < V_302 ; V_336 ++ ) {
struct V_11 * V_11 = V_277 -> V_279 + V_336 ;
unsigned long V_86 , V_410 , V_411 ;
V_86 = F_369 ( V_179 , V_336 , V_397 ) ;
V_410 = V_86 - F_373 ( V_179 , V_336 ,
V_398 ) ;
V_411 =
F_257 ( V_86 * sizeof( struct V_5 ) ) >> V_369 ;
if ( V_410 >= V_411 ) {
V_410 -= V_411 ;
if ( V_411 )
F_21 ( V_376
L_69 ,
V_359 [ V_336 ] , V_411 ) ;
} else
F_21 ( V_312
L_70 ,
V_359 [ V_336 ] , V_411 , V_410 ) ;
if ( V_336 == 0 && V_410 > V_412 ) {
V_410 -= V_412 ;
F_21 ( V_376 L_71 ,
V_359 [ 0 ] , V_412 ) ;
}
if ( ! F_340 ( V_336 ) )
V_413 += V_410 ;
V_414 += V_410 ;
V_11 -> V_16 = V_86 ;
V_11 -> V_264 = V_410 ;
#ifdef F_311
V_11 -> V_176 = V_179 ;
V_11 -> V_415 = ( V_410 * V_416 )
/ 100 ;
V_11 -> V_417 = ( V_410 * V_418 ) / 100 ;
#endif
V_11 -> V_281 = V_359 [ V_336 ] ;
F_381 ( & V_11 -> V_64 ) ;
F_381 ( & V_11 -> V_419 ) ;
F_382 ( V_11 ) ;
V_11 -> V_177 = V_277 ;
F_355 ( V_11 ) ;
F_383 ( & V_11 -> V_420 ) ;
if ( ! V_86 )
continue;
F_377 () ;
F_376 ( V_277 , V_11 , V_86 ) ;
V_12 = F_356 ( V_11 , V_15 ,
V_86 , V_368 ) ;
F_113 ( V_12 ) ;
F_384 ( V_86 , V_179 , V_336 , V_15 ) ;
V_15 += V_86 ;
}
}
static void T_16 F_385 ( struct V_372 * V_277 )
{
if ( ! V_277 -> V_401 )
return;
#ifdef F_386
if ( ! V_277 -> V_421 ) {
unsigned long V_86 , V_422 , V_260 ;
struct V_5 * V_423 ;
V_422 = V_277 -> V_387 & ~ ( V_424 - 1 ) ;
V_260 = V_277 -> V_387 + V_277 -> V_401 ;
V_260 = F_387 ( V_260 , V_424 ) ;
V_86 = ( V_260 - V_422 ) * sizeof( struct V_5 ) ;
V_423 = F_388 ( V_277 -> V_350 , V_86 ) ;
if ( ! V_423 )
V_423 = F_352 ( V_277 , V_86 ) ;
V_277 -> V_421 = V_423 + ( V_277 -> V_387 - V_422 ) ;
}
#ifndef F_389
if ( V_277 == F_195 ( 0 ) ) {
V_425 = F_195 ( 0 ) -> V_421 ;
#ifdef F_390
if ( F_10 ( V_425 ) != V_277 -> V_387 )
V_425 -= ( V_277 -> V_387 - V_426 ) ;
#endif
}
#endif
#endif
}
void T_7 F_391 ( int V_179 , unsigned long * V_397 ,
unsigned long V_387 , unsigned long * V_398 )
{
T_10 * V_277 = F_195 ( V_179 ) ;
F_2 ( V_277 -> V_306 || V_277 -> V_148 ) ;
V_277 -> V_350 = V_179 ;
V_277 -> V_387 = V_387 ;
F_191 ( V_179 ) ;
F_374 ( V_277 , V_397 , V_398 ) ;
F_385 ( V_277 ) ;
#ifdef F_386
F_21 ( V_376 L_72 ,
V_179 , ( unsigned long ) V_277 ,
( unsigned long ) V_277 -> V_421 ) ;
#endif
F_378 ( V_277 , V_397 , V_398 ) ;
}
static void T_2 F_392 ( void )
{
unsigned int V_176 ;
unsigned int V_427 = 0 ;
F_393 (node, node_possible_map)
V_427 = V_176 ;
V_428 = V_427 + 1 ;
}
static inline void F_392 ( void )
{
}
unsigned long T_2 F_394 ( void )
{
unsigned long V_429 = 0 , V_430 = 0 ;
unsigned long V_422 , V_260 , V_431 ;
int V_432 = - 1 ;
int V_28 , V_179 ;
F_359 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_422 || V_432 < 0 || V_432 == V_179 ) {
V_432 = V_179 ;
V_430 = V_260 ;
continue;
}
V_431 = ~ ( ( 1 << F_395 ( V_422 ) ) - 1 ) ;
while ( V_431 && V_430 <= ( V_422 & ( V_431 << 1 ) ) )
V_431 <<= 1 ;
V_429 |= V_431 ;
}
return ~ V_429 + 1 ;
}
static unsigned long T_2 F_396 ( int V_179 )
{
unsigned long V_433 = V_434 ;
unsigned long V_94 ;
int V_28 ;
F_359 (i, nid, &start_pfn, NULL, NULL)
V_433 = V_151 ( V_433 , V_94 ) ;
if ( V_433 == V_434 ) {
F_21 ( V_312
L_73 , V_179 ) ;
return 0 ;
}
return V_433 ;
}
unsigned long T_2 F_397 ( void )
{
return F_396 ( V_334 ) ;
}
static unsigned long T_2 F_398 ( void )
{
unsigned long V_400 = 0 ;
unsigned long V_94 , V_95 ;
int V_28 , V_179 ;
F_359 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_103 = V_95 - V_94 ;
V_400 += V_103 ;
if ( V_103 )
F_399 ( V_179 , V_170 ) ;
}
return V_400 ;
}
static void T_2 F_400 ( void )
{
int V_28 , V_179 ;
unsigned long V_435 ;
unsigned long V_436 , V_437 ;
T_6 V_438 = V_169 [ V_170 ] ;
unsigned long V_400 = F_398 () ;
int V_439 = F_302 ( V_169 [ V_170 ] ) ;
if ( V_440 ) {
unsigned long V_441 ;
V_440 =
F_331 ( V_440 , V_424 ) ;
V_441 = V_400 - V_440 ;
V_442 = F_325 ( V_442 , V_441 ) ;
}
if ( ! V_442 )
goto V_21;
F_367 () ;
V_435 = V_385 [ V_386 ] ;
V_246:
V_436 = V_442 / V_439 ;
F_296 (nid, N_HIGH_MEMORY) {
unsigned long V_94 , V_95 ;
if ( V_442 < V_436 )
V_436 = V_442 / V_439 ;
V_437 = V_436 ;
F_359 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_443 ;
V_94 = F_325 ( V_94 , V_390 [ V_179 ] ) ;
if ( V_94 >= V_95 )
continue;
if ( V_94 < V_435 ) {
unsigned long V_444 ;
V_444 = V_151 ( V_95 , V_435 )
- V_94 ;
V_437 -= V_151 ( V_444 ,
V_437 ) ;
V_442 -= V_151 ( V_444 ,
V_442 ) ;
if ( V_95 <= V_435 ) {
V_390 [ V_179 ] = V_95 ;
continue;
}
V_94 = V_435 ;
}
V_443 = V_95 - V_94 ;
if ( V_443 > V_437 )
V_443 = V_437 ;
V_390 [ V_179 ] = V_94 + V_443 ;
V_442 -= V_151 ( V_442 ,
V_443 ) ;
V_437 -= V_443 ;
if ( ! V_437 )
break;
}
}
V_439 -- ;
if ( V_439 && V_442 > V_439 )
goto V_246;
for ( V_179 = 0 ; V_179 < V_334 ; V_179 ++ )
V_390 [ V_179 ] =
F_331 ( V_390 [ V_179 ] , V_424 ) ;
V_21:
V_169 [ V_170 ] = V_438 ;
}
static void T_2 F_401 ( T_10 * V_277 )
{
#ifdef F_275
enum V_217 V_217 ;
for ( V_217 = 0 ; V_217 <= V_220 ; V_217 ++ ) {
struct V_11 * V_11 = & V_277 -> V_279 [ V_217 ] ;
if ( V_11 -> V_264 ) {
F_399 ( F_115 ( V_11 ) , V_445 ) ;
break;
}
}
#endif
}
void T_2 F_402 ( unsigned long * V_116 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_179 ;
memset ( V_385 , 0 ,
sizeof( V_385 ) ) ;
memset ( V_384 , 0 ,
sizeof( V_384 ) ) ;
V_385 [ 0 ] = F_397 () ;
V_384 [ 0 ] = V_116 [ 0 ] ;
for ( V_28 = 1 ; V_28 < V_302 ; V_28 ++ ) {
if ( V_28 == V_383 )
continue;
V_385 [ V_28 ] =
V_384 [ V_28 - 1 ] ;
V_384 [ V_28 ] =
F_325 ( V_116 [ V_28 ] , V_385 [ V_28 ] ) ;
}
V_385 [ V_383 ] = 0 ;
V_384 [ V_383 ] = 0 ;
memset ( V_390 , 0 , sizeof( V_390 ) ) ;
F_400 () ;
F_21 ( L_74 ) ;
for ( V_28 = 0 ; V_28 < V_302 ; V_28 ++ ) {
if ( V_28 == V_383 )
continue;
F_21 ( V_446 L_75 , V_359 [ V_28 ] ) ;
if ( V_385 [ V_28 ] ==
V_384 [ V_28 ] )
F_21 ( V_446 L_76 ) ;
else
F_21 ( V_446 L_77 ,
V_385 [ V_28 ] << V_369 ,
( V_384 [ V_28 ]
<< V_369 ) - 1 ) ;
}
F_21 ( L_78 ) ;
for ( V_28 = 0 ; V_28 < V_334 ; V_28 ++ ) {
if ( V_390 [ V_28 ] )
F_21 ( L_79 , V_28 ,
V_390 [ V_28 ] << V_369 ) ;
}
F_21 ( L_80 ) ;
F_359 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_21 ( L_81 , V_179 ,
V_94 << V_369 , ( V_95 << V_369 ) - 1 ) ;
F_403 () ;
F_392 () ;
F_192 (nid) {
T_10 * V_277 = F_195 ( V_179 ) ;
F_391 ( V_179 , NULL ,
F_396 ( V_179 ) , NULL ) ;
if ( V_277 -> V_278 )
F_399 ( V_179 , V_170 ) ;
F_401 ( V_277 ) ;
}
}
static int T_2 F_404 ( char * V_30 , unsigned long * V_447 )
{
unsigned long long V_448 ;
if ( ! V_30 )
return - V_313 ;
V_448 = F_405 ( V_30 , & V_30 ) ;
* V_447 = V_448 >> V_369 ;
F_2 ( ( V_448 >> V_369 ) > V_434 ) ;
return 0 ;
}
static int T_2 F_406 ( char * V_30 )
{
return F_404 ( V_30 , & V_442 ) ;
}
static int T_2 F_407 ( char * V_30 )
{
return F_404 ( V_30 , & V_440 ) ;
}
void T_2 F_408 ( unsigned long V_449 )
{
V_412 = V_449 ;
}
void T_2 F_409 ( unsigned long * V_397 )
{
F_391 ( 0 , V_397 ,
F_410 ( V_450 ) >> V_369 , NULL ) ;
}
static int F_411 ( struct V_451 * V_352 ,
unsigned long V_452 , void * V_453 )
{
int V_109 = ( unsigned long ) V_453 ;
if ( V_452 == V_454 || V_452 == V_455 ) {
F_412 ( V_109 ) ;
F_128 ( V_109 ) ;
F_413 ( V_109 ) ;
F_414 ( V_109 ) ;
}
return V_456 ;
}
void T_2 F_415 ( void )
{
F_416 ( F_411 , 0 ) ;
}
static void F_417 ( void )
{
struct V_372 * V_277 ;
unsigned long V_457 = 0 ;
enum V_217 V_28 , V_336 ;
F_418 (pgdat) {
for ( V_28 = 0 ; V_28 < V_302 ; V_28 ++ ) {
struct V_11 * V_11 = V_277 -> V_279 + V_28 ;
unsigned long F_325 = 0 ;
for ( V_336 = V_28 ; V_336 < V_302 ; V_336 ++ ) {
if ( V_11 -> V_152 [ V_336 ] > F_325 )
F_325 = V_11 -> V_152 [ V_336 ] ;
}
F_325 += F_265 ( V_11 ) ;
if ( F_325 > V_11 -> V_264 )
F_325 = V_11 -> V_264 ;
V_457 += F_325 ;
V_11 -> V_458 = F_325 ;
}
}
V_458 = V_457 ;
V_459 = V_457 ;
}
static void F_419 ( void )
{
struct V_372 * V_277 ;
enum V_217 V_336 , V_460 ;
F_418 (pgdat) {
for ( V_336 = 0 ; V_336 < V_302 ; V_336 ++ ) {
struct V_11 * V_11 = V_277 -> V_279 + V_336 ;
unsigned long V_264 = V_11 -> V_264 ;
V_11 -> V_152 [ V_336 ] = 0 ;
V_460 = V_336 ;
while ( V_460 ) {
struct V_11 * V_461 ;
V_460 -- ;
if ( V_462 [ V_460 ] < 1 )
V_462 [ V_460 ] = 1 ;
V_461 = V_277 -> V_279 + V_460 ;
V_461 -> V_152 [ V_336 ] = V_264 /
V_462 [ V_460 ] ;
V_264 += V_461 -> V_264 ;
}
}
}
F_417 () ;
}
static void F_420 ( void )
{
unsigned long V_463 = V_464 >> ( V_369 - 10 ) ;
unsigned long V_465 = 0 ;
struct V_11 * V_11 ;
unsigned long V_56 ;
F_421 (zone) {
if ( ! F_422 ( V_11 ) )
V_465 += V_11 -> V_264 ;
}
F_421 (zone) {
T_17 V_331 ;
F_139 ( & V_11 -> V_64 , V_56 ) ;
V_331 = ( T_17 ) V_463 * V_11 -> V_264 ;
F_423 ( V_331 , V_465 ) ;
if ( F_422 ( V_11 ) ) {
int V_466 ;
V_466 = V_11 -> V_264 / 1024 ;
if ( V_466 < V_467 )
V_466 = V_467 ;
if ( V_466 > 128 )
V_466 = 128 ;
V_11 -> V_122 [ V_468 ] = V_466 ;
} else {
V_11 -> V_122 [ V_468 ] = V_331 ;
}
V_11 -> V_122 [ V_469 ] = F_279 ( V_11 ) + ( V_331 >> 2 ) ;
V_11 -> V_122 [ V_470 ] = F_279 ( V_11 ) + ( V_331 >> 1 ) ;
V_11 -> V_122 [ V_468 ] += F_424 ( V_11 ) ;
V_11 -> V_122 [ V_469 ] += F_424 ( V_11 ) ;
V_11 -> V_122 [ V_470 ] += F_424 ( V_11 ) ;
F_330 ( V_11 ) ;
F_146 ( & V_11 -> V_64 , V_56 ) ;
}
F_417 () ;
}
void F_425 ( void )
{
F_290 ( & V_325 ) ;
F_420 () ;
F_293 ( & V_325 ) ;
}
static void T_3 F_426 ( struct V_11 * V_11 )
{
unsigned int V_471 , V_472 ;
V_471 = V_11 -> V_264 >> ( 30 - V_369 ) ;
if ( V_471 )
V_472 = F_427 ( 10 * V_471 ) ;
else
V_472 = 1 ;
V_11 -> V_473 = V_472 ;
}
static void T_3 F_428 ( void )
{
struct V_11 * V_11 ;
F_421 (zone)
F_426 ( V_11 ) ;
}
int T_3 F_429 ( void )
{
unsigned long V_474 ;
V_474 = F_266 () * ( V_76 >> 10 ) ;
V_464 = F_427 ( V_474 * 16 ) ;
if ( V_464 < 128 )
V_464 = 128 ;
if ( V_464 > 65536 )
V_464 = 65536 ;
F_425 () ;
F_430 () ;
F_419 () ;
F_428 () ;
return 0 ;
}
int F_431 ( T_11 * V_316 , int V_317 ,
void T_12 * V_318 , T_9 * V_319 , T_13 * V_320 )
{
F_432 ( V_316 , V_317 , V_318 , V_319 , V_320 ) ;
if ( V_317 )
F_425 () ;
return 0 ;
}
int F_433 ( T_11 * V_316 , int V_317 ,
void T_12 * V_318 , T_9 * V_319 , T_13 * V_320 )
{
struct V_11 * V_11 ;
int V_475 ;
V_475 = F_434 ( V_316 , V_317 , V_318 , V_319 , V_320 ) ;
if ( V_475 )
return V_475 ;
F_421 (zone)
V_11 -> V_415 = ( V_11 -> V_264 *
V_416 ) / 100 ;
return 0 ;
}
int F_435 ( T_11 * V_316 , int V_317 ,
void T_12 * V_318 , T_9 * V_319 , T_13 * V_320 )
{
struct V_11 * V_11 ;
int V_475 ;
V_475 = F_434 ( V_316 , V_317 , V_318 , V_319 , V_320 ) ;
if ( V_475 )
return V_475 ;
F_421 (zone)
V_11 -> V_417 = ( V_11 -> V_264 *
V_418 ) / 100 ;
return 0 ;
}
int F_436 ( T_11 * V_316 , int V_317 ,
void T_12 * V_318 , T_9 * V_319 , T_13 * V_320 )
{
F_434 ( V_316 , V_317 , V_318 , V_319 , V_320 ) ;
F_419 () ;
return 0 ;
}
int F_437 ( T_11 * V_316 , int V_317 ,
void T_12 * V_318 , T_9 * V_319 , T_13 * V_320 )
{
struct V_11 * V_11 ;
unsigned int V_109 ;
int V_12 ;
V_12 = F_434 ( V_316 , V_317 , V_318 , V_319 , V_320 ) ;
if ( ! V_317 || ( V_12 < 0 ) )
return V_12 ;
F_129 (zone) {
F_312 (cpu) {
unsigned long V_84 ;
V_84 = V_11 -> V_264 / V_370 ;
F_347 (
F_130 ( V_11 -> V_112 , V_109 ) , V_84 ) ;
}
}
return 0 ;
}
static int T_2 F_438 ( char * V_130 )
{
if ( ! V_130 )
return 0 ;
V_476 = F_439 ( V_130 , & V_130 , 0 ) ;
return 1 ;
}
void * T_2 F_440 ( const char * V_477 ,
unsigned long V_478 ,
unsigned long V_479 ,
int V_480 ,
int V_56 ,
unsigned int * V_481 ,
unsigned int * V_482 ,
unsigned long V_483 ,
unsigned long V_484 )
{
unsigned long long F_325 = V_484 ;
unsigned long V_485 , V_86 ;
void * V_316 = NULL ;
if ( ! V_479 ) {
V_479 = V_413 ;
V_479 += ( 1UL << ( 20 - V_369 ) ) - 1 ;
V_479 >>= 20 - V_369 ;
V_479 <<= 20 - V_369 ;
if ( V_480 > V_369 )
V_479 >>= ( V_480 - V_369 ) ;
else
V_479 <<= ( V_369 - V_480 ) ;
if ( F_7 ( V_56 & V_486 ) ) {
F_2 ( ! ( V_56 & V_487 ) ) ;
if ( ! ( V_479 >> * V_481 ) ) {
V_479 = 1UL << * V_481 ;
F_113 ( ! V_479 ) ;
}
} else if ( F_7 ( ( V_479 * V_478 ) < V_76 ) )
V_479 = V_76 / V_478 ;
}
V_479 = F_441 ( V_479 ) ;
if ( F_325 == 0 ) {
F_325 = ( ( unsigned long long ) V_414 << V_369 ) >> 4 ;
F_423 ( F_325 , V_478 ) ;
}
F_325 = V_151 ( F_325 , 0x80000000ULL ) ;
if ( V_479 < V_483 )
V_479 = V_483 ;
if ( V_479 > F_325 )
V_479 = F_325 ;
V_485 = F_442 ( V_479 ) ;
do {
V_86 = V_478 << V_485 ;
if ( V_56 & V_487 )
V_316 = F_443 ( V_86 ) ;
else if ( V_476 )
V_316 = F_444 ( V_86 , V_488 , V_489 ) ;
else {
if ( F_260 ( V_86 ) < V_37 ) {
V_316 = F_259 ( V_86 , V_488 ) ;
F_445 ( V_316 , V_86 , 1 , V_488 ) ;
}
}
} while ( ! V_316 && V_86 > V_76 && -- V_485 );
if ( ! V_316 )
F_446 ( L_82 , V_477 ) ;
F_21 ( V_40 L_83 ,
V_477 ,
( 1UL << V_485 ) ,
F_442 ( V_86 ) - V_369 ,
V_86 ) ;
if ( V_481 )
* V_481 = V_485 ;
if ( V_482 )
* V_482 = ( 1 << V_485 ) - 1 ;
return V_316 ;
}
static inline unsigned long * F_447 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef F_448
return F_449 ( V_14 ) -> V_405 ;
#else
return V_11 -> V_405 ;
#endif
}
static inline int F_450 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef F_448
V_14 &= ( V_490 - 1 ) ;
return ( V_14 >> V_81 ) * V_404 ;
#else
V_14 = V_14 - V_11 -> V_15 ;
return ( V_14 >> V_81 ) * V_404 ;
#endif
}
unsigned long F_451 ( struct V_5 * V_5 ,
int V_491 , int V_492 )
{
struct V_11 * V_11 ;
unsigned long * V_493 ;
unsigned long V_14 , V_494 ;
unsigned long V_56 = 0 ;
unsigned long V_495 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_493 = F_447 ( V_11 , V_14 ) ;
V_494 = F_450 ( V_11 , V_14 ) ;
for (; V_491 <= V_492 ; V_491 ++ , V_495 <<= 1 )
if ( F_186 ( V_494 + V_491 , V_493 ) )
V_56 |= V_495 ;
return V_56 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_56 ,
int V_491 , int V_492 )
{
struct V_11 * V_11 ;
unsigned long * V_493 ;
unsigned long V_14 , V_494 ;
unsigned long V_495 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_493 = F_447 ( V_11 , V_14 ) ;
V_494 = F_450 ( V_11 , V_14 ) ;
F_41 ( V_14 < V_11 -> V_15 ) ;
F_41 ( V_14 >= V_11 -> V_15 + V_11 -> V_16 ) ;
for (; V_491 <= V_492 ; V_491 ++ , V_495 <<= 1 )
if ( V_56 & V_495 )
F_47 ( V_494 + V_491 , V_493 ) ;
else
F_49 ( V_494 + V_491 , V_493 ) ;
}
bool F_452 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_59 )
{
unsigned long V_14 , V_496 , V_497 ;
int V_71 ;
if ( F_197 ( V_11 ) == V_383 )
return false ;
V_71 = F_94 ( V_5 ) ;
if ( V_71 == V_119 || F_78 ( V_71 ) )
return false ;
V_14 = F_10 ( V_5 ) ;
for ( V_497 = 0 , V_496 = 0 ; V_496 < V_79 ; V_496 ++ ) {
unsigned long V_498 = V_14 + V_496 ;
if ( ! F_14 ( V_498 ) )
continue;
V_5 = F_118 ( V_498 ) ;
if ( ! F_70 ( & V_5 -> V_55 ) ) {
if ( F_61 ( V_5 ) )
V_496 += ( 1 << F_59 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_453 ( V_5 ) )
V_497 ++ ;
if ( V_497 > V_59 )
return true ;
}
return false ;
}
bool F_454 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_309 ( F_114 ( V_5 ) ) )
return false ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( V_11 -> V_15 > V_14 ||
V_11 -> V_15 + V_11 -> V_16 <= V_14 )
return false ;
return ! F_452 ( V_11 , V_5 , 0 ) ;
}
static unsigned long F_455 ( unsigned long V_14 )
{
return V_14 & ~ ( F_456 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_457 ( unsigned long V_14 )
{
return F_387 ( V_14 , F_456 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_458 ( struct V_499 * V_500 ,
unsigned long V_422 , unsigned long V_260 )
{
unsigned long V_501 ;
unsigned long V_14 = V_422 ;
unsigned int V_502 = 0 ;
int V_12 = 0 ;
F_459 () ;
while ( V_14 < V_260 || ! F_74 ( & V_500 -> V_503 ) ) {
if ( F_460 ( V_24 ) ) {
V_12 = - V_504 ;
break;
}
if ( F_74 ( & V_500 -> V_503 ) ) {
V_500 -> V_505 = 0 ;
V_14 = F_461 ( V_500 -> V_11 , V_500 ,
V_14 , V_260 , true ) ;
if ( ! V_14 ) {
V_12 = - V_504 ;
break;
}
V_502 = 0 ;
} else if ( ++ V_502 == 5 ) {
V_12 = V_12 < 0 ? V_12 : - V_506 ;
break;
}
V_501 = F_462 ( V_500 -> V_11 ,
& V_500 -> V_503 ) ;
V_500 -> V_505 -= V_501 ;
V_12 = F_463 ( & V_500 -> V_503 ,
V_507 ,
0 , false , V_508 ) ;
}
F_464 ( & V_500 -> V_503 ) ;
return V_12 > 0 ? 0 : V_12 ;
}
static inline void F_465 ( struct V_11 * V_11 , int V_59 )
{
unsigned long V_56 ;
F_139 ( & V_11 -> V_64 , V_56 ) ;
V_11 -> V_509 += V_59 ;
F_146 ( & V_11 -> V_64 , V_56 ) ;
F_425 () ;
}
static int F_466 ( struct V_11 * V_11 , T_1 V_133 , int V_59 )
{
enum V_217 V_183 = F_245 ( V_133 ) ;
struct V_159 * V_159 = F_241 ( 0 , V_133 ) ;
int V_212 = 0 ;
int V_27 = 1 ;
F_465 ( V_11 , V_59 ) ;
while ( ! F_159 ( V_11 , 0 , F_158 ( V_11 ) , 0 , 0 ) ) {
F_231 ( V_27 , V_159 , V_183 , F_197 ( V_11 ) ) ;
V_212 = F_223 ( V_133 , V_27 , V_159 ,
NULL ) ;
if ( ! V_212 ) {
F_213 ( V_159 , V_133 , V_27 , NULL , false ) ;
}
}
F_465 ( V_11 , - V_59 ) ;
return V_59 ;
}
int F_467 ( unsigned long V_422 , unsigned long V_260 ,
unsigned V_6 )
{
struct V_11 * V_11 = F_15 ( F_118 ( V_422 ) ) ;
unsigned long V_510 , V_511 ;
int V_12 = 0 , V_27 ;
struct V_499 V_500 = {
. V_505 = 0 ,
. V_27 = - 1 ,
. V_11 = F_15 ( F_118 ( V_422 ) ) ,
. V_512 = true ,
. V_513 = true ,
} ;
F_106 ( & V_500 . V_503 ) ;
V_12 = F_468 ( F_455 ( V_422 ) ,
F_457 ( V_260 ) , V_6 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_458 ( & V_500 , V_422 , V_260 ) ;
if ( V_12 )
goto V_514;
F_469 () ;
F_133 () ;
V_27 = 0 ;
V_510 = V_422 ;
while ( ! F_61 ( F_118 ( V_510 ) ) ) {
if ( ++ V_27 >= V_37 ) {
V_12 = - V_506 ;
goto V_514;
}
V_510 &= ~ 0UL << V_27 ;
}
if ( F_470 ( V_510 , V_260 ) ) {
F_207 ( L_84 ,
V_510 , V_260 ) ;
V_12 = - V_506 ;
goto V_514;
}
F_466 ( V_11 , V_266 , V_260 - V_422 ) ;
V_511 = F_471 ( & V_500 , V_510 , V_260 ) ;
if ( ! V_511 ) {
V_12 = - V_506 ;
goto V_514;
}
if ( V_422 != V_510 )
F_472 ( V_510 , V_422 - V_510 ) ;
if ( V_260 != V_511 )
F_472 ( V_260 , V_511 - V_260 ) ;
V_514:
F_473 ( F_455 ( V_422 ) ,
F_457 ( V_260 ) , V_6 ) ;
return V_12 ;
}
void F_472 ( unsigned long V_14 , unsigned V_29 )
{
for (; V_29 -- ; ++ V_14 )
F_474 ( F_118 ( V_14 ) ) ;
}
static int T_3 F_475 ( void * V_323 )
{
struct V_11 * V_11 = V_323 ;
int V_109 ;
unsigned long V_108 = F_344 ( V_11 ) , V_56 ;
F_312 (cpu) {
struct V_110 * V_111 ;
struct V_60 * V_61 ;
V_111 = F_130 ( V_11 -> V_112 , V_109 ) ;
V_61 = & V_111 -> V_61 ;
F_92 ( V_56 ) ;
if ( V_61 -> V_59 > 0 )
F_72 ( V_11 , V_61 -> V_59 , V_61 ) ;
F_476 ( V_11 , V_111 ) ;
F_313 ( V_111 , V_108 ) ;
F_96 ( V_56 ) ;
}
return 0 ;
}
void T_3 F_477 ( struct V_11 * V_11 )
{
F_323 ( F_475 , V_11 , NULL ) ;
}
void F_478 ( struct V_11 * V_11 )
{
unsigned long V_56 ;
int V_109 ;
struct V_110 * V_111 ;
F_92 ( V_56 ) ;
if ( V_11 -> V_112 != & V_353 ) {
F_134 (cpu) {
V_111 = F_130 ( V_11 -> V_112 , V_109 ) ;
F_476 ( V_11 , V_111 ) ;
}
F_479 ( V_11 -> V_112 ) ;
V_11 -> V_112 = & V_353 ;
}
F_96 ( V_56 ) ;
}
void
F_480 ( unsigned long V_94 , unsigned long V_95 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_27 , V_28 ;
unsigned long V_14 ;
unsigned long V_56 ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 ++ )
if ( F_140 ( V_14 ) )
break;
if ( V_14 == V_95 )
return;
V_11 = F_15 ( F_118 ( V_14 ) ) ;
F_139 ( & V_11 -> V_64 , V_56 ) ;
V_14 = V_94 ;
while ( V_14 < V_95 ) {
if ( ! F_140 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_118 ( V_14 ) ;
F_113 ( F_60 ( V_5 ) ) ;
F_113 ( ! F_61 ( V_5 ) ) ;
V_27 = F_59 ( V_5 ) ;
#ifdef F_481
F_21 ( V_40 L_85 ,
V_14 , 1 << V_27 , V_95 ) ;
#endif
F_65 ( & V_5 -> V_48 ) ;
F_53 ( V_5 ) ;
V_11 -> V_49 [ V_27 ] . V_50 -- ;
F_79 ( V_11 , V_74 ,
- ( 1UL << V_27 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_338 ( ( V_5 + V_28 ) ) ;
V_14 += ( 1 << V_27 ) ;
}
F_146 ( & V_11 -> V_64 , V_56 ) ;
}
bool F_482 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_15 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_56 ;
int V_27 ;
F_139 ( & V_11 -> V_64 , V_56 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
struct V_5 * V_515 = V_5 - ( V_14 & ( ( 1 << V_27 ) - 1 ) ) ;
if ( F_61 ( V_515 ) && F_59 ( V_515 ) >= V_27 )
break;
}
F_146 ( & V_11 -> V_64 , V_56 ) ;
return V_27 < V_37 ;
}
static void F_483 ( unsigned long V_56 )
{
const char * V_516 = L_86 ;
unsigned long V_431 ;
int V_28 ;
F_201 ( F_484 ( V_517 ) != V_518 ) ;
F_21 ( V_22 L_87 , V_56 ) ;
V_56 &= ( 1UL << V_519 ) - 1 ;
for ( V_28 = 0 ; V_28 < F_484 ( V_517 ) && V_56 ; V_28 ++ ) {
V_431 = V_517 [ V_28 ] . V_431 ;
if ( ( V_56 & V_431 ) != V_431 )
continue;
V_56 &= ~ V_431 ;
F_21 ( L_88 , V_516 , V_517 [ V_28 ] . V_281 ) ;
V_516 = L_89 ;
}
if ( V_56 )
F_21 ( L_90 , V_516 , V_56 ) ;
F_21 ( L_91 ) ;
}
void F_22 ( struct V_5 * V_5 )
{
F_21 ( V_22
L_92 ,
V_5 , F_70 ( & V_5 -> V_55 ) , F_69 ( V_5 ) ,
V_5 -> V_54 , V_5 -> V_520 ) ;
F_483 ( V_5 -> V_56 ) ;
F_485 ( V_5 ) ;
}
