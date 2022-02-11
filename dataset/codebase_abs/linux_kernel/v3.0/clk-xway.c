static inline unsigned int F_1 ( int V_1 )
{
switch ( V_1 ) {
case 0 :
if ( F_2 ( V_2 ) & V_3 )
return V_4 ;
else if ( V_5 )
return V_6 ;
else
return V_7 ;
case 1 :
if ( V_8 )
return V_4 ;
else if ( V_5 )
return V_6 ;
else
return V_7 ;
case 2 :
switch ( V_9 ) {
case 0 :
return F_3 () ;
case 1 :
return V_10 ?
V_6 :
V_7 ;
case 2 :
return V_4 ;
}
default:
return 0 ;
}
}
static inline unsigned int F_4 ( int V_1 , unsigned int V_11 , unsigned int V_12 )
{
T_1 V_13 , clock = F_1 ( V_1 ) ;
V_13 = V_11 * clock ;
F_5 ( V_13 , V_12 ) ;
return V_13 ;
}
static inline unsigned int F_6 ( int V_1 , unsigned int V_14 , unsigned int V_15 ,
unsigned int V_16 )
{
unsigned int V_11 = ( ( V_15 + 1 ) << 10 ) + V_16 ;
unsigned int V_12 = ( V_14 + 1 ) << 10 ;
return F_4 ( V_1 , V_11 , V_12 ) ;
}
static inline unsigned int F_7 ( int V_1 , unsigned int V_14 , unsigned int V_15 ,
unsigned int V_16 )
{
unsigned int V_11 = ( ( V_15 + 1 ) << 11 ) + V_16 + 512 ;
unsigned int V_12 = ( V_14 + 1 ) << 11 ;
return F_4 ( V_1 , V_11 , V_12 ) ;
}
static inline unsigned int F_8 ( int V_1 , unsigned int V_14 , unsigned int V_15 ,
unsigned int V_16 )
{
unsigned int V_11 = V_16 >= 512 ?
( ( V_15 + 1 ) << 12 ) + V_16 - 512 : ( ( V_15 + 1 ) << 12 ) + V_16 + 3584 ;
unsigned int V_12 = ( V_14 + 1 ) << 12 ;
return F_4 ( V_1 , V_11 , V_12 ) ;
}
static inline unsigned int F_9 ( int V_1 , unsigned int V_14 , unsigned int V_15 ,
unsigned int V_16 , unsigned int V_17 , unsigned int V_18 )
{
if ( ! V_17 )
return F_6 ( V_1 , V_14 , V_15 , V_16 ) ;
else if ( ! V_18 )
return F_6 ( V_1 , V_14 , V_15 , V_16 ) ;
else
return F_8 ( V_1 , V_14 , V_15 , V_16 ) ;
}
static inline unsigned int F_10 ( void )
{
if ( V_19 )
return F_1 ( 0 ) ;
else
return ! V_20
? F_9 ( 0 , V_21 , V_22 , 0 ,
V_23 ,
V_5 )
: F_9 ( 0 , V_21 , V_22 ,
V_24 , V_23 ,
V_5 ) ;
}
static unsigned int F_3 ( void )
{
unsigned int div = V_25 + 1 ;
return ( F_10 () + ( div >> 1 ) ) / div ;
}
unsigned int F_11 ( void )
{
unsigned int V_26 = F_10 () ;
switch ( F_2 ( V_27 ) & V_28 ) {
default:
case 0 :
return ( V_26 + 1 ) / 2 ;
case 1 :
return ( V_26 * 2 + 2 ) / 5 ;
case 2 :
return ( V_26 + 1 ) / 3 ;
case 3 :
return ( V_26 + 2 ) / 4 ;
}
}
unsigned int F_12 ( int V_29 )
{
unsigned int V_26 = F_11 () ;
if ( ( V_29 == 2 ) && ( F_2 ( V_30 ) & V_31 ) )
V_26 >>= 1 ;
return V_26 ;
}
unsigned int F_13 ( void )
{
switch ( F_2 ( V_30 ) & 0xc ) {
case 0 :
return V_32 ;
case 4 :
return V_33 ;
case 8 :
return V_33 << 1 ;
default:
return V_33 >> 1 ;
}
}
unsigned int F_14 ( void )
{
unsigned int V_34 = V_33 ;
if ( F_2 ( V_30 ) & 0x40 )
return V_34 >> 1 ;
return V_34 ;
}
