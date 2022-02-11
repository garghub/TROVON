void
F_1 ( void )
{
static const T_1 V_1 [] = {
F_2 ( V_2 , FALSE ) ,
F_2 ( V_3 , FALSE ) ,
F_2 ( V_4 , FALSE ) ,
F_2 ( V_5 , FALSE ) ,
F_2 ( V_6 , FALSE ) ,
F_2 ( V_7 , FALSE ) ,
F_2 ( V_8 , FALSE ) ,
F_2 ( V_9 , FALSE ) ,
F_2 ( V_10 , FALSE ) ,
F_2 ( V_11 , FALSE ) ,
F_2 ( V_12 , FALSE ) ,
#ifdef F_3
F_2 ( V_13 , FALSE ) ,
F_2 ( V_14 , FALSE ) ,
F_2 ( V_15 , FALSE ) ,
#endif
F_2 ( V_16 , FALSE ) ,
#ifdef F_4
F_2 ( V_17 , FALSE ) ,
#endif
#ifdef F_5
F_2 ( V_18 , TRUE ) ,
#endif
F_2 ( V_19 , FALSE ) ,
F_2 ( V_20 , TRUE ) ,
#ifdef F_6
F_2 ( V_21 , TRUE ) ,
F_2 ( V_22 , TRUE ) ,
#endif
#ifdef F_7
F_2 ( V_23 , TRUE ) ,
#endif
#ifdef F_8
F_2 ( V_24 , TRUE ) ,
#endif
#ifdef F_9
F_2 ( V_25 , TRUE ) ,
#endif
#ifdef F_10
F_2 ( V_26 , FALSE ) ,
#endif
F_2 ( V_27 , TRUE ) ,
F_2 ( V_28 , TRUE ) ,
F_2 ( V_29 , TRUE ) ,
#ifdef F_11
F_2 ( V_30 , FALSE ) ,
#endif
#ifdef F_12
F_2 ( V_31 , FALSE ) ,
#endif
#ifdef F_13
F_2 ( V_32 , TRUE ) ,
#endif
#ifdef F_14
F_2 ( V_33 , FALSE ) ,
#endif
{ NULL , NULL , FALSE }
} ;
T_2 * V_34 ;
const T_1 * V_35 ;
V_34 = F_15 ( L_1 , 0 ) ;
if ( ! V_34 ) {
return;
}
V_35 = V_1 ;
while ( V_35 -> V_36 ) {
if ( ! F_16 ( V_34 , V_35 -> V_36 , V_35 -> V_37 ) ) {
if ( V_35 -> V_38 ) {
* V_35 -> V_37 = NULL ;
} else {
return;
}
}
V_35 ++ ;
}
V_39 = TRUE ;
}
char *
F_17 ( const char * V_40 )
{
return F_18 (
L_2
L_3
L_4
L_5
L_4
L_6
L_4
L_7
L_4
L_8
L_4
L_7
L_4
L_9
L_4
L_10
L_11 ,
V_40 ) ;
}
char *
V_2 ( char * V_41 )
{
if ( ! V_39 ) {
return NULL ;
}
return F_19 ( V_41 ) ;
}
void
V_3 ( T_3 * V_41 )
{
F_20 ( V_39 ) ;
F_21 ( V_41 ) ;
}
int
V_4 ( T_3 * V_41 , struct V_42 * V_43 )
{
F_20 ( V_39 ) ;
return F_22 ( V_41 , V_43 ) ;
}
int
V_5 ( T_3 * V_41 , int V_43 , T_4 V_44 , T_5 * V_45 )
{
F_20 ( V_39 ) ;
return F_23 ( V_41 , V_43 , V_44 , V_45 ) ;
}
int
V_6 ( T_3 * V_41 )
{
F_20 ( V_39 ) ;
return F_24 ( V_41 ) ;
}
int
V_7 ( T_3 * V_41 )
{
F_20 ( V_39 ) ;
return F_25 ( V_41 ) ;
}
int
V_31 ( T_3 * V_46 , int V_47 )
{
F_20 ( V_39 ) ;
return F_26 ( V_46 , V_47 ) ;
}
int
V_8 ( T_3 * V_41 , struct V_48 * V_43 )
{
F_20 ( V_39 ) ;
return F_27 ( V_41 , V_43 ) ;
}
char *
V_9 ( T_3 * V_41 )
{
F_20 ( V_39 ) ;
return F_28 ( V_41 ) ;
}
int
V_10 ( T_3 * V_41 , struct V_48 * V_43 , const char * V_44 , int V_45 ,
T_6 V_49 )
{
F_20 ( V_39 ) ;
return F_29 ( V_41 , V_43 , V_44 , V_45 , V_49 ) ;
}
int
V_11 ( int V_41 , int V_43 , struct V_48 * V_44 , const char * V_45 , int V_49 ,
T_6 V_50 )
{
F_20 ( V_39 ) ;
return F_30 ( V_41 , V_43 , V_44 , V_45 , V_49 , V_50 ) ;
}
int
V_12 ( const char * V_41 , T_6 * V_43 , T_6 * V_44 , char * V_45 )
{
F_20 ( V_39 ) ;
return F_31 ( V_41 , V_43 , V_44 , V_45 ) ;
}
T_3 *
V_16 ( const char * V_41 , int V_43 , int V_44 , int V_45 , char * V_49 )
{
if ( ! V_39 ) {
F_32 ( V_49 , V_51 ,
L_12 ,
V_41 ) ;
return NULL ;
}
return F_33 ( V_41 , V_43 , V_44 , V_45 , V_49 ) ;
}
T_3 *
V_17 ( int V_41 , int V_43 )
{
if ( ! V_39 ) {
return NULL ;
}
return F_34 ( V_41 , V_43 ) ;
}
char *
V_33 ( const struct V_52 * V_41 , int V_43 )
{
if ( ! V_39 ) {
return NULL ;
}
return F_35 ( V_41 , V_43 ) ;
}
T_3 *
V_13 ( const char * V_41 , int V_43 , int V_44 , int V_45 , struct V_53 * V_49 , char * V_50 )
{
if ( ! V_39 ) {
F_32 ( V_50 , V_51 ,
L_12 ,
V_41 ) ;
return NULL ;
}
return F_36 ( V_41 , V_43 , V_44 , V_45 , V_49 , V_50 ) ;
}
int
V_14 ( char * V_41 , struct V_53 * V_43 , T_7 * * V_44 , char * V_45 )
{
F_20 ( V_39 ) ;
return F_37 ( V_41 , V_43 , V_44 , V_45 ) ;
}
int
V_15 ( char * V_41 , int V_43 , const char * V_44 , const char * V_45 , const char * V_49 ,
char * V_50 )
{
F_20 ( V_39 ) ;
return F_38 ( V_41 , V_43 , V_44 , V_45 , V_49 , V_50 ) ;
}
struct V_54 *
V_18 ( T_3 * V_41 )
{
F_20 ( V_39 ) ;
if ( V_55 != NULL ) {
return V_55 ( V_41 ) ;
}
return NULL ;
}
int
V_19 ( T_3 * V_41 , int V_43 , T_4 V_44 , T_5 * V_45 )
{
F_20 ( V_39 ) ;
return F_39 ( V_41 , V_43 , V_44 , V_45 ) ;
}
void
V_20 ( struct V_48 * V_41 )
{
F_20 ( V_39 ) ;
if( V_56 ) {
V_56 ( V_41 ) ;
}
}
int
V_21 ( T_7 * * V_41 , char * V_43 )
{
F_20 ( V_39 && V_57 != NULL ) ;
return V_57 ( V_41 , V_43 ) ;
}
void
V_22 ( T_7 * V_41 )
{
F_20 ( V_39 && V_58 != NULL ) ;
V_58 ( V_41 ) ;
}
int
V_23 ( const char * V_36 )
{
int V_59 ;
F_20 ( V_39 ) ;
if ( V_60 != NULL )
return V_60 ( V_36 ) ;
else {
for ( V_59 = 0 ; V_61 [ V_59 ] . V_36 != NULL ; V_59 ++ ) {
if ( F_40 ( V_61 [ V_59 ] . V_36 + sizeof( L_13 ) - 1 ,
V_36 ) == 0 )
return V_61 [ V_59 ] . V_47 ;
}
return - 1 ;
}
}
int
V_30 ( T_3 * V_46 , int * * V_62 )
{
F_20 ( V_39 ) ;
return F_41 ( V_46 , V_62 ) ;
}
void
V_32 ( int * V_62 )
{
F_20 ( V_39 ) ;
if ( V_63 != NULL )
V_63 ( V_62 ) ;
}
const char *
V_24 ( int V_47 )
{
int V_59 ;
F_20 ( V_39 ) ;
if ( V_64 != NULL )
return V_64 ( V_47 ) ;
else {
for ( V_59 = 0 ; V_61 [ V_59 ] . V_36 != NULL ; V_59 ++ ) {
if ( V_61 [ V_59 ] . V_47 == V_47 )
return V_61 [ V_59 ] . V_36 + sizeof( L_13 ) - 1 ;
}
return NULL ;
}
}
const char *
V_25 ( int V_47 )
{
int V_59 ;
F_20 ( V_39 ) ;
if ( V_65 != NULL )
return V_65 ( V_47 ) ;
else {
for ( V_59 = 0 ; V_61 [ V_59 ] . V_36 != NULL ; V_59 ++ ) {
if ( V_61 [ V_59 ] . V_47 == V_47 )
return ( V_61 [ V_59 ] . V_66 ) ;
}
return NULL ;
}
}
void V_26 ( T_3 * V_41 )
{
F_42 ( V_41 ) ;
}
int V_28 ( T_3 * V_41 , int V_43 )
{
F_20 ( V_39 ) ;
return F_43 ( V_41 , V_43 ) ;
}
int V_29 ( T_3 * V_41 , struct V_67 * * V_43 , const T_8 * * V_44 )
{
F_20 ( V_39 ) ;
return F_44 ( V_41 , V_43 , V_44 ) ;
}
T_9 *
F_45 ( const char * V_68 , const char * V_69 ,
int V_70 , const char * V_71 ,
const char * V_72 , int * V_73 , char * * V_74 )
{
struct V_53 V_75 ;
char V_76 [ V_77 ] ;
char V_78 [ V_51 ] ;
T_9 * V_79 ;
if ( V_15 ( V_76 , V_80 , V_68 , V_69 ,
NULL , V_78 ) == - 1 ) {
* V_73 = V_81 ;
if ( V_74 != NULL )
* V_74 = F_46 ( V_78 ) ;
return NULL ;
}
V_75 . type = V_70 ;
V_75 . V_71 = F_47 ( V_71 ) ;
V_75 . V_82 = F_47 ( V_72 ) ;
V_79 = F_48 ( V_76 , & V_75 , V_73 , V_74 ) ;
F_49 ( V_75 . V_71 ) ;
F_49 ( V_75 . V_82 ) ;
return V_79 ;
}
T_9 *
F_50 ( int * V_73 , char * * V_74 )
{
T_9 * V_83 = NULL ;
T_10 * V_84 ;
char * V_85 ;
char V_86 [ V_87 + 1 ] ;
char V_88 [ V_87 + 1 ] ;
int V_59 , V_89 ;
char V_78 [ V_51 ] ;
if ( ! V_39 ) {
* V_73 = V_90 ;
* V_74 = F_17 ( L_14 ) ;
return NULL ;
}
#ifdef F_6
if ( V_57 != NULL )
return F_51 ( V_73 , V_74 ) ;
#endif
V_84 = ( T_10 * ) V_2 ( V_78 ) ;
V_59 = 0 ;
if ( V_84 ) {
char * V_91 = 0 ;
int V_92 = 0 ;
if ( V_84 [ 0 ] < 256 ) {
while ( * ( V_84 + V_92 ) || * ( V_84 + V_92 - 1 ) )
V_92 ++ ;
V_92 ++ ;
V_91 = ( char * ) ( V_84 + V_92 ) ;
while ( V_84 [ V_59 ] != 0 ) {
V_89 = 0 ;
while ( * V_91 != 0 ) {
if ( V_89 < V_87 )
V_88 [ V_89 ++ ] = * V_91 ;
V_91 ++ ;
}
V_88 [ V_89 ] = '\0' ;
V_91 ++ ;
V_89 = 0 ;
while ( V_84 [ V_59 ] != 0 ) {
if ( V_89 < V_87 )
V_86 [ V_89 ++ ] = ( char ) V_84 [ V_59 ++ ] ;
}
V_86 [ V_89 ] = '\0' ;
V_59 ++ ;
V_83 = F_52 ( V_83 ,
F_53 ( V_86 , V_88 , FALSE ) ) ;
}
} else {
V_85 = ( char * ) V_84 ;
while ( * ( V_85 + V_92 ) || * ( V_85 + V_92 - 1 ) )
V_92 ++ ;
V_92 ++ ;
V_91 = V_85 + V_92 ;
while ( V_85 [ V_59 ] != '\0' ) {
V_83 = F_52 ( V_83 ,
F_53 ( & V_85 [ V_59 ] , V_91 , FALSE ) ) ;
while ( * V_91 != 0 )
V_91 ++ ;
V_91 ++ ;
while ( V_85 [ V_59 ] != 0 )
V_59 ++ ;
V_59 ++ ;
}
}
}
if ( V_83 == NULL ) {
* V_73 = 0 ;
if ( V_74 != NULL )
* V_74 = NULL ;
}
return V_83 ;
}
T_11 *
F_46 ( const char * V_74 )
{
if ( strstr ( V_74 , L_15 ) != NULL ||
strstr ( V_74 , L_16 ) != NULL ) {
return F_18 ( L_17
L_18
L_19 ,
V_74 ) ;
}
return F_18 ( L_20 , V_74 ) ;
}
void
F_54 ( T_12 * V_93 )
{
F_55 ( V_93 , L_21 F_56 ( V_94 ) L_22 ) ;
}
void
F_57 ( T_12 * V_93 )
{
T_2 * V_95 ;
static T_11 * V_96 ;
T_11 * V_97 ;
if ( V_39 ) {
F_58 ( V_93 , L_23 ) ;
if ( V_98 != NULL )
F_58 ( V_93 , V_98 () ) ;
else {
if ( V_96 == NULL ) {
V_96 = L_24 ;
V_95 = F_15 ( L_25 , 0 ) ;
if ( V_95 != NULL ) {
if ( F_16 ( V_95 ,
L_26 ,
( V_99 * ) & V_96 ) ) {
V_96 = F_47 ( V_96 ) ;
V_97 = strchr ( V_96 , ' ' ) ;
if ( V_97 != NULL )
* V_97 = '\0' ;
} else {
V_96 = L_24 ;
}
F_59 ( V_95 ) ;
}
}
F_58 ( V_93 , L_27 , V_96 ) ;
}
} else
F_55 ( V_93 , L_28 ) ;
}
void
F_1 ( void )
{
return;
}
void
F_54 ( T_12 * V_93 )
{
F_55 ( V_93 , L_28 ) ;
}
void
F_57 ( T_12 * V_93 V_100 )
{
}
