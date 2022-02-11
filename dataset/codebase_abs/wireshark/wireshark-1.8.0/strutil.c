const T_1 *
F_1 ( const T_1 * V_1 , const T_1 * V_2 , const T_1 * * V_3 )
{
const T_1 * V_4 ;
V_4 = memchr ( V_1 , '\n' , V_2 - V_1 ) ;
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
V_10 [ V_12 ] = F_4 ( V_17 ) ;
V_11 [ V_12 ] = V_17 ;
}
V_13 = 0 ;
while ( string < V_14 ) {
if ( V_13 + 3 + 1 >= V_11 [ V_12 ] ) {
V_11 [ V_12 ] = V_11 [ V_12 ] * 2 ;
V_10 [ V_12 ] = F_5 ( V_10 [ V_12 ] , V_11 [ V_12 ] ) ;
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
V_10 [ V_12 ] = F_4 ( V_17 ) ;
V_11 [ V_12 ] = V_17 ;
}
V_13 = 0 ;
while ( string < V_14 ) {
if ( V_13 + 3 + 1 >= V_11 [ V_12 ] ) {
V_11 [ V_12 ] = V_11 [ V_12 ] * 2 ;
V_10 [ V_12 ] = F_5 ( V_10 [ V_12 ] , V_11 [ V_12 ] ) ;
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
static T_4
F_7 ( T_5 V_15 )
{
return ( V_15 == '-' || V_15 == ':' || V_15 == '.' ) ;
}
T_4
F_8 ( const char * V_18 , T_6 * V_19 , T_4 V_20 ) {
T_5 V_21 ;
const T_1 * V_22 , * V_23 , * V_24 , * V_25 , * V_26 ;
char V_27 [ 3 ] ;
char V_28 [ 3 ] ;
char V_29 [ 3 ] ;
char V_30 [ 2 ] ;
if ( ! V_18 || ! V_19 ) {
return FALSE ;
}
F_9 ( V_19 , 0 ) ;
V_22 = ( const T_1 * ) V_18 ;
while ( * V_22 ) {
V_23 = V_22 + 1 ;
V_24 = V_22 + 2 ;
V_25 = V_22 + 3 ;
if ( * V_23 && * V_24 && * V_25
&& isxdigit ( * V_22 ) && isxdigit ( * V_23 ) &&
isxdigit ( * V_24 ) && isxdigit ( * V_25 ) ) {
V_27 [ 0 ] = * V_22 ;
V_27 [ 1 ] = * V_23 ;
V_27 [ 2 ] = '\0' ;
V_28 [ 0 ] = * V_24 ;
V_28 [ 1 ] = * V_25 ;
V_28 [ 2 ] = '\0' ;
V_21 = ( T_5 ) strtoul ( V_27 , NULL , 16 ) ;
F_10 ( V_19 , & V_21 , 1 ) ;
V_21 = ( T_5 ) strtoul ( V_28 , NULL , 16 ) ;
F_10 ( V_19 , & V_21 , 1 ) ;
V_26 = V_25 + 1 ;
if ( * V_26 ) {
if ( F_7 ( * V_26 ) ) {
V_22 = V_26 + 1 ;
continue;
}
else if ( V_20 ) {
return FALSE ;
}
}
V_22 = V_26 ;
continue;
}
else if ( * V_23 && isxdigit ( * V_22 ) && isxdigit ( * V_23 ) ) {
V_29 [ 0 ] = * V_22 ;
V_29 [ 1 ] = * V_23 ;
V_29 [ 2 ] = '\0' ;
V_21 = ( T_5 ) strtoul ( V_29 , NULL , 16 ) ;
F_10 ( V_19 , & V_21 , 1 ) ;
V_26 = V_23 + 1 ;
if ( * V_26 ) {
if ( F_7 ( * V_26 ) ) {
V_22 = V_26 + 1 ;
continue;
}
else if ( V_20 ) {
return FALSE ;
}
}
V_22 = V_26 ;
continue;
}
else if ( * V_23 && isxdigit ( * V_22 ) && F_7 ( * V_23 ) ) {
V_30 [ 0 ] = * V_22 ;
V_30 [ 1 ] = '\0' ;
V_21 = ( T_5 ) strtoul ( V_30 , NULL , 16 ) ;
F_10 ( V_19 , & V_21 , 1 ) ;
V_22 = V_23 + 1 ;
continue;
}
else if ( ! * V_23 && isxdigit ( * V_22 ) ) {
V_30 [ 0 ] = * V_22 ;
V_30 [ 1 ] = '\0' ;
V_21 = ( T_5 ) strtoul ( V_30 , NULL , 16 ) ;
F_10 ( V_19 , & V_21 , 1 ) ;
V_22 = V_23 ;
continue;
}
else {
return FALSE ;
}
}
return TRUE ;
}
T_4
F_11 ( const char * V_31 , T_6 * V_19 ) {
T_5 V_21 ;
const T_1 * V_22 ;
T_1 V_32 [ V_33 ] ;
F_9 ( V_19 , 0 ) ;
if ( ! V_31 ) {
return FALSE ;
}
V_22 = ( const T_1 * ) V_31 ;
while ( * V_22 ) {
if ( ! isascii ( * V_22 ) || ! isprint ( * V_22 ) )
return FALSE ;
if ( * V_22 == '%' ) {
V_22 ++ ;
if ( * V_22 == '\0' ) return FALSE ;
V_32 [ 0 ] = * V_22 ;
V_22 ++ ;
if ( * V_22 == '\0' ) return FALSE ;
V_32 [ 1 ] = * V_22 ;
V_32 [ 2 ] = '\0' ;
if ( ! isxdigit ( V_32 [ 0 ] ) || ! isxdigit ( V_32 [ 1 ] ) )
return FALSE ;
V_21 = ( T_5 ) strtoul ( ( char * ) V_32 , NULL , 16 ) ;
F_10 ( V_19 , & V_21 , 1 ) ;
} else {
F_10 ( V_19 , ( const T_5 * ) V_22 , 1 ) ;
}
V_22 ++ ;
}
return TRUE ;
}
T_2 *
F_12 ( const T_6 * V_19 , const T_2 * V_34 )
{
static T_2 * V_10 [ 3 ] ;
static T_7 V_11 [ 3 ] ;
static T_7 V_12 ;
const T_1 * V_35 = L_1 ;
const T_1 * V_36 = V_35 ;
T_5 V_15 ;
T_7 V_13 , V_16 ;
T_4 V_37 = FALSE ;
if ( ! V_19 )
return L_2 ;
V_12 = ( V_12 + 1 ) % 3 ;
if ( V_34 )
V_36 = V_34 ;
if ( V_10 [ V_12 ] == NULL ) {
V_10 [ V_12 ] = F_4 ( V_17 ) ;
V_11 [ V_12 ] = V_17 ;
}
for ( V_13 = 0 ; V_13 < V_19 -> V_9 ; V_13 ++ ) {
if ( V_13 + 2 + 1 >= V_11 [ V_12 ] ) {
V_11 [ V_12 ] = V_11 [ V_12 ] * 2 ;
V_10 [ V_12 ] = F_5 ( V_10 [ V_12 ] , V_11 [ V_12 ] ) ;
}
V_15 = V_19 -> V_1 [ V_13 ] ;
if ( ! isascii ( V_15 ) || ! isprint ( V_15 ) || V_15 == '%' ) {
V_37 = TRUE ;
}
for ( V_16 = 0 ; V_36 [ V_16 ] ; V_16 ++ ) {
if ( V_15 == V_36 [ V_16 ] )
V_37 = TRUE ;
}
if ( ! V_37 ) {
V_10 [ V_12 ] [ V_13 ] = V_15 ;
} else {
V_10 [ V_12 ] [ V_13 ] = '%' ;
V_13 ++ ;
V_10 [ V_12 ] [ V_13 ] = V_38 [ V_15 >> 4 ] ;
V_13 ++ ;
V_10 [ V_12 ] [ V_13 ] = V_38 [ V_15 & 0xF ] ;
}
}
V_10 [ V_12 ] [ V_13 ] = '\0' ;
return V_10 [ V_12 ] ;
}
T_6 *
F_13 ( T_6 * V_39 ) {
T_6 * V_40 ;
if ( ! V_39 )
return NULL ;
V_40 = F_14 () ;
F_10 ( V_40 , V_39 -> V_1 , V_39 -> V_9 ) ;
return V_40 ;
}
T_4
F_15 ( const char * V_41 , T_6 * V_19 ) {
T_8 V_42 , V_43 , V_44 , V_16 ;
const char * V_22 , * V_45 ;
T_5 V_46 [ V_47 ] ;
F_9 ( V_19 , 0 ) ;
V_22 = V_41 ;
V_45 = NULL ;
while ( * V_22 ) {
if ( ! isdigit ( ( T_1 ) * V_22 ) && ( * V_22 != '.' ) ) return FALSE ;
if ( * V_22 == '.' ) {
if ( V_22 == V_41 ) return FALSE ;
if ( ! * ( V_22 + 1 ) ) return FALSE ;
if ( ( V_22 - 1 ) == V_45 ) return FALSE ;
V_45 = V_22 ;
}
V_22 ++ ;
}
if ( ! V_45 ) return FALSE ;
V_22 = V_41 ;
V_44 = 0 ;
V_42 = 0 ;
while ( * V_22 ) {
V_43 = 0 ;
while ( isdigit ( ( T_1 ) * V_22 ) ) {
V_43 *= 10 ;
V_43 += * V_22 - '0' ;
V_22 ++ ;
}
if ( V_44 == 0 ) {
V_42 = V_43 ;
if ( V_42 > 2 ) return FALSE ;
} else if ( V_44 == 1 ) {
if ( ( V_42 < 2 ) && ( V_43 > 39 ) ) return FALSE ;
V_43 += 40 * V_42 ;
}
if ( V_44 ) {
V_16 = V_47 ;
do {
V_16 -- ;
V_46 [ V_16 ] = 0x80 | ( V_43 % 0x80 ) ;
V_43 >>= 7 ;
} while ( V_43 && V_16 );
V_46 [ V_47 - 1 ] &= 0x7F ;
F_10 ( V_19 , V_46 + V_16 , V_47 - V_16 ) ;
}
V_44 ++ ;
if ( * V_22 ) V_22 ++ ;
}
return TRUE ;
}
T_4
F_16 ( T_6 * V_48 , T_6 * V_49 ) {
if ( ! V_48 || ! V_49 )
return FALSE ;
if ( V_48 -> V_9 != V_49 -> V_9 )
return FALSE ;
if ( memcmp ( V_48 -> V_1 , V_49 -> V_1 , V_48 -> V_9 ) != 0 )
return FALSE ;
return TRUE ;
}
T_2 *
F_17 ( const T_2 * V_50 )
{
T_9 * V_51 = F_18 ( 128 ) ;
const T_2 * V_22 ;
T_2 V_15 ;
V_22 = V_50 ;
while ( ( V_15 = * V_22 ++ ) ) {
switch ( V_15 ) {
case '<' :
F_19 ( V_51 , L_3 ) ;
break;
case '>' :
F_19 ( V_51 , L_4 ) ;
break;
case '&' :
F_19 ( V_51 , L_5 ) ;
break;
case '\'' :
F_19 ( V_51 , L_6 ) ;
break;
case '"' :
F_19 ( V_51 , L_7 ) ;
break;
default:
F_20 ( V_51 , V_15 ) ;
break;
}
}
return F_21 ( V_51 , FALSE ) ;
}
const T_5 *
F_22 ( const T_5 * V_52 , T_7 V_53 ,
const T_5 * V_54 , T_7 V_55 )
{
const T_5 * V_56 ;
const T_5 * const V_57
= V_52 + V_53 - V_55 ;
if ( V_55 == 0 ) {
return NULL ;
}
if ( V_55 > V_53 ) {
return NULL ;
}
for ( V_56 = V_52 ; V_56 <= V_57 ; ++ V_56 ) {
if ( V_56 [ 0 ] == V_54 [ 0 ] &&
! memcmp ( & V_56 [ 1 ] , V_54 + 1 ,
V_55 - 1 ) ) {
return V_56 ;
}
}
return NULL ;
}
T_5 *
F_23 ( const char * string , T_3 * V_58 )
{
T_3 V_59 ;
const char * V_22 ;
T_1 V_15 ;
T_5 * V_19 , * V_23 , V_60 ;
V_59 = 0 ;
V_22 = & string [ 0 ] ;
for (; ; ) {
V_15 = * V_22 ++ ;
if ( V_15 == '\0' )
break;
if ( isspace ( V_15 ) )
continue;
if ( V_15 == ':' || V_15 == '.' || V_15 == '-' )
continue;
if ( ! isxdigit ( V_15 ) ) {
return NULL ;
}
V_15 = * V_22 ++ ;
if ( ! isxdigit ( V_15 ) )
return NULL ;
V_59 ++ ;
}
if ( V_59 == 0 ) {
return NULL ;
}
V_19 = F_4 ( V_59 ) ;
V_22 = & string [ 0 ] ;
V_23 = & V_19 [ 0 ] ;
for (; ; ) {
V_15 = * V_22 ++ ;
if ( V_15 == '\0' )
break;
if ( isspace ( V_15 ) )
continue;
if ( V_15 == ':' || V_15 == '.' || V_15 == '-' )
continue;
if ( isdigit ( V_15 ) )
V_60 = V_15 - '0' ;
else if ( V_15 >= 'a' )
V_60 = ( V_15 - 'a' ) + 10 ;
else
V_60 = ( V_15 - 'A' ) + 10 ;
V_60 <<= 4 ;
V_15 = * V_22 ++ ;
if ( isdigit ( V_15 ) )
V_60 |= V_15 - '0' ;
else if ( V_15 >= 'a' )
V_60 |= ( V_15 - 'a' ) + 10 ;
else if ( V_15 >= 'A' )
V_60 |= ( V_15 - 'A' ) + 10 ;
* V_23 ++ = V_60 ;
}
* V_58 = V_59 ;
return V_19 ;
}
char *
F_24 ( const char * string , T_4 V_61 )
{
if ( V_61 ) {
return F_25 ( string , - 1 ) ;
} else {
return F_26 ( string ) ;
}
}
char *
F_27 ( const char * V_52 , const char * V_54 )
{
T_10 V_62 = strlen ( V_52 ) ;
T_10 V_63 = strlen ( V_54 ) ;
while ( V_62 -- >= V_63 ) {
if ( ! F_28 ( V_52 , V_54 , V_63 ) )
return ( char * ) V_52 ;
V_52 ++ ;
}
return NULL ;
}
const char *
F_29 ( const char * string )
{
if ( string )
return string ;
return L_8 ;
}
int
F_30 ( const char * string )
{
const char * V_22 ;
T_2 V_15 ;
int V_64 ;
V_64 = 0 ;
for ( V_22 = string ; ( V_15 = * V_22 ) != '\0' ; V_22 ++ ) {
if ( V_15 == '\\' || V_15 == '"' ) {
V_64 += 2 ;
}
else if ( ! isprint ( ( unsigned char ) V_15 ) ) {
V_64 += 4 ;
}
else {
V_64 ++ ;
}
}
return V_64 + 2 ;
}
char *
F_31 ( char * V_46 , const char * string )
{
const T_2 * V_22 ;
T_2 V_15 ;
char * V_65 ;
char V_66 [ 3 ] ;
V_65 = V_46 ;
* V_65 ++ = '"' ;
for ( V_22 = string ; ( V_15 = * V_22 ) != '\0' ; V_22 ++ ) {
if ( V_15 == '\\' || V_15 == '"' ) {
* V_65 ++ = '\\' ;
* V_65 ++ = V_15 ;
}
else if ( ! isprint ( ( unsigned char ) V_15 ) ) {
F_32 ( V_66 , sizeof( V_66 ) , L_9 , ( unsigned char ) V_15 ) ;
* V_65 ++ = '\\' ;
* V_65 ++ = 'x' ;
* V_65 ++ = V_66 [ 0 ] ;
* V_65 ++ = V_66 [ 1 ] ;
}
else {
* V_65 ++ = V_15 ;
}
}
* V_65 ++ = '"' ;
* V_65 = '\0' ;
return V_46 ;
}
static T_11
F_33 ( unsigned char V_67 )
{
if ( V_67 < V_68 )
{
return V_69 [ V_67 ] ;
}
else
{
return '?' ;
}
}
void
F_34 ( unsigned char * V_70 , const unsigned char * V_71 , int V_9 )
{
int V_16 , V_72 ;
T_11 V_46 ;
for ( V_16 = 0 , V_72 = 0 ; V_72 < V_9 ; V_72 ++ )
{
V_46 = F_33 ( V_71 [ V_72 ] ) ;
V_16 += F_35 ( V_46 , & ( V_70 [ V_16 ] ) ) ;
}
V_70 [ V_16 ] = 0 ;
return;
}
T_2 *
F_36 ( const T_2 * V_73 , const T_2 V_74 )
{
const T_2 * V_22 ;
T_2 * V_23 , * V_75 ;
if( ! V_73 )
return NULL ;
V_22 = V_73 ;
V_23 = V_75 = F_4 ( strlen ( V_73 ) * 2 + 1 ) ;
while( * V_22 != 0 )
{
if( * V_22 == V_74 )
* V_23 ++ = V_74 ;
* V_23 ++ = * V_22 ++ ;
}
* V_23 = '\0' ;
return V_75 ;
}
T_2 *
F_37 ( const T_2 * V_73 , const char V_74 )
{
const T_2 * V_22 ;
T_2 * V_23 , * V_75 ;
if( ! V_73 )
return NULL ;
V_22 = V_73 ;
V_23 = V_75 = F_4 ( strlen ( V_73 ) + 1 ) ;
while( * V_22 != 0 )
{
* V_23 ++ = * V_22 ;
if ( ( * V_22 == V_74 ) && ( * ( V_22 + 1 ) == V_74 ) )
V_22 += 2 ;
else
V_22 ++ ;
}
* V_23 = '\0' ;
return V_75 ;
}
T_2 * F_38 ( const T_2 * V_73 , const T_2 * V_76 , const T_2 * V_77 ) {
T_2 * * V_78 ;
T_2 * V_75 ;
if ( ! V_73 || ! V_76 ) {
return NULL ;
}
V_78 = F_39 ( V_73 , V_76 , 0 ) ;
V_75 = F_40 ( V_77 , V_78 ) ;
F_41 ( V_78 ) ;
return V_75 ;
}
