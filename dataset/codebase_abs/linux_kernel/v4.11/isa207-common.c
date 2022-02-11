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
static inline bool F_4 ( T_1 V_1 )
{
if ( V_1 & V_7 )
return true ;
return false ;
}
static void F_5 ( T_1 V_1 , unsigned long * V_8 )
{
if ( F_3 ( V_4 ) ) {
if ( F_4 ( V_1 ) || ( * V_8 & V_9 ) )
* V_8 &= V_10 ;
else if ( ! F_3 ( V_5 ) )
* V_8 |= F_6 ( V_1 ) << V_11 ;
else if ( F_3 ( V_5 ) )
* V_8 |= V_12 ;
} else
* V_8 |= V_12 ;
}
static T_1 F_7 ( T_1 V_13 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return V_13 << V_14 ;
return V_13 << V_15 ;
}
static unsigned long F_8 ( T_1 V_1 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return F_9 ( V_1 ) ;
return F_10 ( V_1 ) ;
}
static unsigned long F_11 ( unsigned long V_16 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return F_12 ( V_16 ) ;
return F_13 ( V_16 ) ;
}
static inline bool F_14 ( T_1 V_1 )
{
return ( V_1 >> V_17 ) & V_18 ;
}
static bool F_15 ( T_1 V_1 )
{
unsigned int V_19 , exp ;
V_19 = ( V_1 >> V_20 ) & V_21 ;
exp = V_19 >> 7 ;
if ( exp && ( V_19 & 0x60 ) == 0 )
return false ;
return true ;
}
int F_16 ( T_1 V_1 , unsigned long * V_22 , unsigned long * V_23 )
{
unsigned int V_24 , V_16 , V_25 , V_26 ;
unsigned long V_27 , V_13 ;
V_27 = V_13 = 0 ;
if ( ! F_2 ( V_1 ) )
return - 1 ;
V_16 = ( V_1 >> V_28 ) & V_29 ;
V_24 = ( V_1 >> V_30 ) & V_31 ;
V_25 = ( V_1 >> V_32 ) & V_33 ;
V_26 = ( V_1 >> V_34 ) & V_35 ;
if ( V_16 ) {
T_1 V_36 ;
if ( V_16 > 6 )
return - 1 ;
V_36 = V_1 & ~ V_37 ;
if ( V_16 >= 5 && V_36 != 0x500fa &&
V_36 != 0x600f4 )
return - 1 ;
V_27 |= F_17 ( V_16 ) ;
V_13 |= F_18 ( V_16 ) ;
}
if ( V_16 <= 4 ) {
V_27 |= V_38 ;
V_13 |= V_39 ;
}
if ( V_24 >= 6 && V_24 <= 9 ) {
if ( V_25 & 0x7 )
return - 1 ;
} else if ( V_1 & V_40 ) {
V_27 |= V_41 ;
V_13 |= F_19 ( V_25 ) ;
}
if ( F_4 ( V_1 ) ) {
V_27 |= V_42 ;
V_13 |= F_20 ( V_1 >> V_43 ) ;
}
if ( F_3 ( V_4 ) ) {
if ( F_14 ( V_1 ) && F_15 ( V_1 ) ) {
V_27 |= V_44 ;
V_13 |= F_21 ( V_1 >> V_45 ) ;
}
} else {
if ( F_1 ( V_1 ) ) {
V_27 |= V_46 ;
V_13 |= F_22 ( V_1 >> V_47 ) ;
} else {
if ( ! F_15 ( V_1 ) )
return - 1 ;
V_27 |= V_44 ;
V_13 |= F_21 ( V_1 >> V_45 ) ;
}
}
if ( ! V_16 && V_26 )
return - 1 ;
if ( V_1 & V_48 ) {
if ( ! V_26 )
return - 1 ;
V_27 |= V_49 ;
V_13 |= F_23 ( V_1 >> V_50 ) ;
}
V_27 |= F_24 ( V_26 ) ;
V_13 |= V_51 ;
* V_22 = V_27 ;
* V_23 = V_13 ;
return 0 ;
}
int F_25 ( T_1 V_1 [] , int V_52 ,
unsigned int V_53 [] , unsigned long V_54 [] ,
struct V_55 * V_56 [] )
{
unsigned long V_8 , V_57 , V_58 , V_24 , V_59 , V_60 , V_25 , V_61 ;
unsigned int V_16 , V_62 ;
int V_63 ;
V_62 = 0 ;
for ( V_63 = 0 ; V_63 < V_52 ; ++ V_63 ) {
V_16 = ( V_1 [ V_63 ] >> V_28 ) & V_29 ;
if ( V_16 )
V_62 |= 1 << V_16 ;
}
V_8 = V_57 = V_58 = 0 ;
for ( V_63 = 0 ; V_63 < V_52 ; ++ V_63 ) {
V_16 = ( V_1 [ V_63 ] >> V_28 ) & V_29 ;
V_24 = ( V_1 [ V_63 ] >> V_30 ) & V_31 ;
V_59 = F_8 ( V_1 [ V_63 ] ) ;
V_60 = V_1 [ V_63 ] & V_64 ;
if ( ! V_16 ) {
for ( V_16 = 1 ; V_16 <= 4 ; ++ V_16 ) {
if ( ! ( V_62 & ( 1 << V_16 ) ) )
break;
}
V_62 |= 1 << V_16 ;
}
if ( V_16 <= 4 ) {
V_57 |= V_24 << F_26 ( V_16 ) ;
V_57 |= V_59 << F_11 ( V_16 ) ;
V_57 |= V_60 << F_27 ( V_16 ) ;
}
F_5 ( V_1 [ V_63 ] , & V_8 ) ;
if ( V_1 [ V_63 ] & V_40 ) {
V_25 = V_1 [ V_63 ] >> V_32 ;
V_57 |= ( V_25 & 1 ) << V_65 ;
V_25 >>= 1 ;
V_57 |= ( V_25 & 1 ) << V_66 ;
}
if ( F_4 ( V_1 [ V_63 ] ) ) {
V_8 |= V_9 ;
V_61 = ( V_1 [ V_63 ] >> V_43 ) & V_67 ;
if ( V_61 ) {
V_8 |= ( V_61 & 3 ) << V_68 ;
V_8 |= ( V_61 >> 2 ) << V_69 ;
}
}
if ( ! F_3 ( V_4 ) && F_1 ( V_1 [ V_63 ] ) ) {
V_57 |= ( ( V_1 [ V_63 ] >> V_47 ) &
V_70 ) << V_71 ;
} else {
V_61 = ( V_1 [ V_63 ] >> V_47 ) & V_70 ;
V_8 |= V_61 << V_72 ;
V_61 = ( V_1 [ V_63 ] >> V_17 ) & V_18 ;
V_8 |= V_61 << V_73 ;
V_61 = ( V_1 [ V_63 ] >> V_20 ) & V_21 ;
V_8 |= F_7 ( V_61 ) ;
}
if ( V_1 [ V_63 ] & V_48 ) {
V_61 = ( V_1 [ V_63 ] >> V_50 ) & V_74 ;
V_8 |= V_61 << V_75 ;
}
if ( V_56 [ V_63 ] -> V_76 . V_77 )
V_58 |= F_28 ( V_16 ) ;
if ( V_56 [ V_63 ] -> V_76 . V_78 )
V_58 |= F_29 ( V_16 ) ;
if ( V_56 [ V_63 ] -> V_76 . V_79 ) {
if ( F_3 ( V_80 ) )
V_58 |= F_29 ( V_16 ) ;
else
V_58 |= F_30 ( V_16 ) ;
}
V_53 [ V_63 ] = V_16 - 1 ;
}
V_54 [ 0 ] = 0 ;
if ( V_62 & 2 )
V_54 [ 0 ] = V_81 ;
if ( V_62 & 0x7c )
V_54 [ 0 ] |= V_82 ;
if ( ! ( V_62 & 0x60 ) )
V_54 [ 0 ] |= V_83 ;
V_54 [ 1 ] = V_57 ;
V_54 [ 2 ] = V_8 ;
V_54 [ 3 ] = V_58 ;
return 0 ;
}
void F_31 ( unsigned int V_16 , unsigned long V_54 [] )
{
if ( V_16 <= 3 )
V_54 [ 1 ] &= ~ ( 0xffUL << F_27 ( V_16 + 1 ) ) ;
}
static int F_32 ( T_1 V_1 , const unsigned int V_84 [] [ V_85 ] , int V_86 )
{
int V_63 , V_87 ;
for ( V_63 = 0 ; V_63 < V_86 ; ++ V_63 ) {
if ( V_1 < V_84 [ V_63 ] [ 0 ] )
break;
for ( V_87 = 0 ; V_87 < V_85 && V_84 [ V_63 ] [ V_87 ] ; ++ V_87 )
if ( V_1 == V_84 [ V_63 ] [ V_87 ] )
return V_63 ;
}
return - 1 ;
}
int F_33 ( T_1 V_1 , T_1 V_88 [] ,
const unsigned int V_84 [] [ V_85 ] , int V_86 )
{
int V_63 , V_87 , V_89 = 0 ;
T_1 V_90 ;
V_88 [ V_89 ++ ] = V_1 ;
V_63 = F_32 ( V_1 , V_84 , V_86 ) ;
if ( V_63 >= 0 ) {
for ( V_87 = 0 ; V_87 < V_85 ; ++ V_87 ) {
V_90 = V_84 [ V_63 ] [ V_87 ] ;
if ( V_90 && V_90 != V_1 )
V_88 [ V_89 ++ ] = V_90 ;
}
}
return V_89 ;
}
