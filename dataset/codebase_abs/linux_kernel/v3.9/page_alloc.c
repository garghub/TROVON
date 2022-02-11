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
V_152 -= ( 1 << V_30 ) - 1 ;
if ( V_151 & V_156 )
V_153 -= V_153 / 2 ;
if ( V_151 & V_157 )
V_153 -= V_153 / 4 ;
#ifdef V_109
if ( ! ( V_151 & V_158 ) )
V_152 -= F_184 ( V_148 , V_77 ) ;
#endif
if ( V_152 <= V_153 + V_154 )
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
if ( V_148 -> V_159 && V_152 < V_148 -> V_159 )
V_152 = F_186 ( V_148 , V_76 ) ;
return F_183 ( V_148 , V_30 , V_149 , V_150 , V_151 ,
V_152 ) ;
}
static T_6 * F_187 ( struct V_160 * V_160 , int V_151 )
{
struct V_161 * V_162 ;
T_6 * V_163 ;
V_162 = V_160 -> V_164 ;
if ( ! V_162 )
return NULL ;
if ( F_188 ( V_22 , V_162 -> V_165 + V_25 ) ) {
F_189 ( V_162 -> V_166 , V_167 ) ;
V_162 -> V_165 = V_22 ;
}
V_163 = ! F_43 () && ( V_151 & V_168 ) ?
& V_169 :
& V_170 [ V_171 ] ;
return V_163 ;
}
static int F_190 ( struct V_160 * V_160 , struct V_172 * V_148 ,
T_6 * V_163 )
{
struct V_161 * V_162 ;
int V_31 ;
int V_173 ;
V_162 = V_160 -> V_164 ;
if ( ! V_162 )
return 1 ;
V_31 = V_148 - V_160 -> V_174 ;
V_173 = V_162 -> V_175 [ V_31 ] ;
return F_191 ( V_173 , * V_163 ) && ! F_192 ( V_31 , V_162 -> V_166 ) ;
}
static void F_193 ( struct V_160 * V_160 , struct V_172 * V_148 )
{
struct V_161 * V_162 ;
int V_31 ;
V_162 = V_160 -> V_164 ;
if ( ! V_162 )
return;
V_31 = V_148 - V_160 -> V_174 ;
F_194 ( V_31 , V_162 -> V_166 ) ;
}
static void F_195 ( struct V_160 * V_160 )
{
struct V_161 * V_162 ;
V_162 = V_160 -> V_164 ;
if ( ! V_162 )
return;
F_189 ( V_162 -> V_166 , V_167 ) ;
}
static bool F_196 ( struct V_11 * V_176 , struct V_11 * V_11 )
{
return F_191 ( V_176 -> V_177 , V_11 -> V_178 -> V_179 ) ;
}
static void T_7 F_197 ( int V_180 )
{
int V_31 ;
F_198 (i)
if ( F_199 ( V_180 , V_31 ) <= V_181 )
F_200 ( V_31 , F_201 ( V_180 ) -> V_179 ) ;
else
V_182 = 1 ;
}
static T_6 * F_187 ( struct V_160 * V_160 , int V_151 )
{
return NULL ;
}
static int F_190 ( struct V_160 * V_160 , struct V_172 * V_148 ,
T_6 * V_163 )
{
return 1 ;
}
static void F_193 ( struct V_160 * V_160 , struct V_172 * V_148 )
{
}
static void F_195 ( struct V_160 * V_160 )
{
}
static bool F_196 ( struct V_11 * V_176 , struct V_11 * V_11 )
{
return true ;
}
static inline void F_197 ( int V_180 )
{
}
static struct V_5 *
F_202 ( T_1 V_135 , T_6 * V_183 , unsigned int V_30 ,
struct V_160 * V_160 , int V_184 , int V_151 ,
struct V_11 * V_126 , int V_6 )
{
struct V_172 * V_148 ;
struct V_5 * V_5 = NULL ;
int V_150 ;
struct V_11 * V_11 ;
T_6 * V_163 = NULL ;
int V_185 = 0 ;
int V_186 = 0 ;
V_150 = F_203 ( V_126 ) ;
V_187:
F_204 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( F_132 ( V_188 ) && V_185 &&
! F_190 ( V_160 , V_148 , V_163 ) )
continue;
if ( ( V_151 & V_168 ) &&
! F_205 ( V_11 , V_135 ) )
continue;
if ( ( V_151 & V_189 ) &&
( V_135 & V_190 ) && ! F_206 ( V_11 ) )
goto V_191;
F_207 ( V_192 < V_193 ) ;
if ( ! ( V_151 & V_192 ) ) {
unsigned long V_149 ;
int V_12 ;
V_149 = V_11 -> V_124 [ V_151 & V_194 ] ;
if ( F_166 ( V_11 , V_30 , V_149 ,
V_150 , V_151 ) )
goto V_195;
if ( F_132 ( V_188 ) &&
! V_186 && V_196 > 1 ) {
V_163 = F_187 ( V_160 , V_151 ) ;
V_185 = 1 ;
V_186 = 1 ;
}
if ( V_182 == 0 ||
! F_196 ( V_126 , V_11 ) )
goto V_191;
if ( F_132 ( V_188 ) && V_185 &&
! F_190 ( V_160 , V_148 , V_163 ) )
continue;
V_12 = F_208 ( V_11 , V_135 , V_30 ) ;
switch ( V_12 ) {
case V_197 :
continue;
case V_198 :
continue;
default:
if ( ! F_166 ( V_11 , V_30 , V_149 ,
V_150 , V_151 ) )
goto V_191;
}
}
V_195:
V_5 = F_168 ( V_126 , V_11 , V_30 ,
V_135 , V_6 ) ;
if ( V_5 )
break;
V_191:
if ( F_132 ( V_188 ) )
F_193 ( V_160 , V_148 ) ;
}
if ( F_7 ( F_132 ( V_188 ) && V_5 == NULL && V_185 ) ) {
V_185 = 0 ;
goto V_187;
}
if ( V_5 )
V_5 -> V_199 = ! ! ( V_151 & V_192 ) ;
return V_5 ;
}
static inline bool F_209 ( void )
{
bool V_12 = false ;
#if V_200 > 8
V_12 = F_43 () ;
#endif
return V_12 ;
}
void F_210 ( T_1 V_135 , int V_30 , const char * V_201 , ... )
{
unsigned int V_202 = V_203 ;
if ( ( V_135 & V_204 ) || ! F_211 ( & V_205 ) ||
F_112 () > 0 )
return;
if ( ! ( V_135 & V_206 ) )
if ( F_212 ( V_207 ) ||
( V_26 -> V_59 & ( V_208 | V_209 ) ) )
V_202 &= ~ V_203 ;
if ( F_43 () || ! ( V_135 & V_139 ) )
V_202 &= ~ V_203 ;
if ( V_201 ) {
struct V_210 V_211 ;
T_8 args ;
va_start ( args , V_201 ) ;
V_211 . V_201 = V_201 ;
V_211 . V_212 = & args ;
F_213 ( L_10 , & V_211 ) ;
va_end ( args ) ;
}
F_213 ( L_11 ,
V_26 -> V_27 , V_30 , V_135 ) ;
F_26 () ;
if ( ! F_209 () )
F_214 ( V_202 ) ;
}
static inline int
F_215 ( T_1 V_135 , unsigned int V_30 ,
unsigned long V_213 ,
unsigned long V_214 )
{
if ( V_135 & V_215 )
return 0 ;
if ( V_135 & V_130 )
return 1 ;
if ( ! V_213 && F_5 () )
return 0 ;
if ( V_30 <= V_216 )
return 1 ;
if ( V_135 & V_217 && V_214 < ( 1 << V_30 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_216 ( T_1 V_135 , unsigned int V_30 ,
struct V_160 * V_160 , enum V_218 V_184 ,
T_6 * V_183 , struct V_11 * V_126 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_217 ( V_160 , V_135 ) ) {
F_218 ( 1 ) ;
return NULL ;
}
V_5 = F_202 ( V_135 | V_219 , V_183 ,
V_30 , V_160 , V_184 ,
V_220 | V_168 ,
V_126 , V_6 ) ;
if ( V_5 )
goto V_23;
if ( ! ( V_135 & V_130 ) ) {
if ( V_30 > V_216 )
goto V_23;
if ( V_184 < V_221 )
goto V_23;
if ( V_135 & V_222 )
goto V_23;
}
F_219 ( V_160 , V_135 , V_30 , V_183 , false ) ;
V_23:
F_220 ( V_160 , V_135 ) ;
return V_5 ;
}
static struct V_5 *
F_221 ( T_1 V_135 , unsigned int V_30 ,
struct V_160 * V_160 , enum V_218 V_184 ,
T_6 * V_183 , int V_151 , struct V_11 * V_126 ,
int V_6 , bool V_223 ,
bool * V_224 , bool * V_225 ,
unsigned long * V_213 )
{
if ( ! V_30 )
return NULL ;
if ( F_222 ( V_126 , V_30 ) ) {
* V_225 = true ;
return NULL ;
}
V_26 -> V_59 |= V_208 ;
* V_213 = F_223 ( V_160 , V_30 , V_135 ,
V_183 , V_223 ,
V_224 ) ;
V_26 -> V_59 &= ~ V_208 ;
if ( * V_213 != V_226 ) {
struct V_5 * V_5 ;
F_134 ( F_224 () ) ;
F_225 () ;
V_5 = F_202 ( V_135 , V_183 ,
V_30 , V_160 , V_184 ,
V_151 & ~ V_192 ,
V_126 , V_6 ) ;
if ( V_5 ) {
V_126 -> V_227 = false ;
V_126 -> V_228 = 0 ;
V_126 -> V_229 = 0 ;
if ( V_30 >= V_126 -> V_230 )
V_126 -> V_230 = V_30 + 1 ;
F_226 ( V_231 ) ;
return V_5 ;
}
F_226 ( V_232 ) ;
if ( V_223 )
F_227 ( V_126 , V_30 ) ;
F_228 () ;
}
return NULL ;
}
static inline struct V_5 *
F_221 ( T_1 V_135 , unsigned int V_30 ,
struct V_160 * V_160 , enum V_218 V_184 ,
T_6 * V_183 , int V_151 , struct V_11 * V_126 ,
int V_6 , bool V_223 ,
bool * V_224 , bool * V_225 ,
unsigned long * V_213 )
{
return NULL ;
}
static int
F_229 ( T_1 V_135 , unsigned int V_30 , struct V_160 * V_160 ,
T_6 * V_183 )
{
struct V_233 V_233 ;
int V_234 ;
F_228 () ;
F_230 () ;
V_26 -> V_59 |= V_208 ;
F_231 ( V_135 ) ;
V_233 . V_235 = 0 ;
V_26 -> V_233 = & V_233 ;
V_234 = F_232 ( V_160 , V_30 , V_135 , V_183 ) ;
V_26 -> V_233 = NULL ;
F_233 () ;
V_26 -> V_59 &= ~ V_208 ;
F_228 () ;
return V_234 ;
}
static inline struct V_5 *
F_234 ( T_1 V_135 , unsigned int V_30 ,
struct V_160 * V_160 , enum V_218 V_184 ,
T_6 * V_183 , int V_151 , struct V_11 * V_126 ,
int V_6 , unsigned long * V_213 )
{
struct V_5 * V_5 = NULL ;
bool V_236 = false ;
* V_213 = F_229 ( V_135 , V_30 , V_160 ,
V_183 ) ;
if ( F_7 ( ! ( * V_213 ) ) )
return NULL ;
if ( F_132 ( V_188 ) )
F_195 ( V_160 ) ;
V_237:
V_5 = F_202 ( V_135 , V_183 , V_30 ,
V_160 , V_184 ,
V_151 & ~ V_192 ,
V_126 , V_6 ) ;
if ( ! V_5 && ! V_236 ) {
F_139 () ;
V_236 = true ;
goto V_237;
}
return V_5 ;
}
static inline struct V_5 *
F_235 ( T_1 V_135 , unsigned int V_30 ,
struct V_160 * V_160 , enum V_218 V_184 ,
T_6 * V_183 , struct V_11 * V_126 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_202 ( V_135 , V_183 , V_30 ,
V_160 , V_184 , V_192 ,
V_126 , V_6 ) ;
if ( ! V_5 && V_135 & V_130 )
F_236 ( V_126 , V_238 , V_25 / 50 ) ;
} while ( ! V_5 && ( V_135 & V_130 ) );
return V_5 ;
}
static inline
void F_237 ( unsigned int V_30 , struct V_160 * V_160 ,
enum V_218 V_184 ,
enum V_218 V_150 )
{
struct V_172 * V_148 ;
struct V_11 * V_11 ;
F_238 (zone, z, zonelist, high_zoneidx)
F_239 ( V_11 , V_30 , V_150 ) ;
}
static inline int
F_240 ( T_1 V_135 )
{
int V_151 = V_239 | V_168 ;
const T_1 V_240 = V_135 & V_139 ;
F_207 ( V_241 != ( V_242 T_1 ) V_156 ) ;
V_151 |= ( V_242 int ) ( V_135 & V_241 ) ;
if ( ! V_240 ) {
if ( ! ( V_135 & V_206 ) )
V_151 |= V_157 ;
V_151 &= ~ V_168 ;
} else if ( F_7 ( F_241 ( V_26 ) ) && ! F_43 () )
V_151 |= V_157 ;
if ( F_81 ( ! ( V_135 & V_206 ) ) ) {
if ( V_135 & V_243 )
V_151 |= V_192 ;
else if ( F_242 () && ( V_26 -> V_59 & V_208 ) )
V_151 |= V_192 ;
else if ( ! F_43 () &&
( ( V_26 -> V_59 & V_208 ) ||
F_7 ( F_212 ( V_207 ) ) ) )
V_151 |= V_192 ;
}
#ifdef V_109
if ( F_243 ( V_135 ) == V_122 )
V_151 |= V_158 ;
#endif
return V_151 ;
}
bool F_244 ( T_1 V_135 )
{
return ! ! ( F_240 ( V_135 ) & V_192 ) ;
}
static inline struct V_5 *
F_245 ( T_1 V_135 , unsigned int V_30 ,
struct V_160 * V_160 , enum V_218 V_184 ,
T_6 * V_183 , struct V_11 * V_126 ,
int V_6 )
{
const T_1 V_240 = V_135 & V_139 ;
struct V_5 * V_5 = NULL ;
int V_151 ;
unsigned long V_214 = 0 ;
unsigned long V_213 ;
bool V_223 = false ;
bool V_225 = false ;
bool V_224 = false ;
if ( V_30 >= V_40 ) {
F_169 ( ! ( V_135 & V_204 ) ) ;
return NULL ;
}
if ( F_132 ( V_188 ) &&
( V_135 & V_244 ) == V_244 )
goto V_245;
V_246:
if ( ! ( V_135 & V_247 ) )
F_237 ( V_30 , V_160 , V_184 ,
F_203 ( V_126 ) ) ;
V_151 = F_240 ( V_135 ) ;
if ( ! ( V_151 & V_168 ) && ! V_183 )
F_246 ( V_160 , V_184 , NULL ,
& V_126 ) ;
V_248:
V_5 = F_202 ( V_135 , V_183 , V_30 , V_160 ,
V_184 , V_151 & ~ V_192 ,
V_126 , V_6 ) ;
if ( V_5 )
goto V_249;
if ( V_151 & V_192 ) {
V_160 = F_247 ( F_248 () , V_135 ) ;
V_5 = F_235 ( V_135 , V_30 ,
V_160 , V_184 , V_183 ,
V_126 , V_6 ) ;
if ( V_5 ) {
goto V_249;
}
}
if ( ! V_240 )
goto V_245;
if ( V_26 -> V_59 & V_208 )
goto V_245;
if ( F_212 ( V_207 ) && ! ( V_135 & V_130 ) )
goto V_245;
V_5 = F_221 ( V_135 , V_30 ,
V_160 , V_184 ,
V_183 ,
V_151 , V_126 ,
V_6 , V_223 ,
& V_224 ,
& V_225 ,
& V_213 ) ;
if ( V_5 )
goto V_249;
V_223 = true ;
if ( ( V_225 || V_224 ) &&
( V_135 & V_247 ) )
goto V_245;
V_5 = F_234 ( V_135 , V_30 ,
V_160 , V_184 ,
V_183 ,
V_151 , V_126 ,
V_6 , & V_213 ) ;
if ( V_5 )
goto V_249;
if ( ! V_213 ) {
if ( ( V_135 & V_250 ) && ! ( V_135 & V_215 ) ) {
if ( V_251 )
goto V_245;
if ( ( V_26 -> V_59 & V_252 ) &&
! ( V_135 & V_130 ) )
goto V_245;
V_5 = F_216 ( V_135 , V_30 ,
V_160 , V_184 ,
V_183 , V_126 ,
V_6 ) ;
if ( V_5 )
goto V_249;
if ( ! ( V_135 & V_130 ) ) {
if ( V_30 > V_216 )
goto V_245;
if ( V_184 < V_221 )
goto V_245;
}
goto V_246;
}
}
V_214 += V_213 ;
if ( F_215 ( V_135 , V_30 , V_213 ,
V_214 ) ) {
F_236 ( V_126 , V_238 , V_25 / 50 ) ;
goto V_248;
} else {
V_5 = F_221 ( V_135 , V_30 ,
V_160 , V_184 ,
V_183 ,
V_151 , V_126 ,
V_6 , V_223 ,
& V_224 ,
& V_225 ,
& V_213 ) ;
if ( V_5 )
goto V_249;
}
V_245:
F_210 ( V_135 , V_30 , NULL ) ;
return V_5 ;
V_249:
if ( V_253 )
F_249 ( V_5 , V_30 , V_135 ) ;
return V_5 ;
}
struct V_5 *
F_250 ( T_1 V_135 , unsigned int V_30 ,
struct V_160 * V_160 , T_6 * V_183 )
{
enum V_218 V_184 = F_251 ( V_135 ) ;
struct V_11 * V_126 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_243 ( V_135 ) ;
unsigned int V_254 ;
int V_151 = V_189 | V_168 ;
struct V_255 * V_256 = NULL ;
V_135 &= V_3 ;
F_252 ( V_135 ) ;
F_253 ( V_135 & V_139 ) ;
if ( F_174 ( V_135 , V_30 ) )
return NULL ;
if ( F_7 ( ! V_160 -> V_174 -> V_11 ) )
return NULL ;
if ( ! F_254 ( V_135 , & V_256 , V_30 ) )
return NULL ;
V_257:
V_254 = F_255 () ;
F_246 ( V_160 , V_184 ,
V_183 ? : & V_169 ,
& V_126 ) ;
if ( ! V_126 )
goto V_23;
#ifdef V_109
if ( F_243 ( V_135 ) == V_122 )
V_151 |= V_158 ;
#endif
V_5 = F_202 ( V_135 | V_219 , V_183 , V_30 ,
V_160 , V_184 , V_151 ,
V_126 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
V_135 = F_256 ( V_135 ) ;
V_5 = F_245 ( V_135 , V_30 ,
V_160 , V_184 , V_183 ,
V_126 , V_6 ) ;
}
F_257 ( V_5 , V_30 , V_135 , V_6 ) ;
V_23:
if ( F_7 ( ! F_258 ( V_254 ) && ! V_5 ) )
goto V_257;
F_259 ( V_5 , V_256 , V_30 ) ;
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
void V_152 ( unsigned long V_258 , unsigned int V_30 )
{
if ( V_258 != 0 ) {
F_42 ( ! F_264 ( ( void * ) V_258 ) ) ;
F_107 ( F_163 ( ( void * ) V_258 ) , V_30 ) ;
}
}
void F_265 ( struct V_5 * V_5 , unsigned int V_30 )
{
F_266 ( V_5 , V_30 ) ;
F_107 ( V_5 , V_30 ) ;
}
void F_267 ( unsigned long V_258 , unsigned int V_30 )
{
if ( V_258 != 0 ) {
F_42 ( ! F_264 ( ( void * ) V_258 ) ) ;
F_265 ( F_163 ( ( void * ) V_258 ) , V_30 ) ;
}
}
static void * F_268 ( unsigned long V_258 , unsigned V_30 , T_9 V_90 )
{
if ( V_258 ) {
unsigned long V_259 = V_258 + ( V_78 << V_30 ) ;
unsigned long V_260 = V_258 + F_269 ( V_90 ) ;
F_160 ( F_163 ( ( void * ) V_258 ) , V_30 ) ;
while ( V_260 < V_259 ) {
F_270 ( V_260 ) ;
V_260 += V_78 ;
}
}
return ( void * ) V_258 ;
}
void * F_271 ( T_9 V_90 , T_1 V_135 )
{
unsigned int V_30 = F_272 ( V_90 ) ;
unsigned long V_258 ;
V_258 = F_260 ( V_135 , V_30 ) ;
return F_268 ( V_258 , V_30 , V_90 ) ;
}
void * F_273 ( int V_180 , T_9 V_90 , T_1 V_135 )
{
unsigned V_30 = F_272 ( V_90 ) ;
struct V_5 * V_33 = F_274 ( V_180 , V_135 , V_30 ) ;
if ( ! V_33 )
return NULL ;
return F_268 ( ( unsigned long ) F_94 ( V_33 ) , V_30 , V_90 ) ;
}
void F_275 ( void * V_261 , T_9 V_90 )
{
unsigned long V_258 = ( unsigned long ) V_261 ;
unsigned long V_262 = V_258 + F_269 ( V_90 ) ;
while ( V_258 < V_262 ) {
F_270 ( V_258 ) ;
V_258 += V_78 ;
}
}
static unsigned long F_276 ( int V_263 )
{
struct V_172 * V_148 ;
struct V_11 * V_11 ;
unsigned long V_264 = 0 ;
struct V_160 * V_160 = F_247 ( F_248 () , V_265 ) ;
F_238 (zone, z, zonelist, offset) {
unsigned long V_90 = V_11 -> V_81 ;
unsigned long V_88 = F_277 ( V_11 ) ;
if ( V_90 > V_88 )
V_264 += V_90 - V_88 ;
}
return V_264 ;
}
unsigned long F_278 ( void )
{
return F_276 ( F_251 ( V_266 ) ) ;
}
unsigned long F_279 ( void )
{
return F_276 ( F_251 ( V_267 ) ) ;
}
static inline void F_280 ( struct V_11 * V_11 )
{
if ( F_132 ( V_188 ) )
F_23 ( L_12 , F_122 ( V_11 ) ) ;
}
void F_281 ( struct V_268 * V_269 )
{
V_269 -> V_270 = V_85 ;
V_269 -> V_271 = 0 ;
V_269 -> V_272 = F_282 ( V_76 ) ;
V_269 -> V_273 = F_283 () ;
V_269 -> V_274 = V_86 ;
V_269 -> V_275 = F_284 () ;
V_269 -> V_276 = V_78 ;
}
void F_285 ( struct V_268 * V_269 , int V_180 )
{
T_10 * V_277 = F_201 ( V_180 ) ;
V_269 -> V_270 = V_277 -> V_278 ;
V_269 -> V_272 = F_286 ( V_180 , V_76 ) ;
#ifdef F_109
V_269 -> V_274 = V_277 -> V_279 [ V_280 ] . V_81 ;
V_269 -> V_275 = F_184 ( & V_277 -> V_279 [ V_280 ] ,
V_76 ) ;
#else
V_269 -> V_274 = 0 ;
V_269 -> V_275 = 0 ;
#endif
V_269 -> V_276 = V_78 ;
}
bool F_287 ( unsigned int V_59 , int V_180 )
{
bool V_12 = false ;
unsigned int V_254 ;
if ( ! ( V_59 & V_203 ) )
goto V_23;
do {
V_254 = F_255 () ;
V_12 = ! F_191 ( V_180 , V_169 ) ;
} while ( ! F_258 ( V_254 ) );
V_23:
return V_12 ;
}
static void F_288 ( unsigned char type )
{
static const char V_281 [ V_282 ] = {
[ V_8 ] = 'U' ,
[ V_105 ] = 'E' ,
[ V_122 ] = 'M' ,
[ V_104 ] = 'R' ,
#ifdef V_109
[ V_83 ] = 'C' ,
#endif
#ifdef F_289
[ V_283 ] = 'I' ,
#endif
} ;
char V_284 [ V_282 + 1 ] ;
char * V_33 = V_284 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_282 ; V_31 ++ ) {
if ( type & ( 1 << V_31 ) )
* V_33 ++ = V_281 [ V_31 ] ;
}
* V_33 = '\0' ;
F_23 ( L_13 , V_284 ) ;
}
void F_290 ( unsigned int V_202 )
{
int V_112 ;
struct V_11 * V_11 ;
F_135 (zone) {
if ( F_287 ( V_202 , F_122 ( V_11 ) ) )
continue;
F_280 ( V_11 ) ;
F_23 ( L_14 , V_11 -> V_285 ) ;
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
F_282 ( V_286 ) ,
F_282 ( V_287 ) ,
F_282 ( V_288 ) ,
F_282 ( V_289 ) ,
F_282 ( V_290 ) ,
F_282 ( V_291 ) ,
F_282 ( V_292 ) ,
F_282 ( V_293 ) ,
F_282 ( V_294 ) ,
F_282 ( V_295 ) ,
F_282 ( V_76 ) ,
F_282 ( V_296 ) ,
F_282 ( V_297 ) ,
F_282 ( V_298 ) ,
F_282 ( V_299 ) ,
F_282 ( V_300 ) ,
F_282 ( V_301 ) ,
F_282 ( V_77 ) ) ;
F_135 (zone) {
int V_31 ;
if ( F_287 ( V_202 , F_122 ( V_11 ) ) )
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
V_11 -> V_285 ,
F_291 ( F_184 ( V_11 , V_76 ) ) ,
F_291 ( F_292 ( V_11 ) ) ,
F_291 ( F_165 ( V_11 ) ) ,
F_291 ( F_277 ( V_11 ) ) ,
F_291 ( F_184 ( V_11 , V_286 ) ) ,
F_291 ( F_184 ( V_11 , V_287 ) ) ,
F_291 ( F_184 ( V_11 , V_289 ) ) ,
F_291 ( F_184 ( V_11 , V_290 ) ) ,
F_291 ( F_184 ( V_11 , V_292 ) ) ,
F_291 ( F_184 ( V_11 , V_288 ) ) ,
F_291 ( F_184 ( V_11 , V_291 ) ) ,
F_291 ( V_11 -> V_302 ) ,
F_291 ( V_11 -> V_81 ) ,
F_291 ( F_184 ( V_11 , V_303 ) ) ,
F_291 ( F_184 ( V_11 , V_293 ) ) ,
F_291 ( F_184 ( V_11 , V_294 ) ) ,
F_291 ( F_184 ( V_11 , V_298 ) ) ,
F_291 ( F_184 ( V_11 , V_299 ) ) ,
F_291 ( F_184 ( V_11 , V_296 ) ) ,
F_291 ( F_184 ( V_11 , V_297 ) ) ,
F_184 ( V_11 , V_304 ) *
V_305 / 1024 ,
F_291 ( F_184 ( V_11 , V_300 ) ) ,
F_291 ( F_184 ( V_11 , V_295 ) ) ,
F_291 ( F_184 ( V_11 , V_301 ) ) ,
F_291 ( F_184 ( V_11 , V_77 ) ) ,
F_291 ( F_184 ( V_11 , V_306 ) ) ,
V_11 -> V_69 ,
( V_11 -> V_68 ? L_53 : L_54 )
) ;
F_23 ( L_55 ) ;
for ( V_31 = 0 ; V_31 < V_307 ; V_31 ++ )
F_23 ( L_56 , V_11 -> V_154 [ V_31 ] ) ;
F_23 ( L_52 ) ;
}
F_135 (zone) {
unsigned long V_308 [ V_40 ] , V_59 , V_30 , V_309 = 0 ;
unsigned char V_281 [ V_40 ] ;
if ( F_287 ( V_202 , F_122 ( V_11 ) ) )
continue;
F_280 ( V_11 ) ;
F_23 ( L_57 , V_11 -> V_285 ) ;
F_145 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
struct V_52 * V_89 = & V_11 -> V_52 [ V_30 ] ;
int type ;
V_308 [ V_30 ] = V_89 -> V_53 ;
V_309 += V_308 [ V_30 ] << V_30 ;
V_281 [ V_30 ] = 0 ;
for ( type = 0 ; type < V_282 ; type ++ ) {
if ( ! F_77 ( & V_89 -> V_56 [ type ] ) )
V_281 [ V_30 ] |= 1 << type ;
}
}
F_153 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
F_23 ( L_58 , V_308 [ V_30 ] , F_291 ( 1UL ) << V_30 ) ;
if ( V_308 [ V_30 ] )
F_288 ( V_281 [ V_30 ] ) ;
}
F_23 ( L_59 , F_291 ( V_309 ) ) ;
}
F_23 ( L_60 , F_282 ( V_310 ) ) ;
F_293 () ;
}
static void F_294 ( struct V_11 * V_11 , struct V_172 * V_172 )
{
V_172 -> V_11 = V_11 ;
V_172 -> F_203 = F_203 ( V_11 ) ;
}
static int F_295 ( T_10 * V_277 , struct V_160 * V_160 ,
int V_311 , enum V_218 V_218 )
{
struct V_11 * V_11 ;
F_120 ( V_218 >= V_307 ) ;
V_218 ++ ;
do {
V_218 -- ;
V_11 = V_277 -> V_279 + V_218 ;
if ( F_296 ( V_11 ) ) {
F_294 ( V_11 ,
& V_160 -> V_174 [ V_311 ++ ] ) ;
F_297 ( V_218 ) ;
}
} while ( V_218 );
return V_311 ;
}
static int F_298 ( char * V_312 )
{
if ( * V_312 == 'd' || * V_312 == 'D' ) {
V_313 = V_314 ;
} else if ( * V_312 == 'n' || * V_312 == 'N' ) {
V_313 = V_315 ;
} else if ( * V_312 == 'z' || * V_312 == 'Z' ) {
V_313 = V_316 ;
} else {
F_23 ( V_317
L_61
L_62 , V_312 ) ;
return - V_318 ;
}
return 0 ;
}
static T_2 int F_299 ( char * V_312 )
{
int V_12 ;
if ( ! V_312 )
return 0 ;
V_12 = F_298 ( V_312 ) ;
if ( V_12 == 0 )
F_300 ( V_319 , V_312 , V_320 ) ;
return V_12 ;
}
int F_301 ( T_11 * V_321 , int V_322 ,
void T_12 * V_323 , T_9 * V_324 ,
T_13 * V_325 )
{
char V_326 [ V_320 ] ;
int V_12 ;
static F_302 ( V_327 ) ;
F_303 ( & V_327 ) ;
if ( V_322 )
strcpy ( V_326 , ( char * ) V_321 -> V_328 ) ;
V_12 = F_304 ( V_321 , V_322 , V_323 , V_324 , V_325 ) ;
if ( V_12 )
goto V_23;
if ( V_322 ) {
int V_329 = V_313 ;
if ( F_298 ( ( char * ) V_321 -> V_328 ) ) {
strncpy ( ( char * ) V_321 -> V_328 , V_326 ,
V_320 ) ;
V_313 = V_329 ;
} else if ( V_329 != V_313 ) {
F_303 ( & V_330 ) ;
F_305 ( NULL , NULL ) ;
F_306 ( & V_330 ) ;
}
}
V_23:
F_306 ( & V_327 ) ;
return V_12 ;
}
static int F_307 ( int V_177 , T_6 * V_331 )
{
int V_173 , V_269 ;
int V_332 = V_333 ;
int V_334 = V_335 ;
const struct V_336 * V_284 = F_308 ( 0 ) ;
if ( ! F_191 ( V_177 , * V_331 ) ) {
F_200 ( V_177 , * V_331 ) ;
return V_177 ;
}
F_309 (n, N_MEMORY) {
if ( F_191 ( V_173 , * V_331 ) )
continue;
V_269 = F_199 ( V_177 , V_173 ) ;
V_269 += ( V_173 < V_177 ) ;
V_284 = F_308 ( V_173 ) ;
if ( ! F_310 ( V_284 ) )
V_269 += V_337 ;
V_269 *= ( V_338 * V_339 ) ;
V_269 += V_340 [ V_173 ] ;
if ( V_269 < V_332 ) {
V_332 = V_269 ;
V_334 = V_173 ;
}
}
if ( V_334 >= 0 )
F_200 ( V_334 , * V_331 ) ;
return V_334 ;
}
static void F_311 ( T_10 * V_277 , int V_177 )
{
int V_341 ;
struct V_160 * V_160 ;
V_160 = & V_277 -> V_342 [ 0 ] ;
for ( V_341 = 0 ; V_160 -> V_174 [ V_341 ] . V_11 != NULL ; V_341 ++ )
;
V_341 = F_295 ( F_201 ( V_177 ) , V_160 , V_341 ,
V_307 - 1 ) ;
V_160 -> V_174 [ V_341 ] . V_11 = NULL ;
V_160 -> V_174 [ V_341 ] . F_203 = 0 ;
}
static void F_312 ( T_10 * V_277 )
{
int V_341 ;
struct V_160 * V_160 ;
V_160 = & V_277 -> V_342 [ 1 ] ;
V_341 = F_295 ( V_277 , V_160 , 0 , V_307 - 1 ) ;
V_160 -> V_174 [ V_341 ] . V_11 = NULL ;
V_160 -> V_174 [ V_341 ] . F_203 = 0 ;
}
static void F_313 ( T_10 * V_277 , int V_343 )
{
int V_344 , V_341 , V_177 ;
int V_218 ;
struct V_11 * V_148 ;
struct V_160 * V_160 ;
V_160 = & V_277 -> V_342 [ 0 ] ;
V_344 = 0 ;
for ( V_218 = V_307 - 1 ; V_218 >= 0 ; V_218 -- ) {
for ( V_341 = 0 ; V_341 < V_343 ; V_341 ++ ) {
V_177 = V_345 [ V_341 ] ;
V_148 = & F_201 ( V_177 ) -> V_279 [ V_218 ] ;
if ( F_296 ( V_148 ) ) {
F_294 ( V_148 ,
& V_160 -> V_174 [ V_344 ++ ] ) ;
F_297 ( V_218 ) ;
}
}
}
V_160 -> V_174 [ V_344 ] . V_11 = NULL ;
V_160 -> V_174 [ V_344 ] . F_203 = 0 ;
}
static int F_314 ( void )
{
int V_180 , V_218 ;
unsigned long V_346 , V_347 ;
struct V_11 * V_148 ;
int V_348 ;
V_346 = 0 ;
V_347 = 0 ;
F_198 (nid) {
for ( V_218 = 0 ; V_218 < V_307 ; V_218 ++ ) {
V_148 = & F_201 ( V_180 ) -> V_279 [ V_218 ] ;
if ( F_296 ( V_148 ) ) {
if ( V_218 < V_221 )
V_346 += V_148 -> V_302 ;
V_347 += V_148 -> V_302 ;
} else if ( V_218 == V_221 ) {
return V_315 ;
}
}
}
if ( ! V_346 ||
V_346 > V_347 / 2 )
return V_315 ;
V_348 = V_347 /
( F_315 ( V_170 [ V_171 ] ) + 1 ) ;
F_198 (nid) {
V_346 = 0 ;
V_347 = 0 ;
for ( V_218 = 0 ; V_218 < V_307 ; V_218 ++ ) {
V_148 = & F_201 ( V_180 ) -> V_279 [ V_218 ] ;
if ( F_296 ( V_148 ) ) {
if ( V_218 < V_221 )
V_346 += V_148 -> V_302 ;
V_347 += V_148 -> V_302 ;
}
}
if ( V_346 &&
V_347 > V_348 &&
V_346 > V_347 * 70 / 100 )
return V_315 ;
}
return V_316 ;
}
static void F_316 ( void )
{
if ( V_313 == V_314 )
V_349 = F_314 () ;
else
V_349 = V_313 ;
}
static void F_317 ( T_10 * V_277 )
{
int V_341 , V_177 , V_350 ;
enum V_218 V_31 ;
T_6 V_351 ;
int V_352 , V_353 ;
struct V_160 * V_160 ;
int V_30 = V_349 ;
for ( V_31 = 0 ; V_31 < V_354 ; V_31 ++ ) {
V_160 = V_277 -> V_342 + V_31 ;
V_160 -> V_174 [ 0 ] . V_11 = NULL ;
V_160 -> V_174 [ 0 ] . F_203 = 0 ;
}
V_352 = V_277 -> V_355 ;
V_350 = V_196 ;
V_353 = V_352 ;
F_318 ( V_351 ) ;
memset ( V_345 , 0 , sizeof( V_345 ) ) ;
V_341 = 0 ;
while ( ( V_177 = F_307 ( V_352 , & V_351 ) ) >= 0 ) {
if ( F_199 ( V_352 , V_177 ) !=
F_199 ( V_352 , V_353 ) )
V_340 [ V_177 ] = V_350 ;
V_353 = V_177 ;
V_350 -- ;
if ( V_30 == V_315 )
F_311 ( V_277 , V_177 ) ;
else
V_345 [ V_341 ++ ] = V_177 ;
}
if ( V_30 == V_316 ) {
F_313 ( V_277 , V_341 ) ;
}
F_312 ( V_277 ) ;
}
static void F_319 ( T_10 * V_277 )
{
struct V_160 * V_160 ;
struct V_161 * V_162 ;
struct V_172 * V_148 ;
V_160 = & V_277 -> V_342 [ 0 ] ;
V_160 -> V_164 = V_162 = & V_160 -> V_356 ;
F_189 ( V_162 -> V_166 , V_167 ) ;
for ( V_148 = V_160 -> V_174 ; V_148 -> V_11 ; V_148 ++ )
V_162 -> V_175 [ V_148 - V_160 -> V_174 ] = F_320 ( V_148 ) ;
}
int F_321 ( int V_177 )
{
struct V_11 * V_11 ;
( void ) F_246 ( F_247 ( V_177 , V_265 ) ,
F_251 ( V_265 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_177 ;
}
static void F_316 ( void )
{
V_349 = V_316 ;
}
static void F_317 ( T_10 * V_277 )
{
int V_177 , V_352 ;
enum V_218 V_341 ;
struct V_160 * V_160 ;
V_352 = V_277 -> V_355 ;
V_160 = & V_277 -> V_342 [ 0 ] ;
V_341 = F_295 ( V_277 , V_160 , 0 , V_307 - 1 ) ;
for ( V_177 = V_352 + 1 ; V_177 < V_339 ; V_177 ++ ) {
if ( ! F_322 ( V_177 ) )
continue;
V_341 = F_295 ( F_201 ( V_177 ) , V_160 , V_341 ,
V_307 - 1 ) ;
}
for ( V_177 = 0 ; V_177 < V_352 ; V_177 ++ ) {
if ( ! F_322 ( V_177 ) )
continue;
V_341 = F_295 ( F_201 ( V_177 ) , V_160 , V_341 ,
V_307 - 1 ) ;
}
V_160 -> V_174 [ V_341 ] . V_11 = NULL ;
V_160 -> V_174 [ V_341 ] . F_203 = 0 ;
}
static void F_319 ( T_10 * V_277 )
{
V_277 -> V_342 [ 0 ] . V_164 = NULL ;
}
static int F_323 ( void * V_328 )
{
int V_180 ;
int V_112 ;
T_10 * V_357 = V_328 ;
#ifdef V_188
memset ( V_340 , 0 , sizeof( V_340 ) ) ;
#endif
if ( V_357 && ! F_322 ( V_357 -> V_355 ) ) {
F_317 ( V_357 ) ;
F_319 ( V_357 ) ;
}
F_198 (nid) {
T_10 * V_277 = F_201 ( V_180 ) ;
F_317 ( V_277 ) ;
F_319 ( V_277 ) ;
}
F_324 (cpu) {
F_325 ( & F_326 ( V_358 , V_112 ) , 0 ) ;
#ifdef F_327
if ( F_328 ( V_112 ) )
F_329 ( V_112 , F_321 ( F_330 ( V_112 ) ) ) ;
#endif
}
return 0 ;
}
void T_14 F_305 ( T_10 * V_277 , struct V_11 * V_11 )
{
F_316 () ;
if ( V_359 == V_360 ) {
F_323 ( NULL ) ;
F_331 () ;
F_332 () ;
} else {
#ifdef F_333
if ( V_11 )
F_334 ( V_11 ) ;
#endif
F_335 ( F_323 , V_277 , NULL ) ;
}
V_361 = F_279 () ;
if ( V_361 < ( V_82 * V_282 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_23 ( L_63
L_64 ,
V_196 ,
V_362 [ V_349 ] ,
V_7 ? L_65 : L_66 ,
V_361 ) ;
#ifdef V_188
F_23 ( L_67 , V_363 [ V_364 ] ) ;
#endif
}
static inline unsigned long F_336 ( unsigned long V_106 )
{
unsigned long V_90 = 1 ;
V_106 /= V_365 ;
while ( V_90 < V_106 )
V_90 <<= 1 ;
V_90 = V_153 ( V_90 , 4096UL ) ;
return F_337 ( V_90 , 4UL ) ;
}
static inline unsigned long F_336 ( unsigned long V_106 )
{
return 4096UL ;
}
static inline unsigned long F_338 ( unsigned long V_90 )
{
return F_339 ( ~ V_90 ) ;
}
static int F_340 ( unsigned long V_16 , unsigned long V_98 )
{
unsigned long V_14 ;
for ( V_14 = V_16 ; V_14 < V_98 ; V_14 ++ ) {
if ( ! F_16 ( V_14 ) || F_341 ( F_125 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_342 ( struct V_11 * V_11 )
{
unsigned long V_16 , V_14 , V_98 , V_366 ;
struct V_5 * V_5 ;
unsigned long V_367 ;
int V_368 ;
V_16 = V_11 -> V_17 ;
V_98 = F_146 ( V_11 ) ;
V_16 = F_343 ( V_16 , V_82 ) ;
V_368 = F_343 ( F_292 ( V_11 ) , V_82 ) >>
V_84 ;
V_368 = V_153 ( 2 , V_368 ) ;
for ( V_14 = V_16 ; V_14 < V_98 ; V_14 += V_82 ) {
if ( ! F_147 ( V_14 ) )
continue;
V_5 = F_125 ( V_14 ) ;
if ( F_121 ( V_5 ) != F_122 ( V_11 ) )
continue;
V_367 = F_100 ( V_5 ) ;
if ( V_368 > 0 ) {
V_366 = V_153 ( V_14 + V_82 , V_98 ) ;
if ( F_340 ( V_14 , V_366 ) )
continue;
if ( V_367 == V_104 ) {
V_368 -- ;
continue;
}
if ( V_367 == V_122 ) {
F_6 ( V_5 ,
V_104 ) ;
F_124 ( V_11 , V_5 ,
V_104 ) ;
V_368 -- ;
continue;
}
}
if ( V_367 == V_104 ) {
F_6 ( V_5 , V_122 ) ;
F_124 ( V_11 , V_5 , V_122 ) ;
}
}
}
void T_3 F_344 ( unsigned long V_90 , int V_180 , unsigned long V_11 ,
unsigned long V_16 , enum V_369 V_370 )
{
struct V_5 * V_5 ;
unsigned long V_98 = V_16 + V_90 ;
unsigned long V_14 ;
struct V_11 * V_148 ;
if ( V_371 < V_98 - 1 )
V_371 = V_98 - 1 ;
V_148 = & F_201 ( V_180 ) -> V_279 [ V_11 ] ;
for ( V_14 = V_16 ; V_14 < V_98 ; V_14 ++ ) {
if ( V_370 == V_372 ) {
if ( ! F_345 ( V_14 ) )
continue;
if ( ! F_346 ( V_14 , V_180 ) )
continue;
}
V_5 = F_125 ( V_14 ) ;
F_347 ( V_5 , V_11 , V_180 , V_14 ) ;
F_348 ( V_5 , V_11 , V_180 , V_14 ) ;
F_349 ( V_5 ) ;
F_21 ( V_5 ) ;
F_74 ( V_5 ) ;
F_350 ( V_5 ) ;
if ( ( V_148 -> V_17 <= V_14 )
&& ( V_14 < F_146 ( V_148 ) )
&& ! ( V_14 & ( V_82 - 1 ) ) )
F_6 ( V_5 , V_122 ) ;
F_113 ( & V_5 -> V_51 ) ;
#ifdef F_351
if ( ! F_352 ( V_11 ) )
F_353 ( V_5 , F_354 ( V_14 << V_373 ) ) ;
#endif
}
}
static void T_3 F_355 ( struct V_11 * V_11 )
{
int V_30 , V_120 ;
F_150 (order, t) {
F_113 ( & V_11 -> V_52 [ V_30 ] . V_56 [ V_120 ] ) ;
V_11 -> V_52 [ V_30 ] . V_53 = 0 ;
}
}
static int T_3 F_356 ( struct V_11 * V_11 )
{
#ifdef F_357
int V_111 ;
V_111 = V_11 -> V_81 / 1024 ;
if ( V_111 * V_78 > 512 * 1024 )
V_111 = ( 512 * 1024 ) / V_78 ;
V_111 /= 4 ;
if ( V_111 < 1 )
V_111 = 1 ;
V_111 = F_358 ( V_111 + V_111 / 2 ) - 1 ;
return V_111 ;
#else
return 0 ;
#endif
}
static void F_325 ( struct V_113 * V_33 , unsigned long V_111 )
{
struct V_63 * V_64 ;
int V_6 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_64 = & V_33 -> V_64 ;
V_64 -> V_62 = 0 ;
V_64 -> V_88 = 6 * V_111 ;
V_64 -> V_111 = F_337 ( 1UL , 1 * V_111 ) ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ )
F_113 ( & V_64 -> V_73 [ V_6 ] ) ;
}
static void F_359 ( struct V_113 * V_33 ,
unsigned long V_88 )
{
struct V_63 * V_64 ;
V_64 = & V_33 -> V_64 ;
V_64 -> V_88 = V_88 ;
V_64 -> V_111 = F_337 ( 1UL , V_88 / 4 ) ;
if ( ( V_88 / 4 ) > ( V_373 * 8 ) )
V_64 -> V_111 = V_373 * 8 ;
}
static void T_3 F_334 ( struct V_11 * V_11 )
{
int V_112 ;
V_11 -> V_115 = F_360 ( struct V_113 ) ;
F_324 (cpu) {
struct V_113 * V_64 = F_136 ( V_11 -> V_115 , V_112 ) ;
F_325 ( V_64 , F_356 ( V_11 ) ) ;
if ( V_374 )
F_359 ( V_64 ,
( V_11 -> V_81 /
V_374 ) ) ;
}
}
void T_2 F_361 ( void )
{
struct V_11 * V_11 ;
F_135 (zone)
F_334 ( V_11 ) ;
}
static T_15 T_16
int F_362 ( struct V_11 * V_11 , unsigned long V_375 )
{
int V_31 ;
struct V_376 * V_277 = V_11 -> V_178 ;
T_9 V_377 ;
V_11 -> F_336 =
F_336 ( V_375 ) ;
V_11 -> F_338 =
F_338 ( V_11 -> F_336 ) ;
V_377 = V_11 -> F_336
* sizeof( V_378 ) ;
if ( ! F_363 () ) {
V_11 -> V_379 = ( V_378 * )
F_364 ( V_277 , V_377 ) ;
} else {
V_11 -> V_379 = F_365 ( V_377 ) ;
}
if ( ! V_11 -> V_379 )
return - V_147 ;
for( V_31 = 0 ; V_31 < V_11 -> F_336 ; ++ V_31 )
F_366 ( V_11 -> V_379 + V_31 ) ;
return 0 ;
}
static T_3 void F_367 ( struct V_11 * V_11 )
{
V_11 -> V_115 = & V_358 ;
if ( V_11 -> V_302 )
F_23 ( V_380 L_68 ,
V_11 -> V_285 , V_11 -> V_302 ,
F_356 ( V_11 ) ) ;
}
int T_3 F_368 ( struct V_11 * V_11 ,
unsigned long V_17 ,
unsigned long V_90 ,
enum V_369 V_370 )
{
struct V_376 * V_277 = V_11 -> V_178 ;
int V_12 ;
V_12 = F_362 ( V_11 , V_90 ) ;
if ( V_12 )
return V_12 ;
V_277 -> V_311 = F_203 ( V_11 ) + 1 ;
V_11 -> V_17 = V_17 ;
F_369 ( V_381 , L_69 ,
L_70 ,
V_277 -> V_355 ,
( unsigned long ) F_203 ( V_11 ) ,
V_17 , ( V_17 + V_90 ) ) ;
F_355 ( V_11 ) ;
return 0 ;
}
int T_3 F_370 ( unsigned long V_14 )
{
unsigned long V_16 , V_98 ;
int V_31 , V_180 ;
F_371 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
if ( V_16 <= V_14 && V_14 < V_98 )
return V_180 ;
return - 1 ;
}
int T_3 F_372 ( unsigned long V_14 )
{
int V_180 ;
V_180 = F_370 ( V_14 ) ;
if ( V_180 >= 0 )
return V_180 ;
return 0 ;
}
bool T_3 F_346 ( unsigned long V_14 , int V_177 )
{
int V_180 ;
V_180 = F_370 ( V_14 ) ;
if ( V_180 >= 0 && V_180 != V_177 )
return false ;
return true ;
}
void T_2 F_373 ( int V_180 , unsigned long V_382 )
{
unsigned long V_16 , V_98 ;
int V_31 , V_383 ;
F_371 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_16 = V_153 ( V_16 , V_382 ) ;
V_98 = V_153 ( V_98 , V_382 ) ;
if ( V_16 < V_98 )
F_374 ( F_201 ( V_383 ) ,
F_375 ( V_16 ) ,
( V_98 - V_16 ) << V_373 ) ;
}
}
void T_2 F_376 ( int V_180 )
{
unsigned long V_16 , V_98 ;
int V_31 , V_383 ;
F_371 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_377 ( V_383 , V_16 , V_98 ) ;
}
void T_3 F_378 ( unsigned int V_180 ,
unsigned long * V_16 , unsigned long * V_98 )
{
unsigned long V_384 , V_385 ;
int V_31 ;
* V_16 = - 1UL ;
* V_98 = 0 ;
F_371 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_16 = V_153 ( * V_16 , V_384 ) ;
* V_98 = F_337 ( * V_98 , V_385 ) ;
}
if ( * V_16 == - 1UL )
* V_16 = 0 ;
}
static void T_2 F_379 ( void )
{
int V_386 ;
for ( V_386 = V_307 - 1 ; V_386 >= 0 ; V_386 -- ) {
if ( V_386 == V_387 )
continue;
if ( V_388 [ V_386 ] >
V_389 [ V_386 ] )
break;
}
F_42 ( V_386 == - 1 ) ;
V_390 = V_386 ;
}
static void T_3 F_380 ( int V_180 ,
unsigned long V_218 ,
unsigned long V_391 ,
unsigned long V_392 ,
unsigned long * V_17 ,
unsigned long * F_146 )
{
if ( V_393 [ V_180 ] ) {
if ( V_218 == V_387 ) {
* V_17 = V_393 [ V_180 ] ;
* F_146 = V_153 ( V_392 ,
V_388 [ V_390 ] ) ;
} else if ( * V_17 < V_393 [ V_180 ] &&
* F_146 > V_393 [ V_180 ] ) {
* F_146 = V_393 [ V_180 ] ;
} else if ( * V_17 >= V_393 [ V_180 ] )
* V_17 = * F_146 ;
}
}
static unsigned long T_3 F_381 ( int V_180 ,
unsigned long V_218 ,
unsigned long * V_394 )
{
unsigned long V_391 , V_392 ;
unsigned long V_17 , F_146 ;
F_378 ( V_180 , & V_391 , & V_392 ) ;
V_17 = V_389 [ V_218 ] ;
F_146 = V_388 [ V_218 ] ;
F_380 ( V_180 , V_218 ,
V_391 , V_392 ,
& V_17 , & F_146 ) ;
if ( F_146 < V_391 || V_17 > V_392 )
return 0 ;
F_146 = V_153 ( F_146 , V_392 ) ;
V_17 = F_337 ( V_17 , V_391 ) ;
return F_146 - V_17 ;
}
unsigned long T_3 F_382 ( int V_180 ,
unsigned long V_395 ,
unsigned long V_396 )
{
unsigned long V_397 = V_396 - V_395 ;
unsigned long V_16 , V_98 ;
int V_31 ;
F_371 (i, nid, &start_pfn, &end_pfn, NULL) {
V_16 = F_383 ( V_16 , V_395 , V_396 ) ;
V_98 = F_383 ( V_98 , V_395 , V_396 ) ;
V_397 -= V_98 - V_16 ;
}
return V_397 ;
}
unsigned long T_2 F_384 ( unsigned long V_16 ,
unsigned long V_98 )
{
return F_382 ( V_339 , V_16 , V_98 ) ;
}
static unsigned long T_3 F_385 ( int V_180 ,
unsigned long V_218 ,
unsigned long * V_394 )
{
unsigned long V_398 = V_389 [ V_218 ] ;
unsigned long V_399 = V_388 [ V_218 ] ;
unsigned long V_391 , V_392 ;
unsigned long V_17 , F_146 ;
F_378 ( V_180 , & V_391 , & V_392 ) ;
V_17 = F_383 ( V_391 , V_398 , V_399 ) ;
F_146 = F_383 ( V_392 , V_398 , V_399 ) ;
F_380 ( V_180 , V_218 ,
V_391 , V_392 ,
& V_17 , & F_146 ) ;
return F_382 ( V_180 , V_17 , F_146 ) ;
}
static inline unsigned long T_3 F_381 ( int V_180 ,
unsigned long V_218 ,
unsigned long * V_400 )
{
return V_400 [ V_218 ] ;
}
static inline unsigned long T_3 F_385 ( int V_180 ,
unsigned long V_218 ,
unsigned long * V_401 )
{
if ( ! V_401 )
return 0 ;
return V_401 [ V_218 ] ;
}
static void T_3 F_386 ( struct V_376 * V_277 ,
unsigned long * V_400 , unsigned long * V_401 )
{
unsigned long V_402 , V_403 = 0 ;
enum V_218 V_31 ;
for ( V_31 = 0 ; V_31 < V_307 ; V_31 ++ )
V_403 += F_381 ( V_277 -> V_355 , V_31 ,
V_400 ) ;
V_277 -> V_404 = V_403 ;
V_402 = V_403 ;
for ( V_31 = 0 ; V_31 < V_307 ; V_31 ++ )
V_402 -=
F_385 ( V_277 -> V_355 , V_31 ,
V_401 ) ;
V_277 -> V_278 = V_402 ;
F_23 ( V_380 L_71 , V_277 -> V_355 ,
V_402 ) ;
}
static unsigned long T_2 F_387 ( unsigned long V_17 , unsigned long V_405 )
{
unsigned long V_406 ;
V_405 += V_17 & ( V_82 - 1 ) ;
V_406 = F_343 ( V_405 , V_82 ) ;
V_406 = V_406 >> V_84 ;
V_406 *= V_407 ;
V_406 = F_343 ( V_406 , 8 * sizeof( unsigned long ) ) ;
return V_406 / 8 ;
}
static void T_2 F_388 ( struct V_376 * V_277 ,
struct V_11 * V_11 ,
unsigned long V_17 ,
unsigned long V_405 )
{
unsigned long V_406 = F_387 ( V_17 , V_405 ) ;
V_11 -> V_408 = NULL ;
if ( V_406 )
V_11 -> V_408 = F_364 ( V_277 ,
V_406 ) ;
}
static inline void F_388 ( struct V_376 * V_277 , struct V_11 * V_11 ,
unsigned long V_17 , unsigned long V_405 ) {}
void T_2 F_389 ( void )
{
unsigned int V_30 ;
if ( V_84 )
return;
if ( V_409 > V_373 )
V_30 = V_410 ;
else
V_30 = V_40 - 1 ;
V_84 = V_30 ;
}
void T_2 F_389 ( void )
{
}
static unsigned long T_7 F_390 ( unsigned long V_18 ,
unsigned long V_302 )
{
unsigned long V_106 = V_18 ;
if ( V_18 > V_302 + ( V_302 >> 4 ) &&
F_132 ( V_411 ) )
V_106 = V_302 ;
return F_269 ( V_106 * sizeof( struct V_5 ) ) >> V_373 ;
}
static void T_7 F_391 ( struct V_376 * V_277 ,
unsigned long * V_400 , unsigned long * V_401 )
{
enum V_218 V_341 ;
int V_180 = V_277 -> V_355 ;
unsigned long V_17 = V_277 -> V_391 ;
int V_12 ;
F_392 ( V_277 ) ;
#ifdef F_393
F_394 ( & V_277 -> V_412 ) ;
V_277 -> V_413 = 0 ;
V_277 -> V_414 = V_22 ;
#endif
F_366 ( & V_277 -> V_415 ) ;
F_366 ( & V_277 -> V_416 ) ;
F_395 ( V_277 ) ;
for ( V_341 = 0 ; V_341 < V_307 ; V_341 ++ ) {
struct V_11 * V_11 = V_277 -> V_279 + V_341 ;
unsigned long V_90 , V_417 , V_418 , V_419 ;
V_90 = F_381 ( V_180 , V_341 , V_400 ) ;
V_417 = V_418 = V_90 - F_385 ( V_180 , V_341 ,
V_401 ) ;
V_419 = F_390 ( V_90 , V_417 ) ;
if ( V_418 >= V_419 ) {
V_418 -= V_419 ;
if ( V_419 )
F_23 ( V_380
L_72 ,
V_363 [ V_341 ] , V_419 ) ;
} else
F_23 ( V_317
L_73 ,
V_363 [ V_341 ] , V_419 , V_418 ) ;
if ( V_341 == 0 && V_418 > V_420 ) {
V_418 -= V_420 ;
F_23 ( V_380 L_74 ,
V_363 [ 0 ] , V_420 ) ;
}
if ( ! F_352 ( V_341 ) )
V_421 += V_418 ;
else if ( V_421 > V_419 * 2 )
V_421 -= V_419 ;
V_422 += V_418 ;
V_11 -> V_18 = V_90 ;
V_11 -> V_302 = V_417 ;
V_11 -> V_81 = F_352 ( V_341 ) ? V_417 : V_418 ;
#ifdef V_188
V_11 -> V_177 = V_180 ;
V_11 -> V_423 = ( V_418 * V_424 )
/ 100 ;
V_11 -> V_425 = ( V_418 * V_426 ) / 100 ;
#endif
V_11 -> V_285 = V_363 [ V_341 ] ;
F_394 ( & V_11 -> V_67 ) ;
F_394 ( & V_11 -> V_427 ) ;
F_396 ( V_11 ) ;
V_11 -> V_178 = V_277 ;
F_367 ( V_11 ) ;
F_397 ( & V_11 -> V_428 ) ;
if ( ! V_90 )
continue;
F_389 () ;
F_388 ( V_277 , V_11 , V_17 , V_90 ) ;
V_12 = F_368 ( V_11 , V_17 ,
V_90 , V_372 ) ;
F_120 ( V_12 ) ;
F_398 ( V_90 , V_180 , V_341 , V_17 ) ;
V_17 += V_90 ;
}
}
static void T_16 F_399 ( struct V_376 * V_277 )
{
if ( ! V_277 -> V_404 )
return;
#ifdef F_400
if ( ! V_277 -> V_429 ) {
unsigned long V_90 , V_430 , V_262 ;
struct V_5 * V_431 ;
V_430 = V_277 -> V_391 & ~ ( V_432 - 1 ) ;
V_262 = F_401 ( V_277 ) ;
V_262 = F_402 ( V_262 , V_432 ) ;
V_90 = ( V_262 - V_430 ) * sizeof( struct V_5 ) ;
V_431 = F_403 ( V_277 -> V_355 , V_90 ) ;
if ( ! V_431 )
V_431 = F_364 ( V_277 , V_90 ) ;
V_277 -> V_429 = V_431 + ( V_277 -> V_391 - V_430 ) ;
}
#ifndef F_404
if ( V_277 == F_201 ( 0 ) ) {
V_433 = F_201 ( 0 ) -> V_429 ;
#ifdef F_405
if ( F_10 ( V_433 ) != V_277 -> V_391 )
V_433 -= ( V_277 -> V_391 - V_434 ) ;
#endif
}
#endif
#endif
}
void T_7 F_406 ( int V_180 , unsigned long * V_400 ,
unsigned long V_391 , unsigned long * V_401 )
{
T_10 * V_277 = F_201 ( V_180 ) ;
F_2 ( V_277 -> V_311 || V_277 -> V_150 ) ;
V_277 -> V_355 = V_180 ;
V_277 -> V_391 = V_391 ;
F_197 ( V_180 ) ;
F_386 ( V_277 , V_400 , V_401 ) ;
F_399 ( V_277 ) ;
#ifdef F_400
F_23 ( V_380 L_75 ,
V_180 , ( unsigned long ) V_277 ,
( unsigned long ) V_277 -> V_429 ) ;
#endif
F_391 ( V_277 , V_400 , V_401 ) ;
}
static void T_2 F_407 ( void )
{
unsigned int V_177 ;
unsigned int V_435 = 0 ;
F_408 (node, node_possible_map)
V_435 = V_177 ;
V_436 = V_435 + 1 ;
}
static inline void F_407 ( void )
{
}
unsigned long T_2 F_409 ( void )
{
unsigned long V_437 = 0 , V_438 = 0 ;
unsigned long V_430 , V_262 , V_439 ;
int V_440 = - 1 ;
int V_31 , V_180 ;
F_371 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_430 || V_440 < 0 || V_440 == V_180 ) {
V_440 = V_180 ;
V_438 = V_262 ;
continue;
}
V_439 = ~ ( ( 1 << F_410 ( V_430 ) ) - 1 ) ;
while ( V_439 && V_438 <= ( V_430 & ( V_439 << 1 ) ) )
V_439 <<= 1 ;
V_437 |= V_439 ;
}
return ~ V_437 + 1 ;
}
static unsigned long T_2 F_411 ( int V_180 )
{
unsigned long V_441 = V_442 ;
unsigned long V_16 ;
int V_31 ;
F_371 (i, nid, &start_pfn, NULL, NULL)
V_441 = V_153 ( V_441 , V_16 ) ;
if ( V_441 == V_442 ) {
F_23 ( V_317
L_76 , V_180 ) ;
return 0 ;
}
return V_441 ;
}
unsigned long T_2 F_412 ( void )
{
return F_411 ( V_339 ) ;
}
static unsigned long T_2 F_413 ( void )
{
unsigned long V_403 = 0 ;
unsigned long V_16 , V_98 ;
int V_31 , V_180 ;
F_371 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_106 = V_98 - V_16 ;
V_403 += V_106 ;
if ( V_106 )
F_414 ( V_180 , V_171 ) ;
}
return V_403 ;
}
static void T_2 F_415 ( void )
{
int V_31 , V_180 ;
unsigned long V_443 ;
unsigned long V_444 , V_445 ;
T_6 V_446 = V_170 [ V_171 ] ;
unsigned long V_403 = F_413 () ;
int V_447 = F_315 ( V_170 [ V_171 ] ) ;
if ( V_448 ) {
unsigned long V_449 ;
V_448 =
F_343 ( V_448 , V_432 ) ;
V_449 = V_403 - V_448 ;
V_450 = F_337 ( V_450 , V_449 ) ;
}
if ( ! V_450 )
goto V_23;
F_379 () ;
V_443 = V_389 [ V_390 ] ;
V_246:
V_444 = V_450 / V_447 ;
F_309 (nid, N_MEMORY) {
unsigned long V_16 , V_98 ;
if ( V_450 < V_444 )
V_444 = V_450 / V_447 ;
V_445 = V_444 ;
F_371 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_451 ;
V_16 = F_337 ( V_16 , V_393 [ V_180 ] ) ;
if ( V_16 >= V_98 )
continue;
if ( V_16 < V_443 ) {
unsigned long V_452 ;
V_452 = V_153 ( V_98 , V_443 )
- V_16 ;
V_445 -= V_153 ( V_452 ,
V_445 ) ;
V_450 -= V_153 ( V_452 ,
V_450 ) ;
if ( V_98 <= V_443 ) {
V_393 [ V_180 ] = V_98 ;
continue;
}
V_16 = V_443 ;
}
V_451 = V_98 - V_16 ;
if ( V_451 > V_445 )
V_451 = V_445 ;
V_393 [ V_180 ] = V_16 + V_451 ;
V_450 -= V_153 ( V_450 ,
V_451 ) ;
V_445 -= V_451 ;
if ( ! V_445 )
break;
}
}
V_447 -- ;
if ( V_447 && V_450 > V_447 )
goto V_246;
for ( V_180 = 0 ; V_180 < V_339 ; V_180 ++ )
V_393 [ V_180 ] =
F_343 ( V_393 [ V_180 ] , V_432 ) ;
V_23:
V_170 [ V_171 ] = V_446 ;
}
static void F_416 ( T_10 * V_277 , int V_180 )
{
enum V_218 V_218 ;
if ( V_171 == V_453 )
return;
for ( V_218 = 0 ; V_218 <= V_387 - 1 ; V_218 ++ ) {
struct V_11 * V_11 = & V_277 -> V_279 [ V_218 ] ;
if ( V_11 -> V_302 ) {
F_414 ( V_180 , V_454 ) ;
if ( V_453 != V_454 &&
V_218 <= V_221 )
F_414 ( V_180 , V_453 ) ;
break;
}
}
}
void T_2 F_417 ( unsigned long * V_119 )
{
unsigned long V_16 , V_98 ;
int V_31 , V_180 ;
memset ( V_389 , 0 ,
sizeof( V_389 ) ) ;
memset ( V_388 , 0 ,
sizeof( V_388 ) ) ;
V_389 [ 0 ] = F_412 () ;
V_388 [ 0 ] = V_119 [ 0 ] ;
for ( V_31 = 1 ; V_31 < V_307 ; V_31 ++ ) {
if ( V_31 == V_387 )
continue;
V_389 [ V_31 ] =
V_388 [ V_31 - 1 ] ;
V_388 [ V_31 ] =
F_337 ( V_119 [ V_31 ] , V_389 [ V_31 ] ) ;
}
V_389 [ V_387 ] = 0 ;
V_388 [ V_387 ] = 0 ;
memset ( V_393 , 0 , sizeof( V_393 ) ) ;
F_415 () ;
F_23 ( L_77 ) ;
for ( V_31 = 0 ; V_31 < V_307 ; V_31 ++ ) {
if ( V_31 == V_387 )
continue;
F_23 ( V_455 L_78 , V_363 [ V_31 ] ) ;
if ( V_389 [ V_31 ] ==
V_388 [ V_31 ] )
F_23 ( V_455 L_79 ) ;
else
F_23 ( V_455 L_80 ,
V_389 [ V_31 ] << V_373 ,
( V_388 [ V_31 ]
<< V_373 ) - 1 ) ;
}
F_23 ( L_81 ) ;
for ( V_31 = 0 ; V_31 < V_339 ; V_31 ++ ) {
if ( V_393 [ V_31 ] )
F_23 ( L_82 , V_31 ,
V_393 [ V_31 ] << V_373 ) ;
}
F_23 ( L_83 ) ;
F_371 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_23 ( L_84 , V_180 ,
V_16 << V_373 , ( V_98 << V_373 ) - 1 ) ;
F_418 () ;
F_407 () ;
F_198 (nid) {
T_10 * V_277 = F_201 ( V_180 ) ;
F_406 ( V_180 , NULL ,
F_411 ( V_180 ) , NULL ) ;
if ( V_277 -> V_278 )
F_414 ( V_180 , V_171 ) ;
F_416 ( V_277 , V_180 ) ;
}
}
static int T_2 F_419 ( char * V_33 , unsigned long * V_456 )
{
unsigned long long V_457 ;
if ( ! V_33 )
return - V_318 ;
V_457 = F_420 ( V_33 , & V_33 ) ;
* V_456 = V_457 >> V_373 ;
F_2 ( ( V_457 >> V_373 ) > V_442 ) ;
return 0 ;
}
static int T_2 F_421 ( char * V_33 )
{
return F_419 ( V_33 , & V_450 ) ;
}
static int T_2 F_422 ( char * V_33 )
{
return F_419 ( V_33 , & V_448 ) ;
}
void T_2 F_423 ( unsigned long V_458 )
{
V_420 = V_458 ;
}
void T_2 F_424 ( unsigned long * V_400 )
{
F_406 ( 0 , V_400 ,
F_425 ( V_459 ) >> V_373 , NULL ) ;
}
static int F_426 ( struct V_460 * V_357 ,
unsigned long V_461 , void * V_462 )
{
int V_112 = ( unsigned long ) V_462 ;
if ( V_461 == V_463 || V_461 == V_464 ) {
F_427 ( V_112 ) ;
F_134 ( V_112 ) ;
F_428 ( V_112 ) ;
F_429 ( V_112 ) ;
}
return V_465 ;
}
void T_2 F_430 ( void )
{
F_431 ( F_426 , 0 ) ;
}
static void F_432 ( void )
{
struct V_376 * V_277 ;
unsigned long V_466 = 0 ;
enum V_218 V_31 , V_341 ;
F_433 (pgdat) {
for ( V_31 = 0 ; V_31 < V_307 ; V_31 ++ ) {
struct V_11 * V_11 = V_277 -> V_279 + V_31 ;
unsigned long F_337 = 0 ;
for ( V_341 = V_31 ; V_341 < V_307 ; V_341 ++ ) {
if ( V_11 -> V_154 [ V_341 ] > F_337 )
F_337 = V_11 -> V_154 [ V_341 ] ;
}
F_337 += F_277 ( V_11 ) ;
if ( F_337 > V_11 -> V_81 )
F_337 = V_11 -> V_81 ;
V_466 += F_337 ;
V_11 -> V_467 = F_337 ;
}
}
V_467 = V_466 ;
V_468 = V_466 ;
}
static void F_434 ( void )
{
struct V_376 * V_277 ;
enum V_218 V_341 , V_469 ;
F_433 (pgdat) {
for ( V_341 = 0 ; V_341 < V_307 ; V_341 ++ ) {
struct V_11 * V_11 = V_277 -> V_279 + V_341 ;
unsigned long V_81 = V_11 -> V_81 ;
V_11 -> V_154 [ V_341 ] = 0 ;
V_469 = V_341 ;
while ( V_469 ) {
struct V_11 * V_470 ;
V_469 -- ;
if ( V_471 [ V_469 ] < 1 )
V_471 [ V_469 ] = 1 ;
V_470 = V_277 -> V_279 + V_469 ;
V_470 -> V_154 [ V_341 ] = V_81 /
V_471 [ V_469 ] ;
V_81 += V_470 -> V_81 ;
}
}
}
F_432 () ;
}
static void F_435 ( void )
{
unsigned long V_472 = V_473 >> ( V_373 - 10 ) ;
unsigned long V_474 = 0 ;
struct V_11 * V_11 ;
unsigned long V_59 ;
F_436 (zone) {
if ( ! F_437 ( V_11 ) )
V_474 += V_11 -> V_81 ;
}
F_436 (zone) {
T_17 V_284 ;
F_145 ( & V_11 -> V_67 , V_59 ) ;
V_284 = ( T_17 ) V_472 * V_11 -> V_81 ;
F_438 ( V_284 , V_474 ) ;
if ( F_437 ( V_11 ) ) {
unsigned long V_475 ;
V_475 = V_11 -> V_81 / 1024 ;
V_475 = F_383 ( V_475 , V_476 , 128UL ) ;
V_11 -> V_124 [ V_477 ] = V_475 ;
} else {
V_11 -> V_124 [ V_477 ] = V_284 ;
}
V_11 -> V_124 [ V_478 ] = F_292 ( V_11 ) + ( V_284 >> 2 ) ;
V_11 -> V_124 [ V_479 ] = F_292 ( V_11 ) + ( V_284 >> 1 ) ;
F_342 ( V_11 ) ;
F_153 ( & V_11 -> V_67 , V_59 ) ;
}
F_432 () ;
}
void F_439 ( void )
{
F_303 ( & V_330 ) ;
F_435 () ;
F_306 ( & V_330 ) ;
}
static void T_3 F_440 ( struct V_11 * V_11 )
{
unsigned int V_480 , V_481 ;
V_480 = V_11 -> V_81 >> ( 30 - V_373 ) ;
if ( V_480 )
V_481 = F_441 ( 10 * V_480 ) ;
else
V_481 = 1 ;
V_11 -> V_482 = V_481 ;
}
static void T_3 F_442 ( void )
{
struct V_11 * V_11 ;
F_436 (zone)
F_440 ( V_11 ) ;
}
int T_3 F_443 ( void )
{
unsigned long V_483 ;
V_483 = F_278 () * ( V_78 >> 10 ) ;
V_473 = F_441 ( V_483 * 16 ) ;
if ( V_473 < 128 )
V_473 = 128 ;
if ( V_473 > 65536 )
V_473 = 65536 ;
F_439 () ;
F_444 () ;
F_434 () ;
F_442 () ;
return 0 ;
}
int F_445 ( T_11 * V_321 , int V_322 ,
void T_12 * V_323 , T_9 * V_324 , T_13 * V_325 )
{
F_446 ( V_321 , V_322 , V_323 , V_324 , V_325 ) ;
if ( V_322 )
F_439 () ;
return 0 ;
}
int F_447 ( T_11 * V_321 , int V_322 ,
void T_12 * V_323 , T_9 * V_324 , T_13 * V_325 )
{
struct V_11 * V_11 ;
int V_484 ;
V_484 = F_448 ( V_321 , V_322 , V_323 , V_324 , V_325 ) ;
if ( V_484 )
return V_484 ;
F_436 (zone)
V_11 -> V_423 = ( V_11 -> V_81 *
V_424 ) / 100 ;
return 0 ;
}
int F_449 ( T_11 * V_321 , int V_322 ,
void T_12 * V_323 , T_9 * V_324 , T_13 * V_325 )
{
struct V_11 * V_11 ;
int V_484 ;
V_484 = F_448 ( V_321 , V_322 , V_323 , V_324 , V_325 ) ;
if ( V_484 )
return V_484 ;
F_436 (zone)
V_11 -> V_425 = ( V_11 -> V_81 *
V_426 ) / 100 ;
return 0 ;
}
int F_450 ( T_11 * V_321 , int V_322 ,
void T_12 * V_323 , T_9 * V_324 , T_13 * V_325 )
{
F_448 ( V_321 , V_322 , V_323 , V_324 , V_325 ) ;
F_434 () ;
return 0 ;
}
int F_451 ( T_11 * V_321 , int V_322 ,
void T_12 * V_323 , T_9 * V_324 , T_13 * V_325 )
{
struct V_11 * V_11 ;
unsigned int V_112 ;
int V_12 ;
V_12 = F_448 ( V_321 , V_322 , V_323 , V_324 , V_325 ) ;
if ( ! V_322 || ( V_12 < 0 ) )
return V_12 ;
F_135 (zone) {
F_324 (cpu) {
unsigned long V_88 ;
V_88 = V_11 -> V_81 / V_374 ;
F_359 (
F_136 ( V_11 -> V_115 , V_112 ) , V_88 ) ;
}
}
return 0 ;
}
static int T_2 F_452 ( char * V_132 )
{
if ( ! V_132 )
return 0 ;
V_485 = F_453 ( V_132 , & V_132 , 0 ) ;
return 1 ;
}
void * T_2 F_454 ( const char * V_486 ,
unsigned long V_487 ,
unsigned long V_488 ,
int V_489 ,
int V_59 ,
unsigned int * V_490 ,
unsigned int * V_491 ,
unsigned long V_492 ,
unsigned long V_493 )
{
unsigned long long F_337 = V_493 ;
unsigned long V_494 , V_90 ;
void * V_321 = NULL ;
if ( ! V_488 ) {
V_488 = V_421 ;
V_488 += ( 1UL << ( 20 - V_373 ) ) - 1 ;
V_488 >>= 20 - V_373 ;
V_488 <<= 20 - V_373 ;
if ( V_489 > V_373 )
V_488 >>= ( V_489 - V_373 ) ;
else
V_488 <<= ( V_373 - V_489 ) ;
if ( F_7 ( V_59 & V_495 ) ) {
F_2 ( ! ( V_59 & V_496 ) ) ;
if ( ! ( V_488 >> * V_490 ) ) {
V_488 = 1UL << * V_490 ;
F_120 ( ! V_488 ) ;
}
} else if ( F_7 ( ( V_488 * V_487 ) < V_78 ) )
V_488 = V_78 / V_487 ;
}
V_488 = F_455 ( V_488 ) ;
if ( F_337 == 0 ) {
F_337 = ( ( unsigned long long ) V_422 << V_373 ) >> 4 ;
F_438 ( F_337 , V_487 ) ;
}
F_337 = V_153 ( F_337 , 0x80000000ULL ) ;
if ( V_488 < V_492 )
V_488 = V_492 ;
if ( V_488 > F_337 )
V_488 = F_337 ;
V_494 = F_456 ( V_488 ) ;
do {
V_90 = V_487 << V_494 ;
if ( V_59 & V_496 )
V_321 = F_457 ( V_90 ) ;
else if ( V_485 )
V_321 = F_458 ( V_90 , V_497 , V_498 ) ;
else {
if ( F_272 ( V_90 ) < V_40 ) {
V_321 = F_271 ( V_90 , V_497 ) ;
F_459 ( V_321 , V_90 , 1 , V_497 ) ;
}
}
} while ( ! V_321 && V_90 > V_78 && -- V_494 );
if ( ! V_321 )
F_460 ( L_85 , V_486 ) ;
F_23 ( V_43 L_86 ,
V_486 ,
( 1UL << V_494 ) ,
F_456 ( V_90 ) - V_373 ,
V_90 ) ;
if ( V_490 )
* V_490 = V_494 ;
if ( V_491 )
* V_491 = ( 1 << V_494 ) - 1 ;
return V_321 ;
}
static inline unsigned long * F_461 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef V_411
return F_462 ( V_14 ) -> V_408 ;
#else
return V_11 -> V_408 ;
#endif
}
static inline int F_463 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef V_411
V_14 &= ( V_499 - 1 ) ;
return ( V_14 >> V_84 ) * V_407 ;
#else
V_14 = V_14 - F_464 ( V_11 -> V_17 , V_82 ) ;
return ( V_14 >> V_84 ) * V_407 ;
#endif
}
unsigned long F_465 ( struct V_5 * V_5 ,
int V_500 , int V_501 )
{
struct V_11 * V_11 ;
unsigned long * V_502 ;
unsigned long V_14 , V_503 ;
unsigned long V_59 = 0 ;
unsigned long V_504 = 1 ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_502 = F_461 ( V_11 , V_14 ) ;
V_503 = F_463 ( V_11 , V_14 ) ;
for (; V_500 <= V_501 ; V_500 ++ , V_504 <<= 1 )
if ( F_192 ( V_503 + V_500 , V_502 ) )
V_59 |= V_504 ;
return V_59 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_59 ,
int V_500 , int V_501 )
{
struct V_11 * V_11 ;
unsigned long * V_502 ;
unsigned long V_14 , V_503 ;
unsigned long V_504 = 1 ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_502 = F_461 ( V_11 , V_14 ) ;
V_503 = F_463 ( V_11 , V_14 ) ;
F_42 ( ! F_12 ( V_11 , V_14 ) ) ;
for (; V_500 <= V_501 ; V_500 ++ , V_504 <<= 1 )
if ( V_59 & V_504 )
F_48 ( V_503 + V_500 , V_502 ) ;
else
F_50 ( V_503 + V_500 , V_502 ) ;
}
bool F_466 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_62 ,
bool V_505 )
{
unsigned long V_14 , V_506 , V_507 ;
int V_74 ;
if ( F_203 ( V_11 ) == V_387 )
return false ;
V_74 = F_100 ( V_5 ) ;
if ( V_74 == V_122 || F_84 ( V_74 ) )
return false ;
V_14 = F_10 ( V_5 ) ;
for ( V_507 = 0 , V_506 = 0 ; V_506 < V_82 ; V_506 ++ ) {
unsigned long V_508 = V_14 + V_506 ;
if ( ! F_16 ( V_508 ) )
continue;
V_5 = F_125 ( V_508 ) ;
if ( ! F_72 ( & V_5 -> V_58 ) ) {
if ( F_62 ( V_5 ) )
V_506 += ( 1 << F_60 ( V_5 ) ) - 1 ;
continue;
}
if ( V_505 && F_20 ( V_5 ) )
continue;
if ( ! F_467 ( V_5 ) )
V_507 ++ ;
if ( V_507 > V_62 )
return true ;
}
return false ;
}
bool F_468 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_322 ( F_121 ( V_5 ) ) )
return false ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_11 , V_14 ) )
return false ;
return ! F_466 ( V_11 , V_5 , 0 , true ) ;
}
static unsigned long F_469 ( unsigned long V_14 )
{
return V_14 & ~ ( F_470 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_471 ( unsigned long V_14 )
{
return F_402 ( V_14 , F_470 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_472 ( struct V_509 * V_510 ,
unsigned long V_430 , unsigned long V_262 )
{
unsigned long V_511 ;
unsigned long V_14 = V_430 ;
unsigned int V_512 = 0 ;
int V_12 = 0 ;
F_473 () ;
while ( V_14 < V_262 || ! F_77 ( & V_510 -> V_513 ) ) {
if ( F_474 ( V_26 ) ) {
V_12 = - V_514 ;
break;
}
if ( F_77 ( & V_510 -> V_513 ) ) {
V_510 -> V_515 = 0 ;
V_14 = F_475 ( V_510 -> V_11 , V_510 ,
V_14 , V_262 , true ) ;
if ( ! V_14 ) {
V_12 = - V_514 ;
break;
}
V_512 = 0 ;
} else if ( ++ V_512 == 5 ) {
V_12 = V_12 < 0 ? V_12 : - V_516 ;
break;
}
V_511 = F_476 ( V_510 -> V_11 ,
& V_510 -> V_513 ) ;
V_510 -> V_515 -= V_511 ;
V_12 = F_477 ( & V_510 -> V_513 , V_517 ,
0 , V_518 , V_519 ) ;
}
if ( V_12 < 0 ) {
F_478 ( & V_510 -> V_513 ) ;
return V_12 ;
}
return 0 ;
}
int F_479 ( unsigned long V_430 , unsigned long V_262 ,
unsigned V_6 )
{
unsigned long V_520 , V_521 ;
int V_12 = 0 , V_30 ;
struct V_509 V_510 = {
. V_515 = 0 ,
. V_30 = - 1 ,
. V_11 = F_17 ( F_125 ( V_430 ) ) ,
. V_522 = true ,
. V_523 = true ,
} ;
F_113 ( & V_510 . V_513 ) ;
V_12 = F_480 ( F_469 ( V_430 ) ,
F_471 ( V_262 ) , V_6 ,
false ) ;
if ( V_12 )
return V_12 ;
V_12 = F_472 ( & V_510 , V_430 , V_262 ) ;
if ( V_12 )
goto V_524;
F_481 () ;
F_139 () ;
V_30 = 0 ;
V_520 = V_430 ;
while ( ! F_62 ( F_125 ( V_520 ) ) ) {
if ( ++ V_30 >= V_40 ) {
V_12 = - V_516 ;
goto V_524;
}
V_520 &= ~ 0UL << V_30 ;
}
if ( F_482 ( V_520 , V_262 , false ) ) {
F_213 ( L_87 ,
V_520 , V_262 ) ;
V_12 = - V_516 ;
goto V_524;
}
V_521 = F_483 ( & V_510 , V_520 , V_262 ) ;
if ( ! V_521 ) {
V_12 = - V_516 ;
goto V_524;
}
if ( V_430 != V_520 )
F_484 ( V_520 , V_430 - V_520 ) ;
if ( V_262 != V_521 )
F_484 ( V_262 , V_521 - V_262 ) ;
V_524:
F_485 ( F_469 ( V_430 ) ,
F_471 ( V_262 ) , V_6 ) ;
return V_12 ;
}
void F_484 ( unsigned long V_14 , unsigned V_32 )
{
unsigned int V_62 = 0 ;
for (; V_32 -- ; V_14 ++ ) {
struct V_5 * V_5 = F_125 ( V_14 ) ;
V_62 += F_61 ( V_5 ) != 1 ;
F_486 ( V_5 ) ;
}
F_487 ( V_62 != 0 , L_88 , V_62 ) ;
}
static int T_3 F_488 ( void * V_328 )
{
struct V_11 * V_11 = V_328 ;
int V_112 ;
unsigned long V_111 = F_356 ( V_11 ) , V_59 ;
F_324 (cpu) {
struct V_113 * V_114 ;
struct V_63 * V_64 ;
V_114 = F_136 ( V_11 -> V_115 , V_112 ) ;
V_64 = & V_114 -> V_64 ;
F_98 ( V_59 ) ;
if ( V_64 -> V_62 > 0 )
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
F_489 ( V_11 , V_114 ) ;
F_325 ( V_114 , V_111 ) ;
F_102 ( V_59 ) ;
}
return 0 ;
}
void T_3 F_490 ( struct V_11 * V_11 )
{
F_335 ( F_488 , V_11 , NULL ) ;
}
void F_491 ( struct V_11 * V_11 )
{
unsigned long V_59 ;
int V_112 ;
struct V_113 * V_114 ;
F_98 ( V_59 ) ;
if ( V_11 -> V_115 != & V_358 ) {
F_140 (cpu) {
V_114 = F_136 ( V_11 -> V_115 , V_112 ) ;
F_489 ( V_11 , V_114 ) ;
}
F_492 ( V_11 -> V_115 ) ;
V_11 -> V_115 = & V_358 ;
}
F_102 ( V_59 ) ;
}
void
F_493 ( unsigned long V_16 , unsigned long V_98 )
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
F_350 ( V_5 ) ;
continue;
}
F_120 ( F_61 ( V_5 ) ) ;
F_120 ( ! F_62 ( V_5 ) ) ;
V_30 = F_60 ( V_5 ) ;
#ifdef F_494
F_23 ( V_43 L_89 ,
V_14 , 1 << V_30 , V_98 ) ;
#endif
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
V_11 -> V_52 [ V_30 ] . V_53 -- ;
for ( V_31 = 0 ; V_31 < ( 1 << V_30 ) ; V_31 ++ )
F_350 ( ( V_5 + V_31 ) ) ;
V_14 += ( 1 << V_30 ) ;
}
F_153 ( & V_11 -> V_67 , V_59 ) ;
}
bool F_495 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_17 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_59 ;
int V_30 ;
F_145 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
struct V_5 * V_525 = V_5 - ( V_14 & ( ( 1 << V_30 ) - 1 ) ) ;
if ( F_62 ( V_525 ) && F_60 ( V_525 ) >= V_30 )
break;
}
F_153 ( & V_11 -> V_67 , V_59 ) ;
return V_30 < V_40 ;
}
static void F_496 ( unsigned long V_59 )
{
const char * V_526 = L_90 ;
unsigned long V_439 ;
int V_31 ;
F_207 ( F_497 ( V_527 ) != V_528 ) ;
F_23 ( V_24 L_91 , V_59 ) ;
V_59 &= ( 1UL << V_529 ) - 1 ;
for ( V_31 = 0 ; V_31 < F_497 ( V_527 ) && V_59 ; V_31 ++ ) {
V_439 = V_527 [ V_31 ] . V_439 ;
if ( ( V_59 & V_439 ) != V_439 )
continue;
V_59 &= ~ V_439 ;
F_23 ( L_92 , V_526 , V_527 [ V_31 ] . V_285 ) ;
V_526 = L_93 ;
}
if ( V_59 )
F_23 ( L_94 , V_526 , V_59 ) ;
F_23 ( L_95 ) ;
}
void F_24 ( struct V_5 * V_5 )
{
F_23 ( V_24
L_96 ,
V_5 , F_72 ( & V_5 -> V_58 ) , F_71 ( V_5 ) ,
V_5 -> V_57 , V_5 -> V_530 ) ;
F_496 ( V_5 -> V_59 ) ;
F_498 ( V_5 ) ;
}
