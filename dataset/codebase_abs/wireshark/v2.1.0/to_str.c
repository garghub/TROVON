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
F_4 ( char * V_3 , T_4 V_5 , char V_6 )
{
V_3 = F_2 ( V_3 , V_5 >> 8 ) ;
* V_3 ++ = V_6 ;
V_3 = F_2 ( V_3 , V_5 ) ;
return V_3 ;
}
char *
F_5 ( char * V_3 , T_4 V_5 )
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
F_6 ( char * V_3 , T_3 V_4 )
{
V_3 = F_3 ( V_3 , V_4 >> 16 ) ;
V_3 = F_3 ( V_3 , V_4 ) ;
return V_3 ;
}
char *
F_7 ( char * V_3 , T_3 V_4 , char V_6 )
{
V_3 = F_4 ( V_3 , V_4 >> 16 , V_6 ) ;
* V_3 ++ = V_6 ;
V_3 = F_4 ( V_3 , V_4 , V_6 ) ;
return V_3 ;
}
char *
F_8 ( char * V_3 , T_5 V_7 )
{
V_3 = F_6 ( V_3 , ( T_3 ) ( V_7 >> 32 ) ) ;
V_3 = F_6 ( V_3 , ( T_3 ) ( V_7 & 0xffffffff ) ) ;
return V_3 ;
}
char *
F_9 ( char * V_3 , T_5 V_7 , char V_6 )
{
V_3 = F_7 ( V_3 , ( T_3 ) ( V_7 >> 32 ) , V_6 ) ;
* V_3 ++ = V_6 ;
V_3 = F_7 ( V_3 , ( T_3 ) ( V_7 & 0xffffffff ) , V_6 ) ;
return V_3 ;
}
char *
F_10 ( char * V_3 , const T_1 * V_8 , T_3 V_9 )
{
T_3 V_10 ;
if ( ! V_8 )
F_11 ( L_1 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
V_3 = F_2 ( V_3 , V_8 [ V_10 ] ) ;
return V_3 ;
}
char *
F_12 ( char * V_3 , const T_1 * V_8 , T_3 V_9 , char V_6 )
{
T_3 V_10 ;
if ( ! V_8 )
F_11 ( L_2 ) ;
V_3 = F_2 ( V_3 , V_8 [ 0 ] ) ;
for ( V_10 = 1 ; V_10 < V_9 ; V_10 ++ ) {
* V_3 ++ = V_6 ;
V_3 = F_2 ( V_3 , V_8 [ V_10 ] ) ;
}
return V_3 ;
}
T_2 *
F_13 ( T_6 * V_11 , const T_1 * V_8 , const T_3 V_9 , const char V_6 )
{
T_2 * V_12 ;
T_3 V_13 = V_9 ;
T_2 * V_14 ;
int V_15 = 0 ;
if ( ! V_6 )
return F_14 ( V_11 , V_8 , V_9 ) ;
if ( ! V_8 )
F_11 ( L_3 ) ;
if ( V_9 == 0 )
return F_15 ( V_11 , L_4 ) ;
V_12 = ( T_2 * ) F_16 ( V_11 , V_16 + 3 + 1 ) ;
if ( V_13 > V_16 / 3 ) {
V_15 = 1 ;
V_13 = V_16 / 3 ;
}
V_14 = F_12 ( V_12 , V_8 , V_13 , V_6 ) ;
if ( V_15 ) {
* V_14 ++ = V_6 ;
V_14 = F_17 ( V_14 , L_5 ) ;
}
* V_14 = '\0' ;
return V_12 ;
}
char *
F_14 ( T_6 * V_11 , const T_1 * V_17 , int V_18 )
{
T_2 * V_19 ;
T_2 * V_20 ;
int V_15 = 0 ;
if ( ! V_17 )
F_11 ( L_6 ) ;
V_19 = ( T_2 * ) F_16 ( V_11 , V_16 + 3 + 1 ) ;
if ( V_18 <= 0 ) { V_19 [ 0 ] = '\0' ; return V_19 ; }
if ( V_18 > V_16 / 2 ) {
V_15 = 1 ;
V_18 = V_16 / 2 ;
}
V_20 = F_10 ( V_19 , V_17 , V_18 ) ;
if ( V_15 )
V_20 = F_17 ( V_20 , L_5 ) ;
* V_20 = '\0' ;
return V_19 ;
}
static int
F_18 ( const T_3 V_21 )
{
if ( V_21 >= 1000000000 ) return 10 ;
if ( V_21 >= 100000000 ) return 9 ;
if ( V_21 >= 10000000 ) return 8 ;
if ( V_21 >= 1000000 ) return 7 ;
if ( V_21 >= 100000 ) return 6 ;
if ( V_21 >= 10000 ) return 5 ;
if ( V_21 >= 1000 ) return 4 ;
if ( V_21 >= 100 ) return 3 ;
if ( V_21 >= 10 ) return 2 ;
return 1 ;
}
static int
F_19 ( const T_5 V_21 )
{
if ( V_21 >= F_20 ( 10000000000000000000 ) ) return 20 ;
if ( V_21 >= F_20 ( 1000000000000000000 ) ) return 19 ;
if ( V_21 >= F_20 ( 100000000000000000 ) ) return 18 ;
if ( V_21 >= F_20 ( 10000000000000000 ) ) return 17 ;
if ( V_21 >= F_20 ( 1000000000000000 ) ) return 16 ;
if ( V_21 >= F_20 ( 100000000000000 ) ) return 15 ;
if ( V_21 >= F_20 ( 10000000000000 ) ) return 14 ;
if ( V_21 >= F_20 ( 1000000000000 ) ) return 13 ;
if ( V_21 >= F_20 ( 100000000000 ) ) return 12 ;
if ( V_21 >= F_20 ( 10000000000 ) ) return 11 ;
if ( V_21 >= F_20 ( 1000000000 ) ) return 10 ;
if ( V_21 >= F_20 ( 100000000 ) ) return 9 ;
if ( V_21 >= F_20 ( 10000000 ) ) return 8 ;
if ( V_21 >= F_20 ( 1000000 ) ) return 7 ;
if ( V_21 >= F_20 ( 100000 ) ) return 6 ;
if ( V_21 >= F_20 ( 10000 ) ) return 5 ;
if ( V_21 >= F_20 ( 1000 ) ) return 4 ;
if ( V_21 >= F_20 ( 100 ) ) return 3 ;
if ( V_21 >= F_20 ( 10 ) ) return 2 ;
return 1 ;
}
void
F_21 ( T_3 V_21 , T_2 * V_12 , int V_22 )
{
int V_23 = F_18 ( V_21 ) + 1 ;
T_2 * V_24 = & V_12 [ V_23 ] ;
if ( V_22 < V_23 ) {
F_22 ( V_12 , V_25 , V_22 ) ;
return;
}
* -- V_24 = '\0' ;
F_23 ( V_24 , V_21 ) ;
}
void
F_24 ( T_5 V_21 , T_2 * V_12 , int V_22 )
{
int V_23 = F_19 ( V_21 ) + 1 ;
T_2 * V_24 = & V_12 [ V_23 ] ;
if ( V_22 < V_23 ) {
F_22 ( V_12 , V_25 , V_22 ) ;
return;
}
* -- V_24 = '\0' ;
F_25 ( V_24 , V_21 ) ;
}
static const T_2 *
F_26 ( struct V_26 * V_27 )
{
#if F_27 ( V_28 )
return V_27 -> V_29 ;
#else
if ( ( V_27 -> V_30 != 0 ) && ( V_27 -> V_30 != 1 ) ) {
return L_7 ;
}
# if F_27 ( V_31 )
return V_32 [ V_27 -> V_30 ] ;
# elif F_27 ( V_33 )
{
static char * V_34 [ 2 ] = { NULL , NULL } ;
if ( V_34 [ V_27 -> V_30 ] == NULL ) {
V_34 [ V_27 -> V_30 ] = F_28 ( V_35 [ V_27 -> V_30 ] , - 1 , NULL , NULL , NULL ) ;
if ( V_34 [ V_27 -> V_30 ] == NULL ) {
V_34 [ V_27 -> V_30 ] = L_7 ;
}
}
return V_34 [ V_27 -> V_30 ] ;
}
# else
return V_27 -> V_30 ? L_8 : L_9 ;
# endif
#endif
}
T_2 *
F_29 ( T_6 * V_11 , const T_7 * V_36 , const T_8 V_37 ,
T_9 V_38 )
{
struct V_26 * V_27 = NULL ;
const char * V_39 = L_7 ;
T_2 * V_12 = NULL ;
switch ( V_37 ) {
case V_40 :
case V_41 :
V_27 = gmtime ( & V_36 -> V_42 ) ;
V_39 = L_10 ;
break;
case V_43 :
V_27 = localtime ( & V_36 -> V_42 ) ;
if ( V_27 ) {
V_39 = F_26 ( V_27 ) ;
}
break;
}
if ( V_27 ) {
switch ( V_37 ) {
case V_41 :
if ( V_38 ) {
V_12 = F_30 ( V_11 ,
L_11 ,
V_27 -> V_44 + 1900 ,
V_27 -> V_45 + 1 ,
V_27 -> V_46 ,
V_27 -> V_47 ,
V_27 -> V_48 ,
( long ) V_36 -> V_49 ,
V_39 ) ;
} else {
V_12 = F_30 ( V_11 ,
L_12 ,
V_27 -> V_44 + 1900 ,
V_27 -> V_45 + 1 ,
V_27 -> V_46 ,
V_27 -> V_47 ,
V_27 -> V_48 ,
( long ) V_36 -> V_49 ) ;
}
break;
case V_40 :
case V_43 :
if ( V_38 ) {
V_12 = F_30 ( V_11 ,
L_13 ,
V_50 [ V_27 -> V_51 ] ,
V_27 -> V_52 ,
V_27 -> V_44 + 1900 ,
V_27 -> V_46 ,
V_27 -> V_47 ,
V_27 -> V_48 ,
( long ) V_36 -> V_49 ,
V_39 ) ;
} else {
V_12 = F_30 ( V_11 ,
L_14 ,
V_50 [ V_27 -> V_51 ] ,
V_27 -> V_52 ,
V_27 -> V_44 + 1900 ,
V_27 -> V_46 ,
V_27 -> V_47 ,
V_27 -> V_48 ,
( long ) V_36 -> V_49 ) ;
}
break;
}
} else
V_12 = F_15 ( V_11 , L_15 ) ;
return V_12 ;
}
T_2 *
F_31 ( T_6 * V_11 , const T_10 V_36 , const T_8 V_37 ,
T_9 V_38 )
{
struct V_26 * V_27 = NULL ;
const char * V_39 = L_7 ;
T_2 * V_12 = NULL ;
switch ( V_37 ) {
case V_40 :
case V_41 :
V_27 = gmtime ( & V_36 ) ;
V_39 = L_10 ;
break;
case V_43 :
V_27 = localtime ( & V_36 ) ;
if ( V_27 ) {
V_39 = F_26 ( V_27 ) ;
}
break;
}
if ( V_27 ) {
switch ( V_37 ) {
case V_41 :
if ( V_38 ) {
V_12 = F_30 ( V_11 ,
L_16 ,
V_27 -> V_44 + 1900 ,
V_27 -> V_45 + 1 ,
V_27 -> V_46 ,
V_27 -> V_47 ,
V_27 -> V_48 ,
V_39 ) ;
} else {
V_12 = F_30 ( V_11 ,
L_17 ,
V_27 -> V_44 + 1900 ,
V_27 -> V_45 + 1 ,
V_27 -> V_46 ,
V_27 -> V_47 ,
V_27 -> V_48 ) ;
}
break;
case V_40 :
case V_43 :
if ( V_38 ) {
V_12 = F_30 ( V_11 ,
L_18 ,
V_50 [ V_27 -> V_51 ] ,
V_27 -> V_52 ,
V_27 -> V_44 + 1900 ,
V_27 -> V_46 ,
V_27 -> V_47 ,
V_27 -> V_48 ,
V_39 ) ;
} else {
V_12 = F_30 ( V_11 ,
L_19 ,
V_50 [ V_27 -> V_51 ] ,
V_27 -> V_52 ,
V_27 -> V_44 + 1900 ,
V_27 -> V_46 ,
V_27 -> V_47 ,
V_27 -> V_48 ) ;
}
break;
}
} else
V_12 = F_15 ( V_11 , L_15 ) ;
return V_12 ;
}
void
F_32 ( T_2 * V_12 , int V_13 , const T_10 V_53 , T_11 V_54 ,
const T_12 V_55 )
{
double V_56 ;
V_56 = difftime ( V_53 , ( T_10 ) 0 ) ;
if ( V_54 < 0 ) {
V_54 = - V_54 ;
if ( V_56 >= 0 ) {
if ( V_13 < 1 ) {
return;
}
V_12 [ 0 ] = '-' ;
V_12 ++ ;
V_13 -- ;
}
}
switch ( V_55 ) {
case V_57 :
F_33 ( V_12 , V_13 , L_20 , V_56 ) ;
break;
case V_58 :
F_33 ( V_12 , V_13 , L_21 , V_56 , V_54 ) ;
break;
case V_59 :
F_33 ( V_12 , V_13 , L_22 , V_56 , V_54 ) ;
break;
case V_60 :
F_33 ( V_12 , V_13 , L_23 , V_56 , V_54 ) ;
break;
case V_61 :
F_33 ( V_12 , V_13 , L_24 , V_56 , V_54 ) ;
break;
case V_62 :
F_33 ( V_12 , V_13 , L_25 , V_56 , V_54 ) ;
break;
}
}
void
F_34 ( T_2 * V_12 , int V_13 , const T_11 V_53 , T_11 V_54 ,
const T_12 V_55 )
{
T_13 V_63 [ 16 ] ;
T_13 * V_64 = & V_63 [ 16 ] ;
T_13 * V_65 ;
int V_66 ;
if ( V_13 < 1 )
return;
if ( V_54 < 0 ) {
V_54 = - V_54 ;
if ( V_53 >= 0 ) {
V_12 [ 0 ] = '-' ;
V_12 ++ ;
V_13 -- ;
}
}
V_65 = F_35 ( V_64 , V_53 ) ;
V_66 = F_36 ( ( int ) ( V_64 - V_65 ) , V_13 ) ;
memcpy ( V_12 , V_65 , V_66 ) ;
V_12 += V_66 ;
V_13 -= V_66 ;
switch ( V_55 ) {
case V_57 :
default:
V_65 = NULL ;
break;
case V_58 :
V_65 = F_37 ( V_64 , V_54 , 1 ) ;
break;
case V_59 :
V_65 = F_37 ( V_64 , V_54 , 2 ) ;
break;
case V_60 :
V_65 = F_37 ( V_64 , V_54 , 3 ) ;
break;
case V_61 :
V_65 = F_37 ( V_64 , V_54 , 6 ) ;
break;
case V_62 :
V_65 = F_37 ( V_64 , V_54 , 9 ) ;
break;
}
if ( V_65 != NULL )
{
* ( -- V_65 ) = '.' ;
V_66 = F_36 ( ( int ) ( V_64 - V_65 ) , V_13 ) ;
memcpy ( V_12 , V_65 , V_66 ) ;
V_12 += V_66 ;
V_13 -= V_66 ;
}
if ( V_13 == 0 )
V_12 -- ;
* V_12 = '\0' ;
}
static void
F_38 ( T_3 V_67 , const T_3 V_54 ,
const T_9 V_68 , T_14 * V_12 )
{
int V_69 , V_70 , V_42 ;
T_9 V_71 = FALSE ;
V_42 = V_67 % 60 ;
V_67 /= 60 ;
V_70 = V_67 % 60 ;
V_67 /= 60 ;
V_69 = V_67 % 24 ;
V_67 /= 24 ;
if ( V_67 != 0 ) {
F_39 ( V_12 , L_26 , V_67 , F_40 ( V_67 ) ) ;
V_71 = TRUE ;
}
if ( V_69 != 0 ) {
F_39 ( V_12 , L_27 , F_41 ( V_71 ) , V_69 , F_40 ( V_69 ) ) ;
V_71 = TRUE ;
}
if ( V_70 != 0 ) {
F_39 ( V_12 , L_28 , F_41 ( V_71 ) , V_70 , F_40 ( V_70 ) ) ;
V_71 = TRUE ;
}
if ( V_42 != 0 || V_54 != 0 ) {
if ( V_54 != 0 ) {
if ( V_68 )
F_39 ( V_12 , L_29 , F_41 ( V_71 ) , V_42 , V_54 ) ;
else
F_39 ( V_12 , L_30 , F_41 ( V_71 ) , V_42 , V_54 ) ;
} else
F_39 ( V_12 , L_31 , F_41 ( V_71 ) , V_42 , F_40 ( V_42 ) ) ;
}
}
T_2 *
F_42 ( T_6 * V_11 , const T_3 V_67 )
{
T_14 * V_12 ;
if ( V_67 == 0 ) {
return F_15 ( V_11 , L_32 ) ;
}
V_12 = F_43 ( V_11 , V_72 + 1 , V_72 + 1 ) ;
F_38 ( V_67 , 0 , FALSE , V_12 ) ;
return F_44 ( V_12 ) ;
}
static void
F_45 ( T_11 V_67 , const T_3 V_54 ,
const T_9 V_68 , T_14 * V_12 )
{
if( V_67 < 0 ) {
F_39 ( V_12 , L_33 ) ;
if( V_67 == V_73 ) {
F_38 ( V_74 , V_54 ,
V_68 , V_12 ) ;
} else {
F_38 ( - V_67 , V_54 ,
V_68 , V_12 ) ;
}
} else
F_38 ( V_67 , V_54 , V_68 , V_12 ) ;
}
T_2 *
F_46 ( T_6 * V_11 , const T_11 V_67 )
{
T_14 * V_12 ;
if ( V_67 == 0 ) {
return F_15 ( V_11 , L_32 ) ;
}
V_12 = F_43 ( V_11 , V_72 + 1 , V_72 + 1 ) ;
F_45 ( V_67 , 0 , FALSE , V_12 ) ;
return F_44 ( V_12 ) ;
}
T_2 *
F_47 ( T_6 * V_11 , T_11 V_67 )
{
T_14 * V_12 ;
int V_75 ;
if ( V_67 == 0 ) {
return F_15 ( V_11 , L_32 ) ;
}
V_12 = F_43 ( V_11 , V_72 + 1 + 3 + 1 , V_72 + 1 + 3 + 1 ) ;
if ( V_67 < 0 ) {
V_67 = - V_67 ;
V_75 = V_67 % 1000 ;
V_67 /= 1000 ;
V_67 = - V_67 ;
} else {
V_75 = V_67 % 1000 ;
V_67 /= 1000 ;
}
F_45 ( V_67 , V_75 , FALSE , V_12 ) ;
return F_44 ( V_12 ) ;
}
T_2 *
F_48 ( T_6 * V_11 , const T_7 * V_76 )
{
T_14 * V_12 ;
T_11 V_67 ;
T_11 V_77 ;
V_67 = ( V_78 ) V_76 -> V_42 ;
V_77 = V_76 -> V_49 ;
if ( V_67 == 0 && V_77 == 0 ) {
return F_15 ( V_11 , L_34 ) ;
}
V_12 = F_43 ( V_11 , 1 + V_72 + 1 + 6 + 1 , 1 + V_72 + 1 + 6 + 1 ) ;
if ( V_77 < 0 ) {
V_77 = - V_77 ;
F_49 ( V_12 , '-' ) ;
V_67 = ( V_78 ) - V_76 -> V_42 ;
}
F_45 ( V_67 , V_77 , TRUE , V_12 ) ;
return F_44 ( V_12 ) ;
}
T_2 *
F_50 ( T_6 * V_11 , const T_7 * V_76 )
{
T_2 * V_12 ;
V_12 = ( T_2 * ) F_16 ( V_11 , V_79 ) ;
F_34 ( V_12 , V_79 , ( T_11 ) V_76 -> V_42 ,
V_76 -> V_49 , V_62 ) ;
return V_12 ;
}
char *
F_51 ( const T_15 V_80 , const V_78 V_81 , const T_5 V_82 )
{
T_5 V_83 = 0 , V_27 ;
char * V_84 ;
int V_85 , V_86 = 0 ;
int V_10 ;
V_83 = 1 ;
V_83 = V_83 << ( V_81 - 1 ) ;
V_84 = ( char * ) F_52 ( F_53 () , 256 + 64 ) ;
for( V_85 = 0 ; V_85 < ( ( int ) ( V_80 & 0x07 ) ) ; V_85 ++ ) {
if( V_85 && ( ! ( V_85 % 4 ) ) ) {
V_84 [ V_86 ] = ' ' ;
V_86 ++ ;
}
V_84 [ V_86 ] = '.' ;
V_86 ++ ;
}
for( V_10 = 0 ; V_10 < V_81 ; V_10 ++ ) {
if( V_85 && ( ! ( V_85 % 4 ) ) ) {
V_84 [ V_86 ] = ' ' ;
V_86 ++ ;
}
if( V_85 && ( ! ( V_85 % 8 ) ) ) {
V_84 [ V_86 ] = ' ' ;
V_86 ++ ;
}
V_85 ++ ;
V_27 = V_82 & V_83 ;
if( V_27 != 0 ) {
V_84 [ V_86 ] = '1' ;
V_86 ++ ;
} else {
V_84 [ V_86 ] = '0' ;
V_86 ++ ;
}
V_83 = V_83 >> 1 ;
}
for(; V_85 % 8 ; V_85 ++ ) {
if( V_85 && ( ! ( V_85 % 4 ) ) ) {
V_84 [ V_86 ] = ' ' ;
V_86 ++ ;
}
V_84 [ V_86 ] = '.' ;
V_86 ++ ;
}
return V_84 ;
}
void
F_54 ( const T_1 * V_8 , T_2 * V_12 , const int V_22 )
{
register T_2 const * V_87 ;
register T_2 * V_88 = V_12 ;
if ( V_22 < V_89 ) {
F_22 ( V_12 , V_25 , V_22 ) ;
return;
}
V_87 = V_90 [ * V_8 ++ ] ;
do {
* V_88 ++ = * V_87 ;
V_87 ++ ;
} while( * V_87 );
* V_88 ++ = '.' ;
V_87 = V_90 [ * V_8 ++ ] ;
do {
* V_88 ++ = * V_87 ;
V_87 ++ ;
} while( * V_87 );
* V_88 ++ = '.' ;
V_87 = V_90 [ * V_8 ++ ] ;
do {
* V_88 ++ = * V_87 ;
V_87 ++ ;
} while( * V_87 );
* V_88 ++ = '.' ;
V_87 = V_90 [ * V_8 ] ;
do {
* V_88 ++ = * V_87 ;
V_87 ++ ;
} while( * V_87 );
* V_88 = 0 ;
}
void
F_55 ( const struct V_91 * V_8 , T_2 * V_12 , int V_22 )
{
if ( V_22 < V_92 ) {
F_22 ( V_12 , V_25 , V_22 ) ;
return;
}
F_56 ( V_8 , V_12 , V_22 ) ;
}
T_2 *
F_57 ( T_6 * V_11 , const T_16 * V_93 )
{
T_2 * V_12 ;
V_12 = ( T_2 * ) F_16 ( V_11 , V_94 ) ;
return F_58 ( V_93 , V_12 , V_94 ) ;
}
T_2 *
F_58 ( const T_16 * V_93 , T_2 * V_12 , int V_22 )
{
char * V_95 = V_12 ;
if ( V_22 < V_94 ) {
F_22 ( V_12 , V_25 , V_22 ) ;
return V_12 ;
}
V_95 = F_6 ( V_95 , V_93 -> V_96 ) ;
* V_95 ++ = '-' ;
V_95 = F_3 ( V_95 , V_93 -> V_97 ) ;
* V_95 ++ = '-' ;
V_95 = F_3 ( V_95 , V_93 -> V_98 ) ;
* V_95 ++ = '-' ;
V_95 = F_10 ( V_95 , & V_93 -> V_99 [ 0 ] , 2 ) ;
* V_95 ++ = '-' ;
V_95 = F_10 ( V_95 , & V_93 -> V_99 [ 2 ] , 6 ) ;
* V_95 = '\0' ;
return V_12 ;
}
T_2 *
F_59 ( T_6 * V_11 , const T_5 V_8 ) {
T_2 * V_12 , * V_27 ;
T_1 * V_100 ;
V_100 = ( T_1 * ) F_16 ( NULL , 8 ) ;
V_12 = ( T_2 * ) F_16 ( V_11 , V_101 ) ;
* ( T_5 * ) ( void * ) ( V_100 ) = F_60 ( & ( V_8 ) ) ;
V_27 = F_12 ( V_12 , V_100 , 8 , ':' ) ;
* V_27 = '\0' ;
F_61 ( NULL , V_100 ) ;
return V_12 ;
}
const T_2 *
F_62 ( T_17 type )
{
switch ( type ) {
case V_102 : return L_35 ;
case V_103 : return L_36 ;
case V_104 : return L_37 ;
case V_105 : return L_38 ;
case V_106 : return L_39 ;
case V_107 : return L_40 ;
case V_108 : return L_41 ;
case V_109 : return L_42 ;
case V_110 : return L_43 ;
case V_111 : return L_44 ;
case V_112 : return L_45 ;
case V_113 : return L_46 ;
case V_114 : return L_47 ;
case V_115 : return L_48 ;
case V_116 : return L_49 ;
case V_117 : return L_50 ;
case V_118 : return L_51 ;
default: return L_52 ;
}
}
char *
F_63 ( char * V_119 , T_3 V_82 )
{
while ( V_82 ) {
* ( -- V_119 ) = '0' + ( V_82 & 0x7 ) ;
V_82 >>= 3 ;
}
* ( -- V_119 ) = '0' ;
return V_119 ;
}
char *
F_64 ( char * V_119 , T_5 V_82 )
{
while ( V_82 ) {
* ( -- V_119 ) = '0' + ( V_82 & 0x7 ) ;
V_82 >>= 3 ;
}
* ( -- V_119 ) = '0' ;
return V_119 ;
}
char *
F_65 ( char * V_119 , int V_9 , T_3 V_82 )
{
do {
* ( -- V_119 ) = F_1 ( V_82 ) ;
V_82 >>= 4 ;
V_9 -- ;
} while ( V_82 );
while ( V_9 > 0 ) {
* ( -- V_119 ) = '0' ;
V_9 -- ;
}
* ( -- V_119 ) = 'x' ;
* ( -- V_119 ) = '0' ;
return V_119 ;
}
char *
F_66 ( char * V_119 , int V_9 , T_5 V_82 )
{
do {
* ( -- V_119 ) = F_1 ( V_82 & 0xF ) ;
V_82 >>= 4 ;
V_9 -- ;
} while ( V_82 );
while ( V_9 > 0 ) {
* ( -- V_119 ) = '0' ;
V_9 -- ;
}
* ( -- V_119 ) = 'x' ;
* ( -- V_119 ) = '0' ;
return V_119 ;
}
char *
F_23 ( char * V_119 , T_3 V_82 )
{
char const * V_87 ;
if ( V_82 == 0 )
* ( -- V_119 ) = '0' ;
while ( V_82 >= 10 ) {
V_87 = V_90 [ 100 + ( V_82 % 100 ) ] ;
V_82 /= 100 ;
* ( -- V_119 ) = V_87 [ 2 ] ;
* ( -- V_119 ) = V_87 [ 1 ] ;
}
if ( V_82 )
* ( -- V_119 ) = ( V_82 ) | '0' ;
return V_119 ;
}
char *
F_25 ( char * V_119 , T_5 V_82 )
{
char const * V_87 ;
if ( V_82 == 0 )
* ( -- V_119 ) = '0' ;
while ( V_82 >= 10 ) {
V_87 = V_90 [ 100 + ( V_82 % 100 ) ] ;
V_82 /= 100 ;
* ( -- V_119 ) = V_87 [ 2 ] ;
* ( -- V_119 ) = V_87 [ 1 ] ;
}
if ( V_82 )
* ( -- V_119 ) = ( V_82 & 0xF ) | '0' ;
return V_119 ;
}
char *
F_37 ( char * V_119 , T_3 V_82 , int V_9 )
{
char * V_120 ;
V_120 = F_23 ( V_119 , V_82 ) ;
V_9 -= ( int ) ( V_119 - V_120 ) ;
while ( V_9 > 0 )
{
* ( -- V_120 ) = '0' ;
V_9 -- ;
}
return V_120 ;
}
char *
F_67 ( char * V_119 , T_5 V_82 , int V_9 )
{
char * V_120 ;
V_120 = F_25 ( V_119 , V_82 ) ;
V_9 -= ( int ) ( V_119 - V_120 ) ;
while ( V_9 > 0 )
{
* ( -- V_120 ) = '0' ;
V_9 -- ;
}
return V_120 ;
}
char *
F_35 ( char * V_119 , T_11 V_82 )
{
if ( V_82 < 0 ) {
V_119 = F_23 ( V_119 , - V_82 ) ;
* ( -- V_119 ) = '-' ;
} else
V_119 = F_23 ( V_119 , V_82 ) ;
return V_119 ;
}
char *
F_68 ( char * V_119 , T_18 V_82 )
{
if ( V_82 < 0 ) {
V_119 = F_25 ( V_119 , - V_82 ) ;
* ( -- V_119 ) = '-' ;
} else
V_119 = F_25 ( V_119 , V_82 ) ;
return V_119 ;
}
