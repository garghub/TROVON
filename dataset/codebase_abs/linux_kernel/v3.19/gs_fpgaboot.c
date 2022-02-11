static void F_1 ( char * V_1 , char * V_2 , int * V_3 , int V_4 )
{
memcpy ( V_2 , V_1 + * V_3 , V_4 ) ;
* V_3 += V_4 ;
}
static void F_2 ( char * V_1 , char * V_2 , int * V_3 )
{
char V_5 [ 64 ] ;
T_1 V_6 ;
F_1 ( V_1 , V_5 , V_3 , 1 ) ;
F_1 ( V_1 , V_5 , V_3 , 2 ) ;
V_6 = V_5 [ 0 ] << 8 | V_5 [ 1 ] ;
F_1 ( V_1 , V_2 , V_3 , V_6 ) ;
V_2 [ V_6 ] = '\0' ;
}
static int F_3 ( char * V_1 , int * V_7 , int * V_3 )
{
char V_5 [ 64 ] ;
F_1 ( V_1 , V_5 , V_3 , 1 ) ;
if ( V_5 [ 0 ] != 'e' ) {
F_4 ( L_1 , V_5 [ 0 ] ) ;
return - 1 ;
}
F_1 ( V_1 , V_5 , V_3 , 4 ) ;
* V_7 = V_5 [ 0 ] << 24 | V_5 [ 1 ] << 16 |
V_5 [ 2 ] << 8 | V_5 [ 3 ] ;
return 0 ;
}
static int F_5 ( char * V_1 , int * V_3 )
{
char V_2 [ 13 ] ;
int V_8 ;
F_1 ( V_1 , V_2 , V_3 , 13 ) ;
V_8 = memcmp ( V_2 , V_9 , 13 ) ;
if ( V_8 ) {
F_4 ( L_2 ) ;
return - 1 ;
}
F_6 ( L_3 ) ;
* V_3 = 13 ;
return 0 ;
}
static enum V_10 F_7 ( struct V_11 * V_12 )
{
return V_13 ;
}
static void F_8 ( struct V_11 * V_12 )
{
F_6 ( L_4 , V_12 -> V_14 ) ;
F_6 ( L_5 , V_12 -> V_15 ) ;
F_6 ( L_6 , V_12 -> V_16 ) ;
F_6 ( L_7 , V_12 -> time ) ;
F_6 ( L_8 , V_12 -> V_7 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
char * V_1 ;
int V_3 ;
V_3 = 0 ;
V_1 = ( char * ) V_12 -> V_17 -> V_18 ;
F_5 ( V_1 , & V_3 ) ;
F_2 ( V_1 , V_12 -> V_14 , & V_3 ) ;
F_2 ( V_1 , V_12 -> V_15 , & V_3 ) ;
F_2 ( V_1 , V_12 -> V_16 , & V_3 ) ;
F_2 ( V_1 , V_12 -> time , & V_3 ) ;
F_3 ( V_1 , & V_12 -> V_7 , & V_3 ) ;
V_12 -> V_19 = V_1 + V_3 ;
}
static int F_10 ( struct V_11 * V_12 )
{
int V_20 ;
V_20 = F_7 ( V_12 ) ;
switch ( V_20 ) {
case V_13 :
F_6 ( L_9 ) ;
F_9 ( V_12 ) ;
break;
default:
F_4 ( L_10 ) ;
return - 1 ;
}
F_8 ( V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , char * V_21 )
{
int V_22 ;
F_6 ( L_11 , V_21 ) ;
V_22 = F_12 ( & V_12 -> V_17 , V_21 , & V_23 -> V_24 ) ;
if ( V_22 != 0 ) {
F_4 ( L_12 , V_21 ) ;
return V_22 ;
}
return 0 ;
}
static int F_13 ( struct V_11 * V_12 , enum V_25 V_26 )
{
char * V_1 ;
int V_27 , V_28 , V_29 ;
V_29 = 0 ;
V_1 = ( char * ) V_12 -> V_19 ;
V_27 = V_12 -> V_7 ;
#ifdef F_14
F_15 ( L_13 , V_30 ,
V_1 , 0x100 ) ;
#endif
if ( ! F_16 ( V_26 ) ) {
F_4 ( L_14 ,
V_26 ) ;
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
F_6 ( L_15 ) ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 += V_26 )
F_22 ( V_26 , V_1 + V_28 ) ;
F_6 ( L_16 ) ;
if ( F_21 () == 0 ) {
F_4 ( L_17 ) ;
return - 1 ;
}
while ( F_23 () == 0 ) {
if ( V_29 ++ > V_31 ) {
F_4 ( L_18 , F_21 () ) ;
break;
}
}
if ( V_29 > V_31 ) {
F_4 ( L_19 ) ;
return - 1 ;
}
F_6 ( L_20 ) ;
F_24 ( 8 ) ;
return 0 ;
}
static int F_25 ( struct V_11 * V_12 )
{
F_26 ( V_12 -> V_17 ) ;
F_6 ( L_21 ) ;
return 0 ;
}
static int F_27 ( struct V_11 * V_12 )
{
F_6 ( L_22 ) ;
V_12 -> V_32 = V_33 ;
F_6 ( L_23 ) ;
return 0 ;
}
static int F_28 ( void )
{
V_23 = F_29 ( L_24 , - 1 ,
NULL , 0 ) ;
return F_30 ( V_23 ) ;
}
static void F_31 ( void )
{
F_32 ( V_23 ) ;
}
static int F_33 ( void )
{
int V_22 ;
struct V_11 * V_12 ;
V_12 = F_34 ( sizeof( struct V_11 ) , V_34 ) ;
if ( ! V_12 )
return - V_35 ;
V_22 = F_11 ( V_12 , V_36 ) ;
if ( V_22 ) {
F_4 ( L_25 ) ;
goto V_37;
}
V_22 = F_10 ( V_12 ) ;
if ( V_22 ) {
F_4 ( L_26 ) ;
goto V_38;
}
V_22 = F_27 ( V_12 ) ;
if ( V_22 ) {
F_4 ( L_27 ) ;
goto V_38;
}
V_22 = F_13 ( V_12 , V_39 ) ;
if ( V_22 ) {
F_4 ( L_28 ) ;
goto V_38;
}
V_22 = F_25 ( V_12 ) ;
if ( V_22 ) {
F_4 ( L_29 ) ;
goto V_37;
}
F_35 ( V_12 ) ;
return 0 ;
V_38:
V_22 = F_25 ( V_12 ) ;
if ( V_22 )
F_4 ( L_29 ) ;
V_37:
F_35 ( V_12 ) ;
return - 1 ;
}
static int T_2 F_36 ( void )
{
int V_22 ;
F_6 ( L_30 ) ;
F_6 ( L_31 , V_36 ) ;
V_22 = F_28 () ;
if ( V_22 ) {
F_4 ( L_32 ) ;
return V_22 ;
}
V_22 = F_37 () ;
if ( V_22 ) {
F_4 ( L_33 ) ;
goto V_40;
}
V_22 = F_33 () ;
if ( V_22 ) {
F_4 ( L_34 ) ;
goto V_40;
}
F_6 ( L_35 ) ;
return 0 ;
V_40:
F_31 () ;
return V_22 ;
}
static void T_3 F_38 ( void )
{
F_31 () ;
F_6 ( L_36 ) ;
}
