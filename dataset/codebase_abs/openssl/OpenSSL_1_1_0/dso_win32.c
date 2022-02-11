static T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
T_4 V_3 [ 64 ] ;
int V_4 ;
for ( V_4 = 0 ; V_2 [ V_4 ] && V_4 < 64 ; V_4 ++ )
V_3 [ V_4 ] = ( T_4 ) V_2 [ V_4 ] ;
if ( V_4 == 64 )
return NULL ;
V_3 [ V_4 ] = 0 ;
return F_2 ( V_1 , V_3 ) ;
}
static T_5 F_3 ( T_3 V_5 )
{
T_4 * V_6 ;
T_6 V_7 = strlen ( V_5 ) + 1 , V_4 ;
# ifdef F_4
V_6 = ( T_4 * ) F_5 ( V_7 * sizeof( T_4 ) ) ;
# else
V_6 = ( T_4 * ) F_6 ( V_7 * sizeof( T_4 ) ) ;
# endif
if ( V_6 == NULL ) {
F_7 ( V_8 ) ;
return NULL ;
}
# if F_8 ( V_9 ) && V_9 >= 101
if ( ! F_9 ( V_10 , 0 , V_5 , V_7 , V_6 , V_7 ) )
# endif
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
V_6 [ V_4 ] = ( T_4 ) V_5 [ V_4 ] ;
return F_10 ( V_6 ) ;
}
T_7 * F_11 ( void )
{
return & V_11 ;
}
static int F_12 ( T_8 * V_12 )
{
T_5 V_13 = NULL , * V_14 = NULL ;
char * V_15 = F_13 ( V_12 , NULL ) ;
if ( V_15 == NULL ) {
F_14 ( V_16 , V_17 ) ;
goto V_18;
}
V_13 = F_3 ( V_15 ) ;
if ( V_13 == NULL ) {
F_14 ( V_16 , V_19 ) ;
F_15 ( 3 , L_1 , V_15 , L_2 ) ;
goto V_18;
}
V_14 = F_16 ( sizeof( * V_14 ) ) ;
if ( V_14 == NULL ) {
F_14 ( V_16 , V_20 ) ;
goto V_18;
}
* V_14 = V_13 ;
if ( ! F_17 ( V_12 -> V_21 , V_14 ) ) {
F_14 ( V_16 , V_22 ) ;
goto V_18;
}
V_12 -> V_23 = V_15 ;
return ( 1 ) ;
V_18:
F_18 ( V_15 ) ;
F_18 ( V_14 ) ;
if ( V_13 != NULL )
F_19 ( V_13 ) ;
return ( 0 ) ;
}
static int F_20 ( T_8 * V_12 )
{
T_5 * V_14 ;
if ( V_12 == NULL ) {
F_14 ( V_24 , V_25 ) ;
return ( 0 ) ;
}
if ( F_21 ( V_12 -> V_21 ) < 1 )
return ( 1 ) ;
V_14 = F_22 ( V_12 -> V_21 ) ;
if ( V_14 == NULL ) {
F_14 ( V_24 , V_26 ) ;
return ( 0 ) ;
}
if ( ! F_19 ( * V_14 ) ) {
F_14 ( V_24 , V_27 ) ;
F_17 ( V_12 -> V_21 , V_14 ) ;
return ( 0 ) ;
}
F_18 ( V_14 ) ;
return ( 1 ) ;
}
static T_9 F_23 ( T_8 * V_12 , const char * V_28 )
{
T_5 * V_29 ;
union {
void * V_14 ;
T_1 V_30 ;
} V_31 ;
if ( ( V_12 == NULL ) || ( V_28 == NULL ) ) {
F_14 ( V_32 , V_25 ) ;
return ( NULL ) ;
}
if ( F_21 ( V_12 -> V_21 ) < 1 ) {
F_14 ( V_32 , V_22 ) ;
return ( NULL ) ;
}
V_29 = F_24 ( V_12 -> V_21 , F_21 ( V_12 -> V_21 ) - 1 ) ;
if ( V_29 == NULL ) {
F_14 ( V_32 , V_26 ) ;
return ( NULL ) ;
}
V_31 . V_30 = F_25 ( * V_29 , V_28 ) ;
if ( V_31 . V_14 == NULL ) {
F_14 ( V_32 , V_33 ) ;
F_15 ( 3 , L_3 , V_28 , L_2 ) ;
return ( NULL ) ;
}
return ( ( T_9 ) V_31 . V_30 ) ;
}
static struct V_34 * F_26 ( T_8 * V_12 , const char * V_15 ,
int V_35 )
{
struct V_34 * V_36 = NULL ;
enum { V_37 , V_38 , V_39 } V_40 ;
const char * V_41 = V_15 ;
char V_42 ;
if ( ! V_15 ) {
F_14 ( V_43 , V_17 ) ;
return ( NULL ) ;
}
V_36 = F_27 ( sizeof( * V_36 ) ) ;
if ( V_36 == NULL ) {
F_14 ( V_43 , V_20 ) ;
return ( NULL ) ;
}
V_40 = V_38 ;
if ( ( V_15 [ 0 ] == '\\' && V_15 [ 1 ] == '\\' )
|| ( V_15 [ 0 ] == '/' && V_15 [ 1 ] == '/' ) ) {
V_40 = V_37 ;
V_15 += 2 ;
V_41 = V_15 ;
V_36 -> V_44 = V_41 ;
}
do {
V_42 = V_15 [ 0 ] ;
switch ( V_42 ) {
case ':' :
if ( V_40 != V_38 ) {
F_14 ( V_43 , V_45 ) ;
F_18 ( V_36 ) ;
return ( NULL ) ;
}
V_36 -> V_46 = V_41 ;
V_36 -> V_47 = ( int ) ( V_15 - V_41 ) ;
V_40 = V_39 ;
V_41 = ++ V_15 ;
V_36 -> V_48 = V_41 ;
break;
case '\\' :
case '/' :
if ( V_40 == V_37 ) {
V_36 -> V_49 = ( int ) ( V_15 - V_41 ) ;
V_40 = V_39 ;
V_41 = ++ V_15 ;
V_36 -> V_48 = V_41 ;
} else if ( V_40 == V_38 ) {
V_40 = V_39 ;
V_15 ++ ;
V_36 -> V_48 = V_41 ;
V_36 -> V_50 = ( int ) ( V_15 - V_41 ) ;
V_41 = V_15 ;
} else {
V_15 ++ ;
V_36 -> V_50 += ( int ) ( V_15 - V_41 ) ;
V_41 = V_15 ;
}
break;
case '\0' :
if ( V_40 == V_37 ) {
V_36 -> V_49 = ( int ) ( V_15 - V_41 ) ;
} else {
if ( V_15 - V_41 > 0 ) {
if ( V_35 ) {
if ( V_40 == V_38 ) {
V_36 -> V_48 = V_41 ;
V_36 -> V_50 = 0 ;
}
V_36 -> V_50 += ( int ) ( V_15 - V_41 ) ;
} else {
V_36 -> V_51 = V_41 ;
V_36 -> V_52 = ( int ) ( V_15 - V_41 ) ;
}
}
}
break;
default:
V_15 ++ ;
break;
}
}
while ( V_42 );
if ( ! V_36 -> V_49 )
V_36 -> V_44 = NULL ;
if ( ! V_36 -> V_47 )
V_36 -> V_46 = NULL ;
if ( ! V_36 -> V_50 )
V_36 -> V_48 = NULL ;
if ( ! V_36 -> V_52 )
V_36 -> V_51 = NULL ;
return ( V_36 ) ;
}
static char * F_28 ( T_8 * V_12 , const struct V_34 * V_53 )
{
int V_54 = 0 , V_55 = 0 ;
char * V_36 = NULL ;
const char * V_41 ;
if ( ! V_53 ) {
F_14 ( V_56 , V_25 ) ;
return ( NULL ) ;
}
if ( V_53 -> V_44 ) {
V_54 += 2 + V_53 -> V_49 ;
if ( V_53 -> V_57 || V_53 -> V_48 || V_53 -> V_51 )
V_54 ++ ;
} else if ( V_53 -> V_46 ) {
V_54 += V_53 -> V_47 + 1 ;
}
V_54 += V_53 -> V_58 ;
if ( V_53 -> V_57 && ( V_53 -> V_48 || V_53 -> V_51 ) ) {
V_54 ++ ;
}
V_54 += V_53 -> V_50 ;
if ( V_53 -> V_48 && V_53 -> V_51 ) {
V_54 ++ ;
}
V_54 += V_53 -> V_52 ;
if ( ! V_54 ) {
F_14 ( V_56 , V_59 ) ;
return ( NULL ) ;
}
V_36 = F_16 ( V_54 + 1 ) ;
if ( V_36 == NULL ) {
F_14 ( V_56 , V_20 ) ;
return ( NULL ) ;
}
if ( V_53 -> V_44 ) {
strcpy ( & V_36 [ V_55 ] , L_4 ) ;
V_55 += 2 ;
strncpy ( & V_36 [ V_55 ] , V_53 -> V_44 , V_53 -> V_49 ) ;
V_55 += V_53 -> V_49 ;
if ( V_53 -> V_57 || V_53 -> V_48 || V_53 -> V_51 ) {
V_36 [ V_55 ] = '\\' ;
V_55 ++ ;
}
} else if ( V_53 -> V_46 ) {
strncpy ( & V_36 [ V_55 ] , V_53 -> V_46 , V_53 -> V_47 ) ;
V_55 += V_53 -> V_47 ;
V_36 [ V_55 ] = ':' ;
V_55 ++ ;
}
V_41 = V_53 -> V_57 ;
while ( V_53 -> V_58 > ( V_41 - V_53 -> V_57 ) ) {
const char * V_60 = F_29 ( V_41 , '/' ,
V_53 -> V_58 - ( V_41 -
V_53 -> V_57 ) ) ;
if ( ! V_60 )
V_60 = V_41
+ V_53 -> V_58 - ( V_41 - V_53 -> V_57 ) ;
strncpy ( & V_36 [ V_55 ] , V_41 , V_60 - V_41 ) ;
V_55 += ( int ) ( V_60 - V_41 ) ;
V_36 [ V_55 ] = '\\' ;
V_55 ++ ;
V_41 = V_60 + 1 ;
}
V_41 = V_53 -> V_48 ;
while ( V_53 -> V_50 > ( V_41 - V_53 -> V_48 ) ) {
const char * V_60 = F_29 ( V_41 , '/' ,
V_53 -> V_50 - ( V_41 -
V_53 -> V_48 ) ) ;
if ( ! V_60 )
V_60 = V_41 + V_53 -> V_50 - ( V_41 - V_53 -> V_48 ) ;
strncpy ( & V_36 [ V_55 ] , V_41 , V_60 - V_41 ) ;
V_55 += ( int ) ( V_60 - V_41 ) ;
V_36 [ V_55 ] = '\\' ;
V_55 ++ ;
V_41 = V_60 + 1 ;
}
strncpy ( & V_36 [ V_55 ] , V_53 -> V_51 , V_53 -> V_52 ) ;
V_55 += V_53 -> V_52 ;
V_36 [ V_55 ] = '\0' ;
return ( V_36 ) ;
}
static char * F_30 ( T_8 * V_12 , const char * V_61 ,
const char * V_62 )
{
char * V_63 = NULL ;
struct V_34 * V_64 = NULL ;
struct V_34 * V_65 = NULL ;
if ( ! V_61 && ! V_62 ) {
F_14 ( V_66 , V_25 ) ;
return ( NULL ) ;
}
if ( ! V_62 ) {
V_63 = F_16 ( strlen ( V_61 ) + 1 ) ;
if ( V_63 == NULL ) {
F_14 ( V_66 , V_20 ) ;
return ( NULL ) ;
}
strcpy ( V_63 , V_61 ) ;
} else if ( ! V_61 ) {
V_63 = F_16 ( strlen ( V_62 ) + 1 ) ;
if ( V_63 == NULL ) {
F_14 ( V_66 , V_20 ) ;
return ( NULL ) ;
}
strcpy ( V_63 , V_62 ) ;
} else {
V_64 = F_26 ( V_12 , V_61 , 0 ) ;
if ( ! V_64 ) {
F_14 ( V_66 , V_20 ) ;
return ( NULL ) ;
}
V_65 = F_26 ( V_12 , V_62 , 1 ) ;
if ( ! V_65 ) {
F_14 ( V_66 , V_20 ) ;
F_18 ( V_64 ) ;
return ( NULL ) ;
}
if ( ! V_64 -> V_44 && ! V_64 -> V_46 ) {
V_64 -> V_44 = V_65 -> V_44 ;
V_64 -> V_49 = V_65 -> V_49 ;
V_64 -> V_46 = V_65 -> V_46 ;
V_64 -> V_47 = V_65 -> V_47 ;
}
if ( ! V_64 -> V_48 ) {
V_64 -> V_48 = V_65 -> V_48 ;
V_64 -> V_50 = V_65 -> V_50 ;
} else if ( V_64 -> V_48 [ 0 ] != '\\'
&& V_64 -> V_48 [ 0 ] != '/' ) {
V_64 -> V_57 = V_65 -> V_48 ;
V_64 -> V_58 = V_65 -> V_50 ;
}
if ( ! V_64 -> V_51 ) {
V_64 -> V_51 = V_65 -> V_51 ;
V_64 -> V_52 = V_65 -> V_52 ;
}
V_63 = F_28 ( V_12 , V_64 ) ;
}
F_18 ( V_64 ) ;
F_18 ( V_65 ) ;
return ( V_63 ) ;
}
static char * F_31 ( T_8 * V_12 , const char * V_15 )
{
char * V_67 ;
int V_54 , V_68 ;
V_54 = strlen ( V_15 ) ;
V_68 = ( ( strstr ( V_15 , L_5 ) == NULL ) &&
( strstr ( V_15 , L_6 ) == NULL ) &&
( strstr ( V_15 , L_7 ) == NULL ) ) ;
if ( V_68 )
V_67 = F_16 ( V_54 + 5 ) ;
else
V_67 = F_16 ( V_54 + 1 ) ;
if ( V_67 == NULL ) {
F_14 ( V_69 , V_70 ) ;
return ( NULL ) ;
}
if ( V_68 )
sprintf ( V_67 , L_8 , V_15 ) ;
else
sprintf ( V_67 , L_9 , V_15 ) ;
return ( V_67 ) ;
}
static const char * F_29 ( const char * string , int V_71 , T_6 V_54 )
{
T_6 V_4 ;
const char * V_14 ;
for ( V_4 = 0 , V_14 = string ; V_4 < V_54 && * V_14 ; V_4 ++ , V_14 ++ ) {
if ( * V_14 == V_71 )
return V_14 ;
}
return NULL ;
}
static void * F_32 ( const char * V_72 )
{
T_2 V_73 ;
T_10 V_74 = V_75 ;
T_11 V_76 ;
T_12 V_77 ;
T_13 V_78 ;
T_14 V_79 , V_80 ;
union {
void * V_14 ;
T_1 V_30 ;
} V_81 = { NULL } ;
V_73 = F_33 ( F_34 ( V_82 ) ) ;
if ( V_73 == NULL ) {
F_14 ( V_83 , V_84 ) ;
return NULL ;
}
V_77 = ( T_12 )
F_25 ( V_73 , L_10 ) ;
if ( V_77 == NULL ) {
F_19 ( V_73 ) ;
F_14 ( V_83 , V_84 ) ;
return NULL ;
}
# ifdef V_9
V_78 = ( T_13 )
F_25 ( V_73 , L_11 ) ;
# else
V_78 = ( T_13 ) V_85 ;
# endif
V_79 = ( T_14 ) F_25 ( V_73 , L_12 ) ;
V_80 = ( T_14 ) F_25 ( V_73 , L_13 ) ;
V_74 = (* V_77) ( V_86 , 0 ) ;
if ( V_74 == V_75 ) {
F_19 ( V_73 ) ;
F_14 ( V_83 , V_84 ) ;
return NULL ;
}
V_76 . V_87 = sizeof( V_76 ) ;
if ( ! (* V_79) ( V_74 , & V_76 ) ) {
(* V_78) ( V_74 ) ;
F_19 ( V_73 ) ;
return NULL ;
}
do {
if ( ( V_81 . V_30 = F_25 ( V_76 . V_1 , V_72 ) ) ) {
(* V_78) ( V_74 ) ;
F_19 ( V_73 ) ;
return V_81 . V_14 ;
}
} while ( (* V_80) ( V_74 , & V_76 ) );
(* V_78) ( V_74 ) ;
F_19 ( V_73 ) ;
return NULL ;
}
