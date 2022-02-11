static void F_1 ( T_1 * V_1 , T_1 * V_2 , int * V_3 , int V_4 )
{
memcpy ( V_2 , V_1 + * V_3 , V_4 ) ;
* V_3 += V_4 ;
}
static int F_2 ( T_1 * V_1 , T_1 * V_2 , int V_5 , int * V_3 )
{
T_1 V_6 [ 2 ] ;
T_2 V_7 ;
F_1 ( V_1 , V_6 , V_3 , 1 ) ;
F_1 ( V_1 , V_6 , V_3 , 2 ) ;
V_7 = F_3 ( V_6 ) ;
if ( V_7 >= V_5 ) {
F_4 ( L_1 ) ;
return - V_8 ;
}
F_1 ( V_1 , V_2 , V_3 , V_7 ) ;
V_2 [ V_7 ] = '\0' ;
return 0 ;
}
static int F_5 ( T_1 * V_1 , int * V_9 , int * V_3 )
{
T_1 V_6 [ 4 ] ;
F_1 ( V_1 , V_6 , V_3 , 1 ) ;
if ( V_6 [ 0 ] != 'e' ) {
F_4 ( L_2 , V_6 [ 0 ] ) ;
return - V_8 ;
}
F_1 ( V_1 , V_6 , V_3 , 4 ) ;
* V_9 = F_6 ( V_6 ) ;
return 0 ;
}
static int F_7 ( T_1 * V_1 , int * V_3 )
{
T_1 V_2 [ 13 ] ;
int V_10 ;
F_1 ( V_1 , V_2 , V_3 , 13 ) ;
V_10 = memcmp ( V_2 , V_11 , 13 ) ;
if ( V_10 ) {
F_4 ( L_3 ) ;
return - V_8 ;
}
F_8 ( L_4 ) ;
* V_3 = 13 ;
return 0 ;
}
static enum V_12 F_9 ( void )
{
return V_13 ;
}
static void F_10 ( struct V_14 * V_15 )
{
F_8 ( L_5 , V_15 -> V_16 ) ;
F_8 ( L_6 , V_15 -> V_17 ) ;
F_8 ( L_7 , V_15 -> V_18 ) ;
F_8 ( L_8 , V_15 -> time ) ;
F_8 ( L_9 , V_15 -> V_9 ) ;
}
static int F_11 ( struct V_14 * V_15 )
{
T_1 * V_1 ;
int V_3 ;
int V_19 ;
V_3 = 0 ;
V_1 = ( T_1 * ) V_15 -> V_20 -> V_21 ;
V_19 = F_7 ( V_1 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_2 ( V_1 , V_15 -> V_16 , V_22 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_2 ( V_1 , V_15 -> V_17 , V_22 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_2 ( V_1 , V_15 -> V_18 , V_22 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_2 ( V_1 , V_15 -> time , V_22 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_5 ( V_1 , & V_15 -> V_9 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_15 -> V_23 = V_1 + V_3 ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 )
{
int V_24 ;
int V_19 ;
V_24 = F_9 () ;
switch ( V_24 ) {
case V_13 :
F_8 ( L_10 ) ;
V_19 = F_11 ( V_15 ) ;
if ( V_19 )
return V_19 ;
break;
default:
F_4 ( L_11 ) ;
return - V_8 ;
}
F_10 ( V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 , char * V_25 )
{
int V_19 ;
F_8 ( L_12 , V_25 ) ;
V_19 = F_14 ( & V_15 -> V_20 , V_25 , & V_26 -> V_27 ) ;
if ( V_19 != 0 ) {
F_4 ( L_13 , V_25 ) ;
return V_19 ;
}
return 0 ;
}
static int F_15 ( struct V_14 * V_15 , enum V_28 V_29 )
{
T_1 * V_1 ;
int V_5 , V_30 , V_31 ;
V_31 = 0 ;
V_1 = ( T_1 * ) V_15 -> V_23 ;
V_5 = V_15 -> V_9 ;
#ifdef F_16
F_17 ( L_14 , V_32 ,
V_1 , 0x100 ) ;
#endif
if ( ! F_18 ( V_29 ) ) {
F_4 ( L_15 ,
V_29 ) ;
return - V_8 ;
}
F_19 ( 1 ) ;
F_20 ( 0 ) ;
F_21 ( 0 ) ;
F_19 ( 0 ) ;
F_22 ( 20 ) ;
F_19 ( 1 ) ;
while ( F_23 () == 0 )
;
F_8 ( L_16 ) ;
for ( V_30 = 0 ; V_30 < V_5 ; V_30 += V_29 )
F_24 ( V_29 , V_1 + V_30 ) ;
F_8 ( L_17 ) ;
if ( F_23 () == 0 ) {
F_4 ( L_18 ) ;
return - V_33 ;
}
while ( F_25 () == 0 ) {
if ( V_31 ++ > V_34 ) {
F_4 ( L_19 , F_23 () ) ;
break;
}
}
if ( V_31 > V_34 ) {
F_4 ( L_20 ) ;
return - V_33 ;
}
F_8 ( L_21 ) ;
F_26 ( 8 ) ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 )
{
F_28 ( V_15 -> V_20 ) ;
F_8 ( L_22 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 )
{
F_8 ( L_23 ) ;
V_15 -> V_35 = V_36 ;
F_8 ( L_24 ) ;
return 0 ;
}
static int F_30 ( void )
{
V_26 = F_31 ( L_25 , - 1 ,
NULL , 0 ) ;
return F_32 ( V_26 ) ;
}
static int F_33 ( void )
{
int V_19 ;
struct V_14 * V_15 ;
V_15 = F_34 ( sizeof( * V_15 ) , V_37 ) ;
if ( ! V_15 )
return - V_38 ;
V_19 = F_13 ( V_15 , V_39 ) ;
if ( V_19 ) {
F_4 ( L_26 ) ;
goto V_40;
}
V_19 = F_12 ( V_15 ) ;
if ( V_19 ) {
F_4 ( L_27 ) ;
goto V_41;
}
V_19 = F_29 ( V_15 ) ;
if ( V_19 ) {
F_4 ( L_28 ) ;
goto V_41;
}
V_19 = F_15 ( V_15 , V_42 ) ;
if ( V_19 ) {
F_4 ( L_29 ) ;
goto V_41;
}
V_19 = F_27 ( V_15 ) ;
if ( V_19 ) {
F_4 ( L_30 ) ;
goto V_40;
}
F_35 ( V_15 ) ;
return 0 ;
V_41:
V_19 = F_27 ( V_15 ) ;
if ( V_19 )
F_4 ( L_30 ) ;
V_40:
F_35 ( V_15 ) ;
return V_19 ;
}
static int T_3 F_36 ( void )
{
int V_19 ;
F_8 ( L_31 ) ;
F_8 ( L_32 , V_39 ) ;
V_19 = F_30 () ;
if ( V_19 ) {
F_4 ( L_33 ) ;
return V_19 ;
}
V_19 = F_37 () ;
if ( V_19 ) {
F_4 ( L_34 ) ;
goto V_43;
}
V_19 = F_33 () ;
if ( V_19 ) {
F_4 ( L_35 ) ;
goto V_43;
}
F_8 ( L_36 ) ;
return 0 ;
V_43:
F_38 ( V_26 ) ;
return V_19 ;
}
static void T_4 F_39 ( void )
{
F_38 ( V_26 ) ;
F_8 ( L_37 ) ;
}
