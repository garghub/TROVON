static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_1 * V_3 ;
if( ! ( V_3 = F_2 ( F_3 () ) ) ) {
F_4 ( V_4 , V_5 ) ;
return 0 ;
}
V_1 = F_5 ( V_3 , V_1 ) ;
F_6 ( V_1 , V_2 ) ;
F_7 ( V_1 ) ;
V_1 = F_8 ( V_1 ) ;
F_9 ( V_3 ) ;
return 1 ;
}
static T_2 * F_10 ( T_1 * V_1 )
{
T_1 * V_3 ;
T_2 * V_2 ;
if( ! ( V_3 = F_2 ( F_3 () ) ) ) {
F_4 ( V_6 , V_5 ) ;
return 0 ;
}
V_1 = F_5 ( V_3 , V_1 ) ;
if( ! ( V_2 = F_11 ( V_1 , NULL ) ) )
F_4 ( V_6 , V_7 ) ;
F_7 ( V_1 ) ;
V_1 = F_8 ( V_1 ) ;
F_9 ( V_3 ) ;
return V_2 ;
}
int F_12 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_8 , int V_9 )
{
char V_10 [ V_11 ] ;
char V_12 [ 33 ] , V_13 ;
int V_14 ;
if( ( V_9 & V_15 ) && V_8 ) {
F_13 ( ( unsigned char * ) V_12 , 32 ) ;
for( V_14 = 0 ; V_14 < 32 ; V_14 ++ ) {
V_13 = V_12 [ V_14 ] & 0xf ;
if( V_13 < 10 ) V_13 += '0' ;
else V_13 += 'A' - 10 ;
V_12 [ V_14 ] = V_13 ;
}
V_12 [ 32 ] = 0 ;
F_14 ( V_1 , L_1 ) ;
F_14 ( V_1 , L_2 ) ;
F_14 ( V_1 , L_3 ) ;
F_14 ( V_1 , L_4 , V_12 ) ;
F_14 ( V_1 , L_5 ) ;
F_14 ( V_1 , L_6 , V_12 ) ;
if( V_9 & V_16 ) F_14 ( V_1 , L_7 ) ;
while( ( V_14 = F_15 ( V_8 , V_10 , V_11 ) ) > 0 )
F_16 ( V_1 , V_10 , V_14 ) ;
F_14 ( V_1 , L_8 , V_12 ) ;
F_14 ( V_1 , L_9 ) ;
F_14 ( V_1 , L_10 ) ;
F_14 ( V_1 , L_11 ) ;
F_1 ( V_1 , V_2 ) ;
F_14 ( V_1 , L_12 , V_12 ) ;
return 1 ;
}
F_14 ( V_1 , L_1 ) ;
F_14 ( V_1 , L_13 ) ;
F_14 ( V_1 , L_14 ) ;
F_14 ( V_1 , L_15 ) ;
F_1 ( V_1 , V_2 ) ;
F_14 ( V_1 , L_16 ) ;
return 1 ;
}
T_2 * F_17 ( T_1 * V_1 , T_1 * * V_17 )
{
T_1 * V_18 ;
T_3 * V_19 = NULL ;
T_3 * V_20 = NULL ;
T_4 * V_21 ;
T_5 * V_22 ;
T_2 * V_2 ;
int V_23 ;
if( V_17 ) * V_17 = NULL ;
if ( ! ( V_19 = F_18 ( V_1 ) ) ) {
F_4 ( V_24 , V_25 ) ;
return NULL ;
}
if( ! ( V_21 = F_19 ( V_19 , L_17 ) ) || ! V_21 -> V_26 ) {
F_20 ( V_19 , V_27 ) ;
F_4 ( V_24 , V_28 ) ;
return NULL ;
}
if( ! strcmp ( V_21 -> V_26 , L_18 ) ) {
V_22 = F_21 ( V_21 , L_19 ) ;
if( ! V_22 || ! V_22 -> V_29 ) {
F_20 ( V_19 , V_27 ) ;
F_4 ( V_24 , V_30 ) ;
return NULL ;
}
V_23 = F_22 ( V_1 , V_22 -> V_29 , & V_20 ) ;
F_20 ( V_19 , V_27 ) ;
if( ! V_23 || ( F_23 ( V_20 ) != 2 ) ) {
F_4 ( V_24 , V_31 ) ;
F_20 ( V_20 , ( V_32 ) F_9 ) ;
return NULL ;
}
V_18 = ( T_1 * ) F_24 ( V_20 , 1 ) ;
if ( ! ( V_19 = F_18 ( V_18 ) ) ) {
F_4 ( V_24 , V_33 ) ;
F_20 ( V_20 , ( V_32 ) F_9 ) ;
return NULL ;
}
if( ! ( V_21 = F_19 ( V_19 , L_17 ) ) ||
! V_21 -> V_26 ) {
F_20 ( V_19 , V_27 ) ;
F_4 ( V_24 , V_34 ) ;
return NULL ;
}
if( strcmp ( V_21 -> V_26 , L_20 ) &&
strcmp ( V_21 -> V_26 , L_21 ) ) {
F_20 ( V_19 , V_27 ) ;
F_4 ( V_24 , V_35 ) ;
F_25 ( 2 , L_22 , V_21 -> V_26 ) ;
F_20 ( V_20 , ( V_32 ) F_9 ) ;
return NULL ;
}
F_20 ( V_19 , V_27 ) ;
if( ! ( V_2 = F_10 ( V_18 ) ) ) {
F_4 ( V_24 , V_36 ) ;
F_20 ( V_20 , ( V_32 ) F_9 ) ;
return NULL ;
}
if( V_17 ) {
* V_17 = ( T_1 * ) F_24 ( V_20 , 0 ) ;
F_9 ( V_18 ) ;
F_26 ( V_20 ) ;
} else F_20 ( V_20 , ( V_32 ) F_9 ) ;
return V_2 ;
}
if ( strcmp ( V_21 -> V_26 , L_23 ) &&
strcmp ( V_21 -> V_26 , L_24 ) ) {
F_4 ( V_24 , V_37 ) ;
F_25 ( 2 , L_22 , V_21 -> V_26 ) ;
F_20 ( V_19 , V_27 ) ;
return NULL ;
}
F_20 ( V_19 , V_27 ) ;
if( ! ( V_2 = F_10 ( V_1 ) ) ) {
F_4 ( V_24 , V_38 ) ;
return NULL ;
}
return V_2 ;
}
int F_27 ( T_1 * V_39 , T_1 * V_40 , int V_9 )
{
char V_41 ;
int V_42 ;
char V_10 [ V_11 ] ;
if( V_9 & V_43 ) {
while( ( V_42 = F_15 ( V_39 , V_10 , V_11 ) ) > 0 )
F_16 ( V_40 , V_10 , V_42 ) ;
return 1 ;
}
if( V_9 & V_16 ) F_14 ( V_40 , L_25 ) ;
while ( ( V_42 = F_28 ( V_39 , V_10 , V_11 ) ) > 0 ) {
V_41 = 0 ;
while( F_29 ( V_10 [ V_42 - 1 ] ) ) {
V_42 -- ;
V_41 = 1 ;
}
F_16 ( V_40 , V_10 , V_42 ) ;
if( V_41 ) F_16 ( V_40 , L_26 , 2 ) ;
}
return 1 ;
}
int F_30 ( T_1 * V_39 , T_1 * V_40 )
{
char V_44 [ 4096 ] ;
int V_42 ;
T_3 * V_19 ;
T_4 * V_21 ;
if ( ! ( V_19 = F_18 ( V_39 ) ) ) {
F_4 ( V_45 , V_25 ) ;
return 0 ;
}
if( ! ( V_21 = F_19 ( V_19 , L_17 ) ) || ! V_21 -> V_26 ) {
F_4 ( V_45 , V_46 ) ;
F_20 ( V_19 , V_27 ) ;
return 0 ;
}
if ( strcmp ( V_21 -> V_26 , L_27 ) ) {
F_4 ( V_45 , V_37 ) ;
F_25 ( 2 , L_22 , V_21 -> V_26 ) ;
F_20 ( V_19 , V_27 ) ;
return 0 ;
}
F_20 ( V_19 , V_27 ) ;
while ( ( V_42 = F_15 ( V_39 , V_44 , sizeof( V_44 ) ) ) > 0 )
F_16 ( V_40 , V_44 , V_42 ) ;
return 1 ;
}
static int F_22 ( T_1 * V_1 , char * V_12 , T_3 * * V_23 )
{
char V_10 [ V_11 ] ;
int V_42 , V_47 ;
T_1 * V_48 = NULL ;
T_3 * V_20 ;
char V_49 , V_50 , V_51 ;
V_47 = strlen ( V_12 ) ;
V_50 = 0 ;
V_49 = 0 ;
V_51 = 1 ;
V_20 = F_31 ( NULL ) ;
* V_23 = V_20 ;
while ( ( V_42 = F_28 ( V_1 , V_10 , V_11 ) ) > 0 ) {
V_49 = F_32 ( V_10 , V_42 , V_12 , V_47 ) ;
if( V_49 == 1 ) {
V_51 = 1 ;
V_50 ++ ;
} else if( V_49 == 2 ) {
F_33 ( V_20 , ( char * ) V_48 ) ;
return 1 ;
} else if( V_50 ) {
if( V_51 ) {
V_51 = 0 ;
if( V_48 ) F_33 ( V_20 , ( char * ) V_48 ) ;
V_48 = F_2 ( F_34 () ) ;
} else F_16 ( V_48 , L_26 , 2 ) ;
while( F_29 ( V_10 [ V_42 - 1 ] ) ) V_42 -- ;
F_16 ( V_48 , V_10 , V_42 ) ;
}
}
return 0 ;
}
static int F_29 ( char V_13 )
{
if( V_13 == '\r' || V_13 == '\n' ) return 1 ;
return 0 ;
}
static T_3 * F_18 ( T_1 * V_1 )
{
char * V_52 , * V_53 , V_13 ;
char * V_54 ;
char V_10 [ V_11 ] ;
T_4 * V_55 = NULL ;
T_3 * V_19 ;
int V_42 , V_49 , V_56 = 0 ;
V_19 = F_31 ( V_57 ) ;
while ( ( V_42 = F_28 ( V_1 , V_10 , V_11 ) ) > 0 ) {
if( V_55 && isspace ( ( unsigned char ) V_10 [ 0 ] ) ) V_49 = V_58 ;
else V_49 = V_59 ;
V_54 = NULL ;
for( V_52 = V_10 , V_53 = V_10 ; ( V_13 = * V_52 ) && ( V_13 != '\r' ) && ( V_13 != '\n' ) ; V_52 ++ ) {
switch( V_49 ) {
case V_59 :
if( V_13 == ':' ) {
V_49 = V_60 ;
* V_52 = 0 ;
V_54 = F_35 ( V_53 ) ;
V_53 = V_52 + 1 ;
}
break;
case V_60 :
if( V_13 == ';' ) {
F_36 ( L_28 ) ;
* V_52 = 0 ;
V_55 = F_37 ( V_54 , F_35 ( V_53 ) ) ;
F_33 ( V_19 , ( char * ) V_55 ) ;
V_54 = NULL ;
V_53 = V_52 + 1 ;
V_49 = V_58 ;
} else if( V_13 == '(' ) {
V_56 = V_49 ;
V_49 = V_61 ;
}
break;
case V_61 :
if( V_13 == ')' ) {
V_49 = V_56 ;
}
break;
case V_58 :
if( V_13 == '=' ) {
V_49 = V_62 ;
* V_52 = 0 ;
V_54 = F_35 ( V_53 ) ;
V_53 = V_52 + 1 ;
}
break ;
case V_62 :
if( V_13 == ';' ) {
V_49 = V_58 ;
* V_52 = 0 ;
F_38 ( V_55 , V_54 , F_35 ( V_53 ) ) ;
V_54 = NULL ;
V_53 = V_52 + 1 ;
} else if ( V_13 == '"' ) {
F_36 ( L_29 ) ;
V_49 = V_63 ;
} else if( V_13 == '(' ) {
V_56 = V_49 ;
V_49 = V_61 ;
}
break;
case V_63 :
if( V_13 == '"' ) {
F_36 ( L_30 ) ;
V_49 = V_62 ;
}
break;
}
}
if( V_49 == V_60 ) {
V_55 = F_37 ( V_54 , F_35 ( V_53 ) ) ;
F_33 ( V_19 , ( char * ) V_55 ) ;
} else if( V_49 == V_62 )
F_38 ( V_55 , V_54 , F_35 ( V_53 ) ) ;
if( V_52 == V_10 ) break;
}
return V_19 ;
}
static char * F_35 ( char * V_64 )
{
return F_39 ( F_40 ( V_64 ) ) ;
}
static char * F_40 ( char * V_64 )
{
char * V_52 , V_13 ;
for( V_52 = V_64 ; ( V_13 = * V_52 ) ; V_52 ++ ) {
if( V_13 == '"' ) {
if( V_52 [ 1 ] ) return V_52 + 1 ;
return NULL ;
}
if( ! isspace ( ( unsigned char ) V_13 ) ) return V_52 ;
}
return NULL ;
}
static char * F_39 ( char * V_64 )
{
char * V_52 , V_13 ;
if( ! V_64 ) return NULL ;
for( V_52 = V_64 + strlen ( V_64 ) - 1 ; V_52 >= V_64 ; V_52 -- ) {
V_13 = * V_52 ;
if( V_13 == '"' ) {
if( V_52 - 1 == V_64 ) return NULL ;
* V_52 = 0 ;
return V_64 ;
}
if( isspace ( ( unsigned char ) V_13 ) ) * V_52 = 0 ;
else return V_64 ;
}
return NULL ;
}
static T_4 * F_37 ( char * V_64 , char * V_26 )
{
T_4 * V_55 ;
char * V_65 , * V_66 , * V_52 ;
int V_13 ;
if( V_64 ) {
if( ! ( V_65 = F_41 ( V_64 ) ) ) return NULL ;
for( V_52 = V_65 ; * V_52 ; V_52 ++ ) {
V_13 = * V_52 ;
if( isupper ( V_13 ) ) {
V_13 = tolower ( V_13 ) ;
* V_52 = V_13 ;
}
}
} else V_65 = NULL ;
if( V_26 ) {
if( ! ( V_66 = F_41 ( V_26 ) ) ) return NULL ;
for( V_52 = V_66 ; * V_52 ; V_52 ++ ) {
V_13 = * V_52 ;
if( isupper ( V_13 ) ) {
V_13 = tolower ( V_13 ) ;
* V_52 = V_13 ;
}
}
} else V_66 = NULL ;
V_55 = ( T_4 * ) Malloc ( sizeof( T_4 ) ) ;
if( ! V_55 ) return NULL ;
V_55 -> V_64 = V_65 ;
V_55 -> V_26 = V_66 ;
if( ! ( V_55 -> V_67 = F_31 ( V_68 ) ) ) return NULL ;
return V_55 ;
}
static int F_38 ( T_4 * V_55 , char * V_64 , char * V_26 )
{
char * V_65 , * V_66 , * V_52 ;
int V_13 ;
T_5 * V_69 ;
if( V_64 ) {
V_65 = F_41 ( V_64 ) ;
if( ! V_65 ) return 0 ;
for( V_52 = V_65 ; * V_52 ; V_52 ++ ) {
V_13 = * V_52 ;
if( isupper ( V_13 ) ) {
V_13 = tolower ( V_13 ) ;
* V_52 = V_13 ;
}
}
} else V_65 = NULL ;
if( V_26 ) {
V_66 = F_41 ( V_26 ) ;
if( ! V_66 ) return 0 ;
} else V_66 = NULL ;
V_69 = ( T_5 * ) Malloc ( sizeof( T_5 ) ) ;
if( ! V_69 ) return 0 ;
V_69 -> V_70 = V_65 ;
V_69 -> V_29 = V_66 ;
F_33 ( V_55 -> V_67 , ( char * ) V_69 ) ;
return 1 ;
}
static int V_57 ( T_4 * * V_71 , T_4 * * V_72 )
{
return ( strcmp ( ( * V_71 ) -> V_64 , ( * V_72 ) -> V_64 ) ) ;
}
static int V_68 ( T_5 * * V_71 , T_5 * * V_72 )
{
return ( strcmp ( ( * V_71 ) -> V_70 , ( * V_72 ) -> V_70 ) ) ;
}
static T_4 * F_19 ( T_3 * V_73 , char * V_64 )
{
T_4 V_74 ;
int V_75 ;
V_74 . V_64 = V_64 ;
V_75 = F_42 ( V_73 , ( char * ) & V_74 ) ;
if( V_75 < 0 ) return NULL ;
return ( T_4 * ) F_24 ( V_73 , V_75 ) ;
}
static T_5 * F_21 ( T_4 * V_21 , char * V_64 )
{
T_5 V_76 ;
int V_75 ;
V_76 . V_70 = V_64 ;
V_75 = F_42 ( V_21 -> V_67 , ( char * ) & V_76 ) ;
if( V_75 < 0 ) return NULL ;
return ( T_5 * ) F_24 ( V_21 -> V_67 , V_75 ) ;
}
static void V_27 ( T_4 * V_21 )
{
if( V_21 -> V_64 ) Free ( V_21 -> V_64 ) ;
if( V_21 -> V_26 ) Free ( V_21 -> V_26 ) ;
if( V_21 -> V_67 ) F_20 ( V_21 -> V_67 , V_77 ) ;
Free ( V_21 ) ;
}
static void V_77 ( T_5 * V_76 )
{
if( V_76 -> V_70 ) Free ( V_76 -> V_70 ) ;
if( V_76 -> V_29 ) Free ( V_76 -> V_29 ) ;
Free ( V_76 ) ;
}
static int F_32 ( char * line , int V_78 , char * V_12 , int V_47 )
{
if( V_78 == - 1 ) V_78 = strlen ( line ) ;
if( V_47 == - 1 ) V_47 = strlen ( V_12 ) ;
if( V_47 + 2 > V_78 ) return 0 ;
if( ! strncmp ( line , L_31 , 2 ) && ! strncmp ( line + 2 , V_12 , V_47 ) ) {
if( ! strncmp ( line + V_47 + 2 , L_31 , 2 ) ) return 2 ;
else return 1 ;
}
return 0 ;
}
