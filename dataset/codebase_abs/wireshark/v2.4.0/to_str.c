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
F_3 ( char * V_3 , T_1 V_5 )
{
return F_2 ( V_3 , V_5 ) ;
}
char *
F_4 ( char * V_3 , T_4 V_6 )
{
V_3 = F_2 ( V_3 , V_6 >> 8 ) ;
V_3 = F_2 ( V_3 , V_6 ) ;
return V_3 ;
}
char *
F_5 ( char * V_3 , T_4 V_6 , char V_7 )
{
V_3 = F_2 ( V_3 , V_6 >> 8 ) ;
* V_3 ++ = V_7 ;
V_3 = F_2 ( V_3 , V_6 ) ;
return V_3 ;
}
char *
F_6 ( char * V_3 , T_4 V_6 )
{
if ( V_6 >= 0x1000 )
* V_3 ++ = F_1 ( ( T_1 ) ( V_6 >> 12 ) ) ;
if ( V_6 >= 0x0100 )
* V_3 ++ = F_1 ( ( T_1 ) ( V_6 >> 8 ) ) ;
if ( V_6 >= 0x0010 )
* V_3 ++ = F_1 ( ( T_1 ) ( V_6 >> 4 ) ) ;
* V_3 ++ = F_1 ( ( T_1 ) ( V_6 >> 0 ) ) ;
return V_3 ;
}
char *
F_7 ( char * V_3 , T_3 V_4 )
{
V_3 = F_4 ( V_3 , V_4 >> 16 ) ;
V_3 = F_4 ( V_3 , V_4 ) ;
return V_3 ;
}
char *
F_8 ( char * V_3 , T_3 V_4 , char V_7 )
{
V_3 = F_5 ( V_3 , V_4 >> 16 , V_7 ) ;
* V_3 ++ = V_7 ;
V_3 = F_5 ( V_3 , V_4 , V_7 ) ;
return V_3 ;
}
char *
F_9 ( char * V_3 , T_5 V_8 )
{
V_3 = F_7 ( V_3 , ( T_3 ) ( V_8 >> 32 ) ) ;
V_3 = F_7 ( V_3 , ( T_3 ) ( V_8 & 0xffffffff ) ) ;
return V_3 ;
}
char *
F_10 ( char * V_3 , T_5 V_8 , char V_7 )
{
V_3 = F_8 ( V_3 , ( T_3 ) ( V_8 >> 32 ) , V_7 ) ;
* V_3 ++ = V_7 ;
V_3 = F_8 ( V_3 , ( T_3 ) ( V_8 & 0xffffffff ) , V_7 ) ;
return V_3 ;
}
char *
F_11 ( char * V_3 , const T_1 * V_9 , T_3 V_10 )
{
T_3 V_11 ;
if ( ! V_9 )
F_12 ( L_1 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
V_3 = F_2 ( V_3 , V_9 [ V_11 ] ) ;
return V_3 ;
}
char *
F_13 ( char * V_3 , const T_1 * V_9 , T_3 V_10 , char V_7 )
{
T_3 V_11 ;
if ( ! V_9 )
F_12 ( L_2 ) ;
V_3 = F_2 ( V_3 , V_9 [ 0 ] ) ;
for ( V_11 = 1 ; V_11 < V_10 ; V_11 ++ ) {
* V_3 ++ = V_7 ;
V_3 = F_2 ( V_3 , V_9 [ V_11 ] ) ;
}
return V_3 ;
}
T_2 *
F_14 ( T_6 * V_12 , const T_1 * V_9 , const T_3 V_10 , const char V_7 )
{
T_2 * V_13 ;
T_3 V_14 = V_10 ;
T_2 * V_15 ;
int V_16 = 0 ;
if ( ! V_7 )
return F_15 ( V_12 , V_9 , V_10 ) ;
if ( ! V_9 )
F_12 ( L_3 ) ;
if ( V_10 == 0 )
return F_16 ( V_12 , L_4 ) ;
V_13 = ( T_2 * ) F_17 ( V_12 , V_17 + 3 + 1 ) ;
if ( V_14 > V_17 / 3 ) {
V_16 = 1 ;
V_14 = V_17 / 3 ;
}
V_15 = F_13 ( V_13 , V_9 , V_14 , V_7 ) ;
if ( V_16 ) {
* V_15 ++ = V_7 ;
V_15 = F_18 ( V_15 , L_5 ) ;
}
* V_15 = '\0' ;
return V_13 ;
}
char *
F_15 ( T_6 * V_12 , const T_1 * V_18 , int V_19 )
{
T_2 * V_20 ;
T_2 * V_21 ;
int V_16 = 0 ;
if ( ! V_18 )
F_12 ( L_6 ) ;
V_20 = ( T_2 * ) F_17 ( V_12 , V_17 + 3 + 1 ) ;
if ( V_19 <= 0 ) { V_20 [ 0 ] = '\0' ; return V_20 ; }
if ( V_19 > V_17 / 2 ) {
V_16 = 1 ;
V_19 = V_17 / 2 ;
}
V_21 = F_11 ( V_20 , V_18 , V_19 ) ;
if ( V_16 )
V_21 = F_18 ( V_21 , L_5 ) ;
* V_21 = '\0' ;
return V_20 ;
}
static int
F_19 ( const T_3 V_22 )
{
if ( V_22 >= 1000000000 ) return 10 ;
if ( V_22 >= 100000000 ) return 9 ;
if ( V_22 >= 10000000 ) return 8 ;
if ( V_22 >= 1000000 ) return 7 ;
if ( V_22 >= 100000 ) return 6 ;
if ( V_22 >= 10000 ) return 5 ;
if ( V_22 >= 1000 ) return 4 ;
if ( V_22 >= 100 ) return 3 ;
if ( V_22 >= 10 ) return 2 ;
return 1 ;
}
static int
F_20 ( const T_5 V_22 )
{
if ( V_22 >= F_21 ( 10000000000000000000 ) ) return 20 ;
if ( V_22 >= F_21 ( 1000000000000000000 ) ) return 19 ;
if ( V_22 >= F_21 ( 100000000000000000 ) ) return 18 ;
if ( V_22 >= F_21 ( 10000000000000000 ) ) return 17 ;
if ( V_22 >= F_21 ( 1000000000000000 ) ) return 16 ;
if ( V_22 >= F_21 ( 100000000000000 ) ) return 15 ;
if ( V_22 >= F_21 ( 10000000000000 ) ) return 14 ;
if ( V_22 >= F_21 ( 1000000000000 ) ) return 13 ;
if ( V_22 >= F_21 ( 100000000000 ) ) return 12 ;
if ( V_22 >= F_21 ( 10000000000 ) ) return 11 ;
if ( V_22 >= F_21 ( 1000000000 ) ) return 10 ;
if ( V_22 >= F_21 ( 100000000 ) ) return 9 ;
if ( V_22 >= F_21 ( 10000000 ) ) return 8 ;
if ( V_22 >= F_21 ( 1000000 ) ) return 7 ;
if ( V_22 >= F_21 ( 100000 ) ) return 6 ;
if ( V_22 >= F_21 ( 10000 ) ) return 5 ;
if ( V_22 >= F_21 ( 1000 ) ) return 4 ;
if ( V_22 >= F_21 ( 100 ) ) return 3 ;
if ( V_22 >= F_21 ( 10 ) ) return 2 ;
return 1 ;
}
void
F_22 ( T_3 V_22 , T_2 * V_13 , int V_23 )
{
int V_24 = F_19 ( V_22 ) + 1 ;
T_2 * V_25 = & V_13 [ V_24 ] ;
if ( V_23 < V_24 ) {
F_23 ( V_13 , V_26 , V_23 ) ;
return;
}
* -- V_25 = '\0' ;
F_24 ( V_25 , V_22 ) ;
}
void
F_25 ( T_5 V_22 , T_2 * V_13 , int V_23 )
{
int V_24 = F_20 ( V_22 ) + 1 ;
T_2 * V_25 = & V_13 [ V_24 ] ;
if ( V_23 < V_24 ) {
F_23 ( V_13 , V_26 , V_23 ) ;
return;
}
* -- V_25 = '\0' ;
F_26 ( V_25 , V_22 ) ;
}
static const T_2 *
F_27 ( struct V_27 * V_28 )
{
#if F_28 ( V_29 )
static char * V_30 [ 2 ] = { NULL , NULL } ;
if ( V_30 [ V_28 -> V_31 ] == NULL ) {
V_30 [ V_28 -> V_31 ] = F_29 ( V_32 [ V_28 -> V_31 ] , - 1 , NULL , NULL , NULL ) ;
if ( V_30 [ V_28 -> V_31 ] == NULL ) {
V_30 [ V_28 -> V_31 ] = L_7 ;
}
}
return V_30 [ V_28 -> V_31 ] ;
#else
# if F_28 ( V_33 )
return V_28 -> V_34 ;
# else
if ( ( V_28 -> V_31 != 0 ) && ( V_28 -> V_31 != 1 ) ) {
return L_7 ;
}
# if F_28 ( V_35 )
return V_36 [ V_28 -> V_31 ] ;
# else
return V_28 -> V_31 ? L_8 : L_9 ;
# endif
# endif
#endif
}
T_2 *
F_30 ( T_6 * V_12 , const T_7 * V_37 , const T_8 V_38 ,
T_9 V_39 )
{
struct V_27 * V_28 = NULL ;
const char * V_40 = L_7 ;
T_2 * V_13 = NULL ;
switch ( V_38 ) {
case V_41 :
case V_42 :
V_28 = gmtime ( & V_37 -> V_43 ) ;
V_40 = L_10 ;
break;
case V_44 :
V_28 = localtime ( & V_37 -> V_43 ) ;
if ( V_28 ) {
V_40 = F_27 ( V_28 ) ;
}
break;
}
if ( V_28 ) {
switch ( V_38 ) {
case V_42 :
if ( V_39 ) {
V_13 = F_31 ( V_12 ,
L_11 ,
V_28 -> V_45 + 1900 ,
V_28 -> V_46 + 1 ,
V_28 -> V_47 ,
V_28 -> V_48 ,
V_28 -> V_49 ,
( long ) V_37 -> V_50 ,
V_40 ) ;
} else {
V_13 = F_31 ( V_12 ,
L_12 ,
V_28 -> V_45 + 1900 ,
V_28 -> V_46 + 1 ,
V_28 -> V_47 ,
V_28 -> V_48 ,
V_28 -> V_49 ,
( long ) V_37 -> V_50 ) ;
}
break;
case V_41 :
case V_44 :
if ( V_39 ) {
V_13 = F_31 ( V_12 ,
L_13 ,
V_51 [ V_28 -> V_52 ] ,
V_28 -> V_53 ,
V_28 -> V_45 + 1900 ,
V_28 -> V_47 ,
V_28 -> V_48 ,
V_28 -> V_49 ,
( long ) V_37 -> V_50 ,
V_40 ) ;
} else {
V_13 = F_31 ( V_12 ,
L_14 ,
V_51 [ V_28 -> V_52 ] ,
V_28 -> V_53 ,
V_28 -> V_45 + 1900 ,
V_28 -> V_47 ,
V_28 -> V_48 ,
V_28 -> V_49 ,
( long ) V_37 -> V_50 ) ;
}
break;
}
} else
V_13 = F_16 ( V_12 , L_15 ) ;
return V_13 ;
}
T_2 *
F_32 ( T_6 * V_12 , const T_10 V_37 , const T_8 V_38 ,
T_9 V_39 )
{
struct V_27 * V_28 = NULL ;
const char * V_40 = L_7 ;
T_2 * V_13 = NULL ;
switch ( V_38 ) {
case V_41 :
case V_42 :
V_28 = gmtime ( & V_37 ) ;
V_40 = L_10 ;
break;
case V_44 :
V_28 = localtime ( & V_37 ) ;
if ( V_28 ) {
V_40 = F_27 ( V_28 ) ;
}
break;
}
if ( V_28 ) {
switch ( V_38 ) {
case V_42 :
if ( V_39 ) {
V_13 = F_31 ( V_12 ,
L_16 ,
V_28 -> V_45 + 1900 ,
V_28 -> V_46 + 1 ,
V_28 -> V_47 ,
V_28 -> V_48 ,
V_28 -> V_49 ,
V_40 ) ;
} else {
V_13 = F_31 ( V_12 ,
L_17 ,
V_28 -> V_45 + 1900 ,
V_28 -> V_46 + 1 ,
V_28 -> V_47 ,
V_28 -> V_48 ,
V_28 -> V_49 ) ;
}
break;
case V_41 :
case V_44 :
if ( V_39 ) {
V_13 = F_31 ( V_12 ,
L_18 ,
V_51 [ V_28 -> V_52 ] ,
V_28 -> V_53 ,
V_28 -> V_45 + 1900 ,
V_28 -> V_47 ,
V_28 -> V_48 ,
V_28 -> V_49 ,
V_40 ) ;
} else {
V_13 = F_31 ( V_12 ,
L_19 ,
V_51 [ V_28 -> V_52 ] ,
V_28 -> V_53 ,
V_28 -> V_45 + 1900 ,
V_28 -> V_47 ,
V_28 -> V_48 ,
V_28 -> V_49 ) ;
}
break;
}
} else
V_13 = F_16 ( V_12 , L_15 ) ;
return V_13 ;
}
void
F_33 ( T_2 * V_13 , int V_14 , const T_10 V_54 , T_11 V_55 ,
const T_12 V_56 )
{
double V_57 ;
V_57 = difftime ( V_54 , ( T_10 ) 0 ) ;
if ( V_55 < 0 ) {
V_55 = - V_55 ;
if ( V_57 >= 0 ) {
if ( V_14 < 1 ) {
return;
}
V_13 [ 0 ] = '-' ;
V_13 ++ ;
V_14 -- ;
}
}
switch ( V_56 ) {
case V_58 :
F_34 ( V_13 , V_14 , L_20 , V_57 ) ;
break;
case V_59 :
F_34 ( V_13 , V_14 , L_21 , V_57 , V_55 ) ;
break;
case V_60 :
F_34 ( V_13 , V_14 , L_22 , V_57 , V_55 ) ;
break;
case V_61 :
F_34 ( V_13 , V_14 , L_23 , V_57 , V_55 ) ;
break;
case V_62 :
F_34 ( V_13 , V_14 , L_24 , V_57 , V_55 ) ;
break;
case V_63 :
F_34 ( V_13 , V_14 , L_25 , V_57 , V_55 ) ;
break;
}
}
void
F_35 ( T_2 * V_13 , int V_14 , const T_11 V_54 , T_11 V_55 ,
const T_12 V_56 )
{
T_13 V_64 [ 16 ] ;
T_13 * V_65 = & V_64 [ 16 ] ;
T_13 * V_66 ;
int V_67 ;
if ( V_14 < 1 )
return;
if ( V_55 < 0 ) {
V_55 = - V_55 ;
if ( V_54 >= 0 ) {
V_13 [ 0 ] = '-' ;
V_13 ++ ;
V_14 -- ;
}
}
V_66 = F_36 ( V_65 , V_54 ) ;
V_67 = F_37 ( ( int ) ( V_65 - V_66 ) , V_14 ) ;
memcpy ( V_13 , V_66 , V_67 ) ;
V_13 += V_67 ;
V_14 -= V_67 ;
switch ( V_56 ) {
case V_58 :
default:
V_66 = NULL ;
break;
case V_59 :
V_66 = F_38 ( V_65 , V_55 , 1 ) ;
break;
case V_60 :
V_66 = F_38 ( V_65 , V_55 , 2 ) ;
break;
case V_61 :
V_66 = F_38 ( V_65 , V_55 , 3 ) ;
break;
case V_62 :
V_66 = F_38 ( V_65 , V_55 , 6 ) ;
break;
case V_63 :
V_66 = F_38 ( V_65 , V_55 , 9 ) ;
break;
}
if ( V_66 != NULL )
{
* ( -- V_66 ) = '.' ;
V_67 = F_37 ( ( int ) ( V_65 - V_66 ) , V_14 ) ;
memcpy ( V_13 , V_66 , V_67 ) ;
V_13 += V_67 ;
V_14 -= V_67 ;
}
if ( V_14 == 0 )
V_13 -- ;
* V_13 = '\0' ;
}
static void
F_39 ( T_3 V_68 , const T_3 V_55 ,
const T_9 V_69 , T_14 * V_13 )
{
int V_70 , V_71 , V_43 ;
T_9 V_72 = FALSE ;
V_43 = V_68 % 60 ;
V_68 /= 60 ;
V_71 = V_68 % 60 ;
V_68 /= 60 ;
V_70 = V_68 % 24 ;
V_68 /= 24 ;
if ( V_68 != 0 ) {
F_40 ( V_13 , L_26 , V_68 , F_41 ( V_68 ) ) ;
V_72 = TRUE ;
}
if ( V_70 != 0 ) {
F_40 ( V_13 , L_27 , F_42 ( V_72 ) , V_70 , F_41 ( V_70 ) ) ;
V_72 = TRUE ;
}
if ( V_71 != 0 ) {
F_40 ( V_13 , L_28 , F_42 ( V_72 ) , V_71 , F_41 ( V_71 ) ) ;
V_72 = TRUE ;
}
if ( V_43 != 0 || V_55 != 0 ) {
if ( V_55 != 0 ) {
if ( V_69 )
F_40 ( V_13 , L_29 , F_42 ( V_72 ) , V_43 , V_55 ) ;
else
F_40 ( V_13 , L_30 , F_42 ( V_72 ) , V_43 , V_55 ) ;
} else
F_40 ( V_13 , L_31 , F_42 ( V_72 ) , V_43 , F_41 ( V_43 ) ) ;
}
}
T_2 *
F_43 ( T_6 * V_12 , const T_3 V_68 )
{
T_14 * V_13 ;
if ( V_68 == 0 ) {
return F_16 ( V_12 , L_32 ) ;
}
V_13 = F_44 ( V_12 , V_73 + 1 , V_73 + 1 ) ;
F_39 ( V_68 , 0 , FALSE , V_13 ) ;
return F_45 ( V_13 ) ;
}
static void
F_46 ( T_11 V_68 , const T_3 V_55 ,
const T_9 V_69 , T_14 * V_13 )
{
if( V_68 < 0 ) {
F_40 ( V_13 , L_33 ) ;
if( V_68 == V_74 ) {
F_39 ( V_75 , V_55 ,
V_69 , V_13 ) ;
} else {
F_39 ( - V_68 , V_55 ,
V_69 , V_13 ) ;
}
} else
F_39 ( V_68 , V_55 , V_69 , V_13 ) ;
}
T_2 *
F_47 ( T_6 * V_12 , const T_11 V_68 )
{
T_14 * V_13 ;
if ( V_68 == 0 ) {
return F_16 ( V_12 , L_32 ) ;
}
V_13 = F_44 ( V_12 , V_73 + 1 , V_73 + 1 ) ;
F_46 ( V_68 , 0 , FALSE , V_13 ) ;
return F_45 ( V_13 ) ;
}
T_2 *
F_48 ( T_6 * V_12 , T_11 V_68 )
{
T_14 * V_13 ;
int V_76 ;
if ( V_68 == 0 ) {
return F_16 ( V_12 , L_32 ) ;
}
V_13 = F_44 ( V_12 , V_73 + 1 + 3 + 1 , V_73 + 1 + 3 + 1 ) ;
if ( V_68 < 0 ) {
V_68 = - V_68 ;
V_76 = V_68 % 1000 ;
V_68 /= 1000 ;
V_68 = - V_68 ;
} else {
V_76 = V_68 % 1000 ;
V_68 /= 1000 ;
}
F_46 ( V_68 , V_76 , FALSE , V_13 ) ;
return F_45 ( V_13 ) ;
}
T_2 *
F_49 ( T_6 * V_12 , const T_7 * V_77 )
{
T_14 * V_13 ;
T_11 V_68 ;
T_11 V_78 ;
V_68 = ( V_79 ) V_77 -> V_43 ;
V_78 = V_77 -> V_50 ;
if ( V_68 == 0 && V_78 == 0 ) {
return F_16 ( V_12 , L_34 ) ;
}
V_13 = F_44 ( V_12 , 1 + V_73 + 1 + 6 + 1 , 1 + V_73 + 1 + 6 + 1 ) ;
if ( V_78 < 0 ) {
V_78 = - V_78 ;
F_50 ( V_13 , '-' ) ;
V_68 = ( V_79 ) - V_77 -> V_43 ;
}
F_46 ( V_68 , V_78 , TRUE , V_13 ) ;
return F_45 ( V_13 ) ;
}
T_2 *
F_51 ( T_6 * V_12 , const T_7 * V_77 )
{
T_2 * V_13 ;
V_13 = ( T_2 * ) F_17 ( V_12 , V_80 ) ;
F_35 ( V_13 , V_80 , ( T_11 ) V_77 -> V_43 ,
V_77 -> V_50 , V_63 ) ;
return V_13 ;
}
char *
F_52 ( const T_15 V_81 , const V_79 V_82 , const T_5 V_83 )
{
T_5 V_84 = 0 , V_28 ;
char * V_85 ;
int V_86 , V_87 = 0 ;
int V_11 ;
V_84 = 1 ;
V_84 = V_84 << ( V_82 - 1 ) ;
V_85 = ( char * ) F_53 ( F_54 () , 256 + 64 ) ;
for( V_86 = 0 ; V_86 < ( ( int ) ( V_81 & 0x07 ) ) ; V_86 ++ ) {
if( V_86 && ( ! ( V_86 % 4 ) ) ) {
V_85 [ V_87 ] = ' ' ;
V_87 ++ ;
}
V_85 [ V_87 ] = '.' ;
V_87 ++ ;
}
for( V_11 = 0 ; V_11 < V_82 ; V_11 ++ ) {
if( V_86 && ( ! ( V_86 % 4 ) ) ) {
V_85 [ V_87 ] = ' ' ;
V_87 ++ ;
}
if( V_86 && ( ! ( V_86 % 8 ) ) ) {
V_85 [ V_87 ] = ' ' ;
V_87 ++ ;
}
V_86 ++ ;
V_28 = V_83 & V_84 ;
if( V_28 != 0 ) {
V_85 [ V_87 ] = '1' ;
V_87 ++ ;
} else {
V_85 [ V_87 ] = '0' ;
V_87 ++ ;
}
V_84 = V_84 >> 1 ;
}
for(; V_86 % 8 ; V_86 ++ ) {
if( V_86 && ( ! ( V_86 % 4 ) ) ) {
V_85 [ V_87 ] = ' ' ;
V_87 ++ ;
}
V_85 [ V_87 ] = '.' ;
V_87 ++ ;
}
return V_85 ;
}
void
F_55 ( const T_1 * V_9 , T_2 * V_13 , const int V_23 )
{
register T_2 const * V_88 ;
register T_2 * V_89 = V_13 ;
if ( V_23 < V_90 ) {
F_23 ( V_13 , V_26 , V_23 ) ;
return;
}
V_88 = V_91 [ * V_9 ++ ] ;
do {
* V_89 ++ = * V_88 ;
V_88 ++ ;
} while( * V_88 );
* V_89 ++ = '.' ;
V_88 = V_91 [ * V_9 ++ ] ;
do {
* V_89 ++ = * V_88 ;
V_88 ++ ;
} while( * V_88 );
* V_89 ++ = '.' ;
V_88 = V_91 [ * V_9 ++ ] ;
do {
* V_89 ++ = * V_88 ;
V_88 ++ ;
} while( * V_88 );
* V_89 ++ = '.' ;
V_88 = V_91 [ * V_9 ] ;
do {
* V_89 ++ = * V_88 ;
V_88 ++ ;
} while( * V_88 );
* V_89 = 0 ;
}
void
F_56 ( const struct V_92 * V_9 , T_2 * V_13 , int V_23 )
{
if ( V_23 < V_93 ) {
F_23 ( V_13 , V_26 , V_23 ) ;
return;
}
F_57 ( V_9 , V_13 , V_23 ) ;
}
T_2 *
F_58 ( T_6 * V_12 , const T_16 * V_94 )
{
T_2 * V_13 ;
V_13 = ( T_2 * ) F_17 ( V_12 , V_95 ) ;
return F_59 ( V_94 , V_13 , V_95 ) ;
}
T_2 *
F_59 ( const T_16 * V_94 , T_2 * V_13 , int V_23 )
{
char * V_96 = V_13 ;
if ( V_23 < V_95 ) {
F_23 ( V_13 , V_26 , V_23 ) ;
return V_13 ;
}
V_96 = F_7 ( V_96 , V_94 -> V_97 ) ;
* V_96 ++ = '-' ;
V_96 = F_4 ( V_96 , V_94 -> V_98 ) ;
* V_96 ++ = '-' ;
V_96 = F_4 ( V_96 , V_94 -> V_99 ) ;
* V_96 ++ = '-' ;
V_96 = F_11 ( V_96 , & V_94 -> V_100 [ 0 ] , 2 ) ;
* V_96 ++ = '-' ;
V_96 = F_11 ( V_96 , & V_94 -> V_100 [ 2 ] , 6 ) ;
* V_96 = '\0' ;
return V_13 ;
}
T_2 *
F_60 ( T_6 * V_12 , const T_5 V_9 ) {
T_2 * V_13 , * V_28 ;
T_1 * V_101 ;
V_101 = ( T_1 * ) F_17 ( NULL , 8 ) ;
V_13 = ( T_2 * ) F_17 ( V_12 , V_102 ) ;
* ( T_5 * ) ( void * ) ( V_101 ) = F_61 ( & ( V_9 ) ) ;
V_28 = F_13 ( V_13 , V_101 , 8 , ':' ) ;
* V_28 = '\0' ;
F_62 ( NULL , V_101 ) ;
return V_13 ;
}
const T_2 *
F_63 ( T_17 type )
{
switch ( type ) {
case V_103 : return L_35 ;
case V_104 : return L_36 ;
case V_105 : return L_37 ;
case V_106 : return L_38 ;
case V_107 : return L_39 ;
case V_108 : return L_40 ;
case V_109 : return L_41 ;
case V_110 : return L_42 ;
case V_111 : return L_43 ;
case V_112 : return L_44 ;
case V_113 : return L_45 ;
case V_114 : return L_46 ;
case V_115 : return L_47 ;
case V_116 : return L_48 ;
case V_117 : return L_49 ;
case V_118 : return L_50 ;
case V_119 : return L_51 ;
default: return L_52 ;
}
}
char *
F_64 ( char * V_120 , T_3 V_83 )
{
while ( V_83 ) {
* ( -- V_120 ) = '0' + ( V_83 & 0x7 ) ;
V_83 >>= 3 ;
}
* ( -- V_120 ) = '0' ;
return V_120 ;
}
char *
F_65 ( char * V_120 , T_5 V_83 )
{
while ( V_83 ) {
* ( -- V_120 ) = '0' + ( V_83 & 0x7 ) ;
V_83 >>= 3 ;
}
* ( -- V_120 ) = '0' ;
return V_120 ;
}
char *
F_66 ( char * V_120 , int V_10 , T_3 V_83 )
{
do {
* ( -- V_120 ) = F_1 ( V_83 ) ;
V_83 >>= 4 ;
V_10 -- ;
} while ( V_83 );
while ( V_10 > 0 ) {
* ( -- V_120 ) = '0' ;
V_10 -- ;
}
* ( -- V_120 ) = 'x' ;
* ( -- V_120 ) = '0' ;
return V_120 ;
}
char *
F_67 ( char * V_120 , int V_10 , T_5 V_83 )
{
do {
* ( -- V_120 ) = F_1 ( V_83 & 0xF ) ;
V_83 >>= 4 ;
V_10 -- ;
} while ( V_83 );
while ( V_10 > 0 ) {
* ( -- V_120 ) = '0' ;
V_10 -- ;
}
* ( -- V_120 ) = 'x' ;
* ( -- V_120 ) = '0' ;
return V_120 ;
}
char *
F_24 ( char * V_120 , T_3 V_83 )
{
char const * V_88 ;
if ( V_83 == 0 )
* ( -- V_120 ) = '0' ;
while ( V_83 >= 10 ) {
V_88 = V_91 [ 100 + ( V_83 % 100 ) ] ;
V_83 /= 100 ;
* ( -- V_120 ) = V_88 [ 2 ] ;
* ( -- V_120 ) = V_88 [ 1 ] ;
}
if ( V_83 )
* ( -- V_120 ) = ( V_83 ) | '0' ;
return V_120 ;
}
char *
F_26 ( char * V_120 , T_5 V_83 )
{
char const * V_88 ;
if ( V_83 == 0 )
* ( -- V_120 ) = '0' ;
while ( V_83 >= 10 ) {
V_88 = V_91 [ 100 + ( V_83 % 100 ) ] ;
V_83 /= 100 ;
* ( -- V_120 ) = V_88 [ 2 ] ;
* ( -- V_120 ) = V_88 [ 1 ] ;
}
if ( V_83 )
* ( -- V_120 ) = ( V_83 & 0xF ) | '0' ;
return V_120 ;
}
char *
F_38 ( char * V_120 , T_3 V_83 , int V_10 )
{
char * V_121 ;
V_121 = F_24 ( V_120 , V_83 ) ;
V_10 -= ( int ) ( V_120 - V_121 ) ;
while ( V_10 > 0 )
{
* ( -- V_121 ) = '0' ;
V_10 -- ;
}
return V_121 ;
}
char *
F_68 ( char * V_120 , T_5 V_83 , int V_10 )
{
char * V_121 ;
V_121 = F_26 ( V_120 , V_83 ) ;
V_10 -= ( int ) ( V_120 - V_121 ) ;
while ( V_10 > 0 )
{
* ( -- V_121 ) = '0' ;
V_10 -- ;
}
return V_121 ;
}
char *
F_36 ( char * V_120 , T_11 V_83 )
{
if ( V_83 < 0 ) {
V_120 = F_24 ( V_120 , - V_83 ) ;
* ( -- V_120 ) = '-' ;
} else
V_120 = F_24 ( V_120 , V_83 ) ;
return V_120 ;
}
char *
F_69 ( char * V_120 , T_18 V_83 )
{
if ( V_83 < 0 ) {
V_120 = F_26 ( V_120 , - V_83 ) ;
* ( -- V_120 ) = '-' ;
} else
V_120 = F_26 ( V_120 , V_83 ) ;
return V_120 ;
}
