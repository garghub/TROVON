static inline T_1 F_1 ( T_1 V_1 , unsigned int V_2 )
{
V_1 &= 0xFFFFFFFF ;
return ( ( V_1 << V_2 ) & 0xFFFFFFFF ) | ( V_1 >> ( 32 - V_2 ) ) ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 V_3 , T_1 V_4 )
{
return ( V_1 & V_3 ) | ( ( ~ V_1 ) & V_4 ) ;
}
static inline T_1 F_3 ( T_1 V_1 , T_1 V_3 , T_1 V_4 )
{
return ( V_1 & V_3 ) | ( V_1 & V_4 ) | ( V_3 & V_4 ) ;
}
static inline T_1 F_4 ( T_1 V_1 , T_1 V_3 , T_1 V_4 )
{
return V_1 ^ V_3 ^ V_4 ;
}
static inline void F_5 ( T_1 * V_5 , unsigned int V_6 )
{
while ( V_6 -- ) {
* V_5 = F_6 ( * V_5 ) ;
V_5 ++ ;
}
}
static inline void F_7 ( T_1 * V_5 , unsigned int V_6 )
{
while ( V_6 -- ) {
* V_5 = F_8 ( * V_5 ) ;
V_5 ++ ;
}
}
static void F_9 ( T_1 * V_7 , T_1 const * V_8 )
{
T_1 V_9 , V_10 , V_11 , V_12 ;
V_9 = V_7 [ 0 ] ;
V_10 = V_7 [ 1 ] ;
V_11 = V_7 [ 2 ] ;
V_12 = V_7 [ 3 ] ;
F_10 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 0 ] , 3 ) ;
F_10 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 1 ] , 7 ) ;
F_10 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 2 ] , 11 ) ;
F_10 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 3 ] , 19 ) ;
F_10 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 4 ] , 3 ) ;
F_10 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 5 ] , 7 ) ;
F_10 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 6 ] , 11 ) ;
F_10 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 7 ] , 19 ) ;
F_10 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 8 ] , 3 ) ;
F_10 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 9 ] , 7 ) ;
F_10 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 10 ] , 11 ) ;
F_10 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 11 ] , 19 ) ;
F_10 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 12 ] , 3 ) ;
F_10 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 13 ] , 7 ) ;
F_10 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 14 ] , 11 ) ;
F_10 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 15 ] , 19 ) ;
F_11 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 0 ] , 3 ) ;
F_11 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 4 ] , 5 ) ;
F_11 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 8 ] , 9 ) ;
F_11 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 12 ] , 13 ) ;
F_11 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 1 ] , 3 ) ;
F_11 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 5 ] , 5 ) ;
F_11 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 9 ] , 9 ) ;
F_11 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 13 ] , 13 ) ;
F_11 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 2 ] , 3 ) ;
F_11 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 6 ] , 5 ) ;
F_11 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 10 ] , 9 ) ;
F_11 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 14 ] , 13 ) ;
F_11 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 3 ] , 3 ) ;
F_11 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 7 ] , 5 ) ;
F_11 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 11 ] , 9 ) ;
F_11 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 15 ] , 13 ) ;
F_12 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 0 ] , 3 ) ;
F_12 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 8 ] , 9 ) ;
F_12 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 4 ] , 11 ) ;
F_12 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 12 ] , 15 ) ;
F_12 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 2 ] , 3 ) ;
F_12 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 10 ] , 9 ) ;
F_12 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 6 ] , 11 ) ;
F_12 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 14 ] , 15 ) ;
F_12 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 1 ] , 3 ) ;
F_12 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 9 ] , 9 ) ;
F_12 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 5 ] , 11 ) ;
F_12 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 13 ] , 15 ) ;
F_12 ( V_9 , V_10 , V_11 , V_12 , V_8 [ 3 ] , 3 ) ;
F_12 ( V_12 , V_9 , V_10 , V_11 , V_8 [ 11 ] , 9 ) ;
F_12 ( V_11 , V_12 , V_9 , V_10 , V_8 [ 7 ] , 11 ) ;
F_12 ( V_10 , V_11 , V_12 , V_9 , V_8 [ 15 ] , 15 ) ;
V_7 [ 0 ] += V_9 ;
V_7 [ 1 ] += V_10 ;
V_7 [ 2 ] += V_11 ;
V_7 [ 3 ] += V_12 ;
}
static inline void F_13 ( struct V_13 * V_14 )
{
F_5 ( V_14 -> V_15 , sizeof( V_14 -> V_15 ) / sizeof( T_1 ) ) ;
F_9 ( V_14 -> V_7 , V_14 -> V_15 ) ;
}
static void F_14 ( struct V_13 * V_16 )
{
V_16 -> V_7 [ 0 ] = 0x67452301 ;
V_16 -> V_7 [ 1 ] = 0xefcdab89 ;
V_16 -> V_7 [ 2 ] = 0x98badcfe ;
V_16 -> V_7 [ 3 ] = 0x10325476 ;
V_16 -> V_17 = 0 ;
}
static void F_15 ( struct V_13 * V_16 ,
const unsigned char * V_18 , unsigned int V_19 )
{
const T_1 V_20 = sizeof( V_16 -> V_15 ) - ( V_16 -> V_17 & 0x3f ) ;
V_16 -> V_17 += V_19 ;
if ( V_20 > V_19 ) {
memcpy ( ( char * ) V_16 -> V_15 + ( sizeof( V_16 -> V_15 ) - V_20 ) ,
V_18 , V_19 ) ;
return;
}
memcpy ( ( char * ) V_16 -> V_15 + ( sizeof( V_16 -> V_15 ) - V_20 ) ,
V_18 , V_20 ) ;
F_13 ( V_16 ) ;
V_18 += V_20 ;
V_19 -= V_20 ;
while ( V_19 >= sizeof( V_16 -> V_15 ) ) {
memcpy ( V_16 -> V_15 , V_18 , sizeof( V_16 -> V_15 ) ) ;
F_13 ( V_16 ) ;
V_18 += sizeof( V_16 -> V_15 ) ;
V_19 -= sizeof( V_16 -> V_15 ) ;
}
memcpy ( V_16 -> V_15 , V_18 , V_19 ) ;
}
static void F_16 ( struct V_13 * V_16 , char * V_21 , unsigned int V_19 )
{
const unsigned int V_22 = V_16 -> V_17 & 0x3f ;
char * V_23 = ( char * ) V_16 -> V_15 + V_22 ;
int V_24 = 56 - ( V_22 + 1 ) ;
* V_23 ++ = 0x80 ;
if ( V_24 < 0 ) {
memset ( V_23 , 0x00 , V_24 + sizeof ( V_25 ) ) ;
F_13 ( V_16 ) ;
V_23 = ( char * ) V_16 -> V_15 ;
V_24 = 56 ;
}
memset ( V_23 , 0 , V_24 ) ;
V_16 -> V_15 [ 14 ] = V_16 -> V_17 << 3 ;
V_16 -> V_15 [ 15 ] = V_16 -> V_17 >> 29 ;
F_5 ( V_16 -> V_15 , ( sizeof( V_16 -> V_15 ) -
sizeof( V_25 ) ) / sizeof( T_1 ) ) ;
F_9 ( V_16 -> V_7 , V_16 -> V_15 ) ;
F_7 ( V_16 -> V_7 , sizeof( V_16 -> V_7 ) / sizeof( T_1 ) ) ;
snprintf ( V_21 , V_19 , L_1 ,
V_16 -> V_7 [ 0 ] , V_16 -> V_7 [ 1 ] , V_16 -> V_7 [ 2 ] , V_16 -> V_7 [ 3 ] ) ;
}
static inline void F_17 ( unsigned char V_11 , struct V_13 * V_26 )
{
F_15 ( V_26 , & V_11 , 1 ) ;
}
static int F_18 ( const char * V_27 , unsigned long V_19 ,
struct V_13 * V_26 )
{
unsigned long V_28 ;
F_17 ( V_27 [ 0 ] , V_26 ) ;
for ( V_28 = 1 ; V_28 < V_19 ; V_28 ++ ) {
F_17 ( V_27 [ V_28 ] , V_26 ) ;
if ( V_27 [ V_28 ] == '"' && V_27 [ V_28 - 1 ] != '\\' )
break;
}
return V_28 ;
}
static int F_19 ( const char * V_27 , unsigned long V_19 )
{
unsigned long V_28 ;
for ( V_28 = 2 ; V_28 < V_19 ; V_28 ++ ) {
if ( V_27 [ V_28 - 1 ] == '*' && V_27 [ V_28 ] == '/' )
break;
}
return V_28 ;
}
static int F_20 ( const char * V_29 , struct V_13 * V_26 )
{
char * V_27 ;
unsigned long V_28 , V_19 ;
V_27 = F_21 ( V_29 , & V_19 ) ;
if ( ! V_27 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_19 ; V_28 ++ ) {
if ( V_27 [ V_28 ] == '\\' && ( V_28 + 1 < V_19 ) && V_27 [ V_28 + 1 ] == '\n' ) {
V_28 ++ ;
continue;
}
if ( isspace ( V_27 [ V_28 ] ) )
continue;
if ( V_27 [ V_28 ] == '"' ) {
V_28 += F_18 ( V_27 + V_28 , V_19 - V_28 , V_26 ) ;
continue;
}
if ( V_27 [ V_28 ] == '/' && V_27 [ V_28 + 1 ] == '*' ) {
V_28 += F_19 ( V_27 + V_28 , V_19 - V_28 ) ;
continue;
}
F_17 ( V_27 [ V_28 ] , V_26 ) ;
}
F_22 ( V_27 , V_19 ) ;
return 1 ;
}
static int F_23 ( const char * V_30 )
{
int V_19 = strlen ( V_30 ) ;
if ( V_30 [ V_19 - 2 ] == '.' && V_30 [ V_19 - 1 ] == 'a' )
return 1 ;
else
return 0 ;
}
static int F_24 ( const char * V_30 , struct V_13 * V_26 )
{
char * V_31 , * V_27 , * line , * V_32 ;
const char * V_33 ;
unsigned long V_34 , V_35 = 0 ;
int V_36 , V_37 = 0 , V_38 = 0 ;
V_31 = F_25 ( malloc ( strlen ( V_30 ) + sizeof( L_2 ) ) ) ;
V_33 = strrchr ( V_30 , '/' ) ;
if ( V_33 ) {
V_33 ++ ;
V_36 = V_33 - V_30 ;
sprintf ( V_31 , L_3 , V_36 , V_30 , V_33 ) ;
} else {
V_36 = 0 ;
sprintf ( V_31 , L_4 , V_30 ) ;
}
V_32 = F_25 ( malloc ( V_36 + 1 ) ) ;
strncpy ( V_32 , V_30 , V_36 ) ;
V_32 [ V_36 ] = '\0' ;
V_27 = F_21 ( V_31 , & V_34 ) ;
if ( ! V_27 ) {
F_26 ( L_5 , V_31 , V_30 ) ;
goto V_21;
}
while ( ( line = F_27 ( & V_35 , V_27 , V_34 ) ) != NULL ) {
char * V_23 = line ;
if ( strncmp ( line , L_6 , sizeof( L_6 ) - 1 ) == 0 ) {
V_23 = strrchr ( line , ' ' ) ;
if ( ! V_23 ) {
F_26 ( L_7 , line ) ;
goto V_39;
}
V_23 ++ ;
if ( ! F_20 ( V_23 , V_26 ) ) {
F_26 ( L_8 ,
V_23 , strerror ( V_40 ) ) ;
goto V_39;
}
continue;
}
if ( strncmp ( line , L_9 , sizeof( L_9 ) - 1 ) == 0 ) {
V_38 = 1 ;
continue;
}
if ( ! V_38 )
continue;
if ( * ( V_23 + strlen ( V_23 ) - 1 ) != '\\' )
break;
while ( * V_23 ) {
if ( isspace ( * V_23 ) ) {
* V_23 = '\0' ;
break;
}
V_23 ++ ;
}
if ( ( strstr ( line , V_32 ) + strlen ( V_32 ) - 1 ) == strrchr ( line , '/' ) ) {
if ( ! F_20 ( line , V_26 ) ) {
F_26 ( L_8 ,
line , strerror ( V_40 ) ) ;
goto V_39;
}
}
}
V_37 = 1 ;
V_39:
F_22 ( V_27 , V_34 ) ;
V_21:
free ( V_32 ) ;
free ( V_31 ) ;
return V_37 ;
}
void F_28 ( const char * V_41 , char V_42 [] , unsigned V_43 )
{
void * V_27 ;
unsigned long V_19 ;
struct V_13 V_26 ;
char * V_44 , * V_45 , * V_29 ;
const char * V_46 ;
char V_47 [ V_48 + 1 ] ;
char * V_49 = getenv ( L_10 ) ;
if ( ! V_49 )
V_49 = L_11 ;
if ( strrchr ( V_41 , '/' ) )
V_46 = strrchr ( V_41 , '/' ) + 1 ;
else
V_46 = V_41 ;
snprintf ( V_47 , sizeof( V_47 ) , L_12 , V_49 ,
( int ) strlen ( V_46 ) - 2 , V_46 ) ;
V_27 = F_21 ( V_47 , & V_19 ) ;
if ( ! V_27 )
return;
V_44 = strchr ( V_27 , '\n' ) ;
if ( ! V_44 ) {
F_26 ( L_13 , V_41 ) ;
goto V_50;
}
V_44 ++ ;
V_45 = strchr ( V_44 , '\n' ) ;
if ( ! V_45 ) {
F_26 ( L_14 , V_41 ) ;
goto V_50;
}
* V_45 = '\0' ;
F_14 ( & V_26 ) ;
while ( ( V_29 = F_29 ( & V_44 , L_15 ) ) != NULL ) {
if ( ! * V_29 )
continue;
if ( ! ( F_23 ( V_29 ) ) &&
! F_24 ( V_29 , & V_26 ) )
goto V_50;
}
F_16 ( & V_26 , V_42 , V_43 ) ;
V_50:
F_22 ( V_27 , V_19 ) ;
}
static void F_30 ( const char * V_51 , const char * V_42 ,
unsigned long V_22 )
{
int V_52 ;
V_52 = F_31 ( V_51 , V_53 ) ;
if ( V_52 < 0 ) {
F_26 ( L_16 ,
V_51 , strerror ( V_40 ) ) ;
return;
}
if ( F_32 ( V_52 , V_22 , V_54 ) == ( V_55 ) - 1 ) {
F_26 ( L_17 ,
V_51 , V_22 , strerror ( V_40 ) ) ;
goto V_21;
}
if ( F_33 ( V_52 , V_42 , strlen ( V_42 ) + 1 ) != strlen ( V_42 ) + 1 ) {
F_26 ( L_18 ,
V_51 , strerror ( V_40 ) ) ;
goto V_21;
}
V_21:
F_34 ( V_52 ) ;
}
static int F_35 ( char * V_56 )
{
unsigned int V_19 , V_57 ;
if ( strncmp ( V_56 , L_19 , strlen ( L_19 ) ) != 0 )
return 0 ;
V_57 = strlen ( V_56 ) + strlen ( V_56 + strlen ( V_56 ) + 1 ) + 2 ;
V_19 = strlen ( L_19 ) ;
if ( V_56 [ V_19 ] == ':' || V_56 [ V_19 ] == '$' )
V_19 ++ ;
while ( isspace ( V_56 [ V_19 ] ) )
V_19 ++ ;
memmove ( V_56 , V_56 + V_19 , V_57 - V_19 ) ;
V_57 -= V_19 ;
V_19 = 0 ;
while ( V_56 [ V_19 ] && ! isspace ( V_56 [ V_19 ] ) )
V_19 ++ ;
memmove ( V_56 + V_19 , V_56 + strlen ( V_56 ) ,
V_57 - strlen ( V_56 ) ) ;
return 1 ;
}
void F_36 ( const char * V_58 ,
char * V_56 ,
void * V_59 ,
unsigned long V_60 )
{
if ( F_35 ( V_56 ) )
F_30 ( V_58 , V_56 , V_60 ) ;
}
