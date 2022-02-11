int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const T_2 * V_3 , const unsigned char * V_4 ,
int V_5 )
{
return F_2 ( V_1 , V_2 , V_3 , NULL , V_4 , V_5 ) ;
}
int F_2 ( T_1 * V_1 , const unsigned char * V_2 ,
const T_2 * V_3 , const T_2 * V_6 ,
const unsigned char * V_4 , int V_5 )
{
int V_7 ;
int V_8 = 0 ;
int V_9 , V_10 , V_11 , V_12 ;
const unsigned char * V_13 ;
unsigned char * V_14 = NULL ;
T_3 * V_15 = F_3 () ;
unsigned char V_16 [ V_17 ] ;
if ( V_15 == NULL )
goto V_18;
if ( V_6 == NULL )
V_6 = V_3 ;
V_9 = F_4 ( V_3 ) ;
if ( V_9 < 0 )
goto V_18;
if ( V_5 == - 1 )
V_5 = V_9 ;
else if ( V_5 == - 2 )
V_5 = - 2 ;
else if ( V_5 < - 2 ) {
F_5 ( V_19 , V_20 ) ;
goto V_18;
}
V_11 = ( F_6 ( V_1 -> V_21 ) - 1 ) & 0x7 ;
V_12 = F_7 ( V_1 ) ;
if ( V_4 [ 0 ] & ( 0xFF << V_11 ) ) {
F_5 ( V_19 , V_22 ) ;
goto V_18;
}
if ( V_11 == 0 ) {
V_4 ++ ;
V_12 -- ;
}
if ( V_12 < ( V_9 + V_5 + 2 ) ) {
F_5 ( V_19 , V_23 ) ;
goto V_18;
}
if ( V_4 [ V_12 - 1 ] != 0xbc ) {
F_5 ( V_19 , V_24 ) ;
goto V_18;
}
V_10 = V_12 - V_9 - 1 ;
V_13 = V_4 + V_10 ;
V_14 = F_8 ( V_10 ) ;
if ( V_14 == NULL ) {
F_5 ( V_19 , V_25 ) ;
goto V_18;
}
if ( F_9 ( V_14 , V_10 , V_13 , V_9 , V_6 ) < 0 )
goto V_18;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ )
V_14 [ V_7 ] ^= V_4 [ V_7 ] ;
if ( V_11 )
V_14 [ 0 ] &= 0xFF >> ( 8 - V_11 ) ;
for ( V_7 = 0 ; V_14 [ V_7 ] == 0 && V_7 < ( V_10 - 1 ) ; V_7 ++ ) ;
if ( V_14 [ V_7 ++ ] != 0x1 ) {
F_5 ( V_19 , V_26 ) ;
goto V_18;
}
if ( V_5 >= 0 && ( V_10 - V_7 ) != V_5 ) {
F_5 ( V_19 , V_20 ) ;
goto V_18;
}
if ( ! F_10 ( V_15 , V_3 , NULL )
|| ! F_11 ( V_15 , V_27 , sizeof V_27 )
|| ! F_11 ( V_15 , V_2 , V_9 ) )
goto V_18;
if ( V_10 - V_7 ) {
if ( ! F_11 ( V_15 , V_14 + V_7 , V_10 - V_7 ) )
goto V_18;
}
if ( ! F_12 ( V_15 , V_16 , NULL ) )
goto V_18;
if ( memcmp ( V_16 , V_13 , V_9 ) ) {
F_5 ( V_19 , V_28 ) ;
V_8 = 0 ;
} else
V_8 = 1 ;
V_18:
F_13 ( V_14 ) ;
F_14 ( V_15 ) ;
return V_8 ;
}
int F_15 ( T_1 * V_1 , unsigned char * V_4 ,
const unsigned char * V_2 ,
const T_2 * V_3 , int V_5 )
{
return F_16 ( V_1 , V_4 , V_2 , V_3 , NULL , V_5 ) ;
}
int F_16 ( T_1 * V_1 , unsigned char * V_4 ,
const unsigned char * V_2 ,
const T_2 * V_3 , const T_2 * V_6 ,
int V_5 )
{
int V_7 ;
int V_8 = 0 ;
int V_9 , V_10 , V_11 , V_12 ;
unsigned char * V_13 , * V_29 = NULL , * V_30 ;
T_3 * V_15 = NULL ;
if ( V_6 == NULL )
V_6 = V_3 ;
V_9 = F_4 ( V_3 ) ;
if ( V_9 < 0 )
goto V_18;
if ( V_5 == - 1 )
V_5 = V_9 ;
else if ( V_5 == - 2 )
V_5 = - 2 ;
else if ( V_5 < - 2 ) {
F_5 ( V_31 , V_20 ) ;
goto V_18;
}
V_11 = ( F_6 ( V_1 -> V_21 ) - 1 ) & 0x7 ;
V_12 = F_7 ( V_1 ) ;
if ( V_11 == 0 ) {
* V_4 ++ = 0 ;
V_12 -- ;
}
if ( V_5 == - 2 ) {
V_5 = V_12 - V_9 - 2 ;
} else if ( V_12 < ( V_9 + V_5 + 2 ) ) {
F_5 ( V_31 ,
V_32 ) ;
goto V_18;
}
if ( V_5 > 0 ) {
V_29 = F_8 ( V_5 ) ;
if ( V_29 == NULL ) {
F_5 ( V_31 ,
V_25 ) ;
goto V_18;
}
if ( F_17 ( V_29 , V_5 ) <= 0 )
goto V_18;
}
V_10 = V_12 - V_9 - 1 ;
V_13 = V_4 + V_10 ;
V_15 = F_3 () ;
if ( V_15 == NULL )
goto V_18;
if ( ! F_10 ( V_15 , V_3 , NULL )
|| ! F_11 ( V_15 , V_27 , sizeof V_27 )
|| ! F_11 ( V_15 , V_2 , V_9 ) )
goto V_18;
if ( V_5 && ! F_11 ( V_15 , V_29 , V_5 ) )
goto V_18;
if ( ! F_12 ( V_15 , V_13 , NULL ) )
goto V_18;
if ( F_9 ( V_4 , V_10 , V_13 , V_9 , V_6 ) )
goto V_18;
V_30 = V_4 ;
V_30 += V_12 - V_5 - V_9 - 2 ;
* V_30 ++ ^= 0x1 ;
if ( V_5 > 0 ) {
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ )
* V_30 ++ ^= V_29 [ V_7 ] ;
}
if ( V_11 )
V_4 [ 0 ] &= 0xFF >> ( 8 - V_11 ) ;
V_4 [ V_12 - 1 ] = 0xbc ;
V_8 = 1 ;
V_18:
F_14 ( V_15 ) ;
F_13 ( V_29 ) ;
return V_8 ;
}
