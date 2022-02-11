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
V_4 = F_4 ( sizeof( T_2 ) + sizeof( unsigned short * ) ) ;
if ( V_4 )
if ( V_3 -> V_5 ( V_4 ) == 0 ) {
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
V_6 -> V_7 = V_8 ;
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
if ( F_9 ( V_6 ) ) {
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
if ( V_12 == NULL ) {
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
int V_24 ;
long V_25 = 0 ;
char V_26 [ F_20 ( V_25 ) + 1 ] ;
T_5 * V_27 = NULL , * V_28 ;
T_5 * V_29 = NULL ;
char * V_30 = NULL , * V_31 ;
char * V_32 , * V_33 , * V_34 ;
void * V_35 = ( void * ) ( V_6 -> V_9 ) ;
if ( ( V_20 = F_21 () ) == NULL ) {
F_16 ( V_36 , V_37 ) ;
goto V_38;
}
V_30 = ( char * ) F_4 ( 10 ) ;
if ( V_30 == NULL ) {
F_16 ( V_36 , V_39 ) ;
goto V_38;
}
F_22 ( V_30 , L_3 , 10 ) ;
if ( F_23 ( V_6 ) == 0 ) {
F_16 ( V_36 , V_39 ) ;
goto V_38;
}
V_29 = F_24 ( V_6 , V_30 ) ;
if ( V_29 == NULL ) {
F_16 ( V_36 , V_40 ) ;
goto V_38;
}
V_17 = 0 ;
V_24 = 0 ;
for (; ; ) {
if ( ! F_25 ( V_20 , V_17 + F_19 ) ) {
F_16 ( V_36 , V_37 ) ;
goto V_38;
}
V_22 = & ( V_20 -> V_9 [ V_17 ] ) ;
* V_22 = '\0' ;
F_26 ( V_12 , V_22 , F_19 - 1 ) ;
V_22 [ F_19 - 1 ] = '\0' ;
V_19 = V_18 = strlen ( V_22 ) ;
if ( V_18 == 0 && ! V_24 )
break;
V_24 = 0 ;
while ( V_18 > 0 ) {
if ( ( V_22 [ V_18 - 1 ] != '\r' ) && ( V_22 [ V_18 - 1 ] != '\n' ) )
break;
else
V_18 -- ;
}
if ( V_19 && V_18 == V_19 )
V_24 = 1 ;
else {
V_22 [ V_18 ] = '\0' ;
V_25 ++ ;
}
V_17 += V_18 ;
V_27 = NULL ;
if ( V_17 >= 1 ) {
V_22 = & ( V_20 -> V_9 [ V_17 - 1 ] ) ;
if ( F_27 ( V_6 , V_22 [ 0 ] ) && ( ( V_17 <= 1 ) || ! F_27 ( V_6 , V_22 [ - 1 ] ) ) ) {
V_17 -- ;
V_24 = 1 ;
}
}
if ( V_24 )
continue;
V_17 = 0 ;
V_31 = V_20 -> V_9 ;
F_28 ( V_6 , V_31 ) ;
V_21 = F_29 ( V_6 , V_31 ) ;
if ( F_30 ( V_6 , * V_21 ) )
continue;
if ( * V_21 == '[' ) {
char * V_41 ;
V_21 ++ ;
V_32 = F_29 ( V_6 , V_21 ) ;
V_41 = V_32 ;
V_24:
V_23 = F_31 ( V_6 , V_41 ) ;
V_22 = F_29 ( V_6 , V_23 ) ;
if ( * V_22 != ']' ) {
if ( * V_22 != '\0' && V_41 != V_22 ) {
V_41 = V_22 ;
goto V_24;
}
F_16 ( V_36 ,
V_42 ) ;
goto V_38;
}
* V_23 = '\0' ;
if ( ! F_32 ( V_6 , NULL , & V_30 , V_32 ) )
goto V_38;
if ( ( V_29 = F_33 ( V_6 , V_30 ) ) == NULL )
V_29 = F_24 ( V_6 , V_30 ) ;
if ( V_29 == NULL ) {
F_16 ( V_36 ,
V_40 ) ;
goto V_38;
}
continue;
} else {
V_34 = V_21 ;
V_33 = NULL ;
V_23 = F_31 ( V_6 , V_21 ) ;
if ( ( V_23 [ 0 ] == ':' ) && ( V_23 [ 1 ] == ':' ) ) {
* V_23 = '\0' ;
V_23 += 2 ;
V_33 = V_34 ;
V_34 = V_23 ;
V_23 = F_31 ( V_6 , V_23 ) ;
}
V_22 = F_29 ( V_6 , V_23 ) ;
if ( * V_22 != '=' ) {
F_16 ( V_36 , V_43 ) ;
goto V_38;
}
* V_23 = '\0' ;
V_22 ++ ;
V_32 = F_29 ( V_6 , V_22 ) ;
while ( ! F_30 ( V_6 , * V_22 ) )
V_22 ++ ;
V_22 -- ;
while ( ( V_22 != V_32 ) && ( F_34 ( V_6 , * V_22 ) ) )
V_22 -- ;
V_22 ++ ;
* V_22 = '\0' ;
if ( ! ( V_27 = ( T_5 * ) F_4 ( sizeof( T_5 ) ) ) ) {
F_16 ( V_36 , V_39 ) ;
goto V_38;
}
if ( V_33 == NULL )
V_33 = V_30 ;
V_27 -> V_11 = ( char * ) F_4 ( strlen ( V_34 ) + 1 ) ;
V_27 -> V_44 = NULL ;
if ( V_27 -> V_11 == NULL ) {
F_16 ( V_36 , V_39 ) ;
goto V_38;
}
F_22 ( V_27 -> V_11 , V_34 , strlen ( V_34 ) + 1 ) ;
if ( ! F_32 ( V_6 , V_33 , & ( V_27 -> V_44 ) , V_32 ) )
goto V_38;
if ( strcmp ( V_33 , V_30 ) != 0 ) {
if ( ( V_28 = F_33 ( V_6 , V_33 ) )
== NULL )
V_28 = F_24 ( V_6 , V_33 ) ;
if ( V_28 == NULL ) {
F_16 ( V_36 ,
V_40 ) ;
goto V_38;
}
} else
V_28 = V_29 ;
#if 1
if ( F_35 ( V_6 , V_28 , V_27 ) == 0 ) {
F_16 ( V_36 , V_39 ) ;
goto V_38;
}
#else
V_27 -> V_30 = V_28 -> V_30 ;
if ( ! F_36 ( V_45 , V_27 ) ) {
F_16 ( V_36 , V_39 ) ;
goto V_38;
}
V_46 = ( T_5 * ) F_37 ( V_6 -> V_9 , V_27 ) ;
if ( V_46 != NULL ) {
F_38 ( V_45 , V_46 ) ;
F_5 ( V_46 -> V_11 ) ;
F_5 ( V_46 -> V_44 ) ;
F_5 ( V_46 ) ;
}
#endif
V_27 = NULL ;
}
}
if ( V_20 != NULL )
F_39 ( V_20 ) ;
if ( V_30 != NULL )
F_5 ( V_30 ) ;
return ( 1 ) ;
V_38:
if ( V_20 != NULL )
F_39 ( V_20 ) ;
if ( V_30 != NULL )
F_5 ( V_30 ) ;
if ( line != NULL )
* line = V_25 ;
F_40 ( V_26 , sizeof V_26 , L_4 , V_25 ) ;
F_41 ( 2 , L_5 , V_26 ) ;
if ( ( V_35 != V_6 -> V_9 ) && ( V_6 -> V_9 != NULL ) ) {
F_42 ( V_6 -> V_9 ) ;
V_6 -> V_9 = NULL ;
}
if ( V_27 != NULL ) {
if ( V_27 -> V_11 != NULL )
F_5 ( V_27 -> V_11 ) ;
if ( V_27 -> V_44 != NULL )
F_5 ( V_27 -> V_44 ) ;
if ( V_27 != NULL )
F_5 ( V_27 ) ;
}
return ( 0 ) ;
}
static void F_28 ( T_2 * V_6 , char * V_22 )
{
for (; ; ) {
if ( F_43 ( V_6 , * V_22 ) ) {
* V_22 = '\0' ;
return;
}
if ( ! F_34 ( V_6 , * V_22 ) ) {
break;
}
V_22 ++ ;
}
for (; ; ) {
if ( F_44 ( V_6 , * V_22 ) ) {
* V_22 = '\0' ;
return;
}
if ( F_45 ( V_6 , * V_22 ) ) {
V_22 = F_46 ( V_6 , V_22 ) ;
continue;
}
if ( F_47 ( V_6 , * V_22 ) ) {
V_22 = F_48 ( V_6 , V_22 ) ;
continue;
}
if ( F_27 ( V_6 , * V_22 ) ) {
V_22 = F_49 ( V_6 , V_22 ) ;
continue;
}
if ( F_30 ( V_6 , * V_22 ) )
return;
else
V_22 ++ ;
}
}
static int F_32 ( T_2 * V_6 , char * V_30 , char * * V_47 , char * V_48 )
{
int V_49 , V_50 , V_51 = 0 , V_52 = 0 , V_53 = 0 ;
char * V_21 , * V_54 , * V_55 , * V_22 , * V_56 , * V_57 , * V_58 , V_27 ;
T_4 * V_31 ;
if ( ( V_31 = F_21 () ) == NULL )
return ( 0 ) ;
V_53 = strlen ( V_48 ) + 1 ;
if ( ! F_25 ( V_31 , V_53 ) )
goto V_38;
for (; ; ) {
if ( F_47 ( V_6 , * V_48 ) ) {
V_49 = * V_48 ;
V_48 ++ ;
while ( ! F_30 ( V_6 , * V_48 ) && ( * V_48 != V_49 ) ) {
if ( F_27 ( V_6 , * V_48 ) ) {
V_48 ++ ;
if ( F_30 ( V_6 , * V_48 ) )
break;
}
V_31 -> V_9 [ V_52 ++ ] = * ( V_48 ++ ) ;
}
if ( * V_48 == V_49 )
V_48 ++ ;
} else if ( F_45 ( V_6 , * V_48 ) ) {
V_49 = * V_48 ;
V_48 ++ ;
while ( ! F_30 ( V_6 , * V_48 ) ) {
if ( * V_48 == V_49 ) {
if ( * ( V_48 + 1 ) == V_49 ) {
V_48 ++ ;
} else {
break;
}
}
V_31 -> V_9 [ V_52 ++ ] = * ( V_48 ++ ) ;
}
if ( * V_48 == V_49 )
V_48 ++ ;
} else if ( F_27 ( V_6 , * V_48 ) ) {
V_48 ++ ;
V_27 = * ( V_48 ++ ) ;
if ( F_30 ( V_6 , V_27 ) )
break;
else if ( V_27 == 'r' )
V_27 = '\r' ;
else if ( V_27 == 'n' )
V_27 = '\n' ;
else if ( V_27 == 'b' )
V_27 = '\b' ;
else if ( V_27 == 't' )
V_27 = '\t' ;
V_31 -> V_9 [ V_52 ++ ] = V_27 ;
} else if ( F_30 ( V_6 , * V_48 ) )
break;
else if ( * V_48 == '$' ) {
V_56 = NULL ;
V_21 = & ( V_48 [ 1 ] ) ;
if ( * V_21 == '{' )
V_49 = '}' ;
else if ( * V_21 == '(' )
V_49 = ')' ;
else
V_49 = 0 ;
if ( V_49 )
V_21 ++ ;
V_58 = V_30 ;
V_54 = V_57 = V_21 ;
while ( F_50 ( V_6 , * V_54 ) )
V_54 ++ ;
if ( ( V_54 [ 0 ] == ':' ) && ( V_54 [ 1 ] == ':' ) ) {
V_58 = V_57 ;
V_56 = V_54 ;
V_51 = * V_54 ;
* V_56 = '\0' ;
V_54 += 2 ;
V_57 = V_54 ;
while ( F_50 ( V_6 , * V_54 ) )
V_54 ++ ;
}
V_50 = * V_54 ;
* V_54 = '\0' ;
V_55 = V_54 ;
if ( V_49 ) {
if ( V_50 != V_49 ) {
F_16 ( V_59 , V_60 ) ;
goto V_38;
}
V_54 ++ ;
}
V_22 = F_51 ( V_6 , V_58 , V_57 ) ;
if ( V_56 != NULL )
* V_56 = V_51 ;
* V_55 = V_50 ;
if ( V_22 == NULL ) {
F_16 ( V_59 , V_61 ) ;
goto V_38;
}
F_52 ( V_31 , ( strlen ( V_22 ) + V_31 -> V_62 - ( V_54 - V_48 ) ) ) ;
while ( * V_22 )
V_31 -> V_9 [ V_52 ++ ] = * ( V_22 ++ ) ;
V_53 -= V_54 - V_48 ;
V_48 = V_54 ;
* V_55 = V_50 ;
} else
V_31 -> V_9 [ V_52 ++ ] = * ( V_48 ++ ) ;
}
V_31 -> V_9 [ V_52 ] = '\0' ;
if ( * V_47 != NULL )
F_5 ( * V_47 ) ;
* V_47 = V_31 -> V_9 ;
F_5 ( V_31 ) ;
return ( 1 ) ;
V_38:
if ( V_31 != NULL )
F_39 ( V_31 ) ;
return ( 0 ) ;
}
static char * F_29 ( T_2 * V_6 , char * V_22 )
{
while ( F_34 ( V_6 , * V_22 ) && ( ! F_30 ( V_6 , * V_22 ) ) )
V_22 ++ ;
return ( V_22 ) ;
}
static char * F_31 ( T_2 * V_6 , char * V_22 )
{
for (; ; ) {
if ( F_27 ( V_6 , * V_22 ) ) {
V_22 = F_49 ( V_6 , V_22 ) ;
continue;
}
if ( ! F_53 ( V_6 , * V_22 ) )
return ( V_22 ) ;
V_22 ++ ;
}
}
static char * F_48 ( T_2 * V_6 , char * V_22 )
{
int V_49 = * V_22 ;
V_22 ++ ;
while ( ! ( F_30 ( V_6 , * V_22 ) ) && ( * V_22 != V_49 ) ) {
if ( F_27 ( V_6 , * V_22 ) ) {
V_22 ++ ;
if ( F_30 ( V_6 , * V_22 ) )
return ( V_22 ) ;
}
V_22 ++ ;
}
if ( * V_22 == V_49 )
V_22 ++ ;
return ( V_22 ) ;
}
static char * F_46 ( T_2 * V_6 , char * V_22 )
{
int V_49 = * V_22 ;
V_22 ++ ;
while ( ! ( F_30 ( V_6 , * V_22 ) ) ) {
if ( * V_22 == V_49 ) {
if ( * ( V_22 + 1 ) == V_49 ) {
V_22 ++ ;
} else {
break;
}
}
V_22 ++ ;
}
if ( * V_22 == V_49 )
V_22 ++ ;
return ( V_22 ) ;
}
static void F_54 ( T_5 * V_63 , T_3 * V_64 )
{
if ( V_63 -> V_11 )
F_55 ( V_64 , L_6 , V_63 -> V_30 , V_63 -> V_11 , V_63 -> V_44 ) ;
else
F_55 ( V_64 , L_7 , V_63 -> V_30 ) ;
}
static int F_56 ( const T_2 * V_6 , char V_65 )
{
return F_57 ( V_6 , V_65 ) ;
}
static int F_58 ( const T_2 * V_6 , char V_65 )
{
return V_65 - '0' ;
}
