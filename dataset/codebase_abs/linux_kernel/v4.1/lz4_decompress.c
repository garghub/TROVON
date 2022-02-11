static int F_1 ( const char * V_1 , char * V_2 , int V_3 )
{
const T_1 * V_4 = ( const T_1 * ) V_1 ;
const T_1 * V_5 ;
T_1 * V_6 = ( T_1 * ) V_2 ;
T_1 * const V_7 = V_6 + V_3 ;
T_1 * V_8 ;
unsigned V_9 ;
T_2 V_10 ;
while ( 1 ) {
V_9 = * V_4 ++ ;
V_10 = ( V_9 >> V_11 ) ;
if ( V_10 == V_12 ) {
T_2 V_13 ;
V_13 = * V_4 ++ ;
for (; V_13 == 255 ; V_10 += 255 )
V_13 = * V_4 ++ ;
if ( F_2 ( V_10 > ( T_2 ) ( V_10 + V_13 ) ) )
goto V_14;
V_10 += V_13 ;
}
V_8 = V_6 + V_10 ;
if ( F_2 ( V_8 > V_7 - V_15 ) ) {
if ( V_8 != V_7 )
goto V_14;
memcpy ( V_6 , V_4 , V_10 ) ;
V_4 += V_10 ;
break;
}
F_3 ( V_4 , V_6 , V_8 ) ;
V_4 -= ( V_6 - V_8 ) ;
V_6 = V_8 ;
F_4 ( V_5 , V_8 , V_4 ) ;
V_4 += 2 ;
if ( F_2 ( V_5 < ( T_1 * const ) V_2 ) )
goto V_14;
V_10 = V_9 & V_16 ;
if ( V_10 == V_16 ) {
for (; * V_4 == 255 ; V_10 += 255 )
V_4 ++ ;
if ( F_2 ( V_10 > ( T_2 ) ( V_10 + * V_4 ) ) )
goto V_14;
V_10 += * V_4 ++ ;
}
if ( F_2 ( ( V_6 - V_5 ) < V_17 ) ) {
#if V_18
int V_19 = V_20 [ V_6 - V_5 ] ;
#else
const int V_19 = 0 ;
#endif
V_6 [ 0 ] = V_5 [ 0 ] ;
V_6 [ 1 ] = V_5 [ 1 ] ;
V_6 [ 2 ] = V_5 [ 2 ] ;
V_6 [ 3 ] = V_5 [ 3 ] ;
V_6 += 4 ;
V_5 += 4 ;
V_5 -= V_21 [ V_6 - V_5 ] ;
F_5 ( V_5 , V_6 ) ;
V_6 += V_17 - 4 ;
V_5 -= V_19 ;
} else {
F_6 ( V_5 , V_6 ) ;
}
V_8 = V_6 + V_10 - ( V_17 - 4 ) ;
if ( V_8 > ( V_7 - V_15 ) ) {
if ( V_8 > V_7 )
goto V_14;
if ( ( V_5 + V_15 ) > V_7 ||
( V_6 + V_15 ) > V_7 )
goto V_14;
F_7 ( V_5 , V_6 , ( V_7 - V_15 ) ) ;
while ( V_6 < V_8 )
* V_6 ++ = * V_5 ++ ;
V_6 = V_8 ;
if ( V_6 == V_7 )
goto V_14;
continue;
}
F_7 ( V_5 , V_6 , V_8 ) ;
V_6 = V_8 ;
}
return ( int ) ( ( ( char * ) V_4 ) - V_1 ) ;
V_14:
return - 1 ;
}
static int F_8 ( const char * V_1 , char * V_2 ,
int V_22 , T_2 V_23 )
{
const T_1 * V_4 = ( const T_1 * ) V_1 ;
const T_1 * const V_24 = V_4 + V_22 ;
const T_1 * V_5 ;
T_1 * V_6 = ( T_1 * ) V_2 ;
T_1 * const V_7 = V_6 + V_23 ;
T_1 * V_8 ;
while ( V_4 < V_24 ) {
unsigned V_9 ;
T_2 V_10 ;
V_9 = * V_4 ++ ;
V_10 = ( V_9 >> V_11 ) ;
if ( V_10 == V_12 ) {
int V_25 = 255 ;
while ( ( V_4 < V_24 ) && ( V_25 == 255 ) ) {
V_25 = * V_4 ++ ;
if ( F_2 ( V_10 > ( T_2 ) ( V_10 + V_25 ) ) )
goto V_14;
V_10 += V_25 ;
}
}
V_8 = V_6 + V_10 ;
if ( ( V_8 > V_7 - V_15 ) ||
( V_4 + V_10 > V_24 - V_15 ) ) {
if ( V_8 > V_7 )
goto V_14;
if ( V_4 + V_10 != V_24 )
goto V_14;
memcpy ( V_6 , V_4 , V_10 ) ;
V_6 += V_10 ;
break;
}
F_3 ( V_4 , V_6 , V_8 ) ;
V_4 -= ( V_6 - V_8 ) ;
V_6 = V_8 ;
F_4 ( V_5 , V_8 , V_4 ) ;
V_4 += 2 ;
if ( V_5 < ( T_1 * const ) V_2 )
goto V_14;
V_10 = ( V_9 & V_16 ) ;
if ( V_10 == V_16 ) {
while ( V_4 < V_24 ) {
int V_25 = * V_4 ++ ;
if ( F_2 ( V_10 > ( T_2 ) ( V_10 + V_25 ) ) )
goto V_14;
V_10 += V_25 ;
if ( V_25 == 255 )
continue;
break;
}
}
if ( F_2 ( ( V_6 - V_5 ) < V_17 ) ) {
#if V_18
int V_19 = V_20 [ V_6 - V_5 ] ;
#else
const int V_19 = 0 ;
#endif
V_6 [ 0 ] = V_5 [ 0 ] ;
V_6 [ 1 ] = V_5 [ 1 ] ;
V_6 [ 2 ] = V_5 [ 2 ] ;
V_6 [ 3 ] = V_5 [ 3 ] ;
V_6 += 4 ;
V_5 += 4 ;
V_5 -= V_21 [ V_6 - V_5 ] ;
F_5 ( V_5 , V_6 ) ;
V_6 += V_17 - 4 ;
V_5 -= V_19 ;
} else {
F_6 ( V_5 , V_6 ) ;
}
V_8 = V_6 + V_10 - ( V_17 - 4 ) ;
if ( V_8 > V_7 - V_15 ) {
if ( V_8 > V_7 )
goto V_14;
F_7 ( V_5 , V_6 , ( V_7 - V_15 ) ) ;
while ( V_6 < V_8 )
* V_6 ++ = * V_5 ++ ;
V_6 = V_8 ;
if ( V_6 == V_7 )
goto V_14;
continue;
}
F_7 ( V_5 , V_6 , V_8 ) ;
V_6 = V_8 ;
}
return ( int ) ( ( ( char * ) V_6 ) - V_2 ) ;
V_14:
return - 1 ;
}
int F_9 ( const unsigned char * V_26 , T_2 * V_27 ,
unsigned char * V_2 , T_2 V_28 )
{
int V_29 = - 1 ;
int V_30 = 0 ;
V_30 = F_1 ( V_26 , V_2 , V_28 ) ;
if ( V_30 < 0 )
goto V_31;
* V_27 = V_30 ;
return 0 ;
V_31:
return V_29 ;
}
int F_10 ( const unsigned char * V_26 , T_2 V_27 ,
unsigned char * V_2 , T_2 * V_32 )
{
int V_29 = - 1 ;
int V_33 = 0 ;
V_33 = F_8 ( V_26 , V_2 , V_27 ,
* V_32 ) ;
if ( V_33 < 0 )
goto V_31;
* V_32 = V_33 ;
return 0 ;
V_31:
return V_29 ;
}
