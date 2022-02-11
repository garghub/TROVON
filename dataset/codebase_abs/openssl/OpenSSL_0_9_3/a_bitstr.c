int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
int V_3 , V_4 , V_5 , V_6 , V_7 ;
unsigned char * V_8 , * V_9 ;
if ( V_1 == NULL ) return ( 0 ) ;
V_7 = V_1 -> V_10 ;
if ( V_7 > 0 )
{
if ( V_1 -> V_11 & V_12 )
{
V_6 = ( int ) V_1 -> V_11 & 0x07 ;
}
else
{
for ( ; V_7 > 0 ; V_7 -- )
{
if ( V_1 -> V_13 [ V_7 - 1 ] ) break;
}
V_4 = V_1 -> V_13 [ V_7 - 1 ] ;
if ( V_4 & 0x01 ) V_6 = 0 ;
else if ( V_4 & 0x02 ) V_6 = 1 ;
else if ( V_4 & 0x04 ) V_6 = 2 ;
else if ( V_4 & 0x08 ) V_6 = 3 ;
else if ( V_4 & 0x10 ) V_6 = 4 ;
else if ( V_4 & 0x20 ) V_6 = 5 ;
else if ( V_4 & 0x40 ) V_6 = 6 ;
else if ( V_4 & 0x80 ) V_6 = 7 ;
else V_6 = 0 ;
}
}
else
V_6 = 0 ;
V_3 = 1 + V_7 ;
V_5 = F_2 ( 0 , V_3 , V_14 ) ;
if ( V_2 == NULL ) return ( V_5 ) ;
V_8 = * V_2 ;
F_3 ( & V_8 , 0 , V_3 , V_14 , V_15 ) ;
* ( V_8 ++ ) = ( unsigned char ) V_6 ;
V_9 = V_1 -> V_13 ;
memcpy ( V_8 , V_9 , V_7 ) ;
V_8 += V_7 ;
if ( V_7 > 0 ) V_8 [ - 1 ] &= ( 0xff << V_6 ) ;
* V_2 = V_8 ;
return ( V_5 ) ;
}
T_1 * F_4 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_10 )
{
T_1 * V_3 = NULL ;
unsigned char * V_8 , * V_16 ;
long V_7 ;
int V_17 , V_18 , V_19 ;
int V_20 ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) )
{
if ( ( V_3 = F_5 () ) == NULL ) return ( NULL ) ;
}
else
V_3 = ( * V_1 ) ;
V_8 = * V_2 ;
V_17 = F_6 ( & V_8 , & V_7 , & V_18 , & V_19 , V_10 ) ;
if ( V_17 & 0x80 )
{
V_20 = V_21 ;
goto V_22;
}
if ( V_18 != V_14 )
{
V_20 = V_23 ;
goto V_22;
}
if ( V_7 < 1 ) { V_20 = V_24 ; goto V_22; }
V_20 = * ( V_8 ++ ) ;
V_3 -> V_11 &= ~ ( V_12 | 0x07 ) ;
V_3 -> V_11 |= ( V_12 | ( V_20 & 0x07 ) ) ;
if ( V_7 -- > 1 )
{
V_16 = ( unsigned char * ) Malloc ( ( int ) V_7 ) ;
if ( V_16 == NULL )
{
V_20 = V_25 ;
goto V_22;
}
memcpy ( V_16 , V_8 , ( int ) V_7 ) ;
V_16 [ V_7 - 1 ] &= ( 0xff << V_20 ) ;
V_8 += V_7 ;
}
else
V_16 = NULL ;
V_3 -> V_10 = ( int ) V_7 ;
if ( V_3 -> V_13 != NULL ) Free ( ( char * ) V_3 -> V_13 ) ;
V_3 -> V_13 = V_16 ;
V_3 -> type = V_14 ;
if ( V_1 != NULL ) ( * V_1 ) = V_3 ;
* V_2 = V_8 ;
return ( V_3 ) ;
V_22:
F_7 ( V_26 , V_20 ) ;
if ( ( V_3 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_3 ) ) )
F_8 ( V_3 ) ;
return ( NULL ) ;
}
int F_9 ( T_1 * V_1 , int V_27 , int V_28 )
{
int V_29 , V_30 , V_31 ;
unsigned char * V_32 ;
V_29 = V_27 / 8 ;
V_30 = 1 << ( 7 - ( V_27 & 0x07 ) ) ;
V_31 = ~ V_30 ;
V_1 -> V_11 &= ~ ( V_12 | 0x07 ) ;
if ( V_1 == NULL ) return ( 0 ) ;
if ( ( V_1 -> V_10 < ( V_29 + 1 ) ) || ( V_1 -> V_13 == NULL ) )
{
if ( ! V_28 ) return ( 1 ) ;
if ( V_1 -> V_13 == NULL )
V_32 = ( unsigned char * ) Malloc ( V_29 + 1 ) ;
else
V_32 = ( unsigned char * ) Realloc ( V_1 -> V_13 , V_29 + 1 ) ;
if ( V_32 == NULL ) return ( 0 ) ;
V_1 -> V_13 = V_32 ;
V_1 -> V_10 = V_29 + 1 ;
V_32 [ V_29 ] = 0 ;
}
V_1 -> V_13 [ V_29 ] = ( ( V_1 -> V_13 [ V_29 ] ) & V_31 ) | V_30 ;
while ( ( V_1 -> V_10 > 0 ) && ( V_1 -> V_13 [ V_1 -> V_10 - 1 ] == 0 ) )
V_1 -> V_10 -- ;
return ( 1 ) ;
}
int F_10 ( T_1 * V_1 , int V_27 )
{
int V_29 , V_30 ;
V_29 = V_27 / 8 ;
V_30 = 1 << ( 7 - ( V_27 & 0x07 ) ) ;
if ( ( V_1 == NULL ) || ( V_1 -> V_10 < ( V_29 + 1 ) ) || ( V_1 -> V_13 == NULL ) )
return ( 0 ) ;
return ( ( V_1 -> V_13 [ V_29 ] & V_30 ) != 0 ) ;
}
