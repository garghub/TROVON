void F_1 ( void )
{
F_2 ( L_1 , F_3 () ) ;
F_2 ( L_2 , F_4 () ) ;
F_2 ( L_3 , F_5 () ) ;
if ( V_1 )
F_2 ( L_4 , F_6 () ) ;
}
static void F_7 ( int V_2 , int V_3 )
{
int V_4 ;
unsigned int V_5 ;
unsigned long V_6 , V_7 , V_8 ;
V_8 = F_8 ( & V_9 ) ;
V_5 = F_4 () & V_8 ;
for ( V_4 = V_2 ; V_4 <= V_3 ; V_4 ++ ) {
F_9 ( V_4 << 8 ) ;
__asm__ __volatile__(
".set\tnoreorder\n\t"
"tlbr\n\t"
"nop\n\t"
".set\treorder");
V_6 = F_4 () ;
V_7 = F_5 () ;
if ( ( V_6 & V_10 ) != V_11 &&
( V_7 & V_12 ||
( V_6 & V_8 ) == V_5 ) ) {
F_10 ( L_5 , V_4 ) ;
F_10 ( L_6
L_7 ,
V_6 & V_10 ,
V_6 & V_8 ,
V_7 & V_10 ,
( V_7 & V_13 ) ? 1 : 0 ,
( V_7 & V_14 ) ? 1 : 0 ,
( V_7 & V_15 ) ? 1 : 0 ,
( V_7 & V_12 ) ? 1 : 0 ) ;
}
}
F_10 ( L_8 ) ;
F_11 ( V_5 ) ;
}
void F_12 ( void )
{
F_7 ( 0 , V_9 . V_16 - 1 ) ;
}
