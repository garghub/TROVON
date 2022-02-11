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
if ( ! V_5 )
return - V_8 ;
while ( V_7 = F_5 ( V_5 ) , V_7 )
if ( F_1 ( V_7 -> V_9 , L_1 ) &&
( F_2 ( V_7 -> V_9 , L_2 ) ||
F_2 ( V_7 -> V_9 , L_3 ) ) )
printf ( L_4 , V_7 -> V_9 ) ;
return ( F_6 ( V_5 ) == - 1 ) ? - V_8 : 0 ;
}
static int F_7 ( const char * V_4 )
{
char V_10 [ V_11 ] ;
int V_12 ;
int V_13 ;
V_13 = sscanf ( V_4 + strlen ( V_14 ) + strlen ( V_15 ) , L_5 ,
& V_12 ) ;
if ( V_13 != 1 )
return - V_16 ;
V_13 = F_8 ( L_6 , V_4 , V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
printf ( L_7 , V_12 , V_10 ) ;
if ( V_17 >= V_18 )
return F_3 ( V_4 ) ;
return 0 ;
}
static int F_9 ( const char * V_4 )
{
char V_10 [ V_11 ] ;
int V_12 ;
int V_13 ;
V_13 = sscanf ( V_4 + strlen ( V_14 ) + strlen ( V_19 ) ,
L_5 , & V_12 ) ;
if ( V_13 != 1 )
return - V_16 ;
V_13 = F_8 ( L_6 , V_4 , V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
printf ( L_8 , V_12 , V_10 ) ;
return 0 ;
}
static int F_10 ( void )
{
const struct V_6 * V_7 ;
int V_13 ;
T_1 * V_5 ;
V_5 = F_4 ( V_14 ) ;
if ( ! V_5 ) {
fprintf ( V_20 , L_9 ) ;
return - V_21 ;
}
while ( V_7 = F_5 ( V_5 ) , V_7 ) {
if ( F_1 ( V_7 -> V_9 , V_15 ) ) {
char * V_4 ;
if ( F_11 ( & V_4 , L_10 , V_14 ,
V_7 -> V_9 ) < 0 ) {
V_13 = - V_22 ;
goto V_23;
}
V_13 = F_7 ( V_4 ) ;
if ( V_13 ) {
free ( V_4 ) ;
goto V_23;
}
free ( V_4 ) ;
if ( V_17 >= V_18 )
printf ( L_11 ) ;
}
}
F_12 ( V_5 ) ;
while ( V_7 = F_5 ( V_5 ) , V_7 ) {
if ( F_1 ( V_7 -> V_9 , V_19 ) ) {
char * V_4 ;
if ( F_11 ( & V_4 , L_10 , V_14 ,
V_7 -> V_9 ) < 0 ) {
V_13 = - V_22 ;
goto V_23;
}
V_13 = F_9 ( V_4 ) ;
if ( V_13 ) {
free ( V_4 ) ;
goto V_23;
}
free ( V_4 ) ;
}
}
return ( F_6 ( V_5 ) == - 1 ) ? - V_8 : 0 ;
V_23:
if ( F_6 ( V_5 ) == - 1 )
perror ( L_12 ) ;
return V_13 ;
}
int main ( int V_24 , char * * V_25 )
{
int V_26 , V_27 = 0 ;
while ( ( V_26 = F_13 ( V_24 , V_25 , L_13 ) ) != V_28 ) {
switch ( V_26 ) {
case 'v' :
V_17 ++ ;
break;
case '?' :
default:
V_27 ++ ;
break;
}
}
if ( V_27 || V_24 > V_29 ) {
fprintf ( V_20 , L_14
L_15
L_16 ) ;
exit ( 1 ) ;
}
return F_10 () ;
}
