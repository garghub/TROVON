void F_1 ( int V_1 , unsigned long V_2 )
{
F_2 ( & V_3 ) ;
V_4 [ V_1 ] += V_2 ;
F_3 ( & V_3 ) ;
}
static void F_4 ( int V_1 )
{
V_4 [ V_1 ] -- ;
V_4 [ V_1 - 1 ] += V_5 ;
}
void F_5 ( struct V_6 * V_7 )
{
F_6 ( V_7 , L_1 ,
V_4 [ V_8 ] << 2 ) ;
#if F_7 ( V_9 ) || F_7 ( V_10 )
F_6 ( V_7 , L_2 ,
V_4 [ V_11 ] << 11 ) ;
#else
F_6 ( V_7 , L_3 ,
V_4 [ V_11 ] << 12 ) ;
#endif
#ifdef V_9
if ( V_12 )
F_6 ( V_7 , L_4 ,
V_4 [ V_13 ] << 20 ) ;
#endif
}
static inline void F_4 ( int V_1 ) { }
static inline unsigned long F_8 ( void )
{
return F_9 ( V_14 ) >> V_15 ;
}
static inline unsigned long F_10 ( void )
{
return F_9 ( F_11 ( V_16 , V_17 ) ) >> V_15 ;
}
static inline int
F_12 ( unsigned long V_18 , unsigned long V_19 , unsigned long V_20 )
{
return V_18 >= V_19 && V_18 < V_20 ;
}
void F_13 ( void * V_21 , unsigned int V_22 )
{
void * V_23 = V_21 + V_22 - 1 ;
F_14 () ;
for (; V_21 < V_23 ; V_21 += V_24 . V_25 )
F_15 ( V_21 ) ;
F_15 ( V_23 ) ;
F_14 () ;
}
static void F_16 ( void * V_26 )
{
unsigned long V_27 = ( unsigned long ) V_26 ;
F_17 () ;
if ( V_27 && V_24 . V_28 >= 4 )
F_18 () ;
}
static void F_19 ( unsigned long V_27 )
{
F_20 ( F_21 () ) ;
F_22 ( F_16 , ( void * ) V_27 , 1 ) ;
}
static void F_23 ( void * V_26 )
{
F_17 () ;
}
static void F_24 ( unsigned long V_19 , int V_29 , int V_27 )
{
unsigned int V_30 , V_1 ;
unsigned long V_18 ;
F_20 ( F_21 () ) ;
F_25 ( F_26 ( V_19 ) != V_19 ) ;
F_22 ( F_23 , NULL , 1 ) ;
if ( ! V_27 )
return;
for ( V_30 = 0 , V_18 = V_19 ; V_30 < V_29 ; V_30 ++ , V_18 += V_31 ) {
T_1 * V_32 = F_27 ( V_18 , & V_1 ) ;
if ( V_32 && ( F_28 ( * V_32 ) & V_33 ) )
F_13 ( ( void * ) V_18 , V_31 ) ;
}
}
static void F_29 ( unsigned long * V_19 , int V_29 , int V_27 ,
int V_34 , struct V_35 * * V_2 )
{
unsigned int V_30 , V_1 ;
unsigned long V_36 = V_27 && V_29 >= 1024 ;
F_20 ( F_21 () ) ;
F_22 ( F_16 , ( void * ) V_36 , 1 ) ;
if ( ! V_27 || V_36 )
return;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
unsigned long V_18 ;
T_1 * V_32 ;
if ( V_34 & V_37 )
V_18 = ( unsigned long ) F_30 ( V_2 [ V_30 ] ) ;
else
V_18 = V_19 [ V_30 ] ;
V_32 = F_27 ( V_18 , & V_1 ) ;
if ( V_32 && ( F_28 ( * V_32 ) & V_33 ) )
F_13 ( ( void * ) V_18 , V_31 ) ;
}
}
static inline T_2 F_31 ( T_2 V_38 , unsigned long V_39 ,
unsigned long V_40 )
{
T_2 V_41 = F_32 ( 0 ) ;
#ifdef F_33
if ( V_42 && F_12 ( V_40 , V_43 >> V_15 , V_44 >> V_15 ) )
F_34 ( V_41 ) |= V_45 ;
#endif
if ( F_12 ( V_39 , ( unsigned long ) V_14 , ( unsigned long ) V_46 ) )
F_34 ( V_41 ) |= V_45 ;
if ( F_12 ( V_40 , F_9 ( V_47 ) >> V_15 ,
F_9 ( V_48 ) >> V_15 ) )
F_34 ( V_41 ) |= V_49 ;
#if F_7 ( V_9 ) && F_7 ( V_50 )
if ( V_51 &&
F_12 ( V_39 , ( unsigned long ) V_14 ,
( unsigned long ) V_52 ) ) {
unsigned int V_1 ;
if ( F_27 ( V_39 , & V_1 ) && ( V_1 != V_8 ) )
F_34 ( V_41 ) |= V_49 ;
}
#endif
V_38 = F_32 ( F_34 ( V_38 ) & ~ F_34 ( V_41 ) ) ;
return V_38 ;
}
T_1 * F_27 ( unsigned long V_39 , unsigned int * V_1 )
{
T_3 * V_53 = F_35 ( V_39 ) ;
T_4 * V_54 ;
T_5 * V_55 ;
* V_1 = V_56 ;
if ( F_36 ( * V_53 ) )
return NULL ;
V_54 = F_37 ( V_53 , V_39 ) ;
if ( F_38 ( * V_54 ) )
return NULL ;
* V_1 = V_13 ;
if ( F_39 ( * V_54 ) || ! F_40 ( * V_54 ) )
return ( T_1 * ) V_54 ;
V_55 = F_41 ( V_54 , V_39 ) ;
if ( F_42 ( * V_55 ) )
return NULL ;
* V_1 = V_11 ;
if ( F_43 ( * V_55 ) || ! F_44 ( * V_55 ) )
return ( T_1 * ) V_55 ;
* V_1 = V_8 ;
return F_45 ( V_55 , V_39 ) ;
}
T_6 F_46 ( void * V_57 )
{
unsigned long V_58 = ( unsigned long ) V_57 ;
T_6 V_59 ;
unsigned long V_60 ;
enum V_61 V_1 ;
unsigned long V_62 ;
unsigned long V_63 ;
T_1 * V_32 ;
V_32 = F_27 ( V_58 , & V_1 ) ;
F_20 ( ! V_32 ) ;
V_62 = F_47 ( V_1 ) ;
V_63 = F_48 ( V_1 ) ;
V_60 = V_58 & ~ V_63 ;
V_59 = F_49 ( * V_32 ) << V_15 ;
return ( V_59 | V_60 ) ;
}
static void F_50 ( T_1 * V_64 , unsigned long V_39 , T_1 V_32 )
{
F_51 ( V_64 , V_32 ) ;
#ifdef F_52
if ( ! V_65 ) {
struct V_35 * V_35 ;
F_53 (page, &pgd_list, lru) {
T_3 * V_53 ;
T_4 * V_54 ;
T_5 * V_55 ;
V_53 = ( T_3 * ) F_30 ( V_35 ) + F_54 ( V_39 ) ;
V_54 = F_37 ( V_53 , V_39 ) ;
V_55 = F_41 ( V_54 , V_39 ) ;
F_51 ( ( T_1 * ) V_55 , V_32 ) ;
}
}
#endif
}
static int
F_55 ( T_1 * V_64 , unsigned long V_39 ,
struct V_66 * V_67 )
{
unsigned long V_68 , V_29 , V_63 , V_62 , V_18 , V_40 ;
T_1 V_69 , V_70 , * V_71 ;
T_2 V_72 , V_73 , V_74 ;
int V_30 , V_75 = 1 ;
enum V_61 V_1 ;
if ( V_67 -> V_76 )
return 1 ;
F_2 ( & V_3 ) ;
V_71 = F_27 ( V_39 , & V_1 ) ;
if ( V_71 != V_64 )
goto V_77;
switch ( V_1 ) {
case V_11 :
#ifdef V_9
case V_13 :
#endif
V_62 = F_47 ( V_1 ) ;
V_63 = F_48 ( V_1 ) ;
break;
default:
V_75 = - V_78 ;
goto V_77;
}
V_68 = ( V_39 + V_62 ) & V_63 ;
V_29 = ( V_68 - V_39 ) >> V_15 ;
if ( V_29 < V_67 -> V_29 )
V_67 -> V_29 = V_29 ;
V_70 = * V_64 ;
V_72 = V_74 = F_56 ( V_70 ) ;
F_34 ( V_74 ) &= ~ F_34 ( V_67 -> V_79 ) ;
F_34 ( V_74 ) |= F_34 ( V_67 -> V_80 ) ;
if ( F_34 ( V_74 ) & V_33 )
F_34 ( V_74 ) |= V_81 | V_82 ;
else
F_34 ( V_74 ) &= ~ ( V_81 | V_82 ) ;
V_74 = F_57 ( V_74 ) ;
V_40 = F_49 ( V_70 ) + ( ( V_39 & ( V_62 - 1 ) ) >> V_15 ) ;
V_67 -> V_40 = V_40 ;
V_73 = F_31 ( V_74 , V_39 , V_40 ) ;
V_18 = V_39 & V_63 ;
V_40 = F_49 ( V_70 ) ;
for ( V_30 = 0 ; V_30 < ( V_62 >> V_15 ) ; V_30 ++ , V_18 += V_31 , V_40 ++ ) {
T_2 V_83 = F_31 ( V_74 , V_18 , V_40 ) ;
if ( F_34 ( V_83 ) != F_34 ( V_73 ) )
goto V_77;
}
if ( F_34 ( V_73 ) == F_34 ( V_72 ) ) {
V_75 = 0 ;
goto V_77;
}
if ( V_39 == ( V_39 & V_63 ) && V_67 -> V_29 == ( V_62 >> V_15 ) ) {
V_69 = F_58 ( F_49 ( V_70 ) , V_73 ) ;
F_50 ( V_64 , V_39 , V_69 ) ;
V_67 -> V_84 |= V_85 ;
V_75 = 0 ;
}
V_77:
F_3 ( & V_3 ) ;
return V_75 ;
}
int F_59 ( T_1 * V_64 , unsigned long V_39 , T_1 * V_86 )
{
unsigned long V_40 , V_87 = 1 ;
unsigned int V_30 , V_1 ;
T_1 * V_71 ;
T_2 V_88 ;
struct V_35 * V_89 = F_60 ( V_86 ) ;
F_2 ( & V_3 ) ;
V_71 = F_27 ( V_39 , & V_1 ) ;
if ( V_71 != V_64 ) {
F_3 ( & V_3 ) ;
return 1 ;
}
F_61 ( & V_90 , F_62 ( V_89 ) ) ;
V_88 = F_56 ( F_63 ( * V_64 ) ) ;
F_64 ( F_34 ( V_88 ) & V_91 ) ;
#ifdef V_9
if ( V_1 == V_13 ) {
V_87 = V_92 >> V_15 ;
if ( F_34 ( V_88 ) & V_33 )
F_34 ( V_88 ) |= V_81 ;
else
F_34 ( V_88 ) &= ~ V_81 ;
}
#endif
if ( F_34 ( V_88 ) & V_33 )
F_34 ( V_88 ) |= V_82 ;
else
F_34 ( V_88 ) &= ~ V_82 ;
V_40 = F_49 ( * V_64 ) ;
for ( V_30 = 0 ; V_30 < V_5 ; V_30 ++ , V_40 += V_87 )
F_65 ( & V_86 [ V_30 ] , F_58 ( V_40 , F_57 ( V_88 ) ) ) ;
if ( F_66 ( F_67 ( F_68 ( V_39 ) ) ,
F_67 ( F_68 ( V_39 ) ) + 1 ) )
F_4 ( V_1 ) ;
F_50 ( V_64 , V_39 , F_69 ( V_89 , F_32 ( V_93 ) ) ) ;
F_17 () ;
F_3 ( & V_3 ) ;
return 0 ;
}
static int F_70 ( T_1 * V_64 , unsigned long V_39 )
{
T_1 * V_86 ;
struct V_35 * V_89 ;
if ( ! V_94 )
F_3 ( & V_95 ) ;
V_89 = F_71 ( V_96 | V_97 , 0 ) ;
if ( ! V_94 )
F_2 ( & V_95 ) ;
if ( ! V_89 )
return - V_98 ;
V_86 = ( T_1 * ) F_30 ( V_89 ) ;
if ( F_59 ( V_64 , V_39 , V_86 ) )
F_72 ( V_89 ) ;
return 0 ;
}
static int F_73 ( struct V_66 * V_67 , unsigned long V_21 ,
int V_99 )
{
if ( ! V_99 )
return 0 ;
if ( F_12 ( V_21 , V_100 ,
V_100 + ( V_101 << V_15 ) ) ) {
V_67 -> V_29 = 1 ;
V_67 -> V_40 = F_68 ( V_21 ) >> V_15 ;
return 0 ;
} else {
F_74 ( 1 , V_102 L_5
L_6 , V_21 ,
* V_67 -> V_21 ) ;
return - V_103 ;
}
}
static int F_75 ( struct V_66 * V_67 , int V_99 )
{
unsigned long V_39 ;
int V_75 , V_104 ;
unsigned int V_1 ;
T_1 * V_64 , V_70 ;
if ( V_67 -> V_84 & V_37 ) {
struct V_35 * V_35 = V_67 -> V_2 [ V_67 -> V_105 ] ;
if ( F_76 ( F_77 ( V_35 ) ) )
return 0 ;
V_39 = ( unsigned long ) F_30 ( V_35 ) ;
} else if ( V_67 -> V_84 & V_106 )
V_39 = V_67 -> V_21 [ V_67 -> V_105 ] ;
else
V_39 = * V_67 -> V_21 ;
V_107:
V_64 = F_27 ( V_39 , & V_1 ) ;
if ( ! V_64 )
return F_73 ( V_67 , V_39 , V_99 ) ;
V_70 = * V_64 ;
if ( ! F_28 ( V_70 ) )
return F_73 ( V_67 , V_39 , V_99 ) ;
if ( V_1 == V_8 ) {
T_1 V_69 ;
T_2 V_73 = F_56 ( V_70 ) ;
unsigned long V_40 = F_49 ( V_70 ) ;
F_34 ( V_73 ) &= ~ F_34 ( V_67 -> V_79 ) ;
F_34 ( V_73 ) |= F_34 ( V_67 -> V_80 ) ;
V_73 = F_31 ( V_73 , V_39 , V_40 ) ;
if ( F_34 ( V_73 ) & V_33 )
F_34 ( V_73 ) |= V_82 ;
else
F_34 ( V_73 ) &= ~ V_82 ;
V_69 = F_58 ( V_40 , F_57 ( V_73 ) ) ;
V_67 -> V_40 = V_40 ;
if ( F_28 ( V_70 ) != F_28 ( V_69 ) ) {
F_51 ( V_64 , V_69 ) ;
V_67 -> V_84 |= V_85 ;
}
V_67 -> V_29 = 1 ;
return 0 ;
}
V_75 = F_55 ( V_64 , V_39 , V_67 ) ;
if ( V_75 <= 0 )
return V_75 ;
V_104 = F_70 ( V_64 , V_39 ) ;
if ( ! V_104 ) {
F_78 () ;
goto V_107;
}
return V_104 ;
}
static int F_79 ( struct V_66 * V_67 )
{
struct V_66 V_108 ;
unsigned long V_109 = ( unsigned long ) F_80 ( V_67 -> V_40 << V_15 ) ;
unsigned long V_21 ;
int V_110 ;
if ( ! F_66 ( V_67 -> V_40 , V_67 -> V_40 + 1 ) )
return 0 ;
if ( V_67 -> V_84 & V_37 ) {
struct V_35 * V_35 = V_67 -> V_2 [ V_67 -> V_105 ] ;
if ( F_76 ( F_77 ( V_35 ) ) )
return 0 ;
V_21 = ( unsigned long ) F_30 ( V_35 ) ;
} else if ( V_67 -> V_84 & V_106 )
V_21 = V_67 -> V_21 [ V_67 -> V_105 ] ;
else
V_21 = * V_67 -> V_21 ;
if ( ! ( F_12 ( V_21 , V_100 ,
V_100 + ( V_101 << V_15 ) ) ) ) {
V_108 = * V_67 ;
V_108 . V_21 = & V_109 ;
V_108 . V_84 &= ~ ( V_37 | V_106 ) ;
V_110 = F_81 ( & V_108 , 0 ) ;
if ( V_110 )
return V_110 ;
}
#ifdef V_9
if ( ! F_12 ( V_21 , ( unsigned long ) V_14 , V_16 ) &&
F_12 ( V_67 -> V_40 , F_8 () , F_10 () ) ) {
unsigned long V_111 = ( V_67 -> V_40 << V_15 ) +
V_112 - V_113 ;
V_108 = * V_67 ;
V_108 . V_21 = & V_111 ;
V_108 . V_84 &= ~ ( V_37 | V_106 ) ;
F_81 ( & V_108 , 0 ) ;
}
#endif
return 0 ;
}
static int F_81 ( struct V_66 * V_67 , int V_114 )
{
int V_110 , V_29 = V_67 -> V_29 ;
while ( V_29 ) {
V_67 -> V_29 = V_29 ;
if ( V_67 -> V_84 & ( V_106 | V_37 ) )
V_67 -> V_29 = 1 ;
if ( ! V_94 )
F_2 ( & V_95 ) ;
V_110 = F_75 ( V_67 , V_114 ) ;
if ( ! V_94 )
F_3 ( & V_95 ) ;
if ( V_110 )
return V_110 ;
if ( V_114 ) {
V_110 = F_79 ( V_67 ) ;
if ( V_110 )
return V_110 ;
}
F_20 ( V_67 -> V_29 > V_29 ) ;
V_29 -= V_67 -> V_29 ;
if ( V_67 -> V_84 & ( V_37 | V_106 ) )
V_67 -> V_105 ++ ;
else
* V_67 -> V_21 += V_67 -> V_29 * V_31 ;
}
return 0 ;
}
static inline int F_82 ( T_2 V_115 )
{
return F_34 ( V_115 ) &
( V_116 | V_91 | V_117 | V_118 ) ;
}
static int F_83 ( unsigned long * V_18 , int V_29 ,
T_2 V_80 , T_2 V_79 ,
int V_76 , int V_119 ,
struct V_35 * * V_2 )
{
struct V_66 V_67 ;
int V_110 , V_27 , V_114 ;
unsigned long V_120 = 0 ;
V_80 = F_57 ( V_80 ) ;
V_79 = F_57 ( V_79 ) ;
if ( ! F_34 ( V_80 ) && ! F_34 ( V_79 ) && ! V_76 )
return 0 ;
if ( V_119 & V_106 ) {
int V_30 ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
if ( V_18 [ V_30 ] & ~ V_121 ) {
V_18 [ V_30 ] &= V_121 ;
F_64 ( 1 ) ;
}
}
} else if ( ! ( V_119 & V_37 ) ) {
if ( * V_18 & ~ V_121 ) {
* V_18 &= V_121 ;
F_64 ( 1 ) ;
}
V_120 = * V_18 ;
}
F_84 () ;
F_85 () ;
V_67 . V_21 = V_18 ;
V_67 . V_2 = V_2 ;
V_67 . V_29 = V_29 ;
V_67 . V_80 = V_80 ;
V_67 . V_79 = V_79 ;
V_67 . V_84 = 0 ;
V_67 . V_105 = 0 ;
V_67 . V_76 = V_76 ;
if ( V_119 & ( V_106 | V_37 ) )
V_67 . V_84 |= V_119 ;
V_114 = ( F_34 ( V_80 ) | F_34 ( V_79 ) ) != V_45 ;
V_110 = F_81 ( & V_67 , V_114 ) ;
if ( ! ( V_67 . V_84 & V_85 ) )
goto V_122;
V_27 = F_82 ( V_80 ) ;
if ( ! V_110 && V_123 ) {
if ( V_67 . V_84 & ( V_37 | V_106 ) ) {
F_29 ( V_18 , V_29 , V_27 ,
V_67 . V_84 , V_2 ) ;
} else
F_24 ( V_120 , V_29 , V_27 ) ;
} else
F_19 ( V_27 ) ;
V_122:
return V_110 ;
}
static inline int F_86 ( unsigned long * V_18 , int V_29 ,
T_2 V_124 , int V_125 )
{
return F_83 ( V_18 , V_29 , V_124 , F_32 ( 0 ) , 0 ,
( V_125 ? V_106 : 0 ) , NULL ) ;
}
static inline int F_87 ( unsigned long * V_18 , int V_29 ,
T_2 V_124 , int V_125 )
{
return F_83 ( V_18 , V_29 , F_32 ( 0 ) , V_124 , 0 ,
( V_125 ? V_106 : 0 ) , NULL ) ;
}
static inline int F_88 ( struct V_35 * * V_2 , int V_29 ,
T_2 V_124 )
{
return F_83 ( NULL , V_29 , V_124 , F_32 ( 0 ) , 0 ,
V_37 , V_2 ) ;
}
static inline int F_89 ( struct V_35 * * V_2 , int V_29 ,
T_2 V_124 )
{
return F_83 ( NULL , V_29 , F_32 ( 0 ) , V_124 , 0 ,
V_37 , V_2 ) ;
}
int F_90 ( unsigned long V_18 , int V_29 )
{
return F_86 ( & V_18 , V_29 ,
F_32 ( V_126 ) , 0 ) ;
}
int F_91 ( unsigned long V_18 , int V_29 )
{
int V_110 ;
V_110 = F_92 ( F_68 ( V_18 ) , F_68 ( V_18 ) + V_29 * V_31 ,
V_126 , NULL ) ;
if ( V_110 )
goto V_127;
V_110 = F_90 ( V_18 , V_29 ) ;
if ( V_110 )
goto V_128;
return 0 ;
V_128:
F_93 ( F_68 ( V_18 ) , F_68 ( V_18 ) + V_29 * V_31 ) ;
V_127:
return V_110 ;
}
static int F_94 ( unsigned long * V_18 , int V_129 ,
unsigned long V_130 )
{
int V_30 , V_131 ;
int V_110 ;
for ( V_30 = 0 ; V_30 < V_129 ; V_30 ++ ) {
V_110 = F_92 ( F_68 ( V_18 [ V_30 ] ) , F_68 ( V_18 [ V_30 ] ) + V_31 ,
V_130 , NULL ) ;
if ( V_110 )
goto V_128;
}
V_110 = F_86 ( V_18 , V_129 ,
F_32 ( V_126 ) , 1 ) ;
if ( ! V_110 && V_130 == V_132 )
V_110 = F_83 ( V_18 , V_129 ,
F_32 ( V_132 ) ,
F_32 ( V_133 ) ,
0 , V_106 , NULL ) ;
if ( V_110 )
goto V_128;
return 0 ;
V_128:
for ( V_131 = 0 ; V_131 < V_30 ; V_131 ++ )
F_93 ( F_68 ( V_18 [ V_131 ] ) , F_68 ( V_18 [ V_131 ] ) + V_31 ) ;
return V_110 ;
}
int F_95 ( unsigned long * V_18 , int V_129 )
{
return F_94 ( V_18 , V_129 , V_126 ) ;
}
int F_96 ( unsigned long * V_18 , int V_129 )
{
return F_94 ( V_18 , V_129 , V_132 ) ;
}
int F_97 ( unsigned long V_18 , int V_29 )
{
int V_110 ;
unsigned long V_134 = V_18 ;
V_110 = F_86 ( & V_18 , V_29 ,
F_32 ( V_126 ) , 0 ) ;
if ( ! V_110 ) {
V_110 = F_83 ( & V_134 , V_29 ,
F_32 ( V_132 ) ,
F_32 ( V_133 ) ,
0 , 0 , NULL ) ;
}
return V_110 ;
}
int F_98 ( unsigned long V_18 , int V_29 )
{
int V_110 ;
if ( ! V_135 )
return F_91 ( V_18 , V_29 ) ;
V_110 = F_92 ( F_68 ( V_18 ) , F_68 ( V_18 ) + V_29 * V_31 ,
V_132 , NULL ) ;
if ( V_110 )
goto V_127;
V_110 = F_97 ( V_18 , V_29 ) ;
if ( V_110 )
goto V_128;
return 0 ;
V_128:
F_93 ( F_68 ( V_18 ) , F_68 ( V_18 ) + V_29 * V_31 ) ;
V_127:
return V_110 ;
}
int F_99 ( unsigned long V_18 , int V_29 )
{
return F_87 ( & V_18 , V_29 ,
F_32 ( V_133 ) , 0 ) ;
}
int F_100 ( unsigned long V_18 , int V_29 )
{
int V_110 ;
V_110 = F_99 ( V_18 , V_29 ) ;
if ( V_110 )
return V_110 ;
F_93 ( F_68 ( V_18 ) , F_68 ( V_18 ) + V_29 * V_31 ) ;
return 0 ;
}
int F_101 ( unsigned long * V_18 , int V_129 )
{
int V_30 ;
int V_110 ;
V_110 = F_87 ( V_18 , V_129 ,
F_32 ( V_133 ) , 1 ) ;
if ( V_110 )
return V_110 ;
for ( V_30 = 0 ; V_30 < V_129 ; V_30 ++ )
F_93 ( F_68 ( V_18 [ V_30 ] ) , F_68 ( V_18 [ V_30 ] ) + V_31 ) ;
return 0 ;
}
int F_102 ( unsigned long V_18 , int V_29 )
{
if ( ! ( V_136 & V_45 ) )
return 0 ;
return F_87 ( & V_18 , V_29 , F_32 ( V_45 ) , 0 ) ;
}
int F_103 ( unsigned long V_18 , int V_29 )
{
if ( ! ( V_136 & V_45 ) )
return 0 ;
return F_86 ( & V_18 , V_29 , F_32 ( V_45 ) , 0 ) ;
}
int F_104 ( unsigned long V_18 , int V_29 )
{
return F_87 ( & V_18 , V_29 , F_32 ( V_49 ) , 0 ) ;
}
int F_105 ( unsigned long V_18 , int V_29 )
{
return F_86 ( & V_18 , V_29 , F_32 ( V_49 ) , 0 ) ;
}
int F_106 ( unsigned long V_18 , int V_29 )
{
return F_87 ( & V_18 , V_29 , F_32 ( V_33 ) , 0 ) ;
}
int F_107 ( unsigned long V_18 , int V_29 )
{
return F_83 ( & V_18 , V_29 , F_32 ( 0 ) ,
F_32 ( 0 ) , 1 , 0 , NULL ) ;
}
int F_108 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_91 ( V_18 , V_29 ) ;
}
static int F_109 ( struct V_35 * * V_2 , int V_129 ,
unsigned long V_130 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_30 ;
int V_137 ;
int V_110 ;
for ( V_30 = 0 ; V_30 < V_129 ; V_30 ++ ) {
if ( F_77 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_62 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
if ( F_92 ( V_19 , V_20 , V_130 , NULL ) )
goto V_138;
}
V_110 = F_88 ( V_2 , V_129 ,
F_32 ( V_126 ) ) ;
if ( ! V_110 && V_130 == V_132 )
V_110 = F_83 ( NULL , V_129 ,
F_32 ( V_132 ) ,
F_32 ( V_133 ) ,
0 , V_37 , V_2 ) ;
if ( V_110 )
goto V_138;
return 0 ;
V_138:
V_137 = V_30 ;
for ( V_30 = 0 ; V_30 < V_137 ; V_30 ++ ) {
if ( F_77 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_62 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
F_93 ( V_19 , V_20 ) ;
}
return - V_78 ;
}
int F_110 ( struct V_35 * * V_2 , int V_129 )
{
return F_109 ( V_2 , V_129 , V_126 ) ;
}
int F_111 ( struct V_35 * * V_2 , int V_129 )
{
return F_109 ( V_2 , V_129 , V_132 ) ;
}
int F_112 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_100 ( V_18 , V_29 ) ;
}
int F_113 ( struct V_35 * * V_2 , int V_129 )
{
int V_139 ;
unsigned long V_19 ;
unsigned long V_20 ;
int V_30 ;
V_139 = F_89 ( V_2 , V_129 ,
F_32 ( V_133 ) ) ;
if ( V_139 )
return V_139 ;
for ( V_30 = 0 ; V_30 < V_129 ; V_30 ++ ) {
if ( F_77 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_62 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
F_93 ( V_19 , V_20 ) ;
}
return 0 ;
}
int F_114 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_102 ( V_18 , V_29 ) ;
}
int F_115 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_103 ( V_18 , V_29 ) ;
}
int F_116 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_104 ( V_18 , V_29 ) ;
}
int F_117 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_105 ( V_18 , V_29 ) ;
}
static int F_118 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_140 = ( unsigned long ) F_30 ( V_35 ) ;
struct V_66 V_67 = { . V_21 = & V_140 ,
. V_29 = V_29 ,
. V_80 = F_32 ( V_33 | V_49 ) ,
. V_79 = F_32 ( 0 ) ,
. V_84 = 0 } ;
return F_81 ( & V_67 , 0 ) ;
}
static int F_119 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_140 = ( unsigned long ) F_30 ( V_35 ) ;
struct V_66 V_67 = { . V_21 = & V_140 ,
. V_29 = V_29 ,
. V_80 = F_32 ( 0 ) ,
. V_79 = F_32 ( V_33 | V_49 ) ,
. V_84 = 0 } ;
return F_81 ( & V_67 , 0 ) ;
}
void F_120 ( struct V_35 * V_35 , int V_29 , int V_141 )
{
if ( F_77 ( V_35 ) )
return;
if ( ! V_141 ) {
F_121 ( F_30 ( V_35 ) ,
V_29 * V_31 ) ;
}
if ( V_141 )
F_118 ( V_35 , V_29 ) ;
else
F_119 ( V_35 , V_29 ) ;
F_17 () ;
F_122 () ;
}
bool F_123 ( struct V_35 * V_35 )
{
unsigned int V_1 ;
T_1 * V_32 ;
if ( F_77 ( V_35 ) )
return false ;
V_32 = F_27 ( ( unsigned long ) F_30 ( V_35 ) , & V_1 ) ;
return ( F_28 ( * V_32 ) & V_33 ) ;
}
