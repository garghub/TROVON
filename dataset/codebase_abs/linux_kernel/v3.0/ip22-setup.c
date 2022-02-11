void T_1 F_1 ( void )
{
char * V_1 ;
char * V_2 ;
V_3 = V_4 ;
F_2 () ;
F_3 () ;
#ifdef F_4
F_5 () ;
#endif
F_6 ( ( unsigned long ) F_7 ( 0x00080000 ,
0x1fffffff - 0x00080000 ) ) ;
V_1 = F_8 ( L_1 ) ;
V_2 = F_8 ( L_2 ) ;
if ( ( V_1 && * V_1 == 'd' ) || ( V_2 && * V_2 == 's' ) ) {
static char V_5 [ 8 ] V_6 ;
char * V_7 = F_8 ( L_3 ) ;
if ( V_7 )
strcpy ( V_5 , V_7 ) ;
F_9 ( L_4 , * ( V_1 + 1 ) == '2' ? 1 : 0 ,
V_7 ? V_5 : NULL ) ;
} else if ( ! V_1 || * V_1 != 'g' ) {
V_8 |= V_9 ;
F_9 ( L_5 , 0 , NULL ) ;
}
#if F_10 ( V_10 ) && F_10 ( V_11 )
{
T_2 * V_12 ;
T_2 * (* F_11)( void ) = ( void * ) ( long )
* ( ( V_13 * ) ( long ) ( ( V_14 ) -> V_15 + 0x20 ) ) ;
V_12 = F_11 () ;
V_16 = ( ( V_12 [ 1 ] >= 0xa0000000
&& V_12 [ 1 ] <= 0xc0000000 )
? V_12 [ 1 ] - 0xa0000000 : 0 ) ;
if ( V_16 == 0x1f0f0000 || V_16 == 0x1f4f0000 ) {
V_17 = & V_18 ;
}
}
#endif
}
