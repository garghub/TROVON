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
memset ( ( void * ) V_6 , 'a' , 64 ) ;
F_13 ( L_2 , V_6 ) ;
}
void F_14 ( void )
{
static T_3 V_6 [ 5 ] V_7 ( ( F_15 ( 4 ) ) ) = { 1 , 2 , 3 , 4 , 5 } ;
T_4 * V_8 ;
T_4 V_9 = 0x12345678 ;
V_8 = ( T_4 * ) ( V_6 + 1 ) ;
if ( * V_8 == 0 )
V_9 = 0x87654321 ;
* V_8 = V_9 ;
}
void F_16 ( void )
{
F_17 () ;
for (; ; )
F_18 () ;
}
void F_19 ( void )
{
F_20 () ;
for (; ; )
F_18 () ;
}
void F_21 ( void )
{
F_22 ( & V_10 ) ;
F_23 ( & V_10 ) ;
}
void F_24 ( void )
{
F_25 ( V_11 ) ;
F_26 () ;
}
void F_27 ( void )
{
T_5 V_12 = F_28 ( V_13 ) ;
F_13 ( L_3 ) ;
F_29 ( & V_12 ) ;
F_30 ( & V_12 ) ;
F_13 ( L_4 ) ;
F_30 ( & V_12 ) ;
}
void F_31 ( void )
{
T_5 V_14 = F_28 ( V_15 ) ;
F_13 ( L_5 ) ;
F_30 ( & V_14 ) ;
F_29 ( & V_14 ) ;
F_13 ( L_6 ) ;
F_29 ( & V_14 ) ;
}
void F_32 ( void )
{
F_33 ( V_16 ) ;
struct V_17 V_18 , V_19 ;
void * V_20 [ 2 ] = { } ;
void * V_21 = & V_20 ;
F_13 ( L_7 ) ;
F_34 ( & V_18 . V_22 , & V_16 ) ;
F_13 ( L_8 ) ;
V_16 . V_23 = V_21 ;
F_34 ( & V_19 . V_22 , & V_16 ) ;
if ( V_20 [ 0 ] == NULL && V_20 [ 1 ] == NULL )
F_35 ( L_9 ) ;
else
F_35 ( L_10 ) ;
}
void F_36 ( void )
{
F_33 ( V_16 ) ;
struct V_17 V_24 ;
void * V_20 [ 2 ] = { } ;
void * V_21 = & V_20 ;
F_34 ( & V_24 . V_22 , & V_16 ) ;
F_13 ( L_11 ) ;
F_37 ( & V_24 . V_22 ) ;
F_13 ( L_12 ) ;
F_34 ( & V_24 . V_22 , & V_16 ) ;
V_24 . V_22 . V_23 = V_21 ;
F_37 ( & V_24 . V_22 ) ;
if ( V_20 [ 0 ] == NULL && V_20 [ 1 ] == NULL )
F_35 ( L_9 ) ;
else
F_35 ( L_13 ) ;
}
