static int F_1 ( T_1 V_1 )
{
int V_2 , V_3 , V_4 ;
int V_5 , V_6 , V_7 ;
T_2 V_8 ;
V_2 = ( V_1 >> V_9 ) & V_10 ;
V_3 = ( V_1 & V_11 ) >> 1 ;
if ( V_2 >= 5 )
return 0 ;
V_5 = - 1 ;
if ( V_3 < sizeof( V_12 ) ) {
V_4 = V_12 [ V_3 ] ;
if ( V_2 == 0 || ! ( V_4 & ( 1 << ( V_2 - 1 ) ) ) )
return 0 ;
V_4 >>= 4 ;
if ( V_4 == 0 )
return 1 ;
if ( V_4 == 1 )
V_5 = 0 ;
else
V_5 = V_4 ^ ( V_2 - 1 ) ;
} else if ( ( V_3 & 0x48 ) == 0x40 )
V_5 = V_3 & 7 ;
if ( ! ( V_1 & V_13 ) || V_5 == - 1 )
return 0 ;
V_6 = ( V_1 >> V_14 ) & V_15 ;
V_7 = ( V_1 >> V_16 ) & V_17 ;
V_8 = V_18 [ V_7 ] ;
return ( V_8 >> ( V_6 * 8 + V_5 ) ) & 1 ;
}
static int F_2 ( T_1 V_1 [] , int V_19 ,
unsigned int V_20 [] , unsigned long V_21 [] )
{
unsigned long V_22 = 0 ;
unsigned long V_23 = V_24 | V_25 ;
int V_26 ;
unsigned int V_2 , V_27 , V_28 , V_29 , V_30 , V_3 ;
unsigned int V_31 = 0 ;
unsigned int V_32 = 0 ;
if ( V_19 > 6 )
return - 1 ;
for ( V_26 = 0 ; V_26 < V_19 ; ++ V_26 ) {
V_2 = ( V_1 [ V_26 ] >> V_9 ) & V_10 ;
if ( V_2 ) {
if ( V_32 & ( 1 << ( V_2 - 1 ) ) )
return - 1 ;
V_32 |= 1 << ( V_2 - 1 ) ;
}
}
for ( V_26 = 0 ; V_26 < V_19 ; ++ V_26 ) {
V_27 = V_1 [ V_26 ] ;
V_2 = ( V_27 >> V_9 ) & V_10 ;
if ( V_2 ) {
-- V_2 ;
} else {
for ( V_2 = 0 ; V_2 < 4 ; ++ V_2 )
if ( ! ( V_32 & ( 1 << V_2 ) ) )
break;
if ( V_2 >= 4 )
return - 1 ;
V_32 |= 1 << V_2 ;
}
V_20 [ V_26 ] = V_2 ;
V_3 = V_27 & V_11 ;
if ( V_27 & V_13 ) {
V_28 = ( V_27 >> V_14 ) & V_15 ;
V_29 = ( V_27 >> V_16 ) & V_17 ;
if ( ( V_31 & ( 1 << V_28 ) ) && F_3 ( V_22 , V_28 ) != V_29 )
return - 1 ;
V_22 |= ( unsigned long ) V_29 << F_4 ( V_28 ) ;
V_31 |= 1 << V_28 ;
if ( V_29 == 5 ) {
V_30 = ( V_27 >> V_33 ) & V_34 ;
if ( ( V_31 & 0x10 ) &&
F_5 ( V_22 ) != V_30 )
return - 1 ;
V_31 |= 0x10 ;
V_22 |= ( unsigned long ) V_30 << V_35 ;
}
if ( 0x30 <= V_3 && V_3 <= 0x3d ) {
if ( V_28 >= 2 )
V_22 |= V_36 >> V_2 ;
}
if ( V_2 >= 2 && ( V_3 & 0x90 ) == 0x80 )
V_3 ^= 0x20 ;
}
if ( V_27 & V_37 ) {
V_22 |= V_38 >> V_2 ;
if ( V_27 & V_39 )
V_22 |= V_40 >> V_2 ;
}
if ( F_1 ( V_1 [ V_26 ] ) )
V_23 |= V_41 ;
if ( V_2 < 4 )
V_22 |= ( unsigned long ) V_3 << F_6 ( V_2 ) ;
}
V_21 [ 0 ] = 0 ;
if ( V_32 & 1 )
V_21 [ 0 ] = V_42 ;
if ( V_32 & 0xe )
V_21 [ 0 ] |= V_43 ;
V_21 [ 1 ] = V_22 ;
V_21 [ 2 ] = V_23 ;
return 0 ;
}
static int F_7 ( T_1 V_1 , unsigned long * V_44 ,
unsigned long * V_45 )
{
int V_2 , V_6 , V_46 , V_47 ;
unsigned long V_8 = 0 , V_48 = 0 ;
V_2 = ( V_1 >> V_9 ) & V_10 ;
if ( V_2 ) {
if ( V_2 > 4 && ! ( V_1 == 0x500009 || V_1 == 0x600005 ) )
return - 1 ;
V_46 = ( V_2 - 1 ) * 2 ;
V_8 |= 2 << V_46 ;
V_48 |= 1 << V_46 ;
}
if ( V_1 & V_13 ) {
V_6 = ( V_1 >> V_14 ) & V_15 ;
V_46 = V_6 * 4 + ( 16 - V_16 ) ;
V_8 |= V_49 << V_46 ;
V_48 |= ( unsigned long ) ( V_1 & V_49 ) << V_46 ;
if ( ( V_1 & V_49 ) == ( 5 << V_16 ) ) {
V_47 = ( V_1 >> V_33 ) & V_34 ;
V_8 |= ( unsigned long ) V_34 << 32 ;
V_48 |= ( unsigned long ) V_47 << 32 ;
}
}
if ( V_2 <= 4 ) {
V_8 |= 0x8000 ;
V_48 |= 0x1000 ;
}
* V_44 = V_8 ;
* V_45 = V_48 ;
return 0 ;
}
static int F_8 ( T_1 V_1 )
{
int V_2 = ( V_1 >> V_9 ) & V_10 ;
return V_2 == 5 || V_2 == 6 ;
}
static int F_9 ( T_1 V_1 )
{
int V_26 , V_50 ;
unsigned int V_51 ;
for ( V_26 = 0 ; V_26 < F_10 ( V_52 ) ; ++ V_26 ) {
if ( V_1 < V_52 [ V_26 ] [ 0 ] )
return - 1 ;
for ( V_50 = 0 ; V_50 < V_53 ; ++ V_50 ) {
V_51 = V_52 [ V_26 ] [ V_50 ] ;
if ( ! V_51 || V_1 < V_51 )
break;
if ( V_1 == V_51 )
return V_26 ;
}
}
return - 1 ;
}
static int F_11 ( T_1 V_1 , unsigned int V_54 , T_1 V_51 [] )
{
int V_26 , V_50 , V_55 ;
unsigned int V_3 , V_2 ;
unsigned int V_56 = 1 ;
T_1 V_57 ;
V_51 [ 0 ] = V_1 ;
V_55 = F_8 ( V_1 ) ;
V_26 = F_9 ( V_1 ) ;
if ( V_26 >= 0 ) {
for ( V_50 = 0 ; V_50 < V_53 ; ++ V_50 ) {
V_57 = V_52 [ V_26 ] [ V_50 ] ;
if ( ! V_57 )
break;
if ( V_57 != V_1 )
V_51 [ V_56 ++ ] = V_57 ;
V_55 += F_8 ( V_57 ) ;
}
} else {
V_3 = V_1 & ( V_11 & ~ 1 ) ;
V_2 = ( V_1 >> V_9 ) & V_10 ;
if ( V_2 && ( V_3 == 0x32 || V_3 == 0x34 ) )
V_51 [ V_56 ++ ] = ( ( V_1 ^ 0x6 ) & ~ V_58 ) |
( ( 5 - V_2 ) << V_9 ) ;
if ( V_2 && ( V_3 == 0x38 || V_3 == 0x3a ) )
V_51 [ V_56 ++ ] = ( ( V_1 ^ 0x2 ) & ~ V_58 ) |
( ( V_2 > 2 ? V_2 - 2 : V_2 + 2 ) << V_9 ) ;
}
if ( V_54 & V_59 ) {
V_50 = V_56 ;
for ( V_26 = 0 ; V_26 < V_56 ; ++ V_26 ) {
switch ( V_51 [ V_26 ] ) {
case 0x1e :
V_51 [ V_50 ++ ] = 0x600005 ;
++ V_55 ;
break;
case 0x10000a :
V_51 [ V_50 ++ ] = 0x1e ;
break;
case 2 :
V_51 [ V_50 ++ ] = 0x500009 ;
++ V_55 ;
break;
case 0x500009 :
V_51 [ V_50 ++ ] = 2 ;
break;
case 0x10000e :
V_51 [ V_50 ++ ] = 0x4000f4 ;
break;
case 0x4000f4 :
V_51 [ V_50 ++ ] = 0x10000e ;
break;
}
}
V_56 = V_50 ;
}
if ( ! ( V_54 & V_60 ) && V_55 ) {
V_50 = 0 ;
for ( V_26 = 0 ; V_26 < V_56 ; ++ V_26 ) {
if ( ! F_8 ( V_51 [ V_26 ] ) ) {
V_51 [ V_50 ] = V_51 [ V_26 ] ;
++ V_50 ;
}
}
V_56 = V_50 ;
} else if ( ( V_54 & V_61 ) && V_55 < V_56 ) {
V_50 = 0 ;
for ( V_26 = 0 ; V_26 < V_56 ; ++ V_26 ) {
if ( F_8 ( V_51 [ V_26 ] ) ) {
V_51 [ V_50 ] = V_51 [ V_26 ] ;
++ V_50 ;
}
}
V_56 = V_50 ;
}
return V_56 ;
}
static void F_12 ( unsigned int V_2 , unsigned long V_21 [] )
{
if ( V_2 <= 3 )
V_21 [ 1 ] &= ~ ( 0xffUL << F_6 ( V_2 ) ) ;
}
static int T_3 F_13 ( void )
{
if ( ! V_62 -> V_63 ||
strcmp ( V_62 -> V_63 , L_1 ) )
return - V_64 ;
return F_14 ( & V_65 ) ;
}
