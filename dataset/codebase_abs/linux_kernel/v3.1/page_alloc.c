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
V_133 = F_150 ( L_3 , NULL ,
& V_121 . V_122 ) ;
if ( F_151 ( V_133 ) )
return F_152 ( V_133 ) ;
if ( ! F_153 ( L_4 , V_128 , V_133 ,
& V_121 . V_126 ) )
goto V_134;
if ( ! F_153 ( L_5 , V_128 , V_133 ,
& V_121 . V_125 ) )
goto V_134;
if ( ! F_154 ( L_6 , V_128 , V_133 ,
& V_121 . V_124 ) )
goto V_134;
return 0 ;
V_134:
F_155 ( V_133 ) ;
return - V_135 ;
}
static inline int F_147 ( T_1 V_123 , unsigned int V_27 )
{
return 0 ;
}
static bool F_156 ( struct V_11 * V_136 , int V_27 , unsigned long V_137 ,
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
bool F_140 ( struct V_11 * V_136 , int V_27 , unsigned long V_137 ,
int V_138 , int V_139 )
{
return F_156 ( V_136 , V_27 , V_137 , V_138 , V_139 ,
F_157 ( V_136 , V_67 ) ) ;
}
bool F_158 ( struct V_11 * V_136 , int V_27 , unsigned long V_137 ,
int V_138 , int V_139 )
{
long V_140 = F_157 ( V_136 , V_67 ) ;
if ( V_136 -> V_146 && V_140 < V_136 -> V_146 )
V_140 = F_159 ( V_136 , V_67 ) ;
return F_156 ( V_136 , V_27 , V_137 , V_138 , V_139 ,
V_140 ) ;
}
static T_5 * F_160 ( struct V_147 * V_147 , int V_139 )
{
struct V_148 * V_149 ;
T_5 * V_150 ;
V_149 = V_147 -> V_151 ;
if ( ! V_149 )
return NULL ;
if ( F_161 ( V_20 , V_149 -> V_152 + V_23 ) ) {
F_162 ( V_149 -> V_153 , V_154 ) ;
V_149 -> V_152 = V_20 ;
}
V_150 = ! F_39 () && ( V_139 & V_155 ) ?
& V_156 :
& V_157 [ V_158 ] ;
return V_150 ;
}
static int F_163 ( struct V_147 * V_147 , struct V_159 * V_136 ,
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
return F_164 ( V_160 , * V_150 ) && ! F_165 ( V_28 , V_149 -> V_153 ) ;
}
static void F_166 ( struct V_147 * V_147 , struct V_159 * V_136 )
{
struct V_148 * V_149 ;
int V_28 ;
V_149 = V_147 -> V_151 ;
if ( ! V_149 )
return;
V_28 = V_136 - V_147 -> V_161 ;
F_167 ( V_28 , V_149 -> V_153 ) ;
}
static void F_168 ( struct V_147 * V_147 )
{
struct V_148 * V_149 ;
V_149 = V_147 -> V_151 ;
if ( ! V_149 )
return;
F_162 ( V_149 -> V_153 , V_154 ) ;
}
static T_5 * F_160 ( struct V_147 * V_147 , int V_139 )
{
return NULL ;
}
static int F_163 ( struct V_147 * V_147 , struct V_159 * V_136 ,
T_5 * V_150 )
{
return 1 ;
}
static void F_166 ( struct V_147 * V_147 , struct V_159 * V_136 )
{
}
static void F_168 ( struct V_147 * V_147 )
{
}
static struct V_5 *
F_169 ( T_1 V_123 , T_5 * V_163 , unsigned int V_27 ,
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
V_138 = F_170 ( V_114 ) ;
V_167:
F_171 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( V_168 && V_165 &&
! F_163 ( V_147 , V_136 , V_150 ) )
continue;
if ( ( V_139 & V_155 ) &&
! F_172 ( V_11 , V_123 ) )
continue;
F_173 ( V_169 < V_170 ) ;
if ( ! ( V_139 & V_169 ) ) {
unsigned long V_137 ;
int V_12 ;
V_137 = V_11 -> V_112 [ V_139 & V_171 ] ;
if ( F_140 ( V_11 , V_27 , V_137 ,
V_138 , V_139 ) )
goto V_172;
if ( V_168 && ! V_166 && V_173 > 1 ) {
V_150 = F_160 ( V_147 , V_139 ) ;
V_165 = 1 ;
V_166 = 1 ;
}
if ( V_174 == 0 )
goto V_175;
if ( V_168 && V_165 &&
! F_163 ( V_147 , V_136 , V_150 ) )
continue;
V_12 = F_174 ( V_11 , V_123 , V_27 ) ;
switch ( V_12 ) {
case V_176 :
continue;
case V_177 :
continue;
default:
if ( ! F_140 ( V_11 , V_27 , V_137 ,
V_138 , V_139 ) )
goto V_175;
}
}
V_172:
V_5 = F_141 ( V_114 , V_11 , V_27 ,
V_123 , V_6 ) ;
if ( V_5 )
break;
V_175:
if ( V_168 )
F_166 ( V_147 , V_136 ) ;
}
if ( F_6 ( V_168 && V_5 == NULL && V_165 ) ) {
V_165 = 0 ;
goto V_167;
}
return V_5 ;
}
static inline bool F_175 ( void )
{
bool V_12 = false ;
#if V_178 > 8
V_12 = F_39 () ;
#endif
return V_12 ;
}
void F_176 ( T_1 V_123 , int V_27 , const char * V_179 , ... )
{
T_6 args ;
unsigned int V_180 = V_181 ;
if ( ( V_123 & V_182 ) || ! F_177 ( & V_183 ) )
return;
if ( ! ( V_123 & V_184 ) )
if ( F_178 ( V_185 ) ||
( V_24 -> V_51 & ( V_186 | V_187 ) ) )
V_180 &= ~ V_181 ;
if ( F_39 () || ! ( V_123 & V_127 ) )
V_180 &= ~ V_181 ;
if ( V_179 ) {
F_20 ( V_188 ) ;
va_start ( args , V_179 ) ;
F_179 ( V_179 , args ) ;
va_end ( args ) ;
}
F_180 ( L_7 ,
V_24 -> V_25 , V_27 , V_123 ) ;
F_22 () ;
if ( ! F_175 () )
F_181 ( V_180 ) ;
}
static inline int
F_182 ( T_1 V_123 , unsigned int V_27 ,
unsigned long V_189 )
{
if ( V_123 & V_190 )
return 0 ;
if ( V_27 <= V_191 )
return 1 ;
if ( V_123 & V_192 && V_189 < ( 1 << V_27 ) )
return 1 ;
if ( V_123 & V_118 )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_183 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_193 V_164 ,
T_5 * V_163 , struct V_11 * V_114 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_184 ( V_147 , V_123 ) ) {
F_185 ( 1 ) ;
return NULL ;
}
V_5 = F_169 ( V_123 | V_194 , V_163 ,
V_27 , V_147 , V_164 ,
V_195 | V_155 ,
V_114 , V_6 ) ;
if ( V_5 )
goto V_21;
if ( ! ( V_123 & V_118 ) ) {
if ( V_27 > V_191 )
goto V_21;
if ( V_164 < V_196 )
goto V_21;
if ( V_123 & V_197 )
goto V_21;
}
F_186 ( V_147 , V_123 , V_27 , V_163 ) ;
V_21:
F_187 ( V_147 , V_123 ) ;
return V_5 ;
}
static struct V_5 *
F_188 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_193 V_164 ,
T_5 * V_163 , int V_139 , struct V_11 * V_114 ,
int V_6 , unsigned long * V_198 ,
bool V_199 )
{
struct V_5 * V_5 ;
if ( ! V_27 || F_189 ( V_114 ) )
return NULL ;
V_24 -> V_51 |= V_186 ;
* V_198 = F_190 ( V_147 , V_27 , V_123 ,
V_163 , V_199 ) ;
V_24 -> V_51 &= ~ V_186 ;
if ( * V_198 != V_200 ) {
F_116 ( F_191 () ) ;
F_192 () ;
V_5 = F_169 ( V_123 , V_163 ,
V_27 , V_147 , V_164 ,
V_139 , V_114 ,
V_6 ) ;
if ( V_5 ) {
V_114 -> V_201 = 0 ;
V_114 -> V_202 = 0 ;
F_193 ( V_203 ) ;
return V_5 ;
}
F_193 ( V_204 ) ;
F_194 ( V_114 ) ;
F_195 () ;
}
return NULL ;
}
static inline struct V_5 *
F_188 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_193 V_164 ,
T_5 * V_163 , int V_139 , struct V_11 * V_114 ,
int V_6 , unsigned long * V_198 ,
bool V_199 )
{
return NULL ;
}
static inline struct V_5 *
F_196 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_193 V_164 ,
T_5 * V_163 , int V_139 , struct V_11 * V_114 ,
int V_6 , unsigned long * V_198 )
{
struct V_5 * V_5 = NULL ;
struct V_205 V_205 ;
bool V_206 = false ;
F_195 () ;
F_197 () ;
V_24 -> V_51 |= V_186 ;
F_198 ( V_123 ) ;
V_205 . V_207 = 0 ;
V_24 -> V_205 = & V_205 ;
* V_198 = F_199 ( V_147 , V_27 , V_123 , V_163 ) ;
V_24 -> V_205 = NULL ;
F_200 () ;
V_24 -> V_51 &= ~ V_186 ;
F_195 () ;
if ( F_6 ( ! ( * V_198 ) ) )
return NULL ;
if ( V_168 )
F_168 ( V_147 ) ;
V_208:
V_5 = F_169 ( V_123 , V_163 , V_27 ,
V_147 , V_164 ,
V_139 , V_114 ,
V_6 ) ;
if ( ! V_5 && ! V_206 ) {
F_121 () ;
V_206 = true ;
goto V_208;
}
return V_5 ;
}
static inline struct V_5 *
F_201 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_193 V_164 ,
T_5 * V_163 , struct V_11 * V_114 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_169 ( V_123 , V_163 , V_27 ,
V_147 , V_164 , V_169 ,
V_114 , V_6 ) ;
if ( ! V_5 && V_123 & V_118 )
F_202 ( V_114 , V_209 , V_23 / 50 ) ;
} while ( ! V_5 && ( V_123 & V_118 ) );
return V_5 ;
}
static inline
void F_203 ( unsigned int V_27 , struct V_147 * V_147 ,
enum V_193 V_164 ,
enum V_193 V_138 )
{
struct V_159 * V_136 ;
struct V_11 * V_11 ;
F_204 (zone, z, zonelist, high_zoneidx)
F_205 ( V_11 , V_27 , V_138 ) ;
}
static inline int
F_206 ( T_1 V_123 )
{
int V_139 = V_210 | V_155 ;
const T_1 V_211 = V_123 & V_127 ;
F_173 ( V_212 != ( V_213 T_1 ) V_143 ) ;
V_139 |= ( V_213 int ) ( V_123 & V_212 ) ;
if ( ! V_211 ) {
if ( ! ( V_123 & V_184 ) )
V_139 |= V_144 ;
V_139 &= ~ V_155 ;
} else if ( F_6 ( F_207 ( V_24 ) ) && ! F_39 () )
V_139 |= V_144 ;
if ( F_114 ( ! ( V_123 & V_184 ) ) ) {
if ( ! F_39 () &&
( ( V_24 -> V_51 & V_186 ) ||
F_6 ( F_178 ( V_185 ) ) ) )
V_139 |= V_169 ;
}
return V_139 ;
}
static inline struct V_5 *
F_208 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , enum V_193 V_164 ,
T_5 * V_163 , struct V_11 * V_114 ,
int V_6 )
{
const T_1 V_211 = V_123 & V_127 ;
struct V_5 * V_5 = NULL ;
int V_139 ;
unsigned long V_189 = 0 ;
unsigned long V_198 ;
bool V_199 = false ;
if ( V_27 >= V_40 ) {
F_142 ( ! ( V_123 & V_182 ) ) ;
return NULL ;
}
if ( V_168 && ( V_123 & V_214 ) == V_214 )
goto V_215;
V_216:
if ( ! ( V_123 & V_217 ) )
F_203 ( V_27 , V_147 , V_164 ,
F_170 ( V_114 ) ) ;
V_139 = F_206 ( V_123 ) ;
if ( ! ( V_139 & V_155 ) && ! V_163 )
F_209 ( V_147 , V_164 , NULL ,
& V_114 ) ;
V_218:
V_5 = F_169 ( V_123 , V_163 , V_27 , V_147 ,
V_164 , V_139 & ~ V_169 ,
V_114 , V_6 ) ;
if ( V_5 )
goto V_219;
if ( V_139 & V_169 ) {
V_5 = F_201 ( V_123 , V_27 ,
V_147 , V_164 , V_163 ,
V_114 , V_6 ) ;
if ( V_5 )
goto V_219;
}
if ( ! V_211 )
goto V_215;
if ( V_24 -> V_51 & V_186 )
goto V_215;
if ( F_178 ( V_185 ) && ! ( V_123 & V_118 ) )
goto V_215;
V_5 = F_188 ( V_123 , V_27 ,
V_147 , V_164 ,
V_163 ,
V_139 , V_114 ,
V_6 , & V_198 ,
V_199 ) ;
if ( V_5 )
goto V_219;
V_199 = true ;
V_5 = F_196 ( V_123 , V_27 ,
V_147 , V_164 ,
V_163 ,
V_139 , V_114 ,
V_6 , & V_198 ) ;
if ( V_5 )
goto V_219;
if ( ! V_198 ) {
if ( ( V_123 & V_220 ) && ! ( V_123 & V_190 ) ) {
if ( V_221 )
goto V_215;
V_5 = F_183 ( V_123 , V_27 ,
V_147 , V_164 ,
V_163 , V_114 ,
V_6 ) ;
if ( V_5 )
goto V_219;
if ( ! ( V_123 & V_118 ) ) {
if ( V_27 > V_191 )
goto V_215;
if ( V_164 < V_196 )
goto V_215;
}
goto V_216;
}
}
V_189 += V_198 ;
if ( F_182 ( V_123 , V_27 , V_189 ) ) {
F_202 ( V_114 , V_209 , V_23 / 50 ) ;
goto V_218;
} else {
V_5 = F_188 ( V_123 , V_27 ,
V_147 , V_164 ,
V_163 ,
V_139 , V_114 ,
V_6 , & V_198 ,
V_199 ) ;
if ( V_5 )
goto V_219;
}
V_215:
F_176 ( V_123 , V_27 , NULL ) ;
return V_5 ;
V_219:
if ( V_222 )
F_210 ( V_5 , V_27 , V_123 ) ;
return V_5 ;
}
struct V_5 *
F_211 ( T_1 V_123 , unsigned int V_27 ,
struct V_147 * V_147 , T_5 * V_163 )
{
enum V_193 V_164 = F_212 ( V_123 ) ;
struct V_11 * V_114 ;
struct V_5 * V_5 ;
int V_6 = F_213 ( V_123 ) ;
V_123 &= V_3 ;
F_214 ( V_123 ) ;
F_215 ( V_123 & V_127 ) ;
if ( F_147 ( V_123 , V_27 ) )
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
V_5 = F_169 ( V_123 | V_194 , V_163 , V_27 ,
V_147 , V_164 , V_223 | V_155 ,
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
F_38 ( ( V_123 & V_34 ) != 0 ) ;
V_5 = F_220 ( V_123 , V_27 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_79 ( V_5 ) ;
}
unsigned long F_221 ( T_1 V_123 )
{
return F_219 ( V_123 | V_77 , 0 ) ;
}
void F_222 ( struct V_224 * V_225 )
{
int V_28 = F_223 ( V_225 ) ;
while ( -- V_28 >= 0 ) {
F_224 ( V_225 -> V_96 [ V_28 ] , V_225 -> V_98 ) ;
F_132 ( V_225 -> V_96 [ V_28 ] , V_225 -> V_98 ) ;
}
}
void F_94 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( F_225 ( V_5 ) ) {
if ( V_27 == 0 )
F_132 ( V_5 , 0 ) ;
else
F_25 ( V_5 , V_27 ) ;
}
}
void V_140 ( unsigned long V_226 , unsigned int V_27 )
{
if ( V_226 != 0 ) {
F_38 ( ! F_226 ( ( void * ) V_226 ) ) ;
F_94 ( F_137 ( ( void * ) V_226 ) , V_27 ) ;
}
}
static void * F_227 ( unsigned long V_226 , unsigned V_27 , T_7 V_76 )
{
if ( V_226 ) {
unsigned long V_227 = V_226 + ( V_68 << V_27 ) ;
unsigned long V_228 = V_226 + F_228 ( V_76 ) ;
F_134 ( F_137 ( ( void * ) V_226 ) , V_27 ) ;
while ( V_228 < V_227 ) {
F_229 ( V_228 ) ;
V_228 += V_68 ;
}
}
return ( void * ) V_226 ;
}
void * F_230 ( T_7 V_76 , T_1 V_123 )
{
unsigned int V_27 = F_231 ( V_76 ) ;
unsigned long V_226 ;
V_226 = F_219 ( V_123 , V_27 ) ;
return F_227 ( V_226 , V_27 , V_76 ) ;
}
void * F_232 ( int V_229 , T_7 V_76 , T_1 V_123 )
{
unsigned V_27 = F_231 ( V_76 ) ;
struct V_5 * V_30 = F_233 ( V_229 , V_123 , V_27 ) ;
if ( ! V_30 )
return NULL ;
return F_227 ( ( unsigned long ) F_79 ( V_30 ) , V_27 , V_76 ) ;
}
void F_234 ( void * V_230 , T_7 V_76 )
{
unsigned long V_226 = ( unsigned long ) V_230 ;
unsigned long V_231 = V_226 + F_228 ( V_76 ) ;
while ( V_226 < V_231 ) {
F_229 ( V_226 ) ;
V_226 += V_68 ;
}
}
static unsigned int F_235 ( int V_232 )
{
struct V_159 * V_136 ;
struct V_11 * V_11 ;
unsigned int V_233 = 0 ;
struct V_147 * V_147 = F_236 ( F_237 () , V_234 ) ;
F_204 (zone, z, zonelist, offset) {
unsigned long V_76 = V_11 -> V_235 ;
unsigned long V_74 = F_238 ( V_11 ) ;
if ( V_76 > V_74 )
V_233 += V_76 - V_74 ;
}
return V_233 ;
}
unsigned int F_239 ( void )
{
return F_235 ( F_212 ( V_236 ) ) ;
}
unsigned int F_240 ( void )
{
return F_235 ( F_212 ( V_237 ) ) ;
}
static inline void F_241 ( struct V_11 * V_11 )
{
if ( V_168 )
F_20 ( L_8 , F_104 ( V_11 ) ) ;
}
void F_242 ( struct V_238 * V_239 )
{
V_239 -> V_240 = V_241 ;
V_239 -> V_242 = 0 ;
V_239 -> V_243 = F_243 ( V_67 ) ;
V_239 -> V_244 = F_244 () ;
V_239 -> V_245 = V_246 ;
V_239 -> V_247 = F_245 () ;
V_239 -> V_248 = V_68 ;
}
void F_246 ( struct V_238 * V_239 , int V_229 )
{
T_8 * V_249 = F_247 ( V_229 ) ;
V_239 -> V_240 = V_249 -> V_250 ;
V_239 -> V_243 = F_248 ( V_229 , V_67 ) ;
#ifdef F_249
V_239 -> V_245 = V_249 -> V_251 [ V_252 ] . V_235 ;
V_239 -> V_247 = F_157 ( & V_249 -> V_251 [ V_252 ] ,
V_67 ) ;
#else
V_239 -> V_245 = 0 ;
V_239 -> V_247 = 0 ;
#endif
V_239 -> V_248 = V_68 ;
}
bool F_250 ( unsigned int V_51 , int V_229 )
{
bool V_12 = false ;
if ( ! ( V_51 & V_181 ) )
goto V_21;
F_216 () ;
V_12 = ! F_164 ( V_229 , V_156 ) ;
F_217 () ;
V_21:
return V_12 ;
}
void F_251 ( unsigned int V_180 )
{
int V_101 ;
struct V_11 * V_11 ;
F_117 (zone) {
if ( F_250 ( V_180 , F_104 ( V_11 ) ) )
continue;
F_241 ( V_11 ) ;
F_20 ( L_9 , V_11 -> V_253 ) ;
F_252 (cpu) {
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
F_243 ( V_254 ) ,
F_243 ( V_255 ) ,
F_243 ( V_256 ) ,
F_243 ( V_257 ) ,
F_243 ( V_258 ) ,
F_243 ( V_259 ) ,
F_243 ( V_260 ) ,
F_243 ( V_261 ) ,
F_243 ( V_262 ) ,
F_243 ( V_263 ) ,
F_243 ( V_67 ) ,
F_243 ( V_264 ) ,
F_243 ( V_265 ) ,
F_243 ( V_266 ) ,
F_243 ( V_267 ) ,
F_243 ( V_268 ) ,
F_243 ( V_269 ) ) ;
F_117 (zone) {
int V_28 ;
if ( F_250 ( V_180 , F_104 ( V_11 ) ) )
continue;
F_241 ( V_11 ) ;
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
V_11 -> V_253 ,
F_253 ( F_157 ( V_11 , V_67 ) ) ,
F_253 ( F_254 ( V_11 ) ) ,
F_253 ( F_139 ( V_11 ) ) ,
F_253 ( F_238 ( V_11 ) ) ,
F_253 ( F_157 ( V_11 , V_254 ) ) ,
F_253 ( F_157 ( V_11 , V_255 ) ) ,
F_253 ( F_157 ( V_11 , V_257 ) ) ,
F_253 ( F_157 ( V_11 , V_258 ) ) ,
F_253 ( F_157 ( V_11 , V_260 ) ) ,
F_253 ( F_157 ( V_11 , V_256 ) ) ,
F_253 ( F_157 ( V_11 , V_259 ) ) ,
F_253 ( V_11 -> V_235 ) ,
F_253 ( F_157 ( V_11 , V_47 ) ) ,
F_253 ( F_157 ( V_11 , V_261 ) ) ,
F_253 ( F_157 ( V_11 , V_262 ) ) ,
F_253 ( F_157 ( V_11 , V_266 ) ) ,
F_253 ( F_157 ( V_11 , V_267 ) ) ,
F_253 ( F_157 ( V_11 , V_264 ) ) ,
F_253 ( F_157 ( V_11 , V_265 ) ) ,
F_157 ( V_11 , V_270 ) *
V_271 / 1024 ,
F_253 ( F_157 ( V_11 , V_268 ) ) ,
F_253 ( F_157 ( V_11 , V_263 ) ) ,
F_253 ( F_157 ( V_11 , V_269 ) ) ,
F_253 ( F_157 ( V_11 , V_272 ) ) ,
V_11 -> V_61 ,
( V_11 -> V_60 ? L_45 : L_46 )
) ;
F_20 ( L_47 ) ;
for ( V_28 = 0 ; V_28 < V_273 ; V_28 ++ )
F_20 ( L_48 , V_11 -> V_145 [ V_28 ] ) ;
F_20 ( L_44 ) ;
}
F_117 (zone) {
unsigned long V_274 [ V_40 ] , V_51 , V_27 , V_275 = 0 ;
if ( F_250 ( V_180 , F_104 ( V_11 ) ) )
continue;
F_241 ( V_11 ) ;
F_20 ( L_49 , V_11 -> V_253 ) ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
V_274 [ V_27 ] = V_11 -> V_42 [ V_27 ] . V_43 ;
V_275 += V_274 [ V_27 ] << V_27 ;
}
F_131 ( & V_11 -> V_59 , V_51 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ )
F_20 ( L_50 , V_274 [ V_27 ] , F_253 ( 1UL ) << V_27 ) ;
F_20 ( L_51 , F_253 ( V_275 ) ) ;
}
F_20 ( L_52 , F_243 ( V_276 ) ) ;
F_255 () ;
}
static void F_256 ( struct V_11 * V_11 , struct V_159 * V_159 )
{
V_159 -> V_11 = V_11 ;
V_159 -> F_170 = F_170 ( V_11 ) ;
}
static int F_257 ( T_8 * V_249 , struct V_147 * V_147 ,
int V_277 , enum V_193 V_193 )
{
struct V_11 * V_11 ;
F_102 ( V_193 >= V_273 ) ;
V_193 ++ ;
do {
V_193 -- ;
V_11 = V_249 -> V_251 + V_193 ;
if ( F_258 ( V_11 ) ) {
F_256 ( V_11 ,
& V_147 -> V_161 [ V_277 ++ ] ) ;
F_259 ( V_193 ) ;
}
} while ( V_193 );
return V_277 ;
}
static int F_260 ( char * V_278 )
{
if ( * V_278 == 'd' || * V_278 == 'D' ) {
V_279 = V_280 ;
} else if ( * V_278 == 'n' || * V_278 == 'N' ) {
V_279 = V_281 ;
} else if ( * V_278 == 'z' || * V_278 == 'Z' ) {
V_279 = V_282 ;
} else {
F_20 ( V_188
L_53
L_54 , V_278 ) ;
return - V_283 ;
}
return 0 ;
}
static T_3 int F_261 ( char * V_278 )
{
int V_12 ;
if ( ! V_278 )
return 0 ;
V_12 = F_260 ( V_278 ) ;
if ( V_12 == 0 )
F_262 ( V_284 , V_278 , V_285 ) ;
return V_12 ;
}
int F_263 ( T_9 * V_286 , int V_287 ,
void T_10 * V_288 , T_7 * V_289 ,
T_11 * V_290 )
{
char V_291 [ V_285 ] ;
int V_12 ;
static F_264 ( V_292 ) ;
F_265 ( & V_292 ) ;
if ( V_287 )
strcpy ( V_291 , ( char * ) V_286 -> V_293 ) ;
V_12 = F_266 ( V_286 , V_287 , V_288 , V_289 , V_290 ) ;
if ( V_12 )
goto V_21;
if ( V_287 ) {
int V_294 = V_279 ;
if ( F_260 ( ( char * ) V_286 -> V_293 ) ) {
strncpy ( ( char * ) V_286 -> V_293 , V_291 ,
V_285 ) ;
V_279 = V_294 ;
} else if ( V_294 != V_279 ) {
F_265 ( & V_295 ) ;
F_267 ( NULL ) ;
F_268 ( & V_295 ) ;
}
}
V_21:
F_268 ( & V_292 ) ;
return V_12 ;
}
static int F_269 ( int V_296 , T_5 * V_297 )
{
int V_160 , V_239 ;
int V_298 = V_299 ;
int V_300 = - 1 ;
const struct V_301 * V_302 = F_270 ( 0 ) ;
if ( ! F_164 ( V_296 , * V_297 ) ) {
F_271 ( V_296 , * V_297 ) ;
return V_296 ;
}
F_272 (n, N_HIGH_MEMORY) {
if ( F_164 ( V_160 , * V_297 ) )
continue;
V_239 = F_273 ( V_296 , V_160 ) ;
V_239 += ( V_160 < V_296 ) ;
V_302 = F_270 ( V_160 ) ;
if ( ! F_274 ( V_302 ) )
V_239 += V_303 ;
V_239 *= ( V_304 * V_305 ) ;
V_239 += V_306 [ V_160 ] ;
if ( V_239 < V_298 ) {
V_298 = V_239 ;
V_300 = V_160 ;
}
}
if ( V_300 >= 0 )
F_271 ( V_300 , * V_297 ) ;
return V_300 ;
}
static void F_275 ( T_8 * V_249 , int V_296 )
{
int V_307 ;
struct V_147 * V_147 ;
V_147 = & V_249 -> V_308 [ 0 ] ;
for ( V_307 = 0 ; V_147 -> V_161 [ V_307 ] . V_11 != NULL ; V_307 ++ )
;
V_307 = F_257 ( F_247 ( V_296 ) , V_147 , V_307 ,
V_273 - 1 ) ;
V_147 -> V_161 [ V_307 ] . V_11 = NULL ;
V_147 -> V_161 [ V_307 ] . F_170 = 0 ;
}
static void F_276 ( T_8 * V_249 )
{
int V_307 ;
struct V_147 * V_147 ;
V_147 = & V_249 -> V_308 [ 1 ] ;
V_307 = F_257 ( V_249 , V_147 , 0 , V_273 - 1 ) ;
V_147 -> V_161 [ V_307 ] . V_11 = NULL ;
V_147 -> V_161 [ V_307 ] . F_170 = 0 ;
}
static void F_277 ( T_8 * V_249 , int V_309 )
{
int V_310 , V_307 , V_296 ;
int V_193 ;
struct V_11 * V_136 ;
struct V_147 * V_147 ;
V_147 = & V_249 -> V_308 [ 0 ] ;
V_310 = 0 ;
for ( V_193 = V_273 - 1 ; V_193 >= 0 ; V_193 -- ) {
for ( V_307 = 0 ; V_307 < V_309 ; V_307 ++ ) {
V_296 = V_311 [ V_307 ] ;
V_136 = & F_247 ( V_296 ) -> V_251 [ V_193 ] ;
if ( F_258 ( V_136 ) ) {
F_256 ( V_136 ,
& V_147 -> V_161 [ V_310 ++ ] ) ;
F_259 ( V_193 ) ;
}
}
}
V_147 -> V_161 [ V_310 ] . V_11 = NULL ;
V_147 -> V_161 [ V_310 ] . F_170 = 0 ;
}
static int F_278 ( void )
{
int V_229 , V_193 ;
unsigned long V_312 , V_313 ;
struct V_11 * V_136 ;
int V_314 ;
V_312 = 0 ;
V_313 = 0 ;
F_279 (nid) {
for ( V_193 = 0 ; V_193 < V_273 ; V_193 ++ ) {
V_136 = & F_247 ( V_229 ) -> V_251 [ V_193 ] ;
if ( F_258 ( V_136 ) ) {
if ( V_193 < V_196 )
V_312 += V_136 -> V_235 ;
V_313 += V_136 -> V_235 ;
} else if ( V_193 == V_196 ) {
return V_281 ;
}
}
}
if ( ! V_312 ||
V_312 > V_313 / 2 )
return V_281 ;
V_314 = V_313 /
( F_280 ( V_157 [ V_158 ] ) + 1 ) ;
F_279 (nid) {
V_312 = 0 ;
V_313 = 0 ;
for ( V_193 = 0 ; V_193 < V_273 ; V_193 ++ ) {
V_136 = & F_247 ( V_229 ) -> V_251 [ V_193 ] ;
if ( F_258 ( V_136 ) ) {
if ( V_193 < V_196 )
V_312 += V_136 -> V_235 ;
V_313 += V_136 -> V_235 ;
}
}
if ( V_312 &&
V_313 > V_314 &&
V_312 > V_313 * 70 / 100 )
return V_281 ;
}
return V_282 ;
}
static void F_281 ( void )
{
if ( V_279 == V_280 )
V_315 = F_278 () ;
else
V_315 = V_279 ;
}
static void F_282 ( T_8 * V_249 )
{
int V_307 , V_296 , V_316 ;
enum V_193 V_28 ;
T_5 V_317 ;
int V_318 , V_319 ;
struct V_147 * V_147 ;
int V_27 = V_315 ;
for ( V_28 = 0 ; V_28 < V_320 ; V_28 ++ ) {
V_147 = V_249 -> V_308 + V_28 ;
V_147 -> V_161 [ 0 ] . V_11 = NULL ;
V_147 -> V_161 [ 0 ] . F_170 = 0 ;
}
V_318 = V_249 -> V_321 ;
V_316 = V_173 ;
V_319 = V_318 ;
F_283 ( V_317 ) ;
memset ( V_311 , 0 , sizeof( V_311 ) ) ;
V_307 = 0 ;
while ( ( V_296 = F_269 ( V_318 , & V_317 ) ) >= 0 ) {
int V_322 = F_273 ( V_318 , V_296 ) ;
if ( V_322 > V_323 )
V_174 = 1 ;
if ( V_322 != F_273 ( V_318 , V_319 ) )
V_306 [ V_296 ] = V_316 ;
V_319 = V_296 ;
V_316 -- ;
if ( V_27 == V_281 )
F_275 ( V_249 , V_296 ) ;
else
V_311 [ V_307 ++ ] = V_296 ;
}
if ( V_27 == V_282 ) {
F_277 ( V_249 , V_307 ) ;
}
F_276 ( V_249 ) ;
}
static void F_284 ( T_8 * V_249 )
{
struct V_147 * V_147 ;
struct V_148 * V_149 ;
struct V_159 * V_136 ;
V_147 = & V_249 -> V_308 [ 0 ] ;
V_147 -> V_151 = V_149 = & V_147 -> V_324 ;
F_162 ( V_149 -> V_153 , V_154 ) ;
for ( V_136 = V_147 -> V_161 ; V_136 -> V_11 ; V_136 ++ )
V_149 -> V_162 [ V_136 - V_147 -> V_161 ] = F_285 ( V_136 ) ;
}
int F_286 ( int V_296 )
{
struct V_11 * V_11 ;
( void ) F_209 ( F_236 ( V_296 , V_234 ) ,
F_212 ( V_234 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_296 ;
}
static void F_281 ( void )
{
V_315 = V_282 ;
}
static void F_282 ( T_8 * V_249 )
{
int V_296 , V_318 ;
enum V_193 V_307 ;
struct V_147 * V_147 ;
V_318 = V_249 -> V_321 ;
V_147 = & V_249 -> V_308 [ 0 ] ;
V_307 = F_257 ( V_249 , V_147 , 0 , V_273 - 1 ) ;
for ( V_296 = V_318 + 1 ; V_296 < V_305 ; V_296 ++ ) {
if ( ! F_287 ( V_296 ) )
continue;
V_307 = F_257 ( F_247 ( V_296 ) , V_147 , V_307 ,
V_273 - 1 ) ;
}
for ( V_296 = 0 ; V_296 < V_318 ; V_296 ++ ) {
if ( ! F_287 ( V_296 ) )
continue;
V_307 = F_257 ( F_247 ( V_296 ) , V_147 , V_307 ,
V_273 - 1 ) ;
}
V_147 -> V_161 [ V_307 ] . V_11 = NULL ;
V_147 -> V_161 [ V_307 ] . F_170 = 0 ;
}
static void F_284 ( T_8 * V_249 )
{
V_249 -> V_308 [ 0 ] . V_151 = NULL ;
}
static T_12 int F_288 ( void * V_293 )
{
int V_229 ;
int V_101 ;
#ifdef F_289
memset ( V_306 , 0 , sizeof( V_306 ) ) ;
#endif
F_279 (nid) {
T_8 * V_249 = F_247 ( V_229 ) ;
F_282 ( V_249 ) ;
F_284 ( V_249 ) ;
}
F_290 (cpu) {
F_291 ( & F_292 ( V_325 , V_101 ) , 0 ) ;
#ifdef F_293
if ( F_294 ( V_101 ) )
F_295 ( V_101 , F_286 ( F_296 ( V_101 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_267 ( void * V_293 )
{
F_281 () ;
if ( V_326 == V_327 ) {
F_288 ( NULL ) ;
F_297 () ;
F_298 () ;
} else {
#ifdef F_299
if ( V_293 )
F_300 ( (struct V_11 * ) V_293 ) ;
#endif
F_301 ( F_288 , NULL , NULL ) ;
}
V_328 = F_240 () ;
if ( V_328 < ( V_86 * V_92 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_20 ( L_55
L_56 ,
V_173 ,
V_329 [ V_315 ] ,
V_7 ? L_57 : L_58 ,
V_328 ) ;
#ifdef F_289
F_20 ( L_59 , V_330 [ V_331 ] ) ;
#endif
}
static inline unsigned long F_302 ( unsigned long V_96 )
{
unsigned long V_76 = 1 ;
V_96 /= V_332 ;
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
if ( ! F_13 ( V_14 ) || F_307 ( F_107 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_308 ( struct V_11 * V_11 )
{
unsigned long V_84 , V_14 , V_85 , V_333 ;
struct V_5 * V_5 ;
unsigned long V_334 ;
int V_335 ;
V_84 = V_11 -> V_15 ;
V_85 = V_84 + V_11 -> V_16 ;
V_335 = F_309 ( F_254 ( V_11 ) , V_86 ) >>
V_90 ;
V_335 = V_141 ( 2 , V_335 ) ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 += V_86 ) {
if ( ! F_125 ( V_14 ) )
continue;
V_5 = F_107 ( V_14 ) ;
if ( F_103 ( V_5 ) != F_104 ( V_11 ) )
continue;
V_333 = V_141 ( V_14 + V_86 , V_85 ) ;
if ( F_306 ( V_14 , V_333 ) )
continue;
V_334 = F_86 ( V_5 ) ;
if ( V_335 > 0 && V_334 == V_94 ) {
V_335 -- ;
continue;
}
if ( V_335 > 0 && V_334 == V_110 ) {
F_5 ( V_5 , V_94 ) ;
F_106 ( V_11 , V_5 , V_94 ) ;
V_335 -- ;
continue;
}
if ( V_334 == V_94 ) {
F_5 ( V_5 , V_110 ) ;
F_106 ( V_11 , V_5 , V_110 ) ;
}
}
}
void T_2 F_310 ( unsigned long V_76 , int V_229 , unsigned long V_11 ,
unsigned long V_84 , enum V_336 V_337 )
{
struct V_5 * V_5 ;
unsigned long V_85 = V_84 + V_76 ;
unsigned long V_14 ;
struct V_11 * V_136 ;
if ( V_338 < V_85 - 1 )
V_338 = V_85 - 1 ;
V_136 = & F_247 ( V_229 ) -> V_251 [ V_11 ] ;
for ( V_14 = V_84 ; V_14 < V_85 ; V_14 ++ ) {
if ( V_337 == V_339 ) {
if ( ! F_311 ( V_14 ) )
continue;
if ( ! F_312 ( V_14 , V_229 ) )
continue;
}
V_5 = F_107 ( V_14 ) ;
F_313 ( V_5 , V_11 , V_229 , V_14 ) ;
F_314 ( V_5 , V_11 , V_229 , V_14 ) ;
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
F_320 ( V_5 , F_321 ( V_14 << V_340 ) ) ;
#endif
}
}
static void T_2 F_322 ( struct V_11 * V_11 )
{
int V_27 , V_107 ;
F_128 (order, t) {
F_317 ( & V_11 -> V_42 [ V_27 ] . V_46 [ V_107 ] ) ;
V_11 -> V_42 [ V_27 ] . V_43 = 0 ;
}
}
static int F_323 ( struct V_11 * V_11 )
{
#ifdef F_324
int V_100 ;
V_100 = V_11 -> V_235 / 1024 ;
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
if ( ( V_74 / 4 ) > ( V_340 * 8 ) )
V_56 -> V_100 = V_340 * 8 ;
}
static void F_300 ( struct V_11 * V_11 )
{
int V_101 ;
V_11 -> V_104 = F_327 ( struct V_102 ) ;
F_290 (cpu) {
struct V_102 * V_56 = F_118 ( V_11 -> V_104 , V_101 ) ;
F_291 ( V_56 , F_323 ( V_11 ) ) ;
if ( V_341 )
F_326 ( V_56 ,
( V_11 -> V_235 /
V_341 ) ) ;
}
}
void T_3 F_328 ( void )
{
struct V_11 * V_11 ;
F_117 (zone)
F_300 ( V_11 ) ;
}
static T_14 T_12
int F_329 ( struct V_11 * V_11 , unsigned long V_342 )
{
int V_28 ;
struct V_343 * V_249 = V_11 -> V_344 ;
T_7 V_345 ;
V_11 -> F_302 =
F_302 ( V_342 ) ;
V_11 -> F_304 =
F_304 ( V_11 -> F_302 ) ;
V_345 = V_11 -> F_302
* sizeof( V_346 ) ;
if ( ! F_330 () ) {
V_11 -> V_347 = ( V_346 * )
F_331 ( V_249 , V_345 ) ;
} else {
V_11 -> V_347 = F_332 ( V_345 ) ;
}
if ( ! V_11 -> V_347 )
return - V_135 ;
for( V_28 = 0 ; V_28 < V_11 -> F_302 ; ++ V_28 )
F_333 ( V_11 -> V_347 + V_28 ) ;
return 0 ;
}
static int F_334 ( void * V_293 )
{
struct V_11 * V_11 = V_293 ;
int V_101 ;
unsigned long V_100 = F_323 ( V_11 ) , V_51 ;
F_290 (cpu) {
struct V_102 * V_103 ;
struct V_55 * V_56 ;
V_103 = F_118 ( V_11 -> V_104 , V_101 ) ;
V_56 = & V_103 -> V_56 ;
F_84 ( V_51 ) ;
F_64 ( V_11 , V_56 -> V_54 , V_56 ) ;
F_291 ( V_103 , V_100 ) ;
F_87 ( V_51 ) ;
}
return 0 ;
}
void F_335 ( struct V_11 * V_11 )
{
F_301 ( F_334 , V_11 , NULL ) ;
}
static T_2 void F_336 ( struct V_11 * V_11 )
{
V_11 -> V_104 = & V_325 ;
if ( V_11 -> V_235 )
F_20 ( V_348 L_60 ,
V_11 -> V_253 , V_11 -> V_235 ,
F_323 ( V_11 ) ) ;
}
T_2 int F_337 ( struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_76 ,
enum V_336 V_337 )
{
struct V_343 * V_249 = V_11 -> V_344 ;
int V_12 ;
V_12 = F_329 ( V_11 , V_76 ) ;
if ( V_12 )
return V_12 ;
V_249 -> V_277 = F_170 ( V_11 ) + 1 ;
V_11 -> V_15 = V_15 ;
F_338 ( V_349 , L_61 ,
L_62 ,
V_249 -> V_321 ,
( unsigned long ) F_170 ( V_11 ) ,
V_15 , ( V_15 + V_76 ) ) ;
F_322 ( V_11 ) ;
return 0 ;
}
static int T_2 F_339 ( int V_229 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_350 ; V_28 ++ )
if ( V_229 == V_305 || V_351 [ V_28 ] . V_229 == V_229 )
return V_28 ;
return - 1 ;
}
static int T_2 F_340 ( int V_352 , int V_229 )
{
for ( V_352 = V_352 + 1 ; V_352 < V_350 ; V_352 ++ )
if ( V_229 == V_305 || V_351 [ V_352 ] . V_229 == V_229 )
return V_352 ;
return - 1 ;
}
int T_2 F_341 ( unsigned long V_14 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_350 ; V_28 ++ ) {
unsigned long V_84 = V_351 [ V_28 ] . V_84 ;
unsigned long V_85 = V_351 [ V_28 ] . V_85 ;
if ( V_84 <= V_14 && V_14 < V_85 )
return V_351 [ V_28 ] . V_229 ;
}
return - 1 ;
}
int T_2 F_342 ( unsigned long V_14 )
{
int V_229 ;
V_229 = F_341 ( V_14 ) ;
if ( V_229 >= 0 )
return V_229 ;
return 0 ;
}
bool T_2 F_312 ( unsigned long V_14 , int V_296 )
{
int V_229 ;
V_229 = F_341 ( V_14 ) ;
if ( V_229 >= 0 && V_229 != V_296 )
return false ;
return true ;
}
void T_3 F_343 ( int V_229 ,
unsigned long V_353 )
{
int V_28 ;
F_344 (i, nid) {
unsigned long V_354 = 0 ;
unsigned long V_85 = V_351 [ V_28 ] . V_85 ;
if ( V_351 [ V_28 ] . V_84 >= V_353 )
continue;
if ( V_85 > V_353 )
V_85 = V_353 ;
V_354 = V_85 - V_351 [ V_28 ] . V_84 ;
F_345 ( F_247 ( V_351 [ V_28 ] . V_229 ) ,
F_346 ( V_351 [ V_28 ] . V_84 ) ,
V_354 << V_340 ) ;
}
}
static int T_2 F_347 ( int V_229 )
{
int V_28 ;
for ( V_28 = V_350 - 1 ; V_28 >= 0 ; V_28 -- )
if ( V_229 == V_305 || V_351 [ V_28 ] . V_229 == V_229 )
return V_28 ;
return - 1 ;
}
static int T_2 F_348 ( int V_352 , int V_229 )
{
for ( V_352 = V_352 - 1 ; V_352 >= 0 ; V_352 -- )
if ( V_229 == V_305 || V_351 [ V_352 ] . V_229 == V_229 )
return V_352 ;
return - 1 ;
}
T_15 T_3 F_349 ( int V_229 , T_15 V_76 , T_15 V_355 ,
T_15 V_356 , T_15 V_357 )
{
int V_28 ;
F_350 (i, nid) {
T_15 V_226 ;
T_15 V_358 , V_359 ;
T_15 V_360 , V_361 ;
V_359 = V_351 [ V_28 ] . V_85 ;
V_359 <<= V_340 ;
V_358 = V_351 [ V_28 ] . V_84 ;
V_358 <<= V_340 ;
V_360 = F_303 ( V_358 , V_356 ) ;
V_361 = V_141 ( V_359 , V_357 ) ;
if ( V_360 >= V_361 )
continue;
V_226 = F_351 ( V_360 , V_361 , V_76 , V_355 ) ;
if ( V_226 == V_362 )
continue;
return V_226 ;
}
return V_362 ;
}
int T_3 F_352 ( struct V_363 * V_363 , int V_364 ,
int V_365 , int V_229 )
{
int V_28 ;
T_15 V_366 , V_231 ;
F_344 (i, nid) {
V_366 = V_351 [ V_28 ] . V_84 ;
V_231 = V_351 [ V_28 ] . V_85 ;
V_365 = F_353 ( V_363 , V_364 , V_365 , V_366 , V_231 ) ;
}
return V_365 ;
}
void T_3 F_354 ( int V_229 , T_16 V_367 , void * V_293 )
{
int V_28 ;
int V_12 ;
F_344 (i, nid) {
V_12 = V_367 ( V_351 [ V_28 ] . V_84 ,
V_351 [ V_28 ] . V_85 , V_293 ) ;
if ( V_12 )
break;
}
}
void T_3 F_355 ( int V_229 )
{
int V_28 ;
F_344 (i, nid)
F_356 ( V_351 [ V_28 ] . V_229 ,
V_351 [ V_28 ] . V_84 ,
V_351 [ V_28 ] . V_85 ) ;
}
void T_2 F_357 ( unsigned int V_229 ,
unsigned long * V_84 , unsigned long * V_85 )
{
int V_28 ;
* V_84 = - 1UL ;
* V_85 = 0 ;
F_344 (i, nid) {
* V_84 = V_141 ( * V_84 , V_351 [ V_28 ] . V_84 ) ;
* V_85 = F_303 ( * V_85 , V_351 [ V_28 ] . V_85 ) ;
}
if ( * V_84 == - 1UL )
* V_84 = 0 ;
}
static void T_3 F_358 ( void )
{
int V_368 ;
for ( V_368 = V_273 - 1 ; V_368 >= 0 ; V_368 -- ) {
if ( V_368 == V_369 )
continue;
if ( V_370 [ V_368 ] >
V_371 [ V_368 ] )
break;
}
F_38 ( V_368 == - 1 ) ;
V_372 = V_368 ;
}
static void T_2 F_359 ( int V_229 ,
unsigned long V_193 ,
unsigned long V_373 ,
unsigned long V_374 ,
unsigned long * V_15 ,
unsigned long * V_375 )
{
if ( V_376 [ V_229 ] ) {
if ( V_193 == V_369 ) {
* V_15 = V_376 [ V_229 ] ;
* V_375 = V_141 ( V_374 ,
V_370 [ V_372 ] ) ;
} else if ( * V_15 < V_376 [ V_229 ] &&
* V_375 > V_376 [ V_229 ] ) {
* V_375 = V_376 [ V_229 ] ;
} else if ( * V_15 >= V_376 [ V_229 ] )
* V_15 = * V_375 ;
}
}
static unsigned long T_2 F_360 ( int V_229 ,
unsigned long V_193 ,
unsigned long * V_377 )
{
unsigned long V_373 , V_374 ;
unsigned long V_15 , V_375 ;
F_357 ( V_229 , & V_373 , & V_374 ) ;
V_15 = V_371 [ V_193 ] ;
V_375 = V_370 [ V_193 ] ;
F_359 ( V_229 , V_193 ,
V_373 , V_374 ,
& V_15 , & V_375 ) ;
if ( V_375 < V_373 || V_15 > V_374 )
return 0 ;
V_375 = V_141 ( V_375 , V_374 ) ;
V_15 = F_303 ( V_15 , V_373 ) ;
return V_375 - V_15 ;
}
unsigned long T_2 F_361 ( int V_229 ,
unsigned long V_378 ,
unsigned long V_379 )
{
int V_28 = 0 ;
unsigned long V_380 = 0 , V_381 = 0 ;
unsigned long V_84 ;
V_28 = F_339 ( V_229 ) ;
if ( V_28 == - 1 )
return 0 ;
V_380 = V_141 ( V_351 [ V_28 ] . V_84 , V_379 ) ;
if ( V_351 [ V_28 ] . V_84 > V_378 )
V_381 = V_380 - V_378 ;
for (; V_28 != - 1 ; V_28 = F_340 ( V_28 , V_229 ) ) {
if ( V_380 >= V_379 )
break;
V_84 = V_141 ( V_351 [ V_28 ] . V_84 , V_379 ) ;
V_380 = F_303 ( V_380 , V_378 ) ;
if ( V_84 > V_378 ) {
F_102 ( V_380 > V_84 ) ;
V_381 += V_84 - V_380 ;
}
V_380 = V_351 [ V_28 ] . V_85 ;
}
if ( V_379 > V_380 )
V_381 += V_379 -
F_303 ( V_378 , V_380 ) ;
return V_381 ;
}
unsigned long T_3 F_362 ( unsigned long V_84 ,
unsigned long V_85 )
{
return F_361 ( V_305 , V_84 , V_85 ) ;
}
static unsigned long T_2 F_363 ( int V_229 ,
unsigned long V_193 ,
unsigned long * V_377 )
{
unsigned long V_373 , V_374 ;
unsigned long V_15 , V_375 ;
F_357 ( V_229 , & V_373 , & V_374 ) ;
V_15 = F_303 ( V_371 [ V_193 ] ,
V_373 ) ;
V_375 = V_141 ( V_370 [ V_193 ] ,
V_374 ) ;
F_359 ( V_229 , V_193 ,
V_373 , V_374 ,
& V_15 , & V_375 ) ;
return F_361 ( V_229 , V_15 , V_375 ) ;
}
static inline unsigned long T_2 F_360 ( int V_229 ,
unsigned long V_193 ,
unsigned long * V_382 )
{
return V_382 [ V_193 ] ;
}
static inline unsigned long T_2 F_363 ( int V_229 ,
unsigned long V_193 ,
unsigned long * V_383 )
{
if ( ! V_383 )
return 0 ;
return V_383 [ V_193 ] ;
}
static void T_2 F_364 ( struct V_343 * V_249 ,
unsigned long * V_382 , unsigned long * V_383 )
{
unsigned long V_384 , V_385 = 0 ;
enum V_193 V_28 ;
for ( V_28 = 0 ; V_28 < V_273 ; V_28 ++ )
V_385 += F_360 ( V_249 -> V_321 , V_28 ,
V_382 ) ;
V_249 -> V_386 = V_385 ;
V_384 = V_385 ;
for ( V_28 = 0 ; V_28 < V_273 ; V_28 ++ )
V_384 -=
F_363 ( V_249 -> V_321 , V_28 ,
V_383 ) ;
V_249 -> V_250 = V_384 ;
F_20 ( V_348 L_63 , V_249 -> V_321 ,
V_384 ) ;
}
static unsigned long T_3 F_365 ( unsigned long V_387 )
{
unsigned long V_388 ;
V_388 = F_309 ( V_387 , V_86 ) ;
V_388 = V_388 >> V_90 ;
V_388 *= V_389 ;
V_388 = F_309 ( V_388 , 8 * sizeof( unsigned long ) ) ;
return V_388 / 8 ;
}
static void T_3 F_366 ( struct V_343 * V_249 ,
struct V_11 * V_11 , unsigned long V_387 )
{
unsigned long V_388 = F_365 ( V_387 ) ;
V_11 -> V_390 = NULL ;
if ( V_388 )
V_11 -> V_390 = F_331 ( V_249 ,
V_388 ) ;
}
static inline void F_366 ( struct V_343 * V_249 ,
struct V_11 * V_11 , unsigned long V_387 ) {}
static inline int F_367 ( void )
{
if ( V_391 > V_340 )
return V_392 ;
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
static void T_17 F_369 ( struct V_343 * V_249 ,
unsigned long * V_382 , unsigned long * V_383 )
{
enum V_193 V_307 ;
int V_229 = V_249 -> V_321 ;
unsigned long V_15 = V_249 -> V_373 ;
int V_12 ;
F_370 ( V_249 ) ;
V_249 -> V_277 = 0 ;
F_333 ( & V_249 -> V_393 ) ;
V_249 -> V_394 = 0 ;
F_371 ( V_249 ) ;
for ( V_307 = 0 ; V_307 < V_273 ; V_307 ++ ) {
struct V_11 * V_11 = V_249 -> V_251 + V_307 ;
unsigned long V_76 , V_395 , V_396 ;
enum V_397 V_398 ;
V_76 = F_360 ( V_229 , V_307 , V_382 ) ;
V_395 = V_76 - F_363 ( V_229 , V_307 ,
V_383 ) ;
V_396 =
F_228 ( V_76 * sizeof( struct V_5 ) ) >> V_340 ;
if ( V_395 >= V_396 ) {
V_395 -= V_396 ;
if ( V_396 )
F_20 ( V_348
L_64 ,
V_330 [ V_307 ] , V_396 ) ;
} else
F_20 ( V_188
L_65 ,
V_330 [ V_307 ] , V_396 , V_395 ) ;
if ( V_307 == 0 && V_395 > V_399 ) {
V_395 -= V_399 ;
F_20 ( V_348 L_66 ,
V_330 [ 0 ] , V_399 ) ;
}
if ( ! F_319 ( V_307 ) )
V_400 += V_395 ;
V_401 += V_395 ;
V_11 -> V_16 = V_76 ;
V_11 -> V_235 = V_395 ;
#ifdef F_289
V_11 -> V_296 = V_229 ;
V_11 -> V_402 = ( V_395 * V_403 )
/ 100 ;
V_11 -> V_404 = ( V_395 * V_405 ) / 100 ;
#endif
V_11 -> V_253 = V_330 [ V_307 ] ;
F_372 ( & V_11 -> V_59 ) ;
F_372 ( & V_11 -> V_406 ) ;
F_373 ( V_11 ) ;
V_11 -> V_344 = V_249 ;
F_336 ( V_11 ) ;
F_374 (l)
F_317 ( & V_11 -> V_41 [ V_398 ] . V_63 ) ;
V_11 -> V_407 . V_408 [ 0 ] = 0 ;
V_11 -> V_407 . V_408 [ 1 ] = 0 ;
V_11 -> V_407 . V_409 [ 0 ] = 0 ;
V_11 -> V_407 . V_409 [ 1 ] = 0 ;
F_375 ( V_11 ) ;
V_11 -> V_51 = 0 ;
if ( ! V_76 )
continue;
F_368 ( F_367 () ) ;
F_366 ( V_249 , V_11 , V_76 ) ;
V_12 = F_337 ( V_11 , V_15 ,
V_76 , V_339 ) ;
F_102 ( V_12 ) ;
F_376 ( V_76 , V_229 , V_307 , V_15 ) ;
V_15 += V_76 ;
}
}
static void T_12 F_377 ( struct V_343 * V_249 )
{
if ( ! V_249 -> V_386 )
return;
#ifdef F_378
if ( ! V_249 -> V_410 ) {
unsigned long V_76 , V_366 , V_231 ;
struct V_5 * V_411 ;
V_366 = V_249 -> V_373 & ~ ( V_412 - 1 ) ;
V_231 = V_249 -> V_373 + V_249 -> V_386 ;
V_231 = F_379 ( V_231 , V_412 ) ;
V_76 = ( V_231 - V_366 ) * sizeof( struct V_5 ) ;
V_411 = F_380 ( V_249 -> V_321 , V_76 ) ;
if ( ! V_411 )
V_411 = F_331 ( V_249 , V_76 ) ;
V_249 -> V_410 = V_411 + ( V_249 -> V_373 - V_366 ) ;
}
#ifndef F_381
if ( V_249 == F_247 ( 0 ) ) {
V_413 = F_247 ( 0 ) -> V_410 ;
#ifdef F_382
if ( F_9 ( V_413 ) != V_249 -> V_373 )
V_413 -= ( V_249 -> V_373 - V_414 ) ;
#endif
}
#endif
#endif
}
void T_17 F_383 ( int V_229 , unsigned long * V_382 ,
unsigned long V_373 , unsigned long * V_383 )
{
T_8 * V_249 = F_247 ( V_229 ) ;
V_249 -> V_321 = V_229 ;
V_249 -> V_373 = V_373 ;
F_364 ( V_249 , V_382 , V_383 ) ;
F_377 ( V_249 ) ;
#ifdef F_378
F_20 ( V_348 L_67 ,
V_229 , ( unsigned long ) V_249 ,
( unsigned long ) V_249 -> V_410 ) ;
#endif
F_369 ( V_249 , V_382 , V_383 ) ;
}
static void T_3 F_384 ( void )
{
unsigned int V_296 ;
unsigned int V_415 = 0 ;
F_385 (node, node_possible_map)
V_415 = V_296 ;
V_416 = V_415 + 1 ;
}
static inline void F_384 ( void )
{
}
void T_3 F_386 ( unsigned int V_229 , unsigned long V_84 ,
unsigned long V_85 )
{
int V_28 ;
F_338 ( V_349 , L_68 ,
L_69
L_70 ,
V_229 , V_84 , V_85 ,
V_350 , V_417 ) ;
F_387 ( & V_84 , & V_85 ) ;
for ( V_28 = 0 ; V_28 < V_350 ; V_28 ++ ) {
if ( V_351 [ V_28 ] . V_229 != V_229 )
continue;
if ( V_84 >= V_351 [ V_28 ] . V_84 &&
V_85 <= V_351 [ V_28 ] . V_85 )
return;
if ( V_84 <= V_351 [ V_28 ] . V_85 &&
V_85 > V_351 [ V_28 ] . V_85 ) {
V_351 [ V_28 ] . V_85 = V_85 ;
return;
}
if ( V_84 < V_351 [ V_28 ] . V_84 &&
V_85 >= V_351 [ V_28 ] . V_84 ) {
V_351 [ V_28 ] . V_84 = V_84 ;
return;
}
}
if ( V_28 >= V_417 ) {
F_20 ( V_418 L_71 ,
V_417 ) ;
return;
}
V_351 [ V_28 ] . V_229 = V_229 ;
V_351 [ V_28 ] . V_84 = V_84 ;
V_351 [ V_28 ] . V_85 = V_85 ;
V_350 = V_28 + 1 ;
}
void T_3 F_388 ( unsigned int V_229 , unsigned long V_84 ,
unsigned long V_85 )
{
int V_28 , V_307 ;
int V_419 = 0 ;
F_20 ( V_348 L_72 ,
V_229 , V_84 , V_85 ) ;
F_344 (i, nid) {
if ( V_351 [ V_28 ] . V_84 >= V_84 &&
V_351 [ V_28 ] . V_85 <= V_85 ) {
V_351 [ V_28 ] . V_84 = 0 ;
V_351 [ V_28 ] . V_85 = 0 ;
V_419 = 1 ;
continue;
}
if ( V_351 [ V_28 ] . V_84 < V_84 &&
V_351 [ V_28 ] . V_85 > V_84 ) {
unsigned long V_420 = V_351 [ V_28 ] . V_85 ;
V_351 [ V_28 ] . V_85 = V_84 ;
if ( V_420 > V_85 )
F_386 ( V_229 , V_85 , V_420 ) ;
continue;
}
if ( V_351 [ V_28 ] . V_84 >= V_84 &&
V_351 [ V_28 ] . V_85 > V_85 &&
V_351 [ V_28 ] . V_84 < V_85 ) {
V_351 [ V_28 ] . V_84 = V_85 ;
continue;
}
}
if ( ! V_419 )
return;
for ( V_28 = V_350 - 1 ; V_28 > 0 ; V_28 -- ) {
if ( V_351 [ V_28 ] . V_229 != V_229 )
continue;
if ( V_351 [ V_28 ] . V_85 )
continue;
for ( V_307 = V_28 ; V_307 < V_350 - 1 ; V_307 ++ )
memcpy ( & V_351 [ V_307 ] , & V_351 [ V_307 + 1 ] ,
sizeof( V_351 [ V_307 ] ) ) ;
V_307 = V_350 - 1 ;
memset ( & V_351 [ V_307 ] , 0 , sizeof( V_351 [ V_307 ] ) ) ;
V_350 -- ;
}
}
void T_3 F_389 ( void )
{
memset ( V_351 , 0 , sizeof( V_351 ) ) ;
V_350 = 0 ;
}
static int T_3 F_390 ( const void * V_421 , const void * V_422 )
{
struct V_423 * V_424 = (struct V_423 * ) V_421 ;
struct V_423 * V_425 = (struct V_423 * ) V_422 ;
if ( V_424 -> V_84 > V_425 -> V_84 )
return 1 ;
if ( V_424 -> V_84 < V_425 -> V_84 )
return - 1 ;
return 0 ;
}
void T_3 F_391 ( void )
{
F_392 ( V_351 , ( T_7 ) V_350 ,
sizeof( struct V_423 ) ,
F_390 , NULL ) ;
}
unsigned long T_3 F_393 ( void )
{
unsigned long V_426 = 0 , V_427 = 0 ;
int V_428 = - 1 ;
int V_28 ;
F_344 (i, MAX_NUMNODES) {
int V_229 = V_351 [ V_28 ] . V_229 ;
unsigned long V_366 = V_351 [ V_28 ] . V_84 ;
unsigned long V_231 = V_351 [ V_28 ] . V_85 ;
unsigned long V_429 ;
if ( ! V_366 || V_428 < 0 || V_428 == V_229 ) {
V_428 = V_229 ;
V_427 = V_231 ;
continue;
}
V_429 = ~ ( ( 1 << F_394 ( V_366 ) ) - 1 ) ;
while ( V_429 && V_427 <= ( V_366 & ( V_429 << 1 ) ) )
V_429 <<= 1 ;
V_426 |= V_429 ;
}
return ~ V_426 + 1 ;
}
static unsigned long T_3 F_395 ( int V_229 )
{
int V_28 ;
unsigned long V_430 = V_431 ;
F_344 (i, nid)
V_430 = V_141 ( V_430 , V_351 [ V_28 ] . V_84 ) ;
if ( V_430 == V_431 ) {
F_20 ( V_188
L_73 , V_229 ) ;
return 0 ;
}
return V_430 ;
}
unsigned long T_3 F_396 ( void )
{
return F_395 ( V_305 ) ;
}
static unsigned long T_3 F_397 ( void )
{
int V_28 ;
unsigned long V_385 = 0 ;
for ( V_28 = 0 ; V_28 < V_350 ; V_28 ++ ) {
unsigned long V_96 = V_351 [ V_28 ] . V_85 -
V_351 [ V_28 ] . V_84 ;
V_385 += V_96 ;
if ( V_96 )
F_398 ( V_351 [ V_28 ] . V_229 , V_158 ) ;
}
return V_385 ;
}
static void T_3 F_399 ( unsigned long * V_432 )
{
int V_28 , V_229 ;
unsigned long V_433 ;
unsigned long V_434 , V_435 ;
T_5 V_436 = V_157 [ V_158 ] ;
unsigned long V_385 = F_397 () ;
int V_437 = F_280 ( V_157 [ V_158 ] ) ;
if ( V_438 ) {
unsigned long V_439 ;
V_438 =
F_309 ( V_438 , V_412 ) ;
V_439 = V_385 - V_438 ;
V_440 = F_303 ( V_440 , V_439 ) ;
}
if ( ! V_440 )
goto V_21;
F_358 () ;
V_433 = V_371 [ V_372 ] ;
V_216:
V_434 = V_440 / V_437 ;
F_272 (nid, N_HIGH_MEMORY) {
if ( V_440 < V_434 )
V_434 = V_440 / V_437 ;
V_435 = V_434 ;
F_344 (i, nid) {
unsigned long V_84 , V_85 ;
unsigned long V_354 ;
V_84 = F_303 ( V_351 [ V_28 ] . V_84 ,
V_376 [ V_229 ] ) ;
V_85 = V_351 [ V_28 ] . V_85 ;
if ( V_84 >= V_85 )
continue;
if ( V_84 < V_433 ) {
unsigned long V_441 ;
V_441 = V_141 ( V_85 , V_433 )
- V_84 ;
V_435 -= V_141 ( V_441 ,
V_435 ) ;
V_440 -= V_141 ( V_441 ,
V_440 ) ;
if ( V_85 <= V_433 ) {
V_376 [ V_229 ] = V_85 ;
continue;
}
V_84 = V_433 ;
}
V_354 = V_85 - V_84 ;
if ( V_354 > V_435 )
V_354 = V_435 ;
V_376 [ V_229 ] = V_84 + V_354 ;
V_440 -= V_141 ( V_440 ,
V_354 ) ;
V_435 -= V_354 ;
if ( ! V_435 )
break;
}
}
V_437 -- ;
if ( V_437 && V_440 > V_437 )
goto V_216;
for ( V_229 = 0 ; V_229 < V_305 ; V_229 ++ )
V_376 [ V_229 ] =
F_309 ( V_376 [ V_229 ] , V_412 ) ;
V_21:
V_157 [ V_158 ] = V_436 ;
}
static void F_400 ( T_8 * V_249 )
{
#ifdef F_249
enum V_193 V_193 ;
for ( V_193 = 0 ; V_193 <= V_196 ; V_193 ++ ) {
struct V_11 * V_11 = & V_249 -> V_251 [ V_193 ] ;
if ( V_11 -> V_235 )
F_398 ( F_104 ( V_11 ) , V_442 ) ;
}
#endif
}
void T_3 F_401 ( unsigned long * V_106 )
{
unsigned long V_229 ;
int V_28 ;
F_391 () ;
memset ( V_371 , 0 ,
sizeof( V_371 ) ) ;
memset ( V_370 , 0 ,
sizeof( V_370 ) ) ;
V_371 [ 0 ] = F_396 () ;
V_370 [ 0 ] = V_106 [ 0 ] ;
for ( V_28 = 1 ; V_28 < V_273 ; V_28 ++ ) {
if ( V_28 == V_369 )
continue;
V_371 [ V_28 ] =
V_370 [ V_28 - 1 ] ;
V_370 [ V_28 ] =
F_303 ( V_106 [ V_28 ] , V_371 [ V_28 ] ) ;
}
V_371 [ V_369 ] = 0 ;
V_370 [ V_369 ] = 0 ;
memset ( V_376 , 0 , sizeof( V_376 ) ) ;
F_399 ( V_376 ) ;
F_20 ( L_74 ) ;
for ( V_28 = 0 ; V_28 < V_273 ; V_28 ++ ) {
if ( V_28 == V_369 )
continue;
F_20 ( L_75 , V_330 [ V_28 ] ) ;
if ( V_371 [ V_28 ] ==
V_370 [ V_28 ] )
F_20 ( L_76 ) ;
else
F_20 ( L_77 ,
V_371 [ V_28 ] ,
V_370 [ V_28 ] ) ;
}
F_20 ( L_78 ) ;
for ( V_28 = 0 ; V_28 < V_305 ; V_28 ++ ) {
if ( V_376 [ V_28 ] )
F_20 ( L_79 , V_28 , V_376 [ V_28 ] ) ;
}
F_20 ( L_80 , V_350 ) ;
for ( V_28 = 0 ; V_28 < V_350 ; V_28 ++ )
F_20 ( L_81 , V_351 [ V_28 ] . V_229 ,
V_351 [ V_28 ] . V_84 ,
V_351 [ V_28 ] . V_85 ) ;
F_402 () ;
F_384 () ;
F_279 (nid) {
T_8 * V_249 = F_247 ( V_229 ) ;
F_383 ( V_229 , NULL ,
F_395 ( V_229 ) , NULL ) ;
if ( V_249 -> V_250 )
F_398 ( V_229 , V_158 ) ;
F_400 ( V_249 ) ;
}
}
static int T_3 F_403 ( char * V_30 , unsigned long * V_443 )
{
unsigned long long V_444 ;
if ( ! V_30 )
return - V_283 ;
V_444 = F_404 ( V_30 , & V_30 ) ;
* V_443 = V_444 >> V_340 ;
F_2 ( ( V_444 >> V_340 ) > V_431 ) ;
return 0 ;
}
static int T_3 F_405 ( char * V_30 )
{
return F_403 ( V_30 , & V_440 ) ;
}
static int T_3 F_406 ( char * V_30 )
{
return F_403 ( V_30 , & V_438 ) ;
}
void T_3 F_407 ( unsigned long V_445 )
{
V_399 = V_445 ;
}
void T_3 F_408 ( unsigned long * V_382 )
{
F_383 ( 0 , V_382 ,
F_409 ( V_446 ) >> V_340 , NULL ) ;
}
static int F_410 ( struct V_447 * V_448 ,
unsigned long V_449 , void * V_450 )
{
int V_101 = ( unsigned long ) V_450 ;
if ( V_449 == V_451 || V_449 == V_452 ) {
F_116 ( V_101 ) ;
F_411 ( V_101 ) ;
F_412 ( V_101 ) ;
}
return V_453 ;
}
void T_3 F_413 ( void )
{
F_414 ( F_410 , 0 ) ;
}
static void F_415 ( void )
{
struct V_343 * V_249 ;
unsigned long V_454 = 0 ;
enum V_193 V_28 , V_307 ;
F_416 (pgdat) {
for ( V_28 = 0 ; V_28 < V_273 ; V_28 ++ ) {
struct V_11 * V_11 = V_249 -> V_251 + V_28 ;
unsigned long F_303 = 0 ;
for ( V_307 = V_28 ; V_307 < V_273 ; V_307 ++ ) {
if ( V_11 -> V_145 [ V_307 ] > F_303 )
F_303 = V_11 -> V_145 [ V_307 ] ;
}
F_303 += F_238 ( V_11 ) ;
if ( F_303 > V_11 -> V_235 )
F_303 = V_11 -> V_235 ;
V_454 += F_303 ;
}
}
V_455 = V_454 ;
}
static void F_417 ( void )
{
struct V_343 * V_249 ;
enum V_193 V_307 , V_456 ;
F_416 (pgdat) {
for ( V_307 = 0 ; V_307 < V_273 ; V_307 ++ ) {
struct V_11 * V_11 = V_249 -> V_251 + V_307 ;
unsigned long V_235 = V_11 -> V_235 ;
V_11 -> V_145 [ V_307 ] = 0 ;
V_456 = V_307 ;
while ( V_456 ) {
struct V_11 * V_457 ;
V_456 -- ;
if ( V_458 [ V_456 ] < 1 )
V_458 [ V_456 ] = 1 ;
V_457 = V_249 -> V_251 + V_456 ;
V_457 -> V_145 [ V_307 ] = V_235 /
V_458 [ V_456 ] ;
V_235 += V_457 -> V_235 ;
}
}
}
F_415 () ;
}
void F_418 ( void )
{
unsigned long V_459 = V_460 >> ( V_340 - 10 ) ;
unsigned long V_461 = 0 ;
struct V_11 * V_11 ;
unsigned long V_51 ;
F_419 (zone) {
if ( ! F_420 ( V_11 ) )
V_461 += V_11 -> V_235 ;
}
F_419 (zone) {
T_15 V_302 ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
V_302 = ( T_15 ) V_459 * V_11 -> V_235 ;
F_421 ( V_302 , V_461 ) ;
if ( F_420 ( V_11 ) ) {
int V_462 ;
V_462 = V_11 -> V_235 / 1024 ;
if ( V_462 < V_463 )
V_462 = V_463 ;
if ( V_462 > 128 )
V_462 = 128 ;
V_11 -> V_112 [ V_464 ] = V_462 ;
} else {
V_11 -> V_112 [ V_464 ] = V_302 ;
}
V_11 -> V_112 [ V_465 ] = F_254 ( V_11 ) + ( V_302 >> 2 ) ;
V_11 -> V_112 [ V_466 ] = F_254 ( V_11 ) + ( V_302 >> 1 ) ;
F_308 ( V_11 ) ;
F_131 ( & V_11 -> V_59 , V_51 ) ;
}
F_415 () ;
}
static void T_2 F_422 ( struct V_11 * V_11 )
{
unsigned int V_467 , V_468 ;
V_467 = V_11 -> V_235 >> ( 30 - V_340 ) ;
if ( V_467 )
V_468 = F_423 ( 10 * V_467 ) ;
else
V_468 = 1 ;
V_11 -> V_469 = V_468 ;
}
static void T_2 F_424 ( void )
{
struct V_11 * V_11 ;
F_419 (zone)
F_422 ( V_11 ) ;
}
int T_2 F_425 ( void )
{
unsigned long V_470 ;
V_470 = F_239 () * ( V_68 >> 10 ) ;
V_460 = F_423 ( V_470 * 16 ) ;
if ( V_460 < 128 )
V_460 = 128 ;
if ( V_460 > 65536 )
V_460 = 65536 ;
F_418 () ;
F_426 () ;
F_417 () ;
F_424 () ;
return 0 ;
}
int F_427 ( T_9 * V_286 , int V_287 ,
void T_10 * V_288 , T_7 * V_289 , T_11 * V_290 )
{
F_428 ( V_286 , V_287 , V_288 , V_289 , V_290 ) ;
if ( V_287 )
F_418 () ;
return 0 ;
}
int F_429 ( T_9 * V_286 , int V_287 ,
void T_10 * V_288 , T_7 * V_289 , T_11 * V_290 )
{
struct V_11 * V_11 ;
int V_471 ;
V_471 = F_430 ( V_286 , V_287 , V_288 , V_289 , V_290 ) ;
if ( V_471 )
return V_471 ;
F_419 (zone)
V_11 -> V_402 = ( V_11 -> V_235 *
V_403 ) / 100 ;
return 0 ;
}
int F_431 ( T_9 * V_286 , int V_287 ,
void T_10 * V_288 , T_7 * V_289 , T_11 * V_290 )
{
struct V_11 * V_11 ;
int V_471 ;
V_471 = F_430 ( V_286 , V_287 , V_288 , V_289 , V_290 ) ;
if ( V_471 )
return V_471 ;
F_419 (zone)
V_11 -> V_404 = ( V_11 -> V_235 *
V_405 ) / 100 ;
return 0 ;
}
int F_432 ( T_9 * V_286 , int V_287 ,
void T_10 * V_288 , T_7 * V_289 , T_11 * V_290 )
{
F_430 ( V_286 , V_287 , V_288 , V_289 , V_290 ) ;
F_417 () ;
return 0 ;
}
int F_433 ( T_9 * V_286 , int V_287 ,
void T_10 * V_288 , T_7 * V_289 , T_11 * V_290 )
{
struct V_11 * V_11 ;
unsigned int V_101 ;
int V_12 ;
V_12 = F_430 ( V_286 , V_287 , V_288 , V_289 , V_290 ) ;
if ( ! V_287 || ( V_12 == - V_283 ) )
return V_12 ;
F_117 (zone) {
F_290 (cpu) {
unsigned long V_74 ;
V_74 = V_11 -> V_235 / V_341 ;
F_326 (
F_118 ( V_11 -> V_104 , V_101 ) , V_74 ) ;
}
}
return 0 ;
}
static int T_3 F_434 ( char * V_120 )
{
if ( ! V_120 )
return 0 ;
V_472 = F_435 ( V_120 , & V_120 , 0 ) ;
return 1 ;
}
void * T_3 F_436 ( const char * V_473 ,
unsigned long V_474 ,
unsigned long V_475 ,
int V_476 ,
int V_51 ,
unsigned int * V_477 ,
unsigned int * V_478 ,
unsigned long V_357 )
{
unsigned long long F_303 = V_357 ;
unsigned long V_479 , V_76 ;
void * V_286 = NULL ;
if ( ! V_475 ) {
V_475 = V_400 ;
V_475 += ( 1UL << ( 20 - V_340 ) ) - 1 ;
V_475 >>= 20 - V_340 ;
V_475 <<= 20 - V_340 ;
if ( V_476 > V_340 )
V_475 >>= ( V_476 - V_340 ) ;
else
V_475 <<= ( V_340 - V_476 ) ;
if ( F_6 ( V_51 & V_480 ) ) {
F_2 ( ! ( V_51 & V_481 ) ) ;
if ( ! ( V_475 >> * V_477 ) ) {
V_475 = 1UL << * V_477 ;
F_102 ( ! V_475 ) ;
}
} else if ( F_6 ( ( V_475 * V_474 ) < V_68 ) )
V_475 = V_68 / V_474 ;
}
V_475 = F_437 ( V_475 ) ;
if ( F_303 == 0 ) {
F_303 = ( ( unsigned long long ) V_401 << V_340 ) >> 4 ;
F_421 ( F_303 , V_474 ) ;
}
if ( V_475 > F_303 )
V_475 = F_303 ;
V_479 = F_438 ( V_475 ) ;
do {
V_76 = V_474 << V_479 ;
if ( V_51 & V_481 )
V_286 = F_439 ( V_76 ) ;
else if ( V_472 )
V_286 = F_440 ( V_76 , V_482 , V_483 ) ;
else {
if ( F_231 ( V_76 ) < V_40 ) {
V_286 = F_230 ( V_76 , V_482 ) ;
F_441 ( V_286 , V_76 , 1 , V_482 ) ;
}
}
} while ( ! V_286 && V_76 > V_68 && -- V_479 );
if ( ! V_286 )
F_442 ( L_82 , V_473 ) ;
F_20 ( V_484 L_83 ,
V_473 ,
( 1UL << V_479 ) ,
F_438 ( V_76 ) - V_340 ,
V_76 ) ;
if ( V_477 )
* V_477 = V_479 ;
if ( V_478 )
* V_478 = ( 1 << V_479 ) - 1 ;
return V_286 ;
}
static inline unsigned long * F_443 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef F_444
return F_445 ( V_14 ) -> V_390 ;
#else
return V_11 -> V_390 ;
#endif
}
static inline int F_446 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef F_444
V_14 &= ( V_485 - 1 ) ;
return ( V_14 >> V_90 ) * V_389 ;
#else
V_14 = V_14 - V_11 -> V_15 ;
return ( V_14 >> V_90 ) * V_389 ;
#endif
}
unsigned long F_447 ( struct V_5 * V_5 ,
int V_486 , int V_487 )
{
struct V_11 * V_11 ;
unsigned long * V_488 ;
unsigned long V_14 , V_489 ;
unsigned long V_51 = 0 ;
unsigned long V_490 = 1 ;
V_11 = F_14 ( V_5 ) ;
V_14 = F_9 ( V_5 ) ;
V_488 = F_443 ( V_11 , V_14 ) ;
V_489 = F_446 ( V_11 , V_14 ) ;
for (; V_486 <= V_487 ; V_486 ++ , V_490 <<= 1 )
if ( F_165 ( V_489 + V_486 , V_488 ) )
V_51 |= V_490 ;
return V_51 ;
}
void F_7 ( struct V_5 * V_5 , unsigned long V_51 ,
int V_486 , int V_487 )
{
struct V_11 * V_11 ;
unsigned long * V_488 ;
unsigned long V_14 , V_489 ;
unsigned long V_490 = 1 ;
V_11 = F_14 ( V_5 ) ;
V_14 = F_9 ( V_5 ) ;
V_488 = F_443 ( V_11 , V_14 ) ;
V_489 = F_446 ( V_11 , V_14 ) ;
F_38 ( V_14 < V_11 -> V_15 ) ;
F_38 ( V_14 >= V_11 -> V_15 + V_11 -> V_16 ) ;
for (; V_486 <= V_487 ; V_486 ++ , V_490 <<= 1 )
if ( V_51 & V_490 )
F_448 ( V_489 + V_486 , V_488 ) ;
else
F_449 ( V_489 + V_486 , V_488 ) ;
}
static int
F_450 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_54 )
{
unsigned long V_14 , V_491 , V_492 ;
if ( F_170 ( V_11 ) == V_369 )
return true ;
if ( F_86 ( V_5 ) == V_110 )
return true ;
V_14 = F_9 ( V_5 ) ;
for ( V_492 = 0 , V_491 = 0 ; V_491 < V_86 ; V_491 ++ ) {
unsigned long V_493 = V_14 + V_491 ;
if ( ! F_13 ( V_493 ) )
continue;
V_5 = F_107 ( V_493 ) ;
if ( ! F_51 ( V_5 ) ) {
if ( F_49 ( V_5 ) )
V_491 += ( 1 << F_50 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_451 ( V_5 ) )
V_492 ++ ;
if ( V_492 > V_54 )
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
struct V_494 V_105 ;
int V_495 ;
int V_12 = - V_496 ;
V_11 = F_14 ( V_5 ) ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
V_14 = F_9 ( V_5 ) ;
V_105 . V_84 = V_14 ;
V_105 . V_29 = V_86 ;
V_105 . V_497 = 0 ;
V_495 = V_494 ( V_498 , & V_105 ) ;
V_495 = F_454 ( V_495 ) ;
if ( V_495 )
goto V_21;
if ( F_450 ( V_11 , V_5 , V_105 . V_497 ) )
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
void F_455 ( struct V_5 * V_5 )
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
F_456 ( unsigned long V_84 , unsigned long V_85 )
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
#ifdef F_457
F_20 ( V_484 L_84 ,
V_14 , 1 << V_27 , V_85 ) ;
#endif
F_54 ( & V_5 -> V_41 ) ;
F_44 ( V_5 ) ;
V_11 -> V_42 [ V_27 ] . V_43 -- ;
F_70 ( V_11 , V_67 ,
- ( 1UL << V_27 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_316 ( ( V_5 + V_28 ) ) ;
V_14 += ( 1 << V_27 ) ;
}
F_131 ( & V_11 -> V_59 , V_51 ) ;
}
bool F_458 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_14 ( V_5 ) ;
unsigned long V_14 = F_9 ( V_5 ) ;
unsigned long V_51 ;
int V_27 ;
F_124 ( & V_11 -> V_59 , V_51 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
struct V_5 * V_499 = V_5 - ( V_14 & ( ( 1 << V_27 ) - 1 ) ) ;
if ( F_49 ( V_499 ) && F_50 ( V_499 ) >= V_27 )
break;
}
F_131 ( & V_11 -> V_59 , V_51 ) ;
return V_27 < V_40 ;
}
static void F_459 ( unsigned long V_51 )
{
const char * V_500 = L_85 ;
unsigned long V_429 ;
int V_28 ;
F_20 ( V_22 L_86 , V_51 ) ;
V_51 &= ( 1UL << V_501 ) - 1 ;
for ( V_28 = 0 ; V_502 [ V_28 ] . V_253 && V_51 ; V_28 ++ ) {
V_429 = V_502 [ V_28 ] . V_429 ;
if ( ( V_51 & V_429 ) != V_429 )
continue;
V_51 &= ~ V_429 ;
F_20 ( L_87 , V_500 , V_502 [ V_28 ] . V_253 ) ;
V_500 = L_88 ;
}
if ( V_51 )
F_20 ( L_89 , V_500 , V_51 ) ;
F_20 ( L_90 ) ;
}
void F_21 ( struct V_5 * V_5 )
{
F_20 ( V_22
L_91 ,
V_5 , F_62 ( & V_5 -> V_50 ) , F_61 ( V_5 ) ,
V_5 -> V_49 , V_5 -> V_352 ) ;
F_459 ( V_5 -> V_51 ) ;
F_460 ( V_5 ) ;
}
