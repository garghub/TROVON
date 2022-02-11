void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_2 = & V_5 [ V_3 ] ;
V_2 -> V_6 = F_2 ( V_7 + V_3 ) ;
}
}
void T_1 T_2 *
F_3 ( T_3 V_8 , unsigned long V_9 , T_4 V_10 )
{
enum V_11 V_12 , V_13 ;
struct V_1 * V_2 ;
unsigned int V_14 ;
unsigned long V_15 ;
int V_3 , V_16 ;
V_15 = V_8 & ~ V_17 ;
V_8 &= V_17 ;
V_9 = F_4 ( V_8 + V_9 ) - V_8 ;
V_16 = - 1 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_2 = & V_5 [ V_3 ] ;
if ( ! V_2 -> V_18 ) {
V_2 -> V_9 = V_9 ;
V_16 = V_3 ;
break;
}
}
if ( V_16 < 0 )
return NULL ;
V_14 = V_9 >> V_19 ;
if ( V_14 > V_4 )
return NULL ;
V_12 = V_7 + V_16 ;
V_13 = V_12 ;
while ( V_14 > 0 ) {
F_5 ( V_10 ) |= V_20 ;
F_6 ( V_13 , V_8 , V_10 ) ;
V_8 += V_21 ;
V_13 ++ ;
-- V_14 ;
}
V_2 -> V_18 = ( void T_2 * ) ( V_15 + V_2 -> V_6 ) ;
return V_2 -> V_18 ;
}
int F_7 ( void T_2 * V_18 )
{
enum V_11 V_13 ;
struct V_1 * V_2 ;
unsigned int V_14 ;
int V_3 , V_16 ;
V_16 = - 1 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_2 = & V_5 [ V_3 ] ;
if ( V_2 -> V_18 == V_18 ) {
V_16 = V_3 ;
break;
}
}
if ( V_16 < 0 )
return - V_22 ;
V_14 = V_2 -> V_9 >> V_19 ;
V_13 = V_7 + V_16 + V_14 - 1 ;
while ( V_14 > 0 ) {
F_8 ( V_13 , F_9 ( V_20 ) ) ;
-- V_13 ;
-- V_14 ;
}
V_2 -> V_9 = 0 ;
V_2 -> V_18 = NULL ;
return 0 ;
}
