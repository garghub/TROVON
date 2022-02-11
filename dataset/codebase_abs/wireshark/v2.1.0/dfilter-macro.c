static T_1 F_1 ( T_2 T_3 V_1 , T_2 V_2 , T_2 T_4 V_1 ) {
T_5 * V_3 = ( T_5 * ) V_2 ;
F_2 ( NULL , V_3 -> V_4 ) ;
F_3 ( V_3 ) ;
return TRUE ;
}
static T_1 F_4 ( T_6 * V_5 , T_2 T_7 V_1 ) {
T_8 * V_6 = F_5 ( V_5 ) ;
T_5 * V_3 ;
if ( ! V_6 ) return FALSE ;
if ( ( V_3 = ( T_5 * ) F_6 ( V_7 , V_6 -> V_8 -> V_9 ) ) ) {
V_3 -> V_10 = FALSE ;
} else if ( V_6 -> V_11 . V_12 -> V_13 ) {
switch ( V_6 -> V_8 -> type ) {
case V_14 :
case V_15 :
return FALSE ;
default:
break;
}
V_3 = F_7 ( T_5 , 1 ) ;
V_3 -> V_16 = V_6 -> V_8 -> V_9 ,
V_3 -> V_4 = F_8 ( NULL , & ( V_6 -> V_11 ) , V_17 , V_6 -> V_8 -> V_18 ) ;
V_3 -> V_10 = TRUE ;
F_9 ( V_7 , ( void * ) V_6 -> V_8 -> V_9 , V_3 ) ;
}
return FALSE ;
}
void F_10 ( void * V_19 ) {
F_11 ( V_7 , F_1 , NULL ) ;
F_12 ( ( V_20 * ) V_19 , F_4 , NULL ) ;
}
static T_9 * F_13 ( T_9 * V_16 , T_9 * * args , T_9 * * error ) {
T_10 * V_21 ;
int V_22 = 0 ;
T_11 * V_23 = NULL ;
T_5 * V_3 ;
int * V_24 ;
T_9 * * V_25 ;
T_9 * V_26 ;
T_12 V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
T_11 * V_29 = & ( V_30 [ V_27 ] ) ;
if ( V_29 -> V_10 && F_14 ( V_29 -> V_16 , V_16 ) ) {
V_23 = V_29 ;
break;
}
}
if ( ! V_23 ) {
if ( V_7 &&
( V_3 = ( T_5 * ) F_6 ( V_7 , V_16 ) ) != NULL ) {
if( V_3 -> V_10 ) {
return F_15 ( NULL , V_3 -> V_4 ) ;
} else {
if ( error != NULL )
* error = F_16 ( L_1 , V_16 ) ;
return NULL ;
}
} else {
if ( error != NULL )
* error = F_16 ( L_2 , V_16 ) ;
return NULL ;
}
}
F_17 ( V_23 ) ;
if ( args ) {
while( args [ V_22 ] ) V_22 ++ ;
}
if ( V_22 != V_23 -> V_22 ) {
if ( error != NULL ) {
* error = F_16 ( L_3 ,
V_16 , V_23 -> V_22 , V_22 ) ;
}
return NULL ;
}
V_24 = V_23 -> V_31 ;
V_25 = V_23 -> V_25 ;
V_21 = F_18 ( * ( V_25 ++ ) ) ;
if ( args ) {
while ( * V_25 ) {
F_19 ( V_21 , L_4 ,
args [ * ( V_24 ++ ) ] ,
* ( V_25 ++ ) ) ;
}
}
V_26 = F_15 ( NULL , V_21 -> V_32 ) ;
F_20 ( V_21 , TRUE ) ;
return V_26 ;
}
static T_9 * F_21 ( const T_9 * V_21 , T_12 V_33 , T_9 * * error ) {
enum { V_34 , V_35 , V_36 , ARGS } V_37 = V_34 ;
T_10 * V_38 ;
T_10 * V_16 = NULL ;
T_10 * V_39 = NULL ;
T_13 * args = NULL ;
T_9 V_29 ;
const T_9 * V_40 = V_21 ;
T_1 V_41 = FALSE ;
if ( V_33 > 31 ) {
if ( error != NULL )
* error = F_22 ( L_5 ) ;
return NULL ;
}
#define F_23 ( T_14 ) if (n) g_string_free(n,TRUE); n = NULL
#define F_24 () \
do { \
FGS(name); \
FGS(arg); \
if (args) { \
while(args->len) { void* p = g_ptr_array_remove_index_fast(args,0); if (p) g_free(p); } \
g_ptr_array_free(args,TRUE); \
args = NULL; \
} \
} while(0)
if ( error != NULL )
* error = NULL ;
V_38 = F_25 ( 64 ) ;
while( 1 ) {
V_29 = * V_40 ++ ;
switch( V_37 ) {
case V_34 : {
switch( V_29 ) {
case '\0' : {
goto V_42;
} case '$' : {
V_37 = V_35 ;
break;
} default: {
F_26 ( V_38 , V_29 ) ;
break;
}
}
break;
} case V_35 : {
switch ( V_29 ) {
case '{' : {
args = F_27 () ;
V_39 = F_25 ( 32 ) ;
V_16 = F_25 ( 32 ) ;
V_37 = V_36 ;
break;
} case '\0' : {
F_26 ( V_38 , '$' ) ;
goto V_42;
} default: {
F_26 ( V_38 , '$' ) ;
F_26 ( V_38 , V_29 ) ;
V_37 = V_34 ;
break;
}
}
break;
} case V_36 : {
if ( F_28 ( V_29 ) || V_29 == '_' || V_29 == '-' || V_29 == '.' ) {
F_26 ( V_16 , V_29 ) ;
} else if ( V_29 == ':' ) {
V_37 = ARGS ;
} else if ( V_29 == '}' ) {
T_9 * V_43 ;
F_29 ( args , NULL ) ;
V_43 = F_13 ( V_16 -> V_32 , ( T_9 * * ) args -> V_44 , error ) ;
if ( V_43 == NULL )
goto V_45;
V_41 = TRUE ;
F_30 ( V_38 , V_43 ) ;
F_2 ( NULL , V_43 ) ;
F_24 () ;
V_37 = V_34 ;
} else if ( V_29 == '\0' ) {
if ( error != NULL )
* error = F_22 ( L_6 ) ;
goto V_45;
} else {
if ( error != NULL )
* error = F_22 ( L_7 ) ;
goto V_45;
}
break;
} case ARGS : {
switch( V_29 ) {
case '\0' : {
if ( error != NULL )
* error = F_22 ( L_6 ) ;
goto V_45;
} case ';' : {
F_29 ( args , F_20 ( V_39 , FALSE ) ) ;
V_39 = F_25 ( 32 ) ;
break;
} case '\\' : {
V_29 = * V_40 ++ ;
if ( V_29 ) {
F_26 ( V_39 , V_29 ) ;
break;
} else {
if ( error != NULL )
* error = F_22 ( L_6 ) ;
goto V_45;
}
} default: {
F_26 ( V_39 , V_29 ) ;
break;
} case '}' : {
T_9 * V_43 ;
F_29 ( args , F_20 ( V_39 , FALSE ) ) ;
F_29 ( args , NULL ) ;
V_39 = NULL ;
V_43 = F_13 ( V_16 -> V_32 , ( T_9 * * ) args -> V_44 , error ) ;
if ( V_43 == NULL )
goto V_45;
V_41 = TRUE ;
F_30 ( V_38 , V_43 ) ;
F_2 ( NULL , V_43 ) ;
F_24 () ;
V_37 = V_34 ;
break;
}
}
break;
}
}
}
V_42:
{
F_24 () ;
if ( V_41 ) {
T_9 * V_43 = F_21 ( V_38 -> V_32 , V_33 + 1 , error ) ;
F_20 ( V_38 , TRUE ) ;
return V_43 ;
} else {
T_9 * V_46 = F_15 ( NULL , V_38 -> V_32 ) ;
F_20 ( V_38 , TRUE ) ;
return V_46 ;
}
}
V_45:
{
F_24 () ;
if ( error != NULL ) {
if ( * error == NULL )
* error = F_22 ( L_8 ) ;
}
F_20 ( V_38 , TRUE ) ;
return NULL ;
}
}
T_9 * F_31 ( const T_9 * V_21 , T_9 * * error ) {
return F_21 ( V_21 , 0 , error ) ;
}
static T_1 F_32 ( void * V_47 , T_9 * * error ) {
T_11 * V_23 = ( T_11 * ) V_47 ;
T_13 * V_25 ;
T_15 * V_31 ;
const T_9 * V_40 ;
T_9 * V_48 ;
T_9 * V_49 ;
int V_22 = 0 ;
F_17 ( V_23 ) ;
* error = NULL ;
if ( V_50 && V_50 -> V_51 )
V_50 -> V_51 () ;
V_25 = F_27 () ;
V_31 = F_33 ( FALSE , FALSE , sizeof( int ) ) ;
V_23 -> V_52 = V_49 = V_48 = F_22 ( V_23 -> V_21 ) ;
V_40 = V_23 -> V_21 ;
F_29 ( V_25 , V_49 ) ;
while ( V_40 && * V_40 ) {
switch ( * V_40 ) {
default:
* ( V_48 ++ ) = * ( V_40 ++ ) ;
break;
case '\0' :
* V_48 = * V_40 ;
goto V_53;
case '\\' :
* ( V_48 ++ ) = * ( ++ V_40 ) ;
V_40 ++ ;
break;
case '$' : {
int V_54 = 0 ;
int V_55 = 0 ;
do {
char V_29 = * ( V_40 + 1 ) ;
if ( V_29 >= '0' && V_29 <= '9' ) {
V_54 ++ ;
V_40 ++ ;
* ( V_48 ++ ) = '\0' ;
V_55 *= 10 ;
V_55 += V_29 - '0' ;
} else {
break;
}
} while( * V_40 );
if ( V_54 ) {
* ( V_48 ++ ) = '\0' ;
V_40 ++ ;
V_22 = V_22 < V_55 ? V_55 : V_22 ;
V_55 -- ;
F_34 ( V_31 , V_55 ) ;
F_29 ( V_25 , V_48 ) ;
} else {
* ( V_48 ++ ) = * ( V_40 ++ ) ;
}
break;
}
}
}
V_53:
F_29 ( V_25 , NULL ) ;
F_3 ( V_23 -> V_25 ) ;
V_23 -> V_25 = ( T_9 * * ) V_25 -> V_44 ;
F_3 ( V_23 -> V_31 ) ;
V_23 -> V_31 = ( int * ) ( void * ) V_31 -> T_7 ;
F_35 ( V_25 , FALSE ) ;
F_36 ( V_31 , FALSE ) ;
V_23 -> V_22 = V_22 ;
V_23 -> V_10 = TRUE ;
F_17 ( V_23 ) ;
return TRUE ;
}
static void F_37 ( void * V_40 ) {
T_11 * V_23 = ( T_11 * ) V_40 ;
F_17 ( V_40 ) ;
F_3 ( V_23 -> V_16 ) ;
F_3 ( V_23 -> V_21 ) ;
F_3 ( V_23 -> V_52 ) ;
F_3 ( V_23 -> V_25 ) ;
F_3 ( V_23 -> V_31 ) ;
}
static void * F_38 ( void * V_56 , const void * V_57 , T_16 T_17 V_1 ) {
T_11 * V_58 = ( T_11 * ) V_56 ;
const T_11 * V_23 = ( const T_11 * ) V_57 ;
F_17 ( V_23 ) ;
V_58 -> V_16 = F_22 ( V_23 -> V_16 ) ;
V_58 -> V_21 = F_22 ( V_23 -> V_21 ) ;
V_58 -> V_10 = V_23 -> V_10 ;
if ( V_23 -> V_25 ) {
T_12 V_59 = 0 ;
V_58 -> V_52 = F_22 ( V_23 -> V_21 ) ;
{
const T_9 * V_60 = V_23 -> V_21 ;
const T_9 * V_61 = ( const T_9 * ) V_23 -> V_52 ;
T_9 * V_62 = ( T_9 * ) V_58 -> V_52 ;
while( V_60 && * V_60 ) {
* ( V_62 ++ ) = * ( V_61 ++ ) ;
V_60 ++ ;
}
}
do V_59 ++ ; while ( V_23 -> V_25 [ V_59 ] );
V_58 -> V_25 = ( T_9 * * ) F_39 ( V_23 -> V_25 , ( V_59 + 1 ) * ( T_12 ) sizeof( void * ) ) ;
V_59 = 0 ;
while( V_23 -> V_25 [ V_59 ] ) {
if( V_59 ) {
V_58 -> V_25 [ V_59 ] = V_58 -> V_25 [ V_59 - 1 ] + ( V_23 -> V_25 [ V_59 ] - V_23 -> V_25 [ V_59 - 1 ] ) ;
} else {
V_58 -> V_25 [ V_59 ] = ( T_9 * ) V_58 -> V_52 ;
}
V_59 ++ ;
}
V_58 -> V_31 = ( int * ) F_39 ( V_23 -> V_31 , ( -- V_59 ) * ( T_12 ) sizeof( int ) ) ;
}
F_17 ( V_58 ) ;
return V_58 ;
}
static T_1 F_40 ( void * V_47 , const char * V_63 , T_12 V_64 ,
const void * T_18 V_1 , const void * T_19 V_1 , char * * error ) {
T_11 * V_23 = ( T_11 * ) V_47 ;
T_12 V_27 ;
if ( V_64 == 0 ) {
* error = F_22 ( L_9 ) ;
return FALSE ;
}
for ( V_27 = 0 ; V_27 < V_64 ; V_27 ++ ) {
if ( ! ( V_63 [ V_27 ] == '_' || F_28 ( V_63 [ V_27 ] ) ) ) {
* error = F_22 ( L_10 ) ;
return FALSE ;
}
}
if ( ! V_23 -> V_16 || F_41 ( V_23 -> V_16 , V_63 ) ) {
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
if ( ! F_41 ( V_63 , V_30 [ V_27 ] . V_16 ) ) {
* error = F_16 ( L_11 ,
V_63 ) ;
return FALSE ;
}
}
}
return TRUE ;
}
void F_42 ( void ) {
static T_20 V_65 [] = {
F_43 ( V_66 , V_16 , L_12 , F_40 , L_13 ) ,
F_44 ( V_66 , V_21 , L_14 , L_15 ) ,
V_67
} ;
V_50 = F_45 ( L_16 ,
sizeof( T_11 ) ,
V_68 ,
TRUE ,
& V_30 ,
& V_28 ,
0 ,
L_17 ,
F_38 ,
F_32 ,
F_37 ,
NULL ,
V_65 ) ;
V_7 = F_46 ( V_69 , F_14 ) ;
}
void F_47 ( T_21 * * V_70 ) {
* V_70 = V_50 ;
}
void F_48 ( const T_11 * V_23 , const char * V_71 , const char * V_72 , int line )
{
printf ( L_18 ) ;
if( V_23 == NULL ) {
printf ( L_19 , V_71 , V_72 , line ) ;
printf ( L_20 ) ;
}
printf ( L_21 , V_23 , V_71 , V_72 , line ) ;
printf ( L_22 , & V_23 -> V_16 ) ;
if( V_23 -> V_16 == NULL ) {
printf ( L_23 ) ;
} else {
printf ( L_24 , V_23 -> V_16 ) ;
printf ( L_25 , V_23 -> V_16 ) ;
}
printf ( L_26 , & V_23 -> V_21 ) ;
if( V_23 -> V_21 == NULL ) {
printf ( L_27 ) ;
} else {
printf ( L_28 , V_23 -> V_21 ) ;
printf ( L_29 , V_23 -> V_21 ) ;
}
printf ( L_30 , & V_23 -> V_10 ) ;
printf ( L_31 , V_23 -> V_10 ) ;
printf ( L_32 , & V_23 -> V_25 ) ;
if( V_23 -> V_25 == NULL ) {
printf ( L_33 ) ;
} else {
int V_27 = 0 ;
while ( V_23 -> V_25 [ V_27 ] ) {
printf ( L_34 , V_27 , V_23 -> V_25 [ V_27 ] ) ;
printf ( L_35 , V_27 , V_23 -> V_25 [ V_27 ] ) ;
V_27 ++ ;
}
printf ( L_36 , V_27 ) ;
}
printf ( L_37 , & V_23 -> V_31 ) ;
if( V_23 -> V_31 == NULL ) {
printf ( L_38 ) ;
} else {
printf ( L_39 , V_23 -> V_31 ) ;
}
printf ( L_40 , & V_23 -> V_22 ) ;
printf ( L_41 , V_23 -> V_22 ) ;
printf ( L_42 , & V_23 -> V_52 ) ;
if( V_23 -> V_52 == NULL ) {
printf ( L_43 ) ;
} else {
printf ( L_44 , V_23 -> V_52 ) ;
printf ( L_45 , ( char * ) V_23 -> V_52 ) ;
}
printf ( L_20 ) ;
}
