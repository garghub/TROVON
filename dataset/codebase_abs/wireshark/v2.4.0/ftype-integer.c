static void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 . V_3 = 0 ;
}
static void
F_2 ( T_1 * V_1 , T_2 V_2 )
{
V_1 -> V_2 . V_3 = V_2 ;
}
static void
F_3 ( T_1 * V_1 , T_3 V_2 )
{
V_1 -> V_2 . V_4 = V_2 ;
}
static T_2
F_4 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 ;
}
static T_3
F_5 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_4 ;
}
static T_4
F_6 ( const char * V_5 , unsigned long * V_6 , T_5 * * V_7 )
{
const char * V_8 ;
unsigned long V_2 ;
V_8 = V_5 + 1 ;
if ( * V_8 == '\\' ) {
V_8 ++ ;
switch ( * V_8 ) {
case '\0' :
if ( V_7 != NULL )
* V_7 = F_7 ( L_1 , V_5 ) ;
return FALSE ;
case 'a' :
V_2 = '\a' ;
break;
case 'b' :
V_2 = '\b' ;
break;
case 'f' :
V_2 = '\f' ;
break;
case 'n' :
V_2 = '\n' ;
break;
case 'r' :
V_2 = '\r' ;
break;
case 't' :
V_2 = '\t' ;
break;
case 'v' :
V_2 = '\v' ;
break;
case '\'' :
V_2 = '\'' ;
break;
case '\\' :
V_2 = '\\' ;
break;
case '"' :
V_2 = '"' ;
break;
case 'x' :
V_8 ++ ;
if ( * V_8 >= '0' && * V_8 <= '9' )
V_2 = * V_8 - '0' ;
else if ( * V_8 >= 'A' && * V_8 <= 'F' )
V_2 = 10 + ( * V_8 - 'A' ) ;
else if ( * V_8 >= 'a' && * V_8 <= 'f' )
V_2 = 10 + ( * V_8 - 'a' ) ;
else {
if ( V_7 != NULL )
* V_7 = F_7 ( L_1 , V_5 ) ;
return FALSE ;
}
V_8 ++ ;
if ( * V_8 != '\'' ) {
V_2 <<= 4 ;
if ( * V_8 >= '0' && * V_8 <= '9' )
V_2 |= * V_8 - '0' ;
else if ( * V_8 >= 'A' && * V_8 <= 'F' )
V_2 |= 10 + ( * V_8 - 'A' ) ;
else if ( * V_8 >= 'a' && * V_8 <= 'f' )
V_2 |= 10 + ( * V_8 - 'a' ) ;
else {
if ( V_7 != NULL )
* V_7 = F_7 ( L_1 , V_5 ) ;
return FALSE ;
}
}
break;
default:
if ( * V_8 >= '0' && * V_8 <= '7' )
V_2 = * V_8 - '0' ;
else {
if ( V_7 != NULL )
* V_7 = F_7 ( L_1 , V_5 ) ;
return FALSE ;
}
V_8 ++ ;
if ( * V_8 != '\'' ) {
V_2 <<= 3 ;
if ( * V_8 >= '0' && * V_8 <= '7' )
V_2 |= * V_8 - '0' ;
else {
if ( V_7 != NULL )
* V_7 = F_7 ( L_1 , V_5 ) ;
return FALSE ;
}
V_8 ++ ;
if ( * V_8 != '\'' ) {
V_2 <<= 3 ;
if ( * V_8 >= '0' && * V_8 <= '7' )
V_2 |= * V_8 - '0' ;
else {
if ( V_7 != NULL )
* V_7 = F_7 ( L_1 , V_5 ) ;
return FALSE ;
}
}
}
if ( V_2 > 0xFF ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_2 , V_5 ) ;
return FALSE ;
}
}
} else {
V_2 = * V_8 ;
V_8 ++ ;
if ( ! F_8 ( V_2 ) ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_3 , V_2 ) ;
return FALSE ;
}
}
* V_6 = V_2 ;
return TRUE ;
}
static T_4
F_9 ( T_1 * V_1 , const char * V_5 , T_4 T_6 V_9 , T_5 * * V_7 ,
T_2 V_10 )
{
unsigned long V_2 ;
char * V_11 ;
if ( V_5 [ 0 ] == '\'' ) {
if ( ! F_6 ( V_5 , & V_2 , V_7 ) )
return FALSE ;
} else {
if ( strchr ( V_5 , '-' ) && strtol ( V_5 , NULL , 0 ) < 0 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_4 , V_5 ) ;
return FALSE ;
}
V_12 = 0 ;
V_2 = strtoul ( V_5 , & V_11 , 0 ) ;
if ( V_12 == V_13 || V_11 == V_5 || * V_11 != '\0' ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_5 , V_5 ) ;
return FALSE ;
}
if ( V_12 == V_14 ) {
if ( V_7 != NULL ) {
if ( V_2 == V_15 ) {
* V_7 = F_7 ( L_6 ,
V_5 ) ;
}
else {
* V_7 = F_7 ( L_7 , V_5 ) ;
}
}
return FALSE ;
}
}
if ( V_2 > V_10 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_8 , V_5 , V_10 ) ;
return FALSE ;
}
V_1 -> V_2 . V_3 = ( T_2 ) V_2 ;
return TRUE ;
}
static T_4
F_10 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_9 ( V_1 , V_5 , T_6 , V_7 , V_16 ) ;
}
static T_4
F_11 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_9 ( V_1 , V_5 , T_6 , V_7 , 0xFFFFFF ) ;
}
static T_4
F_12 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_9 ( V_1 , V_5 , T_6 , V_7 , V_17 ) ;
}
static T_4
F_13 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_9 ( V_1 , V_5 , T_6 , V_7 , V_18 ) ;
}
static T_4
F_14 ( T_1 * V_1 , const char * V_5 , T_4 T_6 V_9 , T_5 * * V_7 ,
T_3 V_10 , T_3 V_19 )
{
long V_2 ;
char * V_11 ;
if ( V_5 [ 0 ] == '\'' ) {
if ( ! F_6 ( V_5 , & V_2 , V_7 ) )
return FALSE ;
} else {
if ( ! strchr ( V_5 , '-' ) && strtoul ( V_5 , NULL , 0 ) > V_20 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_6 , V_5 ) ;
return FALSE ;
}
V_12 = 0 ;
V_2 = strtol ( V_5 , & V_11 , 0 ) ;
if ( V_12 == V_13 || V_11 == V_5 || * V_11 != '\0' ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_5 , V_5 ) ;
return FALSE ;
}
if ( V_12 == V_14 ) {
if ( V_7 != NULL ) {
if ( V_2 == V_21 ) {
* V_7 = F_7 ( L_6 , V_5 ) ;
}
else if ( V_2 == V_22 ) {
* V_7 = F_7 ( L_9 , V_5 ) ;
}
else {
* V_7 = F_7 ( L_7 , V_5 ) ;
}
}
return FALSE ;
}
}
if ( V_2 > V_10 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_10 ,
V_5 , V_10 ) ;
return FALSE ;
} else if ( V_2 < V_19 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_11 ,
V_5 , V_19 ) ;
return FALSE ;
}
V_1 -> V_2 . V_4 = ( T_3 ) V_2 ;
return TRUE ;
}
static T_4
F_15 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_14 ( V_1 , V_5 , T_6 , V_7 , V_20 , V_23 ) ;
}
static T_4
F_16 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_14 ( V_1 , V_5 , T_6 , V_7 , 0x7FFFFF , - 0x800000 ) ;
}
static T_4
F_17 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_14 ( V_1 , V_5 , T_6 , V_7 , V_24 , V_25 ) ;
}
static T_4
F_18 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_14 ( V_1 , V_5 , T_6 , V_7 , V_26 , V_27 ) ;
}
static int
F_19 ( T_1 * V_1 V_9 , T_7 T_8 V_9 , int T_9 V_9 )
{
return 11 ;
}
static void
F_20 ( T_1 * V_1 , T_7 T_8 V_9 , int T_9 V_9 , char * V_28 , unsigned int V_29 )
{
T_2 V_30 ;
if ( V_1 -> V_2 . V_4 < 0 ) {
* V_28 ++ = '-' ;
V_30 = - V_1 -> V_2 . V_4 ;
} else
V_30 = V_1 -> V_2 . V_4 ;
F_21 ( V_30 , V_28 , V_29 ) ;
}
static int
F_22 ( T_1 * V_1 V_9 , T_7 T_8 V_9 , int T_9 V_9 )
{
return 10 ;
}
static int
F_23 ( T_1 * V_1 V_9 , T_7 T_8 V_9 , int T_9 V_9 )
{
return 7 ;
}
static void
F_24 ( T_1 * V_1 , T_7 T_8 V_9 , int T_9 , char * V_28 , unsigned int V_29 )
{
if ( ( T_9 == V_31 ) || ( T_9 == V_32 ) )
{
* V_28 ++ = '0' ;
* V_28 ++ = 'x' ;
V_28 = F_25 ( V_28 , V_1 -> V_2 . V_3 ) ;
* V_28 ++ = '\0' ;
}
else
{
F_21 ( V_1 -> V_2 . V_3 , V_28 , V_29 ) ;
}
}
static void
F_26 ( T_1 * V_1 , T_7 T_8 V_9 , int T_9 , char * V_28 , unsigned int V_29 V_9 )
{
* V_28 ++ = '\'' ;
if ( F_8 ( V_1 -> V_2 . V_3 ) ) {
if ( V_1 -> V_2 . V_3 == '\\' || V_1 -> V_2 . V_3 == '\'' )
* V_28 ++ = '\\' ;
* V_28 ++ = ( char ) V_1 -> V_2 . V_3 ;
} else {
* V_28 ++ = '\\' ;
switch ( V_1 -> V_2 . V_3 ) {
case '\0' :
* V_28 ++ = '0' ;
break;
case '\a' :
* V_28 ++ = 'a' ;
break;
case '\b' :
* V_28 ++ = 'b' ;
break;
case '\f' :
* V_28 ++ = 'f' ;
break;
case '\n' :
* V_28 ++ = 'n' ;
break;
case '\r' :
* V_28 ++ = 'r' ;
break;
case '\t' :
* V_28 ++ = 't' ;
break;
case '\v' :
* V_28 ++ = 'v' ;
break;
default:
if ( T_9 == V_31 ) {
* V_28 ++ = 'x' ;
V_28 = F_27 ( V_28 , V_1 -> V_2 . V_3 ) ;
}
else
{
* V_28 ++ = ( ( V_1 -> V_2 . V_3 >> 6 ) & 0x7 ) + '0' ;
* V_28 ++ = ( ( V_1 -> V_2 . V_3 >> 3 ) & 0x7 ) + '0' ;
* V_28 ++ = ( ( V_1 -> V_2 . V_3 >> 0 ) & 0x7 ) + '0' ;
}
break;
}
}
* V_28 ++ = '\'' ;
* V_28 ++ = '\0' ;
}
static T_4
F_28 ( T_1 * V_1 , const char * V_5 , T_4 T_6 V_9 , T_5 * * V_7 )
{
T_2 V_30 ;
T_4 V_33 ;
if ( F_10 ( V_1 , V_5 , TRUE , NULL ) ) {
return TRUE ;
}
V_30 = F_29 ( V_5 , & V_33 ) ;
if ( V_33 ) {
V_1 -> V_2 . V_3 = V_30 ;
return TRUE ;
}
if ( V_7 != NULL )
* V_7 = F_7 ( L_12 , V_5 ) ;
return FALSE ;
}
static int
F_30 ( T_1 * V_1 V_9 , T_7 T_8 V_9 , int T_9 V_9 )
{
return 2 + 8 ;
}
static void
F_31 ( T_1 * V_1 , T_7 T_8 , int T_9 V_9 , char * V_28 , unsigned int V_29 )
{
F_24 ( V_1 , T_8 , V_31 , V_28 , V_29 ) ;
}
static T_4
F_32 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_3 == V_35 -> V_2 . V_3 ;
}
static T_4
F_33 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_3 != V_35 -> V_2 . V_3 ;
}
static T_4
F_34 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_3 > V_35 -> V_2 . V_3 ;
}
static T_4
F_35 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_3 >= V_35 -> V_2 . V_3 ;
}
static T_4
F_36 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_3 < V_35 -> V_2 . V_3 ;
}
static T_4
F_37 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_3 <= V_35 -> V_2 . V_3 ;
}
static T_4
F_38 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_4 > V_35 -> V_2 . V_4 ;
}
static T_4
F_39 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_4 >= V_35 -> V_2 . V_4 ;
}
static T_4
F_40 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_4 < V_35 -> V_2 . V_4 ;
}
static T_4
F_41 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_4 <= V_35 -> V_2 . V_4 ;
}
static T_4
F_42 ( const T_1 * V_34 , const T_1 * V_35 )
{
return ( ( V_34 -> V_2 . V_3 & V_35 -> V_2 . V_3 ) != 0 ) ;
}
static void
F_43 ( T_1 * V_1 )
{
V_1 -> V_2 . V_36 = 0 ;
}
static void
F_44 ( T_1 * V_1 , T_10 V_2 )
{
V_1 -> V_2 . V_37 = V_2 ;
}
static void
F_45 ( T_1 * V_1 , T_11 V_2 )
{
V_1 -> V_2 . V_36 = V_2 ;
}
static T_10
F_46 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_37 ;
}
static T_11
F_47 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_36 ;
}
static T_4
F_48 ( T_1 * V_1 , const char * V_5 , T_4 T_6 V_9 , T_5 * * V_7 ,
T_10 V_10 )
{
T_10 V_2 ;
char * V_11 ;
if ( strchr ( V_5 , '-' ) && F_49 ( V_5 , NULL , 0 ) < 0 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_9 , V_5 ) ;
return FALSE ;
}
V_12 = 0 ;
V_2 = F_50 ( V_5 , & V_11 , 0 ) ;
if ( V_12 == V_13 || V_11 == V_5 || * V_11 != '\0' ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_5 , V_5 ) ;
return FALSE ;
}
if ( V_12 == V_14 ) {
if ( V_7 != NULL ) {
if ( V_2 == V_38 ) {
* V_7 = F_7 ( L_6 , V_5 ) ;
}
else {
* V_7 = F_7 ( L_7 , V_5 ) ;
}
}
return FALSE ;
}
if ( V_2 > V_10 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_13 V_39 L_14 , V_5 , V_10 ) ;
return FALSE ;
}
V_1 -> V_2 . V_37 = V_2 ;
return TRUE ;
}
static T_4
F_51 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_48 ( V_1 , V_5 , T_6 , V_7 , V_38 ) ;
}
static T_4
F_52 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_48 ( V_1 , V_5 , T_6 , V_7 , F_53 ( 0xFFFFFFFFFFFFFF ) ) ;
}
static T_4
F_54 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_48 ( V_1 , V_5 , T_6 , V_7 , F_53 ( 0xFFFFFFFFFFFF ) ) ;
}
static T_4
F_55 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_48 ( V_1 , V_5 , T_6 , V_7 , F_53 ( 0xFFFFFFFFFF ) ) ;
}
static T_4
F_56 ( T_1 * V_1 , const char * V_5 , T_4 T_6 V_9 , T_5 * * V_7 ,
T_11 V_10 , T_11 V_19 )
{
T_11 V_2 ;
char * V_11 ;
if ( ! strchr ( V_5 , '-' ) && F_50 ( V_5 , NULL , 0 ) > V_40 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_6 , V_5 ) ;
return FALSE ;
}
V_12 = 0 ;
V_2 = F_49 ( V_5 , & V_11 , 0 ) ;
if ( V_12 == V_13 || V_11 == V_5 || * V_11 != '\0' ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_5 , V_5 ) ;
return FALSE ;
}
if ( V_12 == V_14 ) {
if ( V_7 != NULL ) {
if ( V_2 == V_40 ) {
* V_7 = F_7 ( L_6 , V_5 ) ;
}
else if ( V_2 == V_41 ) {
* V_7 = F_7 ( L_9 , V_5 ) ;
}
else {
* V_7 = F_7 ( L_7 , V_5 ) ;
}
}
return FALSE ;
}
if ( V_2 > V_10 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_13 V_39 L_14 , V_5 , V_10 ) ;
return FALSE ;
} else if ( V_2 < V_19 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_15 V_39 L_14 , V_5 , V_10 ) ;
return FALSE ;
}
V_1 -> V_2 . V_36 = ( T_10 ) V_2 ;
return TRUE ;
}
static T_4
F_57 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_56 ( V_1 , V_5 , T_6 , V_7 , V_40 , V_41 ) ;
}
static T_4
F_58 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_56 ( V_1 , V_5 , T_6 , V_7 , F_59 ( 0x7FFFFFFFFFFFFF ) , F_59 ( - 0x80000000000000 ) ) ;
}
static T_4
F_60 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_56 ( V_1 , V_5 , T_6 , V_7 , F_59 ( 0x7FFFFFFFFFFF ) , F_59 ( - 0x800000000000 ) ) ;
}
static T_4
F_61 ( T_1 * V_1 , const char * V_5 , T_4 T_6 , T_5 * * V_7 )
{
return F_56 ( V_1 , V_5 , T_6 , V_7 , F_59 ( 0x7FFFFFFFFF ) , F_59 ( - 0x8000000000 ) ) ;
}
static int
F_62 ( T_1 * V_1 V_9 , T_7 T_8 V_9 , int T_9 V_9 )
{
return 20 ;
}
static void
F_63 ( T_1 * V_1 , T_7 T_8 V_9 , int T_9 V_9 , char * V_28 , unsigned int V_29 )
{
T_10 V_30 ;
if ( V_1 -> V_2 . V_36 < 0 ) {
* V_28 ++ = '-' ;
V_30 = - V_1 -> V_2 . V_36 ;
} else
V_30 = V_1 -> V_2 . V_36 ;
F_64 ( V_30 , V_28 , V_29 ) ;
}
static int
F_65 ( T_1 * V_1 V_9 , T_7 T_8 V_9 , int T_9 V_9 )
{
return 20 ;
}
static void
F_66 ( T_1 * V_1 , T_7 T_8 V_9 , int T_9 , char * V_28 , unsigned int V_29 )
{
if ( ( T_9 == V_31 ) || ( T_9 == V_32 ) )
{
* V_28 ++ = '0' ;
* V_28 ++ = 'x' ;
V_28 = F_67 ( V_28 , V_1 -> V_2 . V_37 ) ;
* V_28 ++ = '\0' ;
}
else
{
F_64 ( V_1 -> V_2 . V_37 , V_28 , V_29 ) ;
}
}
static T_4
F_68 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_37 == V_35 -> V_2 . V_37 ;
}
static T_4
F_69 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_37 != V_35 -> V_2 . V_37 ;
}
static T_4
F_70 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_37 > V_35 -> V_2 . V_37 ;
}
static T_4
F_71 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_37 >= V_35 -> V_2 . V_37 ;
}
static T_4
F_72 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_37 < V_35 -> V_2 . V_37 ;
}
static T_4
F_73 ( const T_1 * V_34 , const T_1 * V_35 )
{
return V_34 -> V_2 . V_37 <= V_35 -> V_2 . V_37 ;
}
static T_4
F_74 ( const T_1 * V_34 , const T_1 * V_35 )
{
return ( T_11 ) V_34 -> V_2 . V_36 > ( T_11 ) V_35 -> V_2 . V_36 ;
}
static T_4
F_75 ( const T_1 * V_34 , const T_1 * V_35 )
{
return ( T_11 ) V_34 -> V_2 . V_36 >= ( T_11 ) V_35 -> V_2 . V_36 ;
}
static T_4
F_76 ( const T_1 * V_34 , const T_1 * V_35 )
{
return ( T_11 ) V_34 -> V_2 . V_36 < ( T_11 ) V_35 -> V_2 . V_36 ;
}
static T_4
F_77 ( const T_1 * V_34 , const T_1 * V_35 )
{
return ( T_11 ) V_34 -> V_2 . V_36 <= ( T_11 ) V_35 -> V_2 . V_36 ;
}
static T_4
F_78 ( const T_1 * V_34 , const T_1 * V_35 )
{
return ( ( V_34 -> V_2 . V_37 & V_35 -> V_2 . V_37 ) != 0 ) ;
}
static void
F_79 ( T_1 * V_1 )
{
V_1 -> V_2 . V_37 = TRUE ;
}
static int
F_80 ( T_1 * V_1 V_9 , T_7 T_8 V_9 , int T_9 V_9 )
{
return 1 ;
}
static void
F_81 ( T_1 * V_1 , T_7 T_8 V_9 , int T_9 V_9 , char * V_28 , unsigned int V_29 V_9 )
{
* V_28 ++ = ( V_1 -> V_2 . V_37 ) ? '1' : '0' ;
* V_28 = '\0' ;
}
static T_4
F_82 ( const T_1 * V_34 , const T_1 * V_35 )
{
if ( V_34 -> V_2 . V_37 ) {
if ( V_35 -> V_2 . V_37 ) {
return TRUE ;
}
else {
return FALSE ;
}
}
else {
if ( V_35 -> V_2 . V_37 ) {
return FALSE ;
}
else {
return TRUE ;
}
}
}
static T_4
F_83 ( const T_1 * V_34 , const T_1 * V_35 )
{
return ( ! F_82 ( V_34 , V_35 ) ) ;
}
static T_4
F_84 ( T_1 * V_1 , const char * V_5 , T_4 T_6 V_9 , T_5 * * V_7 )
{
T_12 * V_42 ;
T_4 V_43 ;
union {
T_10 V_2 ;
T_13 V_42 [ 8 ] ;
} V_44 ;
if ( F_51 ( V_1 , V_5 , TRUE , NULL ) ) {
return TRUE ;
}
V_42 = F_85 () ;
V_43 = F_86 ( V_5 , V_42 , TRUE ) ;
if ( ! V_43 || V_42 -> V_45 != 8 ) {
if ( V_7 != NULL )
* V_7 = F_7 ( L_16 , V_5 ) ;
F_87 ( V_42 , TRUE ) ;
return FALSE ;
}
memcpy ( V_44 . V_42 , V_42 -> V_46 , 8 ) ;
F_87 ( V_42 , TRUE ) ;
V_1 -> V_2 . V_47 = F_88 ( V_44 . V_2 ) ;
return TRUE ;
}
static int
F_89 ( T_1 * V_1 V_9 , T_7 T_8 V_9 , int T_9 V_9 )
{
return V_48 ;
}
static void
F_90 ( T_1 * V_1 , T_7 T_8 V_9 , int T_9 V_9 , char * V_28 , unsigned int V_29 )
{
union {
T_10 V_2 ;
T_13 V_42 [ 8 ] ;
} V_44 ;
V_44 . V_2 = F_91 ( V_1 -> V_2 . V_47 ) ;
F_92 ( V_28 , V_29 , L_17 ,
V_44 . V_42 [ 0 ] , V_44 . V_42 [ 1 ] , V_44 . V_42 [ 2 ] , V_44 . V_42 [ 3 ] ,
V_44 . V_42 [ 4 ] , V_44 . V_42 [ 5 ] , V_44 . V_42 [ 6 ] , V_44 . V_42 [ 7 ] ) ;
}
void
F_93 ( void )
{
static T_14 V_49 = {
V_50 ,
L_18 ,
L_19 ,
1 ,
F_1 ,
NULL ,
F_13 ,
NULL ,
F_26 ,
F_23 ,
{ . V_51 = F_2 } ,
{ . V_52 = F_4 } ,
F_32 ,
F_33 ,
F_34 ,
F_35 ,
F_36 ,
F_37 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_53 = {
V_54 ,
L_20 ,
L_21 ,
1 ,
F_1 ,
NULL ,
F_13 ,
NULL ,
F_24 ,
F_22 ,
{ . V_51 = F_2 } ,
{ . V_52 = F_4 } ,
F_32 ,
F_33 ,
F_34 ,
F_35 ,
F_36 ,
F_37 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_55 = {
V_56 ,
L_22 ,
L_23 ,
2 ,
F_1 ,
NULL ,
F_12 ,
NULL ,
F_24 ,
F_22 ,
{ . V_51 = F_2 } ,
{ . V_52 = F_4 } ,
F_32 ,
F_33 ,
F_34 ,
F_35 ,
F_36 ,
F_37 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_57 = {
V_58 ,
L_24 ,
L_25 ,
3 ,
F_1 ,
NULL ,
F_11 ,
NULL ,
F_24 ,
F_22 ,
{ . V_51 = F_2 } ,
{ . V_52 = F_4 } ,
F_32 ,
F_33 ,
F_34 ,
F_35 ,
F_36 ,
F_37 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_59 = {
V_60 ,
L_26 ,
L_27 ,
4 ,
F_1 ,
NULL ,
F_10 ,
NULL ,
F_24 ,
F_22 ,
{ . V_51 = F_2 } ,
{ . V_52 = F_4 } ,
F_32 ,
F_33 ,
F_34 ,
F_35 ,
F_36 ,
F_37 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_61 = {
V_62 ,
L_28 ,
L_29 ,
5 ,
F_43 ,
NULL ,
F_55 ,
NULL ,
F_66 ,
F_65 ,
{ . V_63 = F_44 } ,
{ . V_64 = F_46 } ,
F_68 ,
F_69 ,
F_70 ,
F_71 ,
F_72 ,
F_73 ,
F_78 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_65 = {
V_66 ,
L_30 ,
L_31 ,
6 ,
F_43 ,
NULL ,
F_54 ,
NULL ,
F_66 ,
F_65 ,
{ . V_63 = F_44 } ,
{ . V_64 = F_46 } ,
F_68 ,
F_69 ,
F_70 ,
F_71 ,
F_72 ,
F_73 ,
F_78 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_67 = {
V_68 ,
L_32 ,
L_33 ,
7 ,
F_43 ,
NULL ,
F_52 ,
NULL ,
F_66 ,
F_65 ,
{ . V_63 = F_44 } ,
{ . V_64 = F_46 } ,
F_68 ,
F_69 ,
F_70 ,
F_71 ,
F_72 ,
F_73 ,
F_78 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_69 = {
V_70 ,
L_34 ,
L_35 ,
8 ,
F_43 ,
NULL ,
F_51 ,
NULL ,
F_66 ,
F_65 ,
{ . V_63 = F_44 } ,
{ . V_64 = F_46 } ,
F_68 ,
F_69 ,
F_70 ,
F_71 ,
F_72 ,
F_73 ,
F_78 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_71 = {
V_72 ,
L_36 ,
L_37 ,
1 ,
F_1 ,
NULL ,
F_18 ,
NULL ,
F_20 ,
F_19 ,
{ . V_73 = F_3 } ,
{ . V_74 = F_5 } ,
F_32 ,
F_33 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_75 = {
V_76 ,
L_38 ,
L_39 ,
2 ,
F_1 ,
NULL ,
F_17 ,
NULL ,
F_20 ,
F_19 ,
{ . V_73 = F_3 } ,
{ . V_74 = F_5 } ,
F_32 ,
F_33 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_77 = {
V_78 ,
L_40 ,
L_41 ,
3 ,
F_1 ,
NULL ,
F_16 ,
NULL ,
F_20 ,
F_19 ,
{ . V_73 = F_3 } ,
{ . V_74 = F_5 } ,
F_32 ,
F_33 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_79 = {
V_80 ,
L_42 ,
L_43 ,
4 ,
F_1 ,
NULL ,
F_15 ,
NULL ,
F_20 ,
F_19 ,
{ . V_73 = F_3 } ,
{ . V_74 = F_5 } ,
F_32 ,
F_33 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_81 = {
V_82 ,
L_44 ,
L_45 ,
5 ,
F_43 ,
NULL ,
F_61 ,
NULL ,
F_63 ,
F_62 ,
{ . V_83 = F_45 } ,
{ . V_84 = F_47 } ,
F_68 ,
F_69 ,
F_74 ,
F_75 ,
F_76 ,
F_77 ,
F_78 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_85 = {
V_86 ,
L_46 ,
L_47 ,
6 ,
F_43 ,
NULL ,
F_60 ,
NULL ,
F_63 ,
F_62 ,
{ . V_83 = F_45 } ,
{ . V_84 = F_47 } ,
F_68 ,
F_69 ,
F_74 ,
F_75 ,
F_76 ,
F_77 ,
F_78 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_87 = {
V_88 ,
L_48 ,
L_49 ,
7 ,
F_43 ,
NULL ,
F_58 ,
NULL ,
F_63 ,
F_62 ,
{ . V_83 = F_45 } ,
{ . V_84 = F_47 } ,
F_68 ,
F_69 ,
F_74 ,
F_75 ,
F_76 ,
F_77 ,
F_78 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_89 = {
V_90 ,
L_50 ,
L_51 ,
8 ,
F_43 ,
NULL ,
F_57 ,
NULL ,
F_63 ,
F_62 ,
{ . V_83 = F_45 } ,
{ . V_84 = F_47 } ,
F_68 ,
F_69 ,
F_74 ,
F_75 ,
F_76 ,
F_77 ,
F_78 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_91 = {
V_92 ,
L_52 ,
L_53 ,
0 ,
F_79 ,
NULL ,
F_51 ,
NULL ,
F_81 ,
F_80 ,
{ . V_63 = F_44 } ,
{ . V_64 = F_46 } ,
F_82 ,
F_83 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_93 = {
V_94 ,
L_54 ,
L_55 ,
4 ,
F_1 ,
NULL ,
F_28 ,
NULL ,
F_31 ,
F_30 ,
{ . V_51 = F_2 } ,
{ . V_52 = F_4 } ,
F_32 ,
F_33 ,
F_34 ,
F_35 ,
F_36 ,
F_37 ,
F_42 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_95 = {
V_96 ,
L_56 ,
L_57 ,
4 ,
F_1 ,
NULL ,
F_10 ,
NULL ,
F_24 ,
F_22 ,
{ . V_51 = F_2 } ,
{ . V_52 = F_4 } ,
F_32 ,
F_33 ,
F_34 ,
F_35 ,
F_36 ,
F_37 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_14 V_97 = {
V_98 ,
L_58 ,
L_59 ,
V_99 ,
F_43 ,
NULL ,
F_84 ,
NULL ,
F_90 ,
F_89 ,
{ . V_63 = F_44 } ,
{ . V_64 = F_46 } ,
F_68 ,
F_69 ,
F_70 ,
F_71 ,
F_72 ,
F_73 ,
F_78 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
F_94 ( V_50 , & V_49 ) ;
F_94 ( V_54 , & V_53 ) ;
F_94 ( V_56 , & V_55 ) ;
F_94 ( V_58 , & V_57 ) ;
F_94 ( V_60 , & V_59 ) ;
F_94 ( V_62 , & V_61 ) ;
F_94 ( V_66 , & V_65 ) ;
F_94 ( V_68 , & V_67 ) ;
F_94 ( V_70 , & V_69 ) ;
F_94 ( V_72 , & V_71 ) ;
F_94 ( V_76 , & V_75 ) ;
F_94 ( V_78 , & V_77 ) ;
F_94 ( V_80 , & V_79 ) ;
F_94 ( V_82 , & V_81 ) ;
F_94 ( V_86 , & V_85 ) ;
F_94 ( V_88 , & V_87 ) ;
F_94 ( V_90 , & V_89 ) ;
F_94 ( V_92 , & V_91 ) ;
F_94 ( V_94 , & V_93 ) ;
F_94 ( V_96 , & V_95 ) ;
F_94 ( V_98 , & V_97 ) ;
}
