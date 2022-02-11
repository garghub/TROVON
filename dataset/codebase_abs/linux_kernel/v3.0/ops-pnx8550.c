static inline void F_1 ( void )
{
unsigned long V_1 ;
V_1 = F_2 ( V_2 | V_3 ) ;
F_3 ( V_1 , V_2 | V_4 ) ;
}
static inline unsigned int
F_4 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 )
{
unsigned int V_9 ;
V_9 = ( ( V_6 -> V_10 > 0 ) ? ( ( ( V_6 -> V_10 & 0xff ) << V_11 ) | 1 ) : 0 ) ;
V_9 |= ( ( V_7 & 0xff ) << V_12 ) | ( V_8 & 0xfc ) ;
return V_9 ;
}
static int
F_5 ( unsigned int V_13 , struct V_5 * V_6 , unsigned int V_7 , int V_8 , unsigned int V_14 , unsigned int * V_15 )
{
unsigned int V_16 ;
unsigned long V_17 = 0 ;
unsigned long V_18 = F_4 ( V_6 , V_7 , V_8 ) ;
F_6 ( V_16 ) ;
if ( F_2 ( V_2 | V_3 ) ) {
F_1 () ;
while ( ! ( F_2 ( V_2 | V_3 ) == 0 ) ) ;
}
F_3 ( V_18 , V_2 | V_19 ) ;
if ( ( V_13 == V_20 ) || ( V_13 == V_21 ) )
F_3 ( * V_15 , V_2 | V_22 ) ;
F_3 ( V_23 | V_13 | ( V_14 & V_24 ) ,
V_2 | V_25 ) ;
V_17 =
( ( V_26 *
V_27 ) >> ( V_28 ) ) ;
while ( 1 ) {
if ( F_2 ( V_2 | V_3 ) & V_29 ) {
if ( ( V_13 == V_30 ) ||
( V_13 == V_31 ) )
* V_15 = F_2 ( V_2 | V_32 ) ;
F_1 () ;
F_7 ( V_16 ) ;
return V_33 ;
} else if ( F_2 ( V_2 | V_3 ) & V_34 ) {
break;
}
V_17 -- ;
if ( V_17 == 0 ) {
F_8 ( L_1 , V_35 ) ;
}
}
F_1 () ;
if ( ( V_13 == V_30 ) || ( V_13 == V_20 ) ) {
F_8 ( L_2 ,
V_35 , F_2 ( V_2 | V_25 ) , V_18 ,
V_13 ) ;
}
if ( ( V_13 == V_30 ) || ( V_13 == V_31 ) )
* V_15 = 0xffffffff ;
F_7 ( V_16 ) ;
return V_36 ;
}
static int
F_9 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 , T_1 * V_15 )
{
unsigned int V_37 = 0 ;
int V_38 ;
if ( V_6 == NULL )
return - 1 ;
V_38 = F_5 ( V_31 , V_6 , V_7 , V_8 , ~ ( 1 << ( V_8 & 3 ) ) , & V_37 ) ;
switch ( V_8 & 0x03 ) {
case 0 :
* V_15 = ( unsigned char ) ( V_37 & 0x000000ff ) ;
break;
case 1 :
* V_15 = ( unsigned char ) ( ( V_37 & 0x0000ff00 ) >> 8 ) ;
break;
case 2 :
* V_15 = ( unsigned char ) ( ( V_37 & 0x00ff0000 ) >> 16 ) ;
break;
case 3 :
* V_15 = ( unsigned char ) ( ( V_37 & 0xff000000 ) >> 24 ) ;
break;
}
return V_38 ;
}
static int
F_10 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 , T_2 * V_15 )
{
unsigned int V_37 = 0 ;
int V_38 ;
if ( V_6 == NULL )
return - 1 ;
if ( V_8 & 0x01 )
return V_39 ;
V_38 = F_5 ( V_31 , V_6 , V_7 , V_8 , ~ ( 3 << ( V_8 & 3 ) ) , & V_37 ) ;
switch ( V_8 & 0x02 ) {
case 0 :
* V_15 = ( unsigned short ) ( V_37 & 0x0000ffff ) ;
break;
case 2 :
* V_15 = ( unsigned short ) ( ( V_37 & 0xffff0000 ) >> 16 ) ;
break;
}
return V_38 ;
}
static int
F_11 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 , T_3 * V_15 )
{
int V_38 ;
if ( V_6 == NULL )
return - 1 ;
if ( V_8 & 0x03 )
return V_39 ;
V_38 = F_5 ( V_31 , V_6 , V_7 , V_8 , 0 , V_15 ) ;
return V_38 ;
}
static int
F_12 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 , T_1 V_15 )
{
unsigned int V_37 = ( unsigned int ) V_15 ;
int V_38 ;
if ( V_6 == NULL )
return - 1 ;
switch ( V_8 & 0x03 ) {
case 1 :
V_37 = ( V_37 << 8 ) ;
break;
case 2 :
V_37 = ( V_37 << 16 ) ;
break;
case 3 :
V_37 = ( V_37 << 24 ) ;
break;
default:
break;
}
V_38 = F_5 ( V_21 , V_6 , V_7 , V_8 , ~ ( 1 << ( V_8 & 3 ) ) , & V_37 ) ;
return V_38 ;
}
static int
F_13 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 , T_2 V_15 )
{
unsigned int V_37 = ( unsigned int ) V_15 ;
int V_38 ;
if ( V_6 == NULL )
return - 1 ;
if ( V_8 & 0x01 )
return V_39 ;
switch ( V_8 & 0x02 ) {
case 2 :
V_37 = ( V_37 << 16 ) ;
break;
default:
break;
}
V_38 = F_5 ( V_21 , V_6 , V_7 , V_8 , ~ ( 3 << ( V_8 & 3 ) ) , & V_37 ) ;
return V_38 ;
}
static int
F_14 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 , T_3 V_15 )
{
int V_38 ;
if ( V_6 == NULL )
return - 1 ;
if ( V_8 & 0x03 )
return V_39 ;
V_38 = F_5 ( V_21 , V_6 , V_7 , V_8 , 0 , & V_15 ) ;
return V_38 ;
}
static int F_15 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 , int V_40 , T_3 * V_15 )
{
switch ( V_40 ) {
case 1 : {
T_1 V_41 ;
int V_42 = F_9 ( V_6 , V_7 , V_8 , & V_41 ) ;
* V_15 = V_41 ;
return V_42 ;
}
case 2 : {
T_2 V_41 ;
int V_42 = F_10 ( V_6 , V_7 , V_8 , & V_41 ) ;
* V_15 = V_41 ;
return V_42 ;
}
default:
return F_11 ( V_6 , V_7 , V_8 , V_15 ) ;
}
}
static int F_16 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 , int V_40 , T_3 V_15 )
{
switch ( V_40 ) {
case 1 :
return F_12 ( V_6 , V_7 , V_8 , ( T_1 ) V_15 ) ;
case 2 :
return F_13 ( V_6 , V_7 , V_8 , ( T_2 ) V_15 ) ;
default:
return F_14 ( V_6 , V_7 , V_8 , V_15 ) ;
}
}
