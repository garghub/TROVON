void
F_1 ( unsigned char V_1 , int V_2 )
{
if ( V_3 == 4 )
{
F_2 ( V_1 | ( V_1 << 8 ) , ( V_2 + V_4 ) - 1 ) ;
F_3 ( ( 0x80 ) , 0 ) ;
} else
F_4 ( V_1 , V_2 ) ;
}
static int
F_5 ( int V_5 , int V_6 , int div , int V_7 ,
int V_8 )
{
int V_9 = V_6 * div / 100 ;
int V_10 = V_5 * div / 100 ;
if ( V_7 & 0x10 )
{
V_9 |= V_8 ;
V_10 |= V_8 ;
}
if ( V_7 == 0x03 || V_7 == 0x04 )
{
F_1 ( 0x80 | V_7 , 0x078B ) ;
F_1 ( V_9 , 0x078B ) ;
V_5 = V_6 ;
} else
{
F_1 ( 0x80 | 0x20 | V_7 , 0x078B ) ;
F_1 ( V_9 , 0x078B ) ;
F_1 ( 0x80 | 0x40 | V_7 , 0x078B ) ;
F_1 ( V_10 , 0x078B ) ;
}
return ( V_6 | ( V_5 << 8 ) ) ;
}
static void
F_6 ( int V_11 )
{
F_1 ( 0x80 | 0x05 , 0x078B ) ;
F_1 ( V_11 , 0x078B ) ;
V_12 = V_11 ;
}
static int
F_7 ( int V_13 , unsigned int V_14 )
{
int V_9 , V_10 , V_15 , V_16 , V_17 , V_8 = 0 ;
V_9 = V_14 & 0x7f ;
V_10 = ( V_14 & 0x7f00 ) >> 8 ;
if ( V_13 < V_18 ) {
if ( ( 1 << V_13 ) & V_19 )
V_8 = 0x20 ;
else
V_8 = 0x00 ;
}
switch ( V_13 )
{
case V_20 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 63 , 0x01 , 0 ) ;
break;
case V_22 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 12 , 0x03 , 0 ) ;
break;
case V_23 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 12 , 0x04 , 0 ) ;
break;
case V_24 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 31 , 0x10 | 0x00 , V_8 ) ;
break;
case V_25 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 31 , 0x10 | 0x05 , V_8 ) ;
break;
case V_26 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 31 , 0x10 | 0x07 , V_8 ) ;
break;
case V_27 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 31 , 0x10 | 0x06 , V_8 ) ;
break;
case V_28 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 31 , 0x10 | 0x02 , V_8 ) ;
break;
case V_29 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 31 , 0x10 | 0x03 , V_8 ) ;
break;
case V_30 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 31 , 0x10 | 0x04 , V_8 ) ;
break;
case V_31 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 31 , 0x10 | 0x01 ,
0x00 ) ;
break;
case V_32 :
V_21 [ V_13 ] = F_5 ( V_10 , V_9 , 15 , 0x02 , 0 ) ;
break;
case V_33 :
V_15 = V_14 & V_34 ;
V_16 = V_15 ^ V_19 ;
V_19 = V_15 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
if ( V_16 & ( 1 << V_17 ) )
{
F_7 ( V_17 , V_21 [ V_17 ] ) ;
}
return V_19 ;
break;
default:
return - V_35 ;
}
return ( V_21 [ V_13 ] ) ;
}
static void
F_8 ( void )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_18 ; V_36 ++ )
F_7 ( V_36 , V_21 [ V_36 ] ) ;
F_6 ( 0x04 | 0x01 ) ;
}
static int F_9 ( int V_37 , unsigned int V_38 , void T_1 * V_39 )
{
int V_14 , V_40 ;
int T_1 * V_41 = ( int T_1 * ) V_39 ;
if ( V_38 == V_42 ) {
if ( F_10 ( V_14 , V_41 ) )
return - V_43 ;
if ( V_14 == - 1 )
V_14 = ( V_12 & 0x04 ) ;
else {
V_12 &= ~ 0x04 ;
if ( V_14 )
V_12 |= 0x04 ;
F_6 ( V_12 ) ;
}
V_14 = ! ! V_14 ;
return F_11 ( V_14 , V_41 ) ;
}
if ( V_38 == V_44 ) {
if ( F_10 ( V_14 , V_41 ) )
return - V_43 ;
if ( V_14 == - 1 ) {
if ( ! ( V_12 & 0x03 ) )
V_14 = 0 ;
else
V_14 = ( ( V_12 & 0x03 ) + 1 ) * 20 ;
} else {
int V_17 = 0 ;
V_14 &= 0x7f ;
if ( V_14 )
V_17 = ( V_14 / 20 ) - 1 ;
V_12 &= ~ 0x03 ;
V_12 |= V_17 & 0x03 ;
F_6 ( V_12 ) ;
if ( V_17 )
V_17 = ( V_17 + 1 ) * 20 ;
V_14 = V_17 ;
}
return F_11 ( V_14 , V_41 ) ;
}
if ( V_38 == V_45 ) {
if ( F_10 ( V_14 , V_41 ) )
return - V_43 ;
if ( V_14 == - 1 )
V_14 = ! ( F_12 ( 0x0B8A ) & 0x20 ) ;
else {
if ( V_14 )
F_4 ( F_12 ( 0x0B8A ) & ( ~ 0x20 ) , 0x0B8A ) ;
else
F_4 ( F_12 ( 0x0B8A ) | 0x20 , 0x0B8A ) ;
V_14 = ! ( F_12 ( 0x0B8A ) & 0x20 ) ;
}
return F_11 ( V_14 , V_41 ) ;
}
if ( ( ( V_38 >> 8 ) & 0xff ) == 'M' ) {
if ( F_10 ( V_40 , V_41 ) )
return - V_43 ;
if ( F_13 ( V_38 ) & V_46 ) {
V_40 = F_7 ( V_38 & 0xff , V_40 ) ;
} else {
switch ( V_38 & 0xff ) {
case V_33 :
V_40 = V_19 ;
break;
case V_47 :
V_40 = V_48 & ~ ( V_49 | V_50 ) ;
break;
case V_51 :
V_40 = V_48 ;
break;
case V_52 :
V_40 = V_34 & V_48 ;
break;
case V_53 :
V_40 = 0 ;
break;
default:
V_40 = V_21 [ V_38 & 0xff ] ;
break;
}
}
return F_11 ( V_40 , V_41 ) ;
}
return - V_35 ;
}
int T_2
F_14 ( void )
{
int V_54 ;
V_21 = F_15 ( L_1 , V_55 , 1 ) ;
F_8 () ;
if ( ( V_54 = F_16 () ) != - 1 )
{
V_56 [ V_57 ] -> V_58 = V_54 ;
V_59 [ V_54 ] = & V_60 ;
}
return 1 ;
}
