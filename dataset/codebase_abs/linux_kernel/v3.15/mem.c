static int T_1 F_1 ( const char * V_1 )
{
struct V_2 V_3 ;
printf ( L_1 , V_1 ) ;
if ( V_2 ( V_1 , & V_3 ) < 0 ) {
printf ( L_2 , strerror ( V_4 ) ) ;
} else if ( V_3 . V_5 != V_6 ) {
printf ( L_3 ) ;
} else {
printf ( L_4 ) ;
return 0 ;
}
return - 1 ;
}
static char * T_1 F_2 ( void )
{
static const char * const V_7 [] = {
L_5 ,
L_6 ,
L_7 ,
NULL
} ;
static const char V_8 [] = L_8 ;
static const char * const V_9 [] = {
L_9 ,
V_8 ,
NULL
} ;
int V_10 ;
const char * V_1 ;
printf ( L_10 ) ;
for ( V_10 = 0 ; V_7 [ V_10 ] ; V_10 ++ ) {
V_1 = getenv ( V_7 [ V_10 ] ) ;
if ( ( V_1 != NULL ) && ( * V_1 != '\0' ) ) {
printf ( L_2 , V_1 ) ;
if ( F_1 ( V_1 ) >= 0 )
goto V_11;
else
goto V_12;
}
}
printf ( L_11 ) ;
for ( V_10 = 0 ; V_9 [ V_10 ] ; V_10 ++ ) {
V_1 = V_9 [ V_10 ] ;
if ( F_1 ( V_1 ) >= 0 )
goto V_11;
}
V_1 = V_8 ;
V_12:
printf ( L_12 , V_1 ) ;
V_11:
return F_3 ( V_1 ) ;
}
static int T_1 F_4 ( const char * V_13 )
{
char * V_14 ;
int V_15 ;
if ( V_16 == NULL ) {
V_16 = F_2 () ;
if ( V_16 == NULL ) {
fprintf ( V_17 , L_13 ,
strerror ( V_4 ) ) ;
return - 1 ;
}
}
V_14 = malloc ( strlen ( V_16 ) + strlen ( V_13 ) + 1 ) ;
if ( V_14 == NULL )
return - 1 ;
strcpy ( V_14 , V_16 ) ;
strcat ( V_14 , V_13 ) ;
V_15 = F_5 ( V_14 ) ;
if ( V_15 < 0 ) {
fprintf ( V_17 , L_14 , V_14 ,
strerror ( V_4 ) ) ;
goto V_18;
}
if ( F_6 ( V_14 ) < 0 ) {
perror ( L_15 ) ;
goto V_19;
}
free ( V_14 ) ;
return V_15 ;
V_19:
V_19 ( V_15 ) ;
V_18:
free ( V_14 ) ;
return - 1 ;
}
static int T_1 F_7 ( unsigned long long V_20 )
{
int V_15 , V_21 ;
char V_22 ;
V_15 = F_4 ( V_23 ) ;
if ( V_15 < 0 )
exit ( 1 ) ;
V_21 = F_8 ( V_15 , 0777 ) ;
if ( V_21 < 0 ) {
perror ( L_16 ) ;
exit ( 1 ) ;
}
if ( F_9 ( V_15 , V_20 - 1 , V_24 ) < 0 ) {
perror ( L_17 ) ;
exit ( 1 ) ;
}
V_22 = 0 ;
V_21 = F_10 ( V_15 , & V_22 , 1 ) ;
if ( V_21 != 1 ) {
perror ( L_18 ) ;
exit ( 1 ) ;
}
return V_15 ;
}
int T_1 F_11 ( unsigned long long V_20 )
{
int V_21 , V_15 ;
V_15 = F_7 ( V_20 ) ;
V_21 = F_12 ( V_15 ) ;
if ( V_21 < 0 ) {
V_4 = - V_21 ;
perror ( L_19 ) ;
}
return V_15 ;
}
void T_1 F_13 ( void )
{
void * V_25 ;
int V_21 , V_15 = F_7 ( V_26 ) ;
V_25 = F_14 ( NULL , V_26 ,
V_27 | V_28 | V_29 , V_30 , V_15 , 0 ) ;
printf ( L_20 , V_16 ) ;
if ( V_25 == V_31 ) {
V_21 = V_4 ;
printf ( L_2 , strerror ( V_21 ) ) ;
V_19 ( V_15 ) ;
if ( V_21 == V_32 )
printf ( L_21 , V_16 ) ;
exit ( 1 ) ;
}
printf ( L_4 ) ;
F_15 ( V_25 , V_26 ) ;
V_19 ( V_15 ) ;
}
