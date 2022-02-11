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
static unsigned long F_7 ( const void * V_6 )
{
return ( ( const V_7 * ) V_6 ) -> V_8 ;
}
static int F_8 ( const void * V_6 , const void * V_9 )
{
return ( ( ( const V_7 * ) V_6 ) -> V_8 -
( ( const V_7 * ) V_9 ) -> V_8 ) ;
}
static int F_9 ( void )
{
int V_5 = 1 ;
F_2 ( V_1 ) ;
if( ! V_10 && ( ( V_10 = F_10 ( F_7 , F_8 ) ) == NULL ) )
V_5 = 0 ;
F_3 ( V_1 ) ;
return V_5 ;
}
static void F_11 ( T_2 * V_11 )
{
F_12 ( V_11 ) ;
}
static void F_13 ( void * V_6 )
{
V_7 * V_12 = ( V_7 * ) V_6 ;
F_14 ( V_12 -> V_13 , F_11 ) ;
F_12 ( V_12 ) ;
}
static V_7 * F_15 ( int V_8 )
{
V_7 V_14 , * V_15 , * V_16 ;
F_16 (return NULL;)
V_14 . V_8 = V_8 ;
F_2 ( V_1 ) ;
V_15 = F_17 ( V_10 , & V_14 ) ;
if( ! V_15 )
{
V_16 = F_18 ( sizeof( V_7 ) ) ;
if( V_16 )
{
V_16 -> V_8 = V_8 ;
V_16 -> V_17 = 0 ;
V_16 -> V_13 = F_19 () ;
if( ! V_16 -> V_13 )
F_12 ( V_16 ) ;
else
{
F_20 ( V_10 , V_16 ) ;
V_15 = V_16 ;
}
}
}
F_3 ( V_1 ) ;
if( ! V_15 )
F_21 ( V_18 , V_19 ) ;
return V_15 ;
}
static int F_22 ( V_7 * V_12 , long V_20 , void * V_21 ,
T_3 * V_22 , T_4 * V_23 ,
T_5 * V_24 )
{
int V_5 = - 1 ;
T_2 * V_25 = ( T_2 * ) F_18 (
sizeof( T_2 ) ) ;
if( ! V_25 )
{
F_21 ( V_26 , V_19 ) ;
return - 1 ;
}
V_25 -> V_20 = V_20 ;
V_25 -> V_21 = V_21 ;
V_25 -> V_22 = V_22 ;
V_25 -> V_23 = V_23 ;
V_25 -> V_24 = V_24 ;
F_2 ( V_1 ) ;
while ( F_23 ( V_12 -> V_13 ) <= V_12 -> V_17 )
{
if ( ! F_24 ( V_12 -> V_13 , NULL ) )
{
F_21 ( V_26 , V_19 ) ;
F_12 ( V_25 ) ;
goto V_27;
}
}
V_5 = V_12 -> V_17 ++ ;
F_25 ( V_12 -> V_13 , V_5 , V_25 ) ;
V_27:
F_3 ( V_1 ) ;
return V_5 ;
}
static int F_26 ( void )
{
int V_5 ;
F_2 ( V_1 ) ;
V_5 = V_28 ++ ;
F_3 ( V_1 ) ;
return V_5 ;
}
static void F_27 ( void )
{
F_16 (return;)
F_28 ( V_10 , F_13 ) ;
F_29 ( V_10 ) ;
V_10 = NULL ;
V_2 = NULL ;
}
static int F_30 ( int V_8 , long V_20 , void * V_21 ,
T_3 * V_22 , T_4 * V_23 ,
T_5 * V_24 )
{
V_7 * V_12 = F_15 ( V_8 ) ;
if( ! V_12 )
return - 1 ;
return F_22 ( V_12 , V_20 , V_21 , V_22 , V_23 , V_24 ) ;
}
static int F_31 ( int V_8 , void * V_29 ,
T_6 * V_30 )
{
int V_31 , V_4 ;
void * V_32 ;
T_2 * * V_33 = NULL ;
V_7 * V_12 = F_15 ( V_8 ) ;
if( ! V_12 )
return 0 ;
V_30 -> V_34 = NULL ;
F_32 ( V_1 ) ;
V_31 = F_23 ( V_12 -> V_13 ) ;
if( V_31 > 0 )
{
V_33 = F_18 ( V_31 * sizeof( T_2 * ) ) ;
if( ! V_33 )
goto V_35;
for( V_4 = 0 ; V_4 < V_31 ; V_4 ++ )
V_33 [ V_4 ] = F_33 ( V_12 -> V_13 , V_4 ) ;
}
V_35:
F_34 ( V_1 ) ;
if( ( V_31 > 0 ) && ! V_33 )
{
F_21 ( V_36 , V_19 ) ;
return 0 ;
}
for( V_4 = 0 ; V_4 < V_31 ; V_4 ++ )
{
if( V_33 [ V_4 ] && V_33 [ V_4 ] -> V_22 )
{
V_32 = F_35 ( V_30 , V_4 ) ;
V_33 [ V_4 ] -> V_22 ( V_29 , V_32 , V_30 , V_4 ,
V_33 [ V_4 ] -> V_20 , V_33 [ V_4 ] -> V_21 ) ;
}
}
if( V_33 )
F_12 ( V_33 ) ;
return 1 ;
}
static int F_36 ( int V_8 , T_6 * V_37 ,
T_6 * V_38 )
{
int V_31 , V_39 , V_4 ;
char * V_32 ;
T_2 * * V_33 = NULL ;
V_7 * V_12 ;
if( ! V_38 -> V_34 )
return 1 ;
if( ( V_12 = F_15 ( V_8 ) ) == NULL )
return 0 ;
F_32 ( V_1 ) ;
V_31 = F_23 ( V_12 -> V_13 ) ;
V_39 = F_37 ( V_38 -> V_34 ) ;
if( V_39 < V_31 )
V_31 = V_39 ;
if( V_31 > 0 )
{
V_33 = F_18 ( V_31 * sizeof( T_2 * ) ) ;
if( ! V_33 )
goto V_35;
for( V_4 = 0 ; V_4 < V_31 ; V_4 ++ )
V_33 [ V_4 ] = F_33 ( V_12 -> V_13 , V_4 ) ;
}
V_35:
F_34 ( V_1 ) ;
if( ( V_31 > 0 ) && ! V_33 )
{
F_21 ( V_40 , V_19 ) ;
return 0 ;
}
for( V_4 = 0 ; V_4 < V_31 ; V_4 ++ )
{
V_32 = F_35 ( V_38 , V_4 ) ;
if( V_33 [ V_4 ] && V_33 [ V_4 ] -> V_23 )
V_33 [ V_4 ] -> V_23 ( V_37 , V_38 , & V_32 , V_4 ,
V_33 [ V_4 ] -> V_20 , V_33 [ V_4 ] -> V_21 ) ;
F_38 ( V_37 , V_4 , V_32 ) ;
}
if( V_33 )
F_12 ( V_33 ) ;
return 1 ;
}
static void F_39 ( int V_8 , void * V_29 ,
T_6 * V_30 )
{
int V_31 , V_4 ;
V_7 * V_12 ;
void * V_32 ;
T_2 * * V_33 = NULL ;
if( ( V_12 = F_15 ( V_8 ) ) == NULL )
return;
F_32 ( V_1 ) ;
V_31 = F_23 ( V_12 -> V_13 ) ;
if( V_31 > 0 )
{
V_33 = F_18 ( V_31 * sizeof( T_2 * ) ) ;
if( ! V_33 )
goto V_35;
for( V_4 = 0 ; V_4 < V_31 ; V_4 ++ )
V_33 [ V_4 ] = F_33 ( V_12 -> V_13 , V_4 ) ;
}
V_35:
F_34 ( V_1 ) ;
if( ( V_31 > 0 ) && ! V_33 )
{
F_21 ( V_41 , V_19 ) ;
return;
}
for( V_4 = 0 ; V_4 < V_31 ; V_4 ++ )
{
if( V_33 [ V_4 ] && V_33 [ V_4 ] -> V_24 )
{
V_32 = F_35 ( V_30 , V_4 ) ;
V_33 [ V_4 ] -> V_24 ( V_29 , V_32 , V_30 , V_4 ,
V_33 [ V_4 ] -> V_20 , V_33 [ V_4 ] -> V_21 ) ;
}
}
if( V_33 )
F_12 ( V_33 ) ;
if( V_30 -> V_34 )
{
F_40 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
}
}
int F_41 ( void )
{
F_5
return F_42 ( V_42 ) () ;
}
void F_43 ( void )
{
F_5
F_42 ( V_43 ) () ;
}
int F_44 ( int V_8 , long V_20 , void * V_21 ,
T_3 * V_22 , T_4 * V_23 ,
T_5 * V_24 )
{
int V_44 = - 1 ;
F_5
V_44 = F_42 ( V_45 ) ( V_8 ,
V_20 , V_21 , V_22 , V_23 , V_24 ) ;
return V_44 ;
}
int F_45 ( int V_8 , void * V_29 , T_6 * V_30 )
{
F_5
return F_42 ( V_46 ) ( V_8 , V_29 , V_30 ) ;
}
int F_46 ( int V_8 , T_6 * V_37 ,
T_6 * V_38 )
{
F_5
return F_42 ( V_47 ) ( V_8 , V_37 , V_38 ) ;
}
void F_47 ( int V_8 , void * V_29 , T_6 * V_30 )
{
F_5
F_42 ( V_48 ) ( V_8 , V_29 , V_30 ) ;
}
int F_38 ( T_6 * V_30 , int V_49 , void * V_50 )
{
int V_4 ;
if ( V_30 -> V_34 == NULL )
{
if ( ( V_30 -> V_34 = F_48 () ) == NULL )
{
F_21 ( V_51 , V_19 ) ;
return ( 0 ) ;
}
}
V_4 = F_37 ( V_30 -> V_34 ) ;
while ( V_4 <= V_49 )
{
if ( ! F_49 ( V_30 -> V_34 , NULL ) )
{
F_21 ( V_51 , V_19 ) ;
return ( 0 ) ;
}
V_4 ++ ;
}
F_50 ( V_30 -> V_34 , V_49 , V_50 ) ;
return ( 1 ) ;
}
void * F_35 ( const T_6 * V_30 , int V_49 )
{
if ( V_30 -> V_34 == NULL )
return ( 0 ) ;
else if ( V_49 >= F_37 ( V_30 -> V_34 ) )
return ( 0 ) ;
else
return ( F_51 ( V_30 -> V_34 , V_49 ) ) ;
}
