static inline char
F_1 ( T_1 V_1 )
{
static const T_2 V_2 [ 16 ] =
{ '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
return V_2 [ V_1 & 0xF ] ;
}
static inline char *
F_2 ( char * V_3 , T_3 V_4 ) {
* V_3 ++ = F_1 ( V_4 >> 4 ) ;
* V_3 ++ = F_1 ( V_4 ) ;
return V_3 ;
}
char *
F_3 ( char * V_3 , T_4 V_5 ) {
V_3 = F_2 ( V_3 , V_5 >> 8 ) ;
V_3 = F_2 ( V_3 , V_5 ) ;
return V_3 ;
}
char *
F_4 ( char * V_3 , T_4 V_5 ) {
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
F_5 ( char * V_3 , T_3 V_4 ) {
V_3 = F_2 ( V_3 , V_4 >> 24 ) ;
V_3 = F_2 ( V_3 , V_4 >> 16 ) ;
V_3 = F_2 ( V_3 , V_4 >> 8 ) ;
V_3 = F_2 ( V_3 , V_4 ) ;
return V_3 ;
}
char *
F_6 ( char * V_3 , T_3 V_4 , char V_6 ) {
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
F_7 ( char * V_3 , const T_1 * V_7 , T_3 V_8 ) {
T_3 V_9 ;
if ( ! V_7 )
F_8 ( L_1 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_3 = F_2 ( V_3 , V_7 [ V_9 ] ) ;
return V_3 ;
}
char *
F_9 ( char * V_3 , const T_1 * V_7 , T_3 V_8 , char V_6 ) {
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
F_10 ( const T_1 * V_7 , const T_3 V_8 , const char V_6 ) {
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
T_2 *
F_12 ( const T_1 * V_12 , int V_13 ) {
T_2 * V_14 ;
T_2 * V_15 ;
int V_16 = 0 ;
if ( ! V_12 )
F_8 ( L_5 ) ;
V_14 = ( T_2 * ) F_11 ( V_17 + 3 + 1 ) ;
if ( V_13 <= 0 ) { V_14 [ 0 ] = '\0' ; return V_14 ; }
if ( V_13 > V_17 / 2 ) {
V_16 = 1 ;
V_13 = V_17 / 2 ;
}
V_15 = F_7 ( V_14 , V_12 , V_13 ) ;
if ( V_16 )
V_15 = F_13 ( V_15 , L_6 ) ;
* V_15 = '\0' ;
return V_14 ;
}
T_2 *
F_14 ( const T_1 * V_12 , int V_13 , T_2 V_6 ) {
T_2 * V_14 ;
T_2 * V_15 ;
int V_16 = 0 ;
if ( ! V_6 )
return F_12 ( V_12 , V_13 ) ;
V_14 = ( T_2 * ) F_11 ( V_17 + 3 + 1 ) ;
if ( V_13 <= 0 ) { V_14 [ 0 ] = '\0' ; return V_14 ; }
if ( V_13 > V_17 / 3 ) {
V_16 = 1 ;
V_13 = V_17 / 3 ;
}
V_15 = F_9 ( V_14 , V_12 , V_13 , V_6 ) ;
if ( V_16 ) {
* V_15 ++ = V_6 ;
V_15 = F_13 ( V_15 , L_6 ) ;
}
* V_15 = '\0' ;
return V_14 ;
}
static int
F_15 ( const T_3 V_18 ) {
if ( V_18 >= 1000000000 ) return 10 ;
if ( V_18 >= 100000000 ) return 9 ;
if ( V_18 >= 10000000 ) return 8 ;
if ( V_18 >= 1000000 ) return 7 ;
if ( V_18 >= 100000 ) return 6 ;
if ( V_18 >= 10000 ) return 5 ;
if ( V_18 >= 1000 ) return 4 ;
if ( V_18 >= 100 ) return 3 ;
if ( V_18 >= 10 ) return 2 ;
return 1 ;
}
void
F_16 ( T_3 V_18 , T_2 * V_10 , int V_19 ) {
int V_20 = F_15 ( V_18 ) + 1 ;
T_2 * V_21 = & V_10 [ V_20 ] ;
if ( V_19 < V_20 ) {
F_17 ( V_10 , V_22 , V_19 ) ;
return;
}
* -- V_21 = '\0' ;
F_18 ( V_21 , V_18 ) ;
}
T_2 *
F_19 ( const T_3 V_18 ) {
int V_20 = 16 ;
T_2 * V_21 = ( T_2 * ) F_11 ( V_20 ) ;
F_16 ( V_18 , V_21 , V_20 ) ;
return V_21 ;
}
static void
F_20 ( T_6 V_23 , const T_3 V_24 , const T_7 V_25 ,
T_8 * V_10 )
{
int V_26 , V_27 , V_28 ;
const T_2 * V_29 = L_4 ;
T_7 V_30 = FALSE ;
if( V_23 == V_31 ) {
F_21 ( V_10 , L_7 , V_23 ) ;
return;
}
if( V_23 < 0 ) {
V_23 = - V_23 ;
V_29 = L_8 ;
}
V_28 = V_23 % 60 ;
V_23 /= 60 ;
V_27 = V_23 % 60 ;
V_23 /= 60 ;
V_26 = V_23 % 24 ;
V_23 /= 24 ;
if ( V_23 != 0 ) {
F_21 ( V_10 , L_9 , V_29 , V_23 , F_22 ( V_23 ) ) ;
V_30 = TRUE ;
V_29 = L_4 ;
}
if ( V_26 != 0 ) {
F_21 ( V_10 , L_10 , F_23 ( V_30 ) , V_29 , V_26 , F_22 ( V_26 ) ) ;
V_30 = TRUE ;
V_29 = L_4 ;
}
if ( V_27 != 0 ) {
F_21 ( V_10 , L_11 , F_23 ( V_30 ) , V_29 , V_27 , F_22 ( V_27 ) ) ;
V_30 = TRUE ;
V_29 = L_4 ;
}
if ( V_28 != 0 || V_24 != 0 ) {
if ( V_24 != 0 ) {
if ( V_25 )
F_21 ( V_10 , L_12 , F_23 ( V_30 ) , V_29 , V_28 , V_24 ) ;
else
F_21 ( V_10 , L_13 , F_23 ( V_30 ) , V_29 , V_28 , V_24 ) ;
} else
F_21 ( V_10 , L_14 , F_23 ( V_30 ) , V_29 , V_28 , F_22 ( V_28 ) ) ;
}
}
T_2 *
F_24 ( const T_6 V_23 )
{
T_8 * V_10 ;
V_10 = F_25 ( V_32 + 1 , V_32 + 1 ) ;
if ( V_23 == 0 ) {
F_26 ( V_10 , L_15 ) ;
return V_10 -> V_33 ;
}
F_20 ( V_23 , 0 , FALSE , V_10 ) ;
return V_10 -> V_33 ;
}
static void
F_27 ( T_3 V_23 , const T_3 V_24 , const T_7 V_25 ,
T_8 * V_10 )
{
int V_26 , V_27 , V_28 ;
T_7 V_30 = FALSE ;
V_28 = V_23 % 60 ;
V_23 /= 60 ;
V_27 = V_23 % 60 ;
V_23 /= 60 ;
V_26 = V_23 % 24 ;
V_23 /= 24 ;
if ( V_23 != 0 ) {
F_21 ( V_10 , L_16 , V_23 , F_22 ( V_23 ) ) ;
V_30 = TRUE ;
}
if ( V_26 != 0 ) {
F_21 ( V_10 , L_17 , F_23 ( V_30 ) , V_26 , F_22 ( V_26 ) ) ;
V_30 = TRUE ;
}
if ( V_27 != 0 ) {
F_21 ( V_10 , L_18 , F_23 ( V_30 ) , V_27 , F_22 ( V_27 ) ) ;
V_30 = TRUE ;
}
if ( V_28 != 0 || V_24 != 0 ) {
if ( V_24 != 0 ) {
if ( V_25 )
F_21 ( V_10 , L_19 , F_23 ( V_30 ) , V_28 , V_24 ) ;
else
F_21 ( V_10 , L_20 , F_23 ( V_30 ) , V_28 , V_24 ) ;
} else
F_21 ( V_10 , L_21 , F_23 ( V_30 ) , V_28 , F_22 ( V_28 ) ) ;
}
}
T_2 *
F_28 ( const T_3 V_23 )
{
T_8 * V_10 ;
V_10 = F_25 ( V_32 + 1 , V_32 + 1 ) ;
if ( V_23 == 0 ) {
F_26 ( V_10 , L_15 ) ;
return V_10 -> V_33 ;
}
F_27 ( V_23 , 0 , FALSE , V_10 ) ;
return V_10 -> V_33 ;
}
T_2 *
F_29 ( T_6 V_23 )
{
T_8 * V_10 ;
int V_34 ;
V_10 = F_25 ( V_32 + 1 + 3 + 1 , V_32 + 1 + 3 + 1 ) ;
if ( V_23 == 0 ) {
F_26 ( V_10 , L_15 ) ;
return V_10 -> V_33 ;
}
if( V_23 < 0 ) {
V_23 = - V_23 ;
V_34 = V_23 % 1000 ;
V_23 /= 1000 ;
V_23 = - V_23 ;
} else {
V_34 = V_23 % 1000 ;
V_23 /= 1000 ;
}
F_20 ( V_23 , V_34 , FALSE , V_10 ) ;
return V_10 -> V_33 ;
}
static const T_2 * F_30 ( struct V_35 * V_36 ) {
#if F_31 ( V_37 )
return V_36 -> V_38 ;
#else
if ( ( V_36 -> V_39 != 0 ) && ( V_36 -> V_39 != 1 ) ) {
return L_22 ;
}
# if F_31 ( V_40 )
return V_41 [ V_36 -> V_39 ] ;
# elif F_31 ( V_42 )
{
static char * V_43 [ 2 ] = { NULL , NULL } ;
if ( V_43 [ V_36 -> V_39 ] == NULL ) {
V_43 [ V_36 -> V_39 ] = F_32 ( V_44 [ V_36 -> V_39 ] , - 1 , NULL , NULL , NULL ) ;
if ( V_43 [ V_36 -> V_39 ] == NULL ) {
V_43 [ V_36 -> V_39 ] = L_22 ;
}
}
return V_43 [ V_36 -> V_39 ] ;
}
# else
return V_36 -> V_39 ? L_23 : L_24 ;
# endif
#endif
}
T_2 *
F_33 ( const T_9 * V_45 , const T_10 V_46 ,
T_7 V_47 )
{
struct V_35 * V_36 = NULL ;
const char * V_48 = L_22 ;
T_2 * V_10 = NULL ;
#if ( F_31 V_42 ) && ( V_49 < 1500 )
if( V_45 -> V_28 > 2000000000 ) {
V_36 = NULL ;
} else
#endif
switch ( V_46 ) {
case V_50 :
case V_51 :
V_36 = gmtime ( & V_45 -> V_28 ) ;
V_48 = L_25 ;
break;
case V_52 :
V_36 = localtime ( & V_45 -> V_28 ) ;
if ( V_36 ) {
V_48 = F_30 ( V_36 ) ;
}
break;
}
if ( V_36 ) {
switch ( V_46 ) {
case V_51 :
if ( V_47 ) {
V_10 = F_34 ( L_26 ,
V_36 -> V_53 + 1900 ,
V_36 -> V_54 + 1 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_36 -> V_57 ,
( long ) V_45 -> V_58 ,
V_48 ) ;
} else {
V_10 = F_34 ( L_27 ,
V_36 -> V_53 + 1900 ,
V_36 -> V_54 + 1 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_36 -> V_57 ,
( long ) V_45 -> V_58 ) ;
}
break;
case V_50 :
case V_52 :
if ( V_47 ) {
V_10 = F_34 ( L_28 ,
V_59 [ V_36 -> V_60 ] ,
V_36 -> V_61 ,
V_36 -> V_53 + 1900 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_36 -> V_57 ,
( long ) V_45 -> V_58 ,
V_48 ) ;
} else {
V_10 = F_34 ( L_29 ,
V_59 [ V_36 -> V_60 ] ,
V_36 -> V_61 ,
V_36 -> V_53 + 1900 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_36 -> V_57 ,
( long ) V_45 -> V_58 ) ;
}
break;
}
} else
V_10 = F_35 ( L_30 ) ;
return V_10 ;
}
T_2 *
F_36 ( const T_11 V_45 , const T_10 V_46 ,
T_7 V_47 )
{
struct V_35 * V_36 = NULL ;
const char * V_48 = L_22 ;
T_2 * V_10 = NULL ;
#if ( F_31 V_42 ) && ( V_49 < 1500 )
if( V_45 > 2000000000 ) {
V_36 = NULL ;
} else
#endif
switch ( V_46 ) {
case V_50 :
case V_51 :
V_36 = gmtime ( & V_45 ) ;
V_48 = L_25 ;
break;
case V_52 :
V_36 = localtime ( & V_45 ) ;
if ( V_36 ) {
V_48 = F_30 ( V_36 ) ;
}
break;
}
if ( V_36 ) {
switch ( V_46 ) {
case V_51 :
if ( V_47 ) {
V_10 = F_34 ( L_31 ,
V_36 -> V_53 + 1900 ,
V_36 -> V_54 + 1 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_36 -> V_57 ,
V_48 ) ;
} else {
V_10 = F_34 ( L_32 ,
V_36 -> V_53 + 1900 ,
V_36 -> V_54 + 1 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_36 -> V_57 ) ;
}
break;
case V_50 :
case V_52 :
if ( V_47 ) {
V_10 = F_34 ( L_33 ,
V_59 [ V_36 -> V_60 ] ,
V_36 -> V_61 ,
V_36 -> V_53 + 1900 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_36 -> V_57 ,
V_48 ) ;
} else {
V_10 = F_34 ( L_34 ,
V_59 [ V_36 -> V_60 ] ,
V_36 -> V_61 ,
V_36 -> V_53 + 1900 ,
V_36 -> V_55 ,
V_36 -> V_56 ,
V_36 -> V_57 ) ;
}
break;
}
} else
V_10 = F_35 ( L_30 ) ;
return V_10 ;
}
void
F_37 ( T_2 * V_10 , int V_11 , const T_6 V_62 , T_6 V_24 ,
const T_12 V_63 )
{
if ( V_24 < 0 ) {
V_24 = - V_24 ;
if ( V_62 >= 0 ) {
if ( V_11 < 1 ) {
return;
}
V_10 [ 0 ] = '-' ;
V_10 ++ ;
V_11 -- ;
}
}
switch ( V_63 ) {
case V_64 :
F_38 ( V_10 , V_11 , L_35 , V_62 ) ;
break;
case V_65 :
F_38 ( V_10 , V_11 , L_36 , V_62 , V_24 ) ;
break;
case V_66 :
F_38 ( V_10 , V_11 , L_37 , V_62 , V_24 ) ;
break;
case V_67 :
F_38 ( V_10 , V_11 , L_38 , V_62 , V_24 ) ;
break;
case V_68 :
F_38 ( V_10 , V_11 , L_39 , V_62 , V_24 ) ;
break;
case V_69 :
F_38 ( V_10 , V_11 , L_40 , V_62 , V_24 ) ;
break;
}
}
void
F_39 ( T_2 * V_10 , int V_11 , const T_11 V_62 , T_6 V_24 ,
const T_12 V_63 )
{
double V_70 ;
V_70 = difftime ( V_62 , ( T_11 ) 0 ) ;
if ( V_24 < 0 ) {
V_24 = - V_24 ;
if ( V_70 >= 0 ) {
if ( V_11 < 1 ) {
return;
}
V_10 [ 0 ] = '-' ;
V_10 ++ ;
V_11 -- ;
}
}
switch ( V_63 ) {
case V_64 :
F_38 ( V_10 , V_11 , L_41 , V_70 ) ;
break;
case V_65 :
F_38 ( V_10 , V_11 , L_42 , V_70 , V_24 ) ;
break;
case V_66 :
F_38 ( V_10 , V_11 , L_43 , V_70 , V_24 ) ;
break;
case V_67 :
F_38 ( V_10 , V_11 , L_44 , V_70 , V_24 ) ;
break;
case V_68 :
F_38 ( V_10 , V_11 , L_45 , V_70 , V_24 ) ;
break;
case V_69 :
F_38 ( V_10 , V_11 , L_46 , V_70 , V_24 ) ;
break;
}
}
T_2 *
F_40 ( const T_9 * V_71 )
{
T_8 * V_10 ;
T_6 V_23 ;
T_6 V_72 ;
V_10 = F_25 ( 1 + V_32 + 1 + 6 + 1 , 1 + V_32 + 1 + 6 + 1 ) ;
V_23 = ( V_73 ) V_71 -> V_28 ;
V_72 = V_71 -> V_58 ;
if ( V_23 == 0 && V_72 == 0 ) {
F_26 ( V_10 , L_47 ) ;
return V_10 -> V_33 ;
}
if ( V_72 < 0 ) {
V_72 = - V_72 ;
F_41 ( V_10 , '-' ) ;
V_23 = ( V_73 ) - V_71 -> V_28 ;
}
F_20 ( V_23 , V_72 , TRUE , V_10 ) ;
return V_10 -> V_33 ;
}
T_2 *
F_42 ( const T_9 * V_71 )
{
T_2 * V_10 ;
V_10 = ( T_2 * ) F_11 ( V_74 ) ;
F_37 ( V_10 , V_74 , ( T_6 ) V_71 -> V_28 ,
V_71 -> V_58 , V_69 ) ;
return V_10 ;
}
char *
F_43 ( const T_13 V_75 , const V_73 V_76 , const T_14 V_77 )
{
T_14 V_78 = 0 , V_36 ;
char * V_33 ;
int V_79 , V_80 = 0 ;
int V_9 ;
V_78 = 1 ;
V_78 = V_78 << ( V_76 - 1 ) ;
V_33 = ( char * ) F_44 ( 256 + 64 ) ;
for( V_79 = 0 ; V_79 < ( ( int ) ( V_75 & 0x07 ) ) ; V_79 ++ ) {
if( V_79 && ( ! ( V_79 % 4 ) ) ) {
V_33 [ V_80 ] = ' ' ;
V_80 ++ ;
}
V_33 [ V_80 ] = '.' ;
V_80 ++ ;
}
for( V_9 = 0 ; V_9 < V_76 ; V_9 ++ ) {
if( V_79 && ( ! ( V_79 % 4 ) ) ) {
V_33 [ V_80 ] = ' ' ;
V_80 ++ ;
}
if( V_79 && ( ! ( V_79 % 8 ) ) ) {
V_33 [ V_80 ] = ' ' ;
V_80 ++ ;
}
V_79 ++ ;
V_36 = V_77 & V_78 ;
if( V_36 != 0 ) {
V_33 [ V_80 ] = '1' ;
V_80 ++ ;
} else {
V_33 [ V_80 ] = '0' ;
V_80 ++ ;
}
V_78 = V_78 >> 1 ;
}
for(; V_79 % 8 ; V_79 ++ ) {
if( V_79 && ( ! ( V_79 % 4 ) ) ) {
V_33 [ V_80 ] = ' ' ;
V_80 ++ ;
}
V_33 [ V_80 ] = '.' ;
V_80 ++ ;
}
return V_33 ;
}
char *
F_45 ( char * V_10 , const T_3 V_81 , const T_3 V_78 , const int V_82 )
{
int V_9 ;
T_3 V_79 ;
char * V_83 ;
V_9 = 0 ;
V_83 = V_10 ;
V_79 = 1 << ( V_82 - 1 ) ;
for (; ; ) {
if ( V_78 & V_79 ) {
if ( V_81 & V_79 )
* V_83 ++ = '1' ;
else
* V_83 ++ = '0' ;
} else {
* V_83 ++ = '.' ;
}
V_79 >>= 1 ;
V_9 ++ ;
if ( V_9 >= V_82 )
break;
if ( V_9 % 4 == 0 )
* V_83 ++ = ' ' ;
}
* V_83 = '\0' ;
return V_83 ;
}
char *
F_46 ( char * V_10 , const T_3 V_81 , const T_3 V_78 , const int V_82 )
{
char * V_83 ;
V_83 = F_45 ( V_10 , V_81 , V_78 , V_82 ) ;
V_83 = F_13 ( V_83 , L_48 ) ;
return V_83 ;
}
const char *
F_47 ( const T_3 V_81 , const T_3 V_78 , const int V_82 ,
const char * V_84 , const char * V_85 )
{
char * V_10 ;
char * V_83 ;
V_10 = ( char * ) F_11 ( 1025 ) ;
V_83 = F_46 ( V_10 , V_81 , V_78 , V_82 ) ;
if ( V_81 & V_78 )
strcpy ( V_83 , V_84 ) ;
else
strcpy ( V_83 , V_85 ) ;
return V_10 ;
}
const char *
F_48 ( const T_3 V_81 , const T_3 V_78 , const int V_82 ,
const char * V_46 )
{
char * V_10 ;
char * V_83 ;
int V_86 = 0 ;
V_10 = ( char * ) F_11 ( 1025 ) ;
while ( ( V_78 & ( 1 << V_86 ) ) == 0 )
V_86 ++ ;
V_83 = F_46 ( V_10 , V_81 , V_78 , V_82 ) ;
F_38 ( V_83 , ( V_87 ) ( 1025 - ( V_83 - V_10 ) ) , V_46 , ( V_81 & V_78 ) >> V_86 ) ;
return V_10 ;
}
void
F_49 ( const T_1 * V_7 , T_2 * V_10 , const int V_19 )
{
register T_2 const * V_83 ;
register T_2 * V_88 = V_10 ;
if ( V_19 < V_89 ) {
F_38 ( V_10 , V_19 , V_22 ) ;
return;
}
V_83 = V_90 [ * V_7 ++ ] ;
do {
* V_88 ++ = * V_83 ;
V_83 ++ ;
} while( * V_83 );
* V_88 ++ = '.' ;
V_83 = V_90 [ * V_7 ++ ] ;
do {
* V_88 ++ = * V_83 ;
V_83 ++ ;
} while( * V_83 );
* V_88 ++ = '.' ;
V_83 = V_90 [ * V_7 ++ ] ;
do {
* V_88 ++ = * V_83 ;
V_83 ++ ;
} while( * V_83 );
* V_88 ++ = '.' ;
V_83 = V_90 [ * V_7 ] ;
do {
* V_88 ++ = * V_83 ;
V_83 ++ ;
} while( * V_83 );
* V_88 = 0 ;
}
T_2 * F_50 ( const T_15 * V_91 ) {
T_2 * V_10 ;
V_10 = ( T_2 * ) F_11 ( V_92 ) ;
return F_51 ( V_91 , V_10 , V_92 ) ;
}
T_2 * F_51 ( const T_15 * V_91 , T_2 * V_10 , int V_19 ) {
char * V_93 = V_10 ;
if ( V_19 < V_92 ) {
F_17 ( V_10 , V_22 , V_19 ) ;
return V_10 ;
}
V_93 = F_5 ( V_93 , V_91 -> V_94 ) ;
* V_93 ++ = '-' ;
V_93 = F_3 ( V_93 , V_91 -> V_95 ) ;
* V_93 ++ = '-' ;
V_93 = F_3 ( V_93 , V_91 -> V_96 ) ;
* V_93 ++ = '-' ;
V_93 = F_7 ( V_93 , & V_91 -> V_97 [ 0 ] , 2 ) ;
* V_93 ++ = '-' ;
V_93 = F_7 ( V_93 , & V_91 -> V_97 [ 2 ] , 6 ) ;
* V_93 = '\0' ;
return V_10 ;
}
const T_2 * F_52 ( T_16 type ) {
switch ( type ) {
case V_98 : return L_49 ;
case V_99 : return L_50 ;
case V_100 : return L_51 ;
case V_101 : return L_52 ;
case V_102 : return L_53 ;
case V_103 : return L_54 ;
case V_104 : return L_55 ;
case V_105 : return L_56 ;
case V_106 : return L_57 ;
case V_107 : return L_58 ;
case V_108 : return L_59 ;
case V_109 : return L_60 ;
case V_110 : return L_61 ;
case V_111 : return L_62 ;
case V_112 : return L_63 ;
case V_113 : return L_64 ;
default: return L_65 ;
}
}
char *
F_53 ( char * V_114 , T_3 V_77 )
{
while ( V_77 ) {
* ( -- V_114 ) = '0' + ( V_77 & 0x7 ) ;
V_77 >>= 3 ;
}
* ( -- V_114 ) = '0' ;
return V_114 ;
}
char *
F_54 ( char * V_114 , int V_115 , T_3 V_77 )
{
do {
* ( -- V_114 ) = F_1 ( V_77 ) ;
V_77 >>= 4 ;
V_115 -- ;
} while ( V_77 );
while ( V_115 > 0 ) {
* ( -- V_114 ) = '0' ;
V_115 -- ;
}
* ( -- V_114 ) = 'x' ;
* ( -- V_114 ) = '0' ;
return V_114 ;
}
char *
F_18 ( char * V_114 , T_3 V_77 )
{
char const * V_83 ;
if ( V_77 == 0 )
* ( -- V_114 ) = '0' ;
while ( V_77 >= 10 ) {
V_83 = V_90 [ 100 + ( V_77 % 100 ) ] ;
V_77 /= 100 ;
* ( -- V_114 ) = V_83 [ 2 ] ;
* ( -- V_114 ) = V_83 [ 1 ] ;
}
if ( V_77 )
* ( -- V_114 ) = ( V_77 ) | '0' ;
return V_114 ;
}
char *
F_55 ( char * V_114 , T_6 V_77 )
{
if ( V_77 < 0 ) {
V_114 = F_18 ( V_114 , - V_77 ) ;
* ( -- V_114 ) = '-' ;
} else
V_114 = F_18 ( V_114 , V_77 ) ;
return V_114 ;
}
