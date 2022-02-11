static inline int
F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
return ( ! F_2 ( V_3 , V_1 , V_4 , V_2 ) ) ? 0 : 1 ;
}
int
F_3 ( struct V_5 * V_6 , int V_7 )
{
return ( V_6 -> V_7 <= V_7 ) ? 0 : 1 ;
}
int F_4 ( void * V_8 , int V_9 )
{
unsigned long V_10 , V_11 , V_12 ;
struct V_5 * V_6 = V_8 ;
struct V_13 * V_14 = NULL ;
int V_15 , V_16 , V_17 = 0 , V_18 ;
struct V_19 * V_20 ;
V_10 = F_5 ( V_6 ) ;
V_11 = F_6 ( V_6 ) ;
if ( V_11 + V_21 > V_10 ) {
if ( V_9 )
F_7 ( L_1 ) ;
return - V_22 ;
}
if ( V_6 -> V_23 != 1 || V_6 -> V_24 != 1 ) {
if ( V_9 )
F_7 ( L_2 ) ;
return - V_22 ;
}
V_12 = V_10 - ( V_21 + V_11 ) ;
if ( V_12 ) {
if ( ( V_12 < V_25 )
|| ( ( V_12 - V_25 ) % V_26 ) ) {
if ( V_9 )
F_7 ( L_3 ) ;
return - V_22 ;
}
V_14 = V_8 + V_21 + V_11 ;
if ( V_12 != F_8 ( V_14 ) ) {
if ( V_9 )
F_7 ( L_4 ) ;
return - V_27 ;
}
V_17 = V_14 -> V_28 ;
}
if ( V_12 ) {
int V_29 = 0 ;
int * V_30 = ( int * ) V_14 ;
V_18 = V_12 / V_31 ;
while ( V_18 -- )
V_29 += V_30 [ V_18 ] ;
if ( V_29 ) {
if ( V_9 )
F_9 ( L_5 ) ;
return - V_22 ;
}
}
V_16 = 0 ;
V_18 = ( V_21 + V_11 ) / V_31 ;
while ( V_18 -- )
V_16 += ( ( int * ) V_8 ) [ V_18 ] ;
if ( V_16 ) {
if ( V_9 )
F_7 ( L_6 ) ;
return - V_22 ;
}
if ( ! V_12 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
V_20 = ( void * ) V_14 + V_25 +
V_26 * V_18 ;
V_15 = V_16
- ( V_6 -> V_3 + V_6 -> V_4 + V_6 -> V_32 )
+ ( V_20 -> V_3 + V_20 -> V_4 + V_20 -> V_32 ) ;
if ( V_15 ) {
if ( V_9 )
F_7 ( L_6 ) ;
return - V_22 ;
}
}
return 0 ;
}
int F_10 ( unsigned int V_1 , int V_2 , void * V_8 , int V_7 )
{
struct V_5 * V_6 = V_8 ;
struct V_13 * V_14 ;
unsigned long V_10 = F_5 ( V_6 ) ;
int V_17 , V_18 ;
struct V_19 * V_20 ;
if ( F_1 ( V_1 , V_2 , V_6 -> V_3 , V_6 -> V_4 ) )
return 1 ;
if ( V_10 <= F_6 ( V_6 ) + V_21 )
return 0 ;
V_14 = V_8 + F_6 ( V_6 ) + V_21 ;
V_17 = V_14 -> V_28 ;
V_20 = ( void * ) V_14 + V_25 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
if ( F_1 ( V_1 , V_2 , V_20 -> V_3 , V_20 -> V_4 ) )
return 1 ;
V_20 ++ ;
}
return 0 ;
}
int F_11 ( unsigned int V_1 , int V_2 , void * V_8 , int V_7 )
{
struct V_5 * V_6 = V_8 ;
if ( ! F_3 ( V_6 , V_7 ) )
return 0 ;
return F_10 ( V_1 , V_2 , V_8 , V_7 ) ;
}
