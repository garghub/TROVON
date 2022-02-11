static void F_1 ( int V_1 )
{
V_2 = 0 ;
longjmp ( V_3 , 1 ) ;
}
void F_2 ( void )
{
struct V_4 V_5 , V_6 ;
F_3 ( V_7 L_1 ) ;
V_6 . V_8 = F_1 ;
V_6 . V_9 = V_10 ;
F_4 ( & V_6 . V_11 ) ;
V_4 ( V_12 , & V_6 , & V_5 ) ;
if ( setjmp ( V_3 ) == 0 ) {
unsigned long V_13 = 0 ;
__asm__ __volatile__("cmovz %0, %1" : "=r" (foo) : "0" (foo));
F_3 ( V_14 L_2 ) ;
} else
F_3 ( V_14 L_3 ) ;
V_4 ( V_12 , & V_5 , & V_6 ) ;
}
void F_5 ( int V_1 , struct V_15 * V_16 )
{
unsigned char V_17 [ 2 ] ;
if ( ( V_1 != V_12 ) || ( F_6 () != 1 ) )
return;
if ( F_7 ( V_17 , ( void * ) F_8 ( V_16 ) , 2 ) ) {
F_3 ( V_18 L_4
L_5 ) ;
return;
}
if ( ( V_17 [ 0 ] != 0x0f ) || ( ( V_17 [ 1 ] & 0xf0 ) != 0x40 ) )
return;
if ( V_2 == 0 )
F_3 ( V_18 L_6
L_7
L_8 ) ;
else if ( V_2 == 1 )
F_3 ( V_18 L_6
L_9 ) ;
else
F_3 ( V_18 L_10 ,
V_2 ) ;
}
