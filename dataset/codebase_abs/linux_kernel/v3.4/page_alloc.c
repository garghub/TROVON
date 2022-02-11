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
int V_107 ;
struct V_108 * V_64 ;
struct V_11 * V_11 ;
static T_4 V_112 ;
F_133 (cpu) {
bool V_113 = false ;
F_128 (zone) {
V_64 = F_129 ( V_11 -> V_110 , V_107 ) ;
if ( V_64 -> V_64 . V_62 ) {
V_113 = true ;
break;
}
}
if ( V_113 )
F_134 ( V_107 , & V_112 ) ;
else
F_135 ( V_107 , & V_112 ) ;
}
F_136 ( & V_112 , F_130 , NULL , 1 ) ;
}
void F_137 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_114 ;
unsigned long V_59 ;
int V_27 , V_115 ;
struct V_70 * V_116 ;
if ( ! V_11 -> V_16 )
return;
F_138 ( & V_11 -> V_67 , V_59 ) ;
V_114 = V_11 -> V_15 + V_11 -> V_16 ;
for ( V_14 = V_11 -> V_15 ; V_14 < V_114 ; V_14 ++ )
if ( F_139 ( V_14 ) ) {
struct V_5 * V_5 = F_118 ( V_14 ) ;
if ( ! F_140 ( V_5 ) )
F_141 ( V_5 ) ;
}
F_142 (order, t) {
F_143 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_28 ;
V_14 = F_10 ( F_78 ( V_116 , struct V_5 , V_49 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1UL << V_27 ) ; V_28 ++ )
F_144 ( F_118 ( V_14 + V_28 ) ) ;
}
}
F_145 ( & V_11 -> V_67 , V_59 ) ;
}
void F_146 ( struct V_5 * V_5 , int V_104 )
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
if ( F_7 ( V_6 == V_117 ) ) {
F_82 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_21;
}
V_6 = V_118 ;
}
V_64 = & F_147 ( V_11 -> V_110 ) -> V_64 ;
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
void F_148 ( struct V_70 * V_71 , int V_104 )
{
struct V_5 * V_5 , * V_86 ;
F_149 (page, next, list, lru) {
F_150 ( V_5 , V_104 ) ;
F_146 ( V_5 , V_104 ) ;
}
}
void F_151 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
F_41 ( F_63 ( V_5 ) ) ;
F_41 ( ! F_60 ( V_5 ) ) ;
#ifdef F_152
if ( F_153 ( V_5 ) )
F_151 ( F_154 ( V_5 [ 0 ] . V_119 ) , V_27 ) ;
#endif
for ( V_28 = 1 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_101 ( V_5 + V_28 ) ;
}
int F_155 ( struct V_5 * V_5 )
{
unsigned int V_27 ;
unsigned long V_120 ;
struct V_11 * V_11 ;
F_113 ( ! F_61 ( V_5 ) ) ;
V_11 = F_15 ( V_5 ) ;
V_27 = F_59 ( V_5 ) ;
V_120 = F_156 ( V_11 ) + ( 1 << V_27 ) ;
if ( ! F_157 ( V_11 , 0 , V_120 , 0 , 0 ) )
return 0 ;
F_65 ( & V_5 -> V_49 ) ;
V_11 -> V_50 [ V_27 ] . V_51 -- ;
F_53 ( V_5 ) ;
F_64 ( V_11 , V_48 , - ( 1UL << V_27 ) ) ;
F_101 ( V_5 ) ;
F_151 ( V_5 , V_27 ) ;
if ( V_27 >= V_96 - 1 ) {
struct V_5 * V_121 = V_5 + ( 1 << V_27 ) - 1 ;
for (; V_5 < V_121 ; V_5 += V_92 )
F_6 ( V_5 , V_118 ) ;
}
return 1 << V_27 ;
}
static inline
struct V_5 * F_158 ( struct V_11 * V_122 ,
struct V_11 * V_11 , int V_27 , T_1 V_33 ,
int V_6 )
{
unsigned long V_59 ;
struct V_5 * V_5 ;
int V_104 = ! ! ( V_33 & V_123 ) ;
V_124:
if ( F_125 ( V_27 == 0 ) ) {
struct V_63 * V_64 ;
struct V_70 * V_71 ;
F_94 ( V_59 ) ;
V_64 = & F_147 ( V_11 -> V_110 ) -> V_64 ;
V_71 = & V_64 -> V_73 [ V_6 ] ;
if ( F_77 ( V_71 ) ) {
V_64 -> V_62 += F_124 ( V_11 , 0 ,
V_64 -> V_106 , V_71 ,
V_6 , V_104 ) ;
if ( F_7 ( F_77 ( V_71 ) ) )
goto V_125;
}
if ( V_104 )
V_5 = F_78 ( V_71 -> V_74 , struct V_5 , V_49 ) ;
else
V_5 = F_78 ( V_71 -> V_86 , struct V_5 , V_49 ) ;
F_65 ( & V_5 -> V_49 ) ;
V_64 -> V_62 -- ;
} else {
if ( F_7 ( V_33 & V_126 ) ) {
F_159 ( V_27 > 1 ) ;
}
F_138 ( & V_11 -> V_67 , V_59 ) ;
V_5 = F_122 ( V_11 , V_27 , V_6 ) ;
F_81 ( & V_11 -> V_67 ) ;
if ( ! V_5 )
goto V_125;
F_64 ( V_11 , V_48 , - ( 1 << V_27 ) ) ;
}
F_160 ( V_127 , V_11 , 1 << V_27 ) ;
F_161 ( V_122 , V_11 , V_33 ) ;
F_97 ( V_59 ) ;
F_41 ( F_16 ( V_11 , V_5 ) ) ;
if ( F_108 ( V_5 , V_27 , V_33 ) )
goto V_124;
return V_5 ;
V_125:
F_97 ( V_59 ) ;
return NULL ;
}
static int T_2 F_162 ( char * V_128 )
{
return F_163 ( & V_129 . V_130 , V_128 ) ;
}
static int F_164 ( T_1 V_131 , unsigned int V_27 )
{
if ( V_27 < V_129 . V_132 )
return 0 ;
if ( V_131 & V_126 )
return 0 ;
if ( V_129 . V_133 && ( V_131 & V_34 ) )
return 0 ;
if ( V_129 . V_134 && ( V_131 & V_135 ) )
return 0 ;
return F_165 ( & V_129 . V_130 , 1 << V_27 ) ;
}
static int T_2 F_166 ( void )
{
T_5 V_136 = V_137 | V_138 | V_139 ;
struct V_140 * V_141 ;
V_141 = F_167 ( L_5 , NULL ,
& V_129 . V_130 ) ;
if ( F_168 ( V_141 ) )
return F_169 ( V_141 ) ;
if ( ! F_170 ( L_6 , V_136 , V_141 ,
& V_129 . V_134 ) )
goto V_142;
if ( ! F_170 ( L_7 , V_136 , V_141 ,
& V_129 . V_133 ) )
goto V_142;
if ( ! F_171 ( L_8 , V_136 , V_141 ,
& V_129 . V_132 ) )
goto V_142;
return 0 ;
V_142:
F_172 ( V_141 ) ;
return - V_143 ;
}
static inline int F_164 ( T_1 V_131 , unsigned int V_27 )
{
return 0 ;
}
static bool F_173 ( struct V_11 * V_144 , int V_27 , unsigned long V_145 ,
int V_146 , int V_147 , long V_148 )
{
long V_149 = V_145 ;
int V_150 ;
V_148 -= ( 1 << V_27 ) - 1 ;
if ( V_147 & V_151 )
V_149 -= V_149 / 2 ;
if ( V_147 & V_152 )
V_149 -= V_149 / 4 ;
if ( V_148 <= V_149 + V_144 -> V_153 [ V_146 ] )
return false ;
for ( V_150 = 0 ; V_150 < V_27 ; V_150 ++ ) {
V_148 -= V_144 -> V_50 [ V_150 ] . V_51 << V_150 ;
V_149 >>= 1 ;
if ( V_148 <= V_149 )
return false ;
}
return true ;
}
bool F_157 ( struct V_11 * V_144 , int V_27 , unsigned long V_145 ,
int V_146 , int V_147 )
{
return F_173 ( V_144 , V_27 , V_145 , V_146 , V_147 ,
F_174 ( V_144 , V_48 ) ) ;
}
bool F_175 ( struct V_11 * V_144 , int V_27 , unsigned long V_145 ,
int V_146 , int V_147 )
{
long V_148 = F_174 ( V_144 , V_48 ) ;
if ( V_144 -> V_154 && V_148 < V_144 -> V_154 )
V_148 = F_176 ( V_144 , V_48 ) ;
return F_173 ( V_144 , V_27 , V_145 , V_146 , V_147 ,
V_148 ) ;
}
static T_6 * F_177 ( struct V_155 * V_155 , int V_147 )
{
struct V_156 * V_157 ;
T_6 * V_158 ;
V_157 = V_155 -> V_159 ;
if ( ! V_157 )
return NULL ;
if ( F_178 ( V_20 , V_157 -> V_160 + V_23 ) ) {
F_179 ( V_157 -> V_161 , V_162 ) ;
V_157 -> V_160 = V_20 ;
}
V_158 = ! F_42 () && ( V_147 & V_163 ) ?
& V_164 :
& V_165 [ V_166 ] ;
return V_158 ;
}
static int F_180 ( struct V_155 * V_155 , struct V_167 * V_144 ,
T_6 * V_158 )
{
struct V_156 * V_157 ;
int V_28 ;
int V_168 ;
V_157 = V_155 -> V_159 ;
if ( ! V_157 )
return 1 ;
V_28 = V_144 - V_155 -> V_169 ;
V_168 = V_157 -> V_170 [ V_28 ] ;
return F_181 ( V_168 , * V_158 ) && ! F_182 ( V_28 , V_157 -> V_161 ) ;
}
static void F_183 ( struct V_155 * V_155 , struct V_167 * V_144 )
{
struct V_156 * V_157 ;
int V_28 ;
V_157 = V_155 -> V_159 ;
if ( ! V_157 )
return;
V_28 = V_144 - V_155 -> V_169 ;
F_184 ( V_28 , V_157 -> V_161 ) ;
}
static void F_185 ( struct V_155 * V_155 )
{
struct V_156 * V_157 ;
V_157 = V_155 -> V_159 ;
if ( ! V_157 )
return;
F_179 ( V_157 -> V_161 , V_162 ) ;
}
static T_6 * F_177 ( struct V_155 * V_155 , int V_147 )
{
return NULL ;
}
static int F_180 ( struct V_155 * V_155 , struct V_167 * V_144 ,
T_6 * V_158 )
{
return 1 ;
}
static void F_183 ( struct V_155 * V_155 , struct V_167 * V_144 )
{
}
static void F_185 ( struct V_155 * V_155 )
{
}
static struct V_5 *
F_186 ( T_1 V_131 , T_6 * V_171 , unsigned int V_27 ,
struct V_155 * V_155 , int V_172 , int V_147 ,
struct V_11 * V_122 , int V_6 )
{
struct V_167 * V_144 ;
struct V_5 * V_5 = NULL ;
int V_146 ;
struct V_11 * V_11 ;
T_6 * V_158 = NULL ;
int V_173 = 0 ;
int V_174 = 0 ;
V_146 = F_187 ( V_122 ) ;
V_175:
F_188 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( V_176 && V_173 &&
! F_180 ( V_155 , V_144 , V_158 ) )
continue;
if ( ( V_147 & V_163 ) &&
! F_189 ( V_11 , V_131 ) )
continue;
if ( ( V_147 & V_177 ) &&
( V_131 & V_178 ) && ! F_190 ( V_11 ) )
goto V_179;
F_191 ( V_180 < V_181 ) ;
if ( ! ( V_147 & V_180 ) ) {
unsigned long V_145 ;
int V_12 ;
V_145 = V_11 -> V_120 [ V_147 & V_182 ] ;
if ( F_157 ( V_11 , V_27 , V_145 ,
V_146 , V_147 ) )
goto V_183;
if ( V_176 && ! V_174 && V_184 > 1 ) {
V_158 = F_177 ( V_155 , V_147 ) ;
V_173 = 1 ;
V_174 = 1 ;
}
if ( V_185 == 0 )
goto V_179;
if ( V_176 && V_173 &&
! F_180 ( V_155 , V_144 , V_158 ) )
continue;
V_12 = F_192 ( V_11 , V_131 , V_27 ) ;
switch ( V_12 ) {
case V_186 :
continue;
case V_187 :
continue;
default:
if ( ! F_157 ( V_11 , V_27 , V_145 ,
V_146 , V_147 ) )
goto V_179;
}
}
V_183:
V_5 = F_158 ( V_122 , V_11 , V_27 ,
V_131 , V_6 ) ;
if ( V_5 )
break;
V_179:
if ( V_176 )
F_183 ( V_155 , V_144 ) ;
}
if ( F_7 ( V_176 && V_5 == NULL && V_173 ) ) {
V_173 = 0 ;
goto V_175;
}
return V_5 ;
}
static inline bool F_193 ( void )
{
bool V_12 = false ;
#if V_188 > 8
V_12 = F_42 () ;
#endif
return V_12 ;
}
void F_194 ( T_1 V_131 , int V_27 , const char * V_189 , ... )
{
unsigned int V_190 = V_191 ;
if ( ( V_131 & V_192 ) || ! F_195 ( & V_193 ) ||
F_105 () > 0 )
return;
if ( ! ( V_131 & V_194 ) )
if ( F_196 ( V_195 ) ||
( V_24 -> V_59 & ( V_196 | V_197 ) ) )
V_190 &= ~ V_191 ;
if ( F_42 () || ! ( V_131 & V_135 ) )
V_190 &= ~ V_191 ;
if ( V_189 ) {
struct V_198 V_199 ;
T_7 args ;
va_start ( args , V_189 ) ;
V_199 . V_189 = V_189 ;
V_199 . V_200 = & args ;
F_197 ( L_9 , & V_199 ) ;
va_end ( args ) ;
}
F_197 ( L_10 ,
V_24 -> V_25 , V_27 , V_131 ) ;
F_24 () ;
if ( ! F_193 () )
F_198 ( V_190 ) ;
}
static inline int
F_199 ( T_1 V_131 , unsigned int V_27 ,
unsigned long V_201 ,
unsigned long V_202 )
{
if ( V_131 & V_203 )
return 0 ;
if ( V_131 & V_126 )
return 1 ;
if ( ! V_201 && F_5 () )
return 0 ;
if ( V_27 <= V_204 )
return 1 ;
if ( V_131 & V_205 && V_202 < ( 1 << V_27 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_200 ( T_1 V_131 , unsigned int V_27 ,
struct V_155 * V_155 , enum V_206 V_172 ,
T_6 * V_171 , struct V_11 * V_122 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_201 ( V_155 , V_131 ) ) {
F_202 ( 1 ) ;
return NULL ;
}
V_5 = F_186 ( V_131 | V_207 , V_171 ,
V_27 , V_155 , V_172 ,
V_208 | V_163 ,
V_122 , V_6 ) ;
if ( V_5 )
goto V_21;
if ( ! ( V_131 & V_126 ) ) {
if ( V_27 > V_204 )
goto V_21;
if ( V_172 < V_209 )
goto V_21;
if ( V_131 & V_210 )
goto V_21;
}
F_203 ( V_155 , V_131 , V_27 , V_171 , false ) ;
V_21:
F_204 ( V_155 , V_131 ) ;
return V_5 ;
}
static struct V_5 *
F_205 ( T_1 V_131 , unsigned int V_27 ,
struct V_155 * V_155 , enum V_206 V_172 ,
T_6 * V_171 , int V_147 , struct V_11 * V_122 ,
int V_6 , bool V_211 ,
bool * V_212 ,
unsigned long * V_201 )
{
struct V_5 * V_5 ;
if ( ! V_27 )
return NULL ;
if ( F_206 ( V_122 , V_27 ) ) {
* V_212 = true ;
return NULL ;
}
V_24 -> V_59 |= V_196 ;
* V_201 = F_207 ( V_155 , V_27 , V_131 ,
V_171 , V_211 ) ;
V_24 -> V_59 &= ~ V_196 ;
if ( * V_201 != V_213 ) {
F_127 ( F_208 () ) ;
F_209 () ;
V_5 = F_186 ( V_131 , V_171 ,
V_27 , V_155 , V_172 ,
V_147 , V_122 ,
V_6 ) ;
if ( V_5 ) {
V_122 -> V_214 = 0 ;
V_122 -> V_215 = 0 ;
if ( V_27 >= V_122 -> V_216 )
V_122 -> V_216 = V_27 + 1 ;
F_210 ( V_217 ) ;
return V_5 ;
}
F_210 ( V_218 ) ;
if ( V_211 )
F_211 ( V_122 , V_27 ) ;
F_212 () ;
}
return NULL ;
}
static inline struct V_5 *
F_205 ( T_1 V_131 , unsigned int V_27 ,
struct V_155 * V_155 , enum V_206 V_172 ,
T_6 * V_171 , int V_147 , struct V_11 * V_122 ,
int V_6 , bool V_211 ,
bool * V_212 ,
unsigned long * V_201 )
{
return NULL ;
}
static inline struct V_5 *
F_213 ( T_1 V_131 , unsigned int V_27 ,
struct V_155 * V_155 , enum V_206 V_172 ,
T_6 * V_171 , int V_147 , struct V_11 * V_122 ,
int V_6 , unsigned long * V_201 )
{
struct V_5 * V_5 = NULL ;
struct V_219 V_219 ;
bool V_220 = false ;
F_212 () ;
F_214 () ;
V_24 -> V_59 |= V_196 ;
F_215 ( V_131 ) ;
V_219 . V_221 = 0 ;
V_24 -> V_219 = & V_219 ;
* V_201 = F_216 ( V_155 , V_27 , V_131 , V_171 ) ;
V_24 -> V_219 = NULL ;
F_217 () ;
V_24 -> V_59 &= ~ V_196 ;
F_212 () ;
if ( F_7 ( ! ( * V_201 ) ) )
return NULL ;
if ( V_176 )
F_185 ( V_155 ) ;
V_222:
V_5 = F_186 ( V_131 , V_171 , V_27 ,
V_155 , V_172 ,
V_147 , V_122 ,
V_6 ) ;
if ( ! V_5 && ! V_220 ) {
F_132 () ;
V_220 = true ;
goto V_222;
}
return V_5 ;
}
static inline struct V_5 *
F_218 ( T_1 V_131 , unsigned int V_27 ,
struct V_155 * V_155 , enum V_206 V_172 ,
T_6 * V_171 , struct V_11 * V_122 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_186 ( V_131 , V_171 , V_27 ,
V_155 , V_172 , V_180 ,
V_122 , V_6 ) ;
if ( ! V_5 && V_131 & V_126 )
F_219 ( V_122 , V_223 , V_23 / 50 ) ;
} while ( ! V_5 && ( V_131 & V_126 ) );
return V_5 ;
}
static inline
void F_220 ( unsigned int V_27 , struct V_155 * V_155 ,
enum V_206 V_172 ,
enum V_206 V_146 )
{
struct V_167 * V_144 ;
struct V_11 * V_11 ;
F_221 (zone, z, zonelist, high_zoneidx)
F_222 ( V_11 , V_27 , V_146 ) ;
}
static inline int
F_223 ( T_1 V_131 )
{
int V_147 = V_224 | V_163 ;
const T_1 V_225 = V_131 & V_135 ;
F_191 ( V_226 != ( V_227 T_1 ) V_151 ) ;
V_147 |= ( V_227 int ) ( V_131 & V_226 ) ;
if ( ! V_225 ) {
if ( ! ( V_131 & V_194 ) )
V_147 |= V_152 ;
V_147 &= ~ V_163 ;
} else if ( F_7 ( F_224 ( V_24 ) ) && ! F_42 () )
V_147 |= V_152 ;
if ( F_125 ( ! ( V_131 & V_194 ) ) ) {
if ( ! F_42 () &&
( ( V_24 -> V_59 & V_196 ) ||
F_7 ( F_196 ( V_195 ) ) ) )
V_147 |= V_180 ;
}
return V_147 ;
}
static inline struct V_5 *
F_225 ( T_1 V_131 , unsigned int V_27 ,
struct V_155 * V_155 , enum V_206 V_172 ,
T_6 * V_171 , struct V_11 * V_122 ,
int V_6 )
{
const T_1 V_225 = V_131 & V_135 ;
struct V_5 * V_5 = NULL ;
int V_147 ;
unsigned long V_202 = 0 ;
unsigned long V_201 ;
bool V_211 = false ;
bool V_212 = false ;
if ( V_27 >= V_37 ) {
F_159 ( ! ( V_131 & V_192 ) ) ;
return NULL ;
}
if ( V_176 && ( V_131 & V_228 ) == V_228 )
goto V_229;
V_230:
if ( ! ( V_131 & V_231 ) )
F_220 ( V_27 , V_155 , V_172 ,
F_187 ( V_122 ) ) ;
V_147 = F_223 ( V_131 ) ;
if ( ! ( V_147 & V_163 ) && ! V_171 )
F_226 ( V_155 , V_172 , NULL ,
& V_122 ) ;
V_232:
V_5 = F_186 ( V_131 , V_171 , V_27 , V_155 ,
V_172 , V_147 & ~ V_180 ,
V_122 , V_6 ) ;
if ( V_5 )
goto V_233;
if ( V_147 & V_180 ) {
V_5 = F_218 ( V_131 , V_27 ,
V_155 , V_172 , V_171 ,
V_122 , V_6 ) ;
if ( V_5 )
goto V_233;
}
if ( ! V_225 )
goto V_229;
if ( V_24 -> V_59 & V_196 )
goto V_229;
if ( F_196 ( V_195 ) && ! ( V_131 & V_126 ) )
goto V_229;
V_5 = F_205 ( V_131 , V_27 ,
V_155 , V_172 ,
V_171 ,
V_147 , V_122 ,
V_6 , V_211 ,
& V_212 ,
& V_201 ) ;
if ( V_5 )
goto V_233;
V_211 = true ;
if ( V_212 && ( V_131 & V_231 ) )
goto V_229;
V_5 = F_213 ( V_131 , V_27 ,
V_155 , V_172 ,
V_171 ,
V_147 , V_122 ,
V_6 , & V_201 ) ;
if ( V_5 )
goto V_233;
if ( ! V_201 ) {
if ( ( V_131 & V_234 ) && ! ( V_131 & V_203 ) ) {
if ( V_235 )
goto V_229;
if ( ( V_24 -> V_59 & V_236 ) &&
! ( V_131 & V_126 ) )
goto V_229;
V_5 = F_200 ( V_131 , V_27 ,
V_155 , V_172 ,
V_171 , V_122 ,
V_6 ) ;
if ( V_5 )
goto V_233;
if ( ! ( V_131 & V_126 ) ) {
if ( V_27 > V_204 )
goto V_229;
if ( V_172 < V_209 )
goto V_229;
}
goto V_230;
}
}
V_202 += V_201 ;
if ( F_199 ( V_131 , V_27 , V_201 ,
V_202 ) ) {
F_219 ( V_122 , V_223 , V_23 / 50 ) ;
goto V_232;
} else {
V_5 = F_205 ( V_131 , V_27 ,
V_155 , V_172 ,
V_171 ,
V_147 , V_122 ,
V_6 , V_211 ,
& V_212 ,
& V_201 ) ;
if ( V_5 )
goto V_233;
}
V_229:
F_194 ( V_131 , V_27 , NULL ) ;
return V_5 ;
V_233:
if ( V_237 )
F_227 ( V_5 , V_27 , V_131 ) ;
return V_5 ;
}
struct V_5 *
F_228 ( T_1 V_131 , unsigned int V_27 ,
struct V_155 * V_155 , T_6 * V_171 )
{
enum V_206 V_172 = F_229 ( V_131 ) ;
struct V_11 * V_122 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_230 ( V_131 ) ;
unsigned int V_238 ;
V_131 &= V_3 ;
F_231 ( V_131 ) ;
F_232 ( V_131 & V_135 ) ;
if ( F_164 ( V_131 , V_27 ) )
return NULL ;
if ( F_7 ( ! V_155 -> V_169 -> V_11 ) )
return NULL ;
V_239:
V_238 = F_233 () ;
F_226 ( V_155 , V_172 ,
V_171 ? : & V_164 ,
& V_122 ) ;
if ( ! V_122 )
goto V_21;
V_5 = F_186 ( V_131 | V_207 , V_171 , V_27 ,
V_155 , V_172 , V_177 | V_163 ,
V_122 , V_6 ) ;
if ( F_7 ( ! V_5 ) )
V_5 = F_225 ( V_131 , V_27 ,
V_155 , V_172 , V_171 ,
V_122 , V_6 ) ;
F_234 ( V_5 , V_27 , V_131 , V_6 ) ;
V_21:
if ( F_7 ( ! F_235 ( V_238 ) && ! V_5 ) )
goto V_239;
return V_5 ;
}
unsigned long F_236 ( T_1 V_131 , unsigned int V_27 )
{
struct V_5 * V_5 ;
F_41 ( ( V_131 & V_34 ) != 0 ) ;
V_5 = F_237 ( V_131 , V_27 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_89 ( V_5 ) ;
}
unsigned long F_238 ( T_1 V_131 )
{
return F_236 ( V_131 | V_83 , 0 ) ;
}
void F_102 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( F_239 ( V_5 ) ) {
if ( V_27 == 0 )
F_146 ( V_5 , 0 ) ;
else
F_27 ( V_5 , V_27 ) ;
}
}
void V_148 ( unsigned long V_240 , unsigned int V_27 )
{
if ( V_240 != 0 ) {
F_41 ( ! F_240 ( ( void * ) V_240 ) ) ;
F_102 ( F_154 ( ( void * ) V_240 ) , V_27 ) ;
}
}
static void * F_241 ( unsigned long V_240 , unsigned V_27 , T_8 V_82 )
{
if ( V_240 ) {
unsigned long V_241 = V_240 + ( V_75 << V_27 ) ;
unsigned long V_242 = V_240 + F_242 ( V_82 ) ;
F_151 ( F_154 ( ( void * ) V_240 ) , V_27 ) ;
while ( V_242 < V_241 ) {
F_243 ( V_242 ) ;
V_242 += V_75 ;
}
}
return ( void * ) V_240 ;
}
void * F_244 ( T_8 V_82 , T_1 V_131 )
{
unsigned int V_27 = F_245 ( V_82 ) ;
unsigned long V_240 ;
V_240 = F_236 ( V_131 , V_27 ) ;
return F_241 ( V_240 , V_27 , V_82 ) ;
}
void * F_246 ( int V_243 , T_8 V_82 , T_1 V_131 )
{
unsigned V_27 = F_245 ( V_82 ) ;
struct V_5 * V_30 = F_247 ( V_243 , V_131 , V_27 ) ;
if ( ! V_30 )
return NULL ;
return F_241 ( ( unsigned long ) F_89 ( V_30 ) , V_27 , V_82 ) ;
}
void F_248 ( void * V_244 , T_8 V_82 )
{
unsigned long V_240 = ( unsigned long ) V_244 ;
unsigned long V_245 = V_240 + F_242 ( V_82 ) ;
while ( V_240 < V_245 ) {
F_243 ( V_240 ) ;
V_240 += V_75 ;
}
}
static unsigned int F_249 ( int V_246 )
{
struct V_167 * V_144 ;
struct V_11 * V_11 ;
unsigned int V_247 = 0 ;
struct V_155 * V_155 = F_250 ( F_251 () , V_248 ) ;
F_221 (zone, z, zonelist, offset) {
unsigned long V_82 = V_11 -> V_249 ;
unsigned long V_80 = F_252 ( V_11 ) ;
if ( V_82 > V_80 )
V_247 += V_82 - V_80 ;
}
return V_247 ;
}
unsigned int F_253 ( void )
{
return F_249 ( F_229 ( V_250 ) ) ;
}
unsigned int F_254 ( void )
{
return F_249 ( F_229 ( V_251 ) ) ;
}
static inline void F_255 ( struct V_11 * V_11 )
{
if ( V_176 )
F_21 ( L_11 , F_115 ( V_11 ) ) ;
}
void F_256 ( struct V_252 * V_253 )
{
V_253 -> V_254 = V_255 ;
V_253 -> V_256 = 0 ;
V_253 -> V_257 = F_257 ( V_48 ) ;
V_253 -> V_258 = F_258 () ;
V_253 -> V_259 = V_260 ;
V_253 -> V_261 = F_259 () ;
V_253 -> V_262 = V_75 ;
}
void F_260 ( struct V_252 * V_253 , int V_243 )
{
T_9 * V_263 = F_261 ( V_243 ) ;
V_253 -> V_254 = V_263 -> V_264 ;
V_253 -> V_257 = F_262 ( V_243 , V_48 ) ;
#ifdef F_263
V_253 -> V_259 = V_263 -> V_265 [ V_266 ] . V_249 ;
V_253 -> V_261 = F_174 ( & V_263 -> V_265 [ V_266 ] ,
V_48 ) ;
#else
V_253 -> V_259 = 0 ;
V_253 -> V_261 = 0 ;
#endif
V_253 -> V_262 = V_75 ;
}
bool F_264 ( unsigned int V_59 , int V_243 )
{
bool V_12 = false ;
unsigned int V_238 ;
if ( ! ( V_59 & V_191 ) )
goto V_21;
do {
V_238 = F_233 () ;
V_12 = ! F_181 ( V_243 , V_164 ) ;
} while ( ! F_235 ( V_238 ) );
V_21:
return V_12 ;
}
void F_265 ( unsigned int V_190 )
{
int V_107 ;
struct V_11 * V_11 ;
F_128 (zone) {
if ( F_264 ( V_190 , F_115 ( V_11 ) ) )
continue;
F_255 ( V_11 ) ;
F_21 ( L_12 , V_11 -> V_267 ) ;
F_133 (cpu) {
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
F_257 ( V_268 ) ,
F_257 ( V_269 ) ,
F_257 ( V_270 ) ,
F_257 ( V_271 ) ,
F_257 ( V_272 ) ,
F_257 ( V_273 ) ,
F_257 ( V_274 ) ,
F_257 ( V_275 ) ,
F_257 ( V_276 ) ,
F_257 ( V_277 ) ,
F_257 ( V_48 ) ,
F_257 ( V_278 ) ,
F_257 ( V_279 ) ,
F_257 ( V_280 ) ,
F_257 ( V_281 ) ,
F_257 ( V_282 ) ,
F_257 ( V_283 ) ) ;
F_128 (zone) {
int V_28 ;
if ( F_264 ( V_190 , F_115 ( V_11 ) ) )
continue;
F_255 ( V_11 ) ;
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
V_11 -> V_267 ,
F_266 ( F_174 ( V_11 , V_48 ) ) ,
F_266 ( F_267 ( V_11 ) ) ,
F_266 ( F_156 ( V_11 ) ) ,
F_266 ( F_252 ( V_11 ) ) ,
F_266 ( F_174 ( V_11 , V_268 ) ) ,
F_266 ( F_174 ( V_11 , V_269 ) ) ,
F_266 ( F_174 ( V_11 , V_271 ) ) ,
F_266 ( F_174 ( V_11 , V_272 ) ) ,
F_266 ( F_174 ( V_11 , V_274 ) ) ,
F_266 ( F_174 ( V_11 , V_270 ) ) ,
F_266 ( F_174 ( V_11 , V_273 ) ) ,
F_266 ( V_11 -> V_249 ) ,
F_266 ( F_174 ( V_11 , V_55 ) ) ,
F_266 ( F_174 ( V_11 , V_275 ) ) ,
F_266 ( F_174 ( V_11 , V_276 ) ) ,
F_266 ( F_174 ( V_11 , V_280 ) ) ,
F_266 ( F_174 ( V_11 , V_281 ) ) ,
F_266 ( F_174 ( V_11 , V_278 ) ) ,
F_266 ( F_174 ( V_11 , V_279 ) ) ,
F_174 ( V_11 , V_284 ) *
V_285 / 1024 ,
F_266 ( F_174 ( V_11 , V_282 ) ) ,
F_266 ( F_174 ( V_11 , V_277 ) ) ,
F_266 ( F_174 ( V_11 , V_283 ) ) ,
F_266 ( F_174 ( V_11 , V_286 ) ) ,
V_11 -> V_69 ,
( V_11 -> V_68 ? L_48 : L_49 )
) ;
F_21 ( L_50 ) ;
for ( V_28 = 0 ; V_28 < V_287 ; V_28 ++ )
F_21 ( L_51 , V_11 -> V_153 [ V_28 ] ) ;
F_21 ( L_47 ) ;
}
F_128 (zone) {
unsigned long V_288 [ V_37 ] , V_59 , V_27 , V_289 = 0 ;
if ( F_264 ( V_190 , F_115 ( V_11 ) ) )
continue;
F_255 ( V_11 ) ;
F_21 ( L_52 , V_11 -> V_267 ) ;
F_138 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
V_288 [ V_27 ] = V_11 -> V_50 [ V_27 ] . V_51 ;
V_289 += V_288 [ V_27 ] << V_27 ;
}
F_145 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ )
F_21 ( L_53 , V_288 [ V_27 ] , F_266 ( 1UL ) << V_27 ) ;
F_21 ( L_54 , F_266 ( V_289 ) ) ;
}
F_21 ( L_55 , F_257 ( V_290 ) ) ;
F_268 () ;
}
static void F_269 ( struct V_11 * V_11 , struct V_167 * V_167 )
{
V_167 -> V_11 = V_11 ;
V_167 -> F_187 = F_187 ( V_11 ) ;
}
static int F_270 ( T_9 * V_263 , struct V_155 * V_155 ,
int V_291 , enum V_206 V_206 )
{
struct V_11 * V_11 ;
F_113 ( V_206 >= V_287 ) ;
V_206 ++ ;
do {
V_206 -- ;
V_11 = V_263 -> V_265 + V_206 ;
if ( F_271 ( V_11 ) ) {
F_269 ( V_11 ,
& V_155 -> V_169 [ V_291 ++ ] ) ;
F_272 ( V_206 ) ;
}
} while ( V_206 );
return V_291 ;
}
static int F_273 ( char * V_292 )
{
if ( * V_292 == 'd' || * V_292 == 'D' ) {
V_293 = V_294 ;
} else if ( * V_292 == 'n' || * V_292 == 'N' ) {
V_293 = V_295 ;
} else if ( * V_292 == 'z' || * V_292 == 'Z' ) {
V_293 = V_296 ;
} else {
F_21 ( V_297
L_56
L_57 , V_292 ) ;
return - V_298 ;
}
return 0 ;
}
static T_2 int F_274 ( char * V_292 )
{
int V_12 ;
if ( ! V_292 )
return 0 ;
V_12 = F_273 ( V_292 ) ;
if ( V_12 == 0 )
F_275 ( V_299 , V_292 , V_300 ) ;
return V_12 ;
}
int F_276 ( T_10 * V_301 , int V_302 ,
void T_11 * V_303 , T_8 * V_304 ,
T_12 * V_305 )
{
char V_306 [ V_300 ] ;
int V_12 ;
static F_277 ( V_307 ) ;
F_278 ( & V_307 ) ;
if ( V_302 )
strcpy ( V_306 , ( char * ) V_301 -> V_308 ) ;
V_12 = F_279 ( V_301 , V_302 , V_303 , V_304 , V_305 ) ;
if ( V_12 )
goto V_21;
if ( V_302 ) {
int V_309 = V_293 ;
if ( F_273 ( ( char * ) V_301 -> V_308 ) ) {
strncpy ( ( char * ) V_301 -> V_308 , V_306 ,
V_300 ) ;
V_293 = V_309 ;
} else if ( V_309 != V_293 ) {
F_278 ( & V_310 ) ;
F_280 ( NULL ) ;
F_281 ( & V_310 ) ;
}
}
V_21:
F_281 ( & V_307 ) ;
return V_12 ;
}
static int F_282 ( int V_311 , T_6 * V_312 )
{
int V_168 , V_253 ;
int V_313 = V_314 ;
int V_315 = - 1 ;
const struct V_316 * V_317 = F_283 ( 0 ) ;
if ( ! F_181 ( V_311 , * V_312 ) ) {
F_284 ( V_311 , * V_312 ) ;
return V_311 ;
}
F_285 (n, N_HIGH_MEMORY) {
if ( F_181 ( V_168 , * V_312 ) )
continue;
V_253 = F_286 ( V_311 , V_168 ) ;
V_253 += ( V_168 < V_311 ) ;
V_317 = F_283 ( V_168 ) ;
if ( ! F_287 ( V_317 ) )
V_253 += V_318 ;
V_253 *= ( V_319 * V_320 ) ;
V_253 += V_321 [ V_168 ] ;
if ( V_253 < V_313 ) {
V_313 = V_253 ;
V_315 = V_168 ;
}
}
if ( V_315 >= 0 )
F_284 ( V_315 , * V_312 ) ;
return V_315 ;
}
static void F_288 ( T_9 * V_263 , int V_311 )
{
int V_322 ;
struct V_155 * V_155 ;
V_155 = & V_263 -> V_323 [ 0 ] ;
for ( V_322 = 0 ; V_155 -> V_169 [ V_322 ] . V_11 != NULL ; V_322 ++ )
;
V_322 = F_270 ( F_261 ( V_311 ) , V_155 , V_322 ,
V_287 - 1 ) ;
V_155 -> V_169 [ V_322 ] . V_11 = NULL ;
V_155 -> V_169 [ V_322 ] . F_187 = 0 ;
}
static void F_289 ( T_9 * V_263 )
{
int V_322 ;
struct V_155 * V_155 ;
V_155 = & V_263 -> V_323 [ 1 ] ;
V_322 = F_270 ( V_263 , V_155 , 0 , V_287 - 1 ) ;
V_155 -> V_169 [ V_322 ] . V_11 = NULL ;
V_155 -> V_169 [ V_322 ] . F_187 = 0 ;
}
static void F_290 ( T_9 * V_263 , int V_324 )
{
int V_325 , V_322 , V_311 ;
int V_206 ;
struct V_11 * V_144 ;
struct V_155 * V_155 ;
V_155 = & V_263 -> V_323 [ 0 ] ;
V_325 = 0 ;
for ( V_206 = V_287 - 1 ; V_206 >= 0 ; V_206 -- ) {
for ( V_322 = 0 ; V_322 < V_324 ; V_322 ++ ) {
V_311 = V_326 [ V_322 ] ;
V_144 = & F_261 ( V_311 ) -> V_265 [ V_206 ] ;
if ( F_271 ( V_144 ) ) {
F_269 ( V_144 ,
& V_155 -> V_169 [ V_325 ++ ] ) ;
F_272 ( V_206 ) ;
}
}
}
V_155 -> V_169 [ V_325 ] . V_11 = NULL ;
V_155 -> V_169 [ V_325 ] . F_187 = 0 ;
}
static int F_291 ( void )
{
int V_243 , V_206 ;
unsigned long V_327 , V_328 ;
struct V_11 * V_144 ;
int V_329 ;
V_327 = 0 ;
V_328 = 0 ;
F_292 (nid) {
for ( V_206 = 0 ; V_206 < V_287 ; V_206 ++ ) {
V_144 = & F_261 ( V_243 ) -> V_265 [ V_206 ] ;
if ( F_271 ( V_144 ) ) {
if ( V_206 < V_209 )
V_327 += V_144 -> V_249 ;
V_328 += V_144 -> V_249 ;
} else if ( V_206 == V_209 ) {
return V_295 ;
}
}
}
if ( ! V_327 ||
V_327 > V_328 / 2 )
return V_295 ;
V_329 = V_328 /
( F_293 ( V_165 [ V_166 ] ) + 1 ) ;
F_292 (nid) {
V_327 = 0 ;
V_328 = 0 ;
for ( V_206 = 0 ; V_206 < V_287 ; V_206 ++ ) {
V_144 = & F_261 ( V_243 ) -> V_265 [ V_206 ] ;
if ( F_271 ( V_144 ) ) {
if ( V_206 < V_209 )
V_327 += V_144 -> V_249 ;
V_328 += V_144 -> V_249 ;
}
}
if ( V_327 &&
V_328 > V_329 &&
V_327 > V_328 * 70 / 100 )
return V_295 ;
}
return V_296 ;
}
static void F_294 ( void )
{
if ( V_293 == V_294 )
V_330 = F_291 () ;
else
V_330 = V_293 ;
}
static void F_295 ( T_9 * V_263 )
{
int V_322 , V_311 , V_331 ;
enum V_206 V_28 ;
T_6 V_332 ;
int V_333 , V_334 ;
struct V_155 * V_155 ;
int V_27 = V_330 ;
for ( V_28 = 0 ; V_28 < V_335 ; V_28 ++ ) {
V_155 = V_263 -> V_323 + V_28 ;
V_155 -> V_169 [ 0 ] . V_11 = NULL ;
V_155 -> V_169 [ 0 ] . F_187 = 0 ;
}
V_333 = V_263 -> V_336 ;
V_331 = V_184 ;
V_334 = V_333 ;
F_296 ( V_332 ) ;
memset ( V_326 , 0 , sizeof( V_326 ) ) ;
V_322 = 0 ;
while ( ( V_311 = F_282 ( V_333 , & V_332 ) ) >= 0 ) {
int V_337 = F_286 ( V_333 , V_311 ) ;
if ( V_337 > V_338 )
V_185 = 1 ;
if ( V_337 != F_286 ( V_333 , V_334 ) )
V_321 [ V_311 ] = V_331 ;
V_334 = V_311 ;
V_331 -- ;
if ( V_27 == V_295 )
F_288 ( V_263 , V_311 ) ;
else
V_326 [ V_322 ++ ] = V_311 ;
}
if ( V_27 == V_296 ) {
F_290 ( V_263 , V_322 ) ;
}
F_289 ( V_263 ) ;
}
static void F_297 ( T_9 * V_263 )
{
struct V_155 * V_155 ;
struct V_156 * V_157 ;
struct V_167 * V_144 ;
V_155 = & V_263 -> V_323 [ 0 ] ;
V_155 -> V_159 = V_157 = & V_155 -> V_339 ;
F_179 ( V_157 -> V_161 , V_162 ) ;
for ( V_144 = V_155 -> V_169 ; V_144 -> V_11 ; V_144 ++ )
V_157 -> V_170 [ V_144 - V_155 -> V_169 ] = F_298 ( V_144 ) ;
}
int F_299 ( int V_311 )
{
struct V_11 * V_11 ;
( void ) F_226 ( F_250 ( V_311 , V_248 ) ,
F_229 ( V_248 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_311 ;
}
static void F_294 ( void )
{
V_330 = V_296 ;
}
static void F_295 ( T_9 * V_263 )
{
int V_311 , V_333 ;
enum V_206 V_322 ;
struct V_155 * V_155 ;
V_333 = V_263 -> V_336 ;
V_155 = & V_263 -> V_323 [ 0 ] ;
V_322 = F_270 ( V_263 , V_155 , 0 , V_287 - 1 ) ;
for ( V_311 = V_333 + 1 ; V_311 < V_320 ; V_311 ++ ) {
if ( ! F_300 ( V_311 ) )
continue;
V_322 = F_270 ( F_261 ( V_311 ) , V_155 , V_322 ,
V_287 - 1 ) ;
}
for ( V_311 = 0 ; V_311 < V_333 ; V_311 ++ ) {
if ( ! F_300 ( V_311 ) )
continue;
V_322 = F_270 ( F_261 ( V_311 ) , V_155 , V_322 ,
V_287 - 1 ) ;
}
V_155 -> V_169 [ V_322 ] . V_11 = NULL ;
V_155 -> V_169 [ V_322 ] . F_187 = 0 ;
}
static void F_297 ( T_9 * V_263 )
{
V_263 -> V_323 [ 0 ] . V_159 = NULL ;
}
static T_13 int F_301 ( void * V_308 )
{
int V_243 ;
int V_107 ;
#ifdef F_302
memset ( V_321 , 0 , sizeof( V_321 ) ) ;
#endif
F_292 (nid) {
T_9 * V_263 = F_261 ( V_243 ) ;
F_295 ( V_263 ) ;
F_297 ( V_263 ) ;
}
F_303 (cpu) {
F_304 ( & F_305 ( V_340 , V_107 ) , 0 ) ;
#ifdef F_306
if ( F_307 ( V_107 ) )
F_308 ( V_107 , F_299 ( F_309 ( V_107 ) ) ) ;
#endif
}
return 0 ;
}
void T_14 F_280 ( void * V_308 )
{
F_294 () ;
if ( V_341 == V_342 ) {
F_301 ( NULL ) ;
F_310 () ;
F_311 () ;
} else {
#ifdef F_312
if ( V_308 )
F_313 ( (struct V_11 * ) V_308 ) ;
#endif
F_314 ( F_301 , NULL , NULL ) ;
}
V_343 = F_254 () ;
if ( V_343 < ( V_92 * V_98 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_21 ( L_58
L_59 ,
V_184 ,
V_344 [ V_330 ] ,
V_7 ? L_60 : L_61 ,
V_343 ) ;
#ifdef F_302
F_21 ( L_62 , V_345 [ V_346 ] ) ;
#endif
}
static inline unsigned long F_315 ( unsigned long V_102 )
{
unsigned long V_82 = 1 ;
V_102 /= V_347 ;
while ( V_82 < V_102 )
V_82 <<= 1 ;
V_82 = V_149 ( V_82 , 4096UL ) ;
return F_316 ( V_82 , 4UL ) ;
}
static inline unsigned long F_315 ( unsigned long V_102 )
{
return 4096UL ;
}
static inline unsigned long F_317 ( unsigned long V_82 )
{
return F_318 ( ~ V_82 ) ;
}
static int F_319 ( unsigned long V_90 , unsigned long V_91 )
{
unsigned long V_14 ;
for ( V_14 = V_90 ; V_14 < V_91 ; V_14 ++ ) {
if ( ! F_14 ( V_14 ) || F_320 ( F_118 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_321 ( struct V_11 * V_11 )
{
unsigned long V_90 , V_14 , V_91 , V_348 ;
struct V_5 * V_5 ;
unsigned long V_349 ;
int V_350 ;
V_90 = V_11 -> V_15 ;
V_91 = V_90 + V_11 -> V_16 ;
V_90 = F_322 ( V_90 , V_92 ) ;
V_350 = F_322 ( F_267 ( V_11 ) , V_92 ) >>
V_96 ;
V_350 = V_149 ( 2 , V_350 ) ;
for ( V_14 = V_90 ; V_14 < V_91 ; V_14 += V_92 ) {
if ( ! F_139 ( V_14 ) )
continue;
V_5 = F_118 ( V_14 ) ;
if ( F_114 ( V_5 ) != F_115 ( V_11 ) )
continue;
V_349 = F_96 ( V_5 ) ;
if ( V_350 > 0 ) {
V_348 = V_149 ( V_14 + V_92 , V_91 ) ;
if ( F_319 ( V_14 , V_348 ) )
continue;
if ( V_349 == V_100 ) {
V_350 -- ;
continue;
}
if ( V_349 == V_118 ) {
F_6 ( V_5 ,
V_100 ) ;
F_117 ( V_11 , V_5 ,
V_100 ) ;
V_350 -- ;
continue;
}
}
if ( V_349 == V_100 ) {
F_6 ( V_5 , V_118 ) ;
F_117 ( V_11 , V_5 , V_118 ) ;
}
}
}
void T_3 F_323 ( unsigned long V_82 , int V_243 , unsigned long V_11 ,
unsigned long V_90 , enum V_351 V_352 )
{
struct V_5 * V_5 ;
unsigned long V_91 = V_90 + V_82 ;
unsigned long V_14 ;
struct V_11 * V_144 ;
if ( V_353 < V_91 - 1 )
V_353 = V_91 - 1 ;
V_144 = & F_261 ( V_243 ) -> V_265 [ V_11 ] ;
for ( V_14 = V_90 ; V_14 < V_91 ; V_14 ++ ) {
if ( V_352 == V_354 ) {
if ( ! F_324 ( V_14 ) )
continue;
if ( ! F_325 ( V_14 , V_243 ) )
continue;
}
V_5 = F_118 ( V_14 ) ;
F_326 ( V_5 , V_11 , V_243 , V_14 ) ;
F_327 ( V_5 , V_11 , V_243 , V_14 ) ;
F_328 ( V_5 ) ;
F_19 ( V_5 ) ;
F_329 ( V_5 ) ;
if ( ( V_144 -> V_15 <= V_14 )
&& ( V_14 < V_144 -> V_15 + V_144 -> V_16 )
&& ! ( V_14 & ( V_92 - 1 ) ) )
F_6 ( V_5 , V_118 ) ;
F_106 ( & V_5 -> V_49 ) ;
#ifdef F_330
if ( ! F_331 ( V_11 ) )
F_332 ( V_5 , F_333 ( V_14 << V_355 ) ) ;
#endif
}
}
static void T_3 F_334 ( struct V_11 * V_11 )
{
int V_27 , V_115 ;
F_142 (order, t) {
F_106 ( & V_11 -> V_50 [ V_27 ] . V_54 [ V_115 ] ) ;
V_11 -> V_50 [ V_27 ] . V_51 = 0 ;
}
}
static int F_335 ( struct V_11 * V_11 )
{
#ifdef F_336
int V_106 ;
V_106 = V_11 -> V_249 / 1024 ;
if ( V_106 * V_75 > 512 * 1024 )
V_106 = ( 512 * 1024 ) / V_75 ;
V_106 /= 4 ;
if ( V_106 < 1 )
V_106 = 1 ;
V_106 = F_337 ( V_106 + V_106 / 2 ) - 1 ;
return V_106 ;
#else
return 0 ;
#endif
}
static void F_304 ( struct V_108 * V_30 , unsigned long V_106 )
{
struct V_63 * V_64 ;
int V_6 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_64 = & V_30 -> V_64 ;
V_64 -> V_62 = 0 ;
V_64 -> V_80 = 6 * V_106 ;
V_64 -> V_106 = F_316 ( 1UL , 1 * V_106 ) ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ )
F_106 ( & V_64 -> V_73 [ V_6 ] ) ;
}
static void F_338 ( struct V_108 * V_30 ,
unsigned long V_80 )
{
struct V_63 * V_64 ;
V_64 = & V_30 -> V_64 ;
V_64 -> V_80 = V_80 ;
V_64 -> V_106 = F_316 ( 1UL , V_80 / 4 ) ;
if ( ( V_80 / 4 ) > ( V_355 * 8 ) )
V_64 -> V_106 = V_355 * 8 ;
}
static void F_313 ( struct V_11 * V_11 )
{
int V_107 ;
V_11 -> V_110 = F_339 ( struct V_108 ) ;
F_303 (cpu) {
struct V_108 * V_64 = F_129 ( V_11 -> V_110 , V_107 ) ;
F_304 ( V_64 , F_335 ( V_11 ) ) ;
if ( V_356 )
F_338 ( V_64 ,
( V_11 -> V_249 /
V_356 ) ) ;
}
}
void T_2 F_340 ( void )
{
struct V_11 * V_11 ;
F_128 (zone)
F_313 ( V_11 ) ;
}
static T_15 T_13
int F_341 ( struct V_11 * V_11 , unsigned long V_357 )
{
int V_28 ;
struct V_358 * V_263 = V_11 -> V_359 ;
T_8 V_360 ;
V_11 -> F_315 =
F_315 ( V_357 ) ;
V_11 -> F_317 =
F_317 ( V_11 -> F_315 ) ;
V_360 = V_11 -> F_315
* sizeof( V_361 ) ;
if ( ! F_342 () ) {
V_11 -> V_362 = ( V_361 * )
F_343 ( V_263 , V_360 ) ;
} else {
V_11 -> V_362 = F_344 ( V_360 ) ;
}
if ( ! V_11 -> V_362 )
return - V_143 ;
for( V_28 = 0 ; V_28 < V_11 -> F_315 ; ++ V_28 )
F_345 ( V_11 -> V_362 + V_28 ) ;
return 0 ;
}
static int F_346 ( void * V_308 )
{
struct V_11 * V_11 = V_308 ;
int V_107 ;
unsigned long V_106 = F_335 ( V_11 ) , V_59 ;
F_303 (cpu) {
struct V_108 * V_109 ;
struct V_63 * V_64 ;
V_109 = F_129 ( V_11 -> V_110 , V_107 ) ;
V_64 = & V_109 -> V_64 ;
F_94 ( V_59 ) ;
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
F_304 ( V_109 , V_106 ) ;
F_97 ( V_59 ) ;
}
return 0 ;
}
void F_347 ( struct V_11 * V_11 )
{
F_314 ( F_346 , V_11 , NULL ) ;
}
static T_3 void F_348 ( struct V_11 * V_11 )
{
V_11 -> V_110 = & V_340 ;
if ( V_11 -> V_249 )
F_21 ( V_363 L_63 ,
V_11 -> V_267 , V_11 -> V_249 ,
F_335 ( V_11 ) ) ;
}
T_3 int F_349 ( struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_82 ,
enum V_351 V_352 )
{
struct V_358 * V_263 = V_11 -> V_359 ;
int V_12 ;
V_12 = F_341 ( V_11 , V_82 ) ;
if ( V_12 )
return V_12 ;
V_263 -> V_291 = F_187 ( V_11 ) + 1 ;
V_11 -> V_15 = V_15 ;
F_350 ( V_364 , L_64 ,
L_65 ,
V_263 -> V_336 ,
( unsigned long ) F_187 ( V_11 ) ,
V_15 , ( V_15 + V_82 ) ) ;
F_334 ( V_11 ) ;
return 0 ;
}
int T_3 F_351 ( unsigned long V_14 )
{
unsigned long V_90 , V_91 ;
int V_28 , V_243 ;
F_352 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
if ( V_90 <= V_14 && V_14 < V_91 )
return V_243 ;
return - 1 ;
}
int T_3 F_353 ( unsigned long V_14 )
{
int V_243 ;
V_243 = F_351 ( V_14 ) ;
if ( V_243 >= 0 )
return V_243 ;
return 0 ;
}
bool T_3 F_325 ( unsigned long V_14 , int V_311 )
{
int V_243 ;
V_243 = F_351 ( V_14 ) ;
if ( V_243 >= 0 && V_243 != V_311 )
return false ;
return true ;
}
void T_2 F_354 ( int V_243 , unsigned long V_365 )
{
unsigned long V_90 , V_91 ;
int V_28 , V_366 ;
F_352 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_90 = V_149 ( V_90 , V_365 ) ;
V_91 = V_149 ( V_91 , V_365 ) ;
if ( V_90 < V_91 )
F_355 ( F_261 ( V_366 ) ,
F_356 ( V_90 ) ,
( V_91 - V_90 ) << V_355 ) ;
}
}
void T_2 F_357 ( int V_243 )
{
unsigned long V_90 , V_91 ;
int V_28 , V_366 ;
F_352 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_358 ( V_366 , V_90 , V_91 ) ;
}
void T_3 F_359 ( unsigned int V_243 ,
unsigned long * V_90 , unsigned long * V_91 )
{
unsigned long V_367 , V_368 ;
int V_28 ;
* V_90 = - 1UL ;
* V_91 = 0 ;
F_352 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_90 = V_149 ( * V_90 , V_367 ) ;
* V_91 = F_316 ( * V_91 , V_368 ) ;
}
if ( * V_90 == - 1UL )
* V_90 = 0 ;
}
static void T_2 F_360 ( void )
{
int V_369 ;
for ( V_369 = V_287 - 1 ; V_369 >= 0 ; V_369 -- ) {
if ( V_369 == V_370 )
continue;
if ( V_371 [ V_369 ] >
V_372 [ V_369 ] )
break;
}
F_41 ( V_369 == - 1 ) ;
V_373 = V_369 ;
}
static void T_3 F_361 ( int V_243 ,
unsigned long V_206 ,
unsigned long V_374 ,
unsigned long V_375 ,
unsigned long * V_15 ,
unsigned long * V_376 )
{
if ( V_377 [ V_243 ] ) {
if ( V_206 == V_370 ) {
* V_15 = V_377 [ V_243 ] ;
* V_376 = V_149 ( V_375 ,
V_371 [ V_373 ] ) ;
} else if ( * V_15 < V_377 [ V_243 ] &&
* V_376 > V_377 [ V_243 ] ) {
* V_376 = V_377 [ V_243 ] ;
} else if ( * V_15 >= V_377 [ V_243 ] )
* V_15 = * V_376 ;
}
}
static unsigned long T_3 F_362 ( int V_243 ,
unsigned long V_206 ,
unsigned long * V_378 )
{
unsigned long V_374 , V_375 ;
unsigned long V_15 , V_376 ;
F_359 ( V_243 , & V_374 , & V_375 ) ;
V_15 = V_372 [ V_206 ] ;
V_376 = V_371 [ V_206 ] ;
F_361 ( V_243 , V_206 ,
V_374 , V_375 ,
& V_15 , & V_376 ) ;
if ( V_376 < V_374 || V_15 > V_375 )
return 0 ;
V_376 = V_149 ( V_376 , V_375 ) ;
V_15 = F_316 ( V_15 , V_374 ) ;
return V_376 - V_15 ;
}
unsigned long T_3 F_363 ( int V_243 ,
unsigned long V_379 ,
unsigned long V_380 )
{
unsigned long V_381 = V_380 - V_379 ;
unsigned long V_90 , V_91 ;
int V_28 ;
F_352 (i, nid, &start_pfn, &end_pfn, NULL) {
V_90 = F_364 ( V_90 , V_379 , V_380 ) ;
V_91 = F_364 ( V_91 , V_379 , V_380 ) ;
V_381 -= V_91 - V_90 ;
}
return V_381 ;
}
unsigned long T_2 F_365 ( unsigned long V_90 ,
unsigned long V_91 )
{
return F_363 ( V_320 , V_90 , V_91 ) ;
}
static unsigned long T_3 F_366 ( int V_243 ,
unsigned long V_206 ,
unsigned long * V_378 )
{
unsigned long V_382 = V_372 [ V_206 ] ;
unsigned long V_383 = V_371 [ V_206 ] ;
unsigned long V_374 , V_375 ;
unsigned long V_15 , V_376 ;
F_359 ( V_243 , & V_374 , & V_375 ) ;
V_15 = F_364 ( V_374 , V_382 , V_383 ) ;
V_376 = F_364 ( V_375 , V_382 , V_383 ) ;
F_361 ( V_243 , V_206 ,
V_374 , V_375 ,
& V_15 , & V_376 ) ;
return F_363 ( V_243 , V_15 , V_376 ) ;
}
static inline unsigned long T_3 F_362 ( int V_243 ,
unsigned long V_206 ,
unsigned long * V_384 )
{
return V_384 [ V_206 ] ;
}
static inline unsigned long T_3 F_366 ( int V_243 ,
unsigned long V_206 ,
unsigned long * V_385 )
{
if ( ! V_385 )
return 0 ;
return V_385 [ V_206 ] ;
}
static void T_3 F_367 ( struct V_358 * V_263 ,
unsigned long * V_384 , unsigned long * V_385 )
{
unsigned long V_386 , V_387 = 0 ;
enum V_206 V_28 ;
for ( V_28 = 0 ; V_28 < V_287 ; V_28 ++ )
V_387 += F_362 ( V_263 -> V_336 , V_28 ,
V_384 ) ;
V_263 -> V_388 = V_387 ;
V_386 = V_387 ;
for ( V_28 = 0 ; V_28 < V_287 ; V_28 ++ )
V_386 -=
F_366 ( V_263 -> V_336 , V_28 ,
V_385 ) ;
V_263 -> V_264 = V_386 ;
F_21 ( V_363 L_66 , V_263 -> V_336 ,
V_386 ) ;
}
static unsigned long T_2 F_368 ( unsigned long V_389 )
{
unsigned long V_390 ;
V_390 = F_322 ( V_389 , V_92 ) ;
V_390 = V_390 >> V_96 ;
V_390 *= V_391 ;
V_390 = F_322 ( V_390 , 8 * sizeof( unsigned long ) ) ;
return V_390 / 8 ;
}
static void T_2 F_369 ( struct V_358 * V_263 ,
struct V_11 * V_11 , unsigned long V_389 )
{
unsigned long V_390 = F_368 ( V_389 ) ;
V_11 -> V_392 = NULL ;
if ( V_390 )
V_11 -> V_392 = F_343 ( V_263 ,
V_390 ) ;
}
static inline void F_369 ( struct V_358 * V_263 ,
struct V_11 * V_11 , unsigned long V_389 ) {}
static inline int F_370 ( void )
{
if ( V_393 > V_355 )
return V_394 ;
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
static void T_16 F_372 ( struct V_358 * V_263 ,
unsigned long * V_384 , unsigned long * V_385 )
{
enum V_206 V_322 ;
int V_243 = V_263 -> V_336 ;
unsigned long V_15 = V_263 -> V_374 ;
int V_12 ;
F_373 ( V_263 ) ;
V_263 -> V_291 = 0 ;
F_345 ( & V_263 -> V_395 ) ;
V_263 -> V_396 = 0 ;
F_374 ( V_263 ) ;
for ( V_322 = 0 ; V_322 < V_287 ; V_322 ++ ) {
struct V_11 * V_11 = V_263 -> V_265 + V_322 ;
unsigned long V_82 , V_397 , V_398 ;
enum V_399 V_49 ;
V_82 = F_362 ( V_243 , V_322 , V_384 ) ;
V_397 = V_82 - F_366 ( V_243 , V_322 ,
V_385 ) ;
V_398 =
F_242 ( V_82 * sizeof( struct V_5 ) ) >> V_355 ;
if ( V_397 >= V_398 ) {
V_397 -= V_398 ;
if ( V_398 )
F_21 ( V_363
L_67 ,
V_345 [ V_322 ] , V_398 ) ;
} else
F_21 ( V_297
L_68 ,
V_345 [ V_322 ] , V_398 , V_397 ) ;
if ( V_322 == 0 && V_397 > V_400 ) {
V_397 -= V_400 ;
F_21 ( V_363 L_69 ,
V_345 [ 0 ] , V_400 ) ;
}
if ( ! F_331 ( V_322 ) )
V_401 += V_397 ;
V_402 += V_397 ;
V_11 -> V_16 = V_82 ;
V_11 -> V_249 = V_397 ;
#ifdef F_302
V_11 -> V_311 = V_243 ;
V_11 -> V_403 = ( V_397 * V_404 )
/ 100 ;
V_11 -> V_405 = ( V_397 * V_406 ) / 100 ;
#endif
V_11 -> V_267 = V_345 [ V_322 ] ;
F_375 ( & V_11 -> V_67 ) ;
F_375 ( & V_11 -> V_407 ) ;
F_376 ( V_11 ) ;
V_11 -> V_359 = V_263 ;
F_348 ( V_11 ) ;
F_377 (lru)
F_106 ( & V_11 -> V_408 . V_73 [ V_49 ] ) ;
V_11 -> V_409 . V_410 [ 0 ] = 0 ;
V_11 -> V_409 . V_410 [ 1 ] = 0 ;
V_11 -> V_409 . V_411 [ 0 ] = 0 ;
V_11 -> V_409 . V_411 [ 1 ] = 0 ;
F_378 ( V_11 ) ;
V_11 -> V_59 = 0 ;
if ( ! V_82 )
continue;
F_371 ( F_370 () ) ;
F_369 ( V_263 , V_11 , V_82 ) ;
V_12 = F_349 ( V_11 , V_15 ,
V_82 , V_354 ) ;
F_113 ( V_12 ) ;
F_379 ( V_82 , V_243 , V_322 , V_15 ) ;
V_15 += V_82 ;
}
}
static void T_13 F_380 ( struct V_358 * V_263 )
{
if ( ! V_263 -> V_388 )
return;
#ifdef F_381
if ( ! V_263 -> V_412 ) {
unsigned long V_82 , V_413 , V_245 ;
struct V_5 * V_414 ;
V_413 = V_263 -> V_374 & ~ ( V_415 - 1 ) ;
V_245 = V_263 -> V_374 + V_263 -> V_388 ;
V_245 = F_382 ( V_245 , V_415 ) ;
V_82 = ( V_245 - V_413 ) * sizeof( struct V_5 ) ;
V_414 = F_383 ( V_263 -> V_336 , V_82 ) ;
if ( ! V_414 )
V_414 = F_343 ( V_263 , V_82 ) ;
V_263 -> V_412 = V_414 + ( V_263 -> V_374 - V_413 ) ;
}
#ifndef F_384
if ( V_263 == F_261 ( 0 ) ) {
V_416 = F_261 ( 0 ) -> V_412 ;
#ifdef F_385
if ( F_10 ( V_416 ) != V_263 -> V_374 )
V_416 -= ( V_263 -> V_374 - V_417 ) ;
#endif
}
#endif
#endif
}
void T_16 F_386 ( int V_243 , unsigned long * V_384 ,
unsigned long V_374 , unsigned long * V_385 )
{
T_9 * V_263 = F_261 ( V_243 ) ;
V_263 -> V_336 = V_243 ;
V_263 -> V_374 = V_374 ;
F_367 ( V_263 , V_384 , V_385 ) ;
F_380 ( V_263 ) ;
#ifdef F_381
F_21 ( V_363 L_70 ,
V_243 , ( unsigned long ) V_263 ,
( unsigned long ) V_263 -> V_412 ) ;
#endif
F_372 ( V_263 , V_384 , V_385 ) ;
}
static void T_2 F_387 ( void )
{
unsigned int V_311 ;
unsigned int V_418 = 0 ;
F_388 (node, node_possible_map)
V_418 = V_311 ;
V_419 = V_418 + 1 ;
}
static inline void F_387 ( void )
{
}
unsigned long T_2 F_389 ( void )
{
unsigned long V_420 = 0 , V_421 = 0 ;
unsigned long V_413 , V_245 , V_422 ;
int V_423 = - 1 ;
int V_28 , V_243 ;
F_352 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_413 || V_423 < 0 || V_423 == V_243 ) {
V_423 = V_243 ;
V_421 = V_245 ;
continue;
}
V_422 = ~ ( ( 1 << F_390 ( V_413 ) ) - 1 ) ;
while ( V_422 && V_421 <= ( V_413 & ( V_422 << 1 ) ) )
V_422 <<= 1 ;
V_420 |= V_422 ;
}
return ~ V_420 + 1 ;
}
static unsigned long T_2 F_391 ( int V_243 )
{
unsigned long V_424 = V_425 ;
unsigned long V_90 ;
int V_28 ;
F_352 (i, nid, &start_pfn, NULL, NULL)
V_424 = V_149 ( V_424 , V_90 ) ;
if ( V_424 == V_425 ) {
F_21 ( V_297
L_71 , V_243 ) ;
return 0 ;
}
return V_424 ;
}
unsigned long T_2 F_392 ( void )
{
return F_391 ( V_320 ) ;
}
static unsigned long T_2 F_393 ( void )
{
unsigned long V_387 = 0 ;
unsigned long V_90 , V_91 ;
int V_28 , V_243 ;
F_352 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_102 = V_91 - V_90 ;
V_387 += V_102 ;
if ( V_102 )
F_394 ( V_243 , V_166 ) ;
}
return V_387 ;
}
static void T_2 F_395 ( void )
{
int V_28 , V_243 ;
unsigned long V_426 ;
unsigned long V_427 , V_428 ;
T_6 V_429 = V_165 [ V_166 ] ;
unsigned long V_387 = F_393 () ;
int V_430 = F_293 ( V_165 [ V_166 ] ) ;
if ( V_431 ) {
unsigned long V_432 ;
V_431 =
F_322 ( V_431 , V_415 ) ;
V_432 = V_387 - V_431 ;
V_433 = F_316 ( V_433 , V_432 ) ;
}
if ( ! V_433 )
goto V_21;
F_360 () ;
V_426 = V_372 [ V_373 ] ;
V_230:
V_427 = V_433 / V_430 ;
F_285 (nid, N_HIGH_MEMORY) {
unsigned long V_90 , V_91 ;
if ( V_433 < V_427 )
V_427 = V_433 / V_430 ;
V_428 = V_427 ;
F_352 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_434 ;
V_90 = F_316 ( V_90 , V_377 [ V_243 ] ) ;
if ( V_90 >= V_91 )
continue;
if ( V_90 < V_426 ) {
unsigned long V_435 ;
V_435 = V_149 ( V_91 , V_426 )
- V_90 ;
V_428 -= V_149 ( V_435 ,
V_428 ) ;
V_433 -= V_149 ( V_435 ,
V_433 ) ;
if ( V_91 <= V_426 ) {
V_377 [ V_243 ] = V_91 ;
continue;
}
V_90 = V_426 ;
}
V_434 = V_91 - V_90 ;
if ( V_434 > V_428 )
V_434 = V_428 ;
V_377 [ V_243 ] = V_90 + V_434 ;
V_433 -= V_149 ( V_433 ,
V_434 ) ;
V_428 -= V_434 ;
if ( ! V_428 )
break;
}
}
V_430 -- ;
if ( V_430 && V_433 > V_430 )
goto V_230;
for ( V_243 = 0 ; V_243 < V_320 ; V_243 ++ )
V_377 [ V_243 ] =
F_322 ( V_377 [ V_243 ] , V_415 ) ;
V_21:
V_165 [ V_166 ] = V_429 ;
}
static void F_396 ( T_9 * V_263 )
{
#ifdef F_263
enum V_206 V_206 ;
for ( V_206 = 0 ; V_206 <= V_209 ; V_206 ++ ) {
struct V_11 * V_11 = & V_263 -> V_265 [ V_206 ] ;
if ( V_11 -> V_249 ) {
F_394 ( F_115 ( V_11 ) , V_436 ) ;
break;
}
}
#endif
}
void T_2 F_397 ( unsigned long * V_114 )
{
unsigned long V_90 , V_91 ;
int V_28 , V_243 ;
memset ( V_372 , 0 ,
sizeof( V_372 ) ) ;
memset ( V_371 , 0 ,
sizeof( V_371 ) ) ;
V_372 [ 0 ] = F_392 () ;
V_371 [ 0 ] = V_114 [ 0 ] ;
for ( V_28 = 1 ; V_28 < V_287 ; V_28 ++ ) {
if ( V_28 == V_370 )
continue;
V_372 [ V_28 ] =
V_371 [ V_28 - 1 ] ;
V_371 [ V_28 ] =
F_316 ( V_114 [ V_28 ] , V_372 [ V_28 ] ) ;
}
V_372 [ V_370 ] = 0 ;
V_371 [ V_370 ] = 0 ;
memset ( V_377 , 0 , sizeof( V_377 ) ) ;
F_395 () ;
F_21 ( L_72 ) ;
for ( V_28 = 0 ; V_28 < V_287 ; V_28 ++ ) {
if ( V_28 == V_370 )
continue;
F_21 ( L_73 , V_345 [ V_28 ] ) ;
if ( V_372 [ V_28 ] ==
V_371 [ V_28 ] )
F_21 ( L_74 ) ;
else
F_21 ( L_75 ,
V_372 [ V_28 ] ,
V_371 [ V_28 ] ) ;
}
F_21 ( L_76 ) ;
for ( V_28 = 0 ; V_28 < V_320 ; V_28 ++ ) {
if ( V_377 [ V_28 ] )
F_21 ( L_77 , V_28 , V_377 [ V_28 ] ) ;
}
F_21 ( L_78 ) ;
F_352 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_21 ( L_79 , V_243 , V_90 , V_91 ) ;
F_398 () ;
F_387 () ;
F_292 (nid) {
T_9 * V_263 = F_261 ( V_243 ) ;
F_386 ( V_243 , NULL ,
F_391 ( V_243 ) , NULL ) ;
if ( V_263 -> V_264 )
F_394 ( V_243 , V_166 ) ;
F_396 ( V_263 ) ;
}
}
static int T_2 F_399 ( char * V_30 , unsigned long * V_437 )
{
unsigned long long V_438 ;
if ( ! V_30 )
return - V_298 ;
V_438 = F_400 ( V_30 , & V_30 ) ;
* V_437 = V_438 >> V_355 ;
F_2 ( ( V_438 >> V_355 ) > V_425 ) ;
return 0 ;
}
static int T_2 F_401 ( char * V_30 )
{
return F_399 ( V_30 , & V_433 ) ;
}
static int T_2 F_402 ( char * V_30 )
{
return F_399 ( V_30 , & V_431 ) ;
}
void T_2 F_403 ( unsigned long V_439 )
{
V_400 = V_439 ;
}
void T_2 F_404 ( unsigned long * V_384 )
{
F_386 ( 0 , V_384 ,
F_405 ( V_440 ) >> V_355 , NULL ) ;
}
static int F_406 ( struct V_441 * V_442 ,
unsigned long V_443 , void * V_444 )
{
int V_107 = ( unsigned long ) V_444 ;
if ( V_443 == V_445 || V_443 == V_446 ) {
F_407 ( V_107 ) ;
F_127 ( V_107 ) ;
F_408 ( V_107 ) ;
F_409 ( V_107 ) ;
}
return V_447 ;
}
void T_2 F_410 ( void )
{
F_411 ( F_406 , 0 ) ;
}
static void F_412 ( void )
{
struct V_358 * V_263 ;
unsigned long V_448 = 0 ;
enum V_206 V_28 , V_322 ;
F_413 (pgdat) {
for ( V_28 = 0 ; V_28 < V_287 ; V_28 ++ ) {
struct V_11 * V_11 = V_263 -> V_265 + V_28 ;
unsigned long F_316 = 0 ;
for ( V_322 = V_28 ; V_322 < V_287 ; V_322 ++ ) {
if ( V_11 -> V_153 [ V_322 ] > F_316 )
F_316 = V_11 -> V_153 [ V_322 ] ;
}
F_316 += F_252 ( V_11 ) ;
if ( F_316 > V_11 -> V_249 )
F_316 = V_11 -> V_249 ;
V_448 += F_316 ;
V_11 -> V_449 = F_316 ;
}
}
V_449 = V_448 ;
V_450 = V_448 ;
}
static void F_414 ( void )
{
struct V_358 * V_263 ;
enum V_206 V_322 , V_451 ;
F_413 (pgdat) {
for ( V_322 = 0 ; V_322 < V_287 ; V_322 ++ ) {
struct V_11 * V_11 = V_263 -> V_265 + V_322 ;
unsigned long V_249 = V_11 -> V_249 ;
V_11 -> V_153 [ V_322 ] = 0 ;
V_451 = V_322 ;
while ( V_451 ) {
struct V_11 * V_452 ;
V_451 -- ;
if ( V_453 [ V_451 ] < 1 )
V_453 [ V_451 ] = 1 ;
V_452 = V_263 -> V_265 + V_451 ;
V_452 -> V_153 [ V_322 ] = V_249 /
V_453 [ V_451 ] ;
V_249 += V_452 -> V_249 ;
}
}
}
F_412 () ;
}
void F_415 ( void )
{
unsigned long V_454 = V_455 >> ( V_355 - 10 ) ;
unsigned long V_456 = 0 ;
struct V_11 * V_11 ;
unsigned long V_59 ;
F_416 (zone) {
if ( ! F_417 ( V_11 ) )
V_456 += V_11 -> V_249 ;
}
F_416 (zone) {
T_17 V_317 ;
F_138 ( & V_11 -> V_67 , V_59 ) ;
V_317 = ( T_17 ) V_454 * V_11 -> V_249 ;
F_418 ( V_317 , V_456 ) ;
if ( F_417 ( V_11 ) ) {
int V_457 ;
V_457 = V_11 -> V_249 / 1024 ;
if ( V_457 < V_458 )
V_457 = V_458 ;
if ( V_457 > 128 )
V_457 = 128 ;
V_11 -> V_120 [ V_459 ] = V_457 ;
} else {
V_11 -> V_120 [ V_459 ] = V_317 ;
}
V_11 -> V_120 [ V_460 ] = F_267 ( V_11 ) + ( V_317 >> 2 ) ;
V_11 -> V_120 [ V_461 ] = F_267 ( V_11 ) + ( V_317 >> 1 ) ;
F_321 ( V_11 ) ;
F_145 ( & V_11 -> V_67 , V_59 ) ;
}
F_412 () ;
}
static void T_3 F_419 ( struct V_11 * V_11 )
{
unsigned int V_462 , V_463 ;
V_462 = V_11 -> V_249 >> ( 30 - V_355 ) ;
if ( V_462 )
V_463 = F_420 ( 10 * V_462 ) ;
else
V_463 = 1 ;
V_11 -> V_464 = V_463 ;
}
static void T_3 F_421 ( void )
{
struct V_11 * V_11 ;
F_416 (zone)
F_419 ( V_11 ) ;
}
int T_3 F_422 ( void )
{
unsigned long V_465 ;
V_465 = F_253 () * ( V_75 >> 10 ) ;
V_455 = F_420 ( V_465 * 16 ) ;
if ( V_455 < 128 )
V_455 = 128 ;
if ( V_455 > 65536 )
V_455 = 65536 ;
F_415 () ;
F_423 () ;
F_414 () ;
F_421 () ;
return 0 ;
}
int F_424 ( T_10 * V_301 , int V_302 ,
void T_11 * V_303 , T_8 * V_304 , T_12 * V_305 )
{
F_425 ( V_301 , V_302 , V_303 , V_304 , V_305 ) ;
if ( V_302 )
F_415 () ;
return 0 ;
}
int F_426 ( T_10 * V_301 , int V_302 ,
void T_11 * V_303 , T_8 * V_304 , T_12 * V_305 )
{
struct V_11 * V_11 ;
int V_466 ;
V_466 = F_427 ( V_301 , V_302 , V_303 , V_304 , V_305 ) ;
if ( V_466 )
return V_466 ;
F_416 (zone)
V_11 -> V_403 = ( V_11 -> V_249 *
V_404 ) / 100 ;
return 0 ;
}
int F_428 ( T_10 * V_301 , int V_302 ,
void T_11 * V_303 , T_8 * V_304 , T_12 * V_305 )
{
struct V_11 * V_11 ;
int V_466 ;
V_466 = F_427 ( V_301 , V_302 , V_303 , V_304 , V_305 ) ;
if ( V_466 )
return V_466 ;
F_416 (zone)
V_11 -> V_405 = ( V_11 -> V_249 *
V_406 ) / 100 ;
return 0 ;
}
int F_429 ( T_10 * V_301 , int V_302 ,
void T_11 * V_303 , T_8 * V_304 , T_12 * V_305 )
{
F_427 ( V_301 , V_302 , V_303 , V_304 , V_305 ) ;
F_414 () ;
return 0 ;
}
int F_430 ( T_10 * V_301 , int V_302 ,
void T_11 * V_303 , T_8 * V_304 , T_12 * V_305 )
{
struct V_11 * V_11 ;
unsigned int V_107 ;
int V_12 ;
V_12 = F_427 ( V_301 , V_302 , V_303 , V_304 , V_305 ) ;
if ( ! V_302 || ( V_12 < 0 ) )
return V_12 ;
F_128 (zone) {
F_303 (cpu) {
unsigned long V_80 ;
V_80 = V_11 -> V_249 / V_356 ;
F_338 (
F_129 ( V_11 -> V_110 , V_107 ) , V_80 ) ;
}
}
return 0 ;
}
static int T_2 F_431 ( char * V_128 )
{
if ( ! V_128 )
return 0 ;
V_467 = F_432 ( V_128 , & V_128 , 0 ) ;
return 1 ;
}
void * T_2 F_433 ( const char * V_468 ,
unsigned long V_469 ,
unsigned long V_470 ,
int V_471 ,
int V_59 ,
unsigned int * V_472 ,
unsigned int * V_473 ,
unsigned long V_474 )
{
unsigned long long F_316 = V_474 ;
unsigned long V_475 , V_82 ;
void * V_301 = NULL ;
if ( ! V_470 ) {
V_470 = V_401 ;
V_470 += ( 1UL << ( 20 - V_355 ) ) - 1 ;
V_470 >>= 20 - V_355 ;
V_470 <<= 20 - V_355 ;
if ( V_471 > V_355 )
V_470 >>= ( V_471 - V_355 ) ;
else
V_470 <<= ( V_355 - V_471 ) ;
if ( F_7 ( V_59 & V_476 ) ) {
F_2 ( ! ( V_59 & V_477 ) ) ;
if ( ! ( V_470 >> * V_472 ) ) {
V_470 = 1UL << * V_472 ;
F_113 ( ! V_470 ) ;
}
} else if ( F_7 ( ( V_470 * V_469 ) < V_75 ) )
V_470 = V_75 / V_469 ;
}
V_470 = F_434 ( V_470 ) ;
if ( F_316 == 0 ) {
F_316 = ( ( unsigned long long ) V_402 << V_355 ) >> 4 ;
F_418 ( F_316 , V_469 ) ;
}
F_316 = V_149 ( F_316 , 0x80000000ULL ) ;
if ( V_470 > F_316 )
V_470 = F_316 ;
V_475 = F_435 ( V_470 ) ;
do {
V_82 = V_469 << V_475 ;
if ( V_59 & V_477 )
V_301 = F_436 ( V_82 ) ;
else if ( V_467 )
V_301 = F_437 ( V_82 , V_478 , V_479 ) ;
else {
if ( F_245 ( V_82 ) < V_37 ) {
V_301 = F_244 ( V_82 , V_478 ) ;
F_438 ( V_301 , V_82 , 1 , V_478 ) ;
}
}
} while ( ! V_301 && V_82 > V_75 && -- V_475 );
if ( ! V_301 )
F_439 ( L_80 , V_468 ) ;
F_21 ( V_40 L_81 ,
V_468 ,
( 1UL << V_475 ) ,
F_435 ( V_82 ) - V_355 ,
V_82 ) ;
if ( V_472 )
* V_472 = V_475 ;
if ( V_473 )
* V_473 = ( 1 << V_475 ) - 1 ;
return V_301 ;
}
static inline unsigned long * F_440 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef F_441
return F_442 ( V_14 ) -> V_392 ;
#else
return V_11 -> V_392 ;
#endif
}
static inline int F_443 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef F_441
V_14 &= ( V_480 - 1 ) ;
return ( V_14 >> V_96 ) * V_391 ;
#else
V_14 = V_14 - V_11 -> V_15 ;
return ( V_14 >> V_96 ) * V_391 ;
#endif
}
unsigned long F_444 ( struct V_5 * V_5 ,
int V_481 , int V_482 )
{
struct V_11 * V_11 ;
unsigned long * V_483 ;
unsigned long V_14 , V_484 ;
unsigned long V_59 = 0 ;
unsigned long V_485 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_483 = F_440 ( V_11 , V_14 ) ;
V_484 = F_443 ( V_11 , V_14 ) ;
for (; V_481 <= V_482 ; V_481 ++ , V_485 <<= 1 )
if ( F_182 ( V_484 + V_481 , V_483 ) )
V_59 |= V_485 ;
return V_59 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_59 ,
int V_481 , int V_482 )
{
struct V_11 * V_11 ;
unsigned long * V_483 ;
unsigned long V_14 , V_484 ;
unsigned long V_485 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_483 = F_440 ( V_11 , V_14 ) ;
V_484 = F_443 ( V_11 , V_14 ) ;
F_41 ( V_14 < V_11 -> V_15 ) ;
F_41 ( V_14 >= V_11 -> V_15 + V_11 -> V_16 ) ;
for (; V_481 <= V_482 ; V_481 ++ , V_485 <<= 1 )
if ( V_59 & V_485 )
F_47 ( V_484 + V_481 , V_483 ) ;
else
F_49 ( V_484 + V_481 , V_483 ) ;
}
static int
F_445 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_62 )
{
unsigned long V_14 , V_486 , V_487 ;
if ( F_187 ( V_11 ) == V_370 )
return true ;
if ( F_96 ( V_5 ) == V_118 )
return true ;
V_14 = F_10 ( V_5 ) ;
for ( V_487 = 0 , V_486 = 0 ; V_486 < V_92 ; V_486 ++ ) {
unsigned long V_488 = V_14 + V_486 ;
if ( ! F_14 ( V_488 ) )
continue;
V_5 = F_118 ( V_488 ) ;
if ( ! F_60 ( V_5 ) ) {
if ( F_61 ( V_5 ) )
V_486 += ( 1 << F_59 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_446 ( V_5 ) )
V_487 ++ ;
if ( V_487 > V_62 )
return false ;
}
return true ;
}
bool F_447 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_300 ( F_114 ( V_5 ) ) )
return false ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( V_11 -> V_15 > V_14 ||
V_11 -> V_15 + V_11 -> V_16 <= V_14 )
return false ;
return F_445 ( V_11 , V_5 , 0 ) ;
}
int F_448 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_59 , V_14 ;
struct V_489 V_111 ;
int V_490 ;
int V_12 = - V_491 ;
V_11 = F_15 ( V_5 ) ;
F_138 ( & V_11 -> V_67 , V_59 ) ;
V_14 = F_10 ( V_5 ) ;
V_111 . V_90 = V_14 ;
V_111 . V_29 = V_92 ;
V_111 . V_492 = 0 ;
V_490 = V_489 ( V_493 , & V_111 ) ;
V_490 = F_449 ( V_490 ) ;
if ( V_490 )
goto V_21;
if ( F_445 ( V_11 , V_5 , V_111 . V_492 ) )
V_12 = 0 ;
V_21:
if ( ! V_12 ) {
F_6 ( V_5 , V_117 ) ;
F_117 ( V_11 , V_5 , V_117 ) ;
}
F_145 ( & V_11 -> V_67 , V_59 ) ;
if ( ! V_12 )
F_132 () ;
return V_12 ;
}
void F_450 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_59 ;
V_11 = F_15 ( V_5 ) ;
F_138 ( & V_11 -> V_67 , V_59 ) ;
if ( F_96 ( V_5 ) != V_117 )
goto V_21;
F_6 ( V_5 , V_118 ) ;
F_117 ( V_11 , V_5 , V_118 ) ;
V_21:
F_145 ( & V_11 -> V_67 , V_59 ) ;
}
void
F_451 ( unsigned long V_90 , unsigned long V_91 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_27 , V_28 ;
unsigned long V_14 ;
unsigned long V_59 ;
for ( V_14 = V_90 ; V_14 < V_91 ; V_14 ++ )
if ( F_139 ( V_14 ) )
break;
if ( V_14 == V_91 )
return;
V_11 = F_15 ( F_118 ( V_14 ) ) ;
F_138 ( & V_11 -> V_67 , V_59 ) ;
V_14 = V_90 ;
while ( V_14 < V_91 ) {
if ( ! F_139 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_118 ( V_14 ) ;
F_113 ( F_60 ( V_5 ) ) ;
F_113 ( ! F_61 ( V_5 ) ) ;
V_27 = F_59 ( V_5 ) ;
#ifdef F_452
F_21 ( V_40 L_82 ,
V_14 , 1 << V_27 , V_91 ) ;
#endif
F_65 ( & V_5 -> V_49 ) ;
F_53 ( V_5 ) ;
V_11 -> V_50 [ V_27 ] . V_51 -- ;
F_64 ( V_11 , V_48 ,
- ( 1UL << V_27 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_329 ( ( V_5 + V_28 ) ) ;
V_14 += ( 1 << V_27 ) ;
}
F_145 ( & V_11 -> V_67 , V_59 ) ;
}
bool F_453 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_15 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_59 ;
int V_27 ;
F_138 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
struct V_5 * V_494 = V_5 - ( V_14 & ( ( 1 << V_27 ) - 1 ) ) ;
if ( F_61 ( V_494 ) && F_59 ( V_494 ) >= V_27 )
break;
}
F_145 ( & V_11 -> V_67 , V_59 ) ;
return V_27 < V_37 ;
}
static void F_454 ( unsigned long V_59 )
{
const char * V_495 = L_83 ;
unsigned long V_422 ;
int V_28 ;
F_21 ( V_22 L_84 , V_59 ) ;
V_59 &= ( 1UL << V_496 ) - 1 ;
for ( V_28 = 0 ; V_497 [ V_28 ] . V_267 && V_59 ; V_28 ++ ) {
V_422 = V_497 [ V_28 ] . V_422 ;
if ( ( V_59 & V_422 ) != V_422 )
continue;
V_59 &= ~ V_422 ;
F_21 ( L_85 , V_495 , V_497 [ V_28 ] . V_267 ) ;
V_495 = L_86 ;
}
if ( V_59 )
F_21 ( L_87 , V_495 , V_59 ) ;
F_21 ( L_88 ) ;
}
void F_22 ( struct V_5 * V_5 )
{
F_21 ( V_22
L_89 ,
V_5 , F_73 ( & V_5 -> V_58 ) , F_72 ( V_5 ) ,
V_5 -> V_57 , V_5 -> V_498 ) ;
F_454 ( V_5 -> V_59 ) ;
F_455 ( V_5 ) ;
}
