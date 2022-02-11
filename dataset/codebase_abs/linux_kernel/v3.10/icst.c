unsigned long F_1 ( const struct V_1 * V_2 , struct V_3 V_4 )
{
return V_2 -> V_5 * 2 * ( V_4 . V_6 + 8 ) / ( ( V_4 . V_7 + 2 ) * V_2 -> V_8 [ V_4 . V_9 ] ) ;
}
struct V_3
F_2 ( const struct V_1 * V_2 , unsigned long V_10 )
{
struct V_3 V_4 = { . V_9 = 1 , . V_6 = V_2 -> V_11 , . V_7 = V_2 -> V_12 } ;
unsigned long V_13 ;
unsigned int V_14 = 0 , V_15 , V_16 = ( unsigned int ) - 1 ;
do {
V_13 = V_10 * V_2 -> V_8 [ V_2 -> V_17 [ V_14 ] ] ;
if ( V_13 > V_2 -> V_18 && V_13 <= V_2 -> V_19 )
break;
} while ( V_14 < 8 );
if ( V_14 >= 8 )
return V_4 ;
V_4 . V_9 = V_2 -> V_17 [ V_14 ] ;
for ( V_15 = V_2 -> V_20 ; V_15 <= V_2 -> V_12 ; V_15 ++ ) {
unsigned long V_21 , V_22 ;
unsigned int V_23 ;
int V_24 ;
V_21 = ( 2 * V_2 -> V_5 ) / V_15 ;
V_23 = ( V_13 + V_21 / 2 ) / V_21 ;
if ( V_23 < V_2 -> V_25 || V_23 > V_2 -> V_11 )
continue;
V_22 = V_21 * V_23 ;
V_24 = V_22 - V_13 ;
if ( V_24 < 0 )
V_24 = - V_24 ;
if ( ( unsigned ) V_24 < V_16 ) {
V_4 . V_6 = V_23 - 8 ;
V_4 . V_7 = V_15 - 2 ;
if ( V_24 == 0 )
break;
V_16 = V_24 ;
}
}
return V_4 ;
}
