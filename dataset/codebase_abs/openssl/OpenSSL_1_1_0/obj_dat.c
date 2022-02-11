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
static int F_5 ( const T_2 * V_6 , const T_2 * V_18 )
{
T_1 * V_1 , * V_2 ;
int V_7 ;
V_7 = V_6 -> type - V_18 -> type ;
if ( V_7 )
return ( V_7 ) ;
V_1 = V_6 -> V_10 ;
V_2 = V_18 -> V_10 ;
switch ( V_6 -> type ) {
case V_11 :
V_7 = ( V_1 -> V_12 - V_2 -> V_12 ) ;
if ( V_7 )
return ( V_7 ) ;
return ( memcmp ( V_1 -> V_13 , V_2 -> V_13 , ( V_19 ) V_1 -> V_12 ) ) ;
case V_14 :
if ( V_1 -> V_3 == NULL )
return ( - 1 ) ;
else if ( V_2 -> V_3 == NULL )
return ( 1 ) ;
else
return ( strcmp ( V_1 -> V_3 , V_2 -> V_3 ) ) ;
case V_15 :
if ( V_1 -> V_5 == NULL )
return ( - 1 ) ;
else if ( V_2 -> V_5 == NULL )
return ( 1 ) ;
else
return ( strcmp ( V_1 -> V_5 , V_2 -> V_5 ) ) ;
case V_16 :
return ( V_1 -> V_17 - V_2 -> V_17 ) ;
default:
return 0 ;
}
}
static int F_6 ( void )
{
if ( V_20 != NULL )
return ( 1 ) ;
V_20 = F_7 ( F_3 , F_5 ) ;
return ( V_20 != NULL ) ;
}
static void F_8 ( T_2 * V_1 )
{
V_1 -> V_10 -> V_17 = 0 ;
V_1 -> V_10 -> V_21 |= V_22 |
V_23 | V_24 ;
}
static void F_9 ( T_2 * V_1 )
{
V_1 -> V_10 -> V_17 ++ ;
}
static void F_10 ( T_2 * V_1 )
{
if ( -- V_1 -> V_10 -> V_17 == 0 )
F_11 ( V_1 -> V_10 ) ;
F_12 ( V_1 ) ;
}
void F_13 ( void )
{
if ( V_20 == NULL )
return;
F_14 ( V_20 , 0 ) ;
F_15 ( V_20 , F_8 ) ;
F_15 ( V_20 , F_9 ) ;
F_15 ( V_20 , F_10 ) ;
F_16 ( V_20 ) ;
V_20 = NULL ;
}
int F_17 ( int V_25 )
{
int V_7 ;
V_7 = V_26 ;
V_26 += V_25 ;
return ( V_7 ) ;
}
int F_18 ( const T_1 * V_10 )
{
T_1 * V_27 ;
T_2 * V_28 [ 4 ] = { NULL , NULL , NULL , NULL } , * V_29 ;
int V_7 ;
if ( V_20 == NULL )
if ( ! F_6 () )
return ( 0 ) ;
if ( ( V_27 = F_19 ( V_10 ) ) == NULL )
goto V_30;
if ( ( V_28 [ V_16 ] = F_20 ( sizeof( * V_28 [ 0 ] ) ) ) == NULL )
goto V_31;
if ( ( V_27 -> V_12 != 0 ) && ( V_10 -> V_13 != NULL ) )
if ( ( V_28 [ V_11 ] = F_20 ( sizeof( * V_28 [ 0 ] ) ) ) == NULL )
goto V_31;
if ( V_27 -> V_3 != NULL )
if ( ( V_28 [ V_14 ] = F_20 ( sizeof( * V_28 [ 0 ] ) ) ) == NULL )
goto V_31;
if ( V_27 -> V_5 != NULL )
if ( ( V_28 [ V_15 ] = F_20 ( sizeof( * V_28 [ 0 ] ) ) ) == NULL )
goto V_31;
for ( V_7 = V_11 ; V_7 <= V_16 ; V_7 ++ ) {
if ( V_28 [ V_7 ] != NULL ) {
V_28 [ V_7 ] -> type = V_7 ;
V_28 [ V_7 ] -> V_10 = V_27 ;
V_29 = F_21 ( V_20 , V_28 [ V_7 ] ) ;
F_12 ( V_29 ) ;
}
}
V_27 -> V_21 &=
~ ( V_22 | V_23 |
V_24 ) ;
return ( V_27 -> V_17 ) ;
V_31:
F_22 ( V_32 , V_33 ) ;
V_30:
for ( V_7 = V_11 ; V_7 <= V_16 ; V_7 ++ )
F_12 ( V_28 [ V_7 ] ) ;
F_12 ( V_27 ) ;
return ( V_34 ) ;
}
T_1 * F_23 ( int V_35 )
{
T_2 V_36 , * V_37 ;
T_1 V_38 ;
if ( ( V_35 >= 0 ) && ( V_35 < V_39 ) ) {
if ( ( V_35 != V_34 ) && ( V_4 [ V_35 ] . V_17 == V_34 ) ) {
F_22 ( V_40 , V_41 ) ;
return ( NULL ) ;
}
return ( ( T_1 * ) & ( V_4 [ V_35 ] ) ) ;
} else if ( V_20 == NULL )
return ( NULL ) ;
else {
V_36 . type = V_16 ;
V_36 . V_10 = & V_38 ;
V_38 . V_17 = V_35 ;
V_37 = F_24 ( V_20 , & V_36 ) ;
if ( V_37 != NULL )
return ( V_37 -> V_10 ) ;
else {
F_22 ( V_40 , V_41 ) ;
return ( NULL ) ;
}
}
}
const char * F_25 ( int V_35 )
{
T_2 V_36 , * V_37 ;
T_1 V_38 ;
if ( ( V_35 >= 0 ) && ( V_35 < V_39 ) ) {
if ( ( V_35 != V_34 ) && ( V_4 [ V_35 ] . V_17 == V_34 ) ) {
F_22 ( V_42 , V_41 ) ;
return ( NULL ) ;
}
return ( V_4 [ V_35 ] . V_3 ) ;
} else if ( V_20 == NULL )
return ( NULL ) ;
else {
V_36 . type = V_16 ;
V_36 . V_10 = & V_38 ;
V_38 . V_17 = V_35 ;
V_37 = F_24 ( V_20 , & V_36 ) ;
if ( V_37 != NULL )
return ( V_37 -> V_10 -> V_3 ) ;
else {
F_22 ( V_42 , V_41 ) ;
return ( NULL ) ;
}
}
}
const char * F_26 ( int V_35 )
{
T_2 V_36 , * V_37 ;
T_1 V_38 ;
if ( ( V_35 >= 0 ) && ( V_35 < V_39 ) ) {
if ( ( V_35 != V_34 ) && ( V_4 [ V_35 ] . V_17 == V_34 ) ) {
F_22 ( V_43 , V_41 ) ;
return ( NULL ) ;
}
return ( V_4 [ V_35 ] . V_5 ) ;
} else if ( V_20 == NULL )
return ( NULL ) ;
else {
V_36 . type = V_16 ;
V_36 . V_10 = & V_38 ;
V_38 . V_17 = V_35 ;
V_37 = F_24 ( V_20 , & V_36 ) ;
if ( V_37 != NULL )
return ( V_37 -> V_10 -> V_5 ) ;
else {
F_22 ( V_43 , V_41 ) ;
return ( NULL ) ;
}
}
}
static int F_27 ( const T_1 * const * V_44 , const unsigned int * V_45 )
{
int V_46 ;
const T_1 * V_1 = * V_44 ;
const T_1 * V_2 = & V_4 [ * V_45 ] ;
V_46 = ( V_1 -> V_12 - V_2 -> V_12 ) ;
if ( V_46 )
return ( V_46 ) ;
if ( V_1 -> V_12 == 0 )
return 0 ;
return ( memcmp ( V_1 -> V_13 , V_2 -> V_13 , V_1 -> V_12 ) ) ;
}
int F_28 ( const T_1 * V_1 )
{
const unsigned int * V_47 ;
T_2 V_36 , * V_37 ;
if ( V_1 == NULL )
return ( V_34 ) ;
if ( V_1 -> V_17 != 0 )
return ( V_1 -> V_17 ) ;
if ( V_1 -> V_12 == 0 )
return V_34 ;
if ( V_20 != NULL ) {
V_36 . type = V_11 ;
V_36 . V_10 = ( T_1 * ) V_1 ;
V_37 = F_24 ( V_20 , & V_36 ) ;
if ( V_37 != NULL )
return ( V_37 -> V_10 -> V_17 ) ;
}
V_47 = F_29 ( & V_1 , V_48 , V_49 ) ;
if ( V_47 == NULL )
return ( V_34 ) ;
return ( V_4 [ * V_47 ] . V_17 ) ;
}
T_1 * F_30 ( const char * V_50 , int V_51 )
{
int V_17 = V_34 ;
T_1 * V_47 = NULL ;
unsigned char * V_52 ;
unsigned char * V_9 ;
const unsigned char * V_53 ;
int V_7 , V_46 ;
if ( ! V_51 ) {
if ( ( ( V_17 = F_31 ( V_50 ) ) != V_34 ) ||
( ( V_17 = F_32 ( V_50 ) ) != V_34 ) )
return F_23 ( V_17 ) ;
}
V_7 = F_33 ( NULL , 0 , V_50 , - 1 ) ;
if ( V_7 <= 0 ) {
return NULL ;
}
V_46 = F_34 ( 0 , V_7 , V_54 ) ;
if ( V_46 < 0 )
return NULL ;
if ( ( V_52 = F_20 ( V_46 ) ) == NULL )
return NULL ;
V_9 = V_52 ;
F_35 ( & V_9 , 0 , V_7 , V_54 , V_55 ) ;
F_33 ( V_9 , V_7 , V_50 , - 1 ) ;
V_53 = V_52 ;
V_47 = F_36 ( NULL , & V_53 , V_46 ) ;
F_12 ( V_52 ) ;
return V_47 ;
}
int F_37 ( char * V_52 , int V_56 , const T_1 * V_1 , int V_51 )
{
int V_7 , V_35 = 0 , V_57 , V_17 , V_58 , V_59 ;
T_3 * V_60 ;
unsigned long V_61 ;
const unsigned char * V_9 ;
char V_62 [ F_38 ( V_7 ) + F_38 ( V_61 ) + 2 ] ;
if ( V_52 && V_56 > 0 )
V_52 [ 0 ] = '\0' ;
if ( ( V_1 == NULL ) || ( V_1 -> V_13 == NULL ) )
return ( 0 ) ;
if ( ! V_51 && ( V_17 = F_28 ( V_1 ) ) != V_34 ) {
const char * V_50 ;
V_50 = F_26 ( V_17 ) ;
if ( V_50 == NULL )
V_50 = F_25 ( V_17 ) ;
if ( V_50 ) {
if ( V_52 )
F_39 ( V_52 , V_50 , V_56 ) ;
V_35 = strlen ( V_50 ) ;
return V_35 ;
}
}
V_57 = V_1 -> V_12 ;
V_9 = V_1 -> V_13 ;
V_58 = 1 ;
V_60 = NULL ;
while ( V_57 > 0 ) {
V_61 = 0 ;
V_59 = 0 ;
for (; ; ) {
unsigned char V_63 = * V_9 ++ ;
V_57 -- ;
if ( ( V_57 == 0 ) && ( V_63 & 0x80 ) )
goto V_30;
if ( V_59 ) {
if ( ! F_40 ( V_60 , V_63 & 0x7f ) )
goto V_30;
} else
V_61 |= V_63 & 0x7f ;
if ( ! ( V_63 & 0x80 ) )
break;
if ( ! V_59 && ( V_61 > ( V_64 >> 7L ) ) ) {
if ( V_60 == NULL && ( V_60 = F_41 () ) == NULL )
goto V_30;
if ( ! F_42 ( V_60 , V_61 ) )
goto V_30;
V_59 = 1 ;
}
if ( V_59 ) {
if ( ! F_43 ( V_60 , V_60 , 7 ) )
goto V_30;
} else
V_61 <<= 7L ;
}
if ( V_58 ) {
V_58 = 0 ;
if ( V_61 >= 80 ) {
V_7 = 2 ;
if ( V_59 ) {
if ( ! F_44 ( V_60 , 80 ) )
goto V_30;
} else
V_61 -= 80 ;
} else {
V_7 = ( int ) ( V_61 / 40 ) ;
V_61 -= ( long ) ( V_7 * 40 ) ;
}
if ( V_52 && ( V_56 > 1 ) ) {
* V_52 ++ = V_7 + '0' ;
* V_52 = '\0' ;
V_56 -- ;
}
V_35 ++ ;
}
if ( V_59 ) {
char * V_65 ;
V_65 = F_45 ( V_60 ) ;
if ( ! V_65 )
goto V_30;
V_7 = strlen ( V_65 ) ;
if ( V_52 ) {
if ( V_56 > 1 ) {
* V_52 ++ = '.' ;
* V_52 = '\0' ;
V_56 -- ;
}
F_39 ( V_52 , V_65 , V_56 ) ;
if ( V_7 > V_56 ) {
V_52 += V_56 ;
V_56 = 0 ;
} else {
V_52 += V_7 ;
V_56 -= V_7 ;
}
}
V_35 ++ ;
V_35 += V_7 ;
F_12 ( V_65 ) ;
} else {
F_46 ( V_62 , sizeof V_62 , L_1 , V_61 ) ;
V_7 = strlen ( V_62 ) ;
if ( V_52 && ( V_56 > 0 ) ) {
F_39 ( V_52 , V_62 , V_56 ) ;
if ( V_7 > V_56 ) {
V_52 += V_56 ;
V_56 = 0 ;
} else {
V_52 += V_7 ;
V_56 -= V_7 ;
}
}
V_35 += V_7 ;
V_61 = 0 ;
}
}
F_47 ( V_60 ) ;
return V_35 ;
V_30:
F_47 ( V_60 ) ;
return - 1 ;
}
int F_48 ( const char * V_50 )
{
T_1 * V_10 ;
int V_17 ;
V_10 = F_30 ( V_50 , 0 ) ;
V_17 = F_28 ( V_10 ) ;
F_11 ( V_10 ) ;
return V_17 ;
}
int F_32 ( const char * V_50 )
{
T_1 V_27 ;
const T_1 * V_66 = & V_27 ;
T_2 V_36 , * V_37 ;
const unsigned int * V_47 ;
V_27 . V_5 = V_50 ;
if ( V_20 != NULL ) {
V_36 . type = V_15 ;
V_36 . V_10 = & V_27 ;
V_37 = F_24 ( V_20 , & V_36 ) ;
if ( V_37 != NULL )
return ( V_37 -> V_10 -> V_17 ) ;
}
V_47 = F_49 ( & V_66 , V_67 , V_68 ) ;
if ( V_47 == NULL )
return ( V_34 ) ;
return ( V_4 [ * V_47 ] . V_17 ) ;
}
int F_31 ( const char * V_50 )
{
T_1 V_27 ;
const T_1 * V_66 = & V_27 ;
T_2 V_36 , * V_37 ;
const unsigned int * V_47 ;
V_27 . V_3 = V_50 ;
if ( V_20 != NULL ) {
V_36 . type = V_14 ;
V_36 . V_10 = & V_27 ;
V_37 = F_24 ( V_20 , & V_36 ) ;
if ( V_37 != NULL )
return ( V_37 -> V_10 -> V_17 ) ;
}
V_47 = F_50 ( & V_66 , V_69 , V_70 ) ;
if ( V_47 == NULL )
return ( V_34 ) ;
return ( V_4 [ * V_47 ] . V_17 ) ;
}
const void * F_51 ( const void * V_71 , const void * V_72 , int V_25 , int V_73 ,
int (* F_52) ( const void * , const void * ) )
{
return F_53 ( V_71 , V_72 , V_25 , V_73 , F_52 , 0 ) ;
}
const void * F_53 ( const void * V_71 , const void * V_74 , int V_25 ,
int V_73 ,
int (* F_52) ( const void * , const void * ) ,
int V_21 )
{
const char * V_72 = V_74 ;
int V_61 , V_75 , V_7 = 0 , V_63 = 0 ;
const char * V_9 = NULL ;
if ( V_25 == 0 )
return ( NULL ) ;
V_61 = 0 ;
V_75 = V_25 ;
while ( V_61 < V_75 ) {
V_7 = ( V_61 + V_75 ) / 2 ;
V_9 = & ( V_72 [ V_7 * V_73 ] ) ;
V_63 = (* F_52) ( V_71 , V_9 ) ;
if ( V_63 < 0 )
V_75 = V_7 ;
else if ( V_63 > 0 )
V_61 = V_7 + 1 ;
else
break;
}
#ifdef F_54
if ( V_63 != 0 ) {
for ( V_7 = 0 ; V_7 < V_25 ; ++ V_7 ) {
V_9 = & ( V_72 [ V_7 * V_73 ] ) ;
V_63 = (* F_52) ( V_71 , V_9 ) ;
if ( V_63 == 0 || ( V_63 < 0 && ( V_21 & V_76 ) ) )
return V_9 ;
}
}
#endif
if ( V_63 != 0 && ! ( V_21 & V_76 ) )
V_9 = NULL ;
else if ( V_63 == 0 && ( V_21 & V_77 ) ) {
while ( V_7 > 0 && (* F_52) ( V_71 , & ( V_72 [ ( V_7 - 1 ) * V_73 ] ) ) == 0 )
V_7 -- ;
V_9 = & ( V_72 [ V_7 * V_73 ] ) ;
}
return ( V_9 ) ;
}
int F_55 ( T_4 * V_78 )
{
char V_52 [ 512 ] ;
int V_7 , V_25 = 0 ;
char * V_27 , * V_50 , * V_61 = NULL ;
for (; ; ) {
V_50 = V_27 = NULL ;
V_7 = F_56 ( V_78 , V_52 , 512 ) ;
if ( V_7 <= 0 )
return ( V_25 ) ;
V_52 [ V_7 - 1 ] = '\0' ;
if ( ! isalnum ( ( unsigned char ) V_52 [ 0 ] ) )
return ( V_25 ) ;
V_27 = V_50 = V_52 ;
while ( isdigit ( ( unsigned char ) * V_50 ) || ( * V_50 == '.' ) )
V_50 ++ ;
if ( * V_50 != '\0' ) {
* ( V_50 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_50 ) )
V_50 ++ ;
if ( * V_50 == '\0' )
V_50 = NULL ;
else {
V_61 = V_50 ;
while ( ( * V_61 != '\0' ) && ! isspace ( ( unsigned char ) * V_61 ) )
V_61 ++ ;
if ( * V_61 != '\0' ) {
* ( V_61 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_61 ) )
V_61 ++ ;
if ( * V_61 == '\0' )
V_61 = NULL ;
} else
V_61 = NULL ;
}
} else
V_50 = NULL ;
if ( ( V_27 == NULL ) || ( * V_27 == '\0' ) )
return ( V_25 ) ;
if ( ! F_57 ( V_27 , V_50 , V_61 ) )
return ( V_25 ) ;
V_25 ++ ;
}
}
int F_57 ( const char * V_79 , const char * V_3 , const char * V_5 )
{
T_1 * V_80 = NULL ;
int V_81 = 0 ;
if ( F_31 ( V_3 ) != V_34 || F_32 ( V_5 ) != V_34 ) {
F_22 ( V_82 , V_83 ) ;
return 0 ;
}
V_80 = F_30 ( V_79 , 1 ) ;
if ( F_28 ( V_80 ) != V_34 ) {
F_22 ( V_82 , V_83 ) ;
goto V_30;
}
V_80 -> V_17 = F_17 ( 1 ) ;
V_80 -> V_3 = ( char * ) V_3 ;
V_80 -> V_5 = ( char * ) V_5 ;
V_81 = F_18 ( V_80 ) ;
V_80 -> V_3 = NULL ;
V_80 -> V_5 = NULL ;
V_30:
F_11 ( V_80 ) ;
return V_81 ;
}
V_19 F_58 ( const T_1 * V_10 )
{
if ( V_10 == NULL )
return 0 ;
return V_10 -> V_12 ;
}
const unsigned char * F_59 ( const T_1 * V_10 )
{
if ( V_10 == NULL )
return NULL ;
return V_10 -> V_13 ;
}
