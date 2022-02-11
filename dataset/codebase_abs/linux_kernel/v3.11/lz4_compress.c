static inline int F_1 ( void * V_1 ,
const char * V_2 ,
char * V_3 ,
int V_4 ,
int V_5 )
{
T_1 * V_6 = ( T_1 * ) V_1 ;
const T_2 * V_7 = ( T_2 * ) V_2 ;
#if V_8
const T_3 * const V_9 = V_7 ;
#else
const int V_9 = 0 ;
#endif
const T_2 * V_10 = V_7 ;
const T_2 * const V_11 = V_7 + V_4 ;
const T_2 * const V_12 = V_11 - V_13 ;
#define F_2 (iend - LASTLITERALS)
T_2 * V_14 = ( T_2 * ) V_3 ;
T_2 * const V_15 = V_14 + V_5 ;
int V_16 ;
const int V_17 = V_18 ;
T_4 V_19 ;
int V_20 ;
if ( V_4 < V_21 )
goto V_22;
memset ( ( void * ) V_6 , 0 , V_23 ) ;
V_6 [ F_3 ( V_7 ) ] = V_7 - V_9 ;
V_7 ++ ;
V_19 = F_3 ( V_7 ) ;
for (; ; ) {
int V_24 = ( 1U << V_17 ) + 3 ;
const T_2 * V_25 = V_7 ;
const T_2 * V_26 ;
T_2 * V_27 ;
do {
T_4 V_28 = V_19 ;
int V_29 = V_24 ++ >> V_17 ;
V_7 = V_25 ;
V_25 = V_7 + V_29 ;
if ( F_4 ( V_25 > V_12 ) )
goto V_22;
V_19 = F_3 ( V_25 ) ;
V_26 = V_9 + V_6 [ V_28 ] ;
V_6 [ V_28 ] = V_7 - V_9 ;
} while ( ( V_26 < V_7 - V_30 ) || ( F_5 ( V_26 ) != F_5 ( V_7 ) ) );
while ( ( V_7 > V_10 ) && ( V_26 > ( T_2 * ) V_2 ) &&
F_4 ( V_7 [ - 1 ] == V_26 [ - 1 ] ) ) {
V_7 -- ;
V_26 -- ;
}
V_16 = ( int ) ( V_7 - V_10 ) ;
V_27 = V_14 ++ ;
if ( F_4 ( V_14 + V_16 + ( 2 + 1 + V_31 ) +
( V_16 >> 8 ) > V_15 ) )
return 0 ;
if ( V_16 >= ( int ) V_32 ) {
int V_33 ;
* V_27 = ( V_32 << V_34 ) ;
V_33 = V_16 - V_32 ;
for (; V_33 > 254 ; V_33 -= 255 )
* V_14 ++ = 255 ;
* V_14 ++ = ( T_2 ) V_33 ;
} else
* V_27 = ( V_16 << V_34 ) ;
F_6 ( V_10 , V_14 , V_16 ) ;
V_35:
F_7 ( V_14 , ( V_36 ) ( V_7 - V_26 ) ) ;
V_7 += V_37 ;
V_26 += V_37 ;
V_10 = V_7 ;
while ( F_8 ( V_7 < F_2 - ( V_38 - 1 ) ) ) {
#if V_8
T_5 V_39 = F_9 ( V_26 ) ^ F_9 ( V_7 ) ;
#else
T_4 V_39 = F_5 ( V_26 ) ^ F_5 ( V_7 ) ;
#endif
if ( ! V_39 ) {
V_7 += V_38 ;
V_26 += V_38 ;
continue;
}
V_7 += F_10 ( V_39 ) ;
goto V_40;
}
#if V_8
if ( ( V_7 < ( F_2 - 3 ) ) && ( F_5 ( V_26 ) == F_5 ( V_7 ) ) ) {
V_7 += 4 ;
V_26 += 4 ;
}
#endif
if ( ( V_7 < ( F_2 - 1 ) ) && ( F_11 ( V_26 ) == F_11 ( V_7 ) ) ) {
V_7 += 2 ;
V_26 += 2 ;
}
if ( ( V_7 < F_2 ) && ( * V_26 == * V_7 ) )
V_7 ++ ;
V_40:
V_16 = ( int ) ( V_7 - V_10 ) ;
if ( F_4 ( V_14 + ( 1 + V_31 ) + ( V_16 >> 8 ) > V_15 ) )
return 0 ;
if ( V_16 >= ( int ) V_41 ) {
* V_27 += V_41 ;
V_16 -= V_41 ;
for (; V_16 > 509 ; V_16 -= 510 ) {
* V_14 ++ = 255 ;
* V_14 ++ = 255 ;
}
if ( V_16 > 254 ) {
V_16 -= 255 ;
* V_14 ++ = 255 ;
}
* V_14 ++ = ( T_2 ) V_16 ;
} else
* V_27 += V_16 ;
if ( V_7 > V_12 ) {
V_10 = V_7 ;
break;
}
V_6 [ F_3 ( V_7 - 2 ) ] = V_7 - 2 - V_9 ;
V_26 = V_9 + V_6 [ F_3 ( V_7 ) ] ;
V_6 [ F_3 ( V_7 ) ] = V_7 - V_9 ;
if ( ( V_26 > V_7 - ( V_30 + 1 ) ) && ( F_5 ( V_26 ) == F_5 ( V_7 ) ) ) {
V_27 = V_14 ++ ;
* V_27 = 0 ;
goto V_35;
}
V_10 = V_7 ++ ;
V_19 = F_3 ( V_7 ) ;
}
V_22:
V_20 = ( int ) ( V_11 - V_10 ) ;
if ( ( ( char * ) V_14 - V_3 ) + V_20 + 1
+ ( ( V_20 + 255 - V_32 ) / 255 ) > ( T_4 ) V_5 )
return 0 ;
if ( V_20 >= ( int ) V_32 ) {
* V_14 ++ = ( V_32 << V_34 ) ;
V_20 -= V_32 ;
for (; V_20 > 254 ; V_20 -= 255 )
* V_14 ++ = 255 ;
* V_14 ++ = ( T_2 ) V_20 ;
} else
* V_14 ++ = ( V_20 << V_34 ) ;
memcpy ( V_14 , V_10 , V_11 - V_10 ) ;
V_14 += V_11 - V_10 ;
return ( int ) ( ( ( char * ) V_14 ) - V_3 ) ;
}
static inline int F_12 ( void * V_1 ,
const char * V_2 ,
char * V_3 ,
int V_4 ,
int V_5 )
{
V_36 * V_6 = ( V_36 * ) V_1 ;
const T_2 * V_7 = ( T_2 * ) V_2 ;
const T_2 * V_10 = V_7 ;
const T_2 * const V_9 = V_7 ;
const T_2 * const V_11 = V_7 + V_4 ;
const T_2 * const V_12 = V_11 - V_13 ;
#define F_2 (iend - LASTLITERALS)
T_2 * V_14 = ( T_2 * ) V_3 ;
T_2 * const V_15 = V_14 + V_5 ;
int V_33 , V_16 ;
const int V_17 = V_18 ;
T_4 V_19 ;
int V_20 ;
if ( V_4 < V_21 )
goto V_22;
memset ( ( void * ) V_6 , 0 , V_23 ) ;
V_7 ++ ;
V_19 = F_13 ( V_7 ) ;
for (; ; ) {
int V_24 = ( 1U << V_17 ) + 3 ;
const T_2 * V_25 = V_7 ;
const T_2 * V_26 ;
T_2 * V_27 ;
do {
T_4 V_28 = V_19 ;
int V_29 = V_24 ++ >> V_17 ;
V_7 = V_25 ;
V_25 = V_7 + V_29 ;
if ( V_25 > V_12 )
goto V_22;
V_19 = F_13 ( V_25 ) ;
V_26 = V_9 + V_6 [ V_28 ] ;
V_6 [ V_28 ] = ( V_36 ) ( V_7 - V_9 ) ;
} while ( F_5 ( V_26 ) != F_5 ( V_7 ) );
while ( ( V_7 > V_10 ) && ( V_26 > ( T_2 * ) V_2 )
&& ( V_7 [ - 1 ] == V_26 [ - 1 ] ) ) {
V_7 -- ;
V_26 -- ;
}
V_16 = ( int ) ( V_7 - V_10 ) ;
V_27 = V_14 ++ ;
if ( F_4 ( V_14 + V_16 + ( 2 + 1 + V_31 )
+ ( V_16 >> 8 ) > V_15 ) )
return 0 ;
if ( V_16 >= ( int ) V_32 ) {
* V_27 = ( V_32 << V_34 ) ;
V_33 = V_16 - V_32 ;
for (; V_33 > 254 ; V_33 -= 255 )
* V_14 ++ = 255 ;
* V_14 ++ = ( T_2 ) V_33 ;
} else
* V_27 = ( V_16 << V_34 ) ;
F_6 ( V_10 , V_14 , V_16 ) ;
V_35:
F_7 ( V_14 , ( V_36 ) ( V_7 - V_26 ) ) ;
V_7 += V_37 ;
V_26 += V_37 ;
V_10 = V_7 ;
while ( V_7 < F_2 - ( V_38 - 1 ) ) {
#if V_8
T_5 V_39 = F_9 ( V_26 ) ^ F_9 ( V_7 ) ;
#else
T_4 V_39 = F_5 ( V_26 ) ^ F_5 ( V_7 ) ;
#endif
if ( ! V_39 ) {
V_7 += V_38 ;
V_26 += V_38 ;
continue;
}
V_7 += F_10 ( V_39 ) ;
goto V_40;
}
#if V_8
if ( ( V_7 < ( F_2 - 3 ) ) && ( F_5 ( V_26 ) == F_5 ( V_7 ) ) ) {
V_7 += 4 ;
V_26 += 4 ;
}
#endif
if ( ( V_7 < ( F_2 - 1 ) ) && ( F_11 ( V_26 ) == F_11 ( V_7 ) ) ) {
V_7 += 2 ;
V_26 += 2 ;
}
if ( ( V_7 < F_2 ) && ( * V_26 == * V_7 ) )
V_7 ++ ;
V_40:
V_33 = ( int ) ( V_7 - V_10 ) ;
if ( F_4 ( V_14 + ( 1 + V_31 ) + ( V_33 >> 8 ) > V_15 ) )
return 0 ;
if ( V_33 >= ( int ) V_41 ) {
* V_27 += V_41 ;
V_33 -= V_41 ;
for (; V_33 > 509 ; V_33 -= 510 ) {
* V_14 ++ = 255 ;
* V_14 ++ = 255 ;
}
if ( V_33 > 254 ) {
V_33 -= 255 ;
* V_14 ++ = 255 ;
}
* V_14 ++ = ( T_2 ) V_33 ;
} else
* V_27 += V_33 ;
if ( V_7 > V_12 ) {
V_10 = V_7 ;
break;
}
V_6 [ F_13 ( V_7 - 2 ) ] = ( V_36 ) ( V_7 - 2 - V_9 ) ;
V_26 = V_9 + V_6 [ F_13 ( V_7 ) ] ;
V_6 [ F_13 ( V_7 ) ] = ( V_36 ) ( V_7 - V_9 ) ;
if ( F_5 ( V_26 ) == F_5 ( V_7 ) ) {
V_27 = V_14 ++ ;
* V_27 = 0 ;
goto V_35;
}
V_10 = V_7 ++ ;
V_19 = F_13 ( V_7 ) ;
}
V_22:
V_20 = ( int ) ( V_11 - V_10 ) ;
if ( V_14 + V_20 + 1 + ( V_20 - V_32 + 255 ) / 255 > V_15 )
return 0 ;
if ( V_20 >= ( int ) V_32 ) {
* V_14 ++ = ( V_32 << V_34 ) ;
V_20 -= V_32 ;
for (; V_20 > 254 ; V_20 -= 255 )
* V_14 ++ = 255 ;
* V_14 ++ = ( T_2 ) V_20 ;
} else
* V_14 ++ = ( V_20 << V_34 ) ;
memcpy ( V_14 , V_10 , V_11 - V_10 ) ;
V_14 += V_11 - V_10 ;
return ( int ) ( ( ( char * ) V_14 ) - V_3 ) ;
}
int F_14 ( const unsigned char * V_42 , T_6 V_43 ,
unsigned char * V_44 , T_6 * V_45 , void * V_46 )
{
int V_47 = - 1 ;
int V_48 = 0 ;
if ( V_43 < V_49 )
V_48 = F_12 ( V_46 , V_42 , V_44 , V_43 ,
F_15 ( V_43 ) ) ;
else
V_48 = F_1 ( V_46 , V_42 , V_44 , V_43 ,
F_15 ( V_43 ) ) ;
if ( V_48 < 0 )
goto exit;
* V_45 = V_48 ;
return 0 ;
exit:
return V_47 ;
}
