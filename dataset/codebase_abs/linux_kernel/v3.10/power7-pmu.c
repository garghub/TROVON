static int F_1 ( T_1 V_1 , unsigned long * V_2 ,
unsigned long * V_3 )
{
int V_4 , V_5 , V_6 ;
unsigned long V_7 = 0 , V_8 = 0 ;
V_4 = ( V_1 >> V_9 ) & V_10 ;
if ( V_4 ) {
if ( V_4 > 6 )
return - 1 ;
V_5 = ( V_4 - 1 ) * 2 ;
V_7 |= 2 << V_5 ;
V_8 |= 1 << V_5 ;
if ( V_4 >= 5 && ! ( V_1 == 0x500fa || V_1 == 0x600f4 ) )
return - 1 ;
}
if ( V_4 < 5 ) {
V_7 |= 0x8000 ;
V_8 |= 0x1000 ;
}
V_6 = ( V_1 >> V_11 ) & V_12 ;
if ( V_6 == 6 ) {
int V_13 = ( V_1 >> V_14 ) & V_15 ;
V_7 |= 0x7 << 16 ;
V_8 |= V_13 << 16 ;
}
* V_2 = V_7 ;
* V_3 = V_8 ;
return 0 ;
}
static int F_2 ( T_1 V_1 )
{
int V_16 , V_17 ;
for ( V_16 = 0 ; V_16 < F_3 ( V_18 ) ; ++ V_16 ) {
if ( V_1 < V_18 [ V_16 ] [ 0 ] )
break;
for ( V_17 = 0 ; V_17 < V_19 && V_18 [ V_16 ] [ V_17 ] ; ++ V_17 )
if ( V_1 == V_18 [ V_16 ] [ V_17 ] )
return V_16 ;
}
return - 1 ;
}
static T_2 F_4 ( T_1 V_1 )
{
int V_4 , V_20 ;
V_4 = ( V_1 >> V_9 ) & V_10 ;
V_20 = V_1 & V_21 ;
if ( ( V_4 == 2 || V_4 == 4 ) && ( V_20 & ~ 7 ) == 0x40 )
return V_1 - ( 1 << V_9 ) + 8 ;
if ( ( V_4 == 1 || V_4 == 3 ) && ( V_20 & ~ 7 ) == 0x48 )
return V_1 + ( 1 << V_9 ) - 8 ;
return - 1 ;
}
static int F_5 ( T_1 V_1 , unsigned int V_22 , T_1 V_23 [] )
{
int V_16 , V_17 , V_24 = 1 ;
T_2 V_25 ;
V_23 [ 0 ] = V_1 ;
V_24 = 1 ;
V_16 = F_2 ( V_1 ) ;
if ( V_16 >= 0 ) {
for ( V_17 = 0 ; V_17 < V_19 ; ++ V_17 ) {
V_25 = V_18 [ V_16 ] [ V_17 ] ;
if ( V_25 && V_25 != V_1 )
V_23 [ V_24 ++ ] = V_25 ;
}
} else {
V_25 = F_4 ( V_1 ) ;
if ( V_25 > 0 )
V_23 [ V_24 ++ ] = V_25 ;
}
if ( V_22 & V_26 ) {
V_17 = V_24 ;
for ( V_16 = 0 ; V_16 < V_24 ; ++ V_16 ) {
switch ( V_23 [ V_16 ] ) {
case 0x1e :
V_23 [ V_17 ++ ] = 0x600f4 ;
break;
case 0x600f4 :
V_23 [ V_17 ++ ] = 0x1e ;
break;
case 0x2 :
V_23 [ V_17 ++ ] = 0x500fa ;
break;
case 0x500fa :
V_23 [ V_17 ++ ] = 0x2 ;
break;
}
}
V_24 = V_17 ;
}
return V_24 ;
}
static int F_6 ( T_1 V_1 )
{
int V_4 , V_20 ;
int V_6 ;
V_4 = ( V_1 >> V_9 ) & V_10 ;
V_6 = ( V_1 >> V_11 ) & V_12 ;
V_20 = V_1 & V_21 & ~ 1 ;
if ( V_4 >= 5 )
return 0 ;
switch ( V_20 >> 4 ) {
case 2 :
return V_4 == 2 || V_4 == 4 ;
case 3 :
if ( V_20 == 0x3c )
return V_4 == 1 ;
if ( V_20 == 0x3e )
return V_4 != 2 ;
return 1 ;
case 4 :
case 5 :
return V_6 == 0xd ;
case 6 :
if ( V_20 == 0x64 )
return V_4 >= 3 ;
case 8 :
return V_6 == 0xd ;
}
return 0 ;
}
static int F_7 ( T_1 V_1 [] , int V_27 ,
unsigned int V_28 [] , unsigned long V_29 [] )
{
unsigned long V_30 = 0 ;
unsigned long V_31 = V_32 | V_33 ;
unsigned int V_4 , V_6 , V_34 , V_13 , V_20 ;
unsigned int V_35 = 0 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_27 ; ++ V_16 ) {
V_4 = ( V_1 [ V_16 ] >> V_9 ) & V_10 ;
if ( V_4 ) {
if ( V_4 > 6 )
return - 1 ;
if ( V_35 & ( 1 << ( V_4 - 1 ) ) )
return - 1 ;
V_35 |= 1 << ( V_4 - 1 ) ;
}
}
for ( V_16 = 0 ; V_16 < V_27 ; ++ V_16 ) {
V_4 = ( V_1 [ V_16 ] >> V_9 ) & V_10 ;
V_6 = ( V_1 [ V_16 ] >> V_11 ) & V_12 ;
V_34 = ( V_1 [ V_16 ] >> V_36 ) & V_37 ;
V_13 = ( V_1 [ V_16 ] >> V_14 ) & V_15 ;
V_20 = V_1 [ V_16 ] & V_21 ;
if ( ! V_4 ) {
for ( V_4 = 0 ; V_4 < 4 ; ++ V_4 ) {
if ( ! ( V_35 & ( 1 << V_4 ) ) )
break;
}
if ( V_4 >= 4 )
return - 1 ;
V_35 |= 1 << V_4 ;
} else {
-- V_4 ;
}
if ( V_4 <= 3 ) {
V_30 |= ( unsigned long ) V_6
<< ( V_38 - 4 * V_4 ) ;
V_30 |= ( unsigned long ) V_34
<< ( V_39 - V_4 ) ;
V_30 |= V_20 << F_8 ( V_4 ) ;
if ( V_6 == 6 )
V_30 |= ( unsigned long ) V_13
<< V_40 ;
}
if ( F_6 ( V_1 [ V_16 ] ) )
V_31 |= V_41 ;
V_28 [ V_16 ] = V_4 ;
}
V_29 [ 0 ] = 0 ;
if ( V_35 & 1 )
V_29 [ 0 ] = V_42 ;
if ( V_35 & 0x3e )
V_29 [ 0 ] |= V_43 ;
V_29 [ 1 ] = V_30 ;
V_29 [ 2 ] = V_31 ;
return 0 ;
}
static void F_9 ( unsigned int V_4 , unsigned long V_29 [] )
{
if ( V_4 <= 3 )
V_29 [ 1 ] &= ~ ( 0xffUL << F_8 ( V_4 ) ) ;
}
static int T_3 F_10 ( void )
{
if ( ! V_44 -> V_45 ||
strcmp ( V_44 -> V_45 , L_1 ) )
return - V_46 ;
if ( F_11 ( V_47 ) )
V_48 . V_22 |= V_49 ;
return F_12 ( & V_48 ) ;
}
