static void F_1 ( void )
{
int V_1 ;
if ( ! V_2 )
return;
for ( V_1 = 0x30 ; V_1 < 0x70 ; V_1 += 0x10 ) {
F_2 ( L_1 ,
V_1 >> 4 ,
( int ) F_3 ( V_3 + V_1 ) ,
( int ) F_3 ( V_4 + V_1 ) ) ;
}
}
static T_1 void F_4 ( void )
{
int V_1 ;
F_2 ( L_2 ) ;
for ( V_1 = 0 ; V_1 < 9 ; V_1 ++ ) {
F_5 ( V_5 + ( V_1 << 4 ) , 0x8800 ) ;
F_5 ( V_5 + ( V_1 << 4 ) , 0x1000 ) ;
F_5 ( V_6 + ( V_1 << 5 ) , 0x1100 ) ;
F_5 ( V_6 + ( V_1 << 5 ) + 0x10 , 0x1100 ) ;
}
F_2 ( L_3 ) ;
}
void T_1 F_6 ( void )
{
int V_1 ;
if ( V_7 -> V_8 != V_9
&& V_7 -> V_8 != V_10 )
{
V_2 = NULL ;
return;
}
V_2 = ( void * ) V_11 ;
F_2 ( L_4 , V_2 ) ;
F_4 () ;
#ifdef F_7
F_1 () ;
#endif
for ( V_1 = 0x30 ; V_1 < 0x70 ; V_1 += 0x10 ) {
F_8 ( V_4 + V_1 , 0x0F ) ;
F_8 ( V_3 + V_1 , 0x0F ) ;
}
}
static void F_9 ( struct V_12 * V_13 )
{
unsigned int V_14 = ( unsigned int ) F_10 ( V_13 ) ;
unsigned int V_15 = F_11 ( V_13 ) ;
int V_16 = V_3 + V_14 ;
int V_17 = V_4 + V_14 ;
int V_18 ;
unsigned char V_19 , V_20 ;
V_20 = F_3 ( V_16 ) & F_3 ( V_17 ) & 0xF ;
if ( ! V_20 )
return;
V_18 = V_15 << 3 ;
V_19 = 1 ;
do {
if ( V_20 & V_19 ) {
F_8 ( V_16 , V_19 ) ;
F_12 ( V_18 ) ;
}
V_18 ++ ;
V_19 <<= 1 ;
} while ( V_20 >= V_19 );
}
void T_1 F_13 ( void )
{
F_14 ( V_21 , F_9 , ( void * ) 0x30 ) ;
F_14 ( V_22 , F_9 , ( void * ) 0x40 ) ;
F_14 ( V_23 , F_9 , ( void * ) 0x50 ) ;
F_14 ( V_24 , F_9 , ( void * ) 0x60 ) ;
}
void F_15 ( int V_15 ) {
int V_25 = F_16 ( V_15 ) ;
int V_26 = F_17 ( V_15 ) ;
int V_17 = V_4 + ( V_25 << 4 ) ;
F_8 ( V_17 , ( 1 << V_26 ) | 0x80 ) ;
}
void F_18 ( int V_15 ) {
int V_25 = F_16 ( V_15 ) ;
int V_26 = F_17 ( V_15 ) ;
int V_17 = V_4 + ( V_25 << 4 ) ;
F_8 ( V_17 , 1 << V_26 ) ;
}
