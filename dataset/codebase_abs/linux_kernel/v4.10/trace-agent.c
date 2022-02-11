static int F_1 ( void )
{
int V_1 = ( int ) F_2 ( V_2 ) ;
if ( V_1 <= 0 ) {
F_3 ( L_1 ) ;
goto error;
} else if ( V_1 > V_3 ) {
F_3 ( L_2 , ( int ) V_3 ) ;
goto error;
}
return V_1 ;
error:
exit ( V_4 ) ;
}
static void * F_4 ( void )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_5 ( sizeof( struct V_5 ) ) ;
if ( V_6 == NULL ) {
F_3 ( L_3 ) ;
exit ( V_4 ) ;
}
V_6 -> V_8 = V_9 ;
V_6 -> V_10 = false ;
V_6 -> V_11 = F_1 () ;
V_6 -> V_12 = - 1 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ )
V_6 -> V_13 [ V_7 ] = F_6 () ;
return V_6 ;
}
static unsigned long F_7 ( const char * V_14 )
{
unsigned long V_15 , V_16 ;
char * V_17 ;
V_15 = strtoul ( V_14 , & V_17 , 10 ) ;
switch ( * V_17 ) {
case 'K' : case 'k' :
V_15 <<= 10 ;
break;
case 'M' : case 'm' :
V_15 <<= 20 ;
break;
default:
break;
}
if ( V_15 > V_18 ) {
F_3 ( L_4 ) ;
goto error;
} else if ( V_15 < V_19 ) {
F_3 ( L_5 ) ;
goto error;
}
V_16 = V_15 & ( V_20 - 1 ) ;
V_15 = V_15 - V_16 ;
return V_15 ;
error:
return 0 ;
}
static void F_8 ( char const * V_21 )
{
F_3 ( L_6 , V_21 ) ;
}
static const char * F_9 ( int V_22 , bool V_23 )
{
int V_24 ;
char * V_25 ;
V_25 = F_5 ( V_26 ) ;
if ( V_25 == NULL ) {
F_3 ( L_7 ) ;
goto error;
}
if ( V_23 )
V_24 = snprintf ( V_25 , V_26 , V_27 , V_22 ) ;
else
V_24 = snprintf ( V_25 , V_26 , V_28 , V_22 ) ;
if ( V_24 <= 0 ) {
F_3 ( L_8 ,
V_23 ? L_9 : L_10 , V_22 , V_24 ) ;
goto error;
}
return V_25 ;
error:
free ( V_25 ) ;
return NULL ;
}
static const char * F_10 ( int V_22 )
{
return F_9 ( V_22 , false ) ;
}
static const char * F_11 ( int V_22 )
{
return F_9 ( V_22 , true ) ;
}
static void * F_12 ( struct V_5 * V_6 )
{
int V_29 ;
const char * V_30 = NULL ;
const char * V_31 = NULL ;
for ( V_29 = 0 ; V_29 < V_6 -> V_11 ; V_29 ++ ) {
V_30 = F_10 ( V_29 ) ;
if ( V_30 == NULL )
goto error;
if ( ! V_6 -> V_10 ) {
V_31 = F_11 ( V_29 ) ;
if ( V_31 == NULL )
goto error;
} else
F_13 ( L_11 ) ;
F_14 ( V_29 , V_30 , V_31 , V_6 -> V_10 ,
V_6 -> V_8 , V_6 -> V_13 [ V_29 ] ) ;
}
V_6 -> V_12 = F_15 ( ( const char * ) V_32 ) ;
return NULL ;
error:
exit ( V_4 ) ;
}
static void * F_16 ( int V_33 , char * V_34 [] , struct V_5 * V_6 )
{
int V_35 ;
unsigned long V_36 ;
while ( ( V_35 = F_17 ( V_33 , V_34 , L_12 ) ) != - 1 ) {
switch ( V_35 ) {
case 'o' :
V_6 -> V_10 = true ;
break;
case 's' :
V_36 = F_7 ( V_37 ) ;
if ( V_36 == 0 )
goto error;
V_6 -> V_8 = V_36 ;
break;
case 'h' :
default:
F_8 ( V_34 [ 0 ] ) ;
goto error;
}
}
F_12 ( V_6 ) ;
return NULL ;
error:
exit ( V_4 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
int V_29 ;
T_1 V_38 [ V_3 ] ;
for ( V_29 = 0 ; V_29 < V_6 -> V_11 ; V_29 ++ )
V_38 [ V_29 ] = F_19 ( V_6 -> V_13 [ V_29 ] ) ;
F_20 ( V_6 -> V_12 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_11 ; V_29 ++ ) {
int V_24 ;
V_24 = F_21 ( V_38 [ V_29 ] , NULL ) ;
if ( V_24 != 0 ) {
F_3 ( L_13 , V_24 , V_29 ) ;
exit ( V_4 ) ;
}
}
}
static void F_22 ( struct V_5 * V_6 )
{
int V_7 ;
F_23 ( V_6 -> V_12 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
F_23 ( V_6 -> V_13 [ V_7 ] -> V_39 ) ;
F_23 ( V_6 -> V_13 [ V_7 ] -> V_40 ) ;
F_23 ( V_6 -> V_13 [ V_7 ] -> V_41 ) ;
F_23 ( V_6 -> V_13 [ V_7 ] -> V_42 ) ;
free ( V_6 -> V_13 [ V_7 ] ) ;
}
free ( V_6 ) ;
}
int main ( int V_33 , char * V_34 [] )
{
struct V_5 * V_6 = NULL ;
V_6 = F_4 () ;
F_16 ( V_33 , V_34 , V_6 ) ;
F_18 ( V_6 ) ;
F_22 ( V_6 ) ;
return 0 ;
}
