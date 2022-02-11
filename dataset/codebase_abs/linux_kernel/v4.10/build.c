void F_1 ( const char * V_1 , ... )
{
T_1 args ;
va_start ( args , V_1 ) ;
vfprintf ( V_2 , V_1 , args ) ;
fputc ( '\n' , V_2 ) ;
exit ( 1 ) ;
}
void F_2 ( const char * V_3 )
{
V_4 = F_3 ( V_3 , V_5 , 0 ) ;
if ( V_4 < 0 )
F_1 ( L_1 , V_3 ) ;
}
void F_4 ( void )
{
F_1 ( L_2 ) ;
}
int main ( int V_6 , char * * V_7 )
{
unsigned int V_8 , V_9 , V_10 , V_11 ;
T_2 V_12 ;
T_3 V_13 , V_14 ;
struct V_15 V_16 ;
if ( V_6 > 2 && ! strcmp ( V_7 [ 1 ] , L_3 ) ) {
V_17 = 1 ;
V_6 -- , V_7 ++ ;
}
if ( ( V_6 < 4 ) || ( V_6 > 5 ) )
F_4 () ;
if ( V_6 > 4 ) {
if ( ! strcmp ( V_7 [ 4 ] , L_4 ) ) {
if ( V_15 ( L_5 , & V_16 ) ) {
perror ( L_5 ) ;
F_1 ( L_6 ) ;
}
V_13 = F_5 ( V_16 . V_18 ) ;
V_14 = F_6 ( V_16 . V_18 ) ;
} else if ( strcmp ( V_7 [ 4 ] , L_7 ) ) {
if ( V_15 ( V_7 [ 4 ] , & V_16 ) ) {
perror ( V_7 [ 4 ] ) ;
F_1 ( L_8 ) ;
}
V_13 = F_5 ( V_16 . V_19 ) ;
V_14 = F_6 ( V_16 . V_19 ) ;
} else {
V_13 = 0 ;
V_14 = 0 ;
}
} else {
V_13 = V_20 ;
V_14 = V_21 ;
}
fprintf ( V_2 , L_9 , V_13 , V_14 ) ;
F_2 ( V_7 [ 1 ] ) ;
V_8 = F_7 ( V_4 , V_22 , sizeof( V_22 ) ) ;
fprintf ( V_2 , L_10 , V_8 ) ;
if ( V_8 != 512 )
F_1 ( L_11 ) ;
if ( V_22 [ 510 ] != 0x55 || V_22 [ 511 ] != 0xaa )
F_1 ( L_12 ) ;
V_22 [ 508 ] = V_14 ;
V_22 [ 509 ] = V_13 ;
if ( F_8 ( 1 , V_22 , 512 ) != 512 )
F_1 ( L_13 ) ;
F_9 ( V_4 ) ;
F_2 ( V_7 [ 2 ] ) ;
for ( V_8 = 0 ; ( V_9 = F_7 ( V_4 , V_22 , sizeof( V_22 ) ) ) > 0 ; V_8 += V_9 )
if ( F_8 ( 1 , V_22 , V_9 ) != V_9 )
F_1 ( L_13 ) ;
if ( V_9 != 0 )
F_1 ( L_14 ) ;
F_9 ( V_4 ) ;
V_11 = ( V_8 + 511 ) / 512 ;
if ( V_11 < V_23 )
V_11 = V_23 ;
fprintf ( V_2 , L_15 , V_8 ) ;
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
while ( V_8 < V_11 * 512 ) {
V_9 = V_11 * 512 - V_8 ;
if ( V_9 > sizeof( V_22 ) )
V_9 = sizeof( V_22 ) ;
if ( F_8 ( 1 , V_22 , V_9 ) != V_9 )
F_1 ( L_13 ) ;
V_8 += V_9 ;
}
F_2 ( V_7 [ 3 ] ) ;
if ( F_10 ( V_4 , & V_16 ) )
F_1 ( L_16 , V_7 [ 3 ] ) ;
V_10 = V_16 . V_24 ;
fprintf ( V_2 , L_17 , V_10 / 1024 ) ;
V_12 = ( V_10 + 15 ) / 16 ;
if ( V_12 > ( V_17 ? 0x28000 : V_25 ) )
F_1 ( L_18 ,
V_17 ? L_19 : L_20 ) ;
if ( V_12 > 0xffff )
fprintf ( V_2 ,
L_21
L_22 ) ;
while ( V_10 > 0 ) {
int V_26 , V_27 ;
V_26 = ( V_10 > sizeof( V_22 ) ) ? sizeof( V_22 ) : V_10 ;
V_27 = F_7 ( V_4 , V_22 , V_26 ) ;
if ( V_27 != V_26 ) {
if ( V_27 < 0 )
F_1 ( L_23 , V_7 [ 3 ] ) ;
else
F_1 ( L_24 , V_7 [ 3 ] ) ;
}
if ( F_8 ( 1 , V_22 , V_26 ) != V_26 )
F_1 ( L_25 ) ;
V_10 -= V_26 ;
}
F_9 ( V_4 ) ;
if ( F_11 ( 1 , 497 , V_28 ) != 497 )
F_1 ( L_26 ) ;
V_22 [ 0 ] = V_11 ;
if ( F_8 ( 1 , V_22 , 1 ) != 1 )
F_1 ( L_27 ) ;
if ( F_11 ( 1 , 500 , V_28 ) != 500 )
F_1 ( L_26 ) ;
V_22 [ 0 ] = ( V_12 & 0xff ) ;
V_22 [ 1 ] = ( ( V_12 >> 8 ) & 0xff ) ;
if ( F_8 ( 1 , V_22 , 2 ) != 2 )
F_1 ( L_28 ) ;
return 0 ;
}
