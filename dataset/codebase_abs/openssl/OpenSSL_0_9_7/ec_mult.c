static signed char * F_1 ( const T_1 * V_1 , int V_2 , T_2 * V_3 , T_3 * V_4 )
{
T_1 * V_5 ;
int V_6 = 0 ;
signed char * V_7 = NULL ;
int V_8 = 1 ;
int V_9 , V_10 , V_11 ;
T_2 V_12 = 0 , V_13 ;
F_2 ( V_4 ) ;
V_5 = F_3 ( V_4 ) ;
if ( V_5 == NULL ) goto V_14;
if ( V_2 <= 0 || V_2 > 7 )
{
F_4 ( V_15 , V_16 ) ;
goto V_14;
}
V_9 = 1 << V_2 ;
V_10 = V_9 << 1 ;
V_11 = V_10 - 1 ;
if ( ! F_5 ( V_5 , V_1 ) ) goto V_14;
if ( V_5 -> V_17 )
{
V_8 = - 1 ;
V_5 -> V_17 = 0 ;
}
V_12 = F_6 ( V_5 ) + 1 ;
V_7 = F_7 ( V_12 ) ;
if ( V_7 == NULL ) goto V_14;
V_13 = 0 ;
while ( ! F_8 ( V_5 ) )
{
int V_18 = 0 ;
if ( F_9 ( V_5 ) )
{
if ( V_5 -> V_19 == NULL || V_5 -> V_20 == 0 )
{
F_4 ( V_15 , V_16 ) ;
goto V_14;
}
V_18 = V_5 -> V_19 [ 0 ] & V_11 ;
if ( V_18 & V_9 )
{
V_18 -= V_10 ;
if ( ! F_10 ( V_5 , - V_18 ) ) goto V_14;
}
else
{
if ( ! F_11 ( V_5 , V_18 ) ) goto V_14;
}
if ( V_18 <= - V_9 || V_18 >= V_9 || ! ( V_18 & 1 ) || V_5 -> V_17 )
{
F_4 ( V_15 , V_16 ) ;
goto V_14;
}
}
V_7 [ V_13 ++ ] = V_8 * V_18 ;
if ( F_9 ( V_5 ) )
{
F_4 ( V_15 , V_16 ) ;
goto V_14;
}
if ( ! F_12 ( V_5 , V_5 ) ) goto V_14;
}
if ( V_13 > V_12 )
{
F_4 ( V_15 , V_16 ) ;
goto V_14;
}
V_12 = V_13 ;
V_6 = 1 ;
V_14:
F_13 ( V_4 ) ;
if ( ! V_6 )
{
F_14 ( V_7 ) ;
V_7 = NULL ;
}
if ( V_6 )
* V_3 = V_12 ;
return V_7 ;
}
int F_15 ( const T_4 * V_21 , T_5 * V_7 , const T_1 * V_1 ,
T_2 V_22 , const T_5 * V_23 [] , const T_1 * V_24 [] , T_3 * V_4 )
{
T_3 * V_25 = NULL ;
T_5 * V_26 = NULL ;
T_5 * V_27 = NULL ;
T_2 V_28 ;
T_2 V_29 , V_13 ;
int V_30 ;
int V_31 = 0 ;
int V_32 = 1 ;
T_2 * V_33 = NULL ;
signed char * * V_34 = NULL ;
T_2 * V_35 = NULL ;
T_2 V_36 = 0 ;
T_2 V_37 ;
T_5 * * V_38 = NULL ;
T_5 * * V_39 ;
T_5 * * * V_40 = NULL ;
int V_41 = 0 ;
if ( V_1 != NULL )
{
V_26 = F_16 ( V_21 ) ;
if ( V_26 == NULL )
{
F_4 ( V_42 , V_43 ) ;
return 0 ;
}
}
for ( V_29 = 0 ; V_29 < V_22 ; V_29 ++ )
{
if ( V_21 -> V_44 != V_23 [ V_29 ] -> V_44 )
{
F_4 ( V_42 , V_45 ) ;
return 0 ;
}
}
V_28 = V_22 + ( V_1 != NULL ) ;
V_33 = F_7 ( V_28 * sizeof V_33 [ 0 ] ) ;
V_35 = F_7 ( V_28 * sizeof V_35 [ 0 ] ) ;
V_34 = F_7 ( ( V_28 + 1 ) * sizeof V_34 [ 0 ] ) ;
if ( V_34 != NULL )
{
V_34 [ 0 ] = NULL ;
}
if ( V_33 == NULL || V_35 == NULL || V_34 == NULL ) goto V_14;
V_37 = 0 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
{
T_2 V_46 ;
V_46 = V_29 < V_22 ? F_6 ( V_24 [ V_29 ] ) : F_6 ( V_1 ) ;
V_33 [ V_29 ] = F_17 ( V_46 ) ;
V_37 += 1u << ( V_33 [ V_29 ] - 1 ) ;
}
V_38 = F_7 ( ( V_37 + 1 ) * sizeof V_38 [ 0 ] ) ;
if ( V_38 == NULL ) goto V_14;
V_38 [ V_37 ] = NULL ;
V_40 = F_7 ( V_28 * sizeof V_40 [ 0 ] ) ;
if ( V_40 == NULL ) goto V_14;
V_39 = V_38 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
{
V_40 [ V_29 ] = V_39 ;
for ( V_13 = 0 ; V_13 < ( 1u << ( V_33 [ V_29 ] - 1 ) ) ; V_13 ++ )
{
* V_39 = F_18 ( V_21 ) ;
if ( * V_39 == NULL ) goto V_14;
V_39 ++ ;
}
}
if ( ! ( V_39 == V_38 + V_37 ) )
{
F_4 ( V_42 , V_16 ) ;
goto V_14;
}
if ( V_4 == NULL )
{
V_4 = V_25 = F_19 () ;
if ( V_4 == NULL )
goto V_14;
}
V_27 = F_18 ( V_21 ) ;
if ( V_27 == NULL ) goto V_14;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
{
if ( V_29 < V_22 )
{
if ( ! F_20 ( V_40 [ V_29 ] [ 0 ] , V_23 [ V_29 ] ) ) goto V_14;
}
else
{
if ( ! F_20 ( V_40 [ V_29 ] [ 0 ] , V_26 ) ) goto V_14;
}
if ( V_33 [ V_29 ] > 1 )
{
if ( ! F_21 ( V_21 , V_27 , V_40 [ V_29 ] [ 0 ] , V_4 ) ) goto V_14;
for ( V_13 = 1 ; V_13 < ( 1u << ( V_33 [ V_29 ] - 1 ) ) ; V_13 ++ )
{
if ( ! F_22 ( V_21 , V_40 [ V_29 ] [ V_13 ] , V_40 [ V_29 ] [ V_13 - 1 ] , V_27 , V_4 ) ) goto V_14;
}
}
V_34 [ V_29 + 1 ] = NULL ;
V_34 [ V_29 ] = F_1 ( ( V_29 < V_22 ? V_24 [ V_29 ] : V_1 ) , V_33 [ V_29 ] , & V_35 [ V_29 ] , V_4 ) ;
if ( V_34 [ V_29 ] == NULL ) goto V_14;
if ( V_35 [ V_29 ] > V_36 )
V_36 = V_35 [ V_29 ] ;
}
#if 1
if ( ! F_23 ( V_21 , V_37 , V_38 , V_4 ) ) goto V_14;
#endif
V_32 = 1 ;
for ( V_30 = V_36 - 1 ; V_30 >= 0 ; V_30 -- )
{
if ( ! V_32 )
{
if ( ! F_21 ( V_21 , V_7 , V_7 , V_4 ) ) goto V_14;
}
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
{
if ( V_35 [ V_29 ] > ( T_2 ) V_30 )
{
int V_47 = V_34 [ V_29 ] [ V_30 ] ;
int V_48 ;
if ( V_47 )
{
V_48 = V_47 < 0 ;
if ( V_48 )
V_47 = - V_47 ;
if ( V_48 != V_31 )
{
if ( ! V_32 )
{
if ( ! F_24 ( V_21 , V_7 , V_4 ) ) goto V_14;
}
V_31 = ! V_31 ;
}
if ( V_32 )
{
if ( ! F_20 ( V_7 , V_40 [ V_29 ] [ V_47 >> 1 ] ) ) goto V_14;
V_32 = 0 ;
}
else
{
if ( ! F_22 ( V_21 , V_7 , V_7 , V_40 [ V_29 ] [ V_47 >> 1 ] , V_4 ) ) goto V_14;
}
}
}
}
}
if ( V_32 )
{
if ( ! F_25 ( V_21 , V_7 ) ) goto V_14;
}
else
{
if ( V_31 )
if ( ! F_24 ( V_21 , V_7 , V_4 ) ) goto V_14;
}
V_41 = 1 ;
V_14:
if ( V_25 != NULL )
F_26 ( V_25 ) ;
if ( V_27 != NULL )
F_27 ( V_27 ) ;
if ( V_33 != NULL )
F_14 ( V_33 ) ;
if ( V_35 != NULL )
F_14 ( V_35 ) ;
if ( V_34 != NULL )
{
signed char * * V_2 ;
for ( V_2 = V_34 ; * V_2 != NULL ; V_2 ++ )
F_14 ( * V_2 ) ;
F_14 ( V_34 ) ;
}
if ( V_38 != NULL )
{
for ( V_39 = V_38 ; * V_39 != NULL ; V_39 ++ )
F_28 ( * V_39 ) ;
F_14 ( V_38 ) ;
}
if ( V_40 != NULL )
{
F_14 ( V_40 ) ;
}
return V_41 ;
}
int F_29 ( const T_4 * V_21 , T_5 * V_7 , const T_1 * V_49 , const T_5 * V_50 , const T_1 * V_51 , T_3 * V_4 )
{
const T_5 * V_23 [ 1 ] ;
const T_1 * V_24 [ 1 ] ;
V_23 [ 0 ] = V_50 ;
V_24 [ 0 ] = V_51 ;
return F_15 ( V_21 , V_7 , V_49 , ( V_50 != NULL && V_51 != NULL ) , V_23 , V_24 , V_4 ) ;
}
int F_30 ( T_4 * V_21 , T_3 * V_4 )
{
const T_5 * V_26 ;
T_3 * V_25 = NULL ;
T_1 * V_52 ;
int V_41 = 0 ;
V_26 = F_16 ( V_21 ) ;
if ( V_26 == NULL )
{
F_4 ( V_53 , V_43 ) ;
return 0 ;
}
if ( V_4 == NULL )
{
V_4 = V_25 = F_19 () ;
if ( V_4 == NULL )
return 0 ;
}
F_2 ( V_4 ) ;
V_52 = F_3 ( V_4 ) ;
if ( V_52 == NULL ) goto V_14;
if ( ! F_31 ( V_21 , V_52 , V_4 ) ) return 0 ;
if ( F_8 ( V_52 ) )
{
F_4 ( V_53 , V_54 ) ;
goto V_14;
}
V_41 = 1 ;
V_14:
F_13 ( V_4 ) ;
if ( V_25 != NULL )
F_26 ( V_25 ) ;
return V_41 ;
}
