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
memset ( V_6 , '\xff' , 64 ) ;
}
T_2 void F_13 ( void )
{
char V_7 [ 8 ] V_8 ( sizeof( void * ) ) ;
F_12 ( & V_7 ) ;
F_14 ( L_2 ) ;
}
T_2 void F_15 ( void )
{
union {
unsigned short V_9 [ 4 ] ;
unsigned long * V_10 ;
} V_7 V_8 ( sizeof( void * ) ) ;
F_12 ( & V_7 ) ;
F_14 ( L_3 ) ;
}
void F_16 ( void )
{
static T_3 V_7 [ 5 ] V_11 ( ( F_17 ( 4 ) ) ) = { 1 , 2 , 3 , 4 , 5 } ;
T_4 * V_12 ;
T_4 V_13 = 0x12345678 ;
V_12 = ( T_4 * ) ( V_7 + 1 ) ;
if ( * V_12 == 0 )
V_13 = 0x87654321 ;
* V_12 = V_13 ;
}
void F_18 ( void )
{
F_19 () ;
for (; ; )
F_20 () ;
}
void F_21 ( void )
{
F_22 () ;
for (; ; )
F_20 () ;
}
void F_23 ( void )
{
F_24 ( & V_14 ) ;
F_25 ( & V_14 ) ;
}
void F_26 ( void )
{
F_27 ( V_15 ) ;
F_28 () ;
}
void F_29 ( void )
{
F_30 ( V_16 ) ;
struct V_17 V_18 , V_19 ;
void * V_20 [ 2 ] = { } ;
void * V_21 = & V_20 ;
F_14 ( L_4 ) ;
F_31 ( & V_18 . V_22 , & V_16 ) ;
F_14 ( L_5 ) ;
V_16 . V_23 = V_21 ;
F_31 ( & V_19 . V_22 , & V_16 ) ;
if ( V_20 [ 0 ] == NULL && V_20 [ 1 ] == NULL )
F_32 ( L_6 ) ;
else
F_32 ( L_7 ) ;
}
void F_33 ( void )
{
F_30 ( V_16 ) ;
struct V_17 V_24 ;
void * V_20 [ 2 ] = { } ;
void * V_21 = & V_20 ;
F_31 ( & V_24 . V_22 , & V_16 ) ;
F_14 ( L_8 ) ;
F_34 ( & V_24 . V_22 ) ;
F_14 ( L_9 ) ;
F_31 ( & V_24 . V_22 , & V_16 ) ;
V_24 . V_22 . V_23 = V_21 ;
F_34 ( & V_24 . V_22 ) ;
if ( V_20 [ 0 ] == NULL && V_20 [ 1 ] == NULL )
F_32 ( L_6 ) ;
else
F_32 ( L_10 ) ;
}
void F_35 ( void )
{
F_14 ( L_11 ) ;
F_36 ( V_25 ) ;
F_37 ( V_26 , V_27 ) ;
}
void F_38 ( void )
{
const unsigned char * V_6 = F_39 ( V_27 ) ;
const unsigned char * V_10 = V_6 - 1 ;
volatile unsigned char V_28 ;
F_14 ( L_12 ) ;
V_28 = * V_10 ;
F_32 ( L_13 ) ;
}
void F_40 ( void )
{
const unsigned char * V_6 = F_39 ( V_27 ) ;
const unsigned char * V_10 = V_6 + V_29 ;
volatile unsigned char V_28 ;
F_14 ( L_14 ) ;
V_28 = * V_10 ;
F_32 ( L_15 ) ;
}
