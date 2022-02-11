static void F_1 ( char * V_1 )
{
for(; ; ) {
switch ( * V_1 ) {
case ' ' :
case '\n' :
case '\r' :
case ':' :
* V_1 = 0 ;
case 0 :
return;
}
V_1 ++ ;
}
}
static int F_2 ( T_1 * V_2 , char * V_1 )
{
T_2 V_3 , V_4 ;
while( * V_1 && ! F_3 ( * V_1 ) ) V_1 ++ ;
if ( * V_1 == 0 )
return - 1 ;
V_3 = ( * V_1 ++ - '0' ) ;
if ( F_3 ( * V_1 ) ) {
V_3 *= 10 ;
V_3 += ( * V_1 ++ - '0' ) ;
}
if ( * V_1 ++ != '.' )
return - 1 ;
if ( ! F_3 ( * V_1 ) )
return - 1 ;
V_4 = * V_1 ++ - '0' ;
if ( F_3 ( * V_1 ) ) {
V_4 *= 10 ;
V_4 += ( * V_1 ++ - '0' ) ;
}
if ( F_3 ( * V_1 ) ) {
V_4 *= 10 ;
V_4 += ( * V_1 ++ - '0' ) ;
}
if ( F_3 ( * V_1 ) ) {
V_4 *= 10 ;
V_4 += ( * V_1 ++ - '0' ) ;
}
if ( ( V_4 > 1023 ) || ( V_3 > 63 ) )
return - 1 ;
if ( F_4 ( * V_1 ) )
return - 1 ;
* V_2 = F_5 ( ( V_3 << 10 ) | V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 , int V_7 ,
void T_3 * V_8 ,
T_4 * V_9 , T_5 * V_10 )
{
char V_2 [ V_11 ] ;
T_4 V_12 ;
T_1 V_13 ;
if ( ! * V_9 || ( * V_10 && ! V_7 ) ) {
* V_9 = 0 ;
return 0 ;
}
if ( V_7 ) {
V_12 = ( * V_9 < V_11 ) ? * V_9 : ( V_11 - 1 ) ;
if ( F_7 ( V_2 , V_8 , V_12 ) )
return - V_14 ;
V_2 [ V_12 ] = 0 ;
F_1 ( V_2 ) ;
if ( F_2 ( & V_13 , V_2 ) )
return - V_15 ;
F_8 () ;
V_16 = V_13 ;
F_9 () ;
* V_10 += V_12 ;
return 0 ;
}
F_10 ( F_11 ( V_16 ) , V_2 ) ;
V_12 = strlen ( V_2 ) ;
V_2 [ V_12 ++ ] = '\n' ;
if ( V_12 > * V_9 ) V_12 = * V_9 ;
if ( F_12 ( V_8 , V_2 , V_12 ) )
return - V_14 ;
* V_9 = V_12 ;
* V_10 += V_12 ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , int V_7 ,
void T_3 * V_8 ,
T_4 * V_9 , T_5 * V_10 )
{
T_4 V_12 ;
struct V_17 * V_18 ;
char V_19 [ 17 ] ;
if ( ! * V_9 || ( * V_10 && ! V_7 ) ) {
* V_9 = 0 ;
return 0 ;
}
if ( V_7 ) {
if ( * V_9 > 16 )
return - V_20 ;
if ( F_7 ( V_19 , V_8 , * V_9 ) )
return - V_14 ;
V_19 [ * V_9 ] = 0 ;
F_1 ( V_19 ) ;
V_18 = F_14 ( & V_21 , V_19 ) ;
if ( V_18 == NULL )
return - V_22 ;
if ( V_18 -> V_23 == NULL ) {
F_15 ( V_18 ) ;
return - V_22 ;
}
if ( F_16 ( V_18 , 1 ) ) {
F_15 ( V_18 ) ;
return - V_22 ;
}
* V_10 += * V_9 ;
return 0 ;
}
V_18 = F_17 () ;
if ( V_18 == NULL ) {
* V_9 = 0 ;
return 0 ;
}
strcpy ( V_19 , V_18 -> V_24 ) ;
F_15 ( V_18 ) ;
V_12 = strlen ( V_19 ) ;
V_19 [ V_12 ++ ] = '\n' ;
if ( V_12 > * V_9 ) V_12 = * V_9 ;
if ( F_12 ( V_8 , V_19 , V_12 ) )
return - V_14 ;
* V_9 = V_12 ;
* V_10 += V_12 ;
return 0 ;
}
void F_18 ( void )
{
V_25 = F_19 ( & V_21 , L_1 , V_26 ) ;
}
void F_20 ( void )
{
F_21 ( V_25 ) ;
}
void F_20 ( void )
{
}
void F_18 ( void )
{
}
