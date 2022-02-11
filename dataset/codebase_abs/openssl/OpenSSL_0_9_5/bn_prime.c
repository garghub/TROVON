T_1 * F_1 ( T_1 * V_1 , int V_2 , int V_3 , T_1 * V_4 ,
T_1 * V_5 , void (* F_2)( int , int , void * ) , void * V_6 )
{
T_1 * V_7 = NULL ;
T_1 V_8 ;
int V_9 = 0 ;
int V_10 , V_11 , V_12 = 0 ;
T_2 * V_13 ;
int V_14 = F_3 ( V_2 ) ;
V_13 = F_4 () ;
if ( V_13 == NULL ) goto V_15;
if ( V_1 == NULL )
{
if ( ( V_7 = F_5 () ) == NULL ) goto V_15;
}
else
V_7 = V_1 ;
F_6 ( & V_8 ) ;
V_16:
if ( V_4 == NULL )
{
if ( ! F_7 ( V_7 , V_2 ) ) goto V_15;
}
else
{
if ( V_3 )
{
if ( ! F_8 ( V_7 , V_2 , V_4 , V_5 , V_13 ) )
goto V_15;
}
else
{
if ( ! F_9 ( V_7 , V_2 , V_4 , V_5 , V_13 ) )
goto V_15;
}
}
if ( F_2 != NULL ) F_2 ( 0 , V_12 ++ , V_6 ) ;
if ( ! V_3 )
{
V_10 = F_10 ( V_7 , V_14 , F_2 , V_13 , V_6 , 0 ) ;
if ( V_10 == - 1 ) goto V_15;
if ( V_10 == 0 ) goto V_16;
}
else
{
if ( ! F_11 ( & V_8 , V_7 ) ) goto V_15;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ )
{
V_11 = F_10 ( V_7 , 1 , F_2 , V_13 , V_6 , 0 ) ;
if ( V_11 == - 1 ) goto V_15;
if ( V_11 == 0 ) goto V_16;
V_11 = F_10 ( & V_8 , 1 , F_2 , V_13 , V_6 , 0 ) ;
if ( V_11 == - 1 ) goto V_15;
if ( V_11 == 0 ) goto V_16;
if ( F_2 != NULL ) F_2 ( 2 , V_12 - 1 , V_6 ) ;
}
}
V_9 = 1 ;
V_15:
if ( ! V_9 && ( V_1 == NULL ) && ( V_7 != NULL ) ) F_12 ( V_7 ) ;
F_12 ( & V_8 ) ;
if ( V_13 != NULL ) F_13 ( V_13 ) ;
return ( V_9 ? V_7 : NULL ) ;
}
int F_14 ( const T_1 * V_17 , int V_14 , void (* F_2)( int , int , void * ) ,
T_2 * V_18 , void * V_6 )
{
return F_10 ( V_17 , V_14 , F_2 , V_18 , V_6 , 0 ) ;
}
int F_10 ( const T_1 * V_17 , int V_14 ,
void (* F_2)( int , int , void * ) ,
T_2 * V_18 , void * V_6 ,
int V_19 )
{
int V_10 , V_11 , V_1 = - 1 ;
int V_20 ;
T_2 * V_13 = NULL ;
T_1 * V_21 , * V_22 , * V_23 ;
T_3 * V_24 = NULL ;
const T_1 * V_25 = NULL ;
if ( V_14 == V_26 )
V_14 = F_3 ( F_15 ( V_17 ) ) ;
if ( ! F_16 ( V_17 ) )
return ( 0 ) ;
if ( V_19 )
{
for ( V_10 = 1 ; V_10 < V_27 ; V_10 ++ )
if ( F_17 ( V_17 , V_28 [ V_10 ] ) == 0 )
return 0 ;
if ( F_2 != NULL ) F_2 ( 1 , - 1 , V_6 ) ;
}
if ( V_18 != NULL )
V_13 = V_18 ;
else
if ( ( V_13 = F_4 () ) == NULL )
goto V_15;
F_18 ( V_13 ) ;
if ( V_17 -> V_29 )
{
T_1 * V_8 ;
if ( ( V_8 = F_19 ( V_13 ) ) == NULL ) goto V_15;
F_20 ( V_8 , V_17 ) ;
V_8 -> V_29 = 0 ;
V_25 = V_8 ;
}
else
V_25 = V_17 ;
V_21 = F_19 ( V_13 ) ;
V_22 = F_19 ( V_13 ) ;
V_23 = F_19 ( V_13 ) ;
if ( V_23 == NULL ) goto V_15;
if ( ! F_20 ( V_21 , V_25 ) )
goto V_15;
if ( ! F_21 ( V_21 , 1 ) )
goto V_15;
if ( F_22 ( V_21 ) )
{
V_1 = 0 ;
goto V_15;
}
V_20 = 1 ;
while ( ! F_23 ( V_21 , V_20 ) )
V_20 ++ ;
if ( ! F_24 ( V_22 , V_21 , V_20 ) )
goto V_15;
V_24 = F_25 () ;
if ( V_24 == NULL )
goto V_15;
if ( ! F_26 ( V_24 , V_25 , V_13 ) )
goto V_15;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ )
{
if ( ! F_27 ( V_23 , F_15 ( V_21 ) , 0 , 0 ) )
goto V_15;
if ( F_28 ( V_23 , V_21 ) >= 0 )
if ( ! F_29 ( V_23 , V_23 , V_21 ) )
goto V_15;
if ( ! F_30 ( V_23 , 1 ) )
goto V_15;
V_11 = F_31 ( V_23 , V_25 , V_21 , V_22 , V_20 , V_13 , V_24 ) ;
if ( V_11 == - 1 ) goto V_15;
if ( V_11 )
{
V_1 = 0 ;
goto V_15;
}
if ( F_2 != NULL ) F_2 ( 1 , V_10 , V_6 ) ;
}
V_1 = 1 ;
V_15:
if ( V_13 != NULL )
{
F_32 ( V_13 ) ;
if ( V_18 == NULL )
F_13 ( V_13 ) ;
}
if ( V_24 != NULL )
F_33 ( V_24 ) ;
return ( V_1 ) ;
}
static int F_31 ( T_1 * V_30 , const T_1 * V_17 , const T_1 * V_31 ,
const T_1 * V_32 , int V_20 , T_2 * V_13 , T_3 * V_24 )
{
if ( ! F_34 ( V_30 , V_30 , V_32 , V_17 , V_13 , V_24 ) )
return - 1 ;
if ( F_35 ( V_30 ) )
return 0 ;
if ( F_28 ( V_30 , V_31 ) == 0 )
return 0 ;
while ( -- V_20 )
{
if ( ! F_36 ( V_30 , V_30 , V_30 , V_17 , V_13 ) )
return - 1 ;
if ( F_35 ( V_30 ) )
return 1 ;
if ( F_28 ( V_30 , V_31 ) == 0 )
return 0 ;
}
return 1 ;
}
static int F_7 ( T_1 * V_7 , int V_2 )
{
int V_10 ;
T_4 V_33 [ V_27 ] ;
T_4 V_34 , V_35 ;
V_36:
if ( ! F_37 ( V_7 , V_2 , 1 , 1 ) ) return ( 0 ) ;
for ( V_10 = 1 ; V_10 < V_27 ; V_10 ++ )
V_33 [ V_10 ] = F_17 ( V_7 , ( T_4 ) V_28 [ V_10 ] ) ;
V_34 = 0 ;
V_16: for ( V_10 = 1 ; V_10 < V_27 ; V_10 ++ )
{
if ( ( ( V_33 [ V_10 ] + V_34 ) % V_28 [ V_10 ] ) <= 1 )
{
V_35 = V_34 ;
V_34 += 2 ;
if ( V_34 < V_35 ) goto V_36;
goto V_16;
}
}
if ( ! F_30 ( V_7 , V_34 ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_9 ( T_1 * V_7 , int V_2 , T_1 * V_4 , T_1 * V_5 ,
T_2 * V_13 )
{
int V_10 , V_1 = 0 ;
T_1 * V_37 ;
F_18 ( V_13 ) ;
if ( ( V_37 = F_19 ( V_13 ) ) == NULL ) goto V_15;
if ( ! F_37 ( V_7 , V_2 , 0 , 1 ) ) goto V_15;
if ( ! F_38 ( V_37 , V_7 , V_4 , V_13 ) ) goto V_15;
if ( ! F_29 ( V_7 , V_7 , V_37 ) ) goto V_15;
if ( V_5 == NULL )
{ if ( ! F_30 ( V_7 , 1 ) ) goto V_15; }
else
{ if ( ! F_39 ( V_7 , V_7 , V_5 ) ) goto V_15; }
V_16: for ( V_10 = 1 ; V_10 < V_27 ; V_10 ++ )
{
if ( F_17 ( V_7 , ( T_4 ) V_28 [ V_10 ] ) <= 1 )
{
if ( ! F_39 ( V_7 , V_7 , V_4 ) ) goto V_15;
goto V_16;
}
}
V_1 = 1 ;
V_15:
F_32 ( V_13 ) ;
return ( V_1 ) ;
}
static int F_8 ( T_1 * V_38 , int V_2 , T_1 * V_39 ,
T_1 * V_5 , T_2 * V_13 )
{
int V_10 , V_1 = 0 ;
T_1 * V_37 , * V_40 , * V_41 ;
V_2 -- ;
F_18 ( V_13 ) ;
V_37 = F_19 ( V_13 ) ;
V_41 = F_19 ( V_13 ) ;
V_40 = F_19 ( V_13 ) ;
if ( V_40 == NULL ) goto V_15;
if ( ! F_11 ( V_40 , V_39 ) ) goto V_15;
if ( ! F_37 ( V_41 , V_2 , 0 , 1 ) ) goto V_15;
if ( ! F_38 ( V_37 , V_41 , V_40 , V_13 ) ) goto V_15;
if ( ! F_29 ( V_41 , V_41 , V_37 ) ) goto V_15;
if ( V_5 == NULL )
{ if ( ! F_30 ( V_41 , 1 ) ) goto V_15; }
else
{
if ( ! F_11 ( V_37 , V_5 ) ) goto V_15;
if ( ! F_39 ( V_41 , V_41 , V_37 ) ) goto V_15;
}
if ( ! F_40 ( V_38 , V_41 ) ) goto V_15;
if ( ! F_30 ( V_38 , 1 ) ) goto V_15;
V_16: for ( V_10 = 1 ; V_10 < V_27 ; V_10 ++ )
{
if ( ( F_17 ( V_38 , ( T_4 ) V_28 [ V_10 ] ) == 0 ) ||
( F_17 ( V_41 , ( T_4 ) V_28 [ V_10 ] ) == 0 ) )
{
if ( ! F_39 ( V_38 , V_38 , V_39 ) ) goto V_15;
if ( ! F_39 ( V_41 , V_41 , V_40 ) ) goto V_15;
goto V_16;
}
}
V_1 = 1 ;
V_15:
F_32 ( V_13 ) ;
return ( V_1 ) ;
}
