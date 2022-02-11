static int F_1 ( void )
{
T_1 V_1 ;
int V_2 = V_3 ;
int V_4 = V_5 ;
while ( V_2 -- ) {
F_2 () ;
V_1 = F_3 ( 0x64 ) ;
if ( V_1 == 0xff ) {
if ( ! -- V_4 )
return - 1 ;
}
if ( V_1 & 1 ) {
F_2 () ;
( void ) F_3 ( 0x60 ) ;
} else if ( ! ( V_1 & 2 ) ) {
return 0 ;
}
}
return - 1 ;
}
static int F_4 ( int V_2 )
{
int V_6 = 0 ;
int V_7 , V_8 ;
F_5 ( 0x0000 ) ;
F_6 ( 0xffff ) ;
V_7 = V_8 = F_7 ( V_9 ) ;
while ( V_2 -- ) {
F_8 ( ++ V_8 , V_9 ) ;
F_2 () ;
V_6 = F_9 ( V_9 + 0x10 ) ^ V_8 ;
if ( V_6 )
break;
}
F_8 ( V_7 , V_9 ) ;
return V_6 ;
}
static int F_10 ( void )
{
return F_4 ( V_10 ) ;
}
static int F_11 ( void )
{
return F_4 ( V_11 ) ;
}
static void F_12 ( void )
{
struct V_12 V_13 ;
F_13 ( & V_13 ) ;
V_13 . V_14 = 0x2401 ;
F_14 ( 0x15 , & V_13 , NULL ) ;
}
static void F_15 ( void )
{
F_1 () ;
F_16 ( 0xd1 , 0x64 ) ;
F_1 () ;
F_16 ( 0xdf , 0x60 ) ;
F_1 () ;
F_16 ( 0xff , 0x64 ) ;
F_1 () ;
}
static void F_17 ( void )
{
T_1 V_15 ;
V_15 = F_3 ( 0x92 ) ;
V_15 |= 0x02 ;
V_15 &= ~ 0x01 ;
F_16 ( V_15 , 0x92 ) ;
}
int F_18 ( void )
{
int V_2 = V_16 ;
int V_17 ;
while ( V_2 -- ) {
if ( F_10 () )
return 0 ;
F_12 () ;
if ( F_10 () )
return 0 ;
V_17 = F_1 () ;
if ( F_10 () )
return 0 ;
if ( ! V_17 ) {
F_15 () ;
if ( F_11 () )
return 0 ;
}
F_17 () ;
if ( F_11 () )
return 0 ;
}
return - 1 ;
}
