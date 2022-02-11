static void T_1 F_1 ( void )
{
const char * V_1 [] = { L_1 , L_2 , L_3 , NULL } ;
int V_2 ;
char * V_3 = NULL ;
if ( V_4 != NULL )
return;
for ( V_2 = 0 ; V_1 [ V_2 ] ; V_2 ++ ) {
V_3 = getenv ( V_1 [ V_2 ] ) ;
if ( ( V_3 != NULL ) && ( * V_3 != '\0' ) )
break;
}
if ( ( V_3 == NULL ) || ( * V_3 == '\0' ) )
V_3 = V_5 ;
V_4 = malloc ( strlen ( V_3 ) + 2 ) ;
if ( V_4 == NULL ) {
fprintf ( V_6 , L_4
L_5 , V_7 ) ;
return;
}
strcpy ( V_4 , V_3 ) ;
strcat ( V_4 , L_6 ) ;
}
static int F_2 ( int V_8 , char * V_9 , T_2 V_10 , char V_11 )
{
T_3 V_12 ;
T_2 V_13 ;
char * V_14 ;
while ( ( V_14 = strchr ( V_9 , V_11 ) ) == NULL ) {
V_12 = F_3 ( V_8 , V_9 , V_10 - 1 ) ;
if ( V_12 == 0 )
return 0 ;
else if ( V_12 < 0 )
return - V_7 ;
V_9 [ V_12 ] = '\0' ;
}
V_14 ++ ;
V_13 = strlen ( V_14 ) ;
memmove ( V_9 , V_14 , V_13 + 1 ) ;
V_12 = F_3 ( V_8 , & V_9 [ V_13 ] , V_10 - V_13 - 1 ) ;
if ( V_12 < 0 )
return - V_7 ;
V_9 [ V_13 + V_12 ] = '\0' ;
return 1 ;
}
static void F_4 ( void )
{
int V_8 , V_15 ;
char V_9 [ 128 ] = { '\0' } ;
if ( V_16 )
return;
V_16 = 1 ;
printf ( L_7 ) ;
V_8 = F_5 ( L_8 , V_17 ) ;
if ( V_8 < 0 ) {
printf ( L_9 , V_7 ) ;
return;
}
while ( 1 ) {
V_15 = F_2 ( V_8 , V_9 , F_6 ( V_9 ) , ' ' ) ;
if ( V_15 != 1 )
break;
if ( ! strncmp ( V_9 , L_10 , strlen ( L_10 ) ) )
goto V_15;
V_15 = F_2 ( V_8 , V_9 , F_6 ( V_9 ) , '\n' ) ;
if ( V_15 != 1 )
break;
}
V_18:
if ( V_15 == 0 )
printf ( L_11 ) ;
else if ( V_15 < 0 )
printf ( L_12 , - V_15 ) ;
V_19:
F_7 ( V_8 ) ;
return;
V_15:
V_15 = F_2 ( V_8 , V_9 , F_6 ( V_9 ) , ' ' ) ;
if ( V_15 != 1 )
goto V_18;
if ( strncmp ( V_9 , L_13 , strlen ( L_13 ) ) ) {
printf ( L_14 ) ;
goto V_19;
}
printf ( L_15 ) ;
V_5 = L_10 ;
goto V_19;
}
static int T_1 F_8 ( const char * V_20 , char * * V_21 ,
int V_22 )
{
char * V_23 ;
int V_8 ;
F_4 () ;
V_23 = malloc ( V_24 ) ;
if ( V_23 == NULL )
return - 1 ;
F_1 () ;
if ( ( V_4 == NULL ) || ( strlen ( V_4 ) >= V_24 ) )
goto V_19;
if ( V_20 [ 0 ] != '/' )
strcpy ( V_23 , V_4 ) ;
else
V_23 [ 0 ] = '\0' ;
strncat ( V_23 , V_20 , V_24 - 1 - strlen ( V_23 ) ) ;
V_8 = F_9 ( V_23 ) ;
if ( V_8 < 0 ) {
fprintf ( V_6 , L_16 , V_23 ,
strerror ( V_7 ) ) ;
goto V_19;
}
if ( V_22 && ( F_10 ( V_23 ) < 0 ) ) {
perror ( L_17 ) ;
goto F_7;
}
if ( V_21 ) {
* V_21 = V_23 ;
} else
free ( V_23 ) ;
return V_8 ;
F_7:
F_7 ( V_8 ) ;
V_19:
free ( V_23 ) ;
return - 1 ;
}
static int T_1 F_11 ( unsigned long long V_13 )
{
int V_8 , V_18 ;
char V_25 ;
V_8 = F_8 ( V_26 , NULL , 1 ) ;
if ( V_8 < 0 )
exit ( 1 ) ;
V_18 = F_12 ( V_8 , 0777 ) ;
if ( V_18 < 0 ) {
perror ( L_18 ) ;
exit ( 1 ) ;
}
if ( F_13 ( V_8 , V_13 - 1 , V_27 ) < 0 ) {
perror ( L_19 ) ;
exit ( 1 ) ;
}
V_25 = 0 ;
V_18 = F_14 ( V_8 , & V_25 , 1 ) ;
if ( V_18 != 1 ) {
perror ( L_20 ) ;
exit ( 1 ) ;
}
return V_8 ;
}
int T_1 F_15 ( unsigned long long V_13 )
{
int V_18 , V_8 ;
V_8 = F_11 ( V_13 ) ;
V_18 = F_16 ( V_8 ) ;
if ( V_18 < 0 ) {
V_7 = - V_18 ;
perror ( L_21 ) ;
}
return V_8 ;
}
void T_1 F_17 ( void )
{
void * V_28 ;
int V_18 , V_8 = F_11 ( V_29 ) ;
V_28 = F_18 ( NULL , V_29 ,
V_30 | V_31 | V_32 , V_33 , V_8 , 0 ) ;
printf ( L_22 , V_4 ) ;
fflush ( stdout ) ;
if ( V_28 == V_34 ) {
V_18 = V_7 ;
perror ( L_23 ) ;
F_7 ( V_8 ) ;
if ( V_18 == V_35 )
printf ( L_24 , V_4 ) ;
exit ( 1 ) ;
}
printf ( L_15 ) ;
F_19 ( V_28 , V_29 ) ;
F_7 ( V_8 ) ;
}
