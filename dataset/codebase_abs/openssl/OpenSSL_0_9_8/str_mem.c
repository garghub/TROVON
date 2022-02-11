const T_1 * F_1 ( void )
{
return & V_1 ;
}
static int F_2 ( T_2 * V_2 )
{
return 1 ;
}
static void F_3 ( T_2 * V_2 )
{
return;
}
static T_3 * F_4 ( T_2 * V_2 , T_4 type ,
T_5 V_3 [] , T_5 V_4 [] )
{
F_5 ( V_5 , V_6 ) ;
return 0 ;
}
static T_3 * F_6 ( T_2 * V_2 , T_4 type ,
T_5 V_3 [] , T_5 V_4 [] )
{
void * V_7 = F_7 ( V_2 , type , V_3 , V_4 ) ;
if ( V_7 )
{
T_3 * V_8 = F_8 ( V_2 , V_7 ) ;
if ( F_9 ( V_2 , V_7 ) )
return V_8 ;
}
return NULL ;
}
static int F_10 ( T_2 * V_2 , T_4 type ,
T_3 * V_9 , T_5 V_3 [] ,
T_5 V_4 [] )
{
F_5 ( V_10 , V_6 ) ;
return 0 ;
}
static int F_11 ( T_2 * V_2 , T_4 type ,
T_5 V_11 [] , T_5 V_12 [] ,
T_5 V_13 [] , T_5 V_14 [] ,
T_5 V_4 [] )
{
F_5 ( V_15 , V_6 ) ;
return 0 ;
}
static int F_12 ( T_2 * V_2 , T_4 type ,
T_5 V_3 [] , T_5 V_4 [] )
{
F_5 ( V_16 , V_6 ) ;
return 0 ;
}
static void * F_7 ( T_2 * V_2 , T_4 type ,
T_5 V_3 [] , T_5 V_4 [] )
{
struct V_17 * V_7 =
(struct V_17 * ) F_13 ( sizeof( struct V_17 ) ) ;
void * V_18 = NULL ;
T_6 * V_19 = NULL ;
if ( ! V_7 )
{
F_5 ( V_20 , V_21 ) ;
return 0 ;
}
memset ( V_7 , 0 , sizeof( struct V_17 ) ) ;
V_18 = F_14 ( V_3 ) ;
if ( ! V_18 )
{
F_5 ( V_20 , V_22 ) ;
goto V_23;
}
while( ( V_19 = F_15 ( V_18 ) ) )
{
if ( V_7 -> V_11 == NULL )
{
V_7 -> V_11 =
F_16 ( ( int ( * ) ( const char * const * , const char * const * ) ) V_24 ) ;
if ( ! V_7 -> V_11 )
{
F_5 ( V_20 ,
V_21 ) ;
goto V_23;
}
}
F_17 ( V_7 -> V_11 , ( char * ) V_19 ) ;
}
if ( ! F_18 ( V_18 ) )
goto V_23;
F_19 ( V_18 ) ;
V_7 -> V_25 = - 1 ;
V_7 -> V_26 = - 1 ;
return V_7 ;
V_23:
if ( V_18 ) F_19 ( V_18 ) ;
F_9 ( V_2 , V_7 ) ;
return NULL ;
}
static T_3 * F_8 ( T_2 * V_2 , void * V_27 )
{
int V_28 ;
struct V_17 * V_7 = (struct V_17 * ) V_27 ;
struct V_29 V_30 = { 0 , 0 , 1 } ;
struct V_31 * V_32 =
(struct V_31 * ) F_20 ( V_2 , 1 ) ;
int V_33 ;
int V_34 = 0 ;
if ( ! V_7 )
{
F_5 ( V_35 , V_36 ) ;
return NULL ;
}
if ( ! V_32 )
{
F_5 ( V_35 , V_37 ) ;
return NULL ;
}
if ( V_7 -> V_25 == - 1 )
{
for ( V_28 = 0 ; V_28 < F_21 ( V_7 -> V_11 ) ; V_28 ++ )
{
V_30 . V_38 =
( T_6 * ) F_22 ( V_7 -> V_11 , V_28 ) ;
V_33 = F_23 ( V_32 -> V_9 , ( char * ) & V_30 ) ;
if ( V_33 >= 0 )
{
V_7 -> V_25 = V_33 ;
break;
}
}
}
if ( V_7 -> V_25 < 0 )
return NULL ;
V_30 . V_38 =
( T_6 * ) F_22 ( V_7 -> V_11 ,
V_7 -> V_25 ) ;
for( V_33 = V_7 -> V_25 ;
V_33 < F_21 ( V_32 -> V_9 )
&& F_24 ( V_30 . V_38 ,
( T_6 * ) F_22 ( V_32 -> V_9 , V_33 ) )
&& ! ( V_34 = F_25 ( V_30 . V_38 ,
( T_6 * ) F_22 ( V_32 -> V_9 , V_33 ) ) ) ;
V_33 ++ )
;
V_7 -> V_25 = V_33 ;
if ( V_34 )
return ( (struct V_29 * ) F_22 ( V_32 -> V_9 ,
V_33 ) ) -> V_8 ;
return NULL ;
}
static int F_9 ( T_2 * V_2 , void * V_27 )
{
struct V_17 * V_7 = (struct V_17 * ) V_27 ;
if ( ! V_7 )
{
F_5 ( V_39 , V_36 ) ;
return 0 ;
}
if ( V_7 && V_7 -> V_11 )
F_26 ( V_7 -> V_11 ) ;
if ( V_7 ) F_27 ( V_7 ) ;
return 1 ;
}
static int F_28 ( T_2 * V_2 , void * V_27 )
{
struct V_17 * V_7 = (struct V_17 * ) V_27 ;
if ( ! V_7
|| V_7 -> V_25 == F_21 ( V_7 -> V_11 ) )
return 1 ;
return 0 ;
}
static int F_29 ( T_2 * V_2 , T_5 V_3 [] ,
T_5 V_4 [] )
{
return 1 ;
}
static int F_30 ( T_2 * V_2 , T_5 V_3 [] ,
T_5 V_4 [] )
{
return 1 ;
}
static int F_31 ( T_2 * V_2 , int V_40 , long V_41 , void * V_42 , void (* F_32)( void ) )
{
return 1 ;
}
