const char * F_1 ( void )
{
#ifdef F_2
if ( sizeof( V_1 ) == 1 )
return ( L_1 ) ;
else
return ( L_2 ) ;
#else
if ( sizeof( V_1 ) == 1 )
return ( L_3 ) ;
else
return ( L_4 ) ;
#endif
}
void F_3 ( T_1 * V_2 , int V_3 , const unsigned char * V_4 )
{
register V_1 V_5 ;
register int V_6 , V_7 ;
register V_1 * V_8 ;
unsigned int V_9 ;
V_8 = & ( V_2 -> V_4 [ 0 ] ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_6 = V_7 = 0 ;
#define F_4 ( V_8 , T_2 ) { \
tmp=d[(n)]; \
id2 = (data[id1] + tmp + id2) & 0xff; \
if (++id1 == len) id1=0; \
d[(n)]=d[id2]; \
d[id2]=tmp; }
#if F_5 ( V_12 ) && ! F_5 ( V_13 )
# if F_5 ( V_14 ) || F_5 ( V_15 ) || F_5 ( V_16 ) || \
F_5 ( V_17 ) || \
F_5 ( V_18 ) || F_5 ( V_19 ) || F_5 ( V_20 )
if ( sizeof( V_1 ) > 1 ) {
if ( V_21 & ( 1 << 28 ) ) {
unsigned char * V_22 = ( unsigned char * ) V_8 ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) V_22 [ V_9 ] = V_9 ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) F_4 ( V_22 , V_9 ) ;
V_8 [ 256 / sizeof( V_1 ) ] = - 1 ;
return;
}
}
# endif
#endif
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) V_8 [ V_9 ] = V_9 ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 += 4 )
{
F_4 ( V_8 , V_9 + 0 ) ;
F_4 ( V_8 , V_9 + 1 ) ;
F_4 ( V_8 , V_9 + 2 ) ;
F_4 ( V_8 , V_9 + 3 ) ;
}
}
