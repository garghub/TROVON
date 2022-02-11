static int F_1 ( T_1 V_1 )
{
int V_2 ;
V_2 = ( V_1 >> V_3 ) & V_4 ;
if ( V_2 ) {
if ( V_2 > V_5 )
return - 1 ;
return 4 ;
}
V_1 &= V_6 ;
if ( V_1 <= 1 )
return 0 ;
if ( V_1 <= 7 )
return 1 ;
if ( V_1 <= 13 )
return 2 ;
if ( V_1 <= 22 )
return 3 ;
return - 1 ;
}
static int F_2 ( T_1 V_1 )
{
int V_2 , V_7 ;
V_2 = ( V_1 >> V_3 ) & V_4 ;
V_7 = V_1 & V_6 ;
switch ( V_2 ) {
case 1 :
if ( V_7 == 0x1e || V_7 == 0x1f )
return 1 ;
if ( V_7 == 0x28 || V_7 == 0x2b )
return 2 ;
break;
case 2 :
if ( V_7 == 0x20 )
return 1 ;
break;
case 3 :
if ( V_7 == 0xc || V_7 == 0xd )
return 1 ;
if ( V_7 == 0x11 )
return 2 ;
break;
case 4 :
if ( V_7 == 0x10 )
return 1 ;
break;
}
return 0 ;
}
static int F_3 ( T_2 V_1 , unsigned long * V_8 ,
unsigned long * V_9 )
{
int V_2 , V_10 ;
T_1 V_11 , V_12 ;
int V_13 , V_14 ;
V_10 = F_1 ( V_1 ) ;
if ( V_10 < 0 )
return - 1 ;
if ( V_10 == 4 ) {
V_2 = ( ( unsigned int ) V_1 >> V_3 ) & V_4 ;
V_11 = V_15 [ V_2 - 1 ] [ 0 ] ;
V_12 = V_15 [ V_2 - 1 ] [ 1 ] ;
} else {
V_11 = V_16 [ V_10 ] [ 0 ] ;
V_12 = V_16 [ V_10 ] [ 1 ] ;
}
V_14 = F_2 ( V_1 ) ;
if ( V_14 ) {
V_13 = ( ( unsigned int ) V_1 >> V_17 ) & V_18 ;
V_11 |= 0x3f << 24 ;
V_12 |= V_13 << 24 ;
if ( V_14 == 2 ) {
V_11 |= 0x40000000 ;
if ( ( unsigned int ) V_1 & V_19 )
V_12 |= 0x40000000 ;
}
}
* V_8 = V_11 ;
* V_9 = V_12 ;
return 0 ;
}
static int F_4 ( T_1 V_1 )
{
int V_20 , V_21 ;
for ( V_20 = 0 ; V_20 < F_5 ( V_22 ) ; ++ V_20 ) {
if ( V_1 < V_22 [ V_20 ] [ 0 ] )
break;
for ( V_21 = 0 ; V_21 < V_23 && V_22 [ V_20 ] [ V_21 ] ; ++ V_21 )
if ( V_1 == V_22 [ V_20 ] [ V_21 ] )
return V_20 ;
}
return - 1 ;
}
static int F_6 ( T_2 V_1 , unsigned int V_24 , T_2 V_25 [] )
{
int V_20 , V_21 , V_26 = 1 ;
T_1 V_27 ;
V_25 [ 0 ] = V_1 ;
V_26 = 1 ;
V_20 = F_4 ( ( T_1 ) V_1 ) ;
if ( V_20 >= 0 ) {
for ( V_21 = 0 ; V_21 < V_23 ; ++ V_21 ) {
V_27 = V_22 [ V_20 ] [ V_21 ] ;
if ( V_27 && V_27 != ( T_1 ) V_1 )
V_25 [ V_26 ++ ] = V_27 ;
}
}
return V_26 ;
}
static int F_7 ( T_2 V_1 [] , int V_28 ,
unsigned int V_29 [] , unsigned long V_30 [] )
{
T_3 V_31 [ V_32 ] [ V_5 ] ;
int V_33 [ V_32 ] ;
int V_20 , V_21 , V_10 , V_14 ;
T_1 V_34 = 0 , V_35 ;
T_1 V_36 = 0 , V_37 = 0 , V_38 = 0 ;
T_1 V_39 , V_2 , V_13 ;
if ( V_28 > V_5 )
return - 1 ;
for ( V_20 = 0 ; V_20 < V_32 ; ++ V_20 )
V_33 [ V_20 ] = 0 ;
for ( V_20 = 0 ; V_20 < V_28 ; ++ V_20 ) {
V_10 = F_1 ( V_1 [ V_20 ] ) ;
if ( V_10 < 0 )
return - 1 ;
V_21 = V_33 [ V_10 ] ++ ;
V_31 [ V_10 ] [ V_21 ] = V_20 ;
}
for ( V_10 = V_32 - 1 ; V_10 >= 0 ; -- V_10 ) {
for ( V_20 = 0 ; V_20 < V_33 [ V_10 ] ; ++ V_20 ) {
V_39 = V_1 [ V_31 [ V_10 ] [ V_20 ] ] ;
if ( V_10 == 4 ) {
V_2 = ( V_39 >> V_3 ) & V_4 ;
if ( V_34 & ( 1 << ( V_2 - 1 ) ) )
return - 1 ;
} else {
V_35 = V_40 [ V_10 ] & ~ V_34 ;
if ( ! V_35 )
return - 1 ;
V_2 = F_8 ( V_35 ) ;
}
V_34 |= 1 << ( V_2 - 1 ) ;
V_14 = F_2 ( V_39 ) ;
if ( V_14 ) {
V_13 = ( V_39 >> V_17 ) & V_18 ;
V_36 |= V_13 << 16 ;
if ( V_14 == 2 && ( V_39 & V_19 ) )
V_38 = 0x80000000 ;
}
V_39 &= V_41 [ V_2 - 1 ] ;
V_39 <<= V_42 [ V_2 - 1 ] ;
if ( V_2 <= 2 )
V_36 |= V_39 ;
else
V_37 |= V_39 ;
V_29 [ V_31 [ V_10 ] [ V_20 ] ] = V_2 - 1 ;
}
}
if ( V_34 & 1 )
V_36 |= V_43 ;
if ( V_34 & 0x3e )
V_36 |= V_44 ;
V_30 [ 0 ] = V_36 ;
V_30 [ 1 ] = V_37 ;
V_30 [ 2 ] = V_38 ;
return 0 ;
}
static void F_9 ( unsigned int V_2 , unsigned long V_30 [] )
{
if ( V_2 <= 1 )
V_30 [ 0 ] &= ~ ( V_41 [ V_2 ] << V_42 [ V_2 ] ) ;
else
V_30 [ 1 ] &= ~ ( V_41 [ V_2 ] << V_42 [ V_2 ] ) ;
}
static int F_10 ( void )
{
if ( ! V_45 -> V_46 ||
strcmp ( V_45 -> V_46 , L_1 ) )
return - V_47 ;
return F_11 ( & V_48 ) ;
}
