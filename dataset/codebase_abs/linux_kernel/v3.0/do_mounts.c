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
F_8 ( V_13 , V_8 ) ;
V_6 = F_9 ( & V_15 , NULL , V_8 , & F_5 ) ;
if ( ! V_6 )
goto V_16;
V_14 = V_6 -> V_17 ;
F_10 ( V_6 ) ;
V_16:
return V_14 ;
}
T_3 F_11 ( char * V_18 )
{
char V_19 [ 32 ] ;
char * V_20 ;
T_3 V_14 = 0 ;
int V_10 ;
#ifdef F_12
if ( strncmp ( V_18 , L_1 , 9 ) == 0 ) {
V_18 += 9 ;
if ( strlen ( V_18 ) != 36 )
goto V_21;
V_14 = F_7 ( V_18 ) ;
if ( ! V_14 )
goto V_21;
goto V_16;
}
#endif
if ( strncmp ( V_18 , L_2 , 5 ) != 0 ) {
unsigned V_22 , V_23 ;
if ( sscanf ( V_18 , L_3 , & V_22 , & V_23 ) == 2 ) {
V_14 = F_13 ( V_22 , V_23 ) ;
if ( V_22 != F_14 ( V_14 ) || V_23 != F_15 ( V_14 ) )
goto V_21;
} else {
V_14 = F_16 ( F_17 ( V_18 , & V_20 , 16 ) ) ;
if ( * V_20 )
goto V_21;
}
goto V_16;
}
V_18 += 5 ;
V_14 = V_24 ;
if ( strcmp ( V_18 , L_4 ) == 0 )
goto V_16;
V_14 = V_25 ;
if ( strcmp ( V_18 , L_5 ) == 0 )
goto V_16;
if ( strlen ( V_18 ) > 31 )
goto V_21;
strcpy ( V_19 , V_18 ) ;
for ( V_20 = V_19 ; * V_20 ; V_20 ++ )
if ( * V_20 == '/' )
* V_20 = '!' ;
V_14 = F_18 ( V_19 , 0 ) ;
if ( V_14 )
goto V_16;
while ( V_20 > V_19 && isdigit ( V_20 [ - 1 ] ) )
V_20 -- ;
if ( V_20 == V_19 || ! * V_20 || * V_20 == '0' )
goto V_21;
V_10 = F_17 ( V_20 , NULL , 10 ) ;
* V_20 = '\0' ;
V_14 = F_18 ( V_19 , V_10 ) ;
if ( V_14 )
goto V_16;
if ( V_20 < V_19 + 2 || ! isdigit ( V_20 [ - 2 ] ) || V_20 [ - 1 ] != 'p' )
goto V_21;
V_20 [ - 1 ] = '\0' ;
V_14 = F_18 ( V_19 , V_10 ) ;
if ( V_14 )
goto V_16;
V_21:
return 0 ;
V_16:
return V_14 ;
}
static int T_1 F_19 ( char * line )
{
F_20 ( V_26 , line , sizeof( V_26 ) ) ;
return 1 ;
}
static int T_1 F_21 ( char * V_1 )
{
if ( * V_1 )
return 0 ;
V_27 = 1 ;
return 1 ;
}
static int T_1 F_22 ( char * V_1 )
{
V_28 = V_1 ;
return 1 ;
}
static int T_1 F_23 ( char * V_1 )
{
V_29 = V_1 ;
return 1 ;
}
static int T_1 F_24 ( char * V_1 )
{
V_30 = F_17 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static void T_1 F_25 ( char * V_31 )
{
char * V_19 = V_31 ;
if ( V_29 ) {
strcpy ( V_31 , V_29 ) ;
while ( * V_19 ++ ) {
if ( V_19 [ - 1 ] == ',' )
V_19 [ - 1 ] = '\0' ;
}
} else {
int V_32 = F_26 ( V_31 ) ;
char * V_20 , * V_33 ;
V_31 [ V_32 ] = '\0' ;
for ( V_20 = V_31 - 1 ; V_20 ; V_20 = V_33 ) {
V_33 = strchr ( ++ V_20 , '\n' ) ;
if ( * V_20 ++ != '\t' )
continue;
while ( ( * V_19 ++ = * V_20 ++ ) != '\n' )
;
V_19 [ - 1 ] = '\0' ;
}
}
* V_19 = '\0' ;
}
static int T_1 F_27 ( char * V_18 , char * V_34 , int V_35 , void * V_7 )
{
int V_36 = F_28 ( V_18 , L_6 , V_34 , V_35 , V_7 ) ;
if ( V_36 )
return V_36 ;
F_29 ( ( const char V_37 V_38 * ) L_6 ) ;
V_39 = V_40 -> V_34 -> V_41 . V_42 -> V_43 -> V_44 ;
F_30 ( V_45
L_7 ,
V_40 -> V_34 -> V_41 . V_42 -> V_43 -> V_46 -> V_18 ,
V_40 -> V_34 -> V_41 . V_42 -> V_43 -> V_47 & V_4 ?
L_8 : L_9 , F_14 ( V_39 ) , F_15 ( V_39 ) ) ;
return 0 ;
}
void T_1 F_31 ( char * V_18 , int V_35 )
{
char * V_48 = F_32 ( V_49
| V_50 ) ;
char * V_20 ;
#ifdef F_12
char V_51 [ V_52 ] ;
#else
const char * V_51 = V_18 ;
#endif
F_25 ( V_48 ) ;
V_53:
for ( V_20 = V_48 ; * V_20 ; V_20 += strlen ( V_20 ) + 1 ) {
int V_36 = F_27 ( V_18 , V_20 , V_35 , V_28 ) ;
switch ( V_36 ) {
case 0 :
goto V_54;
case - V_55 :
V_35 |= V_4 ;
goto V_53;
case - V_56 :
continue;
}
#ifdef F_12
F_33 ( V_39 , V_51 ) ;
#endif
F_30 ( L_10 ,
V_57 , V_51 ) ;
F_30 ( L_11 ) ;
F_34 () ;
#ifdef F_35
F_30 ( L_12
L_13 ) ;
#endif
F_36 ( L_14 , V_51 ) ;
}
F_30 ( L_15 ) ;
F_34 () ;
F_30 ( L_16 ) ;
for ( V_20 = V_48 ; * V_20 ; V_20 += strlen ( V_20 ) + 1 )
F_30 ( L_17 , V_20 ) ;
F_30 ( L_18 ) ;
#ifdef F_12
F_33 ( V_39 , V_51 ) ;
#endif
F_36 ( L_14 , V_51 ) ;
V_54:
F_37 ( V_48 ) ;
}
static int T_1 F_38 ( void )
{
char * V_58 , * V_59 ;
if ( F_39 ( & V_58 , & V_59 ) != 0 )
return 0 ;
if ( F_27 ( V_58 , L_4 , V_3 , V_59 ) != 0 )
return 0 ;
return 1 ;
}
void T_1 F_40 ( char * V_60 , ... )
{
struct V_61 V_61 ;
char V_62 [ 80 ] ;
char V_63 ;
int V_64 ;
T_4 args ;
va_start ( args , V_60 ) ;
vsprintf ( V_62 , V_60 , args ) ;
va_end ( args ) ;
V_64 = F_41 ( L_19 , V_65 | V_66 , 0 ) ;
if ( V_64 >= 0 ) {
F_42 ( V_64 , V_67 , 0 ) ;
F_43 ( V_64 ) ;
}
F_30 ( V_68 L_20 , V_62 ) ;
V_64 = F_41 ( L_21 , V_65 , 0 ) ;
if ( V_64 >= 0 ) {
F_42 ( V_64 , V_69 , ( long ) & V_61 ) ;
V_61 . V_70 &= ~ V_71 ;
F_42 ( V_64 , V_72 , ( long ) & V_61 ) ;
F_44 ( V_64 , & V_63 , 1 ) ;
V_61 . V_70 |= V_71 ;
F_42 ( V_64 , V_72 , ( long ) & V_61 ) ;
F_43 ( V_64 ) ;
}
}
void T_1 F_45 ( void )
{
#ifdef F_46
if ( F_14 ( V_39 ) == V_73 ) {
if ( F_38 () )
return;
F_30 ( V_74 L_22 ) ;
V_39 = V_75 ;
}
#endif
#ifdef F_47
if ( F_14 ( V_39 ) == V_76 ) {
if ( V_2 == 2 ) {
if ( F_48 ( 1 ) ) {
V_39 = V_77 ;
V_57 = NULL ;
}
} else
F_40 ( L_23 ) ;
}
#endif
#ifdef F_12
F_49 ( L_19 , V_39 ) ;
F_31 ( L_19 , V_3 ) ;
#endif
}
void T_1 F_50 ( void )
{
int V_78 ;
if ( V_30 ) {
F_30 ( V_45 L_24 ,
V_30 ) ;
F_51 ( V_30 ) ;
}
F_52 () ;
F_53 () ;
if ( V_26 [ 0 ] ) {
V_57 = V_26 ;
if ( ! strncmp ( V_57 , L_25 , 3 ) ||
! strncmp ( V_57 , L_26 , 3 ) ) {
F_31 ( V_57 , V_3 ) ;
goto V_54;
}
V_39 = F_11 ( V_57 ) ;
if ( strncmp ( V_57 , L_2 , 5 ) == 0 )
V_57 += 5 ;
}
if ( F_54 () )
goto V_54;
if ( ( V_39 == 0 ) && V_27 ) {
F_30 ( V_45 L_27 ,
V_26 ) ;
while ( F_55 () != 0 ||
( V_39 = F_11 ( V_26 ) ) == 0 )
F_56 ( 100 ) ;
F_57 () ;
}
V_78 = F_14 ( V_39 ) == V_76 ;
if ( V_78 && V_2 && F_48 ( 0 ) )
V_39 = V_25 ;
F_45 () ;
V_54:
F_58 ( L_28 ) ;
F_28 ( L_29 , L_30 , NULL , V_79 , NULL ) ;
F_59 ( ( const char V_37 V_38 * ) L_29 ) ;
}
