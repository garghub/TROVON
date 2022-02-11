static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_3 = V_3 | V_5 ;
V_4 = F_2 ( V_2 , V_3 ) ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_3 = V_3 | V_5 | V_6 ;
V_4 = F_4 ( V_2 , V_3 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
T_1 V_8 [ 2 ] = { V_3 , V_7 } ;
return F_6 ( V_2 , V_8 , sizeof( V_8 ) ) ;
}
static T_2 F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_16 * V_17 = F_9 ( V_12 ) ;
int V_4 , V_7 , V_18 = 0 ;
T_3 V_19 , V_20 ;
V_19 = V_17 -> V_21 ;
F_5 ( V_2 , V_22 ,
( V_23 | V_24 | V_19 ) ) ;
V_4 = F_1 ( V_2 , V_22 ) ;
V_20 = ( ( V_4 & V_23 ) >> V_25 ) ;
while ( ( V_18 < 2 ) && V_20 ) {
V_18 ++ ;
V_4 = F_1 ( V_2 , V_22 ) ;
V_20 = ( ( V_4 & V_23 ) >> V_25 ) ;
F_10 ( 1 ) ;
}
if ( V_20 == 0 ) {
V_7 = F_3 ( V_2 , V_26 ) ;
V_7 = ( ( V_7 >> 2 ) * 25000 ) / 8192 ;
return sprintf ( V_13 , L_1 , V_7 ) ;
} else {
return - 1 ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_4 ;
T_3 V_7 ;
struct V_14 * V_15 ;
struct V_9 * V_27 ;
V_2 -> V_28 = ( V_29 ) ;
V_2 -> V_30 = 8 ;
F_12 ( V_2 ) ;
F_5 ( V_2 , V_31 , 0 ) ;
F_5 ( V_2 , V_32 , 0 ) ;
V_7 = ( V_33 | V_34 | V_35 | V_36 ) ;
F_5 ( V_2 , V_37 , V_7 ) ;
V_4 = F_1 ( V_2 , V_37 ) ;
F_13 ( V_10 , L_2 , V_7 , V_4 ) ;
if ( V_7 != V_4 )
return - V_38 ;
V_15 = F_14 ( V_10 , sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_15 )
return - V_40 ;
V_15 -> V_2 = V_2 ;
V_27 = F_15 ( V_10 , V_2 -> V_41 ,
V_15 ,
V_42 ) ;
return F_16 ( V_27 ) ;
}
