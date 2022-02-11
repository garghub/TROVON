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
T_5 * V_8 = V_35 ;
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
T_5 * V_8 = V_35 ;
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
T_10 * V_24 = F_17 ( sizeof( T_10 ) ) ;
F_18 ( V_39 && V_40 && V_42 ) ;
V_24 -> V_39 = F_19 ( V_39 ) ;
V_24 -> V_40 = F_19 ( V_40 ) ;
V_24 -> V_13 = V_13 ? F_19 ( V_13 ) : F_19 ( V_40 ) ;
V_24 -> V_43 = V_43 ;
V_24 -> V_42 = V_42 ;
V_24 -> V_38 = V_38 ;
V_24 -> V_33 = V_33 ;
V_24 -> V_41 = V_41 ;
V_24 -> V_44 = NULL ;
V_24 -> V_45 = NULL ;
V_24 -> V_25 = NULL ;
V_24 -> V_32 = NULL ;
V_24 -> V_46 = NULL ;
V_24 -> V_47 = NULL ;
V_24 -> V_34 = NULL ;
V_24 -> V_37 = NULL ;
if ( ! V_48 ) V_48 = F_20 ( V_49 , V_50 ) ;
F_21 ( V_48 , V_24 -> V_40 , V_24 ) ;
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
V_33 , V_51 ) ;
}
extern T_5 *
F_23 ( T_10 * V_24 , T_11 * V_52 , const char * V_28 )
{
T_5 * V_8 = F_17 ( sizeof( T_5 ) ) ;
V_8 -> V_24 = V_24 ;
V_8 -> V_52 = V_52 ;
V_8 -> V_29 = F_20 ( V_49 , V_50 ) ;
V_8 -> V_30 = F_24 () ;
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
V_8 -> V_31 . V_52 = NULL ;
F_25 ( V_8 -> V_30 , & V_8 -> V_31 ) ;
return V_8 ;
}
extern int
F_26 ( void * V_35 , T_12 * V_53 , T_13 * V_54 , const void * V_55 )
{
T_5 * V_8 = V_35 ;
double V_56 = F_27 ( & V_53 -> V_57 -> V_58 ) ;
if ( V_8 -> V_36 < 0.0 ) V_8 -> V_36 = V_56 ;
V_8 -> V_9 = V_56 - V_8 -> V_36 ;
if ( V_8 -> V_24 -> V_42 )
return V_8 -> V_24 -> V_42 ( V_8 , V_53 , V_54 , V_55 ) ;
else
return 0 ;
}
extern T_10 *
F_28 ( char * V_40 )
{
return F_29 ( V_48 , V_40 ) ;
}
static void
F_30 ( T_14 T_15 V_59 , T_14 V_60 , T_14 V_35 )
{
T_10 * V_24 = V_60 ;
struct V_61 * V_62 = V_35 ;
V_24 -> V_63 = FALSE ;
V_24 -> V_44 = V_62 -> V_44 ;
V_24 -> V_45 = V_62 -> V_45 ;
V_24 -> V_25 = V_62 -> V_25 ;
V_24 -> V_32 = V_62 -> V_32 ;
V_24 -> V_46 = V_62 -> V_46 ;
V_24 -> V_47 = V_62 -> V_47 ;
V_24 -> V_34 = V_62 -> V_34 ;
V_24 -> V_37 = V_62 -> V_37 ;
}
extern void
F_31 ( void (* F_32)( T_14 , T_14 , T_14 ) ,
void (* V_44)( T_1 * ) ,
void (* V_25)( T_1 * ) ,
void (* V_46)( T_1 * ) ,
void (* V_34)( T_1 * ) ,
T_11 * (* V_45)( T_5 * ) ,
void (* V_32)( T_5 * ) ,
void (* V_47)( T_5 * ) ,
void (* V_37)( T_5 * ) ,
void * V_64 )
{
static struct V_61 V_62 ;
V_62 . V_44 = V_44 ;
V_62 . V_45 = V_45 ;
V_62 . V_25 = V_25 ;
V_62 . V_32 = V_32 ;
V_62 . V_46 = V_46 ;
V_62 . V_47 = V_47 ;
V_62 . V_34 = V_34 ;
V_62 . V_37 = V_37 ;
if ( V_48 ) F_33 ( V_48 , F_30 , & V_62 ) ;
if ( F_32 && V_48 )
F_33 ( V_48 , F_32 , V_64 ) ;
}
static T_1 *
F_34 ( T_5 * V_8 , const T_2 * V_13 , int V_65 ,
T_16 V_66 , T_16 V_67 )
{
T_1 * V_1 = F_17 ( sizeof( T_1 ) ) ;
T_1 * V_68 = NULL ;
V_1 -> V_7 = 0 ;
V_1 -> V_13 = F_19 ( V_13 ) ;
V_1 -> V_18 = NULL ;
V_1 -> V_19 = NULL ;
V_1 -> V_8 = ( T_5 * ) V_8 ;
V_1 -> V_26 = V_66 ? F_20 ( V_49 , V_50 ) : NULL ;
V_1 -> V_10 = NULL ;
V_1 -> V_27 = NULL ;
if ( V_67 ) {
F_21 ( V_8 -> V_29 ,
V_1 -> V_13 ,
V_1 ) ;
F_25 ( V_8 -> V_30 , V_1 ) ;
V_1 -> V_69 = V_8 -> V_30 -> V_12 - 1 ;
} else {
V_1 -> V_69 = - 1 ;
}
if ( V_65 >= 0 && V_65 < ( int ) V_8 -> V_30 -> V_12 ) {
V_1 -> V_10 = F_35 ( V_8 -> V_30 , V_65 ) ;
} else {
F_36 () ;
}
if ( V_1 -> V_10 -> V_18 ) {
for ( V_68 = V_1 -> V_10 -> V_18 ;
V_68 -> V_19 ;
V_68 = V_68 -> V_19 ) ;
V_68 -> V_19 = V_1 ;
} else {
V_1 -> V_10 -> V_18 = V_1 ;
}
if( V_1 -> V_10 -> V_26 ) {
F_21 ( V_1 -> V_10 -> V_26 , V_1 -> V_13 , V_1 ) ;
}
if ( V_8 -> V_24 -> V_44 ) {
V_8 -> V_24 -> V_44 ( V_1 ) ;
} else {
V_1 -> V_52 = NULL ;
}
return V_1 ;
}
extern int
F_37 ( T_5 * V_8 , const T_2 * V_13 , int V_65 , T_16 V_66 )
{
T_1 * V_1 = F_34 ( V_8 , V_13 , V_65 , V_66 , TRUE ) ;
if ( V_1 )
return V_1 -> V_69 ;
else
return 0 ;
}
extern int
F_38 ( T_5 * V_8 , const T_2 * V_13 ,
const T_2 * V_70 , T_16 V_71 )
{
return F_37 ( V_8 , V_13 , F_39 ( V_8 , V_70 ) , V_71 ) ;
}
extern int
F_40 ( T_17 V_72 , T_5 * V_8 , const char * V_13 ,
int V_65 , T_16 V_66 , T_18 V_2 )
{
T_1 * V_1 = NULL ;
T_1 * V_10 = NULL ;
F_18 ( V_65 >= 0 && V_65 < ( int ) V_8 -> V_30 -> V_12 ) ;
V_10 = F_35 ( V_8 -> V_30 , V_65 ) ;
if( V_10 -> V_26 ) {
V_1 = F_29 ( V_10 -> V_26 , V_13 ) ;
} else {
V_1 = F_29 ( V_8 -> V_29 , V_13 ) ;
}
if ( V_1 == NULL )
V_1 = F_34 ( V_8 , V_13 , V_65 , V_66 , V_66 ) ;
switch ( V_72 ) {
case V_73 : V_1 -> V_7 += V_2 ; break;
case V_74 : V_1 -> V_7 = V_2 ; break;
}
if ( V_1 )
return V_1 -> V_69 ;
else
return - 1 ;
}
extern char *
F_41 ( const char * V_75 )
{
T_3 V_22 ;
F_18 ( V_75 != NULL ) ;
for ( V_22 = 0 ; V_75 [ V_22 ] && V_75 [ V_22 ] != ',' ; V_22 ++ ) ;
if ( V_75 [ V_22 ] == ',' ) {
return F_42 ( V_75 , V_22 ) ;
} else {
return NULL ;
}
}
static T_19 *
F_43 ( char * V_76 )
{
T_2 * * V_77 ;
T_19 * V_27 ;
V_77 = F_44 ( ( T_2 * ) V_76 , L_6 , 2 ) ;
if ( V_77 [ 0 ] == NULL ) {
F_45 ( V_77 ) ;
return NULL ;
}
if ( V_77 [ 1 ] == NULL ) {
F_45 ( V_77 ) ;
return NULL ;
}
V_27 = F_17 ( sizeof( T_19 ) ) ;
if ( * ( V_77 [ 0 ] ) != '\0' ) {
V_27 -> floor = strtol ( V_77 [ 0 ] , NULL , 10 ) ;
} else
V_27 -> floor = V_78 ;
if ( * ( V_77 [ 1 ] ) != '\0' ) {
V_27 -> ceil = strtol ( V_77 [ 1 ] , NULL , 10 ) ;
} else
V_27 -> ceil = V_79 ;
F_45 ( V_77 ) ;
return V_27 ;
}
extern int
F_46 ( T_5 * V_8 , const T_2 * V_13 , int V_65 , ... )
{
T_20 V_80 ;
T_2 * V_81 ;
T_1 * V_82 = F_34 ( V_8 , V_13 , V_65 , FALSE , TRUE ) ;
T_1 * V_83 = NULL ;
va_start ( V_80 , V_65 ) ;
while ( ( V_81 = va_arg ( V_80 , T_2 * ) ) ) {
V_83 = F_34 ( V_8 , V_81 , V_82 -> V_69 , FALSE , FALSE ) ;
V_83 -> V_27 = F_43 ( V_81 ) ;
}
va_end ( V_80 ) ;
return V_82 -> V_69 ;
}
extern int
F_39 ( T_5 * V_8 , const T_2 * V_70 )
{
T_1 * V_1 = F_29 ( V_8 -> V_29 , V_70 ) ;
if ( V_1 )
return V_1 -> V_69 ;
else
return 0 ;
}
extern int
F_47 ( T_5 * V_8 , const T_2 * V_13 ,
const T_2 * V_70 , ... )
{
T_20 V_80 ;
T_2 * V_81 ;
T_1 * V_83 = NULL ;
int V_65 = F_39 ( V_8 , V_70 ) ;
T_1 * V_82 = F_34 ( V_8 , V_13 , V_65 , FALSE , TRUE ) ;
va_start ( V_80 , V_70 ) ;
while ( ( V_81 = va_arg ( V_80 , T_2 * ) ) ) {
V_83 = F_34 ( V_8 , V_81 , V_82 -> V_69 , FALSE , FALSE ) ;
V_83 -> V_27 = F_43 ( V_81 ) ;
}
va_end ( V_80 ) ;
return V_82 -> V_69 ;
}
extern int
F_48 ( T_5 * V_8 , const T_2 * V_13 , int V_65 ,
int V_84 )
{
T_1 * V_1 = NULL ;
T_1 * V_10 = NULL ;
T_1 * V_15 = NULL ;
T_18 floor , ceil ;
if ( V_65 >= 0 && V_65 < ( int ) V_8 -> V_30 -> V_12 ) {
V_10 = F_35 ( V_8 -> V_30 , V_65 ) ;
} else {
F_36 () ;
}
if( V_10 -> V_26 ) {
V_1 = F_29 ( V_10 -> V_26 , V_13 ) ;
} else {
V_1 = F_29 ( V_8 -> V_29 , V_13 ) ;
}
if ( V_1 == NULL )
F_36 () ;
for ( V_15 = V_1 -> V_18 ; V_15 ; V_15 = V_15 -> V_19 ) {
floor = V_15 -> V_27 -> floor ;
ceil = V_15 -> V_27 -> ceil ;
if ( V_84 >= floor && V_84 <= ceil ) {
V_15 -> V_7 ++ ;
return V_1 -> V_69 ;
}
}
return V_1 -> V_69 ;
}
extern int
F_49 ( T_5 * V_8 , const T_2 * V_13 , int V_65 )
{
T_1 * V_1 = F_34 ( V_8 , V_13 , V_65 , TRUE , TRUE ) ;
if ( V_1 )
return V_1 -> V_69 ;
else
return 0 ;
}
extern int
F_50 ( T_5 * V_8 , const T_2 * V_13 ,
const T_2 * V_70 )
{
int V_65 = F_39 ( V_8 , V_70 ) ;
T_1 * V_1 ;
V_1 = F_34 ( V_8 , V_13 , V_65 , TRUE , TRUE ) ;
if ( V_1 )
return V_1 -> V_69 ;
else
return 0 ;
}
extern int
F_51 ( T_5 * V_8 , int V_85 , const T_2 * V_86 )
{
T_1 * V_10 = F_35 ( V_8 -> V_30 , V_85 ) ;
V_10 -> V_7 ++ ;
F_40 ( V_73 , V_8 , V_86 , V_85 , FALSE , 1 ) ;
return V_85 ;
}
