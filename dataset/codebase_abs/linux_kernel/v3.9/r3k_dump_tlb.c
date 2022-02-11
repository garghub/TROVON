static void F_1 ( int V_1 , int V_2 )
{
int V_3 ;
unsigned int V_4 ;
unsigned long V_5 , V_6 ;
V_4 = F_2 () & 0xfc0 ;
for ( V_3 = V_1 ; V_3 <= V_2 ; V_3 ++ ) {
F_3 ( V_3 << 8 ) ;
__asm__ __volatile__(
".set\tnoreorder\n\t"
"tlbr\n\t"
"nop\n\t"
".set\treorder");
V_5 = F_2 () ;
V_6 = F_4 () ;
if ( ( V_5 & 0xffffe000 ) != 0x80000000
&& ( V_5 & 0xfc0 ) == V_4 ) {
F_5 ( L_1 , V_3 ) ;
F_5 ( L_2
L_3 ,
( V_5 & 0xffffe000 ) ,
V_5 & 0xfc0 ,
V_6 & V_7 ,
( V_6 & ( 1 << 11 ) ) ? 1 : 0 ,
( V_6 & ( 1 << 10 ) ) ? 1 : 0 ,
( V_6 & ( 1 << 9 ) ) ? 1 : 0 ,
( V_6 & ( 1 << 8 ) ) ? 1 : 0 ) ;
}
}
F_5 ( L_4 ) ;
F_6 ( V_4 ) ;
}
void F_7 ( void )
{
F_1 ( 0 , V_8 . V_9 - 1 ) ;
}
