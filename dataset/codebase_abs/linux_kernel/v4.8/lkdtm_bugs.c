static int F_1 ( int V_1 )
{
char V_2 [ V_3 ] ;
memset ( V_2 , ( V_1 & 0xff ) | 0x1 , V_3 ) ;
if ( ! V_1 )
return 0 ;
else
return F_1 ( V_1 - 1 ) ;
}
void T_1 F_2 ( int * V_4 )
{
if ( * V_4 < 0 )
* V_4 = V_5 ;
else
V_5 = * V_4 ;
}
void F_3 ( void )
{
F_4 ( L_1 ) ;
}
void F_5 ( void )
{
F_6 () ;
}
void F_7 ( void )
{
F_8 ( 1 ) ;
}
void F_9 ( void )
{
* ( ( int * ) 0 ) = 0 ;
}
void F_10 ( void )
{
for (; ; )
;
}
void F_11 ( void )
{
( void ) F_1 ( V_5 ) ;
}
T_2 void F_12 ( void )
{
char V_6 [ 8 ] ;
memset ( ( void * ) V_6 , 0 , 64 ) ;
}
void F_13 ( void )
{
static T_3 V_6 [ 5 ] V_7 ( ( F_14 ( 4 ) ) ) = { 1 , 2 , 3 , 4 , 5 } ;
T_4 * V_8 ;
T_4 V_9 = 0x12345678 ;
V_8 = ( T_4 * ) ( V_6 + 1 ) ;
if ( * V_8 == 0 )
V_9 = 0x87654321 ;
* V_8 = V_9 ;
}
void F_15 ( void )
{
F_16 () ;
for (; ; )
F_17 () ;
}
void F_18 ( void )
{
F_19 () ;
for (; ; )
F_17 () ;
}
void F_20 ( void )
{
F_21 ( & V_10 ) ;
F_22 ( & V_10 ) ;
}
void F_23 ( void )
{
F_24 ( V_11 ) ;
F_25 () ;
}
void F_26 ( void )
{
T_5 V_12 = F_27 ( V_13 ) ;
F_28 ( L_2 ) ;
F_29 ( & V_12 ) ;
F_30 ( & V_12 ) ;
F_28 ( L_3 ) ;
F_30 ( & V_12 ) ;
}
void F_31 ( void )
{
T_5 V_14 = F_27 ( V_15 ) ;
F_28 ( L_4 ) ;
F_30 ( & V_14 ) ;
F_29 ( & V_14 ) ;
F_28 ( L_5 ) ;
F_29 ( & V_14 ) ;
}
