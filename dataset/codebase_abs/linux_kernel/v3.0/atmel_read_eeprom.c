static void F_1 ( int F_1 )
{
while ( F_1 -- ) ;
}
static void F_2 ( unsigned char V_1 )
{
V_2 ;
F_1 ( V_3 ) ;
if ( V_1 )
V_4 ;
else
V_5 ;
F_1 ( V_3 ) ;
V_6 ;
F_1 ( V_3 ) ;
}
static void F_3 ( void )
{
F_2 ( 0 ) ;
}
static void F_4 ( unsigned char V_7 )
{
int V_8 = 0 ;
for ( V_8 = 7 ; V_8 >= 0 ; V_8 -- )
F_2 ( ( V_7 >> V_8 ) & 0x01 ) ;
}
static void F_5 ( void )
{
V_4 ;
F_1 ( V_3 ) ;
V_6 ;
F_1 ( V_3 ) ;
V_5 ;
F_1 ( V_3 ) ;
}
static void F_6 ( void )
{
V_5 ;
F_1 ( V_3 ) ;
V_6 ;
F_1 ( V_3 ) ;
V_4 ;
F_1 ( V_3 ) ;
}
static void F_7 ( void )
{
V_4 ;
V_6 ;
V_9 ;
}
static int F_8 ( void )
{
int V_10 ;
V_2 ;
F_1 ( V_3 ) ;
V_4 ;
F_1 ( V_3 ) ;
V_6 ;
F_1 ( V_3 ) ;
return 1 ;
}
static unsigned char F_9 ( void ) {
int V_8 ;
unsigned char V_7 = 0 ;
for ( V_8 = 7 ; V_8 >= 0 ; V_8 -- )
V_7 |= ( F_8 () << V_8 ) ;
return V_7 ;
}
static int F_10 ( void )
{
unsigned int V_11 ;
V_11 = ( unsigned int ) F_8 () ;
V_2 ;
if ( V_11 ) {
F_7 () ;
F_11 ( V_12 L_1 ) ;
return - 1 ;
}
return V_11 ;
}
int F_12 ( char * V_13 , int V_14 , int V_15 )
{
int V_8 = 0 , V_16 ;
F_5 () ;
F_4 ( V_17 ) ;
F_10 () ;
if ( V_14 > 2048 ) {
F_4 ( 0x00 ) ;
F_10 () ;
}
F_5 () ;
F_4 ( V_18 ) ;
V_16 = F_10 () ;
if ( V_16 == - 1 )
return V_16 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
* V_13 ++ = F_9 () ;
F_3 () ;
}
F_6 () ;
}
