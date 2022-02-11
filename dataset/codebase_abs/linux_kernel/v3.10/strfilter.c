static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( V_2 -> V_3 && ! F_2 ( * V_2 -> V_3 ) )
free ( ( char * ) V_2 -> V_3 ) ;
F_1 ( V_2 -> V_4 ) ;
F_1 ( V_2 -> V_5 ) ;
free ( V_2 ) ;
}
}
void F_3 ( struct V_6 * V_2 )
{
if ( V_2 ) {
F_1 ( V_2 -> V_7 ) ;
free ( V_2 ) ;
}
}
static const char * F_4 ( const char * V_8 , const char * * V_9 )
{
const char * V_3 ;
while ( isspace ( * V_8 ) )
V_8 ++ ;
if ( * V_8 == '\0' ) {
V_3 = V_8 ;
goto V_10;
}
V_3 = V_8 + 1 ;
if ( ! F_5 ( * V_8 ) ) {
V_11:
while ( * V_3 && ! F_5 ( * V_3 ) && ! isspace ( * V_3 ) )
V_3 ++ ;
if ( * ( V_3 - 1 ) == '\\' || ( * V_3 == '!' && * ( V_3 - 1 ) == '[' ) ) {
V_3 ++ ;
goto V_11;
}
}
V_10:
* V_9 = V_3 ;
return V_8 ;
}
static struct V_1 * F_6 ( const char * V_12 ,
struct V_1 * V_4 ,
struct V_1 * V_5 )
{
struct V_1 * V_13 = F_7 ( sizeof( struct V_1 ) ) ;
if ( V_13 ) {
V_13 -> V_3 = V_12 ;
V_13 -> V_4 = V_4 ;
V_13 -> V_5 = V_5 ;
}
return V_13 ;
}
static struct V_1 * F_8 ( const char * V_8 ,
const char * * V_14 )
{
struct V_1 V_7 , * V_15 , * V_16 ;
const char * V_9 ;
if ( ! V_8 )
return NULL ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_16 = V_15 = & V_7 ;
V_8 = F_4 ( V_8 , & V_9 ) ;
while ( * V_8 != '\0' && * V_8 != ')' ) {
switch ( * V_8 ) {
case '&' :
if ( ! V_15 -> V_5 || ! V_16 -> V_5 )
goto error;
V_15 = F_6 ( V_17 , V_16 -> V_5 , NULL ) ;
if ( ! V_15 )
goto V_18;
V_16 -> V_5 = V_15 ;
V_16 = V_15 ;
break;
case '|' :
if ( ! V_15 -> V_5 || ! V_7 . V_5 )
goto error;
V_15 = F_6 ( V_19 , V_7 . V_5 , NULL ) ;
if ( ! V_15 )
goto V_18;
V_7 . V_5 = V_15 ;
V_16 = V_15 ;
break;
case '!' :
if ( V_15 -> V_5 )
goto error;
V_15 -> V_5 = F_6 ( V_20 , NULL , NULL ) ;
if ( ! V_15 -> V_5 )
goto V_18;
V_15 = V_15 -> V_5 ;
break;
case '(' :
if ( V_15 -> V_5 )
goto error;
V_15 -> V_5 = F_8 ( V_8 + 1 , & V_8 ) ;
if ( ! V_8 )
goto V_18;
if ( ! V_15 -> V_5 || * V_8 != ')' )
goto error;
V_9 = V_8 + 1 ;
break;
default:
if ( V_15 -> V_5 )
goto error;
V_15 -> V_5 = F_6 ( NULL , NULL , NULL ) ;
if ( ! V_15 -> V_5 )
goto V_18;
V_15 -> V_5 -> V_3 = F_9 ( V_8 , V_9 - V_8 ) ;
if ( ! V_15 -> V_5 -> V_3 )
goto V_18;
}
V_8 = F_4 ( V_9 , & V_9 ) ;
}
if ( ! V_15 -> V_5 )
goto error;
* V_14 = V_8 ;
return V_7 . V_5 ;
V_18:
V_8 = NULL ;
error:
* V_14 = V_8 ;
F_1 ( V_7 . V_5 ) ;
return NULL ;
}
struct V_6 * F_10 ( const char * V_21 , const char * * V_22 )
{
struct V_6 * V_13 = F_7 ( sizeof( struct V_6 ) ) ;
const char * V_14 = NULL ;
if ( V_13 )
V_13 -> V_7 = F_8 ( V_21 , & V_14 ) ;
if ( ! V_13 || ! V_13 -> V_7 || * V_14 != '\0' ) {
if ( V_22 )
* V_22 = V_14 ;
F_3 ( V_13 ) ;
V_13 = NULL ;
}
return V_13 ;
}
static bool F_11 ( struct V_1 * V_2 ,
const char * V_23 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return false ;
switch ( * V_2 -> V_3 ) {
case '|' :
return F_11 ( V_2 -> V_4 , V_23 ) ||
F_11 ( V_2 -> V_5 , V_23 ) ;
case '&' :
return F_11 ( V_2 -> V_4 , V_23 ) &&
F_11 ( V_2 -> V_5 , V_23 ) ;
case '!' :
return ! F_11 ( V_2 -> V_5 , V_23 ) ;
default:
return F_12 ( V_23 , V_2 -> V_3 ) ;
}
}
bool F_13 ( struct V_6 * V_2 , const char * V_23 )
{
if ( ! V_2 )
return false ;
return F_11 ( V_2 -> V_7 , V_23 ) ;
}
