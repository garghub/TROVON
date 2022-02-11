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
const T_6 * V_13 = ( T_6 * ) V_11 ;
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
}
V_9 = F_20 ( FALSE , FALSE , sizeof( T_3 * ) ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . V_15 ) {
F_1 ( V_19 [ V_17 ] . V_15 ) ;
}
}
V_6 = ( T_3 * ) F_21 ( sizeof ( T_3 ) ) ;
V_6 -> V_20 = V_21 ;
F_9 ( V_9 , V_6 ) ;
V_6 = ( T_3 * ) F_21 ( sizeof ( T_3 ) ) ;
V_6 -> V_20 = V_22 ;
F_9 ( V_9 , V_6 ) ;
}
void
F_22 ( T_8 * V_23 )
{
static T_9 V_24 [] = {
F_23 ( V_25 , V_15 , L_4 , L_5 ) ,
V_26
} ;
V_27 = F_24 ( L_6 ,
sizeof( T_6 ) ,
L_7 ,
FALSE ,
( void * * ) & V_19 ,
& V_18 ,
V_28 ,
L_8 ,
F_12 ,
NULL ,
F_14 ,
F_15 ,
V_24 ) ;
F_25 ( V_23 ,
L_7 ,
L_9 ,
L_10
L_11
L_12 ,
V_27 ) ;
}
void
F_26 ( void ) {
T_7 V_17 ;
V_9 = F_20 ( FALSE , FALSE , sizeof( T_3 * ) ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . V_15 ) {
F_1 ( V_19 [ V_17 ] . V_15 ) ;
}
}
{
T_3 * V_29 ;
T_3 * V_30 ;
V_29 = ( T_3 * ) F_21 ( sizeof ( T_3 ) ) ;
V_29 -> V_20 = V_21 ;
F_9 ( V_9 , V_29 ) ;
V_30 = ( T_3 * ) F_21 ( sizeof ( T_3 ) ) ;
V_30 -> V_20 = V_22 ;
F_9 ( V_9 , V_30 ) ;
}
}
T_7
F_16 ( void ) {
return V_9 -> T_5 ;
}
const T_10 *
F_27 ( T_7 V_31 ) {
T_3 * V_6 ;
V_6 = F_17 ( V_9 , T_3 * , V_31 ) ;
if ( V_6 ) {
return ( F_28 ( V_6 -> V_20 , V_32 , L_13 ) ) ;
}
return L_14 ;
}
int
F_29 ( T_7 V_31 ) {
T_3 * V_6 ;
V_6 = F_17 ( V_9 , T_3 * , V_31 ) ;
if ( V_6 ) {
return ( V_6 -> V_20 ) ;
}
return - 1 ;
}
static int
F_30 ( T_11 V_33 , float * V_34 , float * V_35 ) {
T_3 * V_6 ;
T_12 * V_36 ;
T_7 V_17 ;
for ( V_17 = 0 ; V_17 < F_16 () ; V_17 ++ ) {
V_6 = F_17 ( V_9 , T_3 * , V_17 ) ;
if ( V_6 ) {
switch ( V_6 -> V_20 ) {
case V_37 :
case V_38 :
V_36 = F_31 ( V_6 , V_33 ) ;
if( V_36 ) {
* V_34 = V_36 -> V_39 ;
* V_35 = V_36 -> V_40 ;
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
static void
F_32 ( char * V_41 ) {
char * V_42 ;
V_42 = F_33 ( V_41 , V_43 , L_15 , L_16 , NULL , NULL , NULL ) ;
if ( V_42 ) {
F_34 ( V_41 , V_42 , V_43 ) ;
F_10 ( V_42 ) ;
}
}
const char *
F_35 ( T_7 V_31 , T_11 V_33 , const char * V_44 ) {
T_3 * V_6 ;
T_12 * V_36 ;
const char * V_45 , * V_46 = V_44 ;
static char V_41 [ V_43 ] ;
V_6 = F_17 ( V_9 , T_3 * , V_31 ) ;
if ( V_6 ) {
switch ( V_6 -> V_20 ) {
case V_47 :
V_45 = F_36 ( V_6 , V_33 ) ;
if ( V_45 ) {
F_37 ( V_41 , V_43 , L_3 , V_45 ) ;
F_32 ( V_41 ) ;
V_46 = V_41 ;
}
break;
case V_37 :
case V_38 :
V_36 = F_31 ( V_6 , V_33 ) ;
if ( V_36 && V_36 -> V_48 && V_36 -> V_49 ) {
F_37 ( V_41 , V_43 , L_17 , V_36 -> V_48 , V_36 -> V_49 ) ;
F_32 ( V_41 ) ;
V_46 = V_41 ;
} else if ( V_36 && V_36 -> V_48 ) {
F_37 ( V_41 , V_43 , L_3 , V_36 -> V_48 ) ;
F_32 ( V_41 ) ;
V_46 = V_41 ;
}
break;
case V_50 :
case V_51 :
case V_52 :
V_45 = F_38 ( V_6 , V_33 ) ;
if ( V_45 ) {
F_37 ( V_41 , V_43 , L_3 , V_45 ) ;
F_32 ( V_41 ) ;
V_46 = V_41 ;
}
break;
case V_21 :
{
float V_34 ;
float V_35 ;
char * V_53 ;
if( F_30 ( V_33 , & V_34 , & V_35 ) == 0 ) {
F_37 ( V_41 , V_43 , L_18 , V_34 ) ;
V_53 = strchr ( V_41 , ',' ) ;
if ( V_53 != NULL ) * V_53 = '.' ;
V_46 = V_41 ;
}
}
break;
case V_22 :
{
float V_34 ;
float V_35 ;
char * V_53 ;
if( F_30 ( V_33 , & V_34 , & V_35 ) == 0 ) {
F_37 ( V_41 , V_43 , L_18 , V_35 ) ;
V_53 = strchr ( V_41 , ',' ) ;
if ( V_53 != NULL ) * V_53 = '.' ;
V_46 = V_41 ;
}
}
break;
default:
break;
}
}
return V_46 ;
}
static int
#if V_54 > 31
F_39 ( T_13 V_33 , float * V_34 , float * V_35 ) {
T_3 * V_6 ;
T_12 * V_36 ;
T_7 V_17 ;
for ( V_17 = 0 ; V_17 < F_16 () ; V_17 ++ ) {
V_6 = F_17 ( V_9 , T_3 * , V_17 ) ;
if ( V_6 ) {
switch ( V_6 -> V_20 ) {
case V_55 :
case V_56 :
V_36 = F_40 ( V_6 , V_33 ) ;
if( V_36 ) {
* V_34 = V_36 -> V_39 ;
* V_35 = V_36 -> V_40 ;
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
const char *
F_41 ( T_7 V_31 , struct V_57 V_33 , const char * V_44 ) {
T_3 * V_6 ;
T_13 V_58 ;
const char * V_45 , * V_46 = V_44 ;
static char V_41 [ V_43 ] ;
#if V_54 > 31
T_12 * V_36 ;
#endif
memcpy ( & V_58 , & V_33 , sizeof( V_33 ) ) ;
V_6 = F_17 ( V_9 , T_3 * , V_31 ) ;
if ( V_6 ) {
switch ( V_6 -> V_20 ) {
case V_59 :
V_45 = F_42 ( V_6 , V_58 ) ;
if ( V_45 ) {
F_37 ( V_41 , V_43 , L_3 , V_45 ) ;
F_32 ( V_41 ) ;
V_46 = V_41 ;
}
break;
#if V_54 > 31
case V_55 :
case V_56 :
V_36 = F_40 ( V_6 , V_58 ) ;
if ( V_36 && V_36 -> V_48 && V_36 -> V_49 ) {
F_37 ( V_41 , V_43 , L_17 , V_36 -> V_48 , V_36 -> V_49 ) ;
F_32 ( V_41 ) ;
V_46 = V_41 ;
} else if ( V_36 && V_36 -> V_48 ) {
F_37 ( V_41 , V_43 , L_3 , V_36 -> V_48 ) ;
F_32 ( V_41 ) ;
V_46 = V_41 ;
}
break;
case V_60 :
case V_61 :
case V_62 :
V_45 = F_43 ( V_6 , V_58 ) ;
if ( V_45 ) {
F_37 ( V_41 , V_43 , L_3 , V_45 ) ;
F_32 ( V_41 ) ;
V_46 = V_41 ;
}
break;
#endif
case V_21 :
{
float V_34 ;
float V_35 ;
char * V_53 ;
if( F_39 ( V_58 , & V_34 , & V_35 ) == 0 ) {
F_37 ( V_41 , V_43 , L_18 , V_34 ) ;
V_53 = strchr ( V_41 , ',' ) ;
if ( V_53 != NULL ) * V_53 = '.' ;
V_46 = V_41 ;
}
}
break;
case V_22 :
{
float V_34 ;
float V_35 ;
char * V_53 ;
if( F_39 ( V_58 , & V_34 , & V_35 ) == 0 ) {
F_37 ( V_41 , V_43 , L_18 , V_35 ) ;
V_53 = strchr ( V_41 , ',' ) ;
if ( V_53 != NULL ) * V_53 = '.' ;
V_46 = V_41 ;
}
}
break;
default:
break;
}
}
return V_46 ;
}
const char *
F_41 ( T_7 V_31 V_12 , struct V_57 V_33 V_12 , const char * V_44 ) {
return V_44 ;
}
T_10 *
F_44 ( void ) {
T_14 * V_63 = NULL ;
T_10 * V_64 ;
char V_65 ;
T_7 V_17 ;
V_63 = F_45 ( L_19 ) ;
#ifdef F_46
V_65 = ';' ;
#else
V_65 = ':' ;
#endif
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . V_15 ) {
F_47 ( V_63 , L_20 , V_19 [ V_17 ] . V_15 , V_65 ) ;
}
}
F_48 ( V_63 , V_63 -> T_5 - 1 ) ;
V_64 = V_63 -> V_66 ;
F_49 ( V_63 , FALSE ) ;
return V_64 ;
}
void
F_26 ( void ) {}
T_7
F_16 ( void ) {
return 0 ;
}
const T_10 *
F_27 ( T_7 V_31 V_12 ) {
return L_21 ;
}
int
F_29 ( T_7 V_31 V_12 ) {
return - 1 ;
}
const char *
F_35 ( T_7 V_31 V_12 , T_11 V_33 V_12 , const char * V_44 ) {
return V_44 ;
}
const char *
F_41 ( T_7 V_31 V_12 , T_11 V_33 V_12 , const char * V_44 ) {
return V_44 ;
}
T_10 *
F_44 ( void ) {
return F_13 ( L_19 ) ;
}
