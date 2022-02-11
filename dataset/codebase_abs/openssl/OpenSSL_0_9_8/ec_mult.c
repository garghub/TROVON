static T_1 * F_1 ( const T_2 * V_1 )
{
T_1 * V_2 = NULL ;
if ( ! V_1 )
return NULL ;
V_2 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_1 = V_1 ;
V_2 -> V_3 = 8 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 4 ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 1 ;
return V_2 ;
}
static void * F_3 ( void * V_9 )
{
T_1 * V_10 = V_9 ;
F_4 ( & V_10 -> V_8 , 1 , V_11 ) ;
return V_9 ;
}
static void F_5 ( void * V_12 )
{
int V_13 ;
T_1 * V_14 = V_12 ;
if ( ! V_14 )
return;
V_13 = F_4 ( & V_14 -> V_8 , - 1 , V_11 ) ;
if ( V_13 > 0 )
return;
if ( V_14 -> V_6 )
{
T_3 * * V_15 ;
for ( V_15 = V_14 -> V_6 ; * V_15 != NULL ; V_15 ++ )
F_6 ( * V_15 ) ;
F_7 ( V_14 -> V_6 ) ;
}
F_7 ( V_14 ) ;
}
static void F_8 ( void * V_12 )
{
int V_13 ;
T_1 * V_14 = V_12 ;
if ( ! V_14 )
return;
V_13 = F_4 ( & V_14 -> V_8 , - 1 , V_11 ) ;
if ( V_13 > 0 )
return;
if ( V_14 -> V_6 )
{
T_3 * * V_15 ;
for ( V_15 = V_14 -> V_6 ; * V_15 != NULL ; V_15 ++ )
F_9 ( * V_15 ) ;
F_10 ( V_14 -> V_6 , sizeof V_14 -> V_6 ) ;
F_7 ( V_14 -> V_6 ) ;
}
F_10 ( V_14 , sizeof V_14 ) ;
F_7 ( V_14 ) ;
}
static signed char * F_11 ( const T_4 * V_16 , int V_5 , T_5 * V_17 )
{
int V_18 ;
int V_19 = 0 ;
signed char * V_20 = NULL ;
int V_21 = 1 ;
int V_22 , V_23 , V_24 ;
T_5 V_25 = 0 , V_26 ;
if ( V_5 <= 0 || V_5 > 7 )
{
F_12 ( V_27 , V_28 ) ;
goto V_29;
}
V_22 = 1 << V_5 ;
V_23 = V_22 << 1 ;
V_24 = V_23 - 1 ;
if ( F_13 ( V_16 ) )
{
V_21 = - 1 ;
}
V_25 = F_14 ( V_16 ) ;
V_20 = F_2 ( V_25 + 1 ) ;
if ( V_20 == NULL ) goto V_29;
if ( V_16 -> V_30 == NULL || V_16 -> V_31 == 0 )
{
F_12 ( V_27 , V_28 ) ;
goto V_29;
}
V_18 = V_16 -> V_30 [ 0 ] & V_24 ;
V_26 = 0 ;
while ( ( V_18 != 0 ) || ( V_26 + V_5 + 1 < V_25 ) )
{
int V_32 = 0 ;
if ( V_18 & 1 )
{
if ( V_18 & V_22 )
{
V_32 = V_18 - V_23 ;
#if 1
if ( V_26 + V_5 + 1 >= V_25 )
{
V_32 = V_18 & ( V_24 >> 1 ) ;
}
#endif
}
else
{
V_32 = V_18 ;
}
if ( V_32 <= - V_22 || V_32 >= V_22 || ! ( V_32 & 1 ) )
{
F_12 ( V_27 , V_28 ) ;
goto V_29;
}
V_18 -= V_32 ;
if ( V_18 != 0 && V_18 != V_23 && V_18 != V_22 )
{
F_12 ( V_27 , V_28 ) ;
goto V_29;
}
}
V_20 [ V_26 ++ ] = V_21 * V_32 ;
V_18 >>= 1 ;
V_18 += V_22 * F_15 ( V_16 , V_26 + V_5 ) ;
if ( V_18 > V_23 )
{
F_12 ( V_27 , V_28 ) ;
goto V_29;
}
}
if ( V_26 > V_25 + 1 )
{
F_12 ( V_27 , V_28 ) ;
goto V_29;
}
V_25 = V_26 ;
V_19 = 1 ;
V_29:
if ( ! V_19 )
{
F_7 ( V_20 ) ;
V_20 = NULL ;
}
if ( V_19 )
* V_17 = V_25 ;
return V_20 ;
}
int F_16 ( const T_2 * V_1 , T_3 * V_20 , const T_4 * V_16 ,
T_5 V_7 , const T_3 * V_6 [] , const T_4 * V_33 [] , T_6 * V_34 )
{
T_6 * V_35 = NULL ;
const T_3 * V_36 = NULL ;
T_3 * V_37 = NULL ;
T_5 V_38 ;
T_5 V_3 = 0 , V_4 = 0 ;
T_5 V_39 = 0 ;
T_5 V_13 , V_26 ;
int V_40 ;
int V_41 = 0 ;
int V_42 = 1 ;
T_5 * V_43 = NULL ;
signed char * * V_44 = NULL ;
T_5 * V_45 = NULL ;
T_5 V_46 = 0 ;
T_5 V_47 ;
T_3 * * V_48 = NULL ;
T_3 * * V_49 ;
T_3 * * * V_50 = NULL ;
const T_1 * V_51 = NULL ;
int V_52 = 0 ;
int V_2 = 0 ;
if ( V_1 -> V_53 != V_20 -> V_53 )
{
F_12 ( V_54 , V_55 ) ;
return 0 ;
}
if ( ( V_16 == NULL ) && ( V_7 == 0 ) )
{
return F_17 ( V_1 , V_20 ) ;
}
for ( V_13 = 0 ; V_13 < V_7 ; V_13 ++ )
{
if ( V_1 -> V_53 != V_6 [ V_13 ] -> V_53 )
{
F_12 ( V_54 , V_55 ) ;
return 0 ;
}
}
if ( V_34 == NULL )
{
V_34 = V_35 = F_18 () ;
if ( V_34 == NULL )
goto V_29;
}
if ( V_16 != NULL )
{
V_36 = F_19 ( V_1 ) ;
if ( V_36 == NULL )
{
F_12 ( V_54 , V_56 ) ;
goto V_29;
}
V_51 = F_20 ( V_1 -> V_57 , F_3 , F_5 , F_8 ) ;
if ( V_51 && V_51 -> V_4 && ( F_21 ( V_1 , V_36 , V_51 -> V_6 [ 0 ] , V_34 ) == 0 ) )
{
V_3 = V_51 -> V_3 ;
V_4 = ( F_14 ( V_16 ) / V_3 ) + 1 ;
if ( V_4 > V_51 -> V_4 )
V_4 = V_51 -> V_4 ;
V_39 = 1u << ( V_51 -> V_5 - 1 ) ;
if ( V_51 -> V_7 != ( V_51 -> V_4 * V_39 ) )
{
F_12 ( V_54 , V_28 ) ;
goto V_29;
}
}
else
{
V_51 = NULL ;
V_4 = 1 ;
V_52 = 1 ;
}
}
V_38 = V_7 + V_4 ;
V_43 = F_2 ( V_38 * sizeof V_43 [ 0 ] ) ;
V_45 = F_2 ( V_38 * sizeof V_45 [ 0 ] ) ;
V_44 = F_2 ( ( V_38 + 1 ) * sizeof V_44 [ 0 ] ) ;
V_50 = F_2 ( V_38 * sizeof V_50 [ 0 ] ) ;
if ( ! V_43 || ! V_45 || ! V_44 || ! V_50 )
goto V_29;
V_44 [ 0 ] = NULL ;
V_47 = 0 ;
for ( V_13 = 0 ; V_13 < V_7 + V_52 ; V_13 ++ )
{
T_5 V_58 ;
V_58 = V_13 < V_7 ? F_14 ( V_33 [ V_13 ] ) : F_14 ( V_16 ) ;
V_43 [ V_13 ] = F_22 ( V_58 ) ;
V_47 += 1u << ( V_43 [ V_13 ] - 1 ) ;
V_44 [ V_13 + 1 ] = NULL ;
V_44 [ V_13 ] = F_11 ( ( V_13 < V_7 ? V_33 [ V_13 ] : V_16 ) , V_43 [ V_13 ] , & V_45 [ V_13 ] ) ;
if ( V_44 [ V_13 ] == NULL )
goto V_29;
if ( V_45 [ V_13 ] > V_46 )
V_46 = V_45 [ V_13 ] ;
}
if ( V_4 )
{
if ( V_51 == NULL )
{
if ( V_52 != 1 )
{
F_12 ( V_54 , V_28 ) ;
goto V_29;
}
}
else
{
signed char * V_59 = NULL ;
T_5 V_60 = 0 ;
if ( V_52 != 0 )
{
F_12 ( V_54 , V_28 ) ;
goto V_29;
}
V_43 [ V_7 ] = V_51 -> V_5 ;
V_59 = F_11 ( V_16 , V_43 [ V_7 ] , & V_60 ) ;
if ( ! V_59 )
goto V_29;
if ( V_60 <= V_46 )
{
V_4 = 1 ;
V_38 = V_7 + 1 ;
V_44 [ V_7 ] = V_59 ;
V_44 [ V_7 + 1 ] = NULL ;
V_45 [ V_7 ] = V_60 ;
if ( V_60 > V_46 )
V_46 = V_60 ;
V_50 [ V_7 ] = V_51 -> V_6 ;
}
else
{
signed char * V_61 ;
T_3 * * V_62 ;
if ( V_60 < V_4 * V_3 )
{
V_4 = ( V_60 + V_3 - 1 ) / V_3 ;
if ( V_4 > V_51 -> V_4 )
{
F_12 ( V_54 , V_28 ) ;
goto V_29;
}
V_38 = V_7 + V_4 ;
}
V_61 = V_59 ;
V_62 = V_51 -> V_6 ;
for ( V_13 = V_7 ; V_13 < V_38 ; V_13 ++ )
{
if ( V_13 < V_38 - 1 )
{
V_45 [ V_13 ] = V_3 ;
if ( V_60 < V_3 )
{
F_12 ( V_54 , V_28 ) ;
goto V_29;
}
V_60 -= V_3 ;
}
else
V_45 [ V_13 ] = V_60 ;
V_44 [ V_13 + 1 ] = NULL ;
V_44 [ V_13 ] = F_2 ( V_45 [ V_13 ] ) ;
if ( V_44 [ V_13 ] == NULL )
{
F_7 ( V_59 ) ;
goto V_29;
}
memcpy ( V_44 [ V_13 ] , V_61 , V_45 [ V_13 ] ) ;
if ( V_45 [ V_13 ] > V_46 )
V_46 = V_45 [ V_13 ] ;
if ( * V_62 == NULL )
{
F_12 ( V_54 , V_28 ) ;
F_7 ( V_59 ) ;
goto V_29;
}
V_50 [ V_13 ] = V_62 ;
V_62 += V_39 ;
V_61 += V_3 ;
}
F_7 ( V_59 ) ;
}
}
}
V_48 = F_2 ( ( V_47 + 1 ) * sizeof V_48 [ 0 ] ) ;
if ( V_48 == NULL ) goto V_29;
V_48 [ V_47 ] = NULL ;
V_49 = V_48 ;
for ( V_13 = 0 ; V_13 < V_7 + V_52 ; V_13 ++ )
{
V_50 [ V_13 ] = V_49 ;
for ( V_26 = 0 ; V_26 < ( 1u << ( V_43 [ V_13 ] - 1 ) ) ; V_26 ++ )
{
* V_49 = F_23 ( V_1 ) ;
if ( * V_49 == NULL ) goto V_29;
V_49 ++ ;
}
}
if ( ! ( V_49 == V_48 + V_47 ) )
{
F_12 ( V_54 , V_28 ) ;
goto V_29;
}
if ( ! ( V_37 = F_23 ( V_1 ) ) )
goto V_29;
for ( V_13 = 0 ; V_13 < V_7 + V_52 ; V_13 ++ )
{
if ( V_13 < V_7 )
{
if ( ! F_24 ( V_50 [ V_13 ] [ 0 ] , V_6 [ V_13 ] ) ) goto V_29;
}
else
{
if ( ! F_24 ( V_50 [ V_13 ] [ 0 ] , V_36 ) ) goto V_29;
}
if ( V_43 [ V_13 ] > 1 )
{
if ( ! F_25 ( V_1 , V_37 , V_50 [ V_13 ] [ 0 ] , V_34 ) ) goto V_29;
for ( V_26 = 1 ; V_26 < ( 1u << ( V_43 [ V_13 ] - 1 ) ) ; V_26 ++ )
{
if ( ! F_26 ( V_1 , V_50 [ V_13 ] [ V_26 ] , V_50 [ V_13 ] [ V_26 - 1 ] , V_37 , V_34 ) ) goto V_29;
}
}
}
#if 1
if ( ! F_27 ( V_1 , V_47 , V_48 , V_34 ) )
goto V_29;
#endif
V_42 = 1 ;
for ( V_40 = V_46 - 1 ; V_40 >= 0 ; V_40 -- )
{
if ( ! V_42 )
{
if ( ! F_25 ( V_1 , V_20 , V_20 , V_34 ) ) goto V_29;
}
for ( V_13 = 0 ; V_13 < V_38 ; V_13 ++ )
{
if ( V_45 [ V_13 ] > ( T_5 ) V_40 )
{
int V_32 = V_44 [ V_13 ] [ V_40 ] ;
int V_63 ;
if ( V_32 )
{
V_63 = V_32 < 0 ;
if ( V_63 )
V_32 = - V_32 ;
if ( V_63 != V_41 )
{
if ( ! V_42 )
{
if ( ! F_28 ( V_1 , V_20 , V_34 ) ) goto V_29;
}
V_41 = ! V_41 ;
}
if ( V_42 )
{
if ( ! F_24 ( V_20 , V_50 [ V_13 ] [ V_32 >> 1 ] ) ) goto V_29;
V_42 = 0 ;
}
else
{
if ( ! F_26 ( V_1 , V_20 , V_20 , V_50 [ V_13 ] [ V_32 >> 1 ] , V_34 ) ) goto V_29;
}
}
}
}
}
if ( V_42 )
{
if ( ! F_17 ( V_1 , V_20 ) ) goto V_29;
}
else
{
if ( V_41 )
if ( ! F_28 ( V_1 , V_20 , V_34 ) ) goto V_29;
}
V_2 = 1 ;
V_29:
if ( V_35 != NULL )
F_29 ( V_35 ) ;
if ( V_37 != NULL )
F_6 ( V_37 ) ;
if ( V_43 != NULL )
F_7 ( V_43 ) ;
if ( V_45 != NULL )
F_7 ( V_45 ) ;
if ( V_44 != NULL )
{
signed char * * V_5 ;
for ( V_5 = V_44 ; * V_5 != NULL ; V_5 ++ )
F_7 ( * V_5 ) ;
F_7 ( V_44 ) ;
}
if ( V_48 != NULL )
{
for ( V_49 = V_48 ; * V_49 != NULL ; V_49 ++ )
F_9 ( * V_49 ) ;
F_7 ( V_48 ) ;
}
if ( V_50 != NULL )
{
F_7 ( V_50 ) ;
}
return V_2 ;
}
int F_30 ( T_2 * V_1 , T_6 * V_34 )
{
const T_3 * V_36 ;
T_3 * V_64 = NULL , * V_65 = NULL , * * V_66 ;
T_6 * V_35 = NULL ;
T_4 * V_67 ;
T_5 V_13 , V_58 , V_5 , V_39 , V_3 , V_4 , V_7 ;
T_3 * * V_6 = NULL ;
T_1 * V_51 ;
int V_2 = 0 ;
F_31 ( & V_1 -> V_57 , F_3 , F_5 , F_8 ) ;
if ( ( V_51 = F_1 ( V_1 ) ) == NULL )
return 0 ;
V_36 = F_19 ( V_1 ) ;
if ( V_36 == NULL )
{
F_12 ( V_68 , V_56 ) ;
goto V_29;
}
if ( V_34 == NULL )
{
V_34 = V_35 = F_18 () ;
if ( V_34 == NULL )
goto V_29;
}
F_32 ( V_34 ) ;
V_67 = F_33 ( V_34 ) ;
if ( V_67 == NULL ) goto V_29;
if ( ! F_34 ( V_1 , V_67 , V_34 ) ) goto V_29;
if ( F_35 ( V_67 ) )
{
F_12 ( V_68 , V_69 ) ;
goto V_29;
}
V_58 = F_14 ( V_67 ) ;
V_3 = 8 ;
V_5 = 4 ;
if ( F_22 ( V_58 ) > V_5 )
{
V_5 = F_22 ( V_58 ) ;
}
V_4 = ( V_58 + V_3 - 1 ) / V_3 ;
V_39 = 1u << ( V_5 - 1 ) ;
V_7 = V_39 * V_4 ;
V_6 = F_2 ( sizeof ( T_3 * ) * ( V_7 + 1 ) ) ;
if ( ! V_6 )
{
F_12 ( V_68 , V_70 ) ;
goto V_29;
}
V_66 = V_6 ;
V_66 [ V_7 ] = NULL ;
for ( V_13 = 0 ; V_13 < V_7 ; V_13 ++ )
{
if ( ( V_66 [ V_13 ] = F_23 ( V_1 ) ) == NULL )
{
F_12 ( V_68 , V_70 ) ;
goto V_29;
}
}
if ( ! ( V_64 = F_23 ( V_1 ) ) || ! ( V_65 = F_23 ( V_1 ) ) )
{
F_12 ( V_68 , V_70 ) ;
goto V_29;
}
if ( ! F_24 ( V_65 , V_36 ) )
goto V_29;
for ( V_13 = 0 ; V_13 < V_4 ; V_13 ++ )
{
T_5 V_26 ;
if ( ! F_25 ( V_1 , V_64 , V_65 , V_34 ) )
goto V_29;
if ( ! F_24 ( * V_66 ++ , V_65 ) )
goto V_29;
for ( V_26 = 1 ; V_26 < V_39 ; V_26 ++ , V_66 ++ )
{
if ( ! F_26 ( V_1 , * V_66 , V_64 , * ( V_66 - 1 ) , V_34 ) )
goto V_29;
}
if ( V_13 < V_4 - 1 )
{
T_5 V_40 ;
if ( V_3 <= 2 )
{
F_12 ( V_68 , V_28 ) ;
goto V_29;
}
if ( ! F_25 ( V_1 , V_65 , V_64 , V_34 ) )
goto V_29;
for ( V_40 = 2 ; V_40 < V_3 ; V_40 ++ )
{
if ( ! F_25 ( V_1 , V_65 , V_65 , V_34 ) )
goto V_29;
}
}
}
if ( ! F_27 ( V_1 , V_7 , V_6 , V_34 ) )
goto V_29;
V_51 -> V_1 = V_1 ;
V_51 -> V_3 = V_3 ;
V_51 -> V_4 = V_4 ;
V_51 -> V_5 = V_5 ;
V_51 -> V_6 = V_6 ;
V_6 = NULL ;
V_51 -> V_7 = V_7 ;
if ( ! F_36 ( & V_1 -> V_57 , V_51 ,
F_3 , F_5 , F_8 ) )
goto V_29;
V_51 = NULL ;
V_2 = 1 ;
V_29:
F_37 ( V_34 ) ;
if ( V_35 != NULL )
F_29 ( V_35 ) ;
if ( V_51 )
F_5 ( V_51 ) ;
if ( V_6 )
{
T_3 * * V_15 ;
for ( V_15 = V_6 ; * V_15 != NULL ; V_15 ++ )
F_6 ( * V_15 ) ;
F_7 ( V_6 ) ;
}
if ( V_64 )
F_6 ( V_64 ) ;
if ( V_65 )
F_6 ( V_65 ) ;
return V_2 ;
}
int F_38 ( const T_2 * V_1 )
{
if ( F_20 ( V_1 -> V_57 , F_3 , F_5 , F_8 ) != NULL )
return 1 ;
else
return 0 ;
}
