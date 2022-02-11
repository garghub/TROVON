static bool F_1 ( struct V_1 * V_1 )
{
bool V_2 = false ;
char type [ 100 ] ;
T_1 * V_3 ;
V_3 = fopen ( L_1 , L_2 ) ;
if ( V_3 == NULL )
return NULL ;
while ( ! V_2 &&
fscanf ( V_3 , L_3 F_2 ( V_4 ) L_4 ,
V_1 -> V_5 , type ) == 2 ) {
if ( strcmp ( type , V_1 -> V_6 ) == 0 )
V_2 = true ;
}
fclose ( V_3 ) ;
return V_1 -> V_2 = V_2 ;
}
static int F_3 ( const char * V_1 , long V_7 )
{
struct V_8 V_9 ;
if ( V_8 ( V_1 , & V_9 ) < 0 )
return - V_10 ;
else if ( ( long ) V_9 . V_11 != V_7 )
return - V_10 ;
return 0 ;
}
static bool F_4 ( struct V_1 * V_1 )
{
const char * const * V_12 ;
V_12 = V_1 -> V_13 ;
while ( * V_12 ) {
if ( F_3 ( * V_12 , V_1 -> V_7 ) == 0 ) {
V_1 -> V_2 = true ;
strcpy ( V_1 -> V_5 , * V_12 ) ;
return true ;
}
V_12 ++ ;
}
return false ;
}
static void F_5 ( char * V_14 , T_2 V_15 )
{
while ( V_15 ) {
* V_14 = toupper ( * V_14 ) ;
V_14 ++ ;
V_15 -- ;
}
}
static bool F_6 ( struct V_1 * V_1 )
{
char * V_16 ;
T_2 V_17 = strlen ( V_1 -> V_6 ) ;
char V_18 [ V_17 + 5 + 1 ] ;
memcpy ( V_18 , V_1 -> V_6 , V_17 ) ;
F_5 ( V_18 , V_17 ) ;
strcpy ( & V_18 [ V_17 ] , L_5 ) ;
V_16 = getenv ( V_18 ) ;
if ( ! V_16 )
return false ;
V_1 -> V_2 = true ;
strncpy ( V_1 -> V_5 , V_16 , sizeof( V_1 -> V_5 ) ) ;
return true ;
}
static const char * F_7 ( struct V_1 * V_1 )
{
if ( F_6 ( V_1 ) )
return V_1 -> V_5 ;
if ( F_4 ( V_1 ) )
return V_1 -> V_5 ;
if ( F_1 ( V_1 ) )
return V_1 -> V_5 ;
return NULL ;
}
static const char * F_8 ( int V_19 )
{
struct V_1 * V_1 = & V_20 [ V_19 ] ;
if ( V_1 -> V_2 )
return ( const char * ) V_1 -> V_5 ;
return F_7 ( V_1 ) ;
}
static const char * F_9 ( struct V_1 * V_1 )
{
T_2 V_17 = strlen ( V_1 -> V_6 ) ;
char V_18 [ 5 + V_17 + 12 + 1 ] ;
snprintf ( V_18 , V_17 , L_6 , V_1 -> V_6 ) ;
F_5 ( V_18 , V_17 ) ;
return getenv ( V_18 ) ? : * V_1 -> V_13 ;
}
static const char * F_10 ( int V_19 )
{
struct V_1 * V_1 = & V_20 [ V_19 ] ;
const char * V_21 ;
if ( F_8 ( V_19 ) )
return ( const char * ) V_1 -> V_5 ;
V_21 = F_9 ( V_1 ) ;
if ( F_11 ( NULL , V_21 , V_1 -> V_6 , 0 , NULL ) < 0 )
return NULL ;
return F_4 ( V_1 ) ? V_1 -> V_5 : NULL ;
}
int F_12 ( const char * V_22 , int * V_23 )
{
char line [ 64 ] ;
int V_24 = F_13 ( V_22 , V_25 ) , V_26 = - 1 ;
if ( V_24 < 0 )
return - 1 ;
if ( F_14 ( V_24 , line , sizeof( line ) ) > 0 ) {
* V_23 = atoi ( line ) ;
V_26 = 0 ;
}
F_15 ( V_24 ) ;
return V_26 ;
}
int F_16 ( const char * V_22 , unsigned long long * V_23 )
{
char line [ 64 ] ;
int V_24 = F_13 ( V_22 , V_25 ) , V_26 = - 1 ;
if ( V_24 < 0 )
return - 1 ;
if ( F_14 ( V_24 , line , sizeof( line ) ) > 0 ) {
* V_23 = F_17 ( line , NULL , 0 ) ;
if ( * V_23 != V_27 )
V_26 = 0 ;
}
F_15 ( V_24 ) ;
return V_26 ;
}
int F_18 ( const char * V_22 , char * * V_28 , T_2 * V_29 )
{
T_2 V_30 = 0 , V_31 = 0 ;
void * V_32 = NULL , * V_33 ;
int V_24 , V_34 , V_26 = 0 ;
char V_35 [ V_36 ] ;
V_24 = F_13 ( V_22 , V_25 ) ;
if ( V_24 < 0 )
return - V_37 ;
do {
if ( V_30 == V_31 ) {
V_31 += V_38 ;
V_33 = realloc ( V_32 , V_31 ) ;
if ( ! V_33 ) {
V_26 = - V_39 ;
break;
}
V_32 = V_33 ;
}
V_34 = F_14 ( V_24 , V_32 + V_30 , V_31 - V_30 ) ;
if ( V_34 < 0 ) {
if ( V_30 ) {
F_19 ( L_7 , V_37 ,
F_20 ( V_37 , V_35 , sizeof( V_35 ) ) ) ;
V_26 = 0 ;
} else
V_26 = - V_37 ;
break;
}
V_30 += V_34 ;
} while ( V_34 > 0 );
if ( ! V_26 ) {
* V_29 = V_30 ;
* V_28 = V_32 ;
} else
free ( V_32 ) ;
F_15 ( V_24 ) ;
return V_26 ;
}
int F_21 ( const char * V_22 , int V_23 )
{
int V_24 = F_13 ( V_22 , V_40 ) , V_26 = - 1 ;
char V_28 [ 64 ] ;
if ( V_24 < 0 )
return V_26 ;
sprintf ( V_28 , L_8 , V_23 ) ;
if ( F_22 ( V_24 , V_28 , sizeof( V_28 ) ) == sizeof( V_28 ) )
V_26 = 0 ;
F_15 ( V_24 ) ;
return V_26 ;
}
int F_23 ( const char * V_41 , char * * V_28 , T_2 * V_29 )
{
char V_5 [ V_4 ] ;
const char * V_42 = F_24 () ;
if ( ! V_42 )
return - 1 ;
snprintf ( V_5 , sizeof( V_5 ) , L_9 , V_42 , V_41 ) ;
return F_18 ( V_5 , V_28 , V_29 ) ;
}
int F_25 ( const char * V_41 , unsigned long long * V_23 )
{
char V_5 [ V_4 ] ;
const char * V_43 = F_26 () ;
if ( ! V_43 )
return - 1 ;
snprintf ( V_5 , sizeof( V_5 ) , L_9 , V_43 , V_41 ) ;
return F_16 ( V_5 , V_23 ) ;
}
int F_27 ( const char * V_41 , int * V_23 )
{
char V_5 [ V_4 ] ;
const char * V_43 = F_26 () ;
if ( ! V_43 )
return - 1 ;
snprintf ( V_5 , sizeof( V_5 ) , L_9 , V_43 , V_41 ) ;
return F_12 ( V_5 , V_23 ) ;
}
int F_28 ( const char * V_41 , char * * V_28 , T_2 * V_29 )
{
char V_5 [ V_4 ] ;
const char * V_43 = F_26 () ;
if ( ! V_43 )
return - 1 ;
snprintf ( V_5 , sizeof( V_5 ) , L_9 , V_43 , V_41 ) ;
return F_18 ( V_5 , V_28 , V_29 ) ;
}
int F_29 ( const char * V_41 , bool * V_23 )
{
char * V_28 ;
T_2 V_30 ;
int V_44 ;
V_44 = F_28 ( V_41 , & V_28 , & V_30 ) ;
if ( V_44 < 0 )
return V_44 ;
switch ( V_28 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
* V_23 = true ;
break;
case '0' :
case 'n' :
case 'N' :
* V_23 = false ;
break;
default:
V_44 = - 1 ;
}
free ( V_28 ) ;
return V_44 ;
}
int F_30 ( const char * V_45 , int * V_23 )
{
char V_5 [ V_4 ] ;
const char * V_42 = F_24 () ;
if ( ! V_42 )
return - 1 ;
snprintf ( V_5 , sizeof( V_5 ) , L_10 , V_42 , V_45 ) ;
return F_12 ( V_5 , V_23 ) ;
}
int F_31 ( const char * V_41 , int V_23 )
{
char V_5 [ V_4 ] ;
const char * V_43 = F_26 () ;
if ( ! V_43 )
return - 1 ;
if ( snprintf ( V_5 , sizeof( V_5 ) , L_9 , V_43 , V_41 ) >= V_4 )
return - 1 ;
return F_21 ( V_5 , V_23 ) ;
}
