int F_1 ( struct V_1 * V_2 , char * * string )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_3 * V_5 = F_3 () ;
int V_6 ;
if ( ! F_4 ( V_5 , V_4 , true ) ) {
F_5 ( V_5 ) ;
return - V_7 ;
}
V_6 = F_6 ( NULL , 0 , V_5 , V_2 ,
V_8 | V_9 |
V_10 ) ;
F_7 ( V_6 < 0 ) ;
* string = F_8 ( V_6 + 2 , V_11 ) ;
if ( ! * string ) {
F_5 ( V_5 ) ;
return - V_12 ;
}
V_6 = F_6 ( * string , V_6 + 2 , V_5 , V_2 ,
V_8 | V_9 |
V_10 ) ;
if ( V_6 < 0 ) {
F_5 ( V_5 ) ;
return V_6 ;
}
( * string ) [ V_6 ] = '\n' ;
( * string ) [ V_6 + 1 ] = 0 ;
F_5 ( V_5 ) ;
return V_6 + 1 ;
}
static char * F_9 ( const char * V_13 , char * args , T_1 * V_14 )
{
char * V_15 ;
* V_14 = F_10 ( args , & V_15 , 16 ) ;
if ( ( V_15 == args ) || * V_15 != '^' ) {
F_11 ( L_1 , V_13 , args ) ;
return F_12 ( - V_16 ) ;
}
V_15 ++ ;
if ( ! * V_15 )
V_15 = NULL ;
return V_15 ;
}
int F_13 ( char * args , T_2 V_17 , int V_18 )
{
char * V_19 ;
T_1 V_14 ;
const char * V_20 [ 16 ] ;
int V_21 = 0 ;
V_19 = F_9 ( V_22 , args , & V_14 ) ;
if ( F_14 ( V_19 ) )
return F_15 ( V_19 ) ;
if ( ! V_19 && ! V_14 ) {
F_11 ( L_2 ) ;
return - V_16 ;
}
if ( V_19 ) {
char * V_23 = args + V_17 ;
for ( V_21 = 0 ; ( V_19 < V_23 ) && V_21 < 16 ; ++ V_21 ) {
char * V_24 = V_19 + strlen ( V_19 ) + 1 ;
V_20 [ V_21 ] = V_19 ;
F_16 ( L_3
, V_25 , V_26 -> V_27 , V_14 , V_21 , V_19 ) ;
V_19 = V_24 ;
}
} else
F_16 ( L_4 ,
V_25 , V_26 -> V_27 , V_14 , V_21 , L_5 ) ;
return F_17 ( V_20 , V_21 , V_14 , V_18 ) ;
}
