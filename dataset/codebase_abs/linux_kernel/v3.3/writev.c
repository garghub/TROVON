int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned long V_5 , T_1 V_6 , T_2 * V_7 )
{
if ( ! F_2 ( V_2 ) ) {
if ( F_3 () ) {
int V_8 ;
V_8 = F_4 ( V_2 , V_4 , V_5 , ( V_9 ) V_6 ) ;
if ( V_8 ) {
return V_8 ;
}
}
}
return F_5 ( V_2 -> V_10 , V_4 , V_5 , V_6 , V_7 ) ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_11 , T_2 V_12 ,
T_2 * V_7 , const T_3 * V_13 )
{
int V_14 ;
V_14 = F_7 ( V_2 -> V_10 , V_11 , V_12 , V_7 , V_13 ) ;
if ( F_3 () ) {
struct V_3 V_4 [ 1 ] ;
int V_8 ;
V_4 [ 0 ] . V_15 = ( unsigned char * ) V_13 ;
V_4 [ 0 ] . V_16 = V_12 ;
V_8 = F_4 ( V_2 , V_4 , 1 , ( V_9 ) V_11 ) ;
if ( V_8 ) {
return V_8 ;
}
}
return V_14 ;
}
