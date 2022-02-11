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
const T_2 *
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
V_9 = ( T_2 * ) F_10 ( V_10 ) ;
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
V_13 = ( T_2 * ) F_10 ( V_16 + 3 + 1 ) ;
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
V_13 = ( T_2 * ) F_10 ( V_16 + 3 + 1 ) ;
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
T_2 * V_20 = ( T_2 * ) F_10 ( V_19 ) ;
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
#if ( F_29 V_43 ) && ( V_50 < 1500 )
if( V_46 -> V_29 > 2000000000 ) {
V_37 = NULL ;
} else
#endif
switch ( V_47 ) {
case V_51 :
case V_52 :
V_37 = gmtime ( & V_46 -> V_29 ) ;
V_49 = L_25 ;
break;
case V_53 :
V_37 = localtime ( & V_46 -> V_29 ) ;
if ( V_37 ) {
V_49 = F_28 ( V_37 ) ;
}
break;
}
if ( V_37 ) {
switch ( V_47 ) {
case V_52 :
if ( V_48 ) {
V_9 = F_32 ( L_26 ,
V_37 -> V_54 + 1900 ,
V_37 -> V_55 + 1 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_37 -> V_58 ,
( long ) V_46 -> V_59 ,
V_49 ) ;
} else {
V_9 = F_32 ( L_27 ,
V_37 -> V_54 + 1900 ,
V_37 -> V_55 + 1 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_37 -> V_58 ,
( long ) V_46 -> V_59 ) ;
}
break;
case V_51 :
case V_53 :
if ( V_48 ) {
V_9 = F_32 ( L_28 ,
V_60 [ V_37 -> V_61 ] ,
V_37 -> V_62 ,
V_37 -> V_54 + 1900 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_37 -> V_58 ,
( long ) V_46 -> V_59 ,
V_49 ) ;
} else {
V_9 = F_32 ( L_29 ,
V_60 [ V_37 -> V_61 ] ,
V_37 -> V_62 ,
V_37 -> V_54 + 1900 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_37 -> V_58 ,
( long ) V_46 -> V_59 ) ;
}
break;
}
} else
V_9 = F_33 ( L_30 ) ;
return V_9 ;
}
T_2 *
F_34 ( const T_11 V_46 , const T_10 V_47 ,
T_7 V_48 )
{
struct V_36 * V_37 = NULL ;
const char * V_49 = L_22 ;
T_2 * V_9 = NULL ;
#if ( F_29 V_43 ) && ( V_50 < 1500 )
if( V_46 > 2000000000 ) {
V_37 = NULL ;
} else
#endif
switch ( V_47 ) {
case V_51 :
case V_52 :
V_37 = gmtime ( & V_46 ) ;
V_49 = L_25 ;
break;
case V_53 :
V_37 = localtime ( & V_46 ) ;
if ( V_37 ) {
V_49 = F_28 ( V_37 ) ;
}
break;
}
if ( V_37 ) {
switch ( V_47 ) {
case V_52 :
if ( V_48 ) {
V_9 = F_32 ( L_31 ,
V_37 -> V_54 + 1900 ,
V_37 -> V_55 + 1 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_37 -> V_58 ,
V_49 ) ;
} else {
V_9 = F_32 ( L_32 ,
V_37 -> V_54 + 1900 ,
V_37 -> V_55 + 1 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_37 -> V_58 ) ;
}
break;
case V_51 :
case V_53 :
if ( V_48 ) {
V_9 = F_32 ( L_33 ,
V_60 [ V_37 -> V_61 ] ,
V_37 -> V_62 ,
V_37 -> V_54 + 1900 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_37 -> V_58 ,
V_49 ) ;
} else {
V_9 = F_32 ( L_34 ,
V_60 [ V_37 -> V_61 ] ,
V_37 -> V_62 ,
V_37 -> V_54 + 1900 ,
V_37 -> V_56 ,
V_37 -> V_57 ,
V_37 -> V_58 ) ;
}
break;
}
} else
V_9 = F_33 ( L_30 ) ;
return V_9 ;
}
void
F_35 ( T_2 * V_9 , int V_10 , const T_6 V_63 , T_6 V_25 ,
const T_12 V_64 )
{
if ( V_25 < 0 ) {
V_25 = - V_25 ;
if ( V_63 >= 0 ) {
if ( V_10 < 1 ) {
return;
}
V_9 [ 0 ] = '-' ;
V_9 ++ ;
V_10 -- ;
}
}
switch ( V_64 ) {
case V_65 :
F_36 ( V_9 , V_10 , L_35 , V_63 ) ;
break;
case V_66 :
F_36 ( V_9 , V_10 , L_36 , V_63 , V_25 ) ;
break;
case V_67 :
F_36 ( V_9 , V_10 , L_37 , V_63 , V_25 ) ;
break;
case V_68 :
F_36 ( V_9 , V_10 , L_38 , V_63 , V_25 ) ;
break;
case V_69 :
F_36 ( V_9 , V_10 , L_39 , V_63 , V_25 ) ;
break;
case V_70 :
F_36 ( V_9 , V_10 , L_40 , V_63 , V_25 ) ;
break;
}
}
void
F_37 ( T_2 * V_9 , int V_10 , const T_11 V_63 , T_6 V_25 ,
const T_12 V_64 )
{
double V_71 ;
V_71 = difftime ( V_63 , ( T_11 ) 0 ) ;
if ( V_25 < 0 ) {
V_25 = - V_25 ;
if ( V_71 >= 0 ) {
if ( V_10 < 1 ) {
return;
}
V_9 [ 0 ] = '-' ;
V_9 ++ ;
V_10 -- ;
}
}
switch ( V_64 ) {
case V_65 :
F_36 ( V_9 , V_10 , L_41 , V_71 ) ;
break;
case V_66 :
F_36 ( V_9 , V_10 , L_42 , V_71 , V_25 ) ;
break;
case V_67 :
F_36 ( V_9 , V_10 , L_43 , V_71 , V_25 ) ;
break;
case V_68 :
F_36 ( V_9 , V_10 , L_44 , V_71 , V_25 ) ;
break;
case V_69 :
F_36 ( V_9 , V_10 , L_45 , V_71 , V_25 ) ;
break;
case V_70 :
F_36 ( V_9 , V_10 , L_46 , V_71 , V_25 ) ;
break;
}
}
T_2 *
F_38 ( const T_9 * V_72 )
{
T_8 * V_9 ;
T_6 V_24 ;
T_6 V_73 ;
V_9 = F_23 ( 1 + V_33 + 1 + 6 + 1 , 1 + V_33 + 1 + 6 + 1 ) ;
V_24 = ( V_74 ) V_72 -> V_29 ;
V_73 = V_72 -> V_59 ;
if ( V_24 == 0 && V_73 == 0 ) {
F_24 ( V_9 , L_47 ) ;
return V_9 -> V_34 ;
}
if ( V_73 < 0 ) {
V_73 = - V_73 ;
F_39 ( V_9 , '-' ) ;
V_24 = ( V_74 ) - V_72 -> V_29 ;
}
F_18 ( V_24 , V_73 , TRUE , V_9 ) ;
return V_9 -> V_34 ;
}
T_2 *
F_40 ( const T_9 * V_72 )
{
T_2 * V_9 ;
V_9 = ( T_2 * ) F_10 ( V_75 ) ;
F_35 ( V_9 , V_75 , ( T_6 ) V_72 -> V_29 ,
V_72 -> V_59 , V_70 ) ;
return V_9 ;
}
char *
F_41 ( const T_13 V_76 , const V_74 V_77 , const T_14 V_78 )
{
T_14 V_79 = 0 , V_37 ;
char * V_34 ;
int V_80 , V_81 = 0 ;
int V_8 ;
V_79 = 1 ;
V_79 = V_79 << ( V_77 - 1 ) ;
V_34 = ( char * ) F_42 ( 256 + 64 ) ;
for( V_80 = 0 ; V_80 < ( ( int ) ( V_76 & 0x07 ) ) ; V_80 ++ ) {
if( V_80 && ( ! ( V_80 % 4 ) ) ) {
V_34 [ V_81 ] = ' ' ;
V_81 ++ ;
}
V_34 [ V_81 ] = '.' ;
V_81 ++ ;
}
for( V_8 = 0 ; V_8 < V_77 ; V_8 ++ ) {
if( V_80 && ( ! ( V_80 % 4 ) ) ) {
V_34 [ V_81 ] = ' ' ;
V_81 ++ ;
}
if( V_80 && ( ! ( V_80 % 8 ) ) ) {
V_34 [ V_81 ] = ' ' ;
V_81 ++ ;
}
V_80 ++ ;
V_37 = V_78 & V_79 ;
if( V_37 != 0 ) {
V_34 [ V_81 ] = '1' ;
V_81 ++ ;
} else {
V_34 [ V_81 ] = '0' ;
V_81 ++ ;
}
V_79 = V_79 >> 1 ;
}
for(; V_80 % 8 ; V_80 ++ ) {
if( V_80 && ( ! ( V_80 % 4 ) ) ) {
V_34 [ V_81 ] = ' ' ;
V_81 ++ ;
}
V_34 [ V_81 ] = '.' ;
V_81 ++ ;
}
return V_34 ;
}
char *
F_43 ( char * V_9 , const T_1 V_82 , const T_1 V_79 , const int V_83 )
{
int V_8 ;
T_1 V_80 ;
char * V_21 ;
V_8 = 0 ;
V_21 = V_9 ;
V_80 = 1 << ( V_83 - 1 ) ;
for (; ; ) {
if ( V_79 & V_80 ) {
if ( V_82 & V_80 )
* V_21 ++ = '1' ;
else
* V_21 ++ = '0' ;
} else {
* V_21 ++ = '.' ;
}
V_80 >>= 1 ;
V_8 ++ ;
if ( V_8 >= V_83 )
break;
if ( V_8 % 4 == 0 )
* V_21 ++ = ' ' ;
}
* V_21 = '\0' ;
return V_21 ;
}
char *
F_44 ( char * V_9 , const T_1 V_82 , const T_1 V_79 , const int V_83 )
{
char * V_21 ;
V_21 = F_43 ( V_9 , V_82 , V_79 , V_83 ) ;
strcpy ( V_21 , L_48 ) ;
V_21 += 3 ;
return V_21 ;
}
const char *
F_45 ( const T_1 V_82 , const T_1 V_79 , const int V_83 ,
const char * V_84 , const char * V_85 )
{
char * V_9 ;
char * V_21 ;
V_9 = ( char * ) F_10 ( 1025 ) ;
V_21 = F_44 ( V_9 , V_82 , V_79 , V_83 ) ;
if ( V_82 & V_79 )
strcpy ( V_21 , V_84 ) ;
else
strcpy ( V_21 , V_85 ) ;
return V_9 ;
}
const char *
F_46 ( const T_1 V_82 , const T_1 V_79 , const int V_83 ,
const char * V_47 )
{
char * V_9 ;
char * V_21 ;
int V_86 = 0 ;
V_9 = ( char * ) F_10 ( 1025 ) ;
while ( ( V_79 & ( 1 << V_86 ) ) == 0 )
V_86 ++ ;
V_21 = F_44 ( V_9 , V_82 , V_79 , V_83 ) ;
F_36 ( V_21 , ( V_87 ) ( 1025 - ( V_21 - V_9 ) ) , V_47 , ( V_82 & V_79 ) >> V_86 ) ;
return V_9 ;
}
void
F_47 ( const T_4 * V_6 , T_2 * V_9 , const int V_18 )
{
register T_2 const * V_21 ;
register T_2 * V_88 = V_9 ;
if ( V_18 < V_89 ) {
F_36 ( V_9 , V_18 , V_22 ) ;
return;
}
V_21 = V_23 [ * V_6 ++ ] ;
do {
* V_88 ++ = * V_21 ;
V_21 ++ ;
} while( * V_21 );
* V_88 ++ = '.' ;
V_21 = V_23 [ * V_6 ++ ] ;
do {
* V_88 ++ = * V_21 ;
V_21 ++ ;
} while( * V_21 );
* V_88 ++ = '.' ;
V_21 = V_23 [ * V_6 ++ ] ;
do {
* V_88 ++ = * V_21 ;
V_21 ++ ;
} while( * V_21 );
* V_88 ++ = '.' ;
V_21 = V_23 [ * V_6 ] ;
do {
* V_88 ++ = * V_21 ;
V_21 ++ ;
} while( * V_21 );
* V_88 = 0 ;
}
T_2 * F_48 ( const T_15 * V_90 ) {
T_2 * V_9 ;
V_9 = ( T_2 * ) F_10 ( V_91 ) ;
return F_49 ( V_90 , V_9 , V_91 ) ;
}
T_2 * F_49 ( const T_15 * V_90 , T_2 * V_9 , int V_18 ) {
char * V_92 = V_9 ;
if ( V_18 < V_91 ) {
F_16 ( V_9 , V_22 , V_18 ) ;
return V_9 ;
}
V_92 = F_4 ( V_92 , V_90 -> V_93 ) ;
* V_92 ++ = '-' ;
V_92 = F_2 ( V_92 , V_90 -> V_94 ) ;
* V_92 ++ = '-' ;
V_92 = F_2 ( V_92 , V_90 -> V_95 ) ;
* V_92 ++ = '-' ;
V_92 = F_6 ( V_92 , & V_90 -> V_96 [ 0 ] , 2 ) ;
* V_92 ++ = '-' ;
V_92 = F_6 ( V_92 , & V_90 -> V_96 [ 2 ] , 6 ) ;
* V_92 = '\0' ;
return V_9 ;
}
