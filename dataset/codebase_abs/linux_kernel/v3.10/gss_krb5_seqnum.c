static T_1
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
unsigned char * V_5 , unsigned char * V_6 )
{
struct V_7 * V_8 ;
unsigned char V_9 [ 8 ] ;
T_1 V_10 ;
F_2 ( L_1 , V_11 ) ;
V_8 = F_3 ( V_2 -> V_12 -> V_13 , 0 ,
V_14 ) ;
if ( F_4 ( V_8 ) )
return F_5 ( V_8 ) ;
V_9 [ 0 ] = ( unsigned char ) ( ( V_4 >> 24 ) & 0xff ) ;
V_9 [ 1 ] = ( unsigned char ) ( ( V_4 >> 16 ) & 0xff ) ;
V_9 [ 2 ] = ( unsigned char ) ( ( V_4 >> 8 ) & 0xff ) ;
V_9 [ 3 ] = ( unsigned char ) ( ( V_4 >> 0 ) & 0xff ) ;
V_9 [ 4 ] = V_3 ;
V_9 [ 5 ] = V_3 ;
V_9 [ 6 ] = V_3 ;
V_9 [ 7 ] = V_3 ;
V_10 = F_6 ( V_2 , V_8 , V_5 ) ;
if ( V_10 )
goto V_15;
V_10 = F_7 ( V_8 , V_5 , V_9 , V_6 , 8 ) ;
V_15:
F_8 ( V_8 ) ;
return V_10 ;
}
T_1
F_9 ( struct V_1 * V_2 ,
struct V_7 * V_16 ,
int V_3 ,
T_2 V_4 ,
unsigned char * V_5 , unsigned char * V_6 )
{
unsigned char V_9 [ 8 ] ;
if ( V_2 -> V_17 == V_18 )
return F_1 ( V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
V_9 [ 0 ] = ( unsigned char ) ( V_4 & 0xff ) ;
V_9 [ 1 ] = ( unsigned char ) ( ( V_4 >> 8 ) & 0xff ) ;
V_9 [ 2 ] = ( unsigned char ) ( ( V_4 >> 16 ) & 0xff ) ;
V_9 [ 3 ] = ( unsigned char ) ( ( V_4 >> 24 ) & 0xff ) ;
V_9 [ 4 ] = V_3 ;
V_9 [ 5 ] = V_3 ;
V_9 [ 6 ] = V_3 ;
V_9 [ 7 ] = V_3 ;
return F_7 ( V_16 , V_5 , V_9 , V_6 , 8 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 , unsigned char * V_5 ,
unsigned char * V_6 , int * V_3 , T_1 * V_4 )
{
struct V_7 * V_8 ;
unsigned char V_9 [ 8 ] ;
T_1 V_10 ;
F_2 ( L_1 , V_11 ) ;
V_8 = F_3 ( V_2 -> V_12 -> V_13 , 0 ,
V_14 ) ;
if ( F_4 ( V_8 ) )
return F_5 ( V_8 ) ;
V_10 = F_6 ( V_2 , V_8 , V_5 ) ;
if ( V_10 )
goto V_15;
V_10 = F_11 ( V_8 , V_5 , V_6 , V_9 , 8 ) ;
if ( V_10 )
goto V_15;
if ( ( V_9 [ 4 ] != V_9 [ 5 ] ) || ( V_9 [ 4 ] != V_9 [ 6 ] )
|| ( V_9 [ 4 ] != V_9 [ 7 ] ) ) {
V_10 = ( T_1 ) V_19 ;
goto V_15;
}
* V_3 = V_9 [ 4 ] ;
* V_4 = ( ( V_9 [ 0 ] << 24 ) | ( V_9 [ 1 ] << 16 ) |
( V_9 [ 2 ] << 8 ) | ( V_9 [ 3 ] ) ) ;
V_15:
F_8 ( V_8 ) ;
return V_10 ;
}
T_1
F_12 ( struct V_1 * V_2 ,
unsigned char * V_5 ,
unsigned char * V_6 ,
int * V_3 , T_2 * V_4 )
{
T_1 V_10 ;
unsigned char V_9 [ 8 ] ;
struct V_7 * V_16 = V_2 -> V_20 ;
F_2 ( L_2 ) ;
if ( V_2 -> V_17 == V_18 )
return F_10 ( V_2 , V_5 , V_6 ,
V_3 , V_4 ) ;
if ( ( V_10 = F_11 ( V_16 , V_5 , V_6 , V_9 , 8 ) ) )
return V_10 ;
if ( ( V_9 [ 4 ] != V_9 [ 5 ] ) || ( V_9 [ 4 ] != V_9 [ 6 ] ) ||
( V_9 [ 4 ] != V_9 [ 7 ] ) )
return ( T_1 ) V_19 ;
* V_3 = V_9 [ 4 ] ;
* V_4 = ( ( V_9 [ 0 ] ) |
( V_9 [ 1 ] << 8 ) | ( V_9 [ 2 ] << 16 ) | ( V_9 [ 3 ] << 24 ) ) ;
return 0 ;
}
