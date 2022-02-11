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
if ( F_6 ( V_10 ) ) {
V_8 = F_7 ( V_11 , V_8 ) ;
V_6 = F_7 ( V_11 , V_6 ) ;
}
V_12 = V_6 ;
V_9 = 0 ;
F_8 ( true ) ;
do {
V_2 = 0 ;
type = F_9 ( V_9 ) ;
do {
V_2 += V_8 ;
if ( V_12 && V_9 + V_2 >= V_12 )
break;
} while ( type == F_9 ( V_9 + V_2 ) );
if ( type == V_13 || type == V_14 ) {
if ( V_12 && ( V_9 + V_2 > V_12 ) )
V_2 = V_12 - V_9 ;
F_1 ( V_9 , V_2 ) ;
}
V_9 += V_2 ;
} while ( V_9 < V_12 );
F_8 ( false ) ;
if ( ! V_12 )
V_12 = F_10 () ;
}
