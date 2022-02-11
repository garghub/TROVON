void F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = 48 ;
V_1 -> V_3 = 0 ;
V_1 -> V_4 = 0 ;
}
void F_2 ( T_1 * V_1 , unsigned char * V_5 , int * V_6 ,
unsigned char * V_7 , int V_8 )
{
int V_9 , V_10 ;
unsigned int V_11 = 0 ;
* V_6 = 0 ;
if ( V_8 == 0 ) return;
if ( ( V_1 -> V_3 + V_8 ) < V_1 -> V_2 )
{
memcpy ( & ( V_1 -> V_12 [ V_1 -> V_3 ] ) , V_7 , V_8 ) ;
V_1 -> V_3 += V_8 ;
return;
}
if ( V_1 -> V_3 != 0 )
{
V_9 = V_1 -> V_2 - V_1 -> V_3 ;
memcpy ( & ( V_1 -> V_12 [ V_1 -> V_3 ] ) , V_7 , V_9 ) ;
V_7 += V_9 ;
V_8 -= V_9 ;
V_10 = F_3 ( V_5 , V_1 -> V_12 , V_1 -> V_2 ) ;
V_1 -> V_3 = 0 ;
V_5 += V_10 ;
* ( V_5 ++ ) = '\n' ;
* V_5 = '\0' ;
V_11 = V_10 + 1 ;
}
while ( V_8 >= V_1 -> V_2 )
{
V_10 = F_3 ( V_5 , V_7 , V_1 -> V_2 ) ;
V_7 += V_1 -> V_2 ;
V_8 -= V_1 -> V_2 ;
V_5 += V_10 ;
* ( V_5 ++ ) = '\n' ;
* V_5 = '\0' ;
V_11 += V_10 + 1 ;
}
if ( V_8 != 0 )
memcpy ( & ( V_1 -> V_12 [ 0 ] ) , V_7 , V_8 ) ;
V_1 -> V_3 = V_8 ;
* V_6 = V_11 ;
}
void F_4 ( T_1 * V_1 , unsigned char * V_5 , int * V_6 )
{
unsigned int V_13 = 0 ;
if ( V_1 -> V_3 != 0 )
{
V_13 = F_3 ( V_5 , V_1 -> V_12 , V_1 -> V_3 ) ;
V_5 [ V_13 ++ ] = '\n' ;
V_5 [ V_13 ] = '\0' ;
V_1 -> V_3 = 0 ;
}
* V_6 = V_13 ;
}
int F_3 ( unsigned char * V_14 , const unsigned char * V_15 , int V_16 )
{
int V_9 , V_13 = 0 ;
unsigned long V_17 ;
for ( V_9 = V_16 ; V_9 > 0 ; V_9 -= 3 )
{
if ( V_9 >= 3 )
{
V_17 = ( ( ( unsigned long ) V_15 [ 0 ] ) << 16L ) |
( ( ( unsigned long ) V_15 [ 1 ] ) << 8L ) | V_15 [ 2 ] ;
* ( V_14 ++ ) = F_5 ( V_17 >> 18L ) ;
* ( V_14 ++ ) = F_5 ( V_17 >> 12L ) ;
* ( V_14 ++ ) = F_5 ( V_17 >> 6L ) ;
* ( V_14 ++ ) = F_5 ( V_17 ) ;
}
else
{
V_17 = ( ( unsigned long ) V_15 [ 0 ] ) << 16L ;
if ( V_9 == 2 ) V_17 |= ( ( unsigned long ) V_15 [ 1 ] << 8L ) ;
* ( V_14 ++ ) = F_5 ( V_17 >> 18L ) ;
* ( V_14 ++ ) = F_5 ( V_17 >> 12L ) ;
* ( V_14 ++ ) = ( V_9 == 1 ) ? '=' : F_5 ( V_17 >> 6L ) ;
* ( V_14 ++ ) = '=' ;
}
V_13 += 4 ;
V_15 += 3 ;
}
* V_14 = '\0' ;
return ( V_13 ) ;
}
void F_6 ( T_1 * V_1 )
{
V_1 -> V_2 = 30 ;
V_1 -> V_3 = 0 ;
V_1 -> V_4 = 0 ;
V_1 -> V_18 = 0 ;
}
int F_7 ( T_1 * V_1 , unsigned char * V_5 , int * V_6 ,
unsigned char * V_7 , int V_8 )
{
int V_19 = - 1 , V_20 = 0 , V_21 = - 1 , V_13 = 0 , V_9 , V_22 , V_23 , V_24 , V_25 , V_26 , V_27 ;
unsigned char * V_28 ;
V_24 = V_1 -> V_3 ;
V_28 = V_1 -> V_12 ;
V_25 = V_1 -> V_4 ;
V_27 = V_1 -> V_18 ;
if ( ( V_8 == 0 ) || ( ( V_24 == 0 ) && ( F_8 ( V_7 [ 0 ] ) == V_29 ) ) )
{ V_21 = 0 ; goto V_30; }
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
{
if ( V_25 >= 80 ) { V_21 = - 1 ; goto V_30; }
V_23 = * ( V_7 ++ ) ;
V_22 = F_8 ( V_23 ) ;
if ( ! F_9 ( V_22 ) )
{
V_28 [ V_24 ++ ] = V_23 ;
V_25 ++ ;
}
else if ( V_22 == V_31 )
{
V_21 = - 1 ;
goto V_30;
}
if ( V_23 == '=' )
{
if ( V_19 == - 1 ) V_19 = V_24 ;
V_20 ++ ;
}
if ( V_22 == V_32 )
{
V_25 = 0 ;
if ( V_27 )
{
V_27 = 0 ;
continue;
}
}
V_27 = 0 ;
if ( ( ( V_9 + 1 ) == V_8 ) && ( ( ( V_24 & 3 ) == 0 ) || V_20 ) )
V_22 = V_29 ;
if ( ( V_22 == V_29 ) || ( V_24 >= 64 ) )
{
if ( ( V_22 != V_29 ) && ( V_24 >= 64 ) ) V_27 = 1 ;
V_26 = V_22 ;
if ( V_24 > 0 )
{
V_22 = F_10 ( V_5 , V_28 , V_24 ) ;
if ( V_22 < 0 ) { V_21 = 0 ; goto V_30; }
V_24 = 0 ;
V_13 += ( V_22 - V_20 ) ;
}
else
{
V_20 = 1 ;
V_22 = 0 ;
}
if ( ( V_22 < V_1 -> V_2 ) && V_20 )
{
V_21 = 0 ;
goto V_30;
}
else
V_1 -> V_2 = V_22 ;
if ( V_19 >= 0 ) { V_21 = 0 ; goto V_30; }
V_5 += V_22 ;
}
}
V_21 = 1 ;
V_30:
* V_6 = V_13 ;
V_1 -> V_3 = V_24 ;
V_1 -> V_4 = V_25 ;
V_1 -> V_18 = V_27 ;
return ( V_21 ) ;
}
int F_10 ( unsigned char * V_14 , const unsigned char * V_15 , int V_24 )
{
int V_9 , V_13 = 0 , V_33 , V_34 , V_35 , V_28 ;
unsigned long V_17 ;
while ( ( F_8 ( * V_15 ) == V_36 ) && ( V_24 > 0 ) )
{
V_15 ++ ;
V_24 -- ;
}
while ( ( V_24 > 3 ) && ( F_9 ( F_8 ( V_15 [ V_24 - 1 ] ) ) ) )
V_24 -- ;
if ( V_24 % 4 != 0 ) return ( - 1 ) ;
for ( V_9 = 0 ; V_9 < V_24 ; V_9 += 4 )
{
V_33 = F_8 ( * ( V_15 ++ ) ) ;
V_34 = F_8 ( * ( V_15 ++ ) ) ;
V_35 = F_8 ( * ( V_15 ++ ) ) ;
V_28 = F_8 ( * ( V_15 ++ ) ) ;
if ( ( V_33 & 0x80 ) || ( V_34 & 0x80 ) ||
( V_35 & 0x80 ) || ( V_28 & 0x80 ) )
return ( - 1 ) ;
V_17 = ( ( ( ( unsigned long ) V_33 ) << 18L ) |
( ( ( unsigned long ) V_34 ) << 12L ) |
( ( ( unsigned long ) V_35 ) << 6L ) |
( ( ( unsigned long ) V_28 ) ) ) ;
* ( V_14 ++ ) = ( unsigned char ) ( V_17 >> 16L ) & 0xff ;
* ( V_14 ++ ) = ( unsigned char ) ( V_17 >> 8L ) & 0xff ;
* ( V_14 ++ ) = ( unsigned char ) ( V_17 ) & 0xff ;
V_13 += 3 ;
}
return ( V_13 ) ;
}
int F_11 ( T_1 * V_1 , unsigned char * V_5 , int * V_6 )
{
int V_9 ;
* V_6 = 0 ;
if ( V_1 -> V_3 != 0 )
{
V_9 = F_10 ( V_5 , V_1 -> V_12 , V_1 -> V_3 ) ;
if ( V_9 < 0 ) return ( - 1 ) ;
V_1 -> V_3 = 0 ;
* V_6 = V_9 ;
return ( 1 ) ;
}
else
return ( 1 ) ;
}
int F_12 ( unsigned char * V_37 , int V_38 )
{
int V_9 , V_3 = 0 , V_39 = 0 ;
if ( V_38 == 0 ) return ( - 1 ) ;
while ( F_8 ( * V_37 ) == V_36 )
{
V_37 ++ ;
V_38 -- ;
if ( V_38 == 0 ) return ( - 1 ) ;
}
for ( V_9 = V_38 ; V_9 >= 4 ; V_9 -= 4 )
{
if ( ( F_8 ( V_37 [ 0 ] ) >= 0x40 ) ||
( F_8 ( V_37 [ 1 ] ) >= 0x40 ) ||
( F_8 ( V_37 [ 2 ] ) >= 0x40 ) ||
( F_8 ( V_37 [ 3 ] ) >= 0x40 ) )
return ( - 1 ) ;
V_37 += 4 ;
V_3 += 1 + ( V_37 [ 2 ] != '=' ) + ( V_37 [ 3 ] != '=' ) ;
}
if ( ( V_9 == 1 ) && ( F_8 ( V_37 [ 0 ] ) == V_32 ) )
return ( V_3 ) ;
if ( ( V_9 == 2 ) && ( F_8 ( V_37 [ 0 ] ) == V_32 ) &&
( F_8 ( V_37 [ 0 ] ) == V_32 ) )
return ( V_3 ) ;
return ( 1 ) ;
}
