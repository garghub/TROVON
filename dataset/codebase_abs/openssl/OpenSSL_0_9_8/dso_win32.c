T_1 * F_1 ( void )
{
return NULL ;
}
static T_2 F_2 ( T_3 V_1 , T_4 V_2 )
{
T_5 V_3 [ 64 ] ;
int V_4 ;
for ( V_4 = 0 ; V_2 [ V_4 ] && V_4 < 64 ; V_4 ++ )
V_3 [ V_4 ] = ( T_5 ) V_2 [ V_4 ] ;
if ( V_4 == 64 ) return NULL ;
V_3 [ V_4 ] = 0 ;
return F_3 ( V_1 , V_3 ) ;
}
T_1 * F_1 ( void )
{
return ( & V_5 ) ;
}
static int F_4 ( T_6 * V_6 )
{
T_7 V_7 = NULL , * V_8 = NULL ;
char * V_9 = F_5 ( V_6 , NULL ) ;
if( V_9 == NULL )
{
F_6 ( V_10 , V_11 ) ;
goto V_12;
}
V_7 = F_7 ( V_9 ) ;
if( V_7 == NULL )
{
F_6 ( V_10 , V_13 ) ;
F_8 ( 3 , L_1 , V_9 , L_2 ) ;
goto V_12;
}
V_8 = ( T_7 * ) F_9 ( sizeof( T_7 ) ) ;
if( V_8 == NULL )
{
F_6 ( V_10 , V_14 ) ;
goto V_12;
}
* V_8 = V_7 ;
if( ! F_10 ( V_6 -> V_15 , ( char * ) V_8 ) )
{
F_6 ( V_10 , V_16 ) ;
goto V_12;
}
V_6 -> V_17 = V_9 ;
return ( 1 ) ;
V_12:
if( V_9 != NULL )
F_11 ( V_9 ) ;
if( V_8 != NULL )
F_11 ( V_8 ) ;
if( V_7 != NULL )
F_12 ( V_7 ) ;
return ( 0 ) ;
}
static int F_13 ( T_6 * V_6 )
{
T_7 * V_8 ;
if( V_6 == NULL )
{
F_6 ( V_18 , V_19 ) ;
return ( 0 ) ;
}
if( F_14 ( V_6 -> V_15 ) < 1 )
return ( 1 ) ;
V_8 = ( T_7 * ) F_15 ( V_6 -> V_15 ) ;
if( V_8 == NULL )
{
F_6 ( V_18 , V_20 ) ;
return ( 0 ) ;
}
if( ! F_12 ( * V_8 ) )
{
F_6 ( V_18 , V_21 ) ;
F_10 ( V_6 -> V_15 , ( char * ) V_8 ) ;
return ( 0 ) ;
}
F_11 ( V_8 ) ;
return ( 1 ) ;
}
static void * F_16 ( T_6 * V_6 , const char * V_22 )
{
T_7 * V_23 ;
void * V_24 ;
if( ( V_6 == NULL ) || ( V_22 == NULL ) )
{
F_6 ( V_25 , V_19 ) ;
return ( NULL ) ;
}
if( F_14 ( V_6 -> V_15 ) < 1 )
{
F_6 ( V_25 , V_16 ) ;
return ( NULL ) ;
}
V_23 = ( T_7 * ) F_17 ( V_6 -> V_15 , F_14 ( V_6 -> V_15 ) - 1 ) ;
if( V_23 == NULL )
{
F_6 ( V_25 , V_20 ) ;
return ( NULL ) ;
}
V_24 = F_18 ( * V_23 , V_22 ) ;
if( V_24 == NULL )
{
F_6 ( V_25 , V_26 ) ;
F_8 ( 3 , L_3 , V_22 , L_2 ) ;
return ( NULL ) ;
}
return ( V_24 ) ;
}
static T_8 F_19 ( T_6 * V_6 , const char * V_22 )
{
T_7 * V_23 ;
void * V_24 ;
if( ( V_6 == NULL ) || ( V_22 == NULL ) )
{
F_6 ( V_27 , V_19 ) ;
return ( NULL ) ;
}
if( F_14 ( V_6 -> V_15 ) < 1 )
{
F_6 ( V_27 , V_16 ) ;
return ( NULL ) ;
}
V_23 = ( T_7 * ) F_17 ( V_6 -> V_15 , F_14 ( V_6 -> V_15 ) - 1 ) ;
if( V_23 == NULL )
{
F_6 ( V_27 , V_20 ) ;
return ( NULL ) ;
}
V_24 = F_18 ( * V_23 , V_22 ) ;
if( V_24 == NULL )
{
F_6 ( V_27 , V_26 ) ;
F_8 ( 3 , L_3 , V_22 , L_2 ) ;
return ( NULL ) ;
}
return ( ( T_8 ) V_24 ) ;
}
static struct V_28 * F_20 ( T_6 * V_6 , const char * V_9 ,
int V_29 )
{
struct V_28 * V_30 = NULL ;
enum { V_31 , V_32 , V_33 } V_34 ;
const char * V_35 = V_9 ;
if ( ! V_9 )
{
F_6 ( V_36 , V_11 ) ;
return ( NULL ) ;
}
V_30 = F_9 ( sizeof( struct V_28 ) ) ;
if( V_30 == NULL )
{
F_6 ( V_36 ,
V_14 ) ;
return ( NULL ) ;
}
memset ( V_30 , 0 , sizeof( struct V_28 ) ) ;
V_34 = V_32 ;
if( V_9 [ 0 ] == '\\' && V_9 [ 1 ] == '\\'
|| V_9 [ 0 ] == '/' && V_9 [ 1 ] == '/' )
{
V_34 = V_31 ;
V_9 += 2 ;
V_35 = V_9 ;
V_30 -> V_37 = V_35 ;
}
do
{
switch( V_9 [ 0 ] )
{
case ':' :
if( V_34 != V_32 )
{
F_6 ( V_36 ,
V_38 ) ;
return ( NULL ) ;
}
V_30 -> V_39 = V_35 ;
V_30 -> V_40 = V_9 - V_35 ;
V_34 = V_33 ;
V_35 = ++ V_9 ;
V_30 -> V_41 = V_35 ;
break;
case '\\' :
case '/' :
if( V_34 == V_31 )
{
V_30 -> V_42 = V_9 - V_35 ;
V_34 = V_33 ;
V_35 = ++ V_9 ;
V_30 -> V_41 = V_35 ;
}
else
{
V_9 ++ ;
V_30 -> V_43 += V_9 - V_35 ;
}
break;
case '\0' :
if( V_34 == V_31 )
{
V_30 -> V_42 = V_9 - V_35 ;
}
else
{
if( V_9 - V_35 > 0 )
{
if ( V_29 )
{
V_30 -> V_40 += V_9 - V_35 ;
}
else
{
V_30 -> V_44 = V_35 ;
V_30 -> V_45 = V_9 - V_35 ;
}
}
}
break;
default:
V_9 ++ ;
break;
}
}
while( * V_9 );
if( ! V_30 -> V_42 ) V_30 -> V_37 = NULL ;
if( ! V_30 -> V_40 ) V_30 -> V_39 = NULL ;
if( ! V_30 -> V_43 ) V_30 -> V_41 = NULL ;
if( ! V_30 -> V_45 ) V_30 -> V_44 = NULL ;
return ( V_30 ) ;
}
static char * F_21 ( T_6 * V_6 , const struct V_28 * V_46 )
{
int V_47 = 0 , V_48 = 0 ;
char * V_30 = NULL ;
const char * V_35 ;
if( ! V_46 )
{
F_6 ( V_49 ,
V_19 ) ;
return ( NULL ) ;
}
if( V_46 -> V_37 )
{
V_47 += 2 + V_46 -> V_42 ;
if( V_46 -> V_50 || V_46 -> V_41 || V_46 -> V_44 )
V_47 ++ ;
}
else if( V_46 -> V_39 )
{
V_47 += V_46 -> V_40 + 1 ;
}
V_47 += V_46 -> V_51 ;
if( V_46 -> V_50 && ( V_46 -> V_41 || V_46 -> V_44 ) )
{
V_47 ++ ;
}
V_47 += V_46 -> V_43 ;
if( V_46 -> V_41 && V_46 -> V_44 )
{
V_47 ++ ;
}
V_47 += V_46 -> V_45 ;
if( ! V_47 )
{
F_6 ( V_49 , V_52 ) ;
return ( NULL ) ;
}
V_30 = F_9 ( V_47 + 1 ) ;
if ( ! V_30 )
{
F_6 ( V_49 ,
V_14 ) ;
return ( NULL ) ;
}
if( V_46 -> V_37 )
{
strcpy ( & V_30 [ V_48 ] , L_4 ) ; V_48 += 2 ;
strncpy ( & V_30 [ V_48 ] , V_46 -> V_37 ,
V_46 -> V_42 ) ; V_48 += V_46 -> V_42 ;
if( V_46 -> V_50 || V_46 -> V_41 || V_46 -> V_44 )
{
V_30 [ V_48 ] = '\\' ; V_48 ++ ;
}
}
else if( V_46 -> V_39 )
{
strncpy ( & V_30 [ V_48 ] , V_46 -> V_39 ,
V_46 -> V_40 ) ; V_48 += V_46 -> V_40 ;
V_30 [ V_48 ] = ':' ; V_48 ++ ;
}
V_35 = V_46 -> V_50 ;
while( V_46 -> V_51 > ( V_35 - V_46 -> V_50 ) )
{
const char * V_53 = F_22 ( V_35 , '/' ,
V_46 -> V_51 - ( V_35 - V_46 -> V_50 ) ) ;
if( ! V_53 )
V_53 = V_35
+ V_46 -> V_51
- ( V_35 - V_46 -> V_50 ) ;
strncpy ( & V_30 [ V_48 ] , V_35 ,
V_53 - V_35 ) ; V_48 += V_53 - V_35 ;
V_30 [ V_48 ] = '\\' ; V_48 ++ ;
V_35 = V_53 + 1 ;
}
if( V_46 -> V_50 && ( V_46 -> V_41 || V_46 -> V_44 ) )
{
V_30 [ V_48 ] = '\\' ; V_48 ++ ;
}
V_35 = V_46 -> V_41 ;
while( V_46 -> V_43 > ( V_35 - V_46 -> V_41 ) )
{
const char * V_53 = F_22 ( V_35 , '/' ,
V_46 -> V_43 - ( V_35 - V_46 -> V_41 ) ) ;
if( ! V_53 )
V_53 = V_35
+ V_46 -> V_43
- ( V_35 - V_46 -> V_41 ) ;
strncpy ( & V_30 [ V_48 ] , V_35 ,
V_53 - V_35 ) ; V_48 += V_53 - V_35 ;
V_30 [ V_48 ] = '\\' ; V_48 ++ ;
V_35 = V_53 + 1 ;
}
if( V_46 -> V_41 && V_46 -> V_44 )
{
V_30 [ V_48 ] = '\\' ; V_48 ++ ;
}
strncpy ( & V_30 [ V_48 ] , V_46 -> V_44 ,
V_46 -> V_45 ) ; V_48 += V_46 -> V_45 ;
V_30 [ V_48 ] = '\0' ;
return ( V_30 ) ;
}
static char * F_23 ( T_6 * V_6 , const char * V_54 , const char * V_55 )
{
char * V_56 = NULL ;
struct V_28 * V_57 = NULL ;
struct V_28 * V_58 = NULL ;
if( ! V_54 && ! V_55 )
{
F_6 ( V_59 ,
V_19 ) ;
return ( NULL ) ;
}
if ( ! V_55 )
{
V_56 = F_9 ( strlen ( V_54 ) + 1 ) ;
if( ! V_56 )
{
F_6 ( V_59 ,
V_14 ) ;
return ( NULL ) ;
}
strcpy ( V_56 , V_54 ) ;
}
else if ( ! V_54 )
{
V_56 = F_9 ( strlen ( V_55 ) + 1 ) ;
if( ! V_56 )
{
F_6 ( V_59 ,
V_14 ) ;
return ( NULL ) ;
}
strcpy ( V_56 , V_55 ) ;
}
else
{
V_57 = F_20 ( V_6 , V_54 , 1 ) ;
if ( ! V_57 )
{
F_6 ( V_59 ,
V_14 ) ;
return ( NULL ) ;
}
V_58 = F_20 ( V_6 , V_55 , 0 ) ;
if ( ! V_57 )
{
F_6 ( V_59 ,
V_14 ) ;
F_11 ( V_57 ) ;
return ( NULL ) ;
}
if ( ! V_57 -> V_37 && ! V_57 -> V_39 )
{
V_57 -> V_37 = V_58 -> V_37 ;
V_57 -> V_42 = V_58 -> V_42 ;
V_57 -> V_39 = V_58 -> V_39 ;
V_57 -> V_40 = V_58 -> V_40 ;
}
if ( ! V_57 -> V_41 )
{
V_57 -> V_41 = V_58 -> V_41 ;
V_57 -> V_43 = V_58 -> V_43 ;
}
else if ( V_57 -> V_41 [ 0 ] != '\\'
&& V_57 -> V_41 [ 0 ] != '/' )
{
V_57 -> V_50 = V_58 -> V_41 ;
V_57 -> V_51 = V_58 -> V_43 ;
}
if ( ! V_57 -> V_44 )
{
V_57 -> V_44 = V_58 -> V_44 ;
V_57 -> V_45 = V_58 -> V_45 ;
}
V_56 = F_21 ( V_6 , V_57 ) ;
}
return ( V_56 ) ;
}
static char * F_24 ( T_6 * V_6 , const char * V_9 )
{
char * V_60 ;
int V_47 , V_61 ;
V_47 = strlen ( V_9 ) ;
V_61 = ( ( strstr ( V_9 , L_5 ) == NULL ) &&
( strstr ( V_9 , L_6 ) == NULL ) &&
( strstr ( V_9 , L_7 ) == NULL ) ) ;
if( V_61 )
V_60 = F_9 ( V_47 + 5 ) ;
else
V_60 = F_9 ( V_47 + 1 ) ;
if( V_60 == NULL )
{
F_6 ( V_62 ,
V_63 ) ;
return ( NULL ) ;
}
if( V_61 )
sprintf ( V_60 , L_8 , V_9 ) ;
else
sprintf ( V_60 , L_9 , V_9 ) ;
return ( V_60 ) ;
}
static const char * F_22 ( const char * string , int V_64 , T_9 V_47 )
{
T_9 V_4 ;
const char * V_8 ;
for ( V_4 = 0 , V_8 = string ; V_4 < V_47 && * V_8 ; V_4 ++ , V_8 ++ )
{
if ( * V_8 == V_64 )
return V_8 ;
}
return NULL ;
}
