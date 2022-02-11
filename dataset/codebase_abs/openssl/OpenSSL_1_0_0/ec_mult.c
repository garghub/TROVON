static T_1 * F_1 ( const T_2 * V_1 )
{
T_1 * V_2 = NULL ;
if ( ! V_1 )
return NULL ;
V_2 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( ! V_2 )
{
F_3 ( V_3 , V_4 ) ;
return V_2 ;
}
V_2 -> V_1 = V_1 ;
V_2 -> V_5 = 8 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 4 ;
V_2 -> V_8 = NULL ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 1 ;
return V_2 ;
}
static void * F_4 ( void * V_11 )
{
T_1 * V_12 = V_11 ;
F_5 ( & V_12 -> V_10 , 1 , V_13 ) ;
return V_11 ;
}
static void F_6 ( void * V_14 )
{
int V_15 ;
T_1 * V_16 = V_14 ;
if ( ! V_16 )
return;
V_15 = F_5 ( & V_16 -> V_10 , - 1 , V_13 ) ;
if ( V_15 > 0 )
return;
if ( V_16 -> V_8 )
{
T_3 * * V_17 ;
for ( V_17 = V_16 -> V_8 ; * V_17 != NULL ; V_17 ++ )
F_7 ( * V_17 ) ;
F_8 ( V_16 -> V_8 ) ;
}
F_8 ( V_16 ) ;
}
static void F_9 ( void * V_14 )
{
int V_15 ;
T_1 * V_16 = V_14 ;
if ( ! V_16 )
return;
V_15 = F_5 ( & V_16 -> V_10 , - 1 , V_13 ) ;
if ( V_15 > 0 )
return;
if ( V_16 -> V_8 )
{
T_3 * * V_17 ;
for ( V_17 = V_16 -> V_8 ; * V_17 != NULL ; V_17 ++ )
F_10 ( * V_17 ) ;
F_11 ( V_16 -> V_8 , sizeof V_16 -> V_8 ) ;
F_8 ( V_16 -> V_8 ) ;
}
F_11 ( V_16 , sizeof V_16 ) ;
F_8 ( V_16 ) ;
}
static signed char * F_12 ( const T_4 * V_18 , int V_7 , T_5 * V_19 )
{
int V_20 ;
int V_21 = 0 ;
signed char * V_22 = NULL ;
int V_23 = 1 ;
int V_24 , V_25 , V_26 ;
T_5 V_27 = 0 , V_28 ;
if ( F_13 ( V_18 ) )
{
V_22 = F_2 ( 1 ) ;
if ( ! V_22 )
{
F_3 ( V_29 , V_4 ) ;
goto V_30;
}
V_22 [ 0 ] = 0 ;
* V_19 = 1 ;
return V_22 ;
}
if ( V_7 <= 0 || V_7 > 7 )
{
F_3 ( V_29 , V_31 ) ;
goto V_30;
}
V_24 = 1 << V_7 ;
V_25 = V_24 << 1 ;
V_26 = V_25 - 1 ;
if ( F_14 ( V_18 ) )
{
V_23 = - 1 ;
}
if ( V_18 -> V_32 == NULL || V_18 -> V_33 == 0 )
{
F_3 ( V_29 , V_31 ) ;
goto V_30;
}
V_27 = F_15 ( V_18 ) ;
V_22 = F_2 ( V_27 + 1 ) ;
if ( V_22 == NULL )
{
F_3 ( V_29 , V_4 ) ;
goto V_30;
}
V_20 = V_18 -> V_32 [ 0 ] & V_26 ;
V_28 = 0 ;
while ( ( V_20 != 0 ) || ( V_28 + V_7 + 1 < V_27 ) )
{
int V_34 = 0 ;
if ( V_20 & 1 )
{
if ( V_20 & V_24 )
{
V_34 = V_20 - V_25 ;
#if 1
if ( V_28 + V_7 + 1 >= V_27 )
{
V_34 = V_20 & ( V_26 >> 1 ) ;
}
#endif
}
else
{
V_34 = V_20 ;
}
if ( V_34 <= - V_24 || V_34 >= V_24 || ! ( V_34 & 1 ) )
{
F_3 ( V_29 , V_31 ) ;
goto V_30;
}
V_20 -= V_34 ;
if ( V_20 != 0 && V_20 != V_25 && V_20 != V_24 )
{
F_3 ( V_29 , V_31 ) ;
goto V_30;
}
}
V_22 [ V_28 ++ ] = V_23 * V_34 ;
V_20 >>= 1 ;
V_20 += V_24 * F_16 ( V_18 , V_28 + V_7 ) ;
if ( V_20 > V_25 )
{
F_3 ( V_29 , V_31 ) ;
goto V_30;
}
}
if ( V_28 > V_27 + 1 )
{
F_3 ( V_29 , V_31 ) ;
goto V_30;
}
V_27 = V_28 ;
V_21 = 1 ;
V_30:
if ( ! V_21 )
{
F_8 ( V_22 ) ;
V_22 = NULL ;
}
if ( V_21 )
* V_19 = V_27 ;
return V_22 ;
}
int F_17 ( const T_2 * V_1 , T_3 * V_22 , const T_4 * V_18 ,
T_5 V_9 , const T_3 * V_8 [] , const T_4 * V_35 [] , T_6 * V_36 )
{
T_6 * V_37 = NULL ;
const T_3 * V_38 = NULL ;
T_3 * V_39 = NULL ;
T_5 V_40 ;
T_5 V_5 = 0 , V_6 = 0 ;
T_5 V_41 = 0 ;
T_5 V_15 , V_28 ;
int V_42 ;
int V_43 = 0 ;
int V_44 = 1 ;
T_5 * V_45 = NULL ;
signed char * * V_46 = NULL ;
T_5 * V_47 = NULL ;
T_5 V_48 = 0 ;
T_5 V_49 ;
T_3 * * V_50 = NULL ;
T_3 * * V_51 ;
T_3 * * * V_52 = NULL ;
const T_1 * V_53 = NULL ;
int V_54 = 0 ;
int V_2 = 0 ;
if ( V_1 -> V_55 != V_22 -> V_55 )
{
F_3 ( V_56 , V_57 ) ;
return 0 ;
}
if ( ( V_18 == NULL ) && ( V_9 == 0 ) )
{
return F_18 ( V_1 , V_22 ) ;
}
for ( V_15 = 0 ; V_15 < V_9 ; V_15 ++ )
{
if ( V_1 -> V_55 != V_8 [ V_15 ] -> V_55 )
{
F_3 ( V_56 , V_57 ) ;
return 0 ;
}
}
if ( V_36 == NULL )
{
V_36 = V_37 = F_19 () ;
if ( V_36 == NULL )
goto V_30;
}
if ( V_18 != NULL )
{
V_38 = F_20 ( V_1 ) ;
if ( V_38 == NULL )
{
F_3 ( V_56 , V_58 ) ;
goto V_30;
}
V_53 = F_21 ( V_1 -> V_59 , F_4 , F_6 , F_9 ) ;
if ( V_53 && V_53 -> V_6 && ( F_22 ( V_1 , V_38 , V_53 -> V_8 [ 0 ] , V_36 ) == 0 ) )
{
V_5 = V_53 -> V_5 ;
V_6 = ( F_15 ( V_18 ) / V_5 ) + 1 ;
if ( V_6 > V_53 -> V_6 )
V_6 = V_53 -> V_6 ;
V_41 = ( T_5 ) 1 << ( V_53 -> V_7 - 1 ) ;
if ( V_53 -> V_9 != ( V_53 -> V_6 * V_41 ) )
{
F_3 ( V_56 , V_31 ) ;
goto V_30;
}
}
else
{
V_53 = NULL ;
V_6 = 1 ;
V_54 = 1 ;
}
}
V_40 = V_9 + V_6 ;
V_45 = F_2 ( V_40 * sizeof V_45 [ 0 ] ) ;
V_47 = F_2 ( V_40 * sizeof V_47 [ 0 ] ) ;
V_46 = F_2 ( ( V_40 + 1 ) * sizeof V_46 [ 0 ] ) ;
V_52 = F_2 ( V_40 * sizeof V_52 [ 0 ] ) ;
if ( ! V_45 || ! V_47 || ! V_46 || ! V_52 )
{
F_3 ( V_56 , V_4 ) ;
goto V_30;
}
V_46 [ 0 ] = NULL ;
V_49 = 0 ;
for ( V_15 = 0 ; V_15 < V_9 + V_54 ; V_15 ++ )
{
T_5 V_60 ;
V_60 = V_15 < V_9 ? F_15 ( V_35 [ V_15 ] ) : F_15 ( V_18 ) ;
V_45 [ V_15 ] = F_23 ( V_60 ) ;
V_49 += ( T_5 ) 1 << ( V_45 [ V_15 ] - 1 ) ;
V_46 [ V_15 + 1 ] = NULL ;
V_46 [ V_15 ] = F_12 ( ( V_15 < V_9 ? V_35 [ V_15 ] : V_18 ) , V_45 [ V_15 ] , & V_47 [ V_15 ] ) ;
if ( V_46 [ V_15 ] == NULL )
goto V_30;
if ( V_47 [ V_15 ] > V_48 )
V_48 = V_47 [ V_15 ] ;
}
if ( V_6 )
{
if ( V_53 == NULL )
{
if ( V_54 != 1 )
{
F_3 ( V_56 , V_31 ) ;
goto V_30;
}
}
else
{
signed char * V_61 = NULL ;
T_5 V_62 = 0 ;
if ( V_54 != 0 )
{
F_3 ( V_56 , V_31 ) ;
goto V_30;
}
V_45 [ V_9 ] = V_53 -> V_7 ;
V_61 = F_12 ( V_18 , V_45 [ V_9 ] , & V_62 ) ;
if ( ! V_61 )
goto V_30;
if ( V_62 <= V_48 )
{
V_6 = 1 ;
V_40 = V_9 + 1 ;
V_46 [ V_9 ] = V_61 ;
V_46 [ V_9 + 1 ] = NULL ;
V_47 [ V_9 ] = V_62 ;
if ( V_62 > V_48 )
V_48 = V_62 ;
V_52 [ V_9 ] = V_53 -> V_8 ;
}
else
{
signed char * V_63 ;
T_3 * * V_64 ;
if ( V_62 < V_6 * V_5 )
{
V_6 = ( V_62 + V_5 - 1 ) / V_5 ;
if ( V_6 > V_53 -> V_6 )
{
F_3 ( V_56 , V_31 ) ;
goto V_30;
}
V_40 = V_9 + V_6 ;
}
V_63 = V_61 ;
V_64 = V_53 -> V_8 ;
for ( V_15 = V_9 ; V_15 < V_40 ; V_15 ++ )
{
if ( V_15 < V_40 - 1 )
{
V_47 [ V_15 ] = V_5 ;
if ( V_62 < V_5 )
{
F_3 ( V_56 , V_31 ) ;
goto V_30;
}
V_62 -= V_5 ;
}
else
V_47 [ V_15 ] = V_62 ;
V_46 [ V_15 + 1 ] = NULL ;
V_46 [ V_15 ] = F_2 ( V_47 [ V_15 ] ) ;
if ( V_46 [ V_15 ] == NULL )
{
F_3 ( V_56 , V_4 ) ;
F_8 ( V_61 ) ;
goto V_30;
}
memcpy ( V_46 [ V_15 ] , V_63 , V_47 [ V_15 ] ) ;
if ( V_47 [ V_15 ] > V_48 )
V_48 = V_47 [ V_15 ] ;
if ( * V_64 == NULL )
{
F_3 ( V_56 , V_31 ) ;
F_8 ( V_61 ) ;
goto V_30;
}
V_52 [ V_15 ] = V_64 ;
V_64 += V_41 ;
V_63 += V_5 ;
}
F_8 ( V_61 ) ;
}
}
}
V_50 = F_2 ( ( V_49 + 1 ) * sizeof V_50 [ 0 ] ) ;
if ( V_50 == NULL )
{
F_3 ( V_56 , V_4 ) ;
goto V_30;
}
V_50 [ V_49 ] = NULL ;
V_51 = V_50 ;
for ( V_15 = 0 ; V_15 < V_9 + V_54 ; V_15 ++ )
{
V_52 [ V_15 ] = V_51 ;
for ( V_28 = 0 ; V_28 < ( ( T_5 ) 1 << ( V_45 [ V_15 ] - 1 ) ) ; V_28 ++ )
{
* V_51 = F_24 ( V_1 ) ;
if ( * V_51 == NULL ) goto V_30;
V_51 ++ ;
}
}
if ( ! ( V_51 == V_50 + V_49 ) )
{
F_3 ( V_56 , V_31 ) ;
goto V_30;
}
if ( ! ( V_39 = F_24 ( V_1 ) ) )
goto V_30;
for ( V_15 = 0 ; V_15 < V_9 + V_54 ; V_15 ++ )
{
if ( V_15 < V_9 )
{
if ( ! F_25 ( V_52 [ V_15 ] [ 0 ] , V_8 [ V_15 ] ) ) goto V_30;
}
else
{
if ( ! F_25 ( V_52 [ V_15 ] [ 0 ] , V_38 ) ) goto V_30;
}
if ( V_45 [ V_15 ] > 1 )
{
if ( ! F_26 ( V_1 , V_39 , V_52 [ V_15 ] [ 0 ] , V_36 ) ) goto V_30;
for ( V_28 = 1 ; V_28 < ( ( T_5 ) 1 << ( V_45 [ V_15 ] - 1 ) ) ; V_28 ++ )
{
if ( ! F_27 ( V_1 , V_52 [ V_15 ] [ V_28 ] , V_52 [ V_15 ] [ V_28 - 1 ] , V_39 , V_36 ) ) goto V_30;
}
}
}
#if 1
if ( ! F_28 ( V_1 , V_49 , V_50 , V_36 ) )
goto V_30;
#endif
V_44 = 1 ;
for ( V_42 = V_48 - 1 ; V_42 >= 0 ; V_42 -- )
{
if ( ! V_44 )
{
if ( ! F_26 ( V_1 , V_22 , V_22 , V_36 ) ) goto V_30;
}
for ( V_15 = 0 ; V_15 < V_40 ; V_15 ++ )
{
if ( V_47 [ V_15 ] > ( T_5 ) V_42 )
{
int V_34 = V_46 [ V_15 ] [ V_42 ] ;
int V_65 ;
if ( V_34 )
{
V_65 = V_34 < 0 ;
if ( V_65 )
V_34 = - V_34 ;
if ( V_65 != V_43 )
{
if ( ! V_44 )
{
if ( ! F_29 ( V_1 , V_22 , V_36 ) ) goto V_30;
}
V_43 = ! V_43 ;
}
if ( V_44 )
{
if ( ! F_25 ( V_22 , V_52 [ V_15 ] [ V_34 >> 1 ] ) ) goto V_30;
V_44 = 0 ;
}
else
{
if ( ! F_27 ( V_1 , V_22 , V_22 , V_52 [ V_15 ] [ V_34 >> 1 ] , V_36 ) ) goto V_30;
}
}
}
}
}
if ( V_44 )
{
if ( ! F_18 ( V_1 , V_22 ) ) goto V_30;
}
else
{
if ( V_43 )
if ( ! F_29 ( V_1 , V_22 , V_36 ) ) goto V_30;
}
V_2 = 1 ;
V_30:
if ( V_37 != NULL )
F_30 ( V_37 ) ;
if ( V_39 != NULL )
F_7 ( V_39 ) ;
if ( V_45 != NULL )
F_8 ( V_45 ) ;
if ( V_47 != NULL )
F_8 ( V_47 ) ;
if ( V_46 != NULL )
{
signed char * * V_7 ;
for ( V_7 = V_46 ; * V_7 != NULL ; V_7 ++ )
F_8 ( * V_7 ) ;
F_8 ( V_46 ) ;
}
if ( V_50 != NULL )
{
for ( V_51 = V_50 ; * V_51 != NULL ; V_51 ++ )
F_10 ( * V_51 ) ;
F_8 ( V_50 ) ;
}
if ( V_52 != NULL )
{
F_8 ( V_52 ) ;
}
return V_2 ;
}
int F_31 ( T_2 * V_1 , T_6 * V_36 )
{
const T_3 * V_38 ;
T_3 * V_66 = NULL , * V_67 = NULL , * * V_68 ;
T_6 * V_37 = NULL ;
T_4 * V_69 ;
T_5 V_15 , V_60 , V_7 , V_41 , V_5 , V_6 , V_9 ;
T_3 * * V_8 = NULL ;
T_1 * V_53 ;
int V_2 = 0 ;
F_32 ( & V_1 -> V_59 , F_4 , F_6 , F_9 ) ;
if ( ( V_53 = F_1 ( V_1 ) ) == NULL )
return 0 ;
V_38 = F_20 ( V_1 ) ;
if ( V_38 == NULL )
{
F_3 ( V_70 , V_58 ) ;
goto V_30;
}
if ( V_36 == NULL )
{
V_36 = V_37 = F_19 () ;
if ( V_36 == NULL )
goto V_30;
}
F_33 ( V_36 ) ;
V_69 = F_34 ( V_36 ) ;
if ( V_69 == NULL ) goto V_30;
if ( ! F_35 ( V_1 , V_69 , V_36 ) ) goto V_30;
if ( F_13 ( V_69 ) )
{
F_3 ( V_70 , V_71 ) ;
goto V_30;
}
V_60 = F_15 ( V_69 ) ;
V_5 = 8 ;
V_7 = 4 ;
if ( F_23 ( V_60 ) > V_7 )
{
V_7 = F_23 ( V_60 ) ;
}
V_6 = ( V_60 + V_5 - 1 ) / V_5 ;
V_41 = ( T_5 ) 1 << ( V_7 - 1 ) ;
V_9 = V_41 * V_6 ;
V_8 = F_2 ( sizeof ( T_3 * ) * ( V_9 + 1 ) ) ;
if ( ! V_8 )
{
F_3 ( V_70 , V_4 ) ;
goto V_30;
}
V_68 = V_8 ;
V_68 [ V_9 ] = NULL ;
for ( V_15 = 0 ; V_15 < V_9 ; V_15 ++ )
{
if ( ( V_68 [ V_15 ] = F_24 ( V_1 ) ) == NULL )
{
F_3 ( V_70 , V_4 ) ;
goto V_30;
}
}
if ( ! ( V_66 = F_24 ( V_1 ) ) || ! ( V_67 = F_24 ( V_1 ) ) )
{
F_3 ( V_70 , V_4 ) ;
goto V_30;
}
if ( ! F_25 ( V_67 , V_38 ) )
goto V_30;
for ( V_15 = 0 ; V_15 < V_6 ; V_15 ++ )
{
T_5 V_28 ;
if ( ! F_26 ( V_1 , V_66 , V_67 , V_36 ) )
goto V_30;
if ( ! F_25 ( * V_68 ++ , V_67 ) )
goto V_30;
for ( V_28 = 1 ; V_28 < V_41 ; V_28 ++ , V_68 ++ )
{
if ( ! F_27 ( V_1 , * V_68 , V_66 , * ( V_68 - 1 ) , V_36 ) )
goto V_30;
}
if ( V_15 < V_6 - 1 )
{
T_5 V_42 ;
if ( V_5 <= 2 )
{
F_3 ( V_70 , V_31 ) ;
goto V_30;
}
if ( ! F_26 ( V_1 , V_67 , V_66 , V_36 ) )
goto V_30;
for ( V_42 = 2 ; V_42 < V_5 ; V_42 ++ )
{
if ( ! F_26 ( V_1 , V_67 , V_67 , V_36 ) )
goto V_30;
}
}
}
if ( ! F_28 ( V_1 , V_9 , V_8 , V_36 ) )
goto V_30;
V_53 -> V_1 = V_1 ;
V_53 -> V_5 = V_5 ;
V_53 -> V_6 = V_6 ;
V_53 -> V_7 = V_7 ;
V_53 -> V_8 = V_8 ;
V_8 = NULL ;
V_53 -> V_9 = V_9 ;
if ( ! F_36 ( & V_1 -> V_59 , V_53 ,
F_4 , F_6 , F_9 ) )
goto V_30;
V_53 = NULL ;
V_2 = 1 ;
V_30:
if ( V_36 != NULL )
F_37 ( V_36 ) ;
if ( V_37 != NULL )
F_30 ( V_37 ) ;
if ( V_53 )
F_6 ( V_53 ) ;
if ( V_8 )
{
T_3 * * V_17 ;
for ( V_17 = V_8 ; * V_17 != NULL ; V_17 ++ )
F_7 ( * V_17 ) ;
F_8 ( V_8 ) ;
}
if ( V_66 )
F_7 ( V_66 ) ;
if ( V_67 )
F_7 ( V_67 ) ;
return V_2 ;
}
int F_38 ( const T_2 * V_1 )
{
if ( F_21 ( V_1 -> V_59 , F_4 , F_6 , F_9 ) != NULL )
return 1 ;
else
return 0 ;
}
