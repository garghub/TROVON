unsigned int F_1 ( void )
{
unsigned int V_1 = F_2 ( V_2 ) ;
return 0x1000 << ( ( V_1 & V_3 )
>> V_4 ) ;
}
unsigned int F_3 ( void )
{
unsigned int V_1 = F_2 ( V_2 ) ;
return 0x1000 << ( ( V_1 & V_5 )
>> V_6 ) ;
}
unsigned int F_4 ( void )
{
unsigned int V_7 = F_2 ( F_5 ( F_6 () ) ) ;
unsigned int V_8 = V_7 & V_9 ;
return ( F_1 () * ( ( V_8 >> V_10 ) + 1 ) ) >> 4 ;
}
unsigned int F_7 ( void )
{
unsigned int V_7 = F_2 ( F_8 ( F_6 () ) ) ;
unsigned int V_8 = V_7 & V_9 ;
return ( F_3 () * ( ( V_8 >> V_10 ) + 1 ) ) >> 4 ;
}
static unsigned int F_9 ( unsigned int V_11 , int V_12 )
{
unsigned int V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
unsigned int V_16 = 0 ;
V_15 = ( V_11 == V_17 ? F_2 ( V_18 ) & 0x1 :
F_2 ( V_19 ) & 0x1 ) ;
if ( ! V_15 )
return 0 ;
#if V_20 >= V_21
V_13 = ( V_11 == V_17 ? F_10 () :
F_7 () ) ;
V_16 = 8 ;
#else
V_13 = ( V_11 == V_17 ? F_1 () :
F_3 () ) ;
#endif
V_14 = ( V_11 == V_17 ?
( F_2 ( F_5 ( V_12 ) ) >> V_16 ) & 0xF :
( F_2 ( F_8 ( V_12 ) ) >> V_16 ) & 0xF ) ;
switch ( V_14 ) {
case 0xF :
return V_13 ;
case 0x7 :
return V_13 / 2 ;
case 0x3 :
return V_13 / 4 ;
case 0x1 :
return V_13 / 8 ;
case 0 :
return V_13 / 16 ;
}
return - 1 ;
}
void F_11 ( int V_12 )
{
unsigned int V_22 ;
unsigned int V_23 ;
for ( V_23 = V_24 ; V_23 <= V_17 ; V_23 ++ ) {
V_22 =
F_9 ( V_23 , V_12 ) ;
if ( V_22 < 0 )
F_12 ( L_1 , \
V_23 ? L_2 : L_3 ) ;
else if ( V_22 == 0 )
continue;
if ( V_22 / V_25 > V_26 ) {
F_12 ( L_4 ,
V_23 ? L_2 : L_3 , V_12 ) ;
F_13 ( L_5 ,
V_23 ? L_2 : L_6 ,
V_23 ? F_1 ()
: F_3 () ) ;
F_13 ( L_7 ,
V_23 ? L_8 : L_3 ,
V_22 ) ;
F_13 ( L_9 , V_26 ) ;
}
}
}
void F_11 ( int V_12 )
{
return;
}
