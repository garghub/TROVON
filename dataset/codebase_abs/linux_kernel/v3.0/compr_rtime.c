static int F_1 ( unsigned char * V_1 ,
unsigned char * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
short V_5 [ 256 ] ;
int V_6 = 0 ;
int V_7 = 0 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
while ( V_7 < ( * V_3 ) && V_6 <= ( * V_4 ) - 2 ) {
int V_8 , V_9 = 0 ;
unsigned char V_10 ;
V_10 = V_1 [ V_7 ] ;
V_2 [ V_6 ++ ] = V_1 [ V_7 ++ ] ;
V_8 = V_5 [ V_10 ] ;
V_5 [ V_10 ] = V_7 ;
while ( ( V_8 < V_7 ) && ( V_7 < ( * V_3 ) ) &&
( V_1 [ V_7 ] == V_1 [ V_8 ++ ] ) && ( V_9 < 255 ) ) {
V_7 ++ ;
V_9 ++ ;
}
V_2 [ V_6 ++ ] = V_9 ;
}
if ( V_6 >= V_7 ) {
return - 1 ;
}
* V_3 = V_7 ;
* V_4 = V_6 ;
return 0 ;
}
static int F_2 ( unsigned char * V_1 ,
unsigned char * V_2 ,
T_1 V_11 , T_1 V_12 )
{
short V_5 [ 256 ] ;
int V_6 = 0 ;
int V_7 = 0 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
while ( V_6 < V_12 ) {
unsigned char V_10 ;
int V_13 ;
int V_14 ;
V_10 = V_1 [ V_7 ++ ] ;
V_2 [ V_6 ++ ] = V_10 ;
V_14 = V_1 [ V_7 ++ ] ;
V_13 = V_5 [ V_10 ] ;
V_5 [ V_10 ] = V_6 ;
if ( V_14 ) {
if ( V_13 + V_14 >= V_6 ) {
while( V_14 ) {
V_2 [ V_6 ++ ] = V_2 [ V_13 ++ ] ;
V_14 -- ;
}
} else {
memcpy ( & V_2 [ V_6 ] , & V_2 [ V_13 ] , V_14 ) ;
V_6 += V_14 ;
}
}
}
return 0 ;
}
int F_3 ( void )
{
return F_4 ( & V_15 ) ;
}
void F_5 ( void )
{
F_6 ( & V_15 ) ;
}
