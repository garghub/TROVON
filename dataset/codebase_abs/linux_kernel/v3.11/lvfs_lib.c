void F_1 ( struct V_1 * V_2 , int V_3 , long V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
unsigned long V_10 = 0 ;
if ( V_2 == NULL )
return;
V_9 = F_2 ( V_2 , V_11 , & V_10 ) ;
if ( V_9 < 0 )
return;
V_8 = & V_2 -> V_12 [ V_3 ] ;
V_6 = F_3 ( V_2 , V_9 , V_3 ) ;
V_6 -> V_13 ++ ;
if ( V_8 -> V_14 & V_15 ) {
if ( F_4 () &&
( V_2 -> V_16 & V_17 ) != 0 )
V_6 -> V_18 += V_4 ;
else
V_6 -> V_19 += V_4 ;
if ( V_8 -> V_14 & V_20 )
V_6 -> V_21 += ( V_22 ) V_4 * V_4 ;
if ( V_4 < V_6 -> V_23 )
V_6 -> V_23 = V_4 ;
if ( V_4 > V_6 -> V_24 )
V_6 -> V_24 = V_4 ;
}
F_5 ( V_2 , V_11 , & V_10 ) ;
}
void F_6 ( struct V_1 * V_2 , int V_3 , long V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
unsigned long V_10 = 0 ;
if ( V_2 == NULL )
return;
V_9 = F_2 ( V_2 , V_11 , & V_10 ) ;
if ( V_9 < 0 )
return;
V_8 = & V_2 -> V_12 [ V_3 ] ;
V_6 = F_3 ( V_2 , V_9 , V_3 ) ;
if ( V_8 -> V_14 & V_15 ) {
if ( F_4 () &&
( V_2 -> V_16 & V_17 ) != 0 )
V_6 -> V_18 -= V_4 ;
else
V_6 -> V_19 -= V_4 ;
}
F_5 ( V_2 , V_11 , & V_10 ) ;
}
int F_7 ( struct V_1 * V_2 , unsigned int V_25 )
{
struct V_5 * V_26 ;
unsigned int V_27 ;
int V_28 = - V_29 ;
unsigned long V_10 = 0 ;
int V_30 ;
F_8 ( V_2 -> V_31 [ V_25 ] == NULL ) ;
F_8 ( ( V_2 -> V_16 & V_32 ) == 0 ) ;
V_27 = F_9 ( V_2 ) ;
F_10 ( V_2 -> V_31 [ V_25 ] , V_27 ) ;
if ( V_2 -> V_31 [ V_25 ] != NULL ) {
V_28 = 0 ;
if ( F_11 ( V_2 -> V_33 <= V_25 ) ) {
if ( V_2 -> V_16 & V_17 )
F_12 ( & V_2 -> V_34 , V_10 ) ;
else
F_13 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_33 <= V_25 )
V_2 -> V_33 = V_25 + 1 ;
if ( V_2 -> V_16 & V_17 ) {
F_14 ( & V_2 -> V_34 , V_10 ) ;
} else {
F_15 ( & V_2 -> V_34 ) ;
}
}
for ( V_30 = 0 ; V_30 < V_2 -> V_35 ; ++ V_30 ) {
V_26 = F_3 ( V_2 , V_25 , V_30 ) ;
V_26 -> V_23 = V_36 ;
}
}
return V_28 ;
}
