T_1 F_1 ( const char * V_1 )
{
unsigned int V_2 ;
T_1 V_3 = - 1 , V_4 = 1 ;
if ( ! isdigit ( V_1 [ 0 ] ) )
goto V_5;
for ( V_2 = 1 ; V_2 < strlen ( V_1 ) ; V_2 ++ ) {
switch ( V_1 [ V_2 ] ) {
case 'B' :
case 'b' :
break;
case 'K' :
if ( V_1 [ V_2 + 1 ] != 'B' )
goto V_5;
else
goto V_6;
case 'k' :
if ( V_1 [ V_2 + 1 ] != 'b' )
goto V_5;
V_6:
V_4 = V_7 ;
break;
case 'M' :
if ( V_1 [ V_2 + 1 ] != 'B' )
goto V_5;
else
goto V_8;
case 'm' :
if ( V_1 [ V_2 + 1 ] != 'b' )
goto V_5;
V_8:
V_4 = V_7 * V_7 ;
break;
case 'G' :
if ( V_1 [ V_2 + 1 ] != 'B' )
goto V_5;
else
goto V_9;
case 'g' :
if ( V_1 [ V_2 + 1 ] != 'b' )
goto V_5;
V_9:
V_4 = V_7 * V_7 * V_7 ;
break;
case 'T' :
if ( V_1 [ V_2 + 1 ] != 'B' )
goto V_5;
else
goto V_10;
case 't' :
if ( V_1 [ V_2 + 1 ] != 'b' )
goto V_5;
V_10:
V_4 = V_7 * V_7 * V_7 * V_7 ;
break;
case '\0' :
V_4 = 1 ;
break;
default:
if ( ! isdigit ( V_1 [ V_2 ] ) )
goto V_5;
break;
}
}
V_3 = F_2 ( V_1 ) * V_4 ;
goto V_11;
V_5:
V_3 = - 1 ;
V_11:
return V_3 ;
}
static const char * F_3 ( const char * V_12 )
{
while ( * V_12 && isspace ( * V_12 ) )
V_12 ++ ;
return V_12 ;
}
static const char * F_4 ( const char * V_12 )
{
while ( * V_12 && ! isspace ( * V_12 ) )
V_12 ++ ;
return V_12 ;
}
static int F_5 ( const char * V_1 )
{
int V_13 = 0 ;
while ( * V_1 ) {
V_1 = F_3 ( V_1 ) ;
if ( * V_1 ) {
V_13 ++ ;
V_1 = F_4 ( V_1 ) ;
}
}
return V_13 ;
}
void F_6 ( char * * V_14 )
{
char * * V_15 ;
for ( V_15 = V_14 ; * V_15 ; V_15 ++ )
free ( * V_15 ) ;
free ( V_14 ) ;
}
char * * F_7 ( const char * V_1 , int * V_16 )
{
int V_17 = F_5 ( V_1 ) ;
char * * V_14 = F_8 ( sizeof( * V_14 ) * ( V_17 + 1 ) ) ;
char * * V_18 ;
if ( V_14 == NULL )
goto V_11;
if ( V_16 )
* V_16 = V_17 ;
V_18 = V_14 ;
while ( * V_1 ) {
V_1 = F_3 ( V_1 ) ;
if ( * V_1 ) {
const char * V_15 = V_1 ;
char * V_19 ;
V_1 = F_4 ( V_1 ) ;
V_19 = F_9 ( V_15 , V_1 - V_15 ) ;
if ( V_19 == NULL )
goto V_20;
* V_18 ++ = V_19 ;
}
}
* V_18 = NULL ;
V_11:
return V_14 ;
V_20:
F_6 ( V_14 ) ;
return NULL ;
}
static bool F_10 ( const char * V_21 , char V_22 , const char * * V_23 )
{
bool V_24 = false , V_25 = true ;
if ( * V_21 == '!' ) {
V_24 = true ;
V_21 ++ ;
}
if ( * V_21 ++ == V_22 )
goto V_26;
while ( * V_21 && * V_21 != ']' ) {
if ( * V_21 == '-' && * ( V_21 + 1 ) != ']' ) {
if ( * ( V_21 - 1 ) <= V_22 && V_22 <= * ( V_21 + 1 ) )
goto V_26;
if ( * ( V_21 - 1 ) > * ( V_21 + 1 ) )
goto error;
V_21 += 2 ;
} else if ( * V_21 ++ == V_22 )
goto V_26;
}
if ( ! * V_21 )
goto error;
V_25 = false ;
V_26:
while ( * V_21 && * V_21 != ']' )
V_21 ++ ;
if ( ! * V_21 )
goto error;
* V_23 = V_21 + 1 ;
return V_24 ? ! V_25 : V_25 ;
error:
return false ;
}
static bool F_11 ( const char * V_1 , const char * V_21 , bool V_27 )
{
while ( * V_1 && * V_21 && * V_21 != '*' ) {
if ( V_27 ) {
if ( isspace ( * V_1 ) ) {
V_1 ++ ;
continue;
}
if ( isspace ( * V_21 ) ) {
V_21 ++ ;
continue;
}
}
if ( * V_21 == '?' ) {
V_1 ++ ;
V_21 ++ ;
continue;
} else if ( * V_21 == '[' )
if ( F_10 ( V_21 + 1 , * V_1 , & V_21 ) ) {
V_1 ++ ;
continue;
} else
return false ;
else if ( * V_21 == '\\' )
V_21 ++ ;
if ( * V_1 ++ != * V_21 ++ )
return false ;
}
if ( * V_21 == '*' ) {
while ( * V_21 == '*' )
V_21 ++ ;
if ( ! * V_21 )
return true ;
while ( * V_1 )
if ( F_11 ( V_1 ++ , V_21 , V_27 ) )
return true ;
}
return ! * V_1 && ! * V_21 ;
}
bool F_12 ( const char * V_1 , const char * V_21 )
{
return F_11 ( V_1 , V_21 , false ) ;
}
bool F_13 ( const char * V_1 , const char * V_21 )
{
return F_11 ( V_1 , V_21 , true ) ;
}
int F_14 ( const char * V_28 , const char * V_29 )
{
int V_30 = strlen ( V_28 ) ;
int V_31 = strlen ( V_29 ) ;
while ( -- V_30 >= 0 && -- V_31 >= 0 ) {
if ( V_28 [ V_30 ] != V_29 [ V_31 ] )
return V_28 [ V_30 ] - V_29 [ V_31 ] ;
}
return 0 ;
}
char * F_15 ( char * V_32 , char V_33 , char V_34 )
{
char * V_15 = V_32 ;
while ( ( V_15 = strchr ( V_15 , V_33 ) ) != NULL )
* V_15 ++ = V_34 ;
return V_32 ;
}
char * F_16 ( char * V_32 )
{
int V_35 = strlen ( V_32 ) ;
while ( V_35 && isspace ( * V_32 ) ) {
V_35 -- ;
V_32 ++ ;
}
return V_32 ;
}
char * F_17 ( char * V_32 )
{
T_2 V_36 = strlen ( V_32 ) ;
char * V_26 ;
if ( ! V_36 )
return V_32 ;
V_26 = V_32 + V_36 - 1 ;
while ( V_26 >= V_32 && isspace ( * V_26 ) )
V_26 -- ;
* ( V_26 + 1 ) = '\0' ;
return V_32 ;
}
void * F_18 ( const void * V_37 , T_2 V_35 )
{
void * V_15 ;
V_15 = malloc ( V_35 ) ;
if ( V_15 )
memcpy ( V_15 , V_37 , V_35 ) ;
return V_15 ;
}
int F_19 ( char * * V_32 , int * V_35 , const char * V_38 )
{
int V_39 = * V_32 ? strlen ( * V_32 ) : 0 ;
int V_40 = V_39 + strlen ( V_38 ) + 1 ;
if ( * V_35 < V_40 ) {
* V_35 = * V_35 * 2 ;
if ( * V_35 < V_40 )
* V_35 = V_40 ;
* V_32 = realloc ( * V_32 , * V_35 ) ;
if ( ! * V_32 )
return - V_41 ;
if ( V_39 == 0 )
* * V_32 = 0 ;
}
strcat ( * V_32 , V_38 ) ;
return 0 ;
}
