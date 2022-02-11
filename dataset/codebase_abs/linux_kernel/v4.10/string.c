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
static bool F_11 ( const char * V_1 , const char * V_15 , bool V_20 ,
bool V_21 )
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
if ( V_21 ) {
if ( tolower ( * V_1 ) != tolower ( * V_15 ) )
return false ;
} else if ( * V_1 != * V_15 )
return false ;
V_1 ++ ;
V_15 ++ ;
}
if ( * V_15 == '*' ) {
while ( * V_15 == '*' )
V_15 ++ ;
if ( ! * V_15 )
return true ;
while ( * V_1 )
if ( F_11 ( V_1 ++ , V_15 , V_20 , V_21 ) )
return true ;
}
return ! * V_1 && ! * V_15 ;
}
bool F_12 ( const char * V_1 , const char * V_15 )
{
return F_11 ( V_1 , V_15 , false , false ) ;
}
bool F_13 ( const char * V_1 , const char * V_15 )
{
return F_11 ( V_1 , V_15 , false , true ) ;
}
bool F_14 ( const char * V_1 , const char * V_15 )
{
return F_11 ( V_1 , V_15 , true , false ) ;
}
int F_15 ( const char * V_22 , const char * V_23 )
{
int V_24 = strlen ( V_22 ) ;
int V_25 = strlen ( V_23 ) ;
while ( -- V_24 >= 0 && -- V_25 >= 0 ) {
if ( V_22 [ V_24 ] != V_23 [ V_25 ] )
return V_22 [ V_24 ] - V_23 [ V_25 ] ;
}
return 0 ;
}
char * F_16 ( char * V_26 , char V_27 , char V_28 )
{
char * V_3 = V_26 ;
while ( ( V_3 = strchr ( V_3 , V_27 ) ) != NULL )
* V_3 ++ = V_28 ;
return V_26 ;
}
char * F_17 ( char * V_26 )
{
int V_29 = strlen ( V_26 ) ;
while ( V_29 && isspace ( * V_26 ) ) {
V_29 -- ;
V_26 ++ ;
}
return V_26 ;
}
char * F_18 ( char * V_26 )
{
T_2 V_30 = strlen ( V_26 ) ;
char * V_19 ;
if ( ! V_30 )
return V_26 ;
V_19 = V_26 + V_30 - 1 ;
while ( V_19 >= V_26 && isspace ( * V_19 ) )
V_19 -- ;
* ( V_19 + 1 ) = '\0' ;
return V_26 ;
}
char * F_19 ( const char * V_31 , bool V_32 , T_2 V_33 , int * V_34 )
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
V_36 += snprintf ( V_40 + V_36 , V_30 - V_36 , L_7 , V_38 ) ;
V_36 += F_20 ( V_40 + V_36 , V_30 - V_36 ,
L_8 , V_31 , V_39 , V_34 [ V_35 ] ) ;
}
}
return V_37 ;
V_41:
free ( V_37 ) ;
return NULL ;
}
