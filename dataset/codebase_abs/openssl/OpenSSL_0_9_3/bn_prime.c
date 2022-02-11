T_1 * F_1 ( T_1 * V_1 , int V_2 , int V_3 , T_1 * V_4 ,
T_1 * V_5 , void (* F_2)( int , int , char * ) , char * V_6 )
{
T_1 * V_7 = NULL ;
T_1 V_8 ;
int V_9 , V_10 , V_11 = 0 ;
T_2 * V_12 ;
V_12 = F_3 () ;
if ( V_12 == NULL ) goto V_13;
if ( V_1 == NULL )
{
if ( ( V_7 = F_4 () ) == NULL ) goto V_13;
}
else
V_7 = V_1 ;
F_5 ( & V_8 ) ;
V_14:
if ( V_4 == NULL )
{
if ( ! F_6 ( V_7 , V_2 ) ) goto V_13;
}
else
{
if ( V_3 )
{
if ( ! F_7 ( V_7 , V_2 , V_4 , V_5 , V_12 ) )
goto V_13;
}
else
{
if ( ! F_8 ( V_7 , V_2 , V_4 , V_5 , V_12 ) )
goto V_13;
}
}
if ( F_2 != NULL ) F_2 ( 0 , V_11 ++ , V_6 ) ;
if ( ! V_3 )
{
V_9 = F_9 ( V_7 , V_15 , F_2 , V_12 , V_6 ) ;
if ( V_9 == - 1 ) goto V_13;
if ( V_9 == 0 ) goto V_14;
}
else
{
if ( ! F_10 ( & V_8 , V_7 ) ) goto V_13;
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ )
{
V_10 = F_9 ( V_7 , 1 , F_2 , V_12 , V_6 ) ;
if ( V_10 == - 1 ) goto V_13;
if ( V_10 == 0 ) goto V_14;
V_10 = F_9 ( & V_8 , 1 , F_2 , V_12 , V_6 ) ;
if ( V_10 == - 1 ) goto V_13;
if ( V_10 == 0 ) goto V_14;
if ( F_2 != NULL ) F_2 ( 2 , V_11 - 1 , V_6 ) ;
}
}
V_1 = V_7 ;
V_13:
if ( ( V_1 == NULL ) && ( V_7 != NULL ) ) F_11 ( V_7 ) ;
F_11 ( & V_8 ) ;
if ( V_12 != NULL ) F_12 ( V_12 ) ;
return ( V_1 ) ;
}
int F_9 ( T_1 * V_16 , int V_17 , void (* F_2)( int , int , char * ) ,
T_2 * V_18 , char * V_6 )
{
int V_9 , V_10 , V_19 = 0 , V_1 = - 1 ;
T_1 * V_20 ;
T_2 * V_12 = NULL , * V_21 = NULL ;
T_3 * V_22 = NULL ;
if ( ! F_13 ( V_16 ) )
return ( 0 ) ;
if ( V_18 != NULL )
V_12 = V_18 ;
else
if ( ( V_12 = F_3 () ) == NULL ) goto V_13;
if ( ( V_21 = F_3 () ) == NULL ) goto V_13;
if ( ( V_22 = F_14 () ) == NULL ) goto V_13;
V_20 = & ( V_12 -> V_23 [ V_12 -> V_24 ++ ] ) ;
if ( ! F_15 ( V_22 , V_16 , V_21 ) ) goto V_13;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ )
{
if ( ! F_16 ( V_20 , F_17 ( V_16 ) - 1 , 0 , 0 ) ) goto V_13;
V_10 = F_18 ( V_20 , V_16 , V_12 , V_21 , V_22 ) ;
if ( V_10 == - 1 ) goto V_13;
if ( V_10 )
{
V_1 = 0 ;
goto V_13;
}
if ( F_2 != NULL ) F_2 ( 1 , V_19 ++ , V_6 ) ;
}
V_1 = 1 ;
V_13:
V_12 -> V_24 -- ;
if ( ( V_18 == NULL ) && ( V_12 != NULL ) )
F_12 ( V_12 ) ;
if ( V_21 != NULL )
F_12 ( V_21 ) ;
if ( V_22 != NULL ) F_19 ( V_22 ) ;
return ( V_1 ) ;
}
static int F_18 ( T_1 * V_16 , T_1 * V_25 , T_2 * V_12 , T_2 * V_21 ,
T_3 * V_22 )
{
int V_26 , V_9 , V_1 = - 1 , V_27 ;
T_1 * V_28 , * V_29 , * V_30 , * V_31 , * V_32 , * V_33 ;
T_1 * V_34 , * V_35 , * V_36 ;
V_31 = & ( V_12 -> V_23 [ V_12 -> V_24 ] ) ;
V_32 = & ( V_12 -> V_23 [ V_12 -> V_24 + 1 ] ) ;
V_33 = & ( V_12 -> V_23 [ V_12 -> V_24 + 2 ] ) ;
V_12 -> V_24 += 3 ;
V_34 = & ( V_21 -> V_23 [ V_21 -> V_24 ] ) ;
V_35 = & ( V_21 -> V_23 [ V_21 -> V_24 + 1 ] ) ;
V_36 = & ( V_21 -> V_23 [ V_21 -> V_24 + 2 ] ) ;
V_21 -> V_24 += 3 ;
V_28 = V_31 ;
V_29 = V_32 ;
if ( ! F_20 ( V_28 ) ) goto V_13;
if ( ! F_21 ( V_33 , V_25 , V_28 ) ) goto V_13;
V_26 = F_17 ( V_33 ) ;
if ( ! F_22 ( V_34 , F_23 () , V_22 , V_21 ) ) goto V_13;
if ( ! F_22 ( V_35 , V_33 , V_22 , V_21 ) ) goto V_13;
if ( ! F_22 ( V_36 , V_16 , V_22 , V_21 ) ) goto V_13;
F_24 ( V_28 , V_34 ) ;
for ( V_9 = V_26 - 1 ; V_9 >= 0 ; V_9 -- )
{
if ( ( F_25 ( V_28 , V_34 ) != 0 ) &&
( F_25 ( V_28 , V_35 ) != 0 ) )
V_27 = 1 ;
else
V_27 = 0 ;
F_26 ( V_29 , V_28 , V_28 , V_22 , V_21 ) ;
if ( V_27 && ( F_25 ( V_29 , V_34 ) == 0 ) )
{
V_1 = 1 ;
goto V_13;
}
if ( F_27 ( V_33 , V_9 ) )
{
F_26 ( V_28 , V_29 , V_36 , V_22 , V_21 ) ;
}
else
{
V_30 = V_28 ;
V_28 = V_29 ;
V_29 = V_30 ;
}
}
if ( F_25 ( V_28 , V_34 ) == 0 )
V_9 = 0 ;
else V_9 = 1 ;
V_1 = V_9 ;
V_13:
V_12 -> V_24 -= 3 ;
V_21 -> V_24 -= 3 ;
return ( V_1 ) ;
}
static int F_6 ( T_1 * V_7 , int V_2 )
{
int V_9 ;
T_4 T_5 V_37 [ V_38 ] ;
T_5 V_39 , V_28 ;
V_40:
if ( ! F_16 ( V_7 , V_2 , 1 , 1 ) ) return ( 0 ) ;
for ( V_9 = 1 ; V_9 < V_38 ; V_9 ++ )
V_37 [ V_9 ] = F_28 ( V_7 , ( T_5 ) V_41 [ V_9 ] ) ;
V_39 = 0 ;
V_14: for ( V_9 = 1 ; V_9 < V_38 ; V_9 ++ )
{
if ( ( ( V_37 [ V_9 ] + V_39 ) % V_41 [ V_9 ] ) <= 1 )
{
V_28 = V_39 ;
V_39 += 2 ;
if ( V_39 < V_28 ) goto V_40;
goto V_14;
}
}
if ( ! F_29 ( V_7 , V_39 ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_8 ( T_1 * V_7 , int V_2 , T_1 * V_4 , T_1 * V_5 ,
T_2 * V_12 )
{
int V_9 , V_1 = 0 ;
T_1 * V_42 ;
V_42 = & ( V_12 -> V_23 [ V_12 -> V_24 ++ ] ) ;
if ( ! F_16 ( V_7 , V_2 , 0 , 1 ) ) goto V_13;
if ( ! F_30 ( V_42 , V_7 , V_4 , V_12 ) ) goto V_13;
if ( ! F_21 ( V_7 , V_7 , V_42 ) ) goto V_13;
if ( V_5 == NULL )
{ if ( ! F_29 ( V_7 , 1 ) ) goto V_13; }
else
{ if ( ! F_31 ( V_7 , V_7 , V_5 ) ) goto V_13; }
V_14: for ( V_9 = 1 ; V_9 < V_38 ; V_9 ++ )
{
if ( F_28 ( V_7 , ( T_5 ) V_41 [ V_9 ] ) <= 1 )
{
if ( ! F_31 ( V_7 , V_7 , V_4 ) ) goto V_13;
goto V_14;
}
}
V_1 = 1 ;
V_13:
V_12 -> V_24 -- ;
return ( V_1 ) ;
}
static int F_7 ( T_1 * V_43 , int V_2 , T_1 * V_44 ,
T_1 * V_5 , T_2 * V_12 )
{
int V_9 , V_1 = 0 ;
T_1 * V_42 , * V_45 = NULL , * V_46 = NULL ;
V_2 -- ;
V_42 = & ( V_12 -> V_23 [ V_12 -> V_24 ++ ] ) ;
V_46 = & ( V_12 -> V_23 [ V_12 -> V_24 ++ ] ) ;
V_45 = & ( V_12 -> V_23 [ V_12 -> V_24 ++ ] ) ;
if ( ! F_10 ( V_45 , V_44 ) ) goto V_13;
if ( ! F_16 ( V_46 , V_2 , 0 , 1 ) ) goto V_13;
if ( ! F_30 ( V_42 , V_46 , V_45 , V_12 ) ) goto V_13;
if ( ! F_21 ( V_46 , V_46 , V_42 ) ) goto V_13;
if ( V_5 == NULL )
{ if ( ! F_29 ( V_46 , 1 ) ) goto V_13; }
else
{
if ( ! F_10 ( V_42 , V_5 ) ) goto V_13;
if ( ! F_31 ( V_46 , V_46 , V_42 ) ) goto V_13;
}
if ( ! F_32 ( V_43 , V_46 ) ) goto V_13;
if ( ! F_29 ( V_43 , 1 ) ) goto V_13;
V_14: for ( V_9 = 1 ; V_9 < V_38 ; V_9 ++ )
{
if ( ( F_28 ( V_43 , ( T_5 ) V_41 [ V_9 ] ) == 0 ) ||
( F_28 ( V_46 , ( T_5 ) V_41 [ V_9 ] ) == 0 ) )
{
if ( ! F_31 ( V_43 , V_43 , V_44 ) ) goto V_13;
if ( ! F_31 ( V_46 , V_46 , V_45 ) ) goto V_13;
goto V_14;
}
}
V_1 = 1 ;
V_13:
V_12 -> V_24 -= 3 ;
return ( V_1 ) ;
}
