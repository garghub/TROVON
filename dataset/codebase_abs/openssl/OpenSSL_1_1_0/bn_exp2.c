int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_4 , const T_1 * V_5 , const T_1 * V_6 ,
T_2 * V_7 , T_3 * V_8 )
{
int V_9 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 =
0 , V_16 , V_17 , V_18 , V_19 , V_20 , V_21 ;
int V_22 = 1 ;
T_1 * V_23 , * V_24 ;
const T_1 * V_25 ;
T_1 * V_26 [ V_27 ] , * V_28 [ V_27 ] ;
T_3 * V_29 = NULL ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
if ( ! ( V_6 -> V_23 [ 0 ] & 1 ) ) {
F_3 ( V_30 , V_31 ) ;
return ( 0 ) ;
}
V_13 = F_4 ( V_3 ) ;
V_14 = F_4 ( V_5 ) ;
if ( ( V_13 == 0 ) && ( V_14 == 0 ) ) {
V_15 = F_5 ( V_1 ) ;
return V_15 ;
}
V_11 = ( V_13 > V_14 ) ? V_13 : V_14 ;
F_6 ( V_7 ) ;
V_23 = F_7 ( V_7 ) ;
V_24 = F_7 ( V_7 ) ;
V_26 [ 0 ] = F_7 ( V_7 ) ;
V_28 [ 0 ] = F_7 ( V_7 ) ;
if ( ! V_23 || ! V_24 || ! V_26 [ 0 ] || ! V_28 [ 0 ] )
goto V_32;
if ( V_8 != NULL )
V_29 = V_8 ;
else {
if ( ( V_29 = F_8 () ) == NULL )
goto V_32;
if ( ! F_9 ( V_29 , V_6 , V_7 ) )
goto V_32;
}
V_18 = F_10 ( V_13 ) ;
V_19 = F_10 ( V_14 ) ;
if ( V_2 -> V_33 || F_11 ( V_2 , V_6 ) >= 0 ) {
if ( ! F_12 ( V_26 [ 0 ] , V_2 , V_6 , V_7 ) )
goto V_32;
V_25 = V_26 [ 0 ] ;
} else
V_25 = V_2 ;
if ( F_13 ( V_25 ) ) {
F_14 ( V_1 ) ;
V_15 = 1 ;
goto V_32;
}
if ( ! F_15 ( V_26 [ 0 ] , V_25 , V_29 , V_7 ) )
goto V_32;
if ( V_18 > 1 ) {
if ( ! F_16 ( V_23 , V_26 [ 0 ] , V_26 [ 0 ] , V_29 , V_7 ) )
goto V_32;
V_10 = 1 << ( V_18 - 1 ) ;
for ( V_9 = 1 ; V_9 < V_10 ; V_9 ++ ) {
if ( ( ( V_26 [ V_9 ] = F_7 ( V_7 ) ) == NULL ) ||
! F_16 ( V_26 [ V_9 ] , V_26 [ V_9 - 1 ] , V_23 , V_29 , V_7 ) )
goto V_32;
}
}
if ( V_4 -> V_33 || F_11 ( V_4 , V_6 ) >= 0 ) {
if ( ! F_12 ( V_28 [ 0 ] , V_4 , V_6 , V_7 ) )
goto V_32;
V_25 = V_28 [ 0 ] ;
} else
V_25 = V_4 ;
if ( F_13 ( V_25 ) ) {
F_14 ( V_1 ) ;
V_15 = 1 ;
goto V_32;
}
if ( ! F_15 ( V_28 [ 0 ] , V_25 , V_29 , V_7 ) )
goto V_32;
if ( V_19 > 1 ) {
if ( ! F_16 ( V_23 , V_28 [ 0 ] , V_28 [ 0 ] , V_29 , V_7 ) )
goto V_32;
V_10 = 1 << ( V_19 - 1 ) ;
for ( V_9 = 1 ; V_9 < V_10 ; V_9 ++ ) {
if ( ( ( V_28 [ V_9 ] = F_7 ( V_7 ) ) == NULL ) ||
! F_16 ( V_28 [ V_9 ] , V_28 [ V_9 - 1 ] , V_23 , V_29 , V_7 ) )
goto V_32;
}
}
V_22 = 1 ;
V_20 = 0 ;
V_21 = 0 ;
V_16 = 0 ;
V_17 = 0 ;
if ( ! F_15 ( V_24 , F_17 () , V_29 , V_7 ) )
goto V_32;
for ( V_12 = V_11 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( ! V_22 ) {
if ( ! F_16 ( V_24 , V_24 , V_24 , V_29 , V_7 ) )
goto V_32;
}
if ( ! V_20 )
if ( F_18 ( V_3 , V_12 ) ) {
V_9 = V_12 - V_18 + 1 ;
while ( ! F_18 ( V_3 , V_9 ) )
V_9 ++ ;
V_16 = V_9 ;
V_20 = 1 ;
for ( V_9 = V_12 - 1 ; V_9 >= V_16 ; V_9 -- ) {
V_20 <<= 1 ;
if ( F_18 ( V_3 , V_9 ) )
V_20 ++ ;
}
}
if ( ! V_21 )
if ( F_18 ( V_5 , V_12 ) ) {
V_9 = V_12 - V_19 + 1 ;
while ( ! F_18 ( V_5 , V_9 ) )
V_9 ++ ;
V_17 = V_9 ;
V_21 = 1 ;
for ( V_9 = V_12 - 1 ; V_9 >= V_17 ; V_9 -- ) {
V_21 <<= 1 ;
if ( F_18 ( V_5 , V_9 ) )
V_21 ++ ;
}
}
if ( V_20 && V_12 == V_16 ) {
if ( ! F_16 ( V_24 , V_24 , V_26 [ V_20 >> 1 ] , V_29 , V_7 ) )
goto V_32;
V_20 = 0 ;
V_22 = 0 ;
}
if ( V_21 && V_12 == V_17 ) {
if ( ! F_16 ( V_24 , V_24 , V_28 [ V_21 >> 1 ] , V_29 , V_7 ) )
goto V_32;
V_21 = 0 ;
V_22 = 0 ;
}
}
if ( ! F_19 ( V_1 , V_24 , V_29 , V_7 ) )
goto V_32;
V_15 = 1 ;
V_32:
if ( V_8 == NULL )
F_20 ( V_29 ) ;
F_21 ( V_7 ) ;
F_2 ( V_1 ) ;
return ( V_15 ) ;
}
