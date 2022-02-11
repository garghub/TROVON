static int F_1 ( T_1 V_1 )
{
T_1 V_2 , V_3 ;
int V_4 , V_5 = 0 ;
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ ) {
V_2 = V_1 & ( V_6
<< ( V_7 - V_4 )
* V_8 ) ;
V_2 = ( V_2 >> ( ( V_7 - V_4 )
* V_8 ) ) & ~ 1ULL ;
V_3 = V_1 & ( V_9
<< ( V_10
- ( V_4 * V_8 ) ) ) ;
V_3 = V_3 >> ( V_10
- ( V_4 * V_8 ) ) ;
switch ( V_2 >> 4 ) {
case 2 :
V_5 |= ( V_4 == 1 || V_4 == 3 ) << V_4 ;
break;
case 3 :
if ( V_2 == 0x3c ) {
V_5 |= ( V_4 == 0 ) << V_4 ;
break;
}
if ( V_2 == 0x3e ) {
V_5 |= ( V_4 != 1 ) << V_4 ;
break;
}
V_5 |= 1 << V_4 ;
break;
case 4 :
case 5 :
V_5 |= ( V_3 == 0xd ) << V_4 ;
break;
case 6 :
if ( V_2 == 0x64 )
V_5 |= ( V_4 >= 2 ) << V_4 ;
break;
case 8 :
V_5 |= ( V_3 == 0xd ) << V_4 ;
break;
}
}
return V_5 ;
}
static int F_2 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
int V_15 )
{
int V_16 ;
V_17 = V_14 -> V_18 ;
V_19 = V_14 -> V_1 ;
V_20 = V_14 -> V_21 ;
if ( F_3 ( V_22 ) )
V_5 = F_1 ( V_19 ) ;
else
V_5 = 0 ;
for ( V_16 = 0 ; V_16 < V_23 -> V_24 ; ++ V_16 )
V_25 [ V_16 ] = 0x80000000UL - V_12 [ V_16 ] . V_26 ;
if ( V_14 -> V_27 )
V_17 &= ~ V_28 ;
else
V_17 |= V_28 ;
if ( V_14 -> V_29 )
V_17 &= ~ V_30 ;
else
V_17 |= V_30 ;
if ( F_3 ( V_31 ) || F_3 ( V_32 ) ||
F_3 ( V_33 ) || F_3 ( V_34 ) ||
F_3 ( V_35 ) || F_3 ( V_36 ) ||
F_3 ( V_37 ) || F_3 ( V_38 ) )
V_39 = 1 ;
return 0 ;
}
static inline int F_4 ( void )
{
if ( F_3 ( V_31 ) || F_3 ( V_32 ) ||
F_3 ( V_33 ) || F_3 ( V_34 ) ||
F_3 ( V_35 ) || F_3 ( V_36 ) )
return 1 ;
return 0 ;
}
static int F_5 ( struct V_11 * V_12 )
{
unsigned int V_18 = V_17 ;
unsigned long V_21 = V_20 ;
F_6 () ;
V_18 |= V_40 ;
F_7 ( V_41 , V_18 ) ;
V_18 |= V_42 | V_43 | V_44 ;
V_18 |= V_45 | V_46 ;
F_7 ( V_41 , V_18 ) ;
F_7 ( V_47 , V_19 ) ;
if ( F_4 () )
V_21 |= V_48 ;
F_7 ( V_49 , V_21 ) ;
F_8 ( L_1 , F_9 () ,
F_10 ( V_41 ) ) ;
F_8 ( L_2 , F_9 () ,
F_10 ( V_47 ) ) ;
F_8 ( L_3 , F_9 () ,
F_10 ( V_49 ) ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 )
{
int V_16 ;
unsigned int V_18 ;
F_12 ( F_13 () | V_50 ) ;
for ( V_16 = 0 ; V_16 < V_23 -> V_24 ; ++ V_16 ) {
if ( V_12 [ V_16 ] . V_51 ) {
F_14 ( V_16 , V_25 [ V_16 ] ) ;
} else {
F_14 ( V_16 , 0 ) ;
}
}
V_18 = F_10 ( V_41 ) ;
V_18 &= ~ V_52 ;
V_18 &= ~ V_40 ;
F_7 ( V_41 , V_18 ) ;
V_53 = 1 ;
F_8 ( L_4 , F_9 () , V_18 ) ;
return 0 ;
}
static void F_15 ( void )
{
unsigned int V_18 ;
V_18 = F_10 ( V_41 ) ;
V_18 |= V_40 ;
F_7 ( V_41 , V_18 ) ;
V_53 = 0 ;
F_8 ( L_5 , F_9 () , V_18 ) ;
F_16 () ;
}
static void T_2 F_17 ( void )
{
}
static void T_2 F_18 ( void )
{
}
static void T_2 F_19 ( void )
{
}
static unsigned long F_20 ( struct V_54 * V_55 )
{
unsigned long V_56 = F_10 ( V_57 ) ;
unsigned long V_21 ;
unsigned long V_58 ;
if ( ! V_23 -> V_59 )
return V_56 ;
V_21 = F_10 ( V_49 ) ;
if ( V_39 && ( V_21 & V_48 ) ) {
V_58 = ( ( V_21 & V_60 ) >> V_61 ) ;
if ( V_58 > 1 )
V_56 += 4 * ( V_58 - 1 ) ;
}
if ( F_21 ( V_62 ) &&
( V_21 & V_23 -> V_59 ) )
return * ( ( unsigned long * ) F_17 ) ;
if ( V_21 & V_23 -> V_63 )
return V_56 ;
#ifdef F_22
if ( V_56 >= V_64 . V_65 && V_56 < ( V_64 . V_65 + V_64 . V_66 ) )
return * ( ( unsigned long * ) F_18 ) ;
#endif
if ( V_56 < 0x1000000UL )
return ( unsigned long ) F_23 ( V_56 ) ;
if ( ! F_24 ( V_56 ) )
return * ( ( unsigned long * ) F_19 ) ;
return V_56 ;
}
static int F_25 ( unsigned long V_56 , unsigned long V_21 )
{
int V_67 ;
if ( ! V_23 -> V_59 ) {
V_67 = F_24 ( V_56 ) ;
} else {
V_67 = ( ( V_21 & V_23 -> V_63 ) == 0 ) ;
}
return V_67 ;
}
static bool F_26 ( unsigned long V_68 )
{
if ( ( int ) V_68 < 0 )
return true ;
if ( F_3 ( V_69 ) && ( ( 0x80000000 - V_68 ) <= 256 ) )
return true ;
return false ;
}
static void F_27 ( struct V_54 * V_55 ,
struct V_11 * V_12 )
{
unsigned long V_56 ;
int V_67 ;
int V_68 ;
int V_16 ;
unsigned int V_18 ;
unsigned long V_21 ;
bool V_70 = false ;
V_21 = F_10 ( V_49 ) ;
V_56 = F_20 ( V_55 ) ;
V_67 = F_25 ( V_56 , V_21 ) ;
F_12 ( F_13 () | V_50 ) ;
if ( ( V_21 & V_71 ) == V_71 )
V_70 = true ;
for ( V_16 = 0 ; V_16 < V_23 -> V_24 ; ++ V_16 ) {
V_68 = F_28 ( V_16 ) ;
if ( F_26 ( V_68 ) ) {
if ( V_53 && V_12 [ V_16 ] . V_51 ) {
if ( ( V_70 &&
( V_5 & ( 1 << V_16 ) ) )
|| ! ( V_5 & ( 1 << V_16 ) ) )
F_29 ( V_56 , V_55 , V_16 ,
V_67 ) ;
F_14 ( V_16 , V_25 [ V_16 ] ) ;
} else {
F_14 ( V_16 , 0 ) ;
}
}
}
V_18 = F_10 ( V_41 ) ;
V_18 |= V_43 ;
V_18 &= ~ V_52 ;
V_21 &= ~ V_23 -> V_72 ;
F_7 ( V_49 , V_21 ) ;
V_18 &= ~ V_40 ;
F_7 ( V_41 , V_18 ) ;
}
