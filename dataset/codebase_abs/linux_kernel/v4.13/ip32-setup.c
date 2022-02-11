static inline unsigned char F_1 ( unsigned char V_1 )
{
if ( V_1 >= '0' && V_1 <= '9' )
return V_1 - '0' ;
if ( V_1 >= 'a' && V_1 <= 'f' )
return V_1 - 'a' + 10 ;
return 0 ;
}
static inline void F_2 ( unsigned char * V_2 , unsigned char * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ ) {
unsigned char V_5 ;
if( * V_3 == ':' )
V_3 ++ ;
V_5 = F_1 ( * V_3 ++ ) << 4 ;
V_5 |= ( F_1 ( * V_3 ++ ) ) ;
V_2 [ V_4 ] = V_5 ;
}
}
void T_1 F_3 ( void )
{
F_4 ( V_6 L_1 ) ;
F_5 ( 0 ) ;
V_7 -> V_8 = 0 ;
while ( V_7 -> V_8 < V_9 * V_10 / 1000 ) ;
V_11 = F_6 () * 1000 / V_10 ;
F_4 ( L_2 , V_11 * 2 / 1000000 ) ;
}
void T_1 F_7 ( void )
{
V_12 = V_13 ;
#ifdef F_8
{
char * V_14 = F_9 ( L_3 ) ;
F_2 ( V_15 , V_14 ) ;
}
#endif
#if F_10 ( V_16 )
{
char * V_17 = F_9 ( L_4 ) ;
if ( V_17 && * V_17 == 'd' ) {
static char V_18 [ 8 ] V_19 ;
char * V_20 = F_9 ( L_5 ) ;
if ( V_20 )
strcpy ( V_18 , V_20 ) ;
F_11 ( L_6 , * ( V_17 + 1 ) == '2' ? 1 : 0 ,
V_20 ? V_18 : NULL ) ;
}
}
#endif
}
