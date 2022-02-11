char * F_1 ( enum V_1 V_2 )
{
return V_3 [ V_2 ] ;
}
static char * F_2 ( char * V_4 )
{
int V_5 = 0 ;
char * V_6 = V_4 ;
while ( ( V_6 != NULL ) && ! V_5 ) {
V_6 = strchr ( V_6 , '%' ) ;
if ( V_6 != NULL ) {
while ( ( V_6 [ 0 ] == '%' )
&& ( V_6 [ 1 ] == '%' ) )
V_6 += 2 ;
if ( * V_6 == '%' )
V_5 = 1 ;
else if ( * V_6 == '\0' )
V_6 = NULL ;
}
}
return V_6 ;
}
static char * F_3 ( char * V_4 )
{
while ( ( * V_4 != '\0' ) && strchr ( L_1 , * V_4 ) )
V_4 ++ ;
return V_4 ;
}
static char * F_4 ( char * V_4 )
{
while ( isdigit ( * V_4 ) )
V_4 ++ ;
if ( * V_4 == '.' ) {
V_4 ++ ;
while ( isdigit ( * V_4 ) )
V_4 ++ ;
}
return V_4 ;
}
static char * F_5 ( char * V_4 )
{
if ( ( V_4 [ 0 ] == 'l' ) && ( V_4 [ 1 ] == 'd' ) )
V_4 += 2 ;
else if ( ( * V_4 != '\0' ) && strchr ( L_2 , * V_4 ) )
V_4 ++ ;
return V_4 ;
}
static char * F_6 ( char * V_4 )
{
V_4 ++ ;
V_4 = F_3 ( V_4 ) ;
V_4 = F_4 ( V_4 ) ;
V_4 = F_5 ( V_4 ) ;
return V_4 ;
}
static int F_7 ( char * * V_7 , char * * V_8 )
{
int V_9 = 0 ;
char * V_10 = F_6 ( * V_7 ) ;
char * V_11 = F_6 ( * V_8 ) ;
T_1 V_12 = V_10 - * V_7 ;
T_1 V_13 = V_11 - * V_8 ;
if ( ( V_12 == V_13 ) && ! memcmp ( * V_7 , * V_8 , V_12 ) )
V_9 = 1 ;
* V_7 = V_10 ;
* V_8 = V_11 ;
return V_9 ;
}
static int F_8 ( char * V_14 , char * V_15 )
{
int V_16 = 1 ;
int V_17 = 1 ;
char * V_18 = V_14 ;
char * V_19 = V_15 ;
while ( V_17 && V_16 ) {
V_18 = F_2 ( V_18 ) ;
V_19 = F_2 ( V_19 ) ;
if ( V_18 && V_19 ) {
V_16 = F_7 ( & V_18 , & V_19 ) ;
} else {
V_17 = 0 ;
if ( V_18 || V_19 )
V_16 = 0 ;
}
}
return V_16 ;
}
T_2 F_9 ( enum V_1 V_2 , char * V_20 , T_1 V_21 )
{
int V_22 = 0 ;
char * V_23 = NULL ;
unsigned long V_24 ;
if ( ( V_2 >= V_25 ) && ( V_2 < V_26 ) ) {
V_23 = F_10 ( V_21 + 1 , V_27 ) ;
if ( V_23 ) {
memcpy ( V_23 , V_20 , V_21 ) ;
V_23 [ V_21 ] = '\0' ;
if ( ( V_2 >= V_28
&& V_2 <= V_29 )
&& ! F_8 ( V_30 [ V_2 ] ,
V_23 ) ) {
F_11 ( V_23 ) ;
return - V_31 ;
}
F_12 ( & V_32 . V_33 , V_24 ) ;
if ( V_3 [ V_2 ] != V_30 [ V_2 ] )
F_11 ( V_3 [ V_2 ] ) ;
V_3 [ V_2 ] = V_23 ;
F_13 ( & V_32 . V_33 , V_24 ) ;
} else {
V_22 = - V_34 ;
}
} else {
V_22 = - V_31 ;
}
return V_22 ;
}
struct V_35 * F_14 ( const char * V_36 )
{
struct V_35 * V_37 = NULL ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
if ( ! strcmp ( V_40 [ V_38 ] . V_41 , V_36 ) ) {
V_37 = & V_40 [ V_38 ] ;
break;
}
}
return V_37 ;
}
void F_15 ( struct V_35 * V_37 )
{
unsigned long V_24 ;
enum V_1 V_38 ;
F_12 ( & V_32 . V_33 , V_24 ) ;
for ( V_38 = V_37 -> V_42 ; V_38 <= V_37 -> V_43 ; V_38 ++ ) {
if ( V_3 [ V_38 ] != V_30 [ V_38 ] )
F_11 ( V_3 [ V_38 ] ) ;
V_3 [ V_38 ] = V_30 [ V_38 ] ;
}
F_13 ( & V_32 . V_33 , V_24 ) ;
}
void F_16 ( void )
{
memcpy ( V_3 , V_30 ,
sizeof( V_30 ) ) ;
}
void F_17 ( void )
{
enum V_1 V_2 ;
unsigned long V_24 ;
F_12 ( & V_32 . V_33 , V_24 ) ;
for ( V_2 = V_25 ; V_2 < V_26 ; V_2 ++ ) {
if ( V_3 [ V_2 ] != V_30 [ V_2 ] ) {
F_11 ( V_3 [ V_2 ] ) ;
V_3 [ V_2 ] = V_30 [ V_2 ] ;
}
}
F_13 ( & V_32 . V_33 , V_24 ) ;
}
