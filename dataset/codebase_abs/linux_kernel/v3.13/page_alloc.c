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
V_15 , V_17 , V_17 + V_16 ) ;
return V_13 ;
}
static int F_15 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
if ( ! F_16 ( F_10 ( V_5 ) ) )
return 0 ;
if ( V_12 != F_17 ( V_5 ) )
return 0 ;
return 1 ;
}
static int F_18 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
if ( F_9 ( V_12 , V_5 ) )
return 1 ;
if ( ! F_15 ( V_12 , V_5 ) )
return 1 ;
return 0 ;
}
static inline int F_18 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
return 0 ;
}
static void F_19 ( struct V_5 * V_5 )
{
static unsigned long V_20 ;
static unsigned long V_21 ;
static unsigned long V_22 ;
if ( F_20 ( V_5 ) ) {
F_21 ( V_5 ) ;
return;
}
if ( V_21 == 60 ) {
if ( F_22 ( V_23 , V_20 ) ) {
V_22 ++ ;
goto V_24;
}
if ( V_22 ) {
F_23 ( V_25
L_2 ,
V_22 ) ;
V_22 = 0 ;
}
V_21 = 0 ;
}
if ( V_21 ++ == 0 )
V_20 = V_23 + 60 * V_26 ;
F_23 ( V_25 L_3 ,
V_27 -> V_28 , F_10 ( V_5 ) ) ;
F_24 ( V_5 ) ;
F_25 () ;
F_26 () ;
V_24:
F_21 ( V_5 ) ;
F_27 ( V_29 , V_30 ) ;
}
static void F_28 ( struct V_5 * V_5 )
{
F_29 ( V_5 , F_30 ( V_5 ) ) ;
}
void F_31 ( struct V_5 * V_5 , unsigned long V_31 )
{
int V_32 ;
int V_33 = 1 << V_31 ;
F_32 ( V_5 , F_28 ) ;
F_33 ( V_5 , V_31 ) ;
F_34 ( V_5 ) ;
for ( V_32 = 1 ; V_32 < V_33 ; V_32 ++ ) {
struct V_5 * V_34 = V_5 + V_32 ;
F_35 ( V_34 ) ;
F_36 ( V_34 , 0 ) ;
V_34 -> V_35 = V_5 ;
}
}
static int F_37 ( struct V_5 * V_5 , unsigned long V_31 )
{
int V_32 ;
int V_33 = 1 << V_31 ;
int V_36 = 0 ;
if ( F_7 ( F_30 ( V_5 ) != V_31 ) ) {
F_19 ( V_5 ) ;
V_36 ++ ;
}
F_38 ( V_5 ) ;
for ( V_32 = 1 ; V_32 < V_33 ; V_32 ++ ) {
struct V_5 * V_34 = V_5 + V_32 ;
if ( F_7 ( ! F_39 ( V_34 ) || ( V_34 -> V_35 != V_5 ) ) ) {
F_19 ( V_5 ) ;
V_36 ++ ;
}
F_40 ( V_34 ) ;
}
return V_36 ;
}
static inline void F_41 ( struct V_5 * V_5 , int V_31 , T_1 V_37 )
{
int V_32 ;
F_42 ( ( V_37 & V_38 ) && F_43 () ) ;
for ( V_32 = 0 ; V_32 < ( 1 << V_31 ) ; V_32 ++ )
F_44 ( V_5 + V_32 ) ;
}
static int T_2 F_45 ( char * V_39 )
{
unsigned long V_40 ;
if ( F_46 ( V_39 , 10 , & V_40 ) < 0 || V_40 > V_41 / 2 ) {
F_23 ( V_42 L_4 ) ;
return 0 ;
}
V_43 = V_40 ;
F_23 ( V_44 L_5 , V_40 ) ;
return 0 ;
}
static inline void F_47 ( struct V_5 * V_5 )
{
F_48 ( V_45 , & V_5 -> V_46 ) ;
}
static inline void F_49 ( struct V_5 * V_5 )
{
F_50 ( V_45 , & V_5 -> V_46 ) ;
}
static inline void F_47 ( struct V_5 * V_5 ) { }
static inline void F_49 ( struct V_5 * V_5 ) { }
static inline void F_51 ( struct V_5 * V_5 , int V_31 )
{
F_52 ( V_5 , V_31 ) ;
F_53 ( V_5 ) ;
}
static inline void F_54 ( struct V_5 * V_5 )
{
F_55 ( V_5 ) ;
F_52 ( V_5 , 0 ) ;
}
static inline unsigned long
F_56 ( unsigned long V_47 , unsigned int V_31 )
{
return V_47 ^ ( 1 << V_31 ) ;
}
static inline int F_57 ( struct V_5 * V_5 , struct V_5 * V_48 ,
int V_31 )
{
if ( ! F_16 ( F_10 ( V_48 ) ) )
return 0 ;
if ( F_58 ( V_5 ) != F_58 ( V_48 ) )
return 0 ;
if ( F_59 ( V_48 ) && F_60 ( V_48 ) == V_31 ) {
F_42 ( F_61 ( V_48 ) != 0 ) ;
return 1 ;
}
if ( F_62 ( V_48 ) && F_60 ( V_48 ) == V_31 ) {
F_42 ( F_61 ( V_48 ) != 0 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_63 ( struct V_5 * V_5 ,
struct V_12 * V_12 , unsigned int V_31 ,
int V_6 )
{
unsigned long V_47 ;
unsigned long V_49 ;
unsigned long V_50 ( V_51 ) ;
struct V_5 * V_48 ;
F_42 ( ! F_64 ( V_12 ) ) ;
if ( F_7 ( F_65 ( V_5 ) ) )
if ( F_7 ( F_37 ( V_5 , V_31 ) ) )
return;
F_42 ( V_6 == - 1 ) ;
V_47 = F_10 ( V_5 ) & ( ( 1 << V_41 ) - 1 ) ;
F_42 ( V_47 & ( ( 1 << V_31 ) - 1 ) ) ;
F_42 ( F_18 ( V_12 , V_5 ) ) ;
while ( V_31 < V_41 - 1 ) {
V_51 = F_56 ( V_47 , V_31 ) ;
V_48 = V_5 + ( V_51 - V_47 ) ;
if ( ! F_57 ( V_5 , V_48 , V_31 ) )
break;
if ( F_59 ( V_48 ) ) {
F_49 ( V_48 ) ;
F_52 ( V_5 , 0 ) ;
F_66 ( V_12 , 1 << V_31 ,
V_6 ) ;
} else {
F_67 ( & V_48 -> V_52 ) ;
V_12 -> V_53 [ V_31 ] . V_54 -- ;
F_54 ( V_48 ) ;
}
V_49 = V_51 & V_47 ;
V_5 = V_5 + ( V_49 - V_47 ) ;
V_47 = V_49 ;
V_31 ++ ;
}
F_51 ( V_5 , V_31 ) ;
if ( ( V_31 < V_41 - 2 ) && F_16 ( F_10 ( V_48 ) ) ) {
struct V_5 * V_55 , * V_56 ;
V_49 = V_51 & V_47 ;
V_55 = V_5 + ( V_49 - V_47 ) ;
V_51 = F_56 ( V_49 , V_31 + 1 ) ;
V_56 = V_55 + ( V_51 - V_49 ) ;
if ( F_57 ( V_55 , V_56 , V_31 + 1 ) ) {
F_68 ( & V_5 -> V_52 ,
& V_12 -> V_53 [ V_31 ] . V_57 [ V_6 ] ) ;
goto V_24;
}
}
F_69 ( & V_5 -> V_52 , & V_12 -> V_53 [ V_31 ] . V_57 [ V_6 ] ) ;
V_24:
V_12 -> V_53 [ V_31 ] . V_54 ++ ;
}
static inline int F_70 ( struct V_5 * V_5 )
{
if ( F_7 ( F_71 ( V_5 ) |
( V_5 -> V_58 != NULL ) |
( F_72 ( & V_5 -> V_59 ) != 0 ) |
( V_5 -> V_60 & V_61 ) |
( F_73 ( V_5 ) ) ) ) {
F_19 ( V_5 ) ;
return 1 ;
}
F_74 ( V_5 ) ;
if ( V_5 -> V_60 & V_62 )
V_5 -> V_60 &= ~ V_62 ;
return 0 ;
}
static void F_75 ( struct V_12 * V_12 , int V_63 ,
struct V_64 * V_65 )
{
int V_6 = 0 ;
int V_66 = 0 ;
int V_67 = V_63 ;
F_76 ( & V_12 -> V_68 ) ;
V_12 -> V_69 = 0 ;
while ( V_67 ) {
struct V_5 * V_5 ;
struct V_70 * V_71 ;
do {
V_66 ++ ;
if ( ++ V_6 == V_8 )
V_6 = 0 ;
V_71 = & V_65 -> V_72 [ V_6 ] ;
} while ( F_77 ( V_71 ) );
if ( V_66 == V_8 )
V_66 = V_67 ;
do {
int V_73 ;
V_5 = F_78 ( V_71 -> V_74 , struct V_5 , V_52 ) ;
F_67 ( & V_5 -> V_52 ) ;
V_73 = F_79 ( V_5 ) ;
F_63 ( V_5 , V_12 , 0 , V_73 ) ;
F_80 ( V_5 , 0 , V_73 ) ;
if ( F_81 ( ! F_82 ( V_5 ) ) ) {
F_83 ( V_12 , V_75 , 1 ) ;
if ( F_84 ( V_73 ) )
F_83 ( V_12 , V_76 , 1 ) ;
}
} while ( -- V_67 && -- V_66 && ! F_77 ( V_71 ) );
}
F_85 ( & V_12 -> V_68 ) ;
}
static void F_86 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_31 ,
int V_6 )
{
F_76 ( & V_12 -> V_68 ) ;
V_12 -> V_69 = 0 ;
F_63 ( V_5 , V_12 , V_31 , V_6 ) ;
if ( F_7 ( ! F_87 ( V_6 ) ) )
F_66 ( V_12 , 1 << V_31 , V_6 ) ;
F_85 ( & V_12 -> V_68 ) ;
}
static bool F_88 ( struct V_5 * V_5 , unsigned int V_31 )
{
int V_32 ;
int V_36 = 0 ;
F_89 ( V_5 , V_31 ) ;
F_90 ( V_5 , V_31 ) ;
if ( F_91 ( V_5 ) )
V_5 -> V_58 = NULL ;
for ( V_32 = 0 ; V_32 < ( 1 << V_31 ) ; V_32 ++ )
V_36 += F_70 ( V_5 + V_32 ) ;
if ( V_36 )
return false ;
if ( ! F_92 ( V_5 ) ) {
F_93 ( F_94 ( V_5 ) ,
V_77 << V_31 ) ;
F_95 ( F_94 ( V_5 ) ,
V_77 << V_31 ) ;
}
F_96 ( V_5 , V_31 ) ;
F_97 ( V_5 , 1 << V_31 , 0 ) ;
return true ;
}
static void F_29 ( struct V_5 * V_5 , unsigned int V_31 )
{
unsigned long V_60 ;
int V_6 ;
if ( ! F_88 ( V_5 , V_31 ) )
return;
F_98 ( V_60 ) ;
F_99 ( V_78 , 1 << V_31 ) ;
V_6 = F_100 ( V_5 ) ;
F_101 ( V_5 , V_6 ) ;
F_86 ( F_17 ( V_5 ) , V_5 , V_31 , V_6 ) ;
F_102 ( V_60 ) ;
}
void T_2 F_103 ( struct V_5 * V_5 , unsigned int V_31 )
{
unsigned int V_33 = 1 << V_31 ;
struct V_5 * V_34 = V_5 ;
unsigned int V_79 ;
F_104 ( V_34 ) ;
for ( V_79 = 0 ; V_79 < ( V_33 - 1 ) ; V_79 ++ , V_34 ++ ) {
F_104 ( V_34 + 1 ) ;
F_105 ( V_34 ) ;
F_36 ( V_34 , 0 ) ;
}
F_105 ( V_34 ) ;
F_36 ( V_34 , 0 ) ;
F_17 ( V_5 ) -> V_80 += V_33 ;
F_106 ( V_5 ) ;
F_107 ( V_5 , V_31 ) ;
}
void T_2 F_108 ( struct V_5 * V_5 )
{
unsigned V_32 = V_81 ;
struct V_5 * V_34 = V_5 ;
do {
F_105 ( V_34 ) ;
F_36 ( V_34 , 0 ) ;
} while ( ++ V_34 , -- V_32 );
F_106 ( V_5 ) ;
F_6 ( V_5 , V_82 ) ;
F_107 ( V_5 , V_83 ) ;
F_109 ( V_5 , V_81 ) ;
}
static inline void F_110 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_84 , int V_85 , struct V_53 * V_86 ,
int V_6 )
{
unsigned long V_87 = 1 << V_85 ;
while ( V_85 > V_84 ) {
V_86 -- ;
V_85 -- ;
V_87 >>= 1 ;
F_42 ( F_18 ( V_12 , & V_5 [ V_87 ] ) ) ;
#ifdef F_111
if ( V_85 < F_112 () ) {
F_113 ( & V_5 [ V_87 ] . V_52 ) ;
F_47 ( & V_5 [ V_87 ] ) ;
F_52 ( & V_5 [ V_87 ] , V_85 ) ;
F_66 ( V_12 , - ( 1 << V_85 ) ,
V_6 ) ;
continue;
}
#endif
F_69 ( & V_5 [ V_87 ] . V_52 , & V_86 -> V_57 [ V_6 ] ) ;
V_86 -> V_54 ++ ;
F_51 ( & V_5 [ V_87 ] , V_85 ) ;
}
}
static inline int F_114 ( struct V_5 * V_5 )
{
if ( F_7 ( F_71 ( V_5 ) |
( V_5 -> V_58 != NULL ) |
( F_72 ( & V_5 -> V_59 ) != 0 ) |
( V_5 -> V_60 & V_62 ) |
( F_73 ( V_5 ) ) ) ) {
F_19 ( V_5 ) ;
return 1 ;
}
return 0 ;
}
static int F_115 ( struct V_5 * V_5 , int V_31 , T_1 V_37 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < ( 1 << V_31 ) ; V_32 ++ ) {
struct V_5 * V_34 = V_5 + V_32 ;
if ( F_7 ( F_114 ( V_34 ) ) )
return 1 ;
}
F_52 ( V_5 , 0 ) ;
F_106 ( V_5 ) ;
F_116 ( V_5 , V_31 ) ;
F_97 ( V_5 , 1 << V_31 , 1 ) ;
if ( V_37 & V_88 )
F_41 ( V_5 , V_31 , V_37 ) ;
if ( V_31 && ( V_37 & V_89 ) )
F_31 ( V_5 , V_31 ) ;
return 0 ;
}
static inline
struct V_5 * F_117 ( struct V_12 * V_12 , unsigned int V_31 ,
int V_6 )
{
unsigned int V_90 ;
struct V_53 * V_86 ;
struct V_5 * V_5 ;
for ( V_90 = V_31 ; V_90 < V_41 ; ++ V_90 ) {
V_86 = & ( V_12 -> V_53 [ V_90 ] ) ;
if ( F_77 ( & V_86 -> V_57 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_86 -> V_57 [ V_6 ] . V_91 ,
struct V_5 , V_52 ) ;
F_67 ( & V_5 -> V_52 ) ;
F_54 ( V_5 ) ;
V_86 -> V_54 -- ;
F_110 ( V_12 , V_5 , V_31 , V_90 , V_86 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_118 ( struct V_12 * V_12 ,
struct V_5 * V_92 , struct V_5 * V_93 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_31 ;
int V_94 = 0 ;
#ifndef F_119
F_120 ( F_17 ( V_92 ) != F_17 ( V_93 ) ) ;
#endif
for ( V_5 = V_92 ; V_5 <= V_93 ; ) {
F_42 ( F_121 ( V_5 ) != F_122 ( V_12 ) ) ;
if ( ! F_16 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_62 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_31 = F_60 ( V_5 ) ;
F_123 ( & V_5 -> V_52 ,
& V_12 -> V_53 [ V_31 ] . V_57 [ V_6 ] ) ;
F_101 ( V_5 , V_6 ) ;
V_5 += 1 << V_31 ;
V_94 += 1 << V_31 ;
}
return V_94 ;
}
int F_124 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_17 , V_95 ;
struct V_5 * V_92 , * V_93 ;
V_17 = F_10 ( V_5 ) ;
V_17 = V_17 & ~ ( V_81 - 1 ) ;
V_92 = F_125 ( V_17 ) ;
V_93 = V_92 + V_81 - 1 ;
V_95 = V_17 + V_81 - 1 ;
if ( ! F_12 ( V_12 , V_17 ) )
V_92 = V_5 ;
if ( ! F_12 ( V_12 , V_95 ) )
return 0 ;
return F_118 ( V_12 , V_92 , V_93 , V_6 ) ;
}
static void F_126 ( struct V_5 * V_96 ,
int V_97 , int V_6 )
{
int V_98 = 1 << ( V_97 - V_83 ) ;
while ( V_98 -- ) {
F_6 ( V_96 , V_6 ) ;
V_96 += V_81 ;
}
}
static int F_127 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_99 , int V_100 )
{
int V_90 = F_60 ( V_5 ) ;
if ( F_84 ( V_100 ) )
return V_100 ;
if ( V_90 >= V_83 ) {
F_126 ( V_5 , V_90 , V_99 ) ;
return V_99 ;
}
if ( V_90 >= V_83 / 2 ||
V_99 == V_101 ||
V_7 ) {
int V_102 ;
V_102 = F_124 ( V_12 , V_5 , V_99 ) ;
if ( V_102 >= ( 1 << ( V_83 - 1 ) ) ||
V_7 ) {
F_6 ( V_5 , V_99 ) ;
return V_99 ;
}
}
return V_100 ;
}
static inline struct V_5 *
F_128 ( struct V_12 * V_12 , int V_31 , int V_103 )
{
struct V_53 * V_86 ;
int V_90 ;
struct V_5 * V_5 ;
int V_6 , V_104 , V_32 ;
for ( V_90 = V_41 - 1 ; V_90 >= V_31 ;
-- V_90 ) {
for ( V_32 = 0 ; ; V_32 ++ ) {
V_6 = V_105 [ V_103 ] [ V_32 ] ;
if ( V_6 == V_106 )
break;
V_86 = & ( V_12 -> V_53 [ V_90 ] ) ;
if ( F_77 ( & V_86 -> V_57 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_86 -> V_57 [ V_6 ] . V_91 ,
struct V_5 , V_52 ) ;
V_86 -> V_54 -- ;
V_104 = F_127 ( V_12 , V_5 ,
V_103 ,
V_6 ) ;
F_67 ( & V_5 -> V_52 ) ;
F_54 ( V_5 ) ;
F_110 ( V_12 , V_5 , V_31 , V_90 , V_86 ,
V_104 ) ;
F_129 ( V_5 , V_31 , V_90 ,
V_103 , V_6 , V_104 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_130 ( struct V_12 * V_12 , unsigned int V_31 ,
int V_6 )
{
struct V_5 * V_5 ;
V_107:
V_5 = F_117 ( V_12 , V_31 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_106 ) {
V_5 = F_128 ( V_12 , V_31 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_106 ;
goto V_107;
}
}
F_131 ( V_5 , V_31 , V_6 ) ;
return V_5 ;
}
static int F_132 ( struct V_12 * V_12 , unsigned int V_31 ,
unsigned long V_63 , struct V_70 * V_71 ,
int V_6 , int V_108 )
{
int V_73 = V_6 , V_32 ;
F_76 ( & V_12 -> V_68 ) ;
for ( V_32 = 0 ; V_32 < V_63 ; ++ V_32 ) {
struct V_5 * V_5 = F_130 ( V_12 , V_31 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_81 ( V_108 == 0 ) )
F_69 ( & V_5 -> V_52 , V_71 ) ;
else
F_68 ( & V_5 -> V_52 , V_71 ) ;
if ( F_133 ( V_109 ) ) {
V_73 = F_100 ( V_5 ) ;
if ( ! F_84 ( V_73 ) && ! F_87 ( V_73 ) )
V_73 = V_6 ;
}
F_101 ( V_5 , V_73 ) ;
V_71 = & V_5 -> V_52 ;
if ( F_84 ( V_73 ) )
F_83 ( V_12 , V_76 ,
- ( 1 << V_31 ) ) ;
}
F_83 ( V_12 , V_75 , - ( V_32 << V_31 ) ) ;
F_85 ( & V_12 -> V_68 ) ;
return V_32 ;
}
void F_134 ( struct V_12 * V_12 , struct V_64 * V_65 )
{
unsigned long V_60 ;
int V_110 ;
unsigned long V_111 ;
F_98 ( V_60 ) ;
V_111 = F_135 ( V_65 -> V_111 ) ;
if ( V_65 -> V_63 >= V_111 )
V_110 = V_111 ;
else
V_110 = V_65 -> V_63 ;
if ( V_110 > 0 ) {
F_75 ( V_12 , V_110 , V_65 ) ;
V_65 -> V_63 -= V_110 ;
}
F_102 ( V_60 ) ;
}
static void F_136 ( unsigned int V_112 )
{
unsigned long V_60 ;
struct V_12 * V_12 ;
F_137 (zone) {
struct V_113 * V_114 ;
struct V_64 * V_65 ;
F_98 ( V_60 ) ;
V_114 = F_138 ( V_12 -> V_115 , V_112 ) ;
V_65 = & V_114 -> V_65 ;
if ( V_65 -> V_63 ) {
F_75 ( V_12 , V_65 -> V_63 , V_65 ) ;
V_65 -> V_63 = 0 ;
}
F_102 ( V_60 ) ;
}
}
void F_139 ( void * V_116 )
{
F_136 ( F_140 () ) ;
}
void F_141 ( void )
{
int V_112 ;
struct V_113 * V_65 ;
struct V_12 * V_12 ;
static T_3 V_117 ;
F_142 (cpu) {
bool V_118 = false ;
F_137 (zone) {
V_65 = F_138 ( V_12 -> V_115 , V_112 ) ;
if ( V_65 -> V_65 . V_63 ) {
V_118 = true ;
break;
}
}
if ( V_118 )
F_143 ( V_112 , & V_117 ) ;
else
F_144 ( V_112 , & V_117 ) ;
}
F_145 ( & V_117 , F_139 , NULL , 1 ) ;
}
void F_146 ( struct V_12 * V_12 )
{
unsigned long V_15 , V_119 ;
unsigned long V_60 ;
int V_31 , V_120 ;
struct V_70 * V_121 ;
if ( F_147 ( V_12 ) )
return;
F_148 ( & V_12 -> V_68 , V_60 ) ;
V_119 = F_149 ( V_12 ) ;
for ( V_15 = V_12 -> V_18 ; V_15 < V_119 ; V_15 ++ )
if ( F_150 ( V_15 ) ) {
struct V_5 * V_5 = F_125 ( V_15 ) ;
if ( ! F_151 ( V_5 ) )
F_152 ( V_5 ) ;
}
F_153 (order, t) {
F_154 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_32 ;
V_15 = F_10 ( F_78 ( V_121 , struct V_5 , V_52 ) ) ;
for ( V_32 = 0 ; V_32 < ( 1UL << V_31 ) ; V_32 ++ )
F_155 ( F_125 ( V_15 + V_32 ) ) ;
}
}
F_156 ( & V_12 -> V_68 , V_60 ) ;
}
void F_157 ( struct V_5 * V_5 , int V_108 )
{
struct V_12 * V_12 = F_17 ( V_5 ) ;
struct V_64 * V_65 ;
unsigned long V_60 ;
int V_6 ;
if ( ! F_88 ( V_5 , 0 ) )
return;
V_6 = F_100 ( V_5 ) ;
F_101 ( V_5 , V_6 ) ;
F_98 ( V_60 ) ;
F_158 ( V_78 ) ;
if ( V_6 >= V_8 ) {
if ( F_7 ( F_87 ( V_6 ) ) ) {
F_86 ( V_12 , V_5 , 0 , V_6 ) ;
goto V_24;
}
V_6 = V_122 ;
}
V_65 = & F_159 ( V_12 -> V_115 ) -> V_65 ;
if ( V_108 )
F_68 ( & V_5 -> V_52 , & V_65 -> V_72 [ V_6 ] ) ;
else
F_69 ( & V_5 -> V_52 , & V_65 -> V_72 [ V_6 ] ) ;
V_65 -> V_63 ++ ;
if ( V_65 -> V_63 >= V_65 -> V_85 ) {
unsigned long V_111 = F_135 ( V_65 -> V_111 ) ;
F_75 ( V_12 , V_111 , V_65 ) ;
V_65 -> V_63 -= V_111 ;
}
V_24:
F_102 ( V_60 ) ;
}
void F_160 ( struct V_70 * V_71 , int V_108 )
{
struct V_5 * V_5 , * V_91 ;
F_161 (page, next, list, lru) {
F_162 ( V_5 , V_108 ) ;
F_157 ( V_5 , V_108 ) ;
}
}
void F_163 ( struct V_5 * V_5 , unsigned int V_31 )
{
int V_32 ;
F_42 ( F_65 ( V_5 ) ) ;
F_42 ( ! F_61 ( V_5 ) ) ;
#ifdef F_164
if ( F_165 ( V_5 ) )
F_163 ( F_166 ( V_5 [ 0 ] . V_123 ) , V_31 ) ;
#endif
for ( V_32 = 1 ; V_32 < ( 1 << V_31 ) ; V_32 ++ )
F_106 ( V_5 + V_32 ) ;
}
static int F_167 ( struct V_5 * V_5 , unsigned int V_31 )
{
unsigned long V_124 ;
struct V_12 * V_12 ;
int V_73 ;
F_120 ( ! F_62 ( V_5 ) ) ;
V_12 = F_17 ( V_5 ) ;
V_73 = F_100 ( V_5 ) ;
if ( ! F_87 ( V_73 ) ) {
V_124 = F_168 ( V_12 ) + ( 1 << V_31 ) ;
if ( ! F_169 ( V_12 , 0 , V_124 , 0 , 0 ) )
return 0 ;
F_66 ( V_12 , - ( 1UL << V_31 ) , V_73 ) ;
}
F_67 ( & V_5 -> V_52 ) ;
V_12 -> V_53 [ V_31 ] . V_54 -- ;
F_54 ( V_5 ) ;
if ( V_31 >= V_83 - 1 ) {
struct V_5 * V_125 = V_5 + ( 1 << V_31 ) - 1 ;
for (; V_5 < V_125 ; V_5 += V_81 ) {
int V_73 = F_100 ( V_5 ) ;
if ( ! F_87 ( V_73 ) && ! F_84 ( V_73 ) )
F_6 ( V_5 ,
V_122 ) ;
}
}
return 1UL << V_31 ;
}
int F_170 ( struct V_5 * V_5 )
{
unsigned int V_31 ;
int V_33 ;
V_31 = F_60 ( V_5 ) ;
V_33 = F_167 ( V_5 , V_31 ) ;
if ( ! V_33 )
return 0 ;
F_106 ( V_5 ) ;
F_163 ( V_5 , V_31 ) ;
return V_33 ;
}
static inline
struct V_5 * F_171 ( struct V_12 * V_126 ,
struct V_12 * V_12 , int V_31 , T_1 V_37 ,
int V_6 )
{
unsigned long V_60 ;
struct V_5 * V_5 ;
int V_108 = ! ! ( V_37 & V_127 ) ;
V_128:
if ( F_81 ( V_31 == 0 ) ) {
struct V_64 * V_65 ;
struct V_70 * V_71 ;
F_98 ( V_60 ) ;
V_65 = & F_159 ( V_12 -> V_115 ) -> V_65 ;
V_71 = & V_65 -> V_72 [ V_6 ] ;
if ( F_77 ( V_71 ) ) {
V_65 -> V_63 += F_132 ( V_12 , 0 ,
V_65 -> V_111 , V_71 ,
V_6 , V_108 ) ;
if ( F_7 ( F_77 ( V_71 ) ) )
goto V_129;
}
if ( V_108 )
V_5 = F_78 ( V_71 -> V_74 , struct V_5 , V_52 ) ;
else
V_5 = F_78 ( V_71 -> V_91 , struct V_5 , V_52 ) ;
F_67 ( & V_5 -> V_52 ) ;
V_65 -> V_63 -- ;
} else {
if ( F_7 ( V_37 & V_130 ) ) {
F_172 ( V_31 > 1 ) ;
}
F_148 ( & V_12 -> V_68 , V_60 ) ;
V_5 = F_130 ( V_12 , V_31 , V_6 ) ;
F_85 ( & V_12 -> V_68 ) ;
if ( ! V_5 )
goto V_129;
F_66 ( V_12 , - ( 1 << V_31 ) ,
F_100 ( V_5 ) ) ;
}
F_83 ( V_12 , V_131 , - ( 1 << V_31 ) ) ;
F_173 ( V_132 , V_12 , 1 << V_31 ) ;
F_174 ( V_126 , V_12 , V_37 ) ;
F_102 ( V_60 ) ;
F_42 ( F_18 ( V_12 , V_5 ) ) ;
if ( F_115 ( V_5 , V_31 , V_37 ) )
goto V_128;
return V_5 ;
V_129:
F_102 ( V_60 ) ;
return NULL ;
}
static int T_2 F_175 ( char * V_133 )
{
return F_176 ( & V_134 . V_135 , V_133 ) ;
}
static bool F_177 ( T_1 V_136 , unsigned int V_31 )
{
if ( V_31 < V_134 . V_137 )
return false ;
if ( V_136 & V_130 )
return false ;
if ( V_134 . V_138 && ( V_136 & V_38 ) )
return false ;
if ( V_134 . V_139 && ( V_136 & V_140 ) )
return false ;
return F_178 ( & V_134 . V_135 , 1 << V_31 ) ;
}
static int T_2 F_179 ( void )
{
T_4 V_141 = V_142 | V_143 | V_144 ;
struct V_145 * V_146 ;
V_146 = F_180 ( L_6 , NULL ,
& V_134 . V_135 ) ;
if ( F_181 ( V_146 ) )
return F_182 ( V_146 ) ;
if ( ! F_183 ( L_7 , V_141 , V_146 ,
& V_134 . V_139 ) )
goto V_147;
if ( ! F_183 ( L_8 , V_141 , V_146 ,
& V_134 . V_138 ) )
goto V_147;
if ( ! F_184 ( L_9 , V_141 , V_146 ,
& V_134 . V_137 ) )
goto V_147;
return 0 ;
V_147:
F_185 ( V_146 ) ;
return - V_148 ;
}
static inline bool F_177 ( T_1 V_136 , unsigned int V_31 )
{
return false ;
}
static bool F_186 ( struct V_12 * V_149 , int V_31 , unsigned long V_150 ,
int V_151 , int V_152 , long V_153 )
{
long V_154 = V_150 ;
long V_155 = V_149 -> V_155 [ V_151 ] ;
int V_156 ;
long V_157 = 0 ;
V_153 -= ( 1 << V_31 ) - 1 ;
if ( V_152 & V_158 )
V_154 -= V_154 / 2 ;
if ( V_152 & V_159 )
V_154 -= V_154 / 4 ;
#ifdef V_109
if ( ! ( V_152 & V_160 ) )
V_157 = F_187 ( V_149 , V_76 ) ;
#endif
if ( V_153 - V_157 <= V_154 + V_155 )
return false ;
for ( V_156 = 0 ; V_156 < V_31 ; V_156 ++ ) {
V_153 -= V_149 -> V_53 [ V_156 ] . V_54 << V_156 ;
V_154 >>= 1 ;
if ( V_153 <= V_154 )
return false ;
}
return true ;
}
bool F_169 ( struct V_12 * V_149 , int V_31 , unsigned long V_150 ,
int V_151 , int V_152 )
{
return F_186 ( V_149 , V_31 , V_150 , V_151 , V_152 ,
F_187 ( V_149 , V_75 ) ) ;
}
bool F_188 ( struct V_12 * V_149 , int V_31 , unsigned long V_150 ,
int V_151 , int V_152 )
{
long V_153 = F_187 ( V_149 , V_75 ) ;
if ( V_149 -> V_161 && V_153 < V_149 -> V_161 )
V_153 = F_189 ( V_149 , V_75 ) ;
return F_186 ( V_149 , V_31 , V_150 , V_151 , V_152 ,
V_153 ) ;
}
static T_5 * F_190 ( struct V_162 * V_162 , int V_152 )
{
struct V_163 * V_164 ;
T_5 * V_165 ;
V_164 = V_162 -> V_166 ;
if ( ! V_164 )
return NULL ;
if ( F_191 ( V_23 , V_164 -> V_167 + V_26 ) ) {
F_192 ( V_164 -> V_168 , V_169 ) ;
V_164 -> V_167 = V_23 ;
}
V_165 = ! F_43 () && ( V_152 & V_170 ) ?
& V_171 :
& V_172 [ V_173 ] ;
return V_165 ;
}
static int F_193 ( struct V_162 * V_162 , struct V_174 * V_149 ,
T_5 * V_165 )
{
struct V_163 * V_164 ;
int V_32 ;
int V_175 ;
V_164 = V_162 -> V_166 ;
if ( ! V_164 )
return 1 ;
V_32 = V_149 - V_162 -> V_176 ;
V_175 = V_164 -> V_177 [ V_32 ] ;
return F_194 ( V_175 , * V_165 ) && ! F_195 ( V_32 , V_164 -> V_168 ) ;
}
static void F_196 ( struct V_162 * V_162 , struct V_174 * V_149 )
{
struct V_163 * V_164 ;
int V_32 ;
V_164 = V_162 -> V_166 ;
if ( ! V_164 )
return;
V_32 = V_149 - V_162 -> V_176 ;
F_197 ( V_32 , V_164 -> V_168 ) ;
}
static void F_198 ( struct V_162 * V_162 )
{
struct V_163 * V_164 ;
V_164 = V_162 -> V_166 ;
if ( ! V_164 )
return;
F_192 ( V_164 -> V_168 , V_169 ) ;
}
static bool F_199 ( struct V_12 * V_178 , struct V_12 * V_12 )
{
return V_178 -> V_179 == V_12 -> V_179 ;
}
static bool F_200 ( struct V_12 * V_178 , struct V_12 * V_12 )
{
return F_194 ( V_178 -> V_179 , V_12 -> V_180 -> V_181 ) ;
}
static void T_6 F_201 ( int V_182 )
{
int V_32 ;
F_202 (i)
if ( F_203 ( V_182 , V_32 ) <= V_183 )
F_204 ( V_32 , F_205 ( V_182 ) -> V_181 ) ;
else
V_184 = 1 ;
}
static T_5 * F_190 ( struct V_162 * V_162 , int V_152 )
{
return NULL ;
}
static int F_193 ( struct V_162 * V_162 , struct V_174 * V_149 ,
T_5 * V_165 )
{
return 1 ;
}
static void F_196 ( struct V_162 * V_162 , struct V_174 * V_149 )
{
}
static void F_198 ( struct V_162 * V_162 )
{
}
static bool F_199 ( struct V_12 * V_178 , struct V_12 * V_12 )
{
return true ;
}
static bool F_200 ( struct V_12 * V_178 , struct V_12 * V_12 )
{
return true ;
}
static inline void F_201 ( int V_182 )
{
}
static struct V_5 *
F_206 ( T_1 V_136 , T_5 * V_185 , unsigned int V_31 ,
struct V_162 * V_162 , int V_186 , int V_152 ,
struct V_12 * V_126 , int V_6 )
{
struct V_174 * V_149 ;
struct V_5 * V_5 = NULL ;
int V_151 ;
struct V_12 * V_12 ;
T_5 * V_165 = NULL ;
int V_187 = 0 ;
int V_188 = 0 ;
V_151 = F_207 ( V_126 ) ;
V_189:
F_208 (zone, z, zonelist,
high_zoneidx, nodemask) {
unsigned long V_150 ;
if ( F_133 ( V_190 ) && V_187 &&
! F_193 ( V_162 , V_149 , V_165 ) )
continue;
if ( ( V_152 & V_170 ) &&
! F_209 ( V_12 , V_136 ) )
continue;
F_210 ( V_191 < V_192 ) ;
if ( F_7 ( V_152 & V_191 ) )
goto V_193;
if ( V_152 & V_194 ) {
if ( F_187 ( V_12 , V_131 ) <= 0 )
continue;
if ( ! F_199 ( V_126 , V_12 ) )
continue;
}
if ( ( V_152 & V_194 ) &&
( V_136 & V_195 ) && ! F_211 ( V_12 ) )
goto V_196;
V_150 = V_12 -> V_124 [ V_152 & V_197 ] ;
if ( ! F_169 ( V_12 , V_31 , V_150 ,
V_151 , V_152 ) ) {
int V_13 ;
if ( F_133 ( V_190 ) &&
! V_188 && V_198 > 1 ) {
V_165 = F_190 ( V_162 , V_152 ) ;
V_187 = 1 ;
V_188 = 1 ;
}
if ( V_184 == 0 ||
! F_200 ( V_126 , V_12 ) )
goto V_196;
if ( F_133 ( V_190 ) && V_187 &&
! F_193 ( V_162 , V_149 , V_165 ) )
continue;
V_13 = F_212 ( V_12 , V_136 , V_31 ) ;
switch ( V_13 ) {
case V_199 :
continue;
case V_200 :
continue;
default:
if ( F_169 ( V_12 , V_31 , V_150 ,
V_151 , V_152 ) )
goto V_193;
if ( ( ( V_152 & V_197 ) == V_201 ) ||
V_13 == V_202 )
goto V_196;
continue;
}
}
V_193:
V_5 = F_171 ( V_126 , V_12 , V_31 ,
V_136 , V_6 ) ;
if ( V_5 )
break;
V_196:
if ( F_133 ( V_190 ) )
F_196 ( V_162 , V_149 ) ;
}
if ( F_7 ( F_133 ( V_190 ) && V_5 == NULL && V_187 ) ) {
V_187 = 0 ;
goto V_189;
}
if ( V_5 )
V_5 -> V_203 = ! ! ( V_152 & V_191 ) ;
return V_5 ;
}
static inline bool F_213 ( void )
{
bool V_13 = false ;
#if V_204 > 8
V_13 = F_43 () ;
#endif
return V_13 ;
}
void F_214 ( T_1 V_136 , int V_31 , const char * V_205 , ... )
{
unsigned int V_206 = V_207 ;
if ( ( V_136 & V_208 ) || ! F_215 ( & V_209 ) ||
F_112 () > 0 )
return;
if ( ! ( V_136 & V_140 ) )
V_206 |= V_210 ;
if ( ! ( V_136 & V_211 ) )
if ( F_216 ( V_212 ) ||
( V_27 -> V_60 & ( V_213 | V_214 ) ) )
V_206 &= ~ V_207 ;
if ( F_43 () || ! ( V_136 & V_140 ) )
V_206 &= ~ V_207 ;
if ( V_205 ) {
struct V_215 V_216 ;
T_7 args ;
va_start ( args , V_205 ) ;
V_216 . V_205 = V_205 ;
V_216 . V_217 = & args ;
F_217 ( L_10 , & V_216 ) ;
va_end ( args ) ;
}
F_217 ( L_11 ,
V_27 -> V_28 , V_31 , V_136 ) ;
F_26 () ;
if ( ! F_213 () )
F_218 ( V_206 ) ;
}
static inline int
F_219 ( T_1 V_136 , unsigned int V_31 ,
unsigned long V_218 ,
unsigned long V_219 )
{
if ( V_136 & V_220 )
return 0 ;
if ( V_136 & V_130 )
return 1 ;
if ( ! V_218 && F_5 () )
return 0 ;
if ( V_31 <= V_221 )
return 1 ;
if ( V_136 & V_222 && V_219 < ( 1 << V_31 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_220 ( T_1 V_136 , unsigned int V_31 ,
struct V_162 * V_162 , enum V_223 V_186 ,
T_5 * V_185 , struct V_12 * V_126 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_221 ( V_162 , V_136 ) ) {
F_222 ( 1 ) ;
return NULL ;
}
V_5 = F_206 ( V_136 | V_224 , V_185 ,
V_31 , V_162 , V_186 ,
V_225 | V_170 ,
V_126 , V_6 ) ;
if ( V_5 )
goto V_24;
if ( ! ( V_136 & V_130 ) ) {
if ( V_31 > V_221 )
goto V_24;
if ( V_186 < V_226 )
goto V_24;
if ( V_136 & V_227 )
goto V_24;
}
F_223 ( V_162 , V_136 , V_31 , V_185 , false ) ;
V_24:
F_224 ( V_162 , V_136 ) ;
return V_5 ;
}
static struct V_5 *
F_225 ( T_1 V_136 , unsigned int V_31 ,
struct V_162 * V_162 , enum V_223 V_186 ,
T_5 * V_185 , int V_152 , struct V_12 * V_126 ,
int V_6 , bool V_228 ,
bool * V_229 , bool * V_230 ,
unsigned long * V_218 )
{
if ( ! V_31 )
return NULL ;
if ( F_226 ( V_126 , V_31 ) ) {
* V_230 = true ;
return NULL ;
}
V_27 -> V_60 |= V_213 ;
* V_218 = F_227 ( V_162 , V_31 , V_136 ,
V_185 , V_228 ,
V_229 ) ;
V_27 -> V_60 &= ~ V_213 ;
if ( * V_218 != V_231 ) {
struct V_5 * V_5 ;
F_136 ( F_228 () ) ;
F_229 () ;
V_5 = F_206 ( V_136 , V_185 ,
V_31 , V_162 , V_186 ,
V_152 & ~ V_191 ,
V_126 , V_6 ) ;
if ( V_5 ) {
V_126 -> V_232 = false ;
V_126 -> V_233 = 0 ;
V_126 -> V_234 = 0 ;
if ( V_31 >= V_126 -> V_235 )
V_126 -> V_235 = V_31 + 1 ;
F_230 ( V_236 ) ;
return V_5 ;
}
F_230 ( V_237 ) ;
if ( V_228 )
F_231 ( V_126 , V_31 ) ;
F_232 () ;
}
return NULL ;
}
static inline struct V_5 *
F_225 ( T_1 V_136 , unsigned int V_31 ,
struct V_162 * V_162 , enum V_223 V_186 ,
T_5 * V_185 , int V_152 , struct V_12 * V_126 ,
int V_6 , bool V_228 ,
bool * V_229 , bool * V_230 ,
unsigned long * V_218 )
{
return NULL ;
}
static int
F_233 ( T_1 V_136 , unsigned int V_31 , struct V_162 * V_162 ,
T_5 * V_185 )
{
struct V_238 V_238 ;
int V_239 ;
F_232 () ;
F_234 () ;
V_27 -> V_60 |= V_213 ;
F_235 ( V_136 ) ;
V_238 . V_240 = 0 ;
V_27 -> V_238 = & V_238 ;
V_239 = F_236 ( V_162 , V_31 , V_136 , V_185 ) ;
V_27 -> V_238 = NULL ;
F_237 () ;
V_27 -> V_60 &= ~ V_213 ;
F_232 () ;
return V_239 ;
}
static inline struct V_5 *
F_238 ( T_1 V_136 , unsigned int V_31 ,
struct V_162 * V_162 , enum V_223 V_186 ,
T_5 * V_185 , int V_152 , struct V_12 * V_126 ,
int V_6 , unsigned long * V_218 )
{
struct V_5 * V_5 = NULL ;
bool V_241 = false ;
* V_218 = F_233 ( V_136 , V_31 , V_162 ,
V_185 ) ;
if ( F_7 ( ! ( * V_218 ) ) )
return NULL ;
if ( F_133 ( V_190 ) )
F_198 ( V_162 ) ;
V_242:
V_5 = F_206 ( V_136 , V_185 , V_31 ,
V_162 , V_186 ,
V_152 & ~ V_191 ,
V_126 , V_6 ) ;
if ( ! V_5 && ! V_241 ) {
F_141 () ;
V_241 = true ;
goto V_242;
}
return V_5 ;
}
static inline struct V_5 *
F_239 ( T_1 V_136 , unsigned int V_31 ,
struct V_162 * V_162 , enum V_223 V_186 ,
T_5 * V_185 , struct V_12 * V_126 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_206 ( V_136 , V_185 , V_31 ,
V_162 , V_186 , V_191 ,
V_126 , V_6 ) ;
if ( ! V_5 && V_136 & V_130 )
F_240 ( V_126 , V_243 , V_26 / 50 ) ;
} while ( ! V_5 && ( V_136 & V_130 ) );
return V_5 ;
}
static void F_241 ( T_1 V_136 , unsigned int V_31 ,
struct V_162 * V_162 ,
enum V_223 V_186 ,
struct V_12 * V_126 )
{
struct V_174 * V_149 ;
struct V_12 * V_12 ;
F_242 (zone, z, zonelist, high_zoneidx) {
if ( ! ( V_136 & V_244 ) )
F_243 ( V_12 , V_31 , F_207 ( V_126 ) ) ;
if ( ! F_199 ( V_126 , V_12 ) )
continue;
F_244 ( V_12 , V_131 ,
F_245 ( V_12 ) -
F_168 ( V_12 ) -
F_187 ( V_12 , V_131 ) ) ;
}
}
static inline int
F_246 ( T_1 V_136 )
{
int V_152 = V_201 | V_170 ;
const T_1 V_245 = V_136 & V_140 ;
F_210 ( V_246 != ( V_247 T_1 ) V_158 ) ;
V_152 |= ( V_247 int ) ( V_136 & V_246 ) ;
if ( ! V_245 ) {
if ( ! ( V_136 & V_211 ) )
V_152 |= V_159 ;
V_152 &= ~ V_170 ;
} else if ( F_7 ( F_247 ( V_27 ) ) && ! F_43 () )
V_152 |= V_159 ;
if ( F_81 ( ! ( V_136 & V_211 ) ) ) {
if ( V_136 & V_248 )
V_152 |= V_191 ;
else if ( F_248 () && ( V_27 -> V_60 & V_213 ) )
V_152 |= V_191 ;
else if ( ! F_43 () &&
( ( V_27 -> V_60 & V_213 ) ||
F_7 ( F_216 ( V_212 ) ) ) )
V_152 |= V_191 ;
}
#ifdef V_109
if ( F_249 ( V_136 ) == V_122 )
V_152 |= V_160 ;
#endif
return V_152 ;
}
bool F_250 ( T_1 V_136 )
{
return ! ! ( F_246 ( V_136 ) & V_191 ) ;
}
static inline struct V_5 *
F_251 ( T_1 V_136 , unsigned int V_31 ,
struct V_162 * V_162 , enum V_223 V_186 ,
T_5 * V_185 , struct V_12 * V_126 ,
int V_6 )
{
const T_1 V_245 = V_136 & V_140 ;
struct V_5 * V_5 = NULL ;
int V_152 ;
unsigned long V_219 = 0 ;
unsigned long V_218 ;
bool V_228 = false ;
bool V_230 = false ;
bool V_229 = false ;
if ( V_31 >= V_41 ) {
F_172 ( ! ( V_136 & V_208 ) ) ;
return NULL ;
}
if ( F_133 ( V_190 ) &&
( V_136 & V_249 ) == V_249 )
goto V_250;
V_251:
F_241 ( V_136 , V_31 , V_162 ,
V_186 , V_126 ) ;
V_152 = F_246 ( V_136 ) ;
if ( ! ( V_152 & V_170 ) && ! V_185 )
F_252 ( V_162 , V_186 , NULL ,
& V_126 ) ;
V_252:
V_5 = F_206 ( V_136 , V_185 , V_31 , V_162 ,
V_186 , V_152 & ~ V_191 ,
V_126 , V_6 ) ;
if ( V_5 )
goto V_253;
if ( V_152 & V_191 ) {
V_162 = F_253 ( F_254 () , V_136 ) ;
V_5 = F_239 ( V_136 , V_31 ,
V_162 , V_186 , V_185 ,
V_126 , V_6 ) ;
if ( V_5 ) {
goto V_253;
}
}
if ( ! V_245 )
goto V_250;
if ( V_27 -> V_60 & V_213 )
goto V_250;
if ( F_216 ( V_212 ) && ! ( V_136 & V_130 ) )
goto V_250;
V_5 = F_225 ( V_136 , V_31 ,
V_162 , V_186 ,
V_185 ,
V_152 , V_126 ,
V_6 , V_228 ,
& V_229 ,
& V_230 ,
& V_218 ) ;
if ( V_5 )
goto V_253;
V_228 = true ;
if ( ( V_230 || V_229 ) &&
( V_136 & V_244 ) )
goto V_250;
V_5 = F_238 ( V_136 , V_31 ,
V_162 , V_186 ,
V_185 ,
V_152 , V_126 ,
V_6 , & V_218 ) ;
if ( V_5 )
goto V_253;
if ( ! V_218 ) {
if ( F_255 ( V_136 ) ) {
if ( V_254 )
goto V_250;
if ( ( V_27 -> V_60 & V_255 ) &&
! ( V_136 & V_130 ) )
goto V_250;
V_5 = F_220 ( V_136 , V_31 ,
V_162 , V_186 ,
V_185 , V_126 ,
V_6 ) ;
if ( V_5 )
goto V_253;
if ( ! ( V_136 & V_130 ) ) {
if ( V_31 > V_221 )
goto V_250;
if ( V_186 < V_226 )
goto V_250;
}
goto V_251;
}
}
V_219 += V_218 ;
if ( F_219 ( V_136 , V_31 , V_218 ,
V_219 ) ) {
F_240 ( V_126 , V_243 , V_26 / 50 ) ;
goto V_252;
} else {
V_5 = F_225 ( V_136 , V_31 ,
V_162 , V_186 ,
V_185 ,
V_152 , V_126 ,
V_6 , V_228 ,
& V_229 ,
& V_230 ,
& V_218 ) ;
if ( V_5 )
goto V_253;
}
V_250:
F_214 ( V_136 , V_31 , NULL ) ;
return V_5 ;
V_253:
if ( V_256 )
F_256 ( V_5 , V_31 , V_136 ) ;
return V_5 ;
}
struct V_5 *
F_257 ( T_1 V_136 , unsigned int V_31 ,
struct V_162 * V_162 , T_5 * V_185 )
{
enum V_223 V_186 = F_258 ( V_136 ) ;
struct V_12 * V_126 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_249 ( V_136 ) ;
unsigned int V_257 ;
int V_152 = V_194 | V_170 ;
struct V_258 * V_259 = NULL ;
V_136 &= V_3 ;
F_259 ( V_136 ) ;
F_260 ( V_136 & V_140 ) ;
if ( F_177 ( V_136 , V_31 ) )
return NULL ;
if ( F_7 ( ! V_162 -> V_176 -> V_12 ) )
return NULL ;
if ( ! F_261 ( V_136 , & V_259 , V_31 ) )
return NULL ;
V_260:
V_257 = F_262 () ;
F_252 ( V_162 , V_186 ,
V_185 ? : & V_171 ,
& V_126 ) ;
if ( ! V_126 )
goto V_24;
#ifdef V_109
if ( F_249 ( V_136 ) == V_122 )
V_152 |= V_160 ;
#endif
V_5 = F_206 ( V_136 | V_224 , V_185 , V_31 ,
V_162 , V_186 , V_152 ,
V_126 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
V_136 = F_263 ( V_136 ) ;
V_5 = F_251 ( V_136 , V_31 ,
V_162 , V_186 , V_185 ,
V_126 , V_6 ) ;
}
F_264 ( V_5 , V_31 , V_136 , V_6 ) ;
V_24:
if ( F_7 ( ! F_265 ( V_257 ) && ! V_5 ) )
goto V_260;
F_266 ( V_5 , V_259 , V_31 ) ;
return V_5 ;
}
unsigned long F_267 ( T_1 V_136 , unsigned int V_31 )
{
struct V_5 * V_5 ;
F_42 ( ( V_136 & V_38 ) != 0 ) ;
V_5 = F_268 ( V_136 , V_31 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_94 ( V_5 ) ;
}
unsigned long F_269 ( T_1 V_136 )
{
return F_267 ( V_136 | V_88 , 0 ) ;
}
void F_107 ( struct V_5 * V_5 , unsigned int V_31 )
{
if ( F_270 ( V_5 ) ) {
if ( V_31 == 0 )
F_157 ( V_5 , 0 ) ;
else
F_29 ( V_5 , V_31 ) ;
}
}
void V_153 ( unsigned long V_261 , unsigned int V_31 )
{
if ( V_261 != 0 ) {
F_42 ( ! F_271 ( ( void * ) V_261 ) ) ;
F_107 ( F_166 ( ( void * ) V_261 ) , V_31 ) ;
}
}
void F_272 ( struct V_5 * V_5 , unsigned int V_31 )
{
F_273 ( V_5 , V_31 ) ;
F_107 ( V_5 , V_31 ) ;
}
void F_274 ( unsigned long V_261 , unsigned int V_31 )
{
if ( V_261 != 0 ) {
F_42 ( ! F_271 ( ( void * ) V_261 ) ) ;
F_272 ( F_166 ( ( void * ) V_261 ) , V_31 ) ;
}
}
static void * F_275 ( unsigned long V_261 , unsigned V_31 , T_8 V_87 )
{
if ( V_261 ) {
unsigned long V_262 = V_261 + ( V_77 << V_31 ) ;
unsigned long V_263 = V_261 + F_276 ( V_87 ) ;
F_163 ( F_166 ( ( void * ) V_261 ) , V_31 ) ;
while ( V_263 < V_262 ) {
F_277 ( V_263 ) ;
V_263 += V_77 ;
}
}
return ( void * ) V_261 ;
}
void * F_278 ( T_8 V_87 , T_1 V_136 )
{
unsigned int V_31 = F_279 ( V_87 ) ;
unsigned long V_261 ;
V_261 = F_267 ( V_136 , V_31 ) ;
return F_275 ( V_261 , V_31 , V_87 ) ;
}
void * F_280 ( int V_182 , T_8 V_87 , T_1 V_136 )
{
unsigned V_31 = F_279 ( V_87 ) ;
struct V_5 * V_34 = F_281 ( V_182 , V_136 , V_31 ) ;
if ( ! V_34 )
return NULL ;
return F_275 ( ( unsigned long ) F_94 ( V_34 ) , V_31 , V_87 ) ;
}
void F_282 ( void * V_264 , T_8 V_87 )
{
unsigned long V_261 = ( unsigned long ) V_264 ;
unsigned long V_265 = V_261 + F_276 ( V_87 ) ;
while ( V_261 < V_265 ) {
F_277 ( V_261 ) ;
V_261 += V_77 ;
}
}
static unsigned long F_283 ( int V_266 )
{
struct V_174 * V_149 ;
struct V_12 * V_12 ;
unsigned long V_267 = 0 ;
struct V_162 * V_162 = F_253 ( F_254 () , V_268 ) ;
F_242 (zone, z, zonelist, offset) {
unsigned long V_87 = V_12 -> V_80 ;
unsigned long V_85 = F_245 ( V_12 ) ;
if ( V_87 > V_85 )
V_267 += V_87 - V_85 ;
}
return V_267 ;
}
unsigned long F_284 ( void )
{
return F_283 ( F_258 ( V_269 ) ) ;
}
unsigned long F_285 ( void )
{
return F_283 ( F_258 ( V_270 ) ) ;
}
static inline void F_286 ( struct V_12 * V_12 )
{
if ( F_133 ( V_190 ) )
F_23 ( L_12 , F_122 ( V_12 ) ) ;
}
void F_287 ( struct V_271 * V_272 )
{
V_272 -> V_273 = V_274 ;
V_272 -> V_275 = 0 ;
V_272 -> V_276 = F_288 ( V_75 ) ;
V_272 -> V_277 = F_289 () ;
V_272 -> V_278 = V_279 ;
V_272 -> V_280 = F_290 () ;
V_272 -> V_281 = V_77 ;
}
void F_291 ( struct V_271 * V_272 , int V_182 )
{
int V_223 ;
unsigned long V_80 = 0 ;
T_9 * V_282 = F_205 ( V_182 ) ;
for ( V_223 = 0 ; V_223 < V_283 ; V_223 ++ )
V_80 += V_282 -> V_284 [ V_223 ] . V_80 ;
V_272 -> V_273 = V_80 ;
V_272 -> V_276 = F_292 ( V_182 , V_75 ) ;
#ifdef F_293
V_272 -> V_278 = V_282 -> V_284 [ V_285 ] . V_80 ;
V_272 -> V_280 = F_187 ( & V_282 -> V_284 [ V_285 ] ,
V_75 ) ;
#else
V_272 -> V_278 = 0 ;
V_272 -> V_280 = 0 ;
#endif
V_272 -> V_281 = V_77 ;
}
bool F_294 ( unsigned int V_60 , int V_182 )
{
bool V_13 = false ;
unsigned int V_257 ;
if ( ! ( V_60 & V_207 ) )
goto V_24;
do {
V_257 = F_262 () ;
V_13 = ! F_194 ( V_182 , V_171 ) ;
} while ( ! F_265 ( V_257 ) );
V_24:
return V_13 ;
}
static void F_295 ( unsigned char type )
{
static const char V_286 [ V_287 ] = {
[ V_9 ] = 'U' ,
[ V_101 ] = 'E' ,
[ V_122 ] = 'M' ,
[ V_106 ] = 'R' ,
#ifdef V_109
[ V_82 ] = 'C' ,
#endif
#ifdef F_296
[ V_288 ] = 'I' ,
#endif
} ;
char V_289 [ V_287 + 1 ] ;
char * V_34 = V_289 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_287 ; V_32 ++ ) {
if ( type & ( 1 << V_32 ) )
* V_34 ++ = V_286 [ V_32 ] ;
}
* V_34 = '\0' ;
F_23 ( L_13 , V_289 ) ;
}
void F_297 ( unsigned int V_206 )
{
int V_112 ;
struct V_12 * V_12 ;
F_137 (zone) {
if ( F_294 ( V_206 , F_122 ( V_12 ) ) )
continue;
F_286 ( V_12 ) ;
F_23 ( L_14 , V_12 -> V_290 ) ;
F_142 (cpu) {
struct V_113 * V_115 ;
V_115 = F_138 ( V_12 -> V_115 , V_112 ) ;
F_23 ( L_15 ,
V_112 , V_115 -> V_65 . V_85 ,
V_115 -> V_65 . V_111 , V_115 -> V_65 . V_63 ) ;
}
}
F_23 ( L_16
L_17
L_18
L_19
L_20
L_21
L_22 ,
F_288 ( V_291 ) ,
F_288 ( V_292 ) ,
F_288 ( V_293 ) ,
F_288 ( V_294 ) ,
F_288 ( V_295 ) ,
F_288 ( V_296 ) ,
F_288 ( V_297 ) ,
F_288 ( V_298 ) ,
F_288 ( V_299 ) ,
F_288 ( V_300 ) ,
F_288 ( V_75 ) ,
F_288 ( V_301 ) ,
F_288 ( V_302 ) ,
F_288 ( V_303 ) ,
F_288 ( V_304 ) ,
F_288 ( V_305 ) ,
F_288 ( V_306 ) ,
F_288 ( V_76 ) ) ;
F_137 (zone) {
int V_32 ;
if ( F_294 ( V_206 , F_122 ( V_12 ) ) )
continue;
F_286 ( V_12 ) ;
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
V_12 -> V_290 ,
F_298 ( F_187 ( V_12 , V_75 ) ) ,
F_298 ( F_299 ( V_12 ) ) ,
F_298 ( F_168 ( V_12 ) ) ,
F_298 ( F_245 ( V_12 ) ) ,
F_298 ( F_187 ( V_12 , V_291 ) ) ,
F_298 ( F_187 ( V_12 , V_292 ) ) ,
F_298 ( F_187 ( V_12 , V_294 ) ) ,
F_298 ( F_187 ( V_12 , V_295 ) ) ,
F_298 ( F_187 ( V_12 , V_297 ) ) ,
F_298 ( F_187 ( V_12 , V_293 ) ) ,
F_298 ( F_187 ( V_12 , V_296 ) ) ,
F_298 ( V_12 -> V_307 ) ,
F_298 ( V_12 -> V_80 ) ,
F_298 ( F_187 ( V_12 , V_308 ) ) ,
F_298 ( F_187 ( V_12 , V_298 ) ) ,
F_298 ( F_187 ( V_12 , V_299 ) ) ,
F_298 ( F_187 ( V_12 , V_303 ) ) ,
F_298 ( F_187 ( V_12 , V_304 ) ) ,
F_298 ( F_187 ( V_12 , V_301 ) ) ,
F_298 ( F_187 ( V_12 , V_302 ) ) ,
F_187 ( V_12 , V_309 ) *
V_310 / 1024 ,
F_298 ( F_187 ( V_12 , V_305 ) ) ,
F_298 ( F_187 ( V_12 , V_300 ) ) ,
F_298 ( F_187 ( V_12 , V_306 ) ) ,
F_298 ( F_187 ( V_12 , V_76 ) ) ,
F_298 ( F_187 ( V_12 , V_311 ) ) ,
V_12 -> V_69 ,
( ! F_300 ( V_12 ) ? L_53 : L_54 )
) ;
F_23 ( L_55 ) ;
for ( V_32 = 0 ; V_32 < V_283 ; V_32 ++ )
F_23 ( L_56 , V_12 -> V_155 [ V_32 ] ) ;
F_23 ( L_52 ) ;
}
F_137 (zone) {
unsigned long V_312 [ V_41 ] , V_60 , V_31 , V_313 = 0 ;
unsigned char V_286 [ V_41 ] ;
if ( F_294 ( V_206 , F_122 ( V_12 ) ) )
continue;
F_286 ( V_12 ) ;
F_23 ( L_57 , V_12 -> V_290 ) ;
F_148 ( & V_12 -> V_68 , V_60 ) ;
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
struct V_53 * V_86 = & V_12 -> V_53 [ V_31 ] ;
int type ;
V_312 [ V_31 ] = V_86 -> V_54 ;
V_313 += V_312 [ V_31 ] << V_31 ;
V_286 [ V_31 ] = 0 ;
for ( type = 0 ; type < V_287 ; type ++ ) {
if ( ! F_77 ( & V_86 -> V_57 [ type ] ) )
V_286 [ V_31 ] |= 1 << type ;
}
}
F_156 ( & V_12 -> V_68 , V_60 ) ;
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
F_23 ( L_58 , V_312 [ V_31 ] , F_298 ( 1UL ) << V_31 ) ;
if ( V_312 [ V_31 ] )
F_295 ( V_286 [ V_31 ] ) ;
}
F_23 ( L_59 , F_298 ( V_313 ) ) ;
}
F_301 () ;
F_23 ( L_60 , F_288 ( V_314 ) ) ;
F_302 () ;
}
static void F_303 ( struct V_12 * V_12 , struct V_174 * V_174 )
{
V_174 -> V_12 = V_12 ;
V_174 -> F_207 = F_207 ( V_12 ) ;
}
static int F_304 ( T_9 * V_282 , struct V_162 * V_162 ,
int V_315 )
{
struct V_12 * V_12 ;
enum V_223 V_223 = V_283 ;
do {
V_223 -- ;
V_12 = V_282 -> V_284 + V_223 ;
if ( F_305 ( V_12 ) ) {
F_303 ( V_12 ,
& V_162 -> V_176 [ V_315 ++ ] ) ;
F_306 ( V_223 ) ;
}
} while ( V_223 );
return V_315 ;
}
static int F_307 ( char * V_316 )
{
if ( * V_316 == 'd' || * V_316 == 'D' ) {
V_317 = V_318 ;
} else if ( * V_316 == 'n' || * V_316 == 'N' ) {
V_317 = V_319 ;
} else if ( * V_316 == 'z' || * V_316 == 'Z' ) {
V_317 = V_320 ;
} else {
F_23 ( V_321
L_61
L_62 , V_316 ) ;
return - V_322 ;
}
return 0 ;
}
static T_2 int F_308 ( char * V_316 )
{
int V_13 ;
if ( ! V_316 )
return 0 ;
V_13 = F_307 ( V_316 ) ;
if ( V_13 == 0 )
F_309 ( V_323 , V_316 , V_324 ) ;
return V_13 ;
}
int F_310 ( T_10 * V_325 , int V_326 ,
void T_11 * V_327 , T_8 * V_328 ,
T_12 * V_329 )
{
char V_330 [ V_324 ] ;
int V_13 ;
static F_311 ( V_331 ) ;
F_312 ( & V_331 ) ;
if ( V_326 ) {
if ( strlen ( ( char * ) V_325 -> V_332 ) >= V_324 ) {
V_13 = - V_322 ;
goto V_24;
}
strcpy ( V_330 , ( char * ) V_325 -> V_332 ) ;
}
V_13 = F_313 ( V_325 , V_326 , V_327 , V_328 , V_329 ) ;
if ( V_13 )
goto V_24;
if ( V_326 ) {
int V_333 = V_317 ;
V_13 = F_307 ( ( char * ) V_325 -> V_332 ) ;
if ( V_13 ) {
strncpy ( ( char * ) V_325 -> V_332 , V_330 ,
V_324 ) ;
V_317 = V_333 ;
} else if ( V_333 != V_317 ) {
F_312 ( & V_334 ) ;
F_314 ( NULL , NULL ) ;
F_315 ( & V_334 ) ;
}
}
V_24:
F_315 ( & V_331 ) ;
return V_13 ;
}
static int F_316 ( int V_179 , T_5 * V_335 )
{
int V_175 , V_272 ;
int V_336 = V_337 ;
int V_338 = V_339 ;
const struct V_340 * V_289 = F_317 ( 0 ) ;
if ( ! F_194 ( V_179 , * V_335 ) ) {
F_204 ( V_179 , * V_335 ) ;
return V_179 ;
}
F_318 (n, N_MEMORY) {
if ( F_194 ( V_175 , * V_335 ) )
continue;
V_272 = F_203 ( V_179 , V_175 ) ;
V_272 += ( V_175 < V_179 ) ;
V_289 = F_317 ( V_175 ) ;
if ( ! F_319 ( V_289 ) )
V_272 += V_341 ;
V_272 *= ( V_342 * V_343 ) ;
V_272 += V_344 [ V_175 ] ;
if ( V_272 < V_336 ) {
V_336 = V_272 ;
V_338 = V_175 ;
}
}
if ( V_338 >= 0 )
F_204 ( V_338 , * V_335 ) ;
return V_338 ;
}
static void F_320 ( T_9 * V_282 , int V_179 )
{
int V_345 ;
struct V_162 * V_162 ;
V_162 = & V_282 -> V_346 [ 0 ] ;
for ( V_345 = 0 ; V_162 -> V_176 [ V_345 ] . V_12 != NULL ; V_345 ++ )
;
V_345 = F_304 ( F_205 ( V_179 ) , V_162 , V_345 ) ;
V_162 -> V_176 [ V_345 ] . V_12 = NULL ;
V_162 -> V_176 [ V_345 ] . F_207 = 0 ;
}
static void F_321 ( T_9 * V_282 )
{
int V_345 ;
struct V_162 * V_162 ;
V_162 = & V_282 -> V_346 [ 1 ] ;
V_345 = F_304 ( V_282 , V_162 , 0 ) ;
V_162 -> V_176 [ V_345 ] . V_12 = NULL ;
V_162 -> V_176 [ V_345 ] . F_207 = 0 ;
}
static void F_322 ( T_9 * V_282 , int V_347 )
{
int V_348 , V_345 , V_179 ;
int V_223 ;
struct V_12 * V_149 ;
struct V_162 * V_162 ;
V_162 = & V_282 -> V_346 [ 0 ] ;
V_348 = 0 ;
for ( V_223 = V_283 - 1 ; V_223 >= 0 ; V_223 -- ) {
for ( V_345 = 0 ; V_345 < V_347 ; V_345 ++ ) {
V_179 = V_349 [ V_345 ] ;
V_149 = & F_205 ( V_179 ) -> V_284 [ V_223 ] ;
if ( F_305 ( V_149 ) ) {
F_303 ( V_149 ,
& V_162 -> V_176 [ V_348 ++ ] ) ;
F_306 ( V_223 ) ;
}
}
}
V_162 -> V_176 [ V_348 ] . V_12 = NULL ;
V_162 -> V_176 [ V_348 ] . F_207 = 0 ;
}
static int F_323 ( void )
{
int V_182 , V_223 ;
unsigned long V_350 , V_351 ;
struct V_12 * V_149 ;
int V_352 ;
V_350 = 0 ;
V_351 = 0 ;
F_202 (nid) {
for ( V_223 = 0 ; V_223 < V_283 ; V_223 ++ ) {
V_149 = & F_205 ( V_182 ) -> V_284 [ V_223 ] ;
if ( F_305 ( V_149 ) ) {
if ( V_223 < V_226 )
V_350 += V_149 -> V_80 ;
V_351 += V_149 -> V_80 ;
} else if ( V_223 == V_226 ) {
return V_319 ;
}
}
}
if ( ! V_350 ||
V_350 > V_351 / 2 )
return V_319 ;
V_352 = V_351 /
( F_324 ( V_172 [ V_173 ] ) + 1 ) ;
F_202 (nid) {
V_350 = 0 ;
V_351 = 0 ;
for ( V_223 = 0 ; V_223 < V_283 ; V_223 ++ ) {
V_149 = & F_205 ( V_182 ) -> V_284 [ V_223 ] ;
if ( F_305 ( V_149 ) ) {
if ( V_223 < V_226 )
V_350 += V_149 -> V_307 ;
V_351 += V_149 -> V_307 ;
}
}
if ( V_350 &&
V_351 > V_352 &&
V_350 > V_351 * 70 / 100 )
return V_319 ;
}
return V_320 ;
}
static void F_325 ( void )
{
if ( V_317 == V_318 )
V_353 = F_323 () ;
else
V_353 = V_317 ;
}
static void F_326 ( T_9 * V_282 )
{
int V_345 , V_179 , V_354 ;
enum V_223 V_32 ;
T_5 V_355 ;
int V_356 , V_357 ;
struct V_162 * V_162 ;
int V_31 = V_353 ;
for ( V_32 = 0 ; V_32 < V_358 ; V_32 ++ ) {
V_162 = V_282 -> V_346 + V_32 ;
V_162 -> V_176 [ 0 ] . V_12 = NULL ;
V_162 -> V_176 [ 0 ] . F_207 = 0 ;
}
V_356 = V_282 -> V_359 ;
V_354 = V_198 ;
V_357 = V_356 ;
F_327 ( V_355 ) ;
memset ( V_349 , 0 , sizeof( V_349 ) ) ;
V_345 = 0 ;
while ( ( V_179 = F_316 ( V_356 , & V_355 ) ) >= 0 ) {
if ( F_203 ( V_356 , V_179 ) !=
F_203 ( V_356 , V_357 ) )
V_344 [ V_179 ] = V_354 ;
V_357 = V_179 ;
V_354 -- ;
if ( V_31 == V_319 )
F_320 ( V_282 , V_179 ) ;
else
V_349 [ V_345 ++ ] = V_179 ;
}
if ( V_31 == V_320 ) {
F_322 ( V_282 , V_345 ) ;
}
F_321 ( V_282 ) ;
}
static void F_328 ( T_9 * V_282 )
{
struct V_162 * V_162 ;
struct V_163 * V_164 ;
struct V_174 * V_149 ;
V_162 = & V_282 -> V_346 [ 0 ] ;
V_162 -> V_166 = V_164 = & V_162 -> V_360 ;
F_192 ( V_164 -> V_168 , V_169 ) ;
for ( V_149 = V_162 -> V_176 ; V_149 -> V_12 ; V_149 ++ )
V_164 -> V_177 [ V_149 - V_162 -> V_176 ] = F_329 ( V_149 ) ;
}
int F_330 ( int V_179 )
{
struct V_12 * V_12 ;
( void ) F_252 ( F_253 ( V_179 , V_268 ) ,
F_258 ( V_268 ) ,
NULL ,
& V_12 ) ;
return V_12 -> V_179 ;
}
static void F_325 ( void )
{
V_353 = V_320 ;
}
static void F_326 ( T_9 * V_282 )
{
int V_179 , V_356 ;
enum V_223 V_345 ;
struct V_162 * V_162 ;
V_356 = V_282 -> V_359 ;
V_162 = & V_282 -> V_346 [ 0 ] ;
V_345 = F_304 ( V_282 , V_162 , 0 ) ;
for ( V_179 = V_356 + 1 ; V_179 < V_343 ; V_179 ++ ) {
if ( ! F_331 ( V_179 ) )
continue;
V_345 = F_304 ( F_205 ( V_179 ) , V_162 , V_345 ) ;
}
for ( V_179 = 0 ; V_179 < V_356 ; V_179 ++ ) {
if ( ! F_331 ( V_179 ) )
continue;
V_345 = F_304 ( F_205 ( V_179 ) , V_162 , V_345 ) ;
}
V_162 -> V_176 [ V_345 ] . V_12 = NULL ;
V_162 -> V_176 [ V_345 ] . F_207 = 0 ;
}
static void F_328 ( T_9 * V_282 )
{
V_282 -> V_346 [ 0 ] . V_166 = NULL ;
}
static int F_332 ( void * V_332 )
{
int V_182 ;
int V_112 ;
T_9 * V_361 = V_332 ;
#ifdef V_190
memset ( V_344 , 0 , sizeof( V_344 ) ) ;
#endif
if ( V_361 && ! F_331 ( V_361 -> V_359 ) ) {
F_326 ( V_361 ) ;
F_328 ( V_361 ) ;
}
F_202 (nid) {
T_9 * V_282 = F_205 ( V_182 ) ;
F_326 ( V_282 ) ;
F_328 ( V_282 ) ;
}
F_333 (cpu) {
F_334 ( & F_335 ( V_362 , V_112 ) , 0 ) ;
#ifdef F_336
if ( F_337 ( V_112 ) )
F_338 ( V_112 , F_330 ( F_339 ( V_112 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_314 ( T_9 * V_282 , struct V_12 * V_12 )
{
F_325 () ;
if ( V_363 == V_364 ) {
F_332 ( NULL ) ;
F_340 () ;
F_341 () ;
} else {
#ifdef F_342
if ( V_12 )
F_343 ( V_12 ) ;
#endif
F_344 ( F_332 , V_282 , NULL ) ;
}
V_365 = F_285 () ;
if ( V_365 < ( V_81 * V_287 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_23 ( L_63
L_64 ,
V_198 ,
V_366 [ V_353 ] ,
V_7 ? L_65 : L_66 ,
V_365 ) ;
#ifdef V_190
F_23 ( L_67 , V_367 [ V_368 ] ) ;
#endif
}
static inline unsigned long F_345 ( unsigned long V_102 )
{
unsigned long V_87 = 1 ;
V_102 /= V_369 ;
while ( V_87 < V_102 )
V_87 <<= 1 ;
V_87 = V_154 ( V_87 , 4096UL ) ;
return F_346 ( V_87 , 4UL ) ;
}
static inline unsigned long F_345 ( unsigned long V_102 )
{
return 4096UL ;
}
static inline unsigned long F_347 ( unsigned long V_87 )
{
return F_348 ( ~ V_87 ) ;
}
static int F_349 ( unsigned long V_17 , unsigned long V_95 )
{
unsigned long V_15 ;
for ( V_15 = V_17 ; V_15 < V_95 ; V_15 ++ ) {
if ( ! F_16 ( V_15 ) || F_350 ( F_125 ( V_15 ) ) )
return 1 ;
}
return 0 ;
}
static void F_351 ( struct V_12 * V_12 )
{
unsigned long V_17 , V_15 , V_95 , V_370 ;
struct V_5 * V_5 ;
unsigned long V_371 ;
int V_372 ;
V_17 = V_12 -> V_18 ;
V_95 = F_149 ( V_12 ) ;
V_17 = F_352 ( V_17 , V_81 ) ;
V_372 = F_352 ( F_299 ( V_12 ) , V_81 ) >>
V_83 ;
V_372 = V_154 ( 2 , V_372 ) ;
for ( V_15 = V_17 ; V_15 < V_95 ; V_15 += V_81 ) {
if ( ! F_150 ( V_15 ) )
continue;
V_5 = F_125 ( V_15 ) ;
if ( F_121 ( V_5 ) != F_122 ( V_12 ) )
continue;
V_371 = F_100 ( V_5 ) ;
if ( V_372 > 0 ) {
V_370 = V_154 ( V_15 + V_81 , V_95 ) ;
if ( F_349 ( V_15 , V_370 ) )
continue;
if ( V_371 == V_106 ) {
V_372 -- ;
continue;
}
if ( V_371 == V_122 ) {
F_6 ( V_5 ,
V_106 ) ;
F_124 ( V_12 , V_5 ,
V_106 ) ;
V_372 -- ;
continue;
}
}
if ( V_371 == V_106 ) {
F_6 ( V_5 , V_122 ) ;
F_124 ( V_12 , V_5 , V_122 ) ;
}
}
}
void T_14 F_353 ( unsigned long V_87 , int V_182 , unsigned long V_12 ,
unsigned long V_17 , enum V_373 V_374 )
{
struct V_5 * V_5 ;
unsigned long V_95 = V_17 + V_87 ;
unsigned long V_15 ;
struct V_12 * V_149 ;
if ( V_375 < V_95 - 1 )
V_375 = V_95 - 1 ;
V_149 = & F_205 ( V_182 ) -> V_284 [ V_12 ] ;
for ( V_15 = V_17 ; V_15 < V_95 ; V_15 ++ ) {
if ( V_374 == V_376 ) {
if ( ! F_354 ( V_15 ) )
continue;
if ( ! F_355 ( V_15 , V_182 ) )
continue;
}
V_5 = F_125 ( V_15 ) ;
F_356 ( V_5 , V_12 , V_182 , V_15 ) ;
F_357 ( V_5 , V_12 , V_182 , V_15 ) ;
F_358 ( V_5 ) ;
F_21 ( V_5 ) ;
F_74 ( V_5 ) ;
F_359 ( V_5 ) ;
if ( ( V_149 -> V_18 <= V_15 )
&& ( V_15 < F_149 ( V_149 ) )
&& ! ( V_15 & ( V_81 - 1 ) ) )
F_6 ( V_5 , V_122 ) ;
F_113 ( & V_5 -> V_52 ) ;
#ifdef F_360
if ( ! F_361 ( V_12 ) )
F_362 ( V_5 , F_363 ( V_15 << V_377 ) ) ;
#endif
}
}
static void T_14 F_364 ( struct V_12 * V_12 )
{
int V_31 , V_120 ;
F_153 (order, t) {
F_113 ( & V_12 -> V_53 [ V_31 ] . V_57 [ V_120 ] ) ;
V_12 -> V_53 [ V_31 ] . V_54 = 0 ;
}
}
static int T_14 F_365 ( struct V_12 * V_12 )
{
#ifdef F_366
int V_111 ;
V_111 = V_12 -> V_80 / 1024 ;
if ( V_111 * V_77 > 512 * 1024 )
V_111 = ( 512 * 1024 ) / V_77 ;
V_111 /= 4 ;
if ( V_111 < 1 )
V_111 = 1 ;
V_111 = F_367 ( V_111 + V_111 / 2 ) - 1 ;
return V_111 ;
#else
return 0 ;
#endif
}
static void F_368 ( struct V_64 * V_65 , unsigned long V_85 ,
unsigned long V_111 )
{
V_65 -> V_111 = 1 ;
F_369 () ;
V_65 -> V_85 = V_85 ;
F_369 () ;
V_65 -> V_111 = V_111 ;
}
static void F_370 ( struct V_113 * V_34 , unsigned long V_111 )
{
F_368 ( & V_34 -> V_65 , 6 * V_111 , F_346 ( 1UL , 1 * V_111 ) ) ;
}
static void F_371 ( struct V_113 * V_34 )
{
struct V_64 * V_65 ;
int V_6 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_65 = & V_34 -> V_65 ;
V_65 -> V_63 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_113 ( & V_65 -> V_72 [ V_6 ] ) ;
}
static void F_334 ( struct V_113 * V_34 , unsigned long V_111 )
{
F_371 ( V_34 ) ;
F_370 ( V_34 , V_111 ) ;
}
static void F_372 ( struct V_113 * V_34 ,
unsigned long V_85 )
{
unsigned long V_111 = F_346 ( 1UL , V_85 / 4 ) ;
if ( ( V_85 / 4 ) > ( V_377 * 8 ) )
V_111 = V_377 * 8 ;
F_368 ( & V_34 -> V_65 , V_85 , V_111 ) ;
}
static void T_14 F_373 ( struct V_12 * V_12 ,
struct V_113 * V_65 )
{
if ( V_378 )
F_372 ( V_65 ,
( V_12 -> V_80 /
V_378 ) ) ;
else
F_370 ( V_65 , F_365 ( V_12 ) ) ;
}
static void T_14 F_374 ( struct V_12 * V_12 , int V_112 )
{
struct V_113 * V_65 = F_138 ( V_12 -> V_115 , V_112 ) ;
F_371 ( V_65 ) ;
F_373 ( V_12 , V_65 ) ;
}
static void T_14 F_343 ( struct V_12 * V_12 )
{
int V_112 ;
V_12 -> V_115 = F_375 ( struct V_113 ) ;
F_333 (cpu)
F_374 ( V_12 , V_112 ) ;
}
void T_2 F_376 ( void )
{
struct V_12 * V_12 ;
F_137 (zone)
F_343 ( V_12 ) ;
}
static T_15 T_16
int F_377 ( struct V_12 * V_12 , unsigned long V_379 )
{
int V_32 ;
struct V_380 * V_282 = V_12 -> V_180 ;
T_8 V_381 ;
V_12 -> F_345 =
F_345 ( V_379 ) ;
V_12 -> F_347 =
F_347 ( V_12 -> F_345 ) ;
V_381 = V_12 -> F_345
* sizeof( V_382 ) ;
if ( ! F_378 () ) {
V_12 -> V_383 = ( V_382 * )
F_379 ( V_282 , V_381 ) ;
} else {
V_12 -> V_383 = F_380 ( V_381 ) ;
}
if ( ! V_12 -> V_383 )
return - V_148 ;
for ( V_32 = 0 ; V_32 < V_12 -> F_345 ; ++ V_32 )
F_381 ( V_12 -> V_383 + V_32 ) ;
return 0 ;
}
static T_14 void F_382 ( struct V_12 * V_12 )
{
V_12 -> V_115 = & V_362 ;
if ( F_305 ( V_12 ) )
F_23 ( V_384 L_68 ,
V_12 -> V_290 , V_12 -> V_307 ,
F_365 ( V_12 ) ) ;
}
int T_14 F_383 ( struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_87 ,
enum V_373 V_374 )
{
struct V_380 * V_282 = V_12 -> V_180 ;
int V_13 ;
V_13 = F_377 ( V_12 , V_87 ) ;
if ( V_13 )
return V_13 ;
V_282 -> V_315 = F_207 ( V_12 ) + 1 ;
V_12 -> V_18 = V_18 ;
F_384 ( V_385 , L_69 ,
L_70 ,
V_282 -> V_359 ,
( unsigned long ) F_207 ( V_12 ) ,
V_18 , ( V_18 + V_87 ) ) ;
F_364 ( V_12 ) ;
return 0 ;
}
int T_14 F_385 ( unsigned long V_15 )
{
unsigned long V_17 , V_95 ;
int V_182 ;
static unsigned long T_17 V_386 , V_387 ;
static int T_17 V_388 ;
if ( V_386 <= V_15 && V_15 < V_387 )
return V_388 ;
V_182 = F_386 ( V_15 , & V_17 , & V_95 ) ;
if ( V_182 != - 1 ) {
V_386 = V_17 ;
V_387 = V_95 ;
V_388 = V_182 ;
}
return V_182 ;
}
int T_14 F_387 ( unsigned long V_15 )
{
int V_182 ;
V_182 = F_385 ( V_15 ) ;
if ( V_182 >= 0 )
return V_182 ;
return 0 ;
}
bool T_14 F_355 ( unsigned long V_15 , int V_179 )
{
int V_182 ;
V_182 = F_385 ( V_15 ) ;
if ( V_182 >= 0 && V_182 != V_179 )
return false ;
return true ;
}
void T_2 F_388 ( int V_182 , unsigned long V_389 )
{
unsigned long V_17 , V_95 ;
int V_32 , V_390 ;
F_389 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_17 = V_154 ( V_17 , V_389 ) ;
V_95 = V_154 ( V_95 , V_389 ) ;
if ( V_17 < V_95 )
F_390 ( F_205 ( V_390 ) ,
F_391 ( V_17 ) ,
( V_95 - V_17 ) << V_377 ) ;
}
}
void T_2 F_392 ( int V_182 )
{
unsigned long V_17 , V_95 ;
int V_32 , V_390 ;
F_389 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_393 ( V_390 , V_17 , V_95 ) ;
}
void T_14 F_394 ( unsigned int V_182 ,
unsigned long * V_17 , unsigned long * V_95 )
{
unsigned long V_391 , V_392 ;
int V_32 ;
* V_17 = - 1UL ;
* V_95 = 0 ;
F_389 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_17 = V_154 ( * V_17 , V_391 ) ;
* V_95 = F_346 ( * V_95 , V_392 ) ;
}
if ( * V_17 == - 1UL )
* V_17 = 0 ;
}
static void T_2 F_395 ( void )
{
int V_393 ;
for ( V_393 = V_283 - 1 ; V_393 >= 0 ; V_393 -- ) {
if ( V_393 == V_394 )
continue;
if ( V_395 [ V_393 ] >
V_396 [ V_393 ] )
break;
}
F_42 ( V_393 == - 1 ) ;
V_397 = V_393 ;
}
static void T_14 F_396 ( int V_182 ,
unsigned long V_223 ,
unsigned long V_398 ,
unsigned long V_399 ,
unsigned long * V_18 ,
unsigned long * F_149 )
{
if ( V_400 [ V_182 ] ) {
if ( V_223 == V_394 ) {
* V_18 = V_400 [ V_182 ] ;
* F_149 = V_154 ( V_399 ,
V_395 [ V_397 ] ) ;
} else if ( * V_18 < V_400 [ V_182 ] &&
* F_149 > V_400 [ V_182 ] ) {
* F_149 = V_400 [ V_182 ] ;
} else if ( * V_18 >= V_400 [ V_182 ] )
* V_18 = * F_149 ;
}
}
static unsigned long T_14 F_397 ( int V_182 ,
unsigned long V_223 ,
unsigned long V_398 ,
unsigned long V_399 ,
unsigned long * V_401 )
{
unsigned long V_18 , F_149 ;
V_18 = V_396 [ V_223 ] ;
F_149 = V_395 [ V_223 ] ;
F_396 ( V_182 , V_223 ,
V_398 , V_399 ,
& V_18 , & F_149 ) ;
if ( F_149 < V_398 || V_18 > V_399 )
return 0 ;
F_149 = V_154 ( F_149 , V_399 ) ;
V_18 = F_346 ( V_18 , V_398 ) ;
return F_149 - V_18 ;
}
unsigned long T_14 F_398 ( int V_182 ,
unsigned long V_402 ,
unsigned long V_403 )
{
unsigned long V_404 = V_403 - V_402 ;
unsigned long V_17 , V_95 ;
int V_32 ;
F_389 (i, nid, &start_pfn, &end_pfn, NULL) {
V_17 = F_399 ( V_17 , V_402 , V_403 ) ;
V_95 = F_399 ( V_95 , V_402 , V_403 ) ;
V_404 -= V_95 - V_17 ;
}
return V_404 ;
}
unsigned long T_2 F_400 ( unsigned long V_17 ,
unsigned long V_95 )
{
return F_398 ( V_343 , V_17 , V_95 ) ;
}
static unsigned long T_14 F_401 ( int V_182 ,
unsigned long V_223 ,
unsigned long V_398 ,
unsigned long V_399 ,
unsigned long * V_401 )
{
unsigned long V_405 = V_396 [ V_223 ] ;
unsigned long V_406 = V_395 [ V_223 ] ;
unsigned long V_18 , F_149 ;
V_18 = F_399 ( V_398 , V_405 , V_406 ) ;
F_149 = F_399 ( V_399 , V_405 , V_406 ) ;
F_396 ( V_182 , V_223 ,
V_398 , V_399 ,
& V_18 , & F_149 ) ;
return F_398 ( V_182 , V_18 , F_149 ) ;
}
static inline unsigned long T_14 F_397 ( int V_182 ,
unsigned long V_223 ,
unsigned long V_398 ,
unsigned long V_399 ,
unsigned long * V_407 )
{
return V_407 [ V_223 ] ;
}
static inline unsigned long T_14 F_401 ( int V_182 ,
unsigned long V_223 ,
unsigned long V_398 ,
unsigned long V_399 ,
unsigned long * V_408 )
{
if ( ! V_408 )
return 0 ;
return V_408 [ V_223 ] ;
}
static void T_14 F_402 ( struct V_380 * V_282 ,
unsigned long V_398 ,
unsigned long V_399 ,
unsigned long * V_407 ,
unsigned long * V_408 )
{
unsigned long V_409 , V_410 = 0 ;
enum V_223 V_32 ;
for ( V_32 = 0 ; V_32 < V_283 ; V_32 ++ )
V_410 += F_397 ( V_282 -> V_359 , V_32 ,
V_398 ,
V_399 ,
V_407 ) ;
V_282 -> V_411 = V_410 ;
V_409 = V_410 ;
for ( V_32 = 0 ; V_32 < V_283 ; V_32 ++ )
V_409 -=
F_401 ( V_282 -> V_359 , V_32 ,
V_398 , V_399 ,
V_408 ) ;
V_282 -> V_412 = V_409 ;
F_23 ( V_384 L_71 , V_282 -> V_359 ,
V_409 ) ;
}
static unsigned long T_2 F_403 ( unsigned long V_18 , unsigned long V_413 )
{
unsigned long V_414 ;
V_413 += V_18 & ( V_81 - 1 ) ;
V_414 = F_352 ( V_413 , V_81 ) ;
V_414 = V_414 >> V_83 ;
V_414 *= V_415 ;
V_414 = F_352 ( V_414 , 8 * sizeof( unsigned long ) ) ;
return V_414 / 8 ;
}
static void T_2 F_404 ( struct V_380 * V_282 ,
struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_413 )
{
unsigned long V_414 = F_403 ( V_18 , V_413 ) ;
V_12 -> V_416 = NULL ;
if ( V_414 )
V_12 -> V_416 = F_379 ( V_282 ,
V_414 ) ;
}
static inline void F_404 ( struct V_380 * V_282 , struct V_12 * V_12 ,
unsigned long V_18 , unsigned long V_413 ) {}
void T_6 F_405 ( void )
{
unsigned int V_31 ;
if ( V_83 )
return;
if ( V_417 > V_377 )
V_31 = V_418 ;
else
V_31 = V_41 - 1 ;
V_83 = V_31 ;
}
void T_6 F_405 ( void )
{
}
static unsigned long T_6 F_406 ( unsigned long V_19 ,
unsigned long V_307 )
{
unsigned long V_102 = V_19 ;
if ( V_19 > V_307 + ( V_307 >> 4 ) &&
F_133 ( V_419 ) )
V_102 = V_307 ;
return F_276 ( V_102 * sizeof( struct V_5 ) ) >> V_377 ;
}
static void T_6 F_407 ( struct V_380 * V_282 ,
unsigned long V_398 , unsigned long V_399 ,
unsigned long * V_407 , unsigned long * V_408 )
{
enum V_223 V_345 ;
int V_182 = V_282 -> V_359 ;
unsigned long V_18 = V_282 -> V_398 ;
int V_13 ;
F_408 ( V_282 ) ;
#ifdef F_409
F_410 ( & V_282 -> V_420 ) ;
V_282 -> V_421 = 0 ;
V_282 -> V_422 = V_23 ;
#endif
F_381 ( & V_282 -> V_423 ) ;
F_381 ( & V_282 -> V_424 ) ;
F_411 ( V_282 ) ;
for ( V_345 = 0 ; V_345 < V_283 ; V_345 ++ ) {
struct V_12 * V_12 = V_282 -> V_284 + V_345 ;
unsigned long V_87 , V_425 , V_426 , V_427 ;
V_87 = F_397 ( V_182 , V_345 , V_398 ,
V_399 , V_407 ) ;
V_425 = V_426 = V_87 - F_401 ( V_182 , V_345 ,
V_398 ,
V_399 ,
V_408 ) ;
V_427 = F_406 ( V_87 , V_425 ) ;
if ( V_426 >= V_427 ) {
V_426 -= V_427 ;
if ( V_427 )
F_23 ( V_384
L_72 ,
V_367 [ V_345 ] , V_427 ) ;
} else
F_23 ( V_321
L_73 ,
V_367 [ V_345 ] , V_427 , V_426 ) ;
if ( V_345 == 0 && V_426 > V_428 ) {
V_426 -= V_428 ;
F_23 ( V_384 L_74 ,
V_367 [ 0 ] , V_428 ) ;
}
if ( ! F_361 ( V_345 ) )
V_429 += V_426 ;
else if ( V_429 > V_427 * 2 )
V_429 -= V_427 ;
V_430 += V_426 ;
V_12 -> V_19 = V_87 ;
V_12 -> V_307 = V_425 ;
V_12 -> V_80 = F_361 ( V_345 ) ? V_425 : V_426 ;
#ifdef V_190
V_12 -> V_179 = V_182 ;
V_12 -> V_431 = ( V_426 * V_432 )
/ 100 ;
V_12 -> V_433 = ( V_426 * V_434 ) / 100 ;
#endif
V_12 -> V_290 = V_367 [ V_345 ] ;
F_410 ( & V_12 -> V_68 ) ;
F_410 ( & V_12 -> V_435 ) ;
F_412 ( V_12 ) ;
V_12 -> V_180 = V_282 ;
F_382 ( V_12 ) ;
F_244 ( V_12 , V_131 , V_12 -> V_80 ) ;
F_413 ( & V_12 -> V_436 ) ;
if ( ! V_87 )
continue;
F_405 () ;
F_404 ( V_282 , V_12 , V_18 , V_87 ) ;
V_13 = F_383 ( V_12 , V_18 ,
V_87 , V_376 ) ;
F_120 ( V_13 ) ;
F_414 ( V_87 , V_182 , V_345 , V_18 ) ;
V_18 += V_87 ;
}
}
static void T_16 F_415 ( struct V_380 * V_282 )
{
if ( ! V_282 -> V_411 )
return;
#ifdef F_416
if ( ! V_282 -> V_437 ) {
unsigned long V_87 , V_438 , V_265 ;
struct V_5 * V_439 ;
V_438 = V_282 -> V_398 & ~ ( V_440 - 1 ) ;
V_265 = F_417 ( V_282 ) ;
V_265 = F_418 ( V_265 , V_440 ) ;
V_87 = ( V_265 - V_438 ) * sizeof( struct V_5 ) ;
V_439 = F_419 ( V_282 -> V_359 , V_87 ) ;
if ( ! V_439 )
V_439 = F_379 ( V_282 , V_87 ) ;
V_282 -> V_437 = V_439 + ( V_282 -> V_398 - V_438 ) ;
}
#ifndef F_420
if ( V_282 == F_205 ( 0 ) ) {
V_441 = F_205 ( 0 ) -> V_437 ;
#ifdef F_421
if ( F_10 ( V_441 ) != V_282 -> V_398 )
V_441 -= ( V_282 -> V_398 - V_442 ) ;
#endif
}
#endif
#endif
}
void T_6 F_422 ( int V_182 , unsigned long * V_407 ,
unsigned long V_398 , unsigned long * V_408 )
{
T_9 * V_282 = F_205 ( V_182 ) ;
unsigned long V_17 = 0 ;
unsigned long V_95 = 0 ;
F_2 ( V_282 -> V_315 || V_282 -> V_151 ) ;
V_282 -> V_359 = V_182 ;
V_282 -> V_398 = V_398 ;
F_201 ( V_182 ) ;
#ifdef F_421
F_394 ( V_182 , & V_17 , & V_95 ) ;
#endif
F_402 ( V_282 , V_17 , V_95 ,
V_407 , V_408 ) ;
F_415 ( V_282 ) ;
#ifdef F_416
F_23 ( V_384 L_75 ,
V_182 , ( unsigned long ) V_282 ,
( unsigned long ) V_282 -> V_437 ) ;
#endif
F_407 ( V_282 , V_17 , V_95 ,
V_407 , V_408 ) ;
}
void T_2 F_423 ( void )
{
unsigned int V_179 ;
unsigned int V_443 = 0 ;
F_424 (node, node_possible_map)
V_443 = V_179 ;
V_444 = V_443 + 1 ;
}
unsigned long T_2 F_425 ( void )
{
unsigned long V_445 = 0 , V_446 = 0 ;
unsigned long V_438 , V_265 , V_447 ;
int V_388 = - 1 ;
int V_32 , V_182 ;
F_389 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_438 || V_388 < 0 || V_388 == V_182 ) {
V_388 = V_182 ;
V_446 = V_265 ;
continue;
}
V_447 = ~ ( ( 1 << F_426 ( V_438 ) ) - 1 ) ;
while ( V_447 && V_446 <= ( V_438 & ( V_447 << 1 ) ) )
V_447 <<= 1 ;
V_445 |= V_447 ;
}
return ~ V_445 + 1 ;
}
static unsigned long T_2 F_427 ( int V_182 )
{
unsigned long V_448 = V_449 ;
unsigned long V_17 ;
int V_32 ;
F_389 (i, nid, &start_pfn, NULL, NULL)
V_448 = V_154 ( V_448 , V_17 ) ;
if ( V_448 == V_449 ) {
F_23 ( V_321
L_76 , V_182 ) ;
return 0 ;
}
return V_448 ;
}
unsigned long T_2 F_428 ( void )
{
return F_427 ( V_343 ) ;
}
static unsigned long T_2 F_429 ( void )
{
unsigned long V_410 = 0 ;
unsigned long V_17 , V_95 ;
int V_32 , V_182 ;
F_389 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_102 = V_95 - V_17 ;
V_410 += V_102 ;
if ( V_102 )
F_430 ( V_182 , V_173 ) ;
}
return V_410 ;
}
static void T_2 F_431 ( void )
{
int V_32 , V_182 ;
unsigned long V_450 ;
unsigned long V_451 , V_452 ;
T_5 V_453 = V_172 [ V_173 ] ;
unsigned long V_410 = F_429 () ;
int V_454 = F_324 ( V_172 [ V_173 ] ) ;
if ( V_455 ) {
unsigned long V_456 ;
V_455 =
F_352 ( V_455 , V_440 ) ;
V_456 = V_410 - V_455 ;
V_457 = F_346 ( V_457 , V_456 ) ;
}
if ( ! V_457 )
goto V_24;
F_395 () ;
V_450 = V_396 [ V_397 ] ;
V_251:
V_451 = V_457 / V_454 ;
F_318 (nid, N_MEMORY) {
unsigned long V_17 , V_95 ;
if ( V_457 < V_451 )
V_451 = V_457 / V_454 ;
V_452 = V_451 ;
F_389 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_458 ;
V_17 = F_346 ( V_17 , V_400 [ V_182 ] ) ;
if ( V_17 >= V_95 )
continue;
if ( V_17 < V_450 ) {
unsigned long V_459 ;
V_459 = V_154 ( V_95 , V_450 )
- V_17 ;
V_452 -= V_154 ( V_459 ,
V_452 ) ;
V_457 -= V_154 ( V_459 ,
V_457 ) ;
if ( V_95 <= V_450 ) {
V_400 [ V_182 ] = V_95 ;
continue;
}
V_17 = V_450 ;
}
V_458 = V_95 - V_17 ;
if ( V_458 > V_452 )
V_458 = V_452 ;
V_400 [ V_182 ] = V_17 + V_458 ;
V_457 -= V_154 ( V_457 ,
V_458 ) ;
V_452 -= V_458 ;
if ( ! V_452 )
break;
}
}
V_454 -- ;
if ( V_454 && V_457 > V_454 )
goto V_251;
for ( V_182 = 0 ; V_182 < V_343 ; V_182 ++ )
V_400 [ V_182 ] =
F_352 ( V_400 [ V_182 ] , V_440 ) ;
V_24:
V_172 [ V_173 ] = V_453 ;
}
static void F_432 ( T_9 * V_282 , int V_182 )
{
enum V_223 V_223 ;
if ( V_173 == V_460 )
return;
for ( V_223 = 0 ; V_223 <= V_394 - 1 ; V_223 ++ ) {
struct V_12 * V_12 = & V_282 -> V_284 [ V_223 ] ;
if ( F_305 ( V_12 ) ) {
F_430 ( V_182 , V_461 ) ;
if ( V_460 != V_461 &&
V_223 <= V_226 )
F_430 ( V_182 , V_460 ) ;
break;
}
}
}
void T_2 F_433 ( unsigned long * V_119 )
{
unsigned long V_17 , V_95 ;
int V_32 , V_182 ;
memset ( V_396 , 0 ,
sizeof( V_396 ) ) ;
memset ( V_395 , 0 ,
sizeof( V_395 ) ) ;
V_396 [ 0 ] = F_428 () ;
V_395 [ 0 ] = V_119 [ 0 ] ;
for ( V_32 = 1 ; V_32 < V_283 ; V_32 ++ ) {
if ( V_32 == V_394 )
continue;
V_396 [ V_32 ] =
V_395 [ V_32 - 1 ] ;
V_395 [ V_32 ] =
F_346 ( V_119 [ V_32 ] , V_396 [ V_32 ] ) ;
}
V_396 [ V_394 ] = 0 ;
V_395 [ V_394 ] = 0 ;
memset ( V_400 , 0 , sizeof( V_400 ) ) ;
F_431 () ;
F_23 ( L_77 ) ;
for ( V_32 = 0 ; V_32 < V_283 ; V_32 ++ ) {
if ( V_32 == V_394 )
continue;
F_23 ( V_462 L_78 , V_367 [ V_32 ] ) ;
if ( V_396 [ V_32 ] ==
V_395 [ V_32 ] )
F_23 ( V_462 L_79 ) ;
else
F_23 ( V_462 L_80 ,
V_396 [ V_32 ] << V_377 ,
( V_395 [ V_32 ]
<< V_377 ) - 1 ) ;
}
F_23 ( L_81 ) ;
for ( V_32 = 0 ; V_32 < V_343 ; V_32 ++ ) {
if ( V_400 [ V_32 ] )
F_23 ( L_82 , V_32 ,
V_400 [ V_32 ] << V_377 ) ;
}
F_23 ( L_83 ) ;
F_389 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_23 ( L_84 , V_182 ,
V_17 << V_377 , ( V_95 << V_377 ) - 1 ) ;
F_434 () ;
F_423 () ;
F_202 (nid) {
T_9 * V_282 = F_205 ( V_182 ) ;
F_422 ( V_182 , NULL ,
F_427 ( V_182 ) , NULL ) ;
if ( V_282 -> V_412 )
F_430 ( V_182 , V_173 ) ;
F_432 ( V_282 , V_182 ) ;
}
}
static int T_2 F_435 ( char * V_34 , unsigned long * V_463 )
{
unsigned long long V_464 ;
if ( ! V_34 )
return - V_322 ;
V_464 = F_436 ( V_34 , & V_34 ) ;
* V_463 = V_464 >> V_377 ;
F_2 ( ( V_464 >> V_377 ) > V_449 ) ;
return 0 ;
}
static int T_2 F_437 ( char * V_34 )
{
return F_435 ( V_34 , & V_457 ) ;
}
static int T_2 F_438 ( char * V_34 )
{
return F_435 ( V_34 , & V_455 ) ;
}
void F_109 ( struct V_5 * V_5 , long V_63 )
{
F_76 ( & V_465 ) ;
F_17 ( V_5 ) -> V_80 += V_63 ;
V_274 += V_63 ;
#ifdef F_293
if ( F_92 ( V_5 ) )
V_279 += V_63 ;
#endif
F_85 ( & V_465 ) ;
}
unsigned long F_439 ( void * V_438 , void * V_265 , int V_466 , char * V_316 )
{
void * V_348 ;
unsigned long V_102 = 0 ;
V_438 = ( void * ) F_276 ( ( unsigned long ) V_438 ) ;
V_265 = ( void * ) ( ( unsigned long ) V_265 & V_467 ) ;
for ( V_348 = V_438 ; V_348 < V_265 ; V_348 += V_77 , V_102 ++ ) {
if ( ( unsigned int ) V_466 <= 0xFF )
memset ( V_348 , V_466 , V_77 ) ;
F_440 ( F_166 ( V_348 ) ) ;
}
if ( V_102 && V_316 )
F_441 ( L_85 ,
V_316 , V_102 << ( V_377 - 10 ) , V_438 , V_265 ) ;
return V_102 ;
}
void F_442 ( struct V_5 * V_5 )
{
F_443 ( V_5 ) ;
V_274 ++ ;
F_17 ( V_5 ) -> V_80 ++ ;
V_279 ++ ;
}
void T_2 F_444 ( const char * V_133 )
{
unsigned long V_468 , V_469 , V_470 , V_471 , V_472 ;
unsigned long V_473 , V_474 ;
V_468 = F_445 () ;
V_469 = V_475 - V_476 ;
V_470 = V_477 - V_478 ;
V_471 = V_479 - V_480 ;
V_472 = V_481 - V_482 ;
V_474 = V_483 - V_484 ;
V_473 = V_485 - V_486 ;
#define F_446 ( V_438 , V_265 , V_87 , V_348 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_446 ( V_484 , V_483 , V_474 ,
V_486 , V_473 ) ;
F_446 ( V_476 , V_475 , V_469 , V_486 , V_473 ) ;
F_446 ( V_478 , V_477 , V_470 , V_484 , V_474 ) ;
F_446 ( V_476 , V_475 , V_469 , V_480 , V_471 ) ;
F_446 ( V_478 , V_477 , V_470 , V_480 , V_471 ) ;
#undef F_446
F_23 ( L_86
L_87
L_88
#ifdef F_293
L_89
#endif
L_90 ,
F_447 () << ( V_377 - 10 ) , V_468 << ( V_377 - 10 ) ,
V_469 >> 10 , V_470 >> 10 , V_471 >> 10 ,
( V_474 + V_473 ) >> 10 , V_472 >> 10 ,
( V_468 - V_274 ) << ( V_377 - 10 ) ,
#ifdef F_293
V_279 << ( V_377 - 10 ) ,
#endif
V_133 ? L_91 : L_92 , V_133 ? V_133 : L_92 ) ;
}
void T_2 F_448 ( unsigned long V_487 )
{
V_428 = V_487 ;
}
void T_2 F_449 ( unsigned long * V_407 )
{
F_422 ( 0 , V_407 ,
F_450 ( V_488 ) >> V_377 , NULL ) ;
}
static int F_451 ( struct V_489 * V_361 ,
unsigned long V_490 , void * V_491 )
{
int V_112 = ( unsigned long ) V_491 ;
if ( V_490 == V_492 || V_490 == V_493 ) {
F_452 ( V_112 ) ;
F_136 ( V_112 ) ;
F_453 ( V_112 ) ;
F_454 ( V_112 ) ;
}
return V_494 ;
}
void T_2 F_455 ( void )
{
F_456 ( F_451 , 0 ) ;
}
static void F_457 ( void )
{
struct V_380 * V_282 ;
unsigned long V_495 = 0 ;
enum V_223 V_32 , V_345 ;
F_458 (pgdat) {
for ( V_32 = 0 ; V_32 < V_283 ; V_32 ++ ) {
struct V_12 * V_12 = V_282 -> V_284 + V_32 ;
unsigned long F_346 = 0 ;
for ( V_345 = V_32 ; V_345 < V_283 ; V_345 ++ ) {
if ( V_12 -> V_155 [ V_345 ] > F_346 )
F_346 = V_12 -> V_155 [ V_345 ] ;
}
F_346 += F_245 ( V_12 ) ;
if ( F_346 > V_12 -> V_80 )
F_346 = V_12 -> V_80 ;
V_495 += F_346 ;
V_12 -> V_496 = F_346 ;
}
}
V_496 = V_495 ;
V_497 = V_495 ;
}
static void F_459 ( void )
{
struct V_380 * V_282 ;
enum V_223 V_345 , V_498 ;
F_458 (pgdat) {
for ( V_345 = 0 ; V_345 < V_283 ; V_345 ++ ) {
struct V_12 * V_12 = V_282 -> V_284 + V_345 ;
unsigned long V_80 = V_12 -> V_80 ;
V_12 -> V_155 [ V_345 ] = 0 ;
V_498 = V_345 ;
while ( V_498 ) {
struct V_12 * V_499 ;
V_498 -- ;
if ( V_500 [ V_498 ] < 1 )
V_500 [ V_498 ] = 1 ;
V_499 = V_282 -> V_284 + V_498 ;
V_499 -> V_155 [ V_345 ] = V_80 /
V_500 [ V_498 ] ;
V_80 += V_499 -> V_80 ;
}
}
}
F_457 () ;
}
static void F_460 ( void )
{
unsigned long V_501 = V_502 >> ( V_377 - 10 ) ;
unsigned long V_503 = 0 ;
struct V_12 * V_12 ;
unsigned long V_60 ;
F_461 (zone) {
if ( ! F_462 ( V_12 ) )
V_503 += V_12 -> V_80 ;
}
F_461 (zone) {
T_19 V_289 ;
F_148 ( & V_12 -> V_68 , V_60 ) ;
V_289 = ( T_19 ) V_501 * V_12 -> V_80 ;
F_463 ( V_289 , V_503 ) ;
if ( F_462 ( V_12 ) ) {
unsigned long V_504 ;
V_504 = V_12 -> V_80 / 1024 ;
V_504 = F_399 ( V_504 , V_505 , 128UL ) ;
V_12 -> V_124 [ V_506 ] = V_504 ;
} else {
V_12 -> V_124 [ V_506 ] = V_289 ;
}
V_12 -> V_124 [ V_507 ] = F_299 ( V_12 ) + ( V_289 >> 2 ) ;
V_12 -> V_124 [ V_508 ] = F_299 ( V_12 ) + ( V_289 >> 1 ) ;
F_83 ( V_12 , V_131 ,
F_245 ( V_12 ) -
F_168 ( V_12 ) -
F_187 ( V_12 , V_131 ) ) ;
F_351 ( V_12 ) ;
F_156 ( & V_12 -> V_68 , V_60 ) ;
}
F_457 () ;
}
void F_464 ( void )
{
F_312 ( & V_334 ) ;
F_460 () ;
F_315 ( & V_334 ) ;
}
static void T_14 F_465 ( struct V_12 * V_12 )
{
unsigned int V_509 , V_510 ;
V_509 = V_12 -> V_80 >> ( 30 - V_377 ) ;
if ( V_509 )
V_510 = F_466 ( 10 * V_509 ) ;
else
V_510 = 1 ;
V_12 -> V_511 = V_510 ;
}
static void T_14 F_467 ( void )
{
struct V_12 * V_12 ;
F_461 (zone)
F_465 ( V_12 ) ;
}
int T_14 F_468 ( void )
{
unsigned long V_512 ;
int V_513 ;
V_512 = F_284 () * ( V_77 >> 10 ) ;
V_513 = F_466 ( V_512 * 16 ) ;
if ( V_513 > V_514 ) {
V_502 = V_513 ;
if ( V_502 < 128 )
V_502 = 128 ;
if ( V_502 > 65536 )
V_502 = 65536 ;
} else {
F_217 ( L_93 ,
V_513 , V_514 ) ;
}
F_464 () ;
F_469 () ;
F_459 () ;
F_467 () ;
return 0 ;
}
int F_470 ( T_10 * V_325 , int V_326 ,
void T_11 * V_327 , T_8 * V_328 , T_12 * V_329 )
{
F_471 ( V_325 , V_326 , V_327 , V_328 , V_329 ) ;
if ( V_326 ) {
V_514 = V_502 ;
F_464 () ;
}
return 0 ;
}
int F_472 ( T_10 * V_325 , int V_326 ,
void T_11 * V_327 , T_8 * V_328 , T_12 * V_329 )
{
struct V_12 * V_12 ;
int V_515 ;
V_515 = F_473 ( V_325 , V_326 , V_327 , V_328 , V_329 ) ;
if ( V_515 )
return V_515 ;
F_461 (zone)
V_12 -> V_431 = ( V_12 -> V_80 *
V_432 ) / 100 ;
return 0 ;
}
int F_474 ( T_10 * V_325 , int V_326 ,
void T_11 * V_327 , T_8 * V_328 , T_12 * V_329 )
{
struct V_12 * V_12 ;
int V_515 ;
V_515 = F_473 ( V_325 , V_326 , V_327 , V_328 , V_329 ) ;
if ( V_515 )
return V_515 ;
F_461 (zone)
V_12 -> V_433 = ( V_12 -> V_80 *
V_434 ) / 100 ;
return 0 ;
}
int F_475 ( T_10 * V_325 , int V_326 ,
void T_11 * V_327 , T_8 * V_328 , T_12 * V_329 )
{
F_473 ( V_325 , V_326 , V_327 , V_328 , V_329 ) ;
F_459 () ;
return 0 ;
}
int F_476 ( T_10 * V_325 , int V_326 ,
void T_11 * V_327 , T_8 * V_328 , T_12 * V_329 )
{
struct V_12 * V_12 ;
unsigned int V_112 ;
int V_13 ;
V_13 = F_473 ( V_325 , V_326 , V_327 , V_328 , V_329 ) ;
if ( ! V_326 || ( V_13 < 0 ) )
return V_13 ;
F_312 ( & V_516 ) ;
F_137 (zone) {
unsigned long V_85 ;
V_85 = V_12 -> V_80 / V_378 ;
F_333 (cpu)
F_372 ( F_138 ( V_12 -> V_115 , V_112 ) ,
V_85 ) ;
}
F_315 ( & V_516 ) ;
return 0 ;
}
static int T_2 F_477 ( char * V_133 )
{
if ( ! V_133 )
return 0 ;
V_517 = F_478 ( V_133 , & V_133 , 0 ) ;
return 1 ;
}
void * T_2 F_479 ( const char * V_518 ,
unsigned long V_519 ,
unsigned long V_520 ,
int V_521 ,
int V_60 ,
unsigned int * V_522 ,
unsigned int * V_523 ,
unsigned long V_524 ,
unsigned long V_525 )
{
unsigned long long F_346 = V_525 ;
unsigned long V_526 , V_87 ;
void * V_325 = NULL ;
if ( ! V_520 ) {
V_520 = V_429 ;
if ( V_377 < 20 )
V_520 = F_480 ( V_520 , ( 1 << 20 ) / V_77 ) ;
if ( V_521 > V_377 )
V_520 >>= ( V_521 - V_377 ) ;
else
V_520 <<= ( V_377 - V_521 ) ;
if ( F_7 ( V_60 & V_527 ) ) {
F_2 ( ! ( V_60 & V_528 ) ) ;
if ( ! ( V_520 >> * V_522 ) ) {
V_520 = 1UL << * V_522 ;
F_120 ( ! V_520 ) ;
}
} else if ( F_7 ( ( V_520 * V_519 ) < V_77 ) )
V_520 = V_77 / V_519 ;
}
V_520 = F_481 ( V_520 ) ;
if ( F_346 == 0 ) {
F_346 = ( ( unsigned long long ) V_430 << V_377 ) >> 4 ;
F_463 ( F_346 , V_519 ) ;
}
F_346 = V_154 ( F_346 , 0x80000000ULL ) ;
if ( V_520 < V_524 )
V_520 = V_524 ;
if ( V_520 > F_346 )
V_520 = F_346 ;
V_526 = F_482 ( V_520 ) ;
do {
V_87 = V_519 << V_526 ;
if ( V_60 & V_528 )
V_325 = F_483 ( V_87 ) ;
else if ( V_517 )
V_325 = F_484 ( V_87 , V_529 , V_530 ) ;
else {
if ( F_279 ( V_87 ) < V_41 ) {
V_325 = F_278 ( V_87 , V_529 ) ;
F_485 ( V_325 , V_87 , 1 , V_529 ) ;
}
}
} while ( ! V_325 && V_87 > V_77 && -- V_526 );
if ( ! V_325 )
F_486 ( L_94 , V_518 ) ;
F_23 ( V_44 L_95 ,
V_518 ,
( 1UL << V_526 ) ,
F_482 ( V_87 ) - V_377 ,
V_87 ) ;
if ( V_522 )
* V_522 = V_526 ;
if ( V_523 )
* V_523 = ( 1 << V_526 ) - 1 ;
return V_325 ;
}
static inline unsigned long * F_487 ( struct V_12 * V_12 ,
unsigned long V_15 )
{
#ifdef V_419
return F_488 ( V_15 ) -> V_416 ;
#else
return V_12 -> V_416 ;
#endif
}
static inline int F_489 ( struct V_12 * V_12 , unsigned long V_15 )
{
#ifdef V_419
V_15 &= ( V_531 - 1 ) ;
return ( V_15 >> V_83 ) * V_415 ;
#else
V_15 = V_15 - F_490 ( V_12 -> V_18 , V_81 ) ;
return ( V_15 >> V_83 ) * V_415 ;
#endif
}
unsigned long F_491 ( struct V_5 * V_5 ,
int V_532 , int V_533 )
{
struct V_12 * V_12 ;
unsigned long * V_534 ;
unsigned long V_15 , V_535 ;
unsigned long V_60 = 0 ;
unsigned long V_536 = 1 ;
V_12 = F_17 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
V_534 = F_487 ( V_12 , V_15 ) ;
V_535 = F_489 ( V_12 , V_15 ) ;
for (; V_532 <= V_533 ; V_532 ++ , V_536 <<= 1 )
if ( F_195 ( V_535 + V_532 , V_534 ) )
V_60 |= V_536 ;
return V_60 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_60 ,
int V_532 , int V_533 )
{
struct V_12 * V_12 ;
unsigned long * V_534 ;
unsigned long V_15 , V_535 ;
unsigned long V_536 = 1 ;
V_12 = F_17 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
V_534 = F_487 ( V_12 , V_15 ) ;
V_535 = F_489 ( V_12 , V_15 ) ;
F_42 ( ! F_12 ( V_12 , V_15 ) ) ;
for (; V_532 <= V_533 ; V_532 ++ , V_536 <<= 1 )
if ( V_60 & V_536 )
F_48 ( V_535 + V_532 , V_534 ) ;
else
F_50 ( V_535 + V_532 , V_534 ) ;
}
bool F_492 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_63 ,
bool V_537 )
{
unsigned long V_15 , V_538 , V_539 ;
int V_73 ;
if ( F_207 ( V_12 ) == V_394 )
return false ;
V_73 = F_100 ( V_5 ) ;
if ( V_73 == V_122 || F_84 ( V_73 ) )
return false ;
V_15 = F_10 ( V_5 ) ;
for ( V_539 = 0 , V_538 = 0 ; V_538 < V_81 ; V_538 ++ ) {
unsigned long V_540 = V_15 + V_538 ;
if ( ! F_16 ( V_540 ) )
continue;
V_5 = F_125 ( V_540 ) ;
if ( F_493 ( V_5 ) ) {
V_538 = F_480 ( V_538 + 1 , 1 << F_30 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_72 ( & V_5 -> V_59 ) ) {
if ( F_62 ( V_5 ) )
V_538 += ( 1 << F_60 ( V_5 ) ) - 1 ;
continue;
}
if ( V_537 && F_20 ( V_5 ) )
continue;
if ( ! F_494 ( V_5 ) )
V_539 ++ ;
if ( V_539 > V_63 )
return true ;
}
return false ;
}
bool F_495 ( struct V_5 * V_5 )
{
struct V_12 * V_12 ;
unsigned long V_15 ;
if ( ! F_331 ( F_121 ( V_5 ) ) )
return false ;
V_12 = F_17 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_12 , V_15 ) )
return false ;
return ! F_492 ( V_12 , V_5 , 0 , true ) ;
}
static unsigned long F_496 ( unsigned long V_15 )
{
return V_15 & ~ ( F_497 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_498 ( unsigned long V_15 )
{
return F_418 ( V_15 , F_497 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_499 ( struct V_541 * V_542 ,
unsigned long V_438 , unsigned long V_265 )
{
unsigned long V_543 ;
unsigned long V_15 = V_438 ;
unsigned int V_544 = 0 ;
int V_13 = 0 ;
F_500 () ;
while ( V_15 < V_265 || ! F_77 ( & V_542 -> V_545 ) ) {
if ( F_501 ( V_27 ) ) {
V_13 = - V_546 ;
break;
}
if ( F_77 ( & V_542 -> V_545 ) ) {
V_542 -> V_547 = 0 ;
V_15 = F_502 ( V_542 -> V_12 , V_542 ,
V_15 , V_265 , true ) ;
if ( ! V_15 ) {
V_13 = - V_546 ;
break;
}
V_544 = 0 ;
} else if ( ++ V_544 == 5 ) {
V_13 = V_13 < 0 ? V_13 : - V_548 ;
break;
}
V_543 = F_503 ( V_542 -> V_12 ,
& V_542 -> V_545 ) ;
V_542 -> V_547 -= V_543 ;
V_13 = F_504 ( & V_542 -> V_545 , V_549 ,
0 , V_550 , V_551 ) ;
}
if ( V_13 < 0 ) {
F_505 ( & V_542 -> V_545 ) ;
return V_13 ;
}
return 0 ;
}
int F_506 ( unsigned long V_438 , unsigned long V_265 ,
unsigned V_6 )
{
unsigned long V_552 , V_553 ;
int V_13 = 0 , V_31 ;
struct V_541 V_542 = {
. V_547 = 0 ,
. V_31 = - 1 ,
. V_12 = F_17 ( F_125 ( V_438 ) ) ,
. V_554 = true ,
. V_555 = true ,
} ;
F_113 ( & V_542 . V_545 ) ;
V_13 = F_507 ( F_496 ( V_438 ) ,
F_498 ( V_265 ) , V_6 ,
false ) ;
if ( V_13 )
return V_13 ;
V_13 = F_499 ( & V_542 , V_438 , V_265 ) ;
if ( V_13 )
goto V_556;
F_508 () ;
F_141 () ;
V_31 = 0 ;
V_552 = V_438 ;
while ( ! F_62 ( F_125 ( V_552 ) ) ) {
if ( ++ V_31 >= V_41 ) {
V_13 = - V_548 ;
goto V_556;
}
V_552 &= ~ 0UL << V_31 ;
}
if ( F_509 ( V_552 , V_265 , false ) ) {
F_217 ( L_96 ,
V_552 , V_265 ) ;
V_13 = - V_548 ;
goto V_556;
}
V_553 = F_510 ( & V_542 , V_552 , V_265 ) ;
if ( ! V_553 ) {
V_13 = - V_548 ;
goto V_556;
}
if ( V_438 != V_552 )
F_511 ( V_552 , V_438 - V_552 ) ;
if ( V_265 != V_553 )
F_511 ( V_265 , V_553 - V_265 ) ;
V_556:
F_512 ( F_496 ( V_438 ) ,
F_498 ( V_265 ) , V_6 ) ;
return V_13 ;
}
void F_511 ( unsigned long V_15 , unsigned V_33 )
{
unsigned int V_63 = 0 ;
for (; V_33 -- ; V_15 ++ ) {
struct V_5 * V_5 = F_125 ( V_15 ) ;
V_63 += F_61 ( V_5 ) != 1 ;
F_513 ( V_5 ) ;
}
F_514 ( V_63 != 0 , L_97 , V_63 ) ;
}
void T_14 F_515 ( struct V_12 * V_12 )
{
unsigned V_112 ;
F_312 ( & V_516 ) ;
F_333 (cpu)
F_373 ( V_12 ,
F_138 ( V_12 -> V_115 , V_112 ) ) ;
F_315 ( & V_516 ) ;
}
void F_516 ( struct V_12 * V_12 )
{
unsigned long V_60 ;
int V_112 ;
struct V_113 * V_114 ;
F_98 ( V_60 ) ;
if ( V_12 -> V_115 != & V_362 ) {
F_142 (cpu) {
V_114 = F_138 ( V_12 -> V_115 , V_112 ) ;
F_517 ( V_12 , V_114 ) ;
}
F_518 ( V_12 -> V_115 ) ;
V_12 -> V_115 = & V_362 ;
}
F_102 ( V_60 ) ;
}
void
F_519 ( unsigned long V_17 , unsigned long V_95 )
{
struct V_5 * V_5 ;
struct V_12 * V_12 ;
int V_31 , V_32 ;
unsigned long V_15 ;
unsigned long V_60 ;
for ( V_15 = V_17 ; V_15 < V_95 ; V_15 ++ )
if ( F_150 ( V_15 ) )
break;
if ( V_15 == V_95 )
return;
V_12 = F_17 ( F_125 ( V_15 ) ) ;
F_148 ( & V_12 -> V_68 , V_60 ) ;
V_15 = V_17 ;
while ( V_15 < V_95 ) {
if ( ! F_150 ( V_15 ) ) {
V_15 ++ ;
continue;
}
V_5 = F_125 ( V_15 ) ;
if ( F_7 ( ! F_62 ( V_5 ) && F_20 ( V_5 ) ) ) {
V_15 ++ ;
F_359 ( V_5 ) ;
continue;
}
F_120 ( F_61 ( V_5 ) ) ;
F_120 ( ! F_62 ( V_5 ) ) ;
V_31 = F_60 ( V_5 ) ;
#ifdef F_520
F_23 ( V_44 L_98 ,
V_15 , 1 << V_31 , V_95 ) ;
#endif
F_67 ( & V_5 -> V_52 ) ;
F_54 ( V_5 ) ;
V_12 -> V_53 [ V_31 ] . V_54 -- ;
for ( V_32 = 0 ; V_32 < ( 1 << V_31 ) ; V_32 ++ )
F_359 ( ( V_5 + V_32 ) ) ;
V_15 += ( 1 << V_31 ) ;
}
F_156 ( & V_12 -> V_68 , V_60 ) ;
}
bool F_521 ( struct V_5 * V_5 )
{
struct V_12 * V_12 = F_17 ( V_5 ) ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_60 ;
int V_31 ;
F_148 ( & V_12 -> V_68 , V_60 ) ;
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
struct V_5 * V_557 = V_5 - ( V_15 & ( ( 1 << V_31 ) - 1 ) ) ;
if ( F_62 ( V_557 ) && F_60 ( V_557 ) >= V_31 )
break;
}
F_156 ( & V_12 -> V_68 , V_60 ) ;
return V_31 < V_41 ;
}
static void F_522 ( unsigned long V_60 )
{
const char * V_558 = L_92 ;
unsigned long V_447 ;
int V_32 ;
F_210 ( F_523 ( V_559 ) != V_560 ) ;
F_23 ( V_25 L_99 , V_60 ) ;
V_60 &= ( 1UL << V_561 ) - 1 ;
for ( V_32 = 0 ; V_32 < F_523 ( V_559 ) && V_60 ; V_32 ++ ) {
V_447 = V_559 [ V_32 ] . V_447 ;
if ( ( V_60 & V_447 ) != V_447 )
continue;
V_60 &= ~ V_447 ;
F_23 ( L_100 , V_558 , V_559 [ V_32 ] . V_290 ) ;
V_558 = L_101 ;
}
if ( V_60 )
F_23 ( L_102 , V_558 , V_60 ) ;
F_23 ( L_103 ) ;
}
void F_24 ( struct V_5 * V_5 )
{
F_23 ( V_25
L_104 ,
V_5 , F_72 ( & V_5 -> V_59 ) , F_71 ( V_5 ) ,
V_5 -> V_58 , V_5 -> V_562 ) ;
F_522 ( V_5 -> V_60 ) ;
F_524 ( V_5 ) ;
}
