static int F_1 ( const T_1 * const * V_1 , const unsigned int * V_2 )
{
return ( strcmp ( ( * V_1 ) -> V_3 , V_4 [ * V_2 ] . V_3 ) ) ;
}
static int F_2 ( const T_1 * const * V_1 , const unsigned int * V_2 )
{
return ( strcmp ( ( * V_1 ) -> V_5 , V_4 [ * V_2 ] . V_5 ) ) ;
}
static unsigned long F_3 ( const T_2 * V_6 )
{
const T_1 * V_1 ;
int V_7 ;
unsigned long V_8 = 0 ;
unsigned char * V_9 ;
V_1 = V_6 -> V_10 ;
switch ( V_6 -> type ) {
case V_11 :
V_8 = V_1 -> V_12 << 20L ;
V_9 = ( unsigned char * ) V_1 -> V_13 ;
for ( V_7 = 0 ; V_7 < V_1 -> V_12 ; V_7 ++ )
V_8 ^= V_9 [ V_7 ] << ( ( V_7 * 3 ) % 24 ) ;
break;
case V_14 :
V_8 = F_4 ( V_1 -> V_3 ) ;
break;
case V_15 :
V_8 = F_4 ( V_1 -> V_5 ) ;
break;
case V_16 :
V_8 = V_1 -> V_17 ;
break;
default:
return 0 ;
}
V_8 &= 0x3fffffffL ;
V_8 |= ( ( unsigned long ) V_6 -> type ) << 30L ;
return ( V_8 ) ;
}
static int F_5 ( void )
{
if ( V_18 != NULL )
return ( 1 ) ;
V_18 = F_6 () ;
return ( V_18 != NULL ) ;
}
static void F_7 ( T_2 * V_1 )
{
V_1 -> V_10 -> V_17 = 0 ;
V_1 -> V_10 -> V_19 |= V_20 |
V_21 | V_22 ;
}
static void F_8 ( T_2 * V_1 )
{
V_1 -> V_10 -> V_17 ++ ;
}
static void F_9 ( T_2 * V_1 )
{
if ( -- V_1 -> V_10 -> V_17 == 0 )
F_10 ( V_1 -> V_10 ) ;
F_11 ( V_1 ) ;
}
void F_12 ( int V_17 )
{
if ( ! V_23 && V_17 >= V_24 )
V_23 = 1 ;
}
void F_13 ( void )
{
if ( V_23 ) {
V_23 = 2 ;
return;
}
if ( V_18 == NULL )
return;
F_14 ( V_18 ) = 0 ;
F_15 ( V_18 , F_16 ( V_25 ) ) ;
F_15 ( V_18 , F_16 ( V_26 ) ) ;
F_15 ( V_18 , F_16 ( V_27 ) ) ;
F_17 ( V_18 ) ;
V_18 = NULL ;
}
int F_18 ( int V_28 )
{
int V_7 ;
V_7 = V_29 ;
V_29 += V_28 ;
return ( V_7 ) ;
}
int F_19 ( const T_1 * V_10 )
{
T_1 * V_30 ;
T_2 * V_31 [ 4 ] = { NULL , NULL , NULL , NULL } , * V_32 ;
int V_7 ;
if ( V_18 == NULL )
if ( ! F_5 () )
return ( 0 ) ;
if ( ( V_30 = F_20 ( V_10 ) ) == NULL )
goto V_33;
if ( ! ( V_31 [ V_16 ] = ( T_2 * ) F_21 ( sizeof( T_2 ) ) ) )
goto V_34;
if ( ( V_30 -> V_12 != 0 ) && ( V_10 -> V_13 != NULL ) )
if ( !
( V_31 [ V_11 ] = ( T_2 * ) F_21 ( sizeof( T_2 ) ) ) )
goto V_34;
if ( V_30 -> V_3 != NULL )
if ( !
( V_31 [ V_14 ] =
( T_2 * ) F_21 ( sizeof( T_2 ) ) ) )
goto V_34;
if ( V_30 -> V_5 != NULL )
if ( !
( V_31 [ V_15 ] =
( T_2 * ) F_21 ( sizeof( T_2 ) ) ) )
goto V_34;
for ( V_7 = V_11 ; V_7 <= V_16 ; V_7 ++ ) {
if ( V_31 [ V_7 ] != NULL ) {
V_31 [ V_7 ] -> type = V_7 ;
V_31 [ V_7 ] -> V_10 = V_30 ;
V_32 = F_22 ( V_18 , V_31 [ V_7 ] ) ;
if ( V_32 != NULL )
F_11 ( V_32 ) ;
}
}
V_30 -> V_19 &=
~ ( V_20 | V_21 |
V_22 ) ;
return ( V_30 -> V_17 ) ;
V_34:
F_23 ( V_35 , V_36 ) ;
V_33:
for ( V_7 = V_11 ; V_7 <= V_16 ; V_7 ++ )
if ( V_31 [ V_7 ] != NULL )
F_11 ( V_31 [ V_7 ] ) ;
if ( V_30 != NULL )
F_11 ( V_30 ) ;
return ( V_37 ) ;
}
T_1 * F_24 ( int V_38 )
{
T_2 V_39 , * V_40 ;
T_1 V_41 ;
if ( ( V_38 >= 0 ) && ( V_38 < V_24 ) ) {
if ( ( V_38 != V_37 ) && ( V_4 [ V_38 ] . V_17 == V_37 ) ) {
F_23 ( V_42 , V_43 ) ;
return ( NULL ) ;
}
return ( ( T_1 * ) & ( V_4 [ V_38 ] ) ) ;
} else if ( V_18 == NULL )
return ( NULL ) ;
else {
V_39 . type = V_16 ;
V_39 . V_10 = & V_41 ;
V_41 . V_17 = V_38 ;
V_40 = F_25 ( V_18 , & V_39 ) ;
if ( V_40 != NULL )
return ( V_40 -> V_10 ) ;
else {
F_23 ( V_42 , V_43 ) ;
return ( NULL ) ;
}
}
}
const char * F_26 ( int V_38 )
{
T_2 V_39 , * V_40 ;
T_1 V_41 ;
if ( ( V_38 >= 0 ) && ( V_38 < V_24 ) ) {
if ( ( V_38 != V_37 ) && ( V_4 [ V_38 ] . V_17 == V_37 ) ) {
F_23 ( V_44 , V_43 ) ;
return ( NULL ) ;
}
return ( V_4 [ V_38 ] . V_3 ) ;
} else if ( V_18 == NULL )
return ( NULL ) ;
else {
V_39 . type = V_16 ;
V_39 . V_10 = & V_41 ;
V_41 . V_17 = V_38 ;
V_40 = F_25 ( V_18 , & V_39 ) ;
if ( V_40 != NULL )
return ( V_40 -> V_10 -> V_3 ) ;
else {
F_23 ( V_44 , V_43 ) ;
return ( NULL ) ;
}
}
}
const char * F_27 ( int V_38 )
{
T_2 V_39 , * V_40 ;
T_1 V_41 ;
if ( ( V_38 >= 0 ) && ( V_38 < V_24 ) ) {
if ( ( V_38 != V_37 ) && ( V_4 [ V_38 ] . V_17 == V_37 ) ) {
F_23 ( V_45 , V_43 ) ;
return ( NULL ) ;
}
return ( V_4 [ V_38 ] . V_5 ) ;
} else if ( V_18 == NULL )
return ( NULL ) ;
else {
V_39 . type = V_16 ;
V_39 . V_10 = & V_41 ;
V_41 . V_17 = V_38 ;
V_40 = F_25 ( V_18 , & V_39 ) ;
if ( V_40 != NULL )
return ( V_40 -> V_10 -> V_5 ) ;
else {
F_23 ( V_45 , V_43 ) ;
return ( NULL ) ;
}
}
}
static int F_28 ( const T_1 * const * V_46 , const unsigned int * V_47 )
{
int V_48 ;
const T_1 * V_1 = * V_46 ;
const T_1 * V_2 = & V_4 [ * V_47 ] ;
V_48 = ( V_1 -> V_12 - V_2 -> V_12 ) ;
if ( V_48 )
return ( V_48 ) ;
return ( memcmp ( V_1 -> V_13 , V_2 -> V_13 , V_1 -> V_12 ) ) ;
}
int F_29 ( const T_1 * V_1 )
{
const unsigned int * V_49 ;
T_2 V_39 , * V_40 ;
if ( V_1 == NULL )
return ( V_37 ) ;
if ( V_1 -> V_17 != 0 )
return ( V_1 -> V_17 ) ;
if ( V_18 != NULL ) {
V_39 . type = V_11 ;
V_39 . V_10 = ( T_1 * ) V_1 ;
V_40 = F_25 ( V_18 , & V_39 ) ;
if ( V_40 != NULL )
return ( V_40 -> V_10 -> V_17 ) ;
}
V_49 = F_30 ( & V_1 , V_50 , V_51 ) ;
if ( V_49 == NULL )
return ( V_37 ) ;
return ( V_4 [ * V_49 ] . V_17 ) ;
}
T_1 * F_31 ( const char * V_52 , int V_53 )
{
int V_17 = V_37 ;
T_1 * V_49 = NULL ;
unsigned char * V_54 ;
unsigned char * V_9 ;
const unsigned char * V_55 ;
int V_7 , V_48 ;
if ( ! V_53 ) {
if ( ( ( V_17 = F_32 ( V_52 ) ) != V_37 ) ||
( ( V_17 = F_33 ( V_52 ) ) != V_37 ) )
return F_24 ( V_17 ) ;
}
V_7 = F_34 ( NULL , 0 , V_52 , - 1 ) ;
if ( V_7 <= 0 ) {
return NULL ;
}
V_48 = F_35 ( 0 , V_7 , V_56 ) ;
if ( ( V_54 = ( unsigned char * ) F_21 ( V_48 ) ) == NULL )
return NULL ;
V_9 = V_54 ;
F_36 ( & V_9 , 0 , V_7 , V_56 , V_57 ) ;
F_34 ( V_9 , V_7 , V_52 , - 1 ) ;
V_55 = V_54 ;
V_49 = F_37 ( NULL , & V_55 , V_48 ) ;
F_11 ( V_54 ) ;
return V_49 ;
}
int F_38 ( char * V_54 , int V_58 , const T_1 * V_1 , int V_53 )
{
int V_7 , V_38 = 0 , V_59 , V_17 , V_60 , V_61 ;
T_3 * V_62 ;
unsigned long V_63 ;
const unsigned char * V_9 ;
char V_64 [ F_39 ( V_7 ) + F_39 ( V_63 ) + 2 ] ;
if ( V_54 && V_58 > 0 )
V_54 [ 0 ] = '\0' ;
if ( ( V_1 == NULL ) || ( V_1 -> V_13 == NULL ) )
return ( 0 ) ;
if ( ! V_53 && ( V_17 = F_29 ( V_1 ) ) != V_37 ) {
const char * V_52 ;
V_52 = F_27 ( V_17 ) ;
if ( V_52 == NULL )
V_52 = F_26 ( V_17 ) ;
if ( V_52 ) {
if ( V_54 )
F_40 ( V_54 , V_52 , V_58 ) ;
V_38 = strlen ( V_52 ) ;
return V_38 ;
}
}
V_59 = V_1 -> V_12 ;
V_9 = V_1 -> V_13 ;
V_60 = 1 ;
V_62 = NULL ;
while ( V_59 > 0 ) {
V_63 = 0 ;
V_61 = 0 ;
for (; ; ) {
unsigned char V_65 = * V_9 ++ ;
V_59 -- ;
if ( ( V_59 == 0 ) && ( V_65 & 0x80 ) )
goto V_33;
if ( V_61 ) {
if ( ! F_41 ( V_62 , V_65 & 0x7f ) )
goto V_33;
} else
V_63 |= V_65 & 0x7f ;
if ( ! ( V_65 & 0x80 ) )
break;
if ( ! V_61 && ( V_63 > ( V_66 >> 7L ) ) ) {
if ( ! V_62 && ! ( V_62 = F_42 () ) )
goto V_33;
if ( ! F_43 ( V_62 , V_63 ) )
goto V_33;
V_61 = 1 ;
}
if ( V_61 ) {
if ( ! F_44 ( V_62 , V_62 , 7 ) )
goto V_33;
} else
V_63 <<= 7L ;
}
if ( V_60 ) {
V_60 = 0 ;
if ( V_63 >= 80 ) {
V_7 = 2 ;
if ( V_61 ) {
if ( ! F_45 ( V_62 , 80 ) )
goto V_33;
} else
V_63 -= 80 ;
} else {
V_7 = ( int ) ( V_63 / 40 ) ;
V_63 -= ( long ) ( V_7 * 40 ) ;
}
if ( V_54 && ( V_58 > 1 ) ) {
* V_54 ++ = V_7 + '0' ;
* V_54 = '\0' ;
V_58 -- ;
}
V_38 ++ ;
}
if ( V_61 ) {
char * V_67 ;
V_67 = F_46 ( V_62 ) ;
if ( ! V_67 )
goto V_33;
V_7 = strlen ( V_67 ) ;
if ( V_54 ) {
if ( V_58 > 1 ) {
* V_54 ++ = '.' ;
* V_54 = '\0' ;
V_58 -- ;
}
F_40 ( V_54 , V_67 , V_58 ) ;
if ( V_7 > V_58 ) {
V_54 += V_58 ;
V_58 = 0 ;
} else {
V_54 += V_7 ;
V_58 -= V_7 ;
}
}
V_38 ++ ;
V_38 += V_7 ;
F_11 ( V_67 ) ;
} else {
F_47 ( V_64 , sizeof V_64 , L_1 , V_63 ) ;
V_7 = strlen ( V_64 ) ;
if ( V_54 && ( V_58 > 0 ) ) {
F_40 ( V_54 , V_64 , V_58 ) ;
if ( V_7 > V_58 ) {
V_54 += V_58 ;
V_58 = 0 ;
} else {
V_54 += V_7 ;
V_58 -= V_7 ;
}
}
V_38 += V_7 ;
V_63 = 0 ;
}
}
if ( V_62 )
F_48 ( V_62 ) ;
return V_38 ;
V_33:
if ( V_62 )
F_48 ( V_62 ) ;
return - 1 ;
}
int F_49 ( const char * V_52 )
{
T_1 * V_10 ;
int V_17 ;
V_10 = F_31 ( V_52 , 0 ) ;
V_17 = F_29 ( V_10 ) ;
F_10 ( V_10 ) ;
return V_17 ;
}
int F_33 ( const char * V_52 )
{
T_1 V_30 ;
const T_1 * V_68 = & V_30 ;
T_2 V_39 , * V_40 ;
const unsigned int * V_49 ;
V_30 . V_5 = V_52 ;
if ( V_18 != NULL ) {
V_39 . type = V_15 ;
V_39 . V_10 = & V_30 ;
V_40 = F_25 ( V_18 , & V_39 ) ;
if ( V_40 != NULL )
return ( V_40 -> V_10 -> V_17 ) ;
}
V_49 = F_50 ( & V_68 , V_69 , V_70 ) ;
if ( V_49 == NULL )
return ( V_37 ) ;
return ( V_4 [ * V_49 ] . V_17 ) ;
}
int F_32 ( const char * V_52 )
{
T_1 V_30 ;
const T_1 * V_68 = & V_30 ;
T_2 V_39 , * V_40 ;
const unsigned int * V_49 ;
V_30 . V_3 = V_52 ;
if ( V_18 != NULL ) {
V_39 . type = V_14 ;
V_39 . V_10 = & V_30 ;
V_40 = F_25 ( V_18 , & V_39 ) ;
if ( V_40 != NULL )
return ( V_40 -> V_10 -> V_17 ) ;
}
V_49 = F_51 ( & V_68 , V_71 , V_72 ) ;
if ( V_49 == NULL )
return ( V_37 ) ;
return ( V_4 [ * V_49 ] . V_17 ) ;
}
const void * F_52 ( const void * V_73 , const void * V_74 , int V_28 , int V_75 ,
int (* F_53) ( const void * , const void * ) )
{
return F_54 ( V_73 , V_74 , V_28 , V_75 , F_53 , 0 ) ;
}
const void * F_54 ( const void * V_73 , const void * V_76 , int V_28 ,
int V_75 ,
int (* F_53) ( const void * , const void * ) ,
int V_19 )
{
const char * V_74 = V_76 ;
int V_63 , V_77 , V_7 = 0 , V_65 = 0 ;
const char * V_9 = NULL ;
if ( V_28 == 0 )
return ( NULL ) ;
V_63 = 0 ;
V_77 = V_28 ;
while ( V_63 < V_77 ) {
V_7 = ( V_63 + V_77 ) / 2 ;
V_9 = & ( V_74 [ V_7 * V_75 ] ) ;
V_65 = (* F_53) ( V_73 , V_9 ) ;
if ( V_65 < 0 )
V_77 = V_7 ;
else if ( V_65 > 0 )
V_63 = V_7 + 1 ;
else
break;
}
#ifdef F_55
if ( V_65 != 0 ) {
for ( V_7 = 0 ; V_7 < V_28 ; ++ V_7 ) {
V_9 = & ( V_74 [ V_7 * V_75 ] ) ;
V_65 = (* F_53) ( V_73 , V_9 ) ;
if ( V_65 == 0 || ( V_65 < 0 && ( V_19 & V_78 ) ) )
return V_9 ;
}
}
#endif
if ( V_65 != 0 && ! ( V_19 & V_78 ) )
V_9 = NULL ;
else if ( V_65 == 0 && ( V_19 & V_79 ) ) {
while ( V_7 > 0 && (* F_53) ( V_73 , & ( V_74 [ ( V_7 - 1 ) * V_75 ] ) ) == 0 )
V_7 -- ;
V_9 = & ( V_74 [ V_7 * V_75 ] ) ;
}
return ( V_9 ) ;
}
int F_56 ( T_4 * V_80 )
{
T_5 char V_54 [ 512 ] ;
int V_7 , V_28 = 0 ;
char * V_30 , * V_52 , * V_63 = NULL ;
for (; ; ) {
V_52 = V_30 = NULL ;
V_7 = F_57 ( V_80 , V_54 , 512 ) ;
if ( V_7 <= 0 )
return ( V_28 ) ;
V_54 [ V_7 - 1 ] = '\0' ;
if ( ! isalnum ( ( unsigned char ) V_54 [ 0 ] ) )
return ( V_28 ) ;
V_30 = V_52 = V_54 ;
while ( isdigit ( ( unsigned char ) * V_52 ) || ( * V_52 == '.' ) )
V_52 ++ ;
if ( * V_52 != '\0' ) {
* ( V_52 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_52 ) )
V_52 ++ ;
if ( * V_52 == '\0' )
V_52 = NULL ;
else {
V_63 = V_52 ;
while ( ( * V_63 != '\0' ) && ! isspace ( ( unsigned char ) * V_63 ) )
V_63 ++ ;
if ( * V_63 != '\0' ) {
* ( V_63 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_63 ) )
V_63 ++ ;
if ( * V_63 == '\0' )
V_63 = NULL ;
} else
V_63 = NULL ;
}
} else
V_52 = NULL ;
if ( ( V_30 == NULL ) || ( * V_30 == '\0' ) )
return ( V_28 ) ;
if ( ! F_58 ( V_30 , V_52 , V_63 ) )
return ( V_28 ) ;
V_28 ++ ;
}
}
int F_58 ( const char * V_81 , const char * V_3 , const char * V_5 )
{
int V_82 = 0 ;
T_1 * V_49 = NULL ;
unsigned char * V_54 ;
int V_7 ;
V_7 = F_34 ( NULL , 0 , V_81 , - 1 ) ;
if ( V_7 <= 0 )
return ( 0 ) ;
if ( ( V_54 = ( unsigned char * ) F_21 ( V_7 ) ) == NULL ) {
F_23 ( V_83 , V_36 ) ;
return ( 0 ) ;
}
V_7 = F_34 ( V_54 , V_7 , V_81 , - 1 ) ;
if ( V_7 == 0 )
goto V_33;
V_49 = ( T_1 * ) F_59 ( F_18 ( 1 ) , V_54 , V_7 , V_3 , V_5 ) ;
if ( V_49 == NULL )
goto V_33;
V_82 = F_19 ( V_49 ) ;
V_33:
F_10 ( V_49 ) ;
F_11 ( V_54 ) ;
return ( V_82 ) ;
}
