static void F_1 ( int V_1 )
{
while ( V_1 -- )
F_2 () ;
}
static void F_3 ( unsigned int V_2 )
{
T_1 V_3 ;
if ( ! V_2 ) {
V_3 = 0x00 ;
} else {
T_2 div = 1193181 / V_2 ;
F_4 ( 0xb6 , 0x43 ) ;
F_2 () ;
F_4 ( div , 0x42 ) ;
F_2 () ;
F_4 ( div >> 8 , 0x42 ) ;
F_2 () ;
V_3 = 0x03 ;
}
F_5 ( 0x61 ) ;
F_2 () ;
F_4 ( V_3 , 0x61 ) ;
F_2 () ;
}
static void F_6 ( const char * V_4 )
{
char V_5 ;
while ( ( V_5 = * V_4 ++ ) ) {
switch ( V_5 ) {
case '.' :
F_3 ( V_6 ) ;
F_1 ( V_7 ) ;
F_3 ( 0 ) ;
F_1 ( V_7 ) ;
break;
case '-' :
F_3 ( V_8 ) ;
F_1 ( V_7 * 3 ) ;
F_3 ( 0 ) ;
F_1 ( V_7 ) ;
break;
default:
F_1 ( V_7 * 3 ) ;
break;
}
}
}
void main ( void )
{
if ( V_9 . V_10 != 0x12345678 )
while ( 1 ) ;
if ( V_9 . V_11 & 4 )
F_6 ( L_1 ) ;
if ( V_9 . V_11 & 1 )
asm volatile("lcallw $0xc000,$3");
if ( V_9 . V_11 & 2 ) {
F_7 ( 0 ) ;
F_8 ( V_9 . V_12 ) ;
}
}
