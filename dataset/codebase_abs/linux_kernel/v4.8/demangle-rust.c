bool
F_1 ( const char * V_1 )
{
T_1 V_2 , V_3 ;
if ( ! V_1 )
return false ;
V_2 = strlen ( V_1 ) ;
if ( V_2 <= V_4 + V_5 )
return false ;
V_3 = V_2 - ( V_4 + V_5 ) ;
if ( ! F_2 ( V_1 + V_3 ) )
return false ;
return F_3 ( V_1 , V_3 ) ;
}
static bool F_2 ( const char * V_6 )
{
const char * V_7 ;
bool V_8 [ 16 ] ;
T_1 V_9 ;
int V_10 ;
if ( strncmp ( V_6 , V_11 , V_4 ) )
return false ;
V_6 += V_4 ;
memset ( V_8 , false , sizeof( V_8 ) ) ;
for ( V_7 = V_6 + V_5 ; V_6 < V_7 ; V_6 ++ )
if ( * V_6 >= '0' && * V_6 <= '9' )
V_8 [ * V_6 - '0' ] = true ;
else if ( * V_6 >= 'a' && * V_6 <= 'f' )
V_8 [ * V_6 - 'a' + 10 ] = true ;
else
return false ;
V_10 = 0 ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ )
if ( V_8 [ V_9 ] )
V_10 ++ ;
return V_10 >= 5 && V_10 <= 15 ;
}
static bool F_3 ( const char * V_6 , T_1 V_2 )
{
const char * V_7 = V_6 + V_2 ;
while ( V_6 < V_7 )
switch ( * V_6 ) {
case '$' :
if ( ! strncmp ( V_6 , L_1 , 3 ) )
V_6 += 3 ;
else if ( ! strncmp ( V_6 , L_2 , 4 )
|| ! strncmp ( V_6 , L_3 , 4 )
|| ! strncmp ( V_6 , L_4 , 4 )
|| ! strncmp ( V_6 , L_5 , 4 )
|| ! strncmp ( V_6 , L_6 , 4 )
|| ! strncmp ( V_6 , L_7 , 4 )
|| ! strncmp ( V_6 , L_8 , 4 ) )
V_6 += 4 ;
else if ( ! strncmp ( V_6 , L_9 , 5 )
|| ! strncmp ( V_6 , L_10 , 5 )
|| ! strncmp ( V_6 , L_11 , 5 )
|| ! strncmp ( V_6 , L_12 , 5 )
|| ! strncmp ( V_6 , L_13 , 5 ) )
V_6 += 5 ;
else
return false ;
break;
case '.' :
if ( ! strncmp ( V_6 , L_14 , 3 ) )
return false ;
case 'a' ... 'z' :
case 'A' ... 'Z' :
case '0' ... '9' :
case '_' :
case ':' :
V_6 ++ ;
break;
default:
return false ;
}
return true ;
}
void
F_4 ( char * V_1 )
{
const char * V_12 ;
char * V_13 ;
const char * V_7 ;
if ( ! V_1 )
return;
V_12 = V_1 ;
V_13 = V_1 ;
V_7 = V_1 + strlen ( V_1 ) - ( V_4 + V_5 ) ;
while ( V_12 < V_7 )
switch ( * V_12 ) {
case '$' :
if ( ! ( F_5 ( & V_12 , & V_13 , L_1 , ',' )
|| F_5 ( & V_12 , & V_13 , L_2 , '@' )
|| F_5 ( & V_12 , & V_13 , L_3 , '*' )
|| F_5 ( & V_12 , & V_13 , L_4 , '&' )
|| F_5 ( & V_12 , & V_13 , L_5 , '<' )
|| F_5 ( & V_12 , & V_13 , L_6 , '>' )
|| F_5 ( & V_12 , & V_13 , L_7 , '(' )
|| F_5 ( & V_12 , & V_13 , L_8 , ')' )
|| F_5 ( & V_12 , & V_13 , L_9 , ' ' )
|| F_5 ( & V_12 , & V_13 , L_10 , '\'' )
|| F_5 ( & V_12 , & V_13 , L_11 , '[' )
|| F_5 ( & V_12 , & V_13 , L_12 , ']' )
|| F_5 ( & V_12 , & V_13 , L_13 , '~' ) ) ) {
F_6 ( L_15 ) ;
goto V_14;
}
break;
case '_' :
if ( ( V_12 == V_1 || V_12 [ - 1 ] == ':' ) && V_12 [ 1 ] == '$' )
V_12 ++ ;
else
* V_13 ++ = * V_12 ++ ;
break;
case '.' :
if ( V_12 [ 1 ] == '.' ) {
* V_13 ++ = ':' ;
* V_13 ++ = ':' ;
V_12 += 2 ;
} else {
* V_13 ++ = '-' ;
V_12 ++ ;
}
break;
case 'a' ... 'z' :
case 'A' ... 'Z' :
case '0' ... '9' :
case ':' :
* V_13 ++ = * V_12 ++ ;
break;
default:
F_6 ( L_16 ,
* V_12 ) ;
goto V_14;
}
V_14:
* V_13 = '\0' ;
}
static bool F_5 ( const char * * V_12 , char * * V_13 , const char * V_15 , char V_16 )
{
T_1 V_2 = strlen ( V_15 ) ;
if ( strncmp ( * V_12 , V_15 , V_2 ) )
return false ;
* * V_13 = V_16 ;
* V_12 += V_2 ;
* V_13 += 1 ;
return true ;
}
