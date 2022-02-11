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
T_2 F_15 ( char * V_30 )
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
unsigned V_34 , V_35 ;
if ( sscanf ( V_30 , L_7 , & V_34 , & V_35 ) == 2 ) {
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
V_17 = V_36 ;
if ( strcmp ( V_30 , L_8 ) == 0 )
goto V_24;
V_17 = V_37 ;
if ( strcmp ( V_30 , L_9 ) == 0 )
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
F_24 ( V_38 , line , sizeof( V_38 ) ) ;
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
V_39 = V_1 ;
return 1 ;
}
static int T_1 F_27 ( char * V_1 )
{
V_40 = V_1 ;
return 1 ;
}
static int T_1 F_28 ( char * V_1 )
{
V_41 = F_21 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static void T_1 F_29 ( char * V_42 )
{
char * V_31 = V_42 ;
if ( V_40 ) {
strcpy ( V_42 , V_40 ) ;
while ( * V_31 ++ ) {
if ( V_31 [ - 1 ] == ',' )
V_31 [ - 1 ] = '\0' ;
}
} else {
int V_15 = F_30 ( V_42 ) ;
char * V_32 , * V_43 ;
V_42 [ V_15 ] = '\0' ;
for ( V_32 = V_42 - 1 ; V_32 ; V_32 = V_43 ) {
V_43 = strchr ( ++ V_32 , '\n' ) ;
if ( * V_32 ++ != '\t' )
continue;
while ( ( * V_31 ++ = * V_32 ++ ) != '\n' )
;
V_31 [ - 1 ] = '\0' ;
}
}
* V_31 = '\0' ;
}
static int T_1 F_31 ( char * V_30 , char * V_44 , int V_45 , void * V_7 )
{
struct V_46 * V_31 ;
int V_47 = F_32 ( V_30 , L_10 , V_44 , V_45 , V_7 ) ;
if ( V_47 )
return V_47 ;
F_33 ( L_10 ) ;
V_31 = V_48 -> V_44 -> V_49 . V_50 -> V_51 ;
V_52 = V_31 -> V_53 ;
F_34 ( V_54
L_11 ,
V_31 -> V_55 -> V_30 ,
V_31 -> V_56 & V_4 ? L_12 : L_13 ,
F_18 ( V_52 ) , F_19 ( V_52 ) ) ;
return 0 ;
}
void T_1 F_35 ( char * V_30 , int V_45 )
{
struct V_42 * V_42 = F_36 ( V_57 |
V_58 ) ;
char * V_59 = F_37 ( V_42 ) ;
char * V_32 ;
#ifdef F_16
char V_60 [ V_61 ] ;
#else
const char * V_60 = V_30 ;
#endif
F_29 ( V_59 ) ;
V_62:
for ( V_32 = V_59 ; * V_32 ; V_32 += strlen ( V_32 ) + 1 ) {
int V_47 = F_31 ( V_30 , V_32 , V_45 , V_39 ) ;
switch ( V_47 ) {
case 0 :
goto V_63;
case - V_64 :
V_45 |= V_4 ;
goto V_62;
case - V_65 :
continue;
}
#ifdef F_16
F_38 ( V_52 , V_60 ) ;
#endif
F_34 ( L_14 ,
V_66 , V_60 , V_47 ) ;
F_34 ( L_15 ) ;
F_39 () ;
#ifdef F_40
F_34 ( L_16
L_17 ) ;
#endif
F_41 ( L_18 , V_60 ) ;
}
F_34 ( L_19 ) ;
F_39 () ;
F_34 ( L_20 ) ;
for ( V_32 = V_59 ; * V_32 ; V_32 += strlen ( V_32 ) + 1 )
F_34 ( L_21 , V_32 ) ;
F_34 ( L_22 ) ;
#ifdef F_16
F_38 ( V_52 , V_60 ) ;
#endif
F_41 ( L_18 , V_60 ) ;
V_63:
F_42 ( V_42 ) ;
}
static int T_1 F_43 ( void )
{
char * V_67 , * V_68 ;
unsigned int V_69 ;
int V_70 , V_47 ;
V_47 = F_44 ( & V_67 , & V_68 ) ;
if ( V_47 != 0 )
return 0 ;
V_69 = V_71 ;
for ( V_70 = 1 ; ; V_70 ++ ) {
V_47 = F_31 ( V_67 , L_8 ,
V_3 , V_68 ) ;
if ( V_47 == 0 )
return 1 ;
if ( V_70 > V_72 )
break;
F_45 ( V_69 ) ;
V_69 <<= 1 ;
if ( V_69 > V_73 )
V_69 = V_73 ;
}
return 0 ;
}
void T_1 F_46 ( char * V_74 , ... )
{
struct V_75 V_75 ;
char V_76 [ 80 ] ;
char V_23 ;
int V_77 ;
T_3 args ;
va_start ( args , V_74 ) ;
vsprintf ( V_76 , V_74 , args ) ;
va_end ( args ) ;
V_77 = F_47 ( L_23 , V_78 | V_79 , 0 ) ;
if ( V_77 >= 0 ) {
F_48 ( V_77 , V_80 , 0 ) ;
F_49 ( V_77 ) ;
}
F_34 ( V_81 L_24 , V_76 ) ;
V_77 = F_47 ( L_25 , V_78 , 0 ) ;
if ( V_77 >= 0 ) {
F_48 ( V_77 , V_82 , ( long ) & V_75 ) ;
V_75 . V_83 &= ~ V_84 ;
F_48 ( V_77 , V_85 , ( long ) & V_75 ) ;
F_50 ( V_77 , & V_23 , 1 ) ;
V_75 . V_83 |= V_84 ;
F_48 ( V_77 , V_85 , ( long ) & V_75 ) ;
F_49 ( V_77 ) ;
}
}
void T_1 F_51 ( void )
{
#ifdef F_52
if ( V_52 == V_36 ) {
if ( F_43 () )
return;
F_34 ( V_86 L_26 ) ;
V_52 = V_87 ;
}
#endif
#ifdef F_53
if ( F_18 ( V_52 ) == V_88 ) {
if ( V_2 == 2 ) {
if ( F_54 ( 1 ) ) {
V_52 = V_89 ;
V_66 = NULL ;
}
} else
F_46 ( L_27 ) ;
}
#endif
#ifdef F_16
F_55 ( L_23 , V_52 ) ;
F_35 ( L_23 , V_3 ) ;
#endif
}
void T_1 F_56 ( void )
{
int V_90 ;
if ( V_41 ) {
F_34 ( V_54 L_28 ,
V_41 ) ;
F_45 ( V_41 ) ;
}
F_57 () ;
F_58 () ;
if ( V_38 [ 0 ] ) {
V_66 = V_38 ;
if ( ! strncmp ( V_66 , L_29 , 3 ) ||
! strncmp ( V_66 , L_30 , 3 ) ) {
F_35 ( V_66 , V_3 ) ;
goto V_63;
}
V_52 = F_15 ( V_66 ) ;
if ( strncmp ( V_66 , L_6 , 5 ) == 0 )
V_66 += 5 ;
}
if ( F_59 () )
goto V_63;
if ( ( V_52 == 0 ) && V_29 ) {
F_34 ( V_54 L_31 ,
V_38 ) ;
while ( F_60 () != 0 ||
( V_52 = F_15 ( V_38 ) ) == 0 )
F_61 ( 100 ) ;
F_62 () ;
}
V_90 = F_18 ( V_52 ) == V_88 ;
if ( V_90 && V_2 && F_54 ( 0 ) )
V_52 = V_37 ;
F_51 () ;
V_63:
F_63 ( L_32 ) ;
F_32 ( L_33 , L_34 , NULL , V_91 , NULL ) ;
F_64 ( L_33 ) ;
}
static struct V_50 * F_65 ( struct V_92 * V_93 ,
int V_45 , const char * V_94 , void * V_7 )
{
static unsigned long V_95 ;
void * V_96 = V_97 ;
if ( F_66 ( 0 , & V_95 ) )
return F_67 ( - V_98 ) ;
if ( F_68 ( V_99 ) && V_100 )
V_96 = V_101 ;
return F_69 ( V_93 , V_45 , V_7 , V_96 ) ;
}
int T_1 F_70 ( void )
{
int V_47 = F_71 ( & V_102 ) ;
if ( V_47 )
return V_47 ;
if ( F_68 ( V_99 ) && ! V_38 [ 0 ] &&
( ! V_40 || strstr ( V_40 , L_35 ) ) ) {
V_47 = F_72 () ;
V_100 = true ;
} else {
V_47 = F_73 () ;
}
if ( V_47 )
F_74 ( & V_102 ) ;
return V_47 ;
}
