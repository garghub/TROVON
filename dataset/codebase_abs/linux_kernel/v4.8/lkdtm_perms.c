static void F_1 ( void )
{
return;
}
static void F_2 ( void )
{
F_3 ( L_1 ) ;
return;
}
static T_1 void F_4 ( void * V_1 , bool V_2 )
{
void (* F_5)( void ) = V_1 ;
F_3 ( L_2 , F_1 ) ;
F_1 () ;
if ( V_2 == V_3 ) {
memcpy ( V_1 , F_1 , V_4 ) ;
F_6 ( ( unsigned long ) V_1 ,
( unsigned long ) V_1 + V_4 ) ;
}
F_3 ( L_3 , F_5 ) ;
F_5 () ;
}
static void F_7 ( void * V_1 )
{
void (* F_5)( void ) = V_1 ;
F_3 ( L_2 , F_1 ) ;
F_1 () ;
if ( F_8 ( ( void V_5 * ) V_1 , F_1 , V_4 ) )
return;
F_6 ( ( unsigned long ) V_1 , ( unsigned long ) V_1 + V_4 ) ;
F_3 ( L_3 , F_5 ) ;
F_5 () ;
}
void F_9 ( void )
{
unsigned long * V_6 = ( unsigned long * ) & V_7 ;
F_3 ( L_4 , V_6 ) ;
* V_6 ^= 0xabcd1234 ;
}
void F_10 ( void )
{
unsigned long * V_6 = & V_8 ;
if ( ( * V_6 & 0xAA ) != 0xAA ) {
F_3 ( L_5 , V_6 ) ;
return;
}
F_3 ( L_6 , V_6 ) ;
* V_6 ^= 0xabcd1234 ;
}
void F_11 ( void )
{
T_2 V_9 ;
unsigned char * V_6 ;
V_9 = ( unsigned long ) F_2 - ( unsigned long ) F_1 ;
V_6 = ( unsigned char * ) F_2 ;
F_3 ( L_7 , V_9 , V_6 ) ;
memcpy ( V_6 , ( unsigned char * ) F_1 , V_9 ) ;
F_6 ( ( unsigned long ) V_6 , ( unsigned long ) ( V_6 + V_9 ) ) ;
F_2 () ;
}
void F_12 ( void )
{
F_4 ( V_10 , V_3 ) ;
}
void F_13 ( void )
{
T_3 V_11 [ V_4 ] ;
F_4 ( V_11 , V_3 ) ;
}
void F_14 ( void )
{
T_4 * V_12 = F_15 ( V_4 , V_13 ) ;
F_4 ( V_12 , V_3 ) ;
F_16 ( V_12 ) ;
}
void F_17 ( void )
{
T_4 * V_14 = F_18 ( V_4 ) ;
F_4 ( V_14 , V_3 ) ;
F_19 ( V_14 ) ;
}
void F_20 ( void )
{
F_4 ( V_15 , V_16 ) ;
}
void F_21 ( void )
{
unsigned long V_17 ;
V_17 = F_22 ( NULL , 0 , V_18 ,
V_19 | V_20 | V_21 ,
V_22 | V_23 , 0 ) ;
if ( V_17 >= V_24 ) {
F_23 ( L_8 ) ;
return;
}
F_7 ( ( void * ) V_17 ) ;
F_24 ( V_17 , V_18 ) ;
}
void F_25 ( void )
{
unsigned long V_17 , V_25 = 0 ;
unsigned long * V_6 ;
V_17 = F_22 ( NULL , 0 , V_18 ,
V_19 | V_20 | V_21 ,
V_22 | V_23 , 0 ) ;
if ( V_17 >= V_24 ) {
F_23 ( L_8 ) ;
return;
}
if ( F_8 ( ( void V_5 * ) V_17 , & V_25 , sizeof( V_25 ) ) ) {
F_23 ( L_9 ) ;
F_24 ( V_17 , V_18 ) ;
return;
}
V_6 = ( unsigned long * ) V_17 ;
F_3 ( L_10 , V_6 ) ;
V_25 = * V_6 ;
V_25 += 0xc0dec0de ;
F_3 ( L_11 , V_6 ) ;
* V_6 = V_25 ;
F_24 ( V_17 , V_18 ) ;
}
void T_5 F_26 ( void )
{
V_8 |= 0xAA ;
}
