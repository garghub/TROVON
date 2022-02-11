static inline bool F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
if ( V_1 != V_3 )
return false ;
if ( ! V_2 && ! V_4 )
return true ;
return V_2 & V_4 ;
}
int F_2 ( void * V_5 , int V_6 )
{
unsigned long V_7 , V_8 , V_9 ;
struct V_10 * V_11 = V_5 ;
struct V_12 * V_13 = NULL ;
int V_14 , V_15 , V_16 = 0 , V_17 ;
struct V_18 * V_19 ;
V_7 = F_3 ( V_11 ) ;
V_8 = F_4 ( V_11 ) ;
if ( V_8 + V_20 > V_7 ) {
if ( V_6 )
F_5 ( L_1 ) ;
return - V_21 ;
}
if ( V_11 -> V_22 != 1 || V_11 -> V_23 != 1 ) {
if ( V_6 )
F_5 ( L_2 ) ;
return - V_21 ;
}
V_9 = V_7 - ( V_20 + V_8 ) ;
if ( V_9 ) {
if ( ( V_9 < V_24 )
|| ( ( V_9 - V_24 ) % V_25 ) ) {
if ( V_6 )
F_5 ( L_3 ) ;
return - V_21 ;
}
V_13 = V_5 + V_20 + V_8 ;
if ( V_9 != F_6 ( V_13 ) ) {
if ( V_6 )
F_5 ( L_4 ) ;
return - V_26 ;
}
V_16 = V_13 -> V_27 ;
}
if ( V_9 ) {
int V_28 = 0 ;
int * V_29 = ( int * ) V_13 ;
V_17 = V_9 / V_30 ;
while ( V_17 -- )
V_28 += V_29 [ V_17 ] ;
if ( V_28 ) {
if ( V_6 )
F_7 ( L_5 ) ;
return - V_21 ;
}
}
V_15 = 0 ;
V_17 = ( V_20 + V_8 ) / V_30 ;
while ( V_17 -- )
V_15 += ( ( int * ) V_5 ) [ V_17 ] ;
if ( V_15 ) {
if ( V_6 )
F_5 ( L_6 ) ;
return - V_21 ;
}
if ( ! V_9 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
V_19 = ( void * ) V_13 + V_24 +
V_25 * V_17 ;
V_14 = V_15
- ( V_11 -> V_31 + V_11 -> V_32 + V_11 -> V_33 )
+ ( V_19 -> V_31 + V_19 -> V_32 + V_19 -> V_33 ) ;
if ( V_14 ) {
if ( V_6 )
F_5 ( L_6 ) ;
return - V_21 ;
}
}
return 0 ;
}
int F_8 ( void * V_5 , unsigned int V_34 , int V_35 )
{
struct V_10 * V_36 = V_5 ;
struct V_12 * V_37 ;
struct V_18 * V_19 ;
int V_17 ;
if ( F_1 ( V_34 , V_35 , V_36 -> V_31 , V_36 -> V_32 ) )
return 1 ;
if ( F_3 ( V_36 ) <= F_4 ( V_36 ) + V_20 )
return 0 ;
V_37 = V_5 + F_4 ( V_36 ) + V_20 ;
V_19 = ( void * ) V_37 + V_24 ;
for ( V_17 = 0 ; V_17 < V_37 -> V_27 ; V_17 ++ ) {
if ( F_1 ( V_34 , V_35 , V_19 -> V_31 , V_19 -> V_32 ) )
return 1 ;
V_19 ++ ;
}
return 0 ;
}
int F_9 ( void * V_5 , unsigned int V_34 , int V_35 , int V_38 )
{
struct V_10 * V_36 = V_5 ;
if ( V_36 -> V_39 <= V_38 )
return 0 ;
return F_8 ( V_5 , V_34 , V_35 ) ;
}
