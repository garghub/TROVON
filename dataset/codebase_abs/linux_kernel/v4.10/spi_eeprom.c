int T_1 F_1 ( int V_1 , int V_2 , int V_3 )
{
struct V_4 V_5 = {
. V_6 = L_1 ,
. V_7 = 1500000 ,
. V_8 = V_1 ,
. V_9 = V_2 ,
} ;
struct V_10 * V_11 ;
V_11 = F_2 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
strcpy ( V_11 -> V_14 , L_2 ) ;
V_11 -> V_15 = V_3 ;
V_11 -> V_16 = V_17 ;
V_11 -> V_18 = V_19 ;
V_5 . V_20 = V_11 ;
return F_3 ( & V_5 , 1 ) ;
}
static int T_1 F_4 ( struct V_21 * V_22 )
{
int V_23 = 0 ;
T_2 V_24 [ 2 ] ;
int V_25 = V_26 -> V_25 ;
char * V_27 = V_26 -> V_27 ;
int V_28 = V_26 -> V_28 ;
F_5 ( & V_22 -> V_29 , L_3 ,
( V_22 -> V_7 + 500 ) / 1000 ) ;
if ( V_26 -> V_1 != V_22 -> V_30 -> V_8 ||
V_26 -> V_2 != V_22 -> V_9 )
return - V_31 ;
while ( V_25 > 0 ) {
int V_32 = V_25 < V_17 ? V_25 : V_17 ;
V_24 [ 0 ] = 0x03 ;
V_24 [ 1 ] = V_28 ;
V_23 = F_6 ( V_22 , V_24 , sizeof( V_24 ) , V_27 , V_32 ) ;
V_27 += V_32 ;
V_25 -= V_32 ;
V_28 += V_32 ;
}
return V_23 ;
}
int T_1 F_7 ( int V_1 , int V_2 , int V_28 ,
unsigned char * V_27 , int V_25 )
{
int V_33 ;
struct V_26 V_34 = {
. V_1 = V_1 ,
. V_2 = V_2 ,
. V_28 = V_28 ,
. V_27 = V_27 ,
. V_25 = V_25
} ;
V_26 = & V_34 ;
V_33 = F_8 ( & V_35 ) ;
if ( ! V_33 )
F_9 ( & V_35 ) ;
return V_33 ;
}
