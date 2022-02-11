unsigned long F_1 ( void )
{
unsigned long V_1 = V_2 ;
if ( F_2 ( V_3 ) & 0x40 )
return V_1 >> 1 ;
return V_1 ;
}
unsigned long F_3 ( void )
{
switch ( F_2 ( V_3 ) & 0xc ) {
case 0 :
return V_4 ;
case 4 :
return V_2 ;
case 8 :
return V_2 << 1 ;
default:
return V_2 >> 1 ;
}
}
unsigned long F_4 ( void )
{
unsigned int V_5 = ( F_2 ( V_3 ) >> 7 ) & 3 ;
unsigned long V_6 ;
switch ( V_5 ) {
case 1 :
V_6 = V_7 ;
break;
case 2 :
V_6 = V_8 ;
break;
case 3 :
V_6 = V_9 ;
break;
default:
V_6 = V_10 ;
break;
}
return V_6 ;
}
unsigned long F_5 ( void )
{
if ( ( ( F_2 ( V_3 ) >> 3 ) & 0x3 ) == 0x2 )
return V_11 ;
return V_4 ;
}
unsigned long F_6 ( void )
{
unsigned long V_12 = F_5 () ;
if ( F_2 ( V_3 ) & F_7 ( 0 ) )
return V_12 / 3 ;
else
return V_12 / 2 ;
}
unsigned long F_8 ( void )
{
if ( F_2 ( V_3 ) & F_7 ( 2 ) )
return F_6 () ;
else
return F_5 () ;
}
unsigned long F_9 ( void )
{
unsigned int V_13 ;
unsigned long V_6 ;
V_13 = ( F_2 ( V_14 ) >> 4 ) & 0xf ;
switch ( V_13 ) {
case 0 :
V_6 = V_15 ;
break;
case 1 :
V_6 = V_16 ;
break;
case 2 :
V_6 = V_11 ;
break;
case 3 :
V_6 = V_4 ;
break;
case 5 :
case 6 :
V_6 = V_17 ;
break;
case 7 :
V_6 = V_18 ;
break;
case 4 :
case 8 :
case 9 :
V_6 = V_19 ;
break;
default:
V_6 = 0 ;
break;
}
return V_6 ;
}
unsigned long F_10 ( void )
{
unsigned int V_20 , V_21 ;
unsigned long V_6 ;
V_21 = F_9 () ;
V_20 = F_2 ( V_14 ) & 0x3 ;
switch ( V_20 ) {
case 0 :
V_6 = V_21 ;
break;
case 2 :
V_6 = V_21 / 2 ;
break;
case 3 :
V_6 = ( V_21 * 2 ) / 5 ;
break;
case 4 :
V_6 = V_21 / 3 ;
break;
default:
V_6 = 0 ;
break;
}
return V_6 ;
}
unsigned long F_11 ( void )
{
unsigned int V_5 = ( F_2 ( V_3 ) >> 16 ) & 0x7 ;
unsigned long V_6 ;
switch ( V_5 ) {
case 0 :
V_6 = V_16 ;
break;
case 1 :
V_6 = V_22 ;
break;
case 2 :
V_6 = V_23 ;
break;
default:
V_6 = V_16 ;
break;
}
return V_6 ;
}
unsigned long F_12 ( void )
{
unsigned int V_5 ;
int V_24 = ( F_2 ( V_14 ) >> 8 ) & 0x1 ;
int V_25 = ( F_2 ( V_14 ) >> 4 ) & 0x7 ;
switch ( V_24 ) {
case 0 :
V_5 = V_16 ;
break;
case 1 :
V_5 = V_15 ;
break;
default:
V_5 = V_16 ;
break;
}
switch ( V_25 ) {
case 0 :
return V_5 ;
case 1 :
return V_5 >> 1 ;
case 2 :
return V_5 >> 2 ;
default:
return V_5 ;
}
}
unsigned long F_13 ( void )
{
int V_26 = ( F_2 ( V_27 ) >> 25 ) & 0xf ;
switch ( V_26 ) {
case 1 :
return V_28 ;
case 5 :
return V_29 ;
case 2 :
return V_30 ;
case 6 :
return V_19 ;
default:
return V_19 ;
}
}
unsigned long F_14 ( void )
{
unsigned int V_5 = ( F_2 ( V_3 ) >> 16 ) & 0x7 ;
unsigned long V_6 ;
switch ( V_5 ) {
case 1 :
V_6 = V_29 ;
break;
case 4 :
V_6 = V_31 ;
break;
default:
V_6 = V_29 ;
break;
}
return V_6 ;
}
unsigned long F_15 ( void )
{
unsigned int V_5 ;
int V_24 = ( ( F_2 ( V_14 ) >> 9 ) & 0x3 ) ;
int V_25 = ( ( F_2 ( V_14 ) >> 4 ) & 0x7 ) ;
switch ( V_24 ) {
case 0 :
V_5 = V_15 ;
break;
case 1 :
V_5 = V_32 ;
break;
case 2 :
V_5 = V_33 ;
break;
default:
V_5 = V_15 ;
break;
}
switch ( V_25 ) {
case 0 :
return V_5 ;
case 1 :
return V_5 >> 1 ;
case 2 :
return V_5 >> 2 ;
default:
return V_5 ;
}
}
unsigned long F_16 ( void )
{
unsigned int V_5 ;
int V_24 = ( ( F_2 ( V_14 ) >> 9 ) & 0x3 ) ;
int V_25 = ( ( F_2 ( V_14 ) ) & 0x7 ) ;
switch ( V_24 ) {
case 0 :
V_5 = V_15 ;
break;
case 1 :
V_5 = V_32 ;
break;
case 2 :
V_5 = V_33 ;
break;
default:
V_5 = V_15 ;
break;
}
switch ( V_25 ) {
case 1 :
return V_5 >> 1 ;
case 2 :
return V_5 >> 2 ;
default:
return V_5 >> 1 ;
}
}
unsigned long F_17 ( void )
{
unsigned int V_5 = ( F_2 ( V_3 ) >> 16 ) & 0x7 ;
unsigned long V_6 ;
switch ( V_5 ) {
case 1 :
V_6 = V_29 ;
break;
case 2 :
V_6 = V_22 ;
break;
case 4 :
V_6 = V_31 ;
break;
default:
V_6 = V_29 ;
break;
}
return V_6 ;
}
