static const char *
F_1 ( const char * V_1 , T_1 * V_2 ,
const char * * V_3 , T_1 * V_4 ,
const char * * V_5 )
{
const char * V_6 , * V_7 , * V_8 ;
char V_9 ;
V_6 = V_1 ;
while ( ( V_9 = * V_6 ) != '\0' && F_2 ( V_9 ) )
V_6 ++ ;
if ( V_9 == '\0' ) {
return NULL ;
}
V_7 = V_6 ;
while ( ( V_9 = * V_6 ) != '\0' && V_9 != '=' && V_9 != ';' )
V_6 ++ ;
* V_2 = ( T_1 ) ( V_6 - V_7 ) ;
if ( V_9 == '\0' ) {
if ( V_3 != NULL )
* V_3 = NULL ;
if ( V_4 != NULL )
* V_4 = 0 ;
* V_5 = V_6 ;
return V_7 ;
}
if ( V_9 == ';' ) {
if ( V_3 != NULL )
* V_3 = NULL ;
if ( V_4 != NULL )
* V_4 = 0 ;
* V_5 = V_6 + 1 ;
return V_7 ;
}
V_6 ++ ;
V_8 = V_6 ;
if ( V_3 != NULL )
* V_3 = V_8 ;
if ( * V_6 == '"' ) {
V_6 ++ ;
for (; ; ) {
V_9 = * V_6 ;
if ( V_9 == '\0' ) {
if ( V_4 != NULL ) {
* V_4 = ( T_1 ) ( V_6 - V_8 ) ;
}
* V_5 = V_6 ;
return V_7 ;
}
if ( V_9 == '"' ) {
V_6 ++ ;
break;
}
if ( V_9 == '\\' ) {
V_6 ++ ;
if ( * V_6 == '\0' ) {
break;
}
}
V_6 ++ ;
}
while ( ( V_9 = * V_6 ) != '\0' && V_9 != ';' )
V_6 ++ ;
} else {
while ( ( V_9 = * V_6 ) != '\0' && V_9 != ';' )
V_6 ++ ;
}
if ( V_9 == '\0' ) {
if ( V_4 != NULL ) {
* V_4 = ( T_1 ) ( V_6 - V_8 ) ;
}
* V_5 = V_6 ;
return V_7 ;
}
if ( V_4 != NULL ) {
* V_4 = ( T_1 ) ( V_6 - V_8 ) ;
}
* V_5 = V_6 + 1 ;
return V_7 ;
}
char *
F_3 ( const char * V_10 , const char * V_11 )
{
const char * V_6 , * V_12 , * V_13 ;
char V_9 ;
T_1 V_14 , V_15 , V_16 ;
char * V_17 , * V_18 ;
if ( V_10 == NULL || V_11 == NULL )
return NULL ;
V_14 = ( T_1 ) strlen ( V_11 ) ;
if ( V_14 == 0 ) {
return NULL ;
}
V_6 = V_10 ;
if ( * V_6 == '\0' ) {
return NULL ;
}
do {
V_12 = F_1 ( V_6 , & V_15 , & V_13 ,
& V_16 , & V_6 ) ;
if ( V_12 == NULL ) {
return NULL ;
}
if ( V_15 == V_14 && F_4 ( V_12 , V_11 , V_14 ) == 0 ) {
break;
}
} while ( * V_6 );
if ( V_13 == NULL ) {
return NULL ;
}
V_17 = ( char * ) F_5 ( V_16 + 1 ) ;
V_18 = V_17 ;
V_6 = V_13 ;
if ( * V_6 == '"' ) {
V_6 ++ ;
for (; ; ) {
V_9 = * V_6 ;
if ( V_9 == '\0' ) {
* V_18 = '\0' ;
return V_17 ;
}
if ( V_9 == '"' ) {
V_6 ++ ;
break;
}
if ( V_9 == '\\' ) {
V_6 ++ ;
if ( * V_6 == '\0' ) {
break;
}
}
* V_18 ++ = * V_6 ++ ;
}
} else {
while ( ( V_9 = * V_6 ) != '\0' && F_6 ( V_9 ) && V_9 != '(' &&
V_9 != ')' && V_9 != '<' && V_9 != '>' && V_9 != '@' &&
V_9 != ',' && V_9 != ';' && V_9 != ':' && V_9 != '\\' &&
V_9 != '"' && V_9 != '/' && V_9 != '[' && V_9 != ']' &&
V_9 != '?' && V_9 != '=' && V_9 != '{' && V_9 != '}' ) {
* V_18 ++ = V_9 ;
V_6 ++ ;
}
}
* V_18 = '\0' ;
return V_17 ;
}
