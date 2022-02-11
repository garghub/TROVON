static void F_1 ( char * V_1 , void * V_2 , int V_3 )
{
int V_4 ;
unsigned char * V_5 ;
F_2 ( L_1 , V_1 ) ;
V_5 = V_2 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( ( V_4 & 0xf ) == 0 )
F_2 ( V_6 L_2 , V_4 ) ;
F_2 ( L_3 , V_5 [ V_4 ] ) ;
}
F_2 ( L_4 ) ;
}
static void F_3 ( char * V_7 , char * V_8 , int * V_9 , int V_10 )
{
memcpy ( V_8 , V_7 + * V_9 , V_10 ) ;
* V_9 += V_10 ;
}
static void F_4 ( char * V_7 , char * V_8 , int * V_9 )
{
char V_11 [ 64 ] ;
T_1 V_12 ;
F_3 ( V_7 , V_11 , V_9 , 1 ) ;
F_3 ( V_7 , V_11 , V_9 , 2 ) ;
V_12 = V_11 [ 0 ] << 8 | V_11 [ 1 ] ;
F_3 ( V_7 , V_8 , V_9 , V_12 ) ;
V_8 [ V_12 ] = '\0' ;
}
static int F_5 ( char * V_7 , int * V_13 , int * V_9 )
{
char V_11 [ 64 ] ;
F_3 ( V_7 , V_11 , V_9 , 1 ) ;
if ( V_11 [ 0 ] != 'e' ) {
F_6 ( L_5 , V_11 [ 0 ] ) ;
return - 1 ;
}
F_3 ( V_7 , V_11 , V_9 , 4 ) ;
* V_13 = V_11 [ 0 ] << 24 | V_11 [ 1 ] << 16 |
V_11 [ 2 ] << 8 | V_11 [ 3 ] ;
return 0 ;
}
static int F_7 ( char * V_7 , int * V_9 )
{
char V_8 [ 13 ] ;
int V_14 ;
F_3 ( V_7 , V_8 , V_9 , 13 ) ;
V_14 = memcmp ( V_8 , V_15 , 13 ) ;
if ( V_14 ) {
F_6 ( L_6 ) ;
return - 1 ;
}
F_2 ( L_7 ) ;
* V_9 = 13 ;
return 0 ;
}
static enum V_16 F_8 ( struct V_17 * V_18 )
{
return V_19 ;
}
static void F_9 ( struct V_17 * V_18 )
{
F_2 ( L_8 , V_18 -> V_20 ) ;
F_2 ( L_9 , V_18 -> V_21 ) ;
F_2 ( L_10 , V_18 -> V_22 ) ;
F_2 ( L_11 , V_18 -> time ) ;
F_2 ( L_12 , V_18 -> V_13 ) ;
}
static void F_10 ( struct V_17 * V_18 )
{
char * V_7 ;
int V_23 ;
int V_9 ;
V_9 = 0 ;
V_7 = ( char * ) V_18 -> V_24 -> V_25 ;
V_23 = V_18 -> V_24 -> V_23 ;
F_7 ( V_7 , & V_9 ) ;
F_4 ( V_7 , V_18 -> V_20 , & V_9 ) ;
F_4 ( V_7 , V_18 -> V_21 , & V_9 ) ;
F_4 ( V_7 , V_18 -> V_22 , & V_9 ) ;
F_4 ( V_7 , V_18 -> time , & V_9 ) ;
F_5 ( V_7 , & V_18 -> V_13 , & V_9 ) ;
V_18 -> V_26 = V_7 + V_9 ;
}
static int F_11 ( struct V_17 * V_18 )
{
int V_27 ;
V_27 = F_8 ( V_18 ) ;
switch ( V_27 ) {
case V_19 :
F_2 ( L_13 ) ;
F_10 ( V_18 ) ;
break;
default:
F_6 ( L_14 ) ;
return - 1 ;
}
F_9 ( V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , char * V_28 )
{
int V_29 ;
F_2 ( L_15 , V_28 ) ;
V_29 = F_13 ( & V_18 -> V_24 , V_28 , & V_30 -> V_31 ) ;
if ( V_29 != 0 ) {
F_6 ( L_16 , V_28 ) ;
return V_29 ;
}
return 0 ;
}
static int F_14 ( struct V_17 * V_18 , enum V_32 V_33 )
{
char * V_7 ;
int V_23 , V_4 , V_34 ;
V_34 = 0 ;
V_7 = ( char * ) V_18 -> V_26 ;
V_23 = V_18 -> V_13 ;
#ifdef F_15
F_1 ( L_17 , V_7 , 0x100 ) ;
#endif
if ( ! F_16 ( V_33 ) ) {
F_6 ( L_18 ,
V_33 ) ;
return - 1 ;
}
F_17 ( 1 ) ;
F_18 ( 0 ) ;
F_19 ( 0 ) ;
F_17 ( 0 ) ;
F_20 ( 20 ) ;
F_17 ( 1 ) ;
while ( F_21 () == 0 )
;
F_2 ( L_19 ) ;
for ( V_4 = 0 ; V_4 < V_23 ; V_4 += V_33 )
F_22 ( V_33 , V_7 + V_4 ) ;
F_2 ( L_20 ) ;
if ( F_21 () == 0 ) {
F_6 ( L_21 ) ;
return - 1 ;
}
while ( F_23 () == 0 ) {
if ( V_34 ++ > V_35 ) {
F_6 ( L_22 , F_21 () ) ;
break;
}
}
if ( V_34 > V_35 ) {
F_6 ( L_23 ) ;
return - 1 ;
}
F_2 ( L_24 ) ;
F_24 ( 8 ) ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 )
{
F_26 ( V_18 -> V_24 ) ;
F_2 ( L_25 ) ;
return 0 ;
}
static int F_27 ( struct V_17 * V_18 )
{
F_2 ( L_26 ) ;
V_18 -> V_36 = V_37 ;
F_2 ( L_27 ) ;
return 0 ;
}
static int F_28 ( void )
{
V_30 = F_29 ( L_28 , - 1 ,
NULL , 0 ) ;
return F_30 ( V_30 ) ;
}
static void F_31 ( void )
{
F_32 ( V_30 ) ;
}
static int F_33 ( void )
{
int V_29 ;
struct V_17 * V_18 ;
V_18 = F_34 ( sizeof( struct V_17 ) , V_38 ) ;
if ( V_18 == NULL ) {
F_6 ( L_29 ) ;
goto V_39;
}
V_29 = F_12 ( V_18 , V_28 ) ;
if ( V_29 ) {
F_6 ( L_30 ) ;
goto V_40;
}
V_29 = F_11 ( V_18 ) ;
if ( V_29 ) {
F_6 ( L_31 ) ;
goto V_41;
}
V_29 = F_27 ( V_18 ) ;
if ( V_29 ) {
F_6 ( L_32 ) ;
goto V_41;
}
V_29 = F_14 ( V_18 , V_42 ) ;
if ( V_29 ) {
F_6 ( L_33 ) ;
goto V_41;
}
V_29 = F_25 ( V_18 ) ;
if ( V_29 ) {
F_6 ( L_34 ) ;
goto V_40;
}
F_35 ( V_18 ) ;
return 0 ;
V_41:
V_29 = F_25 ( V_18 ) ;
if ( V_29 )
F_6 ( L_34 ) ;
V_40:
F_35 ( V_18 ) ;
V_39:
return - 1 ;
}
static int T_2 F_36 ( void )
{
int V_29 , V_14 ;
V_14 = - 1 ;
F_2 ( L_35 ) ;
F_2 ( L_36 , V_28 ) ;
V_29 = F_28 () ;
if ( V_29 != 0 ) {
F_6 ( L_37 ) ;
return V_14 ;
}
V_29 = F_37 () ;
if ( V_29 ) {
F_6 ( L_38 ) ;
V_14 = - 1 ;
goto V_43;
}
V_29 = F_33 () ;
if ( V_29 ) {
F_6 ( L_39 ) ;
V_14 = - 1 ;
goto V_43;
}
F_2 ( L_40 ) ;
V_14 = 0 ;
return V_14 ;
V_43:
F_31 () ;
return V_14 ;
}
static void T_3 F_38 ( void )
{
F_31 () ;
F_2 ( L_41 ) ;
}
