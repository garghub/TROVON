void F_1 ( void )
{
T_1 V_1 = 1020 ;
T_2 * V_2 = F_2 ( V_1 , V_3 ) ;
V_2 [ 1024 / sizeof( T_2 ) ] = 0x12345678 ;
F_3 ( V_2 ) ;
}
void F_4 ( void )
{
int * V_4 , * V_5 ;
T_1 V_1 = 1024 ;
T_1 V_6 = ( V_1 / sizeof( * V_4 ) ) / 2 ;
V_4 = F_2 ( V_1 , V_3 ) ;
F_5 ( L_1 , V_4 , & V_4 [ V_6 * 2 ] ) ;
F_5 ( L_2 ,
& V_4 [ V_6 ] ) ;
F_3 ( V_4 ) ;
V_4 [ V_6 ] = 0x0abcdef0 ;
V_5 = F_2 ( V_1 , V_3 ) ;
F_3 ( V_5 ) ;
if ( V_5 != V_4 )
F_5 ( L_3 ) ;
}
void F_6 ( void )
{
int * V_4 , * V_7 , V_8 ;
T_1 V_1 = 1024 ;
T_1 V_6 = ( V_1 / sizeof( * V_4 ) ) / 2 ;
V_4 = F_2 ( V_1 , V_3 ) ;
if ( ! V_4 ) {
F_5 ( L_4 ) ;
return;
}
V_7 = F_2 ( V_1 , V_3 ) ;
if ( ! V_7 ) {
F_5 ( L_5 ) ;
F_3 ( V_4 ) ;
return;
}
* V_7 = 0x12345678 ;
V_4 [ V_6 ] = * V_7 ;
F_5 ( L_6 , V_4 [ V_6 ] ) ;
F_3 ( V_4 ) ;
F_5 ( L_7 ) ;
V_8 = V_4 [ V_6 ] ;
if ( V_8 != * V_7 ) {
F_5 ( L_8 , V_8 ) ;
F_7 () ;
}
F_5 ( L_9 ) ;
F_3 ( V_7 ) ;
}
void F_8 ( void )
{
unsigned long V_9 = F_9 ( V_3 ) ;
if ( ! V_9 ) {
F_5 ( L_10 ) ;
return;
}
F_5 ( L_11 ) ;
memset ( ( void * ) V_9 , 0x3 , V_10 ) ;
F_10 ( V_9 ) ;
F_11 () ;
F_5 ( L_12 ) ;
memset ( ( void * ) V_9 , 0x78 , V_10 ) ;
V_9 = F_9 ( V_3 ) ;
F_10 ( V_9 ) ;
F_11 () ;
}
void F_12 ( void )
{
unsigned long V_9 = F_9 ( V_3 ) ;
int V_8 , * V_7 ;
int * V_4 ;
if ( ! V_9 ) {
F_5 ( L_10 ) ;
return;
}
V_7 = F_2 ( 1024 , V_3 ) ;
if ( ! V_7 ) {
F_5 ( L_5 ) ;
F_10 ( V_9 ) ;
return;
}
V_4 = ( int * ) V_9 ;
* V_7 = 0x12345678 ;
V_4 [ 0 ] = * V_7 ;
F_5 ( L_6 , V_4 [ 0 ] ) ;
F_10 ( V_9 ) ;
F_5 ( L_13 ) ;
V_8 = V_4 [ 0 ] ;
if ( V_8 != * V_7 ) {
F_5 ( L_8 , V_8 ) ;
F_7 () ;
}
F_5 ( L_14 ) ;
F_3 ( V_7 ) ;
}
