extern void
F_1 ( const T_1 * V_1 , T_2 * V_2 , T_2 * V_3 , T_2 * V_4 )
{
float V_5 ;
if ( V_2 ) F_2 ( V_2 , V_6 , L_1 , V_1 -> V_7 ) ;
if ( V_3 ) {
* V_3 = '\0' ;
if ( V_1 -> V_8 -> V_9 > 0.0 ) {
V_5 = ( ( float ) V_1 -> V_7 ) / ( float ) V_1 -> V_8 -> V_9 ;
F_2 ( V_3 , V_6 , L_2 , V_5 ) ;
}
}
if ( V_4 ) {
* V_4 = '\0' ;
if ( V_1 -> V_10 -> V_7 > 0 ) {
V_5 = ( float ) ( ( ( float ) V_1 -> V_7 * 100.0 ) / V_1 -> V_10 -> V_7 ) ;
F_2 ( V_4 , V_6 , L_3 , V_5 ) ;
}
}
}
extern T_2 *
F_3 ( const T_1 * V_1 , T_2 * V_11 , T_3 V_12 )
{
if ( V_11 ) {
F_2 ( V_11 , V_12 , L_4 , V_1 -> V_13 , V_1 -> V_7 ) ;
return V_11 ;
} else {
return F_4 ( L_4 , V_1 -> V_13 , V_1 -> V_7 ) ;
}
}
extern T_3
F_5 ( const T_1 * V_1 , T_3 V_14 )
{
T_1 * V_15 ;
T_3 V_16 = 0 ;
T_3 V_12 ;
V_14 = V_14 > V_17 ? V_17 : V_14 ;
if ( V_1 -> V_18 ) {
for ( V_15 = V_1 -> V_18 ; V_15 ; V_15 = V_15 -> V_19 ) {
V_12 = F_5 ( V_15 , V_14 + 1 ) ;
V_16 = V_12 > V_16 ? V_12 : V_16 ;
}
}
V_12 = ( T_3 ) strlen ( V_1 -> V_13 ) + V_14 ;
V_16 = V_12 > V_16 ? V_12 : V_16 ;
return V_16 ;
}
extern void
F_6 ( const T_1 * V_1 , T_4 * V_20 , T_3 V_14 )
{
T_1 * V_15 ;
static T_2 V_21 [ V_17 + 1 ] ;
static T_2 V_2 [ V_6 ] ;
static T_2 V_3 [ V_6 ] ;
static T_2 V_4 [ V_6 ] ;
T_3 V_22 = 0 ;
if ( V_14 == 0 ) {
V_23 = F_4 ( L_5 , F_5 ( V_1 , 0 ) ) ;
}
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
V_14 = V_14 > V_17 ? V_17 : V_14 ;
if ( V_14 > 0 ) {
while( V_22 < V_14 )
V_21 [ V_22 ++ ] = ' ' ;
}
V_21 [ V_22 ] = '\0' ;
F_7 ( V_20 , V_23 ,
V_21 , V_1 -> V_13 , V_2 , V_3 , V_4 ) ;
if ( V_1 -> V_18 ) {
for ( V_15 = V_1 -> V_18 ; V_15 ; V_15 = V_15 -> V_19 ) {
F_6 ( V_15 , V_20 , V_14 + 1 ) ;
}
}
if ( V_14 == 0 ) {
F_8 ( V_23 ) ;
}
}
static void
F_9 ( T_1 * V_1 )
{
T_1 * V_15 ;
T_1 * V_19 ;
if ( V_1 -> V_18 ) {
for ( V_15 = V_1 -> V_18 ; V_15 ; V_15 = V_19 ) {
V_19 = V_15 -> V_19 ;
F_9 ( V_15 ) ;
}
}
if( V_1 -> V_8 -> V_24 -> V_25 ) V_1 -> V_8 -> V_24 -> V_25 ( V_1 ) ;
if ( V_1 -> V_26 ) F_10 ( V_1 -> V_26 ) ;
F_8 ( V_1 -> V_27 ) ;
F_8 ( V_1 -> V_13 ) ;
F_8 ( V_1 ) ;
}
extern void
F_11 ( T_5 * V_8 )
{
T_1 * V_15 ;
T_1 * V_19 ;
F_8 ( V_8 -> V_28 ) ;
F_10 ( V_8 -> V_29 ) ;
F_12 ( V_8 -> V_30 , TRUE ) ;
for ( V_15 = V_8 -> V_31 . V_18 ; V_15 ; V_15 = V_19 ) {
V_19 = V_15 -> V_19 ;
F_9 ( V_15 ) ;
}
if ( V_8 -> V_24 -> V_32 )
V_8 -> V_24 -> V_32 ( V_8 ) ;
if ( V_8 -> V_24 -> V_33 )
V_8 -> V_24 -> V_33 ( V_8 ) ;
F_8 ( V_8 ) ;
}
static void
F_13 ( T_1 * V_1 )
{
T_1 * V_15 ;
if ( V_1 -> V_18 ) {
for ( V_15 = V_1 -> V_18 ; V_15 ; V_15 = V_15 -> V_19 )
F_13 ( V_15 ) ;
}
V_1 -> V_7 = 0 ;
if( V_1 -> V_8 -> V_24 -> V_34 ) {
V_1 -> V_8 -> V_24 -> V_34 ( V_1 ) ;
}
}
extern void
F_14 ( void * V_35 )
{
T_5 * V_8 = ( T_5 * ) V_35 ;
V_8 -> V_36 = - 1.0 ;
V_8 -> V_9 = 0.0 ;
F_13 ( & V_8 -> V_31 ) ;
if ( V_8 -> V_24 -> V_37 ) {
V_8 -> V_24 -> V_37 ( V_8 ) ;
}
}
extern void
F_15 ( void * V_35 )
{
T_5 * V_8 = ( T_5 * ) V_35 ;
T_1 * V_15 ;
T_1 * V_19 ;
for ( V_15 = V_8 -> V_31 . V_18 ; V_15 ; V_15 = V_19 ) {
V_19 = V_15 -> V_19 ;
F_9 ( V_15 ) ;
}
V_8 -> V_31 . V_18 = NULL ;
V_8 -> V_31 . V_7 = 0 ;
if ( V_8 -> V_24 -> V_38 ) {
V_8 -> V_24 -> V_38 ( V_8 ) ;
}
}
extern void
F_16 ( const char * V_39 , const char * V_40 , const char * V_13 ,
T_3 V_41 ,
T_6 V_42 , T_7 V_38 ,
T_8 V_33 , T_9 V_43 )
{
T_10 * V_24 = ( T_10 * ) F_17 ( sizeof( T_10 ) ) ;
F_18 ( V_39 && V_40 && V_42 ) ;
V_24 -> V_44 = FALSE ;
V_24 -> V_39 = F_19 ( V_39 ) ;
V_24 -> V_40 = F_19 ( V_40 ) ;
V_24 -> V_13 = V_13 ? F_19 ( V_13 ) : F_19 ( V_40 ) ;
V_24 -> V_43 = V_43 ;
V_24 -> V_42 = V_42 ;
V_24 -> V_38 = V_38 ;
V_24 -> V_33 = V_33 ;
V_24 -> V_41 = V_41 ;
V_24 -> V_45 = NULL ;
V_24 -> V_46 = NULL ;
V_24 -> V_25 = NULL ;
V_24 -> V_32 = NULL ;
V_24 -> V_47 = NULL ;
V_24 -> V_48 = NULL ;
V_24 -> V_34 = NULL ;
V_24 -> V_37 = NULL ;
if ( ! V_49 ) V_49 = F_20 ( V_50 , V_51 ) ;
F_21 ( V_49 , V_24 -> V_40 , V_24 ) ;
}
extern void
F_22 ( const char * V_39 , const char * V_40 , const char * V_13 ,
T_3 V_41 ,
T_6 V_42 , T_7 V_38 ,
T_8 V_33 )
{
F_16 ( V_39 , V_40 , V_13 ,
V_41 ,
V_42 , V_38 ,
V_33 , V_52 ) ;
}
extern void
F_23 ( const char * V_39 , const char * V_40 , const char * V_13 ,
T_3 V_41 ,
T_6 V_42 , T_7 V_38 ,
T_8 V_33 )
{
T_10 * V_24 ;
F_22 ( V_39 , V_40 , V_13 ,
V_41 ,
V_42 , V_38 ,
V_33 ) ;
V_24 = F_24 ( ( char * ) V_40 ) ;
V_24 -> V_44 = TRUE ;
}
extern T_5 *
F_25 ( T_10 * V_24 , T_11 * V_53 , const char * V_28 )
{
T_5 * V_8 = ( T_5 * ) F_17 ( sizeof( T_5 ) ) ;
V_8 -> V_24 = V_24 ;
V_8 -> V_53 = V_53 ;
V_8 -> V_29 = F_20 ( V_50 , V_51 ) ;
V_8 -> V_30 = F_26 () ;
V_8 -> V_28 = F_19 ( V_28 ) ;
V_8 -> V_36 = - 1.0 ;
V_8 -> V_9 = 0.0 ;
V_8 -> V_31 . V_7 = 0 ;
V_8 -> V_31 . V_13 = F_19 ( V_24 -> V_13 ) ;
V_8 -> V_31 . V_8 = V_8 ;
V_8 -> V_31 . V_10 = NULL ;
V_8 -> V_31 . V_18 = NULL ;
V_8 -> V_31 . V_19 = NULL ;
V_8 -> V_31 . V_26 = NULL ;
V_8 -> V_31 . V_53 = NULL ;
F_27 ( V_8 -> V_30 , & V_8 -> V_31 ) ;
return V_8 ;
}
extern int
F_28 ( void * V_35 , T_12 * V_54 , T_13 * V_55 , const void * V_56 )
{
T_5 * V_8 = ( T_5 * ) V_35 ;
double V_57 = F_29 ( & V_54 -> V_58 -> V_59 ) ;
if ( V_8 -> V_36 < 0.0 ) V_8 -> V_36 = V_57 ;
V_8 -> V_9 = V_57 - V_8 -> V_36 ;
if ( V_8 -> V_24 -> V_42 )
return V_8 -> V_24 -> V_42 ( V_8 , V_54 , V_55 , V_56 ) ;
else
return 0 ;
}
extern T_10 *
F_24 ( char * V_40 )
{
return ( T_10 * ) F_30 ( V_49 , V_40 ) ;
}
extern T_14 *
F_31 ( void )
{
return F_32 ( V_49 ) ;
}
static void
F_33 ( T_15 T_16 V_60 , T_15 V_61 , T_15 V_35 )
{
T_10 * V_24 = ( T_10 * ) V_61 ;
struct V_62 * V_63 = (struct V_62 * ) V_35 ;
V_24 -> V_64 = FALSE ;
V_24 -> V_45 = V_63 -> V_45 ;
V_24 -> V_46 = V_63 -> V_46 ;
V_24 -> V_25 = V_63 -> V_25 ;
V_24 -> V_32 = V_63 -> V_32 ;
V_24 -> V_47 = V_63 -> V_47 ;
V_24 -> V_48 = V_63 -> V_48 ;
V_24 -> V_34 = V_63 -> V_34 ;
V_24 -> V_37 = V_63 -> V_37 ;
}
extern void
F_34 ( void (* F_35)( T_15 , T_15 , T_15 ) ,
void (* V_45)( T_1 * ) ,
void (* V_25)( T_1 * ) ,
void (* V_47)( T_1 * ) ,
void (* V_34)( T_1 * ) ,
T_11 * (* V_46)( T_5 * ) ,
void (* V_32)( T_5 * ) ,
void (* V_48)( T_5 * ) ,
void (* V_37)( T_5 * ) ,
void * V_65 )
{
static struct V_62 V_63 ;
V_63 . V_45 = V_45 ;
V_63 . V_46 = V_46 ;
V_63 . V_25 = V_25 ;
V_63 . V_32 = V_32 ;
V_63 . V_47 = V_47 ;
V_63 . V_48 = V_48 ;
V_63 . V_34 = V_34 ;
V_63 . V_37 = V_37 ;
if ( V_49 ) F_36 ( V_49 , F_33 , & V_63 ) ;
if ( F_35 && V_49 )
F_36 ( V_49 , F_35 , V_65 ) ;
}
static T_1 *
F_37 ( T_5 * V_8 , const T_2 * V_13 , int V_66 ,
T_17 V_67 , T_17 V_68 )
{
T_1 * V_1 = ( T_1 * ) F_17 ( sizeof( T_1 ) ) ;
T_1 * V_69 = NULL ;
V_1 -> V_7 = 0 ;
V_1 -> V_13 = F_19 ( V_13 ) ;
V_1 -> V_18 = NULL ;
V_1 -> V_19 = NULL ;
V_1 -> V_8 = ( T_5 * ) V_8 ;
V_1 -> V_26 = V_67 ? F_20 ( V_50 , V_51 ) : NULL ;
V_1 -> V_10 = NULL ;
V_1 -> V_27 = NULL ;
if ( V_68 ) {
F_21 ( V_8 -> V_29 ,
V_1 -> V_13 ,
V_1 ) ;
F_27 ( V_8 -> V_30 , V_1 ) ;
V_1 -> V_70 = V_8 -> V_30 -> V_12 - 1 ;
} else {
V_1 -> V_70 = - 1 ;
}
if ( V_66 >= 0 && V_66 < ( int ) V_8 -> V_30 -> V_12 ) {
V_1 -> V_10 = ( T_1 * ) F_38 ( V_8 -> V_30 , V_66 ) ;
} else {
F_39 () ;
}
if ( V_1 -> V_10 -> V_18 ) {
for ( V_69 = V_1 -> V_10 -> V_18 ;
V_69 -> V_19 ;
V_69 = V_69 -> V_19 ) ;
V_69 -> V_19 = V_1 ;
} else {
V_1 -> V_10 -> V_18 = V_1 ;
}
if( V_1 -> V_10 -> V_26 ) {
F_21 ( V_1 -> V_10 -> V_26 , V_1 -> V_13 , V_1 ) ;
}
if ( V_8 -> V_24 -> V_45 ) {
V_8 -> V_24 -> V_45 ( V_1 ) ;
} else {
V_1 -> V_53 = NULL ;
}
return V_1 ;
}
extern int
F_40 ( T_5 * V_8 , const T_2 * V_13 , int V_66 , T_17 V_67 )
{
T_1 * V_1 = F_37 ( V_8 , V_13 , V_66 , V_67 , TRUE ) ;
if ( V_1 )
return V_1 -> V_70 ;
else
return 0 ;
}
extern int
F_41 ( T_5 * V_8 , const T_2 * V_13 ,
const T_2 * V_71 , T_17 V_72 )
{
return F_40 ( V_8 , V_13 , F_42 ( V_8 , V_71 ) , V_72 ) ;
}
extern int
F_43 ( T_18 V_73 , T_5 * V_8 , const char * V_13 ,
int V_66 , T_17 V_67 , T_19 V_2 )
{
T_1 * V_1 = NULL ;
T_1 * V_10 = NULL ;
F_18 ( V_66 >= 0 && V_66 < ( int ) V_8 -> V_30 -> V_12 ) ;
V_10 = ( T_1 * ) F_38 ( V_8 -> V_30 , V_66 ) ;
if( V_10 -> V_26 ) {
V_1 = ( T_1 * ) F_30 ( V_10 -> V_26 , V_13 ) ;
} else {
V_1 = ( T_1 * ) F_30 ( V_8 -> V_29 , V_13 ) ;
}
if ( V_1 == NULL )
V_1 = F_37 ( V_8 , V_13 , V_66 , V_67 , V_67 ) ;
switch ( V_73 ) {
case V_74 : V_1 -> V_7 += V_2 ; break;
case V_75 : V_1 -> V_7 = V_2 ; break;
}
if ( V_1 )
return V_1 -> V_70 ;
else
return - 1 ;
}
extern char *
F_44 ( const char * V_76 )
{
T_3 V_22 ;
F_18 ( V_76 != NULL ) ;
for ( V_22 = 0 ; V_76 [ V_22 ] && V_76 [ V_22 ] != ',' ; V_22 ++ ) ;
if ( V_76 [ V_22 ] == ',' ) {
return F_45 ( V_76 , V_22 ) ;
} else {
return NULL ;
}
}
static T_20 *
F_46 ( char * V_77 )
{
T_2 * * V_78 ;
T_20 * V_27 ;
V_78 = F_47 ( ( T_2 * ) V_77 , L_6 , 2 ) ;
if ( V_78 [ 0 ] == NULL ) {
F_48 ( V_78 ) ;
return NULL ;
}
if ( V_78 [ 1 ] == NULL ) {
F_48 ( V_78 ) ;
return NULL ;
}
V_27 = ( T_20 * ) F_17 ( sizeof( T_20 ) ) ;
if ( * ( V_78 [ 0 ] ) != '\0' ) {
V_27 -> floor = ( T_19 ) strtol ( V_78 [ 0 ] , NULL , 10 ) ;
} else
V_27 -> floor = V_79 ;
if ( * ( V_78 [ 1 ] ) != '\0' ) {
V_27 -> ceil = ( T_19 ) strtol ( V_78 [ 1 ] , NULL , 10 ) ;
} else
V_27 -> ceil = V_80 ;
F_48 ( V_78 ) ;
return V_27 ;
}
extern int
F_49 ( T_5 * V_8 , const T_2 * V_13 , int V_66 , ... )
{
T_21 V_81 ;
T_2 * V_82 ;
T_1 * V_83 = F_37 ( V_8 , V_13 , V_66 , FALSE , TRUE ) ;
T_1 * V_84 = NULL ;
va_start ( V_81 , V_66 ) ;
while ( ( V_82 = va_arg ( V_81 , T_2 * ) ) ) {
V_84 = F_37 ( V_8 , V_82 , V_83 -> V_70 , FALSE , FALSE ) ;
V_84 -> V_27 = F_46 ( V_82 ) ;
}
va_end ( V_81 ) ;
return V_83 -> V_70 ;
}
extern int
F_50 ( T_5 * V_8 , const T_2 * V_13 ,
int V_66 , int V_85 ,
T_2 * * V_86 )
{
int V_22 ;
T_1 * V_83 = F_37 ( V_8 , V_13 , V_66 , FALSE , TRUE ) ;
T_1 * V_84 = NULL ;
for ( V_22 = 0 ; V_22 < V_85 ; V_22 ++ ) {
V_84 = F_37 ( V_8 , V_86 [ V_22 ] , V_83 -> V_70 , FALSE , FALSE ) ;
V_84 -> V_27 = F_46 ( V_86 [ V_22 ] ) ;
}
return V_83 -> V_70 ;
}
extern int
F_42 ( T_5 * V_8 , const T_2 * V_71 )
{
T_1 * V_1 = ( T_1 * ) F_30 ( V_8 -> V_29 , V_71 ) ;
if ( V_1 )
return V_1 -> V_70 ;
else
return 0 ;
}
extern int
F_51 ( T_5 * V_8 , const T_2 * V_13 ,
const T_2 * V_71 , ... )
{
T_21 V_81 ;
T_2 * V_82 ;
T_1 * V_84 = NULL ;
int V_66 = F_42 ( V_8 , V_71 ) ;
T_1 * V_83 = F_37 ( V_8 , V_13 , V_66 , FALSE , TRUE ) ;
va_start ( V_81 , V_71 ) ;
while ( ( V_82 = va_arg ( V_81 , T_2 * ) ) ) {
V_84 = F_37 ( V_8 , V_82 , V_83 -> V_70 , FALSE , FALSE ) ;
V_84 -> V_27 = F_46 ( V_82 ) ;
}
va_end ( V_81 ) ;
return V_83 -> V_70 ;
}
extern int
F_52 ( T_5 * V_8 , const T_2 * V_13 , int V_66 ,
int V_87 )
{
T_1 * V_1 = NULL ;
T_1 * V_10 = NULL ;
T_1 * V_15 = NULL ;
T_19 floor , ceil ;
if ( V_66 >= 0 && V_66 < ( int ) V_8 -> V_30 -> V_12 ) {
V_10 = ( T_1 * ) F_38 ( V_8 -> V_30 , V_66 ) ;
} else {
F_39 () ;
}
if( V_10 -> V_26 ) {
V_1 = ( T_1 * ) F_30 ( V_10 -> V_26 , V_13 ) ;
} else {
V_1 = ( T_1 * ) F_30 ( V_8 -> V_29 , V_13 ) ;
}
if ( V_1 == NULL )
F_39 () ;
for ( V_15 = V_1 -> V_18 ; V_15 ; V_15 = V_15 -> V_19 ) {
floor = V_15 -> V_27 -> floor ;
ceil = V_15 -> V_27 -> ceil ;
if ( V_87 >= floor && V_87 <= ceil ) {
V_15 -> V_7 ++ ;
return V_1 -> V_70 ;
}
}
return V_1 -> V_70 ;
}
extern int
F_53 ( T_5 * V_8 , const T_2 * V_13 , int V_66 )
{
T_1 * V_1 = F_37 ( V_8 , V_13 , V_66 , TRUE , TRUE ) ;
if ( V_1 )
return V_1 -> V_70 ;
else
return 0 ;
}
extern int
F_54 ( T_5 * V_8 , const T_2 * V_13 ,
const T_2 * V_71 )
{
int V_66 = F_42 ( V_8 , V_71 ) ;
T_1 * V_1 ;
V_1 = F_37 ( V_8 , V_13 , V_66 , TRUE , TRUE ) ;
if ( V_1 )
return V_1 -> V_70 ;
else
return 0 ;
}
extern int
F_55 ( T_5 * V_8 , int V_88 , const T_2 * V_89 )
{
T_1 * V_10 = ( T_1 * ) F_38 ( V_8 -> V_30 , V_88 ) ;
V_10 -> V_7 ++ ;
F_43 ( V_74 , V_8 , V_89 , V_88 , FALSE , 1 ) ;
return V_88 ;
}
