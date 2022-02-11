static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( V_2 -> V_3 && ! F_2 ( * V_2 -> V_3 ) )
F_3 ( ( char * * ) & V_2 -> V_3 ) ;
F_1 ( V_2 -> V_4 ) ;
F_1 ( V_2 -> V_5 ) ;
free ( V_2 ) ;
}
}
void F_4 ( struct V_6 * V_7 )
{
if ( V_7 ) {
F_1 ( V_7 -> V_8 ) ;
free ( V_7 ) ;
}
}
static const char * F_5 ( const char * V_9 , const char * * V_10 )
{
const char * V_3 ;
while ( isspace ( * V_9 ) )
V_9 ++ ;
if ( * V_9 == '\0' ) {
V_3 = V_9 ;
goto V_11;
}
V_3 = V_9 + 1 ;
if ( ! F_6 ( * V_9 ) ) {
V_12:
while ( * V_3 && ! F_6 ( * V_3 ) && ! isspace ( * V_3 ) )
V_3 ++ ;
if ( * ( V_3 - 1 ) == '\\' || ( * V_3 == '!' && * ( V_3 - 1 ) == '[' ) ) {
V_3 ++ ;
goto V_12;
}
}
V_11:
* V_10 = V_3 ;
return V_9 ;
}
static struct V_1 * F_7 ( const char * V_13 ,
struct V_1 * V_4 ,
struct V_1 * V_5 )
{
struct V_1 * V_2 = F_8 ( sizeof( * V_2 ) ) ;
if ( V_2 ) {
V_2 -> V_3 = V_13 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
}
return V_2 ;
}
static struct V_1 * F_9 ( const char * V_9 ,
const char * * V_14 )
{
struct V_1 V_8 , * V_15 , * V_16 ;
const char * V_10 ;
if ( ! V_9 )
return NULL ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_16 = V_15 = & V_8 ;
V_9 = F_5 ( V_9 , & V_10 ) ;
while ( * V_9 != '\0' && * V_9 != ')' ) {
switch ( * V_9 ) {
case '&' :
if ( ! V_15 -> V_5 || ! V_16 -> V_5 )
goto error;
V_15 = F_7 ( V_17 , V_16 -> V_5 , NULL ) ;
if ( ! V_15 )
goto V_18;
V_16 -> V_5 = V_15 ;
V_16 = V_15 ;
break;
case '|' :
if ( ! V_15 -> V_5 || ! V_8 . V_5 )
goto error;
V_15 = F_7 ( V_19 , V_8 . V_5 , NULL ) ;
if ( ! V_15 )
goto V_18;
V_8 . V_5 = V_15 ;
V_16 = V_15 ;
break;
case '!' :
if ( V_15 -> V_5 )
goto error;
V_15 -> V_5 = F_7 ( V_20 , NULL , NULL ) ;
if ( ! V_15 -> V_5 )
goto V_18;
V_15 = V_15 -> V_5 ;
break;
case '(' :
if ( V_15 -> V_5 )
goto error;
V_15 -> V_5 = F_9 ( V_9 + 1 , & V_9 ) ;
if ( ! V_9 )
goto V_18;
if ( ! V_15 -> V_5 || * V_9 != ')' )
goto error;
V_10 = V_9 + 1 ;
break;
default:
if ( V_15 -> V_5 )
goto error;
V_15 -> V_5 = F_7 ( NULL , NULL , NULL ) ;
if ( ! V_15 -> V_5 )
goto V_18;
V_15 -> V_5 -> V_3 = F_10 ( V_9 , V_10 - V_9 ) ;
if ( ! V_15 -> V_5 -> V_3 )
goto V_18;
}
V_9 = F_5 ( V_10 , & V_10 ) ;
}
if ( ! V_15 -> V_5 )
goto error;
* V_14 = V_9 ;
return V_8 . V_5 ;
V_18:
V_9 = NULL ;
error:
* V_14 = V_9 ;
F_1 ( V_8 . V_5 ) ;
return NULL ;
}
struct V_6 * F_11 ( const char * V_21 , const char * * V_22 )
{
struct V_6 * V_7 = F_8 ( sizeof( * V_7 ) ) ;
const char * V_14 = NULL ;
if ( V_7 )
V_7 -> V_8 = F_9 ( V_21 , & V_14 ) ;
if ( ! V_7 || ! V_7 -> V_8 || * V_14 != '\0' ) {
if ( V_22 )
* V_22 = V_14 ;
F_4 ( V_7 ) ;
V_7 = NULL ;
}
return V_7 ;
}
static bool F_12 ( struct V_1 * V_2 ,
const char * V_23 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return false ;
switch ( * V_2 -> V_3 ) {
case '|' :
return F_12 ( V_2 -> V_4 , V_23 ) ||
F_12 ( V_2 -> V_5 , V_23 ) ;
case '&' :
return F_12 ( V_2 -> V_4 , V_23 ) &&
F_12 ( V_2 -> V_5 , V_23 ) ;
case '!' :
return ! F_12 ( V_2 -> V_5 , V_23 ) ;
default:
return F_13 ( V_23 , V_2 -> V_3 ) ;
}
}
bool F_14 ( struct V_6 * V_7 , const char * V_23 )
{
if ( ! V_7 )
return false ;
return F_12 ( V_7 -> V_8 , V_23 ) ;
}
