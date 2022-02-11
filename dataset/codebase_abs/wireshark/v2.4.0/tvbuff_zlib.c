T_1 *
F_1 ( T_1 * V_1 , const int V_2 , int V_3 )
{
T_2 V_4 ;
T_3 V_5 = 0 ;
T_4 * V_6 ;
T_4 * V_7 = NULL ;
T_1 * V_8 = NULL ;
T_5 V_9 ;
T_6 * V_10 ;
T_3 V_11 = 0 ;
T_2 V_12 = V_13 ;
T_4 * V_14 ;
T_3 V_15 ;
#ifdef F_2
T_3 V_16 = 0 ;
T_3 V_17 = F_3 ( V_1 , V_2 ) ;
#endif
if ( V_1 == NULL ) {
return NULL ;
}
V_6 = ( T_4 * ) F_4 ( NULL , V_1 , V_2 , V_3 ) ;
if ( V_6 == NULL ) {
return NULL ;
}
V_15 = F_3 ( V_1 , V_2 ) * 2 ;
V_15 = F_5 ( V_15 , V_18 , V_19 ) ;
#ifdef F_2
F_6 ( L_1 , V_15 ) ;
#endif
V_14 = V_6 ;
V_9 = F_7 ( V_20 , 1 ) ;
V_9 -> V_21 = V_14 ;
V_9 -> V_22 = V_3 ;
V_10 = ( T_6 * ) F_8 ( V_15 ) ;
V_9 -> V_23 = V_10 ;
V_9 -> V_24 = V_15 ;
V_4 = F_9 ( V_9 , V_12 ) ;
V_11 = 1 ;
if ( V_4 != V_25 ) {
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
F_12 ( NULL , V_6 ) ;
F_11 ( V_10 ) ;
return NULL ;
}
while ( 1 ) {
memset ( V_10 , '\0' , V_15 ) ;
V_9 -> V_23 = V_10 ;
V_9 -> V_24 = V_15 ;
V_4 = F_13 ( V_9 , V_26 ) ;
if ( V_4 == V_25 || V_4 == V_27 ) {
T_3 V_28 = V_15 - V_9 -> V_24 ;
#ifdef F_2
++ V_16 ;
#endif
if ( V_7 == NULL ) {
V_7 = ( T_4 * ) ( ( V_28 || V_4 != V_27 ) ?
F_14 ( V_10 , V_28 ) :
F_15 ( L_2 ) ) ;
} else {
T_4 * V_29 = ( T_4 * ) F_8 ( V_5 + V_28 ) ;
memcpy ( V_29 , V_7 , V_5 ) ;
memcpy ( V_29 + V_5 , V_10 , V_28 ) ;
F_11 ( V_7 ) ;
V_7 = V_29 ;
}
V_5 += V_28 ;
if ( V_4 == V_27 ) {
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
F_11 ( V_10 ) ;
break;
}
} else if ( V_4 == V_30 ) {
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
F_11 ( V_10 ) ;
if ( V_7 != NULL ) {
break;
} else {
F_12 ( NULL , V_6 ) ;
return NULL ;
}
} else if ( V_4 == V_31 && V_11 == 1
&& V_7 == NULL && V_3 >= 2 &&
( * V_6 == 0x1f ) && ( * ( V_6 + 1 ) == 0x8b ) ) {
T_6 * V_32 = V_6 + 2 ;
T_6 V_33 = 0 ;
if ( V_3 < 10 || * V_32 != V_34 ) {
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
F_12 ( NULL , V_6 ) ;
F_11 ( V_10 ) ;
return NULL ;
}
V_32 ++ ;
V_33 = * V_32 ;
V_32 ++ ;
V_32 += 6 ;
if ( V_33 & ( 1 << 2 ) ) {
T_7 V_35 = 0 ;
if ( V_32 - V_6 < V_3 ) {
V_35 += * V_32 ;
V_32 ++ ;
}
if ( V_32 - V_6 < V_3 ) {
V_35 += * V_32 << 8 ;
V_32 ++ ;
}
V_32 += V_35 ;
}
if ( V_33 & ( 1 << 3 ) ) {
while ( ( V_32 - V_6 ) < V_3 && * V_32 != '\0' ) {
V_32 ++ ;
}
V_32 ++ ;
}
if ( V_33 & ( 1 << 4 ) ) {
while ( ( V_32 - V_6 ) < V_3 && * V_32 != '\0' ) {
V_32 ++ ;
}
V_32 ++ ;
}
if ( V_32 - V_6 > V_3 ) {
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
F_12 ( NULL , V_6 ) ;
F_11 ( V_10 ) ;
return NULL ;
}
V_3 -= ( int ) ( V_32 - V_6 ) ;
V_14 = V_32 ;
F_16 ( V_9 ) ;
V_9 -> V_21 = V_14 ;
V_9 -> V_22 = V_3 ;
F_10 ( V_9 ) ;
F_9 ( V_9 , V_12 ) ;
V_11 ++ ;
} else if ( V_4 == V_31 && V_7 == NULL &&
V_11 <= 3 ) {
V_12 = - V_13 ;
F_16 ( V_9 ) ;
V_9 -> V_21 = V_14 ;
V_9 -> V_22 = V_3 ;
F_10 ( V_9 ) ;
memset ( V_10 , '\0' , V_15 ) ;
V_9 -> V_23 = V_10 ;
V_9 -> V_24 = V_15 ;
V_4 = F_9 ( V_9 , V_12 ) ;
V_11 ++ ;
if ( V_4 != V_25 ) {
F_11 ( V_9 ) ;
F_11 ( V_10 ) ;
F_12 ( NULL , V_6 ) ;
F_11 ( V_7 ) ;
return NULL ;
}
} else {
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
F_11 ( V_10 ) ;
if ( V_7 == NULL ) {
F_12 ( NULL , V_6 ) ;
return NULL ;
}
break;
}
}
#ifdef F_2
F_6 ( L_3 , V_16 ) ;
F_6 ( L_4 , V_17 , V_5 ) ;
#endif
if ( V_7 != NULL ) {
V_8 = F_17 ( ( T_4 * ) V_7 , V_5 , V_5 ) ;
F_18 ( V_8 , F_11 ) ;
}
F_12 ( NULL , V_6 ) ;
return V_8 ;
}
T_1 *
F_1 ( T_1 * V_1 V_36 , const int V_2 V_36 , int V_3 V_36 )
{
return NULL ;
}
T_1 *
F_19 ( T_1 * V_37 , T_1 * V_1 , const int V_2 , int V_3 )
{
T_1 * V_38 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_38 )
F_20 ( V_37 , V_38 ) ;
return V_38 ;
}
