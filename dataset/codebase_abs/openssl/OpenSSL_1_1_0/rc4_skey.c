const char * F_1 ( void )
{
if ( sizeof( V_1 ) == 1 )
return ( L_1 ) ;
else
return ( L_2 ) ;
}
void F_2 ( T_1 * V_2 , int V_3 , const unsigned char * V_4 )
{
register V_1 V_5 ;
register int V_6 , V_7 ;
register V_1 * V_8 ;
unsigned int V_9 ;
V_8 = & ( V_2 -> V_4 [ 0 ] ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_6 = V_7 = 0 ;
#define F_3 ( V_8 , T_2 ) { \
tmp=d[(n)]; \
id2 = (data[id1] + tmp + id2) & 0xff; \
if (++id1 == len) id1=0; \
d[(n)]=d[id2]; \
d[id2]=tmp; }
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ )
V_8 [ V_9 ] = V_9 ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 += 4 ) {
F_3 ( V_8 , V_9 + 0 ) ;
F_3 ( V_8 , V_9 + 1 ) ;
F_3 ( V_8 , V_9 + 2 ) ;
F_3 ( V_8 , V_9 + 3 ) ;
}
}
