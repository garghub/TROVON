static const char * F_1 ( const char * V_1 )
{
while ( * V_1 && ! isspace ( * V_1 ) )
V_1 ++ ;
return V_1 ;
}
static int F_2 ( const char * V_2 )
{
int V_3 = 0 ;
while ( * V_2 ) {
V_2 = F_3 ( V_2 ) ;
if ( * V_2 ) {
V_3 ++ ;
V_2 = F_1 ( V_2 ) ;
}
}
return V_3 ;
}
void F_4 ( char * * V_4 )
{
char * * V_5 ;
for ( V_5 = V_4 ; * V_5 ; V_5 ++ )
F_5 ( * V_5 ) ;
F_5 ( V_4 ) ;
}
char * * F_6 ( T_1 V_6 , const char * V_2 , int * V_7 )
{
int V_8 = F_2 ( V_2 ) ;
char * * V_4 = F_7 ( sizeof( * V_4 ) * ( V_8 + 1 ) , V_6 ) ;
char * * V_9 ;
if ( V_4 == NULL )
goto V_10;
if ( V_7 )
* V_7 = V_8 ;
V_9 = V_4 ;
while ( * V_2 ) {
V_2 = F_3 ( V_2 ) ;
if ( * V_2 ) {
const char * V_5 = V_2 ;
char * V_11 ;
V_2 = F_1 ( V_2 ) ;
V_11 = F_8 ( V_5 , V_2 - V_5 , V_6 ) ;
if ( V_11 == NULL )
goto V_12;
* V_9 ++ = V_11 ;
}
}
* V_9 = NULL ;
V_10:
return V_4 ;
V_12:
F_4 ( V_4 ) ;
return NULL ;
}
