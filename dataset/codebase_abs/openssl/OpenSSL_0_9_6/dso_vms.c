T_1 * F_1 ( void )
{
return NULL ;
}
T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , const char * V_3 )
{
T_3 * V_4 ;
const char * V_5 , * V_6 ;
V_5 = strrchr ( V_3 , ']' ) ;
V_6 = strrchr ( V_3 , '>' ) ;
if ( V_5 == NULL ) V_5 = V_6 ;
if ( V_6 != NULL && V_6 > V_5 ) V_5 = V_6 ;
if ( V_5 == NULL ) V_5 = strrchr ( V_3 , ':' ) ;
if ( V_5 == NULL )
V_5 = V_3 ;
else
V_5 ++ ;
V_6 = strchr ( V_5 , '.' ) ;
if ( V_6 == NULL ) V_6 = strchr ( V_5 , ';' ) ;
if ( V_6 == NULL ) V_6 = V_5 + strlen ( V_5 ) ;
if ( V_6 - V_5 > V_7
|| ( V_5 - V_3 ) + strlen ( V_6 ) > V_7 )
{
F_3 ( V_8 , V_9 ) ;
return ( 0 ) ;
}
V_4 = ( T_3 * ) F_4 ( sizeof( T_3 ) ) ;
if( V_4 == NULL )
{
F_3 ( V_8 , V_10 ) ;
return ( 0 ) ;
}
strncpy ( V_4 -> V_3 , V_5 , V_6 - V_5 ) ;
V_4 -> V_3 [ V_6 - V_5 ] = '\0' ;
strncpy ( V_4 -> V_11 , V_3 , V_5 - V_3 ) ;
V_4 -> V_11 [ V_5 - V_3 ] = '\0' ;
strcat ( V_4 -> V_11 , V_6 ) ;
V_4 -> V_12 . V_13 = strlen ( V_4 -> V_3 ) ;
V_4 -> V_12 . V_14 = V_15 ;
V_4 -> V_12 . V_16 = V_17 ;
V_4 -> V_12 . V_18 = V_4 -> V_3 ;
V_4 -> V_19 . V_13 = strlen ( V_4 -> V_11 ) ;
V_4 -> V_19 . V_14 = V_15 ;
V_4 -> V_19 . V_16 = V_17 ;
V_4 -> V_19 . V_18 = V_4 -> V_11 ;
if( ! F_5 ( V_2 -> V_20 , ( char * ) V_4 ) )
{
F_3 ( V_8 , V_21 ) ;
F_6 ( V_4 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_7 ( T_2 * V_2 )
{
T_3 * V_4 ;
if( V_2 == NULL )
{
F_3 ( V_22 , V_23 ) ;
return ( 0 ) ;
}
if( F_8 ( V_2 -> V_20 ) < 1 )
return ( 1 ) ;
V_4 = ( T_3 * ) F_9 ( V_2 -> V_20 ) ;
if( V_4 == NULL )
{
F_3 ( V_22 , V_24 ) ;
return ( 0 ) ;
}
F_6 ( V_4 ) ;
return ( 1 ) ;
}
static int F_10 ( T_3 * V_25 ,
struct V_26 * V_27 , void * * V_28 ,
unsigned long V_29 )
{
F_11 ( V_30 ) ;
if( V_25 -> V_19 . V_13 )
return F_12 ( & V_25 -> V_12 ,
V_27 , V_28 ,
& V_25 -> V_19 , V_29 ) ;
else
return F_12 ( & V_25 -> V_12 ,
V_27 , V_28 ,
0 , V_29 ) ;
}
void F_13 ( T_2 * V_2 , const char * V_31 , void * * V_28 )
{
T_3 * V_25 ;
int V_32 ;
int V_29 = V_33 ;
struct V_26 V_27 ;
* V_28 = NULL ;
V_27 . V_13 = strlen ( V_31 ) ;
V_27 . V_14 = V_15 ;
V_27 . V_16 = V_17 ;
V_27 . V_18 = ( char * ) V_31 ;
if( ( V_2 == NULL ) || ( V_31 == NULL ) )
{
F_3 ( V_34 , V_23 ) ;
return;
}
if( F_8 ( V_2 -> V_20 ) < 1 )
{
F_3 ( V_34 , V_21 ) ;
return;
}
V_25 = ( T_3 * ) F_14 ( V_2 -> V_20 ,
F_8 ( V_2 -> V_20 ) - 1 ) ;
if( V_25 == NULL )
{
F_3 ( V_34 , V_24 ) ;
return;
}
if( V_2 -> V_29 & V_35 ) V_29 = 0 ;
V_32 = F_10 ( V_25 , & V_27 , V_28 , V_29 ) ;
if( ! F_15 ( V_32 ) )
{
unsigned short V_36 ;
char V_37 [ 257 ] ;
struct V_26 V_38 ;
V_38 . V_13 = sizeof( V_37 ) ;
V_38 . V_14 = V_15 ;
V_38 . V_16 = V_17 ;
V_38 . V_18 = V_37 ;
* V_28 = NULL ;
V_32 = F_16 ( V_32 , & V_36 , & V_38 , 1 , 0 ) ;
if ( ! F_15 ( V_32 ) )
F_17 ( V_32 ) ;
else
{
V_37 [ V_36 ] = '\0' ;
F_3 ( V_34 , V_39 ) ;
if ( V_25 -> V_19 . V_13 )
F_18 ( 9 ,
L_1 , V_31 ,
L_2 , V_25 -> V_3 ,
L_3 , V_25 -> V_11 , L_4 ,
L_5 , V_37 ) ;
else
F_18 ( 6 ,
L_1 , V_31 ,
L_2 , V_25 -> V_3 ,
L_5 , V_37 ) ;
}
return;
}
return;
}
static void * F_19 ( T_2 * V_2 , const char * V_31 )
{
void * V_28 = 0 ;
F_13 ( V_2 , V_31 , & V_28 ) ;
return V_28 ;
}
static T_4 F_20 ( T_2 * V_2 , const char * V_31 )
{
T_4 V_28 = 0 ;
F_13 ( V_2 , V_31 , ( void * * ) & V_28 ) ;
return V_28 ;
}
static long F_21 ( T_2 * V_2 , int V_40 , long V_41 , void * V_42 )
{
if( V_2 == NULL )
{
F_3 ( V_43 , V_23 ) ;
return ( - 1 ) ;
}
switch( V_40 )
{
case V_44 :
return V_2 -> V_29 ;
case V_45 :
V_2 -> V_29 = ( int ) V_41 ;
return ( 0 ) ;
case V_46 :
V_2 -> V_29 |= ( int ) V_41 ;
return ( 0 ) ;
default:
break;
}
F_3 ( V_43 , V_47 ) ;
return ( - 1 ) ;
}
