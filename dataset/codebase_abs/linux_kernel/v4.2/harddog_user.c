static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 -> V_4 , 0 ) ;
F_2 ( V_3 -> V_5 , 1 ) ;
F_2 ( V_3 -> V_5 , 2 ) ;
F_3 ( V_3 -> V_4 ) ;
F_3 ( V_3 -> V_5 ) ;
F_3 ( V_3 -> V_6 [ 0 ] ) ;
F_3 ( V_3 -> V_6 [ 1 ] ) ;
}
int F_4 ( int * V_7 , int * V_8 , char * V_9 )
{
struct V_2 V_3 ;
int V_10 [ 2 ] , V_11 [ 2 ] , V_12 , V_13 , V_14 ;
char V_15 [ sizeof( L_1 ) ] , V_16 ;
char * V_17 [] = { L_2 , L_3 , V_15 , NULL } ;
char * V_18 [] = { L_2 , L_4 , NULL ,
NULL } ;
char * * args = NULL ;
V_14 = F_5 ( V_10 , 1 , 0 ) ;
if ( V_14 < 0 ) {
F_6 ( L_5 , - V_14 ) ;
goto V_19;
}
V_14 = F_5 ( V_11 , 1 , 0 ) ;
if ( V_14 < 0 ) {
F_6 ( L_5 , - V_14 ) ;
goto V_20;
}
V_3 . V_4 = V_11 [ 0 ] ;
V_3 . V_5 = V_10 [ 1 ] ;
V_3 . V_6 [ 0 ] = V_11 [ 1 ] ;
V_3 . V_6 [ 1 ] = V_10 [ 0 ] ;
if ( V_9 != NULL ) {
V_18 [ 2 ] = V_9 ;
args = V_18 ;
}
else {
sprintf ( V_15 , L_6 , F_7 () ) ;
args = V_17 ;
}
V_12 = F_8 ( F_1 , & V_3 , args ) ;
F_3 ( V_11 [ 0 ] ) ;
F_3 ( V_10 [ 1 ] ) ;
if ( V_12 < 0 ) {
V_14 = - V_12 ;
F_6 ( L_7 , - V_14 ) ;
goto V_21;
}
V_13 = F_9 ( V_10 [ 0 ] , & V_16 , sizeof( V_16 ) ) ;
if ( V_13 == 0 ) {
F_6 ( L_8 ) ;
F_10 ( V_12 ) ;
V_14 = - V_22 ;
goto V_21;
}
else if ( V_13 < 0 ) {
F_6 ( L_9
L_10 , V_23 ) ;
F_10 ( V_12 ) ;
V_14 = V_13 ;
goto V_21;
}
* V_7 = V_10 [ 0 ] ;
* V_8 = V_11 [ 1 ] ;
return 0 ;
V_20:
F_3 ( V_10 [ 0 ] ) ;
F_3 ( V_10 [ 1 ] ) ;
V_21:
F_3 ( V_11 [ 0 ] ) ;
F_3 ( V_11 [ 1 ] ) ;
V_19:
return V_14 ;
}
void F_11 ( int V_24 , int V_25 )
{
F_3 ( V_24 ) ;
F_3 ( V_25 ) ;
}
int F_12 ( int V_26 )
{
int V_13 ;
char V_16 = '\n' ;
V_13 = F_13 ( V_26 , & V_16 , sizeof( V_16 ) ) ;
if ( V_13 != sizeof( V_16 ) ) {
F_6 ( L_11 ,
V_13 , V_23 ) ;
if ( V_13 < 0 )
return V_13 ;
return - V_22 ;
}
return 1 ;
}
