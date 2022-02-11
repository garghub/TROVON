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
unsigned long F_5 ( struct V_13 * V_14 , unsigned long V_2 , unsigned long V_3 , unsigned long V_8 , unsigned long V_15 )
{
struct V_16 * V_17 = V_18 -> V_17 ;
struct V_19 * V_20 ;
unsigned long V_21 = V_22 ;
int V_23 ;
struct V_24 V_25 ;
if ( V_15 & V_26 ) {
if ( ( V_15 & V_27 ) &&
( ( V_2 - ( V_8 << V_12 ) ) & ( V_10 - 1 ) ) )
return - V_28 ;
return V_2 ;
}
if ( F_6 ( V_29 ) )
V_21 = V_30 ;
if ( F_3 ( V_3 > V_21 || V_3 >= V_6 ) )
return - V_31 ;
V_23 = 0 ;
if ( V_14 || ( V_15 & V_27 ) )
V_23 = 1 ;
if ( V_2 ) {
if ( V_23 )
V_2 = F_4 ( V_2 , V_8 ) ;
else
V_2 = F_7 ( V_2 ) ;
V_20 = F_8 ( V_17 , V_2 ) ;
if ( V_21 - V_3 >= V_2 &&
( ! V_20 || V_2 + V_3 <= F_9 ( V_20 ) ) )
return V_2 ;
}
V_25 . V_15 = 0 ;
V_25 . V_32 = V_3 ;
V_25 . V_33 = V_34 ;
V_25 . V_35 = F_10 ( V_21 , V_6 ) ;
V_25 . V_36 = V_23 ? ( V_37 & ( V_10 - 1 ) ) : 0 ;
V_25 . V_38 = V_8 << V_12 ;
V_2 = F_11 ( & V_25 ) ;
if ( ( V_2 & ~ V_37 ) && V_21 > V_7 ) {
F_12 ( V_2 != - V_31 ) ;
V_25 . V_33 = V_7 ;
V_25 . V_35 = V_21 ;
V_2 = F_11 ( & V_25 ) ;
}
return V_2 ;
}
unsigned long
F_13 ( struct V_13 * V_14 , const unsigned long V_39 ,
const unsigned long V_3 , const unsigned long V_8 ,
const unsigned long V_15 )
{
struct V_19 * V_20 ;
struct V_16 * V_17 = V_18 -> V_17 ;
unsigned long V_21 = V_30 ;
unsigned long V_2 = V_39 ;
int V_23 ;
struct V_24 V_25 ;
F_14 ( ! F_6 ( V_29 ) ) ;
if ( V_15 & V_26 ) {
if ( ( V_15 & V_27 ) &&
( ( V_2 - ( V_8 << V_12 ) ) & ( V_10 - 1 ) ) )
return - V_28 ;
return V_2 ;
}
if ( F_3 ( V_3 > V_21 ) )
return - V_31 ;
V_23 = 0 ;
if ( V_14 || ( V_15 & V_27 ) )
V_23 = 1 ;
if ( V_2 ) {
if ( V_23 )
V_2 = F_4 ( V_2 , V_8 ) ;
else
V_2 = F_7 ( V_2 ) ;
V_20 = F_8 ( V_17 , V_2 ) ;
if ( V_21 - V_3 >= V_2 &&
( ! V_20 || V_2 + V_3 <= F_9 ( V_20 ) ) )
return V_2 ;
}
V_25 . V_15 = V_40 ;
V_25 . V_32 = V_3 ;
V_25 . V_33 = V_1 ;
V_25 . V_35 = V_17 -> V_41 ;
V_25 . V_36 = V_23 ? ( V_37 & ( V_10 - 1 ) ) : 0 ;
V_25 . V_38 = V_8 << V_12 ;
V_2 = F_11 ( & V_25 ) ;
if ( V_2 & ~ V_37 ) {
F_12 ( V_2 != - V_31 ) ;
V_25 . V_15 = 0 ;
V_25 . V_33 = V_34 ;
V_25 . V_35 = V_30 ;
V_2 = F_11 ( & V_25 ) ;
}
return V_2 ;
}
unsigned long F_15 ( struct V_13 * V_14 , unsigned long V_42 , unsigned long V_3 , unsigned long V_8 , unsigned long V_15 )
{
unsigned long V_43 , V_2 = - V_31 ;
unsigned long ( * V_44 ) ( struct V_13 * , unsigned long ,
unsigned long , unsigned long , unsigned long ) ;
V_44 = V_18 -> V_17 -> V_45 ;
if ( V_15 & V_26 ) {
return V_44 ( NULL , V_42 , V_3 , V_8 , V_15 ) ;
}
V_15 &= ~ V_27 ;
V_43 = V_1 ;
if ( V_3 >= ( 4UL * 1024 * 1024 ) )
V_43 = ( 4UL * 1024 * 1024 ) ;
else if ( V_3 >= ( 512UL * 1024 ) )
V_43 = ( 512UL * 1024 ) ;
else if ( V_3 >= ( 64UL * 1024 ) )
V_43 = ( 64UL * 1024 ) ;
do {
V_2 = V_44 ( NULL , V_42 , V_3 + ( V_43 - V_1 ) , V_8 , V_15 ) ;
if ( ! ( V_2 & ~ V_37 ) ) {
V_2 = ( V_2 + ( V_43 - 1UL ) ) & ~ ( V_43 - 1UL ) ;
break;
}
if ( V_43 == ( 4UL * 1024 * 1024 ) )
V_43 = ( 512UL * 1024 ) ;
else if ( V_43 == ( 512UL * 1024 ) )
V_43 = ( 64UL * 1024 ) ;
else
V_43 = V_1 ;
} while ( ( V_2 & ~ V_37 ) && V_43 > V_1 );
if ( V_2 & ~ V_37 )
V_2 = V_44 ( NULL , V_42 , V_3 , V_8 , V_15 ) ;
return V_2 ;
}
static unsigned long F_16 ( void )
{
unsigned long V_46 = 0UL ;
if ( V_18 -> V_15 & V_47 ) {
unsigned long V_48 = F_17 () ;
if ( F_6 ( V_29 ) )
V_46 = ( V_48 % ( 1UL << ( 23UL - V_12 ) ) ) ;
else
V_46 = ( V_48 % ( 1UL << ( 30UL - V_12 ) ) ) ;
}
return V_46 << V_12 ;
}
void F_18 ( struct V_16 * V_17 )
{
unsigned long V_49 = F_16 () ;
unsigned long V_50 ;
V_50 = F_19 ( V_51 ) ;
if ( ! F_6 ( V_29 ) ||
( V_18 -> V_52 & V_53 ) ||
V_50 == V_54 ||
V_55 ) {
V_17 -> V_41 = V_34 + V_49 ;
V_17 -> V_45 = F_5 ;
} else {
unsigned long V_21 = V_30 ;
if ( V_50 < 128 * 1024 * 1024 )
V_50 = 128 * 1024 * 1024 ;
if ( V_50 > ( V_21 / 6 * 5 ) )
V_50 = ( V_21 / 6 * 5 ) ;
V_17 -> V_41 = F_7 ( V_21 - V_50 - V_49 ) ;
V_17 -> V_45 = F_13 ;
}
}
int F_20 ( unsigned long V_2 , unsigned long V_3 )
{
if ( F_6 ( V_29 ) ) {
if ( V_3 >= V_30 )
return - V_28 ;
if ( V_2 > V_30 - V_3 )
return - V_28 ;
} else {
if ( V_3 >= V_6 )
return - V_28 ;
if ( F_2 ( V_2 , V_3 ) )
return - V_28 ;
}
return 0 ;
}
T_1 unsigned long F_21 ( struct V_56 * V_57 )
{
static int V_58 ;
if ( V_58 ++ > 5 )
return - V_59 ;
F_22 ( L_1 , V_57 -> V_60 [ 1 ] ) ;
#ifdef F_23
F_24 ( V_57 ) ;
#endif
return - V_59 ;
}
T_1 void F_25 ( struct V_56 * V_57 )
{
enum V_61 V_62 = F_26 () ;
T_2 V_25 ;
if ( F_6 ( V_29 ) ) {
V_57 -> V_63 &= 0xffffffff ;
V_57 -> V_64 &= 0xffffffff ;
}
#ifdef F_27
F_22 ( L_2 , V_57 -> V_63 , V_57 -> V_64 ) ;
#endif
V_25 . V_65 = V_66 ;
V_25 . V_67 = 0 ;
V_25 . V_68 = V_69 ;
V_25 . V_70 = ( void V_71 * ) V_57 -> V_63 ;
V_25 . V_72 = 0 ;
F_28 ( V_66 , & V_25 , V_18 ) ;
#ifdef F_27
F_22 ( L_3 , V_57 -> V_63 , V_57 -> V_64 ) ;
#endif
F_29 ( V_62 ) ;
}
T_1 long F_30 ( unsigned long V_73 ,
struct V_56 * V_57 )
{
if ( V_73 >= 3 )
return - V_28 ;
V_57 -> V_74 = ( V_57 -> V_74 & ~ V_75 ) | ( V_73 << 14 ) ;
return 0 ;
}
T_1 long F_31 ( void )
{
return V_76 ;
}
