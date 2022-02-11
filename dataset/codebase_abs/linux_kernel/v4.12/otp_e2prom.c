void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_8 = V_3 >> 1 ;
static const unsigned int V_9 = 30 ;
int V_10 ;
T_2 V_11 = V_4 & V_12 ;
bool V_13 = ( V_4 & V_14 ) >> 31 ;
char * V_15 ;
V_15 = F_3 ( & V_7 -> V_16 , V_5 , V_17 ) ;
if ( ! V_15 )
return NULL ;
for ( V_10 = V_11 ; V_10 < V_5 ; V_10 += V_9 ) {
struct V_18 V_19 [ 2 ] ;
unsigned int V_20 = V_8 ;
T_3 V_21 ;
int V_22 ;
V_19 [ 0 ] . V_23 = 0 ;
if ( V_13 ) {
V_19 [ 0 ] . V_10 = V_20 ;
V_21 = F_4 ( V_10 & 0xFFFF ) ;
V_19 [ 0 ] . V_24 = 2 ;
V_19 [ 0 ] . V_25 = ( T_1 * ) & V_21 ;
} else {
V_20 |= ( V_10 >> 8 ) & 0x7 ;
V_19 [ 0 ] . V_10 = V_20 ;
V_21 = V_10 & 0xFF ;
V_19 [ 0 ] . V_24 = 1 ;
V_19 [ 0 ] . V_25 = ( T_1 * ) & V_21 ;
}
V_19 [ 1 ] . V_10 = V_20 ;
V_19 [ 1 ] . V_23 = V_26 ;
V_19 [ 1 ] . V_24 = F_5 ( V_9 , V_5 - V_10 ) ;
V_19 [ 1 ] . V_25 = & V_15 [ V_10 ] ;
V_22 = F_6 ( V_7 -> V_27 , V_19 , F_7 ( V_19 ) ) ;
if ( V_22 != F_7 ( V_19 ) ) {
F_8 ( & V_7 -> V_16 , L_1 , V_10 ) ;
return NULL ;
}
}
return V_15 ;
}
