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
#ifdef F_15
F_2 ( V_34 , TRUE ) ,
F_2 ( V_35 , TRUE ) ,
F_2 ( V_36 , TRUE ) ,
F_2 ( V_37 , TRUE ) ,
F_2 ( V_38 , TRUE ) ,
F_2 ( V_39 , FALSE ) ,
F_2 ( V_40 , FALSE ) ,
F_2 ( V_41 , TRUE ) ,
F_2 ( V_42 , TRUE ) ,
#endif
{ NULL , NULL , FALSE }
} ;
T_2 * V_43 ;
const T_1 * V_44 ;
V_43 = F_16 ( L_1 , 0 ) ;
if ( ! V_43 ) {
return;
}
V_44 = V_1 ;
while ( V_44 -> V_45 ) {
if ( ! F_17 ( V_43 , V_44 -> V_45 , V_44 -> V_46 ) ) {
if ( V_44 -> V_47 ) {
* V_44 -> V_46 = NULL ;
} else {
return;
}
}
V_44 ++ ;
}
V_48 = TRUE ;
}
char *
F_18 ( const char * V_49 )
{
return F_19 (
L_2
L_3
L_4
L_5
L_4
L_6
L_4
L_7
L_8 ,
V_49 ) ;
}
char *
V_2 ( char * V_50 )
{
if ( ! V_48 ) {
return NULL ;
}
return F_20 ( V_50 ) ;
}
void
V_3 ( T_3 * V_50 )
{
F_21 ( V_48 ) ;
F_22 ( V_50 ) ;
}
int
V_4 ( T_3 * V_50 , struct V_51 * V_52 )
{
F_21 ( V_48 ) ;
return F_23 ( V_50 , V_52 ) ;
}
int
V_5 ( T_3 * V_50 , int V_52 , T_4 V_53 , T_5 * V_54 )
{
F_21 ( V_48 ) ;
return F_24 ( V_50 , V_52 , V_53 , V_54 ) ;
}
int
V_6 ( T_3 * V_50 )
{
F_21 ( V_48 ) ;
return F_25 ( V_50 ) ;
}
int
V_7 ( T_3 * V_50 )
{
F_21 ( V_48 ) ;
return F_26 ( V_50 ) ;
}
int
V_31 ( T_3 * V_55 , int V_56 )
{
F_21 ( V_48 ) ;
return F_27 ( V_55 , V_56 ) ;
}
int
V_8 ( T_3 * V_50 , struct V_57 * V_52 )
{
F_21 ( V_48 ) ;
return F_28 ( V_50 , V_52 ) ;
}
char *
V_9 ( T_3 * V_50 )
{
F_21 ( V_48 ) ;
return F_29 ( V_50 ) ;
}
int
V_10 ( T_3 * V_50 , struct V_57 * V_52 , const char * V_53 , int V_54 ,
T_6 V_58 )
{
F_21 ( V_48 ) ;
return F_30 ( V_50 , V_52 , V_53 , V_54 , V_58 ) ;
}
int
V_11 ( int V_50 , int V_52 , struct V_57 * V_53 , const char * V_54 , int V_58 ,
T_6 V_59 )
{
F_21 ( V_48 ) ;
return F_31 ( V_50 , V_52 , V_53 , V_54 , V_58 , V_59 ) ;
}
int
V_12 ( const char * V_50 , T_6 * V_52 , T_6 * V_53 , char * V_54 )
{
F_21 ( V_48 ) ;
return F_32 ( V_50 , V_52 , V_53 , V_54 ) ;
}
T_3 *
V_16 ( const char * V_50 , int V_52 , int V_53 , int V_54 , char * V_58 )
{
if ( ! V_48 ) {
F_33 ( V_58 , V_60 ,
L_9 ,
V_50 ) ;
return NULL ;
}
return F_34 ( V_50 , V_52 , V_53 , V_54 , V_58 ) ;
}
T_3 *
V_17 ( int V_50 , int V_52 )
{
if ( ! V_48 ) {
return NULL ;
}
return F_35 ( V_50 , V_52 ) ;
}
char *
V_33 ( const struct V_61 * V_50 , int V_52 )
{
if ( ! V_48 ) {
return NULL ;
}
return F_36 ( V_50 , V_52 ) ;
}
T_3 *
V_13 ( const char * V_50 , int V_52 , int V_53 , int V_54 , struct V_62 * V_58 , char * V_59 )
{
if ( ! V_48 ) {
F_33 ( V_59 , V_60 ,
L_9 ,
V_50 ) ;
return NULL ;
}
return F_37 ( V_50 , V_52 , V_53 , V_54 , V_58 , V_59 ) ;
}
int
V_14 ( char * V_50 , struct V_62 * V_52 , T_7 * * V_53 , char * V_54 )
{
F_21 ( V_48 ) ;
return F_38 ( V_50 , V_52 , V_53 , V_54 ) ;
}
int
V_15 ( char * V_50 , int V_52 , const char * V_53 , const char * V_54 , const char * V_58 ,
char * V_59 )
{
F_21 ( V_48 ) ;
return F_39 ( V_50 , V_52 , V_53 , V_54 , V_58 , V_59 ) ;
}
struct V_63 *
V_18 ( T_3 * V_50 )
{
F_21 ( V_48 ) ;
if ( V_64 != NULL ) {
return V_64 ( V_50 ) ;
}
return NULL ;
}
int
V_19 ( T_3 * V_50 , int V_52 , T_4 V_53 , T_5 * V_54 )
{
F_21 ( V_48 ) ;
return F_40 ( V_50 , V_52 , V_53 , V_54 ) ;
}
void
V_20 ( struct V_57 * V_50 )
{
F_21 ( V_48 ) ;
if( V_65 ) {
V_65 ( V_50 ) ;
}
}
int
V_21 ( T_7 * * V_50 , char * V_52 )
{
F_21 ( V_48 && V_66 != NULL ) ;
return V_66 ( V_50 , V_52 ) ;
}
void
V_22 ( T_7 * V_50 )
{
F_21 ( V_48 && V_67 != NULL ) ;
V_67 ( V_50 ) ;
}
T_3 *
V_34 ( const char * V_50 , char * V_52 )
{
F_21 ( V_48 && V_68 != NULL ) ;
return V_68 ( V_50 , V_52 ) ;
}
int
V_35 ( T_3 * V_50 , int V_52 )
{
F_21 ( V_48 && V_69 != NULL ) ;
return V_69 ( V_50 , V_52 ) ;
}
int
V_36 ( T_3 * V_50 , int V_52 )
{
F_21 ( V_48 && V_70 != NULL ) ;
return V_70 ( V_50 , V_52 ) ;
}
int
V_37 ( T_3 * V_50 )
{
F_21 ( V_48 ) ;
if ( V_71 != NULL ) {
return V_71 ( V_50 ) ;
}
return 0 ;
}
int
V_38 ( T_3 * V_50 , int V_52 )
{
F_21 ( V_48 && V_72 != NULL ) ;
return V_72 ( V_50 , V_52 ) ;
}
int
V_39 ( T_3 * V_50 , int V_52 )
{
F_21 ( V_48 && V_39 != NULL ) ;
return F_41 ( V_50 , V_52 ) ;
}
int
V_40 ( T_3 * V_50 , int V_52 )
{
F_21 ( V_48 && V_39 != NULL ) ;
return F_42 ( V_50 , V_52 ) ;
}
int
V_41 ( T_3 * V_50 )
{
F_21 ( V_48 && V_41 != NULL ) ;
return F_43 ( V_50 ) ;
}
const char *
V_42 ( int V_50 )
{
static char V_73 [ 15 + 10 + 1 ] ;
F_21 ( V_48 ) ;
if ( V_42 != NULL ) {
return V_42 ( V_50 ) ;
}
( void ) F_33 ( V_73 , sizeof V_73 , L_10 , V_50 ) ;
return ( V_73 ) ;
}
int
V_23 ( const char * V_45 )
{
int V_74 ;
if ( V_48 && ( V_75 != NULL ) )
return V_75 ( V_45 ) ;
else {
for ( V_74 = 0 ; V_76 [ V_74 ] . V_45 != NULL ; V_74 ++ ) {
if ( F_44 ( V_76 [ V_74 ] . V_45 + sizeof( L_11 ) - 1 ,
V_45 ) == 0 )
return V_76 [ V_74 ] . V_56 ;
}
return - 1 ;
}
}
int
V_30 ( T_3 * V_55 , int * * V_77 )
{
F_21 ( V_48 ) ;
return F_45 ( V_55 , V_77 ) ;
}
void
V_32 ( int * V_77 )
{
F_21 ( V_48 ) ;
if ( V_78 != NULL )
V_78 ( V_77 ) ;
}
const char *
V_24 ( int V_56 )
{
int V_74 ;
if ( V_48 && ( V_79 != NULL ) )
return V_79 ( V_56 ) ;
else {
for ( V_74 = 0 ; V_76 [ V_74 ] . V_45 != NULL ; V_74 ++ ) {
if ( V_76 [ V_74 ] . V_56 == V_56 )
return V_76 [ V_74 ] . V_45 + sizeof( L_11 ) - 1 ;
}
return NULL ;
}
}
const char *
V_25 ( int V_56 )
{
int V_74 ;
if ( V_48 && ( V_80 != NULL ) )
return V_80 ( V_56 ) ;
else {
for ( V_74 = 0 ; V_76 [ V_74 ] . V_45 != NULL ; V_74 ++ ) {
if ( V_76 [ V_74 ] . V_56 == V_56 )
return ( V_76 [ V_74 ] . V_81 ) ;
}
return NULL ;
}
}
void V_26 ( T_3 * V_50 )
{
F_46 ( V_50 ) ;
}
int V_28 ( T_3 * V_50 , int V_52 )
{
F_21 ( V_48 ) ;
return F_47 ( V_50 , V_52 ) ;
}
int V_29 ( T_3 * V_50 , struct V_82 * * V_52 , const T_8 * * V_53 )
{
F_21 ( V_48 ) ;
return F_48 ( V_50 , V_52 , V_53 ) ;
}
T_9 *
F_49 ( const char * V_83 , const char * V_84 ,
int V_85 , const char * V_86 ,
const char * V_87 , int * V_88 , char * * V_89 )
{
struct V_62 V_90 ;
char V_91 [ V_92 ] ;
char V_93 [ V_60 ] ;
T_9 * V_94 ;
if ( V_15 ( V_91 , V_95 , V_83 , V_84 ,
NULL , V_93 ) == - 1 ) {
* V_88 = V_96 ;
if ( V_89 != NULL )
* V_89 = F_50 ( V_93 ) ;
return NULL ;
}
V_90 . type = V_85 ;
V_90 . V_86 = F_51 ( V_86 ) ;
V_90 . V_97 = F_51 ( V_87 ) ;
V_94 = F_52 ( V_91 , & V_90 , V_88 , V_89 ) ;
F_53 ( V_90 . V_86 ) ;
F_53 ( V_90 . V_97 ) ;
return V_94 ;
}
T_9 *
F_54 ( int * V_88 , char * * V_89 )
{
T_9 * V_98 = NULL ;
T_10 * V_99 ;
char * V_100 ;
char V_101 [ V_102 + 1 ] ;
char V_103 [ V_102 + 1 ] ;
int V_74 , V_104 ;
char V_93 [ V_60 ] ;
if ( ! V_48 ) {
* V_88 = V_105 ;
if ( V_89 != NULL )
* V_89 = F_18 ( L_12 ) ;
return NULL ;
}
#ifdef F_6
if ( V_66 != NULL )
return F_55 ( V_88 , V_89 ) ;
#endif
V_99 = ( T_10 * ) V_2 ( V_93 ) ;
V_74 = 0 ;
if ( V_99 ) {
char * V_106 = 0 ;
int V_107 = 0 ;
if ( V_99 [ 0 ] < 256 ) {
while ( * ( V_99 + V_107 ) || * ( V_99 + V_107 - 1 ) )
V_107 ++ ;
V_107 ++ ;
V_106 = ( char * ) ( V_99 + V_107 ) ;
while ( V_99 [ V_74 ] != 0 ) {
V_104 = 0 ;
while ( * V_106 != 0 ) {
if ( V_104 < V_102 )
V_103 [ V_104 ++ ] = * V_106 ;
V_106 ++ ;
}
V_103 [ V_104 ] = '\0' ;
V_106 ++ ;
V_104 = 0 ;
while ( V_99 [ V_74 ] != 0 ) {
if ( V_104 < V_102 )
V_101 [ V_104 ++ ] = ( char ) V_99 [ V_74 ++ ] ;
}
V_101 [ V_104 ] = '\0' ;
V_74 ++ ;
V_98 = F_56 ( V_98 ,
F_57 ( V_101 , V_103 , FALSE ) ) ;
}
} else {
V_100 = ( char * ) V_99 ;
while ( * ( V_100 + V_107 ) || * ( V_100 + V_107 - 1 ) )
V_107 ++ ;
V_107 ++ ;
V_106 = V_100 + V_107 ;
while ( V_100 [ V_74 ] != '\0' ) {
V_98 = F_56 ( V_98 ,
F_57 ( & V_100 [ V_74 ] , V_106 , FALSE ) ) ;
while ( * V_106 != 0 )
V_106 ++ ;
V_106 ++ ;
while ( V_100 [ V_74 ] != 0 )
V_74 ++ ;
V_74 ++ ;
}
}
}
if ( V_98 == NULL ) {
* V_88 = 0 ;
if ( V_89 != NULL )
* V_89 = NULL ;
}
return V_98 ;
}
T_11 *
F_50 ( const char * V_89 )
{
if ( strstr ( V_89 , L_13 ) != NULL ||
strstr ( V_89 , L_14 ) != NULL ) {
return F_19 ( L_15
L_16
L_17 ,
V_89 ) ;
}
return F_19 ( L_18 , V_89 ) ;
}
T_12 *
F_58 ( T_13 * V_108 , char * * V_89 )
{
#ifdef F_15
if ( V_68 != NULL )
return F_59 ( V_108 , V_89 ) ;
#endif
return F_60 ( V_108 , V_89 ) ;
}
void
F_61 ( T_14 * V_109 )
{
F_62 ( V_109 , L_19 F_63 ( V_110 ) L_20 ) ;
}
void
F_64 ( T_14 * V_109 )
{
T_2 * V_111 ;
static T_11 * V_112 ;
T_11 * V_113 ;
if ( V_48 ) {
F_65 ( V_109 , L_21 ) ;
if ( V_114 != NULL )
F_65 ( V_109 , V_114 () ) ;
else {
if ( V_112 == NULL ) {
V_112 = L_22 ;
V_111 = F_16 ( L_23 , 0 ) ;
if ( V_111 != NULL ) {
if ( F_17 ( V_111 ,
L_24 ,
( V_115 * ) & V_112 ) ) {
V_112 = F_51 ( V_112 ) ;
V_113 = strchr ( V_112 , ' ' ) ;
if ( V_113 != NULL )
* V_113 = '\0' ;
} else {
V_112 = L_22 ;
}
F_66 ( V_111 ) ;
}
}
F_65 ( V_109 , L_25 , V_112 ) ;
}
} else
F_62 ( V_109 , L_26 ) ;
}
T_15
F_67 ( void )
{
T_16 V_116 , V_117 ;
T_17 V_118 ;
V_116 = F_68 ( NULL , NULL , 0 ) ;
if ( ! V_116 )
return FALSE ;
V_117 = F_69 ( V_116 , F_70 ( L_27 ) , V_119 | V_120 ) ;
if ( ! V_117 ) {
V_117 = F_69 ( V_116 , F_70 ( L_28 ) , V_119 | V_120 ) ;
if ( ! V_117 ) {
F_71 ( V_116 ) ;
return FALSE ;
}
}
if ( F_72 ( V_117 , & V_118 ) ) {
if ( V_118 . V_121 & V_122 ) {
F_71 ( V_117 ) ;
F_71 ( V_116 ) ;
return TRUE ;
}
}
F_71 ( V_117 ) ;
F_71 ( V_116 ) ;
return FALSE ;
}
void
F_1 ( void )
{
return;
}
void
F_61 ( T_14 * V_109 )
{
F_62 ( V_109 , L_26 ) ;
}
void
F_64 ( T_14 * V_109 V_123 )
{
}
