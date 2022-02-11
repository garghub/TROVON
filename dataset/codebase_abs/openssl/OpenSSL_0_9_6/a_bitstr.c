T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{ return F_6 ( V_1 , V_2 , V_3 ) ; }
int F_7 ( T_1 * V_4 , unsigned char * * V_5 )
{
int V_3 , V_6 ;
V_3 = F_8 ( V_4 , NULL ) ;
V_6 = F_9 ( 0 , V_3 , V_7 ) ;
if( V_5 ) {
F_10 ( V_5 , 0 , V_3 , V_7 , V_8 ) ;
F_8 ( V_4 , V_5 ) ;
}
return V_6 ;
}
int F_8 ( T_1 * V_4 , unsigned char * * V_5 )
{
int V_6 , V_9 , V_10 , V_3 ;
unsigned char * V_11 , * V_2 ;
if ( V_4 == NULL ) return ( 0 ) ;
V_3 = V_4 -> V_12 ;
V_6 = 1 + V_3 ;
if ( V_5 == NULL ) return ( V_6 ) ;
if ( V_3 > 0 )
{
if ( V_4 -> V_13 & V_14 )
{
V_10 = ( int ) V_4 -> V_13 & 0x07 ;
}
else
{
for ( ; V_3 > 0 ; V_3 -- )
{
if ( V_4 -> V_15 [ V_3 - 1 ] ) break;
}
V_9 = V_4 -> V_15 [ V_3 - 1 ] ;
if ( V_9 & 0x01 ) V_10 = 0 ;
else if ( V_9 & 0x02 ) V_10 = 1 ;
else if ( V_9 & 0x04 ) V_10 = 2 ;
else if ( V_9 & 0x08 ) V_10 = 3 ;
else if ( V_9 & 0x10 ) V_10 = 4 ;
else if ( V_9 & 0x20 ) V_10 = 5 ;
else if ( V_9 & 0x40 ) V_10 = 6 ;
else if ( V_9 & 0x80 ) V_10 = 7 ;
else V_10 = 0 ;
}
}
else
V_10 = 0 ;
V_11 = * V_5 ;
* ( V_11 ++ ) = ( unsigned char ) V_10 ;
V_2 = V_4 -> V_15 ;
memcpy ( V_11 , V_2 , V_3 ) ;
V_11 += V_3 ;
if ( V_3 > 0 ) V_11 [ - 1 ] &= ( 0xff << V_10 ) ;
* V_5 = V_11 ;
return ( V_6 ) ;
}
T_1 * F_11 ( T_1 * * V_4 , unsigned char * * V_5 ,
long V_12 )
{
unsigned char * V_11 ;
long V_3 ;
int V_16 ;
int V_17 , V_18 , V_19 ;
T_1 * V_6 ;
V_11 = * V_5 ;
V_17 = F_12 ( & V_11 , & V_3 , & V_18 , & V_19 , V_12 ) ;
if ( V_17 & 0x80 )
{
V_16 = V_20 ;
goto V_21;
}
if ( V_18 != V_7 )
{
V_16 = V_22 ;
goto V_21;
}
if ( V_3 < 1 ) { V_16 = V_23 ; goto V_21; }
V_6 = F_13 ( V_4 , & V_11 , V_3 ) ;
if( V_6 ) * V_5 = V_11 ;
return V_6 ;
V_21:
F_14 ( V_24 , V_16 ) ;
return ( NULL ) ;
}
T_1 * F_13 ( T_1 * * V_4 , unsigned char * * V_5 ,
long V_3 )
{
T_1 * V_6 = NULL ;
unsigned char * V_11 , * V_25 ;
int V_16 ;
if ( ( V_4 == NULL ) || ( ( * V_4 ) == NULL ) )
{
if ( ( V_6 = F_2 () ) == NULL ) return ( NULL ) ;
}
else
V_6 = ( * V_4 ) ;
V_11 = * V_5 ;
V_16 = * ( V_11 ++ ) ;
V_6 -> V_13 &= ~ ( V_14 | 0x07 ) ;
V_6 -> V_13 |= ( V_14 | ( V_16 & 0x07 ) ) ;
if ( V_3 -- > 1 )
{
V_25 = ( unsigned char * ) F_15 ( ( int ) V_3 ) ;
if ( V_25 == NULL )
{
V_16 = V_26 ;
goto V_21;
}
memcpy ( V_25 , V_11 , ( int ) V_3 ) ;
V_25 [ V_3 - 1 ] &= ( 0xff << V_16 ) ;
V_11 += V_3 ;
}
else
V_25 = NULL ;
V_6 -> V_12 = ( int ) V_3 ;
if ( V_6 -> V_15 != NULL ) F_16 ( V_6 -> V_15 ) ;
V_6 -> V_15 = V_25 ;
V_6 -> type = V_7 ;
if ( V_4 != NULL ) ( * V_4 ) = V_6 ;
* V_5 = V_11 ;
return ( V_6 ) ;
V_21:
F_14 ( V_24 , V_16 ) ;
if ( ( V_6 != NULL ) && ( ( V_4 == NULL ) || ( * V_4 != V_6 ) ) )
F_4 ( V_6 ) ;
return ( NULL ) ;
}
int F_17 ( T_1 * V_4 , int V_27 , int V_28 )
{
int V_29 , V_30 , V_31 ;
unsigned char * V_32 ;
V_29 = V_27 / 8 ;
V_30 = 1 << ( 7 - ( V_27 & 0x07 ) ) ;
V_31 = ~ V_30 ;
V_4 -> V_13 &= ~ ( V_14 | 0x07 ) ;
if ( V_4 == NULL ) return ( 0 ) ;
if ( ( V_4 -> V_12 < ( V_29 + 1 ) ) || ( V_4 -> V_15 == NULL ) )
{
if ( ! V_28 ) return ( 1 ) ;
if ( V_4 -> V_15 == NULL )
V_32 = ( unsigned char * ) F_15 ( V_29 + 1 ) ;
else
V_32 = ( unsigned char * ) F_18 ( V_4 -> V_15 , V_29 + 1 ) ;
if ( V_32 == NULL ) return ( 0 ) ;
if ( V_29 + 1 - V_4 -> V_12 > 0 ) memset ( V_32 + V_4 -> V_12 , 0 , V_29 + 1 - V_4 -> V_12 ) ;
V_4 -> V_15 = V_32 ;
V_4 -> V_12 = V_29 + 1 ;
}
V_4 -> V_15 [ V_29 ] = ( ( V_4 -> V_15 [ V_29 ] ) & V_31 ) | V_30 ;
while ( ( V_4 -> V_12 > 0 ) && ( V_4 -> V_15 [ V_4 -> V_12 - 1 ] == 0 ) )
V_4 -> V_12 -- ;
return ( 1 ) ;
}
int F_19 ( T_1 * V_4 , int V_27 )
{
int V_29 , V_30 ;
V_29 = V_27 / 8 ;
V_30 = 1 << ( 7 - ( V_27 & 0x07 ) ) ;
if ( ( V_4 == NULL ) || ( V_4 -> V_12 < ( V_29 + 1 ) ) || ( V_4 -> V_15 == NULL ) )
return ( 0 ) ;
return ( ( V_4 -> V_15 [ V_29 ] & V_30 ) != 0 ) ;
}
