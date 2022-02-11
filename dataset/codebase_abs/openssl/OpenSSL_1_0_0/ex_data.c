static void F_1 ( void )
{
F_2 ( V_1 ) ;
if( ! V_2 )
V_2 = & V_3 ;
F_3 ( V_1 ) ;
}
const T_1 * F_4 ( void )
{
F_5
return V_2 ;
}
int F_6 ( const T_1 * V_4 )
{
int V_5 = 0 ;
F_2 ( V_1 ) ;
if( ! V_2 )
{
V_2 = V_4 ;
V_5 = 1 ;
}
F_3 ( V_1 ) ;
return V_5 ;
}
static unsigned long F_7 ( const T_2 * V_6 )
{
return V_6 -> V_7 ;
}
void F_8 ( T_3 * V_8 )
{
F_9 ( V_8 ) ;
}
static void F_10 ( void * V_9 )
{
T_2 * V_10 = ( T_2 * ) V_9 ;
F_11 ( V_10 -> V_11 , F_8 ) ;
F_9 ( V_10 ) ;
}
static T_2 * F_12 ( int V_7 )
{
T_2 V_12 , * V_13 , * V_14 ;
F_13 (return NULL;)
V_12 . V_7 = V_7 ;
F_2 ( V_1 ) ;
V_13 = F_14 ( V_15 , & V_12 ) ;
if( ! V_13 )
{
V_14 = F_15 ( sizeof( T_2 ) ) ;
if( V_14 )
{
V_14 -> V_7 = V_7 ;
V_14 -> V_16 = 0 ;
V_14 -> V_11 = F_16 () ;
if( ! V_14 -> V_11 )
F_9 ( V_14 ) ;
else
{
( void ) F_17 ( V_15 , V_14 ) ;
V_13 = V_14 ;
}
}
}
F_3 ( V_1 ) ;
if( ! V_13 )
F_18 ( V_17 , V_18 ) ;
return V_13 ;
}
static int F_19 ( T_2 * V_10 , long V_19 , void * V_20 ,
T_4 * V_21 , T_5 * V_22 ,
T_6 * V_23 )
{
int V_5 = - 1 ;
T_3 * V_6 = ( T_3 * ) F_15 (
sizeof( T_3 ) ) ;
if( ! V_6 )
{
F_18 ( V_24 , V_18 ) ;
return - 1 ;
}
V_6 -> V_19 = V_19 ;
V_6 -> V_20 = V_20 ;
V_6 -> V_21 = V_21 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_23 = V_23 ;
F_2 ( V_1 ) ;
while ( F_20 ( V_10 -> V_11 ) <= V_10 -> V_16 )
{
if ( ! F_21 ( V_10 -> V_11 , NULL ) )
{
F_18 ( V_24 , V_18 ) ;
F_9 ( V_6 ) ;
goto V_25;
}
}
V_5 = V_10 -> V_16 ++ ;
( void ) F_22 ( V_10 -> V_11 , V_5 , V_6 ) ;
V_25:
F_3 ( V_1 ) ;
return V_5 ;
}
static int F_23 ( void )
{
int V_5 ;
F_2 ( V_1 ) ;
V_5 = V_26 ++ ;
F_3 ( V_1 ) ;
return V_5 ;
}
static void F_24 ( void )
{
F_13 (return;)
F_25 ( V_15 , F_10 ) ;
F_26 ( V_15 ) ;
V_15 = NULL ;
V_2 = NULL ;
}
static int F_27 ( int V_7 , long V_19 , void * V_20 ,
T_4 * V_21 , T_5 * V_22 ,
T_6 * V_23 )
{
T_2 * V_10 = F_12 ( V_7 ) ;
if( ! V_10 )
return - 1 ;
return F_19 ( V_10 , V_19 , V_20 , V_21 , V_22 , V_23 ) ;
}
static int F_28 ( int V_7 , void * V_27 ,
T_7 * V_28 )
{
int V_29 , V_4 ;
void * V_30 ;
T_3 * * V_31 = NULL ;
T_2 * V_10 = F_12 ( V_7 ) ;
if( ! V_10 )
return 0 ;
V_28 -> V_32 = NULL ;
F_29 ( V_1 ) ;
V_29 = F_20 ( V_10 -> V_11 ) ;
if( V_29 > 0 )
{
V_31 = F_15 ( V_29 * sizeof( T_3 * ) ) ;
if( ! V_31 )
goto V_33;
for( V_4 = 0 ; V_4 < V_29 ; V_4 ++ )
V_31 [ V_4 ] = F_30 ( V_10 -> V_11 , V_4 ) ;
}
V_33:
F_31 ( V_1 ) ;
if( ( V_29 > 0 ) && ! V_31 )
{
F_18 ( V_34 , V_18 ) ;
return 0 ;
}
for( V_4 = 0 ; V_4 < V_29 ; V_4 ++ )
{
if( V_31 [ V_4 ] && V_31 [ V_4 ] -> V_21 )
{
V_30 = F_32 ( V_28 , V_4 ) ;
V_31 [ V_4 ] -> V_21 ( V_27 , V_30 , V_28 , V_4 ,
V_31 [ V_4 ] -> V_19 , V_31 [ V_4 ] -> V_20 ) ;
}
}
if( V_31 )
F_9 ( V_31 ) ;
return 1 ;
}
static int F_33 ( int V_7 , T_7 * V_35 ,
T_7 * V_36 )
{
int V_29 , V_37 , V_4 ;
char * V_30 ;
T_3 * * V_31 = NULL ;
T_2 * V_10 ;
if( ! V_36 -> V_32 )
return 1 ;
if( ( V_10 = F_12 ( V_7 ) ) == NULL )
return 0 ;
F_29 ( V_1 ) ;
V_29 = F_20 ( V_10 -> V_11 ) ;
V_37 = F_34 ( V_36 -> V_32 ) ;
if( V_37 < V_29 )
V_29 = V_37 ;
if( V_29 > 0 )
{
V_31 = F_15 ( V_29 * sizeof( T_3 * ) ) ;
if( ! V_31 )
goto V_33;
for( V_4 = 0 ; V_4 < V_29 ; V_4 ++ )
V_31 [ V_4 ] = F_30 ( V_10 -> V_11 , V_4 ) ;
}
V_33:
F_31 ( V_1 ) ;
if( ( V_29 > 0 ) && ! V_31 )
{
F_18 ( V_38 , V_18 ) ;
return 0 ;
}
for( V_4 = 0 ; V_4 < V_29 ; V_4 ++ )
{
V_30 = F_32 ( V_36 , V_4 ) ;
if( V_31 [ V_4 ] && V_31 [ V_4 ] -> V_22 )
V_31 [ V_4 ] -> V_22 ( V_35 , V_36 , & V_30 , V_4 ,
V_31 [ V_4 ] -> V_19 , V_31 [ V_4 ] -> V_20 ) ;
F_35 ( V_35 , V_4 , V_30 ) ;
}
if( V_31 )
F_9 ( V_31 ) ;
return 1 ;
}
static void F_36 ( int V_7 , void * V_27 ,
T_7 * V_28 )
{
int V_29 , V_4 ;
T_2 * V_10 ;
void * V_30 ;
T_3 * * V_31 = NULL ;
if( ( V_10 = F_12 ( V_7 ) ) == NULL )
return;
F_29 ( V_1 ) ;
V_29 = F_20 ( V_10 -> V_11 ) ;
if( V_29 > 0 )
{
V_31 = F_15 ( V_29 * sizeof( T_3 * ) ) ;
if( ! V_31 )
goto V_33;
for( V_4 = 0 ; V_4 < V_29 ; V_4 ++ )
V_31 [ V_4 ] = F_30 ( V_10 -> V_11 , V_4 ) ;
}
V_33:
F_31 ( V_1 ) ;
if( ( V_29 > 0 ) && ! V_31 )
{
F_18 ( V_39 , V_18 ) ;
return;
}
for( V_4 = 0 ; V_4 < V_29 ; V_4 ++ )
{
if( V_31 [ V_4 ] && V_31 [ V_4 ] -> V_23 )
{
V_30 = F_32 ( V_28 , V_4 ) ;
V_31 [ V_4 ] -> V_23 ( V_27 , V_30 , V_28 , V_4 ,
V_31 [ V_4 ] -> V_19 , V_31 [ V_4 ] -> V_20 ) ;
}
}
if( V_31 )
F_9 ( V_31 ) ;
if( V_28 -> V_32 )
{
F_37 ( V_28 -> V_32 ) ;
V_28 -> V_32 = NULL ;
}
}
int F_38 ( void )
{
F_5
return F_39 ( V_40 ) () ;
}
void F_40 ( void )
{
F_5
F_39 ( V_41 ) () ;
}
int F_41 ( int V_7 , long V_19 , void * V_20 ,
T_4 * V_21 , T_5 * V_22 ,
T_6 * V_23 )
{
int V_42 = - 1 ;
F_5
V_42 = F_39 ( V_43 ) ( V_7 ,
V_19 , V_20 , V_21 , V_22 , V_23 ) ;
return V_42 ;
}
int F_42 ( int V_7 , void * V_27 , T_7 * V_28 )
{
F_5
return F_39 ( V_44 ) ( V_7 , V_27 , V_28 ) ;
}
int F_43 ( int V_7 , T_7 * V_35 ,
T_7 * V_36 )
{
F_5
return F_39 ( V_45 ) ( V_7 , V_35 , V_36 ) ;
}
void F_44 ( int V_7 , void * V_27 , T_7 * V_28 )
{
F_5
F_39 ( V_46 ) ( V_7 , V_27 , V_28 ) ;
}
int F_35 ( T_7 * V_28 , int V_47 , void * V_48 )
{
int V_4 ;
if ( V_28 -> V_32 == NULL )
{
if ( ( V_28 -> V_32 = F_45 () ) == NULL )
{
F_18 ( V_49 , V_18 ) ;
return ( 0 ) ;
}
}
V_4 = F_34 ( V_28 -> V_32 ) ;
while ( V_4 <= V_47 )
{
if ( ! F_46 ( V_28 -> V_32 , NULL ) )
{
F_18 ( V_49 , V_18 ) ;
return ( 0 ) ;
}
V_4 ++ ;
}
F_47 ( V_28 -> V_32 , V_47 , V_48 ) ;
return ( 1 ) ;
}
void * F_32 ( const T_7 * V_28 , int V_47 )
{
if ( V_28 -> V_32 == NULL )
return ( 0 ) ;
else if ( V_47 >= F_34 ( V_28 -> V_32 ) )
return ( 0 ) ;
else
return ( F_48 ( V_28 -> V_32 , V_47 ) ) ;
}
