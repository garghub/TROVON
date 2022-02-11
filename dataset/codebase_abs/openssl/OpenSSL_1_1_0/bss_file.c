T_1 * F_1 ( const char * V_1 , const char * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 = F_2 ( V_1 , V_2 ) ;
int V_5 = V_6 ;
if ( strchr ( V_2 , 'b' ) == NULL )
V_5 |= V_7 ;
if ( V_4 == NULL ) {
F_3 ( V_8 , F_4 () ) ;
F_5 ( 5 , L_1 , V_1 , L_2 , V_2 , L_3 ) ;
if ( V_9 == V_10 )
F_6 ( V_11 , V_12 ) ;
else
F_6 ( V_11 , V_13 ) ;
return ( NULL ) ;
}
if ( ( V_3 = F_7 ( F_8 () ) ) == NULL ) {
fclose ( V_4 ) ;
return ( NULL ) ;
}
F_9 ( V_3 , V_14 ) ;
F_10 ( V_3 , V_4 , V_5 ) ;
return ( V_3 ) ;
}
T_1 * F_11 ( T_2 * V_15 , int V_16 )
{
T_1 * V_3 ;
if ( ( V_3 = F_7 ( F_8 () ) ) == NULL )
return ( NULL ) ;
F_12 ( V_3 , V_14 ) ;
F_10 ( V_3 , V_15 , V_16 ) ;
return ( V_3 ) ;
}
const T_3 * F_8 ( void )
{
return ( & V_17 ) ;
}
static int F_13 ( T_1 * V_18 )
{
V_18 -> V_19 = 0 ;
V_18 -> V_20 = 0 ;
V_18 -> V_21 = NULL ;
V_18 -> V_22 = V_14 ;
return ( 1 ) ;
}
static int F_14 ( T_1 * V_23 )
{
if ( V_23 == NULL )
return ( 0 ) ;
if ( V_23 -> V_24 ) {
if ( ( V_23 -> V_19 ) && ( V_23 -> V_21 != NULL ) ) {
if ( V_23 -> V_22 & V_14 )
F_15 ( V_23 -> V_21 ) ;
else
fclose ( V_23 -> V_21 ) ;
V_23 -> V_21 = NULL ;
V_23 -> V_22 = V_14 ;
}
V_23 -> V_19 = 0 ;
}
return ( 1 ) ;
}
static int F_16 ( T_1 * V_25 , char * V_26 , int V_27 )
{
int V_3 = 0 ;
if ( V_25 -> V_19 && ( V_26 != NULL ) ) {
if ( V_25 -> V_22 & V_14 )
V_3 = F_17 ( V_26 , 1 , ( int ) V_27 , V_25 -> V_21 ) ;
else
V_3 = fread ( V_26 , 1 , ( int ) V_27 , ( T_2 * ) V_25 -> V_21 ) ;
if ( V_3 == 0
&& ( V_25 -> V_22 & V_14 ) ? F_18 ( ( T_2 * ) V_25 -> V_21 ) :
ferror ( ( T_2 * ) V_25 -> V_21 ) ) {
F_3 ( V_28 , F_4 () ) ;
F_6 ( V_29 , V_13 ) ;
V_3 = - 1 ;
}
}
return ( V_3 ) ;
}
static int F_19 ( T_1 * V_25 , const char * V_30 , int V_31 )
{
int V_3 = 0 ;
if ( V_25 -> V_19 && ( V_30 != NULL ) ) {
if ( V_25 -> V_22 & V_14 )
V_3 = F_20 ( V_30 , ( int ) V_31 , 1 , V_25 -> V_21 ) ;
else
V_3 = fwrite ( V_30 , ( int ) V_31 , 1 , ( T_2 * ) V_25 -> V_21 ) ;
if ( V_3 )
V_3 = V_31 ;
}
return ( V_3 ) ;
}
static long F_21 ( T_1 * V_25 , int V_32 , long V_20 , void * V_21 )
{
long V_3 = 1 ;
T_2 * V_33 = ( T_2 * ) V_25 -> V_21 ;
T_2 * * V_34 ;
char V_35 [ 4 ] ;
switch ( V_32 ) {
case V_36 :
case V_37 :
if ( V_25 -> V_22 & V_14 )
V_3 = ( long ) F_22 ( V_25 -> V_21 , V_20 , 0 ) ;
else
V_3 = ( long ) fseek ( V_33 , V_20 , 0 ) ;
break;
case V_38 :
if ( V_25 -> V_22 & V_14 )
V_3 = ( long ) F_23 ( V_33 ) ;
else
V_3 = ( long ) feof ( V_33 ) ;
break;
case V_39 :
case V_40 :
if ( V_25 -> V_22 & V_14 )
V_3 = F_24 ( V_25 -> V_21 ) ;
else
V_3 = ftell ( V_33 ) ;
break;
case V_41 :
F_14 ( V_25 ) ;
V_25 -> V_24 = ( int ) V_20 & V_6 ;
V_25 -> V_21 = V_21 ;
V_25 -> V_19 = 1 ;
# if V_14 != 0
# if F_25 ( V_42 ) && F_25 ( V_43 ) && ! F_25 ( V_44 )
# define V_44 20
# endif
# if F_25 ( V_45 ) && V_45 >= 1900
if ( V_21 == V_46 || V_21 == stdout || V_21 == V_47 )
F_9 ( V_25 , V_14 ) ;
# elif F_25 ( V_44 )
if ( ( V_48 ) V_21 >= ( V_48 ) V_46 &&
( V_48 ) V_21 < ( V_48 ) ( V_46 + V_44 ) )
F_9 ( V_25 , V_14 ) ;
# endif
# endif
# ifdef F_26
if ( V_25 -> V_22 & V_14 )
F_26 ( V_25 -> V_21 , ( char ) ( ( V_20 & V_7 ) ? 't' : 'b' ) ) ;
else
# endif
{
# if F_25 ( V_49 )
int V_50 = F_27 ( ( T_2 * ) V_21 ) ;
if ( V_20 & V_7 )
F_28 ( V_50 , V_51 ) ;
else
F_28 ( V_50 , V_52 ) ;
# elif F_25 ( V_53 )
int V_50 = fileno ( ( T_2 * ) V_21 ) ;
if ( V_20 & V_7 )
F_28 ( V_50 , V_51 ) ;
else {
if ( V_50 == V_54 || V_50 == V_55 ) {
if ( F_29 ( V_50 ) <= 0 )
F_28 ( V_50 , V_52 ) ;
} else
F_28 ( V_50 , V_52 ) ;
}
# elif F_25 ( V_56 )
int V_50 = fileno ( ( T_2 * ) V_21 ) ;
if ( V_20 & V_7 )
F_30 ( V_50 , V_57 ) ;
else
F_30 ( V_50 , V_58 ) ;
# endif
}
break;
case V_59 :
F_14 ( V_25 ) ;
V_25 -> V_24 = ( int ) V_20 & V_6 ;
if ( V_20 & V_60 ) {
if ( V_20 & V_61 )
F_31 ( V_35 , L_4 , sizeof V_35 ) ;
else
F_31 ( V_35 , L_5 , sizeof V_35 ) ;
} else if ( ( V_20 & V_61 ) && ( V_20 & V_62 ) )
F_31 ( V_35 , L_6 , sizeof V_35 ) ;
else if ( V_20 & V_62 )
F_31 ( V_35 , L_7 , sizeof V_35 ) ;
else if ( V_20 & V_61 )
F_31 ( V_35 , L_8 , sizeof V_35 ) ;
else {
F_6 ( V_63 , V_64 ) ;
V_3 = 0 ;
break;
}
# if F_25 ( V_53 ) || F_25 ( V_49 ) || F_25 ( V_56 )
if ( ! ( V_20 & V_7 ) )
strcat ( V_35 , L_9 ) ;
else
strcat ( V_35 , L_10 ) ;
# endif
V_33 = F_2 ( V_21 , V_35 ) ;
if ( V_33 == NULL ) {
F_3 ( V_8 , F_4 () ) ;
F_5 ( 5 , L_1 , V_21 , L_2 , V_35 , L_3 ) ;
F_6 ( V_63 , V_13 ) ;
V_3 = 0 ;
break;
}
V_25 -> V_21 = V_33 ;
V_25 -> V_19 = 1 ;
F_9 ( V_25 , V_14 ) ;
break;
case V_65 :
if ( V_21 != NULL ) {
V_34 = ( T_2 * * ) V_21 ;
* V_34 = ( T_2 * ) V_25 -> V_21 ;
}
break;
case V_66 :
V_3 = ( long ) V_25 -> V_24 ;
break;
case V_67 :
V_25 -> V_24 = ( int ) V_20 ;
break;
case V_68 :
if ( V_25 -> V_22 & V_14 )
F_32 ( V_25 -> V_21 ) ;
else
fflush ( ( T_2 * ) V_25 -> V_21 ) ;
break;
case V_69 :
V_3 = 1 ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static int F_33 ( T_1 * V_74 , char * V_75 , int V_76 )
{
int V_3 = 0 ;
V_75 [ 0 ] = '\0' ;
if ( V_74 -> V_22 & V_14 ) {
if ( ! F_34 ( V_75 , V_76 , V_74 -> V_21 ) )
goto V_77;
} else {
if ( ! fgets ( V_75 , V_76 , ( T_2 * ) V_74 -> V_21 ) )
goto V_77;
}
if ( V_75 [ 0 ] != '\0' )
V_3 = strlen ( V_75 ) ;
V_77:
return ( V_3 ) ;
}
static int F_35 ( T_1 * V_74 , const char * V_78 )
{
int V_79 , V_3 ;
V_79 = strlen ( V_78 ) ;
V_3 = F_19 ( V_74 , V_78 , V_79 ) ;
return ( V_3 ) ;
}
static int F_19 ( T_1 * V_25 , const char * V_30 , int V_31 )
{
return - 1 ;
}
static int F_16 ( T_1 * V_25 , char * V_26 , int V_27 )
{
return - 1 ;
}
static int F_35 ( T_1 * V_74 , const char * V_78 )
{
return - 1 ;
}
static int F_33 ( T_1 * V_74 , char * V_75 , int V_76 )
{
return 0 ;
}
static long F_21 ( T_1 * V_25 , int V_32 , long V_20 , void * V_21 )
{
return 0 ;
}
static int F_13 ( T_1 * V_18 )
{
return 0 ;
}
static int F_14 ( T_1 * V_23 )
{
return 0 ;
}
const T_3 * F_8 ( void )
{
return ( & V_17 ) ;
}
T_1 * F_1 ( const char * V_1 , const char * V_2 )
{
return NULL ;
}
