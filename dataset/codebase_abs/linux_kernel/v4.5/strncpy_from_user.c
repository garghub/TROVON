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
if ( F_3 ( F_4 ( V_10 , ( unsigned long T_1 * ) ( V_2 + V_8 ) ) ) )
break;
* ( unsigned long * ) ( V_1 + V_8 ) = V_10 ;
if ( F_5 ( V_10 , & V_11 , & V_6 ) ) {
V_11 = F_6 ( V_10 , V_11 , & V_6 ) ;
V_11 = F_7 ( V_11 ) ;
return V_8 + F_8 ( V_11 ) ;
}
V_8 += sizeof( unsigned long ) ;
V_4 -= sizeof( unsigned long ) ;
}
V_9:
while ( V_4 ) {
char V_10 ;
if ( F_3 ( F_4 ( V_10 , V_2 + V_8 ) ) )
return - V_12 ;
V_1 [ V_8 ] = V_10 ;
if ( ! V_10 )
return V_8 ;
V_8 ++ ;
V_4 -- ;
}
if ( V_8 >= V_3 )
return V_8 ;
return - V_12 ;
}
long F_9 ( char * V_1 , const char T_1 * V_2 , long V_3 )
{
unsigned long V_13 , V_14 ;
if ( F_3 ( V_3 <= 0 ) )
return 0 ;
V_13 = F_10 () ;
V_14 = ( unsigned long ) V_2 ;
if ( F_11 ( V_14 < V_13 ) ) {
unsigned long V_4 = V_13 - V_14 ;
long V_15 ;
F_12 () ;
V_15 = F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
F_13 () ;
return V_15 ;
}
return - V_12 ;
}
