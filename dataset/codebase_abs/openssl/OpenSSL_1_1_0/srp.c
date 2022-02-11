T_1
#else
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <openssl/conf.h>
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/txt_db.h>
# include <openssl/buffer.h>
# include <openssl/srp.h>
# include "apps.h"
# define F_1 "srp"
# define F_2 "openssl.cnf"
# define F_3 "RANDFILE"
# define F_4 "srpvfile"
# define F_5 "default_srp"
static int F_6 ( T_2 * V_1 , char * V_2 , char type )
{
char * * V_3 ;
int V_4 ;
if ( V_2 == NULL )
return - 1 ;
if ( type == V_5 )
for ( V_4 = 0 ; V_4 < F_7 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ ) {
V_3 = F_8 ( V_1 -> V_1 -> V_6 , V_4 ) ;
if ( V_3 [ V_7 ] [ 0 ] == V_5
&& strcmp ( V_2 , V_3 [ V_8 ] ) == 0 )
return V_4 ;
} else
for ( V_4 = 0 ; V_4 < F_7 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ ) {
V_3 = F_8 ( V_1 -> V_1 -> V_6 , V_4 ) ;
if ( V_3 [ V_7 ] [ 0 ] != V_5
&& strcmp ( V_2 , V_3 [ V_8 ] ) == 0 )
return V_4 ;
}
return - 1 ;
}
static void F_9 ( T_2 * V_1 , int V_9 , int V_10 , char * V_11 )
{
if ( V_9 >= 0 && V_10 ) {
int V_12 ;
char * * V_3 = F_8 ( V_1 -> V_1 -> V_6 , V_9 ) ;
F_10 ( V_13 , L_1 , V_11 , V_3 [ V_8 ] ) ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ ) {
F_10 ( V_13 , L_2 , V_12 , V_3 [ V_12 ] ) ;
}
}
}
static void F_11 ( T_2 * V_1 , int V_15 , int V_10 )
{
F_9 ( V_1 , V_15 , V_10 , L_3 ) ;
}
static void F_12 ( T_2 * V_1 , int V_16 , int V_10 )
{
if ( V_10 > 0 ) {
char * * V_3 = F_8 ( V_1 -> V_1 -> V_6 , V_16 ) ;
if ( V_3 [ V_7 ] [ 0 ] != 'I' ) {
F_9 ( V_1 , V_16 , V_10 , L_4 ) ;
F_9 ( V_1 , F_6 ( V_1 , V_3 [ V_17 ] , 'I' ) , V_10 ,
L_3 ) ;
}
}
}
static int F_13 ( T_2 * V_1 , char * * V_18 )
{
char * * V_19 ;
int V_4 ;
V_19 = F_14 ( sizeof( * V_19 ) * ( V_14 + 1 ) , L_5 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
V_19 [ V_4 ] = V_18 [ V_4 ] ;
V_18 [ V_4 ] = NULL ;
}
V_19 [ V_14 ] = NULL ;
if ( ! F_15 ( V_1 -> V_1 , V_19 ) ) {
F_10 ( V_13 , L_6 ) ;
F_10 ( V_13 , L_7 , V_1 -> V_1 -> error ) ;
F_16 ( V_19 ) ;
return 0 ;
}
return 1 ;
}
static char * F_17 ( const T_3 * V_20 , const char * V_21 , const char * V_22 )
{
char * V_23 = F_18 ( V_20 , V_21 , V_22 ) ;
if ( V_23 == NULL )
F_10 ( V_13 , L_8 , V_21 , V_22 ) ;
return V_23 ;
}
static char * F_19 ( const char * V_24 , const char * V_25 ,
char * V_26 , const char * V_27 , const char * V_28 ,
const char * V_29 , int V_10 )
{
char V_30 [ 1024 ] ;
T_4 V_31 ;
char * V_32 = NULL ;
char * V_33 = NULL ;
V_31 . V_34 = V_24 ;
V_31 . V_30 = V_29 ;
if ( F_20 ( V_30 , sizeof( V_30 ) , 0 , & V_31 ) > 0 ) {
if ( V_10 )
F_10 ( V_13 ,
L_9 ,
V_24 , V_25 , V_26 , V_27 , V_28 ) ;
F_10 ( V_13 , L_10 , V_30 ) ;
F_21 ( V_26 != NULL ) ;
if ( !
( V_33 =
F_22 ( V_24 , V_30 , & V_26 , & V_32 , V_28 ,
V_27 ) ) ) {
F_10 ( V_13 , L_11 ) ;
} else {
if ( strcmp ( V_32 , V_25 ) )
V_33 = NULL ;
F_16 ( V_32 ) ;
}
}
return V_33 ;
}
static char * F_23 ( char * V_24 , char * * V_25 ,
char * * V_26 , char * V_27 , char * V_28 ,
char * V_35 , int V_10 )
{
char V_30 [ 1024 ] ;
T_4 V_31 ;
char * V_33 = NULL ;
char * V_36 = NULL ;
V_31 . V_34 = V_24 ;
V_31 . V_30 = V_35 ;
if ( F_20 ( V_30 , sizeof( V_30 ) , 1 , & V_31 ) > 0 ) {
if ( V_10 )
F_10 ( V_13 , L_12 ,
V_24 , V_27 , V_28 ) ;
if ( !
( V_33 =
F_22 ( V_24 , V_30 , & V_36 , V_25 , V_28 ,
V_27 ) ) ) {
F_10 ( V_13 , L_13 ) ;
} else
* V_26 = V_36 ;
if ( V_10 > 1 )
F_10 ( V_13 , L_14 , V_33 ,
V_36 , * V_25 ) ;
}
return V_33 ;
}
int F_24 ( int V_37 , char * * V_38 )
{
T_2 * V_1 = NULL ;
T_3 * V_20 = NULL ;
int V_39 = - 1 , V_40 = - 1 , V_41 = 1 , V_42 = 0 , V_10 = 0 , V_4 ;
int V_43 = 0 , V_44 = V_45 ;
char * V_24 = NULL , * V_46 = NULL , * V_47 = NULL ;
char * V_29 = NULL , * V_35 = NULL , * V_48 = NULL , * V_49 = NULL ;
char * V_50 = NULL , * V_21 = NULL ;
char * * V_51 = NULL , * V_52 = NULL ;
char * V_53 = NULL , * * V_3 , * V_54 ;
T_5 V_55 ;
V_54 = F_25 ( V_37 , V_38 , V_56 ) ;
while ( ( V_55 = F_26 () ) != V_57 ) {
switch ( V_55 ) {
case V_57 :
case V_45 :
V_58:
F_10 ( V_13 , L_15 , V_54 ) ;
goto V_59;
case V_60 :
F_27 ( V_56 ) ;
V_41 = 0 ;
goto V_59;
case V_61 :
V_10 ++ ;
break;
case V_62 :
V_52 = F_28 () ;
break;
case V_63 :
V_21 = F_28 () ;
break;
case V_64 :
V_53 = F_28 () ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
if ( V_44 != V_45 ) {
F_10 ( V_13 ,
L_16 ,
V_54 ) ;
goto V_58;
}
V_44 = V_55 ;
break;
case V_69 :
V_48 = F_28 () ;
break;
case V_70 :
V_49 = F_28 () ;
break;
case V_71 :
V_46 = F_28 () ;
break;
case V_72 :
V_47 = F_28 () ;
break;
case V_73 :
( void ) F_29 ( F_28 () , 0 ) ;
break;
}
}
V_37 = F_30 () ;
V_38 = F_31 () ;
if ( V_53 && V_52 ) {
F_10 ( V_13 ,
L_17 ) ;
goto V_59;
}
if ( V_44 == V_45 ) {
F_10 ( V_13 ,
L_18 ) ;
goto V_58;
}
if ( ( V_44 == V_66 || V_44 == V_67 || V_44 == V_65 )
&& V_37 < 1 ) {
F_10 ( V_13 ,
L_19 ) ;
goto V_58;
}
if ( ( V_29 || V_35 ) && V_37 != 1 ) {
F_10 ( V_13 ,
L_20 ) ;
goto V_58;
}
if ( ! F_32 ( V_46 , V_47 , & V_29 , & V_35 ) ) {
F_10 ( V_13 , L_21 ) ;
goto V_59;
}
if ( ! V_53 ) {
if ( ! V_52 )
V_52 = V_74 ;
if ( V_10 )
F_10 ( V_13 , L_22 ,
V_52 ) ;
V_20 = F_33 ( V_52 ) ;
if ( V_20 == NULL )
goto V_59;
if ( V_52 != V_74 && ! F_34 ( V_20 ) )
goto V_59;
if ( V_21 == NULL ) {
if ( V_10 )
F_10 ( V_13 ,
L_23 F_5
L_24 F_1 L_25 ) ;
V_21 = F_17 ( V_20 , F_1 , F_5 ) ;
if ( V_21 == NULL )
goto V_59;
}
if ( V_50 == NULL )
V_50 = F_18 ( V_20 , F_1 , L_26 ) ;
if ( V_10 )
F_10 ( V_13 ,
L_23 F_4 L_27 ,
V_21 ) ;
V_53 = F_17 ( V_20 , V_21 , F_4 ) ;
if ( V_53 == NULL )
goto V_59;
}
if ( V_50 == NULL )
F_35 () ;
else
F_36 ( V_50 , 0 ) ;
if ( V_10 )
F_10 ( V_13 , L_28 ,
V_53 ) ;
V_1 = F_37 ( V_53 , NULL ) ;
if ( V_1 == NULL )
goto V_59;
for ( V_4 = 0 ; V_4 < F_7 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ ) {
V_3 = F_8 ( V_1 -> V_1 -> V_6 , V_4 ) ;
if ( V_3 [ V_7 ] [ 0 ] == V_5 ) {
V_40 = V_4 ;
if ( ( V_39 < 0 ) && ( V_48 != NULL ) && strcmp ( V_48 , V_3 [ V_8 ] ) == 0 )
V_39 = V_4 ;
F_11 ( V_1 , V_4 , V_10 > 1 ) ;
}
}
if ( V_10 )
F_10 ( V_13 , L_29 ) ;
if ( V_39 >= 0 ) {
V_51 = F_8 ( V_1 -> V_1 -> V_6 , V_39 ) ;
F_9 ( V_1 , V_39 , V_10 > 1 , L_30 ) ;
} else if ( V_40 > 0 && ! F_38 ( V_48 ) ) {
F_10 ( V_13 , L_31 , V_48 ) ;
goto V_59;
} else {
if ( V_10 )
F_10 ( V_13 , L_32 ) ;
V_51 = NULL ;
}
if ( V_10 > 1 )
F_10 ( V_13 , L_33 ) ;
if ( V_37 > 0 )
V_24 = * ( V_38 ++ ) ;
while ( V_44 == V_68 || V_24 ) {
int V_16 = - 1 ;
if ( V_24 != NULL && V_10 > 1 )
F_10 ( V_13 , L_34 , V_24 ) ;
if ( ( V_16 = F_6 ( V_1 , V_24 , 'U' ) ) >= 0 ) {
F_12 ( V_1 , V_16 , ( V_10 > 0 ) || V_44 == V_68 ) ;
}
if ( V_44 == V_68 ) {
if ( V_24 == NULL ) {
F_10 ( V_13 , L_35 ) ;
for ( V_4 = 0 ; V_4 < F_7 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ ) {
F_12 ( V_1 , V_4 , 1 ) ;
}
} else if ( V_16 < 0 ) {
F_10 ( V_13 ,
L_36 , V_24 ) ;
V_42 ++ ;
}
} else if ( V_44 == V_65 ) {
if ( V_16 >= 0 ) {
char * * V_18 =
F_8 ( V_1 -> V_1 -> V_6 , V_16 ) ;
F_10 ( V_13 , L_37 , V_24 ) ;
V_18 [ V_7 ] [ 0 ] = 'V' ;
V_43 = 1 ;
} else {
char * V_18 [ V_14 ] ;
char * V_33 ;
V_18 [ V_75 ] = NULL ;
V_18 [ V_76 ] = NULL ;
V_18 [ V_77 ] = NULL ;
if ( !
( V_33 =
F_23 ( V_24 , & ( V_18 [ V_75 ] ) ,
& ( V_18 [ V_76 ] ) ,
V_51 ? V_51 [ V_76 ] : V_48 ,
V_51 ? V_51 [ V_75 ] : NULL ,
V_35 , V_10 ) ) ) {
F_10 ( V_13 ,
L_38 ,
V_24 ) ;
V_42 ++ ;
goto V_59;
}
V_18 [ V_8 ] = F_39 ( V_24 ) ;
V_18 [ V_7 ] = F_39 ( L_39 ) ;
V_18 [ V_17 ] = F_39 ( V_33 ) ;
if ( ( V_18 [ V_8 ] == NULL )
|| ( V_18 [ V_17 ] == NULL )
|| ( V_18 [ V_7 ] == NULL )
|| ( V_18 [ V_75 ] == NULL )
|| ( V_18 [ V_76 ] == NULL )
|| ( V_49
&& ( ( V_18 [ V_77 ] = F_39 ( V_49 ) ) == NULL ) )
|| ! F_13 ( V_1 , V_18 ) ) {
F_16 ( V_18 [ V_8 ] ) ;
F_16 ( V_18 [ V_17 ] ) ;
F_16 ( V_18 [ V_77 ] ) ;
F_16 ( V_18 [ V_7 ] ) ;
F_16 ( V_18 [ V_75 ] ) ;
F_16 ( V_18 [ V_76 ] ) ;
goto V_59;
}
V_43 = 1 ;
}
} else if ( V_44 == V_67 ) {
if ( V_16 < 0 ) {
F_10 ( V_13 ,
L_40 ,
V_24 ) ;
V_42 ++ ;
} else {
char * * V_18 =
F_8 ( V_1 -> V_1 -> V_6 , V_16 ) ;
char type = V_18 [ V_7 ] [ 0 ] ;
if ( type == 'v' ) {
F_10 ( V_13 ,
L_41 ,
V_24 ) ;
V_42 ++ ;
} else {
char * V_33 ;
if ( V_18 [ V_7 ] [ 0 ] == 'V' ) {
int V_78 ;
char * * V_19 = NULL ;
if ( V_10 )
F_10 ( V_13 ,
L_42 ,
V_24 ) ;
if ( ( V_78 =
F_6 ( V_1 , V_18 [ V_17 ] , V_5 ) ) >= 0 )
V_19 =
F_8 ( V_1 -> V_1 -> V_6 ,
V_16 ) ;
if ( ! F_19
( V_24 , V_18 [ V_75 ] , V_18 [ V_76 ] ,
V_19 ? V_19 [ V_76 ] : V_18 [ V_17 ] ,
V_19 ? V_19 [ V_75 ] : NULL , V_29 ,
V_10 ) ) {
F_10 ( V_13 ,
L_43 ,
V_24 ) ;
V_42 ++ ;
goto V_59;
}
}
if ( V_10 )
F_10 ( V_13 , L_44 ,
V_24 ) ;
if ( !
( V_33 =
F_23 ( V_24 , & ( V_18 [ V_75 ] ) ,
& ( V_18 [ V_76 ] ) ,
V_51 ? V_51 [ V_76 ] : NULL ,
V_51 ? V_51 [ V_75 ] : NULL ,
V_35 , V_10 ) ) ) {
F_10 ( V_13 ,
L_45 ,
V_24 ) ;
V_42 ++ ;
goto V_59;
}
V_18 [ V_7 ] [ 0 ] = 'v' ;
V_18 [ V_17 ] = F_39 ( V_33 ) ;
if ( V_18 [ V_8 ] == NULL
|| V_18 [ V_17 ] == NULL
|| V_18 [ V_7 ] == NULL
|| V_18 [ V_75 ] == NULL
|| V_18 [ V_76 ] == NULL
|| ( V_49
&& ( ( V_18 [ V_77 ] = F_39 ( V_49 ) )
== NULL ) ) )
goto V_59;
V_43 = 1 ;
}
}
} else if ( V_44 == V_66 ) {
if ( V_16 < 0 ) {
F_10 ( V_13 ,
L_46 ,
V_24 ) ;
V_42 ++ ;
} else {
char * * V_79 = F_8 ( V_1 -> V_1 -> V_6 , V_16 ) ;
F_10 ( V_13 , L_47 , V_24 ) ;
V_79 [ V_7 ] [ 0 ] = 'R' ;
V_43 = 1 ;
}
}
if ( -- V_37 > 0 )
V_24 = * ( V_38 ++ ) ;
else {
V_24 = NULL ;
}
}
if ( V_10 )
F_10 ( V_13 , L_48 ) ;
if ( V_43 ) {
for ( V_4 = 0 ; V_4 < F_7 ( V_1 -> V_1 -> V_6 ) ; V_4 ++ ) {
V_3 = F_8 ( V_1 -> V_1 -> V_6 , V_4 ) ;
if ( V_3 [ V_7 ] [ 0 ] == 'v' ) {
V_3 [ V_7 ] [ 0 ] = 'V' ;
F_12 ( V_1 , V_4 , V_10 ) ;
}
}
if ( V_10 )
F_10 ( V_13 , L_49 ) ;
if ( ! F_40 ( V_53 , L_50 , V_1 ) )
goto V_59;
if ( V_10 )
F_10 ( V_13 , L_51 ) ;
if ( ! F_41 ( V_53 , L_50 , L_52 ) )
goto V_59;
if ( V_10 )
F_10 ( V_13 , L_53 ) ;
}
V_41 = ( V_42 != 0 ) ;
V_59:
if ( V_42 != 0 )
if ( V_10 )
F_10 ( V_13 , L_54 , V_42 ) ;
if ( V_10 )
F_10 ( V_13 , L_55 , V_41 ) ;
F_16 ( V_29 ) ;
F_16 ( V_35 ) ;
if ( V_41 )
F_42 ( V_13 ) ;
if ( V_50 )
F_43 ( V_50 ) ;
F_44 ( V_20 ) ;
F_45 ( V_1 ) ;
return ( V_41 ) ;
}
