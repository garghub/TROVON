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
static int F_11 ( T_2 * V_6 , const char * V_11 , long * line )
{
int V_4 ;
T_3 * V_12 = NULL ;
#ifdef F_12
V_12 = F_13 ( V_11 , L_1 ) ;
#else
V_12 = F_13 ( V_11 , L_2 ) ;
#endif
if ( V_12 == NULL )
{
if ( F_14 ( F_15 () ) == V_13 )
F_16 ( V_14 , V_15 ) ;
else
F_16 ( V_14 , V_16 ) ;
return 0 ;
}
V_4 = F_17 ( V_6 , V_12 , line ) ;
F_18 ( V_12 ) ;
return V_4 ;
}
static int F_17 ( T_2 * V_6 , T_3 * V_12 , long * line )
{
#define F_19 512
int V_17 = 0 , V_18 , V_19 ;
T_4 * V_20 = NULL ;
char * V_21 , * V_22 , * V_23 ;
int V_24 , V_25 ;
long V_26 = 0 ;
char V_27 [ F_20 ( V_26 ) + 1 ] ;
T_5 * V_28 = NULL , * V_29 ;
T_5 * V_30 = NULL ;
char * V_31 = NULL , * V_32 ;
F_21 ( T_5 ) * V_33 = NULL , * V_34 ;
char * V_35 , * V_36 , * V_37 ;
void * V_38 = ( void * ) ( V_6 -> V_9 ) ;
if ( ( V_20 = F_22 () ) == NULL )
{
F_16 ( V_39 , V_40 ) ;
goto V_41;
}
V_31 = ( char * ) F_4 ( 10 ) ;
if ( V_31 == NULL )
{
F_16 ( V_39 , V_42 ) ;
goto V_41;
}
F_23 ( V_31 , L_3 , 10 ) ;
if ( F_24 ( V_6 ) == 0 )
{
F_16 ( V_39 , V_42 ) ;
goto V_41;
}
V_30 = F_25 ( V_6 , V_31 ) ;
if ( V_30 == NULL )
{
F_16 ( V_39 ,
V_43 ) ;
goto V_41;
}
V_33 = ( F_21 ( T_5 ) * ) V_30 -> V_44 ;
V_17 = 0 ;
V_24 = 0 ;
for (; ; )
{
if ( ! F_26 ( V_20 , V_17 + F_19 ) )
{
F_16 ( V_39 , V_40 ) ;
goto V_41;
}
V_22 = & ( V_20 -> V_9 [ V_17 ] ) ;
* V_22 = '\0' ;
F_27 ( V_12 , V_22 , F_19 - 1 ) ;
V_22 [ F_19 - 1 ] = '\0' ;
V_19 = V_18 = strlen ( V_22 ) ;
if ( V_18 == 0 && ! V_24 ) break;
V_24 = 0 ;
while ( V_18 > 0 )
{
if ( ( V_22 [ V_18 - 1 ] != '\r' ) && ( V_22 [ V_18 - 1 ] != '\n' ) )
break;
else
V_18 -- ;
}
if ( V_19 && V_18 == V_19 )
V_24 = 1 ;
else
{
V_22 [ V_18 ] = '\0' ;
V_26 ++ ;
}
V_17 += V_18 ;
V_28 = NULL ;
if ( V_17 >= 1 )
{
V_22 = & ( V_20 -> V_9 [ V_17 - 1 ] ) ;
if ( F_28 ( V_6 , V_22 [ 0 ] ) &&
( ( V_17 <= 1 ) || ! F_28 ( V_6 , V_22 [ - 1 ] ) ) )
{
V_17 -- ;
V_24 = 1 ;
}
}
if ( V_24 ) continue;
V_17 = 0 ;
V_32 = V_20 -> V_9 ;
F_29 ( V_6 , V_32 ) ;
V_25 = strlen ( V_32 ) ;
V_21 = F_30 ( V_6 , V_32 ) ;
if ( F_31 ( V_6 , * V_21 ) ) continue;
if ( * V_21 == '[' )
{
char * V_45 ;
V_21 ++ ;
V_35 = F_30 ( V_6 , V_21 ) ;
V_45 = V_35 ;
V_24:
V_23 = F_32 ( V_6 , V_45 ) ;
V_22 = F_30 ( V_6 , V_23 ) ;
if ( * V_22 != ']' )
{
if ( * V_22 != '\0' )
{
V_45 = V_22 ;
goto V_24;
}
F_16 ( V_39 ,
V_46 ) ;
goto V_41;
}
* V_23 = '\0' ;
if ( ! F_33 ( V_6 , NULL , & V_31 , V_35 ) ) goto V_41;
if ( ( V_30 = F_34 ( V_6 , V_31 ) ) == NULL )
V_30 = F_25 ( V_6 , V_31 ) ;
if ( V_30 == NULL )
{
F_16 ( V_39 ,
V_43 ) ;
goto V_41;
}
V_33 = ( F_21 ( T_5 ) * ) V_30 -> V_44 ;
continue;
}
else
{
V_37 = V_21 ;
V_36 = NULL ;
V_23 = F_32 ( V_6 , V_21 ) ;
if ( ( V_23 [ 0 ] == ':' ) && ( V_23 [ 1 ] == ':' ) )
{
* V_23 = '\0' ;
V_23 += 2 ;
V_36 = V_37 ;
V_37 = V_23 ;
V_23 = F_32 ( V_6 , V_23 ) ;
}
V_22 = F_30 ( V_6 , V_23 ) ;
if ( * V_22 != '=' )
{
F_16 ( V_39 ,
V_47 ) ;
goto V_41;
}
* V_23 = '\0' ;
V_22 ++ ;
V_35 = F_30 ( V_6 , V_22 ) ;
while ( ! F_31 ( V_6 , * V_22 ) )
V_22 ++ ;
V_22 -- ;
while ( ( V_22 != V_35 ) && ( F_35 ( V_6 , * V_22 ) ) )
V_22 -- ;
V_22 ++ ;
* V_22 = '\0' ;
if ( ! ( V_28 = ( T_5 * ) F_4 ( sizeof( T_5 ) ) ) )
{
F_16 ( V_39 ,
V_42 ) ;
goto V_41;
}
if ( V_36 == NULL ) V_36 = V_31 ;
V_28 -> V_11 = ( char * ) F_4 ( strlen ( V_37 ) + 1 ) ;
V_28 -> V_44 = NULL ;
if ( V_28 -> V_11 == NULL )
{
F_16 ( V_39 ,
V_42 ) ;
goto V_41;
}
F_23 ( V_28 -> V_11 , V_37 , strlen ( V_37 ) + 1 ) ;
if ( ! F_33 ( V_6 , V_36 , & ( V_28 -> V_44 ) , V_35 ) ) goto V_41;
if ( strcmp ( V_36 , V_31 ) != 0 )
{
if ( ( V_29 = F_34 ( V_6 , V_36 ) )
== NULL )
V_29 = F_25 ( V_6 , V_36 ) ;
if ( V_29 == NULL )
{
F_16 ( V_39 ,
V_43 ) ;
goto V_41;
}
V_34 = ( F_21 ( T_5 ) * ) V_29 -> V_44 ;
}
else
{
V_29 = V_30 ;
V_34 = V_33 ;
}
#if 1
if ( F_36 ( V_6 , V_29 , V_28 ) == 0 )
{
F_16 ( V_39 ,
V_42 ) ;
goto V_41;
}
#else
V_28 -> V_31 = V_29 -> V_31 ;
if ( ! F_37 ( V_34 , V_28 ) )
{
F_16 ( V_39 ,
V_42 ) ;
goto V_41;
}
V_48 = ( T_5 * ) F_38 ( V_6 -> V_9 , V_28 ) ;
if ( V_48 != NULL )
{
F_39 ( V_34 , V_48 ) ;
F_5 ( V_48 -> V_11 ) ;
F_5 ( V_48 -> V_44 ) ;
F_5 ( V_48 ) ;
}
#endif
V_28 = NULL ;
}
}
if ( V_20 != NULL ) F_40 ( V_20 ) ;
if ( V_31 != NULL ) F_5 ( V_31 ) ;
return ( 1 ) ;
V_41:
if ( V_20 != NULL ) F_40 ( V_20 ) ;
if ( V_31 != NULL ) F_5 ( V_31 ) ;
if ( line != NULL ) * line = V_26 ;
F_41 ( V_27 , sizeof V_27 , L_4 , V_26 ) ;
F_42 ( 2 , L_5 , V_27 ) ;
if ( ( V_38 != V_6 -> V_9 ) && ( V_6 -> V_9 != NULL ) )
{
F_43 ( V_6 -> V_9 ) ;
V_6 -> V_9 = NULL ;
}
if ( V_28 != NULL )
{
if ( V_28 -> V_11 != NULL ) F_5 ( V_28 -> V_11 ) ;
if ( V_28 -> V_44 != NULL ) F_5 ( V_28 -> V_44 ) ;
if ( V_28 != NULL ) F_5 ( V_28 ) ;
}
return ( 0 ) ;
}
static void F_29 ( T_2 * V_6 , char * V_22 )
{
char * V_49 ;
V_49 = V_22 ;
for (; ; )
{
if ( F_44 ( V_6 , * V_22 ) )
{
* V_22 = '\0' ;
return;
}
if ( ! F_35 ( V_6 , * V_22 ) )
{
break;
}
V_22 ++ ;
}
for (; ; )
{
if ( F_45 ( V_6 , * V_22 ) )
{
* V_22 = '\0' ;
return;
}
if ( F_46 ( V_6 , * V_22 ) )
{
V_22 = F_47 ( V_6 , V_22 ) ;
continue;
}
if ( F_48 ( V_6 , * V_22 ) )
{
V_22 = F_49 ( V_6 , V_22 ) ;
continue;
}
if ( F_28 ( V_6 , * V_22 ) )
{
V_22 = F_50 ( V_6 , V_22 ) ;
continue;
}
if ( F_31 ( V_6 , * V_22 ) )
return;
else
V_22 ++ ;
}
}
static int F_33 ( T_2 * V_6 , char * V_31 , char * * V_50 , char * V_51 )
{
int V_52 , V_53 , V_54 = 0 , V_49 = 0 , V_55 = 0 ;
char * V_21 , * V_56 , * V_57 , * V_22 , * V_58 , * V_59 , * V_60 , V_28 ;
T_4 * V_32 ;
if ( ( V_32 = F_22 () ) == NULL ) return ( 0 ) ;
V_55 = strlen ( V_51 ) + 1 ;
if ( ! F_26 ( V_32 , V_55 ) ) goto V_41;
for (; ; )
{
if ( F_48 ( V_6 , * V_51 ) )
{
V_52 = * V_51 ;
V_51 ++ ;
while ( ! F_31 ( V_6 , * V_51 ) && ( * V_51 != V_52 ) )
{
if ( F_28 ( V_6 , * V_51 ) )
{
V_51 ++ ;
if ( F_31 ( V_6 , * V_51 ) ) break;
}
V_32 -> V_9 [ V_49 ++ ] = * ( V_51 ++ ) ;
}
if ( * V_51 == V_52 ) V_51 ++ ;
}
else if ( F_46 ( V_6 , * V_51 ) )
{
V_52 = * V_51 ;
V_51 ++ ;
while ( ! F_31 ( V_6 , * V_51 ) )
{
if ( * V_51 == V_52 )
{
if ( * ( V_51 + 1 ) == V_52 )
{
V_51 ++ ;
}
else
{
break;
}
}
V_32 -> V_9 [ V_49 ++ ] = * ( V_51 ++ ) ;
}
if ( * V_51 == V_52 ) V_51 ++ ;
}
else if ( F_28 ( V_6 , * V_51 ) )
{
V_51 ++ ;
V_28 = * ( V_51 ++ ) ;
if ( F_31 ( V_6 , V_28 ) ) break;
else if ( V_28 == 'r' ) V_28 = '\r' ;
else if ( V_28 == 'n' ) V_28 = '\n' ;
else if ( V_28 == 'b' ) V_28 = '\b' ;
else if ( V_28 == 't' ) V_28 = '\t' ;
V_32 -> V_9 [ V_49 ++ ] = V_28 ;
}
else if ( F_31 ( V_6 , * V_51 ) )
break;
else if ( * V_51 == '$' )
{
V_58 = NULL ;
V_21 = & ( V_51 [ 1 ] ) ;
if ( * V_21 == '{' )
V_52 = '}' ;
else if ( * V_21 == '(' )
V_52 = ')' ;
else V_52 = 0 ;
if ( V_52 ) V_21 ++ ;
V_60 = V_31 ;
V_56 = V_59 = V_21 ;
while ( F_51 ( V_6 , * V_56 ) )
V_56 ++ ;
if ( ( V_56 [ 0 ] == ':' ) && ( V_56 [ 1 ] == ':' ) )
{
V_60 = V_59 ;
V_58 = V_56 ;
V_54 = * V_56 ;
* V_58 = '\0' ;
V_56 += 2 ;
V_59 = V_56 ;
while ( F_51 ( V_6 , * V_56 ) )
V_56 ++ ;
}
V_53 = * V_56 ;
* V_56 = '\0' ;
V_57 = V_56 ;
if ( V_52 )
{
if ( V_53 != V_52 )
{
F_16 ( V_61 , V_62 ) ;
goto V_41;
}
V_56 ++ ;
}
V_22 = F_52 ( V_6 , V_60 , V_59 ) ;
if ( V_58 != NULL ) * V_58 = V_54 ;
* V_57 = V_53 ;
if ( V_22 == NULL )
{
F_16 ( V_61 , V_63 ) ;
goto V_41;
}
F_53 ( V_32 , ( strlen ( V_22 ) + V_32 -> V_64 - ( V_56 - V_51 ) ) ) ;
while ( * V_22 )
V_32 -> V_9 [ V_49 ++ ] = * ( V_22 ++ ) ;
V_55 -= V_56 - V_51 ;
V_51 = V_56 ;
}
else
V_32 -> V_9 [ V_49 ++ ] = * ( V_51 ++ ) ;
}
V_32 -> V_9 [ V_49 ] = '\0' ;
if ( * V_50 != NULL ) F_5 ( * V_50 ) ;
* V_50 = V_32 -> V_9 ;
F_5 ( V_32 ) ;
return ( 1 ) ;
V_41:
if ( V_32 != NULL ) F_40 ( V_32 ) ;
return ( 0 ) ;
}
static char * F_30 ( T_2 * V_6 , char * V_22 )
{
while ( F_35 ( V_6 , * V_22 ) && ( ! F_31 ( V_6 , * V_22 ) ) )
V_22 ++ ;
return ( V_22 ) ;
}
static char * F_32 ( T_2 * V_6 , char * V_22 )
{
for (; ; )
{
if ( F_28 ( V_6 , * V_22 ) )
{
V_22 = F_50 ( V_6 , V_22 ) ;
continue;
}
if ( ! F_54 ( V_6 , * V_22 ) )
return ( V_22 ) ;
V_22 ++ ;
}
}
static char * F_49 ( T_2 * V_6 , char * V_22 )
{
int V_52 = * V_22 ;
V_22 ++ ;
while ( ! ( F_31 ( V_6 , * V_22 ) ) && ( * V_22 != V_52 ) )
{
if ( F_28 ( V_6 , * V_22 ) )
{
V_22 ++ ;
if ( F_31 ( V_6 , * V_22 ) ) return ( V_22 ) ;
}
V_22 ++ ;
}
if ( * V_22 == V_52 ) V_22 ++ ;
return ( V_22 ) ;
}
static char * F_47 ( T_2 * V_6 , char * V_22 )
{
int V_52 = * V_22 ;
V_22 ++ ;
while ( ! ( F_31 ( V_6 , * V_22 ) ) )
{
if ( * V_22 == V_52 )
{
if ( * ( V_22 + 1 ) == V_52 )
{
V_22 ++ ;
}
else
{
break;
}
}
V_22 ++ ;
}
if ( * V_22 == V_52 ) V_22 ++ ;
return ( V_22 ) ;
}
static void F_55 ( T_5 * V_65 , T_3 * V_66 )
{
if ( V_65 -> V_11 )
F_56 ( V_66 , L_6 , V_65 -> V_31 , V_65 -> V_11 , V_65 -> V_44 ) ;
else
F_56 ( V_66 , L_7 , V_65 -> V_31 ) ;
}
static int F_57 ( const T_2 * V_6 , char V_67 )
{
return F_58 ( V_6 , V_67 ) ;
}
static int F_59 ( const T_2 * V_6 , char V_67 )
{
return V_67 - '0' ;
}
