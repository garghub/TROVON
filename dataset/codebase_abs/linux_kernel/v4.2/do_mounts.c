static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) & 3 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
if ( * V_1 )
return 0 ;
V_3 |= V_4 ;
return 1 ;
}
static int T_1 F_4 ( char * V_1 )
{
if ( * V_1 )
return 0 ;
V_3 &= ~ V_4 ;
return 1 ;
}
static int F_5 ( struct V_5 * V_6 , const void * V_7 )
{
const struct V_8 * V_9 = V_7 ;
struct V_10 * V_11 = F_6 ( V_6 ) ;
if ( ! V_11 -> V_12 )
goto V_13;
if ( strncasecmp ( V_9 -> V_14 , V_11 -> V_12 -> V_14 , V_9 -> V_15 ) )
goto V_13;
return 1 ;
V_13:
return 0 ;
}
static T_2 F_7 ( const char * V_16 )
{
T_2 V_17 = 0 ;
struct V_8 V_9 ;
struct V_5 * V_6 = NULL ;
struct V_18 * V_19 ;
struct V_10 * V_11 ;
int V_20 = 0 ;
bool V_21 = false ;
char * V_22 ;
V_9 . V_14 = V_16 ;
V_22 = strchr ( V_16 , '/' ) ;
if ( V_22 ) {
char V_23 = 0 ;
if ( sscanf ( V_22 + 1 ,
L_1 , & V_20 , & V_23 ) != 1 ) {
V_21 = true ;
goto V_24;
}
V_9 . V_15 = V_22 - V_16 ;
} else {
V_9 . V_15 = strlen ( V_16 ) ;
}
if ( ! V_9 . V_15 ) {
V_21 = true ;
goto V_24;
}
V_6 = F_8 ( & V_25 , NULL , & V_9 ,
& F_5 ) ;
if ( ! V_6 )
goto V_24;
V_17 = V_6 -> V_26 ;
if ( ! V_20 )
goto V_27;
V_17 = 0 ;
V_19 = F_9 ( F_6 ( V_6 ) ) ;
V_11 = F_10 ( V_19 , F_6 ( V_6 ) -> V_28 + V_20 ) ;
if ( V_11 ) {
V_17 = F_11 ( V_11 ) ;
F_12 ( F_13 ( V_11 ) ) ;
}
V_27:
F_12 ( V_6 ) ;
V_24:
if ( V_21 ) {
F_14 ( L_2
L_3 ) ;
if ( V_29 )
F_14 ( L_4 ) ;
V_29 = 0 ;
}
return V_17 ;
}
T_2 F_15 ( const char * V_30 )
{
char V_31 [ 32 ] ;
char * V_32 ;
T_2 V_17 = 0 ;
int V_11 ;
#ifdef F_16
if ( strncmp ( V_30 , L_5 , 9 ) == 0 ) {
V_30 += 9 ;
V_17 = F_7 ( V_30 ) ;
if ( ! V_17 )
goto V_33;
goto V_24;
}
#endif
if ( strncmp ( V_30 , L_6 , 5 ) != 0 ) {
unsigned V_34 , V_35 , V_20 ;
char V_36 ;
if ( ( sscanf ( V_30 , L_7 , & V_34 , & V_35 , & V_36 ) == 2 ) ||
( sscanf ( V_30 , L_8 , & V_34 , & V_35 , & V_20 , & V_36 ) == 3 ) ) {
V_17 = F_17 ( V_34 , V_35 ) ;
if ( V_34 != F_18 ( V_17 ) || V_35 != F_19 ( V_17 ) )
goto V_33;
} else {
V_17 = F_20 ( F_21 ( V_30 , & V_32 , 16 ) ) ;
if ( * V_32 )
goto V_33;
}
goto V_24;
}
V_30 += 5 ;
V_17 = V_37 ;
if ( strcmp ( V_30 , L_9 ) == 0 )
goto V_24;
V_17 = V_38 ;
if ( strcmp ( V_30 , L_10 ) == 0 )
goto V_24;
if ( strlen ( V_30 ) > 31 )
goto V_33;
strcpy ( V_31 , V_30 ) ;
for ( V_32 = V_31 ; * V_32 ; V_32 ++ )
if ( * V_32 == '/' )
* V_32 = '!' ;
V_17 = F_22 ( V_31 , 0 ) ;
if ( V_17 )
goto V_24;
while ( V_32 > V_31 && isdigit ( V_32 [ - 1 ] ) )
V_32 -- ;
if ( V_32 == V_31 || ! * V_32 || * V_32 == '0' )
goto V_33;
V_11 = F_21 ( V_32 , NULL , 10 ) ;
* V_32 = '\0' ;
V_17 = F_22 ( V_31 , V_11 ) ;
if ( V_17 )
goto V_24;
if ( V_32 < V_31 + 2 || ! isdigit ( V_32 [ - 2 ] ) || V_32 [ - 1 ] != 'p' )
goto V_33;
V_32 [ - 1 ] = '\0' ;
V_17 = F_22 ( V_31 , V_11 ) ;
if ( V_17 )
goto V_24;
V_33:
return 0 ;
V_24:
return V_17 ;
}
static int T_1 F_23 ( char * line )
{
F_24 ( V_39 , line , sizeof( V_39 ) ) ;
return 1 ;
}
static int T_1 F_25 ( char * V_1 )
{
if ( * V_1 )
return 0 ;
V_29 = 1 ;
return 1 ;
}
static int T_1 F_26 ( char * V_1 )
{
V_40 = V_1 ;
return 1 ;
}
static int T_1 F_27 ( char * V_1 )
{
V_41 = V_1 ;
return 1 ;
}
static int T_1 F_28 ( char * V_1 )
{
V_42 = F_21 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static void T_1 F_29 ( char * V_43 )
{
char * V_31 = V_43 ;
if ( V_41 ) {
strcpy ( V_43 , V_41 ) ;
while ( * V_31 ++ ) {
if ( V_31 [ - 1 ] == ',' )
V_31 [ - 1 ] = '\0' ;
}
} else {
int V_15 = F_30 ( V_43 ) ;
char * V_32 , * V_44 ;
V_43 [ V_15 ] = '\0' ;
for ( V_32 = V_43 - 1 ; V_32 ; V_32 = V_44 ) {
V_44 = strchr ( ++ V_32 , '\n' ) ;
if ( * V_32 ++ != '\t' )
continue;
while ( ( * V_31 ++ = * V_32 ++ ) != '\n' )
;
V_31 [ - 1 ] = '\0' ;
}
}
* V_31 = '\0' ;
}
static int T_1 F_31 ( char * V_30 , char * V_45 , int V_46 , void * V_7 )
{
struct V_47 * V_31 ;
int V_48 = F_32 ( V_30 , L_11 , V_45 , V_46 , V_7 ) ;
if ( V_48 )
return V_48 ;
F_33 ( L_11 ) ;
V_31 = V_49 -> V_45 -> V_50 . V_51 -> V_52 ;
V_53 = V_31 -> V_54 ;
F_34 ( V_55
L_12 ,
V_31 -> V_56 -> V_30 ,
V_31 -> V_57 & V_4 ? L_13 : L_14 ,
F_18 ( V_53 ) , F_19 ( V_53 ) ) ;
return 0 ;
}
void T_1 F_35 ( char * V_30 , int V_46 )
{
struct V_43 * V_43 = F_36 ( V_58 |
V_59 ) ;
char * V_60 = F_37 ( V_43 ) ;
char * V_32 ;
#ifdef F_16
char V_61 [ V_62 ] ;
#else
const char * V_61 = V_30 ;
#endif
F_29 ( V_60 ) ;
V_63:
for ( V_32 = V_60 ; * V_32 ; V_32 += strlen ( V_32 ) + 1 ) {
int V_48 = F_31 ( V_30 , V_32 , V_46 , V_40 ) ;
switch ( V_48 ) {
case 0 :
goto V_64;
case - V_65 :
case - V_66 :
continue;
}
#ifdef F_16
F_38 ( V_53 , V_61 ) ;
#endif
F_34 ( L_15 ,
V_67 , V_61 , V_48 ) ;
F_34 ( L_16 ) ;
F_39 () ;
#ifdef F_40
F_34 ( L_17
L_18 ) ;
#endif
F_41 ( L_19 , V_61 ) ;
}
if ( ! ( V_46 & V_4 ) ) {
V_46 |= V_4 ;
goto V_63;
}
F_34 ( L_20 ) ;
F_39 () ;
F_34 ( L_21 ) ;
for ( V_32 = V_60 ; * V_32 ; V_32 += strlen ( V_32 ) + 1 )
F_34 ( L_22 , V_32 ) ;
F_34 ( L_23 ) ;
#ifdef F_16
F_38 ( V_53 , V_61 ) ;
#endif
F_41 ( L_19 , V_61 ) ;
V_64:
F_42 ( V_43 ) ;
}
static int T_1 F_43 ( void )
{
char * V_68 , * V_69 ;
unsigned int V_70 ;
int V_71 , V_48 ;
V_48 = F_44 ( & V_68 , & V_69 ) ;
if ( V_48 != 0 )
return 0 ;
V_70 = V_72 ;
for ( V_71 = 1 ; ; V_71 ++ ) {
V_48 = F_31 ( V_68 , L_9 ,
V_3 , V_69 ) ;
if ( V_48 == 0 )
return 1 ;
if ( V_71 > V_73 )
break;
F_45 ( V_70 ) ;
V_70 <<= 1 ;
if ( V_70 > V_74 )
V_70 = V_74 ;
}
return 0 ;
}
void T_1 F_46 ( char * V_75 , ... )
{
struct V_76 V_76 ;
char V_77 [ 80 ] ;
char V_23 ;
int V_78 ;
T_3 args ;
va_start ( args , V_75 ) ;
vsprintf ( V_77 , V_75 , args ) ;
va_end ( args ) ;
V_78 = F_47 ( L_24 , V_79 | V_80 , 0 ) ;
if ( V_78 >= 0 ) {
F_48 ( V_78 , V_81 , 0 ) ;
F_49 ( V_78 ) ;
}
F_34 ( V_82 L_25 , V_77 ) ;
V_78 = F_47 ( L_26 , V_79 , 0 ) ;
if ( V_78 >= 0 ) {
F_48 ( V_78 , V_83 , ( long ) & V_76 ) ;
V_76 . V_84 &= ~ V_85 ;
F_48 ( V_78 , V_86 , ( long ) & V_76 ) ;
F_50 ( V_78 , & V_23 , 1 ) ;
V_76 . V_84 |= V_85 ;
F_48 ( V_78 , V_86 , ( long ) & V_76 ) ;
F_49 ( V_78 ) ;
}
}
void T_1 F_51 ( void )
{
#ifdef F_52
if ( V_53 == V_37 ) {
if ( F_43 () )
return;
F_34 ( V_87 L_27 ) ;
V_53 = V_88 ;
}
#endif
#ifdef F_53
if ( F_18 ( V_53 ) == V_89 ) {
if ( V_2 == 2 ) {
if ( F_54 ( 1 ) ) {
V_53 = V_90 ;
V_67 = NULL ;
}
} else
F_46 ( L_28 ) ;
}
#endif
#ifdef F_16
{
int V_48 = F_55 ( L_24 , V_53 ) ;
if ( V_48 < 0 )
F_56 ( L_29 , V_48 ) ;
F_35 ( L_24 , V_3 ) ;
}
#endif
}
void T_1 F_57 ( void )
{
int V_91 ;
if ( V_42 ) {
F_34 ( V_55 L_30 ,
V_42 ) ;
F_45 ( V_42 ) ;
}
F_58 () ;
F_59 () ;
if ( V_39 [ 0 ] ) {
V_67 = V_39 ;
if ( ! strncmp ( V_67 , L_31 , 3 ) ||
! strncmp ( V_67 , L_32 , 3 ) ) {
F_35 ( V_67 , V_3 ) ;
goto V_64;
}
V_53 = F_15 ( V_67 ) ;
if ( strncmp ( V_67 , L_6 , 5 ) == 0 )
V_67 += 5 ;
}
if ( F_60 () )
goto V_64;
if ( ( V_53 == 0 ) && V_29 ) {
F_34 ( V_55 L_33 ,
V_39 ) ;
while ( F_61 () != 0 ||
( V_53 = F_15 ( V_39 ) ) == 0 )
F_62 ( 100 ) ;
F_63 () ;
}
V_91 = F_18 ( V_53 ) == V_89 ;
if ( V_91 && V_2 && F_54 ( 0 ) )
V_53 = V_38 ;
F_51 () ;
V_64:
F_64 ( L_34 ) ;
F_32 ( L_35 , L_36 , NULL , V_92 , NULL ) ;
F_65 ( L_35 ) ;
}
static struct V_51 * F_66 ( struct V_93 * V_94 ,
int V_46 , const char * V_95 , void * V_7 )
{
static unsigned long V_96 ;
void * V_97 = V_98 ;
if ( F_67 ( 0 , & V_96 ) )
return F_68 ( - V_99 ) ;
if ( F_69 ( V_100 ) && V_101 )
V_97 = V_102 ;
return F_70 ( V_94 , V_46 , V_7 , V_97 ) ;
}
int T_1 F_71 ( void )
{
int V_48 = F_72 ( & V_103 ) ;
if ( V_48 )
return V_48 ;
if ( F_69 ( V_100 ) && ! V_39 [ 0 ] &&
( ! V_41 || strstr ( V_41 , L_37 ) ) ) {
V_48 = F_73 () ;
V_101 = true ;
} else {
V_48 = F_74 () ;
}
if ( V_48 )
F_75 ( & V_103 ) ;
return V_48 ;
}
