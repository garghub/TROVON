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
F_28 () ;
return 0 ;
}
void T_6 * F_29 ( T_7 V_5 , void * V_4 , unsigned long V_1 ,
unsigned long V_6 )
{
unsigned long V_19 ;
if ( ( V_6 & V_20 ) == 0 )
V_6 |= F_30 ( V_21 ) ;
if ( V_6 & V_22 )
V_6 &= ~ V_23 ;
if ( V_6 & V_24 )
return NULL ;
F_31 ( V_5 & ~ V_25 ) ;
F_31 ( ( ( unsigned long ) V_4 ) & ~ V_25 ) ;
F_31 ( V_1 & ~ V_25 ) ;
for ( V_19 = 0 ; V_19 < V_1 ; V_19 += V_15 )
if ( F_5 ( ( unsigned long ) V_4 + V_19 , V_5 + V_19 , V_6 ) )
return NULL ;
return ( void T_6 * ) V_4 ;
}
void F_32 ( void * V_4 , unsigned long V_1 )
{
F_31 ( ( ( unsigned long ) V_4 ) & ~ V_25 ) ;
F_31 ( V_1 & ~ V_25 ) ;
F_33 ( ( unsigned long ) V_4 , V_1 ) ;
}
void T_6 * F_34 ( T_7 V_26 , unsigned long V_1 ,
unsigned long V_6 , void * V_27 )
{
T_7 V_28 ;
void T_6 * V_29 ;
V_28 = V_26 & V_25 ;
V_1 = F_35 ( V_26 + V_1 ) - V_28 ;
if ( ( V_1 == 0 ) || ( V_28 == 0 ) )
return NULL ;
if ( F_6 () ) {
struct V_30 * V_31 ;
V_31 = F_36 ( V_1 , V_32 ,
V_33 , V_34 ,
V_27 ) ;
if ( V_31 == NULL )
return NULL ;
V_31 -> V_35 = V_28 ;
V_29 = F_29 ( V_28 , V_31 -> V_26 , V_1 , V_6 ) ;
if ( ! V_29 )
F_37 ( V_31 -> V_26 ) ;
} else {
V_29 = F_29 ( V_28 , ( void * ) V_33 , V_1 , V_6 ) ;
if ( V_29 )
V_33 += V_1 ;
}
if ( V_29 )
V_29 += V_26 & ~ V_25 ;
return V_29 ;
}
void T_6 * F_38 ( T_7 V_26 , unsigned long V_1 ,
unsigned long V_6 )
{
return F_34 ( V_26 , V_1 , V_6 , F_39 ( 0 ) ) ;
}
void T_6 * F_40 ( T_7 V_26 , unsigned long V_1 )
{
unsigned long V_6 = V_22 | V_36 ;
void * V_27 = F_39 ( 0 ) ;
if ( V_37 . F_40 )
return V_37 . F_40 ( V_26 , V_1 , V_6 , V_27 ) ;
return F_34 ( V_26 , V_1 , V_6 , V_27 ) ;
}
void T_6 * F_41 ( T_7 V_26 , unsigned long V_1 )
{
unsigned long V_6 = V_22 ;
void * V_27 = F_39 ( 0 ) ;
if ( V_37 . F_40 )
return V_37 . F_40 ( V_26 , V_1 , V_6 , V_27 ) ;
return F_34 ( V_26 , V_1 , V_6 , V_27 ) ;
}
void T_6 * F_42 ( T_7 V_26 , unsigned long V_1 ,
unsigned long V_6 )
{
void * V_27 = F_39 ( 0 ) ;
if ( V_6 & V_38 )
V_6 |= V_39 ;
V_6 &= ~ ( V_40 | V_41 ) ;
#ifdef F_43
V_6 |= F_43 ;
#endif
if ( V_37 . F_40 )
return V_37 . F_40 ( V_26 , V_1 , V_6 , V_27 ) ;
return F_34 ( V_26 , V_1 , V_6 , V_27 ) ;
}
void F_44 ( volatile void T_6 * V_42 )
{
void * V_26 ;
if ( ! F_6 () )
return;
V_26 = ( void * ) ( ( unsigned long V_43 )
F_45 ( V_42 ) & V_25 ) ;
if ( ( unsigned long ) V_26 < V_33 ) {
F_27 ( V_44 L_3
L_4 , V_26 ) ;
return;
}
F_37 ( V_26 ) ;
}
void F_46 ( volatile void T_6 * V_42 )
{
if ( V_37 . F_46 )
V_37 . F_46 ( V_42 ) ;
else
F_44 ( V_42 ) ;
}
struct V_45 * F_47 ( T_2 V_46 )
{
if ( F_48 ( V_46 ) )
return F_49 ( F_50 ( V_46 ) ) ;
return F_51 ( F_52 ( V_46 ) ) ;
}
struct V_45 * F_53 ( T_3 V_47 )
{
if ( F_54 ( V_47 ) )
return F_49 ( F_55 ( V_47 ) ) ;
return F_51 ( F_56 ( V_47 ) ) ;
}
struct V_45 * F_57 ( T_4 V_48 )
{
if ( F_58 ( V_48 ) || F_59 ( V_48 ) )
return F_49 ( F_60 ( V_48 ) ) ;
return F_51 ( F_61 ( V_48 ) ) ;
}
static T_5 * F_62 ( struct V_49 * V_50 )
{
void * V_51 , * V_29 ;
F_63 ( & V_50 -> V_52 ) ;
V_29 = V_50 -> V_53 . V_51 ;
if ( V_29 ) {
V_51 = V_29 + V_54 ;
if ( ( ( unsigned long ) V_51 & ~ V_25 ) == 0 )
V_51 = NULL ;
V_50 -> V_53 . V_51 = V_51 ;
}
F_64 ( & V_50 -> V_52 ) ;
return ( T_5 * ) V_29 ;
}
static T_5 * F_65 ( struct V_49 * V_50 , int V_55 )
{
void * V_29 = NULL ;
struct V_45 * V_45 = F_66 ( V_56 | V_57 |
V_58 | V_59 ) ;
if ( ! V_45 )
return NULL ;
if ( ! V_55 && ! F_67 ( V_45 ) ) {
F_68 ( V_45 ) ;
return NULL ;
}
V_29 = F_69 ( V_45 ) ;
F_63 ( & V_50 -> V_52 ) ;
if ( F_70 ( ! V_50 -> V_53 . V_51 ) ) {
F_71 ( & V_45 -> V_60 , V_61 ) ;
V_50 -> V_53 . V_51 = V_29 + V_54 ;
}
F_64 ( & V_50 -> V_52 ) ;
return ( T_5 * ) V_29 ;
}
T_5 * F_72 ( struct V_49 * V_50 , unsigned long V_62 , int V_55 )
{
T_5 * V_63 ;
V_63 = F_62 ( V_50 ) ;
if ( V_63 )
return V_63 ;
return F_65 ( V_50 , V_55 ) ;
}
void F_73 ( struct V_49 * V_50 , unsigned long * V_64 , int V_55 )
{
struct V_45 * V_45 = F_51 ( V_64 ) ;
if ( F_74 ( V_45 ) ) {
if ( ! V_55 )
F_75 ( V_45 ) ;
F_76 ( V_45 , 0 ) ;
}
}
static void F_77 ( void * V_64 )
{
struct V_45 * V_45 = F_51 ( V_64 ) ;
if ( F_74 ( V_45 ) ) {
F_75 ( V_45 ) ;
F_76 ( V_45 , 0 ) ;
}
}
void F_78 ( struct V_65 * V_66 , void * V_64 , int V_67 )
{
unsigned long V_68 = ( unsigned long ) V_64 ;
F_17 ( V_67 > V_69 ) ;
V_68 |= V_67 ;
F_79 ( V_66 , ( void * ) V_68 ) ;
}
void F_80 ( void * V_70 )
{
void * V_64 = ( void * ) ( ( unsigned long ) V_70 & ~ V_69 ) ;
unsigned V_67 = ( unsigned long ) V_70 & V_69 ;
if ( ! V_67 )
F_77 ( V_64 ) ;
else {
F_17 ( V_67 > V_69 ) ;
F_81 ( F_82 ( V_67 ) , V_64 ) ;
}
}
void F_78 ( struct V_65 * V_66 , void * V_64 , int V_67 )
{
if ( ! V_67 ) {
struct V_45 * V_45 = F_51 ( V_64 ) ;
if ( F_74 ( V_45 ) ) {
F_75 ( V_45 ) ;
F_76 ( V_45 , 0 ) ;
}
} else {
F_17 ( V_67 > V_69 ) ;
F_81 ( F_82 ( V_67 ) , V_64 ) ;
}
}
int F_83 ( struct V_71 * V_72 , unsigned long V_73 ,
T_4 * V_9 , T_4 V_74 , int V_75 )
{
int V_76 ;
#ifdef F_84
F_31 ( ! F_58 ( * V_9 ) ) ;
F_85 ( & V_72 -> V_77 -> V_52 ) ;
#endif
V_76 = ! F_86 ( * ( V_9 ) , V_74 ) ;
if ( V_76 ) {
F_87 ( F_88 ( V_9 ) , F_60 ( V_74 ) ) ;
}
return V_76 ;
}
unsigned long F_89 ( struct V_49 * V_50 , unsigned long V_26 ,
T_4 * V_9 , unsigned long V_78 ,
unsigned long V_79 )
{
unsigned long V_80 , V_81 ;
#ifdef F_84
F_31 ( ! F_58 ( * V_9 ) ) ;
F_85 ( & V_50 -> V_52 ) ;
#endif
#ifdef F_90
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
V_80 = F_91 ( * V_9 ) ;
* V_9 = F_92 ( ( V_80 & ~ V_78 ) | V_79 ) ;
#endif
F_93 ( V_26 , V_80 , V_78 , V_79 ) ;
if ( V_80 & V_82 )
F_94 ( V_50 , V_26 , V_9 , V_80 ) ;
return V_80 ;
}
T_4 F_95 ( struct V_71 * V_72 , unsigned long V_73 ,
T_4 * V_9 )
{
T_4 V_48 ;
F_96 ( V_73 & ~ V_83 ) ;
F_96 ( F_58 ( * V_9 ) ) ;
V_48 = * V_9 ;
F_97 ( V_9 ) ;
F_98 () ;
F_99 ( V_72 -> V_77 , & V_48 , V_73 ) ;
return V_48 ;
}
int F_100 ( struct V_71 * V_72 ,
unsigned long V_73 , T_4 * V_9 )
{
return F_101 ( V_72 -> V_77 , V_73 , V_9 ) ;
}
int F_102 ( struct V_71 * V_72 ,
unsigned long V_73 , T_4 * V_9 )
{
return F_101 ( V_72 -> V_77 , V_73 , V_9 ) ;
}
void F_103 ( struct V_49 * V_50 , T_4 * V_9 ,
T_8 V_84 )
{
T_8 * V_85 ;
F_85 ( & V_50 -> V_52 ) ;
V_85 = ( T_8 * ) V_9 + V_86 ;
* V_85 = V_84 ;
F_28 () ;
}
T_8 F_104 ( struct V_49 * V_50 , T_4 * V_9 )
{
T_8 V_84 ;
T_8 * V_85 ;
F_85 ( & V_50 -> V_52 ) ;
V_85 = ( T_8 * ) V_9 + V_86 ;
V_84 = * V_85 ;
* V_85 = NULL ;
memset ( V_84 , 0 , V_54 ) ;
return V_84 ;
}
void F_105 ( struct V_71 * V_72 ,
unsigned long V_73 , T_4 * V_9 )
{
F_96 ( V_73 & ~ V_83 ) ;
F_96 ( F_106 ( V_73 ) != V_87 ) ;
F_89 ( V_72 -> V_77 , V_73 , V_9 , V_40 , 0 ) ;
}
void F_107 ( struct V_49 * V_50 , unsigned long V_26 ,
T_4 * V_9 , T_4 V_48 )
{
#ifdef F_84
F_31 ( ( F_91 ( * V_9 ) & ( V_20 | V_40 ) ) ==
( V_20 | V_40 ) ) ;
F_85 ( & V_50 -> V_52 ) ;
F_31 ( ! F_58 ( V_48 ) ) ;
#endif
F_108 ( V_26 , F_91 ( V_48 ) ) ;
return F_11 ( V_50 , V_26 , F_88 ( V_9 ) , F_60 ( V_48 ) ) ;
}
void F_109 ( struct V_71 * V_72 , unsigned long V_73 ,
T_4 * V_9 )
{
F_89 ( V_72 -> V_77 , V_73 , V_9 , V_20 , 0 ) ;
F_98 () ;
}
void F_94 ( struct V_49 * V_50 , unsigned long V_26 ,
T_4 * V_9 , unsigned long V_88 )
{
int V_89 ;
unsigned int V_90 ;
unsigned long V_91 ;
unsigned long V_6 = 0 ;
const struct V_92 * V_81 ;
#ifdef F_84
V_90 = F_110 ( V_50 , V_26 ) ;
F_17 ( V_90 == V_93 ) ;
#endif
if ( V_88 & V_94 )
V_90 = V_95 ;
else
V_90 = V_96 ;
if ( ! F_111 ( V_26 ) ) {
V_89 = F_112 ( V_26 ) ;
V_91 = F_113 ( V_50 -> V_53 . V_97 , V_26 , V_89 ) ;
F_31 ( V_91 == 0 ) ;
} else {
V_91 = F_114 ( V_26 , V_17 ) ;
V_89 = V_17 ;
}
V_81 = F_115 ( F_116 () ) ;
if ( F_117 ( F_118 ( V_50 ) , V_81 ) )
V_6 |= V_98 ;
return F_119 ( V_91 , V_26 , V_9 , V_90 , V_89 , V_6 ) ;
}
static T_4 F_120 ( T_4 V_48 , T_9 V_99 )
{
return F_92 ( F_91 ( V_48 ) | F_30 ( V_99 ) ) ;
}
T_4 F_121 ( unsigned long V_100 , T_9 V_99 )
{
unsigned long V_101 ;
V_101 = V_100 << V_102 ;
return F_120 ( F_92 ( V_101 ) , V_99 ) ;
}
T_4 F_122 ( struct V_45 * V_45 , T_9 V_99 )
{
return F_121 ( F_123 ( V_45 ) , V_99 ) ;
}
T_4 F_124 ( T_4 V_48 , T_9 V_103 )
{
unsigned long V_101 ;
V_101 = F_91 ( V_48 ) ;
V_101 &= V_104 ;
return F_120 ( F_92 ( V_101 ) , V_103 ) ;
}
void F_125 ( struct V_71 * V_72 , unsigned long V_26 ,
T_4 * V_48 )
{
return;
}
T_4 F_126 ( struct V_49 * V_50 ,
unsigned long V_26 , T_4 * V_9 )
{
T_4 V_88 ;
T_8 V_84 ;
unsigned long V_80 ;
T_8 * V_85 ;
V_80 = F_89 ( V_50 , V_26 , V_9 , ~ 0UL , 0 ) ;
V_88 = F_92 ( V_80 ) ;
V_85 = ( T_8 * ) V_9 + V_86 ;
V_84 = * V_85 ;
memset ( V_84 , 0 , V_54 ) ;
F_98 () ;
return V_88 ;
}
int F_127 ( void )
{
if ( ! F_128 ( V_105 ) )
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
