static inline long F_1 ( char * V_1 , const char T_1 * V_2 , long V_3 , unsigned long V_4 )
{
const struct V_5 V_6 = V_7 ;
long V_8 = 0 ;
if ( V_4 > V_3 )
V_4 = V_3 ;
if ( F_2 ( V_2 , V_1 ) )
goto V_9;
while ( V_4 >= sizeof( unsigned long ) ) {
unsigned long V_10 , V_11 ;
F_3 ( V_10 , ( unsigned long T_1 * ) ( V_2 + V_8 ) , V_9 ) ;
* ( unsigned long * ) ( V_1 + V_8 ) = V_10 ;
if ( F_4 ( V_10 , & V_11 , & V_6 ) ) {
V_11 = F_5 ( V_10 , V_11 , & V_6 ) ;
V_11 = F_6 ( V_11 ) ;
return V_8 + F_7 ( V_11 ) ;
}
V_8 += sizeof( unsigned long ) ;
V_4 -= sizeof( unsigned long ) ;
}
V_9:
while ( V_4 ) {
char V_10 ;
F_3 ( V_10 , V_2 + V_8 , V_12 ) ;
V_1 [ V_8 ] = V_10 ;
if ( ! V_10 )
return V_8 ;
V_8 ++ ;
V_4 -- ;
}
if ( V_8 >= V_3 )
return V_8 ;
V_12:
return - V_13 ;
}
long F_8 ( char * V_1 , const char T_1 * V_2 , long V_3 )
{
unsigned long V_14 , V_15 ;
if ( F_9 ( V_3 <= 0 ) )
return 0 ;
V_14 = F_10 () ;
V_15 = ( unsigned long ) V_2 ;
if ( F_11 ( V_15 < V_14 ) ) {
unsigned long V_4 = V_14 - V_15 ;
long V_16 ;
F_12 ( V_1 , V_3 ) ;
F_13 ( V_1 , V_3 , false ) ;
F_14 () ;
V_16 = F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
F_15 () ;
return V_16 ;
}
return - V_13 ;
}
