void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
unsigned long V_6 ;
V_2 -> V_7 = 0 ;
if ( ! V_8 ) {
V_2 -> V_9 = V_10 ;
}
else {
V_2 -> V_9 = 0 ;
V_6 = V_11 ;
F_2 ( & V_12 ) ;
for ( V_4 = V_8 ; V_4 ; V_4 = V_4 -> V_13 ) {
unsigned long V_14 = ( unsigned long ) V_4 -> V_14 ;
if ( V_14 < V_11 )
continue;
if ( V_14 >= V_15 )
break;
V_2 -> V_7 += V_4 -> V_16 ;
V_5 = V_14 - V_6 ;
if ( V_2 -> V_9 < V_5 )
V_2 -> V_9 = V_5 ;
V_6 = V_4 -> V_16 + V_14 ;
}
if ( V_15 - V_6 > V_2 -> V_9 )
V_2 -> V_9 = V_15 - V_6 ;
F_3 ( & V_12 ) ;
}
}
