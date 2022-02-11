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
unsigned int V_20 [] , unsigned long V_21 [] , struct V_22 * V_23 [] )
{
unsigned long V_24 = 0 ;
unsigned long V_25 = V_26 | V_27 ;
int V_28 ;
unsigned int V_2 , V_29 , V_30 , V_31 , V_32 , V_3 ;
unsigned int V_33 = 0 ;
unsigned int V_34 = 0 ;
if ( V_19 > 6 )
return - 1 ;
for ( V_28 = 0 ; V_28 < V_19 ; ++ V_28 ) {
V_2 = ( V_1 [ V_28 ] >> V_9 ) & V_10 ;
if ( V_2 ) {
if ( V_34 & ( 1 << ( V_2 - 1 ) ) )
return - 1 ;
V_34 |= 1 << ( V_2 - 1 ) ;
}
}
for ( V_28 = 0 ; V_28 < V_19 ; ++ V_28 ) {
V_29 = V_1 [ V_28 ] ;
V_2 = ( V_29 >> V_9 ) & V_10 ;
if ( V_2 ) {
-- V_2 ;
} else {
for ( V_2 = 0 ; V_2 < 4 ; ++ V_2 )
if ( ! ( V_34 & ( 1 << V_2 ) ) )
break;
if ( V_2 >= 4 )
return - 1 ;
V_34 |= 1 << V_2 ;
}
V_20 [ V_28 ] = V_2 ;
V_3 = V_29 & V_11 ;
if ( V_29 & V_13 ) {
V_30 = ( V_29 >> V_14 ) & V_15 ;
V_31 = ( V_29 >> V_16 ) & V_17 ;
if ( ( V_33 & ( 1 << V_30 ) ) && F_3 ( V_24 , V_30 ) != V_31 )
return - 1 ;
V_24 |= ( unsigned long ) V_31 << F_4 ( V_30 ) ;
V_33 |= 1 << V_30 ;
if ( V_31 == 5 ) {
V_32 = ( V_29 >> V_35 ) & V_36 ;
if ( ( V_33 & 0x10 ) &&
F_5 ( V_24 ) != V_32 )
return - 1 ;
V_33 |= 0x10 ;
V_24 |= ( unsigned long ) V_32 << V_37 ;
}
if ( 0x30 <= V_3 && V_3 <= 0x3d ) {
if ( V_30 >= 2 )
V_24 |= V_38 >> V_2 ;
}
if ( V_2 >= 2 && ( V_3 & 0x90 ) == 0x80 )
V_3 ^= 0x20 ;
}
if ( V_29 & V_39 ) {
V_24 |= V_40 >> V_2 ;
if ( V_29 & V_41 )
V_24 |= V_42 >> V_2 ;
}
if ( F_1 ( V_1 [ V_28 ] ) )
V_25 |= V_43 ;
if ( V_2 < 4 )
V_24 |= ( unsigned long ) V_3 << F_6 ( V_2 ) ;
}
V_21 [ 0 ] = 0 ;
if ( V_34 & 1 )
V_21 [ 0 ] = V_44 ;
if ( V_34 & 0xe )
V_21 [ 0 ] |= V_45 ;
V_21 [ 1 ] = V_24 ;
V_21 [ 2 ] = V_25 ;
return 0 ;
}
static int F_7 ( T_1 V_1 , unsigned long * V_46 ,
unsigned long * V_47 )
{
int V_2 , V_6 , V_48 , V_49 ;
unsigned long V_8 = 0 , V_50 = 0 ;
V_2 = ( V_1 >> V_9 ) & V_10 ;
if ( V_2 ) {
if ( V_2 > 4 && ! ( V_1 == 0x500009 || V_1 == 0x600005 ) )
return - 1 ;
V_48 = ( V_2 - 1 ) * 2 ;
V_8 |= 2 << V_48 ;
V_50 |= 1 << V_48 ;
}
if ( V_1 & V_13 ) {
V_6 = ( V_1 >> V_14 ) & V_15 ;
V_48 = V_6 * 4 + ( 16 - V_16 ) ;
V_8 |= V_51 << V_48 ;
V_50 |= ( unsigned long ) ( V_1 & V_51 ) << V_48 ;
if ( ( V_1 & V_51 ) == ( 5 << V_16 ) ) {
V_49 = ( V_1 >> V_35 ) & V_36 ;
V_8 |= ( unsigned long ) V_36 << 32 ;
V_50 |= ( unsigned long ) V_49 << 32 ;
}
}
if ( V_2 <= 4 ) {
V_8 |= 0x8000 ;
V_50 |= 0x1000 ;
}
* V_46 = V_8 ;
* V_47 = V_50 ;
return 0 ;
}
static int F_8 ( T_1 V_1 )
{
int V_2 = ( V_1 >> V_9 ) & V_10 ;
return V_2 == 5 || V_2 == 6 ;
}
static int F_9 ( T_1 V_1 )
{
int V_28 , V_52 ;
unsigned int V_53 ;
for ( V_28 = 0 ; V_28 < F_10 ( V_54 ) ; ++ V_28 ) {
if ( V_1 < V_54 [ V_28 ] [ 0 ] )
return - 1 ;
for ( V_52 = 0 ; V_52 < V_55 ; ++ V_52 ) {
V_53 = V_54 [ V_28 ] [ V_52 ] ;
if ( ! V_53 || V_1 < V_53 )
break;
if ( V_1 == V_53 )
return V_28 ;
}
}
return - 1 ;
}
static int F_11 ( T_1 V_1 , unsigned int V_56 , T_1 V_53 [] )
{
int V_28 , V_52 , V_57 ;
unsigned int V_3 , V_2 ;
unsigned int V_58 = 1 ;
T_1 V_59 ;
V_53 [ 0 ] = V_1 ;
V_57 = F_8 ( V_1 ) ;
V_28 = F_9 ( V_1 ) ;
if ( V_28 >= 0 ) {
for ( V_52 = 0 ; V_52 < V_55 ; ++ V_52 ) {
V_59 = V_54 [ V_28 ] [ V_52 ] ;
if ( ! V_59 )
break;
if ( V_59 != V_1 )
V_53 [ V_58 ++ ] = V_59 ;
V_57 += F_8 ( V_59 ) ;
}
} else {
V_3 = V_1 & ( V_11 & ~ 1 ) ;
V_2 = ( V_1 >> V_9 ) & V_10 ;
if ( V_2 && ( V_3 == 0x32 || V_3 == 0x34 ) )
V_53 [ V_58 ++ ] = ( ( V_1 ^ 0x6 ) & ~ V_60 ) |
( ( 5 - V_2 ) << V_9 ) ;
if ( V_2 && ( V_3 == 0x38 || V_3 == 0x3a ) )
V_53 [ V_58 ++ ] = ( ( V_1 ^ 0x2 ) & ~ V_60 ) |
( ( V_2 > 2 ? V_2 - 2 : V_2 + 2 ) << V_9 ) ;
}
if ( V_56 & V_61 ) {
V_52 = V_58 ;
for ( V_28 = 0 ; V_28 < V_58 ; ++ V_28 ) {
switch ( V_53 [ V_28 ] ) {
case 0x1e :
V_53 [ V_52 ++ ] = 0x600005 ;
++ V_57 ;
break;
case 0x10000a :
V_53 [ V_52 ++ ] = 0x1e ;
break;
case 2 :
V_53 [ V_52 ++ ] = 0x500009 ;
++ V_57 ;
break;
case 0x500009 :
V_53 [ V_52 ++ ] = 2 ;
break;
case 0x10000e :
V_53 [ V_52 ++ ] = 0x4000f4 ;
break;
case 0x4000f4 :
V_53 [ V_52 ++ ] = 0x10000e ;
break;
}
}
V_58 = V_52 ;
}
if ( ! ( V_56 & V_62 ) && V_57 ) {
V_52 = 0 ;
for ( V_28 = 0 ; V_28 < V_58 ; ++ V_28 ) {
if ( ! F_8 ( V_53 [ V_28 ] ) ) {
V_53 [ V_52 ] = V_53 [ V_28 ] ;
++ V_52 ;
}
}
V_58 = V_52 ;
} else if ( ( V_56 & V_63 ) && V_57 < V_58 ) {
V_52 = 0 ;
for ( V_28 = 0 ; V_28 < V_58 ; ++ V_28 ) {
if ( F_8 ( V_53 [ V_28 ] ) ) {
V_53 [ V_52 ] = V_53 [ V_28 ] ;
++ V_52 ;
}
}
V_58 = V_52 ;
}
return V_58 ;
}
static void F_12 ( unsigned int V_2 , unsigned long V_21 [] )
{
if ( V_2 <= 3 )
V_21 [ 1 ] &= ~ ( 0xffUL << F_6 ( V_2 ) ) ;
}
static int T_3 F_13 ( void )
{
if ( ! V_64 -> V_65 ||
strcmp ( V_64 -> V_65 , L_1 ) )
return - V_66 ;
return F_14 ( & V_67 ) ;
}
