static void T_1 F_1 ( char * V_1 , int V_2 )
{
extern unsigned long V_3 ;
unsigned long * V_4 ;
unsigned long V_5 ;
unsigned long V_6 , V_7 ;
unsigned long V_8 , V_9 ;
V_4 = ( unsigned long * ) V_3 ;
V_5 = V_4 [ 1 ] ;
V_6 = V_4 [ 2 ] ;
V_7 = V_4 [ 3 ] ;
V_8 = V_4 [ 4 ] ;
V_9 = V_4 [ 5 ] ;
if ( V_8 && V_9 )
strncpy ( V_1 , ( const char * ) V_8 , V_2 ) ;
#if F_2 ( V_10 )
if ( V_6 && V_7 &&
( V_7 > V_6 ) ) {
V_11 = V_6 ;
V_12 = V_7 ;
V_13 = V_14 ;
F_3 ( L_1 , V_11 , V_12 ) ;
}
#endif
}
T_1 void F_4 ( char * V_1 , int V_2 )
{
int V_15 , V_16 ;
V_16 = F_5 ( V_1 , V_2 ) ;
V_1 += V_16 ;
V_15 = V_2 - V_16 ;
if ( V_15 ) {
* V_1 ++ = ' ' ;
V_15 -- ;
}
F_1 ( V_1 , V_15 ) ;
V_1 [ V_2 - 1 ] = 0 ;
}
