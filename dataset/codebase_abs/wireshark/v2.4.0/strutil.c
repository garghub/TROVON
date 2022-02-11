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
F_3 ( T_3 * V_9 , const T_1 * string , T_4 V_10 )
{
T_2 * V_11 = ( T_2 * ) F_4 ( V_9 , V_12 ) ;
int V_13 = V_12 ;
int V_14 ;
const T_1 * V_15 = string + V_10 ;
T_1 V_16 ;
int V_17 ;
V_14 = 0 ;
while ( string < V_15 ) {
if ( V_14 + 3 + 1 >= V_13 ) {
V_13 *= 2 ;
V_11 = ( T_2 * ) F_5 ( V_9 , V_11 , V_13 ) ;
}
V_16 = * string ++ ;
if ( F_6 ( V_16 ) ) {
V_11 [ V_14 ] = V_16 ;
V_14 ++ ;
} else {
V_11 [ V_14 ] = '\\' ;
V_14 ++ ;
switch ( V_16 ) {
case '\a' :
V_11 [ V_14 ] = 'a' ;
V_14 ++ ;
break;
case '\b' :
V_11 [ V_14 ] = 'b' ;
V_14 ++ ;
break;
case '\f' :
V_11 [ V_14 ] = 'f' ;
V_14 ++ ;
break;
case '\n' :
V_11 [ V_14 ] = 'n' ;
V_14 ++ ;
break;
case '\r' :
V_11 [ V_14 ] = 'r' ;
V_14 ++ ;
break;
case '\t' :
V_11 [ V_14 ] = 't' ;
V_14 ++ ;
break;
case '\v' :
V_11 [ V_14 ] = 'v' ;
V_14 ++ ;
break;
default:
V_17 = ( V_16 >> 6 ) & 03 ;
V_11 [ V_14 ] = V_17 + '0' ;
V_14 ++ ;
V_17 = ( V_16 >> 3 ) & 07 ;
V_11 [ V_14 ] = V_17 + '0' ;
V_14 ++ ;
V_17 = ( V_16 >> 0 ) & 07 ;
V_11 [ V_14 ] = V_17 + '0' ;
V_14 ++ ;
break;
}
}
}
V_11 [ V_14 ] = '\0' ;
return V_11 ;
}
T_2 *
F_7 ( T_3 * V_9 , const T_1 * string , T_4 V_10 )
{
T_2 * V_11 = ( T_2 * ) F_4 ( V_9 , V_12 ) ;
int V_13 = V_12 ;
int V_14 ;
const T_1 * V_15 = string + V_10 ;
T_1 V_16 ;
int V_17 ;
V_14 = 0 ;
while ( string < V_15 ) {
if ( V_14 + 3 + 1 >= V_13 ) {
V_13 *= 2 ;
V_11 = ( T_2 * ) F_5 ( V_9 , V_11 , V_13 ) ;
}
V_16 = * string ++ ;
if ( F_6 ( V_16 ) ) {
V_11 [ V_14 ] = V_16 ;
V_14 ++ ;
} else if ( F_8 ( V_16 ) ) {
V_11 [ V_14 ] = ' ' ;
V_14 ++ ;
} else {
V_11 [ V_14 ] = '\\' ;
V_14 ++ ;
switch ( V_16 ) {
case '\a' :
V_11 [ V_14 ] = 'a' ;
V_14 ++ ;
break;
case '\b' :
V_11 [ V_14 ] = 'b' ;
V_14 ++ ;
break;
case '\f' :
V_11 [ V_14 ] = 'f' ;
V_14 ++ ;
break;
case '\n' :
V_11 [ V_14 ] = 'n' ;
V_14 ++ ;
break;
case '\r' :
V_11 [ V_14 ] = 'r' ;
V_14 ++ ;
break;
case '\t' :
V_11 [ V_14 ] = 't' ;
V_14 ++ ;
break;
case '\v' :
V_11 [ V_14 ] = 'v' ;
V_14 ++ ;
break;
default:
V_17 = ( V_16 >> 6 ) & 03 ;
V_11 [ V_14 ] = V_17 + '0' ;
V_14 ++ ;
V_17 = ( V_16 >> 3 ) & 07 ;
V_11 [ V_14 ] = V_17 + '0' ;
V_14 ++ ;
V_17 = ( V_16 >> 0 ) & 07 ;
V_11 [ V_14 ] = V_17 + '0' ;
V_14 ++ ;
break;
}
}
}
V_11 [ V_14 ] = '\0' ;
return V_11 ;
}
T_2 *
F_9 ( T_3 * V_9 , const T_1 * string , const T_4 V_10 , const T_1 V_18 )
{
T_2 * V_11 = ( T_2 * ) F_4 ( V_9 , V_12 ) ;
int V_13 = V_12 ;
int V_14 ;
const T_1 * V_15 = string + V_10 ;
T_1 V_16 ;
V_14 = 0 ;
while ( string < V_15 )
{
if ( V_14 + 1 >= V_13 )
{
V_13 *= 2 ;
V_11 = ( T_2 * ) F_5 ( V_9 , V_11 , V_13 ) ;
}
V_16 = * string ++ ;
if ( F_6 ( V_16 ) )
{
V_11 [ V_14 ] = V_16 ;
V_14 ++ ;
}
else if ( F_8 ( V_16 ) )
{
V_11 [ V_14 ] = ' ' ;
V_14 ++ ;
}
else
{
V_11 [ V_14 ] = V_18 ;
V_14 ++ ;
}
}
V_11 [ V_14 ] = '\0' ;
return V_11 ;
}
static T_5
F_10 ( T_6 V_16 )
{
return ( V_16 == '-' || V_16 == ':' || V_16 == '.' ) ;
}
T_5
F_11 ( const char * V_19 , T_7 * V_20 , T_5 V_21 )
{
T_6 V_22 ;
const T_2 * V_23 , * V_24 , * V_25 , * V_26 , * V_27 ;
char V_28 [ 3 ] ;
char V_29 [ 3 ] ;
char V_30 [ 3 ] ;
char V_31 [ 2 ] ;
if ( ! V_19 || ! V_20 ) {
return FALSE ;
}
F_12 ( V_20 , 0 ) ;
V_23 = V_19 ;
while ( * V_23 ) {
V_24 = V_23 + 1 ;
V_25 = V_23 + 2 ;
V_26 = V_23 + 3 ;
if ( * V_24 && * V_25 && * V_26
&& F_13 ( * V_23 ) && F_13 ( * V_24 ) &&
F_13 ( * V_25 ) && F_13 ( * V_26 ) ) {
V_28 [ 0 ] = * V_23 ;
V_28 [ 1 ] = * V_24 ;
V_28 [ 2 ] = '\0' ;
V_29 [ 0 ] = * V_25 ;
V_29 [ 1 ] = * V_26 ;
V_29 [ 2 ] = '\0' ;
V_22 = ( T_6 ) strtoul ( V_28 , NULL , 16 ) ;
F_14 ( V_20 , & V_22 , 1 ) ;
V_22 = ( T_6 ) strtoul ( V_29 , NULL , 16 ) ;
F_14 ( V_20 , & V_22 , 1 ) ;
V_27 = V_26 + 1 ;
if ( * V_27 ) {
if ( F_10 ( * V_27 ) ) {
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
else if ( * V_24 && F_13 ( * V_23 ) && F_13 ( * V_24 ) ) {
V_30 [ 0 ] = * V_23 ;
V_30 [ 1 ] = * V_24 ;
V_30 [ 2 ] = '\0' ;
V_22 = ( T_6 ) strtoul ( V_30 , NULL , 16 ) ;
F_14 ( V_20 , & V_22 , 1 ) ;
V_27 = V_24 + 1 ;
if ( * V_27 ) {
if ( F_10 ( * V_27 ) ) {
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
else if ( * V_24 && F_13 ( * V_23 ) && F_10 ( * V_24 ) ) {
V_31 [ 0 ] = * V_23 ;
V_31 [ 1 ] = '\0' ;
V_22 = ( T_6 ) strtoul ( V_31 , NULL , 16 ) ;
F_14 ( V_20 , & V_22 , 1 ) ;
V_23 = V_24 + 1 ;
continue;
}
else if ( ! * V_24 && F_13 ( * V_23 ) ) {
V_31 [ 0 ] = * V_23 ;
V_31 [ 1 ] = '\0' ;
V_22 = ( T_6 ) strtoul ( V_31 , NULL , 16 ) ;
F_14 ( V_20 , & V_22 , 1 ) ;
V_23 = V_24 ;
continue;
}
else {
return FALSE ;
}
}
return TRUE ;
}
static inline T_2
F_15 ( T_2 V_16 , const T_8 V_32 )
{
T_2 V_33 = - 1 ;
switch ( V_16 ) {
case ':' :
if ( V_32 & V_34 )
V_33 = V_16 ;
break;
case '-' :
if ( V_32 & V_35 )
V_33 = V_16 ;
break;
case '.' :
if ( V_32 & V_36 )
V_33 = V_16 ;
break;
case ' ' :
if ( V_32 & V_37 )
V_33 = V_16 ;
break;
case '\0' :
V_33 = 0 ;
break;
default:
if ( F_13 ( V_16 ) && ( V_32 & V_38 ) )
V_33 = 0 ;
break;
}
return V_33 ;
}
T_5
F_16 ( const T_2 * V_19 , T_7 * V_20 , const T_2 * * V_39 ,
const T_8 V_32 , const T_5 V_40 )
{
T_9 V_16 , V_41 ;
T_6 V_22 ;
const T_2 * V_42 = V_19 ;
T_5 V_33 = FALSE ;
T_2 V_43 = - 1 ;
static const T_9 V_44 [ 256 ] = {
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , 10 , 11 , 12 , 13 , 14 , 15 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , 10 , 11 , 12 , 13 , 14 , 15 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1
} ;
if ( V_20 && * V_42 && F_13 ( * V_42 ) && F_13 ( * ( V_42 + 1 ) ) ) {
V_33 = TRUE ;
V_43 = F_15 ( * ( V_42 + 2 ) , V_32 ) ;
while ( * V_42 ) {
V_16 = V_44 [ ( T_1 ) * V_42 ] ;
if ( V_16 < 0 ) {
if ( V_40 ) V_33 = FALSE ;
break;
}
++ V_42 ;
V_41 = V_44 [ ( T_1 ) * V_42 ] ;
if ( V_41 < 0 ) {
if ( V_40 ) V_33 = FALSE ;
break;
}
V_22 = ( ( T_6 ) V_16 * 16 ) + V_41 ;
F_14 ( V_20 , & V_22 , 1 ) ;
++ V_42 ;
if ( V_43 > 0 && * V_42 == V_43 && V_44 [ ( T_1 ) * ( V_42 + 1 ) ] > - 1 ) {
++ V_42 ;
} else if ( V_43 != 0 && * V_42 ) {
if ( V_40 ) V_33 = FALSE ;
break;
}
}
}
if ( ! V_33 ) {
if ( V_20 ) F_12 ( V_20 , 0 ) ;
V_42 = V_19 ;
}
if ( V_39 ) * V_39 = V_42 ;
return V_33 ;
}
T_5
F_17 ( const char * V_45 , T_7 * V_20 )
{
T_6 V_22 ;
const T_2 * V_23 ;
T_2 V_46 [ V_47 ] ;
F_12 ( V_20 , 0 ) ;
if ( ! V_45 ) {
return FALSE ;
}
V_23 = V_45 ;
while ( * V_23 ) {
if ( ! F_6 ( * V_23 ) )
return FALSE ;
if ( * V_23 == '%' ) {
V_23 ++ ;
if ( * V_23 == '\0' ) return FALSE ;
V_46 [ 0 ] = * V_23 ;
V_23 ++ ;
if ( * V_23 == '\0' ) return FALSE ;
V_46 [ 1 ] = * V_23 ;
V_46 [ 2 ] = '\0' ;
if ( ! F_13 ( V_46 [ 0 ] ) || ! F_13 ( V_46 [ 1 ] ) )
return FALSE ;
V_22 = ( T_6 ) strtoul ( V_46 , NULL , 16 ) ;
F_14 ( V_20 , & V_22 , 1 ) ;
} else {
F_14 ( V_20 , ( const T_6 * ) V_23 , 1 ) ;
}
V_23 ++ ;
}
return TRUE ;
}
T_2 *
F_18 ( T_3 * V_9 , const T_7 * V_20 , const T_2 * V_48 )
{
T_2 * V_11 = ( T_2 * ) F_4 ( V_9 , V_12 ) ;
T_8 V_13 = V_12 ;
static const T_1 * V_49 = L_1 ;
const T_1 * V_50 = V_49 ;
T_6 V_16 ;
T_8 V_14 , V_17 ;
T_5 V_51 = FALSE ;
if ( ! V_20 )
return L_2 ;
if ( V_48 )
V_50 = V_48 ;
for ( V_14 = 0 ; V_14 < V_20 -> V_10 ; V_14 ++ ) {
if ( V_14 + 2 + 1 >= V_13 ) {
V_13 *= 2 ;
V_11 = ( T_2 * ) F_5 ( V_9 , V_11 , V_13 ) ;
}
V_16 = V_20 -> V_1 [ V_14 ] ;
if ( ! F_6 ( V_16 ) || V_16 == '%' ) {
V_51 = TRUE ;
}
for ( V_17 = 0 ; V_50 [ V_17 ] ; V_17 ++ ) {
if ( V_16 == V_50 [ V_17 ] )
V_51 = TRUE ;
}
if ( ! V_51 ) {
V_11 [ V_14 ] = V_16 ;
} else {
V_11 [ V_14 ] = '%' ;
V_14 ++ ;
V_11 [ V_14 ] = V_52 [ V_16 >> 4 ] ;
V_14 ++ ;
V_11 [ V_14 ] = V_52 [ V_16 & 0xF ] ;
}
}
V_11 [ V_14 ] = '\0' ;
return V_11 ;
}
T_7 *
F_19 ( const T_7 * V_53 )
{
T_7 * V_54 ;
if ( ! V_53 )
return NULL ;
V_54 = F_20 () ;
F_14 ( V_54 , V_53 -> V_1 , V_53 -> V_10 ) ;
return V_54 ;
}
T_5
F_21 ( const char * V_55 , T_7 * V_20 )
{
return F_22 ( V_55 , V_20 , TRUE ) ;
}
T_5
F_22 ( const char * V_55 , T_7 * V_20 , T_5 V_56 )
{
T_10 V_57 , V_58 , V_59 , V_17 ;
const char * V_23 , * V_60 ;
T_6 V_61 [ V_62 ] ;
F_12 ( V_20 , 0 ) ;
V_23 = V_55 ;
V_60 = NULL ;
while ( * V_23 ) {
if ( ! F_23 ( * V_23 ) && ( * V_23 != '.' ) ) return FALSE ;
if ( * V_23 == '.' ) {
if ( V_23 == V_55 && V_56 ) return FALSE ;
if ( ! * ( V_23 + 1 ) ) return FALSE ;
if ( ( V_23 - 1 ) == V_60 ) return FALSE ;
V_60 = V_23 ;
}
V_23 ++ ;
}
if ( ! V_60 ) return FALSE ;
V_23 = V_55 ;
V_59 = V_56 ? 0 : 2 ;
if ( ! V_56 ) V_23 ++ ;
V_57 = 0 ;
while ( * V_23 ) {
V_58 = 0 ;
while ( F_23 ( * V_23 ) ) {
V_58 *= 10 ;
V_58 += * V_23 - '0' ;
V_23 ++ ;
}
if ( V_59 == 0 ) {
V_57 = V_58 ;
if ( V_57 > 2 ) return FALSE ;
} else if ( V_59 == 1 ) {
if ( ( V_57 < 2 ) && ( V_58 > 39 ) ) return FALSE ;
V_58 += 40 * V_57 ;
}
if ( V_59 ) {
V_17 = V_62 ;
do {
V_17 -- ;
V_61 [ V_17 ] = 0x80 | ( V_58 % 0x80 ) ;
V_58 >>= 7 ;
} while ( V_58 && V_17 );
V_61 [ V_62 - 1 ] &= 0x7F ;
F_14 ( V_20 , V_61 + V_17 , V_62 - V_17 ) ;
}
V_59 ++ ;
if ( * V_23 ) V_23 ++ ;
}
return TRUE ;
}
T_5
F_24 ( T_7 * V_63 , T_7 * V_64 )
{
if ( ! V_63 || ! V_64 )
return FALSE ;
if ( V_63 -> V_10 != V_64 -> V_10 )
return FALSE ;
if ( memcmp ( V_63 -> V_1 , V_64 -> V_1 , V_63 -> V_10 ) != 0 )
return FALSE ;
return TRUE ;
}
T_2 *
F_25 ( const T_2 * V_65 )
{
T_11 * V_66 = F_26 ( 128 ) ;
const T_2 * V_23 ;
T_2 V_16 ;
V_23 = V_65 ;
while ( ( V_16 = * V_23 ++ ) ) {
switch ( V_16 ) {
case '<' :
F_27 ( V_66 , L_3 ) ;
break;
case '>' :
F_27 ( V_66 , L_4 ) ;
break;
case '&' :
F_27 ( V_66 , L_5 ) ;
break;
case '\'' :
F_27 ( V_66 , L_6 ) ;
break;
case '"' :
F_27 ( V_66 , L_7 ) ;
break;
default:
F_28 ( V_66 , V_16 ) ;
break;
}
}
return F_29 ( V_66 , FALSE ) ;
}
const T_6 *
F_30 ( const T_6 * V_67 , T_8 V_68 ,
const T_6 * V_69 , T_8 V_70 )
{
const T_6 * V_71 ;
const T_6 * const V_72 = V_67 + V_68 - V_70 ;
if ( V_70 == 0 ) {
return NULL ;
}
if ( V_70 > V_68 ) {
return NULL ;
}
for ( V_71 = V_67 ; V_71 <= V_72 ; ++ V_71 ) {
if ( V_71 [ 0 ] == V_69 [ 0 ] &&
! memcmp ( & V_71 [ 1 ] , V_69 + 1 ,
V_70 - 1 ) ) {
return V_71 ;
}
}
return NULL ;
}
T_6 *
F_31 ( const char * string , T_4 * V_73 )
{
T_4 V_74 ;
const char * V_23 ;
T_2 V_16 ;
T_6 * V_20 , * V_24 , V_75 ;
V_74 = 0 ;
V_23 = & string [ 0 ] ;
for (; ; ) {
V_16 = * V_23 ++ ;
if ( V_16 == '\0' )
break;
if ( F_8 ( V_16 ) )
continue;
if ( V_16 == ':' || V_16 == '.' || V_16 == '-' )
continue;
if ( ! F_13 ( V_16 ) ) {
return NULL ;
}
V_16 = * V_23 ++ ;
if ( ! F_13 ( V_16 ) )
return NULL ;
V_74 ++ ;
}
if ( V_74 == 0 ) {
return NULL ;
}
V_20 = ( T_6 * ) F_32 ( V_74 ) ;
V_23 = & string [ 0 ] ;
V_24 = & V_20 [ 0 ] ;
for (; ; ) {
V_16 = * V_23 ++ ;
if ( V_16 == '\0' )
break;
if ( F_8 ( V_16 ) )
continue;
if ( V_16 == ':' || V_16 == '.' || V_16 == '-' )
continue;
V_75 = F_33 ( V_16 ) ;
V_75 <<= 4 ;
V_16 = * V_23 ++ ;
V_75 |= F_33 ( V_16 ) ;
* V_24 ++ = V_75 ;
}
* V_73 = V_74 ;
return V_20 ;
}
char *
F_34 ( const char * string , T_5 V_76 )
{
if ( V_76 ) {
return F_35 ( string , - 1 ) ;
} else {
return F_36 ( string ) ;
}
}
const char *
F_37 ( const char * V_67 , const char * V_69 )
{
T_12 V_77 = strlen ( V_67 ) ;
T_12 V_78 = strlen ( V_69 ) ;
while ( V_77 -- >= V_78 ) {
if ( ! F_38 ( V_67 , V_69 , V_78 ) )
return V_67 ;
V_67 ++ ;
}
return NULL ;
}
const char *
F_39 ( const char * string )
{
if ( string )
return string ;
return L_8 ;
}
int
F_40 ( const char * string )
{
const char * V_23 ;
T_2 V_16 ;
int V_79 ;
V_79 = 0 ;
for ( V_23 = string ; ( V_16 = * V_23 ) != '\0' ; V_23 ++ ) {
if ( V_16 == '\\' || V_16 == '"' ) {
V_79 += 2 ;
}
else if ( ! F_6 ( V_16 ) ) {
V_79 += 4 ;
}
else {
V_79 ++ ;
}
}
return V_79 + 2 ;
}
char *
F_41 ( char * V_61 , const char * string )
{
const T_2 * V_23 ;
T_2 V_16 ;
char * V_80 ;
char V_81 [ 3 ] ;
V_80 = V_61 ;
* V_80 ++ = '"' ;
for ( V_23 = string ; ( V_16 = * V_23 ) != '\0' ; V_23 ++ ) {
if ( V_16 == '\\' || V_16 == '"' ) {
* V_80 ++ = '\\' ;
* V_80 ++ = V_16 ;
}
else if ( ! F_6 ( V_16 ) ) {
F_42 ( V_81 , sizeof( V_81 ) , L_9 , ( unsigned char ) V_16 ) ;
* V_80 ++ = '\\' ;
* V_80 ++ = 'x' ;
* V_80 ++ = V_81 [ 0 ] ;
* V_80 ++ = V_81 [ 1 ] ;
}
else {
* V_80 ++ = V_16 ;
}
}
* V_80 ++ = '"' ;
* V_80 = '\0' ;
return V_61 ;
}
static T_13
F_43 ( unsigned char V_82 )
{
if ( V_82 < V_83 ) {
return V_84 [ V_82 ] ;
}
else {
return '?' ;
}
}
void
F_44 ( unsigned char * V_85 , const unsigned char * V_86 , int V_10 )
{
int V_17 , V_87 ;
T_13 V_61 ;
for ( V_17 = 0 , V_87 = 0 ; V_87 < V_10 ; V_87 ++ ) {
V_61 = F_43 ( V_86 [ V_87 ] ) ;
V_17 += F_45 ( V_61 , & ( V_85 [ V_17 ] ) ) ;
}
V_85 [ V_17 ] = 0 ;
return;
}
T_2 *
F_46 ( const T_2 * V_88 , const T_2 V_18 )
{
const T_2 * V_23 ;
T_2 * V_24 , * V_89 ;
if( ! V_88 )
return NULL ;
V_23 = V_88 ;
V_24 = V_89 = ( T_2 * ) F_32 ( strlen ( V_88 ) * 2 + 1 ) ;
while( * V_23 != 0 ) {
if( * V_23 == V_18 )
* V_24 ++ = V_18 ;
* V_24 ++ = * V_23 ++ ;
}
* V_24 = '\0' ;
return V_89 ;
}
T_2 *
F_47 ( const T_2 * V_88 , const char V_18 )
{
const T_2 * V_23 ;
T_2 * V_24 , * V_89 ;
if( ! V_88 )
return NULL ;
V_23 = V_88 ;
V_24 = V_89 = ( T_2 * ) F_32 ( strlen ( V_88 ) + 1 ) ;
while( * V_23 != 0 ) {
* V_24 ++ = * V_23 ;
if ( ( * V_23 == V_18 ) && ( * ( V_23 + 1 ) == V_18 ) )
V_23 += 2 ;
else
V_23 ++ ;
}
* V_24 = '\0' ;
return V_89 ;
}
T_2 *
F_48 ( const T_2 * V_88 , const T_2 * V_90 , const T_2 * V_91 )
{
T_2 * * V_92 ;
T_2 * V_89 ;
if ( ! V_88 || ! V_90 ) {
return NULL ;
}
V_92 = F_49 ( V_88 , V_90 , 0 ) ;
V_89 = F_50 ( V_91 , V_92 ) ;
F_51 ( V_92 ) ;
return V_89 ;
}
