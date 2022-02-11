static void
F_1 ( unsigned int V_1 , unsigned long * V_2 ,
unsigned long * V_3 , T_1 * type )
{
unsigned char V_4 , V_5 , V_6 , V_7 ;
unsigned long V_8 ;
V_4 = V_9 + ( V_1 << 1 ) + V_1 ;
F_2 ( V_8 ) ;
V_5 = F_3 ( V_10 ) ;
F_4 ( V_10 , ( V_5 & 0x0f ) | 0x10 ) ;
( ( unsigned char * ) V_2 ) [ 3 ] = F_3 ( V_4 ) ;
( ( unsigned char * ) V_2 ) [ 2 ] = F_3 ( V_4 + 1 ) ;
( ( unsigned char * ) V_2 ) [ 1 ] = F_3 ( V_4 + 2 ) ;
V_6 = F_3 ( V_11 + V_1 ) ;
F_4 ( V_10 , V_5 ) ;
F_5 ( V_8 ) ;
V_7 = ( ( unsigned char * ) V_2 ) [ 1 ] & 0x0f ;
* V_2 >>= V_12 ;
if ( V_7 )
* V_3 = ( V_1 < 7 ? 0x1UL : 0x40UL ) << ( V_7 - 1 ) ;
else
* V_3 = 0 ;
if ( V_1 < 7 ) {
switch ( V_6 ) {
case 1 :
* type = V_13 ;
break;
case 8 :
* type = V_14 ;
break;
case 9 :
* type = V_15 ;
break;
case 24 :
default:
* type = V_16 ;
break;
}
} else {
switch ( V_6 ) {
case 0 :
* type = V_13 ;
break;
case 8 :
* type = V_15 ;
break;
case 9 :
* type = V_14 ;
break;
case 25 :
default:
* type = V_16 ;
break;
}
}
}
static int
F_6 ( unsigned long V_2 , unsigned long V_3 , int V_17 )
{
unsigned long V_18 , V_19 ;
T_1 V_20 ;
int V_21 ;
switch ( V_17 ) {
case 7 :
if ( V_3 < 0x40 )
break;
case 6 :
case 5 :
case 4 :
return V_17 ;
case 3 :
case 2 :
case 1 :
case 0 :
return V_17 ;
}
if ( V_3 > 0x2000 ) {
F_1 ( 7 , & V_18 , & V_19 , & V_20 ) ;
if ( V_19 == 0 )
return 7 ;
} else {
for ( V_21 = 0 ; V_21 < 7 ; V_21 ++ ) {
F_1 ( V_21 , & V_18 , & V_19 , & V_20 ) ;
if ( V_19 == 0 )
return V_21 ;
}
F_1 ( V_21 , & V_18 , & V_19 , & V_20 ) ;
if ( ( V_19 == 0 ) && ( V_3 >= 0x40 ) )
return V_21 ;
}
return - V_22 ;
}
static void F_7 ( void )
{
T_2 V_23 ;
if ( V_24 ) {
V_25 = F_8 () ;
F_9 ( V_25 & ~ V_26 ) ;
}
V_23 = F_10 () | V_27 ;
F_11 () ;
F_12 ( V_23 ) ;
F_11 () ;
V_5 = F_3 ( V_10 ) ;
F_4 ( V_10 , ( V_5 & 0x0f ) | 0x10 ) ;
}
static void F_13 ( void )
{
F_11 () ;
F_4 ( V_10 , V_5 ) ;
F_12 ( F_10 () & 0xbfffffff ) ;
if ( V_24 )
F_9 ( V_25 ) ;
}
static void F_14 ( unsigned int V_1 , unsigned long V_2 ,
unsigned long V_3 , T_1 type )
{
unsigned char V_4 , V_28 , V_29 ;
V_4 = V_9 + ( V_1 << 1 ) + V_1 ;
if ( V_1 >= 7 )
V_3 >>= 6 ;
V_3 &= 0x7fff ;
for ( V_29 = 0 ; V_3 ; V_29 ++ , V_3 >>= 1 )
;
if ( V_1 < 7 ) {
switch ( type ) {
case V_13 :
V_28 = 1 ;
break;
case V_15 :
V_28 = 9 ;
break;
case V_16 :
V_28 = 24 ;
break;
default:
V_28 = 8 ;
break;
}
} else {
switch ( type ) {
case V_13 :
V_28 = 0 ;
break;
case V_15 :
V_28 = 8 ;
break;
case V_16 :
V_28 = 25 ;
break;
default:
V_28 = 9 ;
break;
}
}
F_7 () ;
V_2 <<= V_12 ;
F_4 ( V_4 + 0 , ( ( unsigned char * ) & V_2 ) [ 3 ] ) ;
F_4 ( V_4 + 1 , ( ( unsigned char * ) & V_2 ) [ 2 ] ) ;
F_4 ( V_4 + 2 , ( ( ( unsigned char * ) & V_2 ) [ 1 ] ) | V_29 ) ;
F_4 ( V_11 + V_1 , V_28 ) ;
F_13 () ;
}
static void F_15 ( void )
{
int V_21 ;
F_7 () ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ )
F_4 ( V_30 + V_21 , V_31 [ V_21 ] ) ;
for (; V_21 < 7 ; V_21 ++ )
F_4 ( V_32 + V_21 , V_31 [ V_21 ] ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
F_14 ( V_21 , V_33 [ V_21 ] . V_2 ,
V_33 [ V_21 ] . V_3 , V_33 [ V_21 ] . type ) ;
}
F_13 () ;
}
int T_3 F_16 ( void )
{
F_17 ( & V_34 ) ;
return 0 ;
}
