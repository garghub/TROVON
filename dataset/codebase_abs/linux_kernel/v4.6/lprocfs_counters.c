void F_1 ( struct V_1 * V_2 , int V_3 , long V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
unsigned long V_10 = 0 ;
if ( ! V_2 )
return;
F_2 ( 0 <= V_3 && V_3 < V_2 -> V_11 ,
L_1 , V_3 , V_2 -> V_11 ) ;
V_9 = F_3 ( V_2 , V_12 , & V_10 ) ;
if ( V_9 < 0 )
return;
V_8 = & V_2 -> V_13 [ V_3 ] ;
V_6 = F_4 ( V_2 , V_9 , V_3 ) ;
V_6 -> V_14 ++ ;
if ( V_8 -> V_15 & V_16 ) {
if ( F_5 () &&
( V_2 -> V_17 & V_18 ) != 0 )
V_6 -> V_19 += V_4 ;
else
V_6 -> V_20 += V_4 ;
if ( V_8 -> V_15 & V_21 )
V_6 -> V_22 += ( V_23 ) V_4 * V_4 ;
if ( V_4 < V_6 -> V_24 )
V_6 -> V_24 = V_4 ;
if ( V_4 > V_6 -> V_25 )
V_6 -> V_25 = V_4 ;
}
F_6 ( V_2 , V_12 , & V_10 ) ;
}
void F_7 ( struct V_1 * V_2 , int V_3 , long V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
unsigned long V_10 = 0 ;
if ( ! V_2 )
return;
F_2 ( 0 <= V_3 && V_3 < V_2 -> V_11 ,
L_1 , V_3 , V_2 -> V_11 ) ;
V_9 = F_3 ( V_2 , V_12 , & V_10 ) ;
if ( V_9 < 0 )
return;
V_8 = & V_2 -> V_13 [ V_3 ] ;
V_6 = F_4 ( V_2 , V_9 , V_3 ) ;
if ( V_8 -> V_15 & V_16 ) {
if ( F_5 () &&
( V_2 -> V_17 & V_18 ) != 0 )
V_6 -> V_19 -= V_4 ;
else
V_6 -> V_20 -= V_4 ;
}
F_6 ( V_2 , V_12 , & V_10 ) ;
}
