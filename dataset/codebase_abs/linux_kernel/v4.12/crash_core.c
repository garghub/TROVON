static int T_1 F_1 ( char * V_1 ,
unsigned long long V_2 ,
unsigned long long * V_3 ,
unsigned long long * V_4 )
{
char * V_5 = V_1 , * V_6 ;
do {
unsigned long long V_7 , V_8 = V_9 , V_10 ;
V_7 = F_2 ( V_5 , & V_6 ) ;
if ( V_5 == V_6 ) {
F_3 ( L_1 ) ;
return - V_11 ;
}
V_5 = V_6 ;
if ( * V_5 != '-' ) {
F_3 ( L_2 ) ;
return - V_11 ;
}
V_5 ++ ;
if ( * V_5 != ':' ) {
V_8 = F_2 ( V_5 , & V_6 ) ;
if ( V_5 == V_6 ) {
F_3 ( L_1 ) ;
return - V_11 ;
}
V_5 = V_6 ;
if ( V_8 <= V_7 ) {
F_3 ( L_3 ) ;
return - V_11 ;
}
}
if ( * V_5 != ':' ) {
F_3 ( L_4 ) ;
return - V_11 ;
}
V_5 ++ ;
V_10 = F_2 ( V_5 , & V_6 ) ;
if ( V_5 == V_6 ) {
F_3 ( L_5 ) ;
return - V_11 ;
}
V_5 = V_6 ;
if ( V_10 >= V_2 ) {
F_3 ( L_6 ) ;
return - V_11 ;
}
if ( V_2 >= V_7 && V_2 < V_8 ) {
* V_3 = V_10 ;
break;
}
} while ( * V_5 ++ == ',' );
if ( * V_3 > 0 ) {
while ( * V_5 && * V_5 != ' ' && * V_5 != '@' )
V_5 ++ ;
if ( * V_5 == '@' ) {
V_5 ++ ;
* V_4 = F_2 ( V_5 , & V_6 ) ;
if ( V_5 == V_6 ) {
F_3 ( L_7 ) ;
return - V_11 ;
}
}
}
return 0 ;
}
static int T_1 F_4 ( char * V_1 ,
unsigned long long * V_3 ,
unsigned long long * V_4 )
{
char * V_5 = V_1 ;
* V_3 = F_2 ( V_1 , & V_5 ) ;
if ( V_1 == V_5 ) {
F_3 ( L_8 ) ;
return - V_11 ;
}
if ( * V_5 == '@' )
* V_4 = F_2 ( V_5 + 1 , & V_5 ) ;
else if ( * V_5 != ' ' && * V_5 != '\0' ) {
F_3 ( L_9 , * V_5 ) ;
return - V_11 ;
}
return 0 ;
}
static int T_1 F_5 ( char * V_1 ,
unsigned long long * V_3 ,
const char * V_12 )
{
char * V_5 = V_1 ;
* V_3 = F_2 ( V_1 , & V_5 ) ;
if ( V_1 == V_5 ) {
F_3 ( L_8 ) ;
return - V_11 ;
}
if ( strncmp ( V_5 , V_12 , strlen ( V_12 ) ) ) {
F_3 ( L_9 , * V_5 ) ;
return - V_11 ;
}
V_5 += strlen ( V_12 ) ;
if ( * V_5 != ' ' && * V_5 != '\0' ) {
F_3 ( L_9 , * V_5 ) ;
return - V_11 ;
}
return 0 ;
}
static T_1 char * F_6 ( char * V_1 ,
const char * V_13 ,
const char * V_12 )
{
char * V_14 = V_1 , * V_15 = NULL ;
V_14 = strstr ( V_14 , V_13 ) ;
while ( V_14 ) {
char * V_16 = strchr ( V_14 , ' ' ) ;
char * V_17 ;
if ( ! V_16 )
V_16 = V_14 + strlen ( V_14 ) ;
if ( ! V_12 ) {
int V_18 ;
for ( V_18 = 0 ; V_19 [ V_18 ] ; V_18 ++ ) {
V_17 = V_16 - strlen ( V_19 [ V_18 ] ) ;
if ( ! strncmp ( V_17 , V_19 [ V_18 ] ,
strlen ( V_19 [ V_18 ] ) ) )
goto V_20;
}
V_15 = V_14 ;
} else {
V_17 = V_16 - strlen ( V_12 ) ;
if ( ! strncmp ( V_17 , V_12 , strlen ( V_12 ) ) )
V_15 = V_14 ;
}
V_20:
V_14 = strstr ( V_14 + 1 , V_13 ) ;
}
if ( ! V_15 )
return NULL ;
return V_15 ;
}
static int T_1 F_7 ( char * V_1 ,
unsigned long long V_2 ,
unsigned long long * V_3 ,
unsigned long long * V_4 ,
const char * V_13 ,
const char * V_12 )
{
char * V_21 , * V_22 ;
char * V_15 ;
F_8 ( ! V_3 || ! V_4 ) ;
* V_3 = 0 ;
* V_4 = 0 ;
V_15 = F_6 ( V_1 , V_13 , V_12 ) ;
if ( ! V_15 )
return - V_11 ;
V_15 += strlen ( V_13 ) ;
if ( V_12 )
return F_5 ( V_15 , V_3 ,
V_12 ) ;
V_21 = strchr ( V_15 , ':' ) ;
V_22 = strchr ( V_15 , ' ' ) ;
if ( V_21 && ( ! V_22 || V_21 < V_22 ) )
return F_1 ( V_15 , V_2 ,
V_3 , V_4 ) ;
return F_4 ( V_15 , V_3 , V_4 ) ;
}
int T_1 F_9 ( char * V_1 ,
unsigned long long V_2 ,
unsigned long long * V_3 ,
unsigned long long * V_4 )
{
return F_7 ( V_1 , V_2 , V_3 , V_4 ,
L_10 , NULL ) ;
}
int T_1 F_10 ( char * V_1 ,
unsigned long long V_2 ,
unsigned long long * V_3 ,
unsigned long long * V_4 )
{
return F_7 ( V_1 , V_2 , V_3 , V_4 ,
L_10 , V_19 [ V_23 ] ) ;
}
int T_1 F_11 ( char * V_1 ,
unsigned long long V_2 ,
unsigned long long * V_3 ,
unsigned long long * V_4 )
{
return F_7 ( V_1 , V_2 , V_3 , V_4 ,
L_10 , V_19 [ V_24 ] ) ;
}
T_2 * F_12 ( T_2 * V_25 , char * V_13 , unsigned int type ,
void * V_26 , T_3 V_27 )
{
struct V_28 * V_29 = (struct V_28 * ) V_25 ;
V_29 -> V_30 = strlen ( V_13 ) + 1 ;
V_29 -> V_31 = V_27 ;
V_29 -> V_32 = type ;
V_25 += F_13 ( sizeof( * V_29 ) , sizeof( T_2 ) ) ;
memcpy ( V_25 , V_13 , V_29 -> V_30 ) ;
V_25 += F_13 ( V_29 -> V_30 , sizeof( T_2 ) ) ;
memcpy ( V_25 , V_26 , V_27 ) ;
V_25 += F_13 ( V_27 , sizeof( T_2 ) ) ;
return V_25 ;
}
void F_14 ( T_2 * V_25 )
{
memset ( V_25 , 0 , sizeof( struct V_28 ) ) ;
}
static void F_15 ( void )
{
T_4 * V_25 = V_33 ;
if ( ! V_34 )
return;
V_25 = F_12 ( V_25 , V_35 , 0 , V_36 ,
V_34 ) ;
F_14 ( V_25 ) ;
}
void F_16 ( void )
{
F_17 ( L_11 , F_18 () ) ;
F_15 () ;
}
void F_17 ( const char * V_37 , ... )
{
T_5 args ;
char V_25 [ 0x50 ] ;
T_3 V_38 ;
va_start ( args , V_37 ) ;
V_38 = F_19 ( V_25 , sizeof( V_25 ) , V_37 , args ) ;
va_end ( args ) ;
V_38 = F_20 ( V_38 , V_39 - V_34 ) ;
memcpy ( & V_36 [ V_34 ] , V_25 , V_38 ) ;
V_34 += V_38 ;
}
void __weak F_21 ( void )
{}
T_6 __weak F_22 ( void )
{
return F_23 ( ( unsigned long ) ( char * ) & V_33 ) ;
}
static int T_1 F_24 ( void )
{
F_25 ( V_40 . V_13 . V_41 ) ;
F_26 ( V_42 ) ;
F_27 ( V_40 ) ;
F_27 ( V_43 ) ;
#ifdef F_28
F_27 ( V_44 ) ;
#endif
F_27 ( V_45 ) ;
F_27 ( V_46 ) ;
#ifndef F_29
F_27 ( V_47 ) ;
F_27 ( V_48 ) ;
#endif
#ifdef F_30
F_27 ( V_49 ) ;
F_31 ( V_49 , V_50 ) ;
F_32 ( V_49 ) ;
F_33 ( V_49 , V_51 ) ;
#endif
F_32 ( V_52 ) ;
F_32 ( V_53 ) ;
F_32 ( V_54 ) ;
F_32 ( V_55 ) ;
F_32 ( V_56 ) ;
F_34 ( V_57 ) ;
F_33 ( V_52 , V_58 ) ;
F_33 ( V_52 , V_59 ) ;
F_33 ( V_52 , V_60 ) ;
F_33 ( V_52 , V_61 ) ;
F_33 ( V_52 , V_62 ) ;
F_33 ( V_52 , V_63 ) ;
F_33 ( V_52 , V_64 ) ;
F_33 ( V_52 , V_65 ) ;
F_33 ( V_52 , V_66 ) ;
F_33 ( V_53 , V_67 ) ;
F_33 ( V_53 , V_68 ) ;
#ifdef F_35
F_33 ( V_53 , V_69 ) ;
#endif
F_33 ( V_53 , V_70 ) ;
F_33 ( V_53 , V_71 ) ;
F_33 ( V_53 , V_72 ) ;
F_33 ( V_54 , V_55 ) ;
F_33 ( V_54 , V_73 ) ;
F_33 ( V_54 , V_74 ) ;
F_33 ( V_55 , V_75 ) ;
F_33 ( V_56 , V_20 ) ;
F_33 ( V_56 , V_76 ) ;
F_33 ( V_77 , va_start ) ;
F_33 ( V_77 , V_78 ) ;
F_31 ( V_54 . V_55 , V_79 ) ;
F_36 () ;
F_31 ( V_55 . V_75 , V_80 ) ;
F_37 ( V_81 ) ;
F_37 ( V_82 ) ;
F_37 ( V_83 ) ;
F_37 ( V_84 ) ;
F_37 ( V_85 ) ;
#ifdef F_38
F_37 ( V_86 ) ;
#endif
F_37 ( V_87 ) ;
F_37 ( V_88 ) ;
#ifdef F_39
F_37 ( V_89 ) ;
#endif
F_21 () ;
F_15 () ;
return 0 ;
}
