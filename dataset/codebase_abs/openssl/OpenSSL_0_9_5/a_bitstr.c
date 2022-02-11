T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{ return F_6 ( V_1 , V_2 , V_3 ) ; }
int F_7 ( T_1 * V_4 , unsigned char * * V_5 )
{
int V_6 , V_7 , V_8 , V_9 , V_3 ;
unsigned char * V_10 , * V_2 ;
if ( V_4 == NULL ) return ( 0 ) ;
V_3 = V_4 -> V_11 ;
if ( V_3 > 0 )
{
if ( V_4 -> V_12 & V_13 )
{
V_9 = ( int ) V_4 -> V_12 & 0x07 ;
}
else
{
for ( ; V_3 > 0 ; V_3 -- )
{
if ( V_4 -> V_14 [ V_3 - 1 ] ) break;
}
V_7 = V_4 -> V_14 [ V_3 - 1 ] ;
if ( V_7 & 0x01 ) V_9 = 0 ;
else if ( V_7 & 0x02 ) V_9 = 1 ;
else if ( V_7 & 0x04 ) V_9 = 2 ;
else if ( V_7 & 0x08 ) V_9 = 3 ;
else if ( V_7 & 0x10 ) V_9 = 4 ;
else if ( V_7 & 0x20 ) V_9 = 5 ;
else if ( V_7 & 0x40 ) V_9 = 6 ;
else if ( V_7 & 0x80 ) V_9 = 7 ;
else V_9 = 0 ;
}
}
else
V_9 = 0 ;
V_6 = 1 + V_3 ;
V_8 = F_8 ( 0 , V_6 , V_15 ) ;
if ( V_5 == NULL ) return ( V_8 ) ;
V_10 = * V_5 ;
F_9 ( & V_10 , 0 , V_6 , V_15 , V_16 ) ;
* ( V_10 ++ ) = ( unsigned char ) V_9 ;
V_2 = V_4 -> V_14 ;
memcpy ( V_10 , V_2 , V_3 ) ;
V_10 += V_3 ;
if ( V_3 > 0 ) V_10 [ - 1 ] &= ( 0xff << V_9 ) ;
* V_5 = V_10 ;
return ( V_8 ) ;
}
T_1 * F_10 ( T_1 * * V_4 , unsigned char * * V_5 ,
long V_11 )
{
T_1 * V_6 = NULL ;
unsigned char * V_10 , * V_17 ;
long V_3 ;
int V_18 , V_19 , V_20 ;
int V_21 ;
if ( ( V_4 == NULL ) || ( ( * V_4 ) == NULL ) )
{
if ( ( V_6 = F_2 () ) == NULL ) return ( NULL ) ;
}
else
V_6 = ( * V_4 ) ;
V_10 = * V_5 ;
V_18 = F_11 ( & V_10 , & V_3 , & V_19 , & V_20 , V_11 ) ;
if ( V_18 & 0x80 )
{
V_21 = V_22 ;
goto V_23;
}
if ( V_19 != V_15 )
{
V_21 = V_24 ;
goto V_23;
}
if ( V_3 < 1 ) { V_21 = V_25 ; goto V_23; }
V_21 = * ( V_10 ++ ) ;
V_6 -> V_12 &= ~ ( V_13 | 0x07 ) ;
V_6 -> V_12 |= ( V_13 | ( V_21 & 0x07 ) ) ;
if ( V_3 -- > 1 )
{
V_17 = ( unsigned char * ) Malloc ( ( int ) V_3 ) ;
if ( V_17 == NULL )
{
V_21 = V_26 ;
goto V_23;
}
memcpy ( V_17 , V_10 , ( int ) V_3 ) ;
V_17 [ V_3 - 1 ] &= ( 0xff << V_21 ) ;
V_10 += V_3 ;
}
else
V_17 = NULL ;
V_6 -> V_11 = ( int ) V_3 ;
if ( V_6 -> V_14 != NULL ) Free ( V_6 -> V_14 ) ;
V_6 -> V_14 = V_17 ;
V_6 -> type = V_15 ;
if ( V_4 != NULL ) ( * V_4 ) = V_6 ;
* V_5 = V_10 ;
return ( V_6 ) ;
V_23:
F_12 ( V_27 , V_21 ) ;
if ( ( V_6 != NULL ) && ( ( V_4 == NULL ) || ( * V_4 != V_6 ) ) )
F_4 ( V_6 ) ;
return ( NULL ) ;
}
int F_13 ( T_1 * V_4 , int V_28 , int V_29 )
{
int V_30 , V_31 , V_32 ;
unsigned char * V_33 ;
V_30 = V_28 / 8 ;
V_31 = 1 << ( 7 - ( V_28 & 0x07 ) ) ;
V_32 = ~ V_31 ;
V_4 -> V_12 &= ~ ( V_13 | 0x07 ) ;
if ( V_4 == NULL ) return ( 0 ) ;
if ( ( V_4 -> V_11 < ( V_30 + 1 ) ) || ( V_4 -> V_14 == NULL ) )
{
if ( ! V_29 ) return ( 1 ) ;
if ( V_4 -> V_14 == NULL )
V_33 = ( unsigned char * ) Malloc ( V_30 + 1 ) ;
else
V_33 = ( unsigned char * ) Realloc ( V_4 -> V_14 , V_30 + 1 ) ;
if ( V_33 == NULL ) return ( 0 ) ;
V_4 -> V_14 = V_33 ;
V_4 -> V_11 = V_30 + 1 ;
V_33 [ V_30 ] = 0 ;
}
V_4 -> V_14 [ V_30 ] = ( ( V_4 -> V_14 [ V_30 ] ) & V_32 ) | V_31 ;
while ( ( V_4 -> V_11 > 0 ) && ( V_4 -> V_14 [ V_4 -> V_11 - 1 ] == 0 ) )
V_4 -> V_11 -- ;
return ( 1 ) ;
}
int F_14 ( T_1 * V_4 , int V_28 )
{
int V_30 , V_31 ;
V_30 = V_28 / 8 ;
V_31 = 1 << ( 7 - ( V_28 & 0x07 ) ) ;
if ( ( V_4 == NULL ) || ( V_4 -> V_11 < ( V_30 + 1 ) ) || ( V_4 -> V_14 == NULL ) )
return ( 0 ) ;
return ( ( V_4 -> V_14 [ V_30 ] & V_31 ) != 0 ) ;
}
