static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 = V_3 << 27 , V_4 = V_5 << 27 ;
for (; V_2 >= V_3 ; V_2 >>= 1 , V_4 >>= 1 )
if ( V_1 & V_2 )
V_1 ^= V_4 ;
return V_1 & ( V_6 - 1 ) ;
}
const char * F_2 ( T_1 V_7 )
{
struct V_8 * V_9 ;
V_9 = V_10 [ F_1 ( V_7 ) ] ;
for (; V_9 ; V_9 = V_9 -> V_11 )
if ( V_9 -> V_7 == V_7 )
return V_9 -> V_12 ;
return NULL ;
}
const char * F_3 ( T_1 V_7 , T_1 V_13 )
{
struct V_14 * V_15 ;
V_15 = V_16 [ F_1 ( ( V_7 << 16 ) | V_13 ) ] ;
for (; V_15 ; V_15 = V_15 -> V_11 )
if ( V_15 -> V_7 == V_7 && V_15 -> V_13 == V_13 )
return V_15 -> V_12 ;
return NULL ;
}
const char * F_4 ( T_2 V_17 )
{
struct V_18 * V_19 ;
V_19 = V_20 [ F_1 ( V_17 ) ] ;
for (; V_19 ; V_19 = V_19 -> V_11 )
if ( V_19 -> V_17 == V_17 )
return V_19 -> V_12 ;
return NULL ;
}
const char * F_5 ( T_2 V_17 , T_2 V_21 )
{
struct V_22 * V_23 ;
V_23 = V_24 [ F_1 ( ( V_17 << 8 ) | V_21 ) ] ;
for (; V_23 ; V_23 = V_23 -> V_11 )
if ( V_23 -> V_17 == V_17 && V_23 -> V_21 == V_21 )
return V_23 -> V_12 ;
return NULL ;
}
const char * F_6 ( T_2 V_17 , T_2 V_21 ,
T_2 V_25 )
{
struct V_26 * V_15 ;
V_15 = V_27 [ F_1 ( ( V_17 << 16 ) | ( V_21 << 8 )
| V_25 ) ] ;
for (; V_15 ; V_15 = V_15 -> V_11 )
if ( V_15 -> V_17 == V_17 && V_15 -> V_21 == V_21 &&
V_15 -> V_25 == V_25 )
return V_15 -> V_12 ;
return NULL ;
}
static void * F_7 ( T_3 V_28 )
{
struct V_29 * V_15 ;
V_15 = calloc ( 1 , sizeof( struct V_29 ) ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_30 = calloc ( 1 , V_28 ) ;
if ( ! V_15 -> V_30 ) {
free ( V_15 ) ;
return NULL ;
}
V_15 -> V_11 = V_31 ;
V_31 = V_15 ;
return V_15 -> V_30 ;
}
void F_8 ( void )
{
struct V_29 * V_29 ;
if ( ! V_31 )
return;
for ( V_29 = V_31 ; V_29 != NULL ; ) {
struct V_29 * V_32 ;
if ( V_29 -> V_30 )
free ( V_29 -> V_30 ) ;
V_32 = V_29 ;
V_29 = V_29 -> V_11 ;
free ( V_32 ) ;
}
}
static int F_9 ( const char * V_12 , T_1 V_7 )
{
struct V_8 * V_9 ;
unsigned int V_33 = F_1 ( V_7 ) ;
V_9 = V_10 [ V_33 ] ;
for (; V_9 ; V_9 = V_9 -> V_11 )
if ( V_9 -> V_7 == V_7 )
return - 1 ;
V_9 = F_7 ( sizeof( struct V_8 ) + strlen ( V_12 ) ) ;
if ( ! V_9 )
return - 1 ;
strcpy ( V_9 -> V_12 , V_12 ) ;
V_9 -> V_7 = V_7 ;
V_9 -> V_11 = V_10 [ V_33 ] ;
V_10 [ V_33 ] = V_9 ;
return 0 ;
}
static int F_10 ( const char * V_12 , T_1 V_7 ,
T_1 V_13 )
{
struct V_14 * V_15 ;
unsigned int V_33 = F_1 ( ( V_7 << 16 ) | V_13 ) ;
V_15 = V_16 [ V_33 ] ;
for (; V_15 ; V_15 = V_15 -> V_11 )
if ( V_15 -> V_7 == V_7 && V_15 -> V_13 == V_13 )
return - 1 ;
V_15 = F_7 ( sizeof( struct V_14 ) + strlen ( V_12 ) ) ;
if ( ! V_15 )
return - 1 ;
strcpy ( V_15 -> V_12 , V_12 ) ;
V_15 -> V_7 = V_7 ;
V_15 -> V_13 = V_13 ;
V_15 -> V_11 = V_16 [ V_33 ] ;
V_16 [ V_33 ] = V_15 ;
return 0 ;
}
static int F_11 ( const char * V_12 , T_2 V_17 )
{
struct V_18 * V_19 ;
unsigned int V_33 = F_1 ( V_17 ) ;
V_19 = V_20 [ V_33 ] ;
for (; V_19 ; V_19 = V_19 -> V_11 )
if ( V_19 -> V_17 == V_17 )
return - 1 ;
V_19 = F_7 ( sizeof( struct V_18 ) + strlen ( V_12 ) ) ;
if ( ! V_19 )
return - 1 ;
strcpy ( V_19 -> V_12 , V_12 ) ;
V_19 -> V_17 = V_17 ;
V_19 -> V_11 = V_20 [ V_33 ] ;
V_20 [ V_33 ] = V_19 ;
return 0 ;
}
static int F_12 ( const char * V_12 , T_2 V_17 , T_2 V_21 )
{
struct V_22 * V_23 ;
unsigned int V_33 = F_1 ( ( V_17 << 8 ) | V_21 ) ;
V_23 = V_24 [ V_33 ] ;
for (; V_23 ; V_23 = V_23 -> V_11 )
if ( V_23 -> V_17 == V_17 && V_23 -> V_21 == V_21 )
return - 1 ;
V_23 = F_7 ( sizeof( struct V_22 ) + strlen ( V_12 ) ) ;
if ( ! V_23 )
return - 1 ;
strcpy ( V_23 -> V_12 , V_12 ) ;
V_23 -> V_17 = V_17 ;
V_23 -> V_21 = V_21 ;
V_23 -> V_11 = V_24 [ V_33 ] ;
V_24 [ V_33 ] = V_23 ;
return 0 ;
}
static int F_13 ( const char * V_12 , T_2 V_17 , T_2 V_21 ,
T_2 V_25 )
{
struct V_26 * V_15 ;
unsigned int V_33 = F_1 ( ( V_17 << 16 ) | ( V_21 << 8 )
| V_25 ) ;
V_15 = V_27 [ V_33 ] ;
for (; V_15 ; V_15 = V_15 -> V_11 )
if ( V_15 -> V_17 == V_17 && V_15 -> V_21 == V_21
&& V_15 -> V_25 == V_25 )
return - 1 ;
V_15 = F_7 ( sizeof( struct V_26 ) + strlen ( V_12 ) ) ;
if ( ! V_15 )
return - 1 ;
strcpy ( V_15 -> V_12 , V_12 ) ;
V_15 -> V_17 = V_17 ;
V_15 -> V_21 = V_21 ;
V_15 -> V_25 = V_25 ;
V_15 -> V_11 = V_27 [ V_33 ] ;
V_27 [ V_33 ] = V_15 ;
return 0 ;
}
static void F_14 ( T_4 * V_34 )
{
char V_35 [ 512 ] , * V_36 ;
unsigned int V_37 = 0 ;
int V_38 = - 1 ;
int V_39 = - 1 ;
int V_40 = - 1 ;
int V_41 = - 1 ;
int V_42 = - 1 ;
unsigned int V_43 ;
while ( fgets ( V_35 , sizeof( V_35 ) , V_34 ) ) {
V_37 ++ ;
V_36 = strchr ( V_35 , '\r' ) ;
if ( V_36 )
* V_36 = 0 ;
V_36 = strchr ( V_35 , '\n' ) ;
if ( V_36 )
* V_36 = 0 ;
if ( V_35 [ 0 ] == '#' || ! V_35 [ 0 ] )
continue;
V_36 = V_35 ;
if ( V_35 [ 0 ] == 'P' && V_35 [ 1 ] == 'H' && V_35 [ 2 ] == 'Y' &&
V_35 [ 3 ] == 'S' && V_35 [ 4 ] == 'D' &&
V_35 [ 5 ] == 'E' && V_35 [ 6 ] == 'S' &&
V_35 [ 7 ] == ' ' ) {
continue;
}
if ( V_35 [ 0 ] == 'P' && V_35 [ 1 ] == 'H' &&
V_35 [ 2 ] == 'Y' && V_35 [ 3 ] == ' ' ) {
continue;
}
if ( V_35 [ 0 ] == 'B' && V_35 [ 1 ] == 'I' && V_35 [ 2 ] == 'A' &&
V_35 [ 3 ] == 'S' && V_35 [ 4 ] == ' ' ) {
continue;
}
if ( V_35 [ 0 ] == 'L' && V_35 [ 1 ] == ' ' ) {
V_41 = V_39 = V_38 = V_40 = - 1 ;
V_42 = 1 ;
continue;
}
if ( V_35 [ 0 ] == 'C' && V_35 [ 1 ] == ' ' ) {
V_36 = V_35 + 2 ;
while ( isspace ( * V_36 ) )
V_36 ++ ;
if ( ! isxdigit ( * V_36 ) ) {
F_15 ( L_1 , V_37 ) ;
continue;
}
V_43 = strtoul ( V_36 , & V_36 , 16 ) ;
while ( isspace ( * V_36 ) )
V_36 ++ ;
if ( ! * V_36 ) {
F_15 ( L_1 , V_37 ) ;
continue;
}
if ( F_11 ( V_36 , V_43 ) )
F_15 ( L_2 ,
V_37 , V_43 , V_36 ) ;
F_16 ( L_3 , V_37 , V_43 , V_36 ) ;
V_41 = V_42 = V_38 = V_40 = - 1 ;
V_39 = V_43 ;
continue;
}
if ( V_35 [ 0 ] == 'A' && V_35 [ 1 ] == 'T' && isspace ( V_35 [ 2 ] ) ) {
continue;
}
if ( V_35 [ 0 ] == 'H' && V_35 [ 1 ] == 'C' && V_35 [ 2 ] == 'C'
&& isspace ( V_35 [ 3 ] ) ) {
continue;
}
if ( isxdigit ( * V_36 ) ) {
V_43 = strtoul ( V_36 , & V_36 , 16 ) ;
while ( isspace ( * V_36 ) )
V_36 ++ ;
if ( ! * V_36 ) {
F_15 ( L_4 , V_37 ) ;
continue;
}
if ( F_9 ( V_36 , V_43 ) )
F_15 ( L_5 ,
V_37 , V_43 , V_36 ) ;
F_16 ( L_6 , V_37 , V_43 , V_36 ) ;
V_38 = V_43 ;
V_41 = V_42 = V_39 = V_40 = - 1 ;
continue;
}
if ( V_35 [ 0 ] == '\t' && isxdigit ( V_35 [ 1 ] ) ) {
V_43 = strtoul ( V_35 + 1 , & V_36 , 16 ) ;
while ( isspace ( * V_36 ) )
V_36 ++ ;
if ( ! * V_36 ) {
F_15 ( L_7 ,
V_37 ) ;
continue;
}
if ( V_38 != - 1 ) {
if ( F_10 ( V_36 , V_38 , V_43 ) )
F_15 ( L_8 ,
V_37 , V_38 , V_43 , V_36 ) ;
F_16 ( L_9 , V_37 ,
V_38 , V_43 , V_36 ) ;
continue;
}
if ( V_39 != - 1 ) {
if ( F_12 ( V_36 , V_39 , V_43 ) )
F_15 ( L_10 ,
V_37 , V_39 , V_43 , V_36 ) ;
F_16 ( L_11 , V_37 ,
V_39 , V_43 , V_36 ) ;
V_40 = V_43 ;
continue;
}
if ( V_41 != - 1 ) {
continue;
}
if ( V_42 != - 1 ) {
continue;
}
F_15 ( L_12 ,
V_37 ) ;
continue;
}
if ( V_35 [ 0 ] == '\t' && V_35 [ 1 ] == '\t' && isxdigit ( V_35 [ 2 ] ) ) {
V_43 = strtoul ( V_35 + 2 , & V_36 , 16 ) ;
while ( isspace ( * V_36 ) )
V_36 ++ ;
if ( ! * V_36 ) {
F_15 ( L_13 ,
V_37 ) ;
continue;
}
if ( V_39 != - 1 && V_40 != - 1 ) {
if ( F_13 ( V_36 , V_39 , V_40 ,
V_43 ) )
F_15 ( L_14 ,
V_37 , V_39 , V_40 ,
V_43 , V_36 ) ;
F_16 ( L_15 ,
V_37 , V_39 , V_40 , V_43 , V_36 ) ;
continue;
}
F_15 ( L_16 ,
V_37 ) ;
continue;
}
if ( V_35 [ 0 ] == 'H' && V_35 [ 1 ] == 'I' &&
V_35 [ 2 ] == 'D' && V_35 [ 3 ] == ' ' ) {
continue;
}
if ( V_35 [ 0 ] == 'H' && V_35 [ 1 ] == 'U' &&
V_35 [ 2 ] == 'T' && V_35 [ 3 ] == ' ' ) {
V_42 = V_39 = V_38 = V_40 = - 1 ;
V_41 = 1 ;
continue;
}
if ( V_35 [ 0 ] == 'R' && V_35 [ 1 ] == ' ' )
continue;
if ( V_35 [ 0 ] == 'V' && V_35 [ 1 ] == 'T' )
continue;
F_15 ( L_17 , V_37 ) ;
}
}
int F_17 ( char * V_44 )
{
T_4 * V_34 ;
V_34 = fopen ( V_44 , L_18 ) ;
if ( ! V_34 )
return V_45 ;
F_14 ( V_34 ) ;
fclose ( V_34 ) ;
return 0 ;
}
