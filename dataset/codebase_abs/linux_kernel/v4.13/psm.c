int F_1 ( struct V_1 * V_2 , enum V_3 V_4 , unsigned long * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
V_8 = V_10 -> V_12 ;
V_7 = V_10 -> V_13 ;
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ ) {
if ( V_7 -> V_14 . V_4 & V_4 ) {
* V_5 = V_7 -> V_15 ;
return 0 ;
}
V_7 = (struct V_6 * ) ( ( unsigned long ) V_7 + V_10 -> V_16 ) ;
}
return - 1 ;
}
int F_2 ( struct V_1 * V_2 , enum V_17 V_18 , unsigned long * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
V_8 = V_10 -> V_12 ;
V_7 = V_10 -> V_13 ;
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ ) {
if ( V_7 -> V_14 . V_19 & V_18 ) {
* V_5 = V_7 -> V_15 ;
return 0 ;
}
V_7 = (struct V_6 * ) ( ( unsigned long ) V_7 + V_10 -> V_16 ) ;
}
return - 1 ;
}
int F_3 ( struct V_1 * V_2 , unsigned long * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
V_8 = V_10 -> V_12 ;
V_7 = V_10 -> V_13 ;
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ ) {
if ( V_7 -> V_15 == * V_5 ) {
memcpy ( V_10 -> V_20 , V_7 , V_10 -> V_16 ) ;
return 0 ;
}
V_7 = (struct V_6 * ) ( ( unsigned long ) V_7 + V_10 -> V_16 ) ;
}
return - 1 ;
}
int F_4 ( struct V_1 * V_2 , bool V_21 )
{
struct V_6 * V_22 ;
struct V_6 * V_23 ;
struct V_9 * V_10 ;
bool V_24 ;
if ( V_21 )
return 0 ;
V_10 = V_2 -> V_10 ;
V_22 = V_10 -> V_25 ;
V_23 = V_10 -> V_20 ;
if ( V_23 == NULL )
return 0 ;
F_5 ( V_10 , V_23 , V_22 ) ;
if ( V_22 == NULL || ( 0 != F_6 ( V_10 , & V_22 -> V_26 , & V_23 -> V_26 , & V_24 ) ) )
V_24 = false ;
if ( ! V_24 || F_7 ( V_10 ) ) {
F_8 ( V_10 , & V_22 -> V_26 , & V_23 -> V_26 ) ;
memcpy ( V_10 -> V_25 , V_10 -> V_20 , V_10 -> V_16 ) ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 , bool V_21 )
{
return 0 ;
}
