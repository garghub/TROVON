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
while ( V_66 ) {
struct V_5 * V_5 ;
struct V_69 * V_70 ;
do {
V_65 ++ ;
if ( ++ V_6 == V_71 )
V_6 = 0 ;
V_70 = & V_64 -> V_72 [ V_6 ] ;
} while ( F_77 ( V_70 ) );
if ( V_65 == V_71 )
V_65 = V_66 ;
do {
int V_73 ;
V_5 = F_78 ( V_70 -> V_74 , struct V_5 , V_51 ) ;
F_67 ( & V_5 -> V_51 ) ;
V_73 = F_79 ( V_5 ) ;
F_63 ( V_5 , V_11 , 0 , V_73 ) ;
F_80 ( V_5 , 0 , V_73 ) ;
if ( F_81 ( ! F_82 ( V_5 ) ) ) {
F_83 ( V_11 , V_75 , 1 ) ;
if ( F_84 ( V_73 ) )
F_83 ( V_11 , V_76 , 1 ) ;
}
} while ( -- V_66 && -- V_65 && ! F_77 ( V_70 ) );
}
F_85 ( & V_11 -> V_67 ) ;
}
static void F_86 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_30 ,
int V_6 )
{
F_76 ( & V_11 -> V_67 ) ;
V_11 -> V_68 = 0 ;
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
F_93 ( F_94 ( V_5 ) ,
V_77 << V_30 ) ;
F_95 ( F_94 ( V_5 ) ,
V_77 << V_30 ) ;
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
F_99 ( V_78 , 1 << V_30 ) ;
V_6 = F_100 ( V_5 ) ;
F_101 ( V_5 , V_6 ) ;
F_86 ( F_17 ( V_5 ) , V_5 , V_30 , V_6 ) ;
F_102 ( V_59 ) ;
}
void T_2 F_103 ( struct V_5 * V_5 , unsigned int V_30 )
{
unsigned int V_32 = 1 << V_30 ;
struct V_5 * V_33 = V_5 ;
unsigned int V_79 ;
F_104 ( V_33 ) ;
for ( V_79 = 0 ; V_79 < ( V_32 - 1 ) ; V_79 ++ , V_33 ++ ) {
F_104 ( V_33 + 1 ) ;
F_105 ( V_33 ) ;
F_36 ( V_33 , 0 ) ;
}
F_105 ( V_33 ) ;
F_36 ( V_33 , 0 ) ;
F_17 ( V_5 ) -> V_80 += V_32 ;
F_106 ( V_5 ) ;
F_107 ( V_5 , V_30 ) ;
}
void T_2 F_108 ( struct V_5 * V_5 )
{
unsigned V_31 = V_81 ;
struct V_5 * V_33 = V_5 ;
do {
F_105 ( V_33 ) ;
F_36 ( V_33 , 0 ) ;
} while ( ++ V_33 , -- V_31 );
F_106 ( V_5 ) ;
F_6 ( V_5 , V_82 ) ;
F_107 ( V_5 , V_83 ) ;
F_109 ( V_5 , V_81 ) ;
}
static inline void F_110 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_84 , int V_85 , struct V_52 * V_86 ,
int V_6 )
{
unsigned long V_87 = 1 << V_85 ;
while ( V_85 > V_84 ) {
V_86 -- ;
V_85 -- ;
V_87 >>= 1 ;
F_42 ( F_18 ( V_11 , & V_5 [ V_87 ] ) ) ;
#ifdef F_111
if ( V_85 < F_112 () ) {
F_113 ( & V_5 [ V_87 ] . V_51 ) ;
F_47 ( & V_5 [ V_87 ] ) ;
F_52 ( & V_5 [ V_87 ] , V_85 ) ;
F_66 ( V_11 , - ( 1 << V_85 ) ,
V_6 ) ;
continue;
}
#endif
F_69 ( & V_5 [ V_87 ] . V_51 , & V_86 -> V_56 [ V_6 ] ) ;
V_86 -> V_53 ++ ;
F_51 ( & V_5 [ V_87 ] , V_85 ) ;
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
if ( V_36 & V_88 )
F_41 ( V_5 , V_30 , V_36 ) ;
if ( V_30 && ( V_36 & V_89 ) )
F_31 ( V_5 , V_30 ) ;
return 0 ;
}
static inline
struct V_5 * F_117 ( struct V_11 * V_11 , unsigned int V_30 ,
int V_6 )
{
unsigned int V_90 ;
struct V_52 * V_86 ;
struct V_5 * V_5 ;
for ( V_90 = V_30 ; V_90 < V_40 ; ++ V_90 ) {
V_86 = & ( V_11 -> V_52 [ V_90 ] ) ;
if ( F_77 ( & V_86 -> V_56 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_86 -> V_56 [ V_6 ] . V_91 ,
struct V_5 , V_51 ) ;
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
V_86 -> V_53 -- ;
F_110 ( V_11 , V_5 , V_30 , V_90 , V_86 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_118 ( struct V_11 * V_11 ,
struct V_5 * V_92 , struct V_5 * V_93 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_30 ;
int V_94 = 0 ;
#ifndef F_119
F_120 ( F_17 ( V_92 ) != F_17 ( V_93 ) ) ;
#endif
for ( V_5 = V_92 ; V_5 <= V_93 ; ) {
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
V_94 += 1 << V_30 ;
}
return V_94 ;
}
int F_124 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_16 , V_95 ;
struct V_5 * V_92 , * V_93 ;
V_16 = F_10 ( V_5 ) ;
V_16 = V_16 & ~ ( V_81 - 1 ) ;
V_92 = F_125 ( V_16 ) ;
V_93 = V_92 + V_81 - 1 ;
V_95 = V_16 + V_81 - 1 ;
if ( ! F_12 ( V_11 , V_16 ) )
V_92 = V_5 ;
if ( ! F_12 ( V_11 , V_95 ) )
return 0 ;
return F_118 ( V_11 , V_92 , V_93 , V_6 ) ;
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
static int F_127 ( struct V_11 * V_11 , struct V_5 * V_5 ,
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
V_102 = F_124 ( V_11 , V_5 , V_99 ) ;
if ( V_102 >= ( 1 << ( V_83 - 1 ) ) ||
V_7 ) {
F_6 ( V_5 , V_99 ) ;
return V_99 ;
}
}
return V_100 ;
}
static inline struct V_5 *
F_128 ( struct V_11 * V_11 , int V_30 , int V_103 )
{
struct V_52 * V_86 ;
int V_90 ;
struct V_5 * V_5 ;
int V_6 , V_104 , V_31 ;
for ( V_90 = V_40 - 1 ; V_90 >= V_30 ;
-- V_90 ) {
for ( V_31 = 0 ; ; V_31 ++ ) {
V_6 = V_105 [ V_103 ] [ V_31 ] ;
if ( V_6 == V_106 )
break;
V_86 = & ( V_11 -> V_52 [ V_90 ] ) ;
if ( F_77 ( & V_86 -> V_56 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_86 -> V_56 [ V_6 ] . V_91 ,
struct V_5 , V_51 ) ;
V_86 -> V_53 -- ;
V_104 = F_127 ( V_11 , V_5 ,
V_103 ,
V_6 ) ;
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
F_110 ( V_11 , V_5 , V_30 , V_90 , V_86 ,
F_84 ( V_6 )
? V_6 : V_103 ) ;
F_129 ( V_5 , V_30 ,
V_90 , V_103 , V_6 ,
V_104 == V_103 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_130 ( struct V_11 * V_11 , unsigned int V_30 ,
int V_6 )
{
struct V_5 * V_5 ;
V_107:
V_5 = F_117 ( V_11 , V_30 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_106 ) {
V_5 = F_128 ( V_11 , V_30 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_106 ;
goto V_107;
}
}
F_131 ( V_5 , V_30 , V_6 ) ;
return V_5 ;
}
static int F_132 ( struct V_11 * V_11 , unsigned int V_30 ,
unsigned long V_62 , struct V_69 * V_70 ,
int V_6 , int V_108 )
{
int V_73 = V_6 , V_31 ;
F_76 ( & V_11 -> V_67 ) ;
for ( V_31 = 0 ; V_31 < V_62 ; ++ V_31 ) {
struct V_5 * V_5 = F_130 ( V_11 , V_30 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_81 ( V_108 == 0 ) )
F_69 ( & V_5 -> V_51 , V_70 ) ;
else
F_68 ( & V_5 -> V_51 , V_70 ) ;
if ( F_133 ( V_109 ) ) {
V_73 = F_100 ( V_5 ) ;
if ( ! F_84 ( V_73 ) && ! F_87 ( V_73 ) )
V_73 = V_6 ;
}
F_101 ( V_5 , V_73 ) ;
V_70 = & V_5 -> V_51 ;
if ( F_84 ( V_73 ) )
F_83 ( V_11 , V_76 ,
- ( 1 << V_30 ) ) ;
}
F_83 ( V_11 , V_75 , - ( V_31 << V_30 ) ) ;
F_85 ( & V_11 -> V_67 ) ;
return V_31 ;
}
void F_134 ( struct V_11 * V_11 , struct V_63 * V_64 )
{
unsigned long V_59 ;
int V_110 ;
unsigned long V_111 ;
F_98 ( V_59 ) ;
V_111 = F_135 ( V_64 -> V_111 ) ;
if ( V_64 -> V_62 >= V_111 )
V_110 = V_111 ;
else
V_110 = V_64 -> V_62 ;
if ( V_110 > 0 ) {
F_75 ( V_11 , V_110 , V_64 ) ;
V_64 -> V_62 -= V_110 ;
}
F_102 ( V_59 ) ;
}
static void F_136 ( unsigned int V_112 )
{
unsigned long V_59 ;
struct V_11 * V_11 ;
F_137 (zone) {
struct V_113 * V_114 ;
struct V_63 * V_64 ;
F_98 ( V_59 ) ;
V_114 = F_138 ( V_11 -> V_115 , V_112 ) ;
V_64 = & V_114 -> V_64 ;
if ( V_64 -> V_62 ) {
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
V_64 -> V_62 = 0 ;
}
F_102 ( V_59 ) ;
}
}
void F_139 ( void * V_116 )
{
F_136 ( F_140 () ) ;
}
void F_141 ( void )
{
int V_112 ;
struct V_113 * V_64 ;
struct V_11 * V_11 ;
static T_3 V_117 ;
F_142 (cpu) {
bool V_118 = false ;
F_137 (zone) {
V_64 = F_138 ( V_11 -> V_115 , V_112 ) ;
if ( V_64 -> V_64 . V_62 ) {
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
void F_146 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_119 ;
unsigned long V_59 ;
int V_30 , V_120 ;
struct V_69 * V_121 ;
if ( F_147 ( V_11 ) )
return;
F_148 ( & V_11 -> V_67 , V_59 ) ;
V_119 = F_149 ( V_11 ) ;
for ( V_14 = V_11 -> V_17 ; V_14 < V_119 ; V_14 ++ )
if ( F_150 ( V_14 ) ) {
struct V_5 * V_5 = F_125 ( V_14 ) ;
if ( ! F_151 ( V_5 ) )
F_152 ( V_5 ) ;
}
F_153 (order, t) {
F_154 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_31 ;
V_14 = F_10 ( F_78 ( V_121 , struct V_5 , V_51 ) ) ;
for ( V_31 = 0 ; V_31 < ( 1UL << V_30 ) ; V_31 ++ )
F_155 ( F_125 ( V_14 + V_31 ) ) ;
}
}
F_156 ( & V_11 -> V_67 , V_59 ) ;
}
void F_157 ( struct V_5 * V_5 , int V_108 )
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
F_158 ( V_78 ) ;
if ( V_6 >= V_71 ) {
if ( F_7 ( F_87 ( V_6 ) ) ) {
F_86 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_23;
}
V_6 = V_122 ;
}
V_64 = & F_159 ( V_11 -> V_115 ) -> V_64 ;
if ( V_108 )
F_68 ( & V_5 -> V_51 , & V_64 -> V_72 [ V_6 ] ) ;
else
F_69 ( & V_5 -> V_51 , & V_64 -> V_72 [ V_6 ] ) ;
V_64 -> V_62 ++ ;
if ( V_64 -> V_62 >= V_64 -> V_85 ) {
unsigned long V_111 = F_135 ( V_64 -> V_111 ) ;
F_75 ( V_11 , V_111 , V_64 ) ;
V_64 -> V_62 -= V_111 ;
}
V_23:
F_102 ( V_59 ) ;
}
void F_160 ( struct V_69 * V_70 , int V_108 )
{
struct V_5 * V_5 , * V_91 ;
F_161 (page, next, list, lru) {
F_162 ( V_5 , V_108 ) ;
F_157 ( V_5 , V_108 ) ;
}
}
void F_163 ( struct V_5 * V_5 , unsigned int V_30 )
{
int V_31 ;
F_42 ( F_65 ( V_5 ) ) ;
F_42 ( ! F_61 ( V_5 ) ) ;
#ifdef F_164
if ( F_165 ( V_5 ) )
F_163 ( F_166 ( V_5 [ 0 ] . V_123 ) , V_30 ) ;
#endif
for ( V_31 = 1 ; V_31 < ( 1 << V_30 ) ; V_31 ++ )
F_106 ( V_5 + V_31 ) ;
}
static int F_167 ( struct V_5 * V_5 , unsigned int V_30 )
{
unsigned long V_124 ;
struct V_11 * V_11 ;
int V_73 ;
F_120 ( ! F_62 ( V_5 ) ) ;
V_11 = F_17 ( V_5 ) ;
V_73 = F_100 ( V_5 ) ;
if ( ! F_87 ( V_73 ) ) {
V_124 = F_168 ( V_11 ) + ( 1 << V_30 ) ;
if ( ! F_169 ( V_11 , 0 , V_124 , 0 , 0 ) )
return 0 ;
F_66 ( V_11 , - ( 1UL << V_30 ) , V_73 ) ;
}
F_67 ( & V_5 -> V_51 ) ;
V_11 -> V_52 [ V_30 ] . V_53 -- ;
F_54 ( V_5 ) ;
if ( V_30 >= V_83 - 1 ) {
struct V_5 * V_125 = V_5 + ( 1 << V_30 ) - 1 ;
for (; V_5 < V_125 ; V_5 += V_81 ) {
int V_73 = F_100 ( V_5 ) ;
if ( ! F_87 ( V_73 ) && ! F_84 ( V_73 ) )
F_6 ( V_5 ,
V_122 ) ;
}
}
return 1UL << V_30 ;
}
int F_170 ( struct V_5 * V_5 )
{
unsigned int V_30 ;
int V_32 ;
V_30 = F_60 ( V_5 ) ;
V_32 = F_167 ( V_5 , V_30 ) ;
if ( ! V_32 )
return 0 ;
F_106 ( V_5 ) ;
F_163 ( V_5 , V_30 ) ;
return V_32 ;
}
static inline
struct V_5 * F_171 ( struct V_11 * V_126 ,
struct V_11 * V_11 , int V_30 , T_1 V_36 ,
int V_6 )
{
unsigned long V_59 ;
struct V_5 * V_5 ;
int V_108 = ! ! ( V_36 & V_127 ) ;
V_128:
if ( F_81 ( V_30 == 0 ) ) {
struct V_63 * V_64 ;
struct V_69 * V_70 ;
F_98 ( V_59 ) ;
V_64 = & F_159 ( V_11 -> V_115 ) -> V_64 ;
V_70 = & V_64 -> V_72 [ V_6 ] ;
if ( F_77 ( V_70 ) ) {
V_64 -> V_62 += F_132 ( V_11 , 0 ,
V_64 -> V_111 , V_70 ,
V_6 , V_108 ) ;
if ( F_7 ( F_77 ( V_70 ) ) )
goto V_129;
}
if ( V_108 )
V_5 = F_78 ( V_70 -> V_74 , struct V_5 , V_51 ) ;
else
V_5 = F_78 ( V_70 -> V_91 , struct V_5 , V_51 ) ;
F_67 ( & V_5 -> V_51 ) ;
V_64 -> V_62 -- ;
} else {
if ( F_7 ( V_36 & V_130 ) ) {
F_172 ( V_30 > 1 ) ;
}
F_148 ( & V_11 -> V_67 , V_59 ) ;
V_5 = F_130 ( V_11 , V_30 , V_6 ) ;
F_85 ( & V_11 -> V_67 ) ;
if ( ! V_5 )
goto V_129;
F_66 ( V_11 , - ( 1 << V_30 ) ,
F_100 ( V_5 ) ) ;
}
F_83 ( V_11 , V_131 , - ( 1 << V_30 ) ) ;
F_173 ( V_132 , V_11 , 1 << V_30 ) ;
F_174 ( V_126 , V_11 , V_36 ) ;
F_102 ( V_59 ) ;
F_42 ( F_18 ( V_11 , V_5 ) ) ;
if ( F_115 ( V_5 , V_30 , V_36 ) )
goto V_128;
return V_5 ;
V_129:
F_102 ( V_59 ) ;
return NULL ;
}
static int T_2 F_175 ( char * V_133 )
{
return F_176 ( & V_134 . V_135 , V_133 ) ;
}
static bool F_177 ( T_1 V_136 , unsigned int V_30 )
{
if ( V_30 < V_134 . V_137 )
return false ;
if ( V_136 & V_130 )
return false ;
if ( V_134 . V_138 && ( V_136 & V_37 ) )
return false ;
if ( V_134 . V_139 && ( V_136 & V_140 ) )
return false ;
return F_178 ( & V_134 . V_135 , 1 << V_30 ) ;
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
static inline bool F_177 ( T_1 V_136 , unsigned int V_30 )
{
return false ;
}
static bool F_186 ( struct V_11 * V_149 , int V_30 , unsigned long V_150 ,
int V_151 , int V_152 , long V_153 )
{
long V_154 = V_150 ;
long V_155 = V_149 -> V_155 [ V_151 ] ;
int V_156 ;
long V_157 = 0 ;
V_153 -= ( 1 << V_30 ) - 1 ;
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
for ( V_156 = 0 ; V_156 < V_30 ; V_156 ++ ) {
V_153 -= V_149 -> V_52 [ V_156 ] . V_53 << V_156 ;
V_154 >>= 1 ;
if ( V_153 <= V_154 )
return false ;
}
return true ;
}
bool F_169 ( struct V_11 * V_149 , int V_30 , unsigned long V_150 ,
int V_151 , int V_152 )
{
return F_186 ( V_149 , V_30 , V_150 , V_151 , V_152 ,
F_187 ( V_149 , V_75 ) ) ;
}
bool F_188 ( struct V_11 * V_149 , int V_30 , unsigned long V_150 ,
int V_151 , int V_152 )
{
long V_153 = F_187 ( V_149 , V_75 ) ;
if ( V_149 -> V_161 && V_153 < V_149 -> V_161 )
V_153 = F_189 ( V_149 , V_75 ) ;
return F_186 ( V_149 , V_30 , V_150 , V_151 , V_152 ,
V_153 ) ;
}
static T_5 * F_190 ( struct V_162 * V_162 , int V_152 )
{
struct V_163 * V_164 ;
T_5 * V_165 ;
V_164 = V_162 -> V_166 ;
if ( ! V_164 )
return NULL ;
if ( F_191 ( V_22 , V_164 -> V_167 + V_25 ) ) {
F_192 ( V_164 -> V_168 , V_169 ) ;
V_164 -> V_167 = V_22 ;
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
int V_31 ;
int V_175 ;
V_164 = V_162 -> V_166 ;
if ( ! V_164 )
return 1 ;
V_31 = V_149 - V_162 -> V_176 ;
V_175 = V_164 -> V_177 [ V_31 ] ;
return F_194 ( V_175 , * V_165 ) && ! F_195 ( V_31 , V_164 -> V_168 ) ;
}
static void F_196 ( struct V_162 * V_162 , struct V_174 * V_149 )
{
struct V_163 * V_164 ;
int V_31 ;
V_164 = V_162 -> V_166 ;
if ( ! V_164 )
return;
V_31 = V_149 - V_162 -> V_176 ;
F_197 ( V_31 , V_164 -> V_168 ) ;
}
static void F_198 ( struct V_162 * V_162 )
{
struct V_163 * V_164 ;
V_164 = V_162 -> V_166 ;
if ( ! V_164 )
return;
F_192 ( V_164 -> V_168 , V_169 ) ;
}
static bool F_199 ( struct V_11 * V_178 , struct V_11 * V_11 )
{
return F_200 ( V_178 -> V_179 , V_11 -> V_179 ) == V_180 ;
}
static bool F_201 ( struct V_11 * V_178 , struct V_11 * V_11 )
{
return F_194 ( V_178 -> V_179 , V_11 -> V_181 -> V_182 ) ;
}
static void T_6 F_202 ( int V_183 )
{
int V_31 ;
F_203 (i)
if ( F_200 ( V_183 , V_31 ) <= V_184 )
F_204 ( V_31 , F_205 ( V_183 ) -> V_182 ) ;
else
V_185 = 1 ;
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
static bool F_199 ( struct V_11 * V_178 , struct V_11 * V_11 )
{
return true ;
}
static bool F_201 ( struct V_11 * V_178 , struct V_11 * V_11 )
{
return true ;
}
static inline void F_202 ( int V_183 )
{
}
static struct V_5 *
F_206 ( T_1 V_136 , T_5 * V_186 , unsigned int V_30 ,
struct V_162 * V_162 , int V_187 , int V_152 ,
struct V_11 * V_126 , int V_6 )
{
struct V_174 * V_149 ;
struct V_5 * V_5 = NULL ;
int V_151 ;
struct V_11 * V_11 ;
T_5 * V_165 = NULL ;
int V_188 = 0 ;
int V_189 = 0 ;
V_151 = F_207 ( V_126 ) ;
V_190:
F_208 (zone, z, zonelist,
high_zoneidx, nodemask) {
unsigned long V_150 ;
if ( F_133 ( V_191 ) && V_188 &&
! F_193 ( V_162 , V_149 , V_165 ) )
continue;
if ( ( V_152 & V_170 ) &&
! F_209 ( V_11 , V_136 ) )
continue;
F_210 ( V_192 < V_193 ) ;
if ( F_7 ( V_152 & V_192 ) )
goto V_194;
if ( V_152 & V_195 ) {
if ( F_187 ( V_11 , V_131 ) <= 0 )
continue;
if ( V_185 &&
! F_199 ( V_126 , V_11 ) )
continue;
}
if ( ( V_152 & V_195 ) &&
( V_136 & V_196 ) && ! F_211 ( V_11 ) )
goto V_197;
V_150 = V_11 -> V_124 [ V_152 & V_198 ] ;
if ( ! F_169 ( V_11 , V_30 , V_150 ,
V_151 , V_152 ) ) {
int V_12 ;
if ( F_133 ( V_191 ) &&
! V_189 && V_199 > 1 ) {
V_165 = F_190 ( V_162 , V_152 ) ;
V_188 = 1 ;
V_189 = 1 ;
}
if ( V_185 == 0 ||
! F_201 ( V_126 , V_11 ) )
goto V_197;
if ( F_133 ( V_191 ) && V_188 &&
! F_193 ( V_162 , V_149 , V_165 ) )
continue;
V_12 = F_212 ( V_11 , V_136 , V_30 ) ;
switch ( V_12 ) {
case V_200 :
continue;
case V_201 :
continue;
default:
if ( F_169 ( V_11 , V_30 , V_150 ,
V_151 , V_152 ) )
goto V_194;
if ( ( ( V_152 & V_198 ) == V_202 ) ||
V_12 == V_203 )
goto V_197;
continue;
}
}
V_194:
V_5 = F_171 ( V_126 , V_11 , V_30 ,
V_136 , V_6 ) ;
if ( V_5 )
break;
V_197:
if ( F_133 ( V_191 ) )
F_196 ( V_162 , V_149 ) ;
}
if ( F_7 ( F_133 ( V_191 ) && V_5 == NULL && V_188 ) ) {
V_188 = 0 ;
goto V_190;
}
if ( V_5 )
V_5 -> V_204 = ! ! ( V_152 & V_192 ) ;
return V_5 ;
}
static inline bool F_213 ( void )
{
bool V_12 = false ;
#if V_205 > 8
V_12 = F_43 () ;
#endif
return V_12 ;
}
void F_214 ( T_1 V_136 , int V_30 , const char * V_206 , ... )
{
unsigned int V_207 = V_208 ;
if ( ( V_136 & V_209 ) || ! F_215 ( & V_210 ) ||
F_112 () > 0 )
return;
if ( ! ( V_136 & V_140 ) )
V_207 |= V_211 ;
if ( ! ( V_136 & V_212 ) )
if ( F_216 ( V_213 ) ||
( V_26 -> V_59 & ( V_214 | V_215 ) ) )
V_207 &= ~ V_208 ;
if ( F_43 () || ! ( V_136 & V_140 ) )
V_207 &= ~ V_208 ;
if ( V_206 ) {
struct V_216 V_217 ;
T_7 args ;
va_start ( args , V_206 ) ;
V_217 . V_206 = V_206 ;
V_217 . V_218 = & args ;
F_217 ( L_10 , & V_217 ) ;
va_end ( args ) ;
}
F_217 ( L_11 ,
V_26 -> V_27 , V_30 , V_136 ) ;
F_26 () ;
if ( ! F_213 () )
F_218 ( V_207 ) ;
}
static inline int
F_219 ( T_1 V_136 , unsigned int V_30 ,
unsigned long V_219 ,
unsigned long V_220 )
{
if ( V_136 & V_221 )
return 0 ;
if ( V_136 & V_130 )
return 1 ;
if ( ! V_219 && F_5 () )
return 0 ;
if ( V_30 <= V_222 )
return 1 ;
if ( V_136 & V_223 && V_220 < ( 1 << V_30 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_220 ( T_1 V_136 , unsigned int V_30 ,
struct V_162 * V_162 , enum V_224 V_187 ,
T_5 * V_186 , struct V_11 * V_126 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_221 ( V_162 , V_136 ) ) {
F_222 ( 1 ) ;
return NULL ;
}
V_5 = F_206 ( V_136 | V_225 , V_186 ,
V_30 , V_162 , V_187 ,
V_226 | V_170 ,
V_126 , V_6 ) ;
if ( V_5 )
goto V_23;
if ( ! ( V_136 & V_130 ) ) {
if ( V_30 > V_222 )
goto V_23;
if ( V_187 < V_227 )
goto V_23;
if ( V_136 & V_228 )
goto V_23;
}
F_223 ( V_162 , V_136 , V_30 , V_186 , false ) ;
V_23:
F_224 ( V_162 , V_136 ) ;
return V_5 ;
}
static struct V_5 *
F_225 ( T_1 V_136 , unsigned int V_30 ,
struct V_162 * V_162 , enum V_224 V_187 ,
T_5 * V_186 , int V_152 , struct V_11 * V_126 ,
int V_6 , bool V_229 ,
bool * V_230 , bool * V_231 ,
unsigned long * V_219 )
{
if ( ! V_30 )
return NULL ;
if ( F_226 ( V_126 , V_30 ) ) {
* V_231 = true ;
return NULL ;
}
V_26 -> V_59 |= V_214 ;
* V_219 = F_227 ( V_162 , V_30 , V_136 ,
V_186 , V_229 ,
V_230 ) ;
V_26 -> V_59 &= ~ V_214 ;
if ( * V_219 != V_232 ) {
struct V_5 * V_5 ;
F_136 ( F_228 () ) ;
F_229 () ;
V_5 = F_206 ( V_136 , V_186 ,
V_30 , V_162 , V_187 ,
V_152 & ~ V_192 ,
V_126 , V_6 ) ;
if ( V_5 ) {
V_126 -> V_233 = false ;
V_126 -> V_234 = 0 ;
V_126 -> V_235 = 0 ;
if ( V_30 >= V_126 -> V_236 )
V_126 -> V_236 = V_30 + 1 ;
F_230 ( V_237 ) ;
return V_5 ;
}
F_230 ( V_238 ) ;
if ( V_229 )
F_231 ( V_126 , V_30 ) ;
F_232 () ;
}
return NULL ;
}
static inline struct V_5 *
F_225 ( T_1 V_136 , unsigned int V_30 ,
struct V_162 * V_162 , enum V_224 V_187 ,
T_5 * V_186 , int V_152 , struct V_11 * V_126 ,
int V_6 , bool V_229 ,
bool * V_230 , bool * V_231 ,
unsigned long * V_219 )
{
return NULL ;
}
static int
F_233 ( T_1 V_136 , unsigned int V_30 , struct V_162 * V_162 ,
T_5 * V_186 )
{
struct V_239 V_239 ;
int V_240 ;
F_232 () ;
F_234 () ;
V_26 -> V_59 |= V_214 ;
F_235 ( V_136 ) ;
V_239 . V_241 = 0 ;
V_26 -> V_239 = & V_239 ;
V_240 = F_236 ( V_162 , V_30 , V_136 , V_186 ) ;
V_26 -> V_239 = NULL ;
F_237 () ;
V_26 -> V_59 &= ~ V_214 ;
F_232 () ;
return V_240 ;
}
static inline struct V_5 *
F_238 ( T_1 V_136 , unsigned int V_30 ,
struct V_162 * V_162 , enum V_224 V_187 ,
T_5 * V_186 , int V_152 , struct V_11 * V_126 ,
int V_6 , unsigned long * V_219 )
{
struct V_5 * V_5 = NULL ;
bool V_242 = false ;
* V_219 = F_233 ( V_136 , V_30 , V_162 ,
V_186 ) ;
if ( F_7 ( ! ( * V_219 ) ) )
return NULL ;
if ( F_133 ( V_191 ) )
F_198 ( V_162 ) ;
V_243:
V_5 = F_206 ( V_136 , V_186 , V_30 ,
V_162 , V_187 ,
V_152 & ~ V_192 ,
V_126 , V_6 ) ;
if ( ! V_5 && ! V_242 ) {
F_141 () ;
V_242 = true ;
goto V_243;
}
return V_5 ;
}
static inline struct V_5 *
F_239 ( T_1 V_136 , unsigned int V_30 ,
struct V_162 * V_162 , enum V_224 V_187 ,
T_5 * V_186 , struct V_11 * V_126 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_206 ( V_136 , V_186 , V_30 ,
V_162 , V_187 , V_192 ,
V_126 , V_6 ) ;
if ( ! V_5 && V_136 & V_130 )
F_240 ( V_126 , V_244 , V_25 / 50 ) ;
} while ( ! V_5 && ( V_136 & V_130 ) );
return V_5 ;
}
static void F_241 ( T_1 V_136 , unsigned int V_30 ,
struct V_162 * V_162 ,
enum V_224 V_187 ,
struct V_11 * V_126 )
{
struct V_174 * V_149 ;
struct V_11 * V_11 ;
F_242 (zone, z, zonelist, high_zoneidx) {
if ( ! ( V_136 & V_245 ) )
F_243 ( V_11 , V_30 , F_207 ( V_126 ) ) ;
if ( V_185 && ! F_199 ( V_126 , V_11 ) )
continue;
F_244 ( V_11 , V_131 ,
F_245 ( V_11 ) -
F_168 ( V_11 ) -
F_187 ( V_11 , V_131 ) ) ;
}
}
static inline int
F_246 ( T_1 V_136 )
{
int V_152 = V_202 | V_170 ;
const T_1 V_246 = V_136 & V_140 ;
F_210 ( V_247 != ( V_248 T_1 ) V_158 ) ;
V_152 |= ( V_248 int ) ( V_136 & V_247 ) ;
if ( ! V_246 ) {
if ( ! ( V_136 & V_212 ) )
V_152 |= V_159 ;
V_152 &= ~ V_170 ;
} else if ( F_7 ( F_247 ( V_26 ) ) && ! F_43 () )
V_152 |= V_159 ;
if ( F_81 ( ! ( V_136 & V_212 ) ) ) {
if ( V_136 & V_249 )
V_152 |= V_192 ;
else if ( F_248 () && ( V_26 -> V_59 & V_214 ) )
V_152 |= V_192 ;
else if ( ! F_43 () &&
( ( V_26 -> V_59 & V_214 ) ||
F_7 ( F_216 ( V_213 ) ) ) )
V_152 |= V_192 ;
}
#ifdef V_109
if ( F_249 ( V_136 ) == V_122 )
V_152 |= V_160 ;
#endif
return V_152 ;
}
bool F_250 ( T_1 V_136 )
{
return ! ! ( F_246 ( V_136 ) & V_192 ) ;
}
static inline struct V_5 *
F_251 ( T_1 V_136 , unsigned int V_30 ,
struct V_162 * V_162 , enum V_224 V_187 ,
T_5 * V_186 , struct V_11 * V_126 ,
int V_6 )
{
const T_1 V_246 = V_136 & V_140 ;
struct V_5 * V_5 = NULL ;
int V_152 ;
unsigned long V_220 = 0 ;
unsigned long V_219 ;
bool V_229 = false ;
bool V_231 = false ;
bool V_230 = false ;
if ( V_30 >= V_40 ) {
F_172 ( ! ( V_136 & V_209 ) ) ;
return NULL ;
}
if ( F_133 ( V_191 ) &&
( V_136 & V_250 ) == V_250 )
goto V_251;
V_252:
F_241 ( V_136 , V_30 , V_162 ,
V_187 , V_126 ) ;
V_152 = F_246 ( V_136 ) ;
if ( ! ( V_152 & V_170 ) && ! V_186 )
F_252 ( V_162 , V_187 , NULL ,
& V_126 ) ;
V_253:
V_5 = F_206 ( V_136 , V_186 , V_30 , V_162 ,
V_187 , V_152 & ~ V_192 ,
V_126 , V_6 ) ;
if ( V_5 )
goto V_254;
if ( V_152 & V_192 ) {
V_162 = F_253 ( F_254 () , V_136 ) ;
V_5 = F_239 ( V_136 , V_30 ,
V_162 , V_187 , V_186 ,
V_126 , V_6 ) ;
if ( V_5 ) {
goto V_254;
}
}
if ( ! V_246 )
goto V_251;
if ( V_26 -> V_59 & V_214 )
goto V_251;
if ( F_216 ( V_213 ) && ! ( V_136 & V_130 ) )
goto V_251;
V_5 = F_225 ( V_136 , V_30 ,
V_162 , V_187 ,
V_186 ,
V_152 , V_126 ,
V_6 , V_229 ,
& V_230 ,
& V_231 ,
& V_219 ) ;
if ( V_5 )
goto V_254;
V_229 = true ;
if ( ( V_231 || V_230 ) &&
( V_136 & V_245 ) )
goto V_251;
V_5 = F_238 ( V_136 , V_30 ,
V_162 , V_187 ,
V_186 ,
V_152 , V_126 ,
V_6 , & V_219 ) ;
if ( V_5 )
goto V_254;
if ( ! V_219 ) {
if ( ( V_136 & V_255 ) && ! ( V_136 & V_221 ) ) {
if ( V_256 )
goto V_251;
if ( ( V_26 -> V_59 & V_257 ) &&
! ( V_136 & V_130 ) )
goto V_251;
V_5 = F_220 ( V_136 , V_30 ,
V_162 , V_187 ,
V_186 , V_126 ,
V_6 ) ;
if ( V_5 )
goto V_254;
if ( ! ( V_136 & V_130 ) ) {
if ( V_30 > V_222 )
goto V_251;
if ( V_187 < V_227 )
goto V_251;
}
goto V_252;
}
}
V_220 += V_219 ;
if ( F_219 ( V_136 , V_30 , V_219 ,
V_220 ) ) {
F_240 ( V_126 , V_244 , V_25 / 50 ) ;
goto V_253;
} else {
V_5 = F_225 ( V_136 , V_30 ,
V_162 , V_187 ,
V_186 ,
V_152 , V_126 ,
V_6 , V_229 ,
& V_230 ,
& V_231 ,
& V_219 ) ;
if ( V_5 )
goto V_254;
}
V_251:
F_214 ( V_136 , V_30 , NULL ) ;
return V_5 ;
V_254:
if ( V_258 )
F_255 ( V_5 , V_30 , V_136 ) ;
return V_5 ;
}
struct V_5 *
F_256 ( T_1 V_136 , unsigned int V_30 ,
struct V_162 * V_162 , T_5 * V_186 )
{
enum V_224 V_187 = F_257 ( V_136 ) ;
struct V_11 * V_126 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_249 ( V_136 ) ;
unsigned int V_259 ;
int V_152 = V_195 | V_170 ;
struct V_260 * V_261 = NULL ;
V_136 &= V_3 ;
F_258 ( V_136 ) ;
F_259 ( V_136 & V_140 ) ;
if ( F_177 ( V_136 , V_30 ) )
return NULL ;
if ( F_7 ( ! V_162 -> V_176 -> V_11 ) )
return NULL ;
if ( ! F_260 ( V_136 , & V_261 , V_30 ) )
return NULL ;
V_262:
V_259 = F_261 () ;
F_252 ( V_162 , V_187 ,
V_186 ? : & V_171 ,
& V_126 ) ;
if ( ! V_126 )
goto V_23;
#ifdef V_109
if ( F_249 ( V_136 ) == V_122 )
V_152 |= V_160 ;
#endif
V_5 = F_206 ( V_136 | V_225 , V_186 , V_30 ,
V_162 , V_187 , V_152 ,
V_126 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
V_136 = F_262 ( V_136 ) ;
V_5 = F_251 ( V_136 , V_30 ,
V_162 , V_187 , V_186 ,
V_126 , V_6 ) ;
}
F_263 ( V_5 , V_30 , V_136 , V_6 ) ;
V_23:
if ( F_7 ( ! F_264 ( V_259 ) && ! V_5 ) )
goto V_262;
F_265 ( V_5 , V_261 , V_30 ) ;
return V_5 ;
}
unsigned long F_266 ( T_1 V_136 , unsigned int V_30 )
{
struct V_5 * V_5 ;
F_42 ( ( V_136 & V_37 ) != 0 ) ;
V_5 = F_267 ( V_136 , V_30 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_94 ( V_5 ) ;
}
unsigned long F_268 ( T_1 V_136 )
{
return F_266 ( V_136 | V_88 , 0 ) ;
}
void F_107 ( struct V_5 * V_5 , unsigned int V_30 )
{
if ( F_269 ( V_5 ) ) {
if ( V_30 == 0 )
F_157 ( V_5 , 0 ) ;
else
F_29 ( V_5 , V_30 ) ;
}
}
void V_153 ( unsigned long V_263 , unsigned int V_30 )
{
if ( V_263 != 0 ) {
F_42 ( ! F_270 ( ( void * ) V_263 ) ) ;
F_107 ( F_166 ( ( void * ) V_263 ) , V_30 ) ;
}
}
void F_271 ( struct V_5 * V_5 , unsigned int V_30 )
{
F_272 ( V_5 , V_30 ) ;
F_107 ( V_5 , V_30 ) ;
}
void F_273 ( unsigned long V_263 , unsigned int V_30 )
{
if ( V_263 != 0 ) {
F_42 ( ! F_270 ( ( void * ) V_263 ) ) ;
F_271 ( F_166 ( ( void * ) V_263 ) , V_30 ) ;
}
}
static void * F_274 ( unsigned long V_263 , unsigned V_30 , T_8 V_87 )
{
if ( V_263 ) {
unsigned long V_264 = V_263 + ( V_77 << V_30 ) ;
unsigned long V_265 = V_263 + F_275 ( V_87 ) ;
F_163 ( F_166 ( ( void * ) V_263 ) , V_30 ) ;
while ( V_265 < V_264 ) {
F_276 ( V_265 ) ;
V_265 += V_77 ;
}
}
return ( void * ) V_263 ;
}
void * F_277 ( T_8 V_87 , T_1 V_136 )
{
unsigned int V_30 = F_278 ( V_87 ) ;
unsigned long V_263 ;
V_263 = F_266 ( V_136 , V_30 ) ;
return F_274 ( V_263 , V_30 , V_87 ) ;
}
void * F_279 ( int V_183 , T_8 V_87 , T_1 V_136 )
{
unsigned V_30 = F_278 ( V_87 ) ;
struct V_5 * V_33 = F_280 ( V_183 , V_136 , V_30 ) ;
if ( ! V_33 )
return NULL ;
return F_274 ( ( unsigned long ) F_94 ( V_33 ) , V_30 , V_87 ) ;
}
void F_281 ( void * V_266 , T_8 V_87 )
{
unsigned long V_263 = ( unsigned long ) V_266 ;
unsigned long V_267 = V_263 + F_275 ( V_87 ) ;
while ( V_263 < V_267 ) {
F_276 ( V_263 ) ;
V_263 += V_77 ;
}
}
static unsigned long F_282 ( int V_268 )
{
struct V_174 * V_149 ;
struct V_11 * V_11 ;
unsigned long V_269 = 0 ;
struct V_162 * V_162 = F_253 ( F_254 () , V_270 ) ;
F_242 (zone, z, zonelist, offset) {
unsigned long V_87 = V_11 -> V_80 ;
unsigned long V_85 = F_245 ( V_11 ) ;
if ( V_87 > V_85 )
V_269 += V_87 - V_85 ;
}
return V_269 ;
}
unsigned long F_283 ( void )
{
return F_282 ( F_257 ( V_271 ) ) ;
}
unsigned long F_284 ( void )
{
return F_282 ( F_257 ( V_272 ) ) ;
}
static inline void F_285 ( struct V_11 * V_11 )
{
if ( F_133 ( V_191 ) )
F_23 ( L_12 , F_122 ( V_11 ) ) ;
}
void F_286 ( struct V_273 * V_274 )
{
V_274 -> V_275 = V_276 ;
V_274 -> V_277 = 0 ;
V_274 -> V_278 = F_287 ( V_75 ) ;
V_274 -> V_279 = F_288 () ;
V_274 -> V_280 = V_281 ;
V_274 -> V_282 = F_289 () ;
V_274 -> V_283 = V_77 ;
}
void F_290 ( struct V_273 * V_274 , int V_183 )
{
int V_224 ;
unsigned long V_80 = 0 ;
T_9 * V_284 = F_205 ( V_183 ) ;
for ( V_224 = 0 ; V_224 < V_285 ; V_224 ++ )
V_80 += V_284 -> V_286 [ V_224 ] . V_80 ;
V_274 -> V_275 = V_80 ;
V_274 -> V_278 = F_291 ( V_183 , V_75 ) ;
#ifdef F_292
V_274 -> V_280 = V_284 -> V_286 [ V_287 ] . V_80 ;
V_274 -> V_282 = F_187 ( & V_284 -> V_286 [ V_287 ] ,
V_75 ) ;
#else
V_274 -> V_280 = 0 ;
V_274 -> V_282 = 0 ;
#endif
V_274 -> V_283 = V_77 ;
}
bool F_293 ( unsigned int V_59 , int V_183 )
{
bool V_12 = false ;
unsigned int V_259 ;
if ( ! ( V_59 & V_208 ) )
goto V_23;
do {
V_259 = F_261 () ;
V_12 = ! F_194 ( V_183 , V_171 ) ;
} while ( ! F_264 ( V_259 ) );
V_23:
return V_12 ;
}
static void F_294 ( unsigned char type )
{
static const char V_288 [ V_289 ] = {
[ V_8 ] = 'U' ,
[ V_101 ] = 'E' ,
[ V_122 ] = 'M' ,
[ V_106 ] = 'R' ,
#ifdef V_109
[ V_82 ] = 'C' ,
#endif
#ifdef F_295
[ V_290 ] = 'I' ,
#endif
} ;
char V_291 [ V_289 + 1 ] ;
char * V_33 = V_291 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_289 ; V_31 ++ ) {
if ( type & ( 1 << V_31 ) )
* V_33 ++ = V_288 [ V_31 ] ;
}
* V_33 = '\0' ;
F_23 ( L_13 , V_291 ) ;
}
void F_296 ( unsigned int V_207 )
{
int V_112 ;
struct V_11 * V_11 ;
F_137 (zone) {
if ( F_293 ( V_207 , F_122 ( V_11 ) ) )
continue;
F_285 ( V_11 ) ;
F_23 ( L_14 , V_11 -> V_292 ) ;
F_142 (cpu) {
struct V_113 * V_115 ;
V_115 = F_138 ( V_11 -> V_115 , V_112 ) ;
F_23 ( L_15 ,
V_112 , V_115 -> V_64 . V_85 ,
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
F_287 ( V_293 ) ,
F_287 ( V_294 ) ,
F_287 ( V_295 ) ,
F_287 ( V_296 ) ,
F_287 ( V_297 ) ,
F_287 ( V_298 ) ,
F_287 ( V_299 ) ,
F_287 ( V_300 ) ,
F_287 ( V_301 ) ,
F_287 ( V_302 ) ,
F_287 ( V_75 ) ,
F_287 ( V_303 ) ,
F_287 ( V_304 ) ,
F_287 ( V_305 ) ,
F_287 ( V_306 ) ,
F_287 ( V_307 ) ,
F_287 ( V_308 ) ,
F_287 ( V_76 ) ) ;
F_137 (zone) {
int V_31 ;
if ( F_293 ( V_207 , F_122 ( V_11 ) ) )
continue;
F_285 ( V_11 ) ;
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
V_11 -> V_292 ,
F_297 ( F_187 ( V_11 , V_75 ) ) ,
F_297 ( F_298 ( V_11 ) ) ,
F_297 ( F_168 ( V_11 ) ) ,
F_297 ( F_245 ( V_11 ) ) ,
F_297 ( F_187 ( V_11 , V_293 ) ) ,
F_297 ( F_187 ( V_11 , V_294 ) ) ,
F_297 ( F_187 ( V_11 , V_296 ) ) ,
F_297 ( F_187 ( V_11 , V_297 ) ) ,
F_297 ( F_187 ( V_11 , V_299 ) ) ,
F_297 ( F_187 ( V_11 , V_295 ) ) ,
F_297 ( F_187 ( V_11 , V_298 ) ) ,
F_297 ( V_11 -> V_309 ) ,
F_297 ( V_11 -> V_80 ) ,
F_297 ( F_187 ( V_11 , V_310 ) ) ,
F_297 ( F_187 ( V_11 , V_300 ) ) ,
F_297 ( F_187 ( V_11 , V_301 ) ) ,
F_297 ( F_187 ( V_11 , V_305 ) ) ,
F_297 ( F_187 ( V_11 , V_306 ) ) ,
F_297 ( F_187 ( V_11 , V_303 ) ) ,
F_297 ( F_187 ( V_11 , V_304 ) ) ,
F_187 ( V_11 , V_311 ) *
V_312 / 1024 ,
F_297 ( F_187 ( V_11 , V_307 ) ) ,
F_297 ( F_187 ( V_11 , V_302 ) ) ,
F_297 ( F_187 ( V_11 , V_308 ) ) ,
F_297 ( F_187 ( V_11 , V_76 ) ) ,
F_297 ( F_187 ( V_11 , V_313 ) ) ,
V_11 -> V_68 ,
( ! F_299 ( V_11 ) ? L_53 : L_54 )
) ;
F_23 ( L_55 ) ;
for ( V_31 = 0 ; V_31 < V_285 ; V_31 ++ )
F_23 ( L_56 , V_11 -> V_155 [ V_31 ] ) ;
F_23 ( L_52 ) ;
}
F_137 (zone) {
unsigned long V_314 [ V_40 ] , V_59 , V_30 , V_315 = 0 ;
unsigned char V_288 [ V_40 ] ;
if ( F_293 ( V_207 , F_122 ( V_11 ) ) )
continue;
F_285 ( V_11 ) ;
F_23 ( L_57 , V_11 -> V_292 ) ;
F_148 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
struct V_52 * V_86 = & V_11 -> V_52 [ V_30 ] ;
int type ;
V_314 [ V_30 ] = V_86 -> V_53 ;
V_315 += V_314 [ V_30 ] << V_30 ;
V_288 [ V_30 ] = 0 ;
for ( type = 0 ; type < V_289 ; type ++ ) {
if ( ! F_77 ( & V_86 -> V_56 [ type ] ) )
V_288 [ V_30 ] |= 1 << type ;
}
}
F_156 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
F_23 ( L_58 , V_314 [ V_30 ] , F_297 ( 1UL ) << V_30 ) ;
if ( V_314 [ V_30 ] )
F_294 ( V_288 [ V_30 ] ) ;
}
F_23 ( L_59 , F_297 ( V_315 ) ) ;
}
F_300 () ;
F_23 ( L_60 , F_287 ( V_316 ) ) ;
F_301 () ;
}
static void F_302 ( struct V_11 * V_11 , struct V_174 * V_174 )
{
V_174 -> V_11 = V_11 ;
V_174 -> F_207 = F_207 ( V_11 ) ;
}
static int F_303 ( T_9 * V_284 , struct V_162 * V_162 ,
int V_317 )
{
struct V_11 * V_11 ;
enum V_224 V_224 = V_285 ;
do {
V_224 -- ;
V_11 = V_284 -> V_286 + V_224 ;
if ( F_304 ( V_11 ) ) {
F_302 ( V_11 ,
& V_162 -> V_176 [ V_317 ++ ] ) ;
F_305 ( V_224 ) ;
}
} while ( V_224 );
return V_317 ;
}
static int F_306 ( char * V_318 )
{
if ( * V_318 == 'd' || * V_318 == 'D' ) {
V_319 = V_320 ;
} else if ( * V_318 == 'n' || * V_318 == 'N' ) {
V_319 = V_321 ;
} else if ( * V_318 == 'z' || * V_318 == 'Z' ) {
V_319 = V_322 ;
} else {
F_23 ( V_323
L_61
L_62 , V_318 ) ;
return - V_324 ;
}
return 0 ;
}
static T_2 int F_307 ( char * V_318 )
{
int V_12 ;
if ( ! V_318 )
return 0 ;
V_12 = F_306 ( V_318 ) ;
if ( V_12 == 0 )
F_308 ( V_325 , V_318 , V_326 ) ;
return V_12 ;
}
int F_309 ( T_10 * V_327 , int V_328 ,
void T_11 * V_329 , T_8 * V_330 ,
T_12 * V_331 )
{
char V_332 [ V_326 ] ;
int V_12 ;
static F_310 ( V_333 ) ;
F_311 ( & V_333 ) ;
if ( V_328 ) {
if ( strlen ( ( char * ) V_327 -> V_334 ) >= V_326 ) {
V_12 = - V_324 ;
goto V_23;
}
strcpy ( V_332 , ( char * ) V_327 -> V_334 ) ;
}
V_12 = F_312 ( V_327 , V_328 , V_329 , V_330 , V_331 ) ;
if ( V_12 )
goto V_23;
if ( V_328 ) {
int V_335 = V_319 ;
V_12 = F_306 ( ( char * ) V_327 -> V_334 ) ;
if ( V_12 ) {
strncpy ( ( char * ) V_327 -> V_334 , V_332 ,
V_326 ) ;
V_319 = V_335 ;
} else if ( V_335 != V_319 ) {
F_311 ( & V_336 ) ;
F_313 ( NULL , NULL ) ;
F_314 ( & V_336 ) ;
}
}
V_23:
F_314 ( & V_333 ) ;
return V_12 ;
}
static int F_315 ( int V_179 , T_5 * V_337 )
{
int V_175 , V_274 ;
int V_338 = V_339 ;
int V_340 = V_341 ;
const struct V_342 * V_291 = F_316 ( 0 ) ;
if ( ! F_194 ( V_179 , * V_337 ) ) {
F_204 ( V_179 , * V_337 ) ;
return V_179 ;
}
F_317 (n, N_MEMORY) {
if ( F_194 ( V_175 , * V_337 ) )
continue;
V_274 = F_200 ( V_179 , V_175 ) ;
V_274 += ( V_175 < V_179 ) ;
V_291 = F_316 ( V_175 ) ;
if ( ! F_318 ( V_291 ) )
V_274 += V_343 ;
V_274 *= ( V_344 * V_345 ) ;
V_274 += V_346 [ V_175 ] ;
if ( V_274 < V_338 ) {
V_338 = V_274 ;
V_340 = V_175 ;
}
}
if ( V_340 >= 0 )
F_204 ( V_340 , * V_337 ) ;
return V_340 ;
}
static void F_319 ( T_9 * V_284 , int V_179 )
{
int V_347 ;
struct V_162 * V_162 ;
V_162 = & V_284 -> V_348 [ 0 ] ;
for ( V_347 = 0 ; V_162 -> V_176 [ V_347 ] . V_11 != NULL ; V_347 ++ )
;
V_347 = F_303 ( F_205 ( V_179 ) , V_162 , V_347 ) ;
V_162 -> V_176 [ V_347 ] . V_11 = NULL ;
V_162 -> V_176 [ V_347 ] . F_207 = 0 ;
}
static void F_320 ( T_9 * V_284 )
{
int V_347 ;
struct V_162 * V_162 ;
V_162 = & V_284 -> V_348 [ 1 ] ;
V_347 = F_303 ( V_284 , V_162 , 0 ) ;
V_162 -> V_176 [ V_347 ] . V_11 = NULL ;
V_162 -> V_176 [ V_347 ] . F_207 = 0 ;
}
static void F_321 ( T_9 * V_284 , int V_349 )
{
int V_350 , V_347 , V_179 ;
int V_224 ;
struct V_11 * V_149 ;
struct V_162 * V_162 ;
V_162 = & V_284 -> V_348 [ 0 ] ;
V_350 = 0 ;
for ( V_224 = V_285 - 1 ; V_224 >= 0 ; V_224 -- ) {
for ( V_347 = 0 ; V_347 < V_349 ; V_347 ++ ) {
V_179 = V_351 [ V_347 ] ;
V_149 = & F_205 ( V_179 ) -> V_286 [ V_224 ] ;
if ( F_304 ( V_149 ) ) {
F_302 ( V_149 ,
& V_162 -> V_176 [ V_350 ++ ] ) ;
F_305 ( V_224 ) ;
}
}
}
V_162 -> V_176 [ V_350 ] . V_11 = NULL ;
V_162 -> V_176 [ V_350 ] . F_207 = 0 ;
}
static int F_322 ( void )
{
int V_183 , V_224 ;
unsigned long V_352 , V_353 ;
struct V_11 * V_149 ;
int V_354 ;
V_352 = 0 ;
V_353 = 0 ;
F_203 (nid) {
for ( V_224 = 0 ; V_224 < V_285 ; V_224 ++ ) {
V_149 = & F_205 ( V_183 ) -> V_286 [ V_224 ] ;
if ( F_304 ( V_149 ) ) {
if ( V_224 < V_227 )
V_352 += V_149 -> V_80 ;
V_353 += V_149 -> V_80 ;
} else if ( V_224 == V_227 ) {
return V_321 ;
}
}
}
if ( ! V_352 ||
V_352 > V_353 / 2 )
return V_321 ;
V_354 = V_353 /
( F_323 ( V_172 [ V_173 ] ) + 1 ) ;
F_203 (nid) {
V_352 = 0 ;
V_353 = 0 ;
for ( V_224 = 0 ; V_224 < V_285 ; V_224 ++ ) {
V_149 = & F_205 ( V_183 ) -> V_286 [ V_224 ] ;
if ( F_304 ( V_149 ) ) {
if ( V_224 < V_227 )
V_352 += V_149 -> V_309 ;
V_353 += V_149 -> V_309 ;
}
}
if ( V_352 &&
V_353 > V_354 &&
V_352 > V_353 * 70 / 100 )
return V_321 ;
}
return V_322 ;
}
static void F_324 ( void )
{
if ( V_319 == V_320 )
V_355 = F_322 () ;
else
V_355 = V_319 ;
}
static void F_325 ( T_9 * V_284 )
{
int V_347 , V_179 , V_356 ;
enum V_224 V_31 ;
T_5 V_357 ;
int V_358 , V_359 ;
struct V_162 * V_162 ;
int V_30 = V_355 ;
for ( V_31 = 0 ; V_31 < V_360 ; V_31 ++ ) {
V_162 = V_284 -> V_348 + V_31 ;
V_162 -> V_176 [ 0 ] . V_11 = NULL ;
V_162 -> V_176 [ 0 ] . F_207 = 0 ;
}
V_358 = V_284 -> V_361 ;
V_356 = V_199 ;
V_359 = V_358 ;
F_326 ( V_357 ) ;
memset ( V_351 , 0 , sizeof( V_351 ) ) ;
V_347 = 0 ;
while ( ( V_179 = F_315 ( V_358 , & V_357 ) ) >= 0 ) {
if ( F_200 ( V_358 , V_179 ) !=
F_200 ( V_358 , V_359 ) )
V_346 [ V_179 ] = V_356 ;
V_359 = V_179 ;
V_356 -- ;
if ( V_30 == V_321 )
F_319 ( V_284 , V_179 ) ;
else
V_351 [ V_347 ++ ] = V_179 ;
}
if ( V_30 == V_322 ) {
F_321 ( V_284 , V_347 ) ;
}
F_320 ( V_284 ) ;
}
static void F_327 ( T_9 * V_284 )
{
struct V_162 * V_162 ;
struct V_163 * V_164 ;
struct V_174 * V_149 ;
V_162 = & V_284 -> V_348 [ 0 ] ;
V_162 -> V_166 = V_164 = & V_162 -> V_362 ;
F_192 ( V_164 -> V_168 , V_169 ) ;
for ( V_149 = V_162 -> V_176 ; V_149 -> V_11 ; V_149 ++ )
V_164 -> V_177 [ V_149 - V_162 -> V_176 ] = F_328 ( V_149 ) ;
}
int F_329 ( int V_179 )
{
struct V_11 * V_11 ;
( void ) F_252 ( F_253 ( V_179 , V_270 ) ,
F_257 ( V_270 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_179 ;
}
static void F_324 ( void )
{
V_355 = V_322 ;
}
static void F_325 ( T_9 * V_284 )
{
int V_179 , V_358 ;
enum V_224 V_347 ;
struct V_162 * V_162 ;
V_358 = V_284 -> V_361 ;
V_162 = & V_284 -> V_348 [ 0 ] ;
V_347 = F_303 ( V_284 , V_162 , 0 ) ;
for ( V_179 = V_358 + 1 ; V_179 < V_345 ; V_179 ++ ) {
if ( ! F_330 ( V_179 ) )
continue;
V_347 = F_303 ( F_205 ( V_179 ) , V_162 , V_347 ) ;
}
for ( V_179 = 0 ; V_179 < V_358 ; V_179 ++ ) {
if ( ! F_330 ( V_179 ) )
continue;
V_347 = F_303 ( F_205 ( V_179 ) , V_162 , V_347 ) ;
}
V_162 -> V_176 [ V_347 ] . V_11 = NULL ;
V_162 -> V_176 [ V_347 ] . F_207 = 0 ;
}
static void F_327 ( T_9 * V_284 )
{
V_284 -> V_348 [ 0 ] . V_166 = NULL ;
}
static int F_331 ( void * V_334 )
{
int V_183 ;
int V_112 ;
T_9 * V_363 = V_334 ;
#ifdef V_191
memset ( V_346 , 0 , sizeof( V_346 ) ) ;
#endif
if ( V_363 && ! F_330 ( V_363 -> V_361 ) ) {
F_325 ( V_363 ) ;
F_327 ( V_363 ) ;
}
F_203 (nid) {
T_9 * V_284 = F_205 ( V_183 ) ;
F_325 ( V_284 ) ;
F_327 ( V_284 ) ;
}
F_332 (cpu) {
F_333 ( & F_334 ( V_364 , V_112 ) , 0 ) ;
#ifdef F_335
if ( F_336 ( V_112 ) )
F_337 ( V_112 , F_329 ( F_338 ( V_112 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_313 ( T_9 * V_284 , struct V_11 * V_11 )
{
F_324 () ;
if ( V_365 == V_366 ) {
F_331 ( NULL ) ;
F_339 () ;
F_340 () ;
} else {
#ifdef F_341
if ( V_11 )
F_342 ( V_11 ) ;
#endif
F_343 ( F_331 , V_284 , NULL ) ;
}
V_367 = F_284 () ;
if ( V_367 < ( V_81 * V_289 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_23 ( L_63
L_64 ,
V_199 ,
V_368 [ V_355 ] ,
V_7 ? L_65 : L_66 ,
V_367 ) ;
#ifdef V_191
F_23 ( L_67 , V_369 [ V_370 ] ) ;
#endif
}
static inline unsigned long F_344 ( unsigned long V_102 )
{
unsigned long V_87 = 1 ;
V_102 /= V_371 ;
while ( V_87 < V_102 )
V_87 <<= 1 ;
V_87 = V_154 ( V_87 , 4096UL ) ;
return F_345 ( V_87 , 4UL ) ;
}
static inline unsigned long F_344 ( unsigned long V_102 )
{
return 4096UL ;
}
static inline unsigned long F_346 ( unsigned long V_87 )
{
return F_347 ( ~ V_87 ) ;
}
static int F_348 ( unsigned long V_16 , unsigned long V_95 )
{
unsigned long V_14 ;
for ( V_14 = V_16 ; V_14 < V_95 ; V_14 ++ ) {
if ( ! F_16 ( V_14 ) || F_349 ( F_125 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_350 ( struct V_11 * V_11 )
{
unsigned long V_16 , V_14 , V_95 , V_372 ;
struct V_5 * V_5 ;
unsigned long V_373 ;
int V_374 ;
V_16 = V_11 -> V_17 ;
V_95 = F_149 ( V_11 ) ;
V_16 = F_351 ( V_16 , V_81 ) ;
V_374 = F_351 ( F_298 ( V_11 ) , V_81 ) >>
V_83 ;
V_374 = V_154 ( 2 , V_374 ) ;
for ( V_14 = V_16 ; V_14 < V_95 ; V_14 += V_81 ) {
if ( ! F_150 ( V_14 ) )
continue;
V_5 = F_125 ( V_14 ) ;
if ( F_121 ( V_5 ) != F_122 ( V_11 ) )
continue;
V_373 = F_100 ( V_5 ) ;
if ( V_374 > 0 ) {
V_372 = V_154 ( V_14 + V_81 , V_95 ) ;
if ( F_348 ( V_14 , V_372 ) )
continue;
if ( V_373 == V_106 ) {
V_374 -- ;
continue;
}
if ( V_373 == V_122 ) {
F_6 ( V_5 ,
V_106 ) ;
F_124 ( V_11 , V_5 ,
V_106 ) ;
V_374 -- ;
continue;
}
}
if ( V_373 == V_106 ) {
F_6 ( V_5 , V_122 ) ;
F_124 ( V_11 , V_5 , V_122 ) ;
}
}
}
void T_14 F_352 ( unsigned long V_87 , int V_183 , unsigned long V_11 ,
unsigned long V_16 , enum V_375 V_376 )
{
struct V_5 * V_5 ;
unsigned long V_95 = V_16 + V_87 ;
unsigned long V_14 ;
struct V_11 * V_149 ;
if ( V_377 < V_95 - 1 )
V_377 = V_95 - 1 ;
V_149 = & F_205 ( V_183 ) -> V_286 [ V_11 ] ;
for ( V_14 = V_16 ; V_14 < V_95 ; V_14 ++ ) {
if ( V_376 == V_378 ) {
if ( ! F_353 ( V_14 ) )
continue;
if ( ! F_354 ( V_14 , V_183 ) )
continue;
}
V_5 = F_125 ( V_14 ) ;
F_355 ( V_5 , V_11 , V_183 , V_14 ) ;
F_356 ( V_5 , V_11 , V_183 , V_14 ) ;
F_357 ( V_5 ) ;
F_21 ( V_5 ) ;
F_74 ( V_5 ) ;
F_358 ( V_5 ) ;
if ( ( V_149 -> V_17 <= V_14 )
&& ( V_14 < F_149 ( V_149 ) )
&& ! ( V_14 & ( V_81 - 1 ) ) )
F_6 ( V_5 , V_122 ) ;
F_113 ( & V_5 -> V_51 ) ;
#ifdef F_359
if ( ! F_360 ( V_11 ) )
F_361 ( V_5 , F_362 ( V_14 << V_379 ) ) ;
#endif
}
}
static void T_14 F_363 ( struct V_11 * V_11 )
{
int V_30 , V_120 ;
F_153 (order, t) {
F_113 ( & V_11 -> V_52 [ V_30 ] . V_56 [ V_120 ] ) ;
V_11 -> V_52 [ V_30 ] . V_53 = 0 ;
}
}
static int T_14 F_364 ( struct V_11 * V_11 )
{
#ifdef F_365
int V_111 ;
V_111 = V_11 -> V_80 / 1024 ;
if ( V_111 * V_77 > 512 * 1024 )
V_111 = ( 512 * 1024 ) / V_77 ;
V_111 /= 4 ;
if ( V_111 < 1 )
V_111 = 1 ;
V_111 = F_366 ( V_111 + V_111 / 2 ) - 1 ;
return V_111 ;
#else
return 0 ;
#endif
}
static void F_367 ( struct V_63 * V_64 , unsigned long V_85 ,
unsigned long V_111 )
{
V_64 -> V_111 = 1 ;
F_368 () ;
V_64 -> V_85 = V_85 ;
F_368 () ;
V_64 -> V_111 = V_111 ;
}
static void F_369 ( struct V_113 * V_33 , unsigned long V_111 )
{
F_367 ( & V_33 -> V_64 , 6 * V_111 , F_345 ( 1UL , 1 * V_111 ) ) ;
}
static void F_370 ( struct V_113 * V_33 )
{
struct V_63 * V_64 ;
int V_6 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_64 = & V_33 -> V_64 ;
V_64 -> V_62 = 0 ;
for ( V_6 = 0 ; V_6 < V_71 ; V_6 ++ )
F_113 ( & V_64 -> V_72 [ V_6 ] ) ;
}
static void F_333 ( struct V_113 * V_33 , unsigned long V_111 )
{
F_370 ( V_33 ) ;
F_369 ( V_33 , V_111 ) ;
}
static void F_371 ( struct V_113 * V_33 ,
unsigned long V_85 )
{
unsigned long V_111 = F_345 ( 1UL , V_85 / 4 ) ;
if ( ( V_85 / 4 ) > ( V_379 * 8 ) )
V_111 = V_379 * 8 ;
F_367 ( & V_33 -> V_64 , V_85 , V_111 ) ;
}
static void T_14 F_372 ( struct V_11 * V_11 ,
struct V_113 * V_64 )
{
if ( V_380 )
F_371 ( V_64 ,
( V_11 -> V_80 /
V_380 ) ) ;
else
F_369 ( V_64 , F_364 ( V_11 ) ) ;
}
static void T_14 F_373 ( struct V_11 * V_11 , int V_112 )
{
struct V_113 * V_64 = F_138 ( V_11 -> V_115 , V_112 ) ;
F_370 ( V_64 ) ;
F_372 ( V_11 , V_64 ) ;
}
static void T_14 F_342 ( struct V_11 * V_11 )
{
int V_112 ;
V_11 -> V_115 = F_374 ( struct V_113 ) ;
F_332 (cpu)
F_373 ( V_11 , V_112 ) ;
}
void T_2 F_375 ( void )
{
struct V_11 * V_11 ;
F_137 (zone)
F_342 ( V_11 ) ;
}
static T_15 T_16
int F_376 ( struct V_11 * V_11 , unsigned long V_381 )
{
int V_31 ;
struct V_382 * V_284 = V_11 -> V_181 ;
T_8 V_383 ;
V_11 -> F_344 =
F_344 ( V_381 ) ;
V_11 -> F_346 =
F_346 ( V_11 -> F_344 ) ;
V_383 = V_11 -> F_344
* sizeof( V_384 ) ;
if ( ! F_377 () ) {
V_11 -> V_385 = ( V_384 * )
F_378 ( V_284 , V_383 ) ;
} else {
V_11 -> V_385 = F_379 ( V_383 ) ;
}
if ( ! V_11 -> V_385 )
return - V_148 ;
for ( V_31 = 0 ; V_31 < V_11 -> F_344 ; ++ V_31 )
F_380 ( V_11 -> V_385 + V_31 ) ;
return 0 ;
}
static T_14 void F_381 ( struct V_11 * V_11 )
{
V_11 -> V_115 = & V_364 ;
if ( V_11 -> V_309 )
F_23 ( V_386 L_68 ,
V_11 -> V_292 , V_11 -> V_309 ,
F_364 ( V_11 ) ) ;
}
int T_14 F_382 ( struct V_11 * V_11 ,
unsigned long V_17 ,
unsigned long V_87 ,
enum V_375 V_376 )
{
struct V_382 * V_284 = V_11 -> V_181 ;
int V_12 ;
V_12 = F_376 ( V_11 , V_87 ) ;
if ( V_12 )
return V_12 ;
V_284 -> V_317 = F_207 ( V_11 ) + 1 ;
V_11 -> V_17 = V_17 ;
F_383 ( V_387 , L_69 ,
L_70 ,
V_284 -> V_361 ,
( unsigned long ) F_207 ( V_11 ) ,
V_17 , ( V_17 + V_87 ) ) ;
F_363 ( V_11 ) ;
return 0 ;
}
int T_14 F_384 ( unsigned long V_14 )
{
unsigned long V_16 , V_95 ;
int V_183 ;
static unsigned long T_17 V_388 , V_389 ;
static int T_17 V_390 ;
if ( V_388 <= V_14 && V_14 < V_389 )
return V_390 ;
V_183 = F_385 ( V_14 , & V_16 , & V_95 ) ;
if ( V_183 != - 1 ) {
V_388 = V_16 ;
V_389 = V_95 ;
V_390 = V_183 ;
}
return V_183 ;
}
int T_14 F_386 ( unsigned long V_14 )
{
int V_183 ;
V_183 = F_384 ( V_14 ) ;
if ( V_183 >= 0 )
return V_183 ;
return 0 ;
}
bool T_14 F_354 ( unsigned long V_14 , int V_179 )
{
int V_183 ;
V_183 = F_384 ( V_14 ) ;
if ( V_183 >= 0 && V_183 != V_179 )
return false ;
return true ;
}
void T_2 F_387 ( int V_183 , unsigned long V_391 )
{
unsigned long V_16 , V_95 ;
int V_31 , V_392 ;
F_388 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_16 = V_154 ( V_16 , V_391 ) ;
V_95 = V_154 ( V_95 , V_391 ) ;
if ( V_16 < V_95 )
F_389 ( F_205 ( V_392 ) ,
F_390 ( V_16 ) ,
( V_95 - V_16 ) << V_379 ) ;
}
}
void T_2 F_391 ( int V_183 )
{
unsigned long V_16 , V_95 ;
int V_31 , V_392 ;
F_388 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_392 ( V_392 , V_16 , V_95 ) ;
}
void T_14 F_393 ( unsigned int V_183 ,
unsigned long * V_16 , unsigned long * V_95 )
{
unsigned long V_393 , V_394 ;
int V_31 ;
* V_16 = - 1UL ;
* V_95 = 0 ;
F_388 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_16 = V_154 ( * V_16 , V_393 ) ;
* V_95 = F_345 ( * V_95 , V_394 ) ;
}
if ( * V_16 == - 1UL )
* V_16 = 0 ;
}
static void T_2 F_394 ( void )
{
int V_395 ;
for ( V_395 = V_285 - 1 ; V_395 >= 0 ; V_395 -- ) {
if ( V_395 == V_396 )
continue;
if ( V_397 [ V_395 ] >
V_398 [ V_395 ] )
break;
}
F_42 ( V_395 == - 1 ) ;
V_399 = V_395 ;
}
static void T_14 F_395 ( int V_183 ,
unsigned long V_224 ,
unsigned long V_400 ,
unsigned long V_401 ,
unsigned long * V_17 ,
unsigned long * F_149 )
{
if ( V_402 [ V_183 ] ) {
if ( V_224 == V_396 ) {
* V_17 = V_402 [ V_183 ] ;
* F_149 = V_154 ( V_401 ,
V_397 [ V_399 ] ) ;
} else if ( * V_17 < V_402 [ V_183 ] &&
* F_149 > V_402 [ V_183 ] ) {
* F_149 = V_402 [ V_183 ] ;
} else if ( * V_17 >= V_402 [ V_183 ] )
* V_17 = * F_149 ;
}
}
static unsigned long T_14 F_396 ( int V_183 ,
unsigned long V_224 ,
unsigned long V_400 ,
unsigned long V_401 ,
unsigned long * V_403 )
{
unsigned long V_17 , F_149 ;
V_17 = V_398 [ V_224 ] ;
F_149 = V_397 [ V_224 ] ;
F_395 ( V_183 , V_224 ,
V_400 , V_401 ,
& V_17 , & F_149 ) ;
if ( F_149 < V_400 || V_17 > V_401 )
return 0 ;
F_149 = V_154 ( F_149 , V_401 ) ;
V_17 = F_345 ( V_17 , V_400 ) ;
return F_149 - V_17 ;
}
unsigned long T_14 F_397 ( int V_183 ,
unsigned long V_404 ,
unsigned long V_405 )
{
unsigned long V_406 = V_405 - V_404 ;
unsigned long V_16 , V_95 ;
int V_31 ;
F_388 (i, nid, &start_pfn, &end_pfn, NULL) {
V_16 = F_398 ( V_16 , V_404 , V_405 ) ;
V_95 = F_398 ( V_95 , V_404 , V_405 ) ;
V_406 -= V_95 - V_16 ;
}
return V_406 ;
}
unsigned long T_2 F_399 ( unsigned long V_16 ,
unsigned long V_95 )
{
return F_397 ( V_345 , V_16 , V_95 ) ;
}
static unsigned long T_14 F_400 ( int V_183 ,
unsigned long V_224 ,
unsigned long V_400 ,
unsigned long V_401 ,
unsigned long * V_403 )
{
unsigned long V_407 = V_398 [ V_224 ] ;
unsigned long V_408 = V_397 [ V_224 ] ;
unsigned long V_17 , F_149 ;
V_17 = F_398 ( V_400 , V_407 , V_408 ) ;
F_149 = F_398 ( V_401 , V_407 , V_408 ) ;
F_395 ( V_183 , V_224 ,
V_400 , V_401 ,
& V_17 , & F_149 ) ;
return F_397 ( V_183 , V_17 , F_149 ) ;
}
static inline unsigned long T_14 F_396 ( int V_183 ,
unsigned long V_224 ,
unsigned long V_400 ,
unsigned long V_401 ,
unsigned long * V_409 )
{
return V_409 [ V_224 ] ;
}
static inline unsigned long T_14 F_400 ( int V_183 ,
unsigned long V_224 ,
unsigned long V_400 ,
unsigned long V_401 ,
unsigned long * V_410 )
{
if ( ! V_410 )
return 0 ;
return V_410 [ V_224 ] ;
}
static void T_14 F_401 ( struct V_382 * V_284 ,
unsigned long V_400 ,
unsigned long V_401 ,
unsigned long * V_409 ,
unsigned long * V_410 )
{
unsigned long V_411 , V_412 = 0 ;
enum V_224 V_31 ;
for ( V_31 = 0 ; V_31 < V_285 ; V_31 ++ )
V_412 += F_396 ( V_284 -> V_361 , V_31 ,
V_400 ,
V_401 ,
V_409 ) ;
V_284 -> V_413 = V_412 ;
V_411 = V_412 ;
for ( V_31 = 0 ; V_31 < V_285 ; V_31 ++ )
V_411 -=
F_400 ( V_284 -> V_361 , V_31 ,
V_400 , V_401 ,
V_410 ) ;
V_284 -> V_414 = V_411 ;
F_23 ( V_386 L_71 , V_284 -> V_361 ,
V_411 ) ;
}
static unsigned long T_2 F_402 ( unsigned long V_17 , unsigned long V_415 )
{
unsigned long V_416 ;
V_415 += V_17 & ( V_81 - 1 ) ;
V_416 = F_351 ( V_415 , V_81 ) ;
V_416 = V_416 >> V_83 ;
V_416 *= V_417 ;
V_416 = F_351 ( V_416 , 8 * sizeof( unsigned long ) ) ;
return V_416 / 8 ;
}
static void T_2 F_403 ( struct V_382 * V_284 ,
struct V_11 * V_11 ,
unsigned long V_17 ,
unsigned long V_415 )
{
unsigned long V_416 = F_402 ( V_17 , V_415 ) ;
V_11 -> V_418 = NULL ;
if ( V_416 )
V_11 -> V_418 = F_378 ( V_284 ,
V_416 ) ;
}
static inline void F_403 ( struct V_382 * V_284 , struct V_11 * V_11 ,
unsigned long V_17 , unsigned long V_415 ) {}
void T_6 F_404 ( void )
{
unsigned int V_30 ;
if ( V_83 )
return;
if ( V_419 > V_379 )
V_30 = V_420 ;
else
V_30 = V_40 - 1 ;
V_83 = V_30 ;
}
void T_6 F_404 ( void )
{
}
static unsigned long T_6 F_405 ( unsigned long V_18 ,
unsigned long V_309 )
{
unsigned long V_102 = V_18 ;
if ( V_18 > V_309 + ( V_309 >> 4 ) &&
F_133 ( V_421 ) )
V_102 = V_309 ;
return F_275 ( V_102 * sizeof( struct V_5 ) ) >> V_379 ;
}
static void T_6 F_406 ( struct V_382 * V_284 ,
unsigned long V_400 , unsigned long V_401 ,
unsigned long * V_409 , unsigned long * V_410 )
{
enum V_224 V_347 ;
int V_183 = V_284 -> V_361 ;
unsigned long V_17 = V_284 -> V_400 ;
int V_12 ;
F_407 ( V_284 ) ;
#ifdef F_408
F_409 ( & V_284 -> V_422 ) ;
V_284 -> V_423 = 0 ;
V_284 -> V_424 = V_22 ;
#endif
F_380 ( & V_284 -> V_425 ) ;
F_380 ( & V_284 -> V_426 ) ;
F_410 ( V_284 ) ;
for ( V_347 = 0 ; V_347 < V_285 ; V_347 ++ ) {
struct V_11 * V_11 = V_284 -> V_286 + V_347 ;
unsigned long V_87 , V_427 , V_428 , V_429 ;
V_87 = F_396 ( V_183 , V_347 , V_400 ,
V_401 , V_409 ) ;
V_427 = V_428 = V_87 - F_400 ( V_183 , V_347 ,
V_400 ,
V_401 ,
V_410 ) ;
V_429 = F_405 ( V_87 , V_427 ) ;
if ( V_428 >= V_429 ) {
V_428 -= V_429 ;
if ( V_429 )
F_23 ( V_386
L_72 ,
V_369 [ V_347 ] , V_429 ) ;
} else
F_23 ( V_323
L_73 ,
V_369 [ V_347 ] , V_429 , V_428 ) ;
if ( V_347 == 0 && V_428 > V_430 ) {
V_428 -= V_430 ;
F_23 ( V_386 L_74 ,
V_369 [ 0 ] , V_430 ) ;
}
if ( ! F_360 ( V_347 ) )
V_431 += V_428 ;
else if ( V_431 > V_429 * 2 )
V_431 -= V_429 ;
V_432 += V_428 ;
V_11 -> V_18 = V_87 ;
V_11 -> V_309 = V_427 ;
V_11 -> V_80 = F_360 ( V_347 ) ? V_427 : V_428 ;
#ifdef V_191
V_11 -> V_179 = V_183 ;
V_11 -> V_433 = ( V_428 * V_434 )
/ 100 ;
V_11 -> V_435 = ( V_428 * V_436 ) / 100 ;
#endif
V_11 -> V_292 = V_369 [ V_347 ] ;
F_409 ( & V_11 -> V_67 ) ;
F_409 ( & V_11 -> V_437 ) ;
F_411 ( V_11 ) ;
V_11 -> V_181 = V_284 ;
F_381 ( V_11 ) ;
F_244 ( V_11 , V_131 , V_11 -> V_80 ) ;
F_412 ( & V_11 -> V_438 ) ;
if ( ! V_87 )
continue;
F_404 () ;
F_403 ( V_284 , V_11 , V_17 , V_87 ) ;
V_12 = F_382 ( V_11 , V_17 ,
V_87 , V_378 ) ;
F_120 ( V_12 ) ;
F_413 ( V_87 , V_183 , V_347 , V_17 ) ;
V_17 += V_87 ;
}
}
static void T_16 F_414 ( struct V_382 * V_284 )
{
if ( ! V_284 -> V_413 )
return;
#ifdef F_415
if ( ! V_284 -> V_439 ) {
unsigned long V_87 , V_440 , V_267 ;
struct V_5 * V_441 ;
V_440 = V_284 -> V_400 & ~ ( V_442 - 1 ) ;
V_267 = F_416 ( V_284 ) ;
V_267 = F_417 ( V_267 , V_442 ) ;
V_87 = ( V_267 - V_440 ) * sizeof( struct V_5 ) ;
V_441 = F_418 ( V_284 -> V_361 , V_87 ) ;
if ( ! V_441 )
V_441 = F_378 ( V_284 , V_87 ) ;
V_284 -> V_439 = V_441 + ( V_284 -> V_400 - V_440 ) ;
}
#ifndef F_419
if ( V_284 == F_205 ( 0 ) ) {
V_443 = F_205 ( 0 ) -> V_439 ;
#ifdef F_420
if ( F_10 ( V_443 ) != V_284 -> V_400 )
V_443 -= ( V_284 -> V_400 - V_444 ) ;
#endif
}
#endif
#endif
}
void T_6 F_421 ( int V_183 , unsigned long * V_409 ,
unsigned long V_400 , unsigned long * V_410 )
{
T_9 * V_284 = F_205 ( V_183 ) ;
unsigned long V_16 = 0 ;
unsigned long V_95 = 0 ;
F_2 ( V_284 -> V_317 || V_284 -> V_151 ) ;
V_284 -> V_361 = V_183 ;
V_284 -> V_400 = V_400 ;
F_202 ( V_183 ) ;
#ifdef F_420
F_393 ( V_183 , & V_16 , & V_95 ) ;
#endif
F_401 ( V_284 , V_16 , V_95 ,
V_409 , V_410 ) ;
F_414 ( V_284 ) ;
#ifdef F_415
F_23 ( V_386 L_75 ,
V_183 , ( unsigned long ) V_284 ,
( unsigned long ) V_284 -> V_439 ) ;
#endif
F_406 ( V_284 , V_16 , V_95 ,
V_409 , V_410 ) ;
}
void T_2 F_422 ( void )
{
unsigned int V_179 ;
unsigned int V_445 = 0 ;
F_423 (node, node_possible_map)
V_445 = V_179 ;
V_446 = V_445 + 1 ;
}
unsigned long T_2 F_424 ( void )
{
unsigned long V_447 = 0 , V_448 = 0 ;
unsigned long V_440 , V_267 , V_449 ;
int V_390 = - 1 ;
int V_31 , V_183 ;
F_388 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_440 || V_390 < 0 || V_390 == V_183 ) {
V_390 = V_183 ;
V_448 = V_267 ;
continue;
}
V_449 = ~ ( ( 1 << F_425 ( V_440 ) ) - 1 ) ;
while ( V_449 && V_448 <= ( V_440 & ( V_449 << 1 ) ) )
V_449 <<= 1 ;
V_447 |= V_449 ;
}
return ~ V_447 + 1 ;
}
static unsigned long T_2 F_426 ( int V_183 )
{
unsigned long V_450 = V_451 ;
unsigned long V_16 ;
int V_31 ;
F_388 (i, nid, &start_pfn, NULL, NULL)
V_450 = V_154 ( V_450 , V_16 ) ;
if ( V_450 == V_451 ) {
F_23 ( V_323
L_76 , V_183 ) ;
return 0 ;
}
return V_450 ;
}
unsigned long T_2 F_427 ( void )
{
return F_426 ( V_345 ) ;
}
static unsigned long T_2 F_428 ( void )
{
unsigned long V_412 = 0 ;
unsigned long V_16 , V_95 ;
int V_31 , V_183 ;
F_388 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_102 = V_95 - V_16 ;
V_412 += V_102 ;
if ( V_102 )
F_429 ( V_183 , V_173 ) ;
}
return V_412 ;
}
static void T_2 F_430 ( void )
{
int V_31 , V_183 ;
unsigned long V_452 ;
unsigned long V_453 , V_454 ;
T_5 V_455 = V_172 [ V_173 ] ;
unsigned long V_412 = F_428 () ;
int V_456 = F_323 ( V_172 [ V_173 ] ) ;
if ( V_457 ) {
unsigned long V_458 ;
V_457 =
F_351 ( V_457 , V_442 ) ;
V_458 = V_412 - V_457 ;
V_459 = F_345 ( V_459 , V_458 ) ;
}
if ( ! V_459 )
goto V_23;
F_394 () ;
V_452 = V_398 [ V_399 ] ;
V_252:
V_453 = V_459 / V_456 ;
F_317 (nid, N_MEMORY) {
unsigned long V_16 , V_95 ;
if ( V_459 < V_453 )
V_453 = V_459 / V_456 ;
V_454 = V_453 ;
F_388 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_460 ;
V_16 = F_345 ( V_16 , V_402 [ V_183 ] ) ;
if ( V_16 >= V_95 )
continue;
if ( V_16 < V_452 ) {
unsigned long V_461 ;
V_461 = V_154 ( V_95 , V_452 )
- V_16 ;
V_454 -= V_154 ( V_461 ,
V_454 ) ;
V_459 -= V_154 ( V_461 ,
V_459 ) ;
if ( V_95 <= V_452 ) {
V_402 [ V_183 ] = V_95 ;
continue;
}
V_16 = V_452 ;
}
V_460 = V_95 - V_16 ;
if ( V_460 > V_454 )
V_460 = V_454 ;
V_402 [ V_183 ] = V_16 + V_460 ;
V_459 -= V_154 ( V_459 ,
V_460 ) ;
V_454 -= V_460 ;
if ( ! V_454 )
break;
}
}
V_456 -- ;
if ( V_456 && V_459 > V_456 )
goto V_252;
for ( V_183 = 0 ; V_183 < V_345 ; V_183 ++ )
V_402 [ V_183 ] =
F_351 ( V_402 [ V_183 ] , V_442 ) ;
V_23:
V_172 [ V_173 ] = V_455 ;
}
static void F_431 ( T_9 * V_284 , int V_183 )
{
enum V_224 V_224 ;
if ( V_173 == V_462 )
return;
for ( V_224 = 0 ; V_224 <= V_396 - 1 ; V_224 ++ ) {
struct V_11 * V_11 = & V_284 -> V_286 [ V_224 ] ;
if ( V_11 -> V_309 ) {
F_429 ( V_183 , V_463 ) ;
if ( V_462 != V_463 &&
V_224 <= V_227 )
F_429 ( V_183 , V_462 ) ;
break;
}
}
}
void T_2 F_432 ( unsigned long * V_119 )
{
unsigned long V_16 , V_95 ;
int V_31 , V_183 ;
memset ( V_398 , 0 ,
sizeof( V_398 ) ) ;
memset ( V_397 , 0 ,
sizeof( V_397 ) ) ;
V_398 [ 0 ] = F_427 () ;
V_397 [ 0 ] = V_119 [ 0 ] ;
for ( V_31 = 1 ; V_31 < V_285 ; V_31 ++ ) {
if ( V_31 == V_396 )
continue;
V_398 [ V_31 ] =
V_397 [ V_31 - 1 ] ;
V_397 [ V_31 ] =
F_345 ( V_119 [ V_31 ] , V_398 [ V_31 ] ) ;
}
V_398 [ V_396 ] = 0 ;
V_397 [ V_396 ] = 0 ;
memset ( V_402 , 0 , sizeof( V_402 ) ) ;
F_430 () ;
F_23 ( L_77 ) ;
for ( V_31 = 0 ; V_31 < V_285 ; V_31 ++ ) {
if ( V_31 == V_396 )
continue;
F_23 ( V_464 L_78 , V_369 [ V_31 ] ) ;
if ( V_398 [ V_31 ] ==
V_397 [ V_31 ] )
F_23 ( V_464 L_79 ) ;
else
F_23 ( V_464 L_80 ,
V_398 [ V_31 ] << V_379 ,
( V_397 [ V_31 ]
<< V_379 ) - 1 ) ;
}
F_23 ( L_81 ) ;
for ( V_31 = 0 ; V_31 < V_345 ; V_31 ++ ) {
if ( V_402 [ V_31 ] )
F_23 ( L_82 , V_31 ,
V_402 [ V_31 ] << V_379 ) ;
}
F_23 ( L_83 ) ;
F_388 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_23 ( L_84 , V_183 ,
V_16 << V_379 , ( V_95 << V_379 ) - 1 ) ;
F_433 () ;
F_422 () ;
F_203 (nid) {
T_9 * V_284 = F_205 ( V_183 ) ;
F_421 ( V_183 , NULL ,
F_426 ( V_183 ) , NULL ) ;
if ( V_284 -> V_414 )
F_429 ( V_183 , V_173 ) ;
F_431 ( V_284 , V_183 ) ;
}
}
static int T_2 F_434 ( char * V_33 , unsigned long * V_465 )
{
unsigned long long V_466 ;
if ( ! V_33 )
return - V_324 ;
V_466 = F_435 ( V_33 , & V_33 ) ;
* V_465 = V_466 >> V_379 ;
F_2 ( ( V_466 >> V_379 ) > V_451 ) ;
return 0 ;
}
static int T_2 F_436 ( char * V_33 )
{
return F_434 ( V_33 , & V_459 ) ;
}
static int T_2 F_437 ( char * V_33 )
{
return F_434 ( V_33 , & V_457 ) ;
}
void F_109 ( struct V_5 * V_5 , long V_62 )
{
F_76 ( & V_467 ) ;
F_17 ( V_5 ) -> V_80 += V_62 ;
V_276 += V_62 ;
#ifdef F_292
if ( F_92 ( V_5 ) )
V_281 += V_62 ;
#endif
F_85 ( & V_467 ) ;
}
unsigned long F_438 ( void * V_440 , void * V_267 , int V_468 , char * V_318 )
{
void * V_350 ;
unsigned long V_102 = 0 ;
V_440 = ( void * ) F_275 ( ( unsigned long ) V_440 ) ;
V_267 = ( void * ) ( ( unsigned long ) V_267 & V_469 ) ;
for ( V_350 = V_440 ; V_350 < V_267 ; V_350 += V_77 , V_102 ++ ) {
if ( ( unsigned int ) V_468 <= 0xFF )
memset ( V_350 , V_468 , V_77 ) ;
F_439 ( F_166 ( V_350 ) ) ;
}
if ( V_102 && V_318 )
F_440 ( L_85 ,
V_318 , V_102 << ( V_379 - 10 ) , V_440 , V_267 ) ;
return V_102 ;
}
void F_441 ( struct V_5 * V_5 )
{
F_442 ( V_5 ) ;
V_276 ++ ;
F_17 ( V_5 ) -> V_80 ++ ;
V_281 ++ ;
}
void T_2 F_443 ( const char * V_133 )
{
unsigned long V_470 , V_471 , V_472 , V_473 , V_474 ;
unsigned long V_475 , V_476 ;
V_470 = F_444 () ;
V_471 = V_477 - V_478 ;
V_472 = V_479 - V_480 ;
V_473 = V_481 - V_482 ;
V_474 = V_483 - V_484 ;
V_476 = V_485 - V_486 ;
V_475 = V_487 - V_488 ;
#define F_445 ( V_440 , V_267 , V_87 , V_350 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_445 ( V_486 , V_485 , V_476 ,
V_488 , V_475 ) ;
F_445 ( V_478 , V_477 , V_471 , V_488 , V_475 ) ;
F_445 ( V_480 , V_479 , V_472 , V_486 , V_476 ) ;
F_445 ( V_478 , V_477 , V_471 , V_482 , V_473 ) ;
F_445 ( V_480 , V_479 , V_472 , V_482 , V_473 ) ;
#undef F_445
F_23 ( L_86
L_87
L_88
#ifdef F_292
L_89
#endif
L_90 ,
F_446 () << ( V_379 - 10 ) , V_470 << ( V_379 - 10 ) ,
V_471 >> 10 , V_472 >> 10 , V_473 >> 10 ,
( V_476 + V_475 ) >> 10 , V_474 >> 10 ,
( V_470 - V_276 ) << ( V_379 - 10 ) ,
#ifdef F_292
V_281 << ( V_379 - 10 ) ,
#endif
V_133 ? L_91 : L_92 , V_133 ? V_133 : L_92 ) ;
}
void T_2 F_447 ( unsigned long V_489 )
{
V_430 = V_489 ;
}
void T_2 F_448 ( unsigned long * V_409 )
{
F_421 ( 0 , V_409 ,
F_449 ( V_490 ) >> V_379 , NULL ) ;
}
static int F_450 ( struct V_491 * V_363 ,
unsigned long V_492 , void * V_493 )
{
int V_112 = ( unsigned long ) V_493 ;
if ( V_492 == V_494 || V_492 == V_495 ) {
F_451 ( V_112 ) ;
F_136 ( V_112 ) ;
F_452 ( V_112 ) ;
F_453 ( V_112 ) ;
}
return V_496 ;
}
void T_2 F_454 ( void )
{
F_455 ( F_450 , 0 ) ;
}
static void F_456 ( void )
{
struct V_382 * V_284 ;
unsigned long V_497 = 0 ;
enum V_224 V_31 , V_347 ;
F_457 (pgdat) {
for ( V_31 = 0 ; V_31 < V_285 ; V_31 ++ ) {
struct V_11 * V_11 = V_284 -> V_286 + V_31 ;
unsigned long F_345 = 0 ;
for ( V_347 = V_31 ; V_347 < V_285 ; V_347 ++ ) {
if ( V_11 -> V_155 [ V_347 ] > F_345 )
F_345 = V_11 -> V_155 [ V_347 ] ;
}
F_345 += F_245 ( V_11 ) ;
if ( F_345 > V_11 -> V_80 )
F_345 = V_11 -> V_80 ;
V_497 += F_345 ;
V_11 -> V_498 = F_345 ;
}
}
V_498 = V_497 ;
V_499 = V_497 ;
}
static void F_458 ( void )
{
struct V_382 * V_284 ;
enum V_224 V_347 , V_500 ;
F_457 (pgdat) {
for ( V_347 = 0 ; V_347 < V_285 ; V_347 ++ ) {
struct V_11 * V_11 = V_284 -> V_286 + V_347 ;
unsigned long V_80 = V_11 -> V_80 ;
V_11 -> V_155 [ V_347 ] = 0 ;
V_500 = V_347 ;
while ( V_500 ) {
struct V_11 * V_501 ;
V_500 -- ;
if ( V_502 [ V_500 ] < 1 )
V_502 [ V_500 ] = 1 ;
V_501 = V_284 -> V_286 + V_500 ;
V_501 -> V_155 [ V_347 ] = V_80 /
V_502 [ V_500 ] ;
V_80 += V_501 -> V_80 ;
}
}
}
F_456 () ;
}
static void F_459 ( void )
{
unsigned long V_503 = V_504 >> ( V_379 - 10 ) ;
unsigned long V_505 = 0 ;
struct V_11 * V_11 ;
unsigned long V_59 ;
F_460 (zone) {
if ( ! F_461 ( V_11 ) )
V_505 += V_11 -> V_80 ;
}
F_460 (zone) {
T_19 V_291 ;
F_148 ( & V_11 -> V_67 , V_59 ) ;
V_291 = ( T_19 ) V_503 * V_11 -> V_80 ;
F_462 ( V_291 , V_505 ) ;
if ( F_461 ( V_11 ) ) {
unsigned long V_506 ;
V_506 = V_11 -> V_80 / 1024 ;
V_506 = F_398 ( V_506 , V_507 , 128UL ) ;
V_11 -> V_124 [ V_508 ] = V_506 ;
} else {
V_11 -> V_124 [ V_508 ] = V_291 ;
}
V_11 -> V_124 [ V_509 ] = F_298 ( V_11 ) + ( V_291 >> 2 ) ;
V_11 -> V_124 [ V_510 ] = F_298 ( V_11 ) + ( V_291 >> 1 ) ;
F_83 ( V_11 , V_131 ,
F_245 ( V_11 ) -
F_168 ( V_11 ) -
F_187 ( V_11 , V_131 ) ) ;
F_350 ( V_11 ) ;
F_156 ( & V_11 -> V_67 , V_59 ) ;
}
F_456 () ;
}
void F_463 ( void )
{
F_311 ( & V_336 ) ;
F_459 () ;
F_314 ( & V_336 ) ;
}
static void T_14 F_464 ( struct V_11 * V_11 )
{
unsigned int V_511 , V_512 ;
V_511 = V_11 -> V_80 >> ( 30 - V_379 ) ;
if ( V_511 )
V_512 = F_465 ( 10 * V_511 ) ;
else
V_512 = 1 ;
V_11 -> V_513 = V_512 ;
}
static void T_14 F_466 ( void )
{
struct V_11 * V_11 ;
F_460 (zone)
F_464 ( V_11 ) ;
}
int T_14 F_467 ( void )
{
unsigned long V_514 ;
int V_515 ;
V_514 = F_283 () * ( V_77 >> 10 ) ;
V_515 = F_465 ( V_514 * 16 ) ;
if ( V_515 > V_516 ) {
V_504 = V_515 ;
if ( V_504 < 128 )
V_504 = 128 ;
if ( V_504 > 65536 )
V_504 = 65536 ;
} else {
F_217 ( L_93 ,
V_515 , V_516 ) ;
}
F_463 () ;
F_468 () ;
F_458 () ;
F_466 () ;
return 0 ;
}
int F_469 ( T_10 * V_327 , int V_328 ,
void T_11 * V_329 , T_8 * V_330 , T_12 * V_331 )
{
F_470 ( V_327 , V_328 , V_329 , V_330 , V_331 ) ;
if ( V_328 ) {
V_516 = V_504 ;
F_463 () ;
}
return 0 ;
}
int F_471 ( T_10 * V_327 , int V_328 ,
void T_11 * V_329 , T_8 * V_330 , T_12 * V_331 )
{
struct V_11 * V_11 ;
int V_517 ;
V_517 = F_472 ( V_327 , V_328 , V_329 , V_330 , V_331 ) ;
if ( V_517 )
return V_517 ;
F_460 (zone)
V_11 -> V_433 = ( V_11 -> V_80 *
V_434 ) / 100 ;
return 0 ;
}
int F_473 ( T_10 * V_327 , int V_328 ,
void T_11 * V_329 , T_8 * V_330 , T_12 * V_331 )
{
struct V_11 * V_11 ;
int V_517 ;
V_517 = F_472 ( V_327 , V_328 , V_329 , V_330 , V_331 ) ;
if ( V_517 )
return V_517 ;
F_460 (zone)
V_11 -> V_435 = ( V_11 -> V_80 *
V_436 ) / 100 ;
return 0 ;
}
int F_474 ( T_10 * V_327 , int V_328 ,
void T_11 * V_329 , T_8 * V_330 , T_12 * V_331 )
{
F_472 ( V_327 , V_328 , V_329 , V_330 , V_331 ) ;
F_458 () ;
return 0 ;
}
int F_475 ( T_10 * V_327 , int V_328 ,
void T_11 * V_329 , T_8 * V_330 , T_12 * V_331 )
{
struct V_11 * V_11 ;
unsigned int V_112 ;
int V_12 ;
V_12 = F_472 ( V_327 , V_328 , V_329 , V_330 , V_331 ) ;
if ( ! V_328 || ( V_12 < 0 ) )
return V_12 ;
F_311 ( & V_518 ) ;
F_137 (zone) {
unsigned long V_85 ;
V_85 = V_11 -> V_80 / V_380 ;
F_332 (cpu)
F_371 ( F_138 ( V_11 -> V_115 , V_112 ) ,
V_85 ) ;
}
F_314 ( & V_518 ) ;
return 0 ;
}
static int T_2 F_476 ( char * V_133 )
{
if ( ! V_133 )
return 0 ;
V_519 = F_477 ( V_133 , & V_133 , 0 ) ;
return 1 ;
}
void * T_2 F_478 ( const char * V_520 ,
unsigned long V_521 ,
unsigned long V_522 ,
int V_523 ,
int V_59 ,
unsigned int * V_524 ,
unsigned int * V_525 ,
unsigned long V_526 ,
unsigned long V_527 )
{
unsigned long long F_345 = V_527 ;
unsigned long V_528 , V_87 ;
void * V_327 = NULL ;
if ( ! V_522 ) {
V_522 = V_431 ;
if ( V_379 < 20 )
V_522 = F_479 ( V_522 , ( 1 << 20 ) / V_77 ) ;
if ( V_523 > V_379 )
V_522 >>= ( V_523 - V_379 ) ;
else
V_522 <<= ( V_379 - V_523 ) ;
if ( F_7 ( V_59 & V_529 ) ) {
F_2 ( ! ( V_59 & V_530 ) ) ;
if ( ! ( V_522 >> * V_524 ) ) {
V_522 = 1UL << * V_524 ;
F_120 ( ! V_522 ) ;
}
} else if ( F_7 ( ( V_522 * V_521 ) < V_77 ) )
V_522 = V_77 / V_521 ;
}
V_522 = F_480 ( V_522 ) ;
if ( F_345 == 0 ) {
F_345 = ( ( unsigned long long ) V_432 << V_379 ) >> 4 ;
F_462 ( F_345 , V_521 ) ;
}
F_345 = V_154 ( F_345 , 0x80000000ULL ) ;
if ( V_522 < V_526 )
V_522 = V_526 ;
if ( V_522 > F_345 )
V_522 = F_345 ;
V_528 = F_481 ( V_522 ) ;
do {
V_87 = V_521 << V_528 ;
if ( V_59 & V_530 )
V_327 = F_482 ( V_87 ) ;
else if ( V_519 )
V_327 = F_483 ( V_87 , V_531 , V_532 ) ;
else {
if ( F_278 ( V_87 ) < V_40 ) {
V_327 = F_277 ( V_87 , V_531 ) ;
F_484 ( V_327 , V_87 , 1 , V_531 ) ;
}
}
} while ( ! V_327 && V_87 > V_77 && -- V_528 );
if ( ! V_327 )
F_485 ( L_94 , V_520 ) ;
F_23 ( V_43 L_95 ,
V_520 ,
( 1UL << V_528 ) ,
F_481 ( V_87 ) - V_379 ,
V_87 ) ;
if ( V_524 )
* V_524 = V_528 ;
if ( V_525 )
* V_525 = ( 1 << V_528 ) - 1 ;
return V_327 ;
}
static inline unsigned long * F_486 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef V_421
return F_487 ( V_14 ) -> V_418 ;
#else
return V_11 -> V_418 ;
#endif
}
static inline int F_488 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef V_421
V_14 &= ( V_533 - 1 ) ;
return ( V_14 >> V_83 ) * V_417 ;
#else
V_14 = V_14 - F_489 ( V_11 -> V_17 , V_81 ) ;
return ( V_14 >> V_83 ) * V_417 ;
#endif
}
unsigned long F_490 ( struct V_5 * V_5 ,
int V_534 , int V_535 )
{
struct V_11 * V_11 ;
unsigned long * V_536 ;
unsigned long V_14 , V_537 ;
unsigned long V_59 = 0 ;
unsigned long V_538 = 1 ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_536 = F_486 ( V_11 , V_14 ) ;
V_537 = F_488 ( V_11 , V_14 ) ;
for (; V_534 <= V_535 ; V_534 ++ , V_538 <<= 1 )
if ( F_195 ( V_537 + V_534 , V_536 ) )
V_59 |= V_538 ;
return V_59 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_59 ,
int V_534 , int V_535 )
{
struct V_11 * V_11 ;
unsigned long * V_536 ;
unsigned long V_14 , V_537 ;
unsigned long V_538 = 1 ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_536 = F_486 ( V_11 , V_14 ) ;
V_537 = F_488 ( V_11 , V_14 ) ;
F_42 ( ! F_12 ( V_11 , V_14 ) ) ;
for (; V_534 <= V_535 ; V_534 ++ , V_538 <<= 1 )
if ( V_59 & V_538 )
F_48 ( V_537 + V_534 , V_536 ) ;
else
F_50 ( V_537 + V_534 , V_536 ) ;
}
bool F_491 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_62 ,
bool V_539 )
{
unsigned long V_14 , V_540 , V_541 ;
int V_73 ;
if ( F_207 ( V_11 ) == V_396 )
return false ;
V_73 = F_100 ( V_5 ) ;
if ( V_73 == V_122 || F_84 ( V_73 ) )
return false ;
V_14 = F_10 ( V_5 ) ;
for ( V_541 = 0 , V_540 = 0 ; V_540 < V_81 ; V_540 ++ ) {
unsigned long V_542 = V_14 + V_540 ;
if ( ! F_16 ( V_542 ) )
continue;
V_5 = F_125 ( V_542 ) ;
if ( F_492 ( V_5 ) ) {
V_540 = F_479 ( V_540 + 1 , 1 << F_30 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_72 ( & V_5 -> V_58 ) ) {
if ( F_62 ( V_5 ) )
V_540 += ( 1 << F_60 ( V_5 ) ) - 1 ;
continue;
}
if ( V_539 && F_20 ( V_5 ) )
continue;
if ( ! F_493 ( V_5 ) )
V_541 ++ ;
if ( V_541 > V_62 )
return true ;
}
return false ;
}
bool F_494 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_330 ( F_121 ( V_5 ) ) )
return false ;
V_11 = F_17 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_11 , V_14 ) )
return false ;
return ! F_491 ( V_11 , V_5 , 0 , true ) ;
}
static unsigned long F_495 ( unsigned long V_14 )
{
return V_14 & ~ ( F_496 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_497 ( unsigned long V_14 )
{
return F_417 ( V_14 , F_496 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_498 ( struct V_543 * V_544 ,
unsigned long V_440 , unsigned long V_267 )
{
unsigned long V_545 ;
unsigned long V_14 = V_440 ;
unsigned int V_546 = 0 ;
int V_12 = 0 ;
F_499 () ;
while ( V_14 < V_267 || ! F_77 ( & V_544 -> V_547 ) ) {
if ( F_500 ( V_26 ) ) {
V_12 = - V_548 ;
break;
}
if ( F_77 ( & V_544 -> V_547 ) ) {
V_544 -> V_549 = 0 ;
V_14 = F_501 ( V_544 -> V_11 , V_544 ,
V_14 , V_267 , true ) ;
if ( ! V_14 ) {
V_12 = - V_548 ;
break;
}
V_546 = 0 ;
} else if ( ++ V_546 == 5 ) {
V_12 = V_12 < 0 ? V_12 : - V_550 ;
break;
}
V_545 = F_502 ( V_544 -> V_11 ,
& V_544 -> V_547 ) ;
V_544 -> V_549 -= V_545 ;
V_12 = F_503 ( & V_544 -> V_547 , V_551 ,
0 , V_552 , V_553 ) ;
}
if ( V_12 < 0 ) {
F_504 ( & V_544 -> V_547 ) ;
return V_12 ;
}
return 0 ;
}
int F_505 ( unsigned long V_440 , unsigned long V_267 ,
unsigned V_6 )
{
unsigned long V_554 , V_555 ;
int V_12 = 0 , V_30 ;
struct V_543 V_544 = {
. V_549 = 0 ,
. V_30 = - 1 ,
. V_11 = F_17 ( F_125 ( V_440 ) ) ,
. V_556 = true ,
. V_557 = true ,
} ;
F_113 ( & V_544 . V_547 ) ;
V_12 = F_506 ( F_495 ( V_440 ) ,
F_497 ( V_267 ) , V_6 ,
false ) ;
if ( V_12 )
return V_12 ;
V_12 = F_498 ( & V_544 , V_440 , V_267 ) ;
if ( V_12 )
goto V_558;
F_507 () ;
F_141 () ;
V_30 = 0 ;
V_554 = V_440 ;
while ( ! F_62 ( F_125 ( V_554 ) ) ) {
if ( ++ V_30 >= V_40 ) {
V_12 = - V_550 ;
goto V_558;
}
V_554 &= ~ 0UL << V_30 ;
}
if ( F_508 ( V_554 , V_267 , false ) ) {
F_217 ( L_96 ,
V_554 , V_267 ) ;
V_12 = - V_550 ;
goto V_558;
}
V_555 = F_509 ( & V_544 , V_554 , V_267 ) ;
if ( ! V_555 ) {
V_12 = - V_550 ;
goto V_558;
}
if ( V_440 != V_554 )
F_510 ( V_554 , V_440 - V_554 ) ;
if ( V_267 != V_555 )
F_510 ( V_267 , V_555 - V_267 ) ;
V_558:
F_511 ( F_495 ( V_440 ) ,
F_497 ( V_267 ) , V_6 ) ;
return V_12 ;
}
void F_510 ( unsigned long V_14 , unsigned V_32 )
{
unsigned int V_62 = 0 ;
for (; V_32 -- ; V_14 ++ ) {
struct V_5 * V_5 = F_125 ( V_14 ) ;
V_62 += F_61 ( V_5 ) != 1 ;
F_512 ( V_5 ) ;
}
F_513 ( V_62 != 0 , L_97 , V_62 ) ;
}
void T_14 F_514 ( struct V_11 * V_11 )
{
unsigned V_112 ;
F_311 ( & V_518 ) ;
F_332 (cpu)
F_372 ( V_11 ,
F_138 ( V_11 -> V_115 , V_112 ) ) ;
F_314 ( & V_518 ) ;
}
void F_515 ( struct V_11 * V_11 )
{
unsigned long V_59 ;
int V_112 ;
struct V_113 * V_114 ;
F_98 ( V_59 ) ;
if ( V_11 -> V_115 != & V_364 ) {
F_142 (cpu) {
V_114 = F_138 ( V_11 -> V_115 , V_112 ) ;
F_516 ( V_11 , V_114 ) ;
}
F_517 ( V_11 -> V_115 ) ;
V_11 -> V_115 = & V_364 ;
}
F_102 ( V_59 ) ;
}
void
F_518 ( unsigned long V_16 , unsigned long V_95 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_30 , V_31 ;
unsigned long V_14 ;
unsigned long V_59 ;
for ( V_14 = V_16 ; V_14 < V_95 ; V_14 ++ )
if ( F_150 ( V_14 ) )
break;
if ( V_14 == V_95 )
return;
V_11 = F_17 ( F_125 ( V_14 ) ) ;
F_148 ( & V_11 -> V_67 , V_59 ) ;
V_14 = V_16 ;
while ( V_14 < V_95 ) {
if ( ! F_150 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_125 ( V_14 ) ;
if ( F_7 ( ! F_62 ( V_5 ) && F_20 ( V_5 ) ) ) {
V_14 ++ ;
F_358 ( V_5 ) ;
continue;
}
F_120 ( F_61 ( V_5 ) ) ;
F_120 ( ! F_62 ( V_5 ) ) ;
V_30 = F_60 ( V_5 ) ;
#ifdef F_519
F_23 ( V_43 L_98 ,
V_14 , 1 << V_30 , V_95 ) ;
#endif
F_67 ( & V_5 -> V_51 ) ;
F_54 ( V_5 ) ;
V_11 -> V_52 [ V_30 ] . V_53 -- ;
for ( V_31 = 0 ; V_31 < ( 1 << V_30 ) ; V_31 ++ )
F_358 ( ( V_5 + V_31 ) ) ;
V_14 += ( 1 << V_30 ) ;
}
F_156 ( & V_11 -> V_67 , V_59 ) ;
}
bool F_520 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_17 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_59 ;
int V_30 ;
F_148 ( & V_11 -> V_67 , V_59 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
struct V_5 * V_559 = V_5 - ( V_14 & ( ( 1 << V_30 ) - 1 ) ) ;
if ( F_62 ( V_559 ) && F_60 ( V_559 ) >= V_30 )
break;
}
F_156 ( & V_11 -> V_67 , V_59 ) ;
return V_30 < V_40 ;
}
static void F_521 ( unsigned long V_59 )
{
const char * V_560 = L_92 ;
unsigned long V_449 ;
int V_31 ;
F_210 ( F_522 ( V_561 ) != V_562 ) ;
F_23 ( V_24 L_99 , V_59 ) ;
V_59 &= ( 1UL << V_563 ) - 1 ;
for ( V_31 = 0 ; V_31 < F_522 ( V_561 ) && V_59 ; V_31 ++ ) {
V_449 = V_561 [ V_31 ] . V_449 ;
if ( ( V_59 & V_449 ) != V_449 )
continue;
V_59 &= ~ V_449 ;
F_23 ( L_100 , V_560 , V_561 [ V_31 ] . V_292 ) ;
V_560 = L_101 ;
}
if ( V_59 )
F_23 ( L_102 , V_560 , V_59 ) ;
F_23 ( L_103 ) ;
}
void F_24 ( struct V_5 * V_5 )
{
F_23 ( V_24
L_104 ,
V_5 , F_72 ( & V_5 -> V_58 ) , F_71 ( V_5 ) ,
V_5 -> V_57 , V_5 -> V_564 ) ;
F_521 ( V_5 -> V_59 ) ;
F_523 ( V_5 ) ;
}
