void F_1 ( struct V_1 * V_2 , T_1 time )
{
T_2 V_3 ;
if ( time > V_4 )
time = V_4 ;
V_2 -> V_5 . V_6 = time ;
V_2 -> V_5 . V_7 = 0L ;
V_3 = ( T_2 ) time ;
if ( ! V_3 )
V_3 ++ ;
F_2 ( F_3 ( V_8 ) , ( T_1 ) V_3 * 200 ) ;
F_4 ( F_3 ( V_9 ) , V_10 ) ;
V_2 -> V_5 . V_11 = TRUE ;
}
void F_5 ( struct V_1 * V_2 )
{
F_4 ( F_3 ( V_9 ) , V_12 ) ;
F_4 ( F_3 ( V_9 ) , V_13 ) ;
V_2 -> V_5 . V_11 = FALSE ;
}
void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = 0 ;
V_2 -> V_5 . V_11 = FALSE ;
F_7 ( V_2 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
}
T_1 F_8 ( struct V_1 * V_2 )
{
T_2 V_14 ;
T_1 V_15 ;
if ( V_2 -> V_5 . V_11 ) {
F_5 ( V_2 ) ;
V_14 = ( T_2 ) ( ( F_9 ( F_3 ( V_16 ) ) / 200 ) & 0xffff ) ;
V_15 = F_10 () ;
if ( ( V_14 > V_2 -> V_5 . V_6 ) || ( V_15 & V_17 ) ) {
F_7 ( V_2 ) ;
V_2 -> V_5 . V_7 = V_2 -> V_5 . V_6 ;
}
else
V_2 -> V_5 . V_7 = V_2 -> V_5 . V_6 - V_14 ;
}
return V_2 -> V_5 . V_7 ;
}
T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_18 ;
T_1 time ;
V_18 = F_9 ( F_3 ( V_8 ) ) ;
F_4 ( F_3 ( V_9 ) , V_12 ) ;
time = F_9 ( F_3 ( V_16 ) ) ;
F_2 ( F_3 ( V_8 ) , time ) ;
F_4 ( F_3 ( V_9 ) , V_10 ) ;
F_2 ( F_3 ( V_8 ) , V_18 ) ;
return time ;
}
void F_12 ( struct V_1 * V_2 , T_1 V_19 , long int V_20 )
{
long V_21 ;
long V_18 ;
int V_22 ;
if ( V_2 -> V_5 . V_11 == FALSE ||
F_11 ( V_2 ) == F_11 ( V_2 ) ) {
return ;
}
V_18 = F_9 ( F_3 ( V_8 ) ) ;
if ( V_18 > V_20 ) {
do {
V_21 = ( long ) ( V_19 - F_11 ( V_2 ) ) ;
if ( V_21 < 0 ) {
V_21 += V_18 ;
}
} while ( V_21 <= V_20 ) ;
}
else {
V_21 = V_18 ;
V_22 = 0 ;
do {
if ( ! V_22 ) {
if ( F_11 ( V_2 ) >= V_19 ) {
V_21 += V_18 ;
V_22 = 1 ;
}
}
else {
if ( F_11 ( V_2 ) < V_19 ) {
V_22 = 0 ;
}
}
} while ( V_21 <= V_20 ) ;
}
}
