T_1 *
F_1 ( T_1 * V_1 , const int V_2 , int V_3 )
{
T_2 V_4 = V_5 ;
T_3 V_6 = 0 ;
T_4 * V_7 = NULL ;
T_4 * V_8 = NULL ;
T_1 * V_9 = NULL ;
T_5 V_10 = NULL ;
T_6 * V_11 = NULL ;
T_3 V_12 = 0 ;
T_2 V_13 = V_14 ;
T_4 * V_15 = NULL ;
T_3 V_16 = V_17 ;
#ifdef F_2
T_3 V_18 = 0 ;
T_3 V_19 = F_3 ( V_1 , V_2 ) ;
#endif
if ( V_1 == NULL ) {
return NULL ;
}
V_7 = ( T_4 * ) F_4 ( NULL , V_1 , V_2 , V_3 ) ;
if ( ! V_7 )
return NULL ;
V_16 = F_3 ( V_1 , V_2 ) * 2 ;
V_16 = F_5 ( V_16 , V_17 , V_20 ) ;
#ifdef F_2
printf ( L_1 , V_16 ) ;
#endif
V_15 = V_7 ;
V_10 = F_6 ( V_21 , 1 ) ;
V_10 -> V_22 = V_15 ;
V_10 -> V_23 = V_3 ;
V_11 = ( T_6 * ) F_7 ( V_16 ) ;
V_10 -> V_24 = V_11 ;
V_10 -> V_25 = V_16 ;
V_4 = F_8 ( V_10 , V_13 ) ;
V_12 = 1 ;
if ( V_4 != V_5 ) {
F_9 ( V_10 ) ;
F_10 ( V_10 ) ;
F_10 ( V_7 ) ;
F_10 ( V_11 ) ;
return NULL ;
}
while ( 1 ) {
memset ( V_11 , '\0' , V_16 ) ;
V_10 -> V_24 = V_11 ;
V_10 -> V_25 = V_16 ;
V_4 = F_11 ( V_10 , V_26 ) ;
if ( V_4 == V_5 || V_4 == V_27 ) {
T_3 V_28 = V_16 - V_10 -> V_25 ;
#ifdef F_2
++ V_18 ;
#endif
if ( V_8 == NULL ) {
V_8 = ( T_4 * ) ( ( V_28 || V_4 != V_27 ) ?
F_12 ( V_11 , V_28 ) :
F_13 ( L_2 ) ) ;
} else {
T_4 * V_29 = ( T_4 * ) F_7 ( V_6 + V_28 ) ;
memcpy ( V_29 , V_8 , V_6 ) ;
memcpy ( V_29 + V_6 , V_11 , V_28 ) ;
F_10 ( V_8 ) ;
V_8 = V_29 ;
}
V_6 += V_28 ;
if ( V_4 == V_27 ) {
F_9 ( V_10 ) ;
F_10 ( V_10 ) ;
F_10 ( V_11 ) ;
break;
}
} else if ( V_4 == V_30 ) {
F_9 ( V_10 ) ;
F_10 ( V_10 ) ;
F_10 ( V_11 ) ;
if ( V_8 != NULL ) {
break;
} else {
F_10 ( V_7 ) ;
return NULL ;
}
} else if ( V_4 == V_31 && V_12 == 1
&& V_8 == NULL && ( * V_7 == 0x1f ) &&
( * ( V_7 + 1 ) == 0x8b ) ) {
T_6 * V_32 = V_7 + 2 ;
T_6 V_33 = 0 ;
if ( * V_32 == V_34 ) {
V_32 ++ ;
} else {
F_9 ( V_10 ) ;
F_10 ( V_10 ) ;
F_10 ( V_7 ) ;
F_10 ( V_11 ) ;
return NULL ;
}
V_33 = * V_32 ;
V_32 += 7 ;
if ( V_33 & ( 1 << 2 ) ) {
T_2 V_35 = ( T_2 ) ( * V_32 |
( * ( V_32 + 1 ) << 8 ) ) ;
V_32 += V_35 ;
}
if ( V_33 & ( 1 << 3 ) ) {
while ( ( V_32 - V_7 ) < V_3 && * V_32 != '\0' ) {
V_32 ++ ;
}
V_32 ++ ;
}
if ( V_33 & ( 1 << 4 ) ) {
while ( ( V_32 - V_7 ) < V_3 && * V_32 != '\0' ) {
V_32 ++ ;
}
V_32 ++ ;
}
F_14 ( V_10 ) ;
V_15 = V_32 ;
V_10 -> V_22 = V_15 ;
if ( V_32 - V_7 > V_3 ) {
F_9 ( V_10 ) ;
F_10 ( V_10 ) ;
F_10 ( V_7 ) ;
F_10 ( V_11 ) ;
return NULL ;
}
V_3 -= ( int ) ( V_32 - V_7 ) ;
F_9 ( V_10 ) ;
F_8 ( V_10 , V_13 ) ;
V_12 ++ ;
} else if ( V_4 == V_31 && V_8 == NULL &&
V_12 <= 3 ) {
V_13 = - V_14 ;
F_14 ( V_10 ) ;
V_10 -> V_22 = V_15 ;
V_10 -> V_23 = V_3 ;
F_9 ( V_10 ) ;
memset ( V_11 , '\0' , V_16 ) ;
V_10 -> V_24 = V_11 ;
V_10 -> V_25 = V_16 ;
V_4 = F_8 ( V_10 , V_13 ) ;
V_12 ++ ;
if ( V_4 != V_5 ) {
F_10 ( V_10 ) ;
F_10 ( V_11 ) ;
F_10 ( V_7 ) ;
F_10 ( V_8 ) ;
return NULL ;
}
} else {
F_9 ( V_10 ) ;
F_10 ( V_10 ) ;
F_10 ( V_11 ) ;
if ( V_8 == NULL ) {
F_10 ( V_7 ) ;
return NULL ;
}
break;
}
}
#ifdef F_2
printf ( L_3 , V_18 ) ;
printf ( L_4 , V_19 , V_6 ) ;
#endif
if ( V_8 != NULL ) {
V_9 = F_15 ( ( T_4 * ) V_8 , V_6 , V_6 ) ;
F_16 ( V_9 , F_10 ) ;
}
F_10 ( V_7 ) ;
return V_9 ;
}
T_1 *
F_1 ( T_1 * V_1 V_36 , const int V_2 V_36 , int V_3 V_36 )
{
return NULL ;
}
T_1 *
F_17 ( T_1 * V_37 , T_1 * V_1 , const int V_2 , int V_3 )
{
T_1 * V_38 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_38 )
F_18 ( V_37 , V_38 ) ;
return V_38 ;
}
