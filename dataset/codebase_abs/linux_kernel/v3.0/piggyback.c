static int F_1 ( int V_1 )
{
if ( V_2 )
return ( V_1 + 0x1fff ) & ~ 0x1fff ;
else
return ( V_1 + 0xfff ) & ~ 0xfff ;
}
static unsigned short F_2 ( char * V_3 )
{
return ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ;
}
static void F_3 ( char * V_3 , unsigned int V_4 )
{
V_3 [ 0 ] = V_4 >> 24 ;
V_3 [ 1 ] = V_4 >> 16 ;
V_3 [ 2 ] = V_4 >> 8 ;
V_3 [ 3 ] = V_4 ;
}
static void F_4 ( const char * V_5 )
{
perror ( V_5 ) ;
exit ( 1 ) ;
}
static void F_5 ( void )
{
fprintf ( V_6 , L_1 ) ;
fprintf ( V_6 , L_2 ) ;
exit ( 1 ) ;
}
static int F_6 ( const char * line )
{
if ( strcmp ( line + 8 , L_3 ) == 0 )
return 1 ;
else if ( strcmp ( line + 16 , L_3 ) == 0 )
return 1 ;
return 0 ;
}
static int F_7 ( const char * line )
{
if ( strcmp ( line + 8 , L_4 ) == 0 )
return 1 ;
else if ( strcmp ( line + 16 , L_4 ) == 0 )
return 1 ;
return 0 ;
}
static int F_8 ( const char * V_7 , unsigned int * V_8 ,
unsigned int * V_9 )
{
T_1 * V_10 ;
char V_11 [ 1024 ] ;
* V_8 = 0 ;
* V_9 = 0 ;
V_10 = fopen ( V_7 , L_5 ) ;
if ( ! V_10 )
F_4 ( V_7 ) ;
while ( fgets ( V_11 , 1024 , V_10 ) ) {
if ( F_6 ( V_11 ) )
* V_8 = strtoul ( V_11 , NULL , 16 ) ;
else if ( F_7 ( V_11 ) )
* V_9 = strtoul ( V_11 , NULL , 16 ) ;
}
fclose ( V_10 ) ;
if ( * V_8 == 0 || * V_9 == 0 )
return 0 ;
return 1 ;
}
static T_2 F_9 ( int V_12 , const char * V_7 )
{
char V_11 [ V_13 ] ;
T_2 V_14 ;
int V_15 ;
if ( F_10 ( V_12 , 0 , V_16 ) < 0 )
F_4 ( L_6 ) ;
if ( F_11 ( V_12 , V_11 , V_13 ) != V_13 )
F_4 ( V_7 ) ;
if ( V_11 [ 40 ] == 'H' && V_11 [ 41 ] == 'd' &&
V_11 [ 42 ] == 'r' && V_11 [ 43 ] == 'S' ) {
return 40 ;
} else {
V_14 = F_2 ( V_11 + V_17 + 2 ) << 2 ;
V_14 -= V_18 ;
V_14 += V_17 ;
if ( F_10 ( V_12 , V_14 , V_16 ) < 0 )
F_4 ( L_6 ) ;
if ( F_11 ( V_12 , V_11 , V_13 ) != V_13 )
F_4 ( V_7 ) ;
for ( V_15 = 0 ; V_15 < V_18 ; V_15 += 4 ) {
if ( V_11 [ V_15 + 0 ] == 'H' && V_11 [ V_15 + 1 ] == 'd' &&
V_11 [ V_15 + 2 ] == 'r' && V_11 [ V_15 + 3 ] == 'S' ) {
return V_14 + V_15 ;
}
}
}
fprintf ( V_6 , L_7 , V_7 ) ;
exit ( 1 ) ;
}
int main ( int V_19 , char * * V_20 )
{
static char V_21 [] = { 0x01 , 0x03 , 0x01 , 0x07 } ;
char V_11 [ 1024 ] ;
unsigned int V_15 , V_8 , V_9 ;
T_2 V_14 ;
struct V_22 V_23 ;
int V_24 , V_25 ;
if ( V_19 != 5 )
F_5 () ;
if ( strcmp ( V_20 [ 1 ] , L_8 ) == 0 )
V_2 = 1 ;
if ( V_22 ( V_20 [ 4 ] , & V_23 ) < 0 )
F_4 ( V_20 [ 4 ] ) ;
if ( ! F_8 ( V_20 [ 3 ] , & V_8 , & V_9 ) ) {
fprintf ( V_6 , L_9 ,
V_20 [ 3 ] ) ;
exit ( 1 ) ;
}
if ( ( V_24 = F_12 ( V_20 [ 2 ] , V_26 ) ) < 0 )
F_4 ( V_20 [ 2 ] ) ;
if ( F_11 ( V_24 , V_11 , 512 ) != 512 )
F_4 ( V_20 [ 2 ] ) ;
if ( memcmp ( V_11 , V_21 , 4 ) != 0 ) {
fprintf ( V_6 , L_10 ) ;
exit ( 1 ) ;
}
V_14 = F_9 ( V_24 , V_20 [ 2 ] ) ;
V_14 += 10 ;
if ( F_10 ( V_24 , V_14 , 0 ) < 0 )
F_4 ( L_6 ) ;
F_3 ( V_11 , 0 ) ;
F_3 ( V_11 + 4 , 0x01000000 ) ;
F_3 ( V_11 + 8 , F_1 ( V_9 + 32 ) ) ;
F_3 ( V_11 + 12 , V_23 . V_27 ) ;
if ( F_13 ( V_24 , V_11 + 2 , 14 ) != 14 )
F_4 ( V_20 [ 2 ] ) ;
if ( V_2 )
{
if ( F_10 ( V_24 , 4 , 0 ) < 0 )
F_4 ( L_6 ) ;
F_3 ( V_11 , F_1 ( V_9 + 32 + 8191 ) - ( V_8 & ~ 0x3fffffUL ) +
V_23 . V_27 ) ;
F_3 ( V_11 + 4 , 0 ) ;
F_3 ( V_11 + 8 , 0 ) ;
if ( F_13 ( V_24 , V_11 , 12 ) != 12 )
F_4 ( V_20 [ 2 ] ) ;
}
if ( F_10 ( V_24 , V_17 - V_8 + F_1 ( V_9 + 32 ) , 0 ) < 0 )
F_4 ( L_6 ) ;
if ( ( V_25 = F_12 ( V_20 [ 4 ] , V_28 ) ) < 0 )
F_4 ( V_20 [ 4 ] ) ;
while ( ( V_15 = F_11 ( V_25 , V_11 , 1024 ) ) > 0 )
if ( F_13 ( V_24 , V_11 , V_15 ) != V_15 )
F_4 ( V_20 [ 2 ] ) ;
if ( F_14 ( V_24 ) < 0 )
F_4 ( L_11 ) ;
if ( F_14 ( V_25 ) < 0 )
F_4 ( L_11 ) ;
return 0 ;
}
