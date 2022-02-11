int F_1 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{
return F_2 ( V_1 , V_2 , V_3 ) ;
}
int F_3 ( T_1 * V_4 , unsigned char * * V_5 )
{
int V_6 , V_7 , V_8 , V_3 ;
unsigned char * V_9 , * V_2 ;
if ( V_4 == NULL )
return ( 0 ) ;
V_3 = V_4 -> V_10 ;
if ( V_3 > 0 ) {
if ( V_4 -> V_11 & V_12 ) {
V_8 = ( int ) V_4 -> V_11 & 0x07 ;
} else {
for (; V_3 > 0 ; V_3 -- ) {
if ( V_4 -> V_13 [ V_3 - 1 ] )
break;
}
V_7 = V_4 -> V_13 [ V_3 - 1 ] ;
if ( V_7 & 0x01 )
V_8 = 0 ;
else if ( V_7 & 0x02 )
V_8 = 1 ;
else if ( V_7 & 0x04 )
V_8 = 2 ;
else if ( V_7 & 0x08 )
V_8 = 3 ;
else if ( V_7 & 0x10 )
V_8 = 4 ;
else if ( V_7 & 0x20 )
V_8 = 5 ;
else if ( V_7 & 0x40 )
V_8 = 6 ;
else if ( V_7 & 0x80 )
V_8 = 7 ;
else
V_8 = 0 ;
}
} else
V_8 = 0 ;
V_6 = 1 + V_3 ;
if ( V_5 == NULL )
return ( V_6 ) ;
V_9 = * V_5 ;
* ( V_9 ++ ) = ( unsigned char ) V_8 ;
V_2 = V_4 -> V_13 ;
memcpy ( V_9 , V_2 , V_3 ) ;
V_9 += V_3 ;
if ( V_3 > 0 )
V_9 [ - 1 ] &= ( 0xff << V_8 ) ;
* V_5 = V_9 ;
return ( V_6 ) ;
}
T_1 * F_4 ( T_1 * * V_4 ,
const unsigned char * * V_5 , long V_3 )
{
T_1 * V_6 = NULL ;
const unsigned char * V_9 ;
unsigned char * V_14 ;
int V_15 ;
if ( V_3 < 1 ) {
V_15 = V_16 ;
goto V_17;
}
if ( ( V_4 == NULL ) || ( ( * V_4 ) == NULL ) ) {
if ( ( V_6 = F_5 () ) == NULL )
return ( NULL ) ;
} else
V_6 = ( * V_4 ) ;
V_9 = * V_5 ;
V_15 = * ( V_9 ++ ) ;
if ( V_15 > 7 ) {
V_15 = V_18 ;
goto V_17;
}
V_6 -> V_11 &= ~ ( V_12 | 0x07 ) ;
V_6 -> V_11 |= ( V_12 | V_15 ) ;
if ( V_3 -- > 1 ) {
V_14 = ( unsigned char * ) F_6 ( ( int ) V_3 ) ;
if ( V_14 == NULL ) {
V_15 = V_19 ;
goto V_17;
}
memcpy ( V_14 , V_9 , ( int ) V_3 ) ;
V_14 [ V_3 - 1 ] &= ( 0xff << V_15 ) ;
V_9 += V_3 ;
} else
V_14 = NULL ;
V_6 -> V_10 = ( int ) V_3 ;
if ( V_6 -> V_13 != NULL )
F_7 ( V_6 -> V_13 ) ;
V_6 -> V_13 = V_14 ;
V_6 -> type = V_20 ;
if ( V_4 != NULL )
( * V_4 ) = V_6 ;
* V_5 = V_9 ;
return ( V_6 ) ;
V_17:
F_8 ( V_21 , V_15 ) ;
if ( ( V_6 != NULL ) && ( ( V_4 == NULL ) || ( * V_4 != V_6 ) ) )
F_9 ( V_6 ) ;
return ( NULL ) ;
}
int F_10 ( T_1 * V_4 , int V_22 , int V_23 )
{
int V_24 , V_25 , V_26 ;
unsigned char * V_27 ;
V_24 = V_22 / 8 ;
V_25 = 1 << ( 7 - ( V_22 & 0x07 ) ) ;
V_26 = ~ V_25 ;
if ( ! V_23 )
V_25 = 0 ;
if ( V_4 == NULL )
return 0 ;
V_4 -> V_11 &= ~ ( V_12 | 0x07 ) ;
if ( ( V_4 -> V_10 < ( V_24 + 1 ) ) || ( V_4 -> V_13 == NULL ) ) {
if ( ! V_23 )
return ( 1 ) ;
if ( V_4 -> V_13 == NULL )
V_27 = ( unsigned char * ) F_6 ( V_24 + 1 ) ;
else
V_27 = ( unsigned char * ) F_11 ( V_4 -> V_13 ,
V_4 -> V_10 , V_24 + 1 ) ;
if ( V_27 == NULL ) {
F_8 ( V_28 , V_19 ) ;
return 0 ;
}
if ( V_24 + 1 - V_4 -> V_10 > 0 )
memset ( V_27 + V_4 -> V_10 , 0 , V_24 + 1 - V_4 -> V_10 ) ;
V_4 -> V_13 = V_27 ;
V_4 -> V_10 = V_24 + 1 ;
}
V_4 -> V_13 [ V_24 ] = ( ( V_4 -> V_13 [ V_24 ] ) & V_26 ) | V_25 ;
while ( ( V_4 -> V_10 > 0 ) && ( V_4 -> V_13 [ V_4 -> V_10 - 1 ] == 0 ) )
V_4 -> V_10 -- ;
return ( 1 ) ;
}
int F_12 ( T_1 * V_4 , int V_22 )
{
int V_24 , V_25 ;
V_24 = V_22 / 8 ;
V_25 = 1 << ( 7 - ( V_22 & 0x07 ) ) ;
if ( ( V_4 == NULL ) || ( V_4 -> V_10 < ( V_24 + 1 ) ) || ( V_4 -> V_13 == NULL ) )
return ( 0 ) ;
return ( ( V_4 -> V_13 [ V_24 ] & V_25 ) != 0 ) ;
}
int F_13 ( T_1 * V_4 ,
unsigned char * V_11 , int V_29 )
{
int V_15 , V_30 ;
if ( ! V_4 || ! V_4 -> V_13 )
return 1 ;
V_30 = 1 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_10 && V_30 ; ++ V_15 ) {
unsigned char V_31 = V_15 < V_29 ? ~ V_11 [ V_15 ] : 0xff ;
V_30 = ( V_4 -> V_13 [ V_15 ] & V_31 ) == 0 ;
}
return V_30 ;
}
