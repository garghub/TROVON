void F_1 ( char * V_1 )
{
char * string ;
F_2 () ;
if ( ! V_1 ) {
return;
}
for ( string = V_1 ; * string ; string ++ ) {
* string = ( char ) tolower ( ( int ) * string ) ;
}
}
void F_3 ( char * V_1 )
{
char * string ;
F_2 () ;
if ( ! V_1 ) {
return;
}
for ( string = V_1 ; * string ; string ++ ) {
* string = ( char ) toupper ( ( int ) * string ) ;
}
}
int F_4 ( char * V_2 , char * V_3 )
{
int V_4 ;
int V_5 ;
do {
V_4 = tolower ( ( int ) * V_2 ) ;
V_5 = tolower ( ( int ) * V_3 ) ;
V_2 ++ ;
V_3 ++ ;
}
while ( ( V_4 == V_5 ) && ( V_4 ) );
return ( V_4 - V_5 ) ;
}
T_1 F_5 ( char * V_6 , T_2 V_7 , char * V_8 )
{
if ( strlen ( V_8 ) >= V_7 ) {
return ( TRUE ) ;
}
strcpy ( V_6 , V_8 ) ;
return ( FALSE ) ;
}
T_1 F_6 ( char * V_6 , T_2 V_7 , char * V_8 )
{
if ( ( strlen ( V_6 ) + strlen ( V_8 ) ) >= V_7 ) {
return ( TRUE ) ;
}
strcat ( V_6 , V_8 ) ;
return ( FALSE ) ;
}
T_1
F_7 ( char * V_6 ,
T_2 V_7 ,
char * V_8 , T_2 V_9 )
{
T_2 V_10 ;
V_10 = F_8 ( V_9 , strlen ( V_8 ) ) ;
if ( ( strlen ( V_6 ) + V_10 ) >= V_7 ) {
return ( TRUE ) ;
}
strncat ( V_6 , V_8 , V_9 ) ;
return ( FALSE ) ;
}
