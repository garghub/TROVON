static inline void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( & V_3 . V_4 , V_1 , V_2 , 0 , 0 ) ;
F_2 ( & V_3 . V_5 , V_1 , V_2 , 0 , 0 ) ;
}
void T_2 F_3 ( void )
{
unsigned long long V_6 , V_7 , V_8 ;
unsigned long V_9 , V_2 ;
int type ;
V_8 = F_4 () ;
V_7 = F_5 () ;
V_6 = V_8 * V_7 ;
if ( ! V_8 )
V_8 = 1ULL << 17 ;
V_10 = V_6 ;
V_9 = 0 ;
F_6 ( true ) ;
do {
V_2 = 0 ;
type = F_7 ( V_9 ) ;
do {
V_2 += V_8 ;
if ( V_10 && V_9 + V_2 >= V_10 )
break;
} while ( type == F_7 ( V_9 + V_2 ) );
if ( type == V_11 || type == V_12 ) {
if ( V_10 && ( V_9 + V_2 > V_10 ) )
V_2 = V_10 - V_9 ;
F_1 ( V_9 , V_2 ) ;
}
V_9 += V_2 ;
} while ( V_9 < V_10 );
F_6 ( false ) ;
if ( ! V_10 )
V_10 = F_8 () ;
}
