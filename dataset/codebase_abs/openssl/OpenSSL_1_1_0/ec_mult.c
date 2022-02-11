static T_1 * F_1 ( const T_2 * V_1 )
{
T_1 * V_2 = NULL ;
if ( ! V_1 )
return NULL ;
V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL ) {
F_3 ( V_3 , V_4 ) ;
return V_2 ;
}
V_2 -> V_1 = V_1 ;
V_2 -> V_5 = 8 ;
V_2 -> V_6 = 4 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = F_4 () ;
if ( V_2 -> V_8 == NULL ) {
F_3 ( V_3 , V_4 ) ;
F_5 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
T_1 * F_6 ( T_1 * V_9 )
{
int V_10 ;
if ( V_9 != NULL )
F_7 ( & V_9 -> V_7 , 1 , & V_10 , V_9 -> V_8 ) ;
return V_9 ;
}
void F_8 ( T_1 * V_9 )
{
int V_10 ;
if ( V_9 == NULL )
return;
F_7 ( & V_9 -> V_7 , - 1 , & V_10 , V_9 -> V_8 ) ;
F_9 ( L_1 , V_9 ) ;
if ( V_10 > 0 )
return;
F_10 ( V_10 < 0 ) ;
if ( V_9 -> V_11 != NULL ) {
T_3 * * V_12 ;
for ( V_12 = V_9 -> V_11 ; * V_12 != NULL ; V_12 ++ )
F_11 ( * V_12 ) ;
F_5 ( V_9 -> V_11 ) ;
}
F_12 ( V_9 -> V_8 ) ;
F_5 ( V_9 ) ;
}
int F_13 ( const T_2 * V_1 , T_3 * V_13 , const T_4 * V_14 ,
T_5 V_15 , const T_3 * V_11 [] , const T_4 * V_16 [] ,
T_6 * V_17 )
{
T_6 * V_18 = NULL ;
const T_3 * V_19 = NULL ;
T_3 * V_20 = NULL ;
T_5 V_21 ;
T_5 V_5 = 0 , V_22 = 0 ;
T_5 V_23 = 0 ;
T_5 V_10 , V_24 ;
int V_25 ;
int V_26 = 0 ;
int V_27 = 1 ;
T_5 * V_28 = NULL ;
signed char * * V_29 = NULL ;
T_5 * V_30 = NULL ;
T_5 V_31 = 0 ;
T_5 V_32 ;
T_3 * * V_33 = NULL ;
T_3 * * V_34 ;
T_3 * * * V_35 = NULL ;
const T_1 * V_36 = NULL ;
int V_37 = 0 ;
int V_2 = 0 ;
if ( V_1 -> V_38 != V_13 -> V_38 ) {
F_3 ( V_39 , V_40 ) ;
return 0 ;
}
if ( ( V_14 == NULL ) && ( V_15 == 0 ) ) {
return F_14 ( V_1 , V_13 ) ;
}
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ ) {
if ( V_1 -> V_38 != V_11 [ V_10 ] -> V_38 ) {
F_3 ( V_39 , V_40 ) ;
return 0 ;
}
}
if ( V_17 == NULL ) {
V_17 = V_18 = F_15 () ;
if ( V_17 == NULL )
goto V_41;
}
if ( V_14 != NULL ) {
V_19 = F_16 ( V_1 ) ;
if ( V_19 == NULL ) {
F_3 ( V_39 , V_42 ) ;
goto V_41;
}
V_36 = V_1 -> V_36 . V_43 ;
if ( V_36 && V_36 -> V_22
&& ( F_17 ( V_1 , V_19 , V_36 -> V_11 [ 0 ] , V_17 ) ==
0 ) ) {
V_5 = V_36 -> V_5 ;
V_22 = ( F_18 ( V_14 ) / V_5 ) + 1 ;
if ( V_22 > V_36 -> V_22 )
V_22 = V_36 -> V_22 ;
V_23 = ( T_5 ) 1 << ( V_36 -> V_6 - 1 ) ;
if ( V_36 -> V_15 != ( V_36 -> V_22 * V_23 ) ) {
F_3 ( V_39 , V_44 ) ;
goto V_41;
}
} else {
V_36 = NULL ;
V_22 = 1 ;
V_37 = 1 ;
}
}
V_21 = V_15 + V_22 ;
V_28 = F_19 ( V_21 * sizeof V_28 [ 0 ] ) ;
V_30 = F_19 ( V_21 * sizeof V_30 [ 0 ] ) ;
V_29 = F_19 ( ( V_21 + 1 ) * sizeof V_29 [ 0 ] ) ;
V_35 = F_19 ( V_21 * sizeof V_35 [ 0 ] ) ;
if ( V_29 != NULL )
V_29 [ 0 ] = NULL ;
if ( V_28 == NULL || V_30 == NULL || V_29 == NULL || V_35 == NULL ) {
F_3 ( V_39 , V_4 ) ;
goto V_41;
}
V_32 = 0 ;
for ( V_10 = 0 ; V_10 < V_15 + V_37 ; V_10 ++ ) {
T_5 V_45 ;
V_45 = V_10 < V_15 ? F_18 ( V_16 [ V_10 ] ) : F_18 ( V_14 ) ;
V_28 [ V_10 ] = F_20 ( V_45 ) ;
V_32 += ( T_5 ) 1 << ( V_28 [ V_10 ] - 1 ) ;
V_29 [ V_10 + 1 ] = NULL ;
V_29 [ V_10 ] =
F_21 ( ( V_10 < V_15 ? V_16 [ V_10 ] : V_14 ) , V_28 [ V_10 ] ,
& V_30 [ V_10 ] ) ;
if ( V_29 [ V_10 ] == NULL )
goto V_41;
if ( V_30 [ V_10 ] > V_31 )
V_31 = V_30 [ V_10 ] ;
}
if ( V_22 ) {
if ( V_36 == NULL ) {
if ( V_37 != 1 ) {
F_3 ( V_39 , V_44 ) ;
goto V_41;
}
} else {
signed char * V_46 = NULL ;
T_5 V_47 = 0 ;
if ( V_37 != 0 ) {
F_3 ( V_39 , V_44 ) ;
goto V_41;
}
V_28 [ V_15 ] = V_36 -> V_6 ;
V_46 = F_21 ( V_14 , V_28 [ V_15 ] , & V_47 ) ;
if ( ! V_46 )
goto V_41;
if ( V_47 <= V_31 ) {
V_22 = 1 ;
V_21 = V_15 + 1 ;
V_29 [ V_15 ] = V_46 ;
V_29 [ V_15 + 1 ] = NULL ;
V_30 [ V_15 ] = V_47 ;
V_35 [ V_15 ] = V_36 -> V_11 ;
} else {
signed char * V_48 ;
T_3 * * V_49 ;
if ( V_47 < V_22 * V_5 ) {
V_22 = ( V_47 + V_5 - 1 ) / V_5 ;
if ( V_22 > V_36 -> V_22 ) {
F_3 ( V_39 , V_44 ) ;
F_5 ( V_46 ) ;
goto V_41;
}
V_21 = V_15 + V_22 ;
}
V_48 = V_46 ;
V_49 = V_36 -> V_11 ;
for ( V_10 = V_15 ; V_10 < V_21 ; V_10 ++ ) {
if ( V_10 < V_21 - 1 ) {
V_30 [ V_10 ] = V_5 ;
if ( V_47 < V_5 ) {
F_3 ( V_39 , V_44 ) ;
F_5 ( V_46 ) ;
goto V_41;
}
V_47 -= V_5 ;
} else
V_30 [ V_10 ] = V_47 ;
V_29 [ V_10 + 1 ] = NULL ;
V_29 [ V_10 ] = F_19 ( V_30 [ V_10 ] ) ;
if ( V_29 [ V_10 ] == NULL ) {
F_3 ( V_39 , V_4 ) ;
F_5 ( V_46 ) ;
goto V_41;
}
memcpy ( V_29 [ V_10 ] , V_48 , V_30 [ V_10 ] ) ;
if ( V_30 [ V_10 ] > V_31 )
V_31 = V_30 [ V_10 ] ;
if ( * V_49 == NULL ) {
F_3 ( V_39 , V_44 ) ;
F_5 ( V_46 ) ;
goto V_41;
}
V_35 [ V_10 ] = V_49 ;
V_49 += V_23 ;
V_48 += V_5 ;
}
F_5 ( V_46 ) ;
}
}
}
V_33 = F_19 ( ( V_32 + 1 ) * sizeof V_33 [ 0 ] ) ;
if ( V_33 == NULL ) {
F_3 ( V_39 , V_4 ) ;
goto V_41;
}
V_33 [ V_32 ] = NULL ;
V_34 = V_33 ;
for ( V_10 = 0 ; V_10 < V_15 + V_37 ; V_10 ++ ) {
V_35 [ V_10 ] = V_34 ;
for ( V_24 = 0 ; V_24 < ( ( T_5 ) 1 << ( V_28 [ V_10 ] - 1 ) ) ; V_24 ++ ) {
* V_34 = F_22 ( V_1 ) ;
if ( * V_34 == NULL )
goto V_41;
V_34 ++ ;
}
}
if ( ! ( V_34 == V_33 + V_32 ) ) {
F_3 ( V_39 , V_44 ) ;
goto V_41;
}
if ( ( V_20 = F_22 ( V_1 ) ) == NULL )
goto V_41;
for ( V_10 = 0 ; V_10 < V_15 + V_37 ; V_10 ++ ) {
if ( V_10 < V_15 ) {
if ( ! F_23 ( V_35 [ V_10 ] [ 0 ] , V_11 [ V_10 ] ) )
goto V_41;
} else {
if ( ! F_23 ( V_35 [ V_10 ] [ 0 ] , V_19 ) )
goto V_41;
}
if ( V_28 [ V_10 ] > 1 ) {
if ( ! F_24 ( V_1 , V_20 , V_35 [ V_10 ] [ 0 ] , V_17 ) )
goto V_41;
for ( V_24 = 1 ; V_24 < ( ( T_5 ) 1 << ( V_28 [ V_10 ] - 1 ) ) ; V_24 ++ ) {
if ( ! F_25
( V_1 , V_35 [ V_10 ] [ V_24 ] , V_35 [ V_10 ] [ V_24 - 1 ] , V_20 , V_17 ) )
goto V_41;
}
}
}
if ( ! F_26 ( V_1 , V_32 , V_33 , V_17 ) )
goto V_41;
V_27 = 1 ;
for ( V_25 = V_31 - 1 ; V_25 >= 0 ; V_25 -- ) {
if ( ! V_27 ) {
if ( ! F_24 ( V_1 , V_13 , V_13 , V_17 ) )
goto V_41;
}
for ( V_10 = 0 ; V_10 < V_21 ; V_10 ++ ) {
if ( V_30 [ V_10 ] > ( T_5 ) V_25 ) {
int V_50 = V_29 [ V_10 ] [ V_25 ] ;
int V_51 ;
if ( V_50 ) {
V_51 = V_50 < 0 ;
if ( V_51 )
V_50 = - V_50 ;
if ( V_51 != V_26 ) {
if ( ! V_27 ) {
if ( ! F_27 ( V_1 , V_13 , V_17 ) )
goto V_41;
}
V_26 = ! V_26 ;
}
if ( V_27 ) {
if ( ! F_23 ( V_13 , V_35 [ V_10 ] [ V_50 >> 1 ] ) )
goto V_41;
V_27 = 0 ;
} else {
if ( ! F_25
( V_1 , V_13 , V_13 , V_35 [ V_10 ] [ V_50 >> 1 ] , V_17 ) )
goto V_41;
}
}
}
}
}
if ( V_27 ) {
if ( ! F_14 ( V_1 , V_13 ) )
goto V_41;
} else {
if ( V_26 )
if ( ! F_27 ( V_1 , V_13 , V_17 ) )
goto V_41;
}
V_2 = 1 ;
V_41:
F_28 ( V_18 ) ;
F_11 ( V_20 ) ;
F_5 ( V_28 ) ;
F_5 ( V_30 ) ;
if ( V_29 != NULL ) {
signed char * * V_6 ;
for ( V_6 = V_29 ; * V_6 != NULL ; V_6 ++ )
F_5 ( * V_6 ) ;
F_5 ( V_29 ) ;
}
if ( V_33 != NULL ) {
for ( V_34 = V_33 ; * V_34 != NULL ; V_34 ++ )
F_29 ( * V_34 ) ;
F_5 ( V_33 ) ;
}
F_5 ( V_35 ) ;
return V_2 ;
}
int F_30 ( T_2 * V_1 , T_6 * V_17 )
{
const T_3 * V_19 ;
T_3 * V_52 = NULL , * V_53 = NULL , * * V_54 ;
T_6 * V_18 = NULL ;
const T_4 * V_55 ;
T_5 V_10 , V_45 , V_6 , V_23 , V_5 , V_22 , V_15 ;
T_3 * * V_11 = NULL ;
T_1 * V_36 ;
int V_2 = 0 ;
F_31 ( V_1 ) ;
if ( ( V_36 = F_1 ( V_1 ) ) == NULL )
return 0 ;
V_19 = F_16 ( V_1 ) ;
if ( V_19 == NULL ) {
F_3 ( V_56 , V_42 ) ;
goto V_41;
}
if ( V_17 == NULL ) {
V_17 = V_18 = F_15 () ;
if ( V_17 == NULL )
goto V_41;
}
F_32 ( V_17 ) ;
V_55 = F_33 ( V_1 ) ;
if ( V_55 == NULL )
goto V_41;
if ( F_34 ( V_55 ) ) {
F_3 ( V_56 , V_57 ) ;
goto V_41;
}
V_45 = F_18 ( V_55 ) ;
V_5 = 8 ;
V_6 = 4 ;
if ( F_20 ( V_45 ) > V_6 ) {
V_6 = F_20 ( V_45 ) ;
}
V_22 = ( V_45 + V_5 - 1 ) / V_5 ;
V_23 = ( T_5 ) 1 << ( V_6 - 1 ) ;
V_15 = V_23 * V_22 ;
V_11 = F_19 ( sizeof( * V_11 ) * ( V_15 + 1 ) ) ;
if ( V_11 == NULL ) {
F_3 ( V_56 , V_4 ) ;
goto V_41;
}
V_54 = V_11 ;
V_54 [ V_15 ] = NULL ;
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ ) {
if ( ( V_54 [ V_10 ] = F_22 ( V_1 ) ) == NULL ) {
F_3 ( V_56 , V_4 ) ;
goto V_41;
}
}
if ( ( V_52 = F_22 ( V_1 ) ) == NULL
|| ( V_53 = F_22 ( V_1 ) ) == NULL ) {
F_3 ( V_56 , V_4 ) ;
goto V_41;
}
if ( ! F_23 ( V_53 , V_19 ) )
goto V_41;
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ ) {
T_5 V_24 ;
if ( ! F_24 ( V_1 , V_52 , V_53 , V_17 ) )
goto V_41;
if ( ! F_23 ( * V_54 ++ , V_53 ) )
goto V_41;
for ( V_24 = 1 ; V_24 < V_23 ; V_24 ++ , V_54 ++ ) {
if ( ! F_25 ( V_1 , * V_54 , V_52 , * ( V_54 - 1 ) , V_17 ) )
goto V_41;
}
if ( V_10 < V_22 - 1 ) {
T_5 V_25 ;
if ( V_5 <= 2 ) {
F_3 ( V_56 , V_44 ) ;
goto V_41;
}
if ( ! F_24 ( V_1 , V_53 , V_52 , V_17 ) )
goto V_41;
for ( V_25 = 2 ; V_25 < V_5 ; V_25 ++ ) {
if ( ! F_24 ( V_1 , V_53 , V_53 , V_17 ) )
goto V_41;
}
}
}
if ( ! F_26 ( V_1 , V_15 , V_11 , V_17 ) )
goto V_41;
V_36 -> V_1 = V_1 ;
V_36 -> V_5 = V_5 ;
V_36 -> V_22 = V_22 ;
V_36 -> V_6 = V_6 ;
V_36 -> V_11 = V_11 ;
V_11 = NULL ;
V_36 -> V_15 = V_15 ;
F_35 ( V_1 , V_43 , V_36 ) ;
V_36 = NULL ;
V_2 = 1 ;
V_41:
if ( V_17 != NULL )
F_36 ( V_17 ) ;
F_28 ( V_18 ) ;
F_8 ( V_36 ) ;
if ( V_11 ) {
T_3 * * V_58 ;
for ( V_58 = V_11 ; * V_58 != NULL ; V_58 ++ )
F_11 ( * V_58 ) ;
F_5 ( V_11 ) ;
}
F_11 ( V_52 ) ;
F_11 ( V_53 ) ;
return V_2 ;
}
int F_37 ( const T_2 * V_1 )
{
return F_38 ( V_1 , V_43 ) ;
}
