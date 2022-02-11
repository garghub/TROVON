static T_1 void * F_1 ( unsigned long V_1 )
{
void * V_2 ;
V_2 = F_2 ( F_3 ( V_1 , V_1 , F_4 ( V_3 ) ) ) ;
memset ( V_2 , 0 , V_1 ) ;
return V_2 ;
}
int F_5 ( unsigned long V_4 , unsigned long V_5 , int V_6 )
{
T_2 * V_7 ;
T_3 * V_8 ;
T_4 * V_9 ;
T_5 * V_10 ;
if ( F_6 () ) {
V_7 = F_7 ( V_4 ) ;
V_8 = F_8 ( & V_11 , V_7 , V_4 ) ;
if ( ! V_8 )
return - V_12 ;
V_9 = F_9 ( & V_11 , V_8 , V_4 ) ;
if ( ! V_9 )
return - V_12 ;
V_10 = F_10 ( V_9 , V_4 ) ;
if ( ! V_10 )
return - V_12 ;
F_11 ( & V_11 , V_4 , V_10 , F_12 ( V_5 >> V_13 ,
F_13 ( V_6 ) ) ) ;
} else {
#ifdef F_14
V_7 = F_7 ( V_4 ) ;
#ifdef F_15
if ( F_16 ( * V_7 ) ) {
V_8 = F_1 ( F_15 ) ;
F_17 ( V_8 == NULL ) ;
F_18 ( & V_11 , V_7 , V_8 ) ;
}
#endif
V_8 = F_19 ( V_7 , V_4 ) ;
if ( F_20 ( * V_8 ) ) {
V_9 = F_1 ( V_14 ) ;
F_17 ( V_9 == NULL ) ;
F_21 ( & V_11 , V_8 , V_9 ) ;
}
V_9 = F_22 ( V_8 , V_4 ) ;
if ( ! F_23 ( * V_9 ) ) {
V_10 = F_1 ( V_15 ) ;
F_17 ( V_10 == NULL ) ;
F_24 ( & V_11 , V_9 , V_10 ) ;
}
V_10 = F_25 ( V_9 , V_4 ) ;
F_11 ( & V_11 , V_4 , V_10 , F_12 ( V_5 >> V_13 ,
F_13 ( V_6 ) ) ) ;
#else
if ( F_26 ( V_4 , V_4 + V_15 , V_5 , V_6 ,
V_16 , V_17 ) ) {
F_27 ( V_18 L_1
L_2 , V_5 ) ;
return - V_12 ;
}
#endif
}
#ifdef F_28
F_29 () ;
#else
F_30 () ;
#endif
return 0 ;
}
void T_6 * F_31 ( T_7 V_5 , void * V_4 , unsigned long V_1 ,
unsigned long V_6 )
{
unsigned long V_19 ;
if ( ( V_6 & V_20 ) == 0 )
V_6 |= F_32 ( V_21 ) ;
if ( V_6 & V_22 )
V_6 &= ~ V_23 ;
if ( V_6 & V_24 )
return NULL ;
F_33 ( V_5 & ~ V_25 ) ;
F_33 ( ( ( unsigned long ) V_4 ) & ~ V_25 ) ;
F_33 ( V_1 & ~ V_25 ) ;
for ( V_19 = 0 ; V_19 < V_1 ; V_19 += V_15 )
if ( F_5 ( ( unsigned long ) V_4 + V_19 , V_5 + V_19 , V_6 ) )
return NULL ;
return ( void T_6 * ) V_4 ;
}
void F_34 ( void * V_4 , unsigned long V_1 )
{
F_33 ( ( ( unsigned long ) V_4 ) & ~ V_25 ) ;
F_33 ( V_1 & ~ V_25 ) ;
F_35 ( ( unsigned long ) V_4 , V_1 ) ;
}
void T_6 * F_36 ( T_7 V_26 , unsigned long V_1 ,
unsigned long V_6 , void * V_27 )
{
T_7 V_28 ;
void T_6 * V_29 ;
V_28 = V_26 & V_25 ;
V_1 = F_37 ( V_26 + V_1 ) - V_28 ;
if ( ( V_1 == 0 ) || ( V_28 == 0 ) )
return NULL ;
if ( F_6 () ) {
struct V_30 * V_31 ;
V_31 = F_38 ( V_1 , V_32 ,
V_33 , V_34 ,
V_27 ) ;
if ( V_31 == NULL )
return NULL ;
V_31 -> V_35 = V_28 ;
V_29 = F_31 ( V_28 , V_31 -> V_26 , V_1 , V_6 ) ;
if ( ! V_29 )
F_39 ( V_31 -> V_26 ) ;
} else {
V_29 = F_31 ( V_28 , ( void * ) V_33 , V_1 , V_6 ) ;
if ( V_29 )
V_33 += V_1 ;
}
if ( V_29 )
V_29 += V_26 & ~ V_25 ;
return V_29 ;
}
void T_6 * F_40 ( T_7 V_26 , unsigned long V_1 ,
unsigned long V_6 )
{
return F_36 ( V_26 , V_1 , V_6 , F_41 ( 0 ) ) ;
}
void T_6 * F_42 ( T_7 V_26 , unsigned long V_1 )
{
unsigned long V_6 = V_22 | V_36 ;
void * V_27 = F_41 ( 0 ) ;
if ( V_37 . F_42 )
return V_37 . F_42 ( V_26 , V_1 , V_6 , V_27 ) ;
return F_36 ( V_26 , V_1 , V_6 , V_27 ) ;
}
void T_6 * F_43 ( T_7 V_26 , unsigned long V_1 )
{
unsigned long V_6 = V_22 ;
void * V_27 = F_41 ( 0 ) ;
if ( V_37 . F_42 )
return V_37 . F_42 ( V_26 , V_1 , V_6 , V_27 ) ;
return F_36 ( V_26 , V_1 , V_6 , V_27 ) ;
}
void T_6 * F_44 ( T_7 V_26 , unsigned long V_1 ,
unsigned long V_6 )
{
void * V_27 = F_41 ( 0 ) ;
if ( V_6 & V_38 )
V_6 |= V_39 ;
V_6 &= ~ ( V_40 | V_41 ) ;
#ifdef F_45
V_6 |= F_45 ;
#endif
if ( V_37 . F_42 )
return V_37 . F_42 ( V_26 , V_1 , V_6 , V_27 ) ;
return F_36 ( V_26 , V_1 , V_6 , V_27 ) ;
}
void F_46 ( volatile void T_6 * V_42 )
{
void * V_26 ;
if ( ! F_6 () )
return;
V_26 = ( void * ) ( ( unsigned long V_43 )
F_47 ( V_42 ) & V_25 ) ;
if ( ( unsigned long ) V_26 < V_33 ) {
F_27 ( V_44 L_3
L_4 , V_26 ) ;
return;
}
F_39 ( V_26 ) ;
}
void F_48 ( volatile void T_6 * V_42 )
{
if ( V_37 . F_48 )
V_37 . F_48 ( V_42 ) ;
else
F_46 ( V_42 ) ;
}
struct V_45 * F_49 ( T_2 V_46 )
{
if ( F_50 ( V_46 ) )
return F_51 ( F_52 ( V_46 ) ) ;
return F_53 ( F_54 ( V_46 ) ) ;
}
struct V_45 * F_55 ( T_3 V_47 )
{
if ( F_56 ( V_47 ) )
return F_51 ( F_57 ( V_47 ) ) ;
return F_53 ( F_58 ( V_47 ) ) ;
}
struct V_45 * F_59 ( T_4 V_48 )
{
if ( F_60 ( V_48 ) || F_61 ( V_48 ) )
return F_62 ( F_63 ( V_48 ) ) ;
return F_53 ( F_64 ( V_48 ) ) ;
}
static T_5 * F_65 ( struct V_49 * V_50 )
{
void * V_51 , * V_29 ;
F_66 ( & V_50 -> V_52 ) ;
V_29 = V_50 -> V_53 . V_51 ;
if ( V_29 ) {
V_51 = V_29 + V_54 ;
if ( ( ( unsigned long ) V_51 & ~ V_25 ) == 0 )
V_51 = NULL ;
V_50 -> V_53 . V_51 = V_51 ;
}
F_67 ( & V_50 -> V_52 ) ;
return ( T_5 * ) V_29 ;
}
static T_5 * F_68 ( struct V_49 * V_50 , int V_55 )
{
void * V_29 = NULL ;
struct V_45 * V_45 = F_69 ( V_56 | V_57 |
V_58 | V_59 ) ;
if ( ! V_45 )
return NULL ;
if ( ! V_55 && ! F_70 ( V_45 ) ) {
F_71 ( V_45 ) ;
return NULL ;
}
V_29 = F_72 ( V_45 ) ;
F_66 ( & V_50 -> V_52 ) ;
if ( F_73 ( ! V_50 -> V_53 . V_51 ) ) {
F_74 ( & V_45 -> V_60 , V_61 ) ;
V_50 -> V_53 . V_51 = V_29 + V_54 ;
}
F_67 ( & V_50 -> V_52 ) ;
return ( T_5 * ) V_29 ;
}
T_5 * F_75 ( struct V_49 * V_50 , unsigned long V_62 , int V_55 )
{
T_5 * V_63 ;
V_63 = F_65 ( V_50 ) ;
if ( V_63 )
return V_63 ;
return F_68 ( V_50 , V_55 ) ;
}
void F_76 ( struct V_49 * V_50 , unsigned long * V_64 , int V_55 )
{
struct V_45 * V_45 = F_53 ( V_64 ) ;
if ( F_77 ( V_45 ) ) {
if ( ! V_55 )
F_78 ( V_45 ) ;
F_79 ( V_45 , 0 ) ;
}
}
static void F_80 ( void * V_64 )
{
struct V_45 * V_45 = F_53 ( V_64 ) ;
if ( F_77 ( V_45 ) ) {
F_78 ( V_45 ) ;
F_79 ( V_45 , 0 ) ;
}
}
void F_81 ( struct V_65 * V_66 , void * V_64 , int V_67 )
{
unsigned long V_68 = ( unsigned long ) V_64 ;
F_17 ( V_67 > V_69 ) ;
V_68 |= V_67 ;
F_82 ( V_66 , ( void * ) V_68 ) ;
}
void F_83 ( void * V_70 )
{
void * V_64 = ( void * ) ( ( unsigned long ) V_70 & ~ V_69 ) ;
unsigned V_67 = ( unsigned long ) V_70 & V_69 ;
if ( ! V_67 )
F_80 ( V_64 ) ;
else {
F_17 ( V_67 > V_69 ) ;
F_84 ( F_85 ( V_67 ) , V_64 ) ;
}
}
void F_81 ( struct V_65 * V_66 , void * V_64 , int V_67 )
{
if ( ! V_67 ) {
struct V_45 * V_45 = F_53 ( V_64 ) ;
if ( F_77 ( V_45 ) ) {
F_78 ( V_45 ) ;
F_79 ( V_45 , 0 ) ;
}
} else {
F_17 ( V_67 > V_69 ) ;
F_84 ( F_85 ( V_67 ) , V_64 ) ;
}
}
int F_86 ( struct V_71 * V_72 , unsigned long V_73 ,
T_4 * V_9 , T_4 V_74 , int V_75 )
{
int V_76 ;
#ifdef F_87
F_33 ( ! F_60 ( * V_9 ) ) ;
F_88 ( & V_72 -> V_77 -> V_52 ) ;
#endif
V_76 = ! F_89 ( * ( V_9 ) , V_74 ) ;
if ( V_76 ) {
F_90 ( F_91 ( V_9 ) , F_92 ( V_74 ) ) ;
}
return V_76 ;
}
unsigned long F_93 ( struct V_49 * V_50 , unsigned long V_26 ,
T_4 * V_9 , unsigned long V_78 ,
unsigned long V_79 )
{
unsigned long V_80 , V_81 ;
#ifdef F_87
F_33 ( ! F_60 ( * V_9 ) ) ;
F_88 ( & V_50 -> V_52 ) ;
#endif
#ifdef F_94
__asm__ __volatile__(
"1: ldarx %0,0,%3\n\
andi. %1,%0,%6\n\
bne- 1b \n\
andc %1,%0,%4 \n\
or %1,%1,%7\n\
stdcx. %1,0,%3 \n\
bne- 1b"
: "=&r" (old), "=&r" (tmp), "=m" (*pmdp)
: "r" (pmdp), "r" (clr), "m" (*pmdp), "i" (_PAGE_BUSY), "r" (set)
: "cc" );
#else
V_80 = F_95 ( * V_9 ) ;
* V_9 = F_96 ( ( V_80 & ~ V_78 ) | V_79 ) ;
#endif
F_97 ( V_26 , V_80 , V_78 , V_79 ) ;
if ( V_80 & V_82 )
F_98 ( V_50 , V_26 , V_9 , V_80 ) ;
return V_80 ;
}
T_4 F_99 ( struct V_71 * V_72 , unsigned long V_73 ,
T_4 * V_9 )
{
T_4 V_48 ;
F_100 ( V_73 & ~ V_83 ) ;
F_100 ( F_60 ( * V_9 ) ) ;
V_48 = * V_9 ;
F_101 ( V_9 ) ;
F_102 () ;
F_103 ( V_72 -> V_77 , & V_48 , V_73 ) ;
return V_48 ;
}
int F_104 ( struct V_71 * V_72 ,
unsigned long V_73 , T_4 * V_9 )
{
return F_105 ( V_72 -> V_77 , V_73 , V_9 ) ;
}
int F_106 ( struct V_71 * V_72 ,
unsigned long V_73 , T_4 * V_9 )
{
return F_105 ( V_72 -> V_77 , V_73 , V_9 ) ;
}
void F_107 ( struct V_71 * V_72 ,
unsigned long V_73 , T_4 * V_9 )
{
unsigned long V_80 , V_81 ;
F_100 ( V_73 & ~ V_83 ) ;
#ifdef F_87
F_33 ( ! F_60 ( * V_9 ) ) ;
F_88 ( & V_72 -> V_77 -> V_52 ) ;
#endif
#ifdef F_94
__asm__ __volatile__(
"1: ldarx %0,0,%3\n\
andi. %1,%0,%6\n\
bne- 1b \n\
ori %1,%0,%4 \n\
stdcx. %1,0,%3 \n\
bne- 1b"
: "=&r" (old), "=&r" (tmp), "=m" (*pmdp)
: "r" (pmdp), "i" (_PAGE_SPLITTING), "m" (*pmdp), "i" (_PAGE_BUSY)
: "cc" );
#else
V_80 = F_95 ( * V_9 ) ;
* V_9 = F_96 ( V_80 | V_84 ) ;
#endif
F_108 ( V_73 , V_80 ) ;
if ( ! ( V_80 & V_84 ) ) {
if ( V_80 & V_82 )
F_98 ( V_72 -> V_77 , V_73 , V_9 , V_80 ) ;
}
F_102 () ;
}
void F_109 ( struct V_49 * V_50 , T_4 * V_9 ,
T_8 V_85 )
{
T_8 * V_86 ;
F_88 ( & V_50 -> V_52 ) ;
V_86 = ( T_8 * ) V_9 + V_87 ;
* V_86 = V_85 ;
F_30 () ;
}
T_8 F_110 ( struct V_49 * V_50 , T_4 * V_9 )
{
T_8 V_85 ;
T_8 * V_86 ;
F_88 ( & V_50 -> V_52 ) ;
V_86 = ( T_8 * ) V_9 + V_87 ;
V_85 = * V_86 ;
* V_86 = NULL ;
memset ( V_85 , 0 , V_54 ) ;
return V_85 ;
}
void F_111 ( struct V_49 * V_50 , unsigned long V_26 ,
T_4 * V_9 , T_4 V_48 )
{
#ifdef F_87
F_33 ( ( F_95 ( * V_9 ) & ( V_20 | V_40 ) ) ==
( V_20 | V_40 ) ) ;
F_88 ( & V_50 -> V_52 ) ;
F_33 ( ! F_60 ( V_48 ) ) ;
#endif
F_112 ( V_26 , F_95 ( V_48 ) ) ;
return F_11 ( V_50 , V_26 , F_91 ( V_9 ) , F_92 ( V_48 ) ) ;
}
void F_113 ( struct V_71 * V_72 , unsigned long V_73 ,
T_4 * V_9 )
{
F_93 ( V_72 -> V_77 , V_73 , V_9 , V_20 , 0 ) ;
}
void F_98 ( struct V_49 * V_50 , unsigned long V_26 ,
T_4 * V_9 , unsigned long V_88 )
{
int V_89 ;
unsigned int V_90 ;
unsigned long V_91 ;
unsigned long V_6 = 0 ;
const struct V_92 * V_81 ;
#ifdef F_87
V_90 = F_114 ( V_50 , V_26 ) ;
F_17 ( V_90 == V_93 ) ;
#endif
if ( V_88 & V_94 )
V_90 = V_95 ;
else
V_90 = V_96 ;
if ( ! F_115 ( V_26 ) ) {
V_89 = F_116 ( V_26 ) ;
V_91 = F_117 ( V_50 -> V_53 . V_97 , V_26 , V_89 ) ;
F_33 ( V_91 == 0 ) ;
} else {
V_91 = F_118 ( V_26 , V_17 ) ;
V_89 = V_17 ;
}
V_81 = F_119 ( F_120 () ) ;
if ( F_121 ( F_122 ( V_50 ) , V_81 ) )
V_6 |= V_98 ;
return F_123 ( V_91 , V_26 , V_9 , V_90 , V_89 , V_6 ) ;
}
static T_4 F_124 ( T_4 V_48 , T_9 V_99 )
{
F_95 ( V_48 ) |= F_32 ( V_99 ) ;
return V_48 ;
}
T_4 F_125 ( unsigned long V_100 , T_9 V_99 )
{
T_4 V_48 ;
F_95 ( V_48 ) = V_100 << V_101 ;
F_95 ( V_48 ) |= V_102 ;
V_48 = F_124 ( V_48 , V_99 ) ;
return V_48 ;
}
T_4 F_126 ( struct V_45 * V_45 , T_9 V_99 )
{
return F_125 ( F_127 ( V_45 ) , V_99 ) ;
}
T_4 F_128 ( T_4 V_48 , T_9 V_103 )
{
F_95 ( V_48 ) &= V_104 ;
V_48 = F_124 ( V_48 , V_103 ) ;
return V_48 ;
}
void F_129 ( struct V_71 * V_72 , unsigned long V_26 ,
T_4 * V_48 )
{
return;
}
T_4 F_130 ( struct V_49 * V_50 ,
unsigned long V_26 , T_4 * V_9 )
{
T_4 V_88 ;
T_8 V_85 ;
unsigned long V_80 ;
T_8 * V_86 ;
V_80 = F_93 ( V_50 , V_26 , V_9 , ~ 0UL , 0 ) ;
V_88 = F_96 ( V_80 ) ;
V_86 = ( T_8 * ) V_9 + V_87 ;
V_85 = * V_86 ;
memset ( V_85 , 0 , V_54 ) ;
F_102 () ;
return V_88 ;
}
int F_131 ( void )
{
if ( ! F_132 ( V_105 ) )
return 0 ;
if ( V_106 [ V_93 ] . V_67 != V_107 )
return 0 ;
if ( V_106 [ V_96 ] . V_67 &&
( V_106 [ V_96 ] . V_108 [ V_93 ] == - 1 ) )
return 0 ;
if ( V_106 [ V_95 ] . V_108 [ V_93 ] == - 1 )
return 0 ;
return 1 ;
}
