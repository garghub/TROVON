static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 -> V_4 , 0 ) ;
F_2 ( V_3 -> stdout , 1 ) ;
F_2 ( V_3 -> stdout , 2 ) ;
F_3 ( V_3 -> V_4 ) ;
F_3 ( V_3 -> stdout ) ;
F_3 ( V_3 -> V_5 [ 0 ] ) ;
F_3 ( V_3 -> V_5 [ 1 ] ) ;
}
int F_4 ( int * V_6 , int * V_7 , char * V_8 )
{
struct V_2 V_3 ;
int V_9 [ 2 ] , V_10 [ 2 ] , V_11 , V_12 , V_13 ;
char V_14 [ sizeof( L_1 ) ] , V_15 ;
char * V_16 [] = { L_2 , L_3 , V_14 , NULL } ;
char * V_17 [] = { L_2 , L_4 , NULL ,
NULL } ;
char * * args = NULL ;
V_13 = F_5 ( V_9 , 1 , 0 ) ;
if ( V_13 < 0 ) {
F_6 ( L_5 , - V_13 ) ;
goto V_18;
}
V_13 = F_5 ( V_10 , 1 , 0 ) ;
if ( V_13 < 0 ) {
F_6 ( L_5 , - V_13 ) ;
goto V_19;
}
V_3 . V_4 = V_10 [ 0 ] ;
V_3 . stdout = V_9 [ 1 ] ;
V_3 . V_5 [ 0 ] = V_10 [ 1 ] ;
V_3 . V_5 [ 1 ] = V_9 [ 0 ] ;
if ( V_8 != NULL ) {
V_17 [ 2 ] = V_8 ;
args = V_17 ;
}
else {
sprintf ( V_14 , L_6 , F_7 () ) ;
args = V_16 ;
}
V_11 = F_8 ( F_1 , & V_3 , args ) ;
F_3 ( V_10 [ 0 ] ) ;
F_3 ( V_9 [ 1 ] ) ;
if ( V_11 < 0 ) {
V_13 = - V_11 ;
F_6 ( L_7 , - V_13 ) ;
goto V_20;
}
V_12 = F_9 ( V_9 [ 0 ] , & V_15 , sizeof( V_15 ) ) ;
if ( V_12 == 0 ) {
F_6 ( L_8 ) ;
F_10 ( V_11 ) ;
V_13 = - V_21 ;
goto V_20;
}
else if ( V_12 < 0 ) {
F_6 ( L_9
L_10 , V_22 ) ;
F_10 ( V_11 ) ;
V_13 = V_12 ;
goto V_20;
}
* V_6 = V_9 [ 0 ] ;
* V_7 = V_10 [ 1 ] ;
return 0 ;
V_19:
F_3 ( V_9 [ 0 ] ) ;
F_3 ( V_9 [ 1 ] ) ;
V_20:
F_3 ( V_10 [ 0 ] ) ;
F_3 ( V_10 [ 1 ] ) ;
V_18:
return V_13 ;
}
void F_11 ( int V_23 , int V_24 )
{
F_3 ( V_23 ) ;
F_3 ( V_24 ) ;
}
int F_12 ( int V_25 )
{
int V_12 ;
char V_15 = '\n' ;
V_12 = F_13 ( V_25 , & V_15 , sizeof( V_15 ) ) ;
if ( V_12 != sizeof( V_15 ) ) {
F_6 ( L_11 ,
V_12 , V_22 ) ;
if ( V_12 < 0 )
return V_12 ;
return - V_21 ;
}
return 1 ;
}
