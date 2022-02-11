static void F_1 ( struct V_1 V_2 [] , unsigned long V_3 )
{
unsigned long long V_4 , V_5 , V_6 ;
unsigned long V_7 = 0 , V_8 ;
int V_9 = 0 , type ;
V_6 = F_2 () ;
V_5 = F_3 () ;
V_4 = V_6 * V_5 ;
if ( ! V_6 )
V_6 = 1ULL << 17 ;
if ( sizeof( long ) == 4 ) {
V_6 = F_4 ( V_10 , V_6 ) ;
V_4 = V_4 ? F_4 ( V_10 , V_4 ) : V_10 ;
}
if ( V_3 )
V_4 = V_4 ? F_4 ( ( unsigned long ) V_4 , V_3 ) : V_3 ;
do {
V_8 = 0 ;
type = F_5 ( V_7 ) ;
do {
V_8 += V_6 ;
if ( V_4 && V_7 + V_8 >= V_4 )
break;
} while ( type == F_5 ( V_7 + V_8 ) );
if ( type == V_11 || type == V_12 ) {
if ( V_4 && ( V_7 + V_8 > V_4 ) )
V_8 = V_4 - V_7 ;
V_2 [ V_9 ] . V_7 = V_7 ;
V_2 [ V_9 ] . V_8 = V_8 ;
V_2 [ V_9 ] . type = type ;
V_9 ++ ;
}
V_7 += V_8 ;
} while ( V_7 < V_4 && V_9 < V_13 );
}
void F_6 ( struct V_1 V_2 [] , unsigned long V_3 )
{
unsigned long V_14 , V_15 , V_16 ;
memset ( V_2 , 0 , V_13 * sizeof( struct V_1 ) ) ;
F_7 ( V_14 ) ;
V_15 = F_8 ( 0xfb ) ;
if ( F_9 ( 5 , & V_15 ) ) {
if ( F_10 ( F_11 ( V_2 ) ) )
goto V_17;
}
F_12 ( V_16 , 0 , 0 ) ;
F_13 ( 0 , 28 ) ;
F_1 ( V_2 , V_3 ) ;
F_14 ( V_16 , 0 , 0 ) ;
V_17:
F_15 ( V_15 ) ;
F_16 ( V_14 ) ;
}
void F_17 ( struct V_1 V_1 [] , unsigned long V_7 ,
unsigned long V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
struct V_1 * V_2 = & V_1 [ V_9 ] ;
if ( V_2 -> V_8 == 0 )
continue;
if ( V_7 > V_2 -> V_7 + V_2 -> V_8 )
continue;
if ( V_7 + V_8 <= V_2 -> V_7 )
continue;
if ( ( V_7 > V_2 -> V_7 ) &&
( V_7 + V_8 < V_2 -> V_7 + V_2 -> V_8 ) ) {
struct V_1 * V_18 = V_2 + 1 ;
memmove ( V_18 , V_2 , ( V_13 - V_9 - 1 ) * sizeof( * V_18 ) ) ;
V_18 -> V_7 = V_7 + V_8 ;
V_18 -> V_8 = V_2 -> V_7 + V_2 -> V_8 - V_18 -> V_7 ;
V_2 -> V_8 = V_7 - V_2 -> V_7 ;
continue;
} else if ( ( V_7 <= V_2 -> V_7 ) &&
( V_7 + V_8 >= V_2 -> V_7 + V_2 -> V_8 ) ) {
memmove ( V_2 , V_2 + 1 , ( V_13 - V_9 - 1 ) * sizeof( * V_2 ) ) ;
memset ( & V_1 [ V_13 - 1 ] , 0 , sizeof( * V_2 ) ) ;
} else if ( V_7 + V_8 < V_2 -> V_7 + V_2 -> V_8 ) {
V_2 -> V_8 = V_2 -> V_7 + V_2 -> V_8 - V_7 - V_8 ;
V_2 -> V_7 = V_7 + V_8 ;
} else if ( V_7 > V_2 -> V_7 ) {
V_2 -> V_8 = V_7 - V_2 -> V_7 ;
}
}
}
