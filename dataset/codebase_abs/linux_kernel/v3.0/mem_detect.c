static void F_1 ( struct V_1 V_2 [] )
{
unsigned long long V_3 , V_4 , V_5 ;
unsigned long V_6 = 0 , V_7 ;
int V_8 = 0 , type ;
V_5 = F_2 () ;
V_4 = F_3 () ;
V_3 = V_5 * V_4 ;
if ( ! V_5 )
V_5 = 1ULL << 17 ;
if ( sizeof( long ) == 4 ) {
V_5 = F_4 ( V_9 , V_5 ) ;
V_3 = V_3 ? F_4 ( V_9 , V_3 ) : V_9 ;
}
do {
V_7 = 0 ;
type = F_5 ( V_6 ) ;
do {
V_7 += V_5 ;
if ( V_3 && V_6 + V_7 >= V_3 )
break;
} while ( type == F_5 ( V_6 + V_7 ) );
if ( type == V_10 || type == V_11 ) {
V_2 [ V_8 ] . V_6 = V_6 ;
V_2 [ V_8 ] . V_7 = V_7 ;
V_2 [ V_8 ] . type = type ;
V_8 ++ ;
}
V_6 += V_7 ;
} while ( V_6 < V_3 && V_8 < V_12 );
}
void F_6 ( struct V_1 V_2 [] )
{
unsigned long V_13 , V_14 ;
memset ( V_2 , 0 , V_12 * sizeof( struct V_1 ) ) ;
V_13 = F_7 ( 0xf8 ) ;
F_8 ( V_14 , 0 , 0 ) ;
F_9 ( 0 , 28 ) ;
F_1 ( V_2 ) ;
F_10 ( V_14 , 0 , 0 ) ;
F_11 ( V_13 ) ;
}
