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
V_6 ;
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
static const char * F_2 ( const char * V_7 )
{
while ( * V_7 && isspace ( * V_7 ) )
V_7 ++ ;
return V_7 ;
}
static const char * F_3 ( const char * V_7 )
{
while ( * V_7 && ! isspace ( * V_7 ) )
V_7 ++ ;
return V_7 ;
}
static int F_4 ( const char * V_1 )
{
int V_8 = 0 ;
while ( * V_1 ) {
V_1 = F_2 ( V_1 ) ;
if ( * V_1 ) {
V_8 ++ ;
V_1 = F_3 ( V_1 ) ;
}
}
return V_8 ;
}
void F_5 ( char * * V_9 )
{
char * * V_3 ;
for ( V_3 = V_9 ; * V_3 ; V_3 ++ ) {
free ( * V_3 ) ;
* V_3 = NULL ;
}
free ( V_9 ) ;
}
char * * F_6 ( const char * V_1 , int * V_10 )
{
int V_11 = F_4 ( V_1 ) ;
char * * V_9 = calloc ( V_11 + 1 , sizeof( * V_9 ) ) ;
char * * V_12 ;
if ( V_9 == NULL )
goto V_13;
if ( V_10 )
* V_10 = V_11 ;
V_12 = V_9 ;
while ( * V_1 ) {
V_1 = F_2 ( V_1 ) ;
if ( * V_1 ) {
const char * V_3 = V_1 ;
char * V_14 ;
V_1 = F_3 ( V_1 ) ;
V_14 = F_7 ( V_3 , V_1 - V_3 ) ;
if ( V_14 == NULL )
goto V_15;
* V_12 ++ = V_14 ;
}
}
* V_12 = NULL ;
V_13:
return V_9 ;
V_15:
F_5 ( V_9 ) ;
return NULL ;
}
static bool F_8 ( const char * V_16 , char V_4 , const char * * V_17 )
{
bool V_18 = false , V_19 = true ;
if ( * V_16 == '!' ) {
V_18 = true ;
V_16 ++ ;
}
if ( * V_16 ++ == V_4 )
goto V_20;
while ( * V_16 && * V_16 != ']' ) {
if ( * V_16 == '-' && * ( V_16 + 1 ) != ']' ) {
if ( * ( V_16 - 1 ) <= V_4 && V_4 <= * ( V_16 + 1 ) )
goto V_20;
if ( * ( V_16 - 1 ) > * ( V_16 + 1 ) )
goto error;
V_16 += 2 ;
} else if ( * V_16 ++ == V_4 )
goto V_20;
}
if ( ! * V_16 )
goto error;
V_19 = false ;
V_20:
while ( * V_16 && * V_16 != ']' )
V_16 ++ ;
if ( ! * V_16 )
goto error;
* V_17 = V_16 + 1 ;
return V_18 ? ! V_19 : V_19 ;
error:
return false ;
}
static bool F_9 ( const char * V_1 , const char * V_16 , bool V_21 ,
bool V_22 )
{
while ( * V_1 && * V_16 && * V_16 != '*' ) {
if ( V_21 ) {
if ( isspace ( * V_1 ) ) {
V_1 ++ ;
continue;
}
if ( isspace ( * V_16 ) ) {
V_16 ++ ;
continue;
}
}
if ( * V_16 == '?' ) {
V_1 ++ ;
V_16 ++ ;
continue;
} else if ( * V_16 == '[' )
if ( F_8 ( V_16 + 1 , * V_1 , & V_16 ) ) {
V_1 ++ ;
continue;
} else
return false ;
else if ( * V_16 == '\\' )
V_16 ++ ;
if ( V_22 ) {
if ( tolower ( * V_1 ) != tolower ( * V_16 ) )
return false ;
} else if ( * V_1 != * V_16 )
return false ;
V_1 ++ ;
V_16 ++ ;
}
if ( * V_16 == '*' ) {
while ( * V_16 == '*' )
V_16 ++ ;
if ( ! * V_16 )
return true ;
while ( * V_1 )
if ( F_9 ( V_1 ++ , V_16 , V_21 , V_22 ) )
return true ;
}
return ! * V_1 && ! * V_16 ;
}
bool F_10 ( const char * V_1 , const char * V_16 )
{
return F_9 ( V_1 , V_16 , false , false ) ;
}
bool F_11 ( const char * V_1 , const char * V_16 )
{
return F_9 ( V_1 , V_16 , false , true ) ;
}
bool F_12 ( const char * V_1 , const char * V_16 )
{
return F_9 ( V_1 , V_16 , true , false ) ;
}
int F_13 ( const char * V_23 , const char * V_24 )
{
int V_25 = strlen ( V_23 ) ;
int V_26 = strlen ( V_24 ) ;
while ( -- V_25 >= 0 && -- V_26 >= 0 ) {
if ( V_23 [ V_25 ] != V_24 [ V_26 ] )
return V_23 [ V_25 ] - V_24 [ V_26 ] ;
}
return 0 ;
}
char * F_14 ( char * V_27 , char V_28 , char V_29 )
{
char * V_3 = V_27 ;
while ( ( V_3 = strchr ( V_3 , V_28 ) ) != NULL )
* V_3 ++ = V_29 ;
return V_27 ;
}
char * F_15 ( char * V_27 )
{
while ( isspace ( * V_27 ) )
V_27 ++ ;
return V_27 ;
}
char * F_16 ( char * V_27 )
{
T_2 V_30 = strlen ( V_27 ) ;
char * V_20 ;
if ( ! V_30 )
return V_27 ;
V_20 = V_27 + V_30 - 1 ;
while ( V_20 >= V_27 && isspace ( * V_20 ) )
V_20 -- ;
* ( V_20 + 1 ) = '\0' ;
return V_27 ;
}
char * F_17 ( const char * V_31 , bool V_32 , T_2 V_33 , int * V_34 )
{
T_2 V_30 = V_33 * 28 + 1 ;
T_2 V_35 , V_36 = 0 ;
char * V_37 = malloc ( V_30 ) ;
if ( V_37 ) {
const char * V_38 = L_3 , * V_39 = L_4 ;
char * V_40 = V_37 ;
if ( ! V_32 ) {
V_38 = L_5 ;
V_39 = L_6 ;
}
for ( V_35 = 0 ; V_35 < V_33 ; ++ V_35 ) {
if ( V_36 == V_30 )
goto V_41;
if ( V_35 > 0 )
V_36 += F_18 ( V_40 + V_36 , V_30 - V_36 , L_7 , V_38 ) ;
V_36 += F_18 ( V_40 + V_36 , V_30 - V_36 ,
L_8 , V_31 , V_39 , V_34 [ V_35 ] ) ;
}
}
return V_37 ;
V_41:
free ( V_37 ) ;
return NULL ;
}
