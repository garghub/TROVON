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
if ( F_2 ( F_3 ( V_9 , ( unsigned long T_1 * ) V_1 ) ) )
return 0 ;
V_9 |= F_4 ( V_7 ) ;
for (; ; ) {
unsigned long V_10 ;
if ( F_5 ( V_9 , & V_10 , & V_5 ) ) {
V_10 = F_6 ( V_9 , V_10 , & V_5 ) ;
V_10 = F_7 ( V_10 ) ;
return V_8 + F_8 ( V_10 ) + 1 - V_7 ;
}
V_8 += sizeof( unsigned long ) ;
if ( F_2 ( V_3 <= sizeof( unsigned long ) ) )
break;
V_3 -= sizeof( unsigned long ) ;
if ( F_2 ( F_3 ( V_9 , ( unsigned long T_1 * ) ( V_1 + V_8 ) ) ) )
return 0 ;
}
V_8 -= V_7 ;
if ( V_8 >= V_2 )
return V_2 + 1 ;
return 0 ;
}
long F_9 ( const char T_1 * V_11 , long V_2 )
{
unsigned long V_12 , V_13 ;
if ( F_2 ( V_2 <= 0 ) )
return 0 ;
V_12 = F_10 () ;
V_13 = ( unsigned long ) V_11 ;
if ( F_11 ( V_13 < V_12 ) ) {
unsigned long V_3 = V_12 - V_13 ;
long V_14 ;
F_12 () ;
V_14 = F_1 ( V_11 , V_2 , V_3 ) ;
F_13 () ;
return V_14 ;
}
return 0 ;
}
long F_14 ( const char T_1 * V_11 )
{
unsigned long V_12 , V_13 ;
V_12 = F_10 () ;
V_13 = ( unsigned long ) V_11 ;
if ( F_11 ( V_13 < V_12 ) ) {
unsigned long V_3 = V_12 - V_13 ;
long V_14 ;
F_12 () ;
V_14 = F_1 ( V_11 , ~ 0ul , V_3 ) ;
F_13 () ;
return V_14 ;
}
return 0 ;
}
