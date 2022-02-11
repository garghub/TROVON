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
static inline unsigned long F_4 ( unsigned long V_2 ,
unsigned long V_8 )
{
unsigned long V_9 = ( V_2 + V_10 - 1 ) & ~ ( V_10 - 1 ) ;
unsigned long V_11 = ( V_8 << V_12 ) & ( V_10 - 1 ) ;
return V_9 + V_11 ;
}
static inline unsigned long F_5 ( unsigned long V_2 ,
unsigned long V_8 )
{
unsigned long V_9 = V_2 & ~ ( V_10 - 1 ) ;
unsigned long V_11 = ( V_8 << V_12 ) & ( V_10 - 1 ) ;
if ( V_9 + V_11 <= V_2 )
return V_9 + V_11 ;
return V_9 - V_11 ;
}
unsigned long F_6 ( struct V_13 * V_14 , unsigned long V_2 , unsigned long V_3 , unsigned long V_8 , unsigned long V_15 )
{
struct V_16 * V_17 = V_18 -> V_17 ;
struct V_19 * V_20 ;
unsigned long V_21 = V_22 ;
unsigned long V_23 ;
int V_24 ;
if ( V_15 & V_25 ) {
if ( ( V_15 & V_26 ) &&
( ( V_2 - ( V_8 << V_12 ) ) & ( V_10 - 1 ) ) )
return - V_27 ;
return V_2 ;
}
if ( F_7 ( V_28 ) )
V_21 = V_29 ;
if ( F_3 ( V_3 > V_21 || V_3 >= V_6 ) )
return - V_30 ;
V_24 = 0 ;
if ( V_14 || ( V_15 & V_26 ) )
V_24 = 1 ;
if ( V_2 ) {
if ( V_24 )
V_2 = F_4 ( V_2 , V_8 ) ;
else
V_2 = F_8 ( V_2 ) ;
V_20 = F_9 ( V_17 , V_2 ) ;
if ( V_21 - V_3 >= V_2 &&
( ! V_20 || V_2 + V_3 <= V_20 -> V_31 ) )
return V_2 ;
}
if ( V_3 > V_17 -> V_32 ) {
V_23 = V_2 = V_17 -> V_33 ;
} else {
V_23 = V_2 = V_34 ;
V_17 -> V_32 = 0 ;
}
V_21 -= V_3 ;
V_35:
if ( V_24 )
V_2 = F_4 ( V_2 , V_8 ) ;
else
V_2 = F_8 ( V_2 ) ;
for ( V_20 = F_9 ( V_17 , V_2 ) ; ; V_20 = V_20 -> V_36 ) {
if ( V_2 < V_6 &&
( V_2 + V_3 ) >= V_6 ) {
V_2 = V_7 ;
V_20 = F_9 ( V_17 , V_7 ) ;
}
if ( F_3 ( V_21 < V_2 ) ) {
if ( V_23 != V_34 ) {
V_23 = V_2 = V_34 ;
V_17 -> V_32 = 0 ;
goto V_35;
}
return - V_30 ;
}
if ( F_10 ( ! V_20 || V_2 + V_3 <= V_20 -> V_31 ) ) {
V_17 -> V_33 = V_2 + V_3 ;
return V_2 ;
}
if ( V_2 + V_17 -> V_32 < V_20 -> V_31 )
V_17 -> V_32 = V_20 -> V_31 - V_2 ;
V_2 = V_20 -> V_37 ;
if ( V_24 )
V_2 = F_4 ( V_2 , V_8 ) ;
}
}
unsigned long
F_11 ( struct V_13 * V_14 , const unsigned long V_38 ,
const unsigned long V_3 , const unsigned long V_8 ,
const unsigned long V_15 )
{
struct V_19 * V_20 ;
struct V_16 * V_17 = V_18 -> V_17 ;
unsigned long V_21 = V_29 ;
unsigned long V_2 = V_38 ;
int V_24 ;
F_12 ( ! F_7 ( V_28 ) ) ;
if ( V_15 & V_25 ) {
if ( ( V_15 & V_26 ) &&
( ( V_2 - ( V_8 << V_12 ) ) & ( V_10 - 1 ) ) )
return - V_27 ;
return V_2 ;
}
if ( F_3 ( V_3 > V_21 ) )
return - V_30 ;
V_24 = 0 ;
if ( V_14 || ( V_15 & V_26 ) )
V_24 = 1 ;
if ( V_2 ) {
if ( V_24 )
V_2 = F_4 ( V_2 , V_8 ) ;
else
V_2 = F_8 ( V_2 ) ;
V_20 = F_9 ( V_17 , V_2 ) ;
if ( V_21 - V_3 >= V_2 &&
( ! V_20 || V_2 + V_3 <= V_20 -> V_31 ) )
return V_2 ;
}
if ( V_3 <= V_17 -> V_32 ) {
V_17 -> V_32 = 0 ;
V_17 -> V_33 = V_17 -> V_39 ;
}
V_2 = V_17 -> V_33 ;
if ( V_24 ) {
unsigned long V_9 = F_5 ( V_2 - V_3 , V_8 ) ;
V_2 = V_9 + V_3 ;
}
if ( F_10 ( V_2 > V_3 ) ) {
V_20 = F_9 ( V_17 , V_2 - V_3 ) ;
if ( ! V_20 || V_2 <= V_20 -> V_31 ) {
return ( V_17 -> V_33 = V_2 - V_3 ) ;
}
}
if ( F_3 ( V_17 -> V_39 < V_3 ) )
goto V_40;
V_2 = V_17 -> V_39 - V_3 ;
if ( V_24 )
V_2 = F_5 ( V_2 , V_8 ) ;
do {
V_20 = F_9 ( V_17 , V_2 ) ;
if ( F_10 ( ! V_20 || V_2 + V_3 <= V_20 -> V_31 ) ) {
return ( V_17 -> V_33 = V_2 ) ;
}
if ( V_2 + V_17 -> V_32 < V_20 -> V_31 )
V_17 -> V_32 = V_20 -> V_31 - V_2 ;
V_2 = V_20 -> V_31 - V_3 ;
if ( V_24 )
V_2 = F_5 ( V_2 , V_8 ) ;
} while ( F_10 ( V_3 < V_20 -> V_31 ) );
V_40:
V_17 -> V_32 = ~ 0UL ;
V_17 -> V_33 = V_34 ;
V_2 = F_6 ( V_14 , V_38 , V_3 , V_8 , V_15 ) ;
V_17 -> V_33 = V_17 -> V_39 ;
V_17 -> V_32 = ~ 0UL ;
return V_2 ;
}
unsigned long F_13 ( struct V_13 * V_14 , unsigned long V_41 , unsigned long V_3 , unsigned long V_8 , unsigned long V_15 )
{
unsigned long V_42 , V_2 = - V_30 ;
unsigned long ( * V_43 ) ( struct V_13 * , unsigned long ,
unsigned long , unsigned long , unsigned long ) ;
V_43 = V_18 -> V_17 -> V_44 ;
if ( V_15 & V_25 ) {
return V_43 ( NULL , V_41 , V_3 , V_8 , V_15 ) ;
}
V_15 &= ~ V_26 ;
V_42 = V_1 ;
if ( V_3 >= ( 4UL * 1024 * 1024 ) )
V_42 = ( 4UL * 1024 * 1024 ) ;
else if ( V_3 >= ( 512UL * 1024 ) )
V_42 = ( 512UL * 1024 ) ;
else if ( V_3 >= ( 64UL * 1024 ) )
V_42 = ( 64UL * 1024 ) ;
do {
V_2 = V_43 ( NULL , V_41 , V_3 + ( V_42 - V_1 ) , V_8 , V_15 ) ;
if ( ! ( V_2 & ~ V_45 ) ) {
V_2 = ( V_2 + ( V_42 - 1UL ) ) & ~ ( V_42 - 1UL ) ;
break;
}
if ( V_42 == ( 4UL * 1024 * 1024 ) )
V_42 = ( 512UL * 1024 ) ;
else if ( V_42 == ( 512UL * 1024 ) )
V_42 = ( 64UL * 1024 ) ;
else
V_42 = V_1 ;
} while ( ( V_2 & ~ V_45 ) && V_42 > V_1 );
if ( V_2 & ~ V_45 )
V_2 = V_43 ( NULL , V_41 , V_3 , V_8 , V_15 ) ;
return V_2 ;
}
static unsigned long F_14 ( void )
{
unsigned long V_46 = 0UL ;
if ( V_18 -> V_15 & V_47 ) {
unsigned long V_48 = F_15 () ;
if ( F_7 ( V_28 ) )
V_46 = ( V_48 % ( 1UL << ( 23UL - V_12 ) ) ) ;
else
V_46 = ( V_48 % ( 1UL << ( 30UL - V_12 ) ) ) ;
}
return V_46 << V_12 ;
}
void F_16 ( struct V_16 * V_17 )
{
unsigned long V_49 = F_14 () ;
unsigned long V_50 ;
V_50 = F_17 ( V_51 ) ;
if ( ! F_7 ( V_28 ) ||
( V_18 -> V_52 & V_53 ) ||
V_50 == V_54 ||
V_55 ) {
V_17 -> V_39 = V_34 + V_49 ;
V_17 -> V_44 = F_6 ;
V_17 -> V_56 = V_57 ;
} else {
unsigned long V_21 = V_29 ;
if ( V_50 < 128 * 1024 * 1024 )
V_50 = 128 * 1024 * 1024 ;
if ( V_50 > ( V_21 / 6 * 5 ) )
V_50 = ( V_21 / 6 * 5 ) ;
V_17 -> V_39 = F_8 ( V_21 - V_50 - V_49 ) ;
V_17 -> V_44 = F_11 ;
V_17 -> V_56 = V_58 ;
}
}
int F_18 ( unsigned long V_2 , unsigned long V_3 )
{
if ( F_7 ( V_28 ) ) {
if ( V_3 >= V_29 )
return - V_27 ;
if ( V_2 > V_29 - V_3 )
return - V_27 ;
} else {
if ( V_3 >= V_6 )
return - V_27 ;
if ( F_2 ( V_2 , V_3 ) )
return - V_27 ;
}
return 0 ;
}
T_1 unsigned long F_19 ( struct V_59 * V_60 )
{
static int V_61 ;
if ( V_61 ++ > 5 )
return - V_62 ;
F_20 ( L_1 , V_60 -> V_63 [ 1 ] ) ;
#ifdef F_21
F_22 ( V_60 ) ;
#endif
return - V_62 ;
}
T_1 void F_23 ( struct V_59 * V_60 )
{
T_2 V_64 ;
if ( F_7 ( V_28 ) ) {
V_60 -> V_65 &= 0xffffffff ;
V_60 -> V_66 &= 0xffffffff ;
}
#ifdef F_24
F_20 ( L_2 , V_60 -> V_65 , V_60 -> V_66 ) ;
#endif
V_64 . V_67 = V_68 ;
V_64 . V_69 = 0 ;
V_64 . V_70 = V_71 ;
V_64 . V_72 = ( void V_73 * ) V_60 -> V_65 ;
V_64 . V_74 = 0 ;
F_25 ( V_68 , & V_64 , V_18 ) ;
#ifdef F_24
F_20 ( L_3 , V_60 -> V_65 , V_60 -> V_66 ) ;
#endif
}
T_1 long F_26 ( unsigned long V_75 ,
struct V_59 * V_60 )
{
if ( V_75 >= 3 )
return - V_27 ;
V_60 -> V_76 = ( V_60 -> V_76 & ~ V_77 ) | ( V_75 << 14 ) ;
return 0 ;
}
int F_27 ( const char * V_78 ,
const char * const V_79 [] ,
const char * const V_80 [] )
{
long V_81 ;
register long T_3 V_82 ( L_4 ) = V_83 ;
register long T_4 V_82 ( L_5 ) = ( long ) ( V_78 ) ;
register long T_5 V_82 ( L_6 ) = ( long ) ( V_79 ) ;
register long T_6 V_82 ( L_7 ) = ( long ) ( V_80 ) ;
asm volatile ("t 0x6d\n\t"
"sub %%g0, %%o0, %0\n\t"
"movcc %%xcc, %%o0, %0\n\t"
: "=r" (__res), "=&r" (__o0)
: "1" (__o0), "r" (__o1), "r" (__o2), "r" (__g1)
: "cc");
return V_81 ;
}
