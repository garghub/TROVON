static inline int F_1 ( const char * V_1 , const char * V_2 )
{
return strlen ( V_1 ) > strlen ( V_2 ) &&
strncmp ( V_1 , V_2 , strlen ( V_2 ) ) == 0 ;
}
static inline int F_2 ( const char * V_1 , const char * V_3 )
{
return strlen ( V_1 ) > strlen ( V_3 ) &&
strcmp ( V_1 + strlen ( V_1 ) - strlen ( V_3 ) , V_3 ) == 0 ;
}
static int F_3 ( const char * V_4 )
{
T_1 * V_5 ;
const struct V_6 * V_7 ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 == NULL )
return - V_8 ;
while ( V_7 = F_5 ( V_5 ) , V_7 != NULL )
if ( F_1 ( V_7 -> V_9 , L_1 ) &&
F_2 ( V_7 -> V_9 , L_2 ) ) {
printf ( L_3 , V_7 -> V_9 ) ;
}
return 0 ;
}
static int F_6 ( const char * V_4 )
{
char V_10 [ V_11 ] ;
int V_12 ;
sscanf ( V_4 + strlen ( V_13 ) + strlen ( V_14 ) ,
L_4 , & V_12 ) ;
F_7 ( L_5 , V_4 , V_10 ) ;
printf ( L_6 , V_12 , V_10 ) ;
if ( V_15 >= V_16 ) {
int V_17 = F_3 ( V_4 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_8 ( const char * V_4 )
{
char V_10 [ V_11 ] ;
int V_12 ;
sscanf ( V_4 + strlen ( V_13 ) + strlen ( V_18 ) ,
L_4 , & V_12 ) ;
F_7 ( L_5 , V_4 , V_10 ) ;
printf ( L_7 , V_12 , V_10 ) ;
return 0 ;
}
static void F_9 ( void )
{
const struct V_6 * V_7 ;
int V_19 , V_20 ;
T_2 * V_21 ;
T_1 * V_5 ;
char V_22 [ V_11 ] ;
char * V_23 ;
V_5 = F_4 ( V_13 ) ;
if ( V_5 == NULL ) {
printf ( L_8 ) ;
return;
}
while ( V_7 = F_5 ( V_5 ) , V_7 != NULL ) {
if ( F_1 ( V_7 -> V_9 , V_14 ) ) {
char * V_4 ;
F_10 ( & V_4 , L_9 , V_13 , V_7 -> V_9 ) ;
F_6 ( V_4 ) ;
free ( V_4 ) ;
if ( V_15 >= V_16 )
printf ( L_10 ) ;
}
}
F_11 ( V_5 ) ;
while ( V_7 = F_5 ( V_5 ) , V_7 != NULL ) {
if ( F_1 ( V_7 -> V_9 , V_18 ) ) {
char * V_4 ;
F_10 ( & V_4 , L_9 , V_13 , V_7 -> V_9 ) ;
F_8 ( V_4 ) ;
free ( V_4 ) ;
}
}
F_12 ( V_5 ) ;
}
int main ( int V_24 , char * * V_25 )
{
int V_26 , V_27 = 0 ;
while ( ( V_26 = F_13 ( V_24 , V_25 , L_11 ) ) != V_28 ) {
switch ( V_26 ) {
case 'v' :
V_15 ++ ;
break;
case '?' :
default:
V_27 ++ ;
break;
}
}
if ( V_27 || V_24 > V_29 ) {
fprintf ( V_30 , L_12
L_13
L_14
L_15
) ;
exit ( 1 ) ;
}
F_9 () ;
return 0 ;
}
