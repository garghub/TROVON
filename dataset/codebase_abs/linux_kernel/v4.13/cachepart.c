unsigned int F_1 ( void )
{
unsigned int V_1 = F_2 ( V_2 ) ;
unsigned int V_3 = 0x1000 << ( ( V_1 & V_4 )
>> V_5 ) ;
if ( V_1 & V_6 )
V_3 >>= 6 ;
return V_3 ;
}
unsigned int F_3 ( void )
{
unsigned int V_1 = F_2 ( V_2 ) ;
unsigned int V_3 = 0x1000 << ( ( V_1 & V_7 )
>> V_8 ) ;
if ( V_1 & V_9 )
V_3 >>= 6 ;
return V_3 ;
}
unsigned int F_4 ( void )
{
unsigned int V_10 = F_2 ( F_5 ( F_6 () ) ) ;
unsigned int V_11 = V_10 & V_12 ;
return ( F_1 () * ( ( V_11 >> V_13 ) + 1 ) ) >> 4 ;
}
unsigned int F_7 ( void )
{
unsigned int V_10 = F_2 ( F_8 ( F_6 () ) ) ;
unsigned int V_11 = V_10 & V_12 ;
return ( F_3 () * ( ( V_11 >> V_13 ) + 1 ) ) >> 4 ;
}
static int F_9 ( unsigned int V_14 , int V_15 )
{
unsigned int V_16 ;
unsigned int V_17 ;
unsigned int V_18 ;
unsigned int V_19 = 0 ;
V_18 = ( V_14 == V_20 ? F_2 ( V_21 ) & 0x1 :
F_2 ( V_22 ) & 0x1 ) ;
if ( ! V_18 )
return 0 ;
#if V_23 >= V_24
V_16 = ( V_14 == V_20 ? F_4 () :
F_7 () ) ;
V_19 = 8 ;
#else
V_16 = ( V_14 == V_20 ? F_1 () :
F_3 () ) ;
#endif
V_17 = ( V_14 == V_20 ?
( F_2 ( F_5 ( V_15 ) ) >> V_19 ) & 0xF :
( F_2 ( F_8 ( V_15 ) ) >> V_19 ) & 0xF ) ;
switch ( V_17 ) {
case 0xF :
return V_16 ;
case 0x7 :
return V_16 / 2 ;
case 0x3 :
return V_16 / 4 ;
case 0x1 :
return V_16 / 8 ;
case 0 :
return V_16 / 16 ;
}
return - 1 ;
}
void F_10 ( int V_15 )
{
int V_25 ;
unsigned int V_26 ;
for ( V_26 = V_27 ; V_26 <= V_20 ; V_26 ++ ) {
V_25 =
F_9 ( V_26 , V_15 ) ;
if ( V_25 < 0 )
F_11 ( L_1 ,
V_26 ? L_2 : L_3 ) ;
else if ( V_25 == 0 )
continue;
if ( V_25 / V_28 > V_29 ) {
F_11 ( L_4 ,
V_26 ? L_2 : L_3 , V_15 ) ;
F_12 ( L_5 ,
V_26 ? L_2 : L_3 ,
V_26 ? F_1 ()
: F_3 () ) ;
F_12 ( L_6 ,
V_26 ? L_7 : L_3 ,
V_25 ) ;
F_12 ( L_8 , V_29 ) ;
F_13 ( L_9 ) ;
}
}
}
void F_10 ( int V_15 )
{
return;
}
