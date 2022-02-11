static T_1 F_1 ( T_2 T_3 V_1 , T_2 V_2 , T_2 T_4 V_1 ) {
T_5 * V_3 = ( T_5 * ) V_2 ;
F_2 ( V_3 -> V_4 ) ;
F_2 ( V_3 ) ;
return TRUE ;
}
static T_1 F_3 ( T_6 * V_5 , T_2 T_7 V_1 ) {
T_8 * V_6 = F_4 ( V_5 ) ;
T_5 * V_3 ;
if ( ! V_6 ) return FALSE ;
if ( ( V_3 = ( T_5 * ) F_5 ( V_7 , V_6 -> V_8 -> V_9 ) ) ) {
V_3 -> V_10 = FALSE ;
} else if ( V_6 -> V_11 . V_12 -> V_13 ) {
switch ( V_6 -> V_8 -> type ) {
case V_14 :
case V_15 :
return FALSE ;
default:
break;
}
V_3 = F_6 ( T_5 , 1 ) ;
V_3 -> V_16 = V_6 -> V_8 -> V_9 ,
V_3 -> V_4 = F_7 ( & ( V_6 -> V_11 ) , V_17 , NULL ) ;
V_3 -> V_10 = TRUE ;
F_8 ( V_7 , ( void * ) V_6 -> V_8 -> V_9 , V_3 ) ;
}
return FALSE ;
}
void F_9 ( void * V_18 ) {
F_10 ( V_7 , F_1 , NULL ) ;
F_11 ( ( V_19 * ) V_18 , F_3 , NULL ) ;
}
void F_12 ( T_9 V_20 , void * T_7 ) {
T_10 V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
V_20 ( & ( V_23 [ V_21 ] ) , T_7 ) ;
}
return;
}
static void F_13 ( T_11 * V_24 , void * V_25 ) {
T_12 * V_26 = ( T_12 * ) V_25 ;
fprintf ( V_26 , L_1 , V_24 -> V_16 , V_24 -> V_27 ) ;
}
void F_14 ( const T_13 * V_28 , T_13 * * error ) {
T_12 * V_26 = F_15 ( V_28 , L_2 ) ;
if ( ! V_26 ) {
* error = F_16 ( L_3 , V_28 , F_17 ( V_29 ) ) ;
return;
}
F_12 ( F_13 , V_26 ) ;
fclose ( V_26 ) ;
return;
}
static void F_18 ( T_11 * V_24 V_1 , void * V_25 V_1 ) {
T_13 * * V_30 = V_24 -> V_31 ;
int * V_32 = V_24 -> V_32 ;
printf ( L_4 ,
V_24 -> V_16 , V_24 -> V_27 , V_24 -> V_33 , V_24 -> V_10 , * ( V_30 ++ ) ) ;
while ( * V_30 ) {
printf ( L_5 , * V_32 , * V_30 ) ;
V_32 ++ ;
V_30 ++ ;
}
}
void F_19 ( void ) {
#ifdef F_20
F_12 ( F_18 , NULL ) ;
#endif
}
static const T_13 * F_21 ( T_13 * V_16 , T_13 * * args , const T_13 * * error ) {
T_14 * V_27 ;
int V_33 = 0 ;
T_11 * V_24 = NULL ;
T_5 * V_3 ;
int * V_34 ;
T_13 * * V_31 ;
const T_13 * V_35 ;
T_10 V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
T_11 * V_36 = & ( V_23 [ V_21 ] ) ;
if ( V_36 -> V_10 && F_22 ( V_36 -> V_16 , V_16 ) ) {
V_24 = V_36 ;
break;
}
}
if ( ! V_24 ) {
if ( V_7 &&
( V_3 = ( T_5 * ) F_5 ( V_7 , V_16 ) ) != NULL ) {
if( V_3 -> V_10 ) {
return V_3 -> V_4 ;
} else {
* error = F_16 ( L_6 , V_16 ) ;
return NULL ;
}
} else {
* error = F_16 ( L_7 , V_16 ) ;
return NULL ;
}
}
F_23 ( V_24 ) ;
if ( args ) {
while( args [ V_33 ] ) V_33 ++ ;
}
if ( V_33 != V_24 -> V_33 ) {
* error = F_16 ( L_8 ,
V_16 , V_24 -> V_33 , V_33 ) ;
return NULL ;
}
V_34 = V_24 -> V_32 ;
V_31 = V_24 -> V_31 ;
V_27 = F_24 ( * ( V_31 ++ ) ) ;
if ( args ) {
while ( * V_31 ) {
F_25 ( V_27 , L_9 ,
args [ * ( V_34 ++ ) ] ,
* ( V_31 ++ ) ) ;
}
}
V_35 = F_26 ( V_27 -> V_37 ) ;
F_27 ( V_27 , TRUE ) ;
return V_35 ;
}
static const T_13 * F_28 ( const T_13 * V_27 , T_10 V_38 , const T_13 * * error ) {
enum { V_39 , V_40 , V_41 , ARGS } V_42 = V_39 ;
T_14 * V_43 ;
T_14 * V_16 = NULL ;
T_14 * V_44 = NULL ;
T_15 * args = NULL ;
T_13 V_36 ;
const T_13 * V_45 = V_27 ;
T_1 V_46 = FALSE ;
if ( V_38 > 31 ) {
* error = L_10 ;
return NULL ;
}
#define F_29 ( T_16 ) if (n) g_string_free(n,TRUE); n = NULL
#define F_30 () \
do { \
FGS(name); \
FGS(arg); \
if (args) { \
while(args->len) { void* p = g_ptr_array_remove_index_fast(args,0); if (p) g_free(p); } \
g_ptr_array_free(args,TRUE); \
args = NULL; \
} \
} while(0)
* error = NULL ;
V_43 = F_31 ( 64 ) ;
while( 1 ) {
V_36 = * V_45 ++ ;
switch( V_42 ) {
case V_39 : {
switch( V_36 ) {
case '\0' : {
goto V_47;
} case '$' : {
V_42 = V_40 ;
break;
} default: {
F_32 ( V_43 , V_36 ) ;
break;
}
}
break;
} case V_40 : {
switch ( V_36 ) {
case '{' : {
args = F_33 () ;
V_44 = F_31 ( 32 ) ;
V_16 = F_31 ( 32 ) ;
V_42 = V_41 ;
break;
} case '\0' : {
F_32 ( V_43 , '$' ) ;
goto V_47;
} default: {
F_32 ( V_43 , '$' ) ;
F_32 ( V_43 , V_36 ) ;
V_42 = V_39 ;
break;
}
}
break;
} case V_41 : {
if ( isalnum ( ( int ) V_36 ) || V_36 == '_' || V_36 == '-' || V_36 == '.' ) {
F_32 ( V_16 , V_36 ) ;
} else if ( V_36 == ':' ) {
V_42 = ARGS ;
} else if ( V_36 == '}' ) {
const T_13 * V_48 ;
F_34 ( args , NULL ) ;
V_48 = F_21 ( V_16 -> V_37 , ( T_13 * * ) args -> V_49 , error ) ;
if ( * error ) goto V_50;
V_46 = TRUE ;
F_35 ( V_43 , V_48 ) ;
F_30 () ;
V_42 = V_39 ;
} else if ( V_36 == '\0' ) {
* error = L_11 ;
goto V_50;
} else {
* error = L_12 ;
goto V_50;
}
break;
} case ARGS : {
switch( V_36 ) {
case '\0' : {
* error = L_11 ;
goto V_50;
} case ';' : {
F_34 ( args , V_44 -> V_37 ) ;
F_27 ( V_44 , FALSE ) ;
V_44 = F_31 ( 32 ) ;
break;
} case '\\' : {
V_36 = * V_45 ++ ;
if ( V_36 ) {
F_32 ( V_44 , V_36 ) ;
break;
} else {
* error = L_11 ;
goto V_50;
}
} default: {
F_32 ( V_44 , V_36 ) ;
break;
} case '}' : {
const T_13 * V_48 ;
F_34 ( args , V_44 -> V_37 ) ;
F_34 ( args , NULL ) ;
F_27 ( V_44 , FALSE ) ;
V_44 = NULL ;
V_48 = F_21 ( V_16 -> V_37 , ( T_13 * * ) args -> V_49 , error ) ;
if ( * error ) goto V_50;
V_46 = TRUE ;
F_35 ( V_43 , V_48 ) ;
F_30 () ;
V_42 = V_39 ;
break;
}
}
break;
}
}
}
V_47:
{
F_30 () ;
if ( V_46 ) {
const T_13 * V_48 = F_28 ( V_43 -> V_37 , V_38 + 1 , error ) ;
F_27 ( V_43 , TRUE ) ;
return ( * error ) ? NULL : V_48 ;
} else {
const T_13 * V_51 = F_26 ( V_43 -> V_37 ) ;
F_27 ( V_43 , TRUE ) ;
return V_51 ;
}
}
V_50:
{
F_30 () ;
if ( ! * error ) * error = L_13 ;
F_27 ( V_43 , TRUE ) ;
return NULL ;
}
}
const T_13 * F_36 ( const T_13 * V_27 , const T_13 * * error ) {
return F_28 ( V_27 , 0 , error ) ;
}
static void F_37 ( void * V_52 , const T_13 * * error ) {
T_11 * V_24 = ( T_11 * ) V_52 ;
T_15 * V_31 ;
T_17 * V_32 ;
const T_13 * V_45 ;
T_13 * V_53 ;
T_13 * V_30 ;
int V_33 = 0 ;
T_10 V_21 ;
F_23 ( V_24 ) ;
* error = NULL ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_24 == & ( V_23 [ V_21 ] ) ) continue;
if ( F_22 ( V_24 -> V_16 , V_23 [ V_21 ] . V_16 ) ) {
* error = F_38 ( L_14 , V_24 -> V_16 ) ;
V_24 -> V_10 = FALSE ;
return;
}
}
if ( V_54 && V_54 -> V_55 )
V_54 -> V_55 () ;
V_31 = F_33 () ;
V_32 = F_39 ( FALSE , FALSE , sizeof( int ) ) ;
V_24 -> V_56 = V_30 = V_53 = F_40 ( V_24 -> V_27 ) ;
V_45 = V_24 -> V_27 ;
F_34 ( V_31 , V_30 ) ;
while ( V_45 && * V_45 ) {
switch ( * V_45 ) {
default:
* ( V_53 ++ ) = * ( V_45 ++ ) ;
break;
case '\0' :
* V_53 = * V_45 ;
goto V_57;
case '\\' :
* ( V_53 ++ ) = * ( ++ V_45 ) ;
V_45 ++ ;
break;
case '$' : {
int V_58 = 0 ;
int V_59 = 0 ;
do {
char V_36 = * ( V_45 + 1 ) ;
if ( V_36 >= '0' && V_36 <= '9' ) {
V_58 ++ ;
V_45 ++ ;
* ( V_53 ++ ) = '\0' ;
V_59 *= 10 ;
V_59 += V_36 - '0' ;
} else {
break;
}
} while( * V_45 );
if ( V_58 ) {
* ( V_53 ++ ) = '\0' ;
V_45 ++ ;
V_33 = V_33 < V_59 ? V_59 : V_33 ;
V_59 -- ;
F_41 ( V_32 , V_59 ) ;
F_34 ( V_31 , V_53 ) ;
} else {
* ( V_53 ++ ) = * ( V_45 ++ ) ;
}
break;
}
}
}
V_57:
F_34 ( V_31 , NULL ) ;
F_2 ( V_24 -> V_31 ) ;
V_24 -> V_31 = ( T_13 * * ) V_31 -> V_49 ;
F_2 ( V_24 -> V_32 ) ;
V_24 -> V_32 = ( int * ) ( void * ) V_32 -> T_7 ;
F_42 ( V_31 , FALSE ) ;
F_43 ( V_32 , FALSE ) ;
V_24 -> V_33 = V_33 ;
V_24 -> V_10 = TRUE ;
F_18 ( V_24 , NULL ) ;
F_23 ( V_24 ) ;
return;
}
static void F_44 ( void * V_45 ) {
T_11 * V_24 = ( T_11 * ) V_45 ;
F_23 ( V_45 ) ;
F_2 ( V_24 -> V_16 ) ;
F_2 ( V_24 -> V_27 ) ;
F_2 ( V_24 -> V_56 ) ;
F_2 ( V_24 -> V_31 ) ;
F_2 ( V_24 -> V_32 ) ;
}
static void * F_45 ( void * V_60 , const void * V_61 , T_18 T_19 V_1 ) {
T_11 * V_62 = ( T_11 * ) V_60 ;
const T_11 * V_24 = ( const T_11 * ) V_61 ;
F_23 ( V_24 ) ;
V_62 -> V_16 = F_40 ( V_24 -> V_16 ) ;
V_62 -> V_27 = F_40 ( V_24 -> V_27 ) ;
V_62 -> V_10 = V_24 -> V_10 ;
if ( V_24 -> V_31 ) {
T_10 V_63 = 0 ;
V_62 -> V_56 = F_40 ( V_24 -> V_27 ) ;
{
const T_13 * V_64 = V_24 -> V_27 ;
const T_13 * V_65 = ( const T_13 * ) V_24 -> V_56 ;
T_13 * V_66 = ( T_13 * ) V_62 -> V_56 ;
while( V_64 && * V_64 ) {
* ( V_66 ++ ) = * ( V_65 ++ ) ;
V_64 ++ ;
}
}
do V_63 ++ ; while ( V_24 -> V_31 [ V_63 ] );
V_62 -> V_31 = ( T_13 * * ) F_46 ( V_24 -> V_31 , ( V_63 + 1 ) * ( T_10 ) sizeof( void * ) ) ;
V_63 = 0 ;
while( V_24 -> V_31 [ V_63 ] ) {
if( V_63 ) {
V_62 -> V_31 [ V_63 ] = V_62 -> V_31 [ V_63 - 1 ] + ( V_24 -> V_31 [ V_63 ] - V_24 -> V_31 [ V_63 - 1 ] ) ;
} else {
V_62 -> V_31 [ V_63 ] = ( T_13 * ) V_62 -> V_56 ;
}
V_63 ++ ;
}
V_62 -> V_32 = ( int * ) F_46 ( V_24 -> V_32 , ( -- V_63 ) * ( T_10 ) sizeof( int ) ) ;
}
F_23 ( V_62 ) ;
return V_62 ;
}
static T_1 F_47 ( void * V_45 V_1 , const char * V_67 , T_10 V_68 , const void * T_20 V_1 , const void * T_21 V_1 , const char * * error ) {
T_10 V_21 ;
if ( V_68 == 0 ) {
* error = L_15 ;
return FALSE ;
}
for ( V_21 = 0 ; V_21 < V_68 ; V_21 ++ ) {
if ( ! ( V_67 [ V_21 ] == '_' || isalnum ( ( V_69 ) V_67 [ V_21 ] ) ) ) {
* error = L_16 ;
return FALSE ;
}
}
return TRUE ;
}
void F_48 ( void ) {
static T_22 V_70 [] = {
F_49 ( V_71 , V_16 , L_17 , F_47 , L_18 ) ,
F_50 ( V_71 , V_27 , L_19 , L_20 ) ,
V_72
} ;
V_54 = F_51 ( L_21 ,
sizeof( T_11 ) ,
V_73 ,
TRUE ,
& V_23 ,
& V_22 ,
0 ,
L_22 ,
F_45 ,
F_37 ,
F_44 ,
NULL ,
V_70 ) ;
V_7 = F_52 ( V_74 , F_22 ) ;
}
void F_53 ( void * * V_75 ) {
* V_75 = V_54 ;
}
void F_54 ( const T_11 * V_24 , const char * V_76 , const char * V_77 , int line )
{
printf ( L_23 ) ;
if( V_24 == NULL ) {
printf ( L_24 , V_76 , V_77 , line ) ;
printf ( L_25 ) ;
}
printf ( L_26 , V_24 , V_76 , V_77 , line ) ;
printf ( L_27 , & V_24 -> V_16 ) ;
if( V_24 -> V_16 == NULL ) {
printf ( L_28 ) ;
} else {
printf ( L_29 , V_24 -> V_16 ) ;
printf ( L_30 , V_24 -> V_16 ) ;
}
printf ( L_31 , & V_24 -> V_27 ) ;
if( V_24 -> V_27 == NULL ) {
printf ( L_32 ) ;
} else {
printf ( L_33 , V_24 -> V_27 ) ;
printf ( L_34 , V_24 -> V_27 ) ;
}
printf ( L_35 , & V_24 -> V_10 ) ;
printf ( L_36 , V_24 -> V_10 ) ;
printf ( L_37 , & V_24 -> V_31 ) ;
if( V_24 -> V_31 == NULL ) {
printf ( L_38 ) ;
} else {
int V_21 = 0 ;
while ( V_24 -> V_31 [ V_21 ] ) {
printf ( L_39 , V_21 , V_24 -> V_31 [ V_21 ] ) ;
printf ( L_40 , V_21 , V_24 -> V_31 [ V_21 ] ) ;
V_21 ++ ;
}
printf ( L_41 , V_21 ) ;
}
printf ( L_42 , & V_24 -> V_32 ) ;
if( V_24 -> V_32 == NULL ) {
printf ( L_43 ) ;
} else {
printf ( L_44 , V_24 -> V_32 ) ;
}
printf ( L_45 , & V_24 -> V_33 ) ;
printf ( L_46 , V_24 -> V_33 ) ;
printf ( L_47 , & V_24 -> V_56 ) ;
if( V_24 -> V_56 == NULL ) {
printf ( L_48 ) ;
} else {
printf ( L_49 , V_24 -> V_56 ) ;
printf ( L_50 , ( char * ) V_24 -> V_56 ) ;
}
printf ( L_25 ) ;
}
