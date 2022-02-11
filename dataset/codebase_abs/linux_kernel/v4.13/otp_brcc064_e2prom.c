void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_8 = V_3 >> 1 ;
static const unsigned int V_9 = 30 ;
int V_10 ;
T_2 V_11 = V_4 & V_12 ;
unsigned char * V_13 ;
V_13 = F_3 ( & V_7 -> V_14 , V_5 , V_15 ) ;
if ( ! V_13 )
return NULL ;
for ( V_10 = V_11 ; V_10 < V_5 ; V_10 += V_9 ) {
struct V_16 V_17 [ 2 ] ;
unsigned int V_18 = V_8 ;
T_3 V_19 ;
int V_20 ;
V_17 [ 0 ] . V_21 = 0 ;
V_17 [ 0 ] . V_10 = V_18 ;
V_19 = F_4 ( V_10 & 0xFFFF ) ;
V_17 [ 0 ] . V_22 = 2 ;
V_17 [ 0 ] . V_23 = ( T_1 * ) & V_19 ;
V_17 [ 1 ] . V_10 = V_18 ;
V_17 [ 1 ] . V_21 = V_24 ;
V_17 [ 1 ] . V_22 = F_5 ( V_9 , V_5 - V_10 ) ;
V_17 [ 1 ] . V_23 = & V_13 [ V_10 ] ;
V_20 = F_6 ( V_7 -> V_25 , V_17 , F_7 ( V_17 ) ) ;
if ( V_20 != F_7 ( V_17 ) ) {
F_8 ( & V_7 -> V_14 , L_1 , V_10 ) ;
return NULL ;
}
}
return V_13 ;
}
