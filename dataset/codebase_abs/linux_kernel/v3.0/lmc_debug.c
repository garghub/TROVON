void F_1 ( char * type , unsigned char * V_1 , int V_2 )
{
int V_3 = 1 ;
char V_4 [ 80 ] , * V_5 ;
sprintf ( V_4 , V_6 L_1 , type ) ;
V_5 = V_4 + strlen ( V_4 ) ;
if( V_2 > 240 ) {
F_2 ( V_6 L_2 , V_2 ) ;
V_2 = 240 ;
}
else{
F_2 ( V_6 L_3 , V_2 ) ;
}
while( V_2 > 0 )
{
sprintf ( V_5 , L_4 , * V_1 ) ;
V_5 += 3 ;
V_1 ++ ;
if( ! ( V_3 % 20 ) )
{
sprintf ( V_5 , L_5 ) ;
F_2 ( V_4 ) ;
sprintf ( V_4 , V_6 L_1 , type ) ;
V_5 = V_4 + strlen ( V_4 ) ;
}
V_3 ++ ;
V_2 -- ;
}
sprintf ( V_5 , L_5 ) ;
F_2 ( V_4 ) ;
}
void F_3 ( T_1 V_7 , T_1 V_8 , T_1 V_9 )
{
V_10 [ V_11 ++ ] = V_7 ;
V_10 [ V_11 ++ ] = V_8 ;
V_10 [ V_11 ++ ] = V_9 ;
V_10 [ V_11 ++ ] = V_12 ;
V_11 &= ( V_13 * V_14 ) - 1 ;
}
void F_4 ( struct V_15 * V_16 , char * V_17 ) {
#ifdef F_5
unsigned long V_18 = V_12 + 3 ;
if( F_6 () ) {
F_2 ( L_6 , V_16 -> V_19 , V_17 ) ;
}
else {
F_2 ( L_7 , V_16 -> V_19 , V_17 ) ;
while( F_7 ( V_12 , V_18 ) )
F_8 () ;
}
#endif
}
