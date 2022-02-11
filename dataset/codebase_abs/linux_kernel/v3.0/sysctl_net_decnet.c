static void F_1 ( char * V_1 )
{
for(; ; ) {
switch( * V_1 ) {
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
static int F_6 ( T_3 * V_5 , int V_6 ,
void T_4 * V_7 ,
T_5 * V_8 , T_6 * V_9 )
{
char V_2 [ V_10 ] ;
T_5 V_11 ;
T_1 V_12 ;
if ( ! * V_8 || ( * V_9 && ! V_6 ) ) {
* V_8 = 0 ;
return 0 ;
}
if ( V_6 ) {
V_11 = ( * V_8 < V_10 ) ? * V_8 : ( V_10 - 1 ) ;
if ( F_7 ( V_2 , V_7 , V_11 ) )
return - V_13 ;
V_2 [ V_11 ] = 0 ;
F_1 ( V_2 ) ;
if ( F_2 ( & V_12 , V_2 ) )
return - V_14 ;
F_8 () ;
V_15 = V_12 ;
F_9 () ;
* V_9 += V_11 ;
return 0 ;
}
F_10 ( F_11 ( V_15 ) , V_2 ) ;
V_11 = strlen ( V_2 ) ;
V_2 [ V_11 ++ ] = '\n' ;
if ( V_11 > * V_8 ) V_11 = * V_8 ;
if ( F_12 ( V_7 , V_2 , V_11 ) )
return - V_13 ;
* V_8 = V_11 ;
* V_9 += V_11 ;
return 0 ;
}
static int F_13 ( T_3 * V_5 , int V_6 ,
void T_4 * V_7 ,
T_5 * V_8 , T_6 * V_9 )
{
T_5 V_11 ;
struct V_16 * V_17 ;
char V_18 [ 17 ] ;
if ( ! * V_8 || ( * V_9 && ! V_6 ) ) {
* V_8 = 0 ;
return 0 ;
}
if ( V_6 ) {
if ( * V_8 > 16 )
return - V_19 ;
if ( F_7 ( V_18 , V_7 , * V_8 ) )
return - V_13 ;
V_18 [ * V_8 ] = 0 ;
F_1 ( V_18 ) ;
V_17 = F_14 ( & V_20 , V_18 ) ;
if ( V_17 == NULL )
return - V_21 ;
if ( V_17 -> V_22 == NULL ) {
F_15 ( V_17 ) ;
return - V_21 ;
}
if ( F_16 ( V_17 , 1 ) ) {
F_15 ( V_17 ) ;
return - V_21 ;
}
* V_9 += * V_8 ;
return 0 ;
}
V_17 = F_17 () ;
if ( V_17 == NULL ) {
* V_8 = 0 ;
return 0 ;
}
strcpy ( V_18 , V_17 -> V_23 ) ;
F_15 ( V_17 ) ;
V_11 = strlen ( V_18 ) ;
V_18 [ V_11 ++ ] = '\n' ;
if ( V_11 > * V_8 ) V_11 = * V_8 ;
if ( F_12 ( V_7 , V_18 , V_11 ) )
return - V_13 ;
* V_8 = V_11 ;
* V_9 += V_11 ;
return 0 ;
}
void F_18 ( void )
{
V_24 = F_19 ( V_25 , V_26 ) ;
}
void F_20 ( void )
{
F_21 ( V_24 ) ;
}
void F_20 ( void )
{
}
void F_18 ( void )
{
}
