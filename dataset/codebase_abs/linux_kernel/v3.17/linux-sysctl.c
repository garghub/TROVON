static int F_1 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
int V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_8 >= V_9 )
V_8 = F_3 ( V_9 / 3 , 1U ) ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
char V_10 [ 22 ] ;
int V_11 ;
if ( ! * V_5 || ( * V_6 && ! V_3 ) ) {
* V_5 = 0 ;
return 0 ;
}
if ( V_3 )
return - V_12 ;
V_11 = snprintf ( V_10 , sizeof( V_10 ) , L_1 , F_5 () ) ;
if ( V_11 > * V_5 )
V_11 = * V_5 ;
V_10 [ V_11 ] = '\0' ;
if ( F_6 ( V_4 , V_10 , V_11 ) )
return - V_13 ;
* V_5 = V_11 ;
* V_6 += * V_5 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
char V_10 [ 22 ] ;
int V_11 ;
if ( ! * V_5 || ( * V_6 && ! V_3 ) ) {
* V_5 = 0 ;
return 0 ;
}
if ( V_3 )
return - V_12 ;
V_11 = snprintf ( V_10 , sizeof( V_10 ) , L_1 , F_8 () ) ;
if ( V_11 > * V_5 )
V_11 = * V_5 ;
V_10 [ V_11 ] = '\0' ;
if ( F_6 ( V_4 , V_10 , V_11 ) )
return - V_13 ;
* V_5 = V_11 ;
* V_6 += * V_5 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 , void T_1 * V_4 ,
T_2 * V_5 , T_3 * V_6 )
{
char V_10 [ 22 ] ;
int V_11 ;
if ( ! * V_5 || ( * V_6 && ! V_3 ) ) {
* V_5 = 0 ;
return 0 ;
}
if ( V_3 )
return - V_12 ;
V_11 = snprintf ( V_10 , sizeof( V_10 ) , L_1 , F_10 () ) ;
if ( V_11 > * V_5 )
V_11 = * V_5 ;
V_10 [ V_11 ] = '\0' ;
if ( F_6 ( V_4 , V_10 , V_11 ) )
return - V_13 ;
* V_5 = V_11 ;
* V_6 += * V_5 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
char V_10 [ 22 ] ;
int V_11 ;
if ( ! * V_5 || ( * V_6 && ! V_3 ) ) {
* V_5 = 0 ;
return 0 ;
}
if ( V_3 )
return - V_12 ;
V_11 = snprintf ( V_10 , sizeof( V_10 ) , L_1 , F_12 () ) ;
if ( V_11 > * V_5 )
V_11 = * V_5 ;
V_10 [ V_11 ] = '\0' ;
if ( F_6 ( V_4 , V_10 , V_11 ) )
return - V_13 ;
* V_5 = V_11 ;
* V_6 += * V_5 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
int V_7 = 0 ;
if ( ! V_2 -> V_14 || ! V_2 -> V_15 || ! * V_5 || ( * V_6 && ! V_3 ) ) {
* V_5 = 0 ;
return 0 ;
}
if ( V_3 ) {
V_7 = F_14 ( V_4 , * V_5 ,
( unsigned int * ) V_2 -> V_14 ,
1 << ( 20 - V_16 ) ) ;
if ( V_17 > ( ( V_18 / 10 ) * 9 ) ) {
F_15 ( L_2
L_3
L_4 , V_17 ,
( ( V_18 / 10 ) * 9 ) ) ;
V_17 = ( ( V_18 / 10 ) * 9 ) ;
} else if ( V_17 < 4 << ( 20 - V_16 ) ) {
V_17 = 4 << ( 20 - V_16 ) ;
}
} else {
char V_10 [ 21 ] ;
int V_11 ;
V_11 = F_16 ( V_10 , sizeof( V_10 ) ,
* ( unsigned int * ) V_2 -> V_14 ,
1 << ( 20 - V_16 ) ) ;
if ( V_11 > * V_5 )
V_11 = * V_5 ;
V_10 [ V_11 ] = '\0' ;
if ( F_6 ( V_4 , V_10 , V_11 ) )
return - V_13 ;
* V_5 = V_11 ;
}
* V_6 += * V_5 ;
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
int V_7 = 0 ;
if ( ! V_2 -> V_14 || ! V_2 -> V_15 || ! * V_5 || ( * V_6 && ! V_3 ) ) {
* V_5 = 0 ;
return 0 ;
}
if ( V_3 ) {
V_7 = F_14 ( V_4 , * V_5 ,
( unsigned int * ) V_2 -> V_14 ,
V_19 ) ;
} else {
char V_10 [ 21 ] ;
int V_11 ;
V_11 = F_16 ( V_10 , 21 ,
* ( unsigned int * ) V_2 -> V_14 ,
V_19 ) ;
if ( V_11 > * V_5 )
V_11 = * V_5 ;
V_10 [ V_11 ] = '\0' ;
if ( F_6 ( V_4 , V_10 , V_11 ) )
return - V_13 ;
* V_5 = V_11 ;
}
* V_6 += * V_5 ;
return V_7 ;
}
void F_18 ( void )
{
#ifdef F_19
if ( ! V_20 )
V_20 = F_20 ( V_21 ) ;
#endif
}
void F_21 ( void )
{
#ifdef F_19
if ( V_20 )
F_22 ( V_20 ) ;
V_20 = NULL ;
#endif
}
