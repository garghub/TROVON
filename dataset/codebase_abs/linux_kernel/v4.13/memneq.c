static inline unsigned long
F_1 ( const void * V_1 , const void * V_2 , T_1 V_3 )
{
unsigned long V_4 = 0 ;
#if F_2 ( V_5 )
while ( V_3 >= sizeof( unsigned long ) ) {
V_4 |= * ( unsigned long * ) V_1 ^ * ( unsigned long * ) V_2 ;
F_3 ( V_4 ) ;
V_1 += sizeof( unsigned long ) ;
V_2 += sizeof( unsigned long ) ;
V_3 -= sizeof( unsigned long ) ;
}
#endif
while ( V_3 > 0 ) {
V_4 |= * ( unsigned char * ) V_1 ^ * ( unsigned char * ) V_2 ;
F_3 ( V_4 ) ;
V_1 += 1 ;
V_2 += 1 ;
V_3 -= 1 ;
}
return V_4 ;
}
static inline unsigned long F_4 ( const void * V_1 , const void * V_2 )
{
unsigned long V_4 = 0 ;
#ifdef V_5
if (sizeof( unsigned long ) == 8 ) {
V_4 |= * ( unsigned long * ) ( V_1 ) ^ * ( unsigned long * ) ( V_2 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned long * ) ( V_1 + 8 ) ^ * ( unsigned long * ) ( V_2 + 8 ) ;
F_3 ( V_4 ) ;
} else if (sizeof( unsigned int ) == 4 ) {
V_4 |= * ( unsigned int * ) ( V_1 ) ^ * ( unsigned int * ) ( V_2 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned int * ) ( V_1 + 4 ) ^ * ( unsigned int * ) ( V_2 + 4 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned int * ) ( V_1 + 8 ) ^ * ( unsigned int * ) ( V_2 + 8 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned int * ) ( V_1 + 12 ) ^ * ( unsigned int * ) ( V_2 + 12 ) ;
F_3 ( V_4 ) ;
} else
#endif
{
V_4 |= * ( unsigned char * ) ( V_1 ) ^ * ( unsigned char * ) ( V_2 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 1 ) ^ * ( unsigned char * ) ( V_2 + 1 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 2 ) ^ * ( unsigned char * ) ( V_2 + 2 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 3 ) ^ * ( unsigned char * ) ( V_2 + 3 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 4 ) ^ * ( unsigned char * ) ( V_2 + 4 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 5 ) ^ * ( unsigned char * ) ( V_2 + 5 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 6 ) ^ * ( unsigned char * ) ( V_2 + 6 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 7 ) ^ * ( unsigned char * ) ( V_2 + 7 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 8 ) ^ * ( unsigned char * ) ( V_2 + 8 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 9 ) ^ * ( unsigned char * ) ( V_2 + 9 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 10 ) ^ * ( unsigned char * ) ( V_2 + 10 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 11 ) ^ * ( unsigned char * ) ( V_2 + 11 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 12 ) ^ * ( unsigned char * ) ( V_2 + 12 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 13 ) ^ * ( unsigned char * ) ( V_2 + 13 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 14 ) ^ * ( unsigned char * ) ( V_2 + 14 ) ;
F_3 ( V_4 ) ;
V_4 |= * ( unsigned char * ) ( V_1 + 15 ) ^ * ( unsigned char * ) ( V_2 + 15 ) ;
F_3 ( V_4 ) ;
}
return V_4 ;
}
T_2 unsigned long F_5 ( const void * V_1 , const void * V_2 ,
T_1 V_3 )
{
switch ( V_3 ) {
case 16 :
return F_4 ( V_1 , V_2 ) ;
default:
return F_1 ( V_1 , V_2 , V_3 ) ;
}
}
