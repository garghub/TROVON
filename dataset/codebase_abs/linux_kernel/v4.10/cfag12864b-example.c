static int F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , V_3 ) ;
if ( V_2 == - 1 )
return - 1 ;
V_4 = F_3 ( 0 , V_5 , V_6 | V_7 ,
V_8 , V_2 , 0 ) ;
if ( V_4 == V_9 ) {
F_4 ( V_2 ) ;
return - 2 ;
}
return 0 ;
}
static void F_5 ( void )
{
F_6 ( V_4 , V_5 ) ;
F_4 ( V_2 ) ;
}
static void F_7 ( unsigned char V_10 , unsigned char V_11 )
{
if ( F_8 ( V_10 , V_11 ) )
V_12 [ F_9 ( V_10 , V_11 ) ] |=
F_10 ( V_10 % V_13 ) ;
}
static void F_11 ( unsigned char V_10 , unsigned char V_11 )
{
if ( F_8 ( V_10 , V_11 ) )
V_12 [ F_9 ( V_10 , V_11 ) ] &=
~ F_10 ( V_10 % V_13 ) ;
}
static unsigned char F_12 ( unsigned char V_10 , unsigned char V_11 )
{
if ( F_8 ( V_10 , V_11 ) )
if ( V_12 [ F_9 ( V_10 , V_11 ) ] &
F_10 ( V_10 % V_13 ) )
return 1 ;
return 0 ;
}
static void F_13 ( unsigned char V_10 , unsigned char V_11 )
{
if ( F_12 ( V_10 , V_11 ) )
F_11 ( V_10 , V_11 ) ;
else
F_7 ( V_10 , V_11 ) ;
}
static void F_14 ( void )
{
unsigned short V_14 ;
for ( V_14 = 0 ; V_14 < V_5 ; V_14 ++ )
V_12 [ V_14 ] = 0xFF ;
}
static void F_15 ( void )
{
unsigned short V_14 ;
for ( V_14 = 0 ; V_14 < V_5 ; V_14 ++ )
V_12 [ V_14 ] = 0 ;
}
static void F_16 ( unsigned char * V_15 )
{
unsigned char V_14 , V_16 , V_17 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ )
for ( V_16 = 0 ; V_16 < V_19 / V_13 ; V_16 ++ ) {
V_12 [ V_14 * V_19 / V_13 +
V_16 ] = 0 ;
for ( V_17 = 0 ; V_17 < V_13 ; V_17 ++ )
if ( V_15 [ V_14 * V_19 +
V_16 * V_13 + V_17 ] )
V_12 [ V_14 * V_19 /
V_13 + V_16 ] |=
F_10 ( V_17 ) ;
}
}
static void F_17 ( void )
{
memcpy ( V_4 , V_12 , V_5 ) ;
}
static void F_18 ( unsigned char V_17 )
{
unsigned short V_14 , V_16 ;
unsigned char V_15 [ V_19 * V_18 ] ;
if ( V_17 > V_20 )
return;
printf ( L_1 , V_17 , V_20 ) ;
switch ( V_17 ) {
case 1 :
printf ( L_2 ) ;
F_15 () ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 += 2 )
for ( V_16 = 0 ; V_16 < V_18 ; V_16 += 2 )
F_7 ( V_14 , V_16 ) ;
break;
case 2 :
printf ( L_3 ) ;
F_15 () ;
break;
case 3 :
printf ( L_4 ) ;
memset ( V_15 , 0 , V_19 * V_18 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ )
for ( V_16 = 0 ; V_16 < V_18 ; V_16 += 2 )
V_15 [ V_16 * V_19 + V_14 ] = 1 ;
F_16 ( V_15 ) ;
break;
case 4 :
printf ( L_5 ) ;
F_14 () ;
break;
case 5 :
printf ( L_6 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 += 2 )
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ )
F_11 ( V_14 , V_16 ) ;
break;
case 6 :
printf ( L_7 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ )
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ )
F_13 ( V_14 , V_16 ) ;
break;
}
puts ( L_8 ) ;
}
int main ( int V_21 , char * V_22 [] )
{
unsigned char V_17 ;
if ( V_21 != 2 ) {
printf (
L_9
L_10 , V_22 [ 0 ] ) ;
return - 1 ;
}
if ( F_1 ( V_22 [ 1 ] ) ) {
printf ( L_11 , V_22 [ 1 ] ) ;
return - 2 ;
}
for ( V_17 = 1 ; V_17 <= V_20 ; V_17 ++ ) {
F_18 ( V_17 ) ;
F_17 () ;
while ( getchar () != '\n' ) ;
}
F_5 () ;
return 0 ;
}
