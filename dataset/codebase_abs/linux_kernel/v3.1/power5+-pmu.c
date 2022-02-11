static int F_1 ( T_1 V_1 , unsigned long * V_2 ,
unsigned long * V_3 )
{
int V_4 , V_5 , V_6 , V_7 ;
int V_8 , V_9 ;
unsigned long V_10 = 0 , V_11 = 0 ;
V_4 = ( V_1 >> V_12 ) & V_13 ;
if ( V_4 ) {
if ( V_4 > 6 )
return - 1 ;
V_7 = ( V_4 - 1 ) * 2 ;
V_10 |= 2 << V_7 ;
V_11 |= 1 << V_7 ;
if ( V_4 >= 5 && ! ( V_1 == 0x500009 || V_1 == 0x600005 ) )
return - 1 ;
}
if ( V_1 & V_14 ) {
V_6 = ( V_1 >> V_15 ) & V_16 ;
if ( V_6 > V_17 )
return - 1 ;
if ( V_6 == V_18 )
V_6 = V_19 ;
V_10 |= V_20 [ V_6 ] [ 0 ] ;
V_11 |= V_20 [ V_6 ] [ 1 ] ;
V_5 = ( V_1 >> V_21 ) & V_22 ;
if ( V_5 >= 4 ) {
if ( V_6 != V_23 )
return - 1 ;
++ V_6 ;
V_5 &= 3 ;
}
if ( V_6 == V_24 ) {
V_8 = V_1 & 7 ;
V_9 = ( V_8 == 6 ) ? 7 : 3 ;
V_7 = V_25 [ V_8 ] ;
V_10 |= ( unsigned long ) V_9 << V_7 ;
V_11 |= ( unsigned long ) ( ( V_1 >> V_26 ) & V_9 )
<< V_7 ;
}
V_10 |= 0xfUL << ( 24 - 4 * V_5 ) ;
V_11 |= ( unsigned long ) V_6 << ( 24 - 4 * V_5 ) ;
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
int V_4 = ( V_1 >> V_12 ) & V_13 ;
return V_4 == 5 || V_4 == 6 ;
}
static int F_3 ( unsigned int V_1 )
{
int V_27 , V_28 ;
for ( V_27 = 0 ; V_27 < F_4 ( V_29 ) ; ++ V_27 ) {
if ( V_1 < V_29 [ V_27 ] [ 0 ] )
break;
for ( V_28 = 0 ; V_28 < V_30 && V_29 [ V_27 ] [ V_28 ] ; ++ V_28 )
if ( V_1 == V_29 [ V_27 ] [ V_28 ] )
return V_27 ;
}
return - 1 ;
}
static T_2 F_5 ( T_1 V_1 )
{
int V_4 , V_31 , V_32 , V_28 ;
V_4 = ( V_1 >> V_12 ) & V_13 ;
if ( V_4 == 0 || V_4 > 4 )
return - 1 ;
V_31 = 5 - V_4 ;
V_32 = V_1 & V_33 ;
for ( V_28 = 0 ; V_28 < 4 ; ++ V_28 ) {
if ( V_34 [ V_4 - 1 ] [ V_28 ] == V_32 ) {
return ( V_1 & ~ ( V_35 | V_33 ) ) |
( V_31 << V_12 ) |
V_34 [ V_31 - 1 ] [ V_28 ] ;
}
}
if ( V_4 == 1 && ( V_32 == 0x0d || V_32 == 0x0e ) )
return V_1 + ( 2 << V_12 ) + ( 0x2e - 0x0d ) ;
if ( V_4 == 3 && ( V_32 == 0x2e || V_32 == 0x2f ) )
return V_1 - ( 2 << V_12 ) - ( 0x2e - 0x0d ) ;
if ( V_32 == 0x10 || V_32 == 0x28 )
return ( ( V_1 ^ ( 0x10 ^ 0x28 ) ) & ~ V_35 ) |
( V_31 << V_12 ) ;
return - 1 ;
}
static int F_6 ( T_1 V_1 , unsigned int V_36 , T_1 V_37 [] )
{
int V_27 , V_28 , V_38 = 1 ;
int V_39 ;
T_2 V_40 ;
V_37 [ 0 ] = V_1 ;
V_38 = 1 ;
V_39 = F_2 ( V_1 ) ;
V_27 = F_3 ( V_1 ) ;
if ( V_27 >= 0 ) {
for ( V_28 = 0 ; V_28 < V_30 ; ++ V_28 ) {
V_40 = V_29 [ V_27 ] [ V_28 ] ;
if ( V_40 && V_40 != V_1 )
V_37 [ V_38 ++ ] = V_40 ;
V_39 += F_2 ( V_40 ) ;
}
} else {
V_40 = F_5 ( V_1 ) ;
if ( V_40 > 0 )
V_37 [ V_38 ++ ] = V_40 ;
}
if ( V_36 & V_41 ) {
V_28 = V_38 ;
for ( V_27 = 0 ; V_27 < V_38 ; ++ V_27 ) {
switch ( V_37 [ V_27 ] ) {
case 0xf :
V_37 [ V_28 ++ ] = 0x600005 ;
++ V_39 ;
break;
case 0x600005 :
V_37 [ V_28 ++ ] = 0xf ;
break;
case 0x100009 :
V_37 [ V_28 ++ ] = 0x500009 ;
++ V_39 ;
break;
case 0x500009 :
V_37 [ V_28 ++ ] = 0x100009 ;
V_37 [ V_28 ++ ] = 0x200009 ;
break;
}
}
V_38 = V_28 ;
}
if ( ! ( V_36 & V_42 ) && V_39 ) {
V_28 = 0 ;
for ( V_27 = 0 ; V_27 < V_38 ; ++ V_27 ) {
if ( ! F_2 ( V_37 [ V_27 ] ) ) {
V_37 [ V_28 ] = V_37 [ V_27 ] ;
++ V_28 ;
}
}
V_38 = V_28 ;
} else if ( ( V_36 & V_43 ) && V_39 < V_38 ) {
V_28 = 0 ;
for ( V_27 = 0 ; V_27 < V_38 ; ++ V_27 ) {
if ( F_2 ( V_37 [ V_27 ] ) ) {
V_37 [ V_28 ] = V_37 [ V_27 ] ;
++ V_28 ;
}
}
V_38 = V_28 ;
}
return V_38 ;
}
static int F_7 ( T_1 V_1 )
{
int V_4 , V_44 ;
int V_8 , V_5 , V_6 ;
T_3 V_10 ;
V_4 = ( V_1 >> V_12 ) & V_13 ;
V_44 = V_1 & V_33 ;
if ( V_4 >= 5 )
return 0 ;
V_8 = - 1 ;
if ( V_44 < sizeof( V_45 ) ) {
if ( V_45 [ V_44 ] & ( 1 << V_4 ) )
return 1 ;
if ( V_45 [ V_44 ] & 0x80 )
V_8 = 4 ;
else if ( V_44 == 0x08 )
V_8 = V_4 - 1 ;
else if ( V_44 == 0x10 )
V_8 = 4 - V_4 ;
else if ( V_44 == 0x1b && ( V_4 == 1 || V_4 == 3 ) )
V_8 = 4 ;
} else if ( ( V_44 & 0x48 ) == 0x40 ) {
V_8 = V_44 & 7 ;
} else if ( V_44 == 0x28 ) {
V_8 = V_4 - 1 ;
} else if ( V_4 == 3 && ( V_44 == 0x2e || V_44 == 0x2f ) ) {
V_8 = 4 ;
}
if ( ! ( V_1 & V_14 ) || V_8 == - 1 )
return 0 ;
V_5 = ( V_1 >> V_21 ) & V_22 ;
V_6 = ( V_1 >> V_15 ) & V_16 ;
if ( V_6 == V_46 ) {
V_10 = 0x5dff00 ;
} else if ( V_6 == V_23 && V_5 >= 4 ) {
V_5 -= 4 ;
V_10 = 0x5f11c000 ;
} else
return 0 ;
return ( V_10 >> ( V_5 * 8 + V_8 ) ) & 1 ;
}
static int F_8 ( T_1 V_1 [] , int V_47 ,
unsigned int V_48 [] , unsigned long V_49 [] )
{
unsigned long V_50 = 0 ;
unsigned long V_51 = 0 ;
unsigned int V_4 , V_6 , V_5 , V_44 ;
unsigned int V_52 ;
int V_27 , V_53 , V_8 , V_54 ;
unsigned int V_55 = 0 ;
unsigned char V_56 [ 4 ] ;
unsigned char V_57 [ 16 ] ;
int V_58 ;
if ( V_47 > 6 )
return - 1 ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
memset ( V_57 , 0 , sizeof( V_57 ) ) ;
for ( V_27 = 0 ; V_27 < V_47 ; ++ V_27 ) {
V_4 = ( V_1 [ V_27 ] >> V_12 ) & V_13 ;
if ( V_4 ) {
if ( V_4 > 6 )
return - 1 ;
if ( V_55 & ( 1 << ( V_4 - 1 ) ) )
return - 1 ;
V_55 |= 1 << ( V_4 - 1 ) ;
}
if ( V_1 [ V_27 ] & V_14 ) {
V_6 = ( V_1 [ V_27 ] >> V_15 ) & V_16 ;
V_5 = ( V_1 [ V_27 ] >> V_21 ) & V_22 ;
if ( V_6 > V_17 )
return - 1 ;
if ( V_6 == V_18 )
V_6 = V_19 ;
if ( V_5 >= 4 ) {
if ( V_6 != V_23 )
return - 1 ;
++ V_6 ;
V_5 &= 3 ;
}
if ( V_56 [ V_5 ] && V_56 [ V_5 ] != V_6 )
return - 1 ;
V_56 [ V_5 ] = V_6 ;
V_57 [ V_6 ] = 1 ;
}
}
if ( V_57 [ V_19 ] &
( V_57 [ V_59 ] | V_57 [ V_60 ] | V_57 [ V_61 ] ) ) {
V_57 [ V_18 ] = 1 ;
V_57 [ V_19 ] = 0 ;
}
V_58 = 0 ;
for ( V_27 = V_59 ; V_27 <= V_61 ; ++ V_27 ) {
if ( ! V_57 [ V_27 ] )
continue;
if ( V_58 ++ )
return - 1 ;
V_50 |= ( unsigned long ) V_27 << V_62 ;
}
V_58 = 0 ;
for (; V_27 <= V_24 ; ++ V_27 ) {
if ( ! V_57 [ V_27 ] )
continue;
if ( V_58 ++ )
return - 1 ;
V_50 |= ( unsigned long ) ( V_27 & 3 ) << V_63 ;
}
if ( V_58 > 1 )
return - 1 ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 ) {
V_6 = V_56 [ V_5 ] ;
if ( ! V_6 )
continue;
if ( V_6 == V_19 && V_57 [ V_18 ] ) {
V_6 = V_18 ;
} else if ( V_6 == V_23 + 1 ) {
V_50 |= 1ul << ( V_64 + 3 - V_5 ) ;
}
V_52 = V_6 >> 2 ;
V_50 |= ( unsigned long ) V_52
<< ( V_65 - 2 * V_5 ) ;
}
for ( V_27 = 0 ; V_27 < V_47 ; ++ V_27 ) {
V_4 = ( V_1 [ V_27 ] >> V_12 ) & V_13 ;
V_6 = ( V_1 [ V_27 ] >> V_15 ) & V_16 ;
V_5 = ( V_1 [ V_27 ] >> V_21 ) & V_22 ;
V_44 = V_1 [ V_27 ] & V_33 ;
V_53 = V_1 [ V_27 ] & V_14 ;
if ( ! V_4 ) {
for ( V_4 = 0 ; V_4 < 4 ; ++ V_4 ) {
if ( ! ( V_55 & ( 1 << V_4 ) ) )
break;
}
if ( V_4 >= 4 )
return - 1 ;
V_55 |= 1 << V_4 ;
} else if ( V_4 <= 4 ) {
-- V_4 ;
if ( V_53 && ( V_5 & 2 ) &&
( V_44 == 8 || V_44 == 0x10 || V_44 == 0x28 ) )
V_50 |= 1ul << ( V_66 - V_4 ) ;
} else {
-- V_4 ;
}
if ( V_53 && V_6 == V_24 ) {
V_8 = V_44 & 7 ;
V_54 = ( V_1 [ V_27 ] >> V_26 ) & V_67 ;
V_50 |= ( unsigned long ) V_54 << V_25 [ V_8 ] ;
}
if ( F_7 ( V_1 [ V_27 ] ) )
V_51 |= V_68 ;
if ( ( V_44 & 0x58 ) == 0x40 && ( V_5 & 1 ) != ( ( V_4 >> 1 ) & 1 ) )
V_44 |= 0x10 ;
if ( V_4 <= 3 )
V_50 |= V_44 << F_9 ( V_4 ) ;
V_48 [ V_27 ] = V_4 ;
}
V_49 [ 0 ] = 0 ;
if ( V_55 & 1 )
V_49 [ 0 ] = V_69 ;
if ( V_55 & 0x3e )
V_49 [ 0 ] |= V_70 ;
V_49 [ 1 ] = V_50 ;
V_49 [ 2 ] = V_51 ;
return 0 ;
}
static void F_10 ( unsigned int V_4 , unsigned long V_49 [] )
{
if ( V_4 <= 3 )
V_49 [ 1 ] &= ~ ( 0x7fUL << F_9 ( V_4 ) ) ;
}
static int T_4 F_11 ( void )
{
if ( ! V_71 -> V_72 ||
( strcmp ( V_71 -> V_72 , L_1 )
&& strcmp ( V_71 -> V_72 , L_2 ) ) )
return - V_73 ;
return F_12 ( & V_74 ) ;
}
