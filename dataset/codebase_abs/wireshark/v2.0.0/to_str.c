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
const T_2 *
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
static void
F_26 ( T_7 V_26 , const T_3 V_27 , const T_8 V_28 ,
T_9 * V_12 )
{
int V_29 , V_30 , V_31 ;
const T_2 * V_32 = L_4 ;
T_8 V_33 = FALSE ;
if( V_26 == V_34 ) {
F_27 ( V_12 , L_7 , V_26 ) ;
return;
}
if( V_26 < 0 ) {
V_26 = - V_26 ;
V_32 = L_8 ;
}
V_31 = V_26 % 60 ;
V_26 /= 60 ;
V_30 = V_26 % 60 ;
V_26 /= 60 ;
V_29 = V_26 % 24 ;
V_26 /= 24 ;
if ( V_26 != 0 ) {
F_27 ( V_12 , L_9 , V_32 , V_26 , F_28 ( V_26 ) ) ;
V_33 = TRUE ;
V_32 = L_4 ;
}
if ( V_29 != 0 ) {
F_27 ( V_12 , L_10 , F_29 ( V_33 ) , V_32 , V_29 , F_28 ( V_29 ) ) ;
V_33 = TRUE ;
V_32 = L_4 ;
}
if ( V_30 != 0 ) {
F_27 ( V_12 , L_11 , F_29 ( V_33 ) , V_32 , V_30 , F_28 ( V_30 ) ) ;
V_33 = TRUE ;
V_32 = L_4 ;
}
if ( V_31 != 0 || V_27 != 0 ) {
if ( V_27 != 0 ) {
if ( V_28 )
F_27 ( V_12 , L_12 , F_29 ( V_33 ) , V_32 , V_31 , V_27 ) ;
else
F_27 ( V_12 , L_13 , F_29 ( V_33 ) , V_32 , V_31 , V_27 ) ;
} else
F_27 ( V_12 , L_14 , F_29 ( V_33 ) , V_32 , V_31 , F_28 ( V_31 ) ) ;
}
}
T_2 *
F_30 ( T_6 * V_11 , const T_7 V_26 )
{
T_9 * V_12 ;
if ( V_26 == 0 ) {
return F_15 ( V_11 , L_15 ) ;
}
V_12 = F_31 ( V_11 , V_35 + 1 , V_35 + 1 ) ;
F_26 ( V_26 , 0 , FALSE , V_12 ) ;
return F_32 ( V_12 ) ;
}
static void
F_33 ( T_3 V_26 , const T_3 V_27 , const T_8 V_28 ,
T_9 * V_12 )
{
int V_29 , V_30 , V_31 ;
T_8 V_33 = FALSE ;
V_31 = V_26 % 60 ;
V_26 /= 60 ;
V_30 = V_26 % 60 ;
V_26 /= 60 ;
V_29 = V_26 % 24 ;
V_26 /= 24 ;
if ( V_26 != 0 ) {
F_27 ( V_12 , L_16 , V_26 , F_28 ( V_26 ) ) ;
V_33 = TRUE ;
}
if ( V_29 != 0 ) {
F_27 ( V_12 , L_17 , F_29 ( V_33 ) , V_29 , F_28 ( V_29 ) ) ;
V_33 = TRUE ;
}
if ( V_30 != 0 ) {
F_27 ( V_12 , L_18 , F_29 ( V_33 ) , V_30 , F_28 ( V_30 ) ) ;
V_33 = TRUE ;
}
if ( V_31 != 0 || V_27 != 0 ) {
if ( V_27 != 0 ) {
if ( V_28 )
F_27 ( V_12 , L_19 , F_29 ( V_33 ) , V_31 , V_27 ) ;
else
F_27 ( V_12 , L_20 , F_29 ( V_33 ) , V_31 , V_27 ) ;
} else
F_27 ( V_12 , L_21 , F_29 ( V_33 ) , V_31 , F_28 ( V_31 ) ) ;
}
}
T_2 *
F_34 ( T_6 * V_11 , const T_3 V_26 )
{
T_9 * V_12 ;
if ( V_26 == 0 ) {
return F_15 ( V_11 , L_15 ) ;
}
V_12 = F_31 ( V_11 , V_35 + 1 , V_35 + 1 ) ;
F_33 ( V_26 , 0 , FALSE , V_12 ) ;
return F_32 ( V_12 ) ;
}
T_2 *
F_35 ( T_6 * V_11 , T_7 V_26 )
{
T_9 * V_12 ;
int V_36 ;
if ( V_26 == 0 ) {
return F_15 ( V_11 , L_15 ) ;
}
V_12 = F_31 ( V_11 , V_35 + 1 + 3 + 1 , V_35 + 1 + 3 + 1 ) ;
if ( V_26 < 0 ) {
V_26 = - V_26 ;
V_36 = V_26 % 1000 ;
V_26 /= 1000 ;
V_26 = - V_26 ;
} else {
V_36 = V_26 % 1000 ;
V_26 /= 1000 ;
}
F_26 ( V_26 , V_36 , FALSE , V_12 ) ;
return F_32 ( V_12 ) ;
}
static const T_2 *
F_36 ( struct V_37 * V_38 )
{
#if F_37 ( V_39 )
return V_38 -> V_40 ;
#else
if ( ( V_38 -> V_41 != 0 ) && ( V_38 -> V_41 != 1 ) ) {
return L_22 ;
}
# if F_37 ( V_42 )
return V_43 [ V_38 -> V_41 ] ;
# elif F_37 ( V_44 )
{
static char * V_45 [ 2 ] = { NULL , NULL } ;
if ( V_45 [ V_38 -> V_41 ] == NULL ) {
V_45 [ V_38 -> V_41 ] = F_38 ( V_46 [ V_38 -> V_41 ] , - 1 , NULL , NULL , NULL ) ;
if ( V_45 [ V_38 -> V_41 ] == NULL ) {
V_45 [ V_38 -> V_41 ] = L_22 ;
}
}
return V_45 [ V_38 -> V_41 ] ;
}
# else
return V_38 -> V_41 ? L_23 : L_24 ;
# endif
#endif
}
T_2 *
F_39 ( T_6 * V_11 , const T_10 * V_47 , const T_11 V_48 ,
T_8 V_49 )
{
struct V_37 * V_38 = NULL ;
const char * V_50 = L_22 ;
T_2 * V_12 = NULL ;
switch ( V_48 ) {
case V_51 :
case V_52 :
V_38 = gmtime ( & V_47 -> V_31 ) ;
V_50 = L_25 ;
break;
case V_53 :
V_38 = localtime ( & V_47 -> V_31 ) ;
if ( V_38 ) {
V_50 = F_36 ( V_38 ) ;
}
break;
}
if ( V_38 ) {
switch ( V_48 ) {
case V_52 :
if ( V_49 ) {
V_12 = F_40 ( V_11 ,
L_26 ,
V_38 -> V_54 + 1900 ,
V_38 -> V_55 + 1 ,
V_38 -> V_56 ,
V_38 -> V_57 ,
V_38 -> V_58 ,
( long ) V_47 -> V_59 ,
V_50 ) ;
} else {
V_12 = F_40 ( V_11 ,
L_27 ,
V_38 -> V_54 + 1900 ,
V_38 -> V_55 + 1 ,
V_38 -> V_56 ,
V_38 -> V_57 ,
V_38 -> V_58 ,
( long ) V_47 -> V_59 ) ;
}
break;
case V_51 :
case V_53 :
if ( V_49 ) {
V_12 = F_40 ( V_11 ,
L_28 ,
V_60 [ V_38 -> V_61 ] ,
V_38 -> V_62 ,
V_38 -> V_54 + 1900 ,
V_38 -> V_56 ,
V_38 -> V_57 ,
V_38 -> V_58 ,
( long ) V_47 -> V_59 ,
V_50 ) ;
} else {
V_12 = F_40 ( V_11 ,
L_29 ,
V_60 [ V_38 -> V_61 ] ,
V_38 -> V_62 ,
V_38 -> V_54 + 1900 ,
V_38 -> V_56 ,
V_38 -> V_57 ,
V_38 -> V_58 ,
( long ) V_47 -> V_59 ) ;
}
break;
}
} else
V_12 = F_15 ( V_11 , L_30 ) ;
return V_12 ;
}
T_2 *
F_41 ( T_6 * V_11 , const T_12 V_47 , const T_11 V_48 ,
T_8 V_49 )
{
struct V_37 * V_38 = NULL ;
const char * V_50 = L_22 ;
T_2 * V_12 = NULL ;
switch ( V_48 ) {
case V_51 :
case V_52 :
V_38 = gmtime ( & V_47 ) ;
V_50 = L_25 ;
break;
case V_53 :
V_38 = localtime ( & V_47 ) ;
if ( V_38 ) {
V_50 = F_36 ( V_38 ) ;
}
break;
}
if ( V_38 ) {
switch ( V_48 ) {
case V_52 :
if ( V_49 ) {
V_12 = F_40 ( V_11 ,
L_31 ,
V_38 -> V_54 + 1900 ,
V_38 -> V_55 + 1 ,
V_38 -> V_56 ,
V_38 -> V_57 ,
V_38 -> V_58 ,
V_50 ) ;
} else {
V_12 = F_40 ( V_11 ,
L_32 ,
V_38 -> V_54 + 1900 ,
V_38 -> V_55 + 1 ,
V_38 -> V_56 ,
V_38 -> V_57 ,
V_38 -> V_58 ) ;
}
break;
case V_51 :
case V_53 :
if ( V_49 ) {
V_12 = F_40 ( V_11 ,
L_33 ,
V_60 [ V_38 -> V_61 ] ,
V_38 -> V_62 ,
V_38 -> V_54 + 1900 ,
V_38 -> V_56 ,
V_38 -> V_57 ,
V_38 -> V_58 ,
V_50 ) ;
} else {
V_12 = F_40 ( V_11 ,
L_34 ,
V_60 [ V_38 -> V_61 ] ,
V_38 -> V_62 ,
V_38 -> V_54 + 1900 ,
V_38 -> V_56 ,
V_38 -> V_57 ,
V_38 -> V_58 ) ;
}
break;
}
} else
V_12 = F_15 ( V_11 , L_30 ) ;
return V_12 ;
}
void
F_42 ( T_2 * V_12 , int V_13 , const T_7 V_63 , T_7 V_27 ,
const T_13 V_64 )
{
T_14 V_65 [ 16 ] ;
T_14 * V_66 = & V_65 [ 16 ] ;
T_14 * V_67 ;
int V_68 ;
if ( V_13 < 1 )
return;
if ( V_27 < 0 ) {
V_27 = - V_27 ;
if ( V_63 >= 0 ) {
V_12 [ 0 ] = '-' ;
V_12 ++ ;
V_13 -- ;
}
}
V_67 = F_43 ( V_66 , V_63 ) ;
V_68 = F_44 ( ( int ) ( V_66 - V_67 ) , V_13 ) ;
memcpy ( V_12 , V_67 , V_68 ) ;
V_12 += V_68 ;
V_13 -= V_68 ;
switch ( V_64 ) {
case V_69 :
default:
V_67 = NULL ;
break;
case V_70 :
V_67 = F_45 ( V_66 , V_27 , 1 ) ;
break;
case V_71 :
V_67 = F_45 ( V_66 , V_27 , 2 ) ;
break;
case V_72 :
V_67 = F_45 ( V_66 , V_27 , 3 ) ;
break;
case V_73 :
V_67 = F_45 ( V_66 , V_27 , 6 ) ;
break;
case V_74 :
V_67 = F_45 ( V_66 , V_27 , 9 ) ;
break;
}
if ( V_67 != NULL )
{
* ( -- V_67 ) = '.' ;
V_68 = F_44 ( ( int ) ( V_66 - V_67 ) , V_13 ) ;
memcpy ( V_12 , V_67 , V_68 ) ;
V_12 += V_68 ;
V_13 -= V_68 ;
}
if ( V_13 == 0 )
V_12 -- ;
* V_12 = '\0' ;
}
void
F_46 ( T_2 * V_12 , int V_13 , const T_12 V_63 , T_7 V_27 ,
const T_13 V_64 )
{
double V_75 ;
V_75 = difftime ( V_63 , ( T_12 ) 0 ) ;
if ( V_27 < 0 ) {
V_27 = - V_27 ;
if ( V_75 >= 0 ) {
if ( V_13 < 1 ) {
return;
}
V_12 [ 0 ] = '-' ;
V_12 ++ ;
V_13 -- ;
}
}
switch ( V_64 ) {
case V_69 :
F_47 ( V_12 , V_13 , L_35 , V_75 ) ;
break;
case V_70 :
F_47 ( V_12 , V_13 , L_36 , V_75 , V_27 ) ;
break;
case V_71 :
F_47 ( V_12 , V_13 , L_37 , V_75 , V_27 ) ;
break;
case V_72 :
F_47 ( V_12 , V_13 , L_38 , V_75 , V_27 ) ;
break;
case V_73 :
F_47 ( V_12 , V_13 , L_39 , V_75 , V_27 ) ;
break;
case V_74 :
F_47 ( V_12 , V_13 , L_40 , V_75 , V_27 ) ;
break;
}
}
T_2 *
F_48 ( T_6 * V_11 , const T_10 * V_76 )
{
T_9 * V_12 ;
T_7 V_26 ;
T_7 V_77 ;
V_26 = ( V_78 ) V_76 -> V_31 ;
V_77 = V_76 -> V_59 ;
if ( V_26 == 0 && V_77 == 0 ) {
return F_15 ( V_11 , L_41 ) ;
}
V_12 = F_31 ( V_11 , 1 + V_35 + 1 + 6 + 1 , 1 + V_35 + 1 + 6 + 1 ) ;
if ( V_77 < 0 ) {
V_77 = - V_77 ;
F_49 ( V_12 , '-' ) ;
V_26 = ( V_78 ) - V_76 -> V_31 ;
}
F_26 ( V_26 , V_77 , TRUE , V_12 ) ;
return F_32 ( V_12 ) ;
}
T_2 *
F_50 ( T_6 * V_11 , const T_10 * V_76 )
{
T_2 * V_12 ;
V_12 = ( T_2 * ) F_16 ( V_11 , V_79 ) ;
F_42 ( V_12 , V_79 , ( T_7 ) V_76 -> V_31 ,
V_76 -> V_59 , V_74 ) ;
return V_12 ;
}
char *
F_51 ( const T_15 V_80 , const V_78 V_81 , const T_5 V_82 )
{
T_5 V_83 = 0 , V_38 ;
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
V_38 = V_82 & V_83 ;
if( V_38 != 0 ) {
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
T_2 *
F_55 ( T_6 * V_11 , const T_16 * V_91 )
{
T_2 * V_12 ;
V_12 = ( T_2 * ) F_16 ( V_11 , V_92 ) ;
return F_56 ( V_91 , V_12 , V_92 ) ;
}
T_2 *
F_56 ( const T_16 * V_91 , T_2 * V_12 , int V_22 )
{
char * V_93 = V_12 ;
if ( V_22 < V_92 ) {
F_22 ( V_12 , V_25 , V_22 ) ;
return V_12 ;
}
V_93 = F_6 ( V_93 , V_91 -> V_94 ) ;
* V_93 ++ = '-' ;
V_93 = F_3 ( V_93 , V_91 -> V_95 ) ;
* V_93 ++ = '-' ;
V_93 = F_3 ( V_93 , V_91 -> V_96 ) ;
* V_93 ++ = '-' ;
V_93 = F_10 ( V_93 , & V_91 -> V_97 [ 0 ] , 2 ) ;
* V_93 ++ = '-' ;
V_93 = F_10 ( V_93 , & V_91 -> V_97 [ 2 ] , 6 ) ;
* V_93 = '\0' ;
return V_12 ;
}
T_2 *
F_57 ( T_6 * V_11 , const T_5 V_8 ) {
T_2 * V_12 , * V_38 ;
T_1 * V_98 ;
V_98 = ( T_1 * ) F_16 ( NULL , 8 ) ;
V_12 = ( T_2 * ) F_16 ( V_11 , V_99 ) ;
* ( T_5 * ) ( void * ) ( V_98 ) = F_58 ( & ( V_8 ) ) ;
V_38 = F_12 ( V_12 , V_98 , 8 , ':' ) ;
* V_38 = '\0' ;
F_59 ( NULL , V_98 ) ;
return V_12 ;
}
const T_2 *
F_60 ( T_17 type )
{
switch ( type ) {
case V_100 : return L_42 ;
case V_101 : return L_43 ;
case V_102 : return L_44 ;
case V_103 : return L_45 ;
case V_104 : return L_46 ;
case V_105 : return L_47 ;
case V_106 : return L_48 ;
case V_107 : return L_49 ;
case V_108 : return L_50 ;
case V_109 : return L_51 ;
case V_110 : return L_52 ;
case V_111 : return L_53 ;
case V_112 : return L_54 ;
case V_113 : return L_55 ;
case V_114 : return L_56 ;
case V_115 : return L_57 ;
case V_116 : return L_58 ;
default: return L_59 ;
}
}
char *
F_61 ( char * V_117 , T_3 V_82 )
{
while ( V_82 ) {
* ( -- V_117 ) = '0' + ( V_82 & 0x7 ) ;
V_82 >>= 3 ;
}
* ( -- V_117 ) = '0' ;
return V_117 ;
}
char *
F_62 ( char * V_117 , T_5 V_82 )
{
while ( V_82 ) {
* ( -- V_117 ) = '0' + ( V_82 & 0x7 ) ;
V_82 >>= 3 ;
}
* ( -- V_117 ) = '0' ;
return V_117 ;
}
char *
F_63 ( char * V_117 , int V_9 , T_3 V_82 )
{
do {
* ( -- V_117 ) = F_1 ( V_82 ) ;
V_82 >>= 4 ;
V_9 -- ;
} while ( V_82 );
while ( V_9 > 0 ) {
* ( -- V_117 ) = '0' ;
V_9 -- ;
}
* ( -- V_117 ) = 'x' ;
* ( -- V_117 ) = '0' ;
return V_117 ;
}
char *
F_64 ( char * V_117 , int V_9 , T_5 V_82 )
{
do {
* ( -- V_117 ) = F_1 ( V_82 & 0xF ) ;
V_82 >>= 4 ;
V_9 -- ;
} while ( V_82 );
while ( V_9 > 0 ) {
* ( -- V_117 ) = '0' ;
V_9 -- ;
}
* ( -- V_117 ) = 'x' ;
* ( -- V_117 ) = '0' ;
return V_117 ;
}
char *
F_23 ( char * V_117 , T_3 V_82 )
{
char const * V_87 ;
if ( V_82 == 0 )
* ( -- V_117 ) = '0' ;
while ( V_82 >= 10 ) {
V_87 = V_90 [ 100 + ( V_82 % 100 ) ] ;
V_82 /= 100 ;
* ( -- V_117 ) = V_87 [ 2 ] ;
* ( -- V_117 ) = V_87 [ 1 ] ;
}
if ( V_82 )
* ( -- V_117 ) = ( V_82 ) | '0' ;
return V_117 ;
}
char *
F_25 ( char * V_117 , T_5 V_82 )
{
char const * V_87 ;
if ( V_82 == 0 )
* ( -- V_117 ) = '0' ;
while ( V_82 >= 10 ) {
V_87 = V_90 [ 100 + ( V_82 % 100 ) ] ;
V_82 /= 100 ;
* ( -- V_117 ) = V_87 [ 2 ] ;
* ( -- V_117 ) = V_87 [ 1 ] ;
}
if ( V_82 )
* ( -- V_117 ) = ( V_82 & 0xF ) | '0' ;
return V_117 ;
}
char *
F_45 ( char * V_117 , T_3 V_82 , int V_9 )
{
char * V_118 ;
V_118 = F_23 ( V_117 , V_82 ) ;
V_9 -= ( int ) ( V_117 - V_118 ) ;
while ( V_9 > 0 )
{
* ( -- V_118 ) = '0' ;
V_9 -- ;
}
return V_118 ;
}
char *
F_65 ( char * V_117 , T_5 V_82 , int V_9 )
{
char * V_118 ;
V_118 = F_25 ( V_117 , V_82 ) ;
V_9 -= ( int ) ( V_117 - V_118 ) ;
while ( V_9 > 0 )
{
* ( -- V_118 ) = '0' ;
V_9 -- ;
}
return V_118 ;
}
char *
F_43 ( char * V_117 , T_7 V_82 )
{
if ( V_82 < 0 ) {
V_117 = F_23 ( V_117 , - V_82 ) ;
* ( -- V_117 ) = '-' ;
} else
V_117 = F_23 ( V_117 , V_82 ) ;
return V_117 ;
}
char *
F_66 ( char * V_117 , T_18 V_82 )
{
if ( V_82 < 0 ) {
V_117 = F_25 ( V_117 , - V_82 ) ;
* ( -- V_117 ) = '-' ;
} else
V_117 = F_25 ( V_117 , V_82 ) ;
return V_117 ;
}
