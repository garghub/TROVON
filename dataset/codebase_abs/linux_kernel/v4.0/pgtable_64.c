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
if ( V_30 ) {
struct V_31 * V_32 ;
V_32 = F_38 ( V_1 , V_33 ,
V_34 , V_35 ,
V_27 ) ;
if ( V_32 == NULL )
return NULL ;
V_32 -> V_36 = V_28 ;
V_29 = F_31 ( V_28 , V_32 -> V_26 , V_1 , V_6 ) ;
if ( ! V_29 )
F_39 ( V_32 -> V_26 ) ;
} else {
V_29 = F_31 ( V_28 , ( void * ) V_34 , V_1 , V_6 ) ;
if ( V_29 )
V_34 += V_1 ;
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
unsigned long V_6 = V_22 | V_37 ;
void * V_27 = F_41 ( 0 ) ;
if ( V_38 . F_42 )
return V_38 . F_42 ( V_26 , V_1 , V_6 , V_27 ) ;
return F_36 ( V_26 , V_1 , V_6 , V_27 ) ;
}
void T_6 * F_43 ( T_7 V_26 , unsigned long V_1 )
{
unsigned long V_6 = V_22 ;
void * V_27 = F_41 ( 0 ) ;
if ( V_38 . F_42 )
return V_38 . F_42 ( V_26 , V_1 , V_6 , V_27 ) ;
return F_36 ( V_26 , V_1 , V_6 , V_27 ) ;
}
void T_6 * F_44 ( T_7 V_26 , unsigned long V_1 ,
unsigned long V_6 )
{
void * V_27 = F_41 ( 0 ) ;
if ( V_6 & V_39 )
V_6 |= V_40 ;
V_6 &= ~ ( V_41 | V_42 ) ;
#ifdef F_45
V_6 |= F_45 ;
#endif
if ( V_38 . F_42 )
return V_38 . F_42 ( V_26 , V_1 , V_6 , V_27 ) ;
return F_36 ( V_26 , V_1 , V_6 , V_27 ) ;
}
void F_46 ( volatile void T_6 * V_43 )
{
void * V_26 ;
if ( ! V_30 )
return;
V_26 = ( void * ) ( ( unsigned long V_44 )
F_47 ( V_43 ) & V_25 ) ;
if ( ( unsigned long ) V_26 < V_34 ) {
F_27 ( V_45 L_3
L_4 , V_26 ) ;
return;
}
F_39 ( V_26 ) ;
}
void F_48 ( volatile void T_6 * V_43 )
{
if ( V_38 . F_48 )
V_38 . F_48 ( V_43 ) ;
else
F_46 ( V_43 ) ;
}
struct V_46 * F_49 ( T_2 V_47 )
{
if ( F_50 ( V_47 ) )
return F_51 ( F_52 ( V_47 ) ) ;
return F_53 ( F_54 ( V_47 ) ) ;
}
struct V_46 * F_55 ( T_3 V_48 )
{
if ( F_56 ( V_48 ) )
return F_51 ( F_57 ( V_48 ) ) ;
return F_53 ( F_58 ( V_48 ) ) ;
}
struct V_46 * F_59 ( T_4 V_49 )
{
if ( F_60 ( V_49 ) || F_61 ( V_49 ) )
return F_62 ( F_63 ( V_49 ) ) ;
return F_53 ( F_64 ( V_49 ) ) ;
}
static T_5 * F_65 ( struct V_50 * V_51 )
{
void * V_52 , * V_29 ;
F_66 ( & V_51 -> V_53 ) ;
V_29 = V_51 -> V_54 . V_52 ;
if ( V_29 ) {
V_52 = V_29 + V_55 ;
if ( ( ( unsigned long ) V_52 & ~ V_25 ) == 0 )
V_52 = NULL ;
V_51 -> V_54 . V_52 = V_52 ;
}
F_67 ( & V_51 -> V_53 ) ;
return ( T_5 * ) V_29 ;
}
static T_5 * F_68 ( struct V_50 * V_51 , int V_56 )
{
void * V_29 = NULL ;
struct V_46 * V_46 = F_69 ( V_57 | V_58 |
V_59 | V_60 ) ;
if ( ! V_46 )
return NULL ;
if ( ! V_56 && ! F_70 ( V_46 ) ) {
F_71 ( V_46 ) ;
return NULL ;
}
V_29 = F_72 ( V_46 ) ;
F_66 ( & V_51 -> V_53 ) ;
if ( F_73 ( ! V_51 -> V_54 . V_52 ) ) {
F_74 ( & V_46 -> V_61 , V_62 ) ;
V_51 -> V_54 . V_52 = V_29 + V_55 ;
}
F_67 ( & V_51 -> V_53 ) ;
return ( T_5 * ) V_29 ;
}
T_5 * F_75 ( struct V_50 * V_51 , unsigned long V_63 , int V_56 )
{
T_5 * V_64 ;
V_64 = F_65 ( V_51 ) ;
if ( V_64 )
return V_64 ;
return F_68 ( V_51 , V_56 ) ;
}
void F_76 ( struct V_50 * V_51 , unsigned long * V_65 , int V_56 )
{
struct V_46 * V_46 = F_53 ( V_65 ) ;
if ( F_77 ( V_46 ) ) {
if ( ! V_56 )
F_78 ( V_46 ) ;
F_79 ( V_46 , 0 ) ;
}
}
static void F_80 ( void * V_65 )
{
struct V_46 * V_46 = F_53 ( V_65 ) ;
if ( F_77 ( V_46 ) ) {
F_78 ( V_46 ) ;
F_79 ( V_46 , 0 ) ;
}
}
void F_81 ( struct V_66 * V_67 , void * V_65 , int V_68 )
{
unsigned long V_69 = ( unsigned long ) V_65 ;
F_17 ( V_68 > V_70 ) ;
V_69 |= V_68 ;
F_82 ( V_67 , ( void * ) V_69 ) ;
}
void F_83 ( void * V_71 )
{
void * V_65 = ( void * ) ( ( unsigned long ) V_71 & ~ V_70 ) ;
unsigned V_68 = ( unsigned long ) V_71 & V_70 ;
if ( ! V_68 )
F_80 ( V_65 ) ;
else {
F_17 ( V_68 > V_70 ) ;
F_84 ( F_85 ( V_68 ) , V_65 ) ;
}
}
void F_81 ( struct V_66 * V_67 , void * V_65 , int V_68 )
{
if ( ! V_68 ) {
struct V_46 * V_46 = F_53 ( V_65 ) ;
if ( F_77 ( V_46 ) ) {
F_78 ( V_46 ) ;
F_79 ( V_46 , 0 ) ;
}
} else {
F_17 ( V_68 > V_70 ) ;
F_84 ( F_85 ( V_68 ) , V_65 ) ;
}
}
int F_86 ( struct V_72 * V_73 , unsigned long V_74 ,
T_4 * V_9 , T_4 V_75 , int V_76 )
{
int V_77 ;
#ifdef F_87
F_33 ( ! F_60 ( * V_9 ) ) ;
F_88 ( & V_73 -> V_78 -> V_53 ) ;
#endif
V_77 = ! F_89 ( * ( V_9 ) , V_75 ) ;
if ( V_77 ) {
F_90 ( F_91 ( V_9 ) , F_92 ( V_75 ) ) ;
}
return V_77 ;
}
unsigned long F_93 ( struct V_50 * V_51 , unsigned long V_26 ,
T_4 * V_9 , unsigned long V_79 ,
unsigned long V_80 )
{
unsigned long V_81 , V_82 ;
#ifdef F_87
F_33 ( ! F_60 ( * V_9 ) ) ;
F_88 ( & V_51 -> V_53 ) ;
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
V_81 = F_95 ( * V_9 ) ;
* V_9 = F_96 ( ( V_81 & ~ V_79 ) | V_80 ) ;
#endif
F_97 ( V_26 , V_81 , V_79 , V_80 ) ;
if ( V_81 & V_83 )
F_98 ( V_51 , V_26 , V_9 , V_81 ) ;
return V_81 ;
}
T_4 F_99 ( struct V_72 * V_73 , unsigned long V_74 ,
T_4 * V_9 )
{
T_4 V_49 ;
F_100 ( V_74 & ~ V_84 ) ;
if ( F_60 ( * V_9 ) ) {
V_49 = F_101 ( V_73 -> V_78 , V_74 , V_9 ) ;
} else {
V_49 = * V_9 ;
F_102 ( V_9 ) ;
F_103 () ;
F_104 ( V_73 -> V_78 , & V_49 , V_74 ) ;
}
return V_49 ;
}
int F_105 ( struct V_72 * V_73 ,
unsigned long V_74 , T_4 * V_9 )
{
return F_106 ( V_73 -> V_78 , V_74 , V_9 ) ;
}
int F_107 ( struct V_72 * V_73 ,
unsigned long V_74 , T_4 * V_9 )
{
return F_106 ( V_73 -> V_78 , V_74 , V_9 ) ;
}
void F_108 ( struct V_72 * V_73 ,
unsigned long V_74 , T_4 * V_9 )
{
unsigned long V_81 , V_82 ;
F_100 ( V_74 & ~ V_84 ) ;
#ifdef F_87
F_33 ( ! F_60 ( * V_9 ) ) ;
F_88 ( & V_73 -> V_78 -> V_53 ) ;
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
V_81 = F_95 ( * V_9 ) ;
* V_9 = F_96 ( V_81 | V_85 ) ;
#endif
F_109 ( V_74 , V_81 ) ;
if ( ! ( V_81 & V_85 ) ) {
if ( V_81 & V_83 )
F_98 ( V_73 -> V_78 , V_74 , V_9 , V_81 ) ;
}
F_103 () ;
}
void F_110 ( struct V_50 * V_51 , T_4 * V_9 ,
T_8 V_86 )
{
T_8 * V_87 ;
F_88 ( & V_51 -> V_53 ) ;
V_87 = ( T_8 * ) V_9 + V_88 ;
* V_87 = V_86 ;
F_30 () ;
}
T_8 F_111 ( struct V_50 * V_51 , T_4 * V_9 )
{
T_8 V_86 ;
T_8 * V_87 ;
F_88 ( & V_51 -> V_53 ) ;
V_87 = ( T_8 * ) V_9 + V_88 ;
V_86 = * V_87 ;
* V_87 = NULL ;
memset ( V_86 , 0 , V_55 ) ;
return V_86 ;
}
void F_112 ( struct V_50 * V_51 , unsigned long V_26 ,
T_4 * V_9 , T_4 V_49 )
{
#ifdef F_87
F_33 ( ( F_95 ( * V_9 ) & ( V_20 | V_41 ) ) ==
( V_20 | V_41 ) ) ;
F_88 ( & V_51 -> V_53 ) ;
F_33 ( ! F_60 ( V_49 ) ) ;
#endif
F_113 ( V_26 , V_49 ) ;
return F_11 ( V_51 , V_26 , F_91 ( V_9 ) , F_92 ( V_49 ) ) ;
}
void F_114 ( struct V_72 * V_73 , unsigned long V_74 ,
T_4 * V_9 )
{
F_93 ( V_73 -> V_78 , V_74 , V_9 , V_20 , 0 ) ;
}
void F_98 ( struct V_50 * V_51 , unsigned long V_26 ,
T_4 * V_9 , unsigned long V_89 )
{
int V_90 ;
unsigned int V_91 ;
unsigned long V_92 ;
unsigned long V_6 = 0 ;
const struct V_93 * V_82 ;
#ifdef F_87
V_91 = F_115 ( V_51 , V_26 ) ;
F_17 ( V_91 == V_94 ) ;
#endif
if ( V_89 & V_95 )
V_91 = V_96 ;
else
V_91 = V_97 ;
if ( ! F_116 ( V_26 ) ) {
V_90 = F_117 ( V_26 ) ;
V_92 = F_118 ( V_51 -> V_54 . V_98 , V_26 , V_90 ) ;
F_33 ( V_92 == 0 ) ;
} else {
V_92 = F_119 ( V_26 , V_17 ) ;
V_90 = V_17 ;
}
V_82 = F_120 ( F_121 () ) ;
if ( F_122 ( F_123 ( V_51 ) , V_82 ) )
V_6 |= V_99 ;
return F_124 ( V_92 , V_26 , V_9 , V_91 , V_90 , V_6 ) ;
}
static T_4 F_125 ( T_4 V_49 , T_9 V_100 )
{
F_95 ( V_49 ) |= F_32 ( V_100 ) ;
return V_49 ;
}
T_4 F_126 ( unsigned long V_101 , T_9 V_100 )
{
T_4 V_49 ;
F_95 ( V_49 ) = V_101 << V_102 ;
F_95 ( V_49 ) |= V_103 ;
V_49 = F_125 ( V_49 , V_100 ) ;
return V_49 ;
}
T_4 F_127 ( struct V_46 * V_46 , T_9 V_100 )
{
return F_126 ( F_128 ( V_46 ) , V_100 ) ;
}
T_4 F_129 ( T_4 V_49 , T_9 V_104 )
{
F_95 ( V_49 ) &= V_105 ;
V_49 = F_125 ( V_49 , V_104 ) ;
return V_49 ;
}
void F_130 ( struct V_72 * V_73 , unsigned long V_26 ,
T_4 * V_49 )
{
return;
}
T_4 F_101 ( struct V_50 * V_51 ,
unsigned long V_26 , T_4 * V_9 )
{
T_4 V_89 ;
T_8 V_86 ;
unsigned long V_81 ;
T_8 * V_87 ;
V_81 = F_93 ( V_51 , V_26 , V_9 , ~ 0UL , 0 ) ;
V_89 = F_96 ( V_81 ) ;
V_87 = ( T_8 * ) V_9 + V_88 ;
V_86 = * V_87 ;
memset ( V_86 , 0 , V_55 ) ;
return V_89 ;
}
int F_131 ( void )
{
if ( ! F_132 ( V_106 ) )
return 0 ;
if ( V_107 [ V_94 ] . V_68 != V_108 )
return 0 ;
if ( V_107 [ V_97 ] . V_68 &&
( V_107 [ V_97 ] . V_109 [ V_94 ] == - 1 ) )
return 0 ;
if ( V_107 [ V_96 ] . V_109 [ V_94 ] == - 1 )
return 0 ;
return 1 ;
}
