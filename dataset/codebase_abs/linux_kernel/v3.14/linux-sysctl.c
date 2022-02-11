int F_1 ( T_1 )
{
int V_1 ;
V_1 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_8 >= V_9 )
V_8 = F_3 ( V_9 / 3 , 1U ) ;
return V_1 ;
}
int F_1 ( T_2 )
{
char V_10 [ 22 ] ;
int V_11 ;
V_12 ;
if ( ! * V_6 || ( * V_7 && ! V_3 ) ) {
* V_6 = 0 ;
return 0 ;
}
if ( V_3 )
return - V_13 ;
V_11 = snprintf ( V_10 , sizeof( V_10 ) , V_14 L_1 , F_4 () ) ;
if ( V_11 > * V_6 )
V_11 = * V_6 ;
V_10 [ V_11 ] = '\0' ;
if ( F_5 ( V_5 , V_10 , V_11 ) )
return - V_15 ;
* V_6 = V_11 ;
* V_7 += * V_6 ;
return 0 ;
}
int F_1 ( T_3 )
{
char V_10 [ 22 ] ;
int V_11 ;
V_12 ;
if ( ! * V_6 || ( * V_7 && ! V_3 ) ) {
* V_6 = 0 ;
return 0 ;
}
if ( V_3 )
return - V_13 ;
V_11 = snprintf ( V_10 , sizeof( V_10 ) , V_14 L_1 , F_6 () ) ;
if ( V_11 > * V_6 )
V_11 = * V_6 ;
V_10 [ V_11 ] = '\0' ;
if ( F_5 ( V_5 , V_10 , V_11 ) )
return - V_15 ;
* V_6 = V_11 ;
* V_7 += * V_6 ;
return 0 ;
}
int F_1 ( T_4 )
{
char V_10 [ 22 ] ;
int V_11 ;
V_12 ;
if ( ! * V_6 || ( * V_7 && ! V_3 ) ) {
* V_6 = 0 ;
return 0 ;
}
if ( V_3 )
return - V_13 ;
V_11 = snprintf ( V_10 , sizeof( V_10 ) , V_14 L_1 , F_7 () ) ;
if ( V_11 > * V_6 )
V_11 = * V_6 ;
V_10 [ V_11 ] = '\0' ;
if ( F_5 ( V_5 , V_10 , V_11 ) )
return - V_15 ;
* V_6 = V_11 ;
* V_7 += * V_6 ;
return 0 ;
}
int F_1 ( T_5 )
{
char V_10 [ 22 ] ;
int V_11 ;
V_12 ;
if ( ! * V_6 || ( * V_7 && ! V_3 ) ) {
* V_6 = 0 ;
return 0 ;
}
if ( V_3 )
return - V_13 ;
V_11 = snprintf ( V_10 , sizeof( V_10 ) , V_14 L_1 , F_8 () ) ;
if ( V_11 > * V_6 )
V_11 = * V_6 ;
V_10 [ V_11 ] = '\0' ;
if ( F_5 ( V_5 , V_10 , V_11 ) )
return - V_15 ;
* V_6 = V_11 ;
* V_7 += * V_6 ;
return 0 ;
}
int F_1 ( T_6 )
{
int V_1 = 0 ;
V_12 ;
if ( ! V_2 -> V_16 || ! V_2 -> V_17 || ! * V_6 || ( * V_7 && ! V_3 ) ) {
* V_6 = 0 ;
return 0 ;
}
if ( V_3 ) {
V_1 = F_9 ( V_5 , * V_6 ,
( unsigned int * ) V_2 -> V_16 ,
1 << ( 20 - V_18 ) ) ;
if ( V_19 > ( ( V_20 / 10 ) * 9 ) ) {
F_10 ( L_2
L_3
L_4 , V_19 ,
( ( V_20 / 10 ) * 9 ) ) ;
V_19 = ( ( V_20 / 10 ) * 9 ) ;
} else if ( V_19 < 4 << ( 20 - V_18 ) ) {
V_19 = 4 << ( 20 - V_18 ) ;
}
} else {
char V_10 [ 21 ] ;
int V_11 ;
V_11 = F_11 ( V_10 , sizeof( V_10 ) ,
* ( unsigned int * ) V_2 -> V_16 ,
1 << ( 20 - V_18 ) ) ;
if ( V_11 > * V_6 )
V_11 = * V_6 ;
V_10 [ V_11 ] = '\0' ;
if ( F_5 ( V_5 , V_10 , V_11 ) )
return - V_15 ;
* V_6 = V_11 ;
}
* V_7 += * V_6 ;
return V_1 ;
}
int F_1 ( T_7 )
{
int V_1 = 0 ;
V_12 ;
if ( ! V_2 -> V_16 || ! V_2 -> V_17 || ! * V_6 || ( * V_7 && ! V_3 ) ) {
* V_6 = 0 ;
return 0 ;
}
if ( V_3 ) {
V_1 = F_9 ( V_5 , * V_6 ,
( unsigned int * ) V_2 -> V_16 ,
V_21 ) ;
} else {
char V_10 [ 21 ] ;
int V_11 ;
V_11 = F_11 ( V_10 , 21 ,
* ( unsigned int * ) V_2 -> V_16 ,
V_21 ) ;
if ( V_11 > * V_6 )
V_11 = * V_6 ;
V_10 [ V_11 ] = '\0' ;
if ( F_5 ( V_5 , V_10 , V_11 ) )
return - V_15 ;
* V_6 = V_11 ;
}
* V_7 += * V_6 ;
return V_1 ;
}
int F_1 ( T_8 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
int F_1 ( T_9 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
int F_1 ( T_10 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
int F_1 ( T_11 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
int F_1 ( T_12 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
void F_12 ( void )
{
#ifdef F_13
if ( ! V_22 )
V_22 = F_14 ( V_23 ) ;
#endif
}
void F_15 ( void )
{
#ifdef F_13
if ( V_22 )
F_16 ( V_22 ) ;
V_22 = NULL ;
#endif
}
