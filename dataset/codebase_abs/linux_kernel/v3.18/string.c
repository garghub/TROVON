T_1 F_1 ( const char * V_1 )
{
T_1 V_2 ;
char * V_3 ;
char V_4 ;
if ( ! isdigit ( V_1 [ 0 ] ) )
goto V_5;
V_2 = strtoll ( V_1 , & V_3 , 10 ) ;
switch ( V_4 = * V_3 ++ ) {
case 'b' : case 'B' :
if ( * V_3 )
goto V_5;
case '\0' :
return V_2 ;
default:
goto V_5;
case 'k' : case 'K' :
V_2 <<= 10 ;
break;
case 'm' : case 'M' :
V_2 <<= 20 ;
break;
case 'g' : case 'G' :
V_2 <<= 30 ;
break;
case 't' : case 'T' :
V_2 <<= 40 ;
break;
}
if ( islower ( V_4 ) ) {
if ( strcmp ( V_3 , L_1 ) != 0 )
goto V_5;
} else {
if ( strcmp ( V_3 , L_2 ) != 0 )
goto V_5;
}
return V_2 ;
V_5:
return - 1 ;
}
static const char * F_2 ( const char * V_6 )
{
while ( * V_6 && isspace ( * V_6 ) )
V_6 ++ ;
return V_6 ;
}
static const char * F_3 ( const char * V_6 )
{
while ( * V_6 && ! isspace ( * V_6 ) )
V_6 ++ ;
return V_6 ;
}
static int F_4 ( const char * V_1 )
{
int V_7 = 0 ;
while ( * V_1 ) {
V_1 = F_2 ( V_1 ) ;
if ( * V_1 ) {
V_7 ++ ;
V_1 = F_3 ( V_1 ) ;
}
}
return V_7 ;
}
void F_5 ( char * * V_8 )
{
char * * V_3 ;
for ( V_3 = V_8 ; * V_3 ; V_3 ++ )
F_6 ( V_3 ) ;
free ( V_8 ) ;
}
char * * F_7 ( const char * V_1 , int * V_9 )
{
int V_10 = F_4 ( V_1 ) ;
char * * V_8 = F_8 ( sizeof( * V_8 ) * ( V_10 + 1 ) ) ;
char * * V_11 ;
if ( V_8 == NULL )
goto V_12;
if ( V_9 )
* V_9 = V_10 ;
V_11 = V_8 ;
while ( * V_1 ) {
V_1 = F_2 ( V_1 ) ;
if ( * V_1 ) {
const char * V_3 = V_1 ;
char * V_13 ;
V_1 = F_3 ( V_1 ) ;
V_13 = F_9 ( V_3 , V_1 - V_3 ) ;
if ( V_13 == NULL )
goto V_14;
* V_11 ++ = V_13 ;
}
}
* V_11 = NULL ;
V_12:
return V_8 ;
V_14:
F_5 ( V_8 ) ;
return NULL ;
}
static bool F_10 ( const char * V_15 , char V_4 , const char * * V_16 )
{
bool V_17 = false , V_18 = true ;
if ( * V_15 == '!' ) {
V_17 = true ;
V_15 ++ ;
}
if ( * V_15 ++ == V_4 )
goto V_19;
while ( * V_15 && * V_15 != ']' ) {
if ( * V_15 == '-' && * ( V_15 + 1 ) != ']' ) {
if ( * ( V_15 - 1 ) <= V_4 && V_4 <= * ( V_15 + 1 ) )
goto V_19;
if ( * ( V_15 - 1 ) > * ( V_15 + 1 ) )
goto error;
V_15 += 2 ;
} else if ( * V_15 ++ == V_4 )
goto V_19;
}
if ( ! * V_15 )
goto error;
V_18 = false ;
V_19:
while ( * V_15 && * V_15 != ']' )
V_15 ++ ;
if ( ! * V_15 )
goto error;
* V_16 = V_15 + 1 ;
return V_17 ? ! V_18 : V_18 ;
error:
return false ;
}
static bool F_11 ( const char * V_1 , const char * V_15 , bool V_20 )
{
while ( * V_1 && * V_15 && * V_15 != '*' ) {
if ( V_20 ) {
if ( isspace ( * V_1 ) ) {
V_1 ++ ;
continue;
}
if ( isspace ( * V_15 ) ) {
V_15 ++ ;
continue;
}
}
if ( * V_15 == '?' ) {
V_1 ++ ;
V_15 ++ ;
continue;
} else if ( * V_15 == '[' )
if ( F_10 ( V_15 + 1 , * V_1 , & V_15 ) ) {
V_1 ++ ;
continue;
} else
return false ;
else if ( * V_15 == '\\' )
V_15 ++ ;
if ( * V_1 ++ != * V_15 ++ )
return false ;
}
if ( * V_15 == '*' ) {
while ( * V_15 == '*' )
V_15 ++ ;
if ( ! * V_15 )
return true ;
while ( * V_1 )
if ( F_11 ( V_1 ++ , V_15 , V_20 ) )
return true ;
}
return ! * V_1 && ! * V_15 ;
}
bool F_12 ( const char * V_1 , const char * V_15 )
{
return F_11 ( V_1 , V_15 , false ) ;
}
bool F_13 ( const char * V_1 , const char * V_15 )
{
return F_11 ( V_1 , V_15 , true ) ;
}
int F_14 ( const char * V_21 , const char * V_22 )
{
int V_23 = strlen ( V_21 ) ;
int V_24 = strlen ( V_22 ) ;
while ( -- V_23 >= 0 && -- V_24 >= 0 ) {
if ( V_21 [ V_23 ] != V_22 [ V_24 ] )
return V_21 [ V_23 ] - V_22 [ V_24 ] ;
}
return 0 ;
}
char * F_15 ( char * V_25 , char V_26 , char V_27 )
{
char * V_3 = V_25 ;
while ( ( V_3 = strchr ( V_3 , V_26 ) ) != NULL )
* V_3 ++ = V_27 ;
return V_25 ;
}
char * F_16 ( char * V_25 )
{
int V_28 = strlen ( V_25 ) ;
while ( V_28 && isspace ( * V_25 ) ) {
V_28 -- ;
V_25 ++ ;
}
return V_25 ;
}
char * F_17 ( char * V_25 )
{
T_2 V_29 = strlen ( V_25 ) ;
char * V_19 ;
if ( ! V_29 )
return V_25 ;
V_19 = V_25 + V_29 - 1 ;
while ( V_19 >= V_25 && isspace ( * V_19 ) )
V_19 -- ;
* ( V_19 + 1 ) = '\0' ;
return V_25 ;
}
void * F_18 ( const void * V_30 , T_2 V_28 )
{
void * V_3 ;
V_3 = malloc ( V_28 ) ;
if ( V_3 )
memcpy ( V_3 , V_30 , V_28 ) ;
return V_3 ;
}
