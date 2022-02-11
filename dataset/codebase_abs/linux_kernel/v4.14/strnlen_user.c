static inline long F_1 ( const char T_1 * V_1 , unsigned long V_2 , unsigned long V_3 )
{
const struct V_4 V_5 = V_6 ;
long V_7 , V_8 = 0 ;
unsigned long V_9 ;
if ( V_3 > V_2 )
V_3 = V_2 ;
V_7 = ( sizeof( long ) - 1 ) & ( unsigned long ) V_1 ;
V_1 -= V_7 ;
V_3 += V_7 ;
F_2 ( V_9 , ( unsigned long T_1 * ) V_1 , V_10 ) ;
V_9 |= F_3 ( V_7 ) ;
for (; ; ) {
unsigned long V_11 ;
if ( F_4 ( V_9 , & V_11 , & V_5 ) ) {
V_11 = F_5 ( V_9 , V_11 , & V_5 ) ;
V_11 = F_6 ( V_11 ) ;
return V_8 + F_7 ( V_11 ) + 1 - V_7 ;
}
V_8 += sizeof( unsigned long ) ;
if ( F_8 ( V_3 <= sizeof( unsigned long ) ) )
break;
V_3 -= sizeof( unsigned long ) ;
F_2 ( V_9 , ( unsigned long T_1 * ) ( V_1 + V_8 ) , V_10 ) ;
}
V_8 -= V_7 ;
if ( V_8 >= V_2 )
return V_2 + 1 ;
V_10:
return 0 ;
}
long F_9 ( const char T_1 * V_12 , long V_2 )
{
unsigned long V_13 , V_14 ;
if ( F_8 ( V_2 <= 0 ) )
return 0 ;
V_13 = F_10 () ;
V_14 = ( unsigned long ) V_12 ;
if ( F_11 ( V_14 < V_13 ) ) {
unsigned long V_3 = V_13 - V_14 ;
long V_15 ;
F_12 () ;
V_15 = F_1 ( V_12 , V_2 , V_3 ) ;
F_13 () ;
return V_15 ;
}
return 0 ;
}
