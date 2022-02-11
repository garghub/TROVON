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
static void F_5 ( struct V_5 * V_5 , int V_6 )
{
if ( F_6 ( V_7 ) )
V_6 = V_8 ;
F_7 ( V_5 , ( unsigned long ) V_6 ,
V_9 , V_10 ) ;
}
static int F_8 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
int V_12 = 0 ;
unsigned V_13 ;
unsigned long V_14 = F_9 ( V_5 ) ;
do {
V_13 = F_10 ( V_11 ) ;
if ( V_14 >= V_11 -> V_15 + V_11 -> V_16 )
V_12 = 1 ;
else if ( V_14 < V_11 -> V_15 )
V_12 = 1 ;
} while ( F_11 ( V_11 , V_13 ) );
return V_12 ;
}
static int F_12 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
if ( ! F_13 ( F_9 ( V_5 ) ) )
return 0 ;
if ( V_11 != F_14 ( V_5 ) )
return 0 ;
return 1 ;
}
static int F_15 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
if ( F_8 ( V_11 , V_5 ) )
return 1 ;
if ( ! F_12 ( V_11 , V_5 ) )
return 1 ;
return 0 ;
}
static inline int F_15 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
return 0 ;
}
static void F_16 ( struct V_5 * V_5 )
{
static unsigned long V_17 ;
static unsigned long V_18 ;
static unsigned long V_19 ;
if ( F_17 ( V_5 ) ) {
F_18 ( V_5 ) ;
return;
}
if ( V_18 == 60 ) {
if ( F_19 ( V_20 , V_17 ) ) {
V_19 ++ ;
goto V_21;
}
if ( V_19 ) {
F_20 ( V_22
L_1 ,
V_19 ) ;
V_19 = 0 ;
}
V_18 = 0 ;
}
if ( V_18 ++ == 0 )
V_17 = V_20 + 60 * V_23 ;
F_20 ( V_22 L_2 ,
V_24 -> V_25 , F_9 ( V_5 ) ) ;
F_21 ( V_5 ) ;
F_22 () ;
F_23 () ;
V_21:
F_18 ( V_5 ) ;
F_24 ( V_26 ) ;
}
static void F_25 ( struct V_5 * V_5 )
{
F_26 ( V_5 , F_27 ( V_5 ) ) ;
}
void F_28 ( struct V_5 * V_5 , unsigned long V_27 )
{
int V_28 ;
int V_29 = 1 << V_27 ;
F_29 ( V_5 , F_25 ) ;
F_30 ( V_5 , V_27 ) ;
F_31 ( V_5 ) ;
for ( V_28 = 1 ; V_28 < V_29 ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
F_32 ( V_30 ) ;
F_33 ( V_30 , 0 ) ;
V_30 -> V_31 = V_5 ;
}
}
static int F_34 ( struct V_5 * V_5 , unsigned long V_27 )
{
int V_28 ;
int V_29 = 1 << V_27 ;
int V_32 = 0 ;
if ( F_6 ( F_27 ( V_5 ) != V_27 ) ||
F_6 ( ! F_35 ( V_5 ) ) ) {
F_16 ( V_5 ) ;
V_32 ++ ;
}
F_36 ( V_5 ) ;
for ( V_28 = 1 ; V_28 < V_29 ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
if ( F_6 ( ! F_37 ( V_30 ) || ( V_30 -> V_31 != V_5 ) ) ) {
F_16 ( V_5 ) ;
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
static inline void F_43 ( struct V_5 * V_5 , int V_27 )
{
F_44 ( V_5 , V_27 ) ;
F_45 ( V_5 ) ;
}
static inline void F_46 ( struct V_5 * V_5 )
{
F_47 ( V_5 ) ;
F_44 ( V_5 , 0 ) ;
}
static inline unsigned long
F_48 ( unsigned long V_35 , unsigned int V_27 )
{
return V_35 ^ ( 1 << V_27 ) ;
}
static inline int F_49 ( struct V_5 * V_5 , struct V_5 * V_36 ,
int V_27 )
{
if ( ! F_13 ( F_9 ( V_36 ) ) )
return 0 ;
if ( F_50 ( V_5 ) != F_50 ( V_36 ) )
return 0 ;
if ( F_51 ( V_36 ) && F_52 ( V_36 ) == V_27 ) {
F_40 ( F_53 ( V_36 ) != 0 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_54 ( struct V_5 * V_5 ,
struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned long V_35 ;
unsigned long V_37 ;
unsigned long V_38 ( V_39 ) ;
struct V_5 * V_36 ;
if ( F_6 ( F_55 ( V_5 ) ) )
if ( F_6 ( F_34 ( V_5 , V_27 ) ) )
return;
F_40 ( V_6 == - 1 ) ;
V_35 = F_9 ( V_5 ) & ( ( 1 << V_40 ) - 1 ) ;
F_40 ( V_35 & ( ( 1 << V_27 ) - 1 ) ) ;
F_40 ( F_15 ( V_11 , V_5 ) ) ;
while ( V_27 < V_40 - 1 ) {
V_39 = F_48 ( V_35 , V_27 ) ;
V_36 = V_5 + ( V_39 - V_35 ) ;
if ( ! F_49 ( V_5 , V_36 , V_27 ) )
break;
F_56 ( & V_36 -> V_41 ) ;
V_11 -> V_42 [ V_27 ] . V_43 -- ;
F_46 ( V_36 ) ;
V_37 = V_39 & V_35 ;
V_5 = V_5 + ( V_37 - V_35 ) ;
V_35 = V_37 ;
V_27 ++ ;
}
F_43 ( V_5 , V_27 ) ;
if ( ( V_27 < V_40 - 2 ) && F_13 ( F_9 ( V_36 ) ) ) {
struct V_5 * V_44 , * V_45 ;
V_37 = V_39 & V_35 ;
V_44 = V_5 + ( V_37 - V_35 ) ;
V_39 = F_48 ( V_37 , V_27 + 1 ) ;
V_45 = V_5 + ( V_39 - V_37 ) ;
if ( F_49 ( V_44 , V_45 , V_27 + 1 ) ) {
F_57 ( & V_5 -> V_41 ,
& V_11 -> V_42 [ V_27 ] . V_46 [ V_6 ] ) ;
goto V_21;
}
}
F_58 ( & V_5 -> V_41 , & V_11 -> V_42 [ V_27 ] . V_46 [ V_6 ] ) ;
V_21:
V_11 -> V_42 [ V_27 ] . V_43 ++ ;
}
static inline void F_59 ( struct V_5 * V_5 )
{
F_60 ( V_5 , V_47 ) ;
F_61 ( V_48 ) ;
}
static inline int F_62 ( struct V_5 * V_5 )
{
if ( F_6 ( F_63 ( V_5 ) |
( V_5 -> V_49 != NULL ) |
( F_64 ( & V_5 -> V_50 ) != 0 ) |
( V_5 -> V_51 & V_52 ) |
( F_65 ( V_5 ) ) ) ) {
F_16 ( V_5 ) ;
return 1 ;
}
if ( V_5 -> V_51 & V_53 )
V_5 -> V_51 &= ~ V_53 ;
return 0 ;
}
static void F_66 ( struct V_11 * V_11 , int V_54 ,
struct V_55 * V_56 )
{
int V_6 = 0 ;
int V_57 = 0 ;
int V_58 = V_54 ;
F_67 ( & V_11 -> V_59 ) ;
V_11 -> V_60 = 0 ;
V_11 -> V_61 = 0 ;
while ( V_58 ) {
struct V_5 * V_5 ;
struct V_62 * V_63 ;
do {
V_57 ++ ;
if ( ++ V_6 == V_64 )
V_6 = 0 ;
V_63 = & V_56 -> V_65 [ V_6 ] ;
} while ( F_68 ( V_63 ) );
if ( V_57 == V_64 )
V_57 = V_58 ;
do {
V_5 = F_69 ( V_63 -> V_66 , struct V_5 , V_41 ) ;
F_56 ( & V_5 -> V_41 ) ;
F_54 ( V_5 , V_11 , 0 , F_70 ( V_5 ) ) ;
F_71 ( V_5 , 0 , F_70 ( V_5 ) ) ;
} while ( -- V_58 && -- V_57 && ! F_68 ( V_63 ) );
}
F_72 ( V_11 , V_67 , V_54 ) ;
F_73 ( & V_11 -> V_59 ) ;
}
static void F_74 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_27 ,
int V_6 )
{
F_67 ( & V_11 -> V_59 ) ;
V_11 -> V_60 = 0 ;
V_11 -> V_61 = 0 ;
F_54 ( V_5 , V_11 , V_27 , V_6 ) ;
F_72 ( V_11 , V_67 , 1 << V_27 ) ;
F_73 ( & V_11 -> V_59 ) ;
}
static bool F_75 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
int V_32 = 0 ;
F_76 ( V_5 , V_27 ) ;
F_77 ( V_5 , V_27 ) ;
if ( F_78 ( V_5 ) )
V_5 -> V_49 = NULL ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
V_32 += F_62 ( V_5 + V_28 ) ;
if ( V_32 )
return false ;
if ( ! F_79 ( V_5 ) ) {
F_80 ( F_81 ( V_5 ) , V_68 << V_27 ) ;
F_82 ( F_81 ( V_5 ) ,
V_68 << V_27 ) ;
}
F_83 ( V_5 , V_27 ) ;
F_84 ( V_5 , 1 << V_27 , 0 ) ;
return true ;
}
static void F_26 ( struct V_5 * V_5 , unsigned int V_27 )
{
unsigned long V_51 ;
int V_69 = F_85 ( V_5 ) ;
if ( ! F_75 ( V_5 , V_27 ) )
return;
F_86 ( V_51 ) ;
if ( F_6 ( V_69 ) )
F_59 ( V_5 ) ;
F_87 ( V_70 , 1 << V_27 ) ;
F_74 ( F_14 ( V_5 ) , V_5 , V_27 ,
F_88 ( V_5 ) ) ;
F_89 ( V_51 ) ;
}
void T_2 F_90 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( V_27 == 0 ) {
F_91 ( V_5 ) ;
F_33 ( V_5 , 0 ) ;
F_92 ( V_5 ) ;
F_93 ( V_5 ) ;
} else {
int V_71 ;
F_94 ( V_5 ) ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
struct V_5 * V_30 = & V_5 [ V_71 ] ;
if ( V_71 + 1 < V_72 )
F_94 ( V_30 + 1 ) ;
F_91 ( V_30 ) ;
F_33 ( V_30 , 0 ) ;
}
F_92 ( V_5 ) ;
F_95 ( V_5 , V_27 ) ;
}
}
static inline void F_96 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_73 , int V_74 , struct V_42 * V_75 ,
int V_6 )
{
unsigned long V_76 = 1 << V_74 ;
while ( V_74 > V_73 ) {
V_75 -- ;
V_74 -- ;
V_76 >>= 1 ;
F_40 ( F_15 ( V_11 , & V_5 [ V_76 ] ) ) ;
F_58 ( & V_5 [ V_76 ] . V_41 , & V_75 -> V_46 [ V_6 ] ) ;
V_75 -> V_43 ++ ;
F_43 ( & V_5 [ V_76 ] , V_74 ) ;
}
}
static inline int F_97 ( struct V_5 * V_5 )
{
if ( F_6 ( F_63 ( V_5 ) |
( V_5 -> V_49 != NULL ) |
( F_64 ( & V_5 -> V_50 ) != 0 ) |
( V_5 -> V_51 & V_53 ) |
( F_65 ( V_5 ) ) ) ) {
F_16 ( V_5 ) ;
return 1 ;
}
return 0 ;
}
static int F_98 ( struct V_5 * V_5 , int V_27 , T_1 V_33 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
if ( F_6 ( F_97 ( V_30 ) ) )
return 1 ;
}
F_44 ( V_5 , 0 ) ;
F_92 ( V_5 ) ;
F_99 ( V_5 , V_27 ) ;
F_84 ( V_5 , 1 << V_27 , 1 ) ;
if ( V_33 & V_77 )
F_39 ( V_5 , V_27 , V_33 ) ;
if ( V_27 && ( V_33 & V_78 ) )
F_28 ( V_5 , V_27 ) ;
return 0 ;
}
static inline
struct V_5 * F_100 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned int V_79 ;
struct V_42 * V_75 ;
struct V_5 * V_5 ;
for ( V_79 = V_27 ; V_79 < V_40 ; ++ V_79 ) {
V_75 = & ( V_11 -> V_42 [ V_79 ] ) ;
if ( F_68 ( & V_75 -> V_46 [ V_6 ] ) )
continue;
V_5 = F_69 ( V_75 -> V_46 [ V_6 ] . V_80 ,
struct V_5 , V_41 ) ;
F_56 ( & V_5 -> V_41 ) ;
F_46 ( V_5 ) ;
V_75 -> V_43 -- ;
F_96 ( V_11 , V_5 , V_27 , V_79 , V_75 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
static int F_101 ( struct V_11 * V_11 ,
struct V_5 * V_81 , struct V_5 * V_82 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_27 ;
int V_83 = 0 ;
#ifndef F_102
F_103 ( F_14 ( V_81 ) != F_14 ( V_82 ) ) ;
#endif
for ( V_5 = V_81 ; V_5 <= V_82 ; ) {
F_40 ( F_104 ( V_5 ) != F_105 ( V_11 ) ) ;
if ( ! F_13 ( F_9 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_51 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_27 = F_52 ( V_5 ) ;
F_106 ( & V_5 -> V_41 ,
& V_11 -> V_42 [ V_27 ] . V_46 [ V_6 ] ) ;
V_5 += 1 << V_27 ;
V_83 += 1 << V_27 ;
}
return V_83 ;
}
static int F_107 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_84 , V_85 ;
struct V_5 * V_81 , * V_82 ;
V_84 = F_9 ( V_5 ) ;
V_84 = V_84 & ~ ( V_86 - 1 ) ;
V_81 = F_108 ( V_84 ) ;
V_82 = V_81 + V_86 - 1 ;
V_85 = V_84 + V_86 - 1 ;
if ( V_84 < V_11 -> V_15 )
V_81 = V_5 ;
if ( V_85 >= V_11 -> V_15 + V_11 -> V_16 )
return 0 ;
return F_101 ( V_11 , V_81 , V_82 , V_6 ) ;
}
static void F_109 ( struct V_5 * V_87 ,
int V_88 , int V_6 )
{
int V_89 = 1 << ( V_88 - V_90 ) ;
while ( V_89 -- ) {
F_5 ( V_87 , V_6 ) ;
V_87 += V_86 ;
}
}
static inline struct V_5 *
F_110 ( struct V_11 * V_11 , int V_27 , int V_91 )
{
struct V_42 * V_75 ;
int V_79 ;
struct V_5 * V_5 ;
int V_6 , V_28 ;
for ( V_79 = V_40 - 1 ; V_79 >= V_27 ;
-- V_79 ) {
for ( V_28 = 0 ; V_28 < V_92 - 1 ; V_28 ++ ) {
V_6 = V_93 [ V_91 ] [ V_28 ] ;
if ( V_6 == V_94 )
continue;
V_75 = & ( V_11 -> V_42 [ V_79 ] ) ;
if ( F_68 ( & V_75 -> V_46 [ V_6 ] ) )
continue;
V_5 = F_69 ( V_75 -> V_46 [ V_6 ] . V_80 ,
struct V_5 , V_41 ) ;
V_75 -> V_43 -- ;
if ( F_6 ( V_79 >= ( V_90 >> 1 ) ) ||
V_91 == V_95 ||
V_7 ) {
unsigned long V_96 ;
V_96 = F_107 ( V_11 , V_5 ,
V_91 ) ;
if ( V_96 >= ( 1 << ( V_90 - 1 ) ) ||
V_7 )
F_5 ( V_5 ,
V_91 ) ;
V_6 = V_91 ;
}
F_56 ( & V_5 -> V_41 ) ;
F_46 ( V_5 ) ;
if ( V_79 >= V_90 )
F_109 ( V_5 , V_79 ,
V_91 ) ;
F_96 ( V_11 , V_5 , V_27 , V_79 , V_75 , V_6 ) ;
F_111 ( V_5 , V_27 , V_79 ,
V_91 , V_6 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_112 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
struct V_5 * V_5 ;
V_97:
V_5 = F_100 ( V_11 , V_27 , V_6 ) ;
if ( F_6 ( ! V_5 ) && V_6 != V_94 ) {
V_5 = F_110 ( V_11 , V_27 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_94 ;
goto V_97;
}
}
F_113 ( V_5 , V_27 , V_6 ) ;
return V_5 ;
}
static int F_114 ( struct V_11 * V_11 , unsigned int V_27 ,
unsigned long V_54 , struct V_62 * V_63 ,
int V_6 , int V_98 )
{
int V_28 ;
F_67 ( & V_11 -> V_59 ) ;
for ( V_28 = 0 ; V_28 < V_54 ; ++ V_28 ) {
struct V_5 * V_5 = F_112 ( V_11 , V_27 , V_6 ) ;
if ( F_6 ( V_5 == NULL ) )
break;
if ( F_115 ( V_98 == 0 ) )
F_58 ( & V_5 -> V_41 , V_63 ) ;
else
F_57 ( & V_5 -> V_41 , V_63 ) ;
F_44 ( V_5 , V_6 ) ;
V_63 = & V_5 -> V_41 ;
}
F_72 ( V_11 , V_67 , - ( V_28 << V_27 ) ) ;
F_73 ( & V_11 -> V_59 ) ;
return V_28 ;
}
void F_116 ( struct V_11 * V_11 , struct V_55 * V_56 )
{
unsigned long V_51 ;
int V_99 ;
F_86 ( V_51 ) ;
if ( V_56 -> V_54 >= V_56 -> V_100 )
V_99 = V_56 -> V_100 ;
else
V_99 = V_56 -> V_54 ;
F_66 ( V_11 , V_99 , V_56 ) ;
V_56 -> V_54 -= V_99 ;
F_89 ( V_51 ) ;
}
static void F_117 ( unsigned int V_101 )
{
unsigned long V_51 ;
struct V_11 * V_11 ;
F_118 (zone) {
struct V_102 * V_103 ;
struct V_55 * V_56 ;
F_86 ( V_51 ) ;
V_103 = F_119 ( V_11 -> V_104 , V_101 ) ;
V_56 = & V_103 -> V_56 ;
if ( V_56 -> V_54 ) {
F_66 ( V_11 , V_56 -> V_54 , V_56 ) ;
V_56 -> V_54 = 0 ;
}
F_89 ( V_51 ) ;
}
}
void F_120 ( void * V_105 )
{
F_117 ( F_121 () ) ;
}
void F_122 ( void )
{
F_123 ( F_120 , NULL , 1 ) ;
}
void F_124 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_106 ;
unsigned long V_51 ;
int V_27 , V_107 ;
struct V_62 * V_108 ;
if ( ! V_11 -> V_16 )
return;
F_125 ( & V_11 -> V_59 , V_51 ) ;
V_106 = V_11 -> V_15 + V_11 -> V_16 ;
for ( V_14 = V_11 -> V_15 ; V_14 < V_106 ; V_14 ++ )
if ( F_126 ( V_14 ) ) {
struct V_5 * V_5 = F_108 ( V_14 ) ;
if ( ! F_127 ( V_5 ) )
F_128 ( V_5 ) ;
}
F_129 (order, t) {
F_130 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_28 ;
V_14 = F_9 ( F_69 ( V_108 , struct V_5 , V_41 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1UL << V_27 ) ; V_28 ++ )
F_131 ( F_108 ( V_14 + V_28 ) ) ;
}
}
F_132 ( & V_11 -> V_59 , V_51 ) ;
}
void F_133 ( struct V_5 * V_5 , int V_98 )
{
struct V_11 * V_11 = F_14 ( V_5 ) ;
struct V_55 * V_56 ;
unsigned long V_51 ;
int V_6 ;
int V_69 = F_85 ( V_5 ) ;
if ( ! F_75 ( V_5 , 0 ) )
return;
V_6 = F_88 ( V_5 ) ;
F_44 ( V_5 , V_6 ) ;
F_86 ( V_51 ) ;
if ( F_6 ( V_69 ) )
F_59 ( V_5 ) ;
F_61 ( V_70 ) ;
if ( V_6 >= V_64 ) {
if ( F_6 ( V_6 == V_109 ) ) {
F_74 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_21;
}
V_6 = V_110 ;
}
V_56 = & F_134 ( V_11 -> V_104 ) -> V_56 ;
if ( V_98 )
F_57 ( & V_5 -> V_41 , & V_56 -> V_65 [ V_6 ] ) ;
else
F_58 ( & V_5 -> V_41 , & V_56 -> V_65 [ V_6 ] ) ;
V_56 -> V_54 ++ ;
if ( V_56 -> V_54 >= V_56 -> V_74 ) {
F_66 ( V_11 , V_56 -> V_100 , V_56 ) ;
V_56 -> V_54 -= V_56 -> V_100 ;
}
V_21:
F_89 ( V_51 ) ;
}
void F_135 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
F_40 ( F_55 ( V_5 ) ) ;
F_40 ( ! F_53 ( V_5 ) ) ;
#ifdef F_136
if ( F_137 ( V_5 ) )
F_135 ( F_138 ( V_5 [ 0 ] . V_111 ) , V_27 ) ;
#endif
for ( V_28 = 1 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_92 ( V_5 + V_28 ) ;
}
int F_139 ( struct V_5 * V_5 )
{
unsigned int V_27 ;
unsigned long V_112 ;
struct V_11 * V_11 ;
F_103 ( ! F_51 ( V_5 ) ) ;
V_11 = F_14 ( V_5 ) ;
V_27 = F_52 ( V_5 ) ;
V_112 = F_140 ( V_11 ) + ( 1 << V_27 ) ;
if ( ! F_141 ( V_11 , 0 , V_112 , 0 , 0 ) )
return 0 ;
F_56 ( & V_5 -> V_41 ) ;
V_11 -> V_42 [ V_27 ] . V_43 -- ;
F_46 ( V_5 ) ;
F_72 ( V_11 , V_67 , - ( 1UL << V_27 ) ) ;
F_92 ( V_5 ) ;
F_135 ( V_5 , V_27 ) ;
if ( V_27 >= V_90 - 1 ) {
struct V_5 * V_113 = V_5 + ( 1 << V_27 ) - 1 ;
for (; V_5 < V_113 ; V_5 += V_86 )
F_5 ( V_5 , V_110 ) ;
}
return 1 << V_27 ;
}
static inline
struct V_5 * F_142 ( struct V_11 * V_114 ,
struct V_11 * V_11 , int V_27 , T_1 V_33 ,
int V_6 )
{
unsigned long V_51 ;
struct V_5 * V_5 ;
int V_98 = ! ! ( V_33 & V_115 ) ;
V_116:
if ( F_115 ( V_27 == 0 ) ) {
struct V_55 * V_56 ;
struct V_62 * V_63 ;
F_86 ( V_51 ) ;
V_56 = & F_134 ( V_11 -> V_104 ) -> V_56 ;
V_63 = & V_56 -> V_65 [ V_6 ] ;
if ( F_68 ( V_63 ) ) {
V_56 -> V_54 += F_114 ( V_11 , 0 ,
V_56 -> V_100 , V_63 ,
V_6 , V_98 ) ;
if ( F_6 ( F_68 ( V_63 ) ) )
goto V_117;
}
if ( V_98 )
V_5 = F_69 ( V_63 -> V_66 , struct V_5 , V_41 ) ;
else
V_5 = F_69 ( V_63 -> V_80 , struct V_5 , V_41 ) ;
F_56 ( & V_5 -> V_41 ) ;
V_56 -> V_54 -- ;
} else {
if ( F_6 ( V_33 & V_118 ) ) {
F_143 ( V_27 > 1 ) ;
}
F_125 ( & V_11 -> V_59 , V_51 ) ;
V_5 = F_112 ( V_11 , V_27 , V_6 ) ;
F_73 ( & V_11 -> V_59 ) ;
if ( ! V_5 )
goto V_117;
F_72 ( V_11 , V_67 , - ( 1 << V_27 ) ) ;
}
F_144 ( V_119 , V_11 , 1 << V_27 ) ;
F_145 ( V_114 , V_11 , V_33 ) ;
F_89 ( V_51 ) ;
F_40 ( F_15 ( V_11 , V_5 ) ) ;
if ( F_98 ( V_5 , V_27 , V_33 ) )
goto V_116;
return V_5 ;
V_117:
F_89 ( V_51 ) ;
return NULL ;
}
static int T_3 F_146 ( char * V_120 )
{
return F_147 ( & V_121 . V_122 , V_120 ) ;
}
static int F_148 ( T_1 V_123 , unsigned int V_27 )
{
if ( V_27 < V_121 . V_124 )
return 0 ;
if ( V_123 & V_118 )
return 0 ;
if ( V_121 . V_125 && ( V_123 & V_34 ) )
return 0 ;
if ( V_121 . V_126 && ( V_123 & V_127 ) )
return 0 ;
return F_149 ( & V_121 . V_122 , 1 << V_27 ) ;
}
static int T_3 F_150 ( void )
{
T_4 V_128 = V_129 | V_130 | V_131 ;
struct V_132 * V_133 ;
V_133 = F_151 ( L_3 , NULL ,
& V_121 . V_122 ) ;
if ( F_152 ( V_133 ) )
return F_153 ( V_133 ) ;
if ( ! F_154 ( L_4 , V_128 , V_133 ,
& V_121 . V_126 ) )
goto V_134;
if ( ! F_154 ( L_5 , V_128 , V_133 ,
& V_121 . V_125 ) )
goto V_134;
if ( ! F_155 ( L_6 , V_128 , V_133 ,
& V_121 . V_124 ) )
goto V_134;
return 0 ;
V_134:
F_156 ( V_133 ) ;
return - V_135 ;
}
static inline int F_148 ( T_1 V_123 , unsigned int V_27 )
{
return 0 ;
}
static bool F_157 ( struct V_11 * V_136 , int V_27 , unsigned long V_137 ,
int V_138 , int V_139 , long V_140 )
{
long V_141 = V_137 ;
int V_142 ;
V_140 -= ( 1 << V_27 ) + 1 ;
if ( V_139 & V_143 )
V_141 -= V_141 / 2 ;
if ( V_139 & V_144 )
V_141 -= V_141 / 4 ;
if ( V_140 <= V_141 + V_136 -> V_145 [ V_138 ] )
return false ;
for ( V_142 = 0 ; V_142 < V_27 ; V_142 ++ ) {
V_140 -= V_136 -> V_42 [ V_142 ] . V_43 << V_142 ;
V_141 >>= 1 ;
if ( V_140 <= V_141 )
return false ;
}
return true ;
}
bool F_141 ( struct V_11 * V_136 , int V_27 , unsigned long V_137 ,
int V_138 , int V_139 )
{
return F_157 ( V_136 , V_27 , V_137 , V_138 , V_139 ,
F_158 ( V_136 , V_67 ) ) ;
}
bool F_159 ( struct V_11 * V_136 , int V_27 , unsigned long V_137 ,
int V_138 , int V_139 )
{
long V_140 = F_158 ( V_136 , V_67 ) ;
if ( V_136 -> V_146 && V_140 < V_136 -> V_146 )
V_140 = F_160 ( V_136 , V_67 ) ;
return F_157 ( V_136 , V_27 , V_137 , V_138 , V_139 ,
V_140 ) ;
}
static T_5 * F_161 ( struct V_147 * V_147 , int V_139 )
{
struct V_148 * V_149 ;
T_5 * V_150 ;
V_149 = V_147 -> V_151 ;
if ( ! V_149 )
return NULL ;
if ( F_162 ( V_20 , V_149 -> V_152 + V_23 ) ) {
F_163 ( V_149 -> V_153 , V_154 ) ;
V_149 -> V_152 = V_20 ;
}
V_150 = ! F_41 () && ( V_139 & V_155 ) ?
& V_156 :
& V_157 [ V_158 ] ;
return V_150 ;
}
static int F_164 ( struct V_147 * V_147 , struct V_159 * V_136 ,
T_5 * V_150 )
{
struct V_148 * V_149 ;
int V_28 ;
int V_160 ;
V_149 = V_147 -> V_151 ;
if ( ! V_149 )
return 1 ;
V_28 = V_136 - V_147 -> V_161 ;
V_160 = V_149 -> V_162 [ V_28 ] ;
return F_165 ( V_160 , * V_150 ) && ! F_166 ( V_28 , V_149 -> V_153 ) ;
}
static void F_167 ( struct V_147 * V_147 , struct V_159 * V_136 )
{
struct V_148 * V_149 ;
int V_28 ;
V_149 = V_147 -> V_151 ;
if ( ! V_149 )
return;
V_28 = V_136 - V_147 -> V_161 ;
F_168 ( V_28 , V_149 -> V_153 ) ;
}
static void F_169 ( struct V_147 * V_147 )
{
struct V_148 * V_149 ;
V_149 = V_147 -> V_151 ;
if ( ! V_149 )
return;
F_163 ( V_149 -> V_153 , V_154 ) ;
}
static T_5 * F_161 ( struct V_147 * V_147 , int V_139 )
{
return NULL ;
}
static int F_164 ( struct V_147 * V_147 , struct V_159 * V_136 ,
T_5 * V_150 )
{
return 1 ;
}
static void F_167 ( struct V_147 * V_147 , struct V_159 * V_136 )
{
}
static void F_169 ( struct V_147 * V_147 )
{
}
static struct V_5 *
F_170 ( T_1 V_123 , T_5 * V_163 , unsigned int V_27 ,
struct V_147 * V_147 , int V_164 , int V_139 ,
struct V_11 * V_114 , int V_6 )
{
struct V_159 * V_136 ;
struct V_5 * V_5 = NULL ;
int V_138 ;
struct V_11 * V_11 ;
T_5 * V_150 = NULL ;
int V_165 = 0 ;
int V_166 = 0 ;
V_138 = F_171 ( V_114 ) ;
V_167:
F_172 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( V_168 && V_165 &&
! F_164 ( V_147 , V_136 , V_150 ) )
continue;
if ( ( V_139 & V_155 ) &&
! F_173 ( V_11 , V_123 ) )
continue;
F_174 ( V_169 < V_170 ) ;
if ( ! ( V_139 & V_169 ) ) {
unsigned long V_137 ;
int V_12 ;
V_137 = V_11 -> V_112 [ V_139 & V_171 ] ;
if ( F_141 ( V_11 , V_27 , V_137 ,
V_138 , V_139 ) )
goto V_172;
if ( V_168 && ! V_166 && V_173 > 1 ) {
V_150 = F_161 ( V_147 , V_139 ) ;
V_165 = 1 ;
V_166 = 1 ;
}
if ( V_174 == 0 )
goto V_175;
if ( V_168 && V_165 &&
! F_164 ( V_147 , V_136 , V_150 ) )
continue;
V_12 = F_175 ( V_11 , V_123 , V_27 ) ;
switch ( V_12 ) {
case V_176 :
continue;
case V_177 :
continue;
default:
if ( ! F_141 ( V_11 , V_27 , V_137 ,
V_138 , V_139 ) )
goto V_175;
}
}
V_172:
V_5 = F_142 ( V_114 , V_11 , V_27 ,
V_123 , V_6 ) ;
if ( V_5 )
break;
V_175:
if ( V_168 )
F_167 ( V_147 , V_136 ) ;
}
if ( F_6 ( V_168 && V_5 == NULL && V_165 ) ) {
V_165 = 0 ;
goto V_167;
}
return V_5 ;
}
static inline bool F_176 ( void )
{
bool V_12 = false ;
#if V_178 > 8
V_12 = F_41 () ;
#endif
return V_12 ;
}
void F_177 ( T_1 V_123 , int V_27 , const char * V_179 , ... )
{
unsigned int V_180 = V_181 ;
if ( ( V_123 & V_182 ) || ! F_178 ( & V_183 ) )
return;
if ( ! ( V_123 & V_184 ) )
if ( F_179 ( V_185 ) ||
( V_24 -> V_51 & ( V_186 | V_187 ) ) )
V_180 &= ~ V_181 ;
if ( F_41 () || ! ( V_123 & V_127 ) )
V_180 &= ~ V_181 ;
if ( V_179 ) {
struct V_188 V_189 ;
T_6 args ;
va_start ( args , V_179 ) ;
V_189 . V_179 = V_179 ;
V_189 . V_190 = & args ;
F_180 ( L_7 , & V_189 ) ;
va_end ( args ) ;
}
F_180 ( L_8 ,
V_24 -> V_25 , V_27 , V_123 ) ;
F_23 () ;
if ( ! F_176 () )
F_181 ( V_180 ) ;
}
static inline int
F_182 ( T_1 V_123 , unsigned int V_27 ,
unsigned long V_191 )
{
if ( V_123 & V_192 )
return 0 ;
if ( V_27 <= V_193 )
return 1 ;
if ( V_123 & V_194 && V_191 < ( 1 << V_27 ) )
return 1 ;
if ( V_123 & V_118 )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_183 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_195 V_164 ,
T_5 * V_163 , struct V_11 * V_114 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_184 ( V_147 , V_123 ) ) {
F_185 ( 1 ) ;
return NULL ;
}
V_5 = F_170 ( V_123 | V_196 , V_163 ,
V_27 , V_147 , V_164 ,
V_197 | V_155 ,
V_114 , V_6 ) ;
if ( V_5 )
goto V_21;
if ( ! ( V_123 & V_118 ) ) {
if ( V_27 > V_193 )
goto V_21;
if ( V_164 < V_198 )
goto V_21;
if ( V_123 & V_199 )
goto V_21;
}
F_186 ( V_147 , V_123 , V_27 , V_163 ) ;
V_21:
F_187 ( V_147 , V_123 ) ;
return V_5 ;
}
static struct V_5 *
F_188 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_195 V_164 ,
T_5 * V_163 , int V_139 , struct V_11 * V_114 ,
int V_6 , unsigned long * V_200 ,
bool V_201 )
{
struct V_5 * V_5 ;
if ( ! V_27 || F_189 ( V_114 ) )
return NULL ;
V_24 -> V_51 |= V_186 ;
* V_200 = F_190 ( V_147 , V_27 , V_123 ,
V_163 , V_201 ) ;
V_24 -> V_51 &= ~ V_186 ;
if ( * V_200 != V_202 ) {
F_117 ( F_191 () ) ;
F_192 () ;
V_5 = F_170 ( V_123 , V_163 ,
V_27 , V_147 , V_164 ,
V_139 , V_114 ,
V_6 ) ;
if ( V_5 ) {
V_114 -> V_203 = 0 ;
V_114 -> V_204 = 0 ;
F_193 ( V_205 ) ;
return V_5 ;
}
F_193 ( V_206 ) ;
F_194 ( V_114 ) ;
F_195 () ;
}
return NULL ;
}
static inline struct V_5 *
F_188 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_195 V_164 ,
T_5 * V_163 , int V_139 , struct V_11 * V_114 ,
int V_6 , unsigned long * V_200 ,
bool V_201 )
{
return NULL ;
}
static inline struct V_5 *
F_196 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_195 V_164 ,
T_5 * V_163 , int V_139 , struct V_11 * V_114 ,
int V_6 , unsigned long * V_200 )
{
struct V_5 * V_5 = NULL ;
struct V_207 V_207 ;
bool V_208 = false ;
F_195 () ;
F_197 () ;
V_24 -> V_51 |= V_186 ;
F_198 ( V_123 ) ;
V_207 . V_209 = 0 ;
V_24 -> V_207 = & V_207 ;
* V_200 = F_199 ( V_147 , V_27 , V_123 , V_163 ) ;
V_24 -> V_207 = NULL ;
F_200 () ;
V_24 -> V_51 &= ~ V_186 ;
F_195 () ;
if ( F_6 ( ! ( * V_200 ) ) )
return NULL ;
if ( V_168 )
F_169 ( V_147 ) ;
V_210:
V_5 = F_170 ( V_123 , V_163 , V_27 ,
V_147 , V_164 ,
V_139 , V_114 ,
V_6 ) ;
if ( ! V_5 && ! V_208 ) {
F_122 () ;
V_208 = true ;
goto V_210;
}
return V_5 ;
}
static inline struct V_5 *
F_201 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_195 V_164 ,
T_5 * V_163 , struct V_11 * V_114 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_170 ( V_123 , V_163 , V_27 ,
V_147 , V_164 , V_169 ,
V_114 , V_6 ) ;
if ( ! V_5 && V_123 & V_118 )
F_202 ( V_114 , V_211 , V_23 / 50 ) ;
} while ( ! V_5 && ( V_123 & V_118 ) );
return V_5 ;
}
static inline
void F_203 ( unsigned int V_27 , struct V_147 * V_147 ,
enum V_195 V_164 ,
enum V_195 V_138 )
{
struct V_159 * V_136 ;
struct V_11 * V_11 ;
F_204 (zone, z, zonelist, high_zoneidx)
F_205 ( V_11 , V_27 , V_138 ) ;
}
static inline int
F_206 ( T_1 V_123 )
{
int V_139 = V_212 | V_155 ;
const T_1 V_213 = V_123 & V_127 ;
F_174 ( V_214 != ( V_215 T_1 ) V_143 ) ;
V_139 |= ( V_215 int ) ( V_123 & V_214 ) ;
if ( ! V_213 ) {
if ( ! ( V_123 & V_184 ) )
V_139 |= V_144 ;
V_139 &= ~ V_155 ;
} else if ( F_6 ( F_207 ( V_24 ) ) && ! F_41 () )
V_139 |= V_144 ;
if ( F_115 ( ! ( V_123 & V_184 ) ) ) {
if ( ! F_41 () &&
( ( V_24 -> V_51 & V_186 ) ||
F_6 ( F_179 ( V_185 ) ) ) )
V_139 |= V_169 ;
}
return V_139 ;
}
static inline struct V_5 *
F_208 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_195 V_164 ,
T_5 * V_163 , struct V_11 * V_114 ,
int V_6 )
{
const T_1 V_213 = V_123 & V_127 ;
struct V_5 * V_5 = NULL ;
int V_139 ;
unsigned long V_191 = 0 ;
unsigned long V_200 ;
bool V_201 = false ;
if ( V_27 >= V_40 ) {
F_143 ( ! ( V_123 & V_182 ) ) ;
return NULL ;
}
if ( V_168 && ( V_123 & V_216 ) == V_216 )
goto V_217;
V_218:
if ( ! ( V_123 & V_219 ) )
F_203 ( V_27 , V_147 , V_164 ,
F_171 ( V_114 ) ) ;
V_139 = F_206 ( V_123 ) ;
if ( ! ( V_139 & V_155 ) && ! V_163 )
F_209 ( V_147 , V_164 , NULL ,
& V_114 ) ;
V_220:
V_5 = F_170 ( V_123 , V_163 , V_27 , V_147 ,
V_164 , V_139 & ~ V_169 ,
V_114 , V_6 ) ;
if ( V_5 )
goto V_221;
if ( V_139 & V_169 ) {
V_5 = F_201 ( V_123 , V_27 ,
V_147 , V_164 , V_163 ,
V_114 , V_6 ) ;
if ( V_5 )
goto V_221;
}
if ( ! V_213 )
goto V_217;
if ( V_24 -> V_51 & V_186 )
goto V_217;
if ( F_179 ( V_185 ) && ! ( V_123 & V_118 ) )
goto V_217;
V_5 = F_188 ( V_123 , V_27 ,
V_147 , V_164 ,
V_163 ,
V_139 , V_114 ,
V_6 , & V_200 ,
V_201 ) ;
if ( V_5 )
goto V_221;
V_201 = true ;
V_5 = F_196 ( V_123 , V_27 ,
V_147 , V_164 ,
V_163 ,
V_139 , V_114 ,
V_6 , & V_200 ) ;
if ( V_5 )
goto V_221;
if ( ! V_200 ) {
if ( ( V_123 & V_222 ) && ! ( V_123 & V_192 ) ) {
if ( V_223 )
goto V_217;
V_5 = F_183 ( V_123 , V_27 ,
V_147 , V_164 ,
V_163 , V_114 ,
V_6 ) ;
if ( V_5 )
goto V_221;
if ( ! ( V_123 & V_118 ) ) {
if ( V_27 > V_193 )
goto V_217;
if ( V_164 < V_198 )
goto V_217;
}
goto V_218;
}
}
V_191 += V_200 ;
if ( F_182 ( V_123 , V_27 , V_191 ) ) {
F_202 ( V_114 , V_211 , V_23 / 50 ) ;
goto V_220;
} else {
V_5 = F_188 ( V_123 , V_27 ,
V_147 , V_164 ,
V_163 ,
V_139 , V_114 ,
V_6 , & V_200 ,
V_201 ) ;
if ( V_5 )
goto V_221;
}
V_217:
F_177 ( V_123 , V_27 , NULL ) ;
return V_5 ;
V_221:
if ( V_224 )
F_210 ( V_5 , V_27 , V_123 ) ;
return V_5 ;
}
struct V_5 *
F_211 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , T_5 * V_163 )
{
enum V_195 V_164 = F_212 ( V_123 ) ;
struct V_11 * V_114 ;
struct V_5 * V_5 ;
int V_6 = F_213 ( V_123 ) ;
V_123 &= V_3 ;
F_214 ( V_123 ) ;
F_215 ( V_123 & V_127 ) ;
if ( F_148 ( V_123 , V_27 ) )
return NULL ;
if ( F_6 ( ! V_147 -> V_161 -> V_11 ) )
return NULL ;
F_216 () ;
F_209 ( V_147 , V_164 ,
V_163 ? : & V_156 ,
& V_114 ) ;
if ( ! V_114 ) {
F_217 () ;
return NULL ;
}
V_5 = F_170 ( V_123 | V_196 , V_163 , V_27 ,
V_147 , V_164 , V_225 | V_155 ,
V_114 , V_6 ) ;
if ( F_6 ( ! V_5 ) )
V_5 = F_208 ( V_123 , V_27 ,
V_147 , V_164 , V_163 ,
V_114 , V_6 ) ;
F_217 () ;
F_218 ( V_5 , V_27 , V_123 , V_6 ) ;
return V_5 ;
}
unsigned long F_219 ( T_1 V_123 , unsigned int V_27 )
{
struct V_5 * V_5 ;
F_40 ( ( V_123 & V_34 ) != 0 ) ;
V_5 = F_220 ( V_123 , V_27 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_81 ( V_5 ) ;
}
unsigned long F_221 ( T_1 V_123 )
{
return F_219 ( V_123 | V_77 , 0 ) ;
}
void F_222 ( struct V_226 * V_227 )
{
int V_28 = F_223 ( V_227 ) ;
while ( -- V_28 >= 0 ) {
F_224 ( V_227 -> V_96 [ V_28 ] , V_227 -> V_98 ) ;
F_133 ( V_227 -> V_96 [ V_28 ] , V_227 -> V_98 ) ;
}
}
void F_95 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( F_225 ( V_5 ) ) {
if ( V_27 == 0 )
F_133 ( V_5 , 0 ) ;
else
F_26 ( V_5 , V_27 ) ;
}
}
void V_140 ( unsigned long V_228 , unsigned int V_27 )
{
if ( V_228 != 0 ) {
F_40 ( ! F_226 ( ( void * ) V_228 ) ) ;
F_95 ( F_138 ( ( void * ) V_228 ) , V_27 ) ;
}
}
static void * F_227 ( unsigned long V_228 , unsigned V_27 , T_7 V_76 )
{
if ( V_228 ) {
unsigned long V_229 = V_228 + ( V_68 << V_27 ) ;
unsigned long V_230 = V_228 + F_228 ( V_76 ) ;
F_135 ( F_138 ( ( void * ) V_228 ) , V_27 ) ;
while ( V_230 < V_229 ) {
F_229 ( V_230 ) ;
V_230 += V_68 ;
}
}
return ( void * ) V_228 ;
}
void * F_230 ( T_7 V_76 , T_1 V_123 )
{
unsigned int V_27 = F_231 ( V_76 ) ;
unsigned long V_228 ;
V_228 = F_219 ( V_123 , V_27 ) ;
return F_227 ( V_228 , V_27 , V_76 ) ;
}
void * F_232 ( int V_231 , T_7 V_76 , T_1 V_123 )
{
unsigned V_27 = F_231 ( V_76 ) ;
struct V_5 * V_30 = F_233 ( V_231 , V_123 , V_27 ) ;
if ( ! V_30 )
return NULL ;
return F_227 ( ( unsigned long ) F_81 ( V_30 ) , V_27 , V_76 ) ;
}
void F_234 ( void * V_232 , T_7 V_76 )
{
unsigned long V_228 = ( unsigned long ) V_232 ;
unsigned long V_233 = V_228 + F_228 ( V_76 ) ;
while ( V_228 < V_233 ) {
F_229 ( V_228 ) ;
V_228 += V_68 ;
}
}
static unsigned int F_235 ( int V_234 )
{
struct V_159 * V_136 ;
struct V_11 * V_11 ;
unsigned int V_235 = 0 ;
struct V_147 * V_147 = F_236 ( F_237 () , V_236 ) ;
F_204 (zone, z, zonelist, offset) {
unsigned long V_76 = V_11 -> V_237 ;
unsigned long V_74 = F_238 ( V_11 ) ;
if ( V_76 > V_74 )
V_235 += V_76 - V_74 ;
}
return V_235 ;
}
unsigned int F_239 ( void )
{
return F_235 ( F_212 ( V_238 ) ) ;
}
unsigned int F_240 ( void )
{
return F_235 ( F_212 ( V_239 ) ) ;
}
static inline void F_241 ( struct V_11 * V_11 )
{
if ( V_168 )
F_20 ( L_9 , F_105 ( V_11 ) ) ;
}
void F_242 ( struct V_240 * V_241 )
{
V_241 -> V_242 = V_243 ;
V_241 -> V_244 = 0 ;
V_241 -> V_245 = F_243 ( V_67 ) ;
V_241 -> V_246 = F_244 () ;
V_241 -> V_247 = V_248 ;
V_241 -> V_249 = F_245 () ;
V_241 -> V_250 = V_68 ;
}
void F_246 ( struct V_240 * V_241 , int V_231 )
{
T_8 * V_251 = F_247 ( V_231 ) ;
V_241 -> V_242 = V_251 -> V_252 ;
V_241 -> V_245 = F_248 ( V_231 , V_67 ) ;
#ifdef F_249
V_241 -> V_247 = V_251 -> V_253 [ V_254 ] . V_237 ;
V_241 -> V_249 = F_158 ( & V_251 -> V_253 [ V_254 ] ,
V_67 ) ;
#else
V_241 -> V_247 = 0 ;
V_241 -> V_249 = 0 ;
#endif
V_241 -> V_250 = V_68 ;
}
bool F_250 ( unsigned int V_51 , int V_231 )
{
bool V_12 = false ;
if ( ! ( V_51 & V_181 ) )
goto V_21;
F_216 () ;
V_12 = ! F_165 ( V_231 , V_156 ) ;
F_217 () ;
V_21:
return V_12 ;
}
void F_251 ( unsigned int V_180 )
{
int V_101 ;
struct V_11 * V_11 ;
F_118 (zone) {
if ( F_250 ( V_180 , F_105 ( V_11 ) ) )
continue;
F_241 ( V_11 ) ;
F_20 ( L_10 , V_11 -> V_255 ) ;
F_252 (cpu) {
struct V_102 * V_104 ;
V_104 = F_119 ( V_11 -> V_104 , V_101 ) ;
F_20 ( L_11 ,
V_101 , V_104 -> V_56 . V_74 ,
V_104 -> V_56 . V_100 , V_104 -> V_56 . V_54 ) ;
}
}
F_20 ( L_12
L_13
L_14
L_15
L_16
L_17 ,
F_243 ( V_256 ) ,
F_243 ( V_257 ) ,
F_243 ( V_258 ) ,
F_243 ( V_259 ) ,
F_243 ( V_260 ) ,
F_243 ( V_261 ) ,
F_243 ( V_262 ) ,
F_243 ( V_263 ) ,
F_243 ( V_264 ) ,
F_243 ( V_265 ) ,
F_243 ( V_67 ) ,
F_243 ( V_266 ) ,
F_243 ( V_267 ) ,
F_243 ( V_268 ) ,
F_243 ( V_269 ) ,
F_243 ( V_270 ) ,
F_243 ( V_271 ) ) ;
F_118 (zone) {
int V_28 ;
if ( F_250 ( V_180 , F_105 ( V_11 ) ) )
continue;
F_241 ( V_11 ) ;
F_20 ( L_18
L_19
L_20
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
L_45 ,
V_11 -> V_255 ,
F_253 ( F_158 ( V_11 , V_67 ) ) ,
F_253 ( F_254 ( V_11 ) ) ,
F_253 ( F_140 ( V_11 ) ) ,
F_253 ( F_238 ( V_11 ) ) ,
F_253 ( F_158 ( V_11 , V_256 ) ) ,
F_253 ( F_158 ( V_11 , V_257 ) ) ,
F_253 ( F_158 ( V_11 , V_259 ) ) ,
F_253 ( F_158 ( V_11 , V_260 ) ) ,
F_253 ( F_158 ( V_11 , V_262 ) ) ,
F_253 ( F_158 ( V_11 , V_258 ) ) ,
F_253 ( F_158 ( V_11 , V_261 ) ) ,
F_253 ( V_11 -> V_237 ) ,
F_253 ( F_158 ( V_11 , V_47 ) ) ,
F_253 ( F_158 ( V_11 , V_263 ) ) ,
F_253 ( F_158 ( V_11 , V_264 ) ) ,
F_253 ( F_158 ( V_11 , V_268 ) ) ,
F_253 ( F_158 ( V_11 , V_269 ) ) ,
F_253 ( F_158 ( V_11 , V_266 ) ) ,
F_253 ( F_158 ( V_11 , V_267 ) ) ,
F_158 ( V_11 , V_272 ) *
V_273 / 1024 ,
F_253 ( F_158 ( V_11 , V_270 ) ) ,
F_253 ( F_158 ( V_11 , V_265 ) ) ,
F_253 ( F_158 ( V_11 , V_271 ) ) ,
F_253 ( F_158 ( V_11 , V_274 ) ) ,
V_11 -> V_61 ,
( V_11 -> V_60 ? L_46 : L_47 )
) ;
F_20 ( L_48 ) ;
for ( V_28 = 0 ; V_28 < V_275 ; V_28 ++ )
F_20 ( L_49 , V_11 -> V_145 [ V_28 ] ) ;
F_20 ( L_45 ) ;
}
F_118 (zone) {
unsigned long V_276 [ V_40 ] , V_51 , V_27 , V_277 = 0 ;
if ( F_250 ( V_180 , F_105 ( V_11 ) ) )
continue;
F_241 ( V_11 ) ;
F_20 ( L_50 , V_11 -> V_255 ) ;
F_125 ( & V_11 -> V_59 , V_51 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
V_276 [ V_27 ] = V_11 -> V_42 [ V_27 ] . V_43 ;
V_277 += V_276 [ V_27 ] << V_27 ;
}
F_132 ( & V_11 -> V_59 , V_51 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ )
F_20 ( L_51 , V_276 [ V_27 ] , F_253 ( 1UL ) << V_27 ) ;
F_20 ( L_52 , F_253 ( V_277 ) ) ;
}
F_20 ( L_53 , F_243 ( V_278 ) ) ;
F_255 () ;
}
static void F_256 ( struct V_11 * V_11 , struct V_159 * V_159 )
{
V_159 -> V_11 = V_11 ;
V_159 -> F_171 = F_171 ( V_11 ) ;
}
static int F_257 ( T_8 * V_251 , struct V_147 * V_147 ,
int V_279 , enum V_195 V_195 )
{
struct V_11 * V_11 ;
F_103 ( V_195 >= V_275 ) ;
V_195 ++ ;
do {
V_195 -- ;
V_11 = V_251 -> V_253 + V_195 ;
if ( F_258 ( V_11 ) ) {
F_256 ( V_11 ,
& V_147 -> V_161 [ V_279 ++ ] ) ;
F_259 ( V_195 ) ;
}
} while ( V_195 );
return V_279 ;
}
static int F_260 ( char * V_280 )
{
if ( * V_280 == 'd' || * V_280 == 'D' ) {
V_281 = V_282 ;
} else if ( * V_280 == 'n' || * V_280 == 'N' ) {
V_281 = V_283 ;
} else if ( * V_280 == 'z' || * V_280 == 'Z' ) {
V_281 = V_284 ;
} else {
F_20 ( V_285
L_54
L_55 , V_280 ) ;
return - V_286 ;
}
return 0 ;
}
static T_3 int F_261 ( char * V_280 )
{
int V_12 ;
if ( ! V_280 )
return 0 ;
V_12 = F_260 ( V_280 ) ;
if ( V_12 == 0 )
F_262 ( V_287 , V_280 , V_288 ) ;
return V_12 ;
}
int F_263 ( T_9 * V_289 , int V_290 ,
void T_10 * V_291 , T_7 * V_292 ,
T_11 * V_293 )
{
char V_294 [ V_288 ] ;
int V_12 ;
static F_264 ( V_295 ) ;
F_265 ( & V_295 ) ;
if ( V_290 )
strcpy ( V_294 , ( char * ) V_289 -> V_296 ) ;
V_12 = F_266 ( V_289 , V_290 , V_291 , V_292 , V_293 ) ;
if ( V_12 )
goto V_21;
if ( V_290 ) {
int V_297 = V_281 ;
if ( F_260 ( ( char * ) V_289 -> V_296 ) ) {
strncpy ( ( char * ) V_289 -> V_296 , V_294 ,
V_288 ) ;
V_281 = V_297 ;
} else if ( V_297 != V_281 ) {
F_265 ( & V_298 ) ;
F_267 ( NULL ) ;
F_268 ( & V_298 ) ;
}
}
V_21:
F_268 ( & V_295 ) ;
return V_12 ;
}
static int F_269 ( int V_299 , T_5 * V_300 )
{
int V_160 , V_241 ;
int V_301 = V_302 ;
int V_303 = - 1 ;
const struct V_304 * V_305 = F_270 ( 0 ) ;
if ( ! F_165 ( V_299 , * V_300 ) ) {
F_271 ( V_299 , * V_300 ) ;
return V_299 ;
}
F_272 (n, N_HIGH_MEMORY) {
if ( F_165 ( V_160 , * V_300 ) )
continue;
V_241 = F_273 ( V_299 , V_160 ) ;
V_241 += ( V_160 < V_299 ) ;
V_305 = F_270 ( V_160 ) ;
if ( ! F_274 ( V_305 ) )
V_241 += V_306 ;
V_241 *= ( V_307 * V_308 ) ;
V_241 += V_309 [ V_160 ] ;
if ( V_241 < V_301 ) {
V_301 = V_241 ;
V_303 = V_160 ;
}
}
if ( V_303 >= 0 )
F_271 ( V_303 , * V_300 ) ;
return V_303 ;
}
static void F_275 ( T_8 * V_251 , int V_299 )
{
int V_310 ;
struct V_147 * V_147 ;
V_147 = & V_251 -> V_311 [ 0 ] ;
for ( V_310 = 0 ; V_147 -> V_161 [ V_310 ] . V_11 != NULL ; V_310 ++ )
;
V_310 = F_257 ( F_247 ( V_299 ) , V_147 , V_310 ,
V_275 - 1 ) ;
V_147 -> V_161 [ V_310 ] . V_11 = NULL ;
V_147 -> V_161 [ V_310 ] . F_171 = 0 ;
}
static void F_276 ( T_8 * V_251 )
{
int V_310 ;
struct V_147 * V_147 ;
V_147 = & V_251 -> V_311 [ 1 ] ;
V_310 = F_257 ( V_251 , V_147 , 0 , V_275 - 1 ) ;
V_147 -> V_161 [ V_310 ] . V_11 = NULL ;
V_147 -> V_161 [ V_310 ] . F_171 = 0 ;
}
static void F_277 ( T_8 * V_251 , int V_312 )
{
int V_313 , V_310 , V_299 ;
int V_195 ;
struct V_11 * V_136 ;
struct V_147 * V_147 ;
V_147 = & V_251 -> V_311 [ 0 ] ;
V_313 = 0 ;
for ( V_195 = V_275 - 1 ; V_195 >= 0 ; V_195 -- ) {
for ( V_310 = 0 ; V_310 < V_312 ; V_310 ++ ) {
V_299 = V_314 [ V_310 ] ;
V_136 = & F_247 ( V_299 ) -> V_253 [ V_195 ] ;
if ( F_258 ( V_136 ) ) {
F_256 ( V_136 ,
& V_147 -> V_161 [ V_313 ++ ] ) ;
F_259 ( V_195 ) ;
}
}
}
V_147 -> V_161 [ V_313 ] . V_11 = NULL ;
V_147 -> V_161 [ V_313 ] . F_171 = 0 ;
}
static int F_278 ( void )
{
int V_231 , V_195 ;
unsigned long V_315 , V_316 ;
struct V_11 * V_136 ;
int V_317 ;
V_315 = 0 ;
V_316 = 0 ;
F_279 (nid) {
for ( V_195 = 0 ; V_195 < V_275 ; V_195 ++ ) {
V_136 = & F_247 ( V_231 ) -> V_253 [ V_195 ] ;
if ( F_258 ( V_136 ) ) {
if ( V_195 < V_198 )
V_315 += V_136 -> V_237 ;
V_316 += V_136 -> V_237 ;
} else if ( V_195 == V_198 ) {
return V_283 ;
}
}
}
if ( ! V_315 ||
V_315 > V_316 / 2 )
return V_283 ;
V_317 = V_316 /
( F_280 ( V_157 [ V_158 ] ) + 1 ) ;
F_279 (nid) {
V_315 = 0 ;
V_316 = 0 ;
for ( V_195 = 0 ; V_195 < V_275 ; V_195 ++ ) {
V_136 = & F_247 ( V_231 ) -> V_253 [ V_195 ] ;
if ( F_258 ( V_136 ) ) {
if ( V_195 < V_198 )
V_315 += V_136 -> V_237 ;
V_316 += V_136 -> V_237 ;
}
}
if ( V_315 &&
V_316 > V_317 &&
V_315 > V_316 * 70 / 100 )
return V_283 ;
}
return V_284 ;
}
static void F_281 ( void )
{
if ( V_281 == V_282 )
V_318 = F_278 () ;
else
V_318 = V_281 ;
}
static void F_282 ( T_8 * V_251 )
{
int V_310 , V_299 , V_319 ;
enum V_195 V_28 ;
T_5 V_320 ;
int V_321 , V_322 ;
struct V_147 * V_147 ;
int V_27 = V_318 ;
for ( V_28 = 0 ; V_28 < V_323 ; V_28 ++ ) {
V_147 = V_251 -> V_311 + V_28 ;
V_147 -> V_161 [ 0 ] . V_11 = NULL ;
V_147 -> V_161 [ 0 ] . F_171 = 0 ;
}
V_321 = V_251 -> V_324 ;
V_319 = V_173 ;
V_322 = V_321 ;
F_283 ( V_320 ) ;
memset ( V_314 , 0 , sizeof( V_314 ) ) ;
V_310 = 0 ;
while ( ( V_299 = F_269 ( V_321 , & V_320 ) ) >= 0 ) {
int V_325 = F_273 ( V_321 , V_299 ) ;
if ( V_325 > V_326 )
V_174 = 1 ;
if ( V_325 != F_273 ( V_321 , V_322 ) )
V_309 [ V_299 ] = V_319 ;
V_322 = V_299 ;
V_319 -- ;
if ( V_27 == V_283 )
F_275 ( V_251 , V_299 ) ;
else
V_314 [ V_310 ++ ] = V_299 ;
}
if ( V_27 == V_284 ) {
F_277 ( V_251 , V_310 ) ;
}
F_276 ( V_251 ) ;
}
static void F_284 ( T_8 * V_251 )
{
struct V_147 * V_147 ;
struct V_148 * V_149 ;
struct V_159 * V_136 ;
V_147 = & V_251 -> V_311 [ 0 ] ;
V_147 -> V_151 = V_149 = & V_147 -> V_327 ;
F_163 ( V_149 -> V_153 , V_154 ) ;
for ( V_136 = V_147 -> V_161 ; V_136 -> V_11 ; V_136 ++ )
V_149 -> V_162 [ V_136 - V_147 -> V_161 ] = F_285 ( V_136 ) ;
}
int F_286 ( int V_299 )
{
struct V_11 * V_11 ;
( void ) F_209 ( F_236 ( V_299 , V_236 ) ,
F_212 ( V_236 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_299 ;
}
static void F_281 ( void )
{
V_318 = V_284 ;
}
static void F_282 ( T_8 * V_251 )
{
int V_299 , V_321 ;
enum V_195 V_310 ;
struct V_147 * V_147 ;
V_321 = V_251 -> V_324 ;
V_147 = & V_251 -> V_311 [ 0 ] ;
V_310 = F_257 ( V_251 , V_147 , 0 , V_275 - 1 ) ;
for ( V_299 = V_321 + 1 ; V_299 < V_308 ; V_299 ++ ) {
if ( ! F_287 ( V_299 ) )
continue;
V_310 = F_257 ( F_247 ( V_299 ) , V_147 , V_310 ,
V_275 - 1 ) ;
}
for ( V_299 = 0 ; V_299 < V_321 ; V_299 ++ ) {
if ( ! F_287 ( V_299 ) )
continue;
V_310 = F_257 ( F_247 ( V_299 ) , V_147 , V_310 ,
V_275 - 1 ) ;
}
V_147 -> V_161 [ V_310 ] . V_11 = NULL ;
V_147 -> V_161 [ V_310 ] . F_171 = 0 ;
}
static void F_284 ( T_8 * V_251 )
{
V_251 -> V_311 [ 0 ] . V_151 = NULL ;
}
static T_12 int F_288 ( void * V_296 )
{
int V_231 ;
int V_101 ;
#ifdef F_289
memset ( V_309 , 0 , sizeof( V_309 ) ) ;
#endif
F_279 (nid) {
T_8 * V_251 = F_247 ( V_231 ) ;
F_282 ( V_251 ) ;
F_284 ( V_251 ) ;
}
F_290 (cpu) {
F_291 ( & F_292 ( V_328 , V_101 ) , 0 ) ;
#ifdef F_293
if ( F_294 ( V_101 ) )
F_295 ( V_101 , F_286 ( F_296 ( V_101 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_267 ( void * V_296 )
{
F_281 () ;
if ( V_329 == V_330 ) {
F_288 ( NULL ) ;
F_297 () ;
F_298 () ;
} else {
#ifdef F_299
if ( V_296 )
F_300 ( (struct V_11 * ) V_296 ) ;
#endif
F_301 ( F_288 , NULL , NULL ) ;
}
V_331 = F_240 () ;
if ( V_331 < ( V_86 * V_92 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_20 ( L_56
L_57 ,
V_173 ,
V_332 [ V_318 ] ,
V_7 ? L_58 : L_59 ,
V_331 ) ;
#ifdef F_289
F_20 ( L_60 , V_333 [ V_334 ] ) ;
#endif
}
static inline unsigned long F_302 ( unsigned long V_96 )
{
unsigned long V_76 = 1 ;
V_96 /= V_335 ;
while ( V_76 < V_96 )
V_76 <<= 1 ;
V_76 = V_141 ( V_76 , 4096UL ) ;
return F_303 ( V_76 , 4UL ) ;
}
static inline unsigned long F_302 ( unsigned long V_96 )
{
return 4096UL ;
}
static inline unsigned long F_304 ( unsigned long V_76 )
{
return F_305 ( ~ V_76 ) ;
}
static int F_306 ( unsigned long V_84 , unsigned long V_85 )
{
unsigned long V_14 ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 ++ ) {
if ( ! F_13 ( V_14 ) || F_307 ( F_108 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_308 ( struct V_11 * V_11 )
{
unsigned long V_84 , V_14 , V_85 , V_336 ;
struct V_5 * V_5 ;
unsigned long V_337 ;
int V_338 ;
V_84 = V_11 -> V_15 ;
V_85 = V_84 + V_11 -> V_16 ;
V_84 = F_309 ( V_84 , V_86 ) ;
V_338 = F_309 ( F_254 ( V_11 ) , V_86 ) >>
V_90 ;
V_338 = V_141 ( 2 , V_338 ) ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 += V_86 ) {
if ( ! F_126 ( V_14 ) )
continue;
V_5 = F_108 ( V_14 ) ;
if ( F_104 ( V_5 ) != F_105 ( V_11 ) )
continue;
V_336 = V_141 ( V_14 + V_86 , V_85 ) ;
if ( F_306 ( V_14 , V_336 ) )
continue;
V_337 = F_88 ( V_5 ) ;
if ( V_338 > 0 && V_337 == V_94 ) {
V_338 -- ;
continue;
}
if ( V_338 > 0 && V_337 == V_110 ) {
F_5 ( V_5 , V_94 ) ;
F_107 ( V_11 , V_5 , V_94 ) ;
V_338 -- ;
continue;
}
if ( V_337 == V_94 ) {
F_5 ( V_5 , V_110 ) ;
F_107 ( V_11 , V_5 , V_110 ) ;
}
}
}
void T_2 F_310 ( unsigned long V_76 , int V_231 , unsigned long V_11 ,
unsigned long V_84 , enum V_339 V_340 )
{
struct V_5 * V_5 ;
unsigned long V_85 = V_84 + V_76 ;
unsigned long V_14 ;
struct V_11 * V_136 ;
if ( V_341 < V_85 - 1 )
V_341 = V_85 - 1 ;
V_136 = & F_247 ( V_231 ) -> V_253 [ V_11 ] ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 ++ ) {
if ( V_340 == V_342 ) {
if ( ! F_311 ( V_14 ) )
continue;
if ( ! F_312 ( V_14 , V_231 ) )
continue;
}
V_5 = F_108 ( V_14 ) ;
F_313 ( V_5 , V_11 , V_231 , V_14 ) ;
F_314 ( V_5 , V_11 , V_231 , V_14 ) ;
F_315 ( V_5 ) ;
F_18 ( V_5 ) ;
F_316 ( V_5 ) ;
if ( ( V_136 -> V_15 <= V_14 )
&& ( V_14 < V_136 -> V_15 + V_136 -> V_16 )
&& ! ( V_14 & ( V_86 - 1 ) ) )
F_5 ( V_5 , V_110 ) ;
F_317 ( & V_5 -> V_41 ) ;
#ifdef F_318
if ( ! F_319 ( V_11 ) )
F_320 ( V_5 , F_321 ( V_14 << V_343 ) ) ;
#endif
}
}
static void T_2 F_322 ( struct V_11 * V_11 )
{
int V_27 , V_107 ;
F_129 (order, t) {
F_317 ( & V_11 -> V_42 [ V_27 ] . V_46 [ V_107 ] ) ;
V_11 -> V_42 [ V_27 ] . V_43 = 0 ;
}
}
static int F_323 ( struct V_11 * V_11 )
{
#ifdef F_324
int V_100 ;
V_100 = V_11 -> V_237 / 1024 ;
if ( V_100 * V_68 > 512 * 1024 )
V_100 = ( 512 * 1024 ) / V_68 ;
V_100 /= 4 ;
if ( V_100 < 1 )
V_100 = 1 ;
V_100 = F_325 ( V_100 + V_100 / 2 ) - 1 ;
return V_100 ;
#else
return 0 ;
#endif
}
static void F_291 ( struct V_102 * V_30 , unsigned long V_100 )
{
struct V_55 * V_56 ;
int V_6 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_56 = & V_30 -> V_56 ;
V_56 -> V_54 = 0 ;
V_56 -> V_74 = 6 * V_100 ;
V_56 -> V_100 = F_303 ( 1UL , 1 * V_100 ) ;
for ( V_6 = 0 ; V_6 < V_64 ; V_6 ++ )
F_317 ( & V_56 -> V_65 [ V_6 ] ) ;
}
static void F_326 ( struct V_102 * V_30 ,
unsigned long V_74 )
{
struct V_55 * V_56 ;
V_56 = & V_30 -> V_56 ;
V_56 -> V_74 = V_74 ;
V_56 -> V_100 = F_303 ( 1UL , V_74 / 4 ) ;
if ( ( V_74 / 4 ) > ( V_343 * 8 ) )
V_56 -> V_100 = V_343 * 8 ;
}
static void F_300 ( struct V_11 * V_11 )
{
int V_101 ;
V_11 -> V_104 = F_327 ( struct V_102 ) ;
F_290 (cpu) {
struct V_102 * V_56 = F_119 ( V_11 -> V_104 , V_101 ) ;
F_291 ( V_56 , F_323 ( V_11 ) ) ;
if ( V_344 )
F_326 ( V_56 ,
( V_11 -> V_237 /
V_344 ) ) ;
}
}
void T_3 F_328 ( void )
{
struct V_11 * V_11 ;
F_118 (zone)
F_300 ( V_11 ) ;
}
static T_14 T_12
int F_329 ( struct V_11 * V_11 , unsigned long V_345 )
{
int V_28 ;
struct V_346 * V_251 = V_11 -> V_347 ;
T_7 V_348 ;
V_11 -> F_302 =
F_302 ( V_345 ) ;
V_11 -> F_304 =
F_304 ( V_11 -> F_302 ) ;
V_348 = V_11 -> F_302
* sizeof( V_349 ) ;
if ( ! F_330 () ) {
V_11 -> V_350 = ( V_349 * )
F_331 ( V_251 , V_348 ) ;
} else {
V_11 -> V_350 = F_332 ( V_348 ) ;
}
if ( ! V_11 -> V_350 )
return - V_135 ;
for( V_28 = 0 ; V_28 < V_11 -> F_302 ; ++ V_28 )
F_333 ( V_11 -> V_350 + V_28 ) ;
return 0 ;
}
static int F_334 ( void * V_296 )
{
struct V_11 * V_11 = V_296 ;
int V_101 ;
unsigned long V_100 = F_323 ( V_11 ) , V_51 ;
F_290 (cpu) {
struct V_102 * V_103 ;
struct V_55 * V_56 ;
V_103 = F_119 ( V_11 -> V_104 , V_101 ) ;
V_56 = & V_103 -> V_56 ;
F_86 ( V_51 ) ;
F_66 ( V_11 , V_56 -> V_54 , V_56 ) ;
F_291 ( V_103 , V_100 ) ;
F_89 ( V_51 ) ;
}
return 0 ;
}
void F_335 ( struct V_11 * V_11 )
{
F_301 ( F_334 , V_11 , NULL ) ;
}
static T_2 void F_336 ( struct V_11 * V_11 )
{
V_11 -> V_104 = & V_328 ;
if ( V_11 -> V_237 )
F_20 ( V_351 L_61 ,
V_11 -> V_255 , V_11 -> V_237 ,
F_323 ( V_11 ) ) ;
}
T_2 int F_337 ( struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_76 ,
enum V_339 V_340 )
{
struct V_346 * V_251 = V_11 -> V_347 ;
int V_12 ;
V_12 = F_329 ( V_11 , V_76 ) ;
if ( V_12 )
return V_12 ;
V_251 -> V_279 = F_171 ( V_11 ) + 1 ;
V_11 -> V_15 = V_15 ;
F_338 ( V_352 , L_62 ,
L_63 ,
V_251 -> V_324 ,
( unsigned long ) F_171 ( V_11 ) ,
V_15 , ( V_15 + V_76 ) ) ;
F_322 ( V_11 ) ;
return 0 ;
}
static int T_2 F_339 ( int V_231 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_353 ; V_28 ++ )
if ( V_231 == V_308 || V_354 [ V_28 ] . V_231 == V_231 )
return V_28 ;
return - 1 ;
}
static int T_2 F_340 ( int V_355 , int V_231 )
{
for ( V_355 = V_355 + 1 ; V_355 < V_353 ; V_355 ++ )
if ( V_231 == V_308 || V_354 [ V_355 ] . V_231 == V_231 )
return V_355 ;
return - 1 ;
}
int T_2 F_341 ( unsigned long V_14 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_353 ; V_28 ++ ) {
unsigned long V_84 = V_354 [ V_28 ] . V_84 ;
unsigned long V_85 = V_354 [ V_28 ] . V_85 ;
if ( V_84 <= V_14 && V_14 < V_85 )
return V_354 [ V_28 ] . V_231 ;
}
return - 1 ;
}
int T_2 F_342 ( unsigned long V_14 )
{
int V_231 ;
V_231 = F_341 ( V_14 ) ;
if ( V_231 >= 0 )
return V_231 ;
return 0 ;
}
bool T_2 F_312 ( unsigned long V_14 , int V_299 )
{
int V_231 ;
V_231 = F_341 ( V_14 ) ;
if ( V_231 >= 0 && V_231 != V_299 )
return false ;
return true ;
}
void T_3 F_343 ( int V_231 ,
unsigned long V_356 )
{
int V_28 ;
F_344 (i, nid) {
unsigned long V_357 = 0 ;
unsigned long V_85 = V_354 [ V_28 ] . V_85 ;
if ( V_354 [ V_28 ] . V_84 >= V_356 )
continue;
if ( V_85 > V_356 )
V_85 = V_356 ;
V_357 = V_85 - V_354 [ V_28 ] . V_84 ;
F_345 ( F_247 ( V_354 [ V_28 ] . V_231 ) ,
F_346 ( V_354 [ V_28 ] . V_84 ) ,
V_357 << V_343 ) ;
}
}
static int T_2 F_347 ( int V_231 )
{
int V_28 ;
for ( V_28 = V_353 - 1 ; V_28 >= 0 ; V_28 -- )
if ( V_231 == V_308 || V_354 [ V_28 ] . V_231 == V_231 )
return V_28 ;
return - 1 ;
}
static int T_2 F_348 ( int V_355 , int V_231 )
{
for ( V_355 = V_355 - 1 ; V_355 >= 0 ; V_355 -- )
if ( V_231 == V_308 || V_354 [ V_355 ] . V_231 == V_231 )
return V_355 ;
return - 1 ;
}
T_15 T_3 F_349 ( int V_231 , T_15 V_76 , T_15 V_358 ,
T_15 V_359 , T_15 V_360 )
{
int V_28 ;
F_350 (i, nid) {
T_15 V_228 ;
T_15 V_361 , V_362 ;
T_15 V_363 , V_364 ;
V_362 = V_354 [ V_28 ] . V_85 ;
V_362 <<= V_343 ;
V_361 = V_354 [ V_28 ] . V_84 ;
V_361 <<= V_343 ;
V_363 = F_303 ( V_361 , V_359 ) ;
V_364 = V_141 ( V_362 , V_360 ) ;
if ( V_363 >= V_364 )
continue;
V_228 = F_351 ( V_363 , V_364 , V_76 , V_358 ) ;
if ( V_228 == V_365 )
continue;
return V_228 ;
}
return V_365 ;
}
int T_3 F_352 ( struct V_366 * V_366 , int V_367 ,
int V_368 , int V_231 )
{
int V_28 ;
T_15 V_369 , V_233 ;
F_344 (i, nid) {
V_369 = V_354 [ V_28 ] . V_84 ;
V_233 = V_354 [ V_28 ] . V_85 ;
V_368 = F_353 ( V_366 , V_367 , V_368 , V_369 , V_233 ) ;
}
return V_368 ;
}
void T_3 F_354 ( int V_231 , T_16 V_370 , void * V_296 )
{
int V_28 ;
int V_12 ;
F_344 (i, nid) {
V_12 = V_370 ( V_354 [ V_28 ] . V_84 ,
V_354 [ V_28 ] . V_85 , V_296 ) ;
if ( V_12 )
break;
}
}
void T_3 F_355 ( int V_231 )
{
int V_28 ;
F_344 (i, nid)
F_356 ( V_354 [ V_28 ] . V_231 ,
V_354 [ V_28 ] . V_84 ,
V_354 [ V_28 ] . V_85 ) ;
}
void T_2 F_357 ( unsigned int V_231 ,
unsigned long * V_84 , unsigned long * V_85 )
{
int V_28 ;
* V_84 = - 1UL ;
* V_85 = 0 ;
F_344 (i, nid) {
* V_84 = V_141 ( * V_84 , V_354 [ V_28 ] . V_84 ) ;
* V_85 = F_303 ( * V_85 , V_354 [ V_28 ] . V_85 ) ;
}
if ( * V_84 == - 1UL )
* V_84 = 0 ;
}
static void T_3 F_358 ( void )
{
int V_371 ;
for ( V_371 = V_275 - 1 ; V_371 >= 0 ; V_371 -- ) {
if ( V_371 == V_372 )
continue;
if ( V_373 [ V_371 ] >
V_374 [ V_371 ] )
break;
}
F_40 ( V_371 == - 1 ) ;
V_375 = V_371 ;
}
static void T_2 F_359 ( int V_231 ,
unsigned long V_195 ,
unsigned long V_376 ,
unsigned long V_377 ,
unsigned long * V_15 ,
unsigned long * V_378 )
{
if ( V_379 [ V_231 ] ) {
if ( V_195 == V_372 ) {
* V_15 = V_379 [ V_231 ] ;
* V_378 = V_141 ( V_377 ,
V_373 [ V_375 ] ) ;
} else if ( * V_15 < V_379 [ V_231 ] &&
* V_378 > V_379 [ V_231 ] ) {
* V_378 = V_379 [ V_231 ] ;
} else if ( * V_15 >= V_379 [ V_231 ] )
* V_15 = * V_378 ;
}
}
static unsigned long T_2 F_360 ( int V_231 ,
unsigned long V_195 ,
unsigned long * V_380 )
{
unsigned long V_376 , V_377 ;
unsigned long V_15 , V_378 ;
F_357 ( V_231 , & V_376 , & V_377 ) ;
V_15 = V_374 [ V_195 ] ;
V_378 = V_373 [ V_195 ] ;
F_359 ( V_231 , V_195 ,
V_376 , V_377 ,
& V_15 , & V_378 ) ;
if ( V_378 < V_376 || V_15 > V_377 )
return 0 ;
V_378 = V_141 ( V_378 , V_377 ) ;
V_15 = F_303 ( V_15 , V_376 ) ;
return V_378 - V_15 ;
}
unsigned long T_2 F_361 ( int V_231 ,
unsigned long V_381 ,
unsigned long V_382 )
{
int V_28 = 0 ;
unsigned long V_383 = 0 , V_384 = 0 ;
unsigned long V_84 ;
V_28 = F_339 ( V_231 ) ;
if ( V_28 == - 1 )
return 0 ;
V_383 = V_141 ( V_354 [ V_28 ] . V_84 , V_382 ) ;
if ( V_354 [ V_28 ] . V_84 > V_381 )
V_384 = V_383 - V_381 ;
for (; V_28 != - 1 ; V_28 = F_340 ( V_28 , V_231 ) ) {
if ( V_383 >= V_382 )
break;
V_84 = V_141 ( V_354 [ V_28 ] . V_84 , V_382 ) ;
V_383 = F_303 ( V_383 , V_381 ) ;
if ( V_84 > V_381 ) {
F_103 ( V_383 > V_84 ) ;
V_384 += V_84 - V_383 ;
}
V_383 = V_354 [ V_28 ] . V_85 ;
}
if ( V_382 > V_383 )
V_384 += V_382 -
F_303 ( V_381 , V_383 ) ;
return V_384 ;
}
unsigned long T_3 F_362 ( unsigned long V_84 ,
unsigned long V_85 )
{
return F_361 ( V_308 , V_84 , V_85 ) ;
}
static unsigned long T_2 F_363 ( int V_231 ,
unsigned long V_195 ,
unsigned long * V_380 )
{
unsigned long V_376 , V_377 ;
unsigned long V_15 , V_378 ;
F_357 ( V_231 , & V_376 , & V_377 ) ;
V_15 = F_303 ( V_374 [ V_195 ] ,
V_376 ) ;
V_378 = V_141 ( V_373 [ V_195 ] ,
V_377 ) ;
F_359 ( V_231 , V_195 ,
V_376 , V_377 ,
& V_15 , & V_378 ) ;
return F_361 ( V_231 , V_15 , V_378 ) ;
}
static inline unsigned long T_2 F_360 ( int V_231 ,
unsigned long V_195 ,
unsigned long * V_385 )
{
return V_385 [ V_195 ] ;
}
static inline unsigned long T_2 F_363 ( int V_231 ,
unsigned long V_195 ,
unsigned long * V_386 )
{
if ( ! V_386 )
return 0 ;
return V_386 [ V_195 ] ;
}
static void T_2 F_364 ( struct V_346 * V_251 ,
unsigned long * V_385 , unsigned long * V_386 )
{
unsigned long V_387 , V_388 = 0 ;
enum V_195 V_28 ;
for ( V_28 = 0 ; V_28 < V_275 ; V_28 ++ )
V_388 += F_360 ( V_251 -> V_324 , V_28 ,
V_385 ) ;
V_251 -> V_389 = V_388 ;
V_387 = V_388 ;
for ( V_28 = 0 ; V_28 < V_275 ; V_28 ++ )
V_387 -=
F_363 ( V_251 -> V_324 , V_28 ,
V_386 ) ;
V_251 -> V_252 = V_387 ;
F_20 ( V_351 L_64 , V_251 -> V_324 ,
V_387 ) ;
}
static unsigned long T_3 F_365 ( unsigned long V_390 )
{
unsigned long V_391 ;
V_391 = F_309 ( V_390 , V_86 ) ;
V_391 = V_391 >> V_90 ;
V_391 *= V_392 ;
V_391 = F_309 ( V_391 , 8 * sizeof( unsigned long ) ) ;
return V_391 / 8 ;
}
static void T_3 F_366 ( struct V_346 * V_251 ,
struct V_11 * V_11 , unsigned long V_390 )
{
unsigned long V_391 = F_365 ( V_390 ) ;
V_11 -> V_393 = NULL ;
if ( V_391 )
V_11 -> V_393 = F_331 ( V_251 ,
V_391 ) ;
}
static inline void F_366 ( struct V_346 * V_251 ,
struct V_11 * V_11 , unsigned long V_390 ) {}
static inline int F_367 ( void )
{
if ( V_394 > V_343 )
return V_395 ;
return V_40 - 1 ;
}
static inline void T_3 F_368 ( unsigned int V_27 )
{
if ( V_90 )
return;
V_90 = V_27 ;
}
static inline int F_367 ( unsigned int V_27 )
{
return V_40 - 1 ;
}
static void T_17 F_369 ( struct V_346 * V_251 ,
unsigned long * V_385 , unsigned long * V_386 )
{
enum V_195 V_310 ;
int V_231 = V_251 -> V_324 ;
unsigned long V_15 = V_251 -> V_376 ;
int V_12 ;
F_370 ( V_251 ) ;
V_251 -> V_279 = 0 ;
F_333 ( & V_251 -> V_396 ) ;
V_251 -> V_397 = 0 ;
F_371 ( V_251 ) ;
for ( V_310 = 0 ; V_310 < V_275 ; V_310 ++ ) {
struct V_11 * V_11 = V_251 -> V_253 + V_310 ;
unsigned long V_76 , V_398 , V_399 ;
enum V_400 V_401 ;
V_76 = F_360 ( V_231 , V_310 , V_385 ) ;
V_398 = V_76 - F_363 ( V_231 , V_310 ,
V_386 ) ;
V_399 =
F_228 ( V_76 * sizeof( struct V_5 ) ) >> V_343 ;
if ( V_398 >= V_399 ) {
V_398 -= V_399 ;
if ( V_399 )
F_20 ( V_351
L_65 ,
V_333 [ V_310 ] , V_399 ) ;
} else
F_20 ( V_285
L_66 ,
V_333 [ V_310 ] , V_399 , V_398 ) ;
if ( V_310 == 0 && V_398 > V_402 ) {
V_398 -= V_402 ;
F_20 ( V_351 L_67 ,
V_333 [ 0 ] , V_402 ) ;
}
if ( ! F_319 ( V_310 ) )
V_403 += V_398 ;
V_404 += V_398 ;
V_11 -> V_16 = V_76 ;
V_11 -> V_237 = V_398 ;
#ifdef F_289
V_11 -> V_299 = V_231 ;
V_11 -> V_405 = ( V_398 * V_406 )
/ 100 ;
V_11 -> V_407 = ( V_398 * V_408 ) / 100 ;
#endif
V_11 -> V_255 = V_333 [ V_310 ] ;
F_372 ( & V_11 -> V_59 ) ;
F_372 ( & V_11 -> V_409 ) ;
F_373 ( V_11 ) ;
V_11 -> V_347 = V_251 ;
F_336 ( V_11 ) ;
F_374 (l)
F_317 ( & V_11 -> V_41 [ V_401 ] . V_63 ) ;
V_11 -> V_410 . V_411 [ 0 ] = 0 ;
V_11 -> V_410 . V_411 [ 1 ] = 0 ;
V_11 -> V_410 . V_412 [ 0 ] = 0 ;
V_11 -> V_410 . V_412 [ 1 ] = 0 ;
F_375 ( V_11 ) ;
V_11 -> V_51 = 0 ;
if ( ! V_76 )
continue;
F_368 ( F_367 () ) ;
F_366 ( V_251 , V_11 , V_76 ) ;
V_12 = F_337 ( V_11 , V_15 ,
V_76 , V_342 ) ;
F_103 ( V_12 ) ;
F_376 ( V_76 , V_231 , V_310 , V_15 ) ;
V_15 += V_76 ;
}
}
static void T_12 F_377 ( struct V_346 * V_251 )
{
if ( ! V_251 -> V_389 )
return;
#ifdef F_378
if ( ! V_251 -> V_413 ) {
unsigned long V_76 , V_369 , V_233 ;
struct V_5 * V_414 ;
V_369 = V_251 -> V_376 & ~ ( V_415 - 1 ) ;
V_233 = V_251 -> V_376 + V_251 -> V_389 ;
V_233 = F_379 ( V_233 , V_415 ) ;
V_76 = ( V_233 - V_369 ) * sizeof( struct V_5 ) ;
V_414 = F_380 ( V_251 -> V_324 , V_76 ) ;
if ( ! V_414 )
V_414 = F_331 ( V_251 , V_76 ) ;
V_251 -> V_413 = V_414 + ( V_251 -> V_376 - V_369 ) ;
}
#ifndef F_381
if ( V_251 == F_247 ( 0 ) ) {
V_416 = F_247 ( 0 ) -> V_413 ;
#ifdef F_382
if ( F_9 ( V_416 ) != V_251 -> V_376 )
V_416 -= ( V_251 -> V_376 - V_417 ) ;
#endif
}
#endif
#endif
}
void T_17 F_383 ( int V_231 , unsigned long * V_385 ,
unsigned long V_376 , unsigned long * V_386 )
{
T_8 * V_251 = F_247 ( V_231 ) ;
V_251 -> V_324 = V_231 ;
V_251 -> V_376 = V_376 ;
F_364 ( V_251 , V_385 , V_386 ) ;
F_377 ( V_251 ) ;
#ifdef F_378
F_20 ( V_351 L_68 ,
V_231 , ( unsigned long ) V_251 ,
( unsigned long ) V_251 -> V_413 ) ;
#endif
F_369 ( V_251 , V_385 , V_386 ) ;
}
static void T_3 F_384 ( void )
{
unsigned int V_299 ;
unsigned int V_418 = 0 ;
F_385 (node, node_possible_map)
V_418 = V_299 ;
V_419 = V_418 + 1 ;
}
static inline void F_384 ( void )
{
}
void T_3 F_386 ( unsigned int V_231 , unsigned long V_84 ,
unsigned long V_85 )
{
int V_28 ;
F_338 ( V_352 , L_69 ,
L_70
L_71 ,
V_231 , V_84 , V_85 ,
V_353 , V_420 ) ;
F_387 ( & V_84 , & V_85 ) ;
for ( V_28 = 0 ; V_28 < V_353 ; V_28 ++ ) {
if ( V_354 [ V_28 ] . V_231 != V_231 )
continue;
if ( V_84 >= V_354 [ V_28 ] . V_84 &&
V_85 <= V_354 [ V_28 ] . V_85 )
return;
if ( V_84 <= V_354 [ V_28 ] . V_85 &&
V_85 > V_354 [ V_28 ] . V_85 ) {
V_354 [ V_28 ] . V_85 = V_85 ;
return;
}
if ( V_84 < V_354 [ V_28 ] . V_84 &&
V_85 >= V_354 [ V_28 ] . V_84 ) {
V_354 [ V_28 ] . V_84 = V_84 ;
return;
}
}
if ( V_28 >= V_420 ) {
F_20 ( V_421 L_72 ,
V_420 ) ;
return;
}
V_354 [ V_28 ] . V_231 = V_231 ;
V_354 [ V_28 ] . V_84 = V_84 ;
V_354 [ V_28 ] . V_85 = V_85 ;
V_353 = V_28 + 1 ;
}
void T_3 F_388 ( unsigned int V_231 , unsigned long V_84 ,
unsigned long V_85 )
{
int V_28 , V_310 ;
int V_422 = 0 ;
F_20 ( V_351 L_73 ,
V_231 , V_84 , V_85 ) ;
F_344 (i, nid) {
if ( V_354 [ V_28 ] . V_84 >= V_84 &&
V_354 [ V_28 ] . V_85 <= V_85 ) {
V_354 [ V_28 ] . V_84 = 0 ;
V_354 [ V_28 ] . V_85 = 0 ;
V_422 = 1 ;
continue;
}
if ( V_354 [ V_28 ] . V_84 < V_84 &&
V_354 [ V_28 ] . V_85 > V_84 ) {
unsigned long V_423 = V_354 [ V_28 ] . V_85 ;
V_354 [ V_28 ] . V_85 = V_84 ;
if ( V_423 > V_85 )
F_386 ( V_231 , V_85 , V_423 ) ;
continue;
}
if ( V_354 [ V_28 ] . V_84 >= V_84 &&
V_354 [ V_28 ] . V_85 > V_85 &&
V_354 [ V_28 ] . V_84 < V_85 ) {
V_354 [ V_28 ] . V_84 = V_85 ;
continue;
}
}
if ( ! V_422 )
return;
for ( V_28 = V_353 - 1 ; V_28 > 0 ; V_28 -- ) {
if ( V_354 [ V_28 ] . V_231 != V_231 )
continue;
if ( V_354 [ V_28 ] . V_85 )
continue;
for ( V_310 = V_28 ; V_310 < V_353 - 1 ; V_310 ++ )
memcpy ( & V_354 [ V_310 ] , & V_354 [ V_310 + 1 ] ,
sizeof( V_354 [ V_310 ] ) ) ;
V_310 = V_353 - 1 ;
memset ( & V_354 [ V_310 ] , 0 , sizeof( V_354 [ V_310 ] ) ) ;
V_353 -- ;
}
}
void T_3 F_389 ( void )
{
memset ( V_354 , 0 , sizeof( V_354 ) ) ;
V_353 = 0 ;
}
static int T_3 F_390 ( const void * V_424 , const void * V_425 )
{
struct V_426 * V_427 = (struct V_426 * ) V_424 ;
struct V_426 * V_428 = (struct V_426 * ) V_425 ;
if ( V_427 -> V_84 > V_428 -> V_84 )
return 1 ;
if ( V_427 -> V_84 < V_428 -> V_84 )
return - 1 ;
return 0 ;
}
void T_3 F_391 ( void )
{
F_392 ( V_354 , ( T_7 ) V_353 ,
sizeof( struct V_426 ) ,
F_390 , NULL ) ;
}
unsigned long T_3 F_393 ( void )
{
unsigned long V_429 = 0 , V_430 = 0 ;
int V_431 = - 1 ;
int V_28 ;
F_344 (i, MAX_NUMNODES) {
int V_231 = V_354 [ V_28 ] . V_231 ;
unsigned long V_369 = V_354 [ V_28 ] . V_84 ;
unsigned long V_233 = V_354 [ V_28 ] . V_85 ;
unsigned long V_432 ;
if ( ! V_369 || V_431 < 0 || V_431 == V_231 ) {
V_431 = V_231 ;
V_430 = V_233 ;
continue;
}
V_432 = ~ ( ( 1 << F_394 ( V_369 ) ) - 1 ) ;
while ( V_432 && V_430 <= ( V_369 & ( V_432 << 1 ) ) )
V_432 <<= 1 ;
V_429 |= V_432 ;
}
return ~ V_429 + 1 ;
}
static unsigned long T_3 F_395 ( int V_231 )
{
int V_28 ;
unsigned long V_433 = V_434 ;
F_344 (i, nid)
V_433 = V_141 ( V_433 , V_354 [ V_28 ] . V_84 ) ;
if ( V_433 == V_434 ) {
F_20 ( V_285
L_74 , V_231 ) ;
return 0 ;
}
return V_433 ;
}
unsigned long T_3 F_396 ( void )
{
return F_395 ( V_308 ) ;
}
static unsigned long T_3 F_397 ( void )
{
int V_28 ;
unsigned long V_388 = 0 ;
for ( V_28 = 0 ; V_28 < V_353 ; V_28 ++ ) {
unsigned long V_96 = V_354 [ V_28 ] . V_85 -
V_354 [ V_28 ] . V_84 ;
V_388 += V_96 ;
if ( V_96 )
F_398 ( V_354 [ V_28 ] . V_231 , V_158 ) ;
}
return V_388 ;
}
static void T_3 F_399 ( unsigned long * V_435 )
{
int V_28 , V_231 ;
unsigned long V_436 ;
unsigned long V_437 , V_438 ;
T_5 V_439 = V_157 [ V_158 ] ;
unsigned long V_388 = F_397 () ;
int V_440 = F_280 ( V_157 [ V_158 ] ) ;
if ( V_441 ) {
unsigned long V_442 ;
V_441 =
F_309 ( V_441 , V_415 ) ;
V_442 = V_388 - V_441 ;
V_443 = F_303 ( V_443 , V_442 ) ;
}
if ( ! V_443 )
goto V_21;
F_358 () ;
V_436 = V_374 [ V_375 ] ;
V_218:
V_437 = V_443 / V_440 ;
F_272 (nid, N_HIGH_MEMORY) {
if ( V_443 < V_437 )
V_437 = V_443 / V_440 ;
V_438 = V_437 ;
F_344 (i, nid) {
unsigned long V_84 , V_85 ;
unsigned long V_357 ;
V_84 = F_303 ( V_354 [ V_28 ] . V_84 ,
V_379 [ V_231 ] ) ;
V_85 = V_354 [ V_28 ] . V_85 ;
if ( V_84 >= V_85 )
continue;
if ( V_84 < V_436 ) {
unsigned long V_444 ;
V_444 = V_141 ( V_85 , V_436 )
- V_84 ;
V_438 -= V_141 ( V_444 ,
V_438 ) ;
V_443 -= V_141 ( V_444 ,
V_443 ) ;
if ( V_85 <= V_436 ) {
V_379 [ V_231 ] = V_85 ;
continue;
}
V_84 = V_436 ;
}
V_357 = V_85 - V_84 ;
if ( V_357 > V_438 )
V_357 = V_438 ;
V_379 [ V_231 ] = V_84 + V_357 ;
V_443 -= V_141 ( V_443 ,
V_357 ) ;
V_438 -= V_357 ;
if ( ! V_438 )
break;
}
}
V_440 -- ;
if ( V_440 && V_443 > V_440 )
goto V_218;
for ( V_231 = 0 ; V_231 < V_308 ; V_231 ++ )
V_379 [ V_231 ] =
F_309 ( V_379 [ V_231 ] , V_415 ) ;
V_21:
V_157 [ V_158 ] = V_439 ;
}
static void F_400 ( T_8 * V_251 )
{
#ifdef F_249
enum V_195 V_195 ;
for ( V_195 = 0 ; V_195 <= V_198 ; V_195 ++ ) {
struct V_11 * V_11 = & V_251 -> V_253 [ V_195 ] ;
if ( V_11 -> V_237 )
F_398 ( F_105 ( V_11 ) , V_445 ) ;
}
#endif
}
void T_3 F_401 ( unsigned long * V_106 )
{
unsigned long V_231 ;
int V_28 ;
F_391 () ;
memset ( V_374 , 0 ,
sizeof( V_374 ) ) ;
memset ( V_373 , 0 ,
sizeof( V_373 ) ) ;
V_374 [ 0 ] = F_396 () ;
V_373 [ 0 ] = V_106 [ 0 ] ;
for ( V_28 = 1 ; V_28 < V_275 ; V_28 ++ ) {
if ( V_28 == V_372 )
continue;
V_374 [ V_28 ] =
V_373 [ V_28 - 1 ] ;
V_373 [ V_28 ] =
F_303 ( V_106 [ V_28 ] , V_374 [ V_28 ] ) ;
}
V_374 [ V_372 ] = 0 ;
V_373 [ V_372 ] = 0 ;
memset ( V_379 , 0 , sizeof( V_379 ) ) ;
F_399 ( V_379 ) ;
F_20 ( L_75 ) ;
for ( V_28 = 0 ; V_28 < V_275 ; V_28 ++ ) {
if ( V_28 == V_372 )
continue;
F_20 ( L_76 , V_333 [ V_28 ] ) ;
if ( V_374 [ V_28 ] ==
V_373 [ V_28 ] )
F_20 ( L_77 ) ;
else
F_20 ( L_78 ,
V_374 [ V_28 ] ,
V_373 [ V_28 ] ) ;
}
F_20 ( L_79 ) ;
for ( V_28 = 0 ; V_28 < V_308 ; V_28 ++ ) {
if ( V_379 [ V_28 ] )
F_20 ( L_80 , V_28 , V_379 [ V_28 ] ) ;
}
F_20 ( L_81 , V_353 ) ;
for ( V_28 = 0 ; V_28 < V_353 ; V_28 ++ )
F_20 ( L_82 , V_354 [ V_28 ] . V_231 ,
V_354 [ V_28 ] . V_84 ,
V_354 [ V_28 ] . V_85 ) ;
F_402 () ;
F_384 () ;
F_279 (nid) {
T_8 * V_251 = F_247 ( V_231 ) ;
F_383 ( V_231 , NULL ,
F_395 ( V_231 ) , NULL ) ;
if ( V_251 -> V_252 )
F_398 ( V_231 , V_158 ) ;
F_400 ( V_251 ) ;
}
}
static int T_3 F_403 ( char * V_30 , unsigned long * V_446 )
{
unsigned long long V_447 ;
if ( ! V_30 )
return - V_286 ;
V_447 = F_404 ( V_30 , & V_30 ) ;
* V_446 = V_447 >> V_343 ;
F_2 ( ( V_447 >> V_343 ) > V_434 ) ;
return 0 ;
}
static int T_3 F_405 ( char * V_30 )
{
return F_403 ( V_30 , & V_443 ) ;
}
static int T_3 F_406 ( char * V_30 )
{
return F_403 ( V_30 , & V_441 ) ;
}
void T_3 F_407 ( unsigned long V_448 )
{
V_402 = V_448 ;
}
void T_3 F_408 ( unsigned long * V_385 )
{
F_383 ( 0 , V_385 ,
F_409 ( V_449 ) >> V_343 , NULL ) ;
}
static int F_410 ( struct V_450 * V_451 ,
unsigned long V_452 , void * V_453 )
{
int V_101 = ( unsigned long ) V_453 ;
if ( V_452 == V_454 || V_452 == V_455 ) {
F_117 ( V_101 ) ;
F_411 ( V_101 ) ;
F_412 ( V_101 ) ;
}
return V_456 ;
}
void T_3 F_413 ( void )
{
F_414 ( F_410 , 0 ) ;
}
static void F_415 ( void )
{
struct V_346 * V_251 ;
unsigned long V_457 = 0 ;
enum V_195 V_28 , V_310 ;
F_416 (pgdat) {
for ( V_28 = 0 ; V_28 < V_275 ; V_28 ++ ) {
struct V_11 * V_11 = V_251 -> V_253 + V_28 ;
unsigned long F_303 = 0 ;
for ( V_310 = V_28 ; V_310 < V_275 ; V_310 ++ ) {
if ( V_11 -> V_145 [ V_310 ] > F_303 )
F_303 = V_11 -> V_145 [ V_310 ] ;
}
F_303 += F_238 ( V_11 ) ;
if ( F_303 > V_11 -> V_237 )
F_303 = V_11 -> V_237 ;
V_457 += F_303 ;
}
}
V_458 = V_457 ;
}
static void F_417 ( void )
{
struct V_346 * V_251 ;
enum V_195 V_310 , V_459 ;
F_416 (pgdat) {
for ( V_310 = 0 ; V_310 < V_275 ; V_310 ++ ) {
struct V_11 * V_11 = V_251 -> V_253 + V_310 ;
unsigned long V_237 = V_11 -> V_237 ;
V_11 -> V_145 [ V_310 ] = 0 ;
V_459 = V_310 ;
while ( V_459 ) {
struct V_11 * V_460 ;
V_459 -- ;
if ( V_461 [ V_459 ] < 1 )
V_461 [ V_459 ] = 1 ;
V_460 = V_251 -> V_253 + V_459 ;
V_460 -> V_145 [ V_310 ] = V_237 /
V_461 [ V_459 ] ;
V_237 += V_460 -> V_237 ;
}
}
}
F_415 () ;
}
void F_418 ( void )
{
unsigned long V_462 = V_463 >> ( V_343 - 10 ) ;
unsigned long V_464 = 0 ;
struct V_11 * V_11 ;
unsigned long V_51 ;
F_419 (zone) {
if ( ! F_420 ( V_11 ) )
V_464 += V_11 -> V_237 ;
}
F_419 (zone) {
T_15 V_305 ;
F_125 ( & V_11 -> V_59 , V_51 ) ;
V_305 = ( T_15 ) V_462 * V_11 -> V_237 ;
F_421 ( V_305 , V_464 ) ;
if ( F_420 ( V_11 ) ) {
int V_465 ;
V_465 = V_11 -> V_237 / 1024 ;
if ( V_465 < V_466 )
V_465 = V_466 ;
if ( V_465 > 128 )
V_465 = 128 ;
V_11 -> V_112 [ V_467 ] = V_465 ;
} else {
V_11 -> V_112 [ V_467 ] = V_305 ;
}
V_11 -> V_112 [ V_468 ] = F_254 ( V_11 ) + ( V_305 >> 2 ) ;
V_11 -> V_112 [ V_469 ] = F_254 ( V_11 ) + ( V_305 >> 1 ) ;
F_308 ( V_11 ) ;
F_132 ( & V_11 -> V_59 , V_51 ) ;
}
F_415 () ;
}
static void T_2 F_422 ( struct V_11 * V_11 )
{
unsigned int V_470 , V_471 ;
V_470 = V_11 -> V_237 >> ( 30 - V_343 ) ;
if ( V_470 )
V_471 = F_423 ( 10 * V_470 ) ;
else
V_471 = 1 ;
V_11 -> V_472 = V_471 ;
}
static void T_2 F_424 ( void )
{
struct V_11 * V_11 ;
F_419 (zone)
F_422 ( V_11 ) ;
}
int T_2 F_425 ( void )
{
unsigned long V_473 ;
V_473 = F_239 () * ( V_68 >> 10 ) ;
V_463 = F_423 ( V_473 * 16 ) ;
if ( V_463 < 128 )
V_463 = 128 ;
if ( V_463 > 65536 )
V_463 = 65536 ;
F_418 () ;
F_426 () ;
F_417 () ;
F_424 () ;
return 0 ;
}
int F_427 ( T_9 * V_289 , int V_290 ,
void T_10 * V_291 , T_7 * V_292 , T_11 * V_293 )
{
F_428 ( V_289 , V_290 , V_291 , V_292 , V_293 ) ;
if ( V_290 )
F_418 () ;
return 0 ;
}
int F_429 ( T_9 * V_289 , int V_290 ,
void T_10 * V_291 , T_7 * V_292 , T_11 * V_293 )
{
struct V_11 * V_11 ;
int V_474 ;
V_474 = F_430 ( V_289 , V_290 , V_291 , V_292 , V_293 ) ;
if ( V_474 )
return V_474 ;
F_419 (zone)
V_11 -> V_405 = ( V_11 -> V_237 *
V_406 ) / 100 ;
return 0 ;
}
int F_431 ( T_9 * V_289 , int V_290 ,
void T_10 * V_291 , T_7 * V_292 , T_11 * V_293 )
{
struct V_11 * V_11 ;
int V_474 ;
V_474 = F_430 ( V_289 , V_290 , V_291 , V_292 , V_293 ) ;
if ( V_474 )
return V_474 ;
F_419 (zone)
V_11 -> V_407 = ( V_11 -> V_237 *
V_408 ) / 100 ;
return 0 ;
}
int F_432 ( T_9 * V_289 , int V_290 ,
void T_10 * V_291 , T_7 * V_292 , T_11 * V_293 )
{
F_430 ( V_289 , V_290 , V_291 , V_292 , V_293 ) ;
F_417 () ;
return 0 ;
}
int F_433 ( T_9 * V_289 , int V_290 ,
void T_10 * V_291 , T_7 * V_292 , T_11 * V_293 )
{
struct V_11 * V_11 ;
unsigned int V_101 ;
int V_12 ;
V_12 = F_430 ( V_289 , V_290 , V_291 , V_292 , V_293 ) ;
if ( ! V_290 || ( V_12 == - V_286 ) )
return V_12 ;
F_118 (zone) {
F_290 (cpu) {
unsigned long V_74 ;
V_74 = V_11 -> V_237 / V_344 ;
F_326 (
F_119 ( V_11 -> V_104 , V_101 ) , V_74 ) ;
}
}
return 0 ;
}
static int T_3 F_434 ( char * V_120 )
{
if ( ! V_120 )
return 0 ;
V_475 = F_435 ( V_120 , & V_120 , 0 ) ;
return 1 ;
}
void * T_3 F_436 ( const char * V_476 ,
unsigned long V_477 ,
unsigned long V_478 ,
int V_479 ,
int V_51 ,
unsigned int * V_480 ,
unsigned int * V_481 ,
unsigned long V_360 )
{
unsigned long long F_303 = V_360 ;
unsigned long V_482 , V_76 ;
void * V_289 = NULL ;
if ( ! V_478 ) {
V_478 = V_403 ;
V_478 += ( 1UL << ( 20 - V_343 ) ) - 1 ;
V_478 >>= 20 - V_343 ;
V_478 <<= 20 - V_343 ;
if ( V_479 > V_343 )
V_478 >>= ( V_479 - V_343 ) ;
else
V_478 <<= ( V_343 - V_479 ) ;
if ( F_6 ( V_51 & V_483 ) ) {
F_2 ( ! ( V_51 & V_484 ) ) ;
if ( ! ( V_478 >> * V_480 ) ) {
V_478 = 1UL << * V_480 ;
F_103 ( ! V_478 ) ;
}
} else if ( F_6 ( ( V_478 * V_477 ) < V_68 ) )
V_478 = V_68 / V_477 ;
}
V_478 = F_437 ( V_478 ) ;
if ( F_303 == 0 ) {
F_303 = ( ( unsigned long long ) V_404 << V_343 ) >> 4 ;
F_421 ( F_303 , V_477 ) ;
}
if ( V_478 > F_303 )
V_478 = F_303 ;
V_482 = F_438 ( V_478 ) ;
do {
V_76 = V_477 << V_482 ;
if ( V_51 & V_484 )
V_289 = F_439 ( V_76 ) ;
else if ( V_475 )
V_289 = F_440 ( V_76 , V_485 , V_486 ) ;
else {
if ( F_231 ( V_76 ) < V_40 ) {
V_289 = F_230 ( V_76 , V_485 ) ;
F_441 ( V_289 , V_76 , 1 , V_485 ) ;
}
}
} while ( ! V_289 && V_76 > V_68 && -- V_482 );
if ( ! V_289 )
F_442 ( L_83 , V_476 ) ;
F_20 ( V_487 L_84 ,
V_476 ,
( 1UL << V_482 ) ,
F_438 ( V_76 ) - V_343 ,
V_76 ) ;
if ( V_480 )
* V_480 = V_482 ;
if ( V_481 )
* V_481 = ( 1 << V_482 ) - 1 ;
return V_289 ;
}
static inline unsigned long * F_443 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef F_444
return F_445 ( V_14 ) -> V_393 ;
#else
return V_11 -> V_393 ;
#endif
}
static inline int F_446 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef F_444
V_14 &= ( V_488 - 1 ) ;
return ( V_14 >> V_90 ) * V_392 ;
#else
V_14 = V_14 - V_11 -> V_15 ;
return ( V_14 >> V_90 ) * V_392 ;
#endif
}
unsigned long F_447 ( struct V_5 * V_5 ,
int V_489 , int V_490 )
{
struct V_11 * V_11 ;
unsigned long * V_491 ;
unsigned long V_14 , V_492 ;
unsigned long V_51 = 0 ;
unsigned long V_493 = 1 ;
V_11 = F_14 ( V_5 ) ;
V_14 = F_9 ( V_5 ) ;
V_491 = F_443 ( V_11 , V_14 ) ;
V_492 = F_446 ( V_11 , V_14 ) ;
for (; V_489 <= V_490 ; V_489 ++ , V_493 <<= 1 )
if ( F_166 ( V_492 + V_489 , V_491 ) )
V_51 |= V_493 ;
return V_51 ;
}
void F_7 ( struct V_5 * V_5 , unsigned long V_51 ,
int V_489 , int V_490 )
{
struct V_11 * V_11 ;
unsigned long * V_491 ;
unsigned long V_14 , V_492 ;
unsigned long V_493 = 1 ;
V_11 = F_14 ( V_5 ) ;
V_14 = F_9 ( V_5 ) ;
V_491 = F_443 ( V_11 , V_14 ) ;
V_492 = F_446 ( V_11 , V_14 ) ;
F_40 ( V_14 < V_11 -> V_15 ) ;
F_40 ( V_14 >= V_11 -> V_15 + V_11 -> V_16 ) ;
for (; V_489 <= V_490 ; V_489 ++ , V_493 <<= 1 )
if ( V_51 & V_493 )
F_448 ( V_492 + V_489 , V_491 ) ;
else
F_449 ( V_492 + V_489 , V_491 ) ;
}
static int
F_450 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_54 )
{
unsigned long V_14 , V_494 , V_495 ;
if ( F_171 ( V_11 ) == V_372 )
return true ;
if ( F_88 ( V_5 ) == V_110 )
return true ;
V_14 = F_9 ( V_5 ) ;
for ( V_495 = 0 , V_494 = 0 ; V_494 < V_86 ; V_494 ++ ) {
unsigned long V_496 = V_14 + V_494 ;
if ( ! F_13 ( V_496 ) )
continue;
V_5 = F_108 ( V_496 ) ;
if ( ! F_53 ( V_5 ) ) {
if ( F_51 ( V_5 ) )
V_494 += ( 1 << F_52 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_451 ( V_5 ) )
V_495 ++ ;
if ( V_495 > V_54 )
return false ;
}
return true ;
}
bool F_452 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_14 ( V_5 ) ;
return F_450 ( V_11 , V_5 , 0 ) ;
}
int F_453 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_51 , V_14 ;
struct V_497 V_105 ;
int V_498 ;
int V_12 = - V_499 ;
V_11 = F_14 ( V_5 ) ;
F_125 ( & V_11 -> V_59 , V_51 ) ;
V_14 = F_9 ( V_5 ) ;
V_105 . V_84 = V_14 ;
V_105 . V_29 = V_86 ;
V_105 . V_500 = 0 ;
V_498 = V_497 ( V_501 , & V_105 ) ;
V_498 = F_454 ( V_498 ) ;
if ( V_498 )
goto V_21;
if ( F_450 ( V_11 , V_5 , V_105 . V_500 ) )
V_12 = 0 ;
V_21:
if ( ! V_12 ) {
F_5 ( V_5 , V_109 ) ;
F_107 ( V_11 , V_5 , V_109 ) ;
}
F_132 ( & V_11 -> V_59 , V_51 ) ;
if ( ! V_12 )
F_122 () ;
return V_12 ;
}
void F_455 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_51 ;
V_11 = F_14 ( V_5 ) ;
F_125 ( & V_11 -> V_59 , V_51 ) ;
if ( F_88 ( V_5 ) != V_109 )
goto V_21;
F_5 ( V_5 , V_110 ) ;
F_107 ( V_11 , V_5 , V_110 ) ;
V_21:
F_132 ( & V_11 -> V_59 , V_51 ) ;
}
void
F_456 ( unsigned long V_84 , unsigned long V_85 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_27 , V_28 ;
unsigned long V_14 ;
unsigned long V_51 ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 ++ )
if ( F_126 ( V_14 ) )
break;
if ( V_14 == V_85 )
return;
V_11 = F_14 ( F_108 ( V_14 ) ) ;
F_125 ( & V_11 -> V_59 , V_51 ) ;
V_14 = V_84 ;
while ( V_14 < V_85 ) {
if ( ! F_126 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_108 ( V_14 ) ;
F_103 ( F_53 ( V_5 ) ) ;
F_103 ( ! F_51 ( V_5 ) ) ;
V_27 = F_52 ( V_5 ) ;
#ifdef F_457
F_20 ( V_487 L_85 ,
V_14 , 1 << V_27 , V_85 ) ;
#endif
F_56 ( & V_5 -> V_41 ) ;
F_46 ( V_5 ) ;
V_11 -> V_42 [ V_27 ] . V_43 -- ;
F_72 ( V_11 , V_67 ,
- ( 1UL << V_27 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_316 ( ( V_5 + V_28 ) ) ;
V_14 += ( 1 << V_27 ) ;
}
F_132 ( & V_11 -> V_59 , V_51 ) ;
}
bool F_458 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_14 ( V_5 ) ;
unsigned long V_14 = F_9 ( V_5 ) ;
unsigned long V_51 ;
int V_27 ;
F_125 ( & V_11 -> V_59 , V_51 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
struct V_5 * V_502 = V_5 - ( V_14 & ( ( 1 << V_27 ) - 1 ) ) ;
if ( F_51 ( V_502 ) && F_52 ( V_502 ) >= V_27 )
break;
}
F_132 ( & V_11 -> V_59 , V_51 ) ;
return V_27 < V_40 ;
}
static void F_459 ( unsigned long V_51 )
{
const char * V_503 = L_86 ;
unsigned long V_432 ;
int V_28 ;
F_20 ( V_22 L_87 , V_51 ) ;
V_51 &= ( 1UL << V_504 ) - 1 ;
for ( V_28 = 0 ; V_505 [ V_28 ] . V_255 && V_51 ; V_28 ++ ) {
V_432 = V_505 [ V_28 ] . V_432 ;
if ( ( V_51 & V_432 ) != V_432 )
continue;
V_51 &= ~ V_432 ;
F_20 ( L_88 , V_503 , V_505 [ V_28 ] . V_255 ) ;
V_503 = L_89 ;
}
if ( V_51 )
F_20 ( L_90 , V_503 , V_51 ) ;
F_20 ( L_91 ) ;
}
void F_21 ( struct V_5 * V_5 )
{
F_20 ( V_22
L_92 ,
V_5 , F_64 ( & V_5 -> V_50 ) , F_63 ( V_5 ) ,
V_5 -> V_49 , V_5 -> V_355 ) ;
F_459 ( V_5 -> V_51 ) ;
F_460 ( V_5 ) ;
}
