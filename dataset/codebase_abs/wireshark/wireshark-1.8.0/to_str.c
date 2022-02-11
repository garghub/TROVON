static inline char *
F_1 ( char * V_1 , T_1 V_2 ) {
static const T_2 V_3 [ 16 ] =
{ '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
* V_1 ++ = V_3 [ ( V_2 >> 4 ) & 0xF ] ;
* V_1 ++ = V_3 [ V_2 & 0xF ] ;
return V_1 ;
}
char *
F_2 ( char * V_1 , T_3 V_4 ) {
V_1 = F_1 ( V_1 , V_4 >> 8 ) ;
V_1 = F_1 ( V_1 , V_4 ) ;
return V_1 ;
}
char *
F_3 ( char * V_1 , T_3 V_4 ) {
static const T_2 V_3 [ 16 ] =
{ '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( V_4 >= 0x1000 )
* V_1 ++ = V_3 [ ( V_4 >> 12 ) & 0xF ] ;
if ( V_4 >= 0x0100 )
* V_1 ++ = V_3 [ ( V_4 >> 8 ) & 0xF ] ;
if ( V_4 >= 0x0010 )
* V_1 ++ = V_3 [ ( V_4 >> 4 ) & 0xF ] ;
* V_1 ++ = V_3 [ V_4 & 0xF ] ;
return V_1 ;
}
char *
F_4 ( char * V_1 , T_1 V_2 ) {
V_1 = F_1 ( V_1 , V_2 >> 24 ) ;
V_1 = F_1 ( V_1 , V_2 >> 16 ) ;
V_1 = F_1 ( V_1 , V_2 >> 8 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
return V_1 ;
}
char *
F_5 ( char * V_1 , T_1 V_2 , char V_5 ) {
V_1 = F_1 ( V_1 , V_2 >> 24 ) ;
* V_1 ++ = V_5 ;
V_1 = F_1 ( V_1 , V_2 >> 16 ) ;
* V_1 ++ = V_5 ;
V_1 = F_1 ( V_1 , V_2 >> 8 ) ;
* V_1 ++ = V_5 ;
V_1 = F_1 ( V_1 , V_2 ) ;
return V_1 ;
}
char *
F_6 ( char * V_1 , const T_4 * V_6 , T_1 V_7 ) {
T_1 V_8 ;
if ( ! V_6 )
F_7 ( L_1 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_1 = F_1 ( V_1 , V_6 [ V_8 ] ) ;
return V_1 ;
}
char *
F_8 ( char * V_1 , const T_4 * V_6 , T_1 V_7 , char V_5 ) {
T_1 V_8 ;
if ( ! V_6 )
F_7 ( L_2 ) ;
V_1 = F_1 ( V_1 , V_6 [ 0 ] ) ;
for ( V_8 = 1 ; V_8 < V_7 ; V_8 ++ ) {
* V_1 ++ = V_5 ;
V_1 = F_1 ( V_1 , V_6 [ V_8 ] ) ;
}
return V_1 ;
}
T_2 *
F_9 ( const T_4 * V_6 , const T_1 V_7 , const char V_5 ) {
T_2 * V_9 ;
T_5 V_10 ;
if ( ! V_6 )
F_7 ( L_3 ) ;
if ( ( ( int ) V_7 ) < 0 )
return L_4 ;
if ( ! V_7 )
return L_4 ;
if ( V_5 )
V_10 = V_7 * 3 ;
else
V_10 = V_7 * 2 + 1 ;
V_9 = F_10 ( V_10 ) ;
if ( V_5 )
F_8 ( V_9 , V_6 , V_7 , V_5 ) ;
else
F_6 ( V_9 , V_6 , V_7 ) ;
V_9 [ V_10 - 1 ] = '\0' ;
return V_9 ;
}
T_2 *
F_11 ( const T_4 * V_11 , int V_12 ) {
T_2 * V_13 ;
T_2 * V_14 ;
int V_15 = 0 ;
if ( ! V_11 )
F_7 ( L_5 ) ;
V_13 = F_10 ( V_16 + 3 + 1 ) ;
if ( V_12 <= 0 ) { V_13 [ 0 ] = '\0' ; return V_13 ; }
if ( V_12 > V_16 / 2 ) {
V_15 = 1 ;
V_12 = V_16 / 2 ;
}
V_14 = F_6 ( V_13 , V_11 , V_12 ) ;
if ( V_15 )
V_14 = F_12 ( V_14 , L_6 ) ;
* V_14 = '\0' ;
return V_13 ;
}
T_2 *
F_13 ( const T_4 * V_11 , int V_12 , T_2 V_5 ) {
T_2 * V_13 ;
T_2 * V_14 ;
int V_15 = 0 ;
if ( ! V_5 )
return F_11 ( V_11 , V_12 ) ;
V_13 = F_10 ( V_16 + 3 + 1 ) ;
if ( V_12 <= 0 ) { V_13 [ 0 ] = '\0' ; return V_13 ; }
if ( V_12 > V_16 / 3 ) {
V_15 = 1 ;
V_12 = V_16 / 3 ;
}
V_14 = F_8 ( V_13 , V_11 , V_12 , V_5 ) ;
if ( V_15 ) {
* V_14 ++ = V_5 ;
V_14 = F_12 ( V_14 , L_6 ) ;
}
* V_14 = '\0' ;
return V_13 ;
}
static int
F_14 ( const T_1 V_17 ) {
if ( V_17 >= 1000000000 ) return 10 ;
if ( V_17 >= 100000000 ) return 9 ;
if ( V_17 >= 10000000 ) return 8 ;
if ( V_17 >= 1000000 ) return 7 ;
if ( V_17 >= 100000 ) return 6 ;
if ( V_17 >= 10000 ) return 5 ;
if ( V_17 >= 1000 ) return 4 ;
if ( V_17 >= 100 ) return 3 ;
if ( V_17 >= 10 ) return 2 ;
return 1 ;
}
void
F_15 ( T_1 V_17 , T_2 * V_9 , int V_18 ) {
int V_19 = F_14 ( V_17 ) + 1 ;
T_2 * V_20 = & V_9 [ V_19 ] ;
T_2 const * V_21 ;
if ( V_18 < V_19 ) {
F_16 ( V_9 , V_22 , V_18 ) ;
return;
}
* -- V_20 = '\0' ;
while ( V_17 >= 10 ) {
V_21 = V_23 [ 100 + ( V_17 % 100 ) ] ;
* -- V_20 = V_21 [ 2 ] ;
* -- V_20 = V_21 [ 1 ] ;
V_17 /= 100 ;
}
if ( V_20 != V_9 )
* -- V_20 = ( V_17 % 10 ) | '0' ;
}
T_2 *
F_17 ( const T_1 V_17 ) {
int V_19 = 16 ;
T_2 * V_20 = F_10 ( V_19 ) ;
F_15 ( V_17 , V_20 , V_19 ) ;
return V_20 ;
}
static void
F_18 ( T_6 V_24 , const T_1 V_25 , const T_7 V_26 ,
T_8 * V_9 )
{
int V_27 , V_28 , V_29 ;
const T_2 * V_30 = L_4 ;
T_7 V_31 = FALSE ;
if( V_24 == V_32 ) {
F_19 ( V_9 , L_7 , V_24 ) ;
return;
}
if( V_24 < 0 ) {
V_24 = - V_24 ;
V_30 = L_8 ;
}
V_29 = V_24 % 60 ;
V_24 /= 60 ;
V_28 = V_24 % 60 ;
V_24 /= 60 ;
V_27 = V_24 % 24 ;
V_24 /= 24 ;
if ( V_24 != 0 ) {
F_19 ( V_9 , L_9 , V_30 , V_24 , F_20 ( V_24 ) ) ;
V_31 = TRUE ;
V_30 = L_4 ;
}
if ( V_27 != 0 ) {
F_19 ( V_9 , L_10 , F_21 ( V_31 ) , V_30 , V_27 , F_20 ( V_27 ) ) ;
V_31 = TRUE ;
V_30 = L_4 ;
}
if ( V_28 != 0 ) {
F_19 ( V_9 , L_11 , F_21 ( V_31 ) , V_30 , V_28 , F_20 ( V_28 ) ) ;
V_31 = TRUE ;
V_30 = L_4 ;
}
if ( V_29 != 0 || V_25 != 0 ) {
if ( V_25 != 0 ) {
if ( V_26 )
F_19 ( V_9 , L_12 , F_21 ( V_31 ) , V_30 , V_29 , V_25 ) ;
else
F_19 ( V_9 , L_13 , F_21 ( V_31 ) , V_30 , V_29 , V_25 ) ;
} else
F_19 ( V_9 , L_14 , F_21 ( V_31 ) , V_30 , V_29 , F_20 ( V_29 ) ) ;
}
}
T_2 *
F_22 ( const T_6 V_24 )
{
T_8 * V_9 ;
V_9 = F_23 ( V_33 + 1 , V_33 + 1 ) ;
if ( V_24 == 0 ) {
F_24 ( V_9 , L_15 ) ;
return V_9 -> V_34 ;
}
F_18 ( V_24 , 0 , FALSE , V_9 ) ;
return V_9 -> V_34 ;
}
static void
F_25 ( T_1 V_24 , const T_1 V_25 , const T_7 V_26 ,
T_8 * V_9 )
{
int V_27 , V_28 , V_29 ;
T_7 V_31 = FALSE ;
V_29 = V_24 % 60 ;
V_24 /= 60 ;
V_28 = V_24 % 60 ;
V_24 /= 60 ;
V_27 = V_24 % 24 ;
V_24 /= 24 ;
if ( V_24 != 0 ) {
F_19 ( V_9 , L_16 , V_24 , F_20 ( V_24 ) ) ;
V_31 = TRUE ;
}
if ( V_27 != 0 ) {
F_19 ( V_9 , L_17 , F_21 ( V_31 ) , V_27 , F_20 ( V_27 ) ) ;
V_31 = TRUE ;
}
if ( V_28 != 0 ) {
F_19 ( V_9 , L_18 , F_21 ( V_31 ) , V_28 , F_20 ( V_28 ) ) ;
V_31 = TRUE ;
}
if ( V_29 != 0 || V_25 != 0 ) {
if ( V_25 != 0 ) {
if ( V_26 )
F_19 ( V_9 , L_19 , F_21 ( V_31 ) , V_29 , V_25 ) ;
else
F_19 ( V_9 , L_20 , F_21 ( V_31 ) , V_29 , V_25 ) ;
} else
F_19 ( V_9 , L_21 , F_21 ( V_31 ) , V_29 , F_20 ( V_29 ) ) ;
}
}
T_2 *
F_26 ( const T_1 V_24 )
{
T_8 * V_9 ;
V_9 = F_23 ( V_33 + 1 , V_33 + 1 ) ;
if ( V_24 == 0 ) {
F_24 ( V_9 , L_15 ) ;
return V_9 -> V_34 ;
}
F_25 ( V_24 , 0 , FALSE , V_9 ) ;
return V_9 -> V_34 ;
}
T_2 *
F_27 ( T_6 V_24 )
{
T_8 * V_9 ;
int V_35 ;
V_9 = F_23 ( V_33 + 1 + 3 + 1 , V_33 + 1 + 3 + 1 ) ;
if ( V_24 == 0 ) {
F_24 ( V_9 , L_15 ) ;
return V_9 -> V_34 ;
}
if( V_24 < 0 ) {
V_24 = - V_24 ;
V_35 = V_24 % 1000 ;
V_24 /= 1000 ;
V_24 = - V_24 ;
} else {
V_35 = V_24 % 1000 ;
V_24 /= 1000 ;
}
F_18 ( V_24 , V_35 , FALSE , V_9 ) ;
return V_9 -> V_34 ;
}
static const T_2 * F_28 ( struct V_36 * V_37 ) {
#if F_29 ( V_38 )
return V_37 -> V_39 ;
#else
if ( ( V_37 -> V_40 != 0 ) && ( V_37 -> V_40 != 1 ) ) {
return L_22 ;
}
# if F_29 ( V_41 )
return V_42 [ V_37 -> V_40 ] ;
# elif F_29 ( V_43 )
{
static char * V_44 [ 2 ] = { NULL , NULL } ;
if ( V_44 [ V_37 -> V_40 ] == NULL ) {
V_44 [ V_37 -> V_40 ] = F_30 ( V_45 [ V_37 -> V_40 ] , - 1 , NULL , NULL , NULL ) ;
if ( V_44 [ V_37 -> V_40 ] == NULL ) {
V_44 [ V_37 -> V_40 ] = L_22 ;
}
}
return V_44 [ V_37 -> V_40 ] ;
}
# else
return V_37 -> V_40 ? L_23 : L_24 ;
# endif
#endif
}
T_2 *
F_31 ( const T_9 * V_46 , const T_10 V_47 ,
T_7 V_48 )
{
struct V_36 * V_37 = NULL ;
const char * V_49 = L_22 ;
T_2 * V_9 = NULL ;
#ifdef F_32
if( V_46 -> V_29 > 2000000000 ) {
V_37 = NULL ;
} else
#endif
switch ( V_47 ) {
case V_50 :
case V_51 :
V_37 = gmtime ( & V_46 -> V_29 ) ;
V_49 = L_25 ;
break;
case V_52 :
V_37 = localtime ( & V_46 -> V_29 ) ;
if ( V_37 ) {
V_49 = F_28 ( V_37 ) ;
}
break;
}
if ( V_37 ) {
switch ( V_47 ) {
case V_51 :
if ( V_48 ) {
V_9 = F_33 ( L_26 ,
V_37 -> V_53 + 1900 ,
V_37 -> V_54 + 1 ,
V_37 -> V_55 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
( long ) V_46 -> V_58 ,
V_49 ) ;
} else {
V_9 = F_33 ( L_27 ,
V_37 -> V_53 + 1900 ,
V_37 -> V_54 + 1 ,
V_37 -> V_55 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
( long ) V_46 -> V_58 ) ;
}
break;
case V_50 :
case V_52 :
if ( V_48 ) {
V_9 = F_33 ( L_28 ,
V_59 [ V_37 -> V_60 ] ,
V_37 -> V_61 ,
V_37 -> V_53 + 1900 ,
V_37 -> V_55 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
( long ) V_46 -> V_58 ,
V_49 ) ;
} else {
V_9 = F_33 ( L_29 ,
V_59 [ V_37 -> V_60 ] ,
V_37 -> V_61 ,
V_37 -> V_53 + 1900 ,
V_37 -> V_55 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
( long ) V_46 -> V_58 ) ;
}
break;
}
} else
V_9 = F_34 ( L_30 ) ;
return V_9 ;
}
T_2 *
F_35 ( const T_11 V_46 , const T_10 V_47 ,
T_7 V_48 )
{
struct V_36 * V_37 = NULL ;
const char * V_49 = L_22 ;
T_2 * V_9 = NULL ;
#ifdef F_32
if( V_46 > 2000000000 ) {
V_37 = NULL ;
} else
#endif
switch ( V_47 ) {
case V_50 :
case V_51 :
V_37 = gmtime ( & V_46 ) ;
V_49 = L_25 ;
break;
case V_52 :
V_37 = localtime ( & V_46 ) ;
if ( V_37 ) {
V_49 = F_28 ( V_37 ) ;
}
break;
}
if ( V_37 ) {
switch ( V_47 ) {
case V_51 :
if ( V_48 ) {
V_9 = F_33 ( L_31 ,
V_37 -> V_53 + 1900 ,
V_37 -> V_54 + 1 ,
V_37 -> V_55 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_49 ) ;
} else {
V_9 = F_33 ( L_32 ,
V_37 -> V_53 + 1900 ,
V_37 -> V_54 + 1 ,
V_37 -> V_55 ,
V_37 -> V_56 ,
V_37 -> V_57 ) ;
}
break;
case V_50 :
case V_52 :
if ( V_48 ) {
V_9 = F_33 ( L_33 ,
V_59 [ V_37 -> V_60 ] ,
V_37 -> V_61 ,
V_37 -> V_53 + 1900 ,
V_37 -> V_55 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_49 ) ;
} else {
V_9 = F_33 ( L_34 ,
V_59 [ V_37 -> V_60 ] ,
V_37 -> V_61 ,
V_37 -> V_53 + 1900 ,
V_37 -> V_55 ,
V_37 -> V_56 ,
V_37 -> V_57 ) ;
}
break;
}
} else
V_9 = F_34 ( L_30 ) ;
return V_9 ;
}
void
F_36 ( T_2 * V_9 , int V_10 , const T_6 V_62 , T_6 V_25 ,
const T_12 V_63 )
{
if ( V_25 < 0 ) {
V_25 = - V_25 ;
if ( V_62 >= 0 ) {
if ( V_10 < 1 ) {
return;
}
V_9 [ 0 ] = '-' ;
V_9 ++ ;
V_10 -- ;
}
}
switch ( V_63 ) {
case V_64 :
F_37 ( V_9 , V_10 , L_35 , V_62 ) ;
break;
case V_65 :
F_37 ( V_9 , V_10 , L_36 , V_62 , V_25 ) ;
break;
case V_66 :
F_37 ( V_9 , V_10 , L_37 , V_62 , V_25 ) ;
break;
case V_67 :
F_37 ( V_9 , V_10 , L_38 , V_62 , V_25 ) ;
break;
case V_68 :
F_37 ( V_9 , V_10 , L_39 , V_62 , V_25 ) ;
break;
case V_69 :
F_37 ( V_9 , V_10 , L_40 , V_62 , V_25 ) ;
break;
}
}
void
F_38 ( T_2 * V_9 , int V_10 , const T_11 V_62 , T_6 V_25 ,
const T_12 V_63 )
{
double V_70 ;
V_70 = difftime ( V_62 , ( T_11 ) 0 ) ;
if ( V_25 < 0 ) {
V_25 = - V_25 ;
if ( V_70 >= 0 ) {
if ( V_10 < 1 ) {
return;
}
V_9 [ 0 ] = '-' ;
V_9 ++ ;
V_10 -- ;
}
}
switch ( V_63 ) {
case V_64 :
F_37 ( V_9 , V_10 , L_41 , V_70 ) ;
break;
case V_65 :
F_37 ( V_9 , V_10 , L_42 , V_70 , V_25 ) ;
break;
case V_66 :
F_37 ( V_9 , V_10 , L_43 , V_70 , V_25 ) ;
break;
case V_67 :
F_37 ( V_9 , V_10 , L_44 , V_70 , V_25 ) ;
break;
case V_68 :
F_37 ( V_9 , V_10 , L_45 , V_70 , V_25 ) ;
break;
case V_69 :
F_37 ( V_9 , V_10 , L_46 , V_70 , V_25 ) ;
break;
}
}
T_2 *
F_39 ( const T_9 * V_71 )
{
T_8 * V_9 ;
T_6 V_24 ;
T_6 V_72 ;
V_9 = F_23 ( 1 + V_33 + 1 + 6 + 1 , 1 + V_33 + 1 + 6 + 1 ) ;
V_24 = ( V_73 ) V_71 -> V_29 ;
V_72 = V_71 -> V_58 ;
if ( V_24 == 0 && V_72 == 0 ) {
F_24 ( V_9 , L_47 ) ;
return V_9 -> V_34 ;
}
if ( V_72 < 0 ) {
V_72 = - V_72 ;
F_40 ( V_9 , '-' ) ;
V_24 = ( V_73 ) - V_71 -> V_29 ;
}
F_18 ( V_24 , V_72 , TRUE , V_9 ) ;
return V_9 -> V_34 ;
}
T_2 *
F_41 ( const T_9 * V_71 )
{
T_2 * V_9 ;
V_9 = F_10 ( V_74 ) ;
F_36 ( V_9 , V_74 , ( T_6 ) V_71 -> V_29 ,
V_71 -> V_58 , V_69 ) ;
return V_9 ;
}
char *
F_42 ( const T_13 V_75 , const V_73 V_76 , const T_14 V_77 )
{
T_14 V_78 = 0 , V_37 ;
char * V_34 ;
int V_79 ;
int V_8 ;
V_78 = 1 ;
V_78 = V_78 << ( V_76 - 1 ) ;
V_34 = F_10 ( 256 ) ;
V_34 [ 0 ] = '\0' ;
for( V_79 = 0 ; V_79 < ( ( int ) ( V_75 & 0x07 ) ) ; V_79 ++ ) {
if( V_79 && ( ! ( V_79 % 4 ) ) ) {
F_43 ( V_34 , L_48 , 256 ) ;
}
F_43 ( V_34 , L_49 , 256 ) ;
}
for( V_8 = 0 ; V_8 < V_76 ; V_8 ++ ) {
if( V_79 && ( ! ( V_79 % 4 ) ) ) {
F_43 ( V_34 , L_48 , 256 ) ;
}
if( V_79 && ( ! ( V_79 % 8 ) ) ) {
F_43 ( V_34 , L_48 , 256 ) ;
}
V_79 ++ ;
V_37 = V_77 & V_78 ;
if( V_37 != 0 ) {
F_43 ( V_34 , L_50 , 256 ) ;
} else {
F_43 ( V_34 , L_51 , 256 ) ;
}
V_78 = V_78 >> 1 ;
}
for(; V_79 % 8 ; V_79 ++ ) {
if( V_79 && ( ! ( V_79 % 4 ) ) ) {
F_43 ( V_34 , L_48 , 256 ) ;
}
F_43 ( V_34 , L_49 , 256 ) ;
}
return V_34 ;
}
char *
F_44 ( char * V_9 , const T_1 V_80 , const T_1 V_78 , const int V_81 )
{
int V_8 ;
T_1 V_79 ;
char * V_21 ;
V_8 = 0 ;
V_21 = V_9 ;
V_79 = 1 << ( V_81 - 1 ) ;
for (; ; ) {
if ( V_78 & V_79 ) {
if ( V_80 & V_79 )
* V_21 ++ = '1' ;
else
* V_21 ++ = '0' ;
} else {
* V_21 ++ = '.' ;
}
V_79 >>= 1 ;
V_8 ++ ;
if ( V_8 >= V_81 )
break;
if ( V_8 % 4 == 0 )
* V_21 ++ = ' ' ;
}
* V_21 = '\0' ;
return V_21 ;
}
char *
F_45 ( char * V_9 , const T_1 V_80 , const T_1 V_78 , const int V_81 )
{
char * V_21 ;
V_21 = F_44 ( V_9 , V_80 , V_78 , V_81 ) ;
strcpy ( V_21 , L_52 ) ;
V_21 += 3 ;
return V_21 ;
}
const char *
F_46 ( const T_1 V_80 , const T_1 V_78 , const int V_81 ,
const char * V_82 , const char * V_83 )
{
char * V_9 ;
char * V_21 ;
V_9 = F_10 ( 1025 ) ;
V_21 = F_45 ( V_9 , V_80 , V_78 , V_81 ) ;
if ( V_80 & V_78 )
strcpy ( V_21 , V_82 ) ;
else
strcpy ( V_21 , V_83 ) ;
return V_9 ;
}
const char *
F_47 ( const T_1 V_80 , const T_1 V_78 , const int V_81 ,
const char * V_47 )
{
char * V_9 ;
char * V_21 ;
int V_84 = 0 ;
V_9 = F_10 ( 1025 ) ;
while ( ( V_78 & ( 1 << V_84 ) ) == 0 )
V_84 ++ ;
V_21 = F_45 ( V_9 , V_80 , V_78 , V_81 ) ;
F_37 ( V_21 , ( V_85 ) ( 1025 - ( V_21 - V_9 ) ) , V_47 , ( V_80 & V_78 ) >> V_84 ) ;
return V_9 ;
}
void
F_48 ( const T_4 * V_6 , T_2 * V_9 , const int V_18 )
{
register T_2 const * V_21 ;
register T_2 * V_86 = V_9 ;
if ( V_18 < V_87 ) {
F_37 ( V_9 , V_18 , V_22 ) ;
return;
}
V_21 = V_23 [ * V_6 ++ ] ;
do {
* V_86 ++ = * V_21 ;
V_21 ++ ;
} while( * V_21 );
* V_86 ++ = '.' ;
V_21 = V_23 [ * V_6 ++ ] ;
do {
* V_86 ++ = * V_21 ;
V_21 ++ ;
} while( * V_21 );
* V_86 ++ = '.' ;
V_21 = V_23 [ * V_6 ++ ] ;
do {
* V_86 ++ = * V_21 ;
V_21 ++ ;
} while( * V_21 );
* V_86 ++ = '.' ;
V_21 = V_23 [ * V_6 ] ;
do {
* V_86 ++ = * V_21 ;
V_21 ++ ;
} while( * V_21 );
* V_86 = 0 ;
}
T_2 * F_49 ( const T_15 * V_88 ) {
T_2 * V_9 ;
V_9 = F_10 ( V_89 ) ;
return F_50 ( V_88 , V_9 , V_89 ) ;
}
T_2 * F_50 ( const T_15 * V_88 , T_2 * V_9 , int V_18 ) {
char * V_90 = V_9 ;
if ( V_18 < V_89 ) {
F_16 ( V_9 , V_22 , V_18 ) ;
return V_9 ;
}
V_90 = F_4 ( V_90 , V_88 -> V_91 ) ;
* V_90 ++ = '-' ;
V_90 = F_2 ( V_90 , V_88 -> V_92 ) ;
* V_90 ++ = '-' ;
V_90 = F_2 ( V_90 , V_88 -> V_93 ) ;
* V_90 ++ = '-' ;
V_90 = F_6 ( V_90 , & V_88 -> V_94 [ 0 ] , 2 ) ;
* V_90 ++ = '-' ;
V_90 = F_6 ( V_90 , & V_88 -> V_94 [ 2 ] , 6 ) ;
* V_90 = '\0' ;
return V_9 ;
}
