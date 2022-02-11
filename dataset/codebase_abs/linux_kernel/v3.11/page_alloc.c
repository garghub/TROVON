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
unsigned long V_15 , V_16 ;
do {
V_13 = F_11 ( V_11 ) ;
V_16 = V_11 -> V_17 ;
V_15 = V_11 -> V_18 ;
if ( ! F_12 ( V_11 , V_14 ) )
V_12 = 1 ;
} while ( F_13 ( V_11 , V_13 ) );
if ( V_12 )
F_14 ( L_1 ,
V_14 , V_16 , V_16 + V_15 ) ;
return V_12 ;
}
static int F_15 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
if ( ! F_16 ( F_10 ( V_5 ) ) )
return 0 ;
if ( V_11 != F_17 ( V_5 ) )
return 0 ;
return 1 ;
}
static int F_18 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
if ( F_9 ( V_11 , V_5 ) )
return 1 ;
if ( ! F_15 ( V_11 , V_5 ) )
return 1 ;
return 0 ;
}
static inline int F_18 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
return 0 ;
}
static void F_19 ( struct V_5 * V_5 )
{
static unsigned long V_19 ;
static unsigned long V_20 ;
static unsigned long V_21 ;
if ( F_20 ( V_5 ) ) {
F_21 ( V_5 ) ;
return;
}
if ( V_20 == 60 ) {
if ( F_22 ( V_22 , V_19 ) ) {
V_21 ++ ;
goto V_23;
}
if ( V_21 ) {
F_23 ( V_24
L_2 ,
V_21 ) ;
V_21 = 0 ;
}
V_20 = 0 ;
}
if ( V_20 ++ == 0 )
V_19 = V_22 + 60 * V_25 ;
F_23 ( V_24 L_3 ,
V_26 -> V_27 , F_10 ( V_5 ) ) ;
F_24 ( V_5 ) ;
F_25 () ;
F_26 () ;
V_23:
F_21 ( V_5 ) ;
F_27 ( V_28 , V_29 ) ;
}
static void F_28 ( struct V_5 * V_5 )
{
F_29 ( V_5 , F_30 ( V_5 ) ) ;
}
void F_31 ( struct V_5 * V_5 , unsigned long V_30 )
{
int V_31 ;
int V_32 = 1 << V_30 ;
F_32 ( V_5 , F_28 ) ;
F_33 ( V_5 , V_30 ) ;
F_34 ( V_5 ) ;
for ( V_31 = 1 ; V_31 < V_32 ; V_31 ++ ) {
struct V_5 * V_33 = V_5 + V_31 ;
F_35 ( V_33 ) ;
F_36 ( V_33 , 0 ) ;
V_33 -> V_34 = V_5 ;
}
}
static int F_37 ( struct V_5 * V_5 , unsigned long V_30 )
{
int V_31 ;
int V_32 = 1 << V_30 ;
int V_35 = 0 ;
if ( F_7 ( F_30 ( V_5 ) != V_30 ) ) {
F_19 ( V_5 ) ;
V_35 ++ ;
}
F_38 ( V_5 ) ;
for ( V_31 = 1 ; V_31 < V_32 ; V_31 ++ ) {
struct V_5 * V_33 = V_5 + V_31 ;
if ( F_7 ( ! F_39 ( V_33 ) || ( V_33 -> V_34 != V_5 ) ) ) {
F_19 ( V_5 ) ;
V_35 ++ ;
}
F_40 ( V_33 ) ;
}
return V_35 ;
}
static inline void F_41 ( struct V_5 * V_5 , int V_30 , T_1 V_36 )
{
int V_31 ;
F_42 ( ( V_36 & V_37 ) && F_43 () ) ;
for ( V_31 = 0 ; V_31 < ( 1 << V_30 ) ; V_31 ++ )
F_44 ( V_5 + V_31 ) ;
}
static int T_2 F_45 ( char * V_38 )
{
unsigned long V_39 ;
if ( F_46 ( V_38 , 10 , & V_39 ) < 0 || V_39 > V_40 / 2 ) {
F_23 ( V_41 L_4 ) ;
return 0 ;
}
V_42 = V_39 ;
F_23 ( V_43 L_5 , V_39 ) ;
return 0 ;
}
static inline void F_47 ( struct V_5 * V_5 )
{
F_48 ( V_44 , & V_5 -> V_45 ) ;
}
static inline void F_49 ( struct V_5 * V_5 )
{
F_50 ( V_44 , & V_5 -> V_45 ) ;
}
static inline void F_47 ( struct V_5 * V_5 ) { }
static inline void F_49 ( struct V_5 * V_5 ) { }
static inline void F_51 ( struct V_5 * V_5 , int V_30 )
{
F_52 ( V_5 , V_30 ) ;
F_53 ( V_5 ) ;
}
static inline void F_54 ( struct V_5 * V_5 )
{
F_55 ( V_5 ) ;
F_52 ( V_5 , 0 ) ;
}
static inline unsigned long
F_56 ( unsigned long V_46 , unsigned int V_30 )
{
return V_46 ^ ( 1 << V_30 ) ;
}
static inline int F_57 ( struct V_5 * V_5 , struct V_5 * V_47 ,
int V_30 )
{
if ( ! F_16 ( F_10 ( V_47 ) ) )
return 0 ;
if ( F_58 ( V_5 ) != F_58 ( V_47 ) )
return 0 ;
if ( F_59 ( V_47 ) && F_60 ( V_47 ) == V_30 ) {
F_42 ( F_61 ( V_47 ) != 0 ) ;
return 1 ;
}
if ( F_62 ( V_47 ) && F_60 ( V_47 ) == V_30 ) {
F_42 ( F_61 ( V_47 ) != 0 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_63 ( struct V_5 * V_5 ,
struct V_11 * V_11 , unsigned int V_30 ,
int V_6 )
{
unsigned long V_46 ;
unsigned long V_48 ;
unsigned long V_49 ( V_50 ) ;
struct V_5 * V_47 ;
F_42 ( ! F_64 ( V_11 ) ) ;
if ( F_7 ( F_65 ( V_5 ) ) )
if ( F_7 ( F_37 ( V_5 , V_30 ) ) )
return;
F_42 ( V_6 == - 1 ) ;
V_46 = F_10 ( V_5 ) & ( ( 1 << V_40 ) - 1 ) ;
F_42 ( V_46 & ( ( 1 << V_30 ) - 1 ) ) ;
F_42 ( F_18 ( V_11 , V_5 ) ) ;
while ( V_30 < V_40 - 1 ) {
V_50 = F_56 ( V_46 , V_30 ) ;
V_47 = V_5 + ( V_50 - V_46 ) ;
if ( ! F_57 ( V_5 , V_47 , V_30 ) )
break;
if ( F_59 ( V_47 ) ) {
F_49 ( V_47 ) ;
F_52 ( V_5 , 0 ) ;
F_66 ( V_11 , 1 << V_30 ,
V_6 ) ;
} else {
F_67 ( & V_47 -> V_51 ) ;
V_11 -> V_52 [ V_30 ] . V_53 -- ;
F_54 ( V_47 ) ;
}
V_48 = V_50 & V_46 ;
V_5 = V_5 + ( V_48 - V_46 ) ;
V_46 = V_48 ;
V_30 ++ ;
}
F_51 ( V_5 , V_30 ) ;
if ( ( V_30 < V_40 - 2 ) && F_16 ( F_10 ( V_47 ) ) ) {
struct V_5 * V_54 , * V_55 ;
V_48 = V_50 & V_46 ;
V_54 = V_5 + ( V_48 - V_46 ) ;
V_50 = F_56 ( V_48 , V_30 + 1 ) ;
V_55 = V_54 + ( V_50 - V_48 ) ;
if ( F_57 ( V_54 , V_55 , V_30 + 1 ) ) {
F_68 ( & V_5 -> V_51 ,
& V_11 -> V_52 [ V_30 ] . V_56 [ V_6 ] ) ;
goto V_23;
}
}
F_69 ( & V_5 -> V_51 , & V_11 -> V_52 [ V_30 ] . V_56 [ V_6 ] ) ;
V_23:
V_11 -> V_52 [ V_30 ] . V_53 ++ ;
}
static inline int F_70 ( struct V_5 * V_5 )
{
if ( F_7 ( F_71 ( V_5 ) |
( V_5 -> V_57 != NULL ) |
( F_72 ( & V_5 -> V_58 ) != 0 ) |
( V_5 -> V_59 & V_60 ) |
( F_73 ( V_5 ) ) ) ) {
F_19 ( V_5 ) ;
return 1 ;
}
F_74 ( V_5 ) ;
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
int V_74 ;
V_5 = F_78 ( V_71 -> V_75 , struct V_5 , V_51 ) ;
F_67 ( & V_5 -> V_51 ) ;
V_74 = F_79 ( V_5 ) ;
F_63 ( V_5 , V_11 , 0 , V_74 ) ;
F_80 ( V_5 , 0 , V_74 ) ;
if ( F_81 ( ! F_82 ( V_5 ) ) ) {
F_83 ( V_11 , V_76 , 1 ) ;
if ( F_84 ( V_74 ) )
F_83 ( V_11 , V_77 , 1 ) ;
}
} while ( -- V_66 && -- V_65 && ! F_77 ( V_71 ) );
}
F_85 ( & V_11 -> V_67 ) ;
}
static void F_86 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_30 ,
int V_6 )
{
F_76 ( & V_11 -> V_67 ) ;
V_11 -> V_68 = 0 ;
V_11 -> V_69 = 0 ;
F_63 ( V_5 , V_11 , V_30 , V_6 ) ;
if ( F_7 ( ! F_87 ( V_6 ) ) )
F_66 ( V_11 , 1 << V_30 , V_6 ) ;
F_85 ( & V_11 -> V_67 ) ;
}
static bool F_88 ( struct V_5 * V_5 , unsigned int V_30 )
{
int V_31 ;
int V_35 = 0 ;
F_89 ( V_5 , V_30 ) ;
F_90 ( V_5 , V_30 ) ;
if ( F_91 ( V_5 ) )
V_5 -> V_57 = NULL ;
for ( V_31 = 0 ; V_31 < ( 1 << V_30 ) ; V_31 ++ )
V_35 += F_70 ( V_5 + V_31 ) ;
if ( V_35 )
return false ;
if ( ! F_92 ( V_5 ) ) {
F_93 ( F_94 ( V_5 ) , V_78 << V_30 ) ;
F_95 ( F_94 ( V_5 ) ,
V_78 << V_30 ) ;
}
F_96 ( V_5 , V_30 ) ;
F_97 ( V_5 , 1 << V_30 , 0 ) ;
return true ;
}
static void F_29 ( struct V_5 * V_5 , unsigned int V_30 )
{
unsigned long V_59 ;
int V_6 ;
if ( ! F_88 ( V_5 , V_30 ) )
return;
F_98 ( V_59 ) ;
F_99 ( V_79 , 1 << V_30 ) ;
V_6 = F_100 ( V_5 ) ;
F_101 ( V_5 , V_6 ) ;
F_86 ( F_17 ( V_5 ) , V_5 , V_30 , V_6 ) ;
F_102 ( V_59 ) ;
}
void T_2 F_103 ( struct V_5 * V_5 , unsigned int V_30 )
{
unsigned int V_32 = 1 << V_30 ;
unsigned int V_80 ;
F_104 ( V_5 ) ;
for ( V_80 = 0 ; V_80 < V_32 ; V_80 ++ ) {
struct V_5 * V_33 = & V_5 [ V_80 ] ;
if ( V_80 + 1 < V_32 )
F_104 ( V_33 + 1 ) ;
F_105 ( V_33 ) ;
F_36 ( V_33 , 0 ) ;
}
F_17 ( V_5 ) -> V_81 += 1 << V_30 ;
F_106 ( V_5 ) ;
F_107 ( V_5 , V_30 ) ;
}
void T_2 F_108 ( struct V_5 * V_5 )
{
unsigned V_31 = V_82 ;
struct V_5 * V_33 = V_5 ;
do {
F_105 ( V_33 ) ;
F_36 ( V_33 , 0 ) ;
} while ( ++ V_33 , -- V_31 );
F_106 ( V_5 ) ;
F_6 ( V_5 , V_83 ) ;
F_107 ( V_5 , V_84 ) ;
F_109 ( V_5 , V_82 ) ;
}
static inline void F_110 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_85 , int V_86 , struct V_52 * V_87 ,
int V_6 )
{
unsigned long V_88 = 1 << V_86 ;
while ( V_86 > V_85 ) {
V_87 -- ;
V_86 -- ;
V_88 >>= 1 ;
F_42 ( F_18 ( V_11 , & V_5 [ V_88 ] ) ) ;
#ifdef F_111
if ( V_86 < F_112 () ) {
F_113 ( & V_5 [ V_88 ] . V_51 ) ;
F_47 ( & V_5 [ V_88 ] ) ;
F_52 ( & V_5 [ V_88 ] , V_86 ) ;
F_66 ( V_11 , - ( 1 << V_86 ) ,
V_6 ) ;
continue;
}
#endif
F_69 ( & V_5 [ V_88 ] . V_51 , & V_87 -> V_56 [ V_6 ] ) ;
V_87 -> V_53 ++ ;
F_51 ( & V_5 [ V_88 ] , V_86 ) ;
}
}
static inline int F_114 ( struct V_5 * V_5 )
{
if ( F_7 ( F_71 ( V_5 ) |
( V_5 -> V_57 != NULL ) |
( F_72 ( & V_5 -> V_58 ) != 0 ) |
( V_5 -> V_59 & V_61 ) |
( F_73 ( V_5 ) ) ) ) {
F_19 ( V_5 ) ;
return 1 ;
}
return 0 ;
}
static int F_115 ( struct V_5 * V_5 , int V_30 , T_1 V_36 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < ( 1 << V_30 ) ; V_31 ++ ) {
struct V_5 * V_33 = V_5 + V_31 ;
if ( F_7 ( F_114 ( V_33 ) ) )
return 1 ;
}
F_52 ( V_5 , 0 ) ;
F_106 ( V_5 ) ;
F_116 ( V_5 , V_30 ) ;
F_97 ( V_5 , 1 << V_30 , 1 ) ;
if ( V_36 & V_89 )
F_41 ( V_5 , V_30 , V_36 ) ;
if ( V_30 && ( V_36 & V_90 ) )
F_31 ( V_5 , V_30 ) ;
return 0 ;
}
static inline
struct V_5 * F_117 ( struct V_11 * V_11 , unsigned int V_30 ,
int V_6 )
{
unsigned int V_91 ;
struct V_52 * V_87 ;
struct V_5 * V_5 ;
for ( V_91 = V_30 ; V_91 < V_40 ; ++ V_91 ) {
V_87 = & ( V_11 -> V_52 [ V_91 ] ) ;
if ( F_77 ( & V_87 -> V_56 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_87 -> V_56 [ V_6 ] . V_92 ,
struct V_5 , V_51 ) ;
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
V_87 -> V_53 -- ;
F_110 ( V_11 , V_5 , V_30 , V_91 , V_87 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_118 ( struct V_11 * V_11 ,
struct V_5 * V_93 , struct V_5 * V_94 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_30 ;
int V_95 = 0 ;
#ifndef F_119
F_120 ( F_17 ( V_93 ) != F_17 ( V_94 ) ) ;
#endif
for ( V_5 = V_93 ; V_5 <= V_94 ; ) {
F_42 ( F_121 ( V_5 ) != F_122 ( V_11 ) ) ;
if ( ! F_16 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_62 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_30 = F_60 ( V_5 ) ;
F_123 ( & V_5 -> V_51 ,
& V_11 -> V_52 [ V_30 ] . V_56 [ V_6 ] ) ;
F_101 ( V_5 , V_6 ) ;
V_5 += 1 << V_30 ;
V_95 += 1 << V_30 ;
}
return V_95 ;
}
int F_124 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_16 , V_96 ;
struct V_5 * V_93 , * V_94 ;
V_16 = F_10 ( V_5 ) ;
V_16 = V_16 & ~ ( V_82 - 1 ) ;
V_93 = F_125 ( V_16 ) ;
V_94 = V_93 + V_82 - 1 ;
V_96 = V_16 + V_82 - 1 ;
if ( ! F_12 ( V_11 , V_16 ) )
V_93 = V_5 ;
if ( ! F_12 ( V_11 , V_96 ) )
return 0 ;
return F_118 ( V_11 , V_93 , V_94 , V_6 ) ;
}
static void F_126 ( struct V_5 * V_97 ,
int V_98 , int V_6 )
{
int V_99 = 1 << ( V_98 - V_84 ) ;
while ( V_99 -- ) {
F_6 ( V_97 , V_6 ) ;
V_97 += V_82 ;
}
}
static inline struct V_5 *
F_127 ( struct V_11 * V_11 , int V_30 , int V_100 )
{
struct V_52 * V_87 ;
int V_91 ;
struct V_5 * V_5 ;
int V_6 , V_31 ;
for ( V_91 = V_40 - 1 ; V_91 >= V_30 ;
-- V_91 ) {
for ( V_31 = 0 ; ; V_31 ++ ) {
V_6 = V_101 [ V_100 ] [ V_31 ] ;
if ( V_6 == V_102 )
break;
V_87 = & ( V_11 -> V_52 [ V_91 ] ) ;
if ( F_77 ( & V_87 -> V_56 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_87 -> V_56 [ V_6 ] . V_92 ,
struct V_5 , V_51 ) ;
V_87 -> V_53 -- ;
if ( ! F_84 ( V_6 ) &&
( V_91 >= V_84 / 2 ||
V_100 == V_103 ||
V_7 ) ) {
int V_104 ;
V_104 = F_124 ( V_11 , V_5 ,
V_100 ) ;
if ( V_104 >= ( 1 << ( V_84 - 1 ) ) ||
V_7 )
F_6 ( V_5 ,
V_100 ) ;
V_6 = V_100 ;
}
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
if ( V_91 >= V_84 &&
! F_84 ( V_6 ) )
F_126 ( V_5 , V_91 ,
V_100 ) ;
F_110 ( V_11 , V_5 , V_30 , V_91 , V_87 ,
F_84 ( V_6 )
? V_6 : V_100 ) ;
F_128 ( V_5 , V_30 , V_91 ,
V_100 , V_6 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_129 ( struct V_11 * V_11 , unsigned int V_30 ,
int V_6 )
{
struct V_5 * V_5 ;
V_105:
V_5 = F_117 ( V_11 , V_30 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_102 ) {
V_5 = F_127 ( V_11 , V_30 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_102 ;
goto V_105;
}
}
F_130 ( V_5 , V_30 , V_6 ) ;
return V_5 ;
}
static int F_131 ( struct V_11 * V_11 , unsigned int V_30 ,
unsigned long V_62 , struct V_70 * V_71 ,
int V_6 , int V_106 )
{
int V_74 = V_6 , V_31 ;
F_76 ( & V_11 -> V_67 ) ;
for ( V_31 = 0 ; V_31 < V_62 ; ++ V_31 ) {
struct V_5 * V_5 = F_129 ( V_11 , V_30 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_81 ( V_106 == 0 ) )
F_69 ( & V_5 -> V_51 , V_71 ) ;
else
F_68 ( & V_5 -> V_51 , V_71 ) ;
if ( F_132 ( V_107 ) ) {
V_74 = F_100 ( V_5 ) ;
if ( ! F_84 ( V_74 ) && ! F_87 ( V_74 ) )
V_74 = V_6 ;
}
F_101 ( V_5 , V_74 ) ;
V_71 = & V_5 -> V_51 ;
if ( F_84 ( V_74 ) )
F_83 ( V_11 , V_77 ,
- ( 1 << V_30 ) ) ;
}
F_83 ( V_11 , V_76 , - ( V_31 << V_30 ) ) ;
F_85 ( & V_11 -> V_67 ) ;
return V_31 ;
}
void F_133 ( struct V_11 * V_11 , struct V_63 * V_64 )
{
unsigned long V_59 ;
int V_108 ;
unsigned long V_109 ;
F_98 ( V_59 ) ;
V_109 = F_134 ( V_64 -> V_109 ) ;
if ( V_64 -> V_62 >= V_109 )
V_108 = V_109 ;
else
V_108 = V_64 -> V_62 ;
if ( V_108 > 0 ) {
F_75 ( V_11 , V_108 , V_64 ) ;
V_64 -> V_62 -= V_108 ;
}
F_102 ( V_59 ) ;
}
static void F_135 ( unsigned int V_110 )
{
unsigned long V_59 ;
struct V_11 * V_11 ;
F_136 (zone) {
struct V_111 * V_112 ;
struct V_63 * V_64 ;
F_98 ( V_59 ) ;
V_112 = F_137 ( V_11 -> V_113 , V_110 ) ;
V_64 = & V_112 -> V_64 ;
if ( V_64 -> V_62 ) {
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
V_64 -> V_62 = 0 ;
}
F_102 ( V_59 ) ;
}
}
void F_138 ( void * V_114 )
{
F_135 ( F_139 () ) ;
}
void F_140 ( void )
{
int V_110 ;
struct V_111 * V_64 ;
struct V_11 * V_11 ;
static T_3 V_115 ;
F_141 (cpu) {
bool V_116 = false ;
F_136 (zone) {
V_64 = F_137 ( V_11 -> V_113 , V_110 ) ;
if ( V_64 -> V_64 . V_62 ) {
V_116 = true ;
break;
}
}
if ( V_116 )
F_142 ( V_110 , & V_115 ) ;
else
F_143 ( V_110 , & V_115 ) ;
}
F_144 ( & V_115 , F_138 , NULL , 1 ) ;
}
void F_145 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_117 ;
unsigned long V_59 ;
int V_30 , V_118 ;
struct V_70 * V_119 ;
if ( ! V_11 -> V_18 )
return;
F_146 ( & V_11 -> V_67 , V_59 ) ;
V_117 = F_147 ( V_11 ) ;
for ( V_14 = V_11 -> V_17 ; V_14 < V_117 ; V_14 ++ )
if ( F_148 ( V_14 ) ) {
struct V_5 * V_5 = F_125 ( V_14 ) ;
if ( ! F_149 ( V_5 ) )
F_150 ( V_5 ) ;
}
F_151 (order, t) {
F_152 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_31 ;
V_14 = F_10 ( F_78 ( V_119 , struct V_5 , V_51 ) ) ;
for ( V_31 = 0 ; V_31 < ( 1UL << V_30 ) ; V_31 ++ )
F_153 ( F_125 ( V_14 + V_31 ) ) ;
}
}
F_154 ( & V_11 -> V_67 , V_59 ) ;
}
void F_155 ( struct V_5 * V_5 , int V_106 )
{
struct V_11 * V_11 = F_17 ( V_5 ) ;
struct V_63 * V_64 ;
unsigned long V_59 ;
int V_6 ;
if ( ! F_88 ( V_5 , 0 ) )
return;
V_6 = F_100 ( V_5 ) ;
F_101 ( V_5 , V_6 ) ;
F_98 ( V_59 ) ;
F_156 ( V_79 ) ;
if ( V_6 >= V_72 ) {
if ( F_7 ( F_87 ( V_6 ) ) ) {
F_86 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_23;
}
V_6 = V_120 ;
}
V_64 = & F_157 ( V_11 -> V_113 ) -> V_64 ;
if ( V_106 )
F_68 ( & V_5 -> V_51 , & V_64 -> V_73 [ V_6 ] ) ;
else
F_69 ( & V_5 -> V_51 , & V_64 -> V_73 [ V_6 ] ) ;
V_64 -> V_62 ++ ;
if ( V_64 -> V_62 >= V_64 -> V_86 ) {
unsigned long V_109 = F_134 ( V_64 -> V_109 ) ;
F_75 ( V_11 , V_109 , V_64 ) ;
V_64 -> V_62 -= V_109 ;
}
V_23:
F_102 ( V_59 ) ;
}
void F_158 ( struct V_70 * V_71 , int V_106 )
{
struct V_5 * V_5 , * V_92 ;
F_159 (page, next, list, lru) {
F_160 ( V_5 , V_106 ) ;
F_155 ( V_5 , V_106 ) ;
}
}
void F_161 ( struct V_5 * V_5 , unsigned int V_30 )
{
int V_31 ;
F_42 ( F_65 ( V_5 ) ) ;
F_42 ( ! F_61 ( V_5 ) ) ;
#ifdef F_162
if ( F_163 ( V_5 ) )
F_161 ( F_164 ( V_5 [ 0 ] . V_121 ) , V_30 ) ;
#endif
for ( V_31 = 1 ; V_31 < ( 1 << V_30 ) ; V_31 ++ )
F_106 ( V_5 + V_31 ) ;
}
static int F_165 ( struct V_5 * V_5 , unsigned int V_30 )
{
unsigned long V_122 ;
struct V_11 * V_11 ;
int V_74 ;
F_120 ( ! F_62 ( V_5 ) ) ;
V_11 = F_17 ( V_5 ) ;
V_74 = F_100 ( V_5 ) ;
if ( ! F_87 ( V_74 ) ) {
V_122 = F_166 ( V_11 ) + ( 1 << V_30 ) ;
if ( ! F_167 ( V_11 , 0 , V_122 , 0 , 0 ) )
return 0 ;
F_66 ( V_11 , - ( 1UL << V_30 ) , V_74 ) ;
}
F_67 ( & V_5 -> V_51 ) ;
V_11 -> V_52 [ V_30 ] . V_53 -- ;
F_54 ( V_5 ) ;
if ( V_30 >= V_84 - 1 ) {
struct V_5 * V_123 = V_5 + ( 1 << V_30 ) - 1 ;
for (; V_5 < V_123 ; V_5 += V_82 ) {
int V_74 = F_100 ( V_5 ) ;
if ( ! F_87 ( V_74 ) && ! F_84 ( V_74 ) )
F_6 ( V_5 ,
V_120 ) ;
}
}
return 1UL << V_30 ;
}
int F_168 ( struct V_5 * V_5 )
{
unsigned int V_30 ;
int V_32 ;
V_30 = F_60 ( V_5 ) ;
V_32 = F_165 ( V_5 , V_30 ) ;
if ( ! V_32 )
return 0 ;
F_106 ( V_5 ) ;
F_161 ( V_5 , V_30 ) ;
return V_32 ;
}
static inline
struct V_5 * F_169 ( struct V_11 * V_124 ,
struct V_11 * V_11 , int V_30 , T_1 V_36 ,
int V_6 )
{
unsigned long V_59 ;
struct V_5 * V_5 ;
int V_106 = ! ! ( V_36 & V_125 ) ;
V_126:
if ( F_81 ( V_30 == 0 ) ) {
struct V_63 * V_64 ;
struct V_70 * V_71 ;
F_98 ( V_59 ) ;
V_64 = & F_157 ( V_11 -> V_113 ) -> V_64 ;
V_71 = & V_64 -> V_73 [ V_6 ] ;
if ( F_77 ( V_71 ) ) {
V_64 -> V_62 += F_131 ( V_11 , 0 ,
V_64 -> V_109 , V_71 ,
V_6 , V_106 ) ;
if ( F_7 ( F_77 ( V_71 ) ) )
goto V_127;
}
if ( V_106 )
V_5 = F_78 ( V_71 -> V_75 , struct V_5 , V_51 ) ;
else
V_5 = F_78 ( V_71 -> V_92 , struct V_5 , V_51 ) ;
F_67 ( & V_5 -> V_51 ) ;
V_64 -> V_62 -- ;
} else {
if ( F_7 ( V_36 & V_128 ) ) {
F_170 ( V_30 > 1 ) ;
}
F_146 ( & V_11 -> V_67 , V_59 ) ;
V_5 = F_129 ( V_11 , V_30 , V_6 ) ;
F_85 ( & V_11 -> V_67 ) ;
if ( ! V_5 )
goto V_127;
F_66 ( V_11 , - ( 1 << V_30 ) ,
F_100 ( V_5 ) ) ;
}
F_171 ( V_129 , V_11 , 1 << V_30 ) ;
F_172 ( V_124 , V_11 , V_36 ) ;
F_102 ( V_59 ) ;
F_42 ( F_18 ( V_11 , V_5 ) ) ;
if ( F_115 ( V_5 , V_30 , V_36 ) )
goto V_126;
return V_5 ;
V_127:
F_102 ( V_59 ) ;
return NULL ;
}
static int T_2 F_173 ( char * V_130 )
{
return F_174 ( & V_131 . V_132 , V_130 ) ;
}
static bool F_175 ( T_1 V_133 , unsigned int V_30 )
{
if ( V_30 < V_131 . V_134 )
return false ;
if ( V_133 & V_128 )
return false ;
if ( V_131 . V_135 && ( V_133 & V_37 ) )
return false ;
if ( V_131 . V_136 && ( V_133 & V_137 ) )
return false ;
return F_176 ( & V_131 . V_132 , 1 << V_30 ) ;
}
static int T_2 F_177 ( void )
{
T_4 V_138 = V_139 | V_140 | V_141 ;
struct V_142 * V_143 ;
V_143 = F_178 ( L_6 , NULL ,
& V_131 . V_132 ) ;
if ( F_179 ( V_143 ) )
return F_180 ( V_143 ) ;
if ( ! F_181 ( L_7 , V_138 , V_143 ,
& V_131 . V_136 ) )
goto V_144;
if ( ! F_181 ( L_8 , V_138 , V_143 ,
& V_131 . V_135 ) )
goto V_144;
if ( ! F_182 ( L_9 , V_138 , V_143 ,
& V_131 . V_134 ) )
goto V_144;
return 0 ;
V_144:
F_183 ( V_143 ) ;
return - V_145 ;
}
static inline bool F_175 ( T_1 V_133 , unsigned int V_30 )
{
return false ;
}
static bool F_184 ( struct V_11 * V_146 , int V_30 , unsigned long V_147 ,
int V_148 , int V_149 , long V_150 )
{
long V_151 = V_147 ;
long V_152 = V_146 -> V_152 [ V_148 ] ;
int V_153 ;
long V_154 = 0 ;
V_150 -= ( 1 << V_30 ) - 1 ;
if ( V_149 & V_155 )
V_151 -= V_151 / 2 ;
if ( V_149 & V_156 )
V_151 -= V_151 / 4 ;
#ifdef V_107
if ( ! ( V_149 & V_157 ) )
V_154 = F_185 ( V_146 , V_77 ) ;
#endif
if ( V_150 - V_154 <= V_151 + V_152 )
return false ;
for ( V_153 = 0 ; V_153 < V_30 ; V_153 ++ ) {
V_150 -= V_146 -> V_52 [ V_153 ] . V_53 << V_153 ;
V_151 >>= 1 ;
if ( V_150 <= V_151 )
return false ;
}
return true ;
}
bool F_167 ( struct V_11 * V_146 , int V_30 , unsigned long V_147 ,
int V_148 , int V_149 )
{
return F_184 ( V_146 , V_30 , V_147 , V_148 , V_149 ,
F_185 ( V_146 , V_76 ) ) ;
}
bool F_186 ( struct V_11 * V_146 , int V_30 , unsigned long V_147 ,
int V_148 , int V_149 )
{
long V_150 = F_185 ( V_146 , V_76 ) ;
if ( V_146 -> V_158 && V_150 < V_146 -> V_158 )
V_150 = F_187 ( V_146 , V_76 ) ;
return F_184 ( V_146 , V_30 , V_147 , V_148 , V_149 ,
V_150 ) ;
}
static T_5 * F_188 ( struct V_159 * V_159 , int V_149 )
{
struct V_160 * V_161 ;
T_5 * V_162 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return NULL ;
if ( F_189 ( V_22 , V_161 -> V_164 + V_25 ) ) {
F_190 ( V_161 -> V_165 , V_166 ) ;
V_161 -> V_164 = V_22 ;
}
V_162 = ! F_43 () && ( V_149 & V_167 ) ?
& V_168 :
& V_169 [ V_170 ] ;
return V_162 ;
}
static int F_191 ( struct V_159 * V_159 , struct V_171 * V_146 ,
T_5 * V_162 )
{
struct V_160 * V_161 ;
int V_31 ;
int V_172 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return 1 ;
V_31 = V_146 - V_159 -> V_173 ;
V_172 = V_161 -> V_174 [ V_31 ] ;
return F_192 ( V_172 , * V_162 ) && ! F_193 ( V_31 , V_161 -> V_165 ) ;
}
static void F_194 ( struct V_159 * V_159 , struct V_171 * V_146 )
{
struct V_160 * V_161 ;
int V_31 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return;
V_31 = V_146 - V_159 -> V_173 ;
F_195 ( V_31 , V_161 -> V_165 ) ;
}
static void F_196 ( struct V_159 * V_159 )
{
struct V_160 * V_161 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return;
F_190 ( V_161 -> V_165 , V_166 ) ;
}
static bool F_197 ( struct V_11 * V_175 , struct V_11 * V_11 )
{
return F_192 ( V_175 -> V_176 , V_11 -> V_177 -> V_178 ) ;
}
static void T_6 F_198 ( int V_179 )
{
int V_31 ;
F_199 (i)
if ( F_200 ( V_179 , V_31 ) <= V_180 )
F_201 ( V_31 , F_202 ( V_179 ) -> V_178 ) ;
else
V_181 = 1 ;
}
static T_5 * F_188 ( struct V_159 * V_159 , int V_149 )
{
return NULL ;
}
static int F_191 ( struct V_159 * V_159 , struct V_171 * V_146 ,
T_5 * V_162 )
{
return 1 ;
}
static void F_194 ( struct V_159 * V_159 , struct V_171 * V_146 )
{
}
static void F_196 ( struct V_159 * V_159 )
{
}
static bool F_197 ( struct V_11 * V_175 , struct V_11 * V_11 )
{
return true ;
}
static inline void F_198 ( int V_179 )
{
}
static struct V_5 *
F_203 ( T_1 V_133 , T_5 * V_182 , unsigned int V_30 ,
struct V_159 * V_159 , int V_183 , int V_149 ,
struct V_11 * V_124 , int V_6 )
{
struct V_171 * V_146 ;
struct V_5 * V_5 = NULL ;
int V_148 ;
struct V_11 * V_11 ;
T_5 * V_162 = NULL ;
int V_184 = 0 ;
int V_185 = 0 ;
V_148 = F_204 ( V_124 ) ;
V_186:
F_205 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( F_132 ( V_187 ) && V_184 &&
! F_191 ( V_159 , V_146 , V_162 ) )
continue;
if ( ( V_149 & V_167 ) &&
! F_206 ( V_11 , V_133 ) )
continue;
if ( ( V_149 & V_188 ) &&
( V_133 & V_189 ) && ! F_207 ( V_11 ) )
goto V_190;
F_208 ( V_191 < V_192 ) ;
if ( ! ( V_149 & V_191 ) ) {
unsigned long V_147 ;
int V_12 ;
V_147 = V_11 -> V_122 [ V_149 & V_193 ] ;
if ( F_167 ( V_11 , V_30 , V_147 ,
V_148 , V_149 ) )
goto V_194;
if ( F_132 ( V_187 ) &&
! V_185 && V_195 > 1 ) {
V_162 = F_188 ( V_159 , V_149 ) ;
V_184 = 1 ;
V_185 = 1 ;
}
if ( V_181 == 0 ||
! F_197 ( V_124 , V_11 ) )
goto V_190;
if ( F_132 ( V_187 ) && V_184 &&
! F_191 ( V_159 , V_146 , V_162 ) )
continue;
V_12 = F_209 ( V_11 , V_133 , V_30 ) ;
switch ( V_12 ) {
case V_196 :
continue;
case V_197 :
continue;
default:
if ( F_167 ( V_11 , V_30 , V_147 ,
V_148 , V_149 ) )
goto V_194;
if ( ( ( V_149 & V_193 ) == V_198 ) ||
V_12 == V_199 )
goto V_190;
continue;
}
}
V_194:
V_5 = F_169 ( V_124 , V_11 , V_30 ,
V_133 , V_6 ) ;
if ( V_5 )
break;
V_190:
if ( F_132 ( V_187 ) )
F_194 ( V_159 , V_146 ) ;
}
if ( F_7 ( F_132 ( V_187 ) && V_5 == NULL && V_184 ) ) {
V_184 = 0 ;
goto V_186;
}
if ( V_5 )
V_5 -> V_200 = ! ! ( V_149 & V_191 ) ;
return V_5 ;
}
static inline bool F_210 ( void )
{
bool V_12 = false ;
#if V_201 > 8
V_12 = F_43 () ;
#endif
return V_12 ;
}
void F_211 ( T_1 V_133 , int V_30 , const char * V_202 , ... )
{
unsigned int V_203 = V_204 ;
if ( ( V_133 & V_205 ) || ! F_212 ( & V_206 ) ||
F_112 () > 0 )
return;
if ( ! ( V_133 & V_137 ) )
V_203 |= V_207 ;
if ( ! ( V_133 & V_208 ) )
if ( F_213 ( V_209 ) ||
( V_26 -> V_59 & ( V_210 | V_211 ) ) )
V_203 &= ~ V_204 ;
if ( F_43 () || ! ( V_133 & V_137 ) )
V_203 &= ~ V_204 ;
if ( V_202 ) {
struct V_212 V_213 ;
T_7 args ;
va_start ( args , V_202 ) ;
V_213 . V_202 = V_202 ;
V_213 . V_214 = & args ;
F_214 ( L_10 , & V_213 ) ;
va_end ( args ) ;
}
F_214 ( L_11 ,
V_26 -> V_27 , V_30 , V_133 ) ;
F_26 () ;
if ( ! F_210 () )
F_215 ( V_203 ) ;
}
static inline int
F_216 ( T_1 V_133 , unsigned int V_30 ,
unsigned long V_215 ,
unsigned long V_216 )
{
if ( V_133 & V_217 )
return 0 ;
if ( V_133 & V_128 )
return 1 ;
if ( ! V_215 && F_5 () )
return 0 ;
if ( V_30 <= V_218 )
return 1 ;
if ( V_133 & V_219 && V_216 < ( 1 << V_30 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_217 ( T_1 V_133 , unsigned int V_30 ,
struct V_159 * V_159 , enum V_220 V_183 ,
T_5 * V_182 , struct V_11 * V_124 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_218 ( V_159 , V_133 ) ) {
F_219 ( 1 ) ;
return NULL ;
}
V_5 = F_203 ( V_133 | V_221 , V_182 ,
V_30 , V_159 , V_183 ,
V_222 | V_167 ,
V_124 , V_6 ) ;
if ( V_5 )
goto V_23;
if ( ! ( V_133 & V_128 ) ) {
if ( V_30 > V_218 )
goto V_23;
if ( V_183 < V_223 )
goto V_23;
if ( V_133 & V_224 )
goto V_23;
}
F_220 ( V_159 , V_133 , V_30 , V_182 , false ) ;
V_23:
F_221 ( V_159 , V_133 ) ;
return V_5 ;
}
static struct V_5 *
F_222 ( T_1 V_133 , unsigned int V_30 ,
struct V_159 * V_159 , enum V_220 V_183 ,
T_5 * V_182 , int V_149 , struct V_11 * V_124 ,
int V_6 , bool V_225 ,
bool * V_226 , bool * V_227 ,
unsigned long * V_215 )
{
if ( ! V_30 )
return NULL ;
if ( F_223 ( V_124 , V_30 ) ) {
* V_227 = true ;
return NULL ;
}
V_26 -> V_59 |= V_210 ;
* V_215 = F_224 ( V_159 , V_30 , V_133 ,
V_182 , V_225 ,
V_226 ) ;
V_26 -> V_59 &= ~ V_210 ;
if ( * V_215 != V_228 ) {
struct V_5 * V_5 ;
F_135 ( F_225 () ) ;
F_226 () ;
V_5 = F_203 ( V_133 , V_182 ,
V_30 , V_159 , V_183 ,
V_149 & ~ V_191 ,
V_124 , V_6 ) ;
if ( V_5 ) {
V_124 -> V_229 = false ;
V_124 -> V_230 = 0 ;
V_124 -> V_231 = 0 ;
if ( V_30 >= V_124 -> V_232 )
V_124 -> V_232 = V_30 + 1 ;
F_227 ( V_233 ) ;
return V_5 ;
}
F_227 ( V_234 ) ;
if ( V_225 )
F_228 ( V_124 , V_30 ) ;
F_229 () ;
}
return NULL ;
}
static inline struct V_5 *
F_222 ( T_1 V_133 , unsigned int V_30 ,
struct V_159 * V_159 , enum V_220 V_183 ,
T_5 * V_182 , int V_149 , struct V_11 * V_124 ,
int V_6 , bool V_225 ,
bool * V_226 , bool * V_227 ,
unsigned long * V_215 )
{
return NULL ;
}
static int
F_230 ( T_1 V_133 , unsigned int V_30 , struct V_159 * V_159 ,
T_5 * V_182 )
{
struct V_235 V_235 ;
int V_236 ;
F_229 () ;
F_231 () ;
V_26 -> V_59 |= V_210 ;
F_232 ( V_133 ) ;
V_235 . V_237 = 0 ;
V_26 -> V_235 = & V_235 ;
V_236 = F_233 ( V_159 , V_30 , V_133 , V_182 ) ;
V_26 -> V_235 = NULL ;
F_234 () ;
V_26 -> V_59 &= ~ V_210 ;
F_229 () ;
return V_236 ;
}
static inline struct V_5 *
F_235 ( T_1 V_133 , unsigned int V_30 ,
struct V_159 * V_159 , enum V_220 V_183 ,
T_5 * V_182 , int V_149 , struct V_11 * V_124 ,
int V_6 , unsigned long * V_215 )
{
struct V_5 * V_5 = NULL ;
bool V_238 = false ;
* V_215 = F_230 ( V_133 , V_30 , V_159 ,
V_182 ) ;
if ( F_7 ( ! ( * V_215 ) ) )
return NULL ;
if ( F_132 ( V_187 ) )
F_196 ( V_159 ) ;
V_239:
V_5 = F_203 ( V_133 , V_182 , V_30 ,
V_159 , V_183 ,
V_149 & ~ V_191 ,
V_124 , V_6 ) ;
if ( ! V_5 && ! V_238 ) {
F_140 () ;
V_238 = true ;
goto V_239;
}
return V_5 ;
}
static inline struct V_5 *
F_236 ( T_1 V_133 , unsigned int V_30 ,
struct V_159 * V_159 , enum V_220 V_183 ,
T_5 * V_182 , struct V_11 * V_124 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_203 ( V_133 , V_182 , V_30 ,
V_159 , V_183 , V_191 ,
V_124 , V_6 ) ;
if ( ! V_5 && V_133 & V_128 )
F_237 ( V_124 , V_240 , V_25 / 50 ) ;
} while ( ! V_5 && ( V_133 & V_128 ) );
return V_5 ;
}
static inline
void F_238 ( unsigned int V_30 , struct V_159 * V_159 ,
enum V_220 V_183 ,
enum V_220 V_148 )
{
struct V_171 * V_146 ;
struct V_11 * V_11 ;
F_239 (zone, z, zonelist, high_zoneidx)
F_240 ( V_11 , V_30 , V_148 ) ;
}
static inline int
F_241 ( T_1 V_133 )
{
int V_149 = V_198 | V_167 ;
const T_1 V_241 = V_133 & V_137 ;
F_208 ( V_242 != ( V_243 T_1 ) V_155 ) ;
V_149 |= ( V_243 int ) ( V_133 & V_242 ) ;
if ( ! V_241 ) {
if ( ! ( V_133 & V_208 ) )
V_149 |= V_156 ;
V_149 &= ~ V_167 ;
} else if ( F_7 ( F_242 ( V_26 ) ) && ! F_43 () )
V_149 |= V_156 ;
if ( F_81 ( ! ( V_133 & V_208 ) ) ) {
if ( V_133 & V_244 )
V_149 |= V_191 ;
else if ( F_243 () && ( V_26 -> V_59 & V_210 ) )
V_149 |= V_191 ;
else if ( ! F_43 () &&
( ( V_26 -> V_59 & V_210 ) ||
F_7 ( F_213 ( V_209 ) ) ) )
V_149 |= V_191 ;
}
#ifdef V_107
if ( F_244 ( V_133 ) == V_120 )
V_149 |= V_157 ;
#endif
return V_149 ;
}
bool F_245 ( T_1 V_133 )
{
return ! ! ( F_241 ( V_133 ) & V_191 ) ;
}
static inline struct V_5 *
F_246 ( T_1 V_133 , unsigned int V_30 ,
struct V_159 * V_159 , enum V_220 V_183 ,
T_5 * V_182 , struct V_11 * V_124 ,
int V_6 )
{
const T_1 V_241 = V_133 & V_137 ;
struct V_5 * V_5 = NULL ;
int V_149 ;
unsigned long V_216 = 0 ;
unsigned long V_215 ;
bool V_225 = false ;
bool V_227 = false ;
bool V_226 = false ;
if ( V_30 >= V_40 ) {
F_170 ( ! ( V_133 & V_205 ) ) ;
return NULL ;
}
if ( F_132 ( V_187 ) &&
( V_133 & V_245 ) == V_245 )
goto V_246;
V_247:
if ( ! ( V_133 & V_248 ) )
F_238 ( V_30 , V_159 , V_183 ,
F_204 ( V_124 ) ) ;
V_149 = F_241 ( V_133 ) ;
if ( ! ( V_149 & V_167 ) && ! V_182 )
F_247 ( V_159 , V_183 , NULL ,
& V_124 ) ;
V_249:
V_5 = F_203 ( V_133 , V_182 , V_30 , V_159 ,
V_183 , V_149 & ~ V_191 ,
V_124 , V_6 ) ;
if ( V_5 )
goto V_250;
if ( V_149 & V_191 ) {
V_159 = F_248 ( F_249 () , V_133 ) ;
V_5 = F_236 ( V_133 , V_30 ,
V_159 , V_183 , V_182 ,
V_124 , V_6 ) ;
if ( V_5 ) {
goto V_250;
}
}
if ( ! V_241 )
goto V_246;
if ( V_26 -> V_59 & V_210 )
goto V_246;
if ( F_213 ( V_209 ) && ! ( V_133 & V_128 ) )
goto V_246;
V_5 = F_222 ( V_133 , V_30 ,
V_159 , V_183 ,
V_182 ,
V_149 , V_124 ,
V_6 , V_225 ,
& V_226 ,
& V_227 ,
& V_215 ) ;
if ( V_5 )
goto V_250;
V_225 = true ;
if ( ( V_227 || V_226 ) &&
( V_133 & V_248 ) )
goto V_246;
V_5 = F_235 ( V_133 , V_30 ,
V_159 , V_183 ,
V_182 ,
V_149 , V_124 ,
V_6 , & V_215 ) ;
if ( V_5 )
goto V_250;
if ( ! V_215 ) {
if ( ( V_133 & V_251 ) && ! ( V_133 & V_217 ) ) {
if ( V_252 )
goto V_246;
if ( ( V_26 -> V_59 & V_253 ) &&
! ( V_133 & V_128 ) )
goto V_246;
V_5 = F_217 ( V_133 , V_30 ,
V_159 , V_183 ,
V_182 , V_124 ,
V_6 ) ;
if ( V_5 )
goto V_250;
if ( ! ( V_133 & V_128 ) ) {
if ( V_30 > V_218 )
goto V_246;
if ( V_183 < V_223 )
goto V_246;
}
goto V_247;
}
}
V_216 += V_215 ;
if ( F_216 ( V_133 , V_30 , V_215 ,
V_216 ) ) {
F_237 ( V_124 , V_240 , V_25 / 50 ) ;
goto V_249;
} else {
V_5 = F_222 ( V_133 , V_30 ,
V_159 , V_183 ,
V_182 ,
V_149 , V_124 ,
V_6 , V_225 ,
& V_226 ,
& V_227 ,
& V_215 ) ;
if ( V_5 )
goto V_250;
}
V_246:
F_211 ( V_133 , V_30 , NULL ) ;
return V_5 ;
V_250:
if ( V_254 )
F_250 ( V_5 , V_30 , V_133 ) ;
return V_5 ;
}
struct V_5 *
F_251 ( T_1 V_133 , unsigned int V_30 ,
struct V_159 * V_159 , T_5 * V_182 )
{
enum V_220 V_183 = F_252 ( V_133 ) ;
struct V_11 * V_124 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_244 ( V_133 ) ;
unsigned int V_255 ;
int V_149 = V_188 | V_167 ;
struct V_256 * V_257 = NULL ;
V_133 &= V_3 ;
F_253 ( V_133 ) ;
F_254 ( V_133 & V_137 ) ;
if ( F_175 ( V_133 , V_30 ) )
return NULL ;
if ( F_7 ( ! V_159 -> V_173 -> V_11 ) )
return NULL ;
if ( ! F_255 ( V_133 , & V_257 , V_30 ) )
return NULL ;
V_258:
V_255 = F_256 () ;
F_247 ( V_159 , V_183 ,
V_182 ? : & V_168 ,
& V_124 ) ;
if ( ! V_124 )
goto V_23;
#ifdef V_107
if ( F_244 ( V_133 ) == V_120 )
V_149 |= V_157 ;
#endif
V_5 = F_203 ( V_133 | V_221 , V_182 , V_30 ,
V_159 , V_183 , V_149 ,
V_124 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
V_133 = F_257 ( V_133 ) ;
V_5 = F_246 ( V_133 , V_30 ,
V_159 , V_183 , V_182 ,
V_124 , V_6 ) ;
}
F_258 ( V_5 , V_30 , V_133 , V_6 ) ;
V_23:
if ( F_7 ( ! F_259 ( V_255 ) && ! V_5 ) )
goto V_258;
F_260 ( V_5 , V_257 , V_30 ) ;
return V_5 ;
}
unsigned long F_261 ( T_1 V_133 , unsigned int V_30 )
{
struct V_5 * V_5 ;
F_42 ( ( V_133 & V_37 ) != 0 ) ;
V_5 = F_262 ( V_133 , V_30 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_94 ( V_5 ) ;
}
unsigned long F_263 ( T_1 V_133 )
{
return F_261 ( V_133 | V_89 , 0 ) ;
}
void F_107 ( struct V_5 * V_5 , unsigned int V_30 )
{
if ( F_264 ( V_5 ) ) {
if ( V_30 == 0 )
F_155 ( V_5 , 0 ) ;
else
F_29 ( V_5 , V_30 ) ;
}
}
void V_150 ( unsigned long V_259 , unsigned int V_30 )
{
if ( V_259 != 0 ) {
F_42 ( ! F_265 ( ( void * ) V_259 ) ) ;
F_107 ( F_164 ( ( void * ) V_259 ) , V_30 ) ;
}
}
void F_266 ( struct V_5 * V_5 , unsigned int V_30 )
{
F_267 ( V_5 , V_30 ) ;
F_107 ( V_5 , V_30 ) ;
}
void F_268 ( unsigned long V_259 , unsigned int V_30 )
{
if ( V_259 != 0 ) {
F_42 ( ! F_265 ( ( void * ) V_259 ) ) ;
F_266 ( F_164 ( ( void * ) V_259 ) , V_30 ) ;
}
}
static void * F_269 ( unsigned long V_259 , unsigned V_30 , T_8 V_88 )
{
if ( V_259 ) {
unsigned long V_260 = V_259 + ( V_78 << V_30 ) ;
unsigned long V_261 = V_259 + F_270 ( V_88 ) ;
F_161 ( F_164 ( ( void * ) V_259 ) , V_30 ) ;
while ( V_261 < V_260 ) {
F_271 ( V_261 ) ;
V_261 += V_78 ;
}
}
return ( void * ) V_259 ;
}
void * F_272 ( T_8 V_88 , T_1 V_133 )
{
unsigned int V_30 = F_273 ( V_88 ) ;
unsigned long V_259 ;
V_259 = F_261 ( V_133 , V_30 ) ;
return F_269 ( V_259 , V_30 , V_88 ) ;
}
void * F_274 ( int V_179 , T_8 V_88 , T_1 V_133 )
{
unsigned V_30 = F_273 ( V_88 ) ;
struct V_5 * V_33 = F_275 ( V_179 , V_133 , V_30 ) ;
if ( ! V_33 )
return NULL ;
return F_269 ( ( unsigned long ) F_94 ( V_33 ) , V_30 , V_88 ) ;
}
void F_276 ( void * V_262 , T_8 V_88 )
{
unsigned long V_259 = ( unsigned long ) V_262 ;
unsigned long V_263 = V_259 + F_270 ( V_88 ) ;
while ( V_259 < V_263 ) {
F_271 ( V_259 ) ;
V_259 += V_78 ;
}
}
static unsigned long F_277 ( int V_264 )
{
struct V_171 * V_146 ;
struct V_11 * V_11 ;
unsigned long V_265 = 0 ;
struct V_159 * V_159 = F_248 ( F_249 () , V_266 ) ;
F_239 (zone, z, zonelist, offset) {
unsigned long V_88 = V_11 -> V_81 ;
unsigned long V_86 = F_278 ( V_11 ) ;
if ( V_88 > V_86 )
V_265 += V_88 - V_86 ;
}
return V_265 ;
}
unsigned long F_279 ( void )
{
return F_277 ( F_252 ( V_267 ) ) ;
}
unsigned long F_280 ( void )
{
return F_277 ( F_252 ( V_268 ) ) ;
}
static inline void F_281 ( struct V_11 * V_11 )
{
if ( F_132 ( V_187 ) )
F_23 ( L_12 , F_122 ( V_11 ) ) ;
}
void F_282 ( struct V_269 * V_270 )
{
V_270 -> V_271 = V_272 ;
V_270 -> V_273 = 0 ;
V_270 -> V_274 = F_283 ( V_76 ) ;
V_270 -> V_275 = F_284 () ;
V_270 -> V_276 = V_277 ;
V_270 -> V_278 = F_285 () ;
V_270 -> V_279 = V_78 ;
}
void F_286 ( struct V_269 * V_270 , int V_179 )
{
int V_220 ;
unsigned long V_81 = 0 ;
T_9 * V_280 = F_202 ( V_179 ) ;
for ( V_220 = 0 ; V_220 < V_281 ; V_220 ++ )
V_81 += V_280 -> V_282 [ V_220 ] . V_81 ;
V_270 -> V_271 = V_81 ;
V_270 -> V_274 = F_287 ( V_179 , V_76 ) ;
#ifdef F_288
V_270 -> V_276 = V_280 -> V_282 [ V_283 ] . V_81 ;
V_270 -> V_278 = F_185 ( & V_280 -> V_282 [ V_283 ] ,
V_76 ) ;
#else
V_270 -> V_276 = 0 ;
V_270 -> V_278 = 0 ;
#endif
V_270 -> V_279 = V_78 ;
}
bool F_289 ( unsigned int V_59 , int V_179 )
{
bool V_12 = false ;
unsigned int V_255 ;
if ( ! ( V_59 & V_204 ) )
goto V_23;
do {
V_255 = F_256 () ;
V_12 = ! F_192 ( V_179 , V_168 ) ;
} while ( ! F_259 ( V_255 ) );
V_23:
return V_12 ;
}
static void F_290 ( unsigned char type )
{
static const char V_284 [ V_285 ] = {
[ V_8 ] = 'U' ,
[ V_103 ] = 'E' ,
[ V_120 ] = 'M' ,
[ V_102 ] = 'R' ,
#ifdef V_107
[ V_83 ] = 'C' ,
#endif
#ifdef F_291
[ V_286 ] = 'I' ,
#endif
} ;
char V_287 [ V_285 + 1 ] ;
char * V_33 = V_287 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_285 ; V_31 ++ ) {
if ( type & ( 1 << V_31 ) )
* V_33 ++ = V_284 [ V_31 ] ;
}
* V_33 = '\0' ;
F_23 ( L_13 , V_287 ) ;
}
void F_292 ( unsigned int V_203 )
{
int V_110 ;
struct V_11 * V_11 ;
F_136 (zone) {
if ( F_289 ( V_203 , F_122 ( V_11 ) ) )
continue;
F_281 ( V_11 ) ;
F_23 ( L_14 , V_11 -> V_288 ) ;
F_141 (cpu) {
struct V_111 * V_113 ;
V_113 = F_137 ( V_11 -> V_113 , V_110 ) ;
F_23 ( L_15 ,
V_110 , V_113 -> V_64 . V_86 ,
V_113 -> V_64 . V_109 , V_113 -> V_64 . V_62 ) ;
}
}
F_23 ( L_16
L_17
L_18
L_19
L_20
L_21
L_22 ,
F_283 ( V_289 ) ,
F_283 ( V_290 ) ,
F_283 ( V_291 ) ,
F_283 ( V_292 ) ,
F_283 ( V_293 ) ,
F_283 ( V_294 ) ,
F_283 ( V_295 ) ,
F_283 ( V_296 ) ,
F_283 ( V_297 ) ,
F_283 ( V_298 ) ,
F_283 ( V_76 ) ,
F_283 ( V_299 ) ,
F_283 ( V_300 ) ,
F_283 ( V_301 ) ,
F_283 ( V_302 ) ,
F_283 ( V_303 ) ,
F_283 ( V_304 ) ,
F_283 ( V_77 ) ) ;
F_136 (zone) {
int V_31 ;
if ( F_289 ( V_203 , F_122 ( V_11 ) ) )
continue;
F_281 ( V_11 ) ;
F_23 ( L_23
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
L_51
L_52 ,
V_11 -> V_288 ,
F_293 ( F_185 ( V_11 , V_76 ) ) ,
F_293 ( F_294 ( V_11 ) ) ,
F_293 ( F_166 ( V_11 ) ) ,
F_293 ( F_278 ( V_11 ) ) ,
F_293 ( F_185 ( V_11 , V_289 ) ) ,
F_293 ( F_185 ( V_11 , V_290 ) ) ,
F_293 ( F_185 ( V_11 , V_292 ) ) ,
F_293 ( F_185 ( V_11 , V_293 ) ) ,
F_293 ( F_185 ( V_11 , V_295 ) ) ,
F_293 ( F_185 ( V_11 , V_291 ) ) ,
F_293 ( F_185 ( V_11 , V_294 ) ) ,
F_293 ( V_11 -> V_305 ) ,
F_293 ( V_11 -> V_81 ) ,
F_293 ( F_185 ( V_11 , V_306 ) ) ,
F_293 ( F_185 ( V_11 , V_296 ) ) ,
F_293 ( F_185 ( V_11 , V_297 ) ) ,
F_293 ( F_185 ( V_11 , V_301 ) ) ,
F_293 ( F_185 ( V_11 , V_302 ) ) ,
F_293 ( F_185 ( V_11 , V_299 ) ) ,
F_293 ( F_185 ( V_11 , V_300 ) ) ,
F_185 ( V_11 , V_307 ) *
V_308 / 1024 ,
F_293 ( F_185 ( V_11 , V_303 ) ) ,
F_293 ( F_185 ( V_11 , V_298 ) ) ,
F_293 ( F_185 ( V_11 , V_304 ) ) ,
F_293 ( F_185 ( V_11 , V_77 ) ) ,
F_293 ( F_185 ( V_11 , V_309 ) ) ,
V_11 -> V_69 ,
( V_11 -> V_68 ? L_53 : L_54 )
) ;
F_23 ( L_55 ) ;
for ( V_31 = 0 ; V_31 < V_281 ; V_31 ++ )
F_23 ( L_56 , V_11 -> V_152 [ V_31 ] ) ;
F_23 ( L_52 ) ;
}
F_136 (zone) {
unsigned long V_310 [ V_40 ] , V_59 , V_30 , V_311 = 0 ;
unsigned char V_284 [ V_40 ] ;
if ( F_289 ( V_203 , F_122 ( V_11 ) ) )
continue;
F_281 ( V_11 ) ;
F_23 ( L_57 , V_11 -> V_288 ) ;
F_146 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
struct V_52 * V_87 = & V_11 -> V_52 [ V_30 ] ;
int type ;
V_310 [ V_30 ] = V_87 -> V_53 ;
V_311 += V_310 [ V_30 ] << V_30 ;
V_284 [ V_30 ] = 0 ;
for ( type = 0 ; type < V_285 ; type ++ ) {
if ( ! F_77 ( & V_87 -> V_56 [ type ] ) )
V_284 [ V_30 ] |= 1 << type ;
}
}
F_154 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
F_23 ( L_58 , V_310 [ V_30 ] , F_293 ( 1UL ) << V_30 ) ;
if ( V_310 [ V_30 ] )
F_290 ( V_284 [ V_30 ] ) ;
}
F_23 ( L_59 , F_293 ( V_311 ) ) ;
}
F_295 () ;
F_23 ( L_60 , F_283 ( V_312 ) ) ;
F_296 () ;
}
static void F_297 ( struct V_11 * V_11 , struct V_171 * V_171 )
{
V_171 -> V_11 = V_11 ;
V_171 -> F_204 = F_204 ( V_11 ) ;
}
static int F_298 ( T_9 * V_280 , struct V_159 * V_159 ,
int V_313 )
{
struct V_11 * V_11 ;
enum V_220 V_220 = V_281 ;
do {
V_220 -- ;
V_11 = V_280 -> V_282 + V_220 ;
if ( F_299 ( V_11 ) ) {
F_297 ( V_11 ,
& V_159 -> V_173 [ V_313 ++ ] ) ;
F_300 ( V_220 ) ;
}
} while ( V_220 );
return V_313 ;
}
static int F_301 ( char * V_314 )
{
if ( * V_314 == 'd' || * V_314 == 'D' ) {
V_315 = V_316 ;
} else if ( * V_314 == 'n' || * V_314 == 'N' ) {
V_315 = V_317 ;
} else if ( * V_314 == 'z' || * V_314 == 'Z' ) {
V_315 = V_318 ;
} else {
F_23 ( V_319
L_61
L_62 , V_314 ) ;
return - V_320 ;
}
return 0 ;
}
static T_2 int F_302 ( char * V_314 )
{
int V_12 ;
if ( ! V_314 )
return 0 ;
V_12 = F_301 ( V_314 ) ;
if ( V_12 == 0 )
F_303 ( V_321 , V_314 , V_322 ) ;
return V_12 ;
}
int F_304 ( T_10 * V_323 , int V_324 ,
void T_11 * V_325 , T_8 * V_326 ,
T_12 * V_327 )
{
char V_328 [ V_322 ] ;
int V_12 ;
static F_305 ( V_329 ) ;
F_306 ( & V_329 ) ;
if ( V_324 ) {
if ( strlen ( ( char * ) V_323 -> V_330 ) >= V_322 ) {
V_12 = - V_320 ;
goto V_23;
}
strcpy ( V_328 , ( char * ) V_323 -> V_330 ) ;
}
V_12 = F_307 ( V_323 , V_324 , V_325 , V_326 , V_327 ) ;
if ( V_12 )
goto V_23;
if ( V_324 ) {
int V_331 = V_315 ;
V_12 = F_301 ( ( char * ) V_323 -> V_330 ) ;
if ( V_12 ) {
strncpy ( ( char * ) V_323 -> V_330 , V_328 ,
V_322 ) ;
V_315 = V_331 ;
} else if ( V_331 != V_315 ) {
F_306 ( & V_332 ) ;
F_308 ( NULL , NULL ) ;
F_309 ( & V_332 ) ;
}
}
V_23:
F_309 ( & V_329 ) ;
return V_12 ;
}
static int F_310 ( int V_176 , T_5 * V_333 )
{
int V_172 , V_270 ;
int V_334 = V_335 ;
int V_336 = V_337 ;
const struct V_338 * V_287 = F_311 ( 0 ) ;
if ( ! F_192 ( V_176 , * V_333 ) ) {
F_201 ( V_176 , * V_333 ) ;
return V_176 ;
}
F_312 (n, N_MEMORY) {
if ( F_192 ( V_172 , * V_333 ) )
continue;
V_270 = F_200 ( V_176 , V_172 ) ;
V_270 += ( V_172 < V_176 ) ;
V_287 = F_311 ( V_172 ) ;
if ( ! F_313 ( V_287 ) )
V_270 += V_339 ;
V_270 *= ( V_340 * V_341 ) ;
V_270 += V_342 [ V_172 ] ;
if ( V_270 < V_334 ) {
V_334 = V_270 ;
V_336 = V_172 ;
}
}
if ( V_336 >= 0 )
F_201 ( V_336 , * V_333 ) ;
return V_336 ;
}
static void F_314 ( T_9 * V_280 , int V_176 )
{
int V_343 ;
struct V_159 * V_159 ;
V_159 = & V_280 -> V_344 [ 0 ] ;
for ( V_343 = 0 ; V_159 -> V_173 [ V_343 ] . V_11 != NULL ; V_343 ++ )
;
V_343 = F_298 ( F_202 ( V_176 ) , V_159 , V_343 ) ;
V_159 -> V_173 [ V_343 ] . V_11 = NULL ;
V_159 -> V_173 [ V_343 ] . F_204 = 0 ;
}
static void F_315 ( T_9 * V_280 )
{
int V_343 ;
struct V_159 * V_159 ;
V_159 = & V_280 -> V_344 [ 1 ] ;
V_343 = F_298 ( V_280 , V_159 , 0 ) ;
V_159 -> V_173 [ V_343 ] . V_11 = NULL ;
V_159 -> V_173 [ V_343 ] . F_204 = 0 ;
}
static void F_316 ( T_9 * V_280 , int V_345 )
{
int V_346 , V_343 , V_176 ;
int V_220 ;
struct V_11 * V_146 ;
struct V_159 * V_159 ;
V_159 = & V_280 -> V_344 [ 0 ] ;
V_346 = 0 ;
for ( V_220 = V_281 - 1 ; V_220 >= 0 ; V_220 -- ) {
for ( V_343 = 0 ; V_343 < V_345 ; V_343 ++ ) {
V_176 = V_347 [ V_343 ] ;
V_146 = & F_202 ( V_176 ) -> V_282 [ V_220 ] ;
if ( F_299 ( V_146 ) ) {
F_297 ( V_146 ,
& V_159 -> V_173 [ V_346 ++ ] ) ;
F_300 ( V_220 ) ;
}
}
}
V_159 -> V_173 [ V_346 ] . V_11 = NULL ;
V_159 -> V_173 [ V_346 ] . F_204 = 0 ;
}
static int F_317 ( void )
{
int V_179 , V_220 ;
unsigned long V_348 , V_349 ;
struct V_11 * V_146 ;
int V_350 ;
V_348 = 0 ;
V_349 = 0 ;
F_199 (nid) {
for ( V_220 = 0 ; V_220 < V_281 ; V_220 ++ ) {
V_146 = & F_202 ( V_179 ) -> V_282 [ V_220 ] ;
if ( F_299 ( V_146 ) ) {
if ( V_220 < V_223 )
V_348 += V_146 -> V_81 ;
V_349 += V_146 -> V_81 ;
} else if ( V_220 == V_223 ) {
return V_317 ;
}
}
}
if ( ! V_348 ||
V_348 > V_349 / 2 )
return V_317 ;
V_350 = V_349 /
( F_318 ( V_169 [ V_170 ] ) + 1 ) ;
F_199 (nid) {
V_348 = 0 ;
V_349 = 0 ;
for ( V_220 = 0 ; V_220 < V_281 ; V_220 ++ ) {
V_146 = & F_202 ( V_179 ) -> V_282 [ V_220 ] ;
if ( F_299 ( V_146 ) ) {
if ( V_220 < V_223 )
V_348 += V_146 -> V_305 ;
V_349 += V_146 -> V_305 ;
}
}
if ( V_348 &&
V_349 > V_350 &&
V_348 > V_349 * 70 / 100 )
return V_317 ;
}
return V_318 ;
}
static void F_319 ( void )
{
if ( V_315 == V_316 )
V_351 = F_317 () ;
else
V_351 = V_315 ;
}
static void F_320 ( T_9 * V_280 )
{
int V_343 , V_176 , V_352 ;
enum V_220 V_31 ;
T_5 V_353 ;
int V_354 , V_355 ;
struct V_159 * V_159 ;
int V_30 = V_351 ;
for ( V_31 = 0 ; V_31 < V_356 ; V_31 ++ ) {
V_159 = V_280 -> V_344 + V_31 ;
V_159 -> V_173 [ 0 ] . V_11 = NULL ;
V_159 -> V_173 [ 0 ] . F_204 = 0 ;
}
V_354 = V_280 -> V_357 ;
V_352 = V_195 ;
V_355 = V_354 ;
F_321 ( V_353 ) ;
memset ( V_347 , 0 , sizeof( V_347 ) ) ;
V_343 = 0 ;
while ( ( V_176 = F_310 ( V_354 , & V_353 ) ) >= 0 ) {
if ( F_200 ( V_354 , V_176 ) !=
F_200 ( V_354 , V_355 ) )
V_342 [ V_176 ] = V_352 ;
V_355 = V_176 ;
V_352 -- ;
if ( V_30 == V_317 )
F_314 ( V_280 , V_176 ) ;
else
V_347 [ V_343 ++ ] = V_176 ;
}
if ( V_30 == V_318 ) {
F_316 ( V_280 , V_343 ) ;
}
F_315 ( V_280 ) ;
}
static void F_322 ( T_9 * V_280 )
{
struct V_159 * V_159 ;
struct V_160 * V_161 ;
struct V_171 * V_146 ;
V_159 = & V_280 -> V_344 [ 0 ] ;
V_159 -> V_163 = V_161 = & V_159 -> V_358 ;
F_190 ( V_161 -> V_165 , V_166 ) ;
for ( V_146 = V_159 -> V_173 ; V_146 -> V_11 ; V_146 ++ )
V_161 -> V_174 [ V_146 - V_159 -> V_173 ] = F_323 ( V_146 ) ;
}
int F_324 ( int V_176 )
{
struct V_11 * V_11 ;
( void ) F_247 ( F_248 ( V_176 , V_266 ) ,
F_252 ( V_266 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_176 ;
}
static void F_319 ( void )
{
V_351 = V_318 ;
}
static void F_320 ( T_9 * V_280 )
{
int V_176 , V_354 ;
enum V_220 V_343 ;
struct V_159 * V_159 ;
V_354 = V_280 -> V_357 ;
V_159 = & V_280 -> V_344 [ 0 ] ;
V_343 = F_298 ( V_280 , V_159 , 0 ) ;
for ( V_176 = V_354 + 1 ; V_176 < V_341 ; V_176 ++ ) {
if ( ! F_325 ( V_176 ) )
continue;
V_343 = F_298 ( F_202 ( V_176 ) , V_159 , V_343 ) ;
}
for ( V_176 = 0 ; V_176 < V_354 ; V_176 ++ ) {
if ( ! F_325 ( V_176 ) )
continue;
V_343 = F_298 ( F_202 ( V_176 ) , V_159 , V_343 ) ;
}
V_159 -> V_173 [ V_343 ] . V_11 = NULL ;
V_159 -> V_173 [ V_343 ] . F_204 = 0 ;
}
static void F_322 ( T_9 * V_280 )
{
V_280 -> V_344 [ 0 ] . V_163 = NULL ;
}
static int F_326 ( void * V_330 )
{
int V_179 ;
int V_110 ;
T_9 * V_359 = V_330 ;
#ifdef V_187
memset ( V_342 , 0 , sizeof( V_342 ) ) ;
#endif
if ( V_359 && ! F_325 ( V_359 -> V_357 ) ) {
F_320 ( V_359 ) ;
F_322 ( V_359 ) ;
}
F_199 (nid) {
T_9 * V_280 = F_202 ( V_179 ) ;
F_320 ( V_280 ) ;
F_322 ( V_280 ) ;
}
F_327 (cpu) {
F_328 ( & F_329 ( V_360 , V_110 ) , 0 ) ;
#ifdef F_330
if ( F_331 ( V_110 ) )
F_332 ( V_110 , F_324 ( F_333 ( V_110 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_308 ( T_9 * V_280 , struct V_11 * V_11 )
{
F_319 () ;
if ( V_361 == V_362 ) {
F_326 ( NULL ) ;
F_334 () ;
F_335 () ;
} else {
#ifdef F_336
if ( V_11 )
F_337 ( V_11 ) ;
#endif
F_338 ( F_326 , V_280 , NULL ) ;
}
V_363 = F_280 () ;
if ( V_363 < ( V_82 * V_285 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_23 ( L_63
L_64 ,
V_195 ,
V_364 [ V_351 ] ,
V_7 ? L_65 : L_66 ,
V_363 ) ;
#ifdef V_187
F_23 ( L_67 , V_365 [ V_366 ] ) ;
#endif
}
static inline unsigned long F_339 ( unsigned long V_104 )
{
unsigned long V_88 = 1 ;
V_104 /= V_367 ;
while ( V_88 < V_104 )
V_88 <<= 1 ;
V_88 = V_151 ( V_88 , 4096UL ) ;
return F_340 ( V_88 , 4UL ) ;
}
static inline unsigned long F_339 ( unsigned long V_104 )
{
return 4096UL ;
}
static inline unsigned long F_341 ( unsigned long V_88 )
{
return F_342 ( ~ V_88 ) ;
}
static int F_343 ( unsigned long V_16 , unsigned long V_96 )
{
unsigned long V_14 ;
for ( V_14 = V_16 ; V_14 < V_96 ; V_14 ++ ) {
if ( ! F_16 ( V_14 ) || F_344 ( F_125 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_345 ( struct V_11 * V_11 )
{
unsigned long V_16 , V_14 , V_96 , V_368 ;
struct V_5 * V_5 ;
unsigned long V_369 ;
int V_370 ;
V_16 = V_11 -> V_17 ;
V_96 = F_147 ( V_11 ) ;
V_16 = F_346 ( V_16 , V_82 ) ;
V_370 = F_346 ( F_294 ( V_11 ) , V_82 ) >>
V_84 ;
V_370 = V_151 ( 2 , V_370 ) ;
for ( V_14 = V_16 ; V_14 < V_96 ; V_14 += V_82 ) {
if ( ! F_148 ( V_14 ) )
continue;
V_5 = F_125 ( V_14 ) ;
if ( F_121 ( V_5 ) != F_122 ( V_11 ) )
continue;
V_369 = F_100 ( V_5 ) ;
if ( V_370 > 0 ) {
V_368 = V_151 ( V_14 + V_82 , V_96 ) ;
if ( F_343 ( V_14 , V_368 ) )
continue;
if ( V_369 == V_102 ) {
V_370 -- ;
continue;
}
if ( V_369 == V_120 ) {
F_6 ( V_5 ,
V_102 ) ;
F_124 ( V_11 , V_5 ,
V_102 ) ;
V_370 -- ;
continue;
}
}
if ( V_369 == V_102 ) {
F_6 ( V_5 , V_120 ) ;
F_124 ( V_11 , V_5 , V_120 ) ;
}
}
}
void T_14 F_347 ( unsigned long V_88 , int V_179 , unsigned long V_11 ,
unsigned long V_16 , enum V_371 V_372 )
{
struct V_5 * V_5 ;
unsigned long V_96 = V_16 + V_88 ;
unsigned long V_14 ;
struct V_11 * V_146 ;
if ( V_373 < V_96 - 1 )
V_373 = V_96 - 1 ;
V_146 = & F_202 ( V_179 ) -> V_282 [ V_11 ] ;
for ( V_14 = V_16 ; V_14 < V_96 ; V_14 ++ ) {
if ( V_372 == V_374 ) {
if ( ! F_348 ( V_14 ) )
continue;
if ( ! F_349 ( V_14 , V_179 ) )
continue;
}
V_5 = F_125 ( V_14 ) ;
F_350 ( V_5 , V_11 , V_179 , V_14 ) ;
F_351 ( V_5 , V_11 , V_179 , V_14 ) ;
F_352 ( V_5 ) ;
F_21 ( V_5 ) ;
F_74 ( V_5 ) ;
F_353 ( V_5 ) ;
if ( ( V_146 -> V_17 <= V_14 )
&& ( V_14 < F_147 ( V_146 ) )
&& ! ( V_14 & ( V_82 - 1 ) ) )
F_6 ( V_5 , V_120 ) ;
F_113 ( & V_5 -> V_51 ) ;
#ifdef F_354
if ( ! F_355 ( V_11 ) )
F_356 ( V_5 , F_357 ( V_14 << V_375 ) ) ;
#endif
}
}
static void T_14 F_358 ( struct V_11 * V_11 )
{
int V_30 , V_118 ;
F_151 (order, t) {
F_113 ( & V_11 -> V_52 [ V_30 ] . V_56 [ V_118 ] ) ;
V_11 -> V_52 [ V_30 ] . V_53 = 0 ;
}
}
static int T_14 F_359 ( struct V_11 * V_11 )
{
#ifdef F_360
int V_109 ;
V_109 = V_11 -> V_81 / 1024 ;
if ( V_109 * V_78 > 512 * 1024 )
V_109 = ( 512 * 1024 ) / V_78 ;
V_109 /= 4 ;
if ( V_109 < 1 )
V_109 = 1 ;
V_109 = F_361 ( V_109 + V_109 / 2 ) - 1 ;
return V_109 ;
#else
return 0 ;
#endif
}
static void F_362 ( struct V_63 * V_64 , unsigned long V_86 ,
unsigned long V_109 )
{
V_64 -> V_109 = 1 ;
F_363 () ;
V_64 -> V_86 = V_86 ;
F_363 () ;
V_64 -> V_109 = V_109 ;
}
static void F_364 ( struct V_111 * V_33 , unsigned long V_109 )
{
F_362 ( & V_33 -> V_64 , 6 * V_109 , F_340 ( 1UL , 1 * V_109 ) ) ;
}
static void F_365 ( struct V_111 * V_33 )
{
struct V_63 * V_64 ;
int V_6 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_64 = & V_33 -> V_64 ;
V_64 -> V_62 = 0 ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ )
F_113 ( & V_64 -> V_73 [ V_6 ] ) ;
}
static void F_328 ( struct V_111 * V_33 , unsigned long V_109 )
{
F_365 ( V_33 ) ;
F_364 ( V_33 , V_109 ) ;
}
static void F_366 ( struct V_111 * V_33 ,
unsigned long V_86 )
{
unsigned long V_109 = F_340 ( 1UL , V_86 / 4 ) ;
if ( ( V_86 / 4 ) > ( V_375 * 8 ) )
V_109 = V_375 * 8 ;
F_362 ( & V_33 -> V_64 , V_86 , V_109 ) ;
}
static void T_14 F_367 ( struct V_11 * V_11 ,
struct V_111 * V_64 )
{
if ( V_376 )
F_366 ( V_64 ,
( V_11 -> V_81 /
V_376 ) ) ;
else
F_364 ( V_64 , F_359 ( V_11 ) ) ;
}
static void T_14 F_368 ( struct V_11 * V_11 , int V_110 )
{
struct V_111 * V_64 = F_137 ( V_11 -> V_113 , V_110 ) ;
F_365 ( V_64 ) ;
F_367 ( V_11 , V_64 ) ;
}
static void T_14 F_337 ( struct V_11 * V_11 )
{
int V_110 ;
V_11 -> V_113 = F_369 ( struct V_111 ) ;
F_327 (cpu)
F_368 ( V_11 , V_110 ) ;
}
void T_2 F_370 ( void )
{
struct V_11 * V_11 ;
F_136 (zone)
F_337 ( V_11 ) ;
}
static T_15 T_16
int F_371 ( struct V_11 * V_11 , unsigned long V_377 )
{
int V_31 ;
struct V_378 * V_280 = V_11 -> V_177 ;
T_8 V_379 ;
V_11 -> F_339 =
F_339 ( V_377 ) ;
V_11 -> F_341 =
F_341 ( V_11 -> F_339 ) ;
V_379 = V_11 -> F_339
* sizeof( V_380 ) ;
if ( ! F_372 () ) {
V_11 -> V_381 = ( V_380 * )
F_373 ( V_280 , V_379 ) ;
} else {
V_11 -> V_381 = F_374 ( V_379 ) ;
}
if ( ! V_11 -> V_381 )
return - V_145 ;
for( V_31 = 0 ; V_31 < V_11 -> F_339 ; ++ V_31 )
F_375 ( V_11 -> V_381 + V_31 ) ;
return 0 ;
}
static T_14 void F_376 ( struct V_11 * V_11 )
{
V_11 -> V_113 = & V_360 ;
if ( V_11 -> V_305 )
F_23 ( V_382 L_68 ,
V_11 -> V_288 , V_11 -> V_305 ,
F_359 ( V_11 ) ) ;
}
int T_14 F_377 ( struct V_11 * V_11 ,
unsigned long V_17 ,
unsigned long V_88 ,
enum V_371 V_372 )
{
struct V_378 * V_280 = V_11 -> V_177 ;
int V_12 ;
V_12 = F_371 ( V_11 , V_88 ) ;
if ( V_12 )
return V_12 ;
V_280 -> V_313 = F_204 ( V_11 ) + 1 ;
V_11 -> V_17 = V_17 ;
F_378 ( V_383 , L_69 ,
L_70 ,
V_280 -> V_357 ,
( unsigned long ) F_204 ( V_11 ) ,
V_17 , ( V_17 + V_88 ) ) ;
F_358 ( V_11 ) ;
return 0 ;
}
int T_14 F_379 ( unsigned long V_14 )
{
unsigned long V_16 , V_96 ;
int V_31 , V_179 ;
static unsigned long T_17 V_384 , V_385 ;
static int T_17 V_386 ;
if ( V_384 <= V_14 && V_14 < V_385 )
return V_386 ;
F_380 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
if ( V_16 <= V_14 && V_14 < V_96 ) {
V_384 = V_16 ;
V_385 = V_96 ;
V_386 = V_179 ;
return V_179 ;
}
return - 1 ;
}
int T_14 F_381 ( unsigned long V_14 )
{
int V_179 ;
V_179 = F_379 ( V_14 ) ;
if ( V_179 >= 0 )
return V_179 ;
return 0 ;
}
bool T_14 F_349 ( unsigned long V_14 , int V_176 )
{
int V_179 ;
V_179 = F_379 ( V_14 ) ;
if ( V_179 >= 0 && V_179 != V_176 )
return false ;
return true ;
}
void T_2 F_382 ( int V_179 , unsigned long V_387 )
{
unsigned long V_16 , V_96 ;
int V_31 , V_388 ;
F_380 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_16 = V_151 ( V_16 , V_387 ) ;
V_96 = V_151 ( V_96 , V_387 ) ;
if ( V_16 < V_96 )
F_383 ( F_202 ( V_388 ) ,
F_384 ( V_16 ) ,
( V_96 - V_16 ) << V_375 ) ;
}
}
void T_2 F_385 ( int V_179 )
{
unsigned long V_16 , V_96 ;
int V_31 , V_388 ;
F_380 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_386 ( V_388 , V_16 , V_96 ) ;
}
void T_14 F_387 ( unsigned int V_179 ,
unsigned long * V_16 , unsigned long * V_96 )
{
unsigned long V_389 , V_390 ;
int V_31 ;
* V_16 = - 1UL ;
* V_96 = 0 ;
F_380 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_16 = V_151 ( * V_16 , V_389 ) ;
* V_96 = F_340 ( * V_96 , V_390 ) ;
}
if ( * V_16 == - 1UL )
* V_16 = 0 ;
}
static void T_2 F_388 ( void )
{
int V_391 ;
for ( V_391 = V_281 - 1 ; V_391 >= 0 ; V_391 -- ) {
if ( V_391 == V_392 )
continue;
if ( V_393 [ V_391 ] >
V_394 [ V_391 ] )
break;
}
F_42 ( V_391 == - 1 ) ;
V_395 = V_391 ;
}
static void T_14 F_389 ( int V_179 ,
unsigned long V_220 ,
unsigned long V_396 ,
unsigned long V_397 ,
unsigned long * V_17 ,
unsigned long * F_147 )
{
if ( V_398 [ V_179 ] ) {
if ( V_220 == V_392 ) {
* V_17 = V_398 [ V_179 ] ;
* F_147 = V_151 ( V_397 ,
V_393 [ V_395 ] ) ;
} else if ( * V_17 < V_398 [ V_179 ] &&
* F_147 > V_398 [ V_179 ] ) {
* F_147 = V_398 [ V_179 ] ;
} else if ( * V_17 >= V_398 [ V_179 ] )
* V_17 = * F_147 ;
}
}
static unsigned long T_14 F_390 ( int V_179 ,
unsigned long V_220 ,
unsigned long V_396 ,
unsigned long V_397 ,
unsigned long * V_399 )
{
unsigned long V_17 , F_147 ;
V_17 = V_394 [ V_220 ] ;
F_147 = V_393 [ V_220 ] ;
F_389 ( V_179 , V_220 ,
V_396 , V_397 ,
& V_17 , & F_147 ) ;
if ( F_147 < V_396 || V_17 > V_397 )
return 0 ;
F_147 = V_151 ( F_147 , V_397 ) ;
V_17 = F_340 ( V_17 , V_396 ) ;
return F_147 - V_17 ;
}
unsigned long T_14 F_391 ( int V_179 ,
unsigned long V_400 ,
unsigned long V_401 )
{
unsigned long V_402 = V_401 - V_400 ;
unsigned long V_16 , V_96 ;
int V_31 ;
F_380 (i, nid, &start_pfn, &end_pfn, NULL) {
V_16 = F_392 ( V_16 , V_400 , V_401 ) ;
V_96 = F_392 ( V_96 , V_400 , V_401 ) ;
V_402 -= V_96 - V_16 ;
}
return V_402 ;
}
unsigned long T_2 F_393 ( unsigned long V_16 ,
unsigned long V_96 )
{
return F_391 ( V_341 , V_16 , V_96 ) ;
}
static unsigned long T_14 F_394 ( int V_179 ,
unsigned long V_220 ,
unsigned long V_396 ,
unsigned long V_397 ,
unsigned long * V_399 )
{
unsigned long V_403 = V_394 [ V_220 ] ;
unsigned long V_404 = V_393 [ V_220 ] ;
unsigned long V_17 , F_147 ;
V_17 = F_392 ( V_396 , V_403 , V_404 ) ;
F_147 = F_392 ( V_397 , V_403 , V_404 ) ;
F_389 ( V_179 , V_220 ,
V_396 , V_397 ,
& V_17 , & F_147 ) ;
return F_391 ( V_179 , V_17 , F_147 ) ;
}
static inline unsigned long T_14 F_390 ( int V_179 ,
unsigned long V_220 ,
unsigned long V_396 ,
unsigned long V_397 ,
unsigned long * V_405 )
{
return V_405 [ V_220 ] ;
}
static inline unsigned long T_14 F_394 ( int V_179 ,
unsigned long V_220 ,
unsigned long V_396 ,
unsigned long V_397 ,
unsigned long * V_406 )
{
if ( ! V_406 )
return 0 ;
return V_406 [ V_220 ] ;
}
static void T_14 F_395 ( struct V_378 * V_280 ,
unsigned long V_396 ,
unsigned long V_397 ,
unsigned long * V_405 ,
unsigned long * V_406 )
{
unsigned long V_407 , V_408 = 0 ;
enum V_220 V_31 ;
for ( V_31 = 0 ; V_31 < V_281 ; V_31 ++ )
V_408 += F_390 ( V_280 -> V_357 , V_31 ,
V_396 ,
V_397 ,
V_405 ) ;
V_280 -> V_409 = V_408 ;
V_407 = V_408 ;
for ( V_31 = 0 ; V_31 < V_281 ; V_31 ++ )
V_407 -=
F_394 ( V_280 -> V_357 , V_31 ,
V_396 , V_397 ,
V_406 ) ;
V_280 -> V_410 = V_407 ;
F_23 ( V_382 L_71 , V_280 -> V_357 ,
V_407 ) ;
}
static unsigned long T_2 F_396 ( unsigned long V_17 , unsigned long V_411 )
{
unsigned long V_412 ;
V_411 += V_17 & ( V_82 - 1 ) ;
V_412 = F_346 ( V_411 , V_82 ) ;
V_412 = V_412 >> V_84 ;
V_412 *= V_413 ;
V_412 = F_346 ( V_412 , 8 * sizeof( unsigned long ) ) ;
return V_412 / 8 ;
}
static void T_2 F_397 ( struct V_378 * V_280 ,
struct V_11 * V_11 ,
unsigned long V_17 ,
unsigned long V_411 )
{
unsigned long V_412 = F_396 ( V_17 , V_411 ) ;
V_11 -> V_414 = NULL ;
if ( V_412 )
V_11 -> V_414 = F_373 ( V_280 ,
V_412 ) ;
}
static inline void F_397 ( struct V_378 * V_280 , struct V_11 * V_11 ,
unsigned long V_17 , unsigned long V_411 ) {}
void T_2 F_398 ( void )
{
unsigned int V_30 ;
if ( V_84 )
return;
if ( V_415 > V_375 )
V_30 = V_416 ;
else
V_30 = V_40 - 1 ;
V_84 = V_30 ;
}
void T_2 F_398 ( void )
{
}
static unsigned long T_6 F_399 ( unsigned long V_18 ,
unsigned long V_305 )
{
unsigned long V_104 = V_18 ;
if ( V_18 > V_305 + ( V_305 >> 4 ) &&
F_132 ( V_417 ) )
V_104 = V_305 ;
return F_270 ( V_104 * sizeof( struct V_5 ) ) >> V_375 ;
}
static void T_6 F_400 ( struct V_378 * V_280 ,
unsigned long V_396 , unsigned long V_397 ,
unsigned long * V_405 , unsigned long * V_406 )
{
enum V_220 V_343 ;
int V_179 = V_280 -> V_357 ;
unsigned long V_17 = V_280 -> V_396 ;
int V_12 ;
F_401 ( V_280 ) ;
#ifdef F_402
F_403 ( & V_280 -> V_418 ) ;
V_280 -> V_419 = 0 ;
V_280 -> V_420 = V_22 ;
#endif
F_375 ( & V_280 -> V_421 ) ;
F_375 ( & V_280 -> V_422 ) ;
F_404 ( V_280 ) ;
for ( V_343 = 0 ; V_343 < V_281 ; V_343 ++ ) {
struct V_11 * V_11 = V_280 -> V_282 + V_343 ;
unsigned long V_88 , V_423 , V_424 , V_425 ;
V_88 = F_390 ( V_179 , V_343 , V_396 ,
V_397 , V_405 ) ;
V_423 = V_424 = V_88 - F_394 ( V_179 , V_343 ,
V_396 ,
V_397 ,
V_406 ) ;
V_425 = F_399 ( V_88 , V_423 ) ;
if ( V_424 >= V_425 ) {
V_424 -= V_425 ;
if ( V_425 )
F_23 ( V_382
L_72 ,
V_365 [ V_343 ] , V_425 ) ;
} else
F_23 ( V_319
L_73 ,
V_365 [ V_343 ] , V_425 , V_424 ) ;
if ( V_343 == 0 && V_424 > V_426 ) {
V_424 -= V_426 ;
F_23 ( V_382 L_74 ,
V_365 [ 0 ] , V_426 ) ;
}
if ( ! F_355 ( V_343 ) )
V_427 += V_424 ;
else if ( V_427 > V_425 * 2 )
V_427 -= V_425 ;
V_428 += V_424 ;
V_11 -> V_18 = V_88 ;
V_11 -> V_305 = V_423 ;
V_11 -> V_81 = F_355 ( V_343 ) ? V_423 : V_424 ;
#ifdef V_187
V_11 -> V_176 = V_179 ;
V_11 -> V_429 = ( V_424 * V_430 )
/ 100 ;
V_11 -> V_431 = ( V_424 * V_432 ) / 100 ;
#endif
V_11 -> V_288 = V_365 [ V_343 ] ;
F_403 ( & V_11 -> V_67 ) ;
F_403 ( & V_11 -> V_433 ) ;
F_405 ( V_11 ) ;
V_11 -> V_177 = V_280 ;
F_376 ( V_11 ) ;
F_406 ( & V_11 -> V_434 ) ;
if ( ! V_88 )
continue;
F_398 () ;
F_397 ( V_280 , V_11 , V_17 , V_88 ) ;
V_12 = F_377 ( V_11 , V_17 ,
V_88 , V_374 ) ;
F_120 ( V_12 ) ;
F_407 ( V_88 , V_179 , V_343 , V_17 ) ;
V_17 += V_88 ;
}
}
static void T_16 F_408 ( struct V_378 * V_280 )
{
if ( ! V_280 -> V_409 )
return;
#ifdef F_409
if ( ! V_280 -> V_435 ) {
unsigned long V_88 , V_436 , V_263 ;
struct V_5 * V_437 ;
V_436 = V_280 -> V_396 & ~ ( V_438 - 1 ) ;
V_263 = F_410 ( V_280 ) ;
V_263 = F_411 ( V_263 , V_438 ) ;
V_88 = ( V_263 - V_436 ) * sizeof( struct V_5 ) ;
V_437 = F_412 ( V_280 -> V_357 , V_88 ) ;
if ( ! V_437 )
V_437 = F_373 ( V_280 , V_88 ) ;
V_280 -> V_435 = V_437 + ( V_280 -> V_396 - V_436 ) ;
}
#ifndef F_413
if ( V_280 == F_202 ( 0 ) ) {
V_439 = F_202 ( 0 ) -> V_435 ;
#ifdef F_414
if ( F_10 ( V_439 ) != V_280 -> V_396 )
V_439 -= ( V_280 -> V_396 - V_440 ) ;
#endif
}
#endif
#endif
}
void T_6 F_415 ( int V_179 , unsigned long * V_405 ,
unsigned long V_396 , unsigned long * V_406 )
{
T_9 * V_280 = F_202 ( V_179 ) ;
unsigned long V_16 = 0 ;
unsigned long V_96 = 0 ;
F_2 ( V_280 -> V_313 || V_280 -> V_148 ) ;
V_280 -> V_357 = V_179 ;
V_280 -> V_396 = V_396 ;
F_198 ( V_179 ) ;
#ifdef F_414
F_387 ( V_179 , & V_16 , & V_96 ) ;
#endif
F_395 ( V_280 , V_16 , V_96 ,
V_405 , V_406 ) ;
F_408 ( V_280 ) ;
#ifdef F_409
F_23 ( V_382 L_75 ,
V_179 , ( unsigned long ) V_280 ,
( unsigned long ) V_280 -> V_435 ) ;
#endif
F_400 ( V_280 , V_16 , V_96 ,
V_405 , V_406 ) ;
}
void T_2 F_416 ( void )
{
unsigned int V_176 ;
unsigned int V_441 = 0 ;
F_417 (node, node_possible_map)
V_441 = V_176 ;
V_442 = V_441 + 1 ;
}
unsigned long T_2 F_418 ( void )
{
unsigned long V_443 = 0 , V_444 = 0 ;
unsigned long V_436 , V_263 , V_445 ;
int V_386 = - 1 ;
int V_31 , V_179 ;
F_380 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_436 || V_386 < 0 || V_386 == V_179 ) {
V_386 = V_179 ;
V_444 = V_263 ;
continue;
}
V_445 = ~ ( ( 1 << F_419 ( V_436 ) ) - 1 ) ;
while ( V_445 && V_444 <= ( V_436 & ( V_445 << 1 ) ) )
V_445 <<= 1 ;
V_443 |= V_445 ;
}
return ~ V_443 + 1 ;
}
static unsigned long T_2 F_420 ( int V_179 )
{
unsigned long V_446 = V_447 ;
unsigned long V_16 ;
int V_31 ;
F_380 (i, nid, &start_pfn, NULL, NULL)
V_446 = V_151 ( V_446 , V_16 ) ;
if ( V_446 == V_447 ) {
F_23 ( V_319
L_76 , V_179 ) ;
return 0 ;
}
return V_446 ;
}
unsigned long T_2 F_421 ( void )
{
return F_420 ( V_341 ) ;
}
static unsigned long T_2 F_422 ( void )
{
unsigned long V_408 = 0 ;
unsigned long V_16 , V_96 ;
int V_31 , V_179 ;
F_380 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_104 = V_96 - V_16 ;
V_408 += V_104 ;
if ( V_104 )
F_423 ( V_179 , V_170 ) ;
}
return V_408 ;
}
static void T_2 F_424 ( void )
{
int V_31 , V_179 ;
unsigned long V_448 ;
unsigned long V_449 , V_450 ;
T_5 V_451 = V_169 [ V_170 ] ;
unsigned long V_408 = F_422 () ;
int V_452 = F_318 ( V_169 [ V_170 ] ) ;
if ( V_453 ) {
unsigned long V_454 ;
V_453 =
F_346 ( V_453 , V_438 ) ;
V_454 = V_408 - V_453 ;
V_455 = F_340 ( V_455 , V_454 ) ;
}
if ( ! V_455 )
goto V_23;
F_388 () ;
V_448 = V_394 [ V_395 ] ;
V_247:
V_449 = V_455 / V_452 ;
F_312 (nid, N_MEMORY) {
unsigned long V_16 , V_96 ;
if ( V_455 < V_449 )
V_449 = V_455 / V_452 ;
V_450 = V_449 ;
F_380 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_456 ;
V_16 = F_340 ( V_16 , V_398 [ V_179 ] ) ;
if ( V_16 >= V_96 )
continue;
if ( V_16 < V_448 ) {
unsigned long V_457 ;
V_457 = V_151 ( V_96 , V_448 )
- V_16 ;
V_450 -= V_151 ( V_457 ,
V_450 ) ;
V_455 -= V_151 ( V_457 ,
V_455 ) ;
if ( V_96 <= V_448 ) {
V_398 [ V_179 ] = V_96 ;
continue;
}
V_16 = V_448 ;
}
V_456 = V_96 - V_16 ;
if ( V_456 > V_450 )
V_456 = V_450 ;
V_398 [ V_179 ] = V_16 + V_456 ;
V_455 -= V_151 ( V_455 ,
V_456 ) ;
V_450 -= V_456 ;
if ( ! V_450 )
break;
}
}
V_452 -- ;
if ( V_452 && V_455 > V_452 )
goto V_247;
for ( V_179 = 0 ; V_179 < V_341 ; V_179 ++ )
V_398 [ V_179 ] =
F_346 ( V_398 [ V_179 ] , V_438 ) ;
V_23:
V_169 [ V_170 ] = V_451 ;
}
static void F_425 ( T_9 * V_280 , int V_179 )
{
enum V_220 V_220 ;
if ( V_170 == V_458 )
return;
for ( V_220 = 0 ; V_220 <= V_392 - 1 ; V_220 ++ ) {
struct V_11 * V_11 = & V_280 -> V_282 [ V_220 ] ;
if ( V_11 -> V_305 ) {
F_423 ( V_179 , V_459 ) ;
if ( V_458 != V_459 &&
V_220 <= V_223 )
F_423 ( V_179 , V_458 ) ;
break;
}
}
}
void T_2 F_426 ( unsigned long * V_117 )
{
unsigned long V_16 , V_96 ;
int V_31 , V_179 ;
memset ( V_394 , 0 ,
sizeof( V_394 ) ) ;
memset ( V_393 , 0 ,
sizeof( V_393 ) ) ;
V_394 [ 0 ] = F_421 () ;
V_393 [ 0 ] = V_117 [ 0 ] ;
for ( V_31 = 1 ; V_31 < V_281 ; V_31 ++ ) {
if ( V_31 == V_392 )
continue;
V_394 [ V_31 ] =
V_393 [ V_31 - 1 ] ;
V_393 [ V_31 ] =
F_340 ( V_117 [ V_31 ] , V_394 [ V_31 ] ) ;
}
V_394 [ V_392 ] = 0 ;
V_393 [ V_392 ] = 0 ;
memset ( V_398 , 0 , sizeof( V_398 ) ) ;
F_424 () ;
F_23 ( L_77 ) ;
for ( V_31 = 0 ; V_31 < V_281 ; V_31 ++ ) {
if ( V_31 == V_392 )
continue;
F_23 ( V_460 L_78 , V_365 [ V_31 ] ) ;
if ( V_394 [ V_31 ] ==
V_393 [ V_31 ] )
F_23 ( V_460 L_79 ) ;
else
F_23 ( V_460 L_80 ,
V_394 [ V_31 ] << V_375 ,
( V_393 [ V_31 ]
<< V_375 ) - 1 ) ;
}
F_23 ( L_81 ) ;
for ( V_31 = 0 ; V_31 < V_341 ; V_31 ++ ) {
if ( V_398 [ V_31 ] )
F_23 ( L_82 , V_31 ,
V_398 [ V_31 ] << V_375 ) ;
}
F_23 ( L_83 ) ;
F_380 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_23 ( L_84 , V_179 ,
V_16 << V_375 , ( V_96 << V_375 ) - 1 ) ;
F_427 () ;
F_416 () ;
F_199 (nid) {
T_9 * V_280 = F_202 ( V_179 ) ;
F_415 ( V_179 , NULL ,
F_420 ( V_179 ) , NULL ) ;
if ( V_280 -> V_410 )
F_423 ( V_179 , V_170 ) ;
F_425 ( V_280 , V_179 ) ;
}
}
static int T_2 F_428 ( char * V_33 , unsigned long * V_461 )
{
unsigned long long V_462 ;
if ( ! V_33 )
return - V_320 ;
V_462 = F_429 ( V_33 , & V_33 ) ;
* V_461 = V_462 >> V_375 ;
F_2 ( ( V_462 >> V_375 ) > V_447 ) ;
return 0 ;
}
static int T_2 F_430 ( char * V_33 )
{
return F_428 ( V_33 , & V_455 ) ;
}
static int T_2 F_431 ( char * V_33 )
{
return F_428 ( V_33 , & V_453 ) ;
}
void F_109 ( struct V_5 * V_5 , long V_62 )
{
F_76 ( & V_463 ) ;
F_17 ( V_5 ) -> V_81 += V_62 ;
V_272 += V_62 ;
#ifdef F_288
if ( F_92 ( V_5 ) )
V_277 += V_62 ;
#endif
F_85 ( & V_463 ) ;
}
unsigned long F_432 ( void * V_436 , void * V_263 , int V_464 , char * V_314 )
{
void * V_346 ;
unsigned long V_104 = 0 ;
V_436 = ( void * ) F_270 ( ( unsigned long ) V_436 ) ;
V_263 = ( void * ) ( ( unsigned long ) V_263 & V_465 ) ;
for ( V_346 = V_436 ; V_346 < V_263 ; V_346 += V_78 , V_104 ++ ) {
if ( ( unsigned int ) V_464 <= 0xFF )
memset ( V_346 , V_464 , V_78 ) ;
F_433 ( F_164 ( V_346 ) ) ;
}
if ( V_104 && V_314 )
F_434 ( L_85 ,
V_314 , V_104 << ( V_375 - 10 ) , V_436 , V_263 ) ;
return V_104 ;
}
void F_435 ( struct V_5 * V_5 )
{
F_436 ( V_5 ) ;
V_272 ++ ;
F_17 ( V_5 ) -> V_81 ++ ;
V_277 ++ ;
}
void T_2 F_437 ( const char * V_130 )
{
unsigned long V_466 , V_467 , V_468 , V_469 , V_470 ;
unsigned long V_471 , V_472 ;
V_466 = F_438 () ;
V_467 = V_473 - V_474 ;
V_468 = V_475 - V_476 ;
V_469 = V_477 - V_478 ;
V_470 = V_479 - V_480 ;
V_472 = V_481 - V_482 ;
V_471 = V_483 - V_484 ;
#define F_439 ( V_436 , V_263 , V_88 , V_346 , T_18 ) \
if (start <= pos && pos < end && size > adj) \
size -= adj;
F_439 ( V_482 , V_481 , V_472 ,
V_484 , V_471 ) ;
F_439 ( V_474 , V_473 , V_467 , V_484 , V_471 ) ;
F_439 ( V_476 , V_475 , V_468 , V_482 , V_472 ) ;
F_439 ( V_474 , V_473 , V_467 , V_478 , V_469 ) ;
F_439 ( V_476 , V_475 , V_468 , V_478 , V_469 ) ;
#undef F_439
F_23 ( L_86
L_87
L_88
#ifdef F_288
L_89
#endif
L_90 ,
F_440 () << ( V_375 - 10 ) , V_466 << ( V_375 - 10 ) ,
V_467 >> 10 , V_468 >> 10 , V_469 >> 10 ,
( V_472 + V_471 ) >> 10 , V_470 >> 10 ,
( V_466 - V_272 ) << ( V_375 - 10 ) ,
#ifdef F_288
V_277 << ( V_375 - 10 ) ,
#endif
V_130 ? L_91 : L_92 , V_130 ? V_130 : L_92 ) ;
}
void T_2 F_441 ( unsigned long V_485 )
{
V_426 = V_485 ;
}
void T_2 F_442 ( unsigned long * V_405 )
{
F_415 ( 0 , V_405 ,
F_443 ( V_486 ) >> V_375 , NULL ) ;
}
static int F_444 ( struct V_487 * V_359 ,
unsigned long V_488 , void * V_489 )
{
int V_110 = ( unsigned long ) V_489 ;
if ( V_488 == V_490 || V_488 == V_491 ) {
F_445 ( V_110 ) ;
F_135 ( V_110 ) ;
F_446 ( V_110 ) ;
F_447 ( V_110 ) ;
}
return V_492 ;
}
void T_2 F_448 ( void )
{
F_449 ( F_444 , 0 ) ;
}
static void F_450 ( void )
{
struct V_378 * V_280 ;
unsigned long V_493 = 0 ;
enum V_220 V_31 , V_343 ;
F_451 (pgdat) {
for ( V_31 = 0 ; V_31 < V_281 ; V_31 ++ ) {
struct V_11 * V_11 = V_280 -> V_282 + V_31 ;
unsigned long F_340 = 0 ;
for ( V_343 = V_31 ; V_343 < V_281 ; V_343 ++ ) {
if ( V_11 -> V_152 [ V_343 ] > F_340 )
F_340 = V_11 -> V_152 [ V_343 ] ;
}
F_340 += F_278 ( V_11 ) ;
if ( F_340 > V_11 -> V_81 )
F_340 = V_11 -> V_81 ;
V_493 += F_340 ;
V_11 -> V_494 = F_340 ;
}
}
V_494 = V_493 ;
V_495 = V_493 ;
}
static void F_452 ( void )
{
struct V_378 * V_280 ;
enum V_220 V_343 , V_496 ;
F_451 (pgdat) {
for ( V_343 = 0 ; V_343 < V_281 ; V_343 ++ ) {
struct V_11 * V_11 = V_280 -> V_282 + V_343 ;
unsigned long V_81 = V_11 -> V_81 ;
V_11 -> V_152 [ V_343 ] = 0 ;
V_496 = V_343 ;
while ( V_496 ) {
struct V_11 * V_497 ;
V_496 -- ;
if ( V_498 [ V_496 ] < 1 )
V_498 [ V_496 ] = 1 ;
V_497 = V_280 -> V_282 + V_496 ;
V_497 -> V_152 [ V_343 ] = V_81 /
V_498 [ V_496 ] ;
V_81 += V_497 -> V_81 ;
}
}
}
F_450 () ;
}
static void F_453 ( void )
{
unsigned long V_499 = V_500 >> ( V_375 - 10 ) ;
unsigned long V_501 = 0 ;
struct V_11 * V_11 ;
unsigned long V_59 ;
F_454 (zone) {
if ( ! F_455 ( V_11 ) )
V_501 += V_11 -> V_81 ;
}
F_454 (zone) {
T_19 V_287 ;
F_146 ( & V_11 -> V_67 , V_59 ) ;
V_287 = ( T_19 ) V_499 * V_11 -> V_81 ;
F_456 ( V_287 , V_501 ) ;
if ( F_455 ( V_11 ) ) {
unsigned long V_502 ;
V_502 = V_11 -> V_81 / 1024 ;
V_502 = F_392 ( V_502 , V_503 , 128UL ) ;
V_11 -> V_122 [ V_504 ] = V_502 ;
} else {
V_11 -> V_122 [ V_504 ] = V_287 ;
}
V_11 -> V_122 [ V_505 ] = F_294 ( V_11 ) + ( V_287 >> 2 ) ;
V_11 -> V_122 [ V_506 ] = F_294 ( V_11 ) + ( V_287 >> 1 ) ;
F_345 ( V_11 ) ;
F_154 ( & V_11 -> V_67 , V_59 ) ;
}
F_450 () ;
}
void F_457 ( void )
{
F_306 ( & V_332 ) ;
F_453 () ;
F_309 ( & V_332 ) ;
}
static void T_14 F_458 ( struct V_11 * V_11 )
{
unsigned int V_507 , V_508 ;
V_507 = V_11 -> V_81 >> ( 30 - V_375 ) ;
if ( V_507 )
V_508 = F_459 ( 10 * V_507 ) ;
else
V_508 = 1 ;
V_11 -> V_509 = V_508 ;
}
static void T_14 F_460 ( void )
{
struct V_11 * V_11 ;
F_454 (zone)
F_458 ( V_11 ) ;
}
int T_14 F_461 ( void )
{
unsigned long V_510 ;
int V_511 ;
V_510 = F_279 () * ( V_78 >> 10 ) ;
V_511 = F_459 ( V_510 * 16 ) ;
if ( V_511 > V_512 ) {
V_500 = V_511 ;
if ( V_500 < 128 )
V_500 = 128 ;
if ( V_500 > 65536 )
V_500 = 65536 ;
} else {
F_214 ( L_93 ,
V_511 , V_512 ) ;
}
F_457 () ;
F_462 () ;
F_452 () ;
F_460 () ;
return 0 ;
}
int F_463 ( T_10 * V_323 , int V_324 ,
void T_11 * V_325 , T_8 * V_326 , T_12 * V_327 )
{
F_464 ( V_323 , V_324 , V_325 , V_326 , V_327 ) ;
if ( V_324 ) {
V_512 = V_500 ;
F_457 () ;
}
return 0 ;
}
int F_465 ( T_10 * V_323 , int V_324 ,
void T_11 * V_325 , T_8 * V_326 , T_12 * V_327 )
{
struct V_11 * V_11 ;
int V_513 ;
V_513 = F_466 ( V_323 , V_324 , V_325 , V_326 , V_327 ) ;
if ( V_513 )
return V_513 ;
F_454 (zone)
V_11 -> V_429 = ( V_11 -> V_81 *
V_430 ) / 100 ;
return 0 ;
}
int F_467 ( T_10 * V_323 , int V_324 ,
void T_11 * V_325 , T_8 * V_326 , T_12 * V_327 )
{
struct V_11 * V_11 ;
int V_513 ;
V_513 = F_466 ( V_323 , V_324 , V_325 , V_326 , V_327 ) ;
if ( V_513 )
return V_513 ;
F_454 (zone)
V_11 -> V_431 = ( V_11 -> V_81 *
V_432 ) / 100 ;
return 0 ;
}
int F_468 ( T_10 * V_323 , int V_324 ,
void T_11 * V_325 , T_8 * V_326 , T_12 * V_327 )
{
F_466 ( V_323 , V_324 , V_325 , V_326 , V_327 ) ;
F_452 () ;
return 0 ;
}
int F_469 ( T_10 * V_323 , int V_324 ,
void T_11 * V_325 , T_8 * V_326 , T_12 * V_327 )
{
struct V_11 * V_11 ;
unsigned int V_110 ;
int V_12 ;
V_12 = F_466 ( V_323 , V_324 , V_325 , V_326 , V_327 ) ;
if ( ! V_324 || ( V_12 < 0 ) )
return V_12 ;
F_306 ( & V_514 ) ;
F_136 (zone) {
unsigned long V_86 ;
V_86 = V_11 -> V_81 / V_376 ;
F_327 (cpu)
F_366 ( F_137 ( V_11 -> V_113 , V_110 ) ,
V_86 ) ;
}
F_309 ( & V_514 ) ;
return 0 ;
}
static int T_2 F_470 ( char * V_130 )
{
if ( ! V_130 )
return 0 ;
V_515 = F_471 ( V_130 , & V_130 , 0 ) ;
return 1 ;
}
void * T_2 F_472 ( const char * V_516 ,
unsigned long V_517 ,
unsigned long V_518 ,
int V_519 ,
int V_59 ,
unsigned int * V_520 ,
unsigned int * V_521 ,
unsigned long V_522 ,
unsigned long V_523 )
{
unsigned long long F_340 = V_523 ;
unsigned long V_524 , V_88 ;
void * V_323 = NULL ;
if ( ! V_518 ) {
V_518 = V_427 ;
V_518 += ( 1UL << ( 20 - V_375 ) ) - 1 ;
V_518 >>= 20 - V_375 ;
V_518 <<= 20 - V_375 ;
if ( V_519 > V_375 )
V_518 >>= ( V_519 - V_375 ) ;
else
V_518 <<= ( V_375 - V_519 ) ;
if ( F_7 ( V_59 & V_525 ) ) {
F_2 ( ! ( V_59 & V_526 ) ) ;
if ( ! ( V_518 >> * V_520 ) ) {
V_518 = 1UL << * V_520 ;
F_120 ( ! V_518 ) ;
}
} else if ( F_7 ( ( V_518 * V_517 ) < V_78 ) )
V_518 = V_78 / V_517 ;
}
V_518 = F_473 ( V_518 ) ;
if ( F_340 == 0 ) {
F_340 = ( ( unsigned long long ) V_428 << V_375 ) >> 4 ;
F_456 ( F_340 , V_517 ) ;
}
F_340 = V_151 ( F_340 , 0x80000000ULL ) ;
if ( V_518 < V_522 )
V_518 = V_522 ;
if ( V_518 > F_340 )
V_518 = F_340 ;
V_524 = F_474 ( V_518 ) ;
do {
V_88 = V_517 << V_524 ;
if ( V_59 & V_526 )
V_323 = F_475 ( V_88 ) ;
else if ( V_515 )
V_323 = F_476 ( V_88 , V_527 , V_528 ) ;
else {
if ( F_273 ( V_88 ) < V_40 ) {
V_323 = F_272 ( V_88 , V_527 ) ;
F_477 ( V_323 , V_88 , 1 , V_527 ) ;
}
}
} while ( ! V_323 && V_88 > V_78 && -- V_524 );
if ( ! V_323 )
F_478 ( L_94 , V_516 ) ;
F_23 ( V_43 L_95 ,
V_516 ,
( 1UL << V_524 ) ,
F_474 ( V_88 ) - V_375 ,
V_88 ) ;
if ( V_520 )
* V_520 = V_524 ;
if ( V_521 )
* V_521 = ( 1 << V_524 ) - 1 ;
return V_323 ;
}
static inline unsigned long * F_479 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef V_417
return F_480 ( V_14 ) -> V_414 ;
#else
return V_11 -> V_414 ;
#endif
}
static inline int F_481 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef V_417
V_14 &= ( V_529 - 1 ) ;
return ( V_14 >> V_84 ) * V_413 ;
#else
V_14 = V_14 - F_482 ( V_11 -> V_17 , V_82 ) ;
return ( V_14 >> V_84 ) * V_413 ;
#endif
}
unsigned long F_483 ( struct V_5 * V_5 ,
int V_530 , int V_531 )
{
struct V_11 * V_11 ;
unsigned long * V_532 ;
unsigned long V_14 , V_533 ;
unsigned long V_59 = 0 ;
unsigned long V_534 = 1 ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_532 = F_479 ( V_11 , V_14 ) ;
V_533 = F_481 ( V_11 , V_14 ) ;
for (; V_530 <= V_531 ; V_530 ++ , V_534 <<= 1 )
if ( F_193 ( V_533 + V_530 , V_532 ) )
V_59 |= V_534 ;
return V_59 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_59 ,
int V_530 , int V_531 )
{
struct V_11 * V_11 ;
unsigned long * V_532 ;
unsigned long V_14 , V_533 ;
unsigned long V_534 = 1 ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_532 = F_479 ( V_11 , V_14 ) ;
V_533 = F_481 ( V_11 , V_14 ) ;
F_42 ( ! F_12 ( V_11 , V_14 ) ) ;
for (; V_530 <= V_531 ; V_530 ++ , V_534 <<= 1 )
if ( V_59 & V_534 )
F_48 ( V_533 + V_530 , V_532 ) ;
else
F_50 ( V_533 + V_530 , V_532 ) ;
}
bool F_484 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_62 ,
bool V_535 )
{
unsigned long V_14 , V_536 , V_537 ;
int V_74 ;
if ( F_204 ( V_11 ) == V_392 )
return false ;
V_74 = F_100 ( V_5 ) ;
if ( V_74 == V_120 || F_84 ( V_74 ) )
return false ;
V_14 = F_10 ( V_5 ) ;
for ( V_537 = 0 , V_536 = 0 ; V_536 < V_82 ; V_536 ++ ) {
unsigned long V_538 = V_14 + V_536 ;
if ( ! F_16 ( V_538 ) )
continue;
V_5 = F_125 ( V_538 ) ;
if ( ! F_72 ( & V_5 -> V_58 ) ) {
if ( F_62 ( V_5 ) )
V_536 += ( 1 << F_60 ( V_5 ) ) - 1 ;
continue;
}
if ( V_535 && F_20 ( V_5 ) )
continue;
if ( ! F_485 ( V_5 ) )
V_537 ++ ;
if ( V_537 > V_62 )
return true ;
}
return false ;
}
bool F_486 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_325 ( F_121 ( V_5 ) ) )
return false ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_11 , V_14 ) )
return false ;
return ! F_484 ( V_11 , V_5 , 0 , true ) ;
}
static unsigned long F_487 ( unsigned long V_14 )
{
return V_14 & ~ ( F_488 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_489 ( unsigned long V_14 )
{
return F_411 ( V_14 , F_488 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_490 ( struct V_539 * V_540 ,
unsigned long V_436 , unsigned long V_263 )
{
unsigned long V_541 ;
unsigned long V_14 = V_436 ;
unsigned int V_542 = 0 ;
int V_12 = 0 ;
F_491 () ;
while ( V_14 < V_263 || ! F_77 ( & V_540 -> V_543 ) ) {
if ( F_492 ( V_26 ) ) {
V_12 = - V_544 ;
break;
}
if ( F_77 ( & V_540 -> V_543 ) ) {
V_540 -> V_545 = 0 ;
V_14 = F_493 ( V_540 -> V_11 , V_540 ,
V_14 , V_263 , true ) ;
if ( ! V_14 ) {
V_12 = - V_544 ;
break;
}
V_542 = 0 ;
} else if ( ++ V_542 == 5 ) {
V_12 = V_12 < 0 ? V_12 : - V_546 ;
break;
}
V_541 = F_494 ( V_540 -> V_11 ,
& V_540 -> V_543 ) ;
V_540 -> V_545 -= V_541 ;
V_12 = F_495 ( & V_540 -> V_543 , V_547 ,
0 , V_548 , V_549 ) ;
}
if ( V_12 < 0 ) {
F_496 ( & V_540 -> V_543 ) ;
return V_12 ;
}
return 0 ;
}
int F_497 ( unsigned long V_436 , unsigned long V_263 ,
unsigned V_6 )
{
unsigned long V_550 , V_551 ;
int V_12 = 0 , V_30 ;
struct V_539 V_540 = {
. V_545 = 0 ,
. V_30 = - 1 ,
. V_11 = F_17 ( F_125 ( V_436 ) ) ,
. V_552 = true ,
. V_553 = true ,
} ;
F_113 ( & V_540 . V_543 ) ;
V_12 = F_498 ( F_487 ( V_436 ) ,
F_489 ( V_263 ) , V_6 ,
false ) ;
if ( V_12 )
return V_12 ;
V_12 = F_490 ( & V_540 , V_436 , V_263 ) ;
if ( V_12 )
goto V_554;
F_499 () ;
F_140 () ;
V_30 = 0 ;
V_550 = V_436 ;
while ( ! F_62 ( F_125 ( V_550 ) ) ) {
if ( ++ V_30 >= V_40 ) {
V_12 = - V_546 ;
goto V_554;
}
V_550 &= ~ 0UL << V_30 ;
}
if ( F_500 ( V_550 , V_263 , false ) ) {
F_214 ( L_96 ,
V_550 , V_263 ) ;
V_12 = - V_546 ;
goto V_554;
}
V_551 = F_501 ( & V_540 , V_550 , V_263 ) ;
if ( ! V_551 ) {
V_12 = - V_546 ;
goto V_554;
}
if ( V_436 != V_550 )
F_502 ( V_550 , V_436 - V_550 ) ;
if ( V_263 != V_551 )
F_502 ( V_263 , V_551 - V_263 ) ;
V_554:
F_503 ( F_487 ( V_436 ) ,
F_489 ( V_263 ) , V_6 ) ;
return V_12 ;
}
void F_502 ( unsigned long V_14 , unsigned V_32 )
{
unsigned int V_62 = 0 ;
for (; V_32 -- ; V_14 ++ ) {
struct V_5 * V_5 = F_125 ( V_14 ) ;
V_62 += F_61 ( V_5 ) != 1 ;
F_504 ( V_5 ) ;
}
F_505 ( V_62 != 0 , L_97 , V_62 ) ;
}
void T_14 F_506 ( struct V_11 * V_11 )
{
unsigned V_110 ;
F_306 ( & V_514 ) ;
F_327 (cpu)
F_367 ( V_11 ,
F_137 ( V_11 -> V_113 , V_110 ) ) ;
F_309 ( & V_514 ) ;
}
void F_507 ( struct V_11 * V_11 )
{
unsigned long V_59 ;
int V_110 ;
struct V_111 * V_112 ;
F_98 ( V_59 ) ;
if ( V_11 -> V_113 != & V_360 ) {
F_141 (cpu) {
V_112 = F_137 ( V_11 -> V_113 , V_110 ) ;
F_508 ( V_11 , V_112 ) ;
}
F_509 ( V_11 -> V_113 ) ;
V_11 -> V_113 = & V_360 ;
}
F_102 ( V_59 ) ;
}
void
F_510 ( unsigned long V_16 , unsigned long V_96 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_30 , V_31 ;
unsigned long V_14 ;
unsigned long V_59 ;
for ( V_14 = V_16 ; V_14 < V_96 ; V_14 ++ )
if ( F_148 ( V_14 ) )
break;
if ( V_14 == V_96 )
return;
V_11 = F_17 ( F_125 ( V_14 ) ) ;
F_146 ( & V_11 -> V_67 , V_59 ) ;
V_14 = V_16 ;
while ( V_14 < V_96 ) {
if ( ! F_148 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_125 ( V_14 ) ;
if ( F_7 ( ! F_62 ( V_5 ) && F_20 ( V_5 ) ) ) {
V_14 ++ ;
F_353 ( V_5 ) ;
continue;
}
F_120 ( F_61 ( V_5 ) ) ;
F_120 ( ! F_62 ( V_5 ) ) ;
V_30 = F_60 ( V_5 ) ;
#ifdef F_511
F_23 ( V_43 L_98 ,
V_14 , 1 << V_30 , V_96 ) ;
#endif
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
V_11 -> V_52 [ V_30 ] . V_53 -- ;
#ifdef F_288
if ( F_92 ( V_5 ) )
V_277 -= 1 << V_30 ;
#endif
for ( V_31 = 0 ; V_31 < ( 1 << V_30 ) ; V_31 ++ )
F_353 ( ( V_5 + V_31 ) ) ;
V_14 += ( 1 << V_30 ) ;
}
F_154 ( & V_11 -> V_67 , V_59 ) ;
}
bool F_512 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_17 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_59 ;
int V_30 ;
F_146 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
struct V_5 * V_555 = V_5 - ( V_14 & ( ( 1 << V_30 ) - 1 ) ) ;
if ( F_62 ( V_555 ) && F_60 ( V_555 ) >= V_30 )
break;
}
F_154 ( & V_11 -> V_67 , V_59 ) ;
return V_30 < V_40 ;
}
static void F_513 ( unsigned long V_59 )
{
const char * V_556 = L_92 ;
unsigned long V_445 ;
int V_31 ;
F_208 ( F_514 ( V_557 ) != V_558 ) ;
F_23 ( V_24 L_99 , V_59 ) ;
V_59 &= ( 1UL << V_559 ) - 1 ;
for ( V_31 = 0 ; V_31 < F_514 ( V_557 ) && V_59 ; V_31 ++ ) {
V_445 = V_557 [ V_31 ] . V_445 ;
if ( ( V_59 & V_445 ) != V_445 )
continue;
V_59 &= ~ V_445 ;
F_23 ( L_100 , V_556 , V_557 [ V_31 ] . V_288 ) ;
V_556 = L_101 ;
}
if ( V_59 )
F_23 ( L_102 , V_556 , V_59 ) ;
F_23 ( L_103 ) ;
}
void F_24 ( struct V_5 * V_5 )
{
F_23 ( V_24
L_104 ,
V_5 , F_72 ( & V_5 -> V_58 ) , F_71 ( V_5 ) ,
V_5 -> V_57 , V_5 -> V_560 ) ;
F_513 ( V_5 -> V_59 ) ;
F_515 ( V_5 ) ;
}
