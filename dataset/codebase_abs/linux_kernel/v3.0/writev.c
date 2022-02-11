static inline int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned long V_5 , T_1 V_6 , T_2 * V_7 )
{
unsigned long V_8 ;
T_2 V_9 = 0 , V_10 ;
int V_11 = 0 ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 ++ ) {
if ( ! V_4 [ V_8 ] . V_12 )
continue;
V_11 = V_2 -> V_13 ( V_2 , V_6 , V_4 [ V_8 ] . V_12 , & V_10 , V_4 [ V_8 ] . V_14 ) ;
V_9 += V_10 ;
if ( V_11 || V_10 != V_4 [ V_8 ] . V_12 )
break;
V_6 += V_4 [ V_8 ] . V_12 ;
}
if ( V_7 )
* V_7 = V_9 ;
return V_11 ;
}
int F_2 ( struct V_15 * V_16 , const struct V_3 * V_4 ,
unsigned long V_5 , T_1 V_6 , T_2 * V_7 )
{
if ( ! F_3 ( V_16 ) ) {
if ( F_4 () ) {
int V_17 ;
V_17 = F_5 ( V_16 , V_4 , V_5 , ( V_18 ) V_6 ) ;
if ( V_17 ) {
return V_17 ;
}
}
}
if ( V_16 -> V_2 -> V_19 )
return V_16 -> V_2 -> V_19 ( V_16 -> V_2 , V_4 , V_5 , V_6 , V_7 ) ;
else {
return F_1 ( V_16 -> V_2 , V_4 , V_5 , V_6 , V_7 ) ;
}
}
int F_6 ( struct V_15 * V_16 , T_1 V_20 , T_2 V_21 ,
T_2 * V_7 , const T_3 * V_22 )
{
int V_11 ;
V_11 = V_16 -> V_2 -> V_13 ( V_16 -> V_2 , V_20 , V_21 , V_7 , V_22 ) ;
if ( F_4 () ) {
struct V_3 V_4 [ 1 ] ;
int V_17 ;
V_4 [ 0 ] . V_14 = ( unsigned char * ) V_22 ;
V_4 [ 0 ] . V_12 = V_21 ;
V_17 = F_5 ( V_16 , V_4 , 1 , ( V_18 ) V_20 ) ;
if ( V_17 ) {
return V_17 ;
}
}
return V_11 ;
}
