T_1 * F_1 ()
{
return & V_1 ;
}
T_1 * F_2 ()
{
return & V_2 ;
}
static T_2 * F_3 ( T_1 * V_3 )
{
T_2 * V_4 ;
V_4 = ( T_2 * ) F_4 ( sizeof( T_2 ) + sizeof( unsigned short * ) ) ;
if ( V_4 )
if ( V_3 -> V_5 ( V_4 ) == 0 )
{
F_5 ( V_4 ) ;
V_4 = NULL ;
}
return V_4 ;
}
static int F_6 ( T_2 * V_6 )
{
if ( V_6 == NULL )
return 0 ;
V_6 -> V_3 = & V_1 ;
V_6 -> V_7 = ( void * ) V_8 ;
V_6 -> V_9 = NULL ;
return 1 ;
}
static int F_7 ( T_2 * V_6 )
{
if ( V_6 == NULL )
return 0 ;
V_6 -> V_3 = & V_2 ;
V_6 -> V_7 = ( void * ) V_10 ;
V_6 -> V_9 = NULL ;
return 1 ;
}
static int F_8 ( T_2 * V_6 )
{
if ( F_9 ( V_6 ) )
{
F_5 ( V_6 ) ;
return 1 ;
}
return 0 ;
}
static int F_9 ( T_2 * V_6 )
{
if ( V_6 == NULL )
return 0 ;
F_10 ( V_6 ) ;
return 1 ;
}
static int F_11 ( T_2 * V_6 , T_3 * V_11 , long * line )
{
#define F_12 512
char V_12 [ 16 ] ;
int V_13 = 0 , V_14 , V_15 ;
T_4 * V_16 = NULL ;
char * V_17 , * V_18 , * V_19 ;
int V_20 , V_21 ;
long V_22 = 0 ;
T_5 * V_23 = NULL , * V_24 ;
T_5 * V_25 = NULL ;
char * V_26 = NULL , * V_27 ;
F_13 ( T_5 ) * V_28 = NULL , * V_29 ;
char * V_30 , * V_31 , * V_32 ;
void * V_33 = ( void * ) ( V_6 -> V_9 ) ;
if ( ( V_16 = F_14 () ) == NULL )
{
F_15 ( V_34 , V_35 ) ;
goto V_36;
}
V_26 = ( char * ) F_4 ( 10 ) ;
if ( V_26 == NULL )
{
F_15 ( V_34 , V_37 ) ;
goto V_36;
}
strcpy ( V_26 , L_1 ) ;
if ( F_16 ( V_6 ) == 0 )
{
F_15 ( V_34 , V_37 ) ;
goto V_36;
}
V_25 = F_17 ( V_6 , V_26 ) ;
if ( V_25 == NULL )
{
F_15 ( V_34 ,
V_38 ) ;
goto V_36;
}
V_28 = ( F_13 ( T_5 ) * ) V_25 -> V_39 ;
V_13 = 0 ;
for (; ; )
{
V_20 = 0 ;
if ( ! F_18 ( V_16 , V_13 + F_12 ) )
{
F_15 ( V_34 , V_35 ) ;
goto V_36;
}
V_18 = & ( V_16 -> V_9 [ V_13 ] ) ;
* V_18 = '\0' ;
F_19 ( V_11 , V_18 , F_12 - 1 ) ;
V_18 [ F_12 - 1 ] = '\0' ;
V_15 = V_14 = strlen ( V_18 ) ;
if ( V_14 == 0 ) break;
while ( V_14 > 0 )
{
if ( ( V_18 [ V_14 - 1 ] != '\r' ) && ( V_18 [ V_14 - 1 ] != '\n' ) )
break;
else
V_14 -- ;
}
if ( V_14 == V_15 )
V_20 = 1 ;
else
{
V_18 [ V_14 ] = '\0' ;
V_22 ++ ;
}
V_13 += V_14 ;
V_23 = NULL ;
if ( V_13 >= 1 )
{
V_18 = & ( V_16 -> V_9 [ V_13 - 1 ] ) ;
if ( F_20 ( V_6 , V_18 [ 0 ] ) &&
( ( V_13 <= 1 ) || ! F_20 ( V_6 , V_18 [ - 1 ] ) ) )
{
V_13 -- ;
V_20 = 1 ;
}
}
if ( V_20 ) continue;
V_13 = 0 ;
V_27 = V_16 -> V_9 ;
F_21 ( V_6 , V_27 ) ;
V_21 = strlen ( V_27 ) ;
V_17 = F_22 ( V_6 , V_27 ) ;
if ( F_23 ( V_6 , * V_17 ) ) continue;
if ( * V_17 == '[' )
{
char * V_40 ;
V_17 ++ ;
V_30 = F_22 ( V_6 , V_17 ) ;
V_40 = V_30 ;
V_20:
V_19 = F_24 ( V_6 , V_40 ) ;
V_18 = F_22 ( V_6 , V_19 ) ;
if ( * V_18 != ']' )
{
if ( * V_18 != '\0' )
{
V_40 = V_18 ;
goto V_20;
}
F_15 ( V_34 ,
V_41 ) ;
goto V_36;
}
* V_19 = '\0' ;
if ( ! F_25 ( V_6 , NULL , & V_26 , V_30 ) ) goto V_36;
if ( ( V_25 = F_26 ( V_6 , V_26 ) ) == NULL )
V_25 = F_17 ( V_6 , V_26 ) ;
if ( V_25 == NULL )
{
F_15 ( V_34 ,
V_38 ) ;
goto V_36;
}
V_28 = ( F_13 ( T_5 ) * ) V_25 -> V_39 ;
continue;
}
else
{
V_32 = V_17 ;
V_31 = NULL ;
V_19 = F_24 ( V_6 , V_17 ) ;
if ( ( V_19 [ 0 ] == ':' ) && ( V_19 [ 1 ] == ':' ) )
{
* V_19 = '\0' ;
V_19 += 2 ;
V_31 = V_32 ;
V_32 = V_19 ;
V_19 = F_24 ( V_6 , V_19 ) ;
}
V_18 = F_22 ( V_6 , V_19 ) ;
if ( * V_18 != '=' )
{
F_15 ( V_34 ,
V_42 ) ;
goto V_36;
}
* V_19 = '\0' ;
V_18 ++ ;
V_30 = F_22 ( V_6 , V_18 ) ;
while ( ! F_23 ( V_6 , * V_18 ) )
V_18 ++ ;
V_18 -- ;
while ( ( V_18 != V_30 ) && ( F_27 ( V_6 , * V_18 ) ) )
V_18 -- ;
V_18 ++ ;
* V_18 = '\0' ;
if ( ! ( V_23 = ( T_5 * ) F_4 ( sizeof( T_5 ) ) ) )
{
F_15 ( V_34 ,
V_37 ) ;
goto V_36;
}
if ( V_31 == NULL ) V_31 = V_26 ;
V_23 -> V_43 = ( char * ) F_4 ( strlen ( V_32 ) + 1 ) ;
V_23 -> V_39 = NULL ;
if ( V_23 -> V_43 == NULL )
{
F_15 ( V_34 ,
V_37 ) ;
goto V_36;
}
strcpy ( V_23 -> V_43 , V_32 ) ;
if ( ! F_25 ( V_6 , V_31 , & ( V_23 -> V_39 ) , V_30 ) ) goto V_36;
if ( strcmp ( V_31 , V_26 ) != 0 )
{
if ( ( V_24 = F_26 ( V_6 , V_31 ) )
== NULL )
V_24 = F_17 ( V_6 , V_31 ) ;
if ( V_24 == NULL )
{
F_15 ( V_34 ,
V_38 ) ;
goto V_36;
}
V_29 = ( F_13 ( T_5 ) * ) V_24 -> V_39 ;
}
else
{
V_24 = V_25 ;
V_29 = V_28 ;
}
#if 1
if ( F_28 ( V_6 , V_24 , V_23 ) == 0 )
{
F_15 ( V_34 ,
V_37 ) ;
goto V_36;
}
#else
V_23 -> V_26 = V_24 -> V_26 ;
if ( ! F_29 ( V_29 , V_23 ) )
{
F_15 ( V_34 ,
V_37 ) ;
goto V_36;
}
V_44 = ( T_5 * ) F_30 ( V_6 -> V_9 , V_23 ) ;
if ( V_44 != NULL )
{
F_31 ( V_29 , V_44 ) ;
F_5 ( V_44 -> V_43 ) ;
F_5 ( V_44 -> V_39 ) ;
F_5 ( V_44 ) ;
}
#endif
V_23 = NULL ;
}
}
if ( V_16 != NULL ) F_32 ( V_16 ) ;
if ( V_26 != NULL ) F_5 ( V_26 ) ;
return ( 1 ) ;
V_36:
if ( V_16 != NULL ) F_32 ( V_16 ) ;
if ( V_26 != NULL ) F_5 ( V_26 ) ;
if ( line != NULL ) * line = V_22 ;
sprintf ( V_12 , L_2 , V_22 ) ;
F_33 ( 2 , L_3 , V_12 ) ;
if ( ( V_33 != V_6 -> V_9 ) && ( V_6 -> V_9 != NULL ) ) F_34 ( V_6 -> V_9 ) ;
if ( V_23 != NULL )
{
if ( V_23 -> V_43 != NULL ) F_5 ( V_23 -> V_43 ) ;
if ( V_23 -> V_39 != NULL ) F_5 ( V_23 -> V_39 ) ;
if ( V_23 != NULL ) F_5 ( V_23 ) ;
}
return ( 0 ) ;
}
static void F_21 ( T_2 * V_6 , char * V_18 )
{
char * V_45 ;
V_45 = V_18 ;
for (; ; )
{
if ( F_35 ( V_6 , * V_18 ) )
{
* V_18 = '\0' ;
return;
}
if ( ! F_27 ( V_6 , * V_18 ) )
{
break;
}
V_18 ++ ;
}
for (; ; )
{
if ( F_36 ( V_6 , * V_18 ) )
{
* V_18 = '\0' ;
return;
}
if ( F_37 ( V_6 , * V_18 ) )
{
V_18 = F_38 ( V_6 , V_18 ) ;
continue;
}
if ( F_39 ( V_6 , * V_18 ) )
{
V_18 = F_40 ( V_6 , V_18 ) ;
continue;
}
if ( F_20 ( V_6 , * V_18 ) )
{
V_18 = F_41 ( V_6 , V_18 ) ;
continue;
}
if ( F_23 ( V_6 , * V_18 ) )
return;
else
V_18 ++ ;
}
}
static int F_25 ( T_2 * V_6 , char * V_26 , char * * V_46 , char * V_47 )
{
int V_48 , V_49 , V_50 = 0 , V_45 = 0 , V_51 = 0 ;
char * V_17 , * V_52 , * V_53 , * V_18 , * V_54 , * V_55 , * V_56 , V_23 ;
T_4 * V_27 ;
if ( ( V_27 = F_14 () ) == NULL ) return ( 0 ) ;
V_51 = strlen ( V_47 ) + 1 ;
if ( ! F_18 ( V_27 , V_51 ) ) goto V_36;
for (; ; )
{
if ( F_39 ( V_6 , * V_47 ) )
{
V_48 = * V_47 ;
V_47 ++ ;
while ( ! F_23 ( V_6 , * V_47 ) && ( * V_47 != V_48 ) )
{
if ( F_20 ( V_6 , * V_47 ) )
{
V_47 ++ ;
if ( F_23 ( V_6 , * V_47 ) ) break;
}
V_27 -> V_9 [ V_45 ++ ] = * ( V_47 ++ ) ;
}
if ( * V_47 == V_48 ) V_47 ++ ;
}
else if ( F_37 ( V_6 , * V_47 ) )
{
V_48 = * V_47 ;
V_47 ++ ;
while ( ! F_23 ( V_6 , * V_47 ) )
{
if ( * V_47 == V_48 )
{
if ( * ( V_47 + 1 ) == V_48 )
{
V_47 ++ ;
}
else
{
break;
}
}
V_27 -> V_9 [ V_45 ++ ] = * ( V_47 ++ ) ;
}
if ( * V_47 == V_48 ) V_47 ++ ;
}
else if ( F_20 ( V_6 , * V_47 ) )
{
V_47 ++ ;
V_23 = * ( V_47 ++ ) ;
if ( F_23 ( V_6 , V_23 ) ) break;
else if ( V_23 == 'r' ) V_23 = '\r' ;
else if ( V_23 == 'n' ) V_23 = '\n' ;
else if ( V_23 == 'b' ) V_23 = '\b' ;
else if ( V_23 == 't' ) V_23 = '\t' ;
V_27 -> V_9 [ V_45 ++ ] = V_23 ;
}
else if ( F_23 ( V_6 , * V_47 ) )
break;
else if ( * V_47 == '$' )
{
V_54 = NULL ;
V_17 = & ( V_47 [ 1 ] ) ;
if ( * V_17 == '{' )
V_48 = '}' ;
else if ( * V_17 == '(' )
V_48 = ')' ;
else V_48 = 0 ;
if ( V_48 ) V_17 ++ ;
V_56 = V_26 ;
V_52 = V_55 = V_17 ;
while ( F_42 ( V_6 , * V_52 ) )
V_52 ++ ;
if ( ( V_52 [ 0 ] == ':' ) && ( V_52 [ 1 ] == ':' ) )
{
V_56 = V_55 ;
V_54 = V_52 ;
V_50 = * V_52 ;
* V_54 = '\0' ;
V_52 += 2 ;
V_55 = V_52 ;
while ( F_42 ( V_6 , * V_52 ) )
V_52 ++ ;
}
V_49 = * V_52 ;
* V_52 = '\0' ;
V_53 = V_52 ;
if ( V_48 )
{
if ( V_49 != V_48 )
{
F_15 ( V_57 , V_58 ) ;
goto V_36;
}
V_52 ++ ;
}
V_18 = F_43 ( V_6 , V_56 , V_55 ) ;
if ( V_54 != NULL ) * V_54 = V_50 ;
* V_53 = V_49 ;
if ( V_18 == NULL )
{
F_15 ( V_57 , V_59 ) ;
goto V_36;
}
F_18 ( V_27 , ( strlen ( V_18 ) + V_51 - ( V_52 - V_47 ) ) ) ;
while ( * V_18 )
V_27 -> V_9 [ V_45 ++ ] = * ( V_18 ++ ) ;
V_47 = V_52 ;
}
else
V_27 -> V_9 [ V_45 ++ ] = * ( V_47 ++ ) ;
}
V_27 -> V_9 [ V_45 ] = '\0' ;
if ( * V_46 != NULL ) F_5 ( * V_46 ) ;
* V_46 = V_27 -> V_9 ;
F_5 ( V_27 ) ;
return ( 1 ) ;
V_36:
if ( V_27 != NULL ) F_32 ( V_27 ) ;
return ( 0 ) ;
}
static char * F_22 ( T_2 * V_6 , char * V_18 )
{
while ( F_27 ( V_6 , * V_18 ) && ( ! F_23 ( V_6 , * V_18 ) ) )
V_18 ++ ;
return ( V_18 ) ;
}
static char * F_24 ( T_2 * V_6 , char * V_18 )
{
for (; ; )
{
if ( F_20 ( V_6 , * V_18 ) )
{
V_18 = F_41 ( V_6 , V_18 ) ;
continue;
}
if ( ! F_44 ( V_6 , * V_18 ) )
return ( V_18 ) ;
V_18 ++ ;
}
}
static char * F_40 ( T_2 * V_6 , char * V_18 )
{
int V_48 = * V_18 ;
V_18 ++ ;
while ( ! ( F_23 ( V_6 , * V_18 ) ) && ( * V_18 != V_48 ) )
{
if ( F_20 ( V_6 , * V_18 ) )
{
V_18 ++ ;
if ( F_23 ( V_6 , * V_18 ) ) return ( V_18 ) ;
}
V_18 ++ ;
}
if ( * V_18 == V_48 ) V_18 ++ ;
return ( V_18 ) ;
}
static char * F_38 ( T_2 * V_6 , char * V_18 )
{
int V_48 = * V_18 ;
V_18 ++ ;
while ( ! ( F_23 ( V_6 , * V_18 ) ) )
{
if ( * V_18 == V_48 )
{
if ( * ( V_18 + 1 ) == V_48 )
{
V_18 ++ ;
}
else
{
break;
}
}
V_18 ++ ;
}
if ( * V_18 == V_48 ) V_18 ++ ;
return ( V_18 ) ;
}
static void F_45 ( T_5 * V_60 , T_3 * V_61 )
{
if ( V_60 -> V_43 )
F_46 ( V_61 , L_4 , V_60 -> V_26 , V_60 -> V_43 , V_60 -> V_39 ) ;
else
F_46 ( V_61 , L_5 , V_60 -> V_26 ) ;
}
static int F_47 ( T_2 * V_6 , T_3 * V_61 )
{
F_48 ( V_6 -> V_9 , ( void ( * ) () ) F_45 , V_61 ) ;
return 1 ;
}
static int F_49 ( T_2 * V_6 , char V_62 )
{
return F_50 ( V_6 , V_62 ) ;
}
static int F_51 ( T_2 * V_6 , char V_62 )
{
return V_62 - '0' ;
}
