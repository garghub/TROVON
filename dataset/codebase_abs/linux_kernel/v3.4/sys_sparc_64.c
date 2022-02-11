T_1 unsigned long F_1 ( void )
{
return V_1 ;
}
static inline int F_2 ( unsigned long V_2 , unsigned long V_3 )
{
unsigned long V_4 , V_5 ;
V_4 = V_6 ;
V_5 = V_7 ;
if ( F_3 ( V_3 >= V_4 ) )
return 1 ;
if ( F_3 ( ( V_2 + V_3 ) < V_2 ) )
return 1 ;
if ( F_3 ( ( V_2 >= V_4 && V_2 < V_5 ) ||
( ( V_2 + V_3 ) >= V_4 &&
( V_2 + V_3 ) < V_5 ) ) )
return 1 ;
return 0 ;
}
static inline int F_4 ( unsigned long V_8 , unsigned long V_9 )
{
unsigned long V_4 , V_5 ;
V_4 = V_6 ;
V_5 = V_7 ;
if ( F_5 ( V_8 < V_4 && V_9 < V_4 ) )
return 0 ;
if ( F_5 ( V_8 >= V_5 && V_9 >= V_5 ) )
return 0 ;
return 1 ;
}
static inline unsigned long F_6 ( unsigned long V_2 ,
unsigned long V_10 )
{
unsigned long V_11 = ( V_2 + V_12 - 1 ) & ~ ( V_12 - 1 ) ;
unsigned long V_13 = ( V_10 << V_14 ) & ( V_12 - 1 ) ;
return V_11 + V_13 ;
}
static inline unsigned long F_7 ( unsigned long V_2 ,
unsigned long V_10 )
{
unsigned long V_11 = V_2 & ~ ( V_12 - 1 ) ;
unsigned long V_13 = ( V_10 << V_14 ) & ( V_12 - 1 ) ;
if ( V_11 + V_13 <= V_2 )
return V_11 + V_13 ;
return V_11 - V_13 ;
}
unsigned long F_8 ( struct V_15 * V_16 , unsigned long V_2 , unsigned long V_3 , unsigned long V_10 , unsigned long V_17 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
struct V_21 * V_22 ;
unsigned long V_23 = V_24 ;
unsigned long V_25 ;
int V_26 ;
if ( V_17 & V_27 ) {
if ( ( V_17 & V_28 ) &&
( ( V_2 - ( V_10 << V_14 ) ) & ( V_12 - 1 ) ) )
return - V_29 ;
return V_2 ;
}
if ( F_9 ( V_30 ) )
V_23 = V_31 ;
if ( F_3 ( V_3 > V_23 || V_3 >= V_6 ) )
return - V_32 ;
V_26 = 0 ;
if ( V_16 || ( V_17 & V_28 ) )
V_26 = 1 ;
if ( V_2 ) {
if ( V_26 )
V_2 = F_6 ( V_2 , V_10 ) ;
else
V_2 = F_10 ( V_2 ) ;
V_22 = F_11 ( V_19 , V_2 ) ;
if ( V_23 - V_3 >= V_2 &&
( ! V_22 || V_2 + V_3 <= V_22 -> V_33 ) )
return V_2 ;
}
if ( V_3 > V_19 -> V_34 ) {
V_25 = V_2 = V_19 -> V_35 ;
} else {
V_25 = V_2 = V_36 ;
V_19 -> V_34 = 0 ;
}
V_23 -= V_3 ;
V_37:
if ( V_26 )
V_2 = F_6 ( V_2 , V_10 ) ;
else
V_2 = F_10 ( V_2 ) ;
for ( V_22 = F_11 ( V_19 , V_2 ) ; ; V_22 = V_22 -> V_38 ) {
if ( V_2 < V_6 &&
( V_2 + V_3 ) >= V_6 ) {
V_2 = V_7 ;
V_22 = F_11 ( V_19 , V_7 ) ;
}
if ( F_3 ( V_23 < V_2 ) ) {
if ( V_25 != V_36 ) {
V_25 = V_2 = V_36 ;
V_19 -> V_34 = 0 ;
goto V_37;
}
return - V_32 ;
}
if ( F_5 ( ! V_22 || V_2 + V_3 <= V_22 -> V_33 ) ) {
V_19 -> V_35 = V_2 + V_3 ;
return V_2 ;
}
if ( V_2 + V_19 -> V_34 < V_22 -> V_33 )
V_19 -> V_34 = V_22 -> V_33 - V_2 ;
V_2 = V_22 -> V_39 ;
if ( V_26 )
V_2 = F_6 ( V_2 , V_10 ) ;
}
}
unsigned long
F_12 ( struct V_15 * V_16 , const unsigned long V_40 ,
const unsigned long V_3 , const unsigned long V_10 ,
const unsigned long V_17 )
{
struct V_21 * V_22 ;
struct V_18 * V_19 = V_20 -> V_19 ;
unsigned long V_23 = V_31 ;
unsigned long V_2 = V_40 ;
int V_26 ;
F_13 ( ! F_9 ( V_30 ) ) ;
if ( V_17 & V_27 ) {
if ( ( V_17 & V_28 ) &&
( ( V_2 - ( V_10 << V_14 ) ) & ( V_12 - 1 ) ) )
return - V_29 ;
return V_2 ;
}
if ( F_3 ( V_3 > V_23 ) )
return - V_32 ;
V_26 = 0 ;
if ( V_16 || ( V_17 & V_28 ) )
V_26 = 1 ;
if ( V_2 ) {
if ( V_26 )
V_2 = F_6 ( V_2 , V_10 ) ;
else
V_2 = F_10 ( V_2 ) ;
V_22 = F_11 ( V_19 , V_2 ) ;
if ( V_23 - V_3 >= V_2 &&
( ! V_22 || V_2 + V_3 <= V_22 -> V_33 ) )
return V_2 ;
}
if ( V_3 <= V_19 -> V_34 ) {
V_19 -> V_34 = 0 ;
V_19 -> V_35 = V_19 -> V_41 ;
}
V_2 = V_19 -> V_35 ;
if ( V_26 ) {
unsigned long V_11 = F_7 ( V_2 - V_3 , V_10 ) ;
V_2 = V_11 + V_3 ;
}
if ( F_5 ( V_2 > V_3 ) ) {
V_22 = F_11 ( V_19 , V_2 - V_3 ) ;
if ( ! V_22 || V_2 <= V_22 -> V_33 ) {
return ( V_19 -> V_35 = V_2 - V_3 ) ;
}
}
if ( F_3 ( V_19 -> V_41 < V_3 ) )
goto V_42;
V_2 = V_19 -> V_41 - V_3 ;
if ( V_26 )
V_2 = F_7 ( V_2 , V_10 ) ;
do {
V_22 = F_11 ( V_19 , V_2 ) ;
if ( F_5 ( ! V_22 || V_2 + V_3 <= V_22 -> V_33 ) ) {
return ( V_19 -> V_35 = V_2 ) ;
}
if ( V_2 + V_19 -> V_34 < V_22 -> V_33 )
V_19 -> V_34 = V_22 -> V_33 - V_2 ;
V_2 = V_22 -> V_33 - V_3 ;
if ( V_26 )
V_2 = F_7 ( V_2 , V_10 ) ;
} while ( F_5 ( V_3 < V_22 -> V_33 ) );
V_42:
V_19 -> V_34 = ~ 0UL ;
V_19 -> V_35 = V_36 ;
V_2 = F_8 ( V_16 , V_40 , V_3 , V_10 , V_17 ) ;
V_19 -> V_35 = V_19 -> V_41 ;
V_19 -> V_34 = ~ 0UL ;
return V_2 ;
}
unsigned long F_14 ( struct V_15 * V_16 , unsigned long V_43 , unsigned long V_3 , unsigned long V_10 , unsigned long V_17 )
{
unsigned long V_44 , V_2 = - V_32 ;
unsigned long ( * V_45 ) ( struct V_15 * , unsigned long ,
unsigned long , unsigned long , unsigned long ) ;
V_45 = V_20 -> V_19 -> V_46 ;
if ( V_17 & V_27 ) {
return V_45 ( NULL , V_43 , V_3 , V_10 , V_17 ) ;
}
V_17 &= ~ V_28 ;
V_44 = V_1 ;
if ( V_3 >= ( 4UL * 1024 * 1024 ) )
V_44 = ( 4UL * 1024 * 1024 ) ;
else if ( V_3 >= ( 512UL * 1024 ) )
V_44 = ( 512UL * 1024 ) ;
else if ( V_3 >= ( 64UL * 1024 ) )
V_44 = ( 64UL * 1024 ) ;
do {
V_2 = V_45 ( NULL , V_43 , V_3 + ( V_44 - V_1 ) , V_10 , V_17 ) ;
if ( ! ( V_2 & ~ V_47 ) ) {
V_2 = ( V_2 + ( V_44 - 1UL ) ) & ~ ( V_44 - 1UL ) ;
break;
}
if ( V_44 == ( 4UL * 1024 * 1024 ) )
V_44 = ( 512UL * 1024 ) ;
else if ( V_44 == ( 512UL * 1024 ) )
V_44 = ( 64UL * 1024 ) ;
else
V_44 = V_1 ;
} while ( ( V_2 & ~ V_47 ) && V_44 > V_1 );
if ( V_2 & ~ V_47 )
V_2 = V_45 ( NULL , V_43 , V_3 , V_10 , V_17 ) ;
return V_2 ;
}
static unsigned long F_15 ( void )
{
unsigned long V_48 = 0UL ;
if ( V_20 -> V_17 & V_49 ) {
unsigned long V_50 = F_16 () ;
if ( F_9 ( V_30 ) )
V_48 = ( V_50 % ( 1UL << ( 23UL - V_14 ) ) ) ;
else
V_48 = ( V_50 % ( 1UL << ( 30UL - V_14 ) ) ) ;
}
return V_48 << V_14 ;
}
void F_17 ( struct V_18 * V_19 )
{
unsigned long V_51 = F_15 () ;
unsigned long V_52 ;
V_52 = F_18 ( V_53 ) ;
if ( ! F_9 ( V_30 ) ||
( V_20 -> V_54 & V_55 ) ||
V_52 == V_56 ||
V_57 ) {
V_19 -> V_41 = V_36 + V_51 ;
V_19 -> V_46 = F_8 ;
V_19 -> V_58 = V_59 ;
} else {
unsigned long V_23 = V_31 ;
if ( V_52 < 128 * 1024 * 1024 )
V_52 = 128 * 1024 * 1024 ;
if ( V_52 > ( V_23 / 6 * 5 ) )
V_52 = ( V_23 / 6 * 5 ) ;
V_19 -> V_41 = F_10 ( V_23 - V_52 - V_51 ) ;
V_19 -> V_46 = F_12 ;
V_19 -> V_58 = V_60 ;
}
}
int F_19 ( unsigned long V_2 , unsigned long V_3 )
{
if ( F_9 ( V_30 ) ) {
if ( V_3 >= V_31 )
return - V_29 ;
if ( V_2 > V_31 - V_3 )
return - V_29 ;
} else {
if ( V_3 >= V_6 )
return - V_29 ;
if ( F_2 ( V_2 , V_3 ) )
return - V_29 ;
}
return 0 ;
}
T_1 unsigned long F_20 ( struct V_61 * V_62 )
{
static int V_63 ;
if ( V_63 ++ > 5 )
return - V_64 ;
F_21 ( L_1 , V_62 -> V_65 [ 1 ] ) ;
#ifdef F_22
F_23 ( V_62 ) ;
#endif
return - V_64 ;
}
T_1 void F_24 ( struct V_61 * V_62 )
{
T_2 V_66 ;
if ( F_9 ( V_30 ) ) {
V_62 -> V_67 &= 0xffffffff ;
V_62 -> V_68 &= 0xffffffff ;
}
#ifdef F_25
F_21 ( L_2 , V_62 -> V_67 , V_62 -> V_68 ) ;
#endif
V_66 . V_69 = V_70 ;
V_66 . V_71 = 0 ;
V_66 . V_72 = V_73 ;
V_66 . V_74 = ( void V_75 * ) V_62 -> V_67 ;
V_66 . V_76 = 0 ;
F_26 ( V_70 , & V_66 , V_20 ) ;
#ifdef F_25
F_21 ( L_3 , V_62 -> V_67 , V_62 -> V_68 ) ;
#endif
}
T_1 long F_27 ( unsigned long V_77 ,
struct V_61 * V_62 )
{
if ( V_77 >= 3 )
return - V_29 ;
V_62 -> V_78 = ( V_62 -> V_78 & ~ V_79 ) | ( V_77 << 14 ) ;
return 0 ;
}
int F_28 ( const char * V_80 ,
const char * const V_81 [] ,
const char * const V_82 [] )
{
long V_83 ;
register long T_3 V_84 ( L_4 ) = V_85 ;
register long T_4 V_84 ( L_5 ) = ( long ) ( V_80 ) ;
register long T_5 V_84 ( L_6 ) = ( long ) ( V_81 ) ;
register long T_6 V_84 ( L_7 ) = ( long ) ( V_82 ) ;
asm volatile ("t 0x6d\n\t"
"sub %%g0, %%o0, %0\n\t"
"movcc %%xcc, %%o0, %0\n\t"
: "=r" (__res), "=&r" (__o0)
: "1" (__o0), "r" (__o1), "r" (__o2), "r" (__g1)
: "cc");
return V_83 ;
}
