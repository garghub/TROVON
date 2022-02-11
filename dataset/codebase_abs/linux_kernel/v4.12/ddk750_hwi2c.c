int F_1 (
unsigned char V_1
)
{
unsigned int V_2 ;
V_2 = F_2 ( V_3 ) ;
V_2 |= ( V_4 | V_5 ) ;
F_3 ( V_3 , V_2 ) ;
F_4 ( 1 ) ;
V_2 = F_2 ( V_6 ) & ~ ( V_7 | V_8 ) ;
if ( V_1 )
V_2 |= V_7 ;
V_2 |= V_8 ;
F_3 ( V_6 , V_2 ) ;
return 0 ;
}
void F_5 ( void )
{
unsigned int V_2 ;
V_2 = F_2 ( V_6 ) & ~ V_8 ;
F_3 ( V_6 , V_2 ) ;
F_4 ( 0 ) ;
V_2 = F_2 ( V_3 ) ;
V_2 &= ~ V_4 ;
V_2 &= ~ V_5 ;
F_3 ( V_3 , V_2 ) ;
}
static long F_6 ( void )
{
unsigned int V_9 ;
V_9 = V_10 ;
while ( ! ( F_2 ( V_11 ) & V_12 ) && ( V_9 != 0 ) )
V_9 -- ;
if ( V_9 == 0 )
return - 1 ;
return 0 ;
}
static unsigned int F_7 (
unsigned char V_13 ,
unsigned int V_14 ,
unsigned char * V_15
)
{
unsigned char V_16 , V_17 ;
unsigned int V_18 = 0 ;
F_3 ( V_19 , V_13 & ~ 0x01 ) ;
do {
F_3 ( V_20 , 0 ) ;
if ( V_14 < V_21 )
V_16 = V_14 - 1 ;
else
V_16 = V_21 - 1 ;
F_3 ( V_22 , V_16 ) ;
for ( V_17 = 0 ; V_17 <= V_16 ; V_17 ++ )
F_3 ( V_23 + V_17 , * V_15 ++ ) ;
F_3 ( V_6 , F_2 ( V_6 ) | V_24 ) ;
if ( F_6 () != 0 )
break;
V_14 -= ( V_16 + 1 ) ;
V_18 += ( V_16 + 1 ) ;
} while ( V_14 > 0 );
return V_18 ;
}
static unsigned int F_8 (
unsigned char V_13 ,
unsigned int V_14 ,
unsigned char * V_15
)
{
unsigned char V_16 , V_17 ;
unsigned int V_18 = 0 ;
F_3 ( V_19 , V_13 | 0x01 ) ;
do {
F_3 ( V_20 , 0 ) ;
if ( V_14 <= V_21 )
V_16 = V_14 - 1 ;
else
V_16 = V_21 - 1 ;
F_3 ( V_22 , V_16 ) ;
F_3 ( V_6 , F_2 ( V_6 ) | V_24 ) ;
if ( F_6 () != 0 )
break;
for ( V_17 = 0 ; V_17 <= V_16 ; V_17 ++ )
* V_15 ++ = F_2 ( V_23 + V_17 ) ;
V_14 -= ( V_16 + 1 ) ;
V_18 += ( V_16 + 1 ) ;
} while ( V_14 > 0 );
return V_18 ;
}
unsigned char F_9 (
unsigned char V_13 ,
unsigned char V_25
)
{
unsigned char V_2 = 0xFF ;
if ( F_7 ( V_13 , 1 , & V_25 ) == 1 )
F_8 ( V_13 , 1 , & V_2 ) ;
return V_2 ;
}
int F_10 (
unsigned char V_13 ,
unsigned char V_25 ,
unsigned char V_26
)
{
unsigned char V_2 [ 2 ] ;
V_2 [ 0 ] = V_25 ;
V_2 [ 1 ] = V_26 ;
if ( F_7 ( V_13 , 2 , V_2 ) == 2 )
return 0 ;
return - 1 ;
}
