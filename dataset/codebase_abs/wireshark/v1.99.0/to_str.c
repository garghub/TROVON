static inline char
F_1 ( T_1 V_1 )
{
static const T_2 V_2 [ 16 ] =
{ '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
return V_2 [ V_1 & 0xF ] ;
}
static inline char *
F_2 ( char * V_3 , T_3 V_4 )
{
* V_3 ++ = F_1 ( V_4 >> 4 ) ;
* V_3 ++ = F_1 ( V_4 ) ;
return V_3 ;
}
char *
F_3 ( char * V_3 , T_4 V_5 )
{
V_3 = F_2 ( V_3 , V_5 >> 8 ) ;
V_3 = F_2 ( V_3 , V_5 ) ;
return V_3 ;
}
char *
F_4 ( char * V_3 , T_4 V_5 )
{
if ( V_5 >= 0x1000 )
* V_3 ++ = F_1 ( ( T_1 ) ( V_5 >> 12 ) ) ;
if ( V_5 >= 0x0100 )
* V_3 ++ = F_1 ( ( T_1 ) ( V_5 >> 8 ) ) ;
if ( V_5 >= 0x0010 )
* V_3 ++ = F_1 ( ( T_1 ) ( V_5 >> 4 ) ) ;
* V_3 ++ = F_1 ( ( T_1 ) ( V_5 >> 0 ) ) ;
return V_3 ;
}
char *
F_5 ( char * V_3 , T_3 V_4 )
{
V_3 = F_2 ( V_3 , V_4 >> 24 ) ;
V_3 = F_2 ( V_3 , V_4 >> 16 ) ;
V_3 = F_2 ( V_3 , V_4 >> 8 ) ;
V_3 = F_2 ( V_3 , V_4 ) ;
return V_3 ;
}
char *
F_6 ( char * V_3 , T_3 V_4 , char V_6 )
{
V_3 = F_2 ( V_3 , V_4 >> 24 ) ;
* V_3 ++ = V_6 ;
V_3 = F_2 ( V_3 , V_4 >> 16 ) ;
* V_3 ++ = V_6 ;
V_3 = F_2 ( V_3 , V_4 >> 8 ) ;
* V_3 ++ = V_6 ;
V_3 = F_2 ( V_3 , V_4 ) ;
return V_3 ;
}
char *
F_7 ( char * V_3 , const T_1 * V_7 , T_3 V_8 )
{
T_3 V_9 ;
if ( ! V_7 )
F_8 ( L_1 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_3 = F_2 ( V_3 , V_7 [ V_9 ] ) ;
return V_3 ;
}
char *
F_9 ( char * V_3 , const T_1 * V_7 , T_3 V_8 , char V_6 )
{
T_3 V_9 ;
if ( ! V_7 )
F_8 ( L_2 ) ;
V_3 = F_2 ( V_3 , V_7 [ 0 ] ) ;
for ( V_9 = 1 ; V_9 < V_8 ; V_9 ++ ) {
* V_3 ++ = V_6 ;
V_3 = F_2 ( V_3 , V_7 [ V_9 ] ) ;
}
return V_3 ;
}
const T_2 *
F_10 ( const T_1 * V_7 , const T_3 V_8 , const char V_6 )
{
T_2 * V_10 ;
T_5 V_11 ;
if ( ! V_7 )
F_8 ( L_3 ) ;
if ( ( ( int ) V_8 ) < 0 )
return L_4 ;
if ( ! V_8 )
return L_4 ;
if ( V_6 )
V_11 = V_8 * 3 ;
else
V_11 = V_8 * 2 + 1 ;
V_10 = ( T_2 * ) F_11 ( V_11 ) ;
if ( V_6 )
F_9 ( V_10 , V_7 , V_8 , V_6 ) ;
else
F_7 ( V_10 , V_7 , V_8 ) ;
V_10 [ V_11 - 1 ] = '\0' ;
return V_10 ;
}
const T_2 *
F_12 ( T_6 * V_12 , const T_1 * V_7 , const T_3 V_8 , const char V_6 )
{
T_2 * V_10 ;
T_5 V_11 ;
if ( ! V_7 )
F_8 ( L_5 ) ;
if ( V_8 == 0 )
return F_13 ( V_12 , L_4 ) ;
if ( V_6 )
V_11 = V_8 * 3 ;
else
V_11 = V_8 * 2 + 1 ;
V_10 = ( T_2 * ) F_14 ( V_12 , V_11 ) ;
if ( V_6 )
F_9 ( V_10 , V_7 , V_8 , V_6 ) ;
else
F_7 ( V_10 , V_7 , V_8 ) ;
V_10 [ V_11 - 1 ] = '\0' ;
return V_10 ;
}
T_2 *
F_15 ( const T_1 * V_13 , int V_14 )
{
T_2 * V_15 ;
T_2 * V_16 ;
int V_17 = 0 ;
if ( ! V_13 )
F_8 ( L_6 ) ;
V_15 = ( T_2 * ) F_11 ( V_18 + 3 + 1 ) ;
if ( V_14 <= 0 ) { V_15 [ 0 ] = '\0' ; return V_15 ; }
if ( V_14 > V_18 / 2 ) {
V_17 = 1 ;
V_14 = V_18 / 2 ;
}
V_16 = F_7 ( V_15 , V_13 , V_14 ) ;
if ( V_17 )
V_16 = F_16 ( V_16 , L_7 ) ;
* V_16 = '\0' ;
return V_15 ;
}
T_2 *
F_17 ( const T_1 * V_13 , int V_14 , T_2 V_6 )
{
T_2 * V_15 ;
T_2 * V_16 ;
int V_17 = 0 ;
if ( ! V_6 )
return F_15 ( V_13 , V_14 ) ;
V_15 = ( T_2 * ) F_11 ( V_18 + 3 + 1 ) ;
if ( V_14 <= 0 ) { V_15 [ 0 ] = '\0' ; return V_15 ; }
if ( V_14 > V_18 / 3 ) {
V_17 = 1 ;
V_14 = V_18 / 3 ;
}
V_16 = F_9 ( V_15 , V_13 , V_14 , V_6 ) ;
if ( V_17 ) {
* V_16 ++ = V_6 ;
V_16 = F_16 ( V_16 , L_7 ) ;
}
* V_16 = '\0' ;
return V_15 ;
}
static int
F_18 ( const T_3 V_19 )
{
if ( V_19 >= 1000000000 ) return 10 ;
if ( V_19 >= 100000000 ) return 9 ;
if ( V_19 >= 10000000 ) return 8 ;
if ( V_19 >= 1000000 ) return 7 ;
if ( V_19 >= 100000 ) return 6 ;
if ( V_19 >= 10000 ) return 5 ;
if ( V_19 >= 1000 ) return 4 ;
if ( V_19 >= 100 ) return 3 ;
if ( V_19 >= 10 ) return 2 ;
return 1 ;
}
void
F_19 ( T_3 V_19 , T_2 * V_10 , int V_20 )
{
int V_21 = F_18 ( V_19 ) + 1 ;
T_2 * V_22 = & V_10 [ V_21 ] ;
if ( V_20 < V_21 ) {
F_20 ( V_10 , V_23 , V_20 ) ;
return;
}
* -- V_22 = '\0' ;
F_21 ( V_22 , V_19 ) ;
}
static void
F_22 ( T_7 V_24 , const T_3 V_25 , const T_8 V_26 ,
T_9 * V_10 )
{
int V_27 , V_28 , V_29 ;
const T_2 * V_30 = L_4 ;
T_8 V_31 = FALSE ;
if( V_24 == V_32 ) {
F_23 ( V_10 , L_8 , V_24 ) ;
return;
}
if( V_24 < 0 ) {
V_24 = - V_24 ;
V_30 = L_9 ;
}
V_29 = V_24 % 60 ;
V_24 /= 60 ;
V_28 = V_24 % 60 ;
V_24 /= 60 ;
V_27 = V_24 % 24 ;
V_24 /= 24 ;
if ( V_24 != 0 ) {
F_23 ( V_10 , L_10 , V_30 , V_24 , F_24 ( V_24 ) ) ;
V_31 = TRUE ;
V_30 = L_4 ;
}
if ( V_27 != 0 ) {
F_23 ( V_10 , L_11 , F_25 ( V_31 ) , V_30 , V_27 , F_24 ( V_27 ) ) ;
V_31 = TRUE ;
V_30 = L_4 ;
}
if ( V_28 != 0 ) {
F_23 ( V_10 , L_12 , F_25 ( V_31 ) , V_30 , V_28 , F_24 ( V_28 ) ) ;
V_31 = TRUE ;
V_30 = L_4 ;
}
if ( V_29 != 0 || V_25 != 0 ) {
if ( V_25 != 0 ) {
if ( V_26 )
F_23 ( V_10 , L_13 , F_25 ( V_31 ) , V_30 , V_29 , V_25 ) ;
else
F_23 ( V_10 , L_14 , F_25 ( V_31 ) , V_30 , V_29 , V_25 ) ;
} else
F_23 ( V_10 , L_15 , F_25 ( V_31 ) , V_30 , V_29 , F_24 ( V_29 ) ) ;
}
}
T_2 *
F_26 ( T_6 * V_12 , const T_7 V_24 )
{
T_9 * V_10 ;
if ( V_24 == 0 ) {
return F_13 ( V_12 , L_16 ) ;
}
V_10 = F_27 ( V_12 , V_33 + 1 , V_33 + 1 ) ;
F_22 ( V_24 , 0 , FALSE , V_10 ) ;
return F_28 ( V_10 ) ;
}
static void
F_29 ( T_3 V_24 , const T_3 V_25 , const T_8 V_26 ,
T_9 * V_10 )
{
int V_27 , V_28 , V_29 ;
T_8 V_31 = FALSE ;
V_29 = V_24 % 60 ;
V_24 /= 60 ;
V_28 = V_24 % 60 ;
V_24 /= 60 ;
V_27 = V_24 % 24 ;
V_24 /= 24 ;
if ( V_24 != 0 ) {
F_23 ( V_10 , L_17 , V_24 , F_24 ( V_24 ) ) ;
V_31 = TRUE ;
}
if ( V_27 != 0 ) {
F_23 ( V_10 , L_18 , F_25 ( V_31 ) , V_27 , F_24 ( V_27 ) ) ;
V_31 = TRUE ;
}
if ( V_28 != 0 ) {
F_23 ( V_10 , L_19 , F_25 ( V_31 ) , V_28 , F_24 ( V_28 ) ) ;
V_31 = TRUE ;
}
if ( V_29 != 0 || V_25 != 0 ) {
if ( V_25 != 0 ) {
if ( V_26 )
F_23 ( V_10 , L_20 , F_25 ( V_31 ) , V_29 , V_25 ) ;
else
F_23 ( V_10 , L_21 , F_25 ( V_31 ) , V_29 , V_25 ) ;
} else
F_23 ( V_10 , L_22 , F_25 ( V_31 ) , V_29 , F_24 ( V_29 ) ) ;
}
}
T_2 *
F_30 ( T_6 * V_12 , const T_3 V_24 )
{
T_9 * V_10 ;
if ( V_24 == 0 ) {
return F_13 ( V_12 , L_16 ) ;
}
V_10 = F_27 ( V_12 , V_33 + 1 , V_33 + 1 ) ;
F_29 ( V_24 , 0 , FALSE , V_10 ) ;
return F_28 ( V_10 ) ;
}
T_2 *
F_31 ( T_6 * V_12 , T_7 V_24 )
{
T_9 * V_10 ;
int V_34 ;
if ( V_24 == 0 ) {
return F_13 ( V_12 , L_16 ) ;
}
V_10 = F_27 ( V_12 , V_33 + 1 + 3 + 1 , V_33 + 1 + 3 + 1 ) ;
if ( V_24 < 0 ) {
V_24 = - V_24 ;
V_34 = V_24 % 1000 ;
V_24 /= 1000 ;
V_24 = - V_24 ;
} else {
V_34 = V_24 % 1000 ;
V_24 /= 1000 ;
}
F_22 ( V_24 , V_34 , FALSE , V_10 ) ;
return F_28 ( V_10 ) ;
}
static const T_2 *
F_32 ( struct V_35 * V_36 )
{
#if F_33 ( V_37 )
return V_36 -> V_38 ;
#else
if ( ( V_36 -> V_39 != 0 ) && ( V_36 -> V_39 != 1 ) ) {
return L_23 ;
}
# if F_33 ( V_40 )
return V_41 [ V_36 -> V_39 ] ;
# elif F_33 ( V_42 )
{
static char * V_43 [ 2 ] = { NULL , NULL } ;
if ( V_43 [ V_36 -> V_39 ] == NULL ) {
V_43 [ V_36 -> V_39 ] = F_34 ( V_44 [ V_36 -> V_39 ] , - 1 , NULL , NULL , NULL ) ;
if ( V_43 [ V_36 -> V_39 ] == NULL ) {
V_43 [ V_36 -> V_39 ] = L_23 ;
}
}
return V_43 [ V_36 -> V_39 ] ;
}
# else
return V_36 -> V_39 ? L_24 : L_25 ;
# endif
#endif
}
T_2 *
F_35 ( T_6 * V_12 , const T_10 * V_45 , const T_11 V_46 ,
T_8 V_47 )
{
struct V_35 * V_36 = NULL ;
const char * V_48 = L_23 ;
T_2 * V_10 = NULL ;
switch ( V_46 ) {
case V_49 :
case V_50 :
V_36 = gmtime ( & V_45 -> V_29 ) ;
V_48 = L_26 ;
break;
case V_51 :
V_36 = localtime ( & V_45 -> V_29 ) ;
if ( V_36 ) {
V_48 = F_32 ( V_36 ) ;
}
break;
}
if ( V_36 ) {
switch ( V_46 ) {
case V_50 :
if ( V_47 ) {
V_10 = F_36 ( V_12 ,
L_27 ,
V_36 -> V_52 + 1900 ,
V_36 -> V_53 + 1 ,
V_36 -> V_54 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
( long ) V_45 -> V_57 ,
V_48 ) ;
} else {
V_10 = F_36 ( V_12 ,
L_28 ,
V_36 -> V_52 + 1900 ,
V_36 -> V_53 + 1 ,
V_36 -> V_54 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
( long ) V_45 -> V_57 ) ;
}
break;
case V_49 :
case V_51 :
if ( V_47 ) {
V_10 = F_36 ( V_12 ,
L_29 ,
V_58 [ V_36 -> V_59 ] ,
V_36 -> V_60 ,
V_36 -> V_52 + 1900 ,
V_36 -> V_54 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
( long ) V_45 -> V_57 ,
V_48 ) ;
} else {
V_10 = F_36 ( V_12 ,
L_30 ,
V_58 [ V_36 -> V_59 ] ,
V_36 -> V_60 ,
V_36 -> V_52 + 1900 ,
V_36 -> V_54 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
( long ) V_45 -> V_57 ) ;
}
break;
}
} else
V_10 = F_13 ( V_12 , L_31 ) ;
return V_10 ;
}
T_2 *
F_37 ( T_6 * V_12 , const T_12 V_45 , const T_11 V_46 ,
T_8 V_47 )
{
struct V_35 * V_36 = NULL ;
const char * V_48 = L_23 ;
T_2 * V_10 = NULL ;
switch ( V_46 ) {
case V_49 :
case V_50 :
V_36 = gmtime ( & V_45 ) ;
V_48 = L_26 ;
break;
case V_51 :
V_36 = localtime ( & V_45 ) ;
if ( V_36 ) {
V_48 = F_32 ( V_36 ) ;
}
break;
}
if ( V_36 ) {
switch ( V_46 ) {
case V_50 :
if ( V_47 ) {
V_10 = F_36 ( V_12 ,
L_32 ,
V_36 -> V_52 + 1900 ,
V_36 -> V_53 + 1 ,
V_36 -> V_54 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_48 ) ;
} else {
V_10 = F_36 ( V_12 ,
L_33 ,
V_36 -> V_52 + 1900 ,
V_36 -> V_53 + 1 ,
V_36 -> V_54 ,
V_36 -> V_55 ,
V_36 -> V_56 ) ;
}
break;
case V_49 :
case V_51 :
if ( V_47 ) {
V_10 = F_36 ( V_12 ,
L_34 ,
V_58 [ V_36 -> V_59 ] ,
V_36 -> V_60 ,
V_36 -> V_52 + 1900 ,
V_36 -> V_54 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_48 ) ;
} else {
V_10 = F_36 ( V_12 ,
L_35 ,
V_58 [ V_36 -> V_59 ] ,
V_36 -> V_60 ,
V_36 -> V_52 + 1900 ,
V_36 -> V_54 ,
V_36 -> V_55 ,
V_36 -> V_56 ) ;
}
break;
}
} else
V_10 = F_13 ( V_12 , L_31 ) ;
return V_10 ;
}
void
F_38 ( T_2 * V_10 , int V_11 , const T_7 V_61 , T_7 V_25 ,
const T_13 V_62 )
{
T_14 V_63 [ 16 ] ;
T_14 * V_64 = & V_63 [ 16 ] ;
T_14 * V_65 ;
int V_66 ;
if ( V_11 < 1 )
return;
if ( V_25 < 0 ) {
V_25 = - V_25 ;
if ( V_61 >= 0 ) {
V_10 [ 0 ] = '-' ;
V_10 ++ ;
V_11 -- ;
}
}
V_65 = F_39 ( V_64 , V_61 ) ;
V_66 = F_40 ( ( int ) ( V_64 - V_65 ) , V_11 ) ;
memcpy ( V_10 , V_65 , V_66 ) ;
V_10 += V_66 ;
V_11 -= V_66 ;
switch ( V_62 ) {
case V_67 :
default:
V_65 = NULL ;
break;
case V_68 :
V_65 = F_41 ( V_64 , V_25 , 1 ) ;
break;
case V_69 :
V_65 = F_41 ( V_64 , V_25 , 2 ) ;
break;
case V_70 :
V_65 = F_41 ( V_64 , V_25 , 3 ) ;
break;
case V_71 :
V_65 = F_41 ( V_64 , V_25 , 6 ) ;
break;
case V_72 :
V_65 = F_41 ( V_64 , V_25 , 9 ) ;
break;
}
if ( V_65 != NULL )
{
* ( -- V_65 ) = '.' ;
V_66 = F_40 ( ( int ) ( V_64 - V_65 ) , V_11 ) ;
memcpy ( V_10 , V_65 , V_66 ) ;
V_10 += V_66 ;
V_11 -= V_66 ;
}
if ( V_11 == 0 )
V_10 -- ;
* V_10 = '\0' ;
}
void
F_42 ( T_2 * V_10 , int V_11 , const T_12 V_61 , T_7 V_25 ,
const T_13 V_62 )
{
double V_73 ;
V_73 = difftime ( V_61 , ( T_12 ) 0 ) ;
if ( V_25 < 0 ) {
V_25 = - V_25 ;
if ( V_73 >= 0 ) {
if ( V_11 < 1 ) {
return;
}
V_10 [ 0 ] = '-' ;
V_10 ++ ;
V_11 -- ;
}
}
switch ( V_62 ) {
case V_67 :
F_43 ( V_10 , V_11 , L_36 , V_73 ) ;
break;
case V_68 :
F_43 ( V_10 , V_11 , L_37 , V_73 , V_25 ) ;
break;
case V_69 :
F_43 ( V_10 , V_11 , L_38 , V_73 , V_25 ) ;
break;
case V_70 :
F_43 ( V_10 , V_11 , L_39 , V_73 , V_25 ) ;
break;
case V_71 :
F_43 ( V_10 , V_11 , L_40 , V_73 , V_25 ) ;
break;
case V_72 :
F_43 ( V_10 , V_11 , L_41 , V_73 , V_25 ) ;
break;
}
}
T_2 *
F_44 ( T_6 * V_12 , const T_10 * V_74 )
{
T_9 * V_10 ;
T_7 V_24 ;
T_7 V_75 ;
V_24 = ( V_76 ) V_74 -> V_29 ;
V_75 = V_74 -> V_57 ;
if ( V_24 == 0 && V_75 == 0 ) {
return F_13 ( V_12 , L_42 ) ;
}
V_10 = F_27 ( V_12 , 1 + V_33 + 1 + 6 + 1 , 1 + V_33 + 1 + 6 + 1 ) ;
if ( V_75 < 0 ) {
V_75 = - V_75 ;
F_45 ( V_10 , '-' ) ;
V_24 = ( V_76 ) - V_74 -> V_29 ;
}
F_22 ( V_24 , V_75 , TRUE , V_10 ) ;
return F_28 ( V_10 ) ;
}
T_2 *
F_46 ( T_6 * V_12 , const T_10 * V_74 )
{
T_2 * V_10 ;
V_10 = ( T_2 * ) F_14 ( V_12 , V_77 ) ;
F_38 ( V_10 , V_77 , ( T_7 ) V_74 -> V_29 ,
V_74 -> V_57 , V_72 ) ;
return V_10 ;
}
char *
F_47 ( const T_15 V_78 , const V_76 V_79 , const T_16 V_80 )
{
T_16 V_81 = 0 , V_36 ;
char * V_82 ;
int V_83 , V_84 = 0 ;
int V_9 ;
V_81 = 1 ;
V_81 = V_81 << ( V_79 - 1 ) ;
V_82 = ( char * ) F_48 ( 256 + 64 ) ;
for( V_83 = 0 ; V_83 < ( ( int ) ( V_78 & 0x07 ) ) ; V_83 ++ ) {
if( V_83 && ( ! ( V_83 % 4 ) ) ) {
V_82 [ V_84 ] = ' ' ;
V_84 ++ ;
}
V_82 [ V_84 ] = '.' ;
V_84 ++ ;
}
for( V_9 = 0 ; V_9 < V_79 ; V_9 ++ ) {
if( V_83 && ( ! ( V_83 % 4 ) ) ) {
V_82 [ V_84 ] = ' ' ;
V_84 ++ ;
}
if( V_83 && ( ! ( V_83 % 8 ) ) ) {
V_82 [ V_84 ] = ' ' ;
V_84 ++ ;
}
V_83 ++ ;
V_36 = V_80 & V_81 ;
if( V_36 != 0 ) {
V_82 [ V_84 ] = '1' ;
V_84 ++ ;
} else {
V_82 [ V_84 ] = '0' ;
V_84 ++ ;
}
V_81 = V_81 >> 1 ;
}
for(; V_83 % 8 ; V_83 ++ ) {
if( V_83 && ( ! ( V_83 % 4 ) ) ) {
V_82 [ V_84 ] = ' ' ;
V_84 ++ ;
}
V_82 [ V_84 ] = '.' ;
V_84 ++ ;
}
return V_82 ;
}
char *
F_49 ( char * V_10 , const T_3 V_85 , const T_3 V_81 , const int V_86 )
{
int V_9 ;
T_3 V_83 ;
char * V_87 ;
V_9 = 0 ;
V_87 = V_10 ;
V_83 = 1 << ( V_86 - 1 ) ;
for (; ; ) {
if ( V_81 & V_83 ) {
if ( V_85 & V_83 )
* V_87 ++ = '1' ;
else
* V_87 ++ = '0' ;
} else {
* V_87 ++ = '.' ;
}
V_83 >>= 1 ;
V_9 ++ ;
if ( V_9 >= V_86 )
break;
if ( V_9 % 4 == 0 )
* V_87 ++ = ' ' ;
}
* V_87 = '\0' ;
return V_87 ;
}
char *
F_50 ( char * V_10 , const T_3 V_85 , const T_3 V_81 , const int V_86 )
{
char * V_87 ;
V_87 = F_49 ( V_10 , V_85 , V_81 , V_86 ) ;
V_87 = F_16 ( V_87 , L_43 ) ;
return V_87 ;
}
const char *
F_51 ( const T_3 V_85 , const T_3 V_81 , const int V_86 ,
const char * V_46 )
{
char * V_10 ;
char * V_87 ;
int V_88 = 0 ;
V_10 = ( char * ) F_11 ( 1025 ) ;
while ( ( V_81 & ( 1 << V_88 ) ) == 0 )
V_88 ++ ;
V_87 = F_50 ( V_10 , V_85 , V_81 , V_86 ) ;
F_43 ( V_87 , ( V_89 ) ( 1025 - ( V_87 - V_10 ) ) , V_46 , ( V_85 & V_81 ) >> V_88 ) ;
return V_10 ;
}
void
F_52 ( const T_1 * V_7 , T_2 * V_10 , const int V_20 )
{
register T_2 const * V_87 ;
register T_2 * V_90 = V_10 ;
if ( V_20 < V_91 ) {
F_43 ( V_10 , V_20 , V_23 ) ;
return;
}
V_87 = V_92 [ * V_7 ++ ] ;
do {
* V_90 ++ = * V_87 ;
V_87 ++ ;
} while( * V_87 );
* V_90 ++ = '.' ;
V_87 = V_92 [ * V_7 ++ ] ;
do {
* V_90 ++ = * V_87 ;
V_87 ++ ;
} while( * V_87 );
* V_90 ++ = '.' ;
V_87 = V_92 [ * V_7 ++ ] ;
do {
* V_90 ++ = * V_87 ;
V_87 ++ ;
} while( * V_87 );
* V_90 ++ = '.' ;
V_87 = V_92 [ * V_7 ] ;
do {
* V_90 ++ = * V_87 ;
V_87 ++ ;
} while( * V_87 );
* V_90 = 0 ;
}
T_2 *
F_53 ( const T_17 * V_93 )
{
T_2 * V_10 ;
V_10 = ( T_2 * ) F_11 ( V_94 ) ;
return F_54 ( V_93 , V_10 , V_94 ) ;
}
T_2 *
F_54 ( const T_17 * V_93 , T_2 * V_10 , int V_20 )
{
char * V_95 = V_10 ;
if ( V_20 < V_94 ) {
F_20 ( V_10 , V_23 , V_20 ) ;
return V_10 ;
}
V_95 = F_5 ( V_95 , V_93 -> V_96 ) ;
* V_95 ++ = '-' ;
V_95 = F_3 ( V_95 , V_93 -> V_97 ) ;
* V_95 ++ = '-' ;
V_95 = F_3 ( V_95 , V_93 -> V_98 ) ;
* V_95 ++ = '-' ;
V_95 = F_7 ( V_95 , & V_93 -> V_99 [ 0 ] , 2 ) ;
* V_95 ++ = '-' ;
V_95 = F_7 ( V_95 , & V_93 -> V_99 [ 2 ] , 6 ) ;
* V_95 = '\0' ;
return V_10 ;
}
const T_2 *
F_55 ( T_18 type )
{
switch ( type ) {
case V_100 : return L_44 ;
case V_101 : return L_45 ;
case V_102 : return L_46 ;
case V_103 : return L_47 ;
case V_104 : return L_48 ;
case V_105 : return L_49 ;
case V_106 : return L_50 ;
case V_107 : return L_51 ;
case V_108 : return L_52 ;
case V_109 : return L_53 ;
case V_110 : return L_54 ;
case V_111 : return L_55 ;
case V_112 : return L_56 ;
case V_113 : return L_57 ;
case V_114 : return L_58 ;
case V_115 : return L_59 ;
default: return L_60 ;
}
}
char *
F_56 ( char * V_116 , T_3 V_80 )
{
while ( V_80 ) {
* ( -- V_116 ) = '0' + ( V_80 & 0x7 ) ;
V_80 >>= 3 ;
}
* ( -- V_116 ) = '0' ;
return V_116 ;
}
char *
F_57 ( char * V_116 , int V_8 , T_3 V_80 )
{
do {
* ( -- V_116 ) = F_1 ( V_80 ) ;
V_80 >>= 4 ;
V_8 -- ;
} while ( V_80 );
while ( V_8 > 0 ) {
* ( -- V_116 ) = '0' ;
V_8 -- ;
}
* ( -- V_116 ) = 'x' ;
* ( -- V_116 ) = '0' ;
return V_116 ;
}
char *
F_21 ( char * V_116 , T_3 V_80 )
{
char const * V_87 ;
if ( V_80 == 0 )
* ( -- V_116 ) = '0' ;
while ( V_80 >= 10 ) {
V_87 = V_92 [ 100 + ( V_80 % 100 ) ] ;
V_80 /= 100 ;
* ( -- V_116 ) = V_87 [ 2 ] ;
* ( -- V_116 ) = V_87 [ 1 ] ;
}
if ( V_80 )
* ( -- V_116 ) = ( V_80 ) | '0' ;
return V_116 ;
}
char *
F_41 ( char * V_116 , T_3 V_80 , int V_8 )
{
char * V_117 ;
V_117 = F_21 ( V_116 , V_80 ) ;
V_8 -= ( int ) ( V_116 - V_117 ) ;
while ( V_8 > 0 )
{
* ( -- V_117 ) = '0' ;
V_8 -- ;
}
return V_117 ;
}
char *
F_39 ( char * V_116 , T_7 V_80 )
{
if ( V_80 < 0 ) {
V_116 = F_21 ( V_116 , - V_80 ) ;
* ( -- V_116 ) = '-' ;
} else
V_116 = F_21 ( V_116 , V_80 ) ;
return V_116 ;
}
