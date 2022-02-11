static void FPRINTF ( T_1 * V_1 , const char * V_2 , ... )
{
T_2 args ;
#ifdef F_1
va_start ( args , V_2 ) ;
vfprintf ( V_3 , V_2 , args ) ;
va_end ( args ) ;
#endif
if ( V_1 ) {
va_start ( args , V_2 ) ;
vfprintf ( V_1 , V_2 , args ) ;
va_end ( args ) ;
}
}
static void
F_2 ( const char * V_4 , const char * V_5 )
{
T_3 * V_6 ;
V_6 = F_3 ( T_3 , 1 ) ;
if ( ! V_6 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_6 -> V_7 = V_8 ;
V_8 = V_6 ;
V_6 -> V_4 = F_4 ( V_4 , strlen ( V_4 ) ) ;
V_6 -> V_5 = F_4 ( V_5 , strlen ( V_5 ) ) ;
}
static const char *
F_5 ( char * V_4 )
{
T_3 * V_6 ;
for( V_6 = V_8 ; V_6 ; V_6 = V_6 -> V_7 ) {
if( ! F_6 ( V_4 , V_6 -> V_4 ) ) {
return V_6 -> V_5 ;
}
}
return L_2 ;
}
static T_4 *
F_7 ( T_4 * V_9 , int V_10 )
{
T_4 * V_11 ;
V_11 = V_9 ;
while( V_11 ) {
if( V_10 ) V_10 -- ;
V_11 = V_11 -> V_7 ;
}
if( ! V_11 ) V_11 = V_9 ;
while( V_10 -- ) {
V_11 = F_3 ( T_4 , 1 ) ;
if ( ! V_11 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_11 -> V_7 = V_9 ;
V_11 -> type = V_12 ;
V_9 = V_11 ;
}
V_9 = V_11 ;
return V_9 ;
}
static const char *
F_8 ( const char * V_13 )
{
if( ! F_6 ( V_13 , L_3 ) ) {
return L_4 ;
} else if( ! F_6 ( V_13 , L_5 ) ) {
return L_6 ;
} else if( ! F_6 ( V_13 , L_7 ) ) {
return L_8 ;
}
FPRINTF ( V_3 , L_9 , V_13 ) ;
exit ( 10 ) ;
}
static int
F_9 ( char * V_4 )
{
T_5 * V_14 ;
for( V_14 = V_15 ; V_14 ; V_14 = V_14 -> V_7 ) {
if( ! F_6 ( V_4 , V_14 -> V_4 ) ) {
return V_14 -> V_16 ;
}
}
FPRINTF ( V_3 , L_10 , V_4 ) ;
FPRINTF ( V_3 , L_11 ) ;
exit ( 10 ) ;
}
static void
F_10 ( const char * V_17 , const char * V_18 )
{
T_6 * V_19 ;
V_19 = F_3 ( T_6 , 1 ) ;
if ( ! V_19 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_19 -> V_7 = V_20 ;
V_20 = V_19 ;
V_19 -> V_21 = 0 ;
V_19 -> V_17 = F_4 ( V_17 , strlen ( V_17 ) ) ;
V_19 -> V_18 = F_4 ( V_18 , strlen ( V_18 ) ) ;
}
static void
F_11 ( void )
{
T_6 * V_22 ;
for( V_22 = V_20 ; V_22 ; V_22 = V_22 -> V_7 ) {
if( ! V_22 -> V_21 ) {
FPRINTF ( V_3 , L_12 , V_22 -> V_17 ) ;
exit ( 10 ) ;
}
}
}
static T_7 *
F_12 ( char * V_4 )
{
T_7 * V_23 ;
for( V_23 = V_24 ; V_23 ; V_23 = V_23 -> V_7 ) {
if( ! F_6 ( V_23 -> V_4 , V_4 ) ) {
break;
}
}
if ( ! V_23 ) {
FPRINTF ( V_3 , L_13 , V_4 ) ;
Exit ( 10 ) ;
}
return V_23 ;
}
static const char *
F_13 ( const char * V_25 , const char * V_26 , const char * V_27 , const char * V_28 , const char * V_29 , const char * V_30 , const char * V_31 , const char * V_32 )
{
T_7 * V_23 ;
T_6 * V_22 ;
for( V_22 = V_20 ; V_22 ; V_22 = V_22 -> V_7 ) {
if( ! strncmp ( V_25 , V_22 -> V_17 , strlen ( V_25 ) ) ) {
V_23 = F_12 ( V_22 -> V_18 ) ;
if( F_6 ( V_28 , V_23 -> V_28 ) ) {
FPRINTF ( V_3 , L_14 , V_25 , V_23 -> V_4 , V_28 , V_23 -> V_28 ) ;
Exit ( 10 ) ;
}
V_22 -> V_21 ++ ;
return V_22 -> V_18 ;
}
}
V_23 = F_3 ( T_7 , 1 ) ;
if ( ! V_23 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_23 -> V_7 = V_24 ;
V_24 = V_23 ;
V_23 -> V_4 = F_4 ( V_25 , strlen ( V_25 ) ) ;
V_23 -> V_28 = F_4 ( V_28 , strlen ( V_28 ) ) ;
FPRINTF ( V_33 , L_15 , V_25 ) ;
FPRINTF ( V_34 , L_16 , V_25 ) ;
FPRINTF ( V_34 , L_17 , V_26 , V_27 , V_28 , V_29 ) ;
FPRINTF ( V_34 , L_18 , V_30 , V_31 ) ;
if ( strlen ( V_32 ) > 0 )
FPRINTF ( V_34 , L_19 , V_32 ) ;
else
FPRINTF ( V_34 , L_20 ) ;
FPRINTF ( V_34 , L_21 ) ;
return V_25 ;
}
static int
F_14 ( char * V_4 )
{
T_8 * V_35 ;
for( V_35 = V_36 ; V_35 ; V_35 = V_35 -> V_7 ) {
if( ! F_6 ( V_4 , V_35 -> V_4 ) ) {
FPRINTF ( NULL , L_22 , V_4 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_15 ( const char * V_17 , const char * V_18 )
{
T_9 * V_37 ;
for( V_37 = V_38 ; V_37 ; V_37 = V_37 -> V_7 ) {
if( ! F_6 ( V_37 -> V_39 , V_17 ) ) {
V_37 -> V_39 = F_4 ( V_18 , strlen ( V_18 ) ) ;
}
}
}
static void
F_16 ( const char * V_4 )
{
T_9 * V_37 , * V_40 ;
for( V_37 = V_38 ; V_37 ; V_37 = V_37 -> V_7 ) {
if( ! F_6 ( V_37 -> V_39 , V_4 ) ) {
if( ! F_6 ( V_37 -> V_7 -> V_39 , L_23 ) ) {
V_40 = V_37 ;
while( 1 ) {
if( ! F_6 ( V_40 -> V_39 , L_24 ) ) {
V_37 -> V_7 = V_40 -> V_7 ;
break;
}
V_40 = V_40 -> V_7 ;
}
}
}
}
}
static T_9 *
F_17 ( T_9 * V_37 , T_10 * * V_41 ) {
T_10 * V_42 ;
T_11 * V_43 ;
if( F_6 ( V_37 -> V_39 , L_25 ) ) {
FPRINTF ( V_3 , L_26 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_42 = F_3 ( T_10 , 1 ) ;
if ( ! V_42 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
* V_41 = V_42 ;
V_42 -> V_44 = 0 ;
V_42 -> V_45 = NULL ;
V_42 -> V_46 = NULL ;
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_27 )
|| ! F_6 ( V_37 -> V_39 , L_28 ) ) {
FPRINTF ( V_3 , L_29 ) ;
Exit ( 10 ) ;
}
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
FPRINTF ( V_3 , L_30 ) ;
Exit ( 10 ) ;
}
if( ! F_6 ( V_37 -> V_39 , L_31 ) ) {
V_37 = V_37 -> V_7 ;
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
return V_37 ;
}
if( ! F_6 ( V_37 -> V_39 , L_32 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_33 ) ) {
V_42 -> V_44 |= V_47 ;
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_23 ) ) {
FPRINTF ( V_3 , L_34 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_42 -> V_45 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_24 ) ) {
FPRINTF ( V_3 , L_35 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_36 ) ) {
V_42 -> V_44 |= V_47 ;
V_42 -> V_44 |= V_48 ;
V_42 -> V_45 = L_36 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_37 ) ) {
V_42 -> V_44 |= V_49 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_38 ) ) {
V_42 -> V_44 |= V_50 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_39 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_40 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_41 ) ) {
FPRINTF ( V_3 , L_42 ) ;
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_24 ) ) {
V_37 = V_37 -> V_7 ;
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_43 ) ) {
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_24 ) ) {
V_37 = V_37 -> V_7 ;
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_44 ) ) {
int V_51 ;
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_23 ) ) {
FPRINTF ( V_3 , L_45 ) ;
Exit ( 10 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_23 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_24 ) ) {
V_37 = V_37 -> V_7 ;
V_51 -- ;
if( V_51 ) {
continue;
}
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_46 ) ) {
int V_51 ;
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_23 ) ) {
FPRINTF ( V_3 , L_47 ) ;
Exit ( 10 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_23 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_24 ) ) {
V_37 = V_37 -> V_7 ;
V_51 -- ;
if( V_51 ) {
continue;
}
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_48 ) ) {
int V_51 ;
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_23 ) ) {
FPRINTF ( V_3 , L_49 ) ;
Exit ( 10 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_23 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_24 ) ) {
V_37 = V_37 -> V_7 ;
V_51 -- ;
if( V_51 ) {
continue;
}
break;
}
V_37 = V_37 -> V_7 ;
}
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_50 ) ) {
V_42 -> V_44 |= V_52 ;
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_23 ) ) {
FPRINTF ( V_3 , L_51 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_43 = F_18 ( V_37 -> V_39 ) ;
if( ! V_43 ) {
FPRINTF ( V_3 , L_52 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_42 -> V_53 = V_43 -> V_54 ;
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_24 ) ) {
FPRINTF ( V_3 , L_53 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_54 ) ) {
V_42 -> V_44 |= V_55 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_55 ) ) {
V_42 -> V_44 |= V_56 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_56 ) ) {
V_42 -> V_44 |= V_57 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_57 ) ) {
V_42 -> V_44 |= V_58 ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_5 )
|| ! F_6 ( V_37 -> V_39 , L_3 )
|| ! F_6 ( V_37 -> V_39 , L_7 ) ) {
T_4 * V_59 ;
V_42 -> V_44 |= V_60 ;
V_59 = F_3 ( T_4 , 1 ) ;
if ( ! V_59 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_59 -> V_7 = NULL ;
V_59 -> type = V_37 -> V_39 ;
V_59 -> V_7 = V_42 -> V_46 ;
V_42 -> V_46 = V_59 ;
V_37 = V_37 -> V_7 ;
continue;
}
FPRINTF ( V_3 , L_58 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
return NULL ;
}
static T_11 *
F_19 ( const char * V_4 , const char * V_61 , const char * V_28 , const char * V_29 , const char * V_31 , const char * V_30 , int V_54 ) {
T_11 * V_62 ;
FPRINTF ( NULL , L_59 , V_4 , V_61 , V_28 , V_29 , V_31 , V_30 , V_54 ) ;
V_62 = F_3 ( T_11 , 1 ) ;
if ( ! V_62 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_62 -> V_7 = V_63 ;
V_62 -> V_4 = F_4 ( V_4 , strlen ( V_4 ) ) ;
V_62 -> V_64 = F_4 ( V_61 , strlen ( V_61 ) ) ;
V_62 -> V_28 = F_4 ( V_28 , strlen ( V_28 ) ) ;
V_62 -> V_29 = F_4 ( V_29 , strlen ( V_29 ) ) ;
V_62 -> V_31 = F_4 ( V_31 , strlen ( V_31 ) ) ;
V_62 -> V_65 = F_4 ( V_30 , strlen ( V_30 ) ) ;
V_62 -> V_54 = V_54 ;
V_63 = V_62 ;
return V_62 ;
}
static void F_20 ( int V_66 )
{
T_9 * V_37 ;
FPRINTF ( V_3 , L_60 ) ;
for( V_37 = V_38 ; V_37 && V_66 ; V_66 -- , V_37 = V_37 -> V_7 ) {
FPRINTF ( V_3 , L_61 , V_37 -> V_39 ) ;
}
if( ! V_66 ) {
FPRINTF ( V_3 , L_62 ) ;
}
}
static void F_21 ( void )
{
char V_27 [ V_67 ] ;
T_9 * V_37 ;
int V_51 = 0 ;
int V_68 , V_69 ;
V_37 = V_38 ;
if( ! V_37 ) {
FPRINTF ( V_3 , L_63 ) ;
Exit ( 10 ) ;
}
if( F_6 ( V_37 -> V_39 , L_25 ) ) {
FPRINTF ( V_3 , L_64 ) ;
Exit ( 10 ) ;
}
for( V_37 = V_38 ; V_37 ; V_37 = V_37 -> V_7 ) {
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
V_51 ++ ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_31 ) ) {
V_51 -- ;
if( ! V_51 ) {
V_38 = V_37 -> V_7 ;
break;
}
}
if( V_51 == 1 ) {
if( ! F_6 ( V_37 -> V_39 , L_65 ) ) {
V_70 = V_37 -> V_7 -> V_7 -> V_39 ;
FPRINTF ( NULL , L_66 , V_70 ) ;
}
if( ! F_6 ( V_37 -> V_39 , L_67 ) ) {
V_71 = V_37 -> V_7 -> V_7 -> V_39 ;
FPRINTF ( NULL , L_68 , V_71 ) ;
}
if( ! F_6 ( V_37 -> V_39 , L_69 ) ) {
if( ! F_6 ( V_37 -> V_7 -> V_7 -> V_39 , L_3 ) ) {
V_12 = L_3 ;
} else if( ! F_6 ( V_37 -> V_7 -> V_7 -> V_39 , L_7 ) ) {
V_12 = L_7 ;
} else {
FPRINTF ( V_3 , L_70 ) ;
Exit ( 10 ) ;
}
FPRINTF ( NULL , L_71 , V_12 ) ;
}
}
}
if( ! V_38 ) {
FPRINTF ( V_3 , L_72 ) ;
Exit ( 10 ) ;
}
if( F_6 ( V_38 -> V_39 , L_73 ) ) {
FPRINTF ( V_3 , L_74 ) ;
Exit ( 10 ) ;
}
V_38 = V_38 -> V_7 ;
if ( ! V_38 ) {
FPRINTF ( V_3 , L_75 ) ;
Exit ( 10 ) ;
}
V_72 = V_38 -> V_39 ;
V_38 = V_38 -> V_7 ;
FPRINTF ( NULL , L_76 , V_72 ) ;
F_22 ( V_73 , V_67 , L_77 , V_72 ) ;
F_22 ( V_27 , V_67 , L_78 , V_72 ) ;
F_13 ( V_73 , L_79 , V_27 , L_80 , L_81 , L_82 , L_2 , L_83 ) ;
F_22 ( V_73 , V_67 , L_84 , V_72 ) ;
F_22 ( V_27 , V_67 , L_85 , V_72 ) ;
F_13 ( V_73 , L_86 , V_27 , L_87 , L_88 , L_89 , L_2 , L_83 ) ;
FPRINTF ( V_74 , L_90 , V_72 ) ;
FPRINTF ( V_75 , L_91 , V_72 ) ;
if( F_6 ( V_38 -> V_39 , L_27 ) ) {
FPRINTF ( V_3 , L_92 ) ;
Exit ( 10 ) ;
}
V_38 = V_38 -> V_7 ;
if( ! V_70 ) {
FPRINTF ( V_3 , L_93 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_76 , L_94 , V_72 ) ;
FPRINTF ( V_76 , L_95 , V_70 [ 1 ] , V_70 [ 2 ] , V_70 [ 3 ] , V_70 [ 4 ] , V_70 [ 5 ] , V_70 [ 6 ] , V_70 [ 7 ] , V_70 [ 8 ] , V_70 [ 10 ] , V_70 [ 11 ] , V_70 [ 12 ] , V_70 [ 13 ] , V_70 [ 15 ] , V_70 [ 16 ] , V_70 [ 17 ] , V_70 [ 18 ] ) ;
FPRINTF ( V_76 , L_96 , V_70 [ 20 ] , V_70 [ 21 ] , V_70 [ 22 ] , V_70 [ 23 ] , V_70 [ 25 ] , V_70 [ 26 ] , V_70 [ 27 ] , V_70 [ 28 ] , V_70 [ 29 ] , V_70 [ 30 ] , V_70 [ 31 ] , V_70 [ 32 ] , V_70 [ 33 ] , V_70 [ 34 ] , V_70 [ 35 ] , V_70 [ 36 ] ) ;
FPRINTF ( V_76 , L_97 ) ;
FPRINTF ( V_76 , L_21 ) ;
sscanf ( V_71 , L_98 , & V_68 , & V_69 ) ;
FPRINTF ( V_76 , L_99 , V_72 , V_68 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_77 , L_100 , V_72 , V_72 ) ;
FPRINTF ( V_77 , L_101 , V_72 , V_72 ) ;
FPRINTF ( V_77 , L_102 , V_72 ) ;
}
static void F_23 ( char * V_78 )
{
T_9 * V_79 ;
V_79 = F_3 ( T_9 , 1 ) ;
if ( ! V_79 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_79 -> V_7 = NULL ;
V_79 -> V_39 = V_78 ;
if( ! V_38 ) {
V_38 = V_79 ;
} else {
V_80 -> V_7 = V_79 ;
}
V_80 = V_79 ;
}
static void F_24 ( T_1 * V_1 )
{
int V_81 ;
int V_82 = 0 ;
int V_83 = 0 ;
int V_84 = 0 ;
char V_85 [ 4 * V_67 ] ;
int V_86 = 0 ;
int V_87 = 0 ;
char V_78 [ 4 * V_67 ] ;
int V_88 = 0 ;
while( ! feof ( V_1 ) ) {
V_81 = fgetc ( V_1 ) ;
if( V_82 ) {
if( ( V_81 == '\n' ) || ( V_81 == '\r' ) ) {
V_82 = 0 ;
V_89 = 0 ;
}
continue;
}
if( ( V_81 == '#' ) && ( V_89 == 0 ) ) {
V_82 = 1 ;
continue;
}
if( V_83 == 0 ) {
if( V_81 == '/' ) {
int V_90 ;
V_90 = fgetc ( V_1 ) ;
if( V_90 == '*' ) {
V_83 = 1 ;
continue;
}
ungetc ( V_90 , V_1 ) ;
}
} else {
if( V_81 == '*' ) {
int V_90 ;
V_90 = fgetc ( V_1 ) ;
if( V_90 == '/' ) {
V_83 = 0 ;
continue;
}
ungetc ( V_90 , V_1 ) ;
}
continue;
}
if( V_84 ) {
if( V_81 == '"' ) {
V_84 = 0 ;
V_85 [ V_86 ++ ] = '"' ;
V_85 [ V_86 ] = 0 ;
F_23 ( F_4 ( V_85 , strlen ( V_85 ) ) ) ;
continue;
} else {
V_85 [ V_86 ++ ] = ( char ) V_81 ;
continue;
}
} else {
if( V_81 == '"' ) {
V_84 = 1 ;
V_85 [ 0 ] = '"' ;
V_86 = 1 ;
continue;
}
}
switch( V_81 ) {
case '\n' :
case '\r' :
if( V_87 ) {
V_87 = 0 ;
V_78 [ V_88 ] = 0 ;
F_23 ( F_4 ( V_78 , strlen ( V_78 ) ) ) ;
}
line [ V_89 ] = 0 ;
V_89 = 0 ;
V_91 ++ ;
break;
case '\t' :
case ' ' :
if( V_87 ) {
V_87 = 0 ;
V_78 [ V_88 ] = 0 ;
F_23 ( F_4 ( V_78 , strlen ( V_78 ) ) ) ;
}
break;
case '[' :
case ']' :
case '(' :
case ')' :
case ',' :
case ';' :
case '*' :
case '=' :
if( V_87 ) {
V_87 = 0 ;
V_78 [ V_88 ] = 0 ;
F_23 ( F_4 ( V_78 , strlen ( V_78 ) ) ) ;
}
V_78 [ 0 ] = ( char ) V_81 ;
V_78 [ 1 ] = 0 ;
F_23 ( F_4 ( V_78 , strlen ( V_78 ) ) ) ;
break;
default:
if( ! V_87 ) {
V_88 = 0 ;
}
V_87 = 1 ;
V_78 [ V_88 ++ ] = ( char ) V_81 ;
line [ V_89 ++ ] = ( char ) V_81 ;
break;
}
}
}
static T_11 *
F_18 ( char * V_4 )
{
T_11 * V_92 ;
for( V_92 = V_63 ; V_92 ; V_92 = V_92 -> V_7 ) {
if( ! F_6 ( V_92 -> V_4 , V_4 ) ) {
break;
}
}
if( ! V_92 ) {
char V_61 [ V_93 ] ;
if( ! F_6 ( V_4 , L_103 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_109 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_103 , V_61 , L_80 , L_81 , L_2 , L_82 , 2 ) ;
} else if( ! F_6 ( V_4 , L_112 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_109 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_112 , V_61 , L_113 , L_81 , L_2 , L_82 , 2 ) ;
} else if( ! F_6 ( V_4 , L_114 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_115 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_114 , V_61 , L_87 , L_81 , L_2 , L_82 , 4 ) ;
} else if( ( ! F_6 ( V_4 , L_116 ) )
|| ( ! F_6 ( V_4 , L_117 ) ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_115 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
if ( ! F_6 ( V_4 , L_116 ) )
V_92 = F_19 ( L_116 , V_61 , L_118 , L_81 , L_2 , L_82 , 4 ) ;
else
V_92 = F_19 ( L_117 , V_61 , L_118 , L_81 , L_2 , L_82 , 4 ) ;
} else if( ( ! F_6 ( V_4 , L_119 ) ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_120 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_119 , V_61 , L_121 , L_81 , L_2 , L_82 , 1 ) ;
} else if( ( ! F_6 ( V_4 , L_122 ) )
|| ( ! F_6 ( V_4 , L_123 ) ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_120 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
if ( ! F_6 ( V_4 , L_122 ) )
V_92 = F_19 ( L_122 , V_61 , L_124 , L_81 , L_2 , L_82 , 1 ) ;
else
V_92 = F_19 ( L_123 , V_61 , L_124 , L_81 , L_2 , L_82 , 1 ) ;
} else if( ! F_6 ( V_4 , L_125 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_120 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_125 , V_61 , L_124 , L_81 , L_2 , L_82 , 1 ) ;
} else if( ! F_6 ( V_4 , L_126 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_127 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_126 , V_61 , L_128 , L_129 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_130 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_131 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_130 , V_61 , L_128 , L_129 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_132 )
|| ! F_6 ( V_4 , L_133 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_134 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( V_4 , V_61 , L_135 , L_129 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_136 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_137 ) ;
FPRINTF ( V_76 , L_138 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_139 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_140 ) ;
FPRINTF ( V_76 , L_141 ) ;
FPRINTF ( V_76 , L_142 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_136 , V_61 , L_143 , L_129 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_144 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_145 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_144 , V_61 , L_146 , L_147 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_148 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_149 ) ;
FPRINTF ( V_76 , L_145 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_148 , V_61 , L_146 , L_147 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_150 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_149 ) ;
FPRINTF ( V_76 , L_145 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_150 , V_61 , L_146 , L_147 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_151 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_152 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_151 , V_61 , L_153 , L_81 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_154 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_152 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_154 , V_61 , L_155 , L_81 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_156 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_157 ) ;
FPRINTF ( V_76 , L_149 ) ;
FPRINTF ( V_76 , L_158 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_156 , V_61 , L_153 , L_81 , L_2 , L_82 , 8 ) ;
} else if( ! F_6 ( V_4 , L_159 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_157 ) ;
FPRINTF ( V_76 , L_160 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_159 , V_61 , L_146 , L_147 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_161 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_139 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_162 ) ;
FPRINTF ( V_76 , L_163 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_161 , V_61 , L_128 , L_129 , L_2 , L_82 , 4 ) ;
} else if( ! F_6 ( V_4 , L_164 ) ) {
F_22 ( V_61 , V_93 , L_104 , V_72 , V_4 ) ;
FPRINTF ( NULL , L_105 , V_4 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_157 ) ;
FPRINTF ( V_76 , L_115 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_92 = F_19 ( L_164 , V_61 , L_87 , L_81 , L_2 , L_89 , 4 ) ;
}
}
return V_92 ;
}
static void F_25 ( void )
{
T_9 * V_37 ;
V_37 = V_38 ;
if( strncmp ( V_37 -> V_39 , L_165 , 7 ) ) {
FPRINTF ( V_3 , L_166 ) ;
Exit ( 10 ) ;
}
while( V_37 -> V_39 [ 0 ] != ';' ) {
V_37 = V_37 -> V_7 ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
static void F_26 ( void )
{
T_9 * V_37 ;
char * V_4 , * V_5 ;
V_37 = V_38 ;
if( strncmp ( V_37 -> V_39 , L_167 , 5 ) ) {
FPRINTF ( V_3 , L_168 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_37 = V_37 -> V_7 ;
if( F_18 ( V_37 -> V_39 ) ) {
FPRINTF ( V_3 , L_169 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_4 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( V_37 -> V_39 [ 0 ] != '=' ) {
FPRINTF ( V_3 , L_170 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_5 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( V_37 -> V_39 [ 0 ] != ';' ) {
FPRINTF ( V_3 , L_171 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
FPRINTF ( NULL , L_172 , V_4 ) ;
FPRINTF ( V_94 , L_173 , V_4 , V_5 ) ;
FPRINTF ( NULL , L_174 , V_4 ) ;
V_38 = V_37 ;
}
static void F_27 ( int V_95 )
{
T_9 * V_37 , * V_40 ;
char * V_96 ;
char V_61 [ V_93 ] ;
char V_97 [ V_67 ] , * V_98 ;
int V_51 , V_10 ;
static int V_54 ;
T_11 * V_43 ;
char V_99 [ V_67 ] ;
T_10 * V_100 = NULL ;
T_4 * V_11 ;
const char * V_13 ;
char * V_101 ;
int V_102 ;
int V_103 ;
int V_104 = 0 ;
V_37 = V_38 ;
if( F_6 ( V_37 -> V_39 , L_175 ) ) {
FPRINTF ( V_3 , L_176 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
V_37 = F_17 ( V_37 , & V_100 ) ;
}
if( V_100 ) {
if( V_100 -> V_44 ) {
FPRINTF ( V_3 , L_177 , V_100 -> V_44 ) ;
Exit ( 10 ) ;
}
}
if( F_6 ( V_37 -> V_39 , L_178 ) ) {
FPRINTF ( V_3 , L_179 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_27 ) ) {
FPRINTF ( V_3 , L_180 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_28 ) == 0 ) {
V_104 = 1 ;
}
for( V_40 = V_37 , V_51 = 0 ; V_40 ; V_40 = V_40 -> V_7 ) {
if( ! F_6 ( V_40 -> V_39 , L_27 ) ) {
V_51 ++ ;
continue;
}
if( ! F_6 ( V_40 -> V_39 , L_28 ) ) {
if( ! V_51 ) {
break;
}
V_51 -- ;
continue;
}
}
if( ! V_40 || ! V_40 -> V_7 ) {
FPRINTF ( V_3 , L_181 ) ;
Exit ( 10 ) ;
}
V_96 = V_40 -> V_7 -> V_39 ;
F_22 ( V_61 , V_93 , L_104 , V_72 , V_96 ) ;
FPRINTF ( NULL , L_182 , V_96 , V_95 ) ;
if( ! F_14 ( V_61 ) ) {
FPRINTF ( NULL , L_183 ) ;
V_37 = V_40 ;
goto V_105;
}
if( V_95 == 0 ) {
V_54 = 1 ;
}
if( V_95 == 1 ) {
FPRINTF ( V_74 , L_184 , V_72 , V_96 ) ;
FPRINTF ( V_75 , L_185 , V_72 , V_96 ) ;
FPRINTF ( V_94 , L_186 , V_61 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_187 ) ;
FPRINTF ( V_76 , L_188 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_189 ) ;
if( ! V_104 ) {
FPRINTF ( V_76 , L_190 ) ;
}
FPRINTF ( V_76 , L_191 ) ;
FPRINTF ( V_76 , L_21 ) ;
switch( V_54 ) {
case 1 :
break;
case 2 :
FPRINTF ( V_76 , L_192 ) ;
FPRINTF ( V_76 , L_21 ) ;
break;
case 4 :
FPRINTF ( V_76 , L_193 ) ;
FPRINTF ( V_76 , L_21 ) ;
break;
case 8 :
FPRINTF ( V_76 , L_149 ) ;
FPRINTF ( V_76 , L_21 ) ;
break;
default:
FPRINTF ( V_3 , L_194 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_76 , L_195 ) ;
FPRINTF ( V_76 , L_196 ) ;
FPRINTF ( V_76 , L_197 ) ;
if( ! V_104 ) {
FPRINTF ( V_76 , L_198 , V_72 , V_96 ) ;
}
FPRINTF ( V_76 , L_199 ) ;
FPRINTF ( V_76 , L_21 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_27 ) ) {
V_51 ++ ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_28 ) ) {
if( ! V_51 ) {
break;
}
V_51 -- ;
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
V_37 = F_17 ( V_37 , & V_100 ) ;
continue;
}
if( V_100 ) {
if( V_100 -> V_44 & ( ~ ( V_55 | V_56 | V_60 ) ) ) {
FPRINTF ( V_3 , L_177 , V_100 -> V_44 ) ;
Exit ( 10 ) ;
}
}
V_43 = F_18 ( V_37 -> V_39 ) ;
if( ! V_43 ) {
FPRINTF ( V_3 , L_200 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_10 = 0 ; ! F_6 ( V_37 -> V_39 , L_201 ) ; V_37 = V_37 -> V_7 ) {
V_10 ++ ;
if( V_54 < 4 ) {
V_54 = 4 ;
}
}
V_11 = F_7 ( V_100 ? V_100 -> V_46 : NULL , V_10 ) ;
if( V_54 < V_43 -> V_54 ) {
V_54 = V_43 -> V_54 ;
}
V_101 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
V_102 = 0 ;
V_103 = 0 ;
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
char V_106 [ V_67 ] ;
V_37 = V_37 -> V_7 ;
V_102 = atoi ( V_37 -> V_39 ) ;
F_22 ( V_106 , V_67 , L_202 , V_102 ) ;
if( ! F_6 ( L_31 , V_37 -> V_39 ) ) {
V_102 = 0 ;
} else if( ! F_6 ( L_201 , V_37 -> V_39 ) ) {
V_11 = F_7 ( V_11 , V_10 + 1 ) ;
V_102 = 0 ;
V_103 = 1 ;
V_37 = V_37 -> V_7 ;
} else if( F_6 ( V_106 , V_37 -> V_39 ) ) {
FPRINTF ( V_3 , L_203 , V_96 , V_106 , V_37 -> V_39 ) ;
V_37 = V_37 -> V_7 ;
Exit ( 10 ) ;
} else {
V_37 = V_37 -> V_7 ;
}
if( F_6 ( V_37 -> V_39 , L_31 ) ) {
FPRINTF ( V_3 , L_204 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
}
F_22 ( V_99 , V_67 , L_205 , V_72 , V_96 , V_101 ) ;
if( V_95 == 0 ) {
char V_27 [ V_67 ] ;
const char * V_107 ;
F_22 ( V_97 , V_67 , L_206 , V_72 , V_96 , V_101 ) ;
V_98 = F_4 ( V_97 , 26 ) ;
if( F_14 ( V_97 ) ) {
F_22 ( V_27 , V_67 , L_207 , V_72 , V_96 , V_101 ) ;
V_107 = F_13 ( V_99 , V_101 , V_27 , V_43 -> V_28 , V_43 -> V_29 , V_43 -> V_65 , V_43 -> V_31 , L_83 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_98 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_209 , F_5 ( V_98 ) ) ;
FPRINTF ( V_76 , L_210 , V_43 -> V_64 , V_107 ) ;
FPRINTF ( V_76 , L_211 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
} else {
FPRINTF ( NULL , L_212 , V_97 ) ;
}
if( V_103 ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
F_22 ( V_97 , V_67 , L_213 , V_13 , V_98 ) ;
if( F_14 ( V_97 ) ) {
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_214 , V_98 , F_8 ( V_13 ) , V_101 ) ;
FPRINTF ( V_76 , L_211 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
} else {
FPRINTF ( NULL , L_212 , V_97 ) ;
}
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
} else if( V_102 ) {
F_22 ( V_97 , V_67 , L_215 , V_98 ) ;
if( F_14 ( V_97 ) ) {
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_216 , V_102 ) ;
FPRINTF ( V_76 , L_217 ) ;
FPRINTF ( V_76 , L_218 , V_98 ) ;
FPRINTF ( V_76 , L_219 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_211 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
} else {
FPRINTF ( NULL , L_212 , V_97 ) ;
}
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
}
if( V_100 ) {
switch( V_100 -> V_44 & ( V_55 | V_56 ) ) {
case 0 :
break;
case V_55 :
F_22 ( V_97 , V_67 , L_220 , V_98 ) ;
if( F_14 ( V_97 ) ) {
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_221 , V_98 ) ;
FPRINTF ( V_76 , L_211 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
} else {
FPRINTF ( NULL , L_212 , V_97 ) ;
}
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
case V_56 :
F_22 ( V_97 , V_67 , L_222 , V_98 ) ;
if( F_14 ( V_97 ) ) {
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_223 , V_98 ) ;
FPRINTF ( V_76 , L_211 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
} else {
FPRINTF ( NULL , L_212 , V_97 ) ;
}
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
case V_55 | V_56 :
F_22 ( V_97 , V_67 , L_224 , V_98 ) ;
if( F_14 ( V_97 ) ) {
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_225 , V_98 ) ;
FPRINTF ( V_76 , L_211 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
} else {
FPRINTF ( NULL , L_212 , V_97 ) ;
}
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
default:
FPRINTF ( V_3 , L_226 ) ;
Exit ( 10 ) ;
}
}
while( V_10 -- ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
F_22 ( V_97 , V_67 , L_213 , V_13 , V_98 ) ;
if( F_14 ( V_97 ) ) {
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_214 , V_98 , F_8 ( V_13 ) , V_101 ) ;
FPRINTF ( V_76 , L_211 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
} else {
FPRINTF ( NULL , L_212 , V_97 ) ;
}
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
}
}
if( V_95 == 1 ) {
F_22 ( V_97 , V_67 , L_206 , V_72 , V_96 , V_101 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
if( V_103 ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
F_22 ( V_97 , V_67 , L_213 , V_13 , V_98 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
} else if( V_102 ) {
F_22 ( V_97 , V_67 , L_215 , V_98 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
}
if( V_100 ) {
switch( V_100 -> V_44 & ( V_55 | V_56 ) ) {
case 0 :
break;
case V_55 :
F_22 ( V_97 , V_67 , L_220 , V_98 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
case V_56 :
F_22 ( V_97 , V_67 , L_222 , V_98 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
case V_55 | V_56 :
F_22 ( V_97 , V_67 , L_224 , V_98 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
default:
FPRINTF ( V_3 , L_226 ) ;
Exit ( 10 ) ;
}
}
while( V_10 -- ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
F_22 ( V_97 , V_67 , L_213 , V_13 , V_98 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
}
FPRINTF ( V_76 , L_227 , V_98 ) ;
FPRINTF ( V_76 , L_21 ) ;
}
if( F_6 ( V_37 -> V_39 , L_228 ) ) {
FPRINTF ( V_3 , L_229 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_100 = NULL ;
}
if( V_95 == 1 ) {
FPRINTF ( V_76 , L_230 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
F_19 ( V_96 , V_61 , L_231 , L_129 , L_2 , L_82 , V_54 ) ;
}
V_105:
FPRINTF ( NULL , L_232 , V_96 , V_95 ) ;
if( V_95 == 1 ) {
if( ! V_37 || F_6 ( V_37 -> V_39 , L_28 ) ) {
FPRINTF ( V_3 , L_233 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_37 = V_37 -> V_7 ;
if( ! V_37 || F_6 ( V_37 -> V_39 , L_228 ) ) {
FPRINTF ( V_3 , L_234 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
}
static void F_28 ( int V_95 )
{
T_9 * V_37 , * V_40 ;
char * V_108 ;
char V_61 [ V_67 ] , V_109 [ V_67 ] ;
int V_54 ;
unsigned int V_110 ;
char * V_4 , * V_5 ;
T_10 * V_100 = NULL ;
V_37 = V_38 ;
if( F_6 ( V_37 -> V_39 , L_175 ) ) {
FPRINTF ( V_3 , L_235 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_54 = 4 ;
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
V_37 = F_17 ( V_37 , & V_100 ) ;
}
if( V_100 ) {
if( V_100 -> V_44 & ( ~ ( V_58 | V_57 ) ) ) {
FPRINTF ( V_3 , L_236 , V_100 -> V_44 ) ;
Exit ( 10 ) ;
}
if( V_100 -> V_44 & V_58 ) {
V_54 = 4 ;
}
if( V_100 -> V_44 & V_57 ) {
V_54 = 1 ;
}
}
if( F_6 ( V_37 -> V_39 , L_237 ) ) {
FPRINTF ( V_3 , L_238 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_27 ) ) {
FPRINTF ( V_3 , L_239 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_40 = V_37 ; V_40 ; V_40 = V_40 -> V_7 ) {
if( ! F_6 ( V_40 -> V_39 , L_27 ) ) {
FPRINTF ( V_3 , L_240 ) ;
Exit ( 10 ) ;
}
if( ! F_6 ( V_40 -> V_39 , L_28 ) ) {
break;
}
}
if ( ! V_40 || ! V_40 -> V_7 ) {
FPRINTF ( V_3 , L_241 ) ;
Exit ( 10 ) ;
}
V_108 = V_40 -> V_7 -> V_39 ;
F_22 ( V_61 , V_93 , L_104 , V_72 , V_108 ) ;
FPRINTF ( NULL , L_242 , V_108 , V_95 ) ;
if( V_95 == 1 ) {
FPRINTF ( V_74 , L_184 , V_72 , V_108 ) ;
FPRINTF ( V_75 , L_185 , V_72 , V_108 ) ;
FPRINTF ( V_94 , L_186 , V_61 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_187 ) ;
FPRINTF ( V_76 , L_243 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_189 ) ;
FPRINTF ( V_76 , L_190 ) ;
switch( V_54 ) {
case 1 :
FPRINTF ( V_76 , L_244 ) ;
FPRINTF ( V_76 , L_21 ) ;
break;
case 4 :
FPRINTF ( V_76 , L_245 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_193 ) ;
break;
default:
FPRINTF ( V_3 , L_246 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_196 ) ;
FPRINTF ( V_76 , L_247 , V_54 ) ;
FPRINTF ( V_76 , L_198 , V_72 , V_108 ) ;
FPRINTF ( V_76 , L_199 ) ;
FPRINTF ( V_76 , L_21 ) ;
switch( V_54 ) {
case 1 :
FPRINTF ( V_76 , L_248 ) ;
FPRINTF ( V_76 , L_21 ) ;
break;
case 4 :
FPRINTF ( V_76 , L_249 ) ;
FPRINTF ( V_76 , L_21 ) ;
break;
default:
FPRINTF ( V_3 , L_246 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_76 , L_21 ) ;
}
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_28 ) ) {
break;
}
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
FPRINTF ( V_3 , L_250 ) ;
Exit ( 10 ) ;
}
V_4 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
F_22 ( V_109 , V_67 , L_205 , V_72 , V_108 , V_4 ) ;
if( F_6 ( V_37 -> V_39 , L_251 ) ) {
FPRINTF ( V_3 , L_252 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_5 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
V_110 = 0 ;
if( ! strncmp ( V_5 , L_253 , 2 ) ) {
sscanf ( V_5 , L_254 , & V_110 ) ;
} else {
FPRINTF ( V_3 , L_255 ) ;
Exit ( 10 ) ;
}
if( V_110 & ( V_110 - 1 ) ) {
FPRINTF ( V_3 , L_256 ) ;
Exit ( 10 ) ;
}
if( V_95 == 0 ) {
char V_27 [ V_67 ] , V_111 [ V_67 ] , V_112 [ V_67 ] ;
F_22 ( V_27 , V_67 , L_207 , V_72 , V_108 , V_4 ) ;
F_22 ( V_111 , V_67 , L_202 , V_54 * 8 ) ;
F_22 ( V_112 , V_67 , L_257 , V_4 ) ;
F_13 ( V_109 , V_4 , V_27 , L_258 , V_111 , V_112 , V_5 , L_83 ) ;
FPRINTF ( V_76 , L_259 , V_4 ) ;
FPRINTF ( V_76 , L_260 , V_4 ) ;
FPRINTF ( V_76 , L_261 , V_4 ) ;
FPRINTF ( V_76 , L_97 ) ;
FPRINTF ( V_76 , L_21 ) ;
}
if( V_95 == 1 ) {
FPRINTF ( V_76 , L_262 , V_109 , V_54 , V_54 ) ;
FPRINTF ( V_76 , L_263 , V_5 ) ;
FPRINTF ( V_76 , L_264 , V_4 ) ;
FPRINTF ( V_76 , L_199 ) ;
FPRINTF ( V_76 , L_265 , V_5 ) ;
FPRINTF ( V_76 , L_21 ) ;
}
if( ! F_6 ( V_37 -> V_39 , L_32 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
}
if( V_95 == 1 ) {
FPRINTF ( V_76 , L_266 ) ;
FPRINTF ( V_76 , L_267 ) ;
FPRINTF ( V_76 , L_199 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
switch( V_54 ) {
case 1 :
F_19 ( V_108 , V_61 , L_121 , L_88 , L_2 , L_82 , V_54 ) ;
break;
case 4 :
F_19 ( V_108 , V_61 , L_87 , L_88 , L_2 , L_82 , V_54 ) ;
break;
default:
FPRINTF ( V_3 , L_246 , V_54 ) ;
Exit ( 10 ) ;
}
}
FPRINTF ( NULL , L_268 , V_108 , V_95 ) ;
if( V_95 == 1 ) {
if( ! V_37 || F_6 ( V_37 -> V_39 , L_28 ) ) {
FPRINTF ( V_3 , L_269 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_37 = V_37 -> V_7 ;
if( ! V_37 || F_6 ( V_37 -> V_39 , L_228 ) ) {
FPRINTF ( V_3 , L_270 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
}
static const char *
F_29 ( const char * V_39 )
{
char * V_113 ;
if( V_39 [ 0 ] != '-' ) {
return V_39 ;
}
V_113 = F_4 ( V_39 , strlen ( V_39 ) ) ;
V_113 [ 0 ] = 'm' ;
return V_113 ;
}
static void F_30 ( int V_95 )
{
char * V_114 ;
T_9 * V_37 , * V_40 ;
char V_61 [ V_67 ] ;
T_10 * V_100 = NULL ;
char V_97 [ V_67 ] , * V_98 ;
int V_51 , V_10 ;
static int V_54 ;
T_11 * V_43 ;
char V_99 [ V_67 ] ;
int V_115 , V_116 ;
V_37 = V_38 ;
if( F_6 ( V_37 -> V_39 , L_175 ) ) {
FPRINTF ( V_3 , L_271 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
V_37 = F_17 ( V_37 , & V_100 ) ;
}
if( V_100 ) {
if( V_100 -> V_44 & ( ~ ( V_52 ) ) ) {
FPRINTF ( V_3 , L_272 , V_100 -> V_44 ) ;
Exit ( 10 ) ;
}
}
if( F_6 ( V_37 -> V_39 , L_273 ) ) {
FPRINTF ( V_3 , L_274 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_27 ) ) {
FPRINTF ( V_3 , L_275 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_40 = V_37 , V_51 = 0 ; V_40 ; V_40 = V_40 -> V_7 ) {
if( ! F_6 ( V_40 -> V_39 , L_27 ) ) {
V_51 ++ ;
continue;
}
if( ! F_6 ( V_40 -> V_39 , L_28 ) ) {
if( ! V_51 ) {
break;
}
V_51 -- ;
continue;
}
}
if ( ! V_40 || ! V_40 -> V_7 ) {
FPRINTF ( V_3 , L_276 ) ;
Exit ( 10 ) ;
}
V_114 = V_40 -> V_7 -> V_39 ;
F_22 ( V_61 , V_93 , L_277 , V_72 , V_114 ) ;
FPRINTF ( NULL , L_278 , V_114 , V_95 ) ;
if( V_100 && V_100 -> V_44 & V_52 ) {
V_115 = V_100 -> V_53 ;
} else {
V_115 = F_9 ( V_114 ) ;
}
if( V_95 == 0 ) {
V_54 = V_115 ;
}
if( V_95 == 1 ) {
FPRINTF ( V_74 , L_184 , V_72 , V_114 ) ;
FPRINTF ( V_75 , L_185 , V_72 , V_114 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_243 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_189 ) ;
FPRINTF ( V_76 , L_190 ) ;
FPRINTF ( V_76 , L_191 ) ;
switch( V_115 ) {
case 1 :
break;
case 2 :
FPRINTF ( V_76 , L_279 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_192 ) ;
FPRINTF ( V_76 , L_21 ) ;
break;
case 4 :
FPRINTF ( V_76 , L_280 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_193 ) ;
FPRINTF ( V_76 , L_21 ) ;
break;
default:
FPRINTF ( V_3 , L_281 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_76 , L_195 ) ;
FPRINTF ( V_76 , L_196 ) ;
FPRINTF ( V_76 , L_282 , V_72 , V_114 , V_114 ) ;
FPRINTF ( V_76 , L_199 ) ;
FPRINTF ( V_76 , L_21 ) ;
switch( V_115 ) {
case 1 :
break;
case 2 :
FPRINTF ( V_76 , L_283 ) ;
FPRINTF ( V_76 , L_284 ) ;
break;
case 4 :
FPRINTF ( V_76 , L_285 ) ;
FPRINTF ( V_76 , L_284 ) ;
break;
default:
FPRINTF ( V_3 , L_286 , V_54 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_287 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_27 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_28 ) ) {
if( ! V_51 ) {
break;
}
V_37 = V_37 -> V_7 ;
V_51 -- ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
V_37 = F_17 ( V_37 , & V_100 ) ;
continue;
}
if( ! V_100 ) {
FPRINTF ( V_3 , L_288 ) ;
Exit ( 10 ) ;
}
if( V_100 -> V_44 & ( ~ ( V_47 | V_48 | V_60 ) ) ) {
FPRINTF ( V_3 , L_272 , V_100 -> V_44 ) ;
Exit ( 10 ) ;
}
if( ! ( V_100 -> V_44 & V_47 ) ) {
FPRINTF ( V_3 , L_289 ) ;
Exit ( 10 ) ;
}
#ifdef F_31
if( V_100 -> V_44 & V_48 ) {
if( F_6 ( V_37 -> V_39 , L_228 ) ) {
FPRINTF ( V_3 , L_290 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
continue;
}
#endif
if( ! F_6 ( V_37 -> V_39 , L_228 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
V_43 = F_18 ( V_37 -> V_39 ) ;
if( ! V_43 ) {
FPRINTF ( V_3 , L_291 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_10 = 0 ; ! F_6 ( V_37 -> V_39 , L_201 ) ; V_37 = V_37 -> V_7 ) {
V_10 ++ ;
}
if( V_10 ) {
V_116 = 4 ;
} else {
V_116 = V_43 -> V_54 ;
}
if( V_54 < V_116 ) {
V_54 = V_116 ;
}
F_22 ( V_99 , V_67 , L_292 , V_72 , V_114 , F_29 ( V_100 -> V_45 ) , V_37 -> V_39 ) ;
if( V_95 == 0 ) {
char V_27 [ V_67 ] ;
const char * V_107 ;
F_22 ( V_97 , V_67 , L_293 , V_72 , V_114 , F_29 ( V_100 -> V_45 ) , V_37 -> V_39 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
F_22 ( V_27 , V_67 , L_207 , V_72 , V_114 , V_37 -> V_39 ) ;
V_107 = F_13 ( V_99 , V_37 -> V_39 , V_27 , V_43 -> V_28 , V_43 -> V_29 , V_43 -> V_65 , V_43 -> V_31 , L_83 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_98 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_294 , F_5 ( V_98 ) ) ;
FPRINTF ( V_76 , L_295 , V_43 -> V_64 , V_107 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
while( V_10 -- ) {
F_22 ( V_97 , V_67 , L_213 , V_98 , L_3 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_296 , V_98 , V_37 -> V_39 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
}
}
if( V_95 == 1 ) {
F_22 ( V_97 , V_67 , L_293 , V_72 , V_114 , F_29 ( V_100 -> V_45 ) , V_37 -> V_39 ) ;
V_98 = F_4 ( V_97 , 26 ) ;
while( V_10 -- ) {
F_22 ( V_97 , V_67 , L_213 , V_98 , L_3 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
}
if( V_100 -> V_44 & V_48 ) {
FPRINTF ( V_76 , L_297 ) ;
} else {
FPRINTF ( V_76 , L_298 , V_100 -> V_45 ) ;
}
switch( V_116 ) {
case 1 :
break;
case 2 :
FPRINTF ( V_76 , L_299 ) ;
break;
case 4 :
FPRINTF ( V_76 , L_300 ) ;
break;
case 8 :
FPRINTF ( V_76 , L_301 ) ;
break;
default:
FPRINTF ( V_3 , L_302 , V_116 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_76 , L_303 , V_98 ) ;
FPRINTF ( V_76 , L_304 ) ;
FPRINTF ( V_76 , L_21 ) ;
}
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_228 ) ) {
FPRINTF ( V_3 , L_305 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
}
if( V_95 == 1 ) {
FPRINTF ( V_76 , L_199 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_230 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_306 ) ;
FPRINTF ( V_76 , L_111 ) ;
switch( V_115 ) {
case 2 :
F_19 ( V_114 , V_61 , L_80 , L_81 , L_2 , L_82 , V_54 ) ;
break;
case 4 :
F_19 ( V_114 , V_61 , L_87 , L_81 , L_2 , L_82 , V_54 ) ;
break;
default:
FPRINTF ( V_3 , L_307 , V_54 ) ;
Exit ( 10 ) ;
}
}
FPRINTF ( NULL , L_308 , V_114 , V_95 ) ;
if( V_95 == 1 ) {
if( ! V_37 || F_6 ( V_37 -> V_39 , L_28 ) ) {
FPRINTF ( V_3 , L_309 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_37 = V_37 -> V_7 ;
if( ! V_37 || F_6 ( V_37 -> V_39 , L_228 ) ) {
FPRINTF ( V_3 , L_310 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
}
static void F_32 ( int V_95 )
{
char * V_117 ;
static int V_118 = 0 ;
T_9 * V_37 ;
T_10 * V_100 = NULL ;
T_4 * V_11 ;
const char * V_13 ;
char V_97 [ V_67 ] , * V_98 ;
int V_51 , V_10 ;
T_11 * V_43 ;
char V_99 [ V_67 ] ;
V_37 = V_38 ;
if( F_6 ( V_37 -> V_39 , L_164 ) ) {
FPRINTF ( V_3 , L_311 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_117 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_23 ) ) {
FPRINTF ( V_3 , L_312 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
FPRINTF ( NULL , L_313 , V_117 , V_95 ) ;
if( V_95 == 0 ) {
FPRINTF ( V_119 , L_314 , V_118 , V_117 ) ;
FPRINTF ( V_119 , L_315 , V_72 , V_117 ) ;
FPRINTF ( V_119 , L_316 , V_72 , V_117 ) ;
V_118 ++ ;
}
if( ( V_95 == 1 ) || ( V_95 == 2 ) ) {
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_317 , V_72 , V_117 , ( V_95 == 1 ) ? L_318 : L_319 ) ;
FPRINTF ( V_76 , L_108 ) ;
}
V_51 = 0 ;
while( V_37 ) {
if( ! F_6 ( V_37 -> V_39 , L_23 ) ) {
V_37 = V_37 -> V_7 ;
V_51 ++ ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_24 ) ) {
if( ! V_51 ) {
break;
}
V_37 = V_37 -> V_7 ;
V_51 -- ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
V_37 = F_17 ( V_37 , & V_100 ) ;
continue;
}
if( ! V_100 ) {
FPRINTF ( V_3 , L_320 ) ;
Exit ( 10 ) ;
}
if( V_100 -> V_44 & ( ~ ( V_49 | V_50 | V_60 | V_55 | V_56 ) ) ) {
FPRINTF ( V_3 , L_321 , V_100 -> V_44 ) ;
Exit ( 10 ) ;
}
if( ! ( V_100 -> V_44 & ( V_49 | V_50 ) ) ) {
FPRINTF ( V_3 , L_322 ) ;
Exit ( 10 ) ;
}
V_43 = F_18 ( V_37 -> V_39 ) ;
if( ! V_43 ) {
FPRINTF ( V_3 , L_323 , V_37 -> V_39 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
for( V_10 = 0 ; ! F_6 ( V_37 -> V_39 , L_201 ) ; V_37 = V_37 -> V_7 ) {
V_10 ++ ;
}
V_11 = F_7 ( V_100 -> V_46 , V_10 ) ;
F_22 ( V_99 , V_67 , L_205 , V_72 , V_117 , V_37 -> V_39 ) ;
if( V_95 == 0 ) {
char V_27 [ V_67 ] ;
const char * V_107 ;
F_22 ( V_97 , V_67 , L_206 , V_72 , V_117 , V_37 -> V_39 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
F_22 ( V_27 , V_67 , L_207 , V_72 , V_117 , V_37 -> V_39 ) ;
V_107 = F_13 ( V_99 , V_37 -> V_39 , V_27 , V_43 -> V_28 , V_43 -> V_29 , V_43 -> V_65 , V_43 -> V_31 , L_83 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_98 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_294 , F_5 ( V_98 ) ) ;
FPRINTF ( V_76 , L_295 , V_43 -> V_64 , V_107 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
if( V_100 ) {
switch( V_100 -> V_44 & ( V_55 | V_56 ) ) {
case 0 :
break;
case V_55 | V_56 :
F_22 ( V_97 , V_67 , L_224 , V_98 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_324 , V_98 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
case V_55 :
F_22 ( V_97 , V_67 , L_220 , V_98 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_325 , V_98 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
default:
FPRINTF ( V_3 , L_326 ) ;
Exit ( 10 ) ;
}
}
while( V_10 -- ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
F_22 ( V_97 , V_67 , L_213 , V_13 , V_98 ) ;
FPRINTF ( V_76 , L_106 ) ;
FPRINTF ( V_76 , L_208 , V_97 ) ;
FPRINTF ( V_76 , L_108 ) ;
FPRINTF ( V_76 , L_327 , V_98 , F_8 ( V_13 ) , V_37 -> V_39 ) ;
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
}
}
if( ( V_95 == 1 ) || ( V_95 == 2 ) ) {
F_22 ( V_97 , V_67 , L_206 , V_72 , V_117 , V_37 -> V_39 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
if( V_100 ) {
switch( V_100 -> V_44 & ( V_55 | V_56 ) ) {
case 0 :
break;
case V_55 | V_56 :
F_22 ( V_97 , V_67 , L_224 , V_98 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
case V_55 :
F_22 ( V_97 , V_67 , L_220 , V_98 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
break;
default:
FPRINTF ( V_3 , L_326 ) ;
Exit ( 10 ) ;
}
}
while( V_10 -- ) {
V_13 = V_11 -> type ;
V_11 = V_11 -> V_7 ;
F_22 ( V_97 , V_67 , L_213 , V_13 , V_98 ) ;
V_98 = F_4 ( V_97 , strlen ( V_97 ) ) ;
}
if( ( V_95 == 1 ) && ( V_100 -> V_44 & V_49 ) ) {
FPRINTF ( V_76 , L_303 , V_98 ) ;
FPRINTF ( V_76 , L_328 ) ;
FPRINTF ( V_76 , L_21 ) ;
}
if( ( V_95 == 2 ) && ( V_100 -> V_44 & V_50 ) ) {
FPRINTF ( V_76 , L_303 , V_98 ) ;
FPRINTF ( V_76 , L_328 ) ;
FPRINTF ( V_76 , L_21 ) ;
}
}
V_37 = V_37 -> V_7 ;
if( ! F_6 ( V_37 -> V_39 , L_32 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
}
if( ( V_95 == 1 ) || ( V_95 == 2 ) ) {
if( V_95 == 2 ) {
FPRINTF ( V_76 , L_329 , V_73 ) ;
FPRINTF ( V_76 , L_21 ) ;
}
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_306 ) ;
FPRINTF ( V_76 , L_111 ) ;
}
FPRINTF ( NULL , L_330 , V_117 , V_95 ) ;
if( V_95 == 2 ) {
if( ! V_37 || F_6 ( V_37 -> V_39 , L_24 ) ) {
FPRINTF ( V_3 , L_331 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( ! V_37 || F_6 ( V_37 -> V_39 , L_228 ) ) {
FPRINTF ( V_3 , L_332 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_38 = V_37 ;
}
}
static void F_33 ( void )
{
T_9 * V_37 ;
T_12 * V_120 , * V_121 , * V_122 ;
char * V_123 ;
long V_110 ;
int V_124 , V_125 ;
char V_61 [ V_67 ] , V_30 [ V_67 ] , V_126 [ V_67 ] ;
V_125 = 16 ;
V_37 = V_38 ;
if( F_6 ( V_37 -> V_39 , L_175 ) ) {
FPRINTF ( V_3 , L_333 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( ! F_6 ( V_37 -> V_39 , L_25 ) ) {
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_334 ) ) {
FPRINTF ( V_3 , L_335 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_31 ) ) {
FPRINTF ( V_3 , L_336 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_125 = 32 ;
}
if( F_6 ( V_37 -> V_39 , L_337 ) ) {
FPRINTF ( V_3 , L_338 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
if( F_6 ( V_37 -> V_39 , L_27 ) ) {
FPRINTF ( V_3 , L_339 ) ;
Exit ( 10 ) ;
}
V_37 = V_37 -> V_7 ;
V_124 = 0 ;
V_120 = NULL ;
V_122 = NULL ;
while( 1 ) {
if( ! F_6 ( V_37 -> V_39 , L_28 ) ) {
V_37 = V_37 -> V_7 ;
break;
}
V_121 = F_3 ( T_12 , 1 ) ;
if ( ! V_121 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_121 -> V_7 = NULL ;
if( ! V_120 ) {
V_120 = V_121 ;
} else {
V_122 -> V_7 = V_121 ;
}
V_122 = V_121 ;
V_121 -> V_4 = V_37 -> V_39 ;
V_37 = V_37 -> V_7 ;
if( ! F_6 ( V_37 -> V_39 , L_251 ) ) {
V_37 = V_37 -> V_7 ;
V_110 = strtol ( V_37 -> V_39 , & V_123 , 0 ) ;
if ( V_123 == V_37 -> V_39 || * V_123 ) {
FPRINTF ( V_3 , L_340 ) ;
Exit ( 10 ) ;
}
V_121 -> V_110 = ( int ) V_110 ;
V_37 = V_37 -> V_7 ;
} else {
V_121 -> V_110 = V_124 ;
}
V_124 = V_121 -> V_110 + 1 ;
if( ! F_6 ( V_37 -> V_39 , L_32 ) ) {
V_37 = V_37 -> V_7 ;
continue;
}
if( ! F_6 ( V_37 -> V_39 , L_28 ) ) {
V_37 = V_37 -> V_7 ;
break;
}
FPRINTF ( V_3 , L_341 ) ;
Exit ( 10 ) ;
}
if( F_6 ( V_37 -> V_7 -> V_39 , L_228 ) ) {
FPRINTF ( V_3 , L_342 ) ;
Exit ( 10 ) ;
}
F_22 ( V_30 , V_67 , L_343 , V_72 , V_37 -> V_39 ) ;
F_22 ( V_61 , V_93 , L_104 , V_72 , V_37 -> V_39 ) ;
FPRINTF ( NULL , L_344 , V_37 -> V_39 ) ;
FPRINTF ( V_94 , L_21 ) ;
for( V_121 = V_120 ; V_121 ; V_121 = V_121 -> V_7 ) {
FPRINTF ( V_94 , L_345 , V_121 -> V_4 , V_121 -> V_110 ) ;
}
FPRINTF ( V_94 , L_21 ) ;
FPRINTF ( V_94 , L_346 , V_30 ) ;
FPRINTF ( V_94 , L_186 , V_61 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_347 , V_30 ) ;
for( V_121 = V_120 ; V_121 ; V_121 = V_121 -> V_7 ) {
FPRINTF ( V_76 , L_348 , V_121 -> V_110 , V_121 -> V_4 ) ;
}
FPRINTF ( V_76 , L_349 ) ;
FPRINTF ( V_76 , L_97 ) ;
FPRINTF ( V_76 , L_21 ) ;
FPRINTF ( V_76 , L_187 ) ;
FPRINTF ( V_76 , L_107 , V_61 ) ;
FPRINTF ( V_76 , L_108 ) ;
switch( V_125 ) {
case 16 :
FPRINTF ( V_76 , L_109 ) ;
break;
case 32 :
FPRINTF ( V_76 , L_115 ) ;
break;
default:
FPRINTF ( V_3 , L_350 ) ;
Exit ( 10 ) ;
}
FPRINTF ( V_76 , L_110 ) ;
FPRINTF ( V_76 , L_111 ) ;
FPRINTF ( V_76 , L_21 ) ;
F_22 ( V_126 , V_67 , L_351 , V_30 ) ;
switch( V_125 ) {
case 16 :
F_19 ( V_37 -> V_39 , V_61 , L_113 , L_81 , L_2 , V_126 , 2 ) ;
break;
case 32 :
F_19 ( V_37 -> V_39 , V_61 , L_118 , L_81 , L_2 , V_126 , 4 ) ;
break;
default:
FPRINTF ( V_3 , L_350 ) ;
Exit ( 10 ) ;
}
FPRINTF ( NULL , L_352 , V_37 -> V_39 ) ;
V_38 = V_37 -> V_7 -> V_7 ;
}
static void F_34 ( char * V_127 )
{
T_13 * V_128 ;
V_128 = F_3 ( T_13 , 1 ) ;
if ( ! V_128 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_128 -> V_7 = V_129 ;
V_129 = V_128 ;
V_128 -> V_4 = F_4 ( V_127 , strlen ( V_127 ) ) ;
}
static void
F_35 ( void )
{
T_9 * V_37 ;
T_13 * V_130 ;
T_14 V_131 ;
for( V_130 = V_129 ; V_130 ; V_130 = V_130 -> V_7 ) {
V_131 = strlen ( V_130 -> V_4 ) ;
for( V_37 = V_38 ; V_37 ; V_37 = V_37 -> V_7 ) {
if( ! strncmp ( V_37 -> V_39 , V_130 -> V_4 , V_131 ) ) {
V_37 -> V_39 += V_131 ;
}
}
}
}
static int Exit ( int V_132 )
{
FPRINTF ( V_3 , L_353 ) ;
F_20 ( 10 ) ;
exit ( V_132 ) ;
}
static void F_36 ( void )
{
FPRINTF ( V_3 , L_354 ) ;
}
static void
F_37 ( const char * V_4 , T_1 * V_133 )
{
T_1 * V_134 ;
FPRINTF ( V_133 , L_355 , V_4 ) ;
V_134 = F_38 ( V_4 , L_356 ) ;
while( ! feof ( V_134 ) ) {
int V_81 ;
V_81 = fgetc ( V_134 ) ;
if( V_81 != - 1 ) {
fputc ( V_81 , V_133 ) ;
}
}
fclose ( V_134 ) ;
FPRINTF ( V_133 , L_357 , V_4 ) ;
}
static char *
F_39 ( char * V_39 , char * * V_4 )
{
char V_97 [ V_67 ] , * V_135 ;
int V_136 ;
int V_137 ;
V_135 = V_97 ;
V_136 = 1 ;
V_137 = 0 ;
while( 1 ) {
if( ! * V_39 ) {
* V_135 = 0 ;
* V_4 = F_4 ( V_97 , strlen ( V_97 ) ) ;
return V_39 ;
}
if( V_136 ) {
if( ( * V_39 == ' ' ) || ( * V_39 == '\t' ) ) {
V_39 ++ ;
continue;
}
if( * V_39 == '"' ) {
V_39 ++ ;
V_137 = 1 ;
}
V_136 = 0 ;
continue;
}
if( ( * V_39 == ' ' ) || ( * V_39 == '\t' ) ) {
if( V_137 ) {
* V_135 ++ = * V_39 ++ ;
continue;
}
* V_135 = 0 ;
* V_4 = F_4 ( V_97 , strlen ( V_97 ) ) ;
return V_39 ;
}
if( ( * V_39 == '"' ) || ( * V_39 == '\n' ) ) {
* V_135 = 0 ;
* V_4 = F_4 ( V_97 , strlen ( V_97 ) ) ;
return ++ V_39 ;
}
* V_135 ++ = * V_39 ++ ;
}
return NULL ;
}
static void
F_40 ( T_1 * V_1 )
{
char V_138 [ 4 * V_67 ] ;
FPRINTF ( NULL , L_358 ) ;
while( ! feof ( V_1 ) ) {
V_138 [ 0 ] = 0 ;
if( ! fgets ( V_138 , 4 * V_67 , V_1 ) || ! V_138 [ 0 ] ) {
continue;
}
if( V_138 [ 0 ] == '#' ) {
} else if( ! strncmp ( V_138 , L_359 , 6 ) ) {
T_8 * V_139 ;
char * V_39 , * V_4 ;
V_39 = V_138 + 6 ;
F_39 ( V_39 , & V_4 ) ;
V_139 = F_3 ( T_8 , 1 ) ;
if ( ! V_139 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_139 -> V_7 = V_36 ;
V_36 = V_139 ;
V_139 -> V_4 = V_4 ;
FPRINTF ( NULL , L_360 , V_139 -> V_4 ) ;
} else if( ! strncmp ( V_138 , L_361 , 4 ) ) {
char * V_4 , * V_61 , * V_28 , * V_29 ;
char * V_31 , * V_30 , * V_140 ;
char * V_39 ;
int V_54 ;
V_39 = V_138 + 4 ;
V_39 = F_39 ( V_39 , & V_4 ) ;
V_39 = F_39 ( V_39 , & V_61 ) ;
V_39 = F_39 ( V_39 , & V_28 ) ;
V_39 = F_39 ( V_39 , & V_29 ) ;
V_39 = F_39 ( V_39 , & V_31 ) ;
V_39 = F_39 ( V_39 , & V_30 ) ;
F_39 ( V_39 , & V_140 ) ;
V_54 = atoi ( V_140 ) ;
FPRINTF ( NULL , L_362 , V_4 , V_61 ) ;
F_19 ( V_4 , V_61 , V_28 , V_29 , V_31 , V_30 , V_54 ) ;
} else if( ! strncmp ( V_138 , L_363 , 11 ) ) {
char * V_61 , * V_5 ;
char * V_39 ;
V_39 = V_138 + 11 ;
V_39 = F_39 ( V_39 , & V_61 ) ;
F_39 ( V_39 , & V_5 ) ;
FPRINTF ( NULL , L_364 , V_61 , V_5 ) ;
F_2 ( V_61 , V_5 ) ;
} else if( ! strncmp ( V_138 , L_365 , 8 ) ) {
char * V_99 , * V_26 , * V_27 , * V_28 ;
char * V_29 , * V_30 , * V_31 , * V_32 ;
char * V_39 ;
V_39 = V_138 + 8 ;
V_39 = F_39 ( V_39 , & V_99 ) ;
V_39 = F_39 ( V_39 , & V_26 ) ;
V_39 = F_39 ( V_39 , & V_27 ) ;
V_39 = F_39 ( V_39 , & V_28 ) ;
V_39 = F_39 ( V_39 , & V_29 ) ;
V_39 = F_39 ( V_39 , & V_30 ) ;
V_39 = F_39 ( V_39 , & V_31 ) ;
F_39 ( V_39 , & V_32 ) ;
FPRINTF ( NULL , L_366 , V_99 , V_26 ) ;
F_13 ( V_99 , V_26 , V_27 , V_28 , V_29 , V_30 , V_31 , V_32 ) ;
} else if( ! strncmp ( V_138 , L_367 , 9 ) ) {
char * V_17 , * V_18 ;
char * V_39 ;
V_39 = V_138 + 9 ;
V_39 = F_39 ( V_39 , & V_17 ) ;
F_39 ( V_39 , & V_18 ) ;
FPRINTF ( NULL , L_368 , V_17 , V_18 ) ;
F_10 ( V_17 , V_18 ) ;
} else if( ! strncmp ( V_138 , L_369 , 14 ) ) {
char * V_114 , * V_141 ;
int V_53 ;
T_5 * V_14 ;
char * V_39 ;
V_39 = V_138 + 14 ;
V_39 = F_39 ( V_39 , & V_114 ) ;
F_39 ( V_39 , & V_141 ) ;
V_53 = atoi ( V_141 ) ;
FPRINTF ( NULL , L_370 , V_114 , V_53 ) ;
V_14 = F_3 ( T_5 , 1 ) ;
if ( ! V_14 ) {
FPRINTF ( V_3 , L_1 ) ;
exit ( 10 ) ;
}
V_14 -> V_7 = V_15 ;
V_15 = V_14 ;
V_14 -> V_4 = F_4 ( V_114 , strlen ( V_114 ) ) ;
V_14 -> V_16 = V_53 ;
} else if( ! strncmp ( V_138 , L_371 , 12 ) ) {
char * V_127 ;
char * V_39 ;
V_39 = V_138 + 12 ;
F_39 ( V_39 , & V_127 ) ;
FPRINTF ( NULL , L_372 , V_127 ) ;
F_34 ( V_127 ) ;
} else {
FPRINTF ( V_3 , L_373 , V_138 ) ;
exit ( 10 ) ;
}
}
}
int main ( int V_142 , char * V_143 [] )
{
char V_144 [ V_67 ] ;
char V_145 [ V_67 ] ;
char V_146 [ V_67 ] ;
T_10 * V_100 ;
T_1 * V_1 ;
if( V_142 != 2 ) {
F_36 () ;
exit ( 0 ) ;
}
V_76 = F_38 ( L_374 , L_375 ) ;
V_94 = F_38 ( L_376 , L_375 ) ;
V_34 = F_38 ( L_377 , L_375 ) ;
V_33 = F_38 ( L_378 , L_375 ) ;
V_75 = F_38 ( L_379 , L_375 ) ;
V_74 = F_38 ( L_380 , L_375 ) ;
V_119 = F_38 ( L_381 , L_375 ) ;
V_77 = F_38 ( L_382 , L_375 ) ;
F_22 ( V_144 , V_67 , L_383 , V_143 [ 1 ] ) ;
V_1 = F_38 ( V_144 , L_356 ) ;
if( V_1 ) {
F_40 ( V_1 ) ;
fclose ( V_1 ) ;
}
F_22 ( V_144 , V_67 , L_384 , V_143 [ 1 ] ) ;
V_1 = F_38 ( V_144 , L_356 ) ;
if( ! V_1 ) {
FPRINTF ( V_3 , L_385 , V_144 ) ;
Exit ( 0 ) ;
}
V_91 = 0 ;
V_89 = 0 ;
F_24 ( V_1 ) ;
F_16 ( L_54 ) ;
F_16 ( L_55 ) ;
F_15 ( L_386 , L_164 ) ;
F_15 ( L_387 , L_126 ) ;
F_15 ( L_388 , L_130 ) ;
F_15 ( L_389 , L_156 ) ;
FPRINTF ( NULL , L_390 ) ;
F_21 () ;
F_22 ( V_146 , V_67 , L_391 , V_72 ) ;
F_34 ( V_146 ) ;
F_35 () ;
while( 1 ) {
if( ! F_6 ( V_38 -> V_39 , L_25 ) ) {
V_38 = F_17 ( V_38 , & V_100 ) ;
continue;
}
if( ! F_6 ( V_38 -> V_39 , L_175 )
&& ! F_6 ( V_38 -> V_7 -> V_39 , L_337 ) ) {
F_33 () ;
continue;
}
if( ! F_6 ( V_38 -> V_39 , L_175 )
&& ! F_6 ( V_38 -> V_7 -> V_39 , L_25 )
&& ! F_6 ( V_38 -> V_7 -> V_7 -> V_39 , L_334 )
&& ! F_6 ( V_38 -> V_7 -> V_7 -> V_7 -> V_39 , L_31 )
&& ! F_6 ( V_38 -> V_7 -> V_7 -> V_7 -> V_7 -> V_39 , L_337 ) ) {
F_33 () ;
continue;
}
if( ! F_6 ( V_38 -> V_39 , L_167 ) ) {
F_26 () ;
continue;
}
if( ! F_6 ( V_38 -> V_39 , L_175 ) ) {
T_9 * V_40 ;
V_40 = V_38 -> V_7 ;
if( ! F_6 ( V_40 -> V_39 , L_25 ) ) {
V_40 = F_17 ( V_40 , & V_100 ) ;
}
if( ! F_6 ( V_40 -> V_39 , L_178 ) ) {
F_27 ( 0 ) ;
F_27 ( 1 ) ;
continue;
}
}
if( ! F_6 ( V_38 -> V_39 , L_175 ) ) {
T_9 * V_40 ;
V_40 = V_38 -> V_7 ;
if( ! F_6 ( V_40 -> V_39 , L_25 ) ) {
V_40 = F_17 ( V_40 , & V_100 ) ;
}
if( ! F_6 ( V_40 -> V_39 , L_273 ) ) {
F_30 ( 0 ) ;
F_30 ( 1 ) ;
continue;
}
}
if( ! F_6 ( V_38 -> V_39 , L_175 ) ) {
T_9 * V_40 ;
V_40 = V_38 -> V_7 ;
if( ! F_6 ( V_40 -> V_39 , L_25 ) ) {
V_40 = F_17 ( V_40 , & V_100 ) ;
}
if( ! F_6 ( V_40 -> V_39 , L_237 ) ) {
F_28 ( 0 ) ;
F_28 ( 1 ) ;
continue;
}
}
if( ! F_6 ( V_38 -> V_39 , L_164 )
&& ! F_6 ( V_38 -> V_7 -> V_7 -> V_39 , L_23 ) ) {
F_32 ( 0 ) ;
F_32 ( 1 ) ;
F_32 ( 2 ) ;
continue;
}
if( ! F_6 ( V_38 -> V_39 , L_165 ) ) {
F_25 () ;
continue;
}
break;
} ;
fclose ( V_76 ) ;
fclose ( V_94 ) ;
fclose ( V_33 ) ;
fclose ( V_34 ) ;
fclose ( V_74 ) ;
fclose ( V_75 ) ;
fclose ( V_119 ) ;
fclose ( V_77 ) ;
if( F_6 ( V_38 -> V_39 , L_28 ) || V_38 -> V_7 ) {
FPRINTF ( V_3 , L_392 ) ;
F_20 ( 10 ) ;
exit ( 10 ) ;
}
F_11 () ;
F_22 ( line , 4 * V_67 , L_393 , V_72 ) ;
V_1 = F_38 ( line , L_375 ) ;
F_22 ( V_145 , V_67 , L_394 , V_143 [ 1 ] ) ;
V_147 = F_38 ( V_145 , L_356 ) ;
if( ! V_147 ) {
FPRINTF ( V_3 , L_395 , V_145 ) ;
exit ( 10 ) ;
}
while( ! feof ( V_147 ) ) {
line [ 0 ] = 0 ;
if( ! fgets ( line , 4 * V_67 , V_147 ) || ! line [ 0 ] ) {
continue;
}
if( ! strncmp ( line , L_374 , 8 ) ) {
F_37 ( L_374 , V_1 ) ;
} else if( ! strncmp ( line , L_376 , 7 ) ) {
F_37 ( L_376 , V_1 ) ;
} else if( ! strncmp ( line , L_377 , 9 ) ) {
F_37 ( L_377 , V_1 ) ;
} else if( ! strncmp ( line , L_378 , 6 ) ) {
F_37 ( L_378 , V_1 ) ;
} else if( ! strncmp ( line , L_379 , 10 ) ) {
F_37 ( L_379 , V_1 ) ;
} else if( ! strncmp ( line , L_380 , 7 ) ) {
F_37 ( L_380 , V_1 ) ;
} else if( ! strncmp ( line , L_381 , 6 ) ) {
F_37 ( L_381 , V_1 ) ;
} else if( ! strncmp ( line , L_382 , 11 ) ) {
F_37 ( L_382 , V_1 ) ;
} else {
fputs ( line , V_1 ) ;
}
}
fclose ( V_1 ) ;
fclose ( V_147 ) ;
F_22 ( line , 4 * V_67 , L_396 , V_72 ) ;
V_1 = F_38 ( line , L_375 ) ;
F_22 ( V_145 , V_67 , L_397 , V_143 [ 1 ] ) ;
V_147 = F_38 ( V_145 , L_356 ) ;
if( ! V_147 ) {
FPRINTF ( V_3 , L_395 , V_145 ) ;
exit ( 10 ) ;
}
while( ! feof ( V_147 ) ) {
line [ 0 ] = 0 ;
if( ! fgets ( line , 4 * V_67 , V_147 ) || ! line [ 0 ] ) {
continue;
}
if( ! strncmp ( line , L_374 , 8 ) ) {
F_37 ( L_374 , V_1 ) ;
} else if( ! strncmp ( line , L_376 , 7 ) ) {
F_37 ( L_376 , V_1 ) ;
} else if( ! strncmp ( line , L_377 , 9 ) ) {
F_37 ( L_377 , V_1 ) ;
} else if( ! strncmp ( line , L_378 , 6 ) ) {
F_37 ( L_378 , V_1 ) ;
} else if( ! strncmp ( line , L_379 , 10 ) ) {
F_37 ( L_379 , V_1 ) ;
} else if( ! strncmp ( line , L_380 , 7 ) ) {
F_37 ( L_380 , V_1 ) ;
} else if( ! strncmp ( line , L_381 , 6 ) ) {
F_37 ( L_381 , V_1 ) ;
} else if( ! strncmp ( line , L_382 , 11 ) ) {
F_37 ( L_382 , V_1 ) ;
} else {
fputs ( line , V_1 ) ;
}
}
F_41 ( L_398 , V_72 ) ;
fclose ( V_1 ) ;
fclose ( V_147 ) ;
if ( F_42 ( L_374 ) == - 1 ) {
FPRINTF ( V_3 , L_399 ) ;
}
if ( F_42 ( L_376 ) == - 1 ) {
FPRINTF ( V_3 , L_399 ) ;
}
if ( F_42 ( L_377 ) == - 1 ) {
FPRINTF ( V_3 , L_399 ) ;
}
if ( F_42 ( L_378 ) == - 1 ) {
FPRINTF ( V_3 , L_399 ) ;
}
if ( F_42 ( L_379 ) == - 1 ) {
FPRINTF ( V_3 , L_399 ) ;
}
if ( F_42 ( L_380 ) == - 1 ) {
FPRINTF ( V_3 , L_399 ) ;
}
if ( F_42 ( L_381 ) == - 1 ) {
FPRINTF ( V_3 , L_399 ) ;
}
if ( F_42 ( L_382 ) == - 1 ) {
FPRINTF ( V_3 , L_399 ) ;
}
return 0 ;
}
