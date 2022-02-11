static void
F_1 ( const char * V_1 ) {
T_1 * V_2 ;
T_2 * V_3 ;
const char * V_4 ;
char * V_5 ;
T_3 * V_6 ;
if ( ( V_2 = F_2 ( V_1 , 0 , NULL ) ) != NULL ) {
while ( ( V_3 = F_3 ( V_2 ) ) != NULL ) {
V_4 = F_4 ( V_3 ) ;
if ( F_5 ( V_3 , L_1 ) && F_6 ( V_3 , L_2 ) ) {
V_5 = F_7 ( L_3 V_7 L_3 , V_1 , V_4 ) ;
V_6 = F_8 ( V_5 , V_8 ) ;
if ( V_6 ) {
F_9 ( V_9 , V_6 ) ;
}
F_10 ( V_5 ) ;
}
}
F_11 ( V_2 ) ;
}
}
static void * F_12 ( void * V_10 , const void * V_11 , T_4 T_5 V_12 ) {
const T_6 * V_13 = ( const T_6 * ) V_11 ;
T_6 * V_14 = ( T_6 * ) V_10 ;
V_14 -> V_15 = F_13 ( V_13 -> V_15 ) ;
return V_14 ;
}
static void F_14 ( void * V_16 ) {
T_6 * V_13 = ( T_6 * ) V_16 ;
F_10 ( V_13 -> V_15 ) ;
}
static void F_15 ( void ) {
T_3 * V_6 ;
T_7 V_17 ;
if ( V_9 ) {
for ( V_17 = 0 ; V_17 < F_16 () - 2 ; V_17 ++ ) {
V_6 = F_17 ( V_9 , T_3 * , V_17 ) ;
if ( V_6 ) {
F_18 ( V_6 ) ;
}
}
V_6 = F_17 ( V_9 , T_3 * , V_17 ) ;
if ( V_6 ) {
F_10 ( V_6 ) ;
}
V_6 = F_17 ( V_9 , T_3 * , V_17 + 1 ) ;
if ( V_6 ) {
F_10 ( V_6 ) ;
}
F_19 ( V_9 , TRUE ) ;
V_9 = NULL ;
}
}
static void F_20 ( void ) {
T_7 V_17 ;
T_3 * V_6 ;
F_15 () ;
V_9 = F_21 ( FALSE , FALSE , sizeof( T_3 * ) ) ;
for ( V_17 = 0 ; V_18 [ V_17 ] . V_15 != NULL ; V_17 ++ ) {
F_1 ( V_18 [ V_17 ] . V_15 ) ;
}
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
if ( V_20 [ V_17 ] . V_15 ) {
F_1 ( V_20 [ V_17 ] . V_15 ) ;
}
}
V_6 = ( T_3 * ) F_22 ( sizeof ( T_3 ) ) ;
V_6 -> V_21 = V_22 ;
F_9 ( V_9 , V_6 ) ;
V_6 = ( T_3 * ) F_22 ( sizeof ( T_3 ) ) ;
V_6 -> V_21 = V_23 ;
F_9 ( V_9 , V_6 ) ;
}
static void F_23 ( void )
{
F_15 () ;
}
void
F_24 ( T_8 * V_24 )
{
static T_9 V_25 [] = {
F_25 ( V_26 , V_15 , L_4 , L_5 ) ,
V_27
} ;
V_28 = F_26 ( L_6 ,
sizeof( T_6 ) ,
L_7 ,
FALSE ,
( void * * ) & V_20 ,
& V_19 ,
V_29 ,
L_8 ,
F_12 ,
NULL ,
F_14 ,
F_20 ,
F_23 ,
V_25 ) ;
F_27 ( V_24 ,
L_7 ,
L_9 ,
L_10
L_11
L_12 ,
V_28 ) ;
}
T_7
F_16 ( void ) {
return ( V_9 == NULL ) ? 0 : V_9 -> T_5 ;
}
const T_10 *
F_28 ( T_7 V_30 ) {
T_3 * V_6 ;
V_6 = F_17 ( V_9 , T_3 * , V_30 ) ;
if ( V_6 ) {
return ( F_29 ( V_6 -> V_21 , V_31 , L_13 ) ) ;
}
return L_14 ;
}
int
F_30 ( T_7 V_30 ) {
T_3 * V_6 ;
V_6 = F_17 ( V_9 , T_3 * , V_30 ) ;
if ( V_6 ) {
return ( V_6 -> V_21 ) ;
}
return - 1 ;
}
static int
F_31 ( T_11 V_32 , float * V_33 , float * V_34 ) {
T_3 * V_6 ;
T_12 * V_35 ;
T_7 V_17 ;
for ( V_17 = 0 ; V_17 < F_16 () ; V_17 ++ ) {
V_6 = F_17 ( V_9 , T_3 * , V_17 ) ;
if ( V_6 ) {
switch ( V_6 -> V_21 ) {
case V_36 :
case V_37 :
V_35 = F_32 ( V_6 , V_32 ) ;
if ( V_35 ) {
* V_33 = V_35 -> V_38 ;
* V_34 = V_35 -> V_39 ;
F_33 ( V_35 ) ;
return 0 ;
}
return - 1 ;
default:
break;
}
}
}
return - 1 ;
}
static char *
F_34 ( const char * V_40 , T_3 * V_6 ) {
if ( F_35 ( V_6 ) == V_41 ) {
char * V_42 ;
V_42 = F_36 ( V_40 , - 1 , L_15 , L_16 , NULL , NULL , NULL ) ;
if ( V_42 ) {
char * V_43 = F_37 ( NULL , V_42 ) ;
F_10 ( V_42 ) ;
return V_43 ;
}
}
return F_37 ( NULL , V_40 ) ;
}
char *
F_38 ( T_7 V_30 , T_11 V_32 , const char * V_44 ) {
T_3 * V_6 ;
T_12 * V_35 ;
char * V_4 ;
const char * V_45 ;
char * V_40 , * V_46 = NULL ;
if ( V_30 > F_16 () ) {
if ( V_44 == NULL )
return NULL ;
return F_37 ( NULL , V_44 ) ;
}
V_6 = F_17 ( V_9 , T_3 * , V_30 ) ;
if ( V_6 ) {
switch ( V_6 -> V_21 ) {
case V_47 :
V_45 = F_39 ( V_6 , V_32 ) ;
if ( V_45 ) {
V_46 = F_34 ( V_45 , V_6 ) ;
}
break;
case V_36 :
case V_37 :
V_35 = F_32 ( V_6 , V_32 ) ;
if ( V_35 && V_35 -> V_48 && V_35 -> V_49 ) {
V_40 = F_40 ( NULL , L_17 , V_35 -> V_48 , V_35 -> V_49 ) ;
V_46 = F_34 ( V_40 , V_6 ) ;
F_41 ( NULL , V_40 ) ;
} else if ( V_35 && V_35 -> V_48 ) {
V_46 = F_34 ( V_35 -> V_48 , V_6 ) ;
}
if ( V_35 )
F_33 ( V_35 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
V_4 = F_42 ( V_6 , V_32 ) ;
if ( V_4 ) {
V_46 = F_34 ( V_4 , V_6 ) ;
F_43 ( V_4 ) ;
}
break;
case V_22 :
{
float V_33 ;
float V_34 ;
char * V_53 ;
if( F_31 ( V_32 , & V_33 , & V_34 ) == 0 ) {
V_40 = F_40 ( NULL , L_18 , V_33 ) ;
V_53 = strchr ( V_40 , ',' ) ;
if ( V_53 != NULL ) * V_53 = '.' ;
V_46 = V_40 ;
}
}
break;
case V_23 :
{
float V_33 ;
float V_34 ;
char * V_53 ;
if( F_31 ( V_32 , & V_33 , & V_34 ) == 0 ) {
V_40 = F_40 ( NULL , L_18 , V_34 ) ;
V_53 = strchr ( V_40 , ',' ) ;
if ( V_53 != NULL ) * V_53 = '.' ;
V_46 = V_40 ;
}
}
break;
default:
break;
}
}
if ( V_46 == NULL ) {
if ( V_44 == NULL )
return NULL ;
return F_37 ( NULL , V_44 ) ;
}
return V_46 ;
}
static int
#if V_54 > 31
F_44 ( T_13 V_32 , float * V_33 , float * V_34 ) {
T_3 * V_6 ;
T_12 * V_35 ;
T_7 V_17 ;
for ( V_17 = 0 ; V_17 < F_16 () ; V_17 ++ ) {
V_6 = F_17 ( V_9 , T_3 * , V_17 ) ;
if ( V_6 ) {
switch ( V_6 -> V_21 ) {
case V_55 :
case V_56 :
V_35 = F_45 ( V_6 , V_32 ) ;
if( V_35 ) {
* V_33 = V_35 -> V_38 ;
* V_34 = V_35 -> V_39 ;
return 0 ;
}
return - 1 ;
default:
break;
}
}
}
return - 1 ;
}
char *
F_46 ( T_7 V_30 , struct V_57 V_32 , const char * V_44 ) {
T_3 * V_6 ;
T_13 V_58 ;
char * V_4 ;
const char * V_45 ;
char * V_40 , * V_46 = NULL ;
#if V_54 > 31
T_12 * V_35 ;
#endif
if ( V_30 > F_16 () ) {
if ( V_44 == NULL )
return NULL ;
return F_37 ( NULL , V_44 ) ;
}
memcpy ( & V_58 , & V_32 , sizeof( V_32 ) ) ;
V_6 = F_17 ( V_9 , T_3 * , V_30 ) ;
if ( V_6 ) {
switch ( V_6 -> V_21 ) {
case V_59 :
V_45 = F_47 ( V_6 , V_58 ) ;
if ( V_45 ) {
V_46 = F_34 ( V_45 , V_6 ) ;
}
break;
#if V_54 > 31
case V_55 :
case V_56 :
V_35 = F_45 ( V_6 , V_58 ) ;
if ( V_35 && V_35 -> V_48 && V_35 -> V_49 ) {
V_40 = F_40 ( NULL , L_17 , V_35 -> V_48 , V_35 -> V_49 ) ;
V_46 = F_34 ( V_40 , V_6 ) ;
F_41 ( NULL , V_40 ) ;
} else if ( V_35 && V_35 -> V_48 ) {
V_46 = F_34 ( V_35 -> V_48 , V_6 ) ;
}
break;
case V_60 :
case V_61 :
case V_62 :
V_4 = F_48 ( V_6 , V_58 ) ;
if ( V_4 ) {
V_46 = F_34 ( V_4 , V_6 ) ;
F_43 ( V_4 ) ;
}
break;
#endif
case V_22 :
{
float V_33 ;
float V_34 ;
char * V_53 ;
if( F_44 ( V_58 , & V_33 , & V_34 ) == 0 ) {
V_40 = F_40 ( NULL , L_18 , V_33 ) ;
V_53 = strchr ( V_40 , ',' ) ;
if ( V_53 != NULL ) * V_53 = '.' ;
V_46 = V_40 ;
}
}
break;
case V_23 :
{
float V_33 ;
float V_34 ;
char * V_53 ;
if( F_44 ( V_58 , & V_33 , & V_34 ) == 0 ) {
V_40 = F_40 ( NULL , L_18 , V_34 ) ;
V_53 = strchr ( V_40 , ',' ) ;
if ( V_53 != NULL ) * V_53 = '.' ;
V_46 = V_40 ;
}
}
break;
default:
break;
}
}
if ( V_46 == NULL ) {
if ( V_44 == NULL )
return NULL ;
return F_37 ( NULL , V_44 ) ;
}
return V_46 ;
}
char *
F_46 ( T_7 V_30 V_12 , struct V_57 V_32 V_12 , const char * V_44 ) {
if ( V_44 == NULL )
return NULL ;
return F_37 ( NULL , V_44 ) ;
}
T_10 *
F_49 ( void ) {
T_14 * V_63 = NULL ;
T_7 V_17 ;
V_63 = F_50 ( L_19 ) ;
for ( V_17 = 0 ; V_18 [ V_17 ] . V_15 != NULL ; V_17 ++ ) {
F_51 ( V_63 ,
L_3 V_64 , V_18 [ V_17 ] . V_15 ) ;
}
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
if ( V_20 [ V_17 ] . V_15 ) {
F_51 ( V_63 ,
L_3 V_64 , V_20 [ V_17 ] . V_15 ) ;
}
}
F_52 ( V_63 , V_63 -> T_5 - 1 ) ;
return F_53 ( V_63 , FALSE ) ;
}
T_7
F_16 ( void ) {
return 0 ;
}
const T_10 *
F_28 ( T_7 V_30 V_12 ) {
return L_20 ;
}
int
F_30 ( T_7 V_30 V_12 ) {
return - 1 ;
}
char *
F_38 ( T_7 V_30 V_12 , T_11 V_32 V_12 , const char * V_44 ) {
if ( V_44 == NULL )
return NULL ;
return ( char * ) F_37 ( NULL , V_44 ) ;
}
char *
F_46 ( T_7 V_30 V_12 , T_11 V_32 V_12 , const char * V_44 ) {
if ( V_44 == NULL )
return NULL ;
return ( char * ) F_37 ( NULL , V_44 ) ;
}
T_10 *
F_49 ( void ) {
return F_13 ( L_19 ) ;
}
