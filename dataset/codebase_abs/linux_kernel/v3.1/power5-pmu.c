static int F_1 ( T_1 V_1 , unsigned long * V_2 ,
unsigned long * V_3 )
{
int V_4 , V_5 , V_6 , V_7 ;
int V_8 , V_9 ;
unsigned long V_10 = 0 , V_11 = 0 ;
int V_12 = - 1 ;
V_4 = ( V_1 >> V_13 ) & V_14 ;
if ( V_4 ) {
if ( V_4 > 6 )
return - 1 ;
V_7 = ( V_4 - 1 ) * 2 ;
V_10 |= 2 << V_7 ;
V_11 |= 1 << V_7 ;
if ( V_4 <= 4 )
V_12 = ( V_4 - 1 ) >> 1 ;
else if ( V_1 != 0x500009 && V_1 != 0x600005 )
return - 1 ;
}
if ( V_1 & V_15 ) {
V_6 = ( V_1 >> V_16 ) & V_17 ;
if ( V_6 > V_18 )
return - 1 ;
if ( V_6 == V_19 )
V_6 = V_20 ;
V_10 |= V_21 [ V_6 ] [ 0 ] ;
V_11 |= V_21 [ V_6 ] [ 1 ] ;
V_5 = ( V_1 >> V_22 ) & V_23 ;
if ( V_5 >= 4 ) {
if ( V_6 != V_24 )
return - 1 ;
++ V_6 ;
V_5 &= 3 ;
}
if ( V_6 == V_25 ) {
V_8 = V_1 & 7 ;
V_9 = ( V_8 == 6 ) ? 7 : 3 ;
V_7 = V_26 [ V_8 ] ;
V_10 |= ( unsigned long ) V_9 << V_7 ;
V_11 |= ( unsigned long ) ( ( V_1 >> V_27 ) & V_9 )
<< V_7 ;
}
if ( ! V_4 )
V_12 = V_5 & 1 ;
V_10 |= 0xfUL << ( 24 - 4 * V_5 ) ;
V_11 |= ( unsigned long ) V_6 << ( 24 - 4 * V_5 ) ;
}
if ( V_12 == 0 ) {
V_10 |= 0x200000000ul ;
V_11 |= 0x080000000ul ;
} else if ( V_12 == 1 ) {
V_10 |= 0x40000000ul ;
V_11 |= 0x10000000ul ;
}
if ( V_4 < 5 ) {
V_10 |= 0x8000000000000ul ;
V_11 |= 0x1000000000000ul ;
}
* V_2 = V_10 ;
* V_3 = V_11 ;
return 0 ;
}
static int F_2 ( T_1 V_1 )
{
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < F_3 ( V_30 ) ; ++ V_28 ) {
if ( V_1 < V_30 [ V_28 ] [ 0 ] )
break;
for ( V_29 = 0 ; V_29 < V_31 && V_30 [ V_28 ] [ V_29 ] ; ++ V_29 )
if ( V_1 == V_30 [ V_28 ] [ V_29 ] )
return V_28 ;
}
return - 1 ;
}
static T_2 F_4 ( T_1 V_1 )
{
int V_4 , V_32 , V_33 , V_29 ;
V_4 = ( V_1 >> V_13 ) & V_14 ;
if ( V_4 == 0 || V_4 > 4 )
return - 1 ;
V_32 = 5 - V_4 ;
V_33 = V_1 & V_34 ;
for ( V_29 = 0 ; V_29 < 4 ; ++ V_29 ) {
if ( V_35 [ V_4 - 1 ] [ V_29 ] == V_33 ) {
return ( V_1 & ~ ( V_36 | V_34 ) ) |
( V_32 << V_13 ) |
V_35 [ V_32 - 1 ] [ V_29 ] ;
}
}
return - 1 ;
}
static int F_5 ( T_1 V_1 , unsigned int V_37 , T_1 V_38 [] )
{
int V_28 , V_29 , V_39 = 1 ;
T_2 V_40 ;
V_38 [ 0 ] = V_1 ;
V_39 = 1 ;
V_28 = F_2 ( V_1 ) ;
if ( V_28 >= 0 ) {
for ( V_29 = 0 ; V_29 < V_31 ; ++ V_29 ) {
V_40 = V_30 [ V_28 ] [ V_29 ] ;
if ( V_40 && V_40 != V_1 )
V_38 [ V_39 ++ ] = V_40 ;
}
} else {
V_40 = F_4 ( V_1 ) ;
if ( V_40 > 0 )
V_38 [ V_39 ++ ] = V_40 ;
}
return V_39 ;
}
static int F_6 ( T_1 V_1 )
{
int V_4 , V_41 ;
int V_8 , V_5 , V_6 ;
T_3 V_10 ;
V_4 = ( V_1 >> V_13 ) & V_14 ;
V_41 = V_1 & V_34 ;
if ( V_4 >= 5 )
return 0 ;
V_8 = - 1 ;
if ( V_41 < sizeof( V_42 ) ) {
if ( V_42 [ V_41 ] & ( 1 << V_4 ) )
return 1 ;
if ( V_42 [ V_41 ] & 0x80 )
V_8 = 4 ;
else if ( V_41 == 0x08 )
V_8 = V_4 - 1 ;
else if ( V_41 == 0x10 )
V_8 = 4 - V_4 ;
else if ( V_41 == 0x1b && ( V_4 == 1 || V_4 == 3 ) )
V_8 = 4 ;
} else if ( ( V_41 & 0x58 ) == 0x40 )
V_8 = V_41 & 7 ;
if ( ! ( V_1 & V_15 ) )
return 0 ;
V_5 = ( V_1 >> V_22 ) & V_23 ;
V_6 = ( V_1 >> V_16 ) & V_17 ;
if ( V_6 == V_43 ) {
V_10 = 0x5dff00 ;
} else if ( V_6 == V_24 && V_5 >= 4 ) {
V_5 -= 4 ;
V_10 = 0x5f00c0aa ;
} else
return 0 ;
return ( V_10 >> ( V_5 * 8 + V_8 ) ) & 1 ;
}
static int F_7 ( T_1 V_1 [] , int V_44 ,
unsigned int V_45 [] , unsigned long V_46 [] )
{
unsigned long V_47 = 0 ;
unsigned long V_48 = V_49 | V_50 ;
unsigned int V_4 , V_6 , V_5 , V_41 ;
unsigned int V_51 , V_12 ;
int V_28 , V_52 , V_8 , V_53 ;
unsigned int V_54 = 0 ;
unsigned int V_55 [ 2 ] ;
unsigned char V_56 [ 4 ] ;
unsigned char V_57 [ 16 ] ;
int V_58 ;
if ( V_44 > 6 )
return - 1 ;
V_55 [ 0 ] = V_55 [ 1 ] = 0 ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
memset ( V_57 , 0 , sizeof( V_57 ) ) ;
for ( V_28 = 0 ; V_28 < V_44 ; ++ V_28 ) {
V_4 = ( V_1 [ V_28 ] >> V_13 ) & V_14 ;
if ( V_4 ) {
if ( V_4 > 6 )
return - 1 ;
if ( V_54 & ( 1 << ( V_4 - 1 ) ) )
return - 1 ;
V_54 |= 1 << ( V_4 - 1 ) ;
if ( V_4 <= 4 )
++ V_55 [ ( V_4 - 1 ) >> 1 ] ;
}
if ( V_1 [ V_28 ] & V_15 ) {
V_6 = ( V_1 [ V_28 ] >> V_16 ) & V_17 ;
V_5 = ( V_1 [ V_28 ] >> V_22 ) & V_23 ;
if ( V_6 > V_18 )
return - 1 ;
if ( V_6 == V_19 )
V_6 = V_20 ;
if ( V_5 >= 4 ) {
if ( V_6 != V_24 )
return - 1 ;
++ V_6 ;
V_5 &= 3 ;
}
if ( ! V_4 )
++ V_55 [ V_5 & 1 ] ;
if ( V_56 [ V_5 ] && V_56 [ V_5 ] != V_6 )
return - 1 ;
V_56 [ V_5 ] = V_6 ;
V_57 [ V_6 ] = 1 ;
}
}
if ( V_55 [ 0 ] > 2 || V_55 [ 1 ] > 2 )
return - 1 ;
if ( V_57 [ V_20 ] &
( V_57 [ V_59 ] | V_57 [ V_60 ] | V_57 [ V_61 ] ) ) {
V_57 [ V_19 ] = 1 ;
V_57 [ V_20 ] = 0 ;
}
V_58 = 0 ;
for ( V_28 = V_59 ; V_28 <= V_61 ; ++ V_28 ) {
if ( ! V_57 [ V_28 ] )
continue;
if ( V_58 ++ )
return - 1 ;
V_47 |= ( unsigned long ) V_28 << V_62 ;
}
V_58 = 0 ;
for (; V_28 <= V_25 ; ++ V_28 ) {
if ( ! V_57 [ V_28 ] )
continue;
if ( V_58 ++ )
return - 1 ;
V_47 |= ( unsigned long ) ( V_28 & 3 ) << V_63 ;
}
if ( V_58 > 1 )
return - 1 ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 ) {
V_6 = V_56 [ V_5 ] ;
if ( ! V_6 )
continue;
if ( V_6 == V_20 && V_57 [ V_19 ] ) {
V_6 = V_19 ;
} else if ( V_6 == V_24 + 1 ) {
V_47 |= 1ul << ( V_64 + 3 - V_5 ) ;
}
V_51 = V_6 >> 2 ;
V_47 |= ( unsigned long ) V_51
<< ( V_65 - 2 * V_5 ) ;
}
for ( V_28 = 0 ; V_28 < V_44 ; ++ V_28 ) {
V_4 = ( V_1 [ V_28 ] >> V_13 ) & V_14 ;
V_6 = ( V_1 [ V_28 ] >> V_16 ) & V_17 ;
V_5 = ( V_1 [ V_28 ] >> V_22 ) & V_23 ;
V_41 = V_1 [ V_28 ] & V_34 ;
V_52 = V_1 [ V_28 ] & V_15 ;
if ( ! V_4 ) {
for ( V_4 = 0 ; V_4 < 4 ; ++ V_4 ) {
if ( V_54 & ( 1 << V_4 ) )
continue;
V_12 = ( V_4 >> 1 ) & 1 ;
if ( V_52 ) {
if ( V_12 == ( V_5 & 1 ) )
break;
} else if ( V_55 [ V_12 ] < 2 ) {
++ V_55 [ V_12 ] ;
break;
}
}
V_54 |= 1 << V_4 ;
} else if ( V_4 <= 4 ) {
-- V_4 ;
if ( ( V_41 == 8 || V_41 == 0x10 ) && V_52 && ( V_5 & 2 ) )
V_47 |= 1ul << ( V_66 - V_4 ) ;
} else {
-- V_4 ;
}
if ( V_52 && V_6 == V_25 ) {
V_8 = V_41 & 7 ;
V_53 = ( V_1 [ V_28 ] >> V_27 ) & V_67 ;
V_47 |= ( unsigned long ) V_53 << V_26 [ V_8 ] ;
}
if ( F_6 ( V_1 [ V_28 ] ) )
V_48 |= V_68 ;
if ( V_4 <= 3 )
V_47 |= V_41 << F_8 ( V_4 ) ;
V_45 [ V_28 ] = V_4 ;
}
V_46 [ 0 ] = 0 ;
if ( V_54 & 1 )
V_46 [ 0 ] = V_69 ;
if ( V_54 & 0x3e )
V_46 [ 0 ] |= V_70 ;
V_46 [ 1 ] = V_47 ;
V_46 [ 2 ] = V_48 ;
return 0 ;
}
static void F_9 ( unsigned int V_4 , unsigned long V_46 [] )
{
if ( V_4 <= 3 )
V_46 [ 1 ] &= ~ ( 0x7fUL << F_8 ( V_4 ) ) ;
}
static int T_4 F_10 ( void )
{
if ( ! V_71 -> V_72 ||
strcmp ( V_71 -> V_72 , L_1 ) )
return - V_73 ;
return F_11 ( & V_74 ) ;
}
