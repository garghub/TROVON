static inline bool F_1 ( T_1 V_1 )
{
V_1 &= 0xff0fe ;
return ( V_1 == 0x30056 || V_1 == 0x4f052 ) ;
}
static bool F_2 ( T_1 V_1 )
{
T_1 V_2 = V_3 ;
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
V_2 = V_6 ;
return ! ( V_1 & ~ V_2 ) ;
}
static T_1 F_4 ( T_1 V_1 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return F_5 ( V_1 ) << V_7 ;
return V_8 ;
}
static T_1 F_6 ( T_1 V_9 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return V_9 << V_10 ;
return V_9 << V_11 ;
}
static unsigned long F_7 ( T_1 V_1 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return F_8 ( V_1 ) ;
return F_9 ( V_1 ) ;
}
static unsigned long F_10 ( unsigned long V_12 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return F_11 ( V_12 ) ;
return F_12 ( V_12 ) ;
}
int F_13 ( T_1 V_1 , unsigned long * V_13 , unsigned long * V_14 )
{
unsigned int V_15 , V_12 , V_16 , V_17 ;
unsigned long V_18 , V_9 ;
V_18 = V_9 = 0 ;
if ( ! F_2 ( V_1 ) )
return - 1 ;
V_12 = ( V_1 >> V_19 ) & V_20 ;
V_15 = ( V_1 >> V_21 ) & V_22 ;
V_16 = ( V_1 >> V_23 ) & V_24 ;
V_17 = ( V_1 >> V_25 ) & V_26 ;
if ( V_12 ) {
T_1 V_27 ;
if ( V_12 > 6 )
return - 1 ;
V_27 = V_1 & ~ V_28 ;
if ( V_12 >= 5 && V_27 != 0x500fa &&
V_27 != 0x600f4 )
return - 1 ;
V_18 |= F_14 ( V_12 ) ;
V_9 |= F_15 ( V_12 ) ;
}
if ( V_12 <= 4 ) {
V_18 |= V_29 ;
V_9 |= V_30 ;
}
if ( V_15 >= 6 && V_15 <= 9 ) {
if ( V_16 & 0x7 )
return - 1 ;
} else if ( V_1 & V_31 ) {
V_18 |= V_32 ;
V_9 |= F_16 ( V_16 ) ;
}
if ( V_1 & V_33 ) {
V_18 |= V_34 ;
V_9 |= F_17 ( V_1 >> V_35 ) ;
}
if ( F_1 ( V_1 ) ) {
V_18 |= V_36 ;
V_9 |= F_18 ( V_1 >> V_37 ) ;
} else {
unsigned int V_38 , exp ;
V_38 = ( V_1 >> V_39 ) & V_40 ;
exp = V_38 >> 7 ;
if ( exp && ( V_38 & 0x60 ) == 0 )
return - 1 ;
V_18 |= V_41 ;
V_9 |= F_19 ( V_1 >> V_42 ) ;
}
if ( ! V_12 && V_17 )
return - 1 ;
if ( V_1 & V_43 ) {
if ( ! V_17 )
return - 1 ;
V_18 |= V_44 ;
V_9 |= F_20 ( V_1 >> V_45 ) ;
}
V_18 |= F_21 ( V_17 ) ;
V_9 |= V_46 ;
* V_13 = V_18 ;
* V_14 = V_9 ;
return 0 ;
}
int F_22 ( T_1 V_1 [] , int V_47 ,
unsigned int V_48 [] , unsigned long V_49 [] ,
struct V_50 * V_51 [] )
{
unsigned long V_52 , V_53 , V_54 , V_15 , V_55 , V_56 , V_16 , V_57 ;
unsigned int V_12 , V_58 ;
int V_59 ;
V_58 = 0 ;
for ( V_59 = 0 ; V_59 < V_47 ; ++ V_59 ) {
V_12 = ( V_1 [ V_59 ] >> V_19 ) & V_20 ;
if ( V_12 )
V_58 |= 1 << V_12 ;
}
V_52 = V_53 = V_54 = 0 ;
for ( V_59 = 0 ; V_59 < V_47 ; ++ V_59 ) {
V_12 = ( V_1 [ V_59 ] >> V_19 ) & V_20 ;
V_15 = ( V_1 [ V_59 ] >> V_21 ) & V_22 ;
V_55 = F_7 ( V_1 [ V_59 ] ) ;
V_56 = V_1 [ V_59 ] & V_60 ;
if ( ! V_12 ) {
for ( V_12 = 1 ; V_12 <= 4 ; ++ V_12 ) {
if ( ! ( V_58 & ( 1 << V_12 ) ) )
break;
}
V_58 |= 1 << V_12 ;
}
if ( V_12 <= 4 ) {
V_53 |= V_15 << F_23 ( V_12 ) ;
V_53 |= V_55 << F_10 ( V_12 ) ;
V_53 |= V_56 << F_24 ( V_12 ) ;
}
V_52 |= F_4 ( V_1 [ V_59 ] ) ;
if ( V_1 [ V_59 ] & V_31 ) {
V_16 = V_1 [ V_59 ] >> V_23 ;
V_53 |= ( V_16 & 1 ) << V_61 ;
V_16 >>= 1 ;
V_53 |= ( V_16 & 1 ) << V_62 ;
}
if ( V_1 [ V_59 ] & V_33 ) {
V_52 |= V_63 ;
V_57 = ( V_1 [ V_59 ] >> V_35 ) & V_64 ;
if ( V_57 ) {
V_52 |= ( V_57 & 3 ) << V_65 ;
V_52 |= ( V_57 >> 2 ) << V_66 ;
}
}
if ( F_1 ( V_1 [ V_59 ] ) ) {
V_53 |= ( ( V_1 [ V_59 ] >> V_37 ) &
V_67 ) << V_68 ;
} else {
V_57 = ( V_1 [ V_59 ] >> V_37 ) & V_67 ;
V_52 |= V_57 << V_69 ;
V_57 = ( V_1 [ V_59 ] >> V_70 ) & V_71 ;
V_52 |= V_57 << V_72 ;
V_57 = ( V_1 [ V_59 ] >> V_39 ) & V_40 ;
V_52 |= F_6 ( V_57 ) ;
}
if ( V_1 [ V_59 ] & V_43 ) {
V_57 = ( V_1 [ V_59 ] >> V_45 ) & V_73 ;
V_52 |= V_57 << V_74 ;
}
if ( V_51 [ V_59 ] -> V_75 . V_76 )
V_54 |= F_25 ( V_12 ) ;
if ( V_51 [ V_59 ] -> V_75 . V_77 )
V_54 |= F_26 ( V_12 ) ;
if ( V_51 [ V_59 ] -> V_75 . V_78 ) {
if ( F_3 ( V_79 ) )
V_54 |= F_26 ( V_12 ) ;
else
V_54 |= F_27 ( V_12 ) ;
}
V_48 [ V_59 ] = V_12 - 1 ;
}
V_49 [ 0 ] = 0 ;
if ( V_58 & 2 )
V_49 [ 0 ] = V_80 ;
if ( V_58 & 0x7c )
V_49 [ 0 ] |= V_81 ;
if ( ! ( V_58 & 0x60 ) )
V_49 [ 0 ] |= V_82 ;
V_49 [ 1 ] = V_53 ;
V_49 [ 2 ] = V_52 ;
V_49 [ 3 ] = V_54 ;
return 0 ;
}
void F_28 ( unsigned int V_12 , unsigned long V_49 [] )
{
if ( V_12 <= 3 )
V_49 [ 1 ] &= ~ ( 0xffUL << F_24 ( V_12 + 1 ) ) ;
}
