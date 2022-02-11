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
static int F_5 ( struct V_5 * V_6 , void * V_7 )
{
T_2 * V_8 = V_7 ;
struct V_9 * V_10 = F_6 ( V_6 ) ;
if ( ! V_10 -> V_11 )
goto V_12;
if ( memcmp ( V_8 , V_10 -> V_11 -> V_8 , sizeof( V_10 -> V_11 -> V_8 ) ) )
goto V_12;
return 1 ;
V_12:
return 0 ;
}
static T_3 F_7 ( char * V_13 )
{
T_3 V_14 = 0 ;
struct V_5 * V_6 = NULL ;
T_2 V_8 [ 16 ] ;
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_17 = 0 ;
if ( strlen ( V_13 ) < 36 )
goto V_18;
if ( V_13 [ 36 ] ) {
char V_19 = 0 ;
if ( sscanf ( & V_13 [ 36 ] ,
L_1 , & V_17 , & V_19 ) != 1 ) {
F_8 ( V_20 L_2
L_3 ) ;
if ( V_21 )
F_8 ( V_20
L_4 ) ;
V_21 = 0 ;
goto V_18;
}
}
F_9 ( V_13 , V_8 ) ;
V_6 = F_10 ( & V_22 , NULL , V_8 , & F_5 ) ;
if ( ! V_6 )
goto V_18;
V_14 = V_6 -> V_23 ;
if ( ! V_17 )
goto V_24;
V_14 = 0 ;
V_16 = F_11 ( F_6 ( V_6 ) ) ;
V_10 = F_12 ( V_16 , F_6 ( V_6 ) -> V_25 + V_17 ) ;
if ( V_10 ) {
V_14 = F_13 ( V_10 ) ;
F_14 ( F_15 ( V_10 ) ) ;
}
V_24:
F_14 ( V_6 ) ;
V_18:
return V_14 ;
}
T_3 F_16 ( char * V_26 )
{
char V_27 [ 32 ] ;
char * V_28 ;
T_3 V_14 = 0 ;
int V_10 ;
#ifdef F_17
if ( strncmp ( V_26 , L_5 , 9 ) == 0 ) {
V_26 += 9 ;
V_14 = F_7 ( V_26 ) ;
if ( ! V_14 )
goto V_29;
goto V_18;
}
#endif
if ( strncmp ( V_26 , L_6 , 5 ) != 0 ) {
unsigned V_30 , V_31 ;
if ( sscanf ( V_26 , L_7 , & V_30 , & V_31 ) == 2 ) {
V_14 = F_18 ( V_30 , V_31 ) ;
if ( V_30 != F_19 ( V_14 ) || V_31 != F_20 ( V_14 ) )
goto V_29;
} else {
V_14 = F_21 ( F_22 ( V_26 , & V_28 , 16 ) ) ;
if ( * V_28 )
goto V_29;
}
goto V_18;
}
V_26 += 5 ;
V_14 = V_32 ;
if ( strcmp ( V_26 , L_8 ) == 0 )
goto V_18;
V_14 = V_33 ;
if ( strcmp ( V_26 , L_9 ) == 0 )
goto V_18;
if ( strlen ( V_26 ) > 31 )
goto V_29;
strcpy ( V_27 , V_26 ) ;
for ( V_28 = V_27 ; * V_28 ; V_28 ++ )
if ( * V_28 == '/' )
* V_28 = '!' ;
V_14 = F_23 ( V_27 , 0 ) ;
if ( V_14 )
goto V_18;
while ( V_28 > V_27 && isdigit ( V_28 [ - 1 ] ) )
V_28 -- ;
if ( V_28 == V_27 || ! * V_28 || * V_28 == '0' )
goto V_29;
V_10 = F_22 ( V_28 , NULL , 10 ) ;
* V_28 = '\0' ;
V_14 = F_23 ( V_27 , V_10 ) ;
if ( V_14 )
goto V_18;
if ( V_28 < V_27 + 2 || ! isdigit ( V_28 [ - 2 ] ) || V_28 [ - 1 ] != 'p' )
goto V_29;
V_28 [ - 1 ] = '\0' ;
V_14 = F_23 ( V_27 , V_10 ) ;
if ( V_14 )
goto V_18;
V_29:
return 0 ;
V_18:
return V_14 ;
}
static int T_1 F_24 ( char * line )
{
F_25 ( V_34 , line , sizeof( V_34 ) ) ;
return 1 ;
}
static int T_1 F_26 ( char * V_1 )
{
if ( * V_1 )
return 0 ;
V_21 = 1 ;
return 1 ;
}
static int T_1 F_27 ( char * V_1 )
{
V_35 = V_1 ;
return 1 ;
}
static int T_1 F_28 ( char * V_1 )
{
V_36 = V_1 ;
return 1 ;
}
static int T_1 F_29 ( char * V_1 )
{
V_37 = F_22 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static void T_1 F_30 ( char * V_38 )
{
char * V_27 = V_38 ;
if ( V_36 ) {
strcpy ( V_38 , V_36 ) ;
while ( * V_27 ++ ) {
if ( V_27 [ - 1 ] == ',' )
V_27 [ - 1 ] = '\0' ;
}
} else {
int V_39 = F_31 ( V_38 ) ;
char * V_28 , * V_40 ;
V_38 [ V_39 ] = '\0' ;
for ( V_28 = V_38 - 1 ; V_28 ; V_28 = V_40 ) {
V_40 = strchr ( ++ V_28 , '\n' ) ;
if ( * V_28 ++ != '\t' )
continue;
while ( ( * V_27 ++ = * V_28 ++ ) != '\n' )
;
V_27 [ - 1 ] = '\0' ;
}
}
* V_27 = '\0' ;
}
static int T_1 F_32 ( char * V_26 , char * V_41 , int V_42 , void * V_7 )
{
struct V_43 * V_27 ;
int V_44 = F_33 ( V_26 , L_10 , V_41 , V_42 , V_7 ) ;
if ( V_44 )
return V_44 ;
F_34 ( L_10 ) ;
V_27 = V_45 -> V_41 -> V_46 . V_47 -> V_48 ;
V_49 = V_27 -> V_50 ;
F_8 ( V_51
L_11 ,
V_27 -> V_52 -> V_26 ,
V_27 -> V_53 & V_4 ? L_12 : L_13 ,
F_19 ( V_49 ) , F_20 ( V_49 ) ) ;
return 0 ;
}
void T_1 F_35 ( char * V_26 , int V_42 )
{
struct V_38 * V_38 = F_36 ( V_54 |
V_55 ) ;
char * V_56 = F_37 ( V_38 ) ;
char * V_28 ;
#ifdef F_17
char V_57 [ V_58 ] ;
#else
const char * V_57 = V_26 ;
#endif
F_30 ( V_56 ) ;
V_59:
for ( V_28 = V_56 ; * V_28 ; V_28 += strlen ( V_28 ) + 1 ) {
int V_44 = F_32 ( V_26 , V_28 , V_42 , V_35 ) ;
switch ( V_44 ) {
case 0 :
goto V_60;
case - V_61 :
V_42 |= V_4 ;
goto V_59;
case - V_62 :
continue;
}
#ifdef F_17
F_38 ( V_49 , V_57 ) ;
#endif
F_8 ( L_14 ,
V_63 , V_57 , V_44 ) ;
F_8 ( L_15 ) ;
F_39 () ;
#ifdef F_40
F_8 ( L_16
L_17 ) ;
#endif
F_41 ( L_18 , V_57 ) ;
}
F_8 ( L_19 ) ;
F_39 () ;
F_8 ( L_20 ) ;
for ( V_28 = V_56 ; * V_28 ; V_28 += strlen ( V_28 ) + 1 )
F_8 ( L_21 , V_28 ) ;
F_8 ( L_22 ) ;
#ifdef F_17
F_38 ( V_49 , V_57 ) ;
#endif
F_41 ( L_18 , V_57 ) ;
V_60:
F_42 ( V_38 ) ;
}
static int T_1 F_43 ( void )
{
char * V_64 , * V_65 ;
unsigned int V_66 ;
int V_67 , V_44 ;
V_44 = F_44 ( & V_64 , & V_65 ) ;
if ( V_44 != 0 )
return 0 ;
V_66 = V_68 ;
for ( V_67 = 1 ; ; V_67 ++ ) {
V_44 = F_32 ( V_64 , L_8 ,
V_3 , V_65 ) ;
if ( V_44 == 0 )
return 1 ;
if ( V_67 > V_69 )
break;
F_45 ( V_66 ) ;
V_66 <<= 1 ;
if ( V_66 > V_70 )
V_66 = V_70 ;
}
return 0 ;
}
void T_1 F_46 ( char * V_71 , ... )
{
struct V_72 V_72 ;
char V_73 [ 80 ] ;
char V_19 ;
int V_74 ;
T_4 args ;
va_start ( args , V_71 ) ;
vsprintf ( V_73 , V_71 , args ) ;
va_end ( args ) ;
V_74 = F_47 ( L_23 , V_75 | V_76 , 0 ) ;
if ( V_74 >= 0 ) {
F_48 ( V_74 , V_77 , 0 ) ;
F_49 ( V_74 ) ;
}
F_8 ( V_78 L_24 , V_73 ) ;
V_74 = F_47 ( L_25 , V_75 , 0 ) ;
if ( V_74 >= 0 ) {
F_48 ( V_74 , V_79 , ( long ) & V_72 ) ;
V_72 . V_80 &= ~ V_81 ;
F_48 ( V_74 , V_82 , ( long ) & V_72 ) ;
F_50 ( V_74 , & V_19 , 1 ) ;
V_72 . V_80 |= V_81 ;
F_48 ( V_74 , V_82 , ( long ) & V_72 ) ;
F_49 ( V_74 ) ;
}
}
void T_1 F_51 ( void )
{
#ifdef F_52
if ( V_49 == V_32 ) {
if ( F_43 () )
return;
F_8 ( V_20 L_26 ) ;
V_49 = V_83 ;
}
#endif
#ifdef F_53
if ( F_19 ( V_49 ) == V_84 ) {
if ( V_2 == 2 ) {
if ( F_54 ( 1 ) ) {
V_49 = V_85 ;
V_63 = NULL ;
}
} else
F_46 ( L_27 ) ;
}
#endif
#ifdef F_17
F_55 ( L_23 , V_49 ) ;
F_35 ( L_23 , V_3 ) ;
#endif
}
void T_1 F_56 ( void )
{
int V_86 ;
if ( V_37 ) {
F_8 ( V_51 L_28 ,
V_37 ) ;
F_45 ( V_37 ) ;
}
F_57 () ;
F_58 () ;
if ( V_34 [ 0 ] ) {
V_63 = V_34 ;
if ( ! strncmp ( V_63 , L_29 , 3 ) ||
! strncmp ( V_63 , L_30 , 3 ) ) {
F_35 ( V_63 , V_3 ) ;
goto V_60;
}
V_49 = F_16 ( V_63 ) ;
if ( strncmp ( V_63 , L_6 , 5 ) == 0 )
V_63 += 5 ;
}
if ( F_59 () )
goto V_60;
if ( ( V_49 == 0 ) && V_21 ) {
F_8 ( V_51 L_31 ,
V_34 ) ;
while ( F_60 () != 0 ||
( V_49 = F_16 ( V_34 ) ) == 0 )
F_61 ( 100 ) ;
F_62 () ;
}
V_86 = F_19 ( V_49 ) == V_84 ;
if ( V_86 && V_2 && F_54 ( 0 ) )
V_49 = V_33 ;
F_51 () ;
V_60:
F_63 ( L_32 ) ;
F_33 ( L_33 , L_34 , NULL , V_87 , NULL ) ;
F_64 ( L_33 ) ;
}
