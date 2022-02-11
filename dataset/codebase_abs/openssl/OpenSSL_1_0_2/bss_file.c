T_1 * F_1 ( const char * V_1 , const char * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 = NULL ;
# if F_2 ( V_5 ) && F_2 ( V_6 )
int V_7 , V_8 = ( int ) strlen ( V_1 ) + 1 ;
T_3 V_9 ;
if ( ( V_7 = F_3 ( V_6 , ( V_9 = V_10 ) ,
V_1 , V_8 , NULL , 0 ) ) > 0 ||
( F_4 () == V_11 &&
( V_7 = F_3 ( V_6 , ( V_9 = 0 ) ,
V_1 , V_8 , NULL , 0 ) ) > 0 )
) {
T_4 V_12 [ 8 ] ;
T_4 * V_13 = F_5 ( V_7 * sizeof( T_4 ) ) ;
if ( F_3 ( V_6 , V_9 ,
V_1 , V_8 , V_13 , V_7 ) &&
F_3 ( V_6 , 0 , V_2 , strlen ( V_2 ) + 1 ,
V_12 , sizeof( V_12 ) / sizeof( V_12 [ 0 ] ) ) &&
( V_4 = F_6 ( V_13 , V_12 ) ) == NULL &&
( V_14 == V_15 || V_14 == V_16 )
) {
V_4 = fopen ( V_1 , V_2 ) ;
}
} else if ( F_4 () == V_17 ) {
V_4 = fopen ( V_1 , V_2 ) ;
}
# else
V_4 = fopen ( V_1 , V_2 ) ;
# endif
if ( V_4 == NULL ) {
F_7 ( V_18 , F_8 () ) ;
F_9 ( 5 , L_1 , V_1 , L_2 , V_2 , L_3 ) ;
if ( V_14 == V_15 )
F_10 ( V_19 , V_20 ) ;
else
F_10 ( V_19 , V_21 ) ;
return ( NULL ) ;
}
if ( ( V_3 = F_11 ( F_12 () ) ) == NULL ) {
fclose ( V_4 ) ;
return ( NULL ) ;
}
F_13 ( V_3 , V_22 ) ;
F_14 ( V_3 , V_4 , V_23 ) ;
return ( V_3 ) ;
}
T_1 * F_15 ( T_2 * V_24 , int V_25 )
{
T_1 * V_3 ;
if ( ( V_3 = F_11 ( F_12 () ) ) == NULL )
return ( NULL ) ;
F_16 ( V_3 , V_22 ) ;
F_14 ( V_3 , V_24 , V_25 ) ;
return ( V_3 ) ;
}
T_5 * F_12 ( void )
{
return ( & V_26 ) ;
}
static int T_6 F_17 ( T_1 * V_27 )
{
V_27 -> V_28 = 0 ;
V_27 -> V_29 = 0 ;
V_27 -> V_30 = NULL ;
V_27 -> V_9 = V_22 ;
return ( 1 ) ;
}
static int T_6 F_18 ( T_1 * V_31 )
{
if ( V_31 == NULL )
return ( 0 ) ;
if ( V_31 -> V_32 ) {
if ( ( V_31 -> V_28 ) && ( V_31 -> V_30 != NULL ) ) {
if ( V_31 -> V_9 & V_22 )
F_19 ( V_31 -> V_30 ) ;
else
fclose ( V_31 -> V_30 ) ;
V_31 -> V_30 = NULL ;
V_31 -> V_9 = V_22 ;
}
V_31 -> V_28 = 0 ;
}
return ( 1 ) ;
}
static int T_6 F_20 ( T_1 * V_33 , char * V_34 , int V_35 )
{
int V_3 = 0 ;
if ( V_33 -> V_28 && ( V_34 != NULL ) ) {
if ( V_33 -> V_9 & V_22 )
V_3 = F_21 ( V_34 , 1 , ( int ) V_35 , V_33 -> V_30 ) ;
else
V_3 = fread ( V_34 , 1 , ( int ) V_35 , ( T_2 * ) V_33 -> V_30 ) ;
if ( V_3 == 0
&& ( V_33 -> V_9 & V_22 ) ? F_22 ( ( T_2 * ) V_33 -> V_30 ) :
ferror ( ( T_2 * ) V_33 -> V_30 ) ) {
F_7 ( V_36 , F_8 () ) ;
F_10 ( V_37 , V_21 ) ;
V_3 = - 1 ;
}
}
return ( V_3 ) ;
}
static int T_6 F_23 ( T_1 * V_33 , const char * V_38 , int V_39 )
{
int V_3 = 0 ;
if ( V_33 -> V_28 && ( V_38 != NULL ) ) {
if ( V_33 -> V_9 & V_22 )
V_3 = F_24 ( V_38 , ( int ) V_39 , 1 , V_33 -> V_30 ) ;
else
V_3 = fwrite ( V_38 , ( int ) V_39 , 1 , ( T_2 * ) V_33 -> V_30 ) ;
if ( V_3 )
V_3 = V_39 ;
}
return ( V_3 ) ;
}
static long T_6 F_25 ( T_1 * V_33 , int V_40 , long V_29 , void * V_30 )
{
long V_3 = 1 ;
T_2 * V_41 = ( T_2 * ) V_33 -> V_30 ;
T_2 * * V_42 ;
char V_43 [ 4 ] ;
switch ( V_40 ) {
case V_44 :
case V_45 :
if ( V_33 -> V_9 & V_22 )
V_3 = ( long ) F_26 ( V_33 -> V_30 , V_29 , 0 ) ;
else
V_3 = ( long ) fseek ( V_41 , V_29 , 0 ) ;
break;
case V_46 :
if ( V_33 -> V_9 & V_22 )
V_3 = ( long ) F_27 ( V_41 ) ;
else
V_3 = ( long ) feof ( V_41 ) ;
break;
case V_47 :
case V_48 :
if ( V_33 -> V_9 & V_22 )
V_3 = F_28 ( V_33 -> V_30 ) ;
else
V_3 = ftell ( V_41 ) ;
break;
case V_49 :
F_18 ( V_33 ) ;
V_33 -> V_32 = ( int ) V_29 & V_23 ;
V_33 -> V_30 = V_30 ;
V_33 -> V_28 = 1 ;
# if V_22 != 0
# if F_2 ( V_50 ) && F_2 ( V_51 ) && ! F_2 ( V_52 )
# define V_52 20
# endif
# if F_2 ( V_52 )
if ( ( V_53 ) V_30 >= ( V_53 ) V_54 &&
( V_53 ) V_30 < ( V_53 ) ( V_54 + V_52 ) )
F_13 ( V_33 , V_22 ) ;
# endif
# endif
# ifdef F_29
if ( V_33 -> V_9 & V_22 )
F_29 ( V_33 -> V_30 , ( char ) ( ( V_29 & V_55 ) ? 't' : 'b' ) ) ;
else
# endif
{
# if F_2 ( V_56 )
int V_57 = F_30 ( ( T_2 * ) V_30 ) ;
if ( V_29 & V_55 )
F_31 ( V_57 , V_58 ) ;
else
F_31 ( V_57 , V_59 ) ;
# elif F_2 ( V_60 ) && F_2 ( V_61 )
int V_57 = fileno ( ( T_2 * ) V_30 ) ;
if ( V_29 & V_55 )
F_32 ( V_57 , V_62 ) ;
else
F_32 ( V_57 , V_63 ) ;
# elif F_2 ( V_64 )
int V_57 = fileno ( ( T_2 * ) V_30 ) ;
if ( V_29 & V_55 )
F_31 ( V_57 , V_58 ) ;
else {
if ( V_57 == V_65 || V_57 == V_66 ) {
if ( F_33 ( V_57 ) <= 0 )
F_31 ( V_57 , V_59 ) ;
} else
F_31 ( V_57 , V_59 ) ;
}
# elif F_2 ( V_67 ) || F_2 ( V_68 )
int V_57 = fileno ( ( T_2 * ) V_30 ) ;
if ( V_29 & V_55 )
F_32 ( V_57 , V_62 ) ;
else
F_32 ( V_57 , V_63 ) ;
# endif
}
break;
case V_69 :
F_18 ( V_33 ) ;
V_33 -> V_32 = ( int ) V_29 & V_23 ;
if ( V_29 & V_70 ) {
if ( V_29 & V_71 )
F_34 ( V_43 , L_4 , sizeof V_43 ) ;
else
F_34 ( V_43 , L_5 , sizeof V_43 ) ;
} else if ( ( V_29 & V_71 ) && ( V_29 & V_72 ) )
F_34 ( V_43 , L_6 , sizeof V_43 ) ;
else if ( V_29 & V_72 )
F_34 ( V_43 , L_7 , sizeof V_43 ) ;
else if ( V_29 & V_71 )
F_34 ( V_43 , L_8 , sizeof V_43 ) ;
else {
F_10 ( V_73 , V_74 ) ;
V_3 = 0 ;
break;
}
# if F_2 ( V_64 ) || F_2 ( V_56 ) || F_2 ( V_67 ) || F_2 ( V_68 )
if ( ! ( V_29 & V_55 ) )
strcat ( V_43 , L_9 ) ;
else
strcat ( V_43 , L_10 ) ;
# endif
# if F_2 ( V_60 )
if ( ! ( V_29 & V_55 ) )
strcat ( V_43 , L_9 ) ;
else
strcat ( V_43 , L_10 ) ;
# endif
V_41 = fopen ( V_30 , V_43 ) ;
if ( V_41 == NULL ) {
F_7 ( V_18 , F_8 () ) ;
F_9 ( 5 , L_1 , V_30 , L_2 , V_43 , L_3 ) ;
F_10 ( V_73 , V_21 ) ;
V_3 = 0 ;
break;
}
V_33 -> V_30 = V_41 ;
V_33 -> V_28 = 1 ;
F_13 ( V_33 , V_22 ) ;
break;
case V_75 :
if ( V_30 != NULL ) {
V_42 = ( T_2 * * ) V_30 ;
* V_42 = ( T_2 * ) V_33 -> V_30 ;
}
break;
case V_76 :
V_3 = ( long ) V_33 -> V_32 ;
break;
case V_77 :
V_33 -> V_32 = ( int ) V_29 ;
break;
case V_78 :
if ( V_33 -> V_9 & V_22 )
F_35 ( V_33 -> V_30 ) ;
else
fflush ( ( T_2 * ) V_33 -> V_30 ) ;
break;
case V_79 :
V_3 = 1 ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static int T_6 F_36 ( T_1 * V_84 , char * V_85 , int V_86 )
{
int V_3 = 0 ;
V_85 [ 0 ] = '\0' ;
if ( V_84 -> V_9 & V_22 ) {
if ( ! F_37 ( V_85 , V_86 , V_84 -> V_30 ) )
goto V_87;
} else {
if ( ! fgets ( V_85 , V_86 , ( T_2 * ) V_84 -> V_30 ) )
goto V_87;
}
if ( V_85 [ 0 ] != '\0' )
V_3 = strlen ( V_85 ) ;
V_87:
return ( V_3 ) ;
}
static int T_6 F_38 ( T_1 * V_84 , const char * V_88 )
{
int V_89 , V_3 ;
V_89 = strlen ( V_88 ) ;
V_3 = F_23 ( V_84 , V_88 , V_89 ) ;
return ( V_3 ) ;
}
