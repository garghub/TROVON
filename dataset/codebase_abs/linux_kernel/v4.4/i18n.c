char * F_1 ( enum V_1 V_2 )
{
char * V_3 ;
V_3 = V_4 [ V_2 ] ;
return V_3 ;
}
static char * F_2 ( char * V_5 )
{
int V_6 = 0 ;
char * V_7 = V_5 ;
while ( ( V_7 != NULL ) && ! V_6 ) {
V_7 = strchr ( V_7 , '%' ) ;
if ( V_7 != NULL ) {
while ( ( V_7 [ 0 ] == '%' )
&& ( V_7 [ 1 ] == '%' ) )
V_7 += 2 ;
if ( * V_7 == '%' )
V_6 = 1 ;
else if ( * V_7 == '\0' )
V_7 = NULL ;
}
}
return V_7 ;
}
static char * F_3 ( char * V_5 )
{
while ( ( * V_5 != '\0' ) && strchr ( L_1 , * V_5 ) )
V_5 ++ ;
return V_5 ;
}
static char * F_4 ( char * V_5 )
{
while ( isdigit ( * V_5 ) )
V_5 ++ ;
if ( * V_5 == '.' ) {
V_5 ++ ;
while ( isdigit ( * V_5 ) )
V_5 ++ ;
}
return V_5 ;
}
static char * F_5 ( char * V_5 )
{
if ( ( V_5 [ 0 ] == 'l' ) && ( V_5 [ 1 ] == 'd' ) )
V_5 += 2 ;
else if ( ( * V_5 != '\0' ) && strchr ( L_2 , * V_5 ) )
V_5 ++ ;
return V_5 ;
}
static char * F_6 ( char * V_5 )
{
V_5 ++ ;
V_5 = F_3 ( V_5 ) ;
V_5 = F_4 ( V_5 ) ;
V_5 = F_5 ( V_5 ) ;
return V_5 ;
}
static int F_7 ( char * * V_8 , char * * V_9 )
{
int V_10 = 0 ;
char * V_11 = F_6 ( * V_8 ) ;
char * V_12 = F_6 ( * V_9 ) ;
T_1 V_13 = V_11 - * V_8 ;
T_1 V_14 = V_12 - * V_9 ;
if ( ( V_13 == V_14 ) && ! memcmp ( * V_8 , * V_9 , V_13 ) )
V_10 = 1 ;
* V_8 = V_11 ;
* V_9 = V_12 ;
return V_10 ;
}
static int F_8 ( char * V_15 , char * V_16 )
{
int V_17 = 1 ;
int V_18 = 1 ;
char * V_19 = V_15 ;
char * V_20 = V_16 ;
while ( V_18 && V_17 ) {
V_19 = F_2 ( V_19 ) ;
V_20 = F_2 ( V_20 ) ;
if ( V_19 && V_20 ) {
V_17 = F_7 ( & V_19 , & V_20 ) ;
} else {
V_18 = 0 ;
if ( V_19 || V_20 )
V_17 = 0 ;
}
}
return V_17 ;
}
T_2 F_9 ( enum V_1 V_2 , char * V_21 , T_1 V_22 )
{
int V_23 = 0 ;
char * V_24 = NULL ;
unsigned long V_25 ;
if ( ( V_2 >= V_26 ) && ( V_2 < V_27 ) ) {
V_24 = F_10 ( V_22 + 1 , V_28 ) ;
if ( V_24 ) {
memcpy ( V_24 , V_21 , V_22 ) ;
V_24 [ V_22 ] = '\0' ;
if ( ( V_2 >= V_29
&& V_2 <= V_30 )
&& ! F_8 ( V_31 [ V_2 ] ,
V_24 ) ) {
F_11 ( V_24 ) ;
return - V_32 ;
}
F_12 ( & V_33 . V_34 , V_25 ) ;
if ( V_4 [ V_2 ] != V_31 [ V_2 ] )
F_11 ( V_4 [ V_2 ] ) ;
V_4 [ V_2 ] = V_24 ;
F_13 ( & V_33 . V_34 , V_25 ) ;
} else {
V_23 = - V_35 ;
}
} else {
V_23 = - V_32 ;
}
return V_23 ;
}
struct V_36 * F_14 ( const char * V_37 )
{
struct V_36 * V_38 = NULL ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
if ( ! strcmp ( V_41 [ V_39 ] . V_42 , V_37 ) ) {
V_38 = & V_41 [ V_39 ] ;
break;
}
}
return V_38 ;
}
void F_15 ( struct V_36 * V_38 )
{
unsigned long V_25 ;
enum V_1 V_39 ;
F_12 ( & V_33 . V_34 , V_25 ) ;
for ( V_39 = V_38 -> V_43 ; V_39 <= V_38 -> V_44 ; V_39 ++ ) {
if ( V_4 [ V_39 ] != V_31 [ V_39 ] )
F_11 ( V_4 [ V_39 ] ) ;
V_4 [ V_39 ] = V_31 [ V_39 ] ;
}
F_13 ( & V_33 . V_34 , V_25 ) ;
}
void F_16 ( void )
{
memcpy ( V_4 , V_31 ,
sizeof( V_31 ) ) ;
}
void F_17 ( void )
{
enum V_1 V_2 ;
unsigned long V_25 ;
F_12 ( & V_33 . V_34 , V_25 ) ;
for ( V_2 = V_26 ; V_2 < V_27 ; V_2 ++ ) {
if ( V_4 [ V_2 ] != V_31 [ V_2 ] ) {
F_11 ( V_4 [ V_2 ] ) ;
V_4 [ V_2 ] = V_31 [ V_2 ] ;
}
}
F_13 ( & V_33 . V_34 , V_25 ) ;
}
