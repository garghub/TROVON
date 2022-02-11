static T_1 void * F_1 ( unsigned long V_1 )
{
void * V_2 ;
if ( V_3 )
V_2 = F_2 ( V_1 , V_1 , F_3 ( V_4 ) ) ;
else
V_2 = F_4 ( F_5 ( V_1 , V_1 ,
F_3 ( V_4 ) ) ) ;
memset ( V_2 , 0 , V_1 ) ;
return V_2 ;
}
int F_6 ( unsigned long V_5 , unsigned long V_6 , int V_7 )
{
T_2 * V_8 ;
T_3 * V_9 ;
T_4 * V_10 ;
T_5 * V_11 ;
if ( F_7 () ) {
V_8 = F_8 ( V_5 ) ;
V_9 = F_9 ( & V_12 , V_8 , V_5 ) ;
if ( ! V_9 )
return - V_13 ;
V_10 = F_10 ( & V_12 , V_9 , V_5 ) ;
if ( ! V_10 )
return - V_13 ;
V_11 = F_11 ( V_10 , V_5 ) ;
if ( ! V_11 )
return - V_13 ;
F_12 ( & V_12 , V_5 , V_11 , F_13 ( V_6 >> V_14 ,
F_14 ( V_7 ) ) ) ;
} else {
#ifdef F_15
V_8 = F_8 ( V_5 ) ;
#ifdef F_16
if ( F_17 ( * V_8 ) ) {
V_9 = F_1 ( F_16 ) ;
F_18 ( V_9 == NULL ) ;
F_19 ( & V_12 , V_8 , V_9 ) ;
}
#endif
V_9 = F_20 ( V_8 , V_5 ) ;
if ( F_21 ( * V_9 ) ) {
V_10 = F_1 ( V_15 ) ;
F_18 ( V_10 == NULL ) ;
F_22 ( & V_12 , V_9 , V_10 ) ;
}
V_10 = F_23 ( V_9 , V_5 ) ;
if ( ! F_24 ( * V_10 ) ) {
V_11 = F_1 ( V_16 ) ;
F_18 ( V_11 == NULL ) ;
F_25 ( & V_12 , V_10 , V_11 ) ;
}
V_11 = F_26 ( V_10 , V_5 ) ;
F_12 ( & V_12 , V_5 , V_11 , F_13 ( V_6 >> V_14 ,
F_14 ( V_7 ) ) ) ;
#else
if ( F_27 ( V_5 , V_5 + V_16 , V_6 , V_7 ,
V_17 , V_18 ) ) {
F_28 ( V_19 L_1
L_2 , V_6 ) ;
return - V_13 ;
}
#endif
}
#ifdef F_29
F_30 () ;
#else
F_31 () ;
#endif
return 0 ;
}
void T_6 * F_32 ( T_7 V_6 , void * V_5 , unsigned long V_1 ,
unsigned long V_7 )
{
unsigned long V_20 ;
if ( ( V_7 & V_21 ) == 0 )
V_7 |= F_33 ( V_22 ) ;
if ( V_7 & V_23 )
V_7 &= ~ V_24 ;
if ( V_7 & V_25 )
return NULL ;
F_34 ( V_6 & ~ V_26 ) ;
F_34 ( ( ( unsigned long ) V_5 ) & ~ V_26 ) ;
F_34 ( V_1 & ~ V_26 ) ;
for ( V_20 = 0 ; V_20 < V_1 ; V_20 += V_16 )
if ( F_6 ( ( unsigned long ) V_5 + V_20 , V_6 + V_20 , V_7 ) )
return NULL ;
return ( void T_6 * ) V_5 ;
}
void F_35 ( void * V_5 , unsigned long V_1 )
{
F_34 ( ( ( unsigned long ) V_5 ) & ~ V_26 ) ;
F_34 ( V_1 & ~ V_26 ) ;
F_36 ( ( unsigned long ) V_5 , V_1 ) ;
}
void T_6 * F_37 ( T_7 V_27 , unsigned long V_1 ,
unsigned long V_7 , void * V_28 )
{
T_7 V_29 ;
void T_6 * V_30 ;
V_29 = V_27 & V_26 ;
V_1 = F_38 ( V_27 + V_1 ) - V_29 ;
if ( ( V_1 == 0 ) || ( V_29 == 0 ) )
return NULL ;
if ( V_31 ) {
struct V_32 * V_33 ;
V_33 = F_39 ( V_1 , V_34 ,
V_35 , V_36 ,
V_28 ) ;
if ( V_33 == NULL )
return NULL ;
V_33 -> V_37 = V_29 ;
V_30 = F_32 ( V_29 , V_33 -> V_27 , V_1 , V_7 ) ;
if ( ! V_30 )
F_40 ( V_33 -> V_27 ) ;
} else {
V_30 = F_32 ( V_29 , ( void * ) V_35 , V_1 , V_7 ) ;
if ( V_30 )
V_35 += V_1 ;
}
if ( V_30 )
V_30 += V_27 & ~ V_26 ;
return V_30 ;
}
void T_6 * F_41 ( T_7 V_27 , unsigned long V_1 ,
unsigned long V_7 )
{
return F_37 ( V_27 , V_1 , V_7 , F_42 ( 0 ) ) ;
}
void T_6 * F_43 ( T_7 V_27 , unsigned long V_1 )
{
unsigned long V_7 = V_23 | V_38 ;
void * V_28 = F_42 ( 0 ) ;
if ( V_39 . F_43 )
return V_39 . F_43 ( V_27 , V_1 , V_7 , V_28 ) ;
return F_37 ( V_27 , V_1 , V_7 , V_28 ) ;
}
void T_6 * F_44 ( T_7 V_27 , unsigned long V_1 )
{
unsigned long V_7 = V_23 ;
void * V_28 = F_42 ( 0 ) ;
if ( V_39 . F_43 )
return V_39 . F_43 ( V_27 , V_1 , V_7 , V_28 ) ;
return F_37 ( V_27 , V_1 , V_7 , V_28 ) ;
}
void T_6 * F_45 ( T_7 V_27 , unsigned long V_1 ,
unsigned long V_7 )
{
void * V_28 = F_42 ( 0 ) ;
if ( V_7 & V_40 )
V_7 |= V_41 ;
V_7 &= ~ ( V_42 | V_43 ) ;
#ifdef F_46
V_7 |= F_46 ;
#endif
if ( V_39 . F_43 )
return V_39 . F_43 ( V_27 , V_1 , V_7 , V_28 ) ;
return F_37 ( V_27 , V_1 , V_7 , V_28 ) ;
}
void F_47 ( volatile void T_6 * V_44 )
{
void * V_27 ;
if ( ! V_31 )
return;
V_27 = ( void * ) ( ( unsigned long V_45 )
F_48 ( V_44 ) & V_26 ) ;
if ( ( unsigned long ) V_27 < V_35 ) {
F_28 ( V_46 L_3
L_4 , V_27 ) ;
return;
}
F_40 ( V_27 ) ;
}
void F_49 ( volatile void T_6 * V_44 )
{
if ( V_39 . F_49 )
V_39 . F_49 ( V_44 ) ;
else
F_47 ( V_44 ) ;
}
struct V_47 * F_50 ( T_4 V_48 )
{
#ifdef F_51
if ( F_52 ( V_48 ) )
return F_53 ( F_54 ( V_48 ) ) ;
#endif
return F_55 ( F_56 ( V_48 ) ) ;
}
static T_5 * F_57 ( struct V_49 * V_50 )
{
void * V_51 , * V_30 ;
F_58 ( & V_50 -> V_52 ) ;
V_30 = V_50 -> V_53 . V_51 ;
if ( V_30 ) {
V_51 = V_30 + V_54 ;
if ( ( ( unsigned long ) V_51 & ~ V_26 ) == 0 )
V_51 = NULL ;
V_50 -> V_53 . V_51 = V_51 ;
}
F_59 ( & V_50 -> V_52 ) ;
return ( T_5 * ) V_30 ;
}
static T_5 * F_60 ( struct V_49 * V_50 , int V_55 )
{
void * V_30 = NULL ;
struct V_47 * V_47 = F_61 ( V_56 | V_57 |
V_58 | V_59 ) ;
if ( ! V_47 )
return NULL ;
if ( ! V_55 && ! F_62 ( V_47 ) ) {
F_63 ( V_47 ) ;
return NULL ;
}
V_30 = F_64 ( V_47 ) ;
F_58 ( & V_50 -> V_52 ) ;
if ( F_65 ( ! V_50 -> V_53 . V_51 ) ) {
F_66 ( & V_47 -> V_60 , V_61 ) ;
V_50 -> V_53 . V_51 = V_30 + V_54 ;
}
F_59 ( & V_50 -> V_52 ) ;
return ( T_5 * ) V_30 ;
}
T_5 * F_67 ( struct V_49 * V_50 , unsigned long V_62 , int V_55 )
{
T_5 * V_63 ;
V_63 = F_57 ( V_50 ) ;
if ( V_63 )
return V_63 ;
return F_60 ( V_50 , V_55 ) ;
}
void F_68 ( struct V_49 * V_50 , unsigned long * V_64 , int V_55 )
{
struct V_47 * V_47 = F_55 ( V_64 ) ;
if ( F_69 ( V_47 ) ) {
if ( ! V_55 )
F_70 ( V_47 ) ;
F_71 ( V_47 , 0 ) ;
}
}
static void F_72 ( void * V_64 )
{
struct V_47 * V_47 = F_55 ( V_64 ) ;
if ( F_69 ( V_47 ) ) {
F_70 ( V_47 ) ;
F_71 ( V_47 , 0 ) ;
}
}
void F_73 ( struct V_65 * V_66 , void * V_64 , int V_67 )
{
unsigned long V_68 = ( unsigned long ) V_64 ;
F_18 ( V_67 > V_69 ) ;
V_68 |= V_67 ;
F_74 ( V_66 , ( void * ) V_68 ) ;
}
void F_75 ( void * V_70 )
{
void * V_64 = ( void * ) ( ( unsigned long ) V_70 & ~ V_69 ) ;
unsigned V_67 = ( unsigned long ) V_70 & V_69 ;
if ( ! V_67 )
F_72 ( V_64 ) ;
else {
F_18 ( V_67 > V_69 ) ;
F_76 ( F_77 ( V_67 ) , V_64 ) ;
}
}
void F_73 ( struct V_65 * V_66 , void * V_64 , int V_67 )
{
if ( ! V_67 ) {
struct V_47 * V_47 = F_55 ( V_64 ) ;
if ( F_69 ( V_47 ) ) {
F_70 ( V_47 ) ;
F_71 ( V_47 , 0 ) ;
}
} else {
F_18 ( V_67 > V_69 ) ;
F_76 ( F_77 ( V_67 ) , V_64 ) ;
}
}
int F_78 ( struct V_71 * V_72 , unsigned long V_73 ,
T_4 * V_10 , T_4 V_74 , int V_75 )
{
int V_76 ;
#ifdef F_79
F_34 ( ! F_52 ( * V_10 ) ) ;
F_80 ( & V_72 -> V_77 -> V_52 ) ;
#endif
V_76 = ! F_81 ( * ( V_10 ) , V_74 ) ;
if ( V_76 ) {
F_82 ( F_83 ( V_10 ) , F_84 ( V_74 ) ) ;
}
return V_76 ;
}
unsigned long F_85 ( struct V_49 * V_50 , unsigned long V_27 ,
T_4 * V_10 , unsigned long V_78 ,
unsigned long V_79 )
{
unsigned long V_80 , V_81 ;
#ifdef F_79
F_34 ( ! F_52 ( * V_10 ) ) ;
F_80 ( & V_50 -> V_52 ) ;
#endif
#ifdef F_86
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
V_80 = F_87 ( * V_10 ) ;
* V_10 = F_88 ( ( V_80 & ~ V_78 ) | V_79 ) ;
#endif
F_89 ( V_27 , V_80 , V_78 , V_79 ) ;
if ( V_80 & V_82 )
F_90 ( V_50 , V_27 , V_10 , V_80 ) ;
return V_80 ;
}
T_4 F_91 ( struct V_71 * V_72 , unsigned long V_73 ,
T_4 * V_10 )
{
T_4 V_48 ;
F_92 ( V_73 & ~ V_83 ) ;
if ( F_52 ( * V_10 ) ) {
V_48 = F_93 ( V_72 -> V_77 , V_73 , V_10 ) ;
} else {
V_48 = * V_10 ;
F_94 ( V_10 ) ;
F_95 () ;
F_96 ( V_72 -> V_77 , & V_48 , V_73 ) ;
}
return V_48 ;
}
int F_97 ( struct V_71 * V_72 ,
unsigned long V_73 , T_4 * V_10 )
{
return F_98 ( V_72 -> V_77 , V_73 , V_10 ) ;
}
int F_99 ( struct V_71 * V_72 ,
unsigned long V_73 , T_4 * V_10 )
{
return F_98 ( V_72 -> V_77 , V_73 , V_10 ) ;
}
void F_100 ( struct V_71 * V_72 ,
unsigned long V_73 , T_4 * V_10 )
{
unsigned long V_80 , V_81 ;
F_92 ( V_73 & ~ V_83 ) ;
#ifdef F_79
F_34 ( ! F_52 ( * V_10 ) ) ;
F_80 ( & V_72 -> V_77 -> V_52 ) ;
#endif
#ifdef F_86
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
V_80 = F_87 ( * V_10 ) ;
* V_10 = F_88 ( V_80 | V_84 ) ;
#endif
F_101 ( V_73 , V_80 ) ;
if ( ! ( V_80 & V_84 ) ) {
if ( V_80 & V_82 )
F_90 ( V_72 -> V_77 , V_73 , V_10 , V_80 ) ;
}
F_95 () ;
}
void F_102 ( struct V_49 * V_50 , T_4 * V_10 ,
T_8 V_85 )
{
T_8 * V_86 ;
F_80 ( & V_50 -> V_52 ) ;
V_86 = ( T_8 * ) V_10 + V_87 ;
* V_86 = V_85 ;
F_31 () ;
}
T_8 F_103 ( struct V_49 * V_50 , T_4 * V_10 )
{
T_8 V_85 ;
T_8 * V_86 ;
F_80 ( & V_50 -> V_52 ) ;
V_86 = ( T_8 * ) V_10 + V_87 ;
V_85 = * V_86 ;
* V_86 = NULL ;
memset ( V_85 , 0 , V_54 ) ;
return V_85 ;
}
void F_104 ( struct V_49 * V_50 , unsigned long V_27 ,
T_4 * V_10 , T_4 V_48 )
{
#ifdef F_79
F_34 ( F_87 ( * V_10 ) & V_21 ) ;
F_80 ( & V_50 -> V_52 ) ;
F_34 ( ! F_52 ( V_48 ) ) ;
#endif
F_105 ( V_27 , V_48 ) ;
return F_12 ( V_50 , V_27 , F_83 ( V_10 ) , F_84 ( V_48 ) ) ;
}
void F_106 ( struct V_71 * V_72 , unsigned long V_73 ,
T_4 * V_10 )
{
F_85 ( V_72 -> V_77 , V_73 , V_10 , V_21 , 0 ) ;
}
void F_90 ( struct V_49 * V_50 , unsigned long V_27 ,
T_4 * V_10 , unsigned long V_88 )
{
int V_89 , V_20 ;
unsigned long V_90 ;
int V_91 ;
unsigned int V_92 , V_93 ;
unsigned char * V_94 ;
unsigned long V_95 , V_96 , V_97 , V_98 , V_67 , V_99 ;
V_90 = V_27 & V_83 ;
V_94 = F_107 ( V_10 ) ;
if ( ! V_94 )
return;
#ifdef F_79
V_92 = F_108 ( V_50 , V_90 ) ;
F_18 ( V_92 == V_100 ) ;
#endif
if ( V_88 & V_101 )
V_92 = V_102 ;
else
V_92 = V_103 ;
if ( ! F_109 ( V_90 ) ) {
V_89 = F_110 ( V_90 ) ;
V_97 = F_111 ( V_50 -> V_53 . V_104 , V_90 , V_89 ) ;
F_34 ( V_97 == 0 ) ;
} else {
V_97 = F_112 ( V_90 , V_18 ) ;
V_89 = V_18 ;
}
if ( V_39 . V_105 )
return V_39 . V_105 ( V_97 , V_90 ,
V_94 ,
V_92 , V_89 ) ;
V_67 = V_106 [ V_92 ] . V_67 ;
V_91 = V_107 >> V_67 ;
for ( V_20 = 0 ; V_20 < V_91 ; V_20 ++ ) {
V_93 = F_113 ( V_94 , V_20 ) ;
if ( ! V_93 )
continue;
V_95 = F_114 ( V_94 , V_20 ) ;
V_27 = V_90 + ( V_20 * ( 1ul << V_67 ) ) ;
V_96 = F_115 ( V_27 , V_97 , V_89 ) ;
V_98 = F_116 ( V_96 , V_67 , V_89 ) ;
if ( V_95 & V_108 )
V_98 = ~ V_98 ;
V_99 = ( V_98 & V_109 ) * V_110 ;
V_99 += V_95 & V_111 ;
V_39 . V_112 ( V_99 , V_96 , V_92 ,
V_100 , V_89 , 0 ) ;
}
}
static T_4 F_117 ( T_4 V_48 , T_9 V_113 )
{
F_87 ( V_48 ) |= F_33 ( V_113 ) ;
return V_48 ;
}
T_4 F_118 ( unsigned long V_114 , T_9 V_113 )
{
T_4 V_48 ;
F_87 ( V_48 ) = V_114 << V_115 ;
F_87 ( V_48 ) |= V_116 ;
V_48 = F_117 ( V_48 , V_113 ) ;
return V_48 ;
}
T_4 F_119 ( struct V_47 * V_47 , T_9 V_113 )
{
return F_118 ( F_120 ( V_47 ) , V_113 ) ;
}
T_4 F_121 ( T_4 V_48 , T_9 V_117 )
{
F_87 ( V_48 ) &= V_118 ;
V_48 = F_117 ( V_48 , V_117 ) ;
return V_48 ;
}
void F_122 ( struct V_71 * V_72 , unsigned long V_27 ,
T_4 * V_48 )
{
return;
}
T_4 F_93 ( struct V_49 * V_50 ,
unsigned long V_27 , T_4 * V_10 )
{
T_4 V_88 ;
T_8 V_85 ;
unsigned long V_80 ;
T_8 * V_86 ;
V_80 = F_85 ( V_50 , V_27 , V_10 , ~ 0UL , 0 ) ;
V_88 = F_88 ( V_80 ) ;
V_86 = ( T_8 * ) V_10 + V_87 ;
V_85 = * V_86 ;
memset ( V_85 , 0 , V_54 ) ;
return V_88 ;
}
int F_123 ( void )
{
if ( ! F_124 ( V_119 ) )
return 0 ;
if ( V_106 [ V_100 ] . V_67 != V_120 )
return 0 ;
if ( V_106 [ V_103 ] . V_67 &&
( V_106 [ V_103 ] . V_121 [ V_100 ] == - 1 ) )
return 0 ;
if ( V_106 [ V_102 ] . V_121 [ V_100 ] == - 1 )
return 0 ;
return 1 ;
}
