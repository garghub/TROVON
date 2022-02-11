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
static int F_12 ( struct V_6 * V_7 , bool V_23 ,
const char * V_21 , const char * * V_22 )
{
struct V_1 * V_24 , * V_8 ;
const char * V_14 = NULL ;
if ( ! V_7 || ! V_21 )
return - V_25 ;
V_24 = F_9 ( V_21 , & V_14 ) ;
if ( ! V_24 || * V_14 != '\0' ) {
if ( V_22 )
* V_22 = V_14 ;
goto error;
}
V_8 = F_7 ( V_23 ? V_19 : V_17 , V_7 -> V_8 , V_24 ) ;
if ( ! V_8 ) {
V_14 = NULL ;
goto error;
}
V_7 -> V_8 = V_8 ;
return 0 ;
error:
F_1 ( V_24 ) ;
return V_14 ? - V_25 : - V_26 ;
}
int F_13 ( struct V_6 * V_7 , const char * V_21 , const char * * V_22 )
{
return F_12 ( V_7 , true , V_21 , V_22 ) ;
}
int F_14 ( struct V_6 * V_7 , const char * V_21 ,
const char * * V_22 )
{
return F_12 ( V_7 , false , V_21 , V_22 ) ;
}
static bool F_15 ( struct V_1 * V_2 ,
const char * V_27 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return false ;
switch ( * V_2 -> V_3 ) {
case '|' :
return F_15 ( V_2 -> V_4 , V_27 ) ||
F_15 ( V_2 -> V_5 , V_27 ) ;
case '&' :
return F_15 ( V_2 -> V_4 , V_27 ) &&
F_15 ( V_2 -> V_5 , V_27 ) ;
case '!' :
return ! F_15 ( V_2 -> V_5 , V_27 ) ;
default:
return F_16 ( V_27 , V_2 -> V_3 ) ;
}
}
bool F_17 ( struct V_6 * V_7 , const char * V_27 )
{
if ( ! V_7 )
return false ;
return F_15 ( V_7 -> V_8 , V_27 ) ;
}
static int F_18 ( struct V_1 * V_2 , char * V_28 )
{
int V_29 ;
int V_30 = V_2 -> V_5 ? 2 : 0 ;
if ( V_28 && V_30 )
* V_28 ++ = '(' ;
V_29 = F_19 ( V_2 , V_28 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_28 && V_30 )
* ( V_28 + V_29 ) = ')' ;
return V_29 + V_30 ;
}
static int F_19 ( struct V_1 * V_2 , char * V_28 )
{
int V_29 = 0 , V_31 ;
if ( ! V_2 || ! V_2 -> V_3 )
return - V_25 ;
switch ( * V_2 -> V_3 ) {
case '|' :
case '&' :
V_29 = F_18 ( V_2 -> V_4 , V_28 ) ;
if ( V_29 < 0 )
return V_29 ;
V_32 ;
case '!' :
if ( V_28 ) {
* ( V_28 + V_29 ++ ) = * V_2 -> V_3 ;
V_28 += V_29 ;
} else
V_29 ++ ;
V_31 = F_18 ( V_2 -> V_5 , V_28 ) ;
if ( V_31 < 0 )
return V_31 ;
V_29 += V_31 ;
break;
default:
V_29 = strlen ( V_2 -> V_3 ) ;
if ( V_28 )
strcpy ( V_28 , V_2 -> V_3 ) ;
}
return V_29 ;
}
char * F_20 ( struct V_6 * V_7 )
{
int V_29 ;
char * V_33 = NULL ;
V_29 = F_19 ( V_7 -> V_8 , NULL ) ;
if ( V_29 < 0 )
return NULL ;
V_33 = malloc ( V_29 + 1 ) ;
if ( V_33 )
F_19 ( V_7 -> V_8 , V_33 ) ;
return V_33 ;
}
