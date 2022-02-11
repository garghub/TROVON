static int F_1 ( T_1 V_1 , unsigned long * V_2 ,
unsigned long * V_3 )
{
int V_4 , V_5 ;
unsigned long V_6 = 0 , V_7 = 0 ;
V_4 = ( V_1 >> V_8 ) & V_9 ;
if ( V_4 ) {
if ( V_4 > 6 )
return - 1 ;
V_5 = ( V_4 - 1 ) * 2 ;
V_6 |= 2 << V_5 ;
V_7 |= 1 << V_5 ;
if ( V_4 >= 5 && ! ( V_1 == 0x500fa || V_1 == 0x600f4 ) )
return - 1 ;
}
if ( V_4 < 5 ) {
V_6 |= 0x8000 ;
V_7 |= 0x1000 ;
}
* V_2 = V_6 ;
* V_3 = V_7 ;
return 0 ;
}
static int F_2 ( T_1 V_1 )
{
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < F_3 ( V_12 ) ; ++ V_10 ) {
if ( V_1 < V_12 [ V_10 ] [ 0 ] )
break;
for ( V_11 = 0 ; V_11 < V_13 && V_12 [ V_10 ] [ V_11 ] ; ++ V_11 )
if ( V_1 == V_12 [ V_10 ] [ V_11 ] )
return V_10 ;
}
return - 1 ;
}
static T_2 F_4 ( T_1 V_1 )
{
int V_4 , V_14 ;
V_4 = ( V_1 >> V_8 ) & V_9 ;
V_14 = V_1 & V_15 ;
if ( ( V_4 == 2 || V_4 == 4 ) && ( V_14 & ~ 7 ) == 0x40 )
return V_1 - ( 1 << V_8 ) + 8 ;
if ( ( V_4 == 1 || V_4 == 3 ) && ( V_14 & ~ 7 ) == 0x48 )
return V_1 + ( 1 << V_8 ) - 8 ;
return - 1 ;
}
static int F_5 ( T_1 V_1 , unsigned int V_16 , T_1 V_17 [] )
{
int V_10 , V_11 , V_18 = 1 ;
T_2 V_19 ;
V_17 [ 0 ] = V_1 ;
V_18 = 1 ;
V_10 = F_2 ( V_1 ) ;
if ( V_10 >= 0 ) {
for ( V_11 = 0 ; V_11 < V_13 ; ++ V_11 ) {
V_19 = V_12 [ V_10 ] [ V_11 ] ;
if ( V_19 && V_19 != V_1 )
V_17 [ V_18 ++ ] = V_19 ;
}
} else {
V_19 = F_4 ( V_1 ) ;
if ( V_19 > 0 )
V_17 [ V_18 ++ ] = V_19 ;
}
if ( V_16 & V_20 ) {
V_11 = V_18 ;
for ( V_10 = 0 ; V_10 < V_18 ; ++ V_10 ) {
switch ( V_17 [ V_10 ] ) {
case 0x1e :
V_17 [ V_11 ++ ] = 0x600f4 ;
break;
case 0x600f4 :
V_17 [ V_11 ++ ] = 0x1e ;
break;
case 0x2 :
V_17 [ V_11 ++ ] = 0x500fa ;
break;
case 0x500fa :
V_17 [ V_11 ++ ] = 0x2 ;
break;
}
}
V_18 = V_11 ;
}
return V_18 ;
}
static int F_6 ( T_1 V_1 )
{
int V_4 , V_14 ;
int V_21 ;
V_4 = ( V_1 >> V_8 ) & V_9 ;
V_21 = ( V_1 >> V_22 ) & V_23 ;
V_14 = V_1 & V_15 & ~ 1 ;
if ( V_4 >= 5 )
return 0 ;
switch ( V_14 >> 4 ) {
case 2 :
return V_4 == 2 || V_4 == 4 ;
case 3 :
if ( V_14 == 0x3c )
return V_4 == 1 ;
if ( V_14 == 0x3e )
return V_4 != 2 ;
return 1 ;
case 4 :
case 5 :
return V_21 == 0xd ;
case 6 :
if ( V_14 == 0x64 )
return V_4 >= 3 ;
case 8 :
return V_21 == 0xd ;
}
return 0 ;
}
static int F_7 ( T_1 V_1 [] , int V_24 ,
unsigned int V_25 [] , unsigned long V_26 [] )
{
unsigned long V_27 = 0 ;
unsigned long V_28 = V_29 | V_30 ;
unsigned int V_4 , V_21 , V_31 , V_32 , V_14 ;
unsigned int V_33 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_24 ; ++ V_10 ) {
V_4 = ( V_1 [ V_10 ] >> V_8 ) & V_9 ;
if ( V_4 ) {
if ( V_4 > 6 )
return - 1 ;
if ( V_33 & ( 1 << ( V_4 - 1 ) ) )
return - 1 ;
V_33 |= 1 << ( V_4 - 1 ) ;
}
}
for ( V_10 = 0 ; V_10 < V_24 ; ++ V_10 ) {
V_4 = ( V_1 [ V_10 ] >> V_8 ) & V_9 ;
V_21 = ( V_1 [ V_10 ] >> V_22 ) & V_23 ;
V_31 = ( V_1 [ V_10 ] >> V_34 ) & V_35 ;
V_32 = ( V_1 [ V_10 ] >> V_36 ) & V_37 ;
V_14 = V_1 [ V_10 ] & V_15 ;
if ( ! V_4 ) {
for ( V_4 = 0 ; V_4 < 4 ; ++ V_4 ) {
if ( ! ( V_33 & ( 1 << V_4 ) ) )
break;
}
if ( V_4 >= 4 )
return - 1 ;
V_33 |= 1 << V_4 ;
} else {
-- V_4 ;
}
if ( V_4 <= 3 ) {
V_27 |= ( unsigned long ) V_21
<< ( V_38 - 4 * V_4 ) ;
V_27 |= ( unsigned long ) V_31
<< ( V_39 - V_4 ) ;
V_27 |= V_14 << F_8 ( V_4 ) ;
if ( V_21 == 6 )
V_27 |= ( unsigned long ) V_32
<< V_40 ;
}
if ( F_6 ( V_1 [ V_10 ] ) )
V_28 |= V_41 ;
V_25 [ V_10 ] = V_4 ;
}
V_26 [ 0 ] = 0 ;
if ( V_33 & 1 )
V_26 [ 0 ] = V_42 ;
if ( V_33 & 0x3e )
V_26 [ 0 ] |= V_43 ;
V_26 [ 1 ] = V_27 ;
V_26 [ 2 ] = V_28 ;
return 0 ;
}
static void F_9 ( unsigned int V_4 , unsigned long V_26 [] )
{
if ( V_4 <= 3 )
V_26 [ 1 ] &= ~ ( 0xffUL << F_8 ( V_4 ) ) ;
}
static int T_3 F_10 ( void )
{
if ( ! V_44 -> V_45 ||
strcmp ( V_44 -> V_45 , L_1 ) )
return - V_46 ;
if ( F_11 ( V_47 ) )
V_48 . V_16 |= V_49 ;
return F_12 ( & V_48 ) ;
}
