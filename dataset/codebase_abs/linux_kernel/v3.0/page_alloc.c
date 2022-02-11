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
V_21:
F_18 ( V_5 ) ;
F_23 ( V_26 ) ;
}
static void F_24 ( struct V_5 * V_5 )
{
F_25 ( V_5 , F_26 ( V_5 ) ) ;
}
void F_27 ( struct V_5 * V_5 , unsigned long V_27 )
{
int V_28 ;
int V_29 = 1 << V_27 ;
F_28 ( V_5 , F_24 ) ;
F_29 ( V_5 , V_27 ) ;
F_30 ( V_5 ) ;
for ( V_28 = 1 ; V_28 < V_29 ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
F_31 ( V_30 ) ;
V_30 -> V_31 = V_5 ;
}
}
static int F_32 ( struct V_5 * V_5 , unsigned long V_27 )
{
int V_28 ;
int V_29 = 1 << V_27 ;
int V_32 = 0 ;
if ( F_6 ( F_26 ( V_5 ) != V_27 ) ||
F_6 ( ! F_33 ( V_5 ) ) ) {
F_16 ( V_5 ) ;
V_32 ++ ;
}
F_34 ( V_5 ) ;
for ( V_28 = 1 ; V_28 < V_29 ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
if ( F_6 ( ! F_35 ( V_30 ) || ( V_30 -> V_31 != V_5 ) ) ) {
F_16 ( V_5 ) ;
V_32 ++ ;
}
F_36 ( V_30 ) ;
}
return V_32 ;
}
static inline void F_37 ( struct V_5 * V_5 , int V_27 , T_1 V_33 )
{
int V_28 ;
F_38 ( ( V_33 & V_34 ) && F_39 () ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_40 ( V_5 + V_28 ) ;
}
static inline void F_41 ( struct V_5 * V_5 , int V_27 )
{
F_42 ( V_5 , V_27 ) ;
F_43 ( V_5 ) ;
}
static inline void F_44 ( struct V_5 * V_5 )
{
F_45 ( V_5 ) ;
F_42 ( V_5 , 0 ) ;
}
static inline unsigned long
F_46 ( unsigned long V_35 , unsigned int V_27 )
{
return V_35 ^ ( 1 << V_27 ) ;
}
static inline int F_47 ( struct V_5 * V_5 , struct V_5 * V_36 ,
int V_27 )
{
if ( ! F_13 ( F_9 ( V_36 ) ) )
return 0 ;
if ( F_48 ( V_5 ) != F_48 ( V_36 ) )
return 0 ;
if ( F_49 ( V_36 ) && F_50 ( V_36 ) == V_27 ) {
F_38 ( F_51 ( V_36 ) != 0 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_52 ( struct V_5 * V_5 ,
struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned long V_35 ;
unsigned long V_37 ;
unsigned long V_38 ( V_39 ) ;
struct V_5 * V_36 ;
if ( F_6 ( F_53 ( V_5 ) ) )
if ( F_6 ( F_32 ( V_5 , V_27 ) ) )
return;
F_38 ( V_6 == - 1 ) ;
V_35 = F_9 ( V_5 ) & ( ( 1 << V_40 ) - 1 ) ;
F_38 ( V_35 & ( ( 1 << V_27 ) - 1 ) ) ;
F_38 ( F_15 ( V_11 , V_5 ) ) ;
while ( V_27 < V_40 - 1 ) {
V_39 = F_46 ( V_35 , V_27 ) ;
V_36 = V_5 + ( V_39 - V_35 ) ;
if ( ! F_47 ( V_5 , V_36 , V_27 ) )
break;
F_54 ( & V_36 -> V_41 ) ;
V_11 -> V_42 [ V_27 ] . V_43 -- ;
F_44 ( V_36 ) ;
V_37 = V_39 & V_35 ;
V_5 = V_5 + ( V_37 - V_35 ) ;
V_35 = V_37 ;
V_27 ++ ;
}
F_41 ( V_5 , V_27 ) ;
if ( ( V_27 < V_40 - 2 ) && F_13 ( F_9 ( V_36 ) ) ) {
struct V_5 * V_44 , * V_45 ;
V_37 = V_39 & V_35 ;
V_44 = V_5 + ( V_37 - V_35 ) ;
V_39 = F_46 ( V_37 , V_27 + 1 ) ;
V_45 = V_5 + ( V_39 - V_37 ) ;
if ( F_47 ( V_44 , V_45 , V_27 + 1 ) ) {
F_55 ( & V_5 -> V_41 ,
& V_11 -> V_42 [ V_27 ] . V_46 [ V_6 ] ) ;
goto V_21;
}
}
F_56 ( & V_5 -> V_41 , & V_11 -> V_42 [ V_27 ] . V_46 [ V_6 ] ) ;
V_21:
V_11 -> V_42 [ V_27 ] . V_43 ++ ;
}
static inline void F_57 ( struct V_5 * V_5 )
{
F_58 ( V_5 , V_47 ) ;
F_59 ( V_48 ) ;
}
static inline int F_60 ( struct V_5 * V_5 )
{
if ( F_6 ( F_61 ( V_5 ) |
( V_5 -> V_49 != NULL ) |
( F_62 ( & V_5 -> V_50 ) != 0 ) |
( V_5 -> V_51 & V_52 ) |
( F_63 ( V_5 ) ) ) ) {
F_16 ( V_5 ) ;
return 1 ;
}
if ( V_5 -> V_51 & V_53 )
V_5 -> V_51 &= ~ V_53 ;
return 0 ;
}
static void F_64 ( struct V_11 * V_11 , int V_54 ,
struct V_55 * V_56 )
{
int V_6 = 0 ;
int V_57 = 0 ;
int V_58 = V_54 ;
F_65 ( & V_11 -> V_59 ) ;
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
} while ( F_66 ( V_63 ) );
if ( V_57 == V_64 )
V_57 = V_58 ;
do {
V_5 = F_67 ( V_63 -> V_66 , struct V_5 , V_41 ) ;
F_54 ( & V_5 -> V_41 ) ;
F_52 ( V_5 , V_11 , 0 , F_68 ( V_5 ) ) ;
F_69 ( V_5 , 0 , F_68 ( V_5 ) ) ;
} while ( -- V_58 && -- V_57 && ! F_66 ( V_63 ) );
}
F_70 ( V_11 , V_67 , V_54 ) ;
F_71 ( & V_11 -> V_59 ) ;
}
static void F_72 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_27 ,
int V_6 )
{
F_65 ( & V_11 -> V_59 ) ;
V_11 -> V_60 = 0 ;
V_11 -> V_61 = 0 ;
F_52 ( V_5 , V_11 , V_27 , V_6 ) ;
F_70 ( V_11 , V_67 , 1 << V_27 ) ;
F_71 ( & V_11 -> V_59 ) ;
}
static bool F_73 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
int V_32 = 0 ;
F_74 ( V_5 , V_27 ) ;
F_75 ( V_5 , V_27 ) ;
if ( F_76 ( V_5 ) )
V_5 -> V_49 = NULL ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
V_32 += F_60 ( V_5 + V_28 ) ;
if ( V_32 )
return false ;
if ( ! F_77 ( V_5 ) ) {
F_78 ( F_79 ( V_5 ) , V_68 << V_27 ) ;
F_80 ( F_79 ( V_5 ) ,
V_68 << V_27 ) ;
}
F_81 ( V_5 , V_27 ) ;
F_82 ( V_5 , 1 << V_27 , 0 ) ;
return true ;
}
static void F_25 ( struct V_5 * V_5 , unsigned int V_27 )
{
unsigned long V_51 ;
int V_69 = F_83 ( V_5 ) ;
if ( ! F_73 ( V_5 , V_27 ) )
return;
F_84 ( V_51 ) ;
if ( F_6 ( V_69 ) )
F_57 ( V_5 ) ;
F_85 ( V_70 , 1 << V_27 ) ;
F_72 ( F_14 ( V_5 ) , V_5 , V_27 ,
F_86 ( V_5 ) ) ;
F_87 ( V_51 ) ;
}
void T_2 F_88 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( V_27 == 0 ) {
F_89 ( V_5 ) ;
F_90 ( V_5 , 0 ) ;
F_91 ( V_5 ) ;
F_92 ( V_5 ) ;
} else {
int V_71 ;
F_93 ( V_5 ) ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
struct V_5 * V_30 = & V_5 [ V_71 ] ;
if ( V_71 + 1 < V_72 )
F_93 ( V_30 + 1 ) ;
F_89 ( V_30 ) ;
F_90 ( V_30 , 0 ) ;
}
F_91 ( V_5 ) ;
F_94 ( V_5 , V_27 ) ;
}
}
static inline void F_95 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_73 , int V_74 , struct V_42 * V_75 ,
int V_6 )
{
unsigned long V_76 = 1 << V_74 ;
while ( V_74 > V_73 ) {
V_75 -- ;
V_74 -- ;
V_76 >>= 1 ;
F_38 ( F_15 ( V_11 , & V_5 [ V_76 ] ) ) ;
F_56 ( & V_5 [ V_76 ] . V_41 , & V_75 -> V_46 [ V_6 ] ) ;
V_75 -> V_43 ++ ;
F_41 ( & V_5 [ V_76 ] , V_74 ) ;
}
}
static inline int F_96 ( struct V_5 * V_5 )
{
if ( F_6 ( F_61 ( V_5 ) |
( V_5 -> V_49 != NULL ) |
( F_62 ( & V_5 -> V_50 ) != 0 ) |
( V_5 -> V_51 & V_53 ) |
( F_63 ( V_5 ) ) ) ) {
F_16 ( V_5 ) ;
return 1 ;
}
return 0 ;
}
static int F_97 ( struct V_5 * V_5 , int V_27 , T_1 V_33 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
if ( F_6 ( F_96 ( V_30 ) ) )
return 1 ;
}
F_42 ( V_5 , 0 ) ;
F_91 ( V_5 ) ;
F_98 ( V_5 , V_27 ) ;
F_82 ( V_5 , 1 << V_27 , 1 ) ;
if ( V_33 & V_77 )
F_37 ( V_5 , V_27 , V_33 ) ;
if ( V_27 && ( V_33 & V_78 ) )
F_27 ( V_5 , V_27 ) ;
return 0 ;
}
static inline
struct V_5 * F_99 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned int V_79 ;
struct V_42 * V_75 ;
struct V_5 * V_5 ;
for ( V_79 = V_27 ; V_79 < V_40 ; ++ V_79 ) {
V_75 = & ( V_11 -> V_42 [ V_79 ] ) ;
if ( F_66 ( & V_75 -> V_46 [ V_6 ] ) )
continue;
V_5 = F_67 ( V_75 -> V_46 [ V_6 ] . V_80 ,
struct V_5 , V_41 ) ;
F_54 ( & V_5 -> V_41 ) ;
F_44 ( V_5 ) ;
V_75 -> V_43 -- ;
F_95 ( V_11 , V_5 , V_27 , V_79 , V_75 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
static int F_100 ( struct V_11 * V_11 ,
struct V_5 * V_81 , struct V_5 * V_82 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_27 ;
int V_83 = 0 ;
#ifndef F_101
F_102 ( F_14 ( V_81 ) != F_14 ( V_82 ) ) ;
#endif
for ( V_5 = V_81 ; V_5 <= V_82 ; ) {
F_38 ( F_103 ( V_5 ) != F_104 ( V_11 ) ) ;
if ( ! F_13 ( F_9 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_49 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_27 = F_50 ( V_5 ) ;
F_105 ( & V_5 -> V_41 ,
& V_11 -> V_42 [ V_27 ] . V_46 [ V_6 ] ) ;
V_5 += 1 << V_27 ;
V_83 += 1 << V_27 ;
}
return V_83 ;
}
static int F_106 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_84 , V_85 ;
struct V_5 * V_81 , * V_82 ;
V_84 = F_9 ( V_5 ) ;
V_84 = V_84 & ~ ( V_86 - 1 ) ;
V_81 = F_107 ( V_84 ) ;
V_82 = V_81 + V_86 - 1 ;
V_85 = V_84 + V_86 - 1 ;
if ( V_84 < V_11 -> V_15 )
V_81 = V_5 ;
if ( V_85 >= V_11 -> V_15 + V_11 -> V_16 )
return 0 ;
return F_100 ( V_11 , V_81 , V_82 , V_6 ) ;
}
static void F_108 ( struct V_5 * V_87 ,
int V_88 , int V_6 )
{
int V_89 = 1 << ( V_88 - V_90 ) ;
while ( V_89 -- ) {
F_5 ( V_87 , V_6 ) ;
V_87 += V_86 ;
}
}
static inline struct V_5 *
F_109 ( struct V_11 * V_11 , int V_27 , int V_91 )
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
if ( F_66 ( & V_75 -> V_46 [ V_6 ] ) )
continue;
V_5 = F_67 ( V_75 -> V_46 [ V_6 ] . V_80 ,
struct V_5 , V_41 ) ;
V_75 -> V_43 -- ;
if ( F_6 ( V_79 >= ( V_90 >> 1 ) ) ||
V_91 == V_95 ||
V_7 ) {
unsigned long V_96 ;
V_96 = F_106 ( V_11 , V_5 ,
V_91 ) ;
if ( V_96 >= ( 1 << ( V_90 - 1 ) ) ||
V_7 )
F_5 ( V_5 ,
V_91 ) ;
V_6 = V_91 ;
}
F_54 ( & V_5 -> V_41 ) ;
F_44 ( V_5 ) ;
if ( V_79 >= V_90 )
F_108 ( V_5 , V_79 ,
V_91 ) ;
F_95 ( V_11 , V_5 , V_27 , V_79 , V_75 , V_6 ) ;
F_110 ( V_5 , V_27 , V_79 ,
V_91 , V_6 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_111 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
struct V_5 * V_5 ;
V_97:
V_5 = F_99 ( V_11 , V_27 , V_6 ) ;
if ( F_6 ( ! V_5 ) && V_6 != V_94 ) {
V_5 = F_109 ( V_11 , V_27 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_94 ;
goto V_97;
}
}
F_112 ( V_5 , V_27 , V_6 ) ;
return V_5 ;
}
static int F_113 ( struct V_11 * V_11 , unsigned int V_27 ,
unsigned long V_54 , struct V_62 * V_63 ,
int V_6 , int V_98 )
{
int V_28 ;
F_65 ( & V_11 -> V_59 ) ;
for ( V_28 = 0 ; V_28 < V_54 ; ++ V_28 ) {
struct V_5 * V_5 = F_111 ( V_11 , V_27 , V_6 ) ;
if ( F_6 ( V_5 == NULL ) )
break;
if ( F_114 ( V_98 == 0 ) )
F_56 ( & V_5 -> V_41 , V_63 ) ;
else
F_55 ( & V_5 -> V_41 , V_63 ) ;
F_42 ( V_5 , V_6 ) ;
V_63 = & V_5 -> V_41 ;
}
F_70 ( V_11 , V_67 , - ( V_28 << V_27 ) ) ;
F_71 ( & V_11 -> V_59 ) ;
return V_28 ;
}
void F_115 ( struct V_11 * V_11 , struct V_55 * V_56 )
{
unsigned long V_51 ;
int V_99 ;
F_84 ( V_51 ) ;
if ( V_56 -> V_54 >= V_56 -> V_100 )
V_99 = V_56 -> V_100 ;
else
V_99 = V_56 -> V_54 ;
F_64 ( V_11 , V_99 , V_56 ) ;
V_56 -> V_54 -= V_99 ;
F_87 ( V_51 ) ;
}
static void F_116 ( unsigned int V_101 )
{
unsigned long V_51 ;
struct V_11 * V_11 ;
F_117 (zone) {
struct V_102 * V_103 ;
struct V_55 * V_56 ;
F_84 ( V_51 ) ;
V_103 = F_118 ( V_11 -> V_104 , V_101 ) ;
V_56 = & V_103 -> V_56 ;
if ( V_56 -> V_54 ) {
F_64 ( V_11 , V_56 -> V_54 , V_56 ) ;
V_56 -> V_54 = 0 ;
}
F_87 ( V_51 ) ;
}
}
void F_119 ( void * V_105 )
{
F_116 ( F_120 () ) ;
}
void F_121 ( void )
{
F_122 ( F_119 , NULL , 1 ) ;
}
void F_123 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_106 ;
unsigned long V_51 ;
int V_27 , V_107 ;
struct V_62 * V_108 ;
if ( ! V_11 -> V_16 )
return;
F_124 ( & V_11 -> V_59 , V_51 ) ;
V_106 = V_11 -> V_15 + V_11 -> V_16 ;
for ( V_14 = V_11 -> V_15 ; V_14 < V_106 ; V_14 ++ )
if ( F_125 ( V_14 ) ) {
struct V_5 * V_5 = F_107 ( V_14 ) ;
if ( ! F_126 ( V_5 ) )
F_127 ( V_5 ) ;
}
F_128 (order, t) {
F_129 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_28 ;
V_14 = F_9 ( F_67 ( V_108 , struct V_5 , V_41 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1UL << V_27 ) ; V_28 ++ )
F_130 ( F_107 ( V_14 + V_28 ) ) ;
}
}
F_131 ( & V_11 -> V_59 , V_51 ) ;
}
void F_132 ( struct V_5 * V_5 , int V_98 )
{
struct V_11 * V_11 = F_14 ( V_5 ) ;
struct V_55 * V_56 ;
unsigned long V_51 ;
int V_6 ;
int V_69 = F_83 ( V_5 ) ;
if ( ! F_73 ( V_5 , 0 ) )
return;
V_6 = F_86 ( V_5 ) ;
F_42 ( V_5 , V_6 ) ;
F_84 ( V_51 ) ;
if ( F_6 ( V_69 ) )
F_57 ( V_5 ) ;
F_59 ( V_70 ) ;
if ( V_6 >= V_64 ) {
if ( F_6 ( V_6 == V_109 ) ) {
F_72 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_21;
}
V_6 = V_110 ;
}
V_56 = & F_133 ( V_11 -> V_104 ) -> V_56 ;
if ( V_98 )
F_55 ( & V_5 -> V_41 , & V_56 -> V_65 [ V_6 ] ) ;
else
F_56 ( & V_5 -> V_41 , & V_56 -> V_65 [ V_6 ] ) ;
V_56 -> V_54 ++ ;
if ( V_56 -> V_54 >= V_56 -> V_74 ) {
F_64 ( V_11 , V_56 -> V_100 , V_56 ) ;
V_56 -> V_54 -= V_56 -> V_100 ;
}
V_21:
F_87 ( V_51 ) ;
}
void F_134 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
F_38 ( F_53 ( V_5 ) ) ;
F_38 ( ! F_51 ( V_5 ) ) ;
#ifdef F_135
if ( F_136 ( V_5 ) )
F_134 ( F_137 ( V_5 [ 0 ] . V_111 ) , V_27 ) ;
#endif
for ( V_28 = 1 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_91 ( V_5 + V_28 ) ;
}
int F_138 ( struct V_5 * V_5 )
{
unsigned int V_27 ;
unsigned long V_112 ;
struct V_11 * V_11 ;
F_102 ( ! F_49 ( V_5 ) ) ;
V_11 = F_14 ( V_5 ) ;
V_27 = F_50 ( V_5 ) ;
V_112 = F_139 ( V_11 ) + ( 1 << V_27 ) ;
if ( ! F_140 ( V_11 , 0 , V_112 , 0 , 0 ) )
return 0 ;
F_54 ( & V_5 -> V_41 ) ;
V_11 -> V_42 [ V_27 ] . V_43 -- ;
F_44 ( V_5 ) ;
F_70 ( V_11 , V_67 , - ( 1UL << V_27 ) ) ;
F_91 ( V_5 ) ;
F_134 ( V_5 , V_27 ) ;
if ( V_27 >= V_90 - 1 ) {
struct V_5 * V_113 = V_5 + ( 1 << V_27 ) - 1 ;
for (; V_5 < V_113 ; V_5 += V_86 )
F_5 ( V_5 , V_110 ) ;
}
return 1 << V_27 ;
}
static inline
struct V_5 * F_141 ( struct V_11 * V_114 ,
struct V_11 * V_11 , int V_27 , T_1 V_33 ,
int V_6 )
{
unsigned long V_51 ;
struct V_5 * V_5 ;
int V_98 = ! ! ( V_33 & V_115 ) ;
V_116:
if ( F_114 ( V_27 == 0 ) ) {
struct V_55 * V_56 ;
struct V_62 * V_63 ;
F_84 ( V_51 ) ;
V_56 = & F_133 ( V_11 -> V_104 ) -> V_56 ;
V_63 = & V_56 -> V_65 [ V_6 ] ;
if ( F_66 ( V_63 ) ) {
V_56 -> V_54 += F_113 ( V_11 , 0 ,
V_56 -> V_100 , V_63 ,
V_6 , V_98 ) ;
if ( F_6 ( F_66 ( V_63 ) ) )
goto V_117;
}
if ( V_98 )
V_5 = F_67 ( V_63 -> V_66 , struct V_5 , V_41 ) ;
else
V_5 = F_67 ( V_63 -> V_80 , struct V_5 , V_41 ) ;
F_54 ( & V_5 -> V_41 ) ;
V_56 -> V_54 -- ;
} else {
if ( F_6 ( V_33 & V_118 ) ) {
F_142 ( V_27 > 1 ) ;
}
F_124 ( & V_11 -> V_59 , V_51 ) ;
V_5 = F_111 ( V_11 , V_27 , V_6 ) ;
F_71 ( & V_11 -> V_59 ) ;
if ( ! V_5 )
goto V_117;
F_70 ( V_11 , V_67 , - ( 1 << V_27 ) ) ;
}
F_143 ( V_119 , V_11 , 1 << V_27 ) ;
F_144 ( V_114 , V_11 , V_33 ) ;
F_87 ( V_51 ) ;
F_38 ( F_15 ( V_11 , V_5 ) ) ;
if ( F_97 ( V_5 , V_27 , V_33 ) )
goto V_116;
return V_5 ;
V_117:
F_87 ( V_51 ) ;
return NULL ;
}
static int T_3 F_145 ( char * V_120 )
{
return F_146 ( & V_121 . V_122 , V_120 ) ;
}
static int F_147 ( T_1 V_123 , unsigned int V_27 )
{
if ( V_27 < V_121 . V_124 )
return 0 ;
if ( V_123 & V_118 )
return 0 ;
if ( V_121 . V_125 && ( V_123 & V_34 ) )
return 0 ;
if ( V_121 . V_126 && ( V_123 & V_127 ) )
return 0 ;
return F_148 ( & V_121 . V_122 , 1 << V_27 ) ;
}
static int T_3 F_149 ( void )
{
T_4 V_128 = V_129 | V_130 | V_131 ;
struct V_132 * V_133 ;
int V_134 ;
V_134 = F_150 ( & V_121 . V_122 ,
L_3 ) ;
if ( V_134 )
return V_134 ;
V_133 = V_121 . V_122 . V_135 . V_133 ;
V_121 . V_136 =
F_151 ( L_4 , V_128 , V_133 ,
& V_121 . V_126 ) ;
V_121 . V_137 =
F_151 ( L_5 , V_128 , V_133 ,
& V_121 . V_125 ) ;
V_121 . V_138 =
F_152 ( L_6 , V_128 , V_133 ,
& V_121 . V_124 ) ;
if ( ! V_121 . V_136 ||
! V_121 . V_137 ||
! V_121 . V_138 ) {
V_134 = - V_139 ;
F_153 ( V_121 . V_136 ) ;
F_153 ( V_121 . V_137 ) ;
F_153 ( V_121 . V_138 ) ;
F_154 ( & V_121 . V_122 ) ;
}
return V_134 ;
}
static inline int F_147 ( T_1 V_123 , unsigned int V_27 )
{
return 0 ;
}
static bool F_155 ( struct V_11 * V_140 , int V_27 , unsigned long V_141 ,
int V_142 , int V_143 , long V_144 )
{
long V_145 = V_141 ;
int V_146 ;
V_144 -= ( 1 << V_27 ) + 1 ;
if ( V_143 & V_147 )
V_145 -= V_145 / 2 ;
if ( V_143 & V_148 )
V_145 -= V_145 / 4 ;
if ( V_144 <= V_145 + V_140 -> V_149 [ V_142 ] )
return false ;
for ( V_146 = 0 ; V_146 < V_27 ; V_146 ++ ) {
V_144 -= V_140 -> V_42 [ V_146 ] . V_43 << V_146 ;
V_145 >>= 1 ;
if ( V_144 <= V_145 )
return false ;
}
return true ;
}
bool F_140 ( struct V_11 * V_140 , int V_27 , unsigned long V_141 ,
int V_142 , int V_143 )
{
return F_155 ( V_140 , V_27 , V_141 , V_142 , V_143 ,
F_156 ( V_140 , V_67 ) ) ;
}
bool F_157 ( struct V_11 * V_140 , int V_27 , unsigned long V_141 ,
int V_142 , int V_143 )
{
long V_144 = F_156 ( V_140 , V_67 ) ;
if ( V_140 -> V_150 && V_144 < V_140 -> V_150 )
V_144 = F_158 ( V_140 , V_67 ) ;
return F_155 ( V_140 , V_27 , V_141 , V_142 , V_143 ,
V_144 ) ;
}
static T_5 * F_159 ( struct V_151 * V_151 , int V_143 )
{
struct V_152 * V_153 ;
T_5 * V_154 ;
V_153 = V_151 -> V_155 ;
if ( ! V_153 )
return NULL ;
if ( F_160 ( V_20 , V_153 -> V_156 + V_23 ) ) {
F_161 ( V_153 -> V_157 , V_158 ) ;
V_153 -> V_156 = V_20 ;
}
V_154 = ! F_39 () && ( V_143 & V_159 ) ?
& V_160 :
& V_161 [ V_162 ] ;
return V_154 ;
}
static int F_162 ( struct V_151 * V_151 , struct V_163 * V_140 ,
T_5 * V_154 )
{
struct V_152 * V_153 ;
int V_28 ;
int V_164 ;
V_153 = V_151 -> V_155 ;
if ( ! V_153 )
return 1 ;
V_28 = V_140 - V_151 -> V_165 ;
V_164 = V_153 -> V_166 [ V_28 ] ;
return F_163 ( V_164 , * V_154 ) && ! F_164 ( V_28 , V_153 -> V_157 ) ;
}
static void F_165 ( struct V_151 * V_151 , struct V_163 * V_140 )
{
struct V_152 * V_153 ;
int V_28 ;
V_153 = V_151 -> V_155 ;
if ( ! V_153 )
return;
V_28 = V_140 - V_151 -> V_165 ;
F_166 ( V_28 , V_153 -> V_157 ) ;
}
static T_5 * F_159 ( struct V_151 * V_151 , int V_143 )
{
return NULL ;
}
static int F_162 ( struct V_151 * V_151 , struct V_163 * V_140 ,
T_5 * V_154 )
{
return 1 ;
}
static void F_165 ( struct V_151 * V_151 , struct V_163 * V_140 )
{
}
static struct V_5 *
F_167 ( T_1 V_123 , T_5 * V_167 , unsigned int V_27 ,
struct V_151 * V_151 , int V_168 , int V_143 ,
struct V_11 * V_114 , int V_6 )
{
struct V_163 * V_140 ;
struct V_5 * V_5 = NULL ;
int V_142 ;
struct V_11 * V_11 ;
T_5 * V_154 = NULL ;
int V_169 = 0 ;
int V_170 = 0 ;
V_142 = F_168 ( V_114 ) ;
V_171:
F_169 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( V_172 && V_169 &&
! F_162 ( V_151 , V_140 , V_154 ) )
continue;
if ( ( V_143 & V_159 ) &&
! F_170 ( V_11 , V_123 ) )
goto V_173;
F_171 ( V_174 < V_175 ) ;
if ( ! ( V_143 & V_174 ) ) {
unsigned long V_141 ;
int V_12 ;
V_141 = V_11 -> V_112 [ V_143 & V_176 ] ;
if ( F_140 ( V_11 , V_27 , V_141 ,
V_142 , V_143 ) )
goto V_177;
if ( V_178 == 0 )
goto V_179;
V_12 = F_172 ( V_11 , V_123 , V_27 ) ;
switch ( V_12 ) {
case V_180 :
goto V_173;
case V_181 :
goto V_179;
default:
if ( ! F_140 ( V_11 , V_27 , V_141 ,
V_142 , V_143 ) )
goto V_179;
}
}
V_177:
V_5 = F_141 ( V_114 , V_11 , V_27 ,
V_123 , V_6 ) ;
if ( V_5 )
break;
V_179:
if ( V_172 )
F_165 ( V_151 , V_140 ) ;
V_173:
if ( V_172 && ! V_170 && V_182 > 1 ) {
V_154 = F_159 ( V_151 , V_143 ) ;
V_169 = 1 ;
V_170 = 1 ;
}
}
if ( F_6 ( V_172 && V_5 == NULL && V_169 ) ) {
V_169 = 0 ;
goto V_171;
}
return V_5 ;
}
static inline bool F_173 ( void )
{
bool V_12 = false ;
#if V_183 > 8
V_12 = F_39 () ;
#endif
return V_12 ;
}
void F_174 ( T_1 V_123 , int V_27 , const char * V_184 , ... )
{
T_6 args ;
unsigned int V_185 = V_186 ;
if ( ( V_123 & V_187 ) || ! F_175 ( & V_188 ) )
return;
if ( ! ( V_123 & V_189 ) )
if ( F_176 ( V_190 ) ||
( V_24 -> V_51 & ( V_191 | V_192 ) ) )
V_185 &= ~ V_186 ;
if ( F_39 () || ! ( V_123 & V_127 ) )
V_185 &= ~ V_186 ;
if ( V_184 ) {
F_20 ( V_193 ) ;
va_start ( args , V_184 ) ;
F_177 ( V_184 , args ) ;
va_end ( args ) ;
}
F_178 ( L_7 ,
V_24 -> V_25 , V_27 , V_123 ) ;
F_22 () ;
if ( ! F_173 () )
F_179 ( V_185 ) ;
}
static inline int
F_180 ( T_1 V_123 , unsigned int V_27 ,
unsigned long V_194 )
{
if ( V_123 & V_195 )
return 0 ;
if ( V_27 <= V_196 )
return 1 ;
if ( V_123 & V_197 && V_194 < ( 1 << V_27 ) )
return 1 ;
if ( V_123 & V_118 )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_181 ( T_1 V_123 , unsigned int V_27 ,
struct V_151 * V_151 , enum V_198 V_168 ,
T_5 * V_167 , struct V_11 * V_114 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_182 ( V_151 , V_123 ) ) {
F_183 ( 1 ) ;
return NULL ;
}
V_5 = F_167 ( V_123 | V_199 , V_167 ,
V_27 , V_151 , V_168 ,
V_200 | V_159 ,
V_114 , V_6 ) ;
if ( V_5 )
goto V_21;
if ( ! ( V_123 & V_118 ) ) {
if ( V_27 > V_196 )
goto V_21;
if ( V_168 < V_201 )
goto V_21;
if ( V_123 & V_202 )
goto V_21;
}
F_184 ( V_151 , V_123 , V_27 , V_167 ) ;
V_21:
F_185 ( V_151 , V_123 ) ;
return V_5 ;
}
static struct V_5 *
F_186 ( T_1 V_123 , unsigned int V_27 ,
struct V_151 * V_151 , enum V_198 V_168 ,
T_5 * V_167 , int V_143 , struct V_11 * V_114 ,
int V_6 , unsigned long * V_203 ,
bool V_204 )
{
struct V_5 * V_5 ;
if ( ! V_27 || F_187 ( V_114 ) )
return NULL ;
V_24 -> V_51 |= V_191 ;
* V_203 = F_188 ( V_151 , V_27 , V_123 ,
V_167 , V_204 ) ;
V_24 -> V_51 &= ~ V_191 ;
if ( * V_203 != V_205 ) {
F_116 ( F_189 () ) ;
F_190 () ;
V_5 = F_167 ( V_123 , V_167 ,
V_27 , V_151 , V_168 ,
V_143 , V_114 ,
V_6 ) ;
if ( V_5 ) {
V_114 -> V_206 = 0 ;
V_114 -> V_207 = 0 ;
F_191 ( V_208 ) ;
return V_5 ;
}
F_191 ( V_209 ) ;
F_192 ( V_114 ) ;
F_193 () ;
}
return NULL ;
}
static inline struct V_5 *
F_186 ( T_1 V_123 , unsigned int V_27 ,
struct V_151 * V_151 , enum V_198 V_168 ,
T_5 * V_167 , int V_143 , struct V_11 * V_114 ,
int V_6 , unsigned long * V_203 ,
bool V_204 )
{
return NULL ;
}
static inline struct V_5 *
F_194 ( T_1 V_123 , unsigned int V_27 ,
struct V_151 * V_151 , enum V_198 V_168 ,
T_5 * V_167 , int V_143 , struct V_11 * V_114 ,
int V_6 , unsigned long * V_203 )
{
struct V_5 * V_5 = NULL ;
struct V_210 V_210 ;
bool V_211 = false ;
F_193 () ;
F_195 () ;
V_24 -> V_51 |= V_191 ;
F_196 ( V_123 ) ;
V_210 . V_212 = 0 ;
V_24 -> V_210 = & V_210 ;
* V_203 = F_197 ( V_151 , V_27 , V_123 , V_167 ) ;
V_24 -> V_210 = NULL ;
F_198 () ;
V_24 -> V_51 &= ~ V_191 ;
F_193 () ;
if ( F_6 ( ! ( * V_203 ) ) )
return NULL ;
V_213:
V_5 = F_167 ( V_123 , V_167 , V_27 ,
V_151 , V_168 ,
V_143 , V_114 ,
V_6 ) ;
if ( ! V_5 && ! V_211 ) {
F_121 () ;
V_211 = true ;
goto V_213;
}
return V_5 ;
}
static inline struct V_5 *
F_199 ( T_1 V_123 , unsigned int V_27 ,
struct V_151 * V_151 , enum V_198 V_168 ,
T_5 * V_167 , struct V_11 * V_114 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_167 ( V_123 , V_167 , V_27 ,
V_151 , V_168 , V_174 ,
V_114 , V_6 ) ;
if ( ! V_5 && V_123 & V_118 )
F_200 ( V_114 , V_214 , V_23 / 50 ) ;
} while ( ! V_5 && ( V_123 & V_118 ) );
return V_5 ;
}
static inline
void F_201 ( unsigned int V_27 , struct V_151 * V_151 ,
enum V_198 V_168 ,
enum V_198 V_142 )
{
struct V_163 * V_140 ;
struct V_11 * V_11 ;
F_202 (zone, z, zonelist, high_zoneidx)
F_203 ( V_11 , V_27 , V_142 ) ;
}
static inline int
F_204 ( T_1 V_123 )
{
int V_143 = V_215 | V_159 ;
const T_1 V_216 = V_123 & V_127 ;
F_171 ( V_217 != ( V_218 T_1 ) V_147 ) ;
V_143 |= ( V_218 int ) ( V_123 & V_217 ) ;
if ( ! V_216 ) {
if ( ! ( V_123 & V_189 ) )
V_143 |= V_148 ;
V_143 &= ~ V_159 ;
} else if ( F_6 ( F_205 ( V_24 ) ) && ! F_39 () )
V_143 |= V_148 ;
if ( F_114 ( ! ( V_123 & V_189 ) ) ) {
if ( ! F_39 () &&
( ( V_24 -> V_51 & V_191 ) ||
F_6 ( F_176 ( V_190 ) ) ) )
V_143 |= V_174 ;
}
return V_143 ;
}
static inline struct V_5 *
F_206 ( T_1 V_123 , unsigned int V_27 ,
struct V_151 * V_151 , enum V_198 V_168 ,
T_5 * V_167 , struct V_11 * V_114 ,
int V_6 )
{
const T_1 V_216 = V_123 & V_127 ;
struct V_5 * V_5 = NULL ;
int V_143 ;
unsigned long V_194 = 0 ;
unsigned long V_203 ;
bool V_204 = false ;
if ( V_27 >= V_40 ) {
F_142 ( ! ( V_123 & V_187 ) ) ;
return NULL ;
}
if ( V_172 && ( V_123 & V_219 ) == V_219 )
goto V_220;
V_221:
if ( ! ( V_123 & V_222 ) )
F_201 ( V_27 , V_151 , V_168 ,
F_168 ( V_114 ) ) ;
V_143 = F_204 ( V_123 ) ;
if ( ! ( V_143 & V_159 ) && ! V_167 )
F_207 ( V_151 , V_168 , NULL ,
& V_114 ) ;
V_223:
V_5 = F_167 ( V_123 , V_167 , V_27 , V_151 ,
V_168 , V_143 & ~ V_174 ,
V_114 , V_6 ) ;
if ( V_5 )
goto V_224;
if ( V_143 & V_174 ) {
V_5 = F_199 ( V_123 , V_27 ,
V_151 , V_168 , V_167 ,
V_114 , V_6 ) ;
if ( V_5 )
goto V_224;
}
if ( ! V_216 )
goto V_220;
if ( V_24 -> V_51 & V_191 )
goto V_220;
if ( F_176 ( V_190 ) && ! ( V_123 & V_118 ) )
goto V_220;
V_5 = F_186 ( V_123 , V_27 ,
V_151 , V_168 ,
V_167 ,
V_143 , V_114 ,
V_6 , & V_203 ,
V_204 ) ;
if ( V_5 )
goto V_224;
V_204 = true ;
V_5 = F_194 ( V_123 , V_27 ,
V_151 , V_168 ,
V_167 ,
V_143 , V_114 ,
V_6 , & V_203 ) ;
if ( V_5 )
goto V_224;
if ( ! V_203 ) {
if ( ( V_123 & V_225 ) && ! ( V_123 & V_195 ) ) {
if ( V_226 )
goto V_220;
V_5 = F_181 ( V_123 , V_27 ,
V_151 , V_168 ,
V_167 , V_114 ,
V_6 ) ;
if ( V_5 )
goto V_224;
if ( ! ( V_123 & V_118 ) ) {
if ( V_27 > V_196 )
goto V_220;
if ( V_168 < V_201 )
goto V_220;
}
goto V_221;
}
}
V_194 += V_203 ;
if ( F_180 ( V_123 , V_27 , V_194 ) ) {
F_200 ( V_114 , V_214 , V_23 / 50 ) ;
goto V_223;
} else {
V_5 = F_186 ( V_123 , V_27 ,
V_151 , V_168 ,
V_167 ,
V_143 , V_114 ,
V_6 , & V_203 ,
V_204 ) ;
if ( V_5 )
goto V_224;
}
V_220:
F_174 ( V_123 , V_27 , NULL ) ;
return V_5 ;
V_224:
if ( V_227 )
F_208 ( V_5 , V_27 , V_123 ) ;
return V_5 ;
}
struct V_5 *
F_209 ( T_1 V_123 , unsigned int V_27 ,
struct V_151 * V_151 , T_5 * V_167 )
{
enum V_198 V_168 = F_210 ( V_123 ) ;
struct V_11 * V_114 ;
struct V_5 * V_5 ;
int V_6 = F_211 ( V_123 ) ;
V_123 &= V_3 ;
F_212 ( V_123 ) ;
F_213 ( V_123 & V_127 ) ;
if ( F_147 ( V_123 , V_27 ) )
return NULL ;
if ( F_6 ( ! V_151 -> V_165 -> V_11 ) )
return NULL ;
F_214 () ;
F_207 ( V_151 , V_168 ,
V_167 ? : & V_160 ,
& V_114 ) ;
if ( ! V_114 ) {
F_215 () ;
return NULL ;
}
V_5 = F_167 ( V_123 | V_199 , V_167 , V_27 ,
V_151 , V_168 , V_228 | V_159 ,
V_114 , V_6 ) ;
if ( F_6 ( ! V_5 ) )
V_5 = F_206 ( V_123 , V_27 ,
V_151 , V_168 , V_167 ,
V_114 , V_6 ) ;
F_215 () ;
F_216 ( V_5 , V_27 , V_123 , V_6 ) ;
return V_5 ;
}
unsigned long F_217 ( T_1 V_123 , unsigned int V_27 )
{
struct V_5 * V_5 ;
F_38 ( ( V_123 & V_34 ) != 0 ) ;
V_5 = F_218 ( V_123 , V_27 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_79 ( V_5 ) ;
}
unsigned long F_219 ( T_1 V_123 )
{
return F_217 ( V_123 | V_77 , 0 ) ;
}
void F_220 ( struct V_229 * V_230 )
{
int V_28 = F_221 ( V_230 ) ;
while ( -- V_28 >= 0 ) {
F_222 ( V_230 -> V_96 [ V_28 ] , V_230 -> V_98 ) ;
F_132 ( V_230 -> V_96 [ V_28 ] , V_230 -> V_98 ) ;
}
}
void F_94 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( F_223 ( V_5 ) ) {
if ( V_27 == 0 )
F_132 ( V_5 , 0 ) ;
else
F_25 ( V_5 , V_27 ) ;
}
}
void V_144 ( unsigned long V_231 , unsigned int V_27 )
{
if ( V_231 != 0 ) {
F_38 ( ! F_224 ( ( void * ) V_231 ) ) ;
F_94 ( F_137 ( ( void * ) V_231 ) , V_27 ) ;
}
}
static void * F_225 ( unsigned long V_231 , unsigned V_27 , T_7 V_76 )
{
if ( V_231 ) {
unsigned long V_232 = V_231 + ( V_68 << V_27 ) ;
unsigned long V_233 = V_231 + F_226 ( V_76 ) ;
F_134 ( F_137 ( ( void * ) V_231 ) , V_27 ) ;
while ( V_233 < V_232 ) {
F_227 ( V_233 ) ;
V_233 += V_68 ;
}
}
return ( void * ) V_231 ;
}
void * F_228 ( T_7 V_76 , T_1 V_123 )
{
unsigned int V_27 = F_229 ( V_76 ) ;
unsigned long V_231 ;
V_231 = F_217 ( V_123 , V_27 ) ;
return F_225 ( V_231 , V_27 , V_76 ) ;
}
void * F_230 ( int V_234 , T_7 V_76 , T_1 V_123 )
{
unsigned V_27 = F_229 ( V_76 ) ;
struct V_5 * V_30 = F_231 ( V_234 , V_123 , V_27 ) ;
if ( ! V_30 )
return NULL ;
return F_225 ( ( unsigned long ) F_79 ( V_30 ) , V_27 , V_76 ) ;
}
void F_232 ( void * V_235 , T_7 V_76 )
{
unsigned long V_231 = ( unsigned long ) V_235 ;
unsigned long V_236 = V_231 + F_226 ( V_76 ) ;
while ( V_231 < V_236 ) {
F_227 ( V_231 ) ;
V_231 += V_68 ;
}
}
static unsigned int F_233 ( int V_237 )
{
struct V_163 * V_140 ;
struct V_11 * V_11 ;
unsigned int V_238 = 0 ;
struct V_151 * V_151 = F_234 ( F_235 () , V_239 ) ;
F_202 (zone, z, zonelist, offset) {
unsigned long V_76 = V_11 -> V_240 ;
unsigned long V_74 = F_236 ( V_11 ) ;
if ( V_76 > V_74 )
V_238 += V_76 - V_74 ;
}
return V_238 ;
}
unsigned int F_237 ( void )
{
return F_233 ( F_210 ( V_241 ) ) ;
}
unsigned int F_238 ( void )
{
return F_233 ( F_210 ( V_242 ) ) ;
}
static inline void F_239 ( struct V_11 * V_11 )
{
if ( V_172 )
F_20 ( L_8 , F_104 ( V_11 ) ) ;
}
void F_240 ( struct V_243 * V_244 )
{
V_244 -> V_245 = V_246 ;
V_244 -> V_247 = 0 ;
V_244 -> V_248 = F_241 ( V_67 ) ;
V_244 -> V_249 = F_242 () ;
V_244 -> V_250 = V_251 ;
V_244 -> V_252 = F_243 () ;
V_244 -> V_253 = V_68 ;
}
void F_244 ( struct V_243 * V_244 , int V_234 )
{
T_8 * V_254 = F_245 ( V_234 ) ;
V_244 -> V_245 = V_254 -> V_255 ;
V_244 -> V_248 = F_246 ( V_234 , V_67 ) ;
#ifdef F_247
V_244 -> V_250 = V_254 -> V_256 [ V_257 ] . V_240 ;
V_244 -> V_252 = F_156 ( & V_254 -> V_256 [ V_257 ] ,
V_67 ) ;
#else
V_244 -> V_250 = 0 ;
V_244 -> V_252 = 0 ;
#endif
V_244 -> V_253 = V_68 ;
}
bool F_248 ( unsigned int V_51 , int V_234 )
{
bool V_12 = false ;
if ( ! ( V_51 & V_186 ) )
goto V_21;
F_214 () ;
V_12 = ! F_163 ( V_234 , V_160 ) ;
F_215 () ;
V_21:
return V_12 ;
}
void F_249 ( unsigned int V_185 )
{
int V_101 ;
struct V_11 * V_11 ;
F_117 (zone) {
if ( F_248 ( V_185 , F_104 ( V_11 ) ) )
continue;
F_239 ( V_11 ) ;
F_20 ( L_9 , V_11 -> V_258 ) ;
F_250 (cpu) {
struct V_102 * V_104 ;
V_104 = F_118 ( V_11 -> V_104 , V_101 ) ;
F_20 ( L_10 ,
V_101 , V_104 -> V_56 . V_74 ,
V_104 -> V_56 . V_100 , V_104 -> V_56 . V_54 ) ;
}
}
F_20 ( L_11
L_12
L_13
L_14
L_15
L_16 ,
F_241 ( V_259 ) ,
F_241 ( V_260 ) ,
F_241 ( V_261 ) ,
F_241 ( V_262 ) ,
F_241 ( V_263 ) ,
F_241 ( V_264 ) ,
F_241 ( V_265 ) ,
F_241 ( V_266 ) ,
F_241 ( V_267 ) ,
F_241 ( V_268 ) ,
F_241 ( V_67 ) ,
F_241 ( V_269 ) ,
F_241 ( V_270 ) ,
F_241 ( V_271 ) ,
F_241 ( V_272 ) ,
F_241 ( V_273 ) ,
F_241 ( V_274 ) ) ;
F_117 (zone) {
int V_28 ;
if ( F_248 ( V_185 , F_104 ( V_11 ) ) )
continue;
F_239 ( V_11 ) ;
F_20 ( L_17
L_18
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
L_44 ,
V_11 -> V_258 ,
F_251 ( F_156 ( V_11 , V_67 ) ) ,
F_251 ( F_252 ( V_11 ) ) ,
F_251 ( F_139 ( V_11 ) ) ,
F_251 ( F_236 ( V_11 ) ) ,
F_251 ( F_156 ( V_11 , V_259 ) ) ,
F_251 ( F_156 ( V_11 , V_260 ) ) ,
F_251 ( F_156 ( V_11 , V_262 ) ) ,
F_251 ( F_156 ( V_11 , V_263 ) ) ,
F_251 ( F_156 ( V_11 , V_265 ) ) ,
F_251 ( F_156 ( V_11 , V_261 ) ) ,
F_251 ( F_156 ( V_11 , V_264 ) ) ,
F_251 ( V_11 -> V_240 ) ,
F_251 ( F_156 ( V_11 , V_47 ) ) ,
F_251 ( F_156 ( V_11 , V_266 ) ) ,
F_251 ( F_156 ( V_11 , V_267 ) ) ,
F_251 ( F_156 ( V_11 , V_271 ) ) ,
F_251 ( F_156 ( V_11 , V_272 ) ) ,
F_251 ( F_156 ( V_11 , V_269 ) ) ,
F_251 ( F_156 ( V_11 , V_270 ) ) ,
F_156 ( V_11 , V_275 ) *
V_276 / 1024 ,
F_251 ( F_156 ( V_11 , V_273 ) ) ,
F_251 ( F_156 ( V_11 , V_268 ) ) ,
F_251 ( F_156 ( V_11 , V_274 ) ) ,
F_251 ( F_156 ( V_11 , V_277 ) ) ,
V_11 -> V_61 ,
( V_11 -> V_60 ? L_45 : L_46 )
) ;
F_20 ( L_47 ) ;
for ( V_28 = 0 ; V_28 < V_278 ; V_28 ++ )
F_20 ( L_48 , V_11 -> V_149 [ V_28 ] ) ;
F_20 ( L_44 ) ;
}
F_117 (zone) {
unsigned long V_279 [ V_40 ] , V_51 , V_27 , V_280 = 0 ;
if ( F_248 ( V_185 , F_104 ( V_11 ) ) )
continue;
F_239 ( V_11 ) ;
F_20 ( L_49 , V_11 -> V_258 ) ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
V_279 [ V_27 ] = V_11 -> V_42 [ V_27 ] . V_43 ;
V_280 += V_279 [ V_27 ] << V_27 ;
}
F_131 ( & V_11 -> V_59 , V_51 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ )
F_20 ( L_50 , V_279 [ V_27 ] , F_251 ( 1UL ) << V_27 ) ;
F_20 ( L_51 , F_251 ( V_280 ) ) ;
}
F_20 ( L_52 , F_241 ( V_281 ) ) ;
F_253 () ;
}
static void F_254 ( struct V_11 * V_11 , struct V_163 * V_163 )
{
V_163 -> V_11 = V_11 ;
V_163 -> F_168 = F_168 ( V_11 ) ;
}
static int F_255 ( T_8 * V_254 , struct V_151 * V_151 ,
int V_282 , enum V_198 V_198 )
{
struct V_11 * V_11 ;
F_102 ( V_198 >= V_278 ) ;
V_198 ++ ;
do {
V_198 -- ;
V_11 = V_254 -> V_256 + V_198 ;
if ( F_256 ( V_11 ) ) {
F_254 ( V_11 ,
& V_151 -> V_165 [ V_282 ++ ] ) ;
F_257 ( V_198 ) ;
}
} while ( V_198 );
return V_282 ;
}
static int F_258 ( char * V_283 )
{
if ( * V_283 == 'd' || * V_283 == 'D' ) {
V_284 = V_285 ;
} else if ( * V_283 == 'n' || * V_283 == 'N' ) {
V_284 = V_286 ;
} else if ( * V_283 == 'z' || * V_283 == 'Z' ) {
V_284 = V_287 ;
} else {
F_20 ( V_193
L_53
L_54 , V_283 ) ;
return - V_288 ;
}
return 0 ;
}
static T_3 int F_259 ( char * V_283 )
{
int V_12 ;
if ( ! V_283 )
return 0 ;
V_12 = F_258 ( V_283 ) ;
if ( V_12 == 0 )
F_260 ( V_289 , V_283 , V_290 ) ;
return V_12 ;
}
int F_261 ( T_9 * V_291 , int V_292 ,
void T_10 * V_293 , T_7 * V_294 ,
T_11 * V_295 )
{
char V_296 [ V_290 ] ;
int V_12 ;
static F_262 ( V_297 ) ;
F_263 ( & V_297 ) ;
if ( V_292 )
strcpy ( V_296 , ( char * ) V_291 -> V_298 ) ;
V_12 = F_264 ( V_291 , V_292 , V_293 , V_294 , V_295 ) ;
if ( V_12 )
goto V_21;
if ( V_292 ) {
int V_299 = V_284 ;
if ( F_258 ( ( char * ) V_291 -> V_298 ) ) {
strncpy ( ( char * ) V_291 -> V_298 , V_296 ,
V_290 ) ;
V_284 = V_299 ;
} else if ( V_299 != V_284 ) {
F_263 ( & V_300 ) ;
F_265 ( NULL ) ;
F_266 ( & V_300 ) ;
}
}
V_21:
F_266 ( & V_297 ) ;
return V_12 ;
}
static int F_267 ( int V_301 , T_5 * V_302 )
{
int V_164 , V_244 ;
int V_303 = V_304 ;
int V_305 = - 1 ;
const struct V_306 * V_307 = F_268 ( 0 ) ;
if ( ! F_163 ( V_301 , * V_302 ) ) {
F_269 ( V_301 , * V_302 ) ;
return V_301 ;
}
F_270 (n, N_HIGH_MEMORY) {
if ( F_163 ( V_164 , * V_302 ) )
continue;
V_244 = F_271 ( V_301 , V_164 ) ;
V_244 += ( V_164 < V_301 ) ;
V_307 = F_268 ( V_164 ) ;
if ( ! F_272 ( V_307 ) )
V_244 += V_308 ;
V_244 *= ( V_309 * V_310 ) ;
V_244 += V_311 [ V_164 ] ;
if ( V_244 < V_303 ) {
V_303 = V_244 ;
V_305 = V_164 ;
}
}
if ( V_305 >= 0 )
F_269 ( V_305 , * V_302 ) ;
return V_305 ;
}
static void F_273 ( T_8 * V_254 , int V_301 )
{
int V_312 ;
struct V_151 * V_151 ;
V_151 = & V_254 -> V_313 [ 0 ] ;
for ( V_312 = 0 ; V_151 -> V_165 [ V_312 ] . V_11 != NULL ; V_312 ++ )
;
V_312 = F_255 ( F_245 ( V_301 ) , V_151 , V_312 ,
V_278 - 1 ) ;
V_151 -> V_165 [ V_312 ] . V_11 = NULL ;
V_151 -> V_165 [ V_312 ] . F_168 = 0 ;
}
static void F_274 ( T_8 * V_254 )
{
int V_312 ;
struct V_151 * V_151 ;
V_151 = & V_254 -> V_313 [ 1 ] ;
V_312 = F_255 ( V_254 , V_151 , 0 , V_278 - 1 ) ;
V_151 -> V_165 [ V_312 ] . V_11 = NULL ;
V_151 -> V_165 [ V_312 ] . F_168 = 0 ;
}
static void F_275 ( T_8 * V_254 , int V_314 )
{
int V_315 , V_312 , V_301 ;
int V_198 ;
struct V_11 * V_140 ;
struct V_151 * V_151 ;
V_151 = & V_254 -> V_313 [ 0 ] ;
V_315 = 0 ;
for ( V_198 = V_278 - 1 ; V_198 >= 0 ; V_198 -- ) {
for ( V_312 = 0 ; V_312 < V_314 ; V_312 ++ ) {
V_301 = V_316 [ V_312 ] ;
V_140 = & F_245 ( V_301 ) -> V_256 [ V_198 ] ;
if ( F_256 ( V_140 ) ) {
F_254 ( V_140 ,
& V_151 -> V_165 [ V_315 ++ ] ) ;
F_257 ( V_198 ) ;
}
}
}
V_151 -> V_165 [ V_315 ] . V_11 = NULL ;
V_151 -> V_165 [ V_315 ] . F_168 = 0 ;
}
static int F_276 ( void )
{
int V_234 , V_198 ;
unsigned long V_317 , V_318 ;
struct V_11 * V_140 ;
int V_319 ;
V_317 = 0 ;
V_318 = 0 ;
F_277 (nid) {
for ( V_198 = 0 ; V_198 < V_278 ; V_198 ++ ) {
V_140 = & F_245 ( V_234 ) -> V_256 [ V_198 ] ;
if ( F_256 ( V_140 ) ) {
if ( V_198 < V_201 )
V_317 += V_140 -> V_240 ;
V_318 += V_140 -> V_240 ;
} else if ( V_198 == V_201 ) {
return V_286 ;
}
}
}
if ( ! V_317 ||
V_317 > V_318 / 2 )
return V_286 ;
V_319 = V_318 /
( F_278 ( V_161 [ V_162 ] ) + 1 ) ;
F_277 (nid) {
V_317 = 0 ;
V_318 = 0 ;
for ( V_198 = 0 ; V_198 < V_278 ; V_198 ++ ) {
V_140 = & F_245 ( V_234 ) -> V_256 [ V_198 ] ;
if ( F_256 ( V_140 ) ) {
if ( V_198 < V_201 )
V_317 += V_140 -> V_240 ;
V_318 += V_140 -> V_240 ;
}
}
if ( V_317 &&
V_318 > V_319 &&
V_317 > V_318 * 70 / 100 )
return V_286 ;
}
return V_287 ;
}
static void F_279 ( void )
{
if ( V_284 == V_285 )
V_320 = F_276 () ;
else
V_320 = V_284 ;
}
static void F_280 ( T_8 * V_254 )
{
int V_312 , V_301 , V_321 ;
enum V_198 V_28 ;
T_5 V_322 ;
int V_323 , V_324 ;
struct V_151 * V_151 ;
int V_27 = V_320 ;
for ( V_28 = 0 ; V_28 < V_325 ; V_28 ++ ) {
V_151 = V_254 -> V_313 + V_28 ;
V_151 -> V_165 [ 0 ] . V_11 = NULL ;
V_151 -> V_165 [ 0 ] . F_168 = 0 ;
}
V_323 = V_254 -> V_326 ;
V_321 = V_182 ;
V_324 = V_323 ;
F_281 ( V_322 ) ;
memset ( V_316 , 0 , sizeof( V_316 ) ) ;
V_312 = 0 ;
while ( ( V_301 = F_267 ( V_323 , & V_322 ) ) >= 0 ) {
int V_327 = F_271 ( V_323 , V_301 ) ;
if ( V_327 > V_328 )
V_178 = 1 ;
if ( V_327 != F_271 ( V_323 , V_324 ) )
V_311 [ V_301 ] = V_321 ;
V_324 = V_301 ;
V_321 -- ;
if ( V_27 == V_286 )
F_273 ( V_254 , V_301 ) ;
else
V_316 [ V_312 ++ ] = V_301 ;
}
if ( V_27 == V_287 ) {
F_275 ( V_254 , V_312 ) ;
}
F_274 ( V_254 ) ;
}
static void F_282 ( T_8 * V_254 )
{
struct V_151 * V_151 ;
struct V_152 * V_153 ;
struct V_163 * V_140 ;
V_151 = & V_254 -> V_313 [ 0 ] ;
V_151 -> V_155 = V_153 = & V_151 -> V_329 ;
F_161 ( V_153 -> V_157 , V_158 ) ;
for ( V_140 = V_151 -> V_165 ; V_140 -> V_11 ; V_140 ++ )
V_153 -> V_166 [ V_140 - V_151 -> V_165 ] = F_283 ( V_140 ) ;
}
int F_284 ( int V_301 )
{
struct V_11 * V_11 ;
( void ) F_207 ( F_234 ( V_301 , V_239 ) ,
F_210 ( V_239 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_301 ;
}
static void F_279 ( void )
{
V_320 = V_287 ;
}
static void F_280 ( T_8 * V_254 )
{
int V_301 , V_323 ;
enum V_198 V_312 ;
struct V_151 * V_151 ;
V_323 = V_254 -> V_326 ;
V_151 = & V_254 -> V_313 [ 0 ] ;
V_312 = F_255 ( V_254 , V_151 , 0 , V_278 - 1 ) ;
for ( V_301 = V_323 + 1 ; V_301 < V_310 ; V_301 ++ ) {
if ( ! F_285 ( V_301 ) )
continue;
V_312 = F_255 ( F_245 ( V_301 ) , V_151 , V_312 ,
V_278 - 1 ) ;
}
for ( V_301 = 0 ; V_301 < V_323 ; V_301 ++ ) {
if ( ! F_285 ( V_301 ) )
continue;
V_312 = F_255 ( F_245 ( V_301 ) , V_151 , V_312 ,
V_278 - 1 ) ;
}
V_151 -> V_165 [ V_312 ] . V_11 = NULL ;
V_151 -> V_165 [ V_312 ] . F_168 = 0 ;
}
static void F_282 ( T_8 * V_254 )
{
V_254 -> V_313 [ 0 ] . V_155 = NULL ;
}
static T_12 int F_286 ( void * V_298 )
{
int V_234 ;
int V_101 ;
#ifdef F_287
memset ( V_311 , 0 , sizeof( V_311 ) ) ;
#endif
F_277 (nid) {
T_8 * V_254 = F_245 ( V_234 ) ;
F_280 ( V_254 ) ;
F_282 ( V_254 ) ;
}
F_288 (cpu) {
F_289 ( & F_290 ( V_330 , V_101 ) , 0 ) ;
#ifdef F_291
if ( F_292 ( V_101 ) )
F_293 ( V_101 , F_284 ( F_294 ( V_101 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_265 ( void * V_298 )
{
F_279 () ;
if ( V_331 == V_332 ) {
F_286 ( NULL ) ;
F_295 () ;
F_296 () ;
} else {
#ifdef F_297
if ( V_298 )
F_298 ( (struct V_11 * ) V_298 ) ;
#endif
F_299 ( F_286 , NULL , NULL ) ;
}
V_333 = F_238 () ;
if ( V_333 < ( V_86 * V_92 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_20 ( L_55
L_56 ,
V_182 ,
V_334 [ V_320 ] ,
V_7 ? L_57 : L_58 ,
V_333 ) ;
#ifdef F_287
F_20 ( L_59 , V_335 [ V_336 ] ) ;
#endif
}
static inline unsigned long F_300 ( unsigned long V_96 )
{
unsigned long V_76 = 1 ;
V_96 /= V_337 ;
while ( V_76 < V_96 )
V_76 <<= 1 ;
V_76 = V_145 ( V_76 , 4096UL ) ;
return F_301 ( V_76 , 4UL ) ;
}
static inline unsigned long F_300 ( unsigned long V_96 )
{
return 4096UL ;
}
static inline unsigned long F_302 ( unsigned long V_76 )
{
return F_303 ( ~ V_76 ) ;
}
static int F_304 ( unsigned long V_84 , unsigned long V_85 )
{
unsigned long V_14 ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 ++ ) {
if ( ! F_13 ( V_14 ) || F_305 ( F_107 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_306 ( struct V_11 * V_11 )
{
unsigned long V_84 , V_14 , V_85 , V_338 ;
struct V_5 * V_5 ;
unsigned long V_339 ;
int V_340 ;
V_84 = V_11 -> V_15 ;
V_85 = V_84 + V_11 -> V_16 ;
V_340 = F_307 ( F_252 ( V_11 ) , V_86 ) >>
V_90 ;
V_340 = V_145 ( 2 , V_340 ) ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 += V_86 ) {
if ( ! F_125 ( V_14 ) )
continue;
V_5 = F_107 ( V_14 ) ;
if ( F_103 ( V_5 ) != F_104 ( V_11 ) )
continue;
V_338 = V_145 ( V_14 + V_86 , V_85 ) ;
if ( F_304 ( V_14 , V_338 ) )
continue;
V_339 = F_86 ( V_5 ) ;
if ( V_340 > 0 && V_339 == V_94 ) {
V_340 -- ;
continue;
}
if ( V_340 > 0 && V_339 == V_110 ) {
F_5 ( V_5 , V_94 ) ;
F_106 ( V_11 , V_5 , V_94 ) ;
V_340 -- ;
continue;
}
if ( V_339 == V_94 ) {
F_5 ( V_5 , V_110 ) ;
F_106 ( V_11 , V_5 , V_110 ) ;
}
}
}
void T_2 F_308 ( unsigned long V_76 , int V_234 , unsigned long V_11 ,
unsigned long V_84 , enum V_341 V_342 )
{
struct V_5 * V_5 ;
unsigned long V_85 = V_84 + V_76 ;
unsigned long V_14 ;
struct V_11 * V_140 ;
if ( V_343 < V_85 - 1 )
V_343 = V_85 - 1 ;
V_140 = & F_245 ( V_234 ) -> V_256 [ V_11 ] ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 ++ ) {
if ( V_342 == V_344 ) {
if ( ! F_309 ( V_14 ) )
continue;
if ( ! F_310 ( V_14 , V_234 ) )
continue;
}
V_5 = F_107 ( V_14 ) ;
F_311 ( V_5 , V_11 , V_234 , V_14 ) ;
F_312 ( V_5 , V_11 , V_234 , V_14 ) ;
F_313 ( V_5 ) ;
F_18 ( V_5 ) ;
F_314 ( V_5 ) ;
if ( ( V_140 -> V_15 <= V_14 )
&& ( V_14 < V_140 -> V_15 + V_140 -> V_16 )
&& ! ( V_14 & ( V_86 - 1 ) ) )
F_5 ( V_5 , V_110 ) ;
F_315 ( & V_5 -> V_41 ) ;
#ifdef F_316
if ( ! F_317 ( V_11 ) )
F_318 ( V_5 , F_319 ( V_14 << V_345 ) ) ;
#endif
}
}
static void T_2 F_320 ( struct V_11 * V_11 )
{
int V_27 , V_107 ;
F_128 (order, t) {
F_315 ( & V_11 -> V_42 [ V_27 ] . V_46 [ V_107 ] ) ;
V_11 -> V_42 [ V_27 ] . V_43 = 0 ;
}
}
static int F_321 ( struct V_11 * V_11 )
{
#ifdef F_322
int V_100 ;
V_100 = V_11 -> V_240 / 1024 ;
if ( V_100 * V_68 > 512 * 1024 )
V_100 = ( 512 * 1024 ) / V_68 ;
V_100 /= 4 ;
if ( V_100 < 1 )
V_100 = 1 ;
V_100 = F_323 ( V_100 + V_100 / 2 ) - 1 ;
return V_100 ;
#else
return 0 ;
#endif
}
static void F_289 ( struct V_102 * V_30 , unsigned long V_100 )
{
struct V_55 * V_56 ;
int V_6 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_56 = & V_30 -> V_56 ;
V_56 -> V_54 = 0 ;
V_56 -> V_74 = 6 * V_100 ;
V_56 -> V_100 = F_301 ( 1UL , 1 * V_100 ) ;
for ( V_6 = 0 ; V_6 < V_64 ; V_6 ++ )
F_315 ( & V_56 -> V_65 [ V_6 ] ) ;
}
static void F_324 ( struct V_102 * V_30 ,
unsigned long V_74 )
{
struct V_55 * V_56 ;
V_56 = & V_30 -> V_56 ;
V_56 -> V_74 = V_74 ;
V_56 -> V_100 = F_301 ( 1UL , V_74 / 4 ) ;
if ( ( V_74 / 4 ) > ( V_345 * 8 ) )
V_56 -> V_100 = V_345 * 8 ;
}
static void F_298 ( struct V_11 * V_11 )
{
int V_101 ;
V_11 -> V_104 = F_325 ( struct V_102 ) ;
F_288 (cpu) {
struct V_102 * V_56 = F_118 ( V_11 -> V_104 , V_101 ) ;
F_289 ( V_56 , F_321 ( V_11 ) ) ;
if ( V_346 )
F_324 ( V_56 ,
( V_11 -> V_240 /
V_346 ) ) ;
}
}
void T_3 F_326 ( void )
{
struct V_11 * V_11 ;
F_117 (zone)
F_298 ( V_11 ) ;
}
static T_14 T_12
int F_327 ( struct V_11 * V_11 , unsigned long V_347 )
{
int V_28 ;
struct V_348 * V_254 = V_11 -> V_349 ;
T_7 V_350 ;
V_11 -> F_300 =
F_300 ( V_347 ) ;
V_11 -> F_302 =
F_302 ( V_11 -> F_300 ) ;
V_350 = V_11 -> F_300
* sizeof( V_351 ) ;
if ( ! F_328 () ) {
V_11 -> V_352 = ( V_351 * )
F_329 ( V_254 , V_350 ) ;
} else {
V_11 -> V_352 = F_330 ( V_350 ) ;
}
if ( ! V_11 -> V_352 )
return - V_139 ;
for( V_28 = 0 ; V_28 < V_11 -> F_300 ; ++ V_28 )
F_331 ( V_11 -> V_352 + V_28 ) ;
return 0 ;
}
static int F_332 ( void * V_298 )
{
struct V_11 * V_11 = V_298 ;
int V_101 ;
unsigned long V_100 = F_321 ( V_11 ) , V_51 ;
F_288 (cpu) {
struct V_102 * V_103 ;
struct V_55 * V_56 ;
V_103 = F_118 ( V_11 -> V_104 , V_101 ) ;
V_56 = & V_103 -> V_56 ;
F_84 ( V_51 ) ;
F_64 ( V_11 , V_56 -> V_54 , V_56 ) ;
F_289 ( V_103 , V_100 ) ;
F_87 ( V_51 ) ;
}
return 0 ;
}
void F_333 ( struct V_11 * V_11 )
{
F_299 ( F_332 , V_11 , NULL ) ;
}
static T_2 void F_334 ( struct V_11 * V_11 )
{
V_11 -> V_104 = & V_330 ;
if ( V_11 -> V_240 )
F_20 ( V_353 L_60 ,
V_11 -> V_258 , V_11 -> V_240 ,
F_321 ( V_11 ) ) ;
}
T_2 int F_335 ( struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_76 ,
enum V_341 V_342 )
{
struct V_348 * V_254 = V_11 -> V_349 ;
int V_12 ;
V_12 = F_327 ( V_11 , V_76 ) ;
if ( V_12 )
return V_12 ;
V_254 -> V_282 = F_168 ( V_11 ) + 1 ;
V_11 -> V_15 = V_15 ;
F_336 ( V_354 , L_61 ,
L_62 ,
V_254 -> V_326 ,
( unsigned long ) F_168 ( V_11 ) ,
V_15 , ( V_15 + V_76 ) ) ;
F_320 ( V_11 ) ;
return 0 ;
}
static int T_2 F_337 ( int V_234 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_355 ; V_28 ++ )
if ( V_234 == V_310 || V_356 [ V_28 ] . V_234 == V_234 )
return V_28 ;
return - 1 ;
}
static int T_2 F_338 ( int V_357 , int V_234 )
{
for ( V_357 = V_357 + 1 ; V_357 < V_355 ; V_357 ++ )
if ( V_234 == V_310 || V_356 [ V_357 ] . V_234 == V_234 )
return V_357 ;
return - 1 ;
}
int T_2 F_339 ( unsigned long V_14 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_355 ; V_28 ++ ) {
unsigned long V_84 = V_356 [ V_28 ] . V_84 ;
unsigned long V_85 = V_356 [ V_28 ] . V_85 ;
if ( V_84 <= V_14 && V_14 < V_85 )
return V_356 [ V_28 ] . V_234 ;
}
return - 1 ;
}
int T_2 F_340 ( unsigned long V_14 )
{
int V_234 ;
V_234 = F_339 ( V_14 ) ;
if ( V_234 >= 0 )
return V_234 ;
return 0 ;
}
bool T_2 F_310 ( unsigned long V_14 , int V_301 )
{
int V_234 ;
V_234 = F_339 ( V_14 ) ;
if ( V_234 >= 0 && V_234 != V_301 )
return false ;
return true ;
}
void T_3 F_341 ( int V_234 ,
unsigned long V_358 )
{
int V_28 ;
F_342 (i, nid) {
unsigned long V_359 = 0 ;
unsigned long V_85 = V_356 [ V_28 ] . V_85 ;
if ( V_356 [ V_28 ] . V_84 >= V_358 )
continue;
if ( V_85 > V_358 )
V_85 = V_358 ;
V_359 = V_85 - V_356 [ V_28 ] . V_84 ;
F_343 ( F_245 ( V_356 [ V_28 ] . V_234 ) ,
F_344 ( V_356 [ V_28 ] . V_84 ) ,
V_359 << V_345 ) ;
}
}
static int T_2 F_345 ( int V_234 )
{
int V_28 ;
for ( V_28 = V_355 - 1 ; V_28 >= 0 ; V_28 -- )
if ( V_234 == V_310 || V_356 [ V_28 ] . V_234 == V_234 )
return V_28 ;
return - 1 ;
}
static int T_2 F_346 ( int V_357 , int V_234 )
{
for ( V_357 = V_357 - 1 ; V_357 >= 0 ; V_357 -- )
if ( V_234 == V_310 || V_356 [ V_357 ] . V_234 == V_234 )
return V_357 ;
return - 1 ;
}
T_15 T_3 F_347 ( int V_234 , T_15 V_76 , T_15 V_360 ,
T_15 V_361 , T_15 V_362 )
{
int V_28 ;
F_348 (i, nid) {
T_15 V_231 ;
T_15 V_363 , V_364 ;
T_15 V_365 , V_366 ;
V_364 = V_356 [ V_28 ] . V_85 ;
V_364 <<= V_345 ;
V_363 = V_356 [ V_28 ] . V_84 ;
V_363 <<= V_345 ;
V_365 = F_301 ( V_363 , V_361 ) ;
V_366 = V_145 ( V_364 , V_362 ) ;
if ( V_365 >= V_366 )
continue;
V_231 = F_349 ( V_365 , V_366 , V_76 , V_360 ) ;
if ( V_231 == V_367 )
continue;
return V_231 ;
}
return V_367 ;
}
int T_3 F_350 ( struct V_368 * V_368 , int V_369 ,
int V_370 , int V_234 )
{
int V_28 ;
T_15 V_371 , V_236 ;
F_342 (i, nid) {
V_371 = V_356 [ V_28 ] . V_84 ;
V_236 = V_356 [ V_28 ] . V_85 ;
V_370 = F_351 ( V_368 , V_369 , V_370 , V_371 , V_236 ) ;
}
return V_370 ;
}
void T_3 F_352 ( int V_234 , T_16 V_372 , void * V_298 )
{
int V_28 ;
int V_12 ;
F_342 (i, nid) {
V_12 = V_372 ( V_356 [ V_28 ] . V_84 ,
V_356 [ V_28 ] . V_85 , V_298 ) ;
if ( V_12 )
break;
}
}
void T_3 F_353 ( int V_234 )
{
int V_28 ;
F_342 (i, nid)
F_354 ( V_356 [ V_28 ] . V_234 ,
V_356 [ V_28 ] . V_84 ,
V_356 [ V_28 ] . V_85 ) ;
}
void T_2 F_355 ( unsigned int V_234 ,
unsigned long * V_84 , unsigned long * V_85 )
{
int V_28 ;
* V_84 = - 1UL ;
* V_85 = 0 ;
F_342 (i, nid) {
* V_84 = V_145 ( * V_84 , V_356 [ V_28 ] . V_84 ) ;
* V_85 = F_301 ( * V_85 , V_356 [ V_28 ] . V_85 ) ;
}
if ( * V_84 == - 1UL )
* V_84 = 0 ;
}
static void T_3 F_356 ( void )
{
int V_373 ;
for ( V_373 = V_278 - 1 ; V_373 >= 0 ; V_373 -- ) {
if ( V_373 == V_374 )
continue;
if ( V_375 [ V_373 ] >
V_376 [ V_373 ] )
break;
}
F_38 ( V_373 == - 1 ) ;
V_377 = V_373 ;
}
static void T_2 F_357 ( int V_234 ,
unsigned long V_198 ,
unsigned long V_378 ,
unsigned long V_379 ,
unsigned long * V_15 ,
unsigned long * V_380 )
{
if ( V_381 [ V_234 ] ) {
if ( V_198 == V_374 ) {
* V_15 = V_381 [ V_234 ] ;
* V_380 = V_145 ( V_379 ,
V_375 [ V_377 ] ) ;
} else if ( * V_15 < V_381 [ V_234 ] &&
* V_380 > V_381 [ V_234 ] ) {
* V_380 = V_381 [ V_234 ] ;
} else if ( * V_15 >= V_381 [ V_234 ] )
* V_15 = * V_380 ;
}
}
static unsigned long T_2 F_358 ( int V_234 ,
unsigned long V_198 ,
unsigned long * V_382 )
{
unsigned long V_378 , V_379 ;
unsigned long V_15 , V_380 ;
F_355 ( V_234 , & V_378 , & V_379 ) ;
V_15 = V_376 [ V_198 ] ;
V_380 = V_375 [ V_198 ] ;
F_357 ( V_234 , V_198 ,
V_378 , V_379 ,
& V_15 , & V_380 ) ;
if ( V_380 < V_378 || V_15 > V_379 )
return 0 ;
V_380 = V_145 ( V_380 , V_379 ) ;
V_15 = F_301 ( V_15 , V_378 ) ;
return V_380 - V_15 ;
}
unsigned long T_2 F_359 ( int V_234 ,
unsigned long V_383 ,
unsigned long V_384 )
{
int V_28 = 0 ;
unsigned long V_385 = 0 , V_386 = 0 ;
unsigned long V_84 ;
V_28 = F_337 ( V_234 ) ;
if ( V_28 == - 1 )
return 0 ;
V_385 = V_145 ( V_356 [ V_28 ] . V_84 , V_384 ) ;
if ( V_356 [ V_28 ] . V_84 > V_383 )
V_386 = V_385 - V_383 ;
for (; V_28 != - 1 ; V_28 = F_338 ( V_28 , V_234 ) ) {
if ( V_385 >= V_384 )
break;
V_84 = V_145 ( V_356 [ V_28 ] . V_84 , V_384 ) ;
V_385 = F_301 ( V_385 , V_383 ) ;
if ( V_84 > V_383 ) {
F_102 ( V_385 > V_84 ) ;
V_386 += V_84 - V_385 ;
}
V_385 = V_356 [ V_28 ] . V_85 ;
}
if ( V_384 > V_385 )
V_386 += V_384 -
F_301 ( V_383 , V_385 ) ;
return V_386 ;
}
unsigned long T_3 F_360 ( unsigned long V_84 ,
unsigned long V_85 )
{
return F_359 ( V_310 , V_84 , V_85 ) ;
}
static unsigned long T_2 F_361 ( int V_234 ,
unsigned long V_198 ,
unsigned long * V_382 )
{
unsigned long V_378 , V_379 ;
unsigned long V_15 , V_380 ;
F_355 ( V_234 , & V_378 , & V_379 ) ;
V_15 = F_301 ( V_376 [ V_198 ] ,
V_378 ) ;
V_380 = V_145 ( V_375 [ V_198 ] ,
V_379 ) ;
F_357 ( V_234 , V_198 ,
V_378 , V_379 ,
& V_15 , & V_380 ) ;
return F_359 ( V_234 , V_15 , V_380 ) ;
}
static inline unsigned long T_2 F_358 ( int V_234 ,
unsigned long V_198 ,
unsigned long * V_387 )
{
return V_387 [ V_198 ] ;
}
static inline unsigned long T_2 F_361 ( int V_234 ,
unsigned long V_198 ,
unsigned long * V_388 )
{
if ( ! V_388 )
return 0 ;
return V_388 [ V_198 ] ;
}
static void T_2 F_362 ( struct V_348 * V_254 ,
unsigned long * V_387 , unsigned long * V_388 )
{
unsigned long V_389 , V_390 = 0 ;
enum V_198 V_28 ;
for ( V_28 = 0 ; V_28 < V_278 ; V_28 ++ )
V_390 += F_358 ( V_254 -> V_326 , V_28 ,
V_387 ) ;
V_254 -> V_391 = V_390 ;
V_389 = V_390 ;
for ( V_28 = 0 ; V_28 < V_278 ; V_28 ++ )
V_389 -=
F_361 ( V_254 -> V_326 , V_28 ,
V_388 ) ;
V_254 -> V_255 = V_389 ;
F_20 ( V_353 L_63 , V_254 -> V_326 ,
V_389 ) ;
}
static unsigned long T_3 F_363 ( unsigned long V_392 )
{
unsigned long V_393 ;
V_393 = F_307 ( V_392 , V_86 ) ;
V_393 = V_393 >> V_90 ;
V_393 *= V_394 ;
V_393 = F_307 ( V_393 , 8 * sizeof( unsigned long ) ) ;
return V_393 / 8 ;
}
static void T_3 F_364 ( struct V_348 * V_254 ,
struct V_11 * V_11 , unsigned long V_392 )
{
unsigned long V_393 = F_363 ( V_392 ) ;
V_11 -> V_395 = NULL ;
if ( V_393 )
V_11 -> V_395 = F_329 ( V_254 ,
V_393 ) ;
}
static inline void F_364 ( struct V_348 * V_254 ,
struct V_11 * V_11 , unsigned long V_392 ) {}
static inline int F_365 ( void )
{
if ( V_396 > V_345 )
return V_397 ;
return V_40 - 1 ;
}
static inline void T_3 F_366 ( unsigned int V_27 )
{
if ( V_90 )
return;
V_90 = V_27 ;
}
static inline int F_365 ( unsigned int V_27 )
{
return V_40 - 1 ;
}
static void T_17 F_367 ( struct V_348 * V_254 ,
unsigned long * V_387 , unsigned long * V_388 )
{
enum V_198 V_312 ;
int V_234 = V_254 -> V_326 ;
unsigned long V_15 = V_254 -> V_378 ;
int V_12 ;
F_368 ( V_254 ) ;
V_254 -> V_282 = 0 ;
F_331 ( & V_254 -> V_398 ) ;
V_254 -> V_399 = 0 ;
F_369 ( V_254 ) ;
for ( V_312 = 0 ; V_312 < V_278 ; V_312 ++ ) {
struct V_11 * V_11 = V_254 -> V_256 + V_312 ;
unsigned long V_76 , V_400 , V_401 ;
enum V_402 V_403 ;
V_76 = F_358 ( V_234 , V_312 , V_387 ) ;
V_400 = V_76 - F_361 ( V_234 , V_312 ,
V_388 ) ;
V_401 =
F_226 ( V_76 * sizeof( struct V_5 ) ) >> V_345 ;
if ( V_400 >= V_401 ) {
V_400 -= V_401 ;
if ( V_401 )
F_20 ( V_353
L_64 ,
V_335 [ V_312 ] , V_401 ) ;
} else
F_20 ( V_193
L_65 ,
V_335 [ V_312 ] , V_401 , V_400 ) ;
if ( V_312 == 0 && V_400 > V_404 ) {
V_400 -= V_404 ;
F_20 ( V_353 L_66 ,
V_335 [ 0 ] , V_404 ) ;
}
if ( ! F_317 ( V_312 ) )
V_405 += V_400 ;
V_406 += V_400 ;
V_11 -> V_16 = V_76 ;
V_11 -> V_240 = V_400 ;
#ifdef F_287
V_11 -> V_301 = V_234 ;
V_11 -> V_407 = ( V_400 * V_408 )
/ 100 ;
V_11 -> V_409 = ( V_400 * V_410 ) / 100 ;
#endif
V_11 -> V_258 = V_335 [ V_312 ] ;
F_370 ( & V_11 -> V_59 ) ;
F_370 ( & V_11 -> V_411 ) ;
F_371 ( V_11 ) ;
V_11 -> V_349 = V_254 ;
F_334 ( V_11 ) ;
F_372 (l)
F_315 ( & V_11 -> V_41 [ V_403 ] . V_63 ) ;
V_11 -> V_412 . V_413 [ 0 ] = 0 ;
V_11 -> V_412 . V_413 [ 1 ] = 0 ;
V_11 -> V_412 . V_414 [ 0 ] = 0 ;
V_11 -> V_412 . V_414 [ 1 ] = 0 ;
F_373 ( V_11 ) ;
V_11 -> V_51 = 0 ;
if ( ! V_76 )
continue;
F_366 ( F_365 () ) ;
F_364 ( V_254 , V_11 , V_76 ) ;
V_12 = F_335 ( V_11 , V_15 ,
V_76 , V_344 ) ;
F_102 ( V_12 ) ;
F_374 ( V_76 , V_234 , V_312 , V_15 ) ;
V_15 += V_76 ;
}
}
static void T_12 F_375 ( struct V_348 * V_254 )
{
if ( ! V_254 -> V_391 )
return;
#ifdef F_376
if ( ! V_254 -> V_415 ) {
unsigned long V_76 , V_371 , V_236 ;
struct V_5 * V_416 ;
V_371 = V_254 -> V_378 & ~ ( V_417 - 1 ) ;
V_236 = V_254 -> V_378 + V_254 -> V_391 ;
V_236 = F_377 ( V_236 , V_417 ) ;
V_76 = ( V_236 - V_371 ) * sizeof( struct V_5 ) ;
V_416 = F_378 ( V_254 -> V_326 , V_76 ) ;
if ( ! V_416 )
V_416 = F_329 ( V_254 , V_76 ) ;
V_254 -> V_415 = V_416 + ( V_254 -> V_378 - V_371 ) ;
}
#ifndef F_379
if ( V_254 == F_245 ( 0 ) ) {
V_418 = F_245 ( 0 ) -> V_415 ;
#ifdef F_380
if ( F_9 ( V_418 ) != V_254 -> V_378 )
V_418 -= ( V_254 -> V_378 - V_419 ) ;
#endif
}
#endif
#endif
}
void T_17 F_381 ( int V_234 , unsigned long * V_387 ,
unsigned long V_378 , unsigned long * V_388 )
{
T_8 * V_254 = F_245 ( V_234 ) ;
V_254 -> V_326 = V_234 ;
V_254 -> V_378 = V_378 ;
F_362 ( V_254 , V_387 , V_388 ) ;
F_375 ( V_254 ) ;
#ifdef F_376
F_20 ( V_353 L_67 ,
V_234 , ( unsigned long ) V_254 ,
( unsigned long ) V_254 -> V_415 ) ;
#endif
F_367 ( V_254 , V_387 , V_388 ) ;
}
static void T_3 F_382 ( void )
{
unsigned int V_301 ;
unsigned int V_420 = 0 ;
F_383 (node, node_possible_map)
V_420 = V_301 ;
V_421 = V_420 + 1 ;
}
static inline void F_382 ( void )
{
}
void T_3 F_384 ( unsigned int V_234 , unsigned long V_84 ,
unsigned long V_85 )
{
int V_28 ;
F_336 ( V_354 , L_68 ,
L_69
L_70 ,
V_234 , V_84 , V_85 ,
V_355 , V_422 ) ;
F_385 ( & V_84 , & V_85 ) ;
for ( V_28 = 0 ; V_28 < V_355 ; V_28 ++ ) {
if ( V_356 [ V_28 ] . V_234 != V_234 )
continue;
if ( V_84 >= V_356 [ V_28 ] . V_84 &&
V_85 <= V_356 [ V_28 ] . V_85 )
return;
if ( V_84 <= V_356 [ V_28 ] . V_85 &&
V_85 > V_356 [ V_28 ] . V_85 ) {
V_356 [ V_28 ] . V_85 = V_85 ;
return;
}
if ( V_84 < V_356 [ V_28 ] . V_84 &&
V_85 >= V_356 [ V_28 ] . V_84 ) {
V_356 [ V_28 ] . V_84 = V_84 ;
return;
}
}
if ( V_28 >= V_422 ) {
F_20 ( V_423 L_71 ,
V_422 ) ;
return;
}
V_356 [ V_28 ] . V_234 = V_234 ;
V_356 [ V_28 ] . V_84 = V_84 ;
V_356 [ V_28 ] . V_85 = V_85 ;
V_355 = V_28 + 1 ;
}
void T_3 F_386 ( unsigned int V_234 , unsigned long V_84 ,
unsigned long V_85 )
{
int V_28 , V_312 ;
int V_424 = 0 ;
F_20 ( V_353 L_72 ,
V_234 , V_84 , V_85 ) ;
F_342 (i, nid) {
if ( V_356 [ V_28 ] . V_84 >= V_84 &&
V_356 [ V_28 ] . V_85 <= V_85 ) {
V_356 [ V_28 ] . V_84 = 0 ;
V_356 [ V_28 ] . V_85 = 0 ;
V_424 = 1 ;
continue;
}
if ( V_356 [ V_28 ] . V_84 < V_84 &&
V_356 [ V_28 ] . V_85 > V_84 ) {
unsigned long V_425 = V_356 [ V_28 ] . V_85 ;
V_356 [ V_28 ] . V_85 = V_84 ;
if ( V_425 > V_85 )
F_384 ( V_234 , V_85 , V_425 ) ;
continue;
}
if ( V_356 [ V_28 ] . V_84 >= V_84 &&
V_356 [ V_28 ] . V_85 > V_85 &&
V_356 [ V_28 ] . V_84 < V_85 ) {
V_356 [ V_28 ] . V_84 = V_85 ;
continue;
}
}
if ( ! V_424 )
return;
for ( V_28 = V_355 - 1 ; V_28 > 0 ; V_28 -- ) {
if ( V_356 [ V_28 ] . V_234 != V_234 )
continue;
if ( V_356 [ V_28 ] . V_85 )
continue;
for ( V_312 = V_28 ; V_312 < V_355 - 1 ; V_312 ++ )
memcpy ( & V_356 [ V_312 ] , & V_356 [ V_312 + 1 ] ,
sizeof( V_356 [ V_312 ] ) ) ;
V_312 = V_355 - 1 ;
memset ( & V_356 [ V_312 ] , 0 , sizeof( V_356 [ V_312 ] ) ) ;
V_355 -- ;
}
}
void T_3 F_387 ( void )
{
memset ( V_356 , 0 , sizeof( V_356 ) ) ;
V_355 = 0 ;
}
static int T_3 F_388 ( const void * V_426 , const void * V_427 )
{
struct V_428 * V_429 = (struct V_428 * ) V_426 ;
struct V_428 * V_430 = (struct V_428 * ) V_427 ;
if ( V_429 -> V_84 > V_430 -> V_84 )
return 1 ;
if ( V_429 -> V_84 < V_430 -> V_84 )
return - 1 ;
return 0 ;
}
void T_3 F_389 ( void )
{
F_390 ( V_356 , ( T_7 ) V_355 ,
sizeof( struct V_428 ) ,
F_388 , NULL ) ;
}
static unsigned long T_3 F_391 ( int V_234 )
{
int V_28 ;
unsigned long V_431 = V_432 ;
F_342 (i, nid)
V_431 = V_145 ( V_431 , V_356 [ V_28 ] . V_84 ) ;
if ( V_431 == V_432 ) {
F_20 ( V_193
L_73 , V_234 ) ;
return 0 ;
}
return V_431 ;
}
unsigned long T_3 F_392 ( void )
{
return F_391 ( V_310 ) ;
}
static unsigned long T_3 F_393 ( void )
{
int V_28 ;
unsigned long V_390 = 0 ;
for ( V_28 = 0 ; V_28 < V_355 ; V_28 ++ ) {
unsigned long V_96 = V_356 [ V_28 ] . V_85 -
V_356 [ V_28 ] . V_84 ;
V_390 += V_96 ;
if ( V_96 )
F_394 ( V_356 [ V_28 ] . V_234 , V_162 ) ;
}
return V_390 ;
}
static void T_3 F_395 ( unsigned long * V_433 )
{
int V_28 , V_234 ;
unsigned long V_434 ;
unsigned long V_435 , V_436 ;
T_5 V_437 = V_161 [ V_162 ] ;
unsigned long V_390 = F_393 () ;
int V_438 = F_278 ( V_161 [ V_162 ] ) ;
if ( V_439 ) {
unsigned long V_440 ;
V_439 =
F_307 ( V_439 , V_417 ) ;
V_440 = V_390 - V_439 ;
V_441 = F_301 ( V_441 , V_440 ) ;
}
if ( ! V_441 )
goto V_21;
F_356 () ;
V_434 = V_376 [ V_377 ] ;
V_221:
V_435 = V_441 / V_438 ;
F_270 (nid, N_HIGH_MEMORY) {
if ( V_441 < V_435 )
V_435 = V_441 / V_438 ;
V_436 = V_435 ;
F_342 (i, nid) {
unsigned long V_84 , V_85 ;
unsigned long V_359 ;
V_84 = F_301 ( V_356 [ V_28 ] . V_84 ,
V_381 [ V_234 ] ) ;
V_85 = V_356 [ V_28 ] . V_85 ;
if ( V_84 >= V_85 )
continue;
if ( V_84 < V_434 ) {
unsigned long V_442 ;
V_442 = V_145 ( V_85 , V_434 )
- V_84 ;
V_436 -= V_145 ( V_442 ,
V_436 ) ;
V_441 -= V_145 ( V_442 ,
V_441 ) ;
if ( V_85 <= V_434 ) {
V_381 [ V_234 ] = V_85 ;
continue;
}
V_84 = V_434 ;
}
V_359 = V_85 - V_84 ;
if ( V_359 > V_436 )
V_359 = V_436 ;
V_381 [ V_234 ] = V_84 + V_359 ;
V_441 -= V_145 ( V_441 ,
V_359 ) ;
V_436 -= V_359 ;
if ( ! V_436 )
break;
}
}
V_438 -- ;
if ( V_438 && V_441 > V_438 )
goto V_221;
for ( V_234 = 0 ; V_234 < V_310 ; V_234 ++ )
V_381 [ V_234 ] =
F_307 ( V_381 [ V_234 ] , V_417 ) ;
V_21:
V_161 [ V_162 ] = V_437 ;
}
static void F_396 ( T_8 * V_254 )
{
#ifdef F_247
enum V_198 V_198 ;
for ( V_198 = 0 ; V_198 <= V_201 ; V_198 ++ ) {
struct V_11 * V_11 = & V_254 -> V_256 [ V_198 ] ;
if ( V_11 -> V_240 )
F_394 ( F_104 ( V_11 ) , V_443 ) ;
}
#endif
}
void T_3 F_397 ( unsigned long * V_106 )
{
unsigned long V_234 ;
int V_28 ;
F_389 () ;
memset ( V_376 , 0 ,
sizeof( V_376 ) ) ;
memset ( V_375 , 0 ,
sizeof( V_375 ) ) ;
V_376 [ 0 ] = F_392 () ;
V_375 [ 0 ] = V_106 [ 0 ] ;
for ( V_28 = 1 ; V_28 < V_278 ; V_28 ++ ) {
if ( V_28 == V_374 )
continue;
V_376 [ V_28 ] =
V_375 [ V_28 - 1 ] ;
V_375 [ V_28 ] =
F_301 ( V_106 [ V_28 ] , V_376 [ V_28 ] ) ;
}
V_376 [ V_374 ] = 0 ;
V_375 [ V_374 ] = 0 ;
memset ( V_381 , 0 , sizeof( V_381 ) ) ;
F_395 ( V_381 ) ;
F_20 ( L_74 ) ;
for ( V_28 = 0 ; V_28 < V_278 ; V_28 ++ ) {
if ( V_28 == V_374 )
continue;
F_20 ( L_75 , V_335 [ V_28 ] ) ;
if ( V_376 [ V_28 ] ==
V_375 [ V_28 ] )
F_20 ( L_76 ) ;
else
F_20 ( L_77 ,
V_376 [ V_28 ] ,
V_375 [ V_28 ] ) ;
}
F_20 ( L_78 ) ;
for ( V_28 = 0 ; V_28 < V_310 ; V_28 ++ ) {
if ( V_381 [ V_28 ] )
F_20 ( L_79 , V_28 , V_381 [ V_28 ] ) ;
}
F_20 ( L_80 , V_355 ) ;
for ( V_28 = 0 ; V_28 < V_355 ; V_28 ++ )
F_20 ( L_81 , V_356 [ V_28 ] . V_234 ,
V_356 [ V_28 ] . V_84 ,
V_356 [ V_28 ] . V_85 ) ;
F_398 () ;
F_382 () ;
F_277 (nid) {
T_8 * V_254 = F_245 ( V_234 ) ;
F_381 ( V_234 , NULL ,
F_391 ( V_234 ) , NULL ) ;
if ( V_254 -> V_255 )
F_394 ( V_234 , V_162 ) ;
F_396 ( V_254 ) ;
}
}
static int T_3 F_399 ( char * V_30 , unsigned long * V_444 )
{
unsigned long long V_445 ;
if ( ! V_30 )
return - V_288 ;
V_445 = F_400 ( V_30 , & V_30 ) ;
* V_444 = V_445 >> V_345 ;
F_2 ( ( V_445 >> V_345 ) > V_432 ) ;
return 0 ;
}
static int T_3 F_401 ( char * V_30 )
{
return F_399 ( V_30 , & V_441 ) ;
}
static int T_3 F_402 ( char * V_30 )
{
return F_399 ( V_30 , & V_439 ) ;
}
void T_3 F_403 ( unsigned long V_446 )
{
V_404 = V_446 ;
}
void T_3 F_404 ( unsigned long * V_387 )
{
F_381 ( 0 , V_387 ,
F_405 ( V_447 ) >> V_345 , NULL ) ;
}
static int F_406 ( struct V_448 * V_449 ,
unsigned long V_450 , void * V_451 )
{
int V_101 = ( unsigned long ) V_451 ;
if ( V_450 == V_452 || V_450 == V_453 ) {
F_116 ( V_101 ) ;
F_407 ( V_101 ) ;
F_408 ( V_101 ) ;
}
return V_454 ;
}
void T_3 F_409 ( void )
{
F_410 ( F_406 , 0 ) ;
}
static void F_411 ( void )
{
struct V_348 * V_254 ;
unsigned long V_455 = 0 ;
enum V_198 V_28 , V_312 ;
F_412 (pgdat) {
for ( V_28 = 0 ; V_28 < V_278 ; V_28 ++ ) {
struct V_11 * V_11 = V_254 -> V_256 + V_28 ;
unsigned long F_301 = 0 ;
for ( V_312 = V_28 ; V_312 < V_278 ; V_312 ++ ) {
if ( V_11 -> V_149 [ V_312 ] > F_301 )
F_301 = V_11 -> V_149 [ V_312 ] ;
}
F_301 += F_236 ( V_11 ) ;
if ( F_301 > V_11 -> V_240 )
F_301 = V_11 -> V_240 ;
V_455 += F_301 ;
}
}
V_456 = V_455 ;
}
static void F_413 ( void )
{
struct V_348 * V_254 ;
enum V_198 V_312 , V_457 ;
F_412 (pgdat) {
for ( V_312 = 0 ; V_312 < V_278 ; V_312 ++ ) {
struct V_11 * V_11 = V_254 -> V_256 + V_312 ;
unsigned long V_240 = V_11 -> V_240 ;
V_11 -> V_149 [ V_312 ] = 0 ;
V_457 = V_312 ;
while ( V_457 ) {
struct V_11 * V_458 ;
V_457 -- ;
if ( V_459 [ V_457 ] < 1 )
V_459 [ V_457 ] = 1 ;
V_458 = V_254 -> V_256 + V_457 ;
V_458 -> V_149 [ V_312 ] = V_240 /
V_459 [ V_457 ] ;
V_240 += V_458 -> V_240 ;
}
}
}
F_411 () ;
}
void F_414 ( void )
{
unsigned long V_460 = V_461 >> ( V_345 - 10 ) ;
unsigned long V_462 = 0 ;
struct V_11 * V_11 ;
unsigned long V_51 ;
F_415 (zone) {
if ( ! F_416 ( V_11 ) )
V_462 += V_11 -> V_240 ;
}
F_415 (zone) {
T_15 V_307 ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
V_307 = ( T_15 ) V_460 * V_11 -> V_240 ;
F_417 ( V_307 , V_462 ) ;
if ( F_416 ( V_11 ) ) {
int V_463 ;
V_463 = V_11 -> V_240 / 1024 ;
if ( V_463 < V_464 )
V_463 = V_464 ;
if ( V_463 > 128 )
V_463 = 128 ;
V_11 -> V_112 [ V_465 ] = V_463 ;
} else {
V_11 -> V_112 [ V_465 ] = V_307 ;
}
V_11 -> V_112 [ V_466 ] = F_252 ( V_11 ) + ( V_307 >> 2 ) ;
V_11 -> V_112 [ V_467 ] = F_252 ( V_11 ) + ( V_307 >> 1 ) ;
F_306 ( V_11 ) ;
F_131 ( & V_11 -> V_59 , V_51 ) ;
}
F_411 () ;
}
static void T_2 F_418 ( struct V_11 * V_11 )
{
unsigned int V_468 , V_469 ;
V_468 = V_11 -> V_240 >> ( 30 - V_345 ) ;
if ( V_468 )
V_469 = F_419 ( 10 * V_468 ) ;
else
V_469 = 1 ;
V_11 -> V_470 = V_469 ;
}
static void T_2 F_420 ( void )
{
struct V_11 * V_11 ;
F_415 (zone)
F_418 ( V_11 ) ;
}
int T_2 F_421 ( void )
{
unsigned long V_471 ;
V_471 = F_237 () * ( V_68 >> 10 ) ;
V_461 = F_419 ( V_471 * 16 ) ;
if ( V_461 < 128 )
V_461 = 128 ;
if ( V_461 > 65536 )
V_461 = 65536 ;
F_414 () ;
F_422 () ;
F_413 () ;
F_420 () ;
return 0 ;
}
int F_423 ( T_9 * V_291 , int V_292 ,
void T_10 * V_293 , T_7 * V_294 , T_11 * V_295 )
{
F_424 ( V_291 , V_292 , V_293 , V_294 , V_295 ) ;
if ( V_292 )
F_414 () ;
return 0 ;
}
int F_425 ( T_9 * V_291 , int V_292 ,
void T_10 * V_293 , T_7 * V_294 , T_11 * V_295 )
{
struct V_11 * V_11 ;
int V_472 ;
V_472 = F_426 ( V_291 , V_292 , V_293 , V_294 , V_295 ) ;
if ( V_472 )
return V_472 ;
F_415 (zone)
V_11 -> V_407 = ( V_11 -> V_240 *
V_408 ) / 100 ;
return 0 ;
}
int F_427 ( T_9 * V_291 , int V_292 ,
void T_10 * V_293 , T_7 * V_294 , T_11 * V_295 )
{
struct V_11 * V_11 ;
int V_472 ;
V_472 = F_426 ( V_291 , V_292 , V_293 , V_294 , V_295 ) ;
if ( V_472 )
return V_472 ;
F_415 (zone)
V_11 -> V_409 = ( V_11 -> V_240 *
V_410 ) / 100 ;
return 0 ;
}
int F_428 ( T_9 * V_291 , int V_292 ,
void T_10 * V_293 , T_7 * V_294 , T_11 * V_295 )
{
F_426 ( V_291 , V_292 , V_293 , V_294 , V_295 ) ;
F_413 () ;
return 0 ;
}
int F_429 ( T_9 * V_291 , int V_292 ,
void T_10 * V_293 , T_7 * V_294 , T_11 * V_295 )
{
struct V_11 * V_11 ;
unsigned int V_101 ;
int V_12 ;
V_12 = F_426 ( V_291 , V_292 , V_293 , V_294 , V_295 ) ;
if ( ! V_292 || ( V_12 == - V_288 ) )
return V_12 ;
F_117 (zone) {
F_288 (cpu) {
unsigned long V_74 ;
V_74 = V_11 -> V_240 / V_346 ;
F_324 (
F_118 ( V_11 -> V_104 , V_101 ) , V_74 ) ;
}
}
return 0 ;
}
static int T_3 F_430 ( char * V_120 )
{
if ( ! V_120 )
return 0 ;
V_473 = F_431 ( V_120 , & V_120 , 0 ) ;
return 1 ;
}
void * T_3 F_432 ( const char * V_474 ,
unsigned long V_475 ,
unsigned long V_476 ,
int V_477 ,
int V_51 ,
unsigned int * V_478 ,
unsigned int * V_479 ,
unsigned long V_362 )
{
unsigned long long F_301 = V_362 ;
unsigned long V_480 , V_76 ;
void * V_291 = NULL ;
if ( ! V_476 ) {
V_476 = V_405 ;
V_476 += ( 1UL << ( 20 - V_345 ) ) - 1 ;
V_476 >>= 20 - V_345 ;
V_476 <<= 20 - V_345 ;
if ( V_477 > V_345 )
V_476 >>= ( V_477 - V_345 ) ;
else
V_476 <<= ( V_345 - V_477 ) ;
if ( F_6 ( V_51 & V_481 ) ) {
F_2 ( ! ( V_51 & V_482 ) ) ;
if ( ! ( V_476 >> * V_478 ) ) {
V_476 = 1UL << * V_478 ;
F_102 ( ! V_476 ) ;
}
} else if ( F_6 ( ( V_476 * V_475 ) < V_68 ) )
V_476 = V_68 / V_475 ;
}
V_476 = F_433 ( V_476 ) ;
if ( F_301 == 0 ) {
F_301 = ( ( unsigned long long ) V_406 << V_345 ) >> 4 ;
F_417 ( F_301 , V_475 ) ;
}
if ( V_476 > F_301 )
V_476 = F_301 ;
V_480 = F_434 ( V_476 ) ;
do {
V_76 = V_475 << V_480 ;
if ( V_51 & V_482 )
V_291 = F_435 ( V_76 ) ;
else if ( V_473 )
V_291 = F_436 ( V_76 , V_483 , V_484 ) ;
else {
if ( F_229 ( V_76 ) < V_40 ) {
V_291 = F_228 ( V_76 , V_483 ) ;
F_437 ( V_291 , V_76 , 1 , V_483 ) ;
}
}
} while ( ! V_291 && V_76 > V_68 && -- V_480 );
if ( ! V_291 )
F_438 ( L_82 , V_474 ) ;
F_20 ( V_485 L_83 ,
V_474 ,
( 1UL << V_480 ) ,
F_434 ( V_76 ) - V_345 ,
V_76 ) ;
if ( V_478 )
* V_478 = V_480 ;
if ( V_479 )
* V_479 = ( 1 << V_480 ) - 1 ;
return V_291 ;
}
static inline unsigned long * F_439 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef F_440
return F_441 ( V_14 ) -> V_395 ;
#else
return V_11 -> V_395 ;
#endif
}
static inline int F_442 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef F_440
V_14 &= ( V_486 - 1 ) ;
return ( V_14 >> V_90 ) * V_394 ;
#else
V_14 = V_14 - V_11 -> V_15 ;
return ( V_14 >> V_90 ) * V_394 ;
#endif
}
unsigned long F_443 ( struct V_5 * V_5 ,
int V_487 , int V_488 )
{
struct V_11 * V_11 ;
unsigned long * V_489 ;
unsigned long V_14 , V_490 ;
unsigned long V_51 = 0 ;
unsigned long V_491 = 1 ;
V_11 = F_14 ( V_5 ) ;
V_14 = F_9 ( V_5 ) ;
V_489 = F_439 ( V_11 , V_14 ) ;
V_490 = F_442 ( V_11 , V_14 ) ;
for (; V_487 <= V_488 ; V_487 ++ , V_491 <<= 1 )
if ( F_164 ( V_490 + V_487 , V_489 ) )
V_51 |= V_491 ;
return V_51 ;
}
void F_7 ( struct V_5 * V_5 , unsigned long V_51 ,
int V_487 , int V_488 )
{
struct V_11 * V_11 ;
unsigned long * V_489 ;
unsigned long V_14 , V_490 ;
unsigned long V_491 = 1 ;
V_11 = F_14 ( V_5 ) ;
V_14 = F_9 ( V_5 ) ;
V_489 = F_439 ( V_11 , V_14 ) ;
V_490 = F_442 ( V_11 , V_14 ) ;
F_38 ( V_14 < V_11 -> V_15 ) ;
F_38 ( V_14 >= V_11 -> V_15 + V_11 -> V_16 ) ;
for (; V_487 <= V_488 ; V_487 ++ , V_491 <<= 1 )
if ( V_51 & V_491 )
F_444 ( V_490 + V_487 , V_489 ) ;
else
F_445 ( V_490 + V_487 , V_489 ) ;
}
static int
F_446 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_54 )
{
unsigned long V_14 , V_492 , V_493 ;
if ( F_168 ( V_11 ) == V_374 )
return true ;
if ( F_86 ( V_5 ) == V_110 )
return true ;
V_14 = F_9 ( V_5 ) ;
for ( V_493 = 0 , V_492 = 0 ; V_492 < V_86 ; V_492 ++ ) {
unsigned long V_494 = V_14 + V_492 ;
if ( ! F_13 ( V_494 ) )
continue;
V_5 = F_107 ( V_494 ) ;
if ( ! F_51 ( V_5 ) ) {
if ( F_49 ( V_5 ) )
V_492 += ( 1 << F_50 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_447 ( V_5 ) )
V_493 ++ ;
if ( V_493 > V_54 )
return false ;
}
return true ;
}
bool F_448 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_14 ( V_5 ) ;
return F_446 ( V_11 , V_5 , 0 ) ;
}
int F_449 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_51 , V_14 ;
struct V_495 V_105 ;
int V_496 ;
int V_12 = - V_497 ;
V_11 = F_14 ( V_5 ) ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
V_14 = F_9 ( V_5 ) ;
V_105 . V_84 = V_14 ;
V_105 . V_29 = V_86 ;
V_105 . V_498 = 0 ;
V_496 = V_495 ( V_499 , & V_105 ) ;
V_496 = F_450 ( V_496 ) ;
if ( V_496 )
goto V_21;
if ( F_446 ( V_11 , V_5 , V_105 . V_498 ) )
V_12 = 0 ;
V_21:
if ( ! V_12 ) {
F_5 ( V_5 , V_109 ) ;
F_106 ( V_11 , V_5 , V_109 ) ;
}
F_131 ( & V_11 -> V_59 , V_51 ) ;
if ( ! V_12 )
F_121 () ;
return V_12 ;
}
void F_451 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_51 ;
V_11 = F_14 ( V_5 ) ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
if ( F_86 ( V_5 ) != V_109 )
goto V_21;
F_5 ( V_5 , V_110 ) ;
F_106 ( V_11 , V_5 , V_110 ) ;
V_21:
F_131 ( & V_11 -> V_59 , V_51 ) ;
}
void
F_452 ( unsigned long V_84 , unsigned long V_85 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_27 , V_28 ;
unsigned long V_14 ;
unsigned long V_51 ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 ++ )
if ( F_125 ( V_14 ) )
break;
if ( V_14 == V_85 )
return;
V_11 = F_14 ( F_107 ( V_14 ) ) ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
V_14 = V_84 ;
while ( V_14 < V_85 ) {
if ( ! F_125 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_107 ( V_14 ) ;
F_102 ( F_51 ( V_5 ) ) ;
F_102 ( ! F_49 ( V_5 ) ) ;
V_27 = F_50 ( V_5 ) ;
#ifdef F_453
F_20 ( V_485 L_84 ,
V_14 , 1 << V_27 , V_85 ) ;
#endif
F_54 ( & V_5 -> V_41 ) ;
F_44 ( V_5 ) ;
V_11 -> V_42 [ V_27 ] . V_43 -- ;
F_70 ( V_11 , V_67 ,
- ( 1UL << V_27 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_314 ( ( V_5 + V_28 ) ) ;
V_14 += ( 1 << V_27 ) ;
}
F_131 ( & V_11 -> V_59 , V_51 ) ;
}
bool F_454 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_14 ( V_5 ) ;
unsigned long V_14 = F_9 ( V_5 ) ;
unsigned long V_51 ;
int V_27 ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
struct V_5 * V_500 = V_5 - ( V_14 & ( ( 1 << V_27 ) - 1 ) ) ;
if ( F_49 ( V_500 ) && F_50 ( V_500 ) >= V_27 )
break;
}
F_131 ( & V_11 -> V_59 , V_51 ) ;
return V_27 < V_40 ;
}
static void F_455 ( unsigned long V_51 )
{
const char * V_501 = L_85 ;
unsigned long V_502 ;
int V_28 ;
F_20 ( V_22 L_86 , V_51 ) ;
V_51 &= ( 1UL << V_503 ) - 1 ;
for ( V_28 = 0 ; V_504 [ V_28 ] . V_258 && V_51 ; V_28 ++ ) {
V_502 = V_504 [ V_28 ] . V_502 ;
if ( ( V_51 & V_502 ) != V_502 )
continue;
V_51 &= ~ V_502 ;
F_20 ( L_87 , V_501 , V_504 [ V_28 ] . V_258 ) ;
V_501 = L_88 ;
}
if ( V_51 )
F_20 ( L_89 , V_501 , V_51 ) ;
F_20 ( L_90 ) ;
}
void F_21 ( struct V_5 * V_5 )
{
F_20 ( V_22
L_91 ,
V_5 , F_62 ( & V_5 -> V_50 ) , F_61 ( V_5 ) ,
V_5 -> V_49 , V_5 -> V_357 ) ;
F_455 ( V_5 -> V_51 ) ;
F_456 ( V_5 ) ;
}
