static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_8 = & V_4 -> V_8 ;
T_1 V_10 [ 16 ] = V_11 ;
T_1 * V_12 ;
int V_13 ;
V_12 = F_2 ( V_10 , 16 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
F_3 ( V_8 , L_1 , V_16 ) ;
V_13 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_17 ,
V_18 | V_19 | V_20 ,
0 ,
0 ,
NULL ,
0 ,
100000 ) ;
if ( V_13 < 0 )
F_6 ( V_8 , L_2 , V_13 ) ;
F_7 ( V_6 , F_8 ( V_6 , V_4 -> V_21 ) ) ;
F_7 ( V_6 , F_9 ( V_6 , V_4 -> V_22 ) ) ;
F_3 ( V_8 , L_3 , V_16 ) ;
F_10 ( V_2 , V_4 ) ;
F_3 ( V_8 , L_4 , V_16 ) ;
V_13 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_23 ,
V_18 | V_19 | V_20 ,
V_24 ,
0 ,
NULL ,
0 ,
100000 ) ;
if ( V_13 < 0 )
F_6 ( V_8 , L_5 , V_13 ) ;
F_3 ( V_8 , L_6 , V_16 , V_12 ) ;
V_13 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_25 ,
V_18 | V_19 | V_20 ,
0 ,
0 ,
V_12 ,
0x10 ,
200000 ) ;
if ( V_13 < 0 )
F_6 ( V_8 , L_7 , V_13 ) ;
F_11 ( V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_26 * V_7 )
{
struct V_27 * V_28 ;
V_28 = F_13 ( sizeof( struct V_27 ) , V_14 ) ;
if ( ! V_28 )
return - V_15 ;
F_14 ( & V_28 -> V_29 ) ;
F_15 ( V_7 , V_28 ) ;
return 0 ;
}
static void F_16 ( struct V_26 * V_7 )
{
struct V_27 * V_28 = F_17 ( V_7 ) ;
F_15 ( V_7 , NULL ) ;
F_11 ( V_28 ) ;
}
static void F_18 ( struct V_3 * V_4 , int V_30 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_8 = & V_4 -> V_8 ;
int V_13 ;
F_3 ( V_8 , L_8 , V_16 , V_30 ) ;
V_13 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_31 ,
V_18 | V_19 | V_20 ,
V_30 ? V_32 : V_33 ,
0 ,
NULL ,
0 ,
200000 ) ;
if ( V_13 < 0 )
F_6 ( V_8 , L_9 , V_13 ) ;
V_13 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_31 , V_18 |
V_19 | V_20 ,
V_30 ? V_34 : V_35 ,
0 ,
NULL ,
0 ,
200000 ) ;
if ( V_13 < 0 )
F_6 ( V_8 , L_10 , V_13 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_8 = & V_4 -> V_8 ;
int V_13 ;
F_3 ( V_8 , L_11 , V_16 ) ;
V_13 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_36 , V_18 |
V_19 | V_20 ,
0x03 ,
0 ,
NULL ,
0 ,
200000 ) ;
if ( V_13 < 0 )
F_6 ( V_8 , L_12 , V_13 ) ;
V_13 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_23 ,
V_18 | V_19 | V_20 ,
V_37 ,
0 ,
NULL ,
0 ,
100000 ) ;
if ( V_13 < 0 )
F_6 ( V_8 , L_13 , V_13 ) ;
F_20 ( V_4 ) ;
}
