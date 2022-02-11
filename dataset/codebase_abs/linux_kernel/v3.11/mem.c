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
static int F_2 ( int V_8 , char * V_9 , T_2 V_10 , T_2 V_11 )
{
T_3 V_12 ;
T_2 V_13 = strlen ( & V_9 [ V_11 ] ) ;
memmove ( V_9 , & V_9 [ V_11 ] , V_13 + 1 ) ;
V_12 = F_3 ( V_8 , & V_9 [ V_13 ] , V_10 - V_13 - 1 ) ;
if ( V_12 < 0 )
return - V_7 ;
V_9 [ V_13 + V_12 ] = '\0' ;
return 1 ;
}
static int F_4 ( int V_8 , char * V_9 , T_2 V_10 , char V_14 )
{
T_3 V_12 ;
char * V_15 ;
while ( ( V_15 = strchr ( V_9 , V_14 ) ) == NULL ) {
V_12 = F_3 ( V_8 , V_9 , V_10 - 1 ) ;
if ( V_12 == 0 )
return 0 ;
else if ( V_12 < 0 )
return - V_7 ;
V_9 [ V_12 ] = '\0' ;
}
return F_2 ( V_8 , V_9 , V_10 , V_15 - V_9 + 1 ) ;
}
static int F_5 ( const char * V_16 , char * V_17 , T_2 * V_13 )
{
char * V_18 = V_17 ;
int V_14 ;
int V_2 ;
int V_19 = - V_20 ;
while ( 1 ) {
switch ( * V_16 ) {
case '\0' :
goto V_17;
case ' ' :
V_19 = 0 ;
goto V_17;
case '\\' :
V_16 ++ ;
V_14 = 0 ;
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
if ( * V_16 < '0' || * V_16 > '7' )
goto V_17;
V_14 = ( V_14 << 3 ) | ( * V_16 ++ - '0' ) ;
}
* ( unsigned char * ) V_17 ++ = ( unsigned char ) V_14 ;
break;
default:
* V_17 ++ = * V_16 ++ ;
break;
}
}
V_17:
* V_17 = '\0' ;
* V_13 = V_17 - V_18 ;
return V_19 ;
}
static T_2 F_6 ( const char * V_21 , const char * V_22 )
{
T_2 V_13 = strlen ( V_21 ) ;
while ( ( V_21 = strpbrk ( V_21 , V_22 ) ) != NULL ) {
V_13 += 3 ;
V_21 ++ ;
}
return V_13 ;
}
static int F_7 ( int V_8 , char * V_9 , T_2 V_23 , const char * V_24 ,
int * V_25 )
{
int V_26 ;
int V_27 ;
char * V_28 ;
T_2 V_13 ;
enum {
V_29 ,
V_30 ,
V_31 ,
};
V_26 = F_4 ( V_8 , V_9 , V_23 , ' ' ) ;
if ( V_26 != 1 )
return V_26 ;
V_28 = strchr ( V_9 , ' ' ) ;
if ( V_28 ) {
V_27 = V_29 ;
if ( ! F_5 ( V_9 , V_9 , & V_13 ) ) {
if ( ! strcmp ( V_9 , V_24 ) )
V_27 = V_30 ;
else if ( ! strncmp ( V_9 , V_24 , V_13 )
&& ( V_24 [ V_13 ] == '/' || ! strcmp ( V_9 , L_6 ) ) )
V_27 = V_31 ;
}
V_26 = F_2 ( V_8 , V_9 , V_23 , V_28 - V_9 + 1 ) ;
if ( V_26 != 1 )
return V_26 ;
switch ( V_27 ) {
case V_30 :
if ( ! strncmp ( V_9 , L_7 , strlen ( L_7 ) ) )
* V_25 = V_32 ;
else
* V_25 = V_33 ;
break;
case V_31 :
* V_25 = V_34 ;
break;
}
}
return F_4 ( V_8 , V_9 , V_23 , '\n' ) ;
}
static void F_8 ( void )
{
int V_8 ;
int V_26 ;
int V_25 ;
char * V_24 ;
char * V_9 ;
T_2 V_23 ;
if ( V_35 )
return;
V_35 = 1 ;
printf ( L_8 ) ;
V_24 = F_9 ( L_9 , NULL ) ;
if ( ! V_24 ) {
printf ( L_10 , V_7 ) ;
return;
}
printf ( L_11 , V_24 ) ;
V_23 = F_6 ( V_24 , L_12 ) + 2 ;
if ( V_23 < 128 )
V_23 = 128 ;
V_9 = malloc ( V_23 ) ;
if ( ! V_9 ) {
printf ( L_13 , V_7 ) ;
goto V_17;
}
V_9 [ 0 ] = '\0' ;
V_8 = F_10 ( L_14 , V_36 ) ;
if ( V_8 < 0 ) {
printf ( L_15 , V_7 ) ;
goto V_37;
}
V_25 = V_34 ;
while ( 1 ) {
V_26 = F_7 ( V_8 , V_9 , V_23 , V_24 , & V_25 ) ;
if ( V_26 != 1 )
break;
}
if ( V_26 < 0 ) {
printf ( L_16 , - V_26 ) ;
} else {
switch ( V_25 ) {
case V_32 :
printf ( L_17 ) ;
V_5 = L_9 ;
break;
case V_33 :
printf ( L_18 ) ;
break;
default:
printf ( L_19 ) ;
break;
}
}
F_11 ( V_8 ) ;
V_37:
free ( V_9 ) ;
V_17:
free ( V_24 ) ;
}
static int T_1 F_12 ( const char * V_38 , char * * V_39 ,
int V_40 )
{
char * V_41 ;
int V_8 ;
F_8 () ;
V_41 = malloc ( V_42 ) ;
if ( V_41 == NULL )
return - 1 ;
F_1 () ;
if ( ( V_4 == NULL ) || ( strlen ( V_4 ) >= V_42 ) )
goto V_17;
if ( V_38 [ 0 ] != '/' )
strcpy ( V_41 , V_4 ) ;
else
V_41 [ 0 ] = '\0' ;
strncat ( V_41 , V_38 , V_42 - 1 - strlen ( V_41 ) ) ;
V_8 = F_13 ( V_41 ) ;
if ( V_8 < 0 ) {
fprintf ( V_6 , L_20 , V_41 ,
strerror ( V_7 ) ) ;
goto V_17;
}
if ( V_40 && ( F_14 ( V_41 ) < 0 ) ) {
perror ( L_21 ) ;
goto F_11;
}
if ( V_39 ) {
* V_39 = V_41 ;
} else
free ( V_41 ) ;
return V_8 ;
F_11:
F_11 ( V_8 ) ;
V_17:
free ( V_41 ) ;
return - 1 ;
}
static int T_1 F_15 ( unsigned long long V_13 )
{
int V_8 , V_43 ;
char V_44 ;
V_8 = F_12 ( V_45 , NULL , 1 ) ;
if ( V_8 < 0 )
exit ( 1 ) ;
V_43 = F_16 ( V_8 , 0777 ) ;
if ( V_43 < 0 ) {
perror ( L_22 ) ;
exit ( 1 ) ;
}
if ( F_17 ( V_8 , V_13 - 1 , V_46 ) < 0 ) {
perror ( L_23 ) ;
exit ( 1 ) ;
}
V_44 = 0 ;
V_43 = F_18 ( V_8 , & V_44 , 1 ) ;
if ( V_43 != 1 ) {
perror ( L_24 ) ;
exit ( 1 ) ;
}
return V_8 ;
}
int T_1 F_19 ( unsigned long long V_13 )
{
int V_43 , V_8 ;
V_8 = F_15 ( V_13 ) ;
V_43 = F_20 ( V_8 ) ;
if ( V_43 < 0 ) {
V_7 = - V_43 ;
perror ( L_25 ) ;
}
return V_8 ;
}
void T_1 F_21 ( void )
{
void * V_47 ;
int V_43 , V_8 = F_15 ( V_48 ) ;
V_47 = F_22 ( NULL , V_48 ,
V_49 | V_50 | V_51 , V_52 , V_8 , 0 ) ;
printf ( L_26 , V_4 ) ;
fflush ( stdout ) ;
if ( V_47 == V_53 ) {
V_43 = V_7 ;
perror ( L_27 ) ;
F_11 ( V_8 ) ;
if ( V_43 == V_54 )
printf ( L_28 , V_4 ) ;
exit ( 1 ) ;
}
printf ( L_17 ) ;
F_23 ( V_47 , V_48 ) ;
F_11 ( V_8 ) ;
}
