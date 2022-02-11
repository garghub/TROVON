unsigned long T_1 F_1 ( void )
{
int V_1 [ 8 ] ;
int error ;
unsigned int V_2 ;
T_2 V_3 ;
V_3 = F_2 () + V_4 * 1000 * V_5 ;
do {
error = F_3 ( F_4 ( L_1 ) , 0 , 8 , V_1 ) ;
V_2 = F_5 ( error ) ;
if ( V_2 ) {
F_6 ( V_2 * 1000 ) ;
}
} while ( V_2 && ( F_2 () < V_3 ) );
if ( error != 0 ) {
F_7 ( V_6
L_2 ,
error ) ;
return 0 ;
}
return mktime ( V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
void F_8 ( struct V_7 * V_8 )
{
int V_1 [ 8 ] ;
int error ;
unsigned int V_2 ;
T_2 V_3 ;
V_3 = F_2 () + V_4 * 1000 * V_5 ;
do {
error = F_3 ( F_4 ( L_1 ) , 0 , 8 , V_1 ) ;
V_2 = F_5 ( error ) ;
if ( V_2 ) {
if ( F_9 () ) {
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
F_7 ( V_6
L_3
L_4 ) ;
return;
}
F_10 ( V_2 ) ;
}
} while ( V_2 && ( F_2 () < V_3 ) );
if ( error != 0 ) {
F_7 ( V_6
L_2 ,
error ) ;
return;
}
V_8 -> V_9 = V_1 [ 5 ] ;
V_8 -> V_10 = V_1 [ 4 ] ;
V_8 -> V_11 = V_1 [ 3 ] ;
V_8 -> V_12 = V_1 [ 2 ] ;
V_8 -> V_13 = V_1 [ 1 ] - 1 ;
V_8 -> V_14 = V_1 [ 0 ] - 1900 ;
}
int F_11 ( struct V_7 * V_15 )
{
int error , V_2 ;
T_2 V_3 ;
V_3 = F_2 () + V_4 * 1000 * V_5 ;
do {
error = F_3 ( F_4 ( L_5 ) , 7 , 1 , NULL ,
V_15 -> V_14 + 1900 , V_15 -> V_13 + 1 ,
V_15 -> V_12 , V_15 -> V_11 , V_15 -> V_10 ,
V_15 -> V_9 , 0 ) ;
V_2 = F_5 ( error ) ;
if ( V_2 ) {
if ( F_9 () )
return 1 ;
F_10 ( V_2 ) ;
}
} while ( V_2 && ( F_2 () < V_3 ) );
if ( error != 0 )
F_7 ( V_6
L_6 ,
error ) ;
return 0 ;
}
