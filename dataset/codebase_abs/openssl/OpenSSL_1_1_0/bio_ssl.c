const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 = F_3 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL ) {
F_4 ( V_4 , V_5 ) ;
return ( 0 ) ;
}
F_5 ( V_2 , 0 ) ;
F_6 ( V_2 , V_3 ) ;
F_7 ( V_2 , ~ 0 ) ;
return 1 ;
}
static int F_8 ( T_2 * V_6 )
{
T_3 * V_3 ;
if ( V_6 == NULL )
return ( 0 ) ;
V_3 = F_9 ( V_6 ) ;
if ( V_3 -> V_7 != NULL )
F_10 ( V_3 -> V_7 ) ;
if ( F_11 ( V_6 ) ) {
if ( F_12 ( V_6 ) )
F_13 ( V_3 -> V_7 ) ;
F_7 ( V_6 , ~ 0 ) ;
F_5 ( V_6 , 0 ) ;
}
F_14 ( V_3 ) ;
return 1 ;
}
static int F_15 ( T_2 * V_8 , char * V_9 , int V_10 )
{
int V_11 = 1 ;
T_3 * V_12 ;
T_4 * V_7 ;
int V_13 = 0 ;
int V_14 = 0 ;
if ( V_9 == NULL )
return ( 0 ) ;
V_12 = F_9 ( V_8 ) ;
V_7 = V_12 -> V_7 ;
F_16 ( V_8 ) ;
V_11 = F_17 ( V_7 , V_9 , V_10 ) ;
switch ( F_18 ( V_7 , V_11 ) ) {
case V_15 :
if ( V_11 <= 0 )
break;
if ( V_12 -> V_16 > 0 ) {
V_12 -> V_17 += V_11 ;
if ( V_12 -> V_17 > V_12 -> V_16 ) {
V_12 -> V_17 = 0 ;
V_12 -> V_18 ++ ;
F_19 ( V_7 ) ;
V_14 = 1 ;
}
}
if ( ( V_12 -> V_19 > 0 ) && ( ! V_14 ) ) {
unsigned long V_20 ;
V_20 = ( unsigned long ) time ( NULL ) ;
if ( V_20 > V_12 -> V_21 + V_12 -> V_19 ) {
V_12 -> V_21 = V_20 ;
V_12 -> V_18 ++ ;
F_19 ( V_7 ) ;
}
}
break;
case V_22 :
F_20 ( V_8 ) ;
break;
case V_23 :
F_21 ( V_8 ) ;
break;
case V_24 :
F_22 ( V_8 ) ;
V_13 = V_25 ;
break;
case V_26 :
F_22 ( V_8 ) ;
V_13 = V_27 ;
break;
case V_28 :
F_22 ( V_8 ) ;
V_13 = V_29 ;
break;
case V_30 :
case V_31 :
case V_32 :
default:
break;
}
F_23 ( V_8 , V_13 ) ;
return ( V_11 ) ;
}
static int F_24 ( T_2 * V_8 , const char * V_9 , int V_10 )
{
int V_11 , V_14 = 0 ;
int V_13 = 0 ;
T_4 * V_7 ;
T_3 * V_3 ;
if ( V_9 == NULL )
return ( 0 ) ;
V_3 = F_9 ( V_8 ) ;
V_7 = V_3 -> V_7 ;
F_16 ( V_8 ) ;
V_11 = F_25 ( V_7 , V_9 , V_10 ) ;
switch ( F_18 ( V_7 , V_11 ) ) {
case V_15 :
if ( V_11 <= 0 )
break;
if ( V_3 -> V_16 > 0 ) {
V_3 -> V_17 += V_11 ;
if ( V_3 -> V_17 > V_3 -> V_16 ) {
V_3 -> V_17 = 0 ;
V_3 -> V_18 ++ ;
F_19 ( V_7 ) ;
V_14 = 1 ;
}
}
if ( ( V_3 -> V_19 > 0 ) && ( ! V_14 ) ) {
unsigned long V_20 ;
V_20 = ( unsigned long ) time ( NULL ) ;
if ( V_20 > V_3 -> V_21 + V_3 -> V_19 ) {
V_3 -> V_21 = V_20 ;
V_3 -> V_18 ++ ;
F_19 ( V_7 ) ;
}
}
break;
case V_23 :
F_21 ( V_8 ) ;
break;
case V_22 :
F_20 ( V_8 ) ;
break;
case V_24 :
F_22 ( V_8 ) ;
V_13 = V_25 ;
break;
case V_28 :
F_22 ( V_8 ) ;
V_13 = V_29 ;
case V_30 :
case V_31 :
default:
break;
}
F_23 ( V_8 , V_13 ) ;
return V_11 ;
}
static long F_26 ( T_2 * V_8 , int V_33 , long V_34 , void * V_35 )
{
T_4 * * V_36 , * V_7 ;
T_3 * V_3 , * V_37 ;
T_2 * V_38 , * V_39 ;
long V_11 = 1 ;
T_2 * V_40 ;
V_3 = F_9 ( V_8 ) ;
V_40 = F_27 ( V_8 ) ;
V_7 = V_3 -> V_7 ;
if ( ( V_7 == NULL ) && ( V_33 != V_41 ) )
return ( 0 ) ;
switch ( V_33 ) {
case V_42 :
F_10 ( V_7 ) ;
if ( V_7 -> V_43 == V_7 -> V_44 -> V_45 )
F_28 ( V_7 ) ;
else if ( V_7 -> V_43 == V_7 -> V_44 -> V_46 )
F_29 ( V_7 ) ;
if ( ! F_30 ( V_7 ) ) {
V_11 = 0 ;
break;
}
if ( V_40 != NULL )
V_11 = F_31 ( V_40 , V_33 , V_34 , V_35 ) ;
else if ( V_7 -> V_47 != NULL )
V_11 = F_31 ( V_7 -> V_47 , V_33 , V_34 , V_35 ) ;
else
V_11 = 1 ;
break;
case V_48 :
V_11 = 0 ;
break;
case V_49 :
if ( V_34 )
F_28 ( V_7 ) ;
else
F_29 ( V_7 ) ;
break;
case V_50 :
V_11 = V_3 -> V_19 ;
if ( V_34 < 60 )
V_34 = 5 ;
V_3 -> V_19 = ( unsigned long ) V_34 ;
V_3 -> V_21 = ( unsigned long ) time ( NULL ) ;
break;
case V_51 :
V_11 = V_3 -> V_16 ;
if ( ( long ) V_34 >= 512 )
V_3 -> V_16 = ( unsigned long ) V_34 ;
break;
case V_52 :
V_11 = V_3 -> V_18 ;
break;
case V_41 :
if ( V_7 != NULL ) {
F_8 ( V_8 ) ;
if ( ! F_2 ( V_8 ) )
return 0 ;
}
F_32 ( V_8 , V_34 ) ;
V_7 = ( T_4 * ) V_35 ;
V_3 -> V_7 = V_7 ;
V_39 = F_33 ( V_7 ) ;
if ( V_39 != NULL ) {
if ( V_40 != NULL )
F_34 ( V_39 , V_40 ) ;
F_35 ( V_8 , V_39 ) ;
F_36 ( V_39 ) ;
}
F_5 ( V_8 , 1 ) ;
break;
case V_53 :
if ( V_35 != NULL ) {
V_36 = ( T_4 * * ) V_35 ;
* V_36 = V_7 ;
} else
V_11 = 0 ;
break;
case V_54 :
V_11 = F_11 ( V_8 ) ;
break;
case V_55 :
F_32 ( V_8 , ( int ) V_34 ) ;
break;
case V_56 :
V_11 = F_31 ( V_7 -> V_57 , V_33 , V_34 , V_35 ) ;
break;
case V_58 :
V_11 = F_37 ( V_7 ) ;
if ( V_11 == 0 )
V_11 = F_38 ( V_7 -> V_47 ) ;
break;
case V_59 :
F_16 ( V_8 ) ;
V_11 = F_31 ( V_7 -> V_57 , V_33 , V_34 , V_35 ) ;
F_39 ( V_8 ) ;
break;
case V_60 :
if ( ( V_40 != NULL ) && ( V_40 != V_7 -> V_47 ) ) {
F_36 ( V_40 ) ;
F_40 ( V_7 , V_40 , V_40 ) ;
}
break;
case V_61 :
if ( V_8 == V_35 ) {
F_40 ( V_7 , NULL , NULL ) ;
}
break;
case V_62 :
F_16 ( V_8 ) ;
F_23 ( V_8 , 0 ) ;
V_11 = ( int ) F_41 ( V_7 ) ;
switch ( F_18 ( V_7 , ( int ) V_11 ) ) {
case V_22 :
F_42 ( V_8 , V_63 | V_64 ) ;
break;
case V_23 :
F_42 ( V_8 , V_65 | V_64 ) ;
break;
case V_28 :
F_42 ( V_8 , V_66 | V_64 ) ;
F_23 ( V_8 , F_43 ( V_40 ) ) ;
break;
case V_24 :
F_22 ( V_8 ) ;
F_23 ( V_8 , V_25 ) ;
break;
default:
break;
}
break;
case V_67 :
V_38 = ( T_2 * ) V_35 ;
V_37 = F_9 ( V_38 ) ;
F_13 ( V_37 -> V_7 ) ;
V_37 -> V_7 = F_44 ( V_7 ) ;
V_37 -> V_18 = V_3 -> V_18 ;
V_37 -> V_16 = V_3 -> V_16 ;
V_37 -> V_17 = V_3 -> V_17 ;
V_37 -> V_19 = V_3 -> V_19 ;
V_37 -> V_21 = V_3 -> V_21 ;
V_11 = ( V_37 -> V_7 != NULL ) ;
break;
case V_68 :
V_11 = F_31 ( V_7 -> V_47 , V_33 , V_34 , V_35 ) ;
break;
case V_69 :
{
#if 0
SSLerr(SSL_F_SSL_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
ret = -1;
#else
V_11 = 0 ;
#endif
}
break;
case V_70 :
{
void (* * F_45) ( const T_4 * V_71 , int type , int V_72 );
F_45 = ( void (**) ( const T_4 * V_71 , int type , int V_72 ) ) V_35 ;
* F_45 = F_46 ( V_7 ) ;
}
break;
default:
V_11 = F_31 ( V_7 -> V_47 , V_33 , V_34 , V_35 ) ;
break;
}
return ( V_11 ) ;
}
static long F_47 ( T_2 * V_8 , int V_33 , T_5 * V_73 )
{
T_4 * V_7 ;
T_3 * V_3 ;
long V_11 = 1 ;
V_3 = F_9 ( V_8 ) ;
V_7 = V_3 -> V_7 ;
switch ( V_33 ) {
case V_69 :
{
F_48 ( V_7 , ( void ( * ) ( const T_4 * , int , int ) ) V_73 ) ;
}
break;
default:
V_11 = F_49 ( V_7 -> V_47 , V_33 , V_73 ) ;
break;
}
return ( V_11 ) ;
}
static int F_50 ( T_2 * V_74 , const char * V_75 )
{
int V_76 , V_11 ;
V_76 = strlen ( V_75 ) ;
V_11 = F_51 ( V_74 , V_75 , V_76 ) ;
return ( V_11 ) ;
}
T_2 * F_52 ( T_6 * V_77 )
{
#ifndef F_53
T_2 * V_11 = NULL , * V_78 = NULL , * V_7 = NULL ;
if ( ( V_78 = F_54 ( F_55 () ) ) == NULL )
return ( NULL ) ;
if ( ( V_7 = F_56 ( V_77 ) ) == NULL )
goto V_79;
if ( ( V_11 = F_34 ( V_78 , V_7 ) ) == NULL )
goto V_79;
return ( V_11 ) ;
V_79:
F_57 ( V_78 ) ;
F_57 ( V_7 ) ;
#endif
return ( NULL ) ;
}
T_2 * F_56 ( T_6 * V_77 )
{
#ifndef F_53
T_2 * V_11 = NULL , * V_80 = NULL , * V_7 = NULL ;
if ( ( V_80 = F_54 ( F_58 () ) ) == NULL )
return ( NULL ) ;
if ( ( V_7 = F_59 ( V_77 , 1 ) ) == NULL )
goto V_79;
if ( ( V_11 = F_34 ( V_7 , V_80 ) ) == NULL )
goto V_79;
return ( V_11 ) ;
V_79:
F_57 ( V_80 ) ;
#endif
return ( NULL ) ;
}
T_2 * F_59 ( T_6 * V_77 , int V_81 )
{
T_2 * V_11 ;
T_4 * V_7 ;
if ( ( V_11 = F_54 ( F_1 () ) ) == NULL )
return ( NULL ) ;
if ( ( V_7 = F_60 ( V_77 ) ) == NULL ) {
F_57 ( V_11 ) ;
return ( NULL ) ;
}
if ( V_81 )
F_28 ( V_7 ) ;
else
F_29 ( V_7 ) ;
F_61 ( V_11 , V_7 , V_82 ) ;
return ( V_11 ) ;
}
int F_62 ( T_2 * V_83 , T_2 * V_84 )
{
T_3 * V_85 , * V_86 ;
V_83 = F_63 ( V_83 , V_87 ) ;
V_84 = F_63 ( V_84 , V_87 ) ;
if ( ( V_83 == NULL ) || ( V_84 == NULL ) )
return 0 ;
V_85 = F_9 ( V_83 ) ;
V_86 = F_9 ( V_84 ) ;
if ( ( V_85 -> V_7 == NULL ) || ( V_86 -> V_7 == NULL ) )
return ( 0 ) ;
if ( ! F_64 ( V_85 -> V_7 , ( V_86 -> V_7 ) ) )
return 0 ;
return ( 1 ) ;
}
void F_65 ( T_2 * V_8 )
{
T_4 * V_88 ;
V_8 = F_63 ( V_8 , V_87 ) ;
if ( V_8 == NULL )
return;
V_88 = F_9 ( V_8 ) ;
F_10 ( V_88 ) ;
}
