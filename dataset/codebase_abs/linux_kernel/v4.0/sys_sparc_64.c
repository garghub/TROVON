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
( ! V_20 || V_2 + V_3 <= V_20 -> V_32 ) )
return V_2 ;
}
V_25 . V_15 = 0 ;
V_25 . V_33 = V_3 ;
V_25 . V_34 = V_35 ;
V_25 . V_36 = F_9 ( V_21 , V_6 ) ;
V_25 . V_37 = V_23 ? ( V_38 & ( V_10 - 1 ) ) : 0 ;
V_25 . V_39 = V_8 << V_12 ;
V_2 = F_10 ( & V_25 ) ;
if ( ( V_2 & ~ V_38 ) && V_21 > V_7 ) {
F_11 ( V_2 != - V_31 ) ;
V_25 . V_34 = V_7 ;
V_25 . V_36 = V_21 ;
V_2 = F_10 ( & V_25 ) ;
}
return V_2 ;
}
unsigned long
F_12 ( struct V_13 * V_14 , const unsigned long V_40 ,
const unsigned long V_3 , const unsigned long V_8 ,
const unsigned long V_15 )
{
struct V_19 * V_20 ;
struct V_16 * V_17 = V_18 -> V_17 ;
unsigned long V_21 = V_30 ;
unsigned long V_2 = V_40 ;
int V_23 ;
struct V_24 V_25 ;
F_13 ( ! F_6 ( V_29 ) ) ;
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
( ! V_20 || V_2 + V_3 <= V_20 -> V_32 ) )
return V_2 ;
}
V_25 . V_15 = V_41 ;
V_25 . V_33 = V_3 ;
V_25 . V_34 = V_1 ;
V_25 . V_36 = V_17 -> V_42 ;
V_25 . V_37 = V_23 ? ( V_38 & ( V_10 - 1 ) ) : 0 ;
V_25 . V_39 = V_8 << V_12 ;
V_2 = F_10 ( & V_25 ) ;
if ( V_2 & ~ V_38 ) {
F_11 ( V_2 != - V_31 ) ;
V_25 . V_15 = 0 ;
V_25 . V_34 = V_35 ;
V_25 . V_36 = V_30 ;
V_2 = F_10 ( & V_25 ) ;
}
return V_2 ;
}
unsigned long F_14 ( struct V_13 * V_14 , unsigned long V_43 , unsigned long V_3 , unsigned long V_8 , unsigned long V_15 )
{
unsigned long V_44 , V_2 = - V_31 ;
unsigned long ( * V_45 ) ( struct V_13 * , unsigned long ,
unsigned long , unsigned long , unsigned long ) ;
V_45 = V_18 -> V_17 -> V_46 ;
if ( V_15 & V_26 ) {
return V_45 ( NULL , V_43 , V_3 , V_8 , V_15 ) ;
}
V_15 &= ~ V_27 ;
V_44 = V_1 ;
if ( V_3 >= ( 4UL * 1024 * 1024 ) )
V_44 = ( 4UL * 1024 * 1024 ) ;
else if ( V_3 >= ( 512UL * 1024 ) )
V_44 = ( 512UL * 1024 ) ;
else if ( V_3 >= ( 64UL * 1024 ) )
V_44 = ( 64UL * 1024 ) ;
do {
V_2 = V_45 ( NULL , V_43 , V_3 + ( V_44 - V_1 ) , V_8 , V_15 ) ;
if ( ! ( V_2 & ~ V_38 ) ) {
V_2 = ( V_2 + ( V_44 - 1UL ) ) & ~ ( V_44 - 1UL ) ;
break;
}
if ( V_44 == ( 4UL * 1024 * 1024 ) )
V_44 = ( 512UL * 1024 ) ;
else if ( V_44 == ( 512UL * 1024 ) )
V_44 = ( 64UL * 1024 ) ;
else
V_44 = V_1 ;
} while ( ( V_2 & ~ V_38 ) && V_44 > V_1 );
if ( V_2 & ~ V_38 )
V_2 = V_45 ( NULL , V_43 , V_3 , V_8 , V_15 ) ;
return V_2 ;
}
static unsigned long F_15 ( void )
{
unsigned long V_47 = 0UL ;
if ( V_18 -> V_15 & V_48 ) {
unsigned long V_49 = F_16 () ;
if ( F_6 ( V_29 ) )
V_47 = ( V_49 % ( 1UL << ( 23UL - V_12 ) ) ) ;
else
V_47 = ( V_49 % ( 1UL << ( 30UL - V_12 ) ) ) ;
}
return V_47 << V_12 ;
}
void F_17 ( struct V_16 * V_17 )
{
unsigned long V_50 = F_15 () ;
unsigned long V_51 ;
V_51 = F_18 ( V_52 ) ;
if ( ! F_6 ( V_29 ) ||
( V_18 -> V_53 & V_54 ) ||
V_51 == V_55 ||
V_56 ) {
V_17 -> V_42 = V_35 + V_50 ;
V_17 -> V_46 = F_5 ;
} else {
unsigned long V_21 = V_30 ;
if ( V_51 < 128 * 1024 * 1024 )
V_51 = 128 * 1024 * 1024 ;
if ( V_51 > ( V_21 / 6 * 5 ) )
V_51 = ( V_21 / 6 * 5 ) ;
V_17 -> V_42 = F_7 ( V_21 - V_51 - V_50 ) ;
V_17 -> V_46 = F_12 ;
}
}
int F_19 ( unsigned long V_2 , unsigned long V_3 )
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
T_1 unsigned long F_20 ( struct V_57 * V_58 )
{
static int V_59 ;
if ( V_59 ++ > 5 )
return - V_60 ;
F_21 ( L_1 , V_58 -> V_61 [ 1 ] ) ;
#ifdef F_22
F_23 ( V_58 ) ;
#endif
return - V_60 ;
}
T_1 void F_24 ( struct V_57 * V_58 )
{
enum V_62 V_63 = F_25 () ;
T_2 V_25 ;
if ( F_6 ( V_29 ) ) {
V_58 -> V_64 &= 0xffffffff ;
V_58 -> V_65 &= 0xffffffff ;
}
#ifdef F_26
F_21 ( L_2 , V_58 -> V_64 , V_58 -> V_65 ) ;
#endif
V_25 . V_66 = V_67 ;
V_25 . V_68 = 0 ;
V_25 . V_69 = V_70 ;
V_25 . V_71 = ( void V_72 * ) V_58 -> V_64 ;
V_25 . V_73 = 0 ;
F_27 ( V_67 , & V_25 , V_18 ) ;
#ifdef F_26
F_21 ( L_3 , V_58 -> V_64 , V_58 -> V_65 ) ;
#endif
F_28 ( V_63 ) ;
}
T_1 long F_29 ( unsigned long V_74 ,
struct V_57 * V_58 )
{
if ( V_74 >= 3 )
return - V_28 ;
V_58 -> V_75 = ( V_58 -> V_75 & ~ V_76 ) | ( V_74 << 14 ) ;
return 0 ;
}
T_1 long F_30 ( void )
{
return V_77 ;
}
