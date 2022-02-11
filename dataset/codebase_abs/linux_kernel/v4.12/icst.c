unsigned long F_1 ( const struct V_1 * V_2 , struct V_3 V_4 )
{
T_1 V_5 = V_2 -> V_6 * 2 * ( T_1 ) ( V_4 . V_7 + 8 ) ;
T_2 V_8 = ( V_4 . V_9 + 2 ) * V_2 -> V_10 [ V_4 . V_11 ] ;
F_2 ( V_5 , V_8 ) ;
return ( unsigned long ) V_5 ;
}
struct V_3
F_3 ( const struct V_1 * V_2 , unsigned long V_12 )
{
struct V_3 V_4 = { . V_11 = 1 , . V_7 = V_2 -> V_13 , . V_9 = V_2 -> V_14 } ;
unsigned long V_15 ;
unsigned int V_16 = 0 , V_17 , V_18 = ( unsigned int ) - 1 ;
do {
V_15 = V_12 * V_2 -> V_10 [ V_2 -> V_19 [ V_16 ] ] ;
if ( V_15 > V_2 -> V_20 && V_15 <= V_2 -> V_21 )
break;
V_16 ++ ;
} while ( V_16 < 8 );
if ( V_16 >= 8 )
return V_4 ;
V_4 . V_11 = V_2 -> V_19 [ V_16 ] ;
for ( V_17 = V_2 -> V_22 ; V_17 <= V_2 -> V_14 ; V_17 ++ ) {
unsigned long V_23 , V_24 ;
unsigned int V_25 ;
int V_26 ;
V_23 = ( 2 * V_2 -> V_6 ) / V_17 ;
V_25 = ( V_15 + V_23 / 2 ) / V_23 ;
if ( V_25 < V_2 -> V_27 || V_25 > V_2 -> V_13 )
continue;
V_24 = V_23 * V_25 ;
V_26 = V_24 - V_15 ;
if ( V_26 < 0 )
V_26 = - V_26 ;
if ( ( unsigned ) V_26 < V_18 ) {
V_4 . V_7 = V_25 - 8 ;
V_4 . V_9 = V_17 - 2 ;
if ( V_26 == 0 )
break;
V_18 = V_26 ;
}
}
return V_4 ;
}
