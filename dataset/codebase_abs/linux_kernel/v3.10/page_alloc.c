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
void T_3 F_103 ( struct V_5 * V_5 , unsigned int V_30 )
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
V_85 += V_82 ;
#ifdef F_109
if ( F_92 ( V_5 ) )
V_86 += V_82 ;
#endif
}
static inline void F_110 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_87 , int V_88 , struct V_52 * V_89 ,
int V_6 )
{
unsigned long V_90 = 1 << V_88 ;
while ( V_88 > V_87 ) {
V_89 -- ;
V_88 -- ;
V_90 >>= 1 ;
F_42 ( F_18 ( V_11 , & V_5 [ V_90 ] ) ) ;
#ifdef F_111
if ( V_88 < F_112 () ) {
F_113 ( & V_5 [ V_90 ] . V_51 ) ;
F_47 ( & V_5 [ V_90 ] ) ;
F_52 ( & V_5 [ V_90 ] , V_88 ) ;
F_66 ( V_11 , - ( 1 << V_88 ) ,
V_6 ) ;
continue;
}
#endif
F_69 ( & V_5 [ V_90 ] . V_51 , & V_89 -> V_56 [ V_6 ] ) ;
V_89 -> V_53 ++ ;
F_51 ( & V_5 [ V_90 ] , V_88 ) ;
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
if ( V_36 & V_91 )
F_41 ( V_5 , V_30 , V_36 ) ;
if ( V_30 && ( V_36 & V_92 ) )
F_31 ( V_5 , V_30 ) ;
return 0 ;
}
static inline
struct V_5 * F_117 ( struct V_11 * V_11 , unsigned int V_30 ,
int V_6 )
{
unsigned int V_93 ;
struct V_52 * V_89 ;
struct V_5 * V_5 ;
for ( V_93 = V_30 ; V_93 < V_40 ; ++ V_93 ) {
V_89 = & ( V_11 -> V_52 [ V_93 ] ) ;
if ( F_77 ( & V_89 -> V_56 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_89 -> V_56 [ V_6 ] . V_94 ,
struct V_5 , V_51 ) ;
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
V_89 -> V_53 -- ;
F_110 ( V_11 , V_5 , V_30 , V_93 , V_89 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_118 ( struct V_11 * V_11 ,
struct V_5 * V_95 , struct V_5 * V_96 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_30 ;
int V_97 = 0 ;
#ifndef F_119
F_120 ( F_17 ( V_95 ) != F_17 ( V_96 ) ) ;
#endif
for ( V_5 = V_95 ; V_5 <= V_96 ; ) {
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
V_97 += 1 << V_30 ;
}
return V_97 ;
}
int F_124 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_16 , V_98 ;
struct V_5 * V_95 , * V_96 ;
V_16 = F_10 ( V_5 ) ;
V_16 = V_16 & ~ ( V_82 - 1 ) ;
V_95 = F_125 ( V_16 ) ;
V_96 = V_95 + V_82 - 1 ;
V_98 = V_16 + V_82 - 1 ;
if ( ! F_12 ( V_11 , V_16 ) )
V_95 = V_5 ;
if ( ! F_12 ( V_11 , V_98 ) )
return 0 ;
return F_118 ( V_11 , V_95 , V_96 , V_6 ) ;
}
static void F_126 ( struct V_5 * V_99 ,
int V_100 , int V_6 )
{
int V_101 = 1 << ( V_100 - V_84 ) ;
while ( V_101 -- ) {
F_6 ( V_99 , V_6 ) ;
V_99 += V_82 ;
}
}
static inline struct V_5 *
F_127 ( struct V_11 * V_11 , int V_30 , int V_102 )
{
struct V_52 * V_89 ;
int V_93 ;
struct V_5 * V_5 ;
int V_6 , V_31 ;
for ( V_93 = V_40 - 1 ; V_93 >= V_30 ;
-- V_93 ) {
for ( V_31 = 0 ; ; V_31 ++ ) {
V_6 = V_103 [ V_102 ] [ V_31 ] ;
if ( V_6 == V_104 )
break;
V_89 = & ( V_11 -> V_52 [ V_93 ] ) ;
if ( F_77 ( & V_89 -> V_56 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_89 -> V_56 [ V_6 ] . V_94 ,
struct V_5 , V_51 ) ;
V_89 -> V_53 -- ;
if ( ! F_84 ( V_6 ) &&
( F_7 ( V_93 >= V_84 / 2 ) ||
V_102 == V_105 ||
V_7 ) ) {
int V_106 ;
V_106 = F_124 ( V_11 , V_5 ,
V_102 ) ;
if ( V_106 >= ( 1 << ( V_84 - 1 ) ) ||
V_7 )
F_6 ( V_5 ,
V_102 ) ;
V_6 = V_102 ;
}
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
if ( V_93 >= V_84 &&
! F_84 ( V_6 ) )
F_126 ( V_5 , V_93 ,
V_102 ) ;
F_110 ( V_11 , V_5 , V_30 , V_93 , V_89 ,
F_84 ( V_6 )
? V_6 : V_102 ) ;
F_128 ( V_5 , V_30 , V_93 ,
V_102 , V_6 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_129 ( struct V_11 * V_11 , unsigned int V_30 ,
int V_6 )
{
struct V_5 * V_5 ;
V_107:
V_5 = F_117 ( V_11 , V_30 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_104 ) {
V_5 = F_127 ( V_11 , V_30 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_104 ;
goto V_107;
}
}
F_130 ( V_5 , V_30 , V_6 ) ;
return V_5 ;
}
static int F_131 ( struct V_11 * V_11 , unsigned int V_30 ,
unsigned long V_62 , struct V_70 * V_71 ,
int V_6 , int V_108 )
{
int V_74 = V_6 , V_31 ;
F_76 ( & V_11 -> V_67 ) ;
for ( V_31 = 0 ; V_31 < V_62 ; ++ V_31 ) {
struct V_5 * V_5 = F_129 ( V_11 , V_30 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_81 ( V_108 == 0 ) )
F_69 ( & V_5 -> V_51 , V_71 ) ;
else
F_68 ( & V_5 -> V_51 , V_71 ) ;
if ( F_132 ( V_109 ) ) {
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
int V_110 ;
F_98 ( V_59 ) ;
if ( V_64 -> V_62 >= V_64 -> V_111 )
V_110 = V_64 -> V_111 ;
else
V_110 = V_64 -> V_62 ;
if ( V_110 > 0 ) {
F_75 ( V_11 , V_110 , V_64 ) ;
V_64 -> V_62 -= V_110 ;
}
F_102 ( V_59 ) ;
}
static void F_134 ( unsigned int V_112 )
{
unsigned long V_59 ;
struct V_11 * V_11 ;
F_135 (zone) {
struct V_113 * V_114 ;
struct V_63 * V_64 ;
F_98 ( V_59 ) ;
V_114 = F_136 ( V_11 -> V_115 , V_112 ) ;
V_64 = & V_114 -> V_64 ;
if ( V_64 -> V_62 ) {
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
V_64 -> V_62 = 0 ;
}
F_102 ( V_59 ) ;
}
}
void F_137 ( void * V_116 )
{
F_134 ( F_138 () ) ;
}
void F_139 ( void )
{
int V_112 ;
struct V_113 * V_64 ;
struct V_11 * V_11 ;
static T_4 V_117 ;
F_140 (cpu) {
bool V_118 = false ;
F_135 (zone) {
V_64 = F_136 ( V_11 -> V_115 , V_112 ) ;
if ( V_64 -> V_64 . V_62 ) {
V_118 = true ;
break;
}
}
if ( V_118 )
F_141 ( V_112 , & V_117 ) ;
else
F_142 ( V_112 , & V_117 ) ;
}
F_143 ( & V_117 , F_137 , NULL , 1 ) ;
}
void F_144 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_119 ;
unsigned long V_59 ;
int V_30 , V_120 ;
struct V_70 * V_121 ;
if ( ! V_11 -> V_18 )
return;
F_145 ( & V_11 -> V_67 , V_59 ) ;
V_119 = F_146 ( V_11 ) ;
for ( V_14 = V_11 -> V_17 ; V_14 < V_119 ; V_14 ++ )
if ( F_147 ( V_14 ) ) {
struct V_5 * V_5 = F_125 ( V_14 ) ;
if ( ! F_148 ( V_5 ) )
F_149 ( V_5 ) ;
}
F_150 (order, t) {
F_151 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_31 ;
V_14 = F_10 ( F_78 ( V_121 , struct V_5 , V_51 ) ) ;
for ( V_31 = 0 ; V_31 < ( 1UL << V_30 ) ; V_31 ++ )
F_152 ( F_125 ( V_14 + V_31 ) ) ;
}
}
F_153 ( & V_11 -> V_67 , V_59 ) ;
}
void F_154 ( struct V_5 * V_5 , int V_108 )
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
F_155 ( V_79 ) ;
if ( V_6 >= V_72 ) {
if ( F_7 ( F_87 ( V_6 ) ) ) {
F_86 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_23;
}
V_6 = V_122 ;
}
V_64 = & F_156 ( V_11 -> V_115 ) -> V_64 ;
if ( V_108 )
F_68 ( & V_5 -> V_51 , & V_64 -> V_73 [ V_6 ] ) ;
else
F_69 ( & V_5 -> V_51 , & V_64 -> V_73 [ V_6 ] ) ;
V_64 -> V_62 ++ ;
if ( V_64 -> V_62 >= V_64 -> V_88 ) {
F_75 ( V_11 , V_64 -> V_111 , V_64 ) ;
V_64 -> V_62 -= V_64 -> V_111 ;
}
V_23:
F_102 ( V_59 ) ;
}
void F_157 ( struct V_70 * V_71 , int V_108 )
{
struct V_5 * V_5 , * V_94 ;
F_158 (page, next, list, lru) {
F_159 ( V_5 , V_108 ) ;
F_154 ( V_5 , V_108 ) ;
}
}
void F_160 ( struct V_5 * V_5 , unsigned int V_30 )
{
int V_31 ;
F_42 ( F_65 ( V_5 ) ) ;
F_42 ( ! F_61 ( V_5 ) ) ;
#ifdef F_161
if ( F_162 ( V_5 ) )
F_160 ( F_163 ( V_5 [ 0 ] . V_123 ) , V_30 ) ;
#endif
for ( V_31 = 1 ; V_31 < ( 1 << V_30 ) ; V_31 ++ )
F_106 ( V_5 + V_31 ) ;
}
static int F_164 ( struct V_5 * V_5 , unsigned int V_30 )
{
unsigned long V_124 ;
struct V_11 * V_11 ;
int V_74 ;
F_120 ( ! F_62 ( V_5 ) ) ;
V_11 = F_17 ( V_5 ) ;
V_74 = F_100 ( V_5 ) ;
if ( ! F_87 ( V_74 ) ) {
V_124 = F_165 ( V_11 ) + ( 1 << V_30 ) ;
if ( ! F_166 ( V_11 , 0 , V_124 , 0 , 0 ) )
return 0 ;
F_66 ( V_11 , - ( 1UL << V_30 ) , V_74 ) ;
}
F_67 ( & V_5 -> V_51 ) ;
V_11 -> V_52 [ V_30 ] . V_53 -- ;
F_54 ( V_5 ) ;
if ( V_30 >= V_84 - 1 ) {
struct V_5 * V_125 = V_5 + ( 1 << V_30 ) - 1 ;
for (; V_5 < V_125 ; V_5 += V_82 ) {
int V_74 = F_100 ( V_5 ) ;
if ( ! F_87 ( V_74 ) && ! F_84 ( V_74 ) )
F_6 ( V_5 ,
V_122 ) ;
}
}
return 1UL << V_30 ;
}
int F_167 ( struct V_5 * V_5 )
{
unsigned int V_30 ;
int V_32 ;
V_30 = F_60 ( V_5 ) ;
V_32 = F_164 ( V_5 , V_30 ) ;
if ( ! V_32 )
return 0 ;
F_106 ( V_5 ) ;
F_160 ( V_5 , V_30 ) ;
return V_32 ;
}
static inline
struct V_5 * F_168 ( struct V_11 * V_126 ,
struct V_11 * V_11 , int V_30 , T_1 V_36 ,
int V_6 )
{
unsigned long V_59 ;
struct V_5 * V_5 ;
int V_108 = ! ! ( V_36 & V_127 ) ;
V_128:
if ( F_81 ( V_30 == 0 ) ) {
struct V_63 * V_64 ;
struct V_70 * V_71 ;
F_98 ( V_59 ) ;
V_64 = & F_156 ( V_11 -> V_115 ) -> V_64 ;
V_71 = & V_64 -> V_73 [ V_6 ] ;
if ( F_77 ( V_71 ) ) {
V_64 -> V_62 += F_131 ( V_11 , 0 ,
V_64 -> V_111 , V_71 ,
V_6 , V_108 ) ;
if ( F_7 ( F_77 ( V_71 ) ) )
goto V_129;
}
if ( V_108 )
V_5 = F_78 ( V_71 -> V_75 , struct V_5 , V_51 ) ;
else
V_5 = F_78 ( V_71 -> V_94 , struct V_5 , V_51 ) ;
F_67 ( & V_5 -> V_51 ) ;
V_64 -> V_62 -- ;
} else {
if ( F_7 ( V_36 & V_130 ) ) {
F_169 ( V_30 > 1 ) ;
}
F_145 ( & V_11 -> V_67 , V_59 ) ;
V_5 = F_129 ( V_11 , V_30 , V_6 ) ;
F_85 ( & V_11 -> V_67 ) ;
if ( ! V_5 )
goto V_129;
F_66 ( V_11 , - ( 1 << V_30 ) ,
F_100 ( V_5 ) ) ;
}
F_170 ( V_131 , V_11 , 1 << V_30 ) ;
F_171 ( V_126 , V_11 , V_36 ) ;
F_102 ( V_59 ) ;
F_42 ( F_18 ( V_11 , V_5 ) ) ;
if ( F_115 ( V_5 , V_30 , V_36 ) )
goto V_128;
return V_5 ;
V_129:
F_102 ( V_59 ) ;
return NULL ;
}
static int T_2 F_172 ( char * V_132 )
{
return F_173 ( & V_133 . V_134 , V_132 ) ;
}
static bool F_174 ( T_1 V_135 , unsigned int V_30 )
{
if ( V_30 < V_133 . V_136 )
return false ;
if ( V_135 & V_130 )
return false ;
if ( V_133 . V_137 && ( V_135 & V_37 ) )
return false ;
if ( V_133 . V_138 && ( V_135 & V_139 ) )
return false ;
return F_175 ( & V_133 . V_134 , 1 << V_30 ) ;
}
static int T_2 F_176 ( void )
{
T_5 V_140 = V_141 | V_142 | V_143 ;
struct V_144 * V_145 ;
V_145 = F_177 ( L_6 , NULL ,
& V_133 . V_134 ) ;
if ( F_178 ( V_145 ) )
return F_179 ( V_145 ) ;
if ( ! F_180 ( L_7 , V_140 , V_145 ,
& V_133 . V_138 ) )
goto V_146;
if ( ! F_180 ( L_8 , V_140 , V_145 ,
& V_133 . V_137 ) )
goto V_146;
if ( ! F_181 ( L_9 , V_140 , V_145 ,
& V_133 . V_136 ) )
goto V_146;
return 0 ;
V_146:
F_182 ( V_145 ) ;
return - V_147 ;
}
static inline bool F_174 ( T_1 V_135 , unsigned int V_30 )
{
return false ;
}
static bool F_183 ( struct V_11 * V_148 , int V_30 , unsigned long V_149 ,
int V_150 , int V_151 , long V_152 )
{
long V_153 = V_149 ;
long V_154 = V_148 -> V_154 [ V_150 ] ;
int V_155 ;
long V_156 = 0 ;
V_152 -= ( 1 << V_30 ) - 1 ;
if ( V_151 & V_157 )
V_153 -= V_153 / 2 ;
if ( V_151 & V_158 )
V_153 -= V_153 / 4 ;
#ifdef V_109
if ( ! ( V_151 & V_159 ) )
V_156 = F_184 ( V_148 , V_77 ) ;
#endif
if ( V_152 - V_156 <= V_153 + V_154 )
return false ;
for ( V_155 = 0 ; V_155 < V_30 ; V_155 ++ ) {
V_152 -= V_148 -> V_52 [ V_155 ] . V_53 << V_155 ;
V_153 >>= 1 ;
if ( V_152 <= V_153 )
return false ;
}
return true ;
}
bool F_166 ( struct V_11 * V_148 , int V_30 , unsigned long V_149 ,
int V_150 , int V_151 )
{
return F_183 ( V_148 , V_30 , V_149 , V_150 , V_151 ,
F_184 ( V_148 , V_76 ) ) ;
}
bool F_185 ( struct V_11 * V_148 , int V_30 , unsigned long V_149 ,
int V_150 , int V_151 )
{
long V_152 = F_184 ( V_148 , V_76 ) ;
if ( V_148 -> V_160 && V_152 < V_148 -> V_160 )
V_152 = F_186 ( V_148 , V_76 ) ;
return F_183 ( V_148 , V_30 , V_149 , V_150 , V_151 ,
V_152 ) ;
}
static T_6 * F_187 ( struct V_161 * V_161 , int V_151 )
{
struct V_162 * V_163 ;
T_6 * V_164 ;
V_163 = V_161 -> V_165 ;
if ( ! V_163 )
return NULL ;
if ( F_188 ( V_22 , V_163 -> V_166 + V_25 ) ) {
F_189 ( V_163 -> V_167 , V_168 ) ;
V_163 -> V_166 = V_22 ;
}
V_164 = ! F_43 () && ( V_151 & V_169 ) ?
& V_170 :
& V_171 [ V_172 ] ;
return V_164 ;
}
static int F_190 ( struct V_161 * V_161 , struct V_173 * V_148 ,
T_6 * V_164 )
{
struct V_162 * V_163 ;
int V_31 ;
int V_174 ;
V_163 = V_161 -> V_165 ;
if ( ! V_163 )
return 1 ;
V_31 = V_148 - V_161 -> V_175 ;
V_174 = V_163 -> V_176 [ V_31 ] ;
return F_191 ( V_174 , * V_164 ) && ! F_192 ( V_31 , V_163 -> V_167 ) ;
}
static void F_193 ( struct V_161 * V_161 , struct V_173 * V_148 )
{
struct V_162 * V_163 ;
int V_31 ;
V_163 = V_161 -> V_165 ;
if ( ! V_163 )
return;
V_31 = V_148 - V_161 -> V_175 ;
F_194 ( V_31 , V_163 -> V_167 ) ;
}
static void F_195 ( struct V_161 * V_161 )
{
struct V_162 * V_163 ;
V_163 = V_161 -> V_165 ;
if ( ! V_163 )
return;
F_189 ( V_163 -> V_167 , V_168 ) ;
}
static bool F_196 ( struct V_11 * V_177 , struct V_11 * V_11 )
{
return F_191 ( V_177 -> V_178 , V_11 -> V_179 -> V_180 ) ;
}
static void T_7 F_197 ( int V_181 )
{
int V_31 ;
F_198 (i)
if ( F_199 ( V_181 , V_31 ) <= V_182 )
F_200 ( V_31 , F_201 ( V_181 ) -> V_180 ) ;
else
V_183 = 1 ;
}
static T_6 * F_187 ( struct V_161 * V_161 , int V_151 )
{
return NULL ;
}
static int F_190 ( struct V_161 * V_161 , struct V_173 * V_148 ,
T_6 * V_164 )
{
return 1 ;
}
static void F_193 ( struct V_161 * V_161 , struct V_173 * V_148 )
{
}
static void F_195 ( struct V_161 * V_161 )
{
}
static bool F_196 ( struct V_11 * V_177 , struct V_11 * V_11 )
{
return true ;
}
static inline void F_197 ( int V_181 )
{
}
static struct V_5 *
F_202 ( T_1 V_135 , T_6 * V_184 , unsigned int V_30 ,
struct V_161 * V_161 , int V_185 , int V_151 ,
struct V_11 * V_126 , int V_6 )
{
struct V_173 * V_148 ;
struct V_5 * V_5 = NULL ;
int V_150 ;
struct V_11 * V_11 ;
T_6 * V_164 = NULL ;
int V_186 = 0 ;
int V_187 = 0 ;
V_150 = F_203 ( V_126 ) ;
V_188:
F_204 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( F_132 ( V_189 ) && V_186 &&
! F_190 ( V_161 , V_148 , V_164 ) )
continue;
if ( ( V_151 & V_169 ) &&
! F_205 ( V_11 , V_135 ) )
continue;
if ( ( V_151 & V_190 ) &&
( V_135 & V_191 ) && ! F_206 ( V_11 ) )
goto V_192;
F_207 ( V_193 < V_194 ) ;
if ( ! ( V_151 & V_193 ) ) {
unsigned long V_149 ;
int V_12 ;
V_149 = V_11 -> V_124 [ V_151 & V_195 ] ;
if ( F_166 ( V_11 , V_30 , V_149 ,
V_150 , V_151 ) )
goto V_196;
if ( F_132 ( V_189 ) &&
! V_187 && V_197 > 1 ) {
V_164 = F_187 ( V_161 , V_151 ) ;
V_186 = 1 ;
V_187 = 1 ;
}
if ( V_183 == 0 ||
! F_196 ( V_126 , V_11 ) )
goto V_192;
if ( F_132 ( V_189 ) && V_186 &&
! F_190 ( V_161 , V_148 , V_164 ) )
continue;
V_12 = F_208 ( V_11 , V_135 , V_30 ) ;
switch ( V_12 ) {
case V_198 :
continue;
case V_199 :
continue;
default:
if ( F_166 ( V_11 , V_30 , V_149 ,
V_150 , V_151 ) )
goto V_196;
if ( ( ( V_151 & V_195 ) == V_200 ) ||
V_12 == V_201 )
goto V_192;
continue;
}
}
V_196:
V_5 = F_168 ( V_126 , V_11 , V_30 ,
V_135 , V_6 ) ;
if ( V_5 )
break;
V_192:
if ( F_132 ( V_189 ) )
F_193 ( V_161 , V_148 ) ;
}
if ( F_7 ( F_132 ( V_189 ) && V_5 == NULL && V_186 ) ) {
V_186 = 0 ;
goto V_188;
}
if ( V_5 )
V_5 -> V_202 = ! ! ( V_151 & V_193 ) ;
return V_5 ;
}
static inline bool F_209 ( void )
{
bool V_12 = false ;
#if V_203 > 8
V_12 = F_43 () ;
#endif
return V_12 ;
}
void F_210 ( T_1 V_135 , int V_30 , const char * V_204 , ... )
{
unsigned int V_205 = V_206 ;
if ( ( V_135 & V_207 ) || ! F_211 ( & V_208 ) ||
F_112 () > 0 )
return;
if ( ! ( V_135 & V_139 ) )
V_205 |= V_209 ;
if ( ! ( V_135 & V_210 ) )
if ( F_212 ( V_211 ) ||
( V_26 -> V_59 & ( V_212 | V_213 ) ) )
V_205 &= ~ V_206 ;
if ( F_43 () || ! ( V_135 & V_139 ) )
V_205 &= ~ V_206 ;
if ( V_204 ) {
struct V_214 V_215 ;
T_8 args ;
va_start ( args , V_204 ) ;
V_215 . V_204 = V_204 ;
V_215 . V_216 = & args ;
F_213 ( L_10 , & V_215 ) ;
va_end ( args ) ;
}
F_213 ( L_11 ,
V_26 -> V_27 , V_30 , V_135 ) ;
F_26 () ;
if ( ! F_209 () )
F_214 ( V_205 ) ;
}
static inline int
F_215 ( T_1 V_135 , unsigned int V_30 ,
unsigned long V_217 ,
unsigned long V_218 )
{
if ( V_135 & V_219 )
return 0 ;
if ( V_135 & V_130 )
return 1 ;
if ( ! V_217 && F_5 () )
return 0 ;
if ( V_30 <= V_220 )
return 1 ;
if ( V_135 & V_221 && V_218 < ( 1 << V_30 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_216 ( T_1 V_135 , unsigned int V_30 ,
struct V_161 * V_161 , enum V_222 V_185 ,
T_6 * V_184 , struct V_11 * V_126 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_217 ( V_161 , V_135 ) ) {
F_218 ( 1 ) ;
return NULL ;
}
V_5 = F_202 ( V_135 | V_223 , V_184 ,
V_30 , V_161 , V_185 ,
V_224 | V_169 ,
V_126 , V_6 ) ;
if ( V_5 )
goto V_23;
if ( ! ( V_135 & V_130 ) ) {
if ( V_30 > V_220 )
goto V_23;
if ( V_185 < V_225 )
goto V_23;
if ( V_135 & V_226 )
goto V_23;
}
F_219 ( V_161 , V_135 , V_30 , V_184 , false ) ;
V_23:
F_220 ( V_161 , V_135 ) ;
return V_5 ;
}
static struct V_5 *
F_221 ( T_1 V_135 , unsigned int V_30 ,
struct V_161 * V_161 , enum V_222 V_185 ,
T_6 * V_184 , int V_151 , struct V_11 * V_126 ,
int V_6 , bool V_227 ,
bool * V_228 , bool * V_229 ,
unsigned long * V_217 )
{
if ( ! V_30 )
return NULL ;
if ( F_222 ( V_126 , V_30 ) ) {
* V_229 = true ;
return NULL ;
}
V_26 -> V_59 |= V_212 ;
* V_217 = F_223 ( V_161 , V_30 , V_135 ,
V_184 , V_227 ,
V_228 ) ;
V_26 -> V_59 &= ~ V_212 ;
if ( * V_217 != V_230 ) {
struct V_5 * V_5 ;
F_134 ( F_224 () ) ;
F_225 () ;
V_5 = F_202 ( V_135 , V_184 ,
V_30 , V_161 , V_185 ,
V_151 & ~ V_193 ,
V_126 , V_6 ) ;
if ( V_5 ) {
V_126 -> V_231 = false ;
V_126 -> V_232 = 0 ;
V_126 -> V_233 = 0 ;
if ( V_30 >= V_126 -> V_234 )
V_126 -> V_234 = V_30 + 1 ;
F_226 ( V_235 ) ;
return V_5 ;
}
F_226 ( V_236 ) ;
if ( V_227 )
F_227 ( V_126 , V_30 ) ;
F_228 () ;
}
return NULL ;
}
static inline struct V_5 *
F_221 ( T_1 V_135 , unsigned int V_30 ,
struct V_161 * V_161 , enum V_222 V_185 ,
T_6 * V_184 , int V_151 , struct V_11 * V_126 ,
int V_6 , bool V_227 ,
bool * V_228 , bool * V_229 ,
unsigned long * V_217 )
{
return NULL ;
}
static int
F_229 ( T_1 V_135 , unsigned int V_30 , struct V_161 * V_161 ,
T_6 * V_184 )
{
struct V_237 V_237 ;
int V_238 ;
F_228 () ;
F_230 () ;
V_26 -> V_59 |= V_212 ;
F_231 ( V_135 ) ;
V_237 . V_239 = 0 ;
V_26 -> V_237 = & V_237 ;
V_238 = F_232 ( V_161 , V_30 , V_135 , V_184 ) ;
V_26 -> V_237 = NULL ;
F_233 () ;
V_26 -> V_59 &= ~ V_212 ;
F_228 () ;
return V_238 ;
}
static inline struct V_5 *
F_234 ( T_1 V_135 , unsigned int V_30 ,
struct V_161 * V_161 , enum V_222 V_185 ,
T_6 * V_184 , int V_151 , struct V_11 * V_126 ,
int V_6 , unsigned long * V_217 )
{
struct V_5 * V_5 = NULL ;
bool V_240 = false ;
* V_217 = F_229 ( V_135 , V_30 , V_161 ,
V_184 ) ;
if ( F_7 ( ! ( * V_217 ) ) )
return NULL ;
if ( F_132 ( V_189 ) )
F_195 ( V_161 ) ;
V_241:
V_5 = F_202 ( V_135 , V_184 , V_30 ,
V_161 , V_185 ,
V_151 & ~ V_193 ,
V_126 , V_6 ) ;
if ( ! V_5 && ! V_240 ) {
F_139 () ;
V_240 = true ;
goto V_241;
}
return V_5 ;
}
static inline struct V_5 *
F_235 ( T_1 V_135 , unsigned int V_30 ,
struct V_161 * V_161 , enum V_222 V_185 ,
T_6 * V_184 , struct V_11 * V_126 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_202 ( V_135 , V_184 , V_30 ,
V_161 , V_185 , V_193 ,
V_126 , V_6 ) ;
if ( ! V_5 && V_135 & V_130 )
F_236 ( V_126 , V_242 , V_25 / 50 ) ;
} while ( ! V_5 && ( V_135 & V_130 ) );
return V_5 ;
}
static inline
void F_237 ( unsigned int V_30 , struct V_161 * V_161 ,
enum V_222 V_185 ,
enum V_222 V_150 )
{
struct V_173 * V_148 ;
struct V_11 * V_11 ;
F_238 (zone, z, zonelist, high_zoneidx)
F_239 ( V_11 , V_30 , V_150 ) ;
}
static inline int
F_240 ( T_1 V_135 )
{
int V_151 = V_200 | V_169 ;
const T_1 V_243 = V_135 & V_139 ;
F_207 ( V_244 != ( V_245 T_1 ) V_157 ) ;
V_151 |= ( V_245 int ) ( V_135 & V_244 ) ;
if ( ! V_243 ) {
if ( ! ( V_135 & V_210 ) )
V_151 |= V_158 ;
V_151 &= ~ V_169 ;
} else if ( F_7 ( F_241 ( V_26 ) ) && ! F_43 () )
V_151 |= V_158 ;
if ( F_81 ( ! ( V_135 & V_210 ) ) ) {
if ( V_135 & V_246 )
V_151 |= V_193 ;
else if ( F_242 () && ( V_26 -> V_59 & V_212 ) )
V_151 |= V_193 ;
else if ( ! F_43 () &&
( ( V_26 -> V_59 & V_212 ) ||
F_7 ( F_212 ( V_211 ) ) ) )
V_151 |= V_193 ;
}
#ifdef V_109
if ( F_243 ( V_135 ) == V_122 )
V_151 |= V_159 ;
#endif
return V_151 ;
}
bool F_244 ( T_1 V_135 )
{
return ! ! ( F_240 ( V_135 ) & V_193 ) ;
}
static inline struct V_5 *
F_245 ( T_1 V_135 , unsigned int V_30 ,
struct V_161 * V_161 , enum V_222 V_185 ,
T_6 * V_184 , struct V_11 * V_126 ,
int V_6 )
{
const T_1 V_243 = V_135 & V_139 ;
struct V_5 * V_5 = NULL ;
int V_151 ;
unsigned long V_218 = 0 ;
unsigned long V_217 ;
bool V_227 = false ;
bool V_229 = false ;
bool V_228 = false ;
if ( V_30 >= V_40 ) {
F_169 ( ! ( V_135 & V_207 ) ) ;
return NULL ;
}
if ( F_132 ( V_189 ) &&
( V_135 & V_247 ) == V_247 )
goto V_248;
V_249:
if ( ! ( V_135 & V_250 ) )
F_237 ( V_30 , V_161 , V_185 ,
F_203 ( V_126 ) ) ;
V_151 = F_240 ( V_135 ) ;
if ( ! ( V_151 & V_169 ) && ! V_184 )
F_246 ( V_161 , V_185 , NULL ,
& V_126 ) ;
V_251:
V_5 = F_202 ( V_135 , V_184 , V_30 , V_161 ,
V_185 , V_151 & ~ V_193 ,
V_126 , V_6 ) ;
if ( V_5 )
goto V_252;
if ( V_151 & V_193 ) {
V_161 = F_247 ( F_248 () , V_135 ) ;
V_5 = F_235 ( V_135 , V_30 ,
V_161 , V_185 , V_184 ,
V_126 , V_6 ) ;
if ( V_5 ) {
goto V_252;
}
}
if ( ! V_243 )
goto V_248;
if ( V_26 -> V_59 & V_212 )
goto V_248;
if ( F_212 ( V_211 ) && ! ( V_135 & V_130 ) )
goto V_248;
V_5 = F_221 ( V_135 , V_30 ,
V_161 , V_185 ,
V_184 ,
V_151 , V_126 ,
V_6 , V_227 ,
& V_228 ,
& V_229 ,
& V_217 ) ;
if ( V_5 )
goto V_252;
V_227 = true ;
if ( ( V_229 || V_228 ) &&
( V_135 & V_250 ) )
goto V_248;
V_5 = F_234 ( V_135 , V_30 ,
V_161 , V_185 ,
V_184 ,
V_151 , V_126 ,
V_6 , & V_217 ) ;
if ( V_5 )
goto V_252;
if ( ! V_217 ) {
if ( ( V_135 & V_253 ) && ! ( V_135 & V_219 ) ) {
if ( V_254 )
goto V_248;
if ( ( V_26 -> V_59 & V_255 ) &&
! ( V_135 & V_130 ) )
goto V_248;
V_5 = F_216 ( V_135 , V_30 ,
V_161 , V_185 ,
V_184 , V_126 ,
V_6 ) ;
if ( V_5 )
goto V_252;
if ( ! ( V_135 & V_130 ) ) {
if ( V_30 > V_220 )
goto V_248;
if ( V_185 < V_225 )
goto V_248;
}
goto V_249;
}
}
V_218 += V_217 ;
if ( F_215 ( V_135 , V_30 , V_217 ,
V_218 ) ) {
F_236 ( V_126 , V_242 , V_25 / 50 ) ;
goto V_251;
} else {
V_5 = F_221 ( V_135 , V_30 ,
V_161 , V_185 ,
V_184 ,
V_151 , V_126 ,
V_6 , V_227 ,
& V_228 ,
& V_229 ,
& V_217 ) ;
if ( V_5 )
goto V_252;
}
V_248:
F_210 ( V_135 , V_30 , NULL ) ;
return V_5 ;
V_252:
if ( V_256 )
F_249 ( V_5 , V_30 , V_135 ) ;
return V_5 ;
}
struct V_5 *
F_250 ( T_1 V_135 , unsigned int V_30 ,
struct V_161 * V_161 , T_6 * V_184 )
{
enum V_222 V_185 = F_251 ( V_135 ) ;
struct V_11 * V_126 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_243 ( V_135 ) ;
unsigned int V_257 ;
int V_151 = V_190 | V_169 ;
struct V_258 * V_259 = NULL ;
V_135 &= V_3 ;
F_252 ( V_135 ) ;
F_253 ( V_135 & V_139 ) ;
if ( F_174 ( V_135 , V_30 ) )
return NULL ;
if ( F_7 ( ! V_161 -> V_175 -> V_11 ) )
return NULL ;
if ( ! F_254 ( V_135 , & V_259 , V_30 ) )
return NULL ;
V_260:
V_257 = F_255 () ;
F_246 ( V_161 , V_185 ,
V_184 ? : & V_170 ,
& V_126 ) ;
if ( ! V_126 )
goto V_23;
#ifdef V_109
if ( F_243 ( V_135 ) == V_122 )
V_151 |= V_159 ;
#endif
V_5 = F_202 ( V_135 | V_223 , V_184 , V_30 ,
V_161 , V_185 , V_151 ,
V_126 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
V_135 = F_256 ( V_135 ) ;
V_5 = F_245 ( V_135 , V_30 ,
V_161 , V_185 , V_184 ,
V_126 , V_6 ) ;
}
F_257 ( V_5 , V_30 , V_135 , V_6 ) ;
V_23:
if ( F_7 ( ! F_258 ( V_257 ) && ! V_5 ) )
goto V_260;
F_259 ( V_5 , V_259 , V_30 ) ;
return V_5 ;
}
unsigned long F_260 ( T_1 V_135 , unsigned int V_30 )
{
struct V_5 * V_5 ;
F_42 ( ( V_135 & V_37 ) != 0 ) ;
V_5 = F_261 ( V_135 , V_30 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_94 ( V_5 ) ;
}
unsigned long F_262 ( T_1 V_135 )
{
return F_260 ( V_135 | V_91 , 0 ) ;
}
void F_107 ( struct V_5 * V_5 , unsigned int V_30 )
{
if ( F_263 ( V_5 ) ) {
if ( V_30 == 0 )
F_154 ( V_5 , 0 ) ;
else
F_29 ( V_5 , V_30 ) ;
}
}
void V_152 ( unsigned long V_261 , unsigned int V_30 )
{
if ( V_261 != 0 ) {
F_42 ( ! F_264 ( ( void * ) V_261 ) ) ;
F_107 ( F_163 ( ( void * ) V_261 ) , V_30 ) ;
}
}
void F_265 ( struct V_5 * V_5 , unsigned int V_30 )
{
F_266 ( V_5 , V_30 ) ;
F_107 ( V_5 , V_30 ) ;
}
void F_267 ( unsigned long V_261 , unsigned int V_30 )
{
if ( V_261 != 0 ) {
F_42 ( ! F_264 ( ( void * ) V_261 ) ) ;
F_265 ( F_163 ( ( void * ) V_261 ) , V_30 ) ;
}
}
static void * F_268 ( unsigned long V_261 , unsigned V_30 , T_9 V_90 )
{
if ( V_261 ) {
unsigned long V_262 = V_261 + ( V_78 << V_30 ) ;
unsigned long V_263 = V_261 + F_269 ( V_90 ) ;
F_160 ( F_163 ( ( void * ) V_261 ) , V_30 ) ;
while ( V_263 < V_262 ) {
F_270 ( V_263 ) ;
V_263 += V_78 ;
}
}
return ( void * ) V_261 ;
}
void * F_271 ( T_9 V_90 , T_1 V_135 )
{
unsigned int V_30 = F_272 ( V_90 ) ;
unsigned long V_261 ;
V_261 = F_260 ( V_135 , V_30 ) ;
return F_268 ( V_261 , V_30 , V_90 ) ;
}
void * F_273 ( int V_181 , T_9 V_90 , T_1 V_135 )
{
unsigned V_30 = F_272 ( V_90 ) ;
struct V_5 * V_33 = F_274 ( V_181 , V_135 , V_30 ) ;
if ( ! V_33 )
return NULL ;
return F_268 ( ( unsigned long ) F_94 ( V_33 ) , V_30 , V_90 ) ;
}
void F_275 ( void * V_264 , T_9 V_90 )
{
unsigned long V_261 = ( unsigned long ) V_264 ;
unsigned long V_265 = V_261 + F_269 ( V_90 ) ;
while ( V_261 < V_265 ) {
F_270 ( V_261 ) ;
V_261 += V_78 ;
}
}
static unsigned long F_276 ( int V_266 )
{
struct V_173 * V_148 ;
struct V_11 * V_11 ;
unsigned long V_267 = 0 ;
struct V_161 * V_161 = F_247 ( F_248 () , V_268 ) ;
F_238 (zone, z, zonelist, offset) {
unsigned long V_90 = V_11 -> V_81 ;
unsigned long V_88 = F_277 ( V_11 ) ;
if ( V_90 > V_88 )
V_267 += V_90 - V_88 ;
}
return V_267 ;
}
unsigned long F_278 ( void )
{
return F_276 ( F_251 ( V_269 ) ) ;
}
unsigned long F_279 ( void )
{
return F_276 ( F_251 ( V_270 ) ) ;
}
static inline void F_280 ( struct V_11 * V_11 )
{
if ( F_132 ( V_189 ) )
F_23 ( L_12 , F_122 ( V_11 ) ) ;
}
void F_281 ( struct V_271 * V_272 )
{
V_272 -> V_273 = V_85 ;
V_272 -> V_274 = 0 ;
V_272 -> V_275 = F_282 ( V_76 ) ;
V_272 -> V_276 = F_283 () ;
V_272 -> V_277 = V_86 ;
V_272 -> V_278 = F_284 () ;
V_272 -> V_279 = V_78 ;
}
void F_285 ( struct V_271 * V_272 , int V_181 )
{
T_10 * V_280 = F_201 ( V_181 ) ;
V_272 -> V_273 = V_280 -> V_281 ;
V_272 -> V_275 = F_286 ( V_181 , V_76 ) ;
#ifdef F_109
V_272 -> V_277 = V_280 -> V_282 [ V_283 ] . V_81 ;
V_272 -> V_278 = F_184 ( & V_280 -> V_282 [ V_283 ] ,
V_76 ) ;
#else
V_272 -> V_277 = 0 ;
V_272 -> V_278 = 0 ;
#endif
V_272 -> V_279 = V_78 ;
}
bool F_287 ( unsigned int V_59 , int V_181 )
{
bool V_12 = false ;
unsigned int V_257 ;
if ( ! ( V_59 & V_206 ) )
goto V_23;
do {
V_257 = F_255 () ;
V_12 = ! F_191 ( V_181 , V_170 ) ;
} while ( ! F_258 ( V_257 ) );
V_23:
return V_12 ;
}
static void F_288 ( unsigned char type )
{
static const char V_284 [ V_285 ] = {
[ V_8 ] = 'U' ,
[ V_105 ] = 'E' ,
[ V_122 ] = 'M' ,
[ V_104 ] = 'R' ,
#ifdef V_109
[ V_83 ] = 'C' ,
#endif
#ifdef F_289
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
void F_290 ( unsigned int V_205 )
{
int V_112 ;
struct V_11 * V_11 ;
F_135 (zone) {
if ( F_287 ( V_205 , F_122 ( V_11 ) ) )
continue;
F_280 ( V_11 ) ;
F_23 ( L_14 , V_11 -> V_288 ) ;
F_140 (cpu) {
struct V_113 * V_115 ;
V_115 = F_136 ( V_11 -> V_115 , V_112 ) ;
F_23 ( L_15 ,
V_112 , V_115 -> V_64 . V_88 ,
V_115 -> V_64 . V_111 , V_115 -> V_64 . V_62 ) ;
}
}
F_23 ( L_16
L_17
L_18
L_19
L_20
L_21
L_22 ,
F_282 ( V_289 ) ,
F_282 ( V_290 ) ,
F_282 ( V_291 ) ,
F_282 ( V_292 ) ,
F_282 ( V_293 ) ,
F_282 ( V_294 ) ,
F_282 ( V_295 ) ,
F_282 ( V_296 ) ,
F_282 ( V_297 ) ,
F_282 ( V_298 ) ,
F_282 ( V_76 ) ,
F_282 ( V_299 ) ,
F_282 ( V_300 ) ,
F_282 ( V_301 ) ,
F_282 ( V_302 ) ,
F_282 ( V_303 ) ,
F_282 ( V_304 ) ,
F_282 ( V_77 ) ) ;
F_135 (zone) {
int V_31 ;
if ( F_287 ( V_205 , F_122 ( V_11 ) ) )
continue;
F_280 ( V_11 ) ;
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
F_291 ( F_184 ( V_11 , V_76 ) ) ,
F_291 ( F_292 ( V_11 ) ) ,
F_291 ( F_165 ( V_11 ) ) ,
F_291 ( F_277 ( V_11 ) ) ,
F_291 ( F_184 ( V_11 , V_289 ) ) ,
F_291 ( F_184 ( V_11 , V_290 ) ) ,
F_291 ( F_184 ( V_11 , V_292 ) ) ,
F_291 ( F_184 ( V_11 , V_293 ) ) ,
F_291 ( F_184 ( V_11 , V_295 ) ) ,
F_291 ( F_184 ( V_11 , V_291 ) ) ,
F_291 ( F_184 ( V_11 , V_294 ) ) ,
F_291 ( V_11 -> V_305 ) ,
F_291 ( V_11 -> V_81 ) ,
F_291 ( F_184 ( V_11 , V_306 ) ) ,
F_291 ( F_184 ( V_11 , V_296 ) ) ,
F_291 ( F_184 ( V_11 , V_297 ) ) ,
F_291 ( F_184 ( V_11 , V_301 ) ) ,
F_291 ( F_184 ( V_11 , V_302 ) ) ,
F_291 ( F_184 ( V_11 , V_299 ) ) ,
F_291 ( F_184 ( V_11 , V_300 ) ) ,
F_184 ( V_11 , V_307 ) *
V_308 / 1024 ,
F_291 ( F_184 ( V_11 , V_303 ) ) ,
F_291 ( F_184 ( V_11 , V_298 ) ) ,
F_291 ( F_184 ( V_11 , V_304 ) ) ,
F_291 ( F_184 ( V_11 , V_77 ) ) ,
F_291 ( F_184 ( V_11 , V_309 ) ) ,
V_11 -> V_69 ,
( V_11 -> V_68 ? L_53 : L_54 )
) ;
F_23 ( L_55 ) ;
for ( V_31 = 0 ; V_31 < V_310 ; V_31 ++ )
F_23 ( L_56 , V_11 -> V_154 [ V_31 ] ) ;
F_23 ( L_52 ) ;
}
F_135 (zone) {
unsigned long V_311 [ V_40 ] , V_59 , V_30 , V_312 = 0 ;
unsigned char V_284 [ V_40 ] ;
if ( F_287 ( V_205 , F_122 ( V_11 ) ) )
continue;
F_280 ( V_11 ) ;
F_23 ( L_57 , V_11 -> V_288 ) ;
F_145 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
struct V_52 * V_89 = & V_11 -> V_52 [ V_30 ] ;
int type ;
V_311 [ V_30 ] = V_89 -> V_53 ;
V_312 += V_311 [ V_30 ] << V_30 ;
V_284 [ V_30 ] = 0 ;
for ( type = 0 ; type < V_285 ; type ++ ) {
if ( ! F_77 ( & V_89 -> V_56 [ type ] ) )
V_284 [ V_30 ] |= 1 << type ;
}
}
F_153 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
F_23 ( L_58 , V_311 [ V_30 ] , F_291 ( 1UL ) << V_30 ) ;
if ( V_311 [ V_30 ] )
F_288 ( V_284 [ V_30 ] ) ;
}
F_23 ( L_59 , F_291 ( V_312 ) ) ;
}
F_293 () ;
F_23 ( L_60 , F_282 ( V_313 ) ) ;
F_294 () ;
}
static void F_295 ( struct V_11 * V_11 , struct V_173 * V_173 )
{
V_173 -> V_11 = V_11 ;
V_173 -> F_203 = F_203 ( V_11 ) ;
}
static int F_296 ( T_10 * V_280 , struct V_161 * V_161 ,
int V_314 , enum V_222 V_222 )
{
struct V_11 * V_11 ;
F_120 ( V_222 >= V_310 ) ;
V_222 ++ ;
do {
V_222 -- ;
V_11 = V_280 -> V_282 + V_222 ;
if ( F_297 ( V_11 ) ) {
F_295 ( V_11 ,
& V_161 -> V_175 [ V_314 ++ ] ) ;
F_298 ( V_222 ) ;
}
} while ( V_222 );
return V_314 ;
}
static int F_299 ( char * V_315 )
{
if ( * V_315 == 'd' || * V_315 == 'D' ) {
V_316 = V_317 ;
} else if ( * V_315 == 'n' || * V_315 == 'N' ) {
V_316 = V_318 ;
} else if ( * V_315 == 'z' || * V_315 == 'Z' ) {
V_316 = V_319 ;
} else {
F_23 ( V_320
L_61
L_62 , V_315 ) ;
return - V_321 ;
}
return 0 ;
}
static T_2 int F_300 ( char * V_315 )
{
int V_12 ;
if ( ! V_315 )
return 0 ;
V_12 = F_299 ( V_315 ) ;
if ( V_12 == 0 )
F_301 ( V_322 , V_315 , V_323 ) ;
return V_12 ;
}
int F_302 ( T_11 * V_324 , int V_325 ,
void T_12 * V_326 , T_9 * V_327 ,
T_13 * V_328 )
{
char V_329 [ V_323 ] ;
int V_12 ;
static F_303 ( V_330 ) ;
F_304 ( & V_330 ) ;
if ( V_325 )
strcpy ( V_329 , ( char * ) V_324 -> V_331 ) ;
V_12 = F_305 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( V_12 )
goto V_23;
if ( V_325 ) {
int V_332 = V_316 ;
if ( F_299 ( ( char * ) V_324 -> V_331 ) ) {
strncpy ( ( char * ) V_324 -> V_331 , V_329 ,
V_323 ) ;
V_316 = V_332 ;
} else if ( V_332 != V_316 ) {
F_304 ( & V_333 ) ;
F_306 ( NULL , NULL ) ;
F_307 ( & V_333 ) ;
}
}
V_23:
F_307 ( & V_330 ) ;
return V_12 ;
}
static int F_308 ( int V_178 , T_6 * V_334 )
{
int V_174 , V_272 ;
int V_335 = V_336 ;
int V_337 = V_338 ;
const struct V_339 * V_287 = F_309 ( 0 ) ;
if ( ! F_191 ( V_178 , * V_334 ) ) {
F_200 ( V_178 , * V_334 ) ;
return V_178 ;
}
F_310 (n, N_MEMORY) {
if ( F_191 ( V_174 , * V_334 ) )
continue;
V_272 = F_199 ( V_178 , V_174 ) ;
V_272 += ( V_174 < V_178 ) ;
V_287 = F_309 ( V_174 ) ;
if ( ! F_311 ( V_287 ) )
V_272 += V_340 ;
V_272 *= ( V_341 * V_342 ) ;
V_272 += V_343 [ V_174 ] ;
if ( V_272 < V_335 ) {
V_335 = V_272 ;
V_337 = V_174 ;
}
}
if ( V_337 >= 0 )
F_200 ( V_337 , * V_334 ) ;
return V_337 ;
}
static void F_312 ( T_10 * V_280 , int V_178 )
{
int V_344 ;
struct V_161 * V_161 ;
V_161 = & V_280 -> V_345 [ 0 ] ;
for ( V_344 = 0 ; V_161 -> V_175 [ V_344 ] . V_11 != NULL ; V_344 ++ )
;
V_344 = F_296 ( F_201 ( V_178 ) , V_161 , V_344 ,
V_310 - 1 ) ;
V_161 -> V_175 [ V_344 ] . V_11 = NULL ;
V_161 -> V_175 [ V_344 ] . F_203 = 0 ;
}
static void F_313 ( T_10 * V_280 )
{
int V_344 ;
struct V_161 * V_161 ;
V_161 = & V_280 -> V_345 [ 1 ] ;
V_344 = F_296 ( V_280 , V_161 , 0 , V_310 - 1 ) ;
V_161 -> V_175 [ V_344 ] . V_11 = NULL ;
V_161 -> V_175 [ V_344 ] . F_203 = 0 ;
}
static void F_314 ( T_10 * V_280 , int V_346 )
{
int V_347 , V_344 , V_178 ;
int V_222 ;
struct V_11 * V_148 ;
struct V_161 * V_161 ;
V_161 = & V_280 -> V_345 [ 0 ] ;
V_347 = 0 ;
for ( V_222 = V_310 - 1 ; V_222 >= 0 ; V_222 -- ) {
for ( V_344 = 0 ; V_344 < V_346 ; V_344 ++ ) {
V_178 = V_348 [ V_344 ] ;
V_148 = & F_201 ( V_178 ) -> V_282 [ V_222 ] ;
if ( F_297 ( V_148 ) ) {
F_295 ( V_148 ,
& V_161 -> V_175 [ V_347 ++ ] ) ;
F_298 ( V_222 ) ;
}
}
}
V_161 -> V_175 [ V_347 ] . V_11 = NULL ;
V_161 -> V_175 [ V_347 ] . F_203 = 0 ;
}
static int F_315 ( void )
{
int V_181 , V_222 ;
unsigned long V_349 , V_350 ;
struct V_11 * V_148 ;
int V_351 ;
V_349 = 0 ;
V_350 = 0 ;
F_198 (nid) {
for ( V_222 = 0 ; V_222 < V_310 ; V_222 ++ ) {
V_148 = & F_201 ( V_181 ) -> V_282 [ V_222 ] ;
if ( F_297 ( V_148 ) ) {
if ( V_222 < V_225 )
V_349 += V_148 -> V_305 ;
V_350 += V_148 -> V_305 ;
} else if ( V_222 == V_225 ) {
return V_318 ;
}
}
}
if ( ! V_349 ||
V_349 > V_350 / 2 )
return V_318 ;
V_351 = V_350 /
( F_316 ( V_171 [ V_172 ] ) + 1 ) ;
F_198 (nid) {
V_349 = 0 ;
V_350 = 0 ;
for ( V_222 = 0 ; V_222 < V_310 ; V_222 ++ ) {
V_148 = & F_201 ( V_181 ) -> V_282 [ V_222 ] ;
if ( F_297 ( V_148 ) ) {
if ( V_222 < V_225 )
V_349 += V_148 -> V_305 ;
V_350 += V_148 -> V_305 ;
}
}
if ( V_349 &&
V_350 > V_351 &&
V_349 > V_350 * 70 / 100 )
return V_318 ;
}
return V_319 ;
}
static void F_317 ( void )
{
if ( V_316 == V_317 )
V_352 = F_315 () ;
else
V_352 = V_316 ;
}
static void F_318 ( T_10 * V_280 )
{
int V_344 , V_178 , V_353 ;
enum V_222 V_31 ;
T_6 V_354 ;
int V_355 , V_356 ;
struct V_161 * V_161 ;
int V_30 = V_352 ;
for ( V_31 = 0 ; V_31 < V_357 ; V_31 ++ ) {
V_161 = V_280 -> V_345 + V_31 ;
V_161 -> V_175 [ 0 ] . V_11 = NULL ;
V_161 -> V_175 [ 0 ] . F_203 = 0 ;
}
V_355 = V_280 -> V_358 ;
V_353 = V_197 ;
V_356 = V_355 ;
F_319 ( V_354 ) ;
memset ( V_348 , 0 , sizeof( V_348 ) ) ;
V_344 = 0 ;
while ( ( V_178 = F_308 ( V_355 , & V_354 ) ) >= 0 ) {
if ( F_199 ( V_355 , V_178 ) !=
F_199 ( V_355 , V_356 ) )
V_343 [ V_178 ] = V_353 ;
V_356 = V_178 ;
V_353 -- ;
if ( V_30 == V_318 )
F_312 ( V_280 , V_178 ) ;
else
V_348 [ V_344 ++ ] = V_178 ;
}
if ( V_30 == V_319 ) {
F_314 ( V_280 , V_344 ) ;
}
F_313 ( V_280 ) ;
}
static void F_320 ( T_10 * V_280 )
{
struct V_161 * V_161 ;
struct V_162 * V_163 ;
struct V_173 * V_148 ;
V_161 = & V_280 -> V_345 [ 0 ] ;
V_161 -> V_165 = V_163 = & V_161 -> V_359 ;
F_189 ( V_163 -> V_167 , V_168 ) ;
for ( V_148 = V_161 -> V_175 ; V_148 -> V_11 ; V_148 ++ )
V_163 -> V_176 [ V_148 - V_161 -> V_175 ] = F_321 ( V_148 ) ;
}
int F_322 ( int V_178 )
{
struct V_11 * V_11 ;
( void ) F_246 ( F_247 ( V_178 , V_268 ) ,
F_251 ( V_268 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_178 ;
}
static void F_317 ( void )
{
V_352 = V_319 ;
}
static void F_318 ( T_10 * V_280 )
{
int V_178 , V_355 ;
enum V_222 V_344 ;
struct V_161 * V_161 ;
V_355 = V_280 -> V_358 ;
V_161 = & V_280 -> V_345 [ 0 ] ;
V_344 = F_296 ( V_280 , V_161 , 0 , V_310 - 1 ) ;
for ( V_178 = V_355 + 1 ; V_178 < V_342 ; V_178 ++ ) {
if ( ! F_323 ( V_178 ) )
continue;
V_344 = F_296 ( F_201 ( V_178 ) , V_161 , V_344 ,
V_310 - 1 ) ;
}
for ( V_178 = 0 ; V_178 < V_355 ; V_178 ++ ) {
if ( ! F_323 ( V_178 ) )
continue;
V_344 = F_296 ( F_201 ( V_178 ) , V_161 , V_344 ,
V_310 - 1 ) ;
}
V_161 -> V_175 [ V_344 ] . V_11 = NULL ;
V_161 -> V_175 [ V_344 ] . F_203 = 0 ;
}
static void F_320 ( T_10 * V_280 )
{
V_280 -> V_345 [ 0 ] . V_165 = NULL ;
}
static int F_324 ( void * V_331 )
{
int V_181 ;
int V_112 ;
T_10 * V_360 = V_331 ;
#ifdef V_189
memset ( V_343 , 0 , sizeof( V_343 ) ) ;
#endif
if ( V_360 && ! F_323 ( V_360 -> V_358 ) ) {
F_318 ( V_360 ) ;
F_320 ( V_360 ) ;
}
F_198 (nid) {
T_10 * V_280 = F_201 ( V_181 ) ;
F_318 ( V_280 ) ;
F_320 ( V_280 ) ;
}
F_325 (cpu) {
F_326 ( & F_327 ( V_361 , V_112 ) , 0 ) ;
#ifdef F_328
if ( F_329 ( V_112 ) )
F_330 ( V_112 , F_322 ( F_331 ( V_112 ) ) ) ;
#endif
}
return 0 ;
}
void T_14 F_306 ( T_10 * V_280 , struct V_11 * V_11 )
{
F_317 () ;
if ( V_362 == V_363 ) {
F_324 ( NULL ) ;
F_332 () ;
F_333 () ;
} else {
#ifdef F_334
if ( V_11 )
F_335 ( V_11 ) ;
#endif
F_336 ( F_324 , V_280 , NULL ) ;
}
V_364 = F_279 () ;
if ( V_364 < ( V_82 * V_285 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_23 ( L_63
L_64 ,
V_197 ,
V_365 [ V_352 ] ,
V_7 ? L_65 : L_66 ,
V_364 ) ;
#ifdef V_189
F_23 ( L_67 , V_366 [ V_367 ] ) ;
#endif
}
static inline unsigned long F_337 ( unsigned long V_106 )
{
unsigned long V_90 = 1 ;
V_106 /= V_368 ;
while ( V_90 < V_106 )
V_90 <<= 1 ;
V_90 = V_153 ( V_90 , 4096UL ) ;
return F_338 ( V_90 , 4UL ) ;
}
static inline unsigned long F_337 ( unsigned long V_106 )
{
return 4096UL ;
}
static inline unsigned long F_339 ( unsigned long V_90 )
{
return F_340 ( ~ V_90 ) ;
}
static int F_341 ( unsigned long V_16 , unsigned long V_98 )
{
unsigned long V_14 ;
for ( V_14 = V_16 ; V_14 < V_98 ; V_14 ++ ) {
if ( ! F_16 ( V_14 ) || F_342 ( F_125 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_343 ( struct V_11 * V_11 )
{
unsigned long V_16 , V_14 , V_98 , V_369 ;
struct V_5 * V_5 ;
unsigned long V_370 ;
int V_371 ;
V_16 = V_11 -> V_17 ;
V_98 = F_146 ( V_11 ) ;
V_16 = F_344 ( V_16 , V_82 ) ;
V_371 = F_344 ( F_292 ( V_11 ) , V_82 ) >>
V_84 ;
V_371 = V_153 ( 2 , V_371 ) ;
for ( V_14 = V_16 ; V_14 < V_98 ; V_14 += V_82 ) {
if ( ! F_147 ( V_14 ) )
continue;
V_5 = F_125 ( V_14 ) ;
if ( F_121 ( V_5 ) != F_122 ( V_11 ) )
continue;
V_370 = F_100 ( V_5 ) ;
if ( V_371 > 0 ) {
V_369 = V_153 ( V_14 + V_82 , V_98 ) ;
if ( F_341 ( V_14 , V_369 ) )
continue;
if ( V_370 == V_104 ) {
V_371 -- ;
continue;
}
if ( V_370 == V_122 ) {
F_6 ( V_5 ,
V_104 ) ;
F_124 ( V_11 , V_5 ,
V_104 ) ;
V_371 -- ;
continue;
}
}
if ( V_370 == V_104 ) {
F_6 ( V_5 , V_122 ) ;
F_124 ( V_11 , V_5 , V_122 ) ;
}
}
}
void T_3 F_345 ( unsigned long V_90 , int V_181 , unsigned long V_11 ,
unsigned long V_16 , enum V_372 V_373 )
{
struct V_5 * V_5 ;
unsigned long V_98 = V_16 + V_90 ;
unsigned long V_14 ;
struct V_11 * V_148 ;
if ( V_374 < V_98 - 1 )
V_374 = V_98 - 1 ;
V_148 = & F_201 ( V_181 ) -> V_282 [ V_11 ] ;
for ( V_14 = V_16 ; V_14 < V_98 ; V_14 ++ ) {
if ( V_373 == V_375 ) {
if ( ! F_346 ( V_14 ) )
continue;
if ( ! F_347 ( V_14 , V_181 ) )
continue;
}
V_5 = F_125 ( V_14 ) ;
F_348 ( V_5 , V_11 , V_181 , V_14 ) ;
F_349 ( V_5 , V_11 , V_181 , V_14 ) ;
F_350 ( V_5 ) ;
F_21 ( V_5 ) ;
F_74 ( V_5 ) ;
F_351 ( V_5 ) ;
if ( ( V_148 -> V_17 <= V_14 )
&& ( V_14 < F_146 ( V_148 ) )
&& ! ( V_14 & ( V_82 - 1 ) ) )
F_6 ( V_5 , V_122 ) ;
F_113 ( & V_5 -> V_51 ) ;
#ifdef F_352
if ( ! F_353 ( V_11 ) )
F_354 ( V_5 , F_355 ( V_14 << V_376 ) ) ;
#endif
}
}
static void T_3 F_356 ( struct V_11 * V_11 )
{
int V_30 , V_120 ;
F_150 (order, t) {
F_113 ( & V_11 -> V_52 [ V_30 ] . V_56 [ V_120 ] ) ;
V_11 -> V_52 [ V_30 ] . V_53 = 0 ;
}
}
static int T_3 F_357 ( struct V_11 * V_11 )
{
#ifdef F_358
int V_111 ;
V_111 = V_11 -> V_81 / 1024 ;
if ( V_111 * V_78 > 512 * 1024 )
V_111 = ( 512 * 1024 ) / V_78 ;
V_111 /= 4 ;
if ( V_111 < 1 )
V_111 = 1 ;
V_111 = F_359 ( V_111 + V_111 / 2 ) - 1 ;
return V_111 ;
#else
return 0 ;
#endif
}
static void F_326 ( struct V_113 * V_33 , unsigned long V_111 )
{
struct V_63 * V_64 ;
int V_6 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_64 = & V_33 -> V_64 ;
V_64 -> V_62 = 0 ;
V_64 -> V_88 = 6 * V_111 ;
V_64 -> V_111 = F_338 ( 1UL , 1 * V_111 ) ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ )
F_113 ( & V_64 -> V_73 [ V_6 ] ) ;
}
static void F_360 ( struct V_113 * V_33 ,
unsigned long V_88 )
{
struct V_63 * V_64 ;
V_64 = & V_33 -> V_64 ;
V_64 -> V_88 = V_88 ;
V_64 -> V_111 = F_338 ( 1UL , V_88 / 4 ) ;
if ( ( V_88 / 4 ) > ( V_376 * 8 ) )
V_64 -> V_111 = V_376 * 8 ;
}
static void T_3 F_335 ( struct V_11 * V_11 )
{
int V_112 ;
V_11 -> V_115 = F_361 ( struct V_113 ) ;
F_325 (cpu) {
struct V_113 * V_64 = F_136 ( V_11 -> V_115 , V_112 ) ;
F_326 ( V_64 , F_357 ( V_11 ) ) ;
if ( V_377 )
F_360 ( V_64 ,
( V_11 -> V_81 /
V_377 ) ) ;
}
}
void T_2 F_362 ( void )
{
struct V_11 * V_11 ;
F_135 (zone)
F_335 ( V_11 ) ;
}
static T_15 T_16
int F_363 ( struct V_11 * V_11 , unsigned long V_378 )
{
int V_31 ;
struct V_379 * V_280 = V_11 -> V_179 ;
T_9 V_380 ;
V_11 -> F_337 =
F_337 ( V_378 ) ;
V_11 -> F_339 =
F_339 ( V_11 -> F_337 ) ;
V_380 = V_11 -> F_337
* sizeof( V_381 ) ;
if ( ! F_364 () ) {
V_11 -> V_382 = ( V_381 * )
F_365 ( V_280 , V_380 ) ;
} else {
V_11 -> V_382 = F_366 ( V_380 ) ;
}
if ( ! V_11 -> V_382 )
return - V_147 ;
for( V_31 = 0 ; V_31 < V_11 -> F_337 ; ++ V_31 )
F_367 ( V_11 -> V_382 + V_31 ) ;
return 0 ;
}
static T_3 void F_368 ( struct V_11 * V_11 )
{
V_11 -> V_115 = & V_361 ;
if ( V_11 -> V_305 )
F_23 ( V_383 L_68 ,
V_11 -> V_288 , V_11 -> V_305 ,
F_357 ( V_11 ) ) ;
}
int T_3 F_369 ( struct V_11 * V_11 ,
unsigned long V_17 ,
unsigned long V_90 ,
enum V_372 V_373 )
{
struct V_379 * V_280 = V_11 -> V_179 ;
int V_12 ;
V_12 = F_363 ( V_11 , V_90 ) ;
if ( V_12 )
return V_12 ;
V_280 -> V_314 = F_203 ( V_11 ) + 1 ;
V_11 -> V_17 = V_17 ;
F_370 ( V_384 , L_69 ,
L_70 ,
V_280 -> V_358 ,
( unsigned long ) F_203 ( V_11 ) ,
V_17 , ( V_17 + V_90 ) ) ;
F_356 ( V_11 ) ;
return 0 ;
}
int T_3 F_371 ( unsigned long V_14 )
{
unsigned long V_16 , V_98 ;
int V_31 , V_181 ;
static unsigned long T_17 V_385 , V_386 ;
static int T_17 V_387 ;
if ( V_385 <= V_14 && V_14 < V_386 )
return V_387 ;
F_372 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
if ( V_16 <= V_14 && V_14 < V_98 ) {
V_385 = V_16 ;
V_386 = V_98 ;
V_387 = V_181 ;
return V_181 ;
}
return - 1 ;
}
int T_3 F_373 ( unsigned long V_14 )
{
int V_181 ;
V_181 = F_371 ( V_14 ) ;
if ( V_181 >= 0 )
return V_181 ;
return 0 ;
}
bool T_3 F_347 ( unsigned long V_14 , int V_178 )
{
int V_181 ;
V_181 = F_371 ( V_14 ) ;
if ( V_181 >= 0 && V_181 != V_178 )
return false ;
return true ;
}
void T_2 F_374 ( int V_181 , unsigned long V_388 )
{
unsigned long V_16 , V_98 ;
int V_31 , V_389 ;
F_372 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_16 = V_153 ( V_16 , V_388 ) ;
V_98 = V_153 ( V_98 , V_388 ) ;
if ( V_16 < V_98 )
F_375 ( F_201 ( V_389 ) ,
F_376 ( V_16 ) ,
( V_98 - V_16 ) << V_376 ) ;
}
}
void T_2 F_377 ( int V_181 )
{
unsigned long V_16 , V_98 ;
int V_31 , V_389 ;
F_372 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_378 ( V_389 , V_16 , V_98 ) ;
}
void T_3 F_379 ( unsigned int V_181 ,
unsigned long * V_16 , unsigned long * V_98 )
{
unsigned long V_390 , V_391 ;
int V_31 ;
* V_16 = - 1UL ;
* V_98 = 0 ;
F_372 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_16 = V_153 ( * V_16 , V_390 ) ;
* V_98 = F_338 ( * V_98 , V_391 ) ;
}
if ( * V_16 == - 1UL )
* V_16 = 0 ;
}
static void T_2 F_380 ( void )
{
int V_392 ;
for ( V_392 = V_310 - 1 ; V_392 >= 0 ; V_392 -- ) {
if ( V_392 == V_393 )
continue;
if ( V_394 [ V_392 ] >
V_395 [ V_392 ] )
break;
}
F_42 ( V_392 == - 1 ) ;
V_396 = V_392 ;
}
static void T_3 F_381 ( int V_181 ,
unsigned long V_222 ,
unsigned long V_397 ,
unsigned long V_398 ,
unsigned long * V_17 ,
unsigned long * F_146 )
{
if ( V_399 [ V_181 ] ) {
if ( V_222 == V_393 ) {
* V_17 = V_399 [ V_181 ] ;
* F_146 = V_153 ( V_398 ,
V_394 [ V_396 ] ) ;
} else if ( * V_17 < V_399 [ V_181 ] &&
* F_146 > V_399 [ V_181 ] ) {
* F_146 = V_399 [ V_181 ] ;
} else if ( * V_17 >= V_399 [ V_181 ] )
* V_17 = * F_146 ;
}
}
static unsigned long T_3 F_382 ( int V_181 ,
unsigned long V_222 ,
unsigned long * V_400 )
{
unsigned long V_397 , V_398 ;
unsigned long V_17 , F_146 ;
F_379 ( V_181 , & V_397 , & V_398 ) ;
V_17 = V_395 [ V_222 ] ;
F_146 = V_394 [ V_222 ] ;
F_381 ( V_181 , V_222 ,
V_397 , V_398 ,
& V_17 , & F_146 ) ;
if ( F_146 < V_397 || V_17 > V_398 )
return 0 ;
F_146 = V_153 ( F_146 , V_398 ) ;
V_17 = F_338 ( V_17 , V_397 ) ;
return F_146 - V_17 ;
}
unsigned long T_3 F_383 ( int V_181 ,
unsigned long V_401 ,
unsigned long V_402 )
{
unsigned long V_403 = V_402 - V_401 ;
unsigned long V_16 , V_98 ;
int V_31 ;
F_372 (i, nid, &start_pfn, &end_pfn, NULL) {
V_16 = F_384 ( V_16 , V_401 , V_402 ) ;
V_98 = F_384 ( V_98 , V_401 , V_402 ) ;
V_403 -= V_98 - V_16 ;
}
return V_403 ;
}
unsigned long T_2 F_385 ( unsigned long V_16 ,
unsigned long V_98 )
{
return F_383 ( V_342 , V_16 , V_98 ) ;
}
static unsigned long T_3 F_386 ( int V_181 ,
unsigned long V_222 ,
unsigned long * V_400 )
{
unsigned long V_404 = V_395 [ V_222 ] ;
unsigned long V_405 = V_394 [ V_222 ] ;
unsigned long V_397 , V_398 ;
unsigned long V_17 , F_146 ;
F_379 ( V_181 , & V_397 , & V_398 ) ;
V_17 = F_384 ( V_397 , V_404 , V_405 ) ;
F_146 = F_384 ( V_398 , V_404 , V_405 ) ;
F_381 ( V_181 , V_222 ,
V_397 , V_398 ,
& V_17 , & F_146 ) ;
return F_383 ( V_181 , V_17 , F_146 ) ;
}
static inline unsigned long T_3 F_382 ( int V_181 ,
unsigned long V_222 ,
unsigned long * V_406 )
{
return V_406 [ V_222 ] ;
}
static inline unsigned long T_3 F_386 ( int V_181 ,
unsigned long V_222 ,
unsigned long * V_407 )
{
if ( ! V_407 )
return 0 ;
return V_407 [ V_222 ] ;
}
static void T_3 F_387 ( struct V_379 * V_280 ,
unsigned long * V_406 , unsigned long * V_407 )
{
unsigned long V_408 , V_409 = 0 ;
enum V_222 V_31 ;
for ( V_31 = 0 ; V_31 < V_310 ; V_31 ++ )
V_409 += F_382 ( V_280 -> V_358 , V_31 ,
V_406 ) ;
V_280 -> V_410 = V_409 ;
V_408 = V_409 ;
for ( V_31 = 0 ; V_31 < V_310 ; V_31 ++ )
V_408 -=
F_386 ( V_280 -> V_358 , V_31 ,
V_407 ) ;
V_280 -> V_281 = V_408 ;
F_23 ( V_383 L_71 , V_280 -> V_358 ,
V_408 ) ;
}
static unsigned long T_2 F_388 ( unsigned long V_17 , unsigned long V_411 )
{
unsigned long V_412 ;
V_411 += V_17 & ( V_82 - 1 ) ;
V_412 = F_344 ( V_411 , V_82 ) ;
V_412 = V_412 >> V_84 ;
V_412 *= V_413 ;
V_412 = F_344 ( V_412 , 8 * sizeof( unsigned long ) ) ;
return V_412 / 8 ;
}
static void T_2 F_389 ( struct V_379 * V_280 ,
struct V_11 * V_11 ,
unsigned long V_17 ,
unsigned long V_411 )
{
unsigned long V_412 = F_388 ( V_17 , V_411 ) ;
V_11 -> V_414 = NULL ;
if ( V_412 )
V_11 -> V_414 = F_365 ( V_280 ,
V_412 ) ;
}
static inline void F_389 ( struct V_379 * V_280 , struct V_11 * V_11 ,
unsigned long V_17 , unsigned long V_411 ) {}
void T_2 F_390 ( void )
{
unsigned int V_30 ;
if ( V_84 )
return;
if ( V_415 > V_376 )
V_30 = V_416 ;
else
V_30 = V_40 - 1 ;
V_84 = V_30 ;
}
void T_2 F_390 ( void )
{
}
static unsigned long T_7 F_391 ( unsigned long V_18 ,
unsigned long V_305 )
{
unsigned long V_106 = V_18 ;
if ( V_18 > V_305 + ( V_305 >> 4 ) &&
F_132 ( V_417 ) )
V_106 = V_305 ;
return F_269 ( V_106 * sizeof( struct V_5 ) ) >> V_376 ;
}
static void T_7 F_392 ( struct V_379 * V_280 ,
unsigned long * V_406 , unsigned long * V_407 )
{
enum V_222 V_344 ;
int V_181 = V_280 -> V_358 ;
unsigned long V_17 = V_280 -> V_397 ;
int V_12 ;
F_393 ( V_280 ) ;
#ifdef F_394
F_395 ( & V_280 -> V_418 ) ;
V_280 -> V_419 = 0 ;
V_280 -> V_420 = V_22 ;
#endif
F_367 ( & V_280 -> V_421 ) ;
F_367 ( & V_280 -> V_422 ) ;
F_396 ( V_280 ) ;
for ( V_344 = 0 ; V_344 < V_310 ; V_344 ++ ) {
struct V_11 * V_11 = V_280 -> V_282 + V_344 ;
unsigned long V_90 , V_423 , V_424 , V_425 ;
V_90 = F_382 ( V_181 , V_344 , V_406 ) ;
V_423 = V_424 = V_90 - F_386 ( V_181 , V_344 ,
V_407 ) ;
V_425 = F_391 ( V_90 , V_423 ) ;
if ( V_424 >= V_425 ) {
V_424 -= V_425 ;
if ( V_425 )
F_23 ( V_383
L_72 ,
V_366 [ V_344 ] , V_425 ) ;
} else
F_23 ( V_320
L_73 ,
V_366 [ V_344 ] , V_425 , V_424 ) ;
if ( V_344 == 0 && V_424 > V_426 ) {
V_424 -= V_426 ;
F_23 ( V_383 L_74 ,
V_366 [ 0 ] , V_426 ) ;
}
if ( ! F_353 ( V_344 ) )
V_427 += V_424 ;
else if ( V_427 > V_425 * 2 )
V_427 -= V_425 ;
V_428 += V_424 ;
V_11 -> V_18 = V_90 ;
V_11 -> V_305 = V_423 ;
V_11 -> V_81 = F_353 ( V_344 ) ? V_423 : V_424 ;
#ifdef V_189
V_11 -> V_178 = V_181 ;
V_11 -> V_429 = ( V_424 * V_430 )
/ 100 ;
V_11 -> V_431 = ( V_424 * V_432 ) / 100 ;
#endif
V_11 -> V_288 = V_366 [ V_344 ] ;
F_395 ( & V_11 -> V_67 ) ;
F_395 ( & V_11 -> V_433 ) ;
F_397 ( V_11 ) ;
V_11 -> V_179 = V_280 ;
F_368 ( V_11 ) ;
F_398 ( & V_11 -> V_434 ) ;
if ( ! V_90 )
continue;
F_390 () ;
F_389 ( V_280 , V_11 , V_17 , V_90 ) ;
V_12 = F_369 ( V_11 , V_17 ,
V_90 , V_375 ) ;
F_120 ( V_12 ) ;
F_399 ( V_90 , V_181 , V_344 , V_17 ) ;
V_17 += V_90 ;
}
}
static void T_16 F_400 ( struct V_379 * V_280 )
{
if ( ! V_280 -> V_410 )
return;
#ifdef F_401
if ( ! V_280 -> V_435 ) {
unsigned long V_90 , V_436 , V_265 ;
struct V_5 * V_437 ;
V_436 = V_280 -> V_397 & ~ ( V_438 - 1 ) ;
V_265 = F_402 ( V_280 ) ;
V_265 = F_403 ( V_265 , V_438 ) ;
V_90 = ( V_265 - V_436 ) * sizeof( struct V_5 ) ;
V_437 = F_404 ( V_280 -> V_358 , V_90 ) ;
if ( ! V_437 )
V_437 = F_365 ( V_280 , V_90 ) ;
V_280 -> V_435 = V_437 + ( V_280 -> V_397 - V_436 ) ;
}
#ifndef F_405
if ( V_280 == F_201 ( 0 ) ) {
V_439 = F_201 ( 0 ) -> V_435 ;
#ifdef F_406
if ( F_10 ( V_439 ) != V_280 -> V_397 )
V_439 -= ( V_280 -> V_397 - V_440 ) ;
#endif
}
#endif
#endif
}
void T_7 F_407 ( int V_181 , unsigned long * V_406 ,
unsigned long V_397 , unsigned long * V_407 )
{
T_10 * V_280 = F_201 ( V_181 ) ;
F_2 ( V_280 -> V_314 || V_280 -> V_150 ) ;
V_280 -> V_358 = V_181 ;
V_280 -> V_397 = V_397 ;
F_197 ( V_181 ) ;
F_387 ( V_280 , V_406 , V_407 ) ;
F_400 ( V_280 ) ;
#ifdef F_401
F_23 ( V_383 L_75 ,
V_181 , ( unsigned long ) V_280 ,
( unsigned long ) V_280 -> V_435 ) ;
#endif
F_392 ( V_280 , V_406 , V_407 ) ;
}
void T_2 F_408 ( void )
{
unsigned int V_178 ;
unsigned int V_441 = 0 ;
F_409 (node, node_possible_map)
V_441 = V_178 ;
V_442 = V_441 + 1 ;
}
unsigned long T_2 F_410 ( void )
{
unsigned long V_443 = 0 , V_444 = 0 ;
unsigned long V_436 , V_265 , V_445 ;
int V_387 = - 1 ;
int V_31 , V_181 ;
F_372 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_436 || V_387 < 0 || V_387 == V_181 ) {
V_387 = V_181 ;
V_444 = V_265 ;
continue;
}
V_445 = ~ ( ( 1 << F_411 ( V_436 ) ) - 1 ) ;
while ( V_445 && V_444 <= ( V_436 & ( V_445 << 1 ) ) )
V_445 <<= 1 ;
V_443 |= V_445 ;
}
return ~ V_443 + 1 ;
}
static unsigned long T_2 F_412 ( int V_181 )
{
unsigned long V_446 = V_447 ;
unsigned long V_16 ;
int V_31 ;
F_372 (i, nid, &start_pfn, NULL, NULL)
V_446 = V_153 ( V_446 , V_16 ) ;
if ( V_446 == V_447 ) {
F_23 ( V_320
L_76 , V_181 ) ;
return 0 ;
}
return V_446 ;
}
unsigned long T_2 F_413 ( void )
{
return F_412 ( V_342 ) ;
}
static unsigned long T_2 F_414 ( void )
{
unsigned long V_409 = 0 ;
unsigned long V_16 , V_98 ;
int V_31 , V_181 ;
F_372 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_106 = V_98 - V_16 ;
V_409 += V_106 ;
if ( V_106 )
F_415 ( V_181 , V_172 ) ;
}
return V_409 ;
}
static void T_2 F_416 ( void )
{
int V_31 , V_181 ;
unsigned long V_448 ;
unsigned long V_449 , V_450 ;
T_6 V_451 = V_171 [ V_172 ] ;
unsigned long V_409 = F_414 () ;
int V_452 = F_316 ( V_171 [ V_172 ] ) ;
if ( V_453 ) {
unsigned long V_454 ;
V_453 =
F_344 ( V_453 , V_438 ) ;
V_454 = V_409 - V_453 ;
V_455 = F_338 ( V_455 , V_454 ) ;
}
if ( ! V_455 )
goto V_23;
F_380 () ;
V_448 = V_395 [ V_396 ] ;
V_249:
V_449 = V_455 / V_452 ;
F_310 (nid, N_MEMORY) {
unsigned long V_16 , V_98 ;
if ( V_455 < V_449 )
V_449 = V_455 / V_452 ;
V_450 = V_449 ;
F_372 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_456 ;
V_16 = F_338 ( V_16 , V_399 [ V_181 ] ) ;
if ( V_16 >= V_98 )
continue;
if ( V_16 < V_448 ) {
unsigned long V_457 ;
V_457 = V_153 ( V_98 , V_448 )
- V_16 ;
V_450 -= V_153 ( V_457 ,
V_450 ) ;
V_455 -= V_153 ( V_457 ,
V_455 ) ;
if ( V_98 <= V_448 ) {
V_399 [ V_181 ] = V_98 ;
continue;
}
V_16 = V_448 ;
}
V_456 = V_98 - V_16 ;
if ( V_456 > V_450 )
V_456 = V_450 ;
V_399 [ V_181 ] = V_16 + V_456 ;
V_455 -= V_153 ( V_455 ,
V_456 ) ;
V_450 -= V_456 ;
if ( ! V_450 )
break;
}
}
V_452 -- ;
if ( V_452 && V_455 > V_452 )
goto V_249;
for ( V_181 = 0 ; V_181 < V_342 ; V_181 ++ )
V_399 [ V_181 ] =
F_344 ( V_399 [ V_181 ] , V_438 ) ;
V_23:
V_171 [ V_172 ] = V_451 ;
}
static void F_417 ( T_10 * V_280 , int V_181 )
{
enum V_222 V_222 ;
if ( V_172 == V_458 )
return;
for ( V_222 = 0 ; V_222 <= V_393 - 1 ; V_222 ++ ) {
struct V_11 * V_11 = & V_280 -> V_282 [ V_222 ] ;
if ( V_11 -> V_305 ) {
F_415 ( V_181 , V_459 ) ;
if ( V_458 != V_459 &&
V_222 <= V_225 )
F_415 ( V_181 , V_458 ) ;
break;
}
}
}
void T_2 F_418 ( unsigned long * V_119 )
{
unsigned long V_16 , V_98 ;
int V_31 , V_181 ;
memset ( V_395 , 0 ,
sizeof( V_395 ) ) ;
memset ( V_394 , 0 ,
sizeof( V_394 ) ) ;
V_395 [ 0 ] = F_413 () ;
V_394 [ 0 ] = V_119 [ 0 ] ;
for ( V_31 = 1 ; V_31 < V_310 ; V_31 ++ ) {
if ( V_31 == V_393 )
continue;
V_395 [ V_31 ] =
V_394 [ V_31 - 1 ] ;
V_394 [ V_31 ] =
F_338 ( V_119 [ V_31 ] , V_395 [ V_31 ] ) ;
}
V_395 [ V_393 ] = 0 ;
V_394 [ V_393 ] = 0 ;
memset ( V_399 , 0 , sizeof( V_399 ) ) ;
F_416 () ;
F_23 ( L_77 ) ;
for ( V_31 = 0 ; V_31 < V_310 ; V_31 ++ ) {
if ( V_31 == V_393 )
continue;
F_23 ( V_460 L_78 , V_366 [ V_31 ] ) ;
if ( V_395 [ V_31 ] ==
V_394 [ V_31 ] )
F_23 ( V_460 L_79 ) ;
else
F_23 ( V_460 L_80 ,
V_395 [ V_31 ] << V_376 ,
( V_394 [ V_31 ]
<< V_376 ) - 1 ) ;
}
F_23 ( L_81 ) ;
for ( V_31 = 0 ; V_31 < V_342 ; V_31 ++ ) {
if ( V_399 [ V_31 ] )
F_23 ( L_82 , V_31 ,
V_399 [ V_31 ] << V_376 ) ;
}
F_23 ( L_83 ) ;
F_372 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_23 ( L_84 , V_181 ,
V_16 << V_376 , ( V_98 << V_376 ) - 1 ) ;
F_419 () ;
F_408 () ;
F_198 (nid) {
T_10 * V_280 = F_201 ( V_181 ) ;
F_407 ( V_181 , NULL ,
F_412 ( V_181 ) , NULL ) ;
if ( V_280 -> V_281 )
F_415 ( V_181 , V_172 ) ;
F_417 ( V_280 , V_181 ) ;
}
}
static int T_2 F_420 ( char * V_33 , unsigned long * V_461 )
{
unsigned long long V_462 ;
if ( ! V_33 )
return - V_321 ;
V_462 = F_421 ( V_33 , & V_33 ) ;
* V_461 = V_462 >> V_376 ;
F_2 ( ( V_462 >> V_376 ) > V_447 ) ;
return 0 ;
}
static int T_2 F_422 ( char * V_33 )
{
return F_420 ( V_33 , & V_455 ) ;
}
static int T_2 F_423 ( char * V_33 )
{
return F_420 ( V_33 , & V_453 ) ;
}
unsigned long F_424 ( unsigned long V_436 , unsigned long V_265 ,
int V_463 , char * V_315 )
{
unsigned long V_106 , V_347 ;
V_347 = V_436 = F_269 ( V_436 ) ;
V_265 &= V_464 ;
for ( V_106 = 0 ; V_347 < V_265 ; V_347 += V_78 , V_106 ++ ) {
if ( V_463 )
memset ( ( void * ) V_347 , V_463 , V_78 ) ;
F_425 ( F_163 ( ( void * ) V_347 ) ) ;
}
if ( V_106 && V_315 )
F_426 ( L_85 ,
V_315 , V_106 << ( V_376 - 10 ) , V_436 , V_265 ) ;
return V_106 ;
}
void F_427 ( struct V_5 * V_5 )
{
F_428 ( V_5 ) ;
V_85 ++ ;
V_86 ++ ;
}
void T_2 F_429 ( unsigned long V_465 )
{
V_426 = V_465 ;
}
void T_2 F_430 ( unsigned long * V_406 )
{
F_407 ( 0 , V_406 ,
F_431 ( V_466 ) >> V_376 , NULL ) ;
}
static int F_432 ( struct V_467 * V_360 ,
unsigned long V_468 , void * V_469 )
{
int V_112 = ( unsigned long ) V_469 ;
if ( V_468 == V_470 || V_468 == V_471 ) {
F_433 ( V_112 ) ;
F_134 ( V_112 ) ;
F_434 ( V_112 ) ;
F_435 ( V_112 ) ;
}
return V_472 ;
}
void T_2 F_436 ( void )
{
F_437 ( F_432 , 0 ) ;
}
static void F_438 ( void )
{
struct V_379 * V_280 ;
unsigned long V_473 = 0 ;
enum V_222 V_31 , V_344 ;
F_439 (pgdat) {
for ( V_31 = 0 ; V_31 < V_310 ; V_31 ++ ) {
struct V_11 * V_11 = V_280 -> V_282 + V_31 ;
unsigned long F_338 = 0 ;
for ( V_344 = V_31 ; V_344 < V_310 ; V_344 ++ ) {
if ( V_11 -> V_154 [ V_344 ] > F_338 )
F_338 = V_11 -> V_154 [ V_344 ] ;
}
F_338 += F_277 ( V_11 ) ;
if ( F_338 > V_11 -> V_81 )
F_338 = V_11 -> V_81 ;
V_473 += F_338 ;
V_11 -> V_474 = F_338 ;
}
}
V_474 = V_473 ;
V_475 = V_473 ;
}
static void F_440 ( void )
{
struct V_379 * V_280 ;
enum V_222 V_344 , V_476 ;
F_439 (pgdat) {
for ( V_344 = 0 ; V_344 < V_310 ; V_344 ++ ) {
struct V_11 * V_11 = V_280 -> V_282 + V_344 ;
unsigned long V_81 = V_11 -> V_81 ;
V_11 -> V_154 [ V_344 ] = 0 ;
V_476 = V_344 ;
while ( V_476 ) {
struct V_11 * V_477 ;
V_476 -- ;
if ( V_478 [ V_476 ] < 1 )
V_478 [ V_476 ] = 1 ;
V_477 = V_280 -> V_282 + V_476 ;
V_477 -> V_154 [ V_344 ] = V_81 /
V_478 [ V_476 ] ;
V_81 += V_477 -> V_81 ;
}
}
}
F_438 () ;
}
static void F_441 ( void )
{
unsigned long V_479 = V_480 >> ( V_376 - 10 ) ;
unsigned long V_481 = 0 ;
struct V_11 * V_11 ;
unsigned long V_59 ;
F_442 (zone) {
if ( ! F_443 ( V_11 ) )
V_481 += V_11 -> V_81 ;
}
F_442 (zone) {
T_18 V_287 ;
F_145 ( & V_11 -> V_67 , V_59 ) ;
V_287 = ( T_18 ) V_479 * V_11 -> V_81 ;
F_444 ( V_287 , V_481 ) ;
if ( F_443 ( V_11 ) ) {
unsigned long V_482 ;
V_482 = V_11 -> V_81 / 1024 ;
V_482 = F_384 ( V_482 , V_483 , 128UL ) ;
V_11 -> V_124 [ V_484 ] = V_482 ;
} else {
V_11 -> V_124 [ V_484 ] = V_287 ;
}
V_11 -> V_124 [ V_485 ] = F_292 ( V_11 ) + ( V_287 >> 2 ) ;
V_11 -> V_124 [ V_486 ] = F_292 ( V_11 ) + ( V_287 >> 1 ) ;
F_343 ( V_11 ) ;
F_153 ( & V_11 -> V_67 , V_59 ) ;
}
F_438 () ;
}
void F_445 ( void )
{
F_304 ( & V_333 ) ;
F_441 () ;
F_307 ( & V_333 ) ;
}
static void T_3 F_446 ( struct V_11 * V_11 )
{
unsigned int V_487 , V_488 ;
V_487 = V_11 -> V_81 >> ( 30 - V_376 ) ;
if ( V_487 )
V_488 = F_447 ( 10 * V_487 ) ;
else
V_488 = 1 ;
V_11 -> V_489 = V_488 ;
}
static void T_3 F_448 ( void )
{
struct V_11 * V_11 ;
F_442 (zone)
F_446 ( V_11 ) ;
}
int T_3 F_449 ( void )
{
unsigned long V_490 ;
V_490 = F_278 () * ( V_78 >> 10 ) ;
V_480 = F_447 ( V_490 * 16 ) ;
if ( V_480 < 128 )
V_480 = 128 ;
if ( V_480 > 65536 )
V_480 = 65536 ;
F_445 () ;
F_450 () ;
F_440 () ;
F_448 () ;
return 0 ;
}
int F_451 ( T_11 * V_324 , int V_325 ,
void T_12 * V_326 , T_9 * V_327 , T_13 * V_328 )
{
F_452 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( V_325 )
F_445 () ;
return 0 ;
}
int F_453 ( T_11 * V_324 , int V_325 ,
void T_12 * V_326 , T_9 * V_327 , T_13 * V_328 )
{
struct V_11 * V_11 ;
int V_491 ;
V_491 = F_454 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( V_491 )
return V_491 ;
F_442 (zone)
V_11 -> V_429 = ( V_11 -> V_81 *
V_430 ) / 100 ;
return 0 ;
}
int F_455 ( T_11 * V_324 , int V_325 ,
void T_12 * V_326 , T_9 * V_327 , T_13 * V_328 )
{
struct V_11 * V_11 ;
int V_491 ;
V_491 = F_454 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( V_491 )
return V_491 ;
F_442 (zone)
V_11 -> V_431 = ( V_11 -> V_81 *
V_432 ) / 100 ;
return 0 ;
}
int F_456 ( T_11 * V_324 , int V_325 ,
void T_12 * V_326 , T_9 * V_327 , T_13 * V_328 )
{
F_454 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
F_440 () ;
return 0 ;
}
int F_457 ( T_11 * V_324 , int V_325 ,
void T_12 * V_326 , T_9 * V_327 , T_13 * V_328 )
{
struct V_11 * V_11 ;
unsigned int V_112 ;
int V_12 ;
V_12 = F_454 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( ! V_325 || ( V_12 < 0 ) )
return V_12 ;
F_135 (zone) {
F_325 (cpu) {
unsigned long V_88 ;
V_88 = V_11 -> V_81 / V_377 ;
F_360 (
F_136 ( V_11 -> V_115 , V_112 ) , V_88 ) ;
}
}
return 0 ;
}
static int T_2 F_458 ( char * V_132 )
{
if ( ! V_132 )
return 0 ;
V_492 = F_459 ( V_132 , & V_132 , 0 ) ;
return 1 ;
}
void * T_2 F_460 ( const char * V_493 ,
unsigned long V_494 ,
unsigned long V_495 ,
int V_496 ,
int V_59 ,
unsigned int * V_497 ,
unsigned int * V_498 ,
unsigned long V_499 ,
unsigned long V_500 )
{
unsigned long long F_338 = V_500 ;
unsigned long V_501 , V_90 ;
void * V_324 = NULL ;
if ( ! V_495 ) {
V_495 = V_427 ;
V_495 += ( 1UL << ( 20 - V_376 ) ) - 1 ;
V_495 >>= 20 - V_376 ;
V_495 <<= 20 - V_376 ;
if ( V_496 > V_376 )
V_495 >>= ( V_496 - V_376 ) ;
else
V_495 <<= ( V_376 - V_496 ) ;
if ( F_7 ( V_59 & V_502 ) ) {
F_2 ( ! ( V_59 & V_503 ) ) ;
if ( ! ( V_495 >> * V_497 ) ) {
V_495 = 1UL << * V_497 ;
F_120 ( ! V_495 ) ;
}
} else if ( F_7 ( ( V_495 * V_494 ) < V_78 ) )
V_495 = V_78 / V_494 ;
}
V_495 = F_461 ( V_495 ) ;
if ( F_338 == 0 ) {
F_338 = ( ( unsigned long long ) V_428 << V_376 ) >> 4 ;
F_444 ( F_338 , V_494 ) ;
}
F_338 = V_153 ( F_338 , 0x80000000ULL ) ;
if ( V_495 < V_499 )
V_495 = V_499 ;
if ( V_495 > F_338 )
V_495 = F_338 ;
V_501 = F_462 ( V_495 ) ;
do {
V_90 = V_494 << V_501 ;
if ( V_59 & V_503 )
V_324 = F_463 ( V_90 ) ;
else if ( V_492 )
V_324 = F_464 ( V_90 , V_504 , V_505 ) ;
else {
if ( F_272 ( V_90 ) < V_40 ) {
V_324 = F_271 ( V_90 , V_504 ) ;
F_465 ( V_324 , V_90 , 1 , V_504 ) ;
}
}
} while ( ! V_324 && V_90 > V_78 && -- V_501 );
if ( ! V_324 )
F_466 ( L_86 , V_493 ) ;
F_23 ( V_43 L_87 ,
V_493 ,
( 1UL << V_501 ) ,
F_462 ( V_90 ) - V_376 ,
V_90 ) ;
if ( V_497 )
* V_497 = V_501 ;
if ( V_498 )
* V_498 = ( 1 << V_501 ) - 1 ;
return V_324 ;
}
static inline unsigned long * F_467 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef V_417
return F_468 ( V_14 ) -> V_414 ;
#else
return V_11 -> V_414 ;
#endif
}
static inline int F_469 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef V_417
V_14 &= ( V_506 - 1 ) ;
return ( V_14 >> V_84 ) * V_413 ;
#else
V_14 = V_14 - F_470 ( V_11 -> V_17 , V_82 ) ;
return ( V_14 >> V_84 ) * V_413 ;
#endif
}
unsigned long F_471 ( struct V_5 * V_5 ,
int V_507 , int V_508 )
{
struct V_11 * V_11 ;
unsigned long * V_509 ;
unsigned long V_14 , V_510 ;
unsigned long V_59 = 0 ;
unsigned long V_511 = 1 ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_509 = F_467 ( V_11 , V_14 ) ;
V_510 = F_469 ( V_11 , V_14 ) ;
for (; V_507 <= V_508 ; V_507 ++ , V_511 <<= 1 )
if ( F_192 ( V_510 + V_507 , V_509 ) )
V_59 |= V_511 ;
return V_59 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_59 ,
int V_507 , int V_508 )
{
struct V_11 * V_11 ;
unsigned long * V_509 ;
unsigned long V_14 , V_510 ;
unsigned long V_511 = 1 ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_509 = F_467 ( V_11 , V_14 ) ;
V_510 = F_469 ( V_11 , V_14 ) ;
F_42 ( ! F_12 ( V_11 , V_14 ) ) ;
for (; V_507 <= V_508 ; V_507 ++ , V_511 <<= 1 )
if ( V_59 & V_511 )
F_48 ( V_510 + V_507 , V_509 ) ;
else
F_50 ( V_510 + V_507 , V_509 ) ;
}
bool F_472 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_62 ,
bool V_512 )
{
unsigned long V_14 , V_513 , V_514 ;
int V_74 ;
if ( F_203 ( V_11 ) == V_393 )
return false ;
V_74 = F_100 ( V_5 ) ;
if ( V_74 == V_122 || F_84 ( V_74 ) )
return false ;
V_14 = F_10 ( V_5 ) ;
for ( V_514 = 0 , V_513 = 0 ; V_513 < V_82 ; V_513 ++ ) {
unsigned long V_515 = V_14 + V_513 ;
if ( ! F_16 ( V_515 ) )
continue;
V_5 = F_125 ( V_515 ) ;
if ( ! F_72 ( & V_5 -> V_58 ) ) {
if ( F_62 ( V_5 ) )
V_513 += ( 1 << F_60 ( V_5 ) ) - 1 ;
continue;
}
if ( V_512 && F_20 ( V_5 ) )
continue;
if ( ! F_473 ( V_5 ) )
V_514 ++ ;
if ( V_514 > V_62 )
return true ;
}
return false ;
}
bool F_474 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_323 ( F_121 ( V_5 ) ) )
return false ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_11 , V_14 ) )
return false ;
return ! F_472 ( V_11 , V_5 , 0 , true ) ;
}
static unsigned long F_475 ( unsigned long V_14 )
{
return V_14 & ~ ( F_476 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_477 ( unsigned long V_14 )
{
return F_403 ( V_14 , F_476 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_478 ( struct V_516 * V_517 ,
unsigned long V_436 , unsigned long V_265 )
{
unsigned long V_518 ;
unsigned long V_14 = V_436 ;
unsigned int V_519 = 0 ;
int V_12 = 0 ;
F_479 () ;
while ( V_14 < V_265 || ! F_77 ( & V_517 -> V_520 ) ) {
if ( F_480 ( V_26 ) ) {
V_12 = - V_521 ;
break;
}
if ( F_77 ( & V_517 -> V_520 ) ) {
V_517 -> V_522 = 0 ;
V_14 = F_481 ( V_517 -> V_11 , V_517 ,
V_14 , V_265 , true ) ;
if ( ! V_14 ) {
V_12 = - V_521 ;
break;
}
V_519 = 0 ;
} else if ( ++ V_519 == 5 ) {
V_12 = V_12 < 0 ? V_12 : - V_523 ;
break;
}
V_518 = F_482 ( V_517 -> V_11 ,
& V_517 -> V_520 ) ;
V_517 -> V_522 -= V_518 ;
V_12 = F_483 ( & V_517 -> V_520 , V_524 ,
0 , V_525 , V_526 ) ;
}
if ( V_12 < 0 ) {
F_484 ( & V_517 -> V_520 ) ;
return V_12 ;
}
return 0 ;
}
int F_485 ( unsigned long V_436 , unsigned long V_265 ,
unsigned V_6 )
{
unsigned long V_527 , V_528 ;
int V_12 = 0 , V_30 ;
struct V_516 V_517 = {
. V_522 = 0 ,
. V_30 = - 1 ,
. V_11 = F_17 ( F_125 ( V_436 ) ) ,
. V_529 = true ,
. V_530 = true ,
} ;
F_113 ( & V_517 . V_520 ) ;
V_12 = F_486 ( F_475 ( V_436 ) ,
F_477 ( V_265 ) , V_6 ,
false ) ;
if ( V_12 )
return V_12 ;
V_12 = F_478 ( & V_517 , V_436 , V_265 ) ;
if ( V_12 )
goto V_531;
F_487 () ;
F_139 () ;
V_30 = 0 ;
V_527 = V_436 ;
while ( ! F_62 ( F_125 ( V_527 ) ) ) {
if ( ++ V_30 >= V_40 ) {
V_12 = - V_523 ;
goto V_531;
}
V_527 &= ~ 0UL << V_30 ;
}
if ( F_488 ( V_527 , V_265 , false ) ) {
F_213 ( L_88 ,
V_527 , V_265 ) ;
V_12 = - V_523 ;
goto V_531;
}
V_528 = F_489 ( & V_517 , V_527 , V_265 ) ;
if ( ! V_528 ) {
V_12 = - V_523 ;
goto V_531;
}
if ( V_436 != V_527 )
F_490 ( V_527 , V_436 - V_527 ) ;
if ( V_265 != V_528 )
F_490 ( V_265 , V_528 - V_265 ) ;
V_531:
F_491 ( F_475 ( V_436 ) ,
F_477 ( V_265 ) , V_6 ) ;
return V_12 ;
}
void F_490 ( unsigned long V_14 , unsigned V_32 )
{
unsigned int V_62 = 0 ;
for (; V_32 -- ; V_14 ++ ) {
struct V_5 * V_5 = F_125 ( V_14 ) ;
V_62 += F_61 ( V_5 ) != 1 ;
F_492 ( V_5 ) ;
}
F_493 ( V_62 != 0 , L_89 , V_62 ) ;
}
static int T_3 F_494 ( void * V_331 )
{
struct V_11 * V_11 = V_331 ;
int V_112 ;
unsigned long V_111 = F_357 ( V_11 ) , V_59 ;
F_325 (cpu) {
struct V_113 * V_114 ;
struct V_63 * V_64 ;
V_114 = F_136 ( V_11 -> V_115 , V_112 ) ;
V_64 = & V_114 -> V_64 ;
F_98 ( V_59 ) ;
if ( V_64 -> V_62 > 0 )
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
F_495 ( V_11 , V_114 ) ;
F_326 ( V_114 , V_111 ) ;
F_102 ( V_59 ) ;
}
return 0 ;
}
void T_3 F_496 ( struct V_11 * V_11 )
{
F_336 ( F_494 , V_11 , NULL ) ;
}
void F_497 ( struct V_11 * V_11 )
{
unsigned long V_59 ;
int V_112 ;
struct V_113 * V_114 ;
F_98 ( V_59 ) ;
if ( V_11 -> V_115 != & V_361 ) {
F_140 (cpu) {
V_114 = F_136 ( V_11 -> V_115 , V_112 ) ;
F_495 ( V_11 , V_114 ) ;
}
F_498 ( V_11 -> V_115 ) ;
V_11 -> V_115 = & V_361 ;
}
F_102 ( V_59 ) ;
}
void
F_499 ( unsigned long V_16 , unsigned long V_98 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_30 , V_31 ;
unsigned long V_14 ;
unsigned long V_59 ;
for ( V_14 = V_16 ; V_14 < V_98 ; V_14 ++ )
if ( F_147 ( V_14 ) )
break;
if ( V_14 == V_98 )
return;
V_11 = F_17 ( F_125 ( V_14 ) ) ;
F_145 ( & V_11 -> V_67 , V_59 ) ;
V_14 = V_16 ;
while ( V_14 < V_98 ) {
if ( ! F_147 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_125 ( V_14 ) ;
if ( F_7 ( ! F_62 ( V_5 ) && F_20 ( V_5 ) ) ) {
V_14 ++ ;
F_351 ( V_5 ) ;
continue;
}
F_120 ( F_61 ( V_5 ) ) ;
F_120 ( ! F_62 ( V_5 ) ) ;
V_30 = F_60 ( V_5 ) ;
#ifdef F_500
F_23 ( V_43 L_90 ,
V_14 , 1 << V_30 , V_98 ) ;
#endif
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
V_11 -> V_52 [ V_30 ] . V_53 -- ;
for ( V_31 = 0 ; V_31 < ( 1 << V_30 ) ; V_31 ++ )
F_351 ( ( V_5 + V_31 ) ) ;
V_14 += ( 1 << V_30 ) ;
}
F_153 ( & V_11 -> V_67 , V_59 ) ;
}
bool F_501 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_17 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_59 ;
int V_30 ;
F_145 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
struct V_5 * V_532 = V_5 - ( V_14 & ( ( 1 << V_30 ) - 1 ) ) ;
if ( F_62 ( V_532 ) && F_60 ( V_532 ) >= V_30 )
break;
}
F_153 ( & V_11 -> V_67 , V_59 ) ;
return V_30 < V_40 ;
}
static void F_502 ( unsigned long V_59 )
{
const char * V_533 = L_91 ;
unsigned long V_445 ;
int V_31 ;
F_207 ( F_503 ( V_534 ) != V_535 ) ;
F_23 ( V_24 L_92 , V_59 ) ;
V_59 &= ( 1UL << V_536 ) - 1 ;
for ( V_31 = 0 ; V_31 < F_503 ( V_534 ) && V_59 ; V_31 ++ ) {
V_445 = V_534 [ V_31 ] . V_445 ;
if ( ( V_59 & V_445 ) != V_445 )
continue;
V_59 &= ~ V_445 ;
F_23 ( L_93 , V_533 , V_534 [ V_31 ] . V_288 ) ;
V_533 = L_94 ;
}
if ( V_59 )
F_23 ( L_95 , V_533 , V_59 ) ;
F_23 ( L_96 ) ;
}
void F_24 ( struct V_5 * V_5 )
{
F_23 ( V_24
L_97 ,
V_5 , F_72 ( & V_5 -> V_58 ) , F_71 ( V_5 ) ,
V_5 -> V_57 , V_5 -> V_537 ) ;
F_502 ( V_5 -> V_59 ) ;
F_504 ( V_5 ) ;
}
