static int T_1 F_1 ( void )
{
char V_1 [ 512 ] = { '\0' } ;
int V_2 , V_3 ;
if ( * V_4 == '~' ) {
char * V_5 = getenv ( L_1 ) ;
V_3 = - V_6 ;
if ( V_5 == NULL ) {
F_2 ( V_7 L_2
L_3 ) ;
goto V_3;
}
F_3 ( V_1 , V_5 , sizeof( V_1 ) ) ;
V_4 ++ ;
}
F_4 ( V_1 , V_4 , sizeof( V_1 ) ) ;
V_2 = strlen ( V_1 ) ;
if ( V_2 > 0 && V_1 [ V_2 - 1 ] != '/' )
F_4 ( V_1 , L_4 , sizeof( V_1 ) ) ;
V_3 = - V_8 ;
V_4 = malloc ( strlen ( V_1 ) + 1 ) ;
if ( V_4 == NULL ) {
printf ( L_5 , V_9 ) ;
goto V_3;
}
strcpy ( V_4 , V_1 ) ;
if ( ( F_5 ( V_4 , 0777 ) < 0 ) && ( V_9 != V_10 ) ) {
printf ( L_6 , V_4 , strerror ( V_9 ) ) ;
V_3 = - V_9 ;
goto V_11;
}
return 0 ;
V_11:
free ( V_4 ) ;
V_3:
V_4 = NULL ;
return V_3 ;
}
static int F_6 ( char * V_1 )
{
T_2 * V_12 ;
struct V_13 * V_14 ;
int V_2 ;
char V_15 [ 256 ] ;
int V_16 ;
V_12 = F_7 ( V_1 ) ;
if ( V_12 == NULL ) {
if ( V_9 != V_6 )
return - V_9 ;
else
return 0 ;
}
while ( ( V_14 = F_8 ( V_12 ) ) != NULL ) {
if ( ! strcmp ( V_14 -> V_17 , L_7 ) || ! strcmp ( V_14 -> V_17 , L_8 ) )
continue;
V_2 = strlen ( V_1 ) + sizeof( L_4 ) + strlen ( V_14 -> V_17 ) + 1 ;
if ( V_2 > sizeof( V_15 ) ) {
V_16 = - V_18 ;
goto V_19;
}
sprintf ( V_15 , L_9 , V_1 , V_14 -> V_17 ) ;
if ( F_9 ( V_15 ) < 0 && V_9 != V_6 ) {
V_16 = - V_9 ;
goto V_19;
}
}
if ( F_10 ( V_1 ) < 0 && V_9 != V_6 ) {
V_16 = - V_9 ;
goto V_19;
}
V_16 = 0 ;
V_19:
F_11 ( V_12 ) ;
return V_16 ;
}
static inline int F_12 ( char * V_1 )
{
char V_15 [ strlen ( V_4 ) + V_20 + sizeof( L_10 ) ] ;
char V_21 [ sizeof( L_11 ) ] , * V_22 ;
int V_23 , V_24 , V_25 , V_26 , V_3 ;
V_26 = snprintf ( V_15 , sizeof( V_15 ) , L_12 , V_1 ) ;
if ( V_26 >= sizeof( V_15 ) ) {
F_2 ( V_7 L_13 ) ;
V_3 = - V_18 ;
goto V_19;
}
V_23 = 0 ;
V_24 = F_13 ( V_15 , V_27 ) ;
if ( V_24 < 0 ) {
V_24 = - V_9 ;
if ( V_24 != - V_6 ) {
F_2 ( V_7 L_14
L_15 , V_15 , - V_24 ) ;
}
goto V_19;
}
V_3 = 0 ;
V_26 = F_14 ( V_24 , V_21 , sizeof( V_21 ) ) ;
if ( V_26 < 0 ) {
F_2 ( V_7 L_16
L_17 , V_15 , V_9 ) ;
goto V_28;
} else if ( V_26 == 0 ) {
F_2 ( V_7 L_16
L_18 , V_15 ) ;
goto V_28;
}
V_25 = strtoul ( V_21 , & V_22 , 0 ) ;
if ( V_22 == V_21 ) {
F_2 ( V_7 L_19
L_20 , V_15 , V_9 ) ;
goto V_28;
}
if ( ( F_15 ( V_25 , 0 ) == 0 ) || ( V_9 != V_29 ) ) {
F_2 ( V_7 L_21 ,
V_30 , V_25 ) ;
return 1 ;
}
V_28:
F_16 ( V_24 ) ;
V_19:
return 0 ;
}
static int F_17 ( char * V_1 )
{
int V_16 ;
if ( F_12 ( V_1 ) )
return - V_10 ;
V_16 = F_6 ( V_1 ) ;
if ( V_16 ) {
F_2 ( V_7 L_22
L_23 , V_16 ) ;
}
return V_16 ;
}
static void T_1 F_18 ( void )
{
char V_15 [ strlen ( V_4 ) + V_20 + sizeof( L_10 ) ] ;
char V_21 [ sizeof( L_11 ) ] ;
int V_24 , V_26 ;
if ( F_19 ( L_24 , V_15 , sizeof( V_15 ) ) )
return;
V_24 = F_13 ( V_15 , V_31 | V_32 | V_33 , 0644 ) ;
if ( V_24 < 0 ) {
F_2 ( V_7 L_25
L_26 , V_15 , strerror ( V_9 ) ) ;
return;
}
snprintf ( V_21 , sizeof( V_21 ) , L_27 , F_20 () ) ;
V_26 = F_21 ( V_24 , V_21 , strlen ( V_21 ) ) ;
if ( V_26 != strlen ( V_21 ) )
F_2 ( V_7 L_28 ,
V_9 ) ;
F_16 ( V_24 ) ;
}
int T_1 F_22 ( char * V_34 )
{
if ( strlen ( V_34 ) > V_20 - 1 )
return - V_18 ;
F_3 ( V_30 , V_34 , sizeof( V_30 ) ) ;
return 0 ;
}
static int T_1 F_23 ( void )
{
int V_24 , V_3 ;
char V_35 [ 256 ] ;
if ( V_36 )
return 0 ;
F_1 () ;
if ( * V_30 == '\0' ) {
F_3 ( V_35 , V_4 , sizeof( V_35 ) ) ;
F_4 ( V_35 , L_29 , sizeof( V_35 ) ) ;
V_24 = F_24 ( V_35 ) ;
if ( V_24 < 0 ) {
F_2 ( V_7 L_30
L_26 , V_35 , strerror ( V_9 ) ) ;
V_3 = - V_9 ;
goto V_3;
}
F_16 ( V_24 ) ;
F_22 ( & V_35 [ strlen ( V_4 ) ] ) ;
if ( F_9 ( V_35 ) ) {
V_3 = - V_9 ;
goto V_3;
}
}
snprintf ( V_35 , sizeof( V_35 ) , L_31 , V_4 , V_30 ) ;
V_3 = F_5 ( V_35 , 0777 ) ;
if ( V_3 < 0 ) {
V_3 = - V_9 ;
if ( V_3 != - V_10 )
goto V_3;
if ( F_17 ( V_35 ) < 0 )
goto V_3;
V_3 = F_5 ( V_35 , 0777 ) ;
}
if ( V_3 ) {
V_3 = - V_9 ;
F_2 ( V_7 L_32 , V_30 ,
V_9 ) ;
goto V_3;
}
V_36 = 1 ;
F_18 () ;
V_3 = 0 ;
V_3:
return V_3 ;
}
static int T_1 F_25 ( void )
{
if ( ! F_23 () )
return 0 ;
F_2 ( V_7 L_33
L_34 , V_30 ) ;
* V_30 = '\0' ;
F_23 () ;
return 0 ;
}
int T_1 F_19 ( char * V_34 , char * V_37 , int V_2 )
{
int V_26 , V_3 ;
V_3 = F_23 () ;
if ( V_3 )
return V_3 ;
V_26 = snprintf ( V_37 , V_2 , L_35 , V_4 , V_30 , V_34 ) ;
if ( V_26 >= V_2 ) {
F_2 ( V_7 L_36 ) ;
return - V_18 ;
}
return 0 ;
}
char * F_26 ( void )
{
return V_30 ;
}
static int T_1 F_27 ( char * V_34 , int * V_38 )
{
if ( * V_34 == '\0' ) {
printf ( L_37 ) ;
return 0 ;
}
if ( V_34 [ strlen ( V_34 ) - 1 ] == '/' ) {
V_4 = V_34 ;
return 0 ;
}
V_4 = malloc ( strlen ( V_34 ) + 2 ) ;
if ( V_4 == NULL ) {
printf ( L_38 , V_9 ) ;
return 0 ;
}
sprintf ( V_4 , L_39 , V_34 ) ;
return 0 ;
}
static void F_28 ( void )
{
char V_1 [ strlen ( V_4 ) + V_20 + 1 ] , V_3 ;
sprintf ( V_1 , L_31 , V_4 , V_30 ) ;
V_3 = F_6 ( V_1 ) ;
if ( V_3 )
printf ( L_40
L_41 , V_3 ) ;
}
