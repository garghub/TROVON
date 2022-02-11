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
if ( F_12 ( V_40 , F_9 ( ( unsigned long ) V_47 ) >> V_15 ,
F_9 ( ( unsigned long ) V_48 ) >> V_15 ) )
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
static void F_46 ( T_1 * V_57 , unsigned long V_39 , T_1 V_32 )
{
F_47 ( V_57 , V_32 ) ;
#ifdef F_48
if ( ! V_58 ) {
struct V_35 * V_35 ;
F_49 (page, &pgd_list, lru) {
T_3 * V_53 ;
T_4 * V_54 ;
T_5 * V_55 ;
V_53 = ( T_3 * ) F_30 ( V_35 ) + F_50 ( V_39 ) ;
V_54 = F_37 ( V_53 , V_39 ) ;
V_55 = F_41 ( V_54 , V_39 ) ;
F_47 ( ( T_1 * ) V_55 , V_32 ) ;
}
}
#endif
}
static int
F_51 ( T_1 * V_57 , unsigned long V_39 ,
struct V_59 * V_60 )
{
unsigned long V_61 , V_29 , V_62 , V_63 , V_18 , V_40 ;
T_1 V_64 , V_65 , * V_66 ;
T_2 V_67 , V_68 , V_69 ;
int V_30 , V_70 = 1 ;
unsigned int V_1 ;
if ( V_60 -> V_71 )
return 1 ;
F_2 ( & V_3 ) ;
V_66 = F_27 ( V_39 , & V_1 ) ;
if ( V_66 != V_57 )
goto V_72;
switch ( V_1 ) {
case V_11 :
V_63 = V_73 ;
V_62 = V_74 ;
break;
#ifdef V_9
case V_13 :
V_63 = V_75 ;
V_62 = V_76 ;
break;
#endif
default:
V_70 = - V_77 ;
goto V_72;
}
V_61 = ( V_39 + V_63 ) & V_62 ;
V_29 = ( V_61 - V_39 ) >> V_15 ;
if ( V_29 < V_60 -> V_29 )
V_60 -> V_29 = V_29 ;
V_65 = * V_57 ;
V_67 = V_68 = V_69 = F_52 ( V_65 ) ;
F_34 ( V_69 ) &= ~ F_34 ( V_60 -> V_78 ) ;
F_34 ( V_69 ) |= F_34 ( V_60 -> V_79 ) ;
V_40 = F_53 ( V_65 ) + ( ( V_39 & ( V_63 - 1 ) ) >> V_15 ) ;
V_60 -> V_40 = V_40 ;
V_68 = F_31 ( V_69 , V_39 , V_40 ) ;
V_18 = V_39 & V_62 ;
V_40 = F_53 ( V_65 ) ;
for ( V_30 = 0 ; V_30 < ( V_63 >> V_15 ) ; V_30 ++ , V_18 += V_31 , V_40 ++ ) {
T_2 V_80 = F_31 ( V_69 , V_18 , V_40 ) ;
if ( F_34 ( V_80 ) != F_34 ( V_68 ) )
goto V_72;
}
if ( F_34 ( V_68 ) == F_34 ( V_67 ) ) {
V_70 = 0 ;
goto V_72;
}
if ( V_39 == ( V_39 & V_62 ) && V_60 -> V_29 == ( V_63 >> V_15 ) ) {
V_64 = F_54 ( F_53 ( V_65 ) , F_55 ( V_68 ) ) ;
F_46 ( V_57 , V_39 , V_64 ) ;
V_60 -> V_81 |= V_82 ;
V_70 = 0 ;
}
V_72:
F_3 ( & V_3 ) ;
return V_70 ;
}
static int F_56 ( T_1 * V_57 , unsigned long V_39 )
{
unsigned long V_40 , V_83 = 1 ;
unsigned int V_30 , V_1 ;
T_1 * V_84 , * V_66 ;
T_2 V_85 ;
struct V_35 * V_86 ;
if ( ! V_87 )
F_3 ( & V_88 ) ;
V_86 = F_57 ( V_89 | V_90 , 0 ) ;
if ( ! V_87 )
F_2 ( & V_88 ) ;
if ( ! V_86 )
return - V_91 ;
F_2 ( & V_3 ) ;
V_66 = F_27 ( V_39 , & V_1 ) ;
if ( V_66 != V_57 )
goto V_72;
V_84 = ( T_1 * ) F_30 ( V_86 ) ;
F_58 ( & V_92 , F_59 ( V_86 ) ) ;
V_85 = F_52 ( F_60 ( * V_57 ) ) ;
F_61 ( F_34 ( V_85 ) & V_93 ) ;
#ifdef V_9
if ( V_1 == V_13 ) {
V_83 = V_73 >> V_15 ;
F_34 ( V_85 ) |= V_94 ;
}
#endif
V_40 = F_53 ( * V_57 ) ;
for ( V_30 = 0 ; V_30 < V_5 ; V_30 ++ , V_40 += V_83 )
F_62 ( & V_84 [ V_30 ] , F_54 ( V_40 , V_85 ) ) ;
if ( V_39 >= ( unsigned long ) F_63 ( 0 ) &&
V_39 < ( unsigned long ) F_63 ( V_95 << V_15 ) )
F_4 ( V_1 ) ;
#ifdef V_9
if ( V_39 >= ( unsigned long ) F_63 ( 1UL << 32 ) &&
V_39 < ( unsigned long ) F_63 ( V_96 << V_15 ) )
F_4 ( V_1 ) ;
#endif
F_46 ( V_57 , V_39 , F_64 ( V_86 , F_32 ( V_97 ) ) ) ;
F_17 () ;
V_86 = NULL ;
V_72:
if ( V_86 )
F_65 ( V_86 ) ;
F_3 ( & V_3 ) ;
return 0 ;
}
static int F_66 ( struct V_59 * V_60 , unsigned long V_21 ,
int V_98 )
{
if ( ! V_98 )
return 0 ;
if ( F_12 ( V_21 , V_99 ,
V_99 + ( V_96 << V_15 ) ) ) {
V_60 -> V_29 = 1 ;
V_60 -> V_40 = F_9 ( V_21 ) >> V_15 ;
return 0 ;
} else {
F_67 ( 1 , V_100 L_5
L_6 , V_21 ,
* V_60 -> V_21 ) ;
return - V_101 ;
}
}
static int F_68 ( struct V_59 * V_60 , int V_98 )
{
unsigned long V_39 ;
int V_70 , V_102 ;
unsigned int V_1 ;
T_1 * V_57 , V_65 ;
if ( V_60 -> V_81 & V_37 ) {
struct V_35 * V_35 = V_60 -> V_2 [ V_60 -> V_103 ] ;
if ( F_69 ( F_70 ( V_35 ) ) )
return 0 ;
V_39 = ( unsigned long ) F_30 ( V_35 ) ;
} else if ( V_60 -> V_81 & V_104 )
V_39 = V_60 -> V_21 [ V_60 -> V_103 ] ;
else
V_39 = * V_60 -> V_21 ;
V_105:
V_57 = F_27 ( V_39 , & V_1 ) ;
if ( ! V_57 )
return F_66 ( V_60 , V_39 , V_98 ) ;
V_65 = * V_57 ;
if ( ! F_28 ( V_65 ) )
return F_66 ( V_60 , V_39 , V_98 ) ;
if ( V_1 == V_8 ) {
T_1 V_64 ;
T_2 V_68 = F_52 ( V_65 ) ;
unsigned long V_40 = F_53 ( V_65 ) ;
F_34 ( V_68 ) &= ~ F_34 ( V_60 -> V_78 ) ;
F_34 ( V_68 ) |= F_34 ( V_60 -> V_79 ) ;
V_68 = F_31 ( V_68 , V_39 , V_40 ) ;
V_64 = F_54 ( V_40 , F_55 ( V_68 ) ) ;
V_60 -> V_40 = V_40 ;
if ( F_28 ( V_65 ) != F_28 ( V_64 ) ) {
F_47 ( V_57 , V_64 ) ;
V_60 -> V_81 |= V_82 ;
}
V_60 -> V_29 = 1 ;
return 0 ;
}
V_70 = F_51 ( V_57 , V_39 , V_60 ) ;
if ( V_70 <= 0 )
return V_70 ;
V_102 = F_56 ( V_57 , V_39 ) ;
if ( ! V_102 ) {
F_71 () ;
goto V_105;
}
return V_102 ;
}
static int F_72 ( struct V_59 * V_60 )
{
struct V_59 V_106 ;
unsigned long V_107 = ( unsigned long ) F_63 ( V_60 -> V_40 << V_15 ) ;
unsigned long V_21 ;
int V_108 ;
if ( V_60 -> V_40 >= V_96 )
return 0 ;
#ifdef V_9
if ( V_60 -> V_40 >= V_95 && V_60 -> V_40 < ( 1UL << ( 32 - V_15 ) ) )
return 0 ;
#endif
if ( V_60 -> V_81 & V_37 ) {
struct V_35 * V_35 = V_60 -> V_2 [ V_60 -> V_103 ] ;
if ( F_69 ( F_70 ( V_35 ) ) )
return 0 ;
V_21 = ( unsigned long ) F_30 ( V_35 ) ;
} else if ( V_60 -> V_81 & V_104 )
V_21 = V_60 -> V_21 [ V_60 -> V_103 ] ;
else
V_21 = * V_60 -> V_21 ;
if ( ! ( F_12 ( V_21 , V_99 ,
V_99 + ( V_96 << V_15 ) ) ) ) {
V_106 = * V_60 ;
V_106 . V_21 = & V_107 ;
V_106 . V_81 &= ~ ( V_37 | V_104 ) ;
V_108 = F_73 ( & V_106 , 0 ) ;
if ( V_108 )
return V_108 ;
}
#ifdef V_9
if ( ! F_12 ( V_21 , ( unsigned long ) V_14 , V_16 ) &&
F_12 ( V_60 -> V_40 , F_8 () , F_10 () ) ) {
unsigned long V_109 = ( V_60 -> V_40 << V_15 ) +
V_110 - V_111 ;
V_106 = * V_60 ;
V_106 . V_21 = & V_109 ;
V_106 . V_81 &= ~ ( V_37 | V_104 ) ;
F_73 ( & V_106 , 0 ) ;
}
#endif
return 0 ;
}
static int F_73 ( struct V_59 * V_60 , int V_112 )
{
int V_108 , V_29 = V_60 -> V_29 ;
while ( V_29 ) {
V_60 -> V_29 = V_29 ;
if ( V_60 -> V_81 & ( V_104 | V_37 ) )
V_60 -> V_29 = 1 ;
if ( ! V_87 )
F_2 ( & V_88 ) ;
V_108 = F_68 ( V_60 , V_112 ) ;
if ( ! V_87 )
F_3 ( & V_88 ) ;
if ( V_108 )
return V_108 ;
if ( V_112 ) {
V_108 = F_72 ( V_60 ) ;
if ( V_108 )
return V_108 ;
}
F_20 ( V_60 -> V_29 > V_29 ) ;
V_29 -= V_60 -> V_29 ;
if ( V_60 -> V_81 & ( V_37 | V_104 ) )
V_60 -> V_103 ++ ;
else
* V_60 -> V_21 += V_60 -> V_29 * V_31 ;
}
return 0 ;
}
static inline int F_74 ( T_2 V_113 )
{
return F_34 ( V_113 ) &
( V_114 | V_93 | V_115 | V_116 ) ;
}
static int F_75 ( unsigned long * V_18 , int V_29 ,
T_2 V_79 , T_2 V_78 ,
int V_71 , int V_117 ,
struct V_35 * * V_2 )
{
struct V_59 V_60 ;
int V_108 , V_27 , V_112 ;
unsigned long V_118 = 0 ;
V_79 = F_55 ( V_79 ) ;
V_78 = F_55 ( V_78 ) ;
if ( ! F_34 ( V_79 ) && ! F_34 ( V_78 ) && ! V_71 )
return 0 ;
if ( V_117 & V_104 ) {
int V_30 ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
if ( V_18 [ V_30 ] & ~ V_119 ) {
V_18 [ V_30 ] &= V_119 ;
F_61 ( 1 ) ;
}
}
} else if ( ! ( V_117 & V_37 ) ) {
if ( * V_18 & ~ V_119 ) {
* V_18 &= V_119 ;
F_61 ( 1 ) ;
}
V_118 = * V_18 ;
}
F_76 () ;
F_77 () ;
V_60 . V_21 = V_18 ;
V_60 . V_2 = V_2 ;
V_60 . V_29 = V_29 ;
V_60 . V_79 = V_79 ;
V_60 . V_78 = V_78 ;
V_60 . V_81 = 0 ;
V_60 . V_103 = 0 ;
V_60 . V_71 = V_71 ;
if ( V_117 & ( V_104 | V_37 ) )
V_60 . V_81 |= V_117 ;
V_112 = ( F_34 ( V_79 ) | F_34 ( V_78 ) ) != V_45 ;
V_108 = F_73 ( & V_60 , V_112 ) ;
if ( ! ( V_60 . V_81 & V_82 ) )
goto V_120;
V_27 = F_74 ( V_79 ) ;
if ( ! V_108 && V_121 ) {
if ( V_60 . V_81 & ( V_37 | V_104 ) ) {
F_29 ( V_18 , V_29 , V_27 ,
V_60 . V_81 , V_2 ) ;
} else
F_24 ( V_118 , V_29 , V_27 ) ;
} else
F_19 ( V_27 ) ;
V_120:
return V_108 ;
}
static inline int F_78 ( unsigned long * V_18 , int V_29 ,
T_2 V_122 , int V_123 )
{
return F_75 ( V_18 , V_29 , V_122 , F_32 ( 0 ) , 0 ,
( V_123 ? V_104 : 0 ) , NULL ) ;
}
static inline int F_79 ( unsigned long * V_18 , int V_29 ,
T_2 V_122 , int V_123 )
{
return F_75 ( V_18 , V_29 , F_32 ( 0 ) , V_122 , 0 ,
( V_123 ? V_104 : 0 ) , NULL ) ;
}
static inline int F_80 ( struct V_35 * * V_2 , int V_29 ,
T_2 V_122 )
{
return F_75 ( NULL , V_29 , V_122 , F_32 ( 0 ) , 0 ,
V_37 , V_2 ) ;
}
static inline int F_81 ( struct V_35 * * V_2 , int V_29 ,
T_2 V_122 )
{
return F_75 ( NULL , V_29 , F_32 ( 0 ) , V_122 , 0 ,
V_37 , V_2 ) ;
}
int F_82 ( unsigned long V_18 , int V_29 )
{
return F_78 ( & V_18 , V_29 ,
F_32 ( V_124 ) , 0 ) ;
}
int F_83 ( unsigned long V_18 , int V_29 )
{
int V_108 ;
V_108 = F_84 ( F_9 ( V_18 ) , F_9 ( V_18 ) + V_29 * V_31 ,
V_124 , NULL ) ;
if ( V_108 )
goto V_125;
V_108 = F_82 ( V_18 , V_29 ) ;
if ( V_108 )
goto V_126;
return 0 ;
V_126:
F_85 ( F_9 ( V_18 ) , F_9 ( V_18 ) + V_29 * V_31 ) ;
V_125:
return V_108 ;
}
int F_86 ( unsigned long * V_18 , int V_127 ,
unsigned long V_128 )
{
int V_30 , V_129 ;
int V_108 ;
for ( V_30 = 0 ; V_30 < V_127 ; V_30 ++ ) {
V_108 = F_84 ( F_9 ( V_18 [ V_30 ] ) , F_9 ( V_18 [ V_30 ] ) + V_31 ,
V_128 , NULL ) ;
if ( V_108 )
goto V_126;
}
V_108 = F_78 ( V_18 , V_127 ,
F_32 ( V_124 ) , 1 ) ;
if ( ! V_108 && V_128 == V_130 )
V_108 = F_75 ( V_18 , V_127 ,
F_32 ( V_130 ) ,
F_32 ( V_131 ) ,
0 , V_104 , NULL ) ;
if ( V_108 )
goto V_126;
return 0 ;
V_126:
for ( V_129 = 0 ; V_129 < V_30 ; V_129 ++ )
F_85 ( F_9 ( V_18 [ V_129 ] ) , F_9 ( V_18 [ V_129 ] ) + V_31 ) ;
return V_108 ;
}
int F_87 ( unsigned long * V_18 , int V_127 )
{
return F_86 ( V_18 , V_127 , V_124 ) ;
}
int F_88 ( unsigned long * V_18 , int V_127 )
{
return F_86 ( V_18 , V_127 , V_130 ) ;
}
int F_89 ( unsigned long V_18 , int V_29 )
{
int V_108 ;
unsigned long V_132 = V_18 ;
V_108 = F_78 ( & V_18 , V_29 ,
F_32 ( V_124 ) , 0 ) ;
if ( ! V_108 ) {
V_108 = F_75 ( & V_132 , V_29 ,
F_32 ( V_130 ) ,
F_32 ( V_131 ) ,
0 , 0 , NULL ) ;
}
return V_108 ;
}
int F_90 ( unsigned long V_18 , int V_29 )
{
int V_108 ;
if ( ! V_133 )
return F_83 ( V_18 , V_29 ) ;
V_108 = F_84 ( F_9 ( V_18 ) , F_9 ( V_18 ) + V_29 * V_31 ,
V_130 , NULL ) ;
if ( V_108 )
goto V_125;
V_108 = F_89 ( V_18 , V_29 ) ;
if ( V_108 )
goto V_126;
return 0 ;
V_126:
F_85 ( F_9 ( V_18 ) , F_9 ( V_18 ) + V_29 * V_31 ) ;
V_125:
return V_108 ;
}
int F_91 ( unsigned long V_18 , int V_29 )
{
return F_79 ( & V_18 , V_29 ,
F_32 ( V_131 ) , 0 ) ;
}
int F_92 ( unsigned long V_18 , int V_29 )
{
int V_108 ;
V_108 = F_91 ( V_18 , V_29 ) ;
if ( V_108 )
return V_108 ;
F_85 ( F_9 ( V_18 ) , F_9 ( V_18 ) + V_29 * V_31 ) ;
return 0 ;
}
int F_93 ( unsigned long * V_18 , int V_127 )
{
int V_30 ;
int V_108 ;
V_108 = F_79 ( V_18 , V_127 ,
F_32 ( V_131 ) , 1 ) ;
if ( V_108 )
return V_108 ;
for ( V_30 = 0 ; V_30 < V_127 ; V_30 ++ )
F_85 ( F_9 ( V_18 [ V_30 ] ) , F_9 ( V_18 [ V_30 ] ) + V_31 ) ;
return 0 ;
}
int F_94 ( unsigned long V_18 , int V_29 )
{
if ( ! ( V_134 & V_45 ) )
return 0 ;
return F_79 ( & V_18 , V_29 , F_32 ( V_45 ) , 0 ) ;
}
int F_95 ( unsigned long V_18 , int V_29 )
{
if ( ! ( V_134 & V_45 ) )
return 0 ;
return F_78 ( & V_18 , V_29 , F_32 ( V_45 ) , 0 ) ;
}
int F_96 ( unsigned long V_18 , int V_29 )
{
return F_79 ( & V_18 , V_29 , F_32 ( V_49 ) , 0 ) ;
}
int F_97 ( unsigned long V_18 , int V_29 )
{
return F_78 ( & V_18 , V_29 , F_32 ( V_49 ) , 0 ) ;
}
int F_98 ( unsigned long V_18 , int V_29 )
{
return F_79 ( & V_18 , V_29 , F_32 ( V_33 ) , 0 ) ;
}
int F_99 ( unsigned long V_18 , int V_29 )
{
return F_75 ( & V_18 , V_29 , F_32 ( 0 ) ,
F_32 ( 0 ) , 1 , 0 , NULL ) ;
}
int F_100 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_83 ( V_18 , V_29 ) ;
}
static int F_101 ( struct V_35 * * V_2 , int V_127 ,
unsigned long V_128 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_30 ;
int V_135 ;
int V_108 ;
for ( V_30 = 0 ; V_30 < V_127 ; V_30 ++ ) {
if ( F_70 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_59 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
if ( F_84 ( V_19 , V_20 , V_128 , NULL ) )
goto V_136;
}
V_108 = F_80 ( V_2 , V_127 ,
F_32 ( V_124 ) ) ;
if ( ! V_108 && V_128 == V_130 )
V_108 = F_75 ( NULL , V_127 ,
F_32 ( V_130 ) ,
F_32 ( V_131 ) ,
0 , V_37 , V_2 ) ;
if ( V_108 )
goto V_136;
return 0 ;
V_136:
V_135 = V_30 ;
for ( V_30 = 0 ; V_30 < V_135 ; V_30 ++ ) {
if ( F_70 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_59 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
F_85 ( V_19 , V_20 ) ;
}
return - V_77 ;
}
int F_102 ( struct V_35 * * V_2 , int V_127 )
{
return F_101 ( V_2 , V_127 , V_124 ) ;
}
int F_103 ( struct V_35 * * V_2 , int V_127 )
{
return F_101 ( V_2 , V_127 , V_130 ) ;
}
int F_104 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_92 ( V_18 , V_29 ) ;
}
int F_105 ( struct V_35 * * V_2 , int V_127 )
{
int V_137 ;
unsigned long V_19 ;
unsigned long V_20 ;
int V_30 ;
V_137 = F_81 ( V_2 , V_127 ,
F_32 ( V_131 ) ) ;
if ( V_137 )
return V_137 ;
for ( V_30 = 0 ; V_30 < V_127 ; V_30 ++ ) {
if ( F_70 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_59 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
F_85 ( V_19 , V_20 ) ;
}
return 0 ;
}
int F_106 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_94 ( V_18 , V_29 ) ;
}
int F_107 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_95 ( V_18 , V_29 ) ;
}
int F_108 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_96 ( V_18 , V_29 ) ;
}
int F_109 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_97 ( V_18 , V_29 ) ;
}
static int F_110 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_138 = ( unsigned long ) F_30 ( V_35 ) ;
struct V_59 V_60 = { . V_21 = & V_138 ,
. V_29 = V_29 ,
. V_79 = F_32 ( V_33 | V_49 ) ,
. V_78 = F_32 ( 0 ) ,
. V_81 = 0 } ;
return F_73 ( & V_60 , 0 ) ;
}
static int F_111 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_138 = ( unsigned long ) F_30 ( V_35 ) ;
struct V_59 V_60 = { . V_21 = & V_138 ,
. V_29 = V_29 ,
. V_79 = F_32 ( 0 ) ,
. V_78 = F_32 ( V_33 | V_49 ) ,
. V_81 = 0 } ;
return F_73 ( & V_60 , 0 ) ;
}
void F_112 ( struct V_35 * V_35 , int V_29 , int V_139 )
{
if ( F_70 ( V_35 ) )
return;
if ( ! V_139 ) {
F_113 ( F_30 ( V_35 ) ,
V_29 * V_31 ) ;
}
if ( ! V_140 )
return;
if ( V_139 )
F_110 ( V_35 , V_29 ) ;
else
F_111 ( V_35 , V_29 ) ;
F_17 () ;
}
bool F_114 ( struct V_35 * V_35 )
{
unsigned int V_1 ;
T_1 * V_32 ;
if ( F_70 ( V_35 ) )
return false ;
V_32 = F_27 ( ( unsigned long ) F_30 ( V_35 ) , & V_1 ) ;
return ( F_28 ( * V_32 ) & V_33 ) ;
}
