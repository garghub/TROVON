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
* ( ( volatile int * ) 0 ) = 0 ;
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
static T_2 void F_12 ( void * V_6 )
{
memset ( V_6 , 'a' , 64 ) ;
}
T_2 void F_13 ( void )
{
char V_7 [ 8 ] ;
F_12 ( & V_7 ) ;
F_14 ( L_2 , V_7 ) ;
}
void F_15 ( void )
{
static T_3 V_7 [ 5 ] V_8 ( ( F_16 ( 4 ) ) ) = { 1 , 2 , 3 , 4 , 5 } ;
T_4 * V_9 ;
T_4 V_10 = 0x12345678 ;
V_9 = ( T_4 * ) ( V_7 + 1 ) ;
if ( * V_9 == 0 )
V_10 = 0x87654321 ;
* V_9 = V_10 ;
}
void F_17 ( void )
{
F_18 () ;
for (; ; )
F_19 () ;
}
void F_20 ( void )
{
F_21 () ;
for (; ; )
F_19 () ;
}
void F_22 ( void )
{
F_23 ( & V_11 ) ;
F_24 ( & V_11 ) ;
}
void F_25 ( void )
{
F_26 ( V_12 ) ;
F_27 () ;
}
void F_28 ( void )
{
T_5 V_13 = F_29 ( V_14 - 1 ) ;
F_14 ( L_3 ) ;
F_30 ( & V_13 ) ;
F_31 ( & V_13 ) ;
F_14 ( L_4 ) ;
F_31 ( & V_13 ) ;
F_31 ( & V_13 ) ;
if ( F_32 ( & V_13 ) == V_14 )
F_33 ( L_5 ) ;
else
F_33 ( L_6 ) ;
}
void F_34 ( void )
{
T_5 V_13 = F_29 ( V_14 - 1 ) ;
F_14 ( L_3 ) ;
F_30 ( & V_13 ) ;
F_31 ( & V_13 ) ;
F_14 ( L_7 ) ;
F_35 ( 2 , & V_13 ) ;
if ( F_32 ( & V_13 ) == V_14 )
F_33 ( L_5 ) ;
else
F_33 ( L_6 ) ;
}
void F_36 ( void )
{
T_5 V_15 = F_29 ( 1 ) ;
F_14 ( L_8 ) ;
F_30 ( & V_15 ) ;
if ( F_32 ( & V_15 ) == 0 )
F_33 ( L_9 ) ;
else
F_33 ( L_10 ) ;
}
void F_37 ( void )
{
T_5 V_15 = F_29 ( 1 ) ;
F_14 ( L_11 ) ;
if ( ! F_38 ( 2 , & V_15 ) )
F_14 ( L_12 ) ;
if ( F_32 ( & V_15 ) == 1 )
F_33 ( L_13 ) ;
else
F_33 ( L_6 ) ;
}
void F_39 ( void )
{
T_5 V_15 = F_29 ( 0 ) ;
F_14 ( L_14 ) ;
F_31 ( & V_15 ) ;
if ( F_32 ( & V_15 ) == 0 )
F_33 ( L_9 ) ;
else
F_33 ( L_15 ) ;
}
void F_40 ( void )
{
T_5 V_15 = F_29 ( 0 ) ;
F_14 ( L_16 ) ;
F_35 ( 2 , & V_15 ) ;
if ( F_32 ( & V_15 ) == 0 )
F_33 ( L_9 ) ;
else
F_33 ( L_15 ) ;
}
void F_41 ( void )
{
F_42 ( V_16 ) ;
struct V_17 V_18 , V_19 ;
void * V_20 [ 2 ] = { } ;
void * V_21 = & V_20 ;
F_14 ( L_17 ) ;
F_43 ( & V_18 . V_22 , & V_16 ) ;
F_14 ( L_18 ) ;
V_16 . V_23 = V_21 ;
F_43 ( & V_19 . V_22 , & V_16 ) ;
if ( V_20 [ 0 ] == NULL && V_20 [ 1 ] == NULL )
F_33 ( L_19 ) ;
else
F_33 ( L_20 ) ;
}
void F_44 ( void )
{
F_42 ( V_16 ) ;
struct V_17 V_24 ;
void * V_20 [ 2 ] = { } ;
void * V_21 = & V_20 ;
F_43 ( & V_24 . V_22 , & V_16 ) ;
F_14 ( L_21 ) ;
F_45 ( & V_24 . V_22 ) ;
F_14 ( L_22 ) ;
F_43 ( & V_24 . V_22 , & V_16 ) ;
V_24 . V_22 . V_23 = V_21 ;
F_45 ( & V_24 . V_22 ) ;
if ( V_20 [ 0 ] == NULL && V_20 [ 1 ] == NULL )
F_33 ( L_19 ) ;
else
F_33 ( L_23 ) ;
}
void F_46 ( void )
{
F_14 ( L_24 ) ;
F_47 ( V_25 ) ;
F_48 ( V_26 , V_27 ) ;
}
