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
int V_5 ;
void (* F_5)( void ) = V_1 ;
F_3 ( L_2 , F_1 ) ;
F_1 () ;
V_5 = F_8 ( V_6 , ( unsigned long ) V_1 , F_1 ,
V_4 , V_7 ) ;
if ( V_5 < V_4 )
return;
F_3 ( L_3 , F_5 ) ;
F_5 () ;
}
void F_9 ( void )
{
unsigned long * V_8 = ( unsigned long * ) & V_9 ;
F_3 ( L_4 , V_8 ) ;
* V_8 ^= 0xabcd1234 ;
}
void F_10 ( void )
{
unsigned long * V_8 = & V_10 ;
if ( ( * V_8 & 0xAA ) != 0xAA ) {
F_3 ( L_5 , V_8 ) ;
return;
}
F_3 ( L_6 , V_8 ) ;
* V_8 ^= 0xabcd1234 ;
}
void F_11 ( void )
{
T_2 V_11 ;
unsigned char * V_8 ;
V_11 = ( unsigned long ) F_2 - ( unsigned long ) F_1 ;
V_8 = ( unsigned char * ) F_2 ;
F_3 ( L_7 , V_11 , V_8 ) ;
memcpy ( V_8 , ( unsigned char * ) F_1 , V_11 ) ;
F_6 ( ( unsigned long ) V_8 , ( unsigned long ) ( V_8 + V_11 ) ) ;
F_2 () ;
}
void F_12 ( void )
{
F_4 ( V_12 , V_3 ) ;
}
void F_13 ( void )
{
T_3 V_13 [ V_4 ] ;
F_4 ( V_13 , V_3 ) ;
}
void F_14 ( void )
{
T_4 * V_14 = F_15 ( V_4 , V_15 ) ;
F_4 ( V_14 , V_3 ) ;
F_16 ( V_14 ) ;
}
void F_17 ( void )
{
T_4 * V_16 = F_18 ( V_4 ) ;
F_4 ( V_16 , V_3 ) ;
F_19 ( V_16 ) ;
}
void F_20 ( void )
{
F_4 ( V_17 , V_18 ) ;
}
void F_21 ( void )
{
unsigned long V_19 ;
V_19 = F_22 ( NULL , 0 , V_20 ,
V_21 | V_22 | V_23 ,
V_24 | V_25 , 0 ) ;
if ( V_19 >= V_26 ) {
F_23 ( L_8 ) ;
return;
}
F_7 ( ( void * ) V_19 ) ;
F_24 ( V_19 , V_20 ) ;
}
void F_25 ( void )
{
unsigned long V_19 , V_27 = 0 ;
unsigned long * V_8 ;
V_19 = F_22 ( NULL , 0 , V_20 ,
V_21 | V_22 | V_23 ,
V_24 | V_25 , 0 ) ;
if ( V_19 >= V_26 ) {
F_23 ( L_8 ) ;
return;
}
if ( F_26 ( ( void V_28 * ) V_19 , & V_27 , sizeof( V_27 ) ) ) {
F_23 ( L_9 ) ;
F_24 ( V_19 , V_20 ) ;
return;
}
V_8 = ( unsigned long * ) V_19 ;
F_3 ( L_10 , V_8 ) ;
V_27 = * V_8 ;
V_27 += 0xc0dec0de ;
F_3 ( L_11 , V_8 ) ;
* V_8 = V_27 ;
F_24 ( V_19 , V_20 ) ;
}
void T_5 F_27 ( void )
{
V_10 |= 0xAA ;
}
