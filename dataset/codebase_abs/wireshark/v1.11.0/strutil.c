const T_1 *
F_1 ( const T_1 * V_1 , const T_1 * V_2 , const T_1 * * V_3 )
{
const T_1 * V_4 ;
V_4 = ( T_1 * ) memchr ( V_1 , '\n' , V_2 - V_1 ) ;
if ( V_4 == NULL ) {
V_4 = V_2 ;
* V_3 = V_2 ;
} else {
if ( V_4 > V_1 ) {
if ( * ( V_4 - 1 ) == '\r' ) {
* V_3 = V_4 - 1 ;
} else {
* V_3 = V_4 ;
if ( V_4 < ( V_2 - 1 ) && * ( V_4 + 1 ) == '\r' ) {
V_4 ++ ;
}
}
} else {
* V_3 = V_4 ;
}
V_4 ++ ;
}
return V_4 ;
}
int
F_2 ( const T_1 * V_5 , const T_1 * V_4 ,
const T_1 * * V_6 )
{
const T_1 * V_7 ;
int V_8 ;
V_7 = V_5 ;
while ( V_5 < V_4 && * V_5 != ' ' && * V_5 != '\r' && * V_5 != '\n' )
V_5 ++ ;
V_8 = ( int ) ( V_5 - V_7 ) ;
while ( V_5 < V_4 && * V_5 == ' ' )
V_5 ++ ;
* V_6 = V_5 ;
return V_8 ;
}
T_2 *
F_3 ( const T_1 * string , T_3 V_9 )
{
static T_2 * V_10 [ 3 ] ;
static int V_11 [ 3 ] ;
static int V_12 ;
int V_13 ;
const T_1 * V_14 = string + V_9 ;
T_1 V_15 ;
int V_16 ;
V_12 = ( V_12 + 1 ) % 3 ;
if ( V_10 [ V_12 ] == NULL ) {
V_10 [ V_12 ] = ( T_2 * ) F_4 ( V_17 ) ;
V_11 [ V_12 ] = V_17 ;
}
V_13 = 0 ;
while ( string < V_14 ) {
if ( V_13 + 3 + 1 >= V_11 [ V_12 ] ) {
V_11 [ V_12 ] = V_11 [ V_12 ] * 2 ;
V_10 [ V_12 ] = ( T_2 * ) F_5 ( V_10 [ V_12 ] , V_11 [ V_12 ] ) ;
}
V_15 = * string ++ ;
if ( isprint ( V_15 ) ) {
V_10 [ V_12 ] [ V_13 ] = V_15 ;
V_13 ++ ;
} else {
V_10 [ V_12 ] [ V_13 ] = '\\' ;
V_13 ++ ;
switch ( V_15 ) {
case '\a' :
V_10 [ V_12 ] [ V_13 ] = 'a' ;
V_13 ++ ;
break;
case '\b' :
V_10 [ V_12 ] [ V_13 ] = 'b' ;
V_13 ++ ;
break;
case '\f' :
V_10 [ V_12 ] [ V_13 ] = 'f' ;
V_13 ++ ;
break;
case '\n' :
V_10 [ V_12 ] [ V_13 ] = 'n' ;
V_13 ++ ;
break;
case '\r' :
V_10 [ V_12 ] [ V_13 ] = 'r' ;
V_13 ++ ;
break;
case '\t' :
V_10 [ V_12 ] [ V_13 ] = 't' ;
V_13 ++ ;
break;
case '\v' :
V_10 [ V_12 ] [ V_13 ] = 'v' ;
V_13 ++ ;
break;
default:
V_16 = ( V_15 >> 6 ) & 03 ;
V_10 [ V_12 ] [ V_13 ] = V_16 + '0' ;
V_13 ++ ;
V_16 = ( V_15 >> 3 ) & 07 ;
V_10 [ V_12 ] [ V_13 ] = V_16 + '0' ;
V_13 ++ ;
V_16 = ( V_15 >> 0 ) & 07 ;
V_10 [ V_12 ] [ V_13 ] = V_16 + '0' ;
V_13 ++ ;
break;
}
}
}
V_10 [ V_12 ] [ V_13 ] = '\0' ;
return V_10 [ V_12 ] ;
}
T_2 *
F_6 ( const T_1 * string , T_3 V_9 )
{
static T_2 * V_10 [ 3 ] ;
static int V_11 [ 3 ] ;
static int V_12 ;
int V_13 ;
const T_1 * V_14 = string + V_9 ;
T_1 V_15 ;
int V_16 ;
V_12 = ( V_12 + 1 ) % 3 ;
if ( V_10 [ V_12 ] == NULL ) {
V_10 [ V_12 ] = ( T_2 * ) F_4 ( V_17 ) ;
V_11 [ V_12 ] = V_17 ;
}
V_13 = 0 ;
while ( string < V_14 ) {
if ( V_13 + 3 + 1 >= V_11 [ V_12 ] ) {
V_11 [ V_12 ] = V_11 [ V_12 ] * 2 ;
V_10 [ V_12 ] = ( T_2 * ) F_5 ( V_10 [ V_12 ] , V_11 [ V_12 ] ) ;
}
V_15 = * string ++ ;
if ( isprint ( V_15 ) ) {
V_10 [ V_12 ] [ V_13 ] = V_15 ;
V_13 ++ ;
} else if ( isspace ( V_15 ) ) {
V_10 [ V_12 ] [ V_13 ] = ' ' ;
V_13 ++ ;
} else {
V_10 [ V_12 ] [ V_13 ] = '\\' ;
V_13 ++ ;
switch ( V_15 ) {
case '\a' :
V_10 [ V_12 ] [ V_13 ] = 'a' ;
V_13 ++ ;
break;
case '\b' :
V_10 [ V_12 ] [ V_13 ] = 'b' ;
V_13 ++ ;
break;
case '\f' :
V_10 [ V_12 ] [ V_13 ] = 'f' ;
V_13 ++ ;
break;
case '\n' :
V_10 [ V_12 ] [ V_13 ] = 'n' ;
V_13 ++ ;
break;
case '\r' :
V_10 [ V_12 ] [ V_13 ] = 'r' ;
V_13 ++ ;
break;
case '\t' :
V_10 [ V_12 ] [ V_13 ] = 't' ;
V_13 ++ ;
break;
case '\v' :
V_10 [ V_12 ] [ V_13 ] = 'v' ;
V_13 ++ ;
break;
default:
V_16 = ( V_15 >> 6 ) & 03 ;
V_10 [ V_12 ] [ V_13 ] = V_16 + '0' ;
V_13 ++ ;
V_16 = ( V_15 >> 3 ) & 07 ;
V_10 [ V_12 ] [ V_13 ] = V_16 + '0' ;
V_13 ++ ;
V_16 = ( V_15 >> 0 ) & 07 ;
V_10 [ V_12 ] [ V_13 ] = V_16 + '0' ;
V_13 ++ ;
break;
}
}
}
V_10 [ V_12 ] [ V_13 ] = '\0' ;
return V_10 [ V_12 ] ;
}
T_2 *
F_7 ( const T_1 * string , const T_3 V_9 , const T_1 V_18 )
{
static T_2 * V_10 [ 3 ] ;
static int V_11 [ 3 ] ;
static int V_12 ;
int V_13 ;
const T_1 * V_14 = string + V_9 ;
T_1 V_15 ;
V_12 = ( V_12 + 1 ) % 3 ;
if ( V_10 [ V_12 ] == NULL ) {
V_10 [ V_12 ] = ( T_2 * ) F_4 ( V_17 ) ;
V_11 [ V_12 ] = V_17 ;
}
V_13 = 0 ;
while ( string < V_14 )
{
if ( V_13 + 1 >= V_11 [ V_12 ] )
{
V_11 [ V_12 ] = V_11 [ V_12 ] * 2 ;
V_10 [ V_12 ] = ( T_2 * ) F_5 ( V_10 [ V_12 ] , V_11 [ V_12 ] ) ;
}
V_15 = * string ++ ;
if ( isprint ( V_15 ) )
{
V_10 [ V_12 ] [ V_13 ] = V_15 ;
V_13 ++ ;
}
else if ( isspace ( V_15 ) )
{
V_10 [ V_12 ] [ V_13 ] = ' ' ;
V_13 ++ ;
}
else
{
V_10 [ V_12 ] [ V_13 ] = V_18 ;
V_13 ++ ;
}
}
V_10 [ V_12 ] [ V_13 ] = '\0' ;
return V_10 [ V_12 ] ;
}
static T_4
F_8 ( T_5 V_15 )
{
return ( V_15 == '-' || V_15 == ':' || V_15 == '.' ) ;
}
T_4
F_9 ( const char * V_19 , T_6 * V_20 , T_4 V_21 ) {
T_5 V_22 ;
const T_1 * V_23 , * V_24 , * V_25 , * V_26 , * V_27 ;
char V_28 [ 3 ] ;
char V_29 [ 3 ] ;
char V_30 [ 3 ] ;
char V_31 [ 2 ] ;
if ( ! V_19 || ! V_20 ) {
return FALSE ;
}
F_10 ( V_20 , 0 ) ;
V_23 = ( const T_1 * ) V_19 ;
while ( * V_23 ) {
V_24 = V_23 + 1 ;
V_25 = V_23 + 2 ;
V_26 = V_23 + 3 ;
if ( * V_24 && * V_25 && * V_26
&& isxdigit ( * V_23 ) && isxdigit ( * V_24 ) &&
isxdigit ( * V_25 ) && isxdigit ( * V_26 ) ) {
V_28 [ 0 ] = * V_23 ;
V_28 [ 1 ] = * V_24 ;
V_28 [ 2 ] = '\0' ;
V_29 [ 0 ] = * V_25 ;
V_29 [ 1 ] = * V_26 ;
V_29 [ 2 ] = '\0' ;
V_22 = ( T_5 ) strtoul ( V_28 , NULL , 16 ) ;
F_11 ( V_20 , & V_22 , 1 ) ;
V_22 = ( T_5 ) strtoul ( V_29 , NULL , 16 ) ;
F_11 ( V_20 , & V_22 , 1 ) ;
V_27 = V_26 + 1 ;
if ( * V_27 ) {
if ( F_8 ( * V_27 ) ) {
V_23 = V_27 + 1 ;
continue;
}
else if ( V_21 ) {
return FALSE ;
}
}
V_23 = V_27 ;
continue;
}
else if ( * V_24 && isxdigit ( * V_23 ) && isxdigit ( * V_24 ) ) {
V_30 [ 0 ] = * V_23 ;
V_30 [ 1 ] = * V_24 ;
V_30 [ 2 ] = '\0' ;
V_22 = ( T_5 ) strtoul ( V_30 , NULL , 16 ) ;
F_11 ( V_20 , & V_22 , 1 ) ;
V_27 = V_24 + 1 ;
if ( * V_27 ) {
if ( F_8 ( * V_27 ) ) {
V_23 = V_27 + 1 ;
continue;
}
else if ( V_21 ) {
return FALSE ;
}
}
V_23 = V_27 ;
continue;
}
else if ( * V_24 && isxdigit ( * V_23 ) && F_8 ( * V_24 ) ) {
V_31 [ 0 ] = * V_23 ;
V_31 [ 1 ] = '\0' ;
V_22 = ( T_5 ) strtoul ( V_31 , NULL , 16 ) ;
F_11 ( V_20 , & V_22 , 1 ) ;
V_23 = V_24 + 1 ;
continue;
}
else if ( ! * V_24 && isxdigit ( * V_23 ) ) {
V_31 [ 0 ] = * V_23 ;
V_31 [ 1 ] = '\0' ;
V_22 = ( T_5 ) strtoul ( V_31 , NULL , 16 ) ;
F_11 ( V_20 , & V_22 , 1 ) ;
V_23 = V_24 ;
continue;
}
else {
return FALSE ;
}
}
return TRUE ;
}
T_4
F_12 ( const char * V_32 , T_6 * V_20 ) {
T_5 V_22 ;
const T_1 * V_23 ;
T_1 V_33 [ V_34 ] ;
F_10 ( V_20 , 0 ) ;
if ( ! V_32 ) {
return FALSE ;
}
V_23 = ( const T_1 * ) V_32 ;
while ( * V_23 ) {
if ( ! isascii ( * V_23 ) || ! isprint ( * V_23 ) )
return FALSE ;
if ( * V_23 == '%' ) {
V_23 ++ ;
if ( * V_23 == '\0' ) return FALSE ;
V_33 [ 0 ] = * V_23 ;
V_23 ++ ;
if ( * V_23 == '\0' ) return FALSE ;
V_33 [ 1 ] = * V_23 ;
V_33 [ 2 ] = '\0' ;
if ( ! isxdigit ( V_33 [ 0 ] ) || ! isxdigit ( V_33 [ 1 ] ) )
return FALSE ;
V_22 = ( T_5 ) strtoul ( ( char * ) V_33 , NULL , 16 ) ;
F_11 ( V_20 , & V_22 , 1 ) ;
} else {
F_11 ( V_20 , ( const T_5 * ) V_23 , 1 ) ;
}
V_23 ++ ;
}
return TRUE ;
}
const T_2 *
F_13 ( const T_6 * V_20 , const T_2 * V_35 )
{
static T_2 * V_10 [ 3 ] ;
static T_7 V_11 [ 3 ] ;
static T_7 V_12 ;
static const T_1 * V_36 = L_1 ;
const T_1 * V_37 = V_36 ;
T_5 V_15 ;
T_7 V_13 , V_16 ;
T_4 V_38 = FALSE ;
if ( ! V_20 )
return L_2 ;
V_12 = ( V_12 + 1 ) % 3 ;
if ( V_35 )
V_37 = V_35 ;
if ( V_10 [ V_12 ] == NULL ) {
V_10 [ V_12 ] = ( T_2 * ) F_4 ( V_17 ) ;
V_11 [ V_12 ] = V_17 ;
}
for ( V_13 = 0 ; V_13 < V_20 -> V_9 ; V_13 ++ ) {
if ( V_13 + 2 + 1 >= V_11 [ V_12 ] ) {
V_11 [ V_12 ] = V_11 [ V_12 ] * 2 ;
V_10 [ V_12 ] = ( T_2 * ) F_5 ( V_10 [ V_12 ] , V_11 [ V_12 ] ) ;
}
V_15 = V_20 -> V_1 [ V_13 ] ;
if ( ! isascii ( V_15 ) || ! isprint ( V_15 ) || V_15 == '%' ) {
V_38 = TRUE ;
}
for ( V_16 = 0 ; V_37 [ V_16 ] ; V_16 ++ ) {
if ( V_15 == V_37 [ V_16 ] )
V_38 = TRUE ;
}
if ( ! V_38 ) {
V_10 [ V_12 ] [ V_13 ] = V_15 ;
} else {
V_10 [ V_12 ] [ V_13 ] = '%' ;
V_13 ++ ;
V_10 [ V_12 ] [ V_13 ] = V_39 [ V_15 >> 4 ] ;
V_13 ++ ;
V_10 [ V_12 ] [ V_13 ] = V_39 [ V_15 & 0xF ] ;
}
}
V_10 [ V_12 ] [ V_13 ] = '\0' ;
return V_10 [ V_12 ] ;
}
T_6 *
F_14 ( T_6 * V_40 ) {
T_6 * V_41 ;
if ( ! V_40 )
return NULL ;
V_41 = F_15 () ;
F_11 ( V_41 , V_40 -> V_1 , V_40 -> V_9 ) ;
return V_41 ;
}
T_4
F_16 ( const char * V_42 , T_6 * V_20 ) {
return F_17 ( V_42 , V_20 , TRUE ) ;
}
T_4
F_17 ( const char * V_42 , T_6 * V_20 , T_4 V_43 ) {
T_8 V_44 , V_45 , V_46 , V_16 ;
const char * V_23 , * V_47 ;
T_5 V_48 [ V_49 ] ;
F_10 ( V_20 , 0 ) ;
V_23 = V_42 ;
V_47 = NULL ;
while ( * V_23 ) {
if ( ! isdigit ( ( T_1 ) * V_23 ) && ( * V_23 != '.' ) ) return FALSE ;
if ( * V_23 == '.' ) {
if ( V_23 == V_42 && V_43 ) return FALSE ;
if ( ! * ( V_23 + 1 ) ) return FALSE ;
if ( ( V_23 - 1 ) == V_47 ) return FALSE ;
V_47 = V_23 ;
}
V_23 ++ ;
}
if ( ! V_47 ) return FALSE ;
V_23 = V_42 ;
V_46 = V_43 ? 0 : 2 ;
if ( ! V_43 ) V_23 ++ ;
V_44 = 0 ;
while ( * V_23 ) {
V_45 = 0 ;
while ( isdigit ( ( T_1 ) * V_23 ) ) {
V_45 *= 10 ;
V_45 += * V_23 - '0' ;
V_23 ++ ;
}
if ( V_46 == 0 ) {
V_44 = V_45 ;
if ( V_44 > 2 ) return FALSE ;
} else if ( V_46 == 1 ) {
if ( ( V_44 < 2 ) && ( V_45 > 39 ) ) return FALSE ;
V_45 += 40 * V_44 ;
}
if ( V_46 ) {
V_16 = V_49 ;
do {
V_16 -- ;
V_48 [ V_16 ] = 0x80 | ( V_45 % 0x80 ) ;
V_45 >>= 7 ;
} while ( V_45 && V_16 );
V_48 [ V_49 - 1 ] &= 0x7F ;
F_11 ( V_20 , V_48 + V_16 , V_49 - V_16 ) ;
}
V_46 ++ ;
if ( * V_23 ) V_23 ++ ;
}
return TRUE ;
}
T_4
F_18 ( T_6 * V_50 , T_6 * V_51 ) {
if ( ! V_50 || ! V_51 )
return FALSE ;
if ( V_50 -> V_9 != V_51 -> V_9 )
return FALSE ;
if ( memcmp ( V_50 -> V_1 , V_51 -> V_1 , V_50 -> V_9 ) != 0 )
return FALSE ;
return TRUE ;
}
T_2 *
F_19 ( const T_2 * V_52 )
{
T_9 * V_53 = F_20 ( 128 ) ;
const T_2 * V_23 ;
T_2 V_15 ;
V_23 = V_52 ;
while ( ( V_15 = * V_23 ++ ) ) {
switch ( V_15 ) {
case '<' :
F_21 ( V_53 , L_3 ) ;
break;
case '>' :
F_21 ( V_53 , L_4 ) ;
break;
case '&' :
F_21 ( V_53 , L_5 ) ;
break;
case '\'' :
F_21 ( V_53 , L_6 ) ;
break;
case '"' :
F_21 ( V_53 , L_7 ) ;
break;
default:
F_22 ( V_53 , V_15 ) ;
break;
}
}
return F_23 ( V_53 , FALSE ) ;
}
const T_5 *
F_24 ( const T_5 * V_54 , T_7 V_55 ,
const T_5 * V_56 , T_7 V_57 )
{
const T_5 * V_58 ;
const T_5 * const V_59 = V_54 + V_55 - V_57 ;
if ( V_57 == 0 ) {
return NULL ;
}
if ( V_57 > V_55 ) {
return NULL ;
}
for ( V_58 = V_54 ; V_58 <= V_59 ; ++ V_58 ) {
if ( V_58 [ 0 ] == V_56 [ 0 ] &&
! memcmp ( & V_58 [ 1 ] , V_56 + 1 ,
V_57 - 1 ) ) {
return V_58 ;
}
}
return NULL ;
}
T_5 *
F_25 ( const char * string , T_3 * V_60 )
{
T_3 V_61 ;
const char * V_23 ;
T_1 V_15 ;
T_5 * V_20 , * V_24 , V_62 ;
V_61 = 0 ;
V_23 = & string [ 0 ] ;
for (; ; ) {
V_15 = * V_23 ++ ;
if ( V_15 == '\0' )
break;
if ( isspace ( V_15 ) )
continue;
if ( V_15 == ':' || V_15 == '.' || V_15 == '-' )
continue;
if ( ! isxdigit ( V_15 ) ) {
return NULL ;
}
V_15 = * V_23 ++ ;
if ( ! isxdigit ( V_15 ) )
return NULL ;
V_61 ++ ;
}
if ( V_61 == 0 ) {
return NULL ;
}
V_20 = ( T_5 * ) F_4 ( V_61 ) ;
V_23 = & string [ 0 ] ;
V_24 = & V_20 [ 0 ] ;
for (; ; ) {
V_15 = * V_23 ++ ;
if ( V_15 == '\0' )
break;
if ( isspace ( V_15 ) )
continue;
if ( V_15 == ':' || V_15 == '.' || V_15 == '-' )
continue;
if ( isdigit ( V_15 ) )
V_62 = V_15 - '0' ;
else if ( V_15 >= 'a' )
V_62 = ( V_15 - 'a' ) + 10 ;
else
V_62 = ( V_15 - 'A' ) + 10 ;
V_62 <<= 4 ;
V_15 = * V_23 ++ ;
if ( isdigit ( V_15 ) )
V_62 |= V_15 - '0' ;
else if ( V_15 >= 'a' )
V_62 |= ( V_15 - 'a' ) + 10 ;
else if ( V_15 >= 'A' )
V_62 |= ( V_15 - 'A' ) + 10 ;
* V_24 ++ = V_62 ;
}
* V_60 = V_61 ;
return V_20 ;
}
char *
F_26 ( const char * string , T_4 V_63 )
{
if ( V_63 ) {
return F_27 ( string , - 1 ) ;
} else {
return F_28 ( string ) ;
}
}
char *
F_29 ( const char * V_54 , const char * V_56 )
{
T_10 V_64 = strlen ( V_54 ) ;
T_10 V_65 = strlen ( V_56 ) ;
while ( V_64 -- >= V_65 ) {
if ( ! F_30 ( V_54 , V_56 , V_65 ) )
return ( char * ) V_54 ;
V_54 ++ ;
}
return NULL ;
}
const char *
F_31 ( const char * string )
{
if ( string )
return string ;
return L_8 ;
}
int
F_32 ( const char * string )
{
const char * V_23 ;
T_2 V_15 ;
int V_66 ;
V_66 = 0 ;
for ( V_23 = string ; ( V_15 = * V_23 ) != '\0' ; V_23 ++ ) {
if ( V_15 == '\\' || V_15 == '"' ) {
V_66 += 2 ;
}
else if ( ! isprint ( ( unsigned char ) V_15 ) ) {
V_66 += 4 ;
}
else {
V_66 ++ ;
}
}
return V_66 + 2 ;
}
char *
F_33 ( char * V_48 , const char * string )
{
const T_2 * V_23 ;
T_2 V_15 ;
char * V_67 ;
char V_68 [ 3 ] ;
V_67 = V_48 ;
* V_67 ++ = '"' ;
for ( V_23 = string ; ( V_15 = * V_23 ) != '\0' ; V_23 ++ ) {
if ( V_15 == '\\' || V_15 == '"' ) {
* V_67 ++ = '\\' ;
* V_67 ++ = V_15 ;
}
else if ( ! isprint ( ( unsigned char ) V_15 ) ) {
F_34 ( V_68 , sizeof( V_68 ) , L_9 , ( unsigned char ) V_15 ) ;
* V_67 ++ = '\\' ;
* V_67 ++ = 'x' ;
* V_67 ++ = V_68 [ 0 ] ;
* V_67 ++ = V_68 [ 1 ] ;
}
else {
* V_67 ++ = V_15 ;
}
}
* V_67 ++ = '"' ;
* V_67 = '\0' ;
return V_48 ;
}
static T_11
F_35 ( unsigned char V_69 )
{
if ( V_69 < V_70 ) {
return V_71 [ V_69 ] ;
}
else {
return '?' ;
}
}
void
F_36 ( unsigned char * V_72 , const unsigned char * V_73 , int V_9 )
{
int V_16 , V_74 ;
T_11 V_48 ;
for ( V_16 = 0 , V_74 = 0 ; V_74 < V_9 ; V_74 ++ ) {
V_48 = F_35 ( V_73 [ V_74 ] ) ;
V_16 += F_37 ( V_48 , & ( V_72 [ V_16 ] ) ) ;
}
V_72 [ V_16 ] = 0 ;
return;
}
T_2 *
F_38 ( const T_2 * V_75 , const T_2 V_18 )
{
const T_2 * V_23 ;
T_2 * V_24 , * V_76 ;
if( ! V_75 )
return NULL ;
V_23 = V_75 ;
V_24 = V_76 = ( T_2 * ) F_4 ( strlen ( V_75 ) * 2 + 1 ) ;
while( * V_23 != 0 ) {
if( * V_23 == V_18 )
* V_24 ++ = V_18 ;
* V_24 ++ = * V_23 ++ ;
}
* V_24 = '\0' ;
return V_76 ;
}
T_2 *
F_39 ( const T_2 * V_75 , const char V_18 )
{
const T_2 * V_23 ;
T_2 * V_24 , * V_76 ;
if( ! V_75 )
return NULL ;
V_23 = V_75 ;
V_24 = V_76 = ( T_2 * ) F_4 ( strlen ( V_75 ) + 1 ) ;
while( * V_23 != 0 ) {
* V_24 ++ = * V_23 ;
if ( ( * V_23 == V_18 ) && ( * ( V_23 + 1 ) == V_18 ) )
V_23 += 2 ;
else
V_23 ++ ;
}
* V_24 = '\0' ;
return V_76 ;
}
T_2 * F_40 ( const T_2 * V_75 , const T_2 * V_77 , const T_2 * V_78 ) {
T_2 * * V_79 ;
T_2 * V_76 ;
if ( ! V_75 || ! V_77 ) {
return NULL ;
}
V_79 = F_41 ( V_75 , V_77 , 0 ) ;
V_76 = F_42 ( V_78 , V_79 ) ;
F_43 ( V_79 ) ;
return V_76 ;
}
