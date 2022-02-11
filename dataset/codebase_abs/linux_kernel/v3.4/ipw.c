static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_6 ;
T_1 V_8 [ 16 ] = V_9 ;
T_1 * V_10 ;
int V_11 ;
F_2 ( L_1 , V_12 ) ;
V_10 = F_3 ( V_8 , 16 , V_13 ) ;
if ( ! V_10 )
return - V_14 ;
F_2 ( L_2 , V_12 ) ;
V_11 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_15 ,
V_16 | V_17 | V_18 ,
0 ,
0 ,
NULL ,
0 ,
100000 ) ;
if ( V_11 < 0 )
F_6 ( & V_4 -> V_6 ,
L_3 , V_11 ) ;
F_7 ( V_6 ,
F_8 ( V_6 , V_4 -> V_19 ) ) ;
F_7 ( V_6 ,
F_9 ( V_6 , V_4 -> V_20 ) ) ;
F_2 ( L_4 , V_12 ) ;
F_10 ( V_2 , V_4 ) ;
F_2 ( L_5 , V_12 ) ;
V_11 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_21 ,
V_16 | V_17 | V_18 ,
V_22 ,
0 ,
NULL ,
0 ,
100000 ) ;
if ( V_11 < 0 )
F_6 ( & V_4 -> V_6 ,
L_6 , V_11 ) ;
F_2 ( L_7 , V_12 , V_10 ) ;
V_11 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_23 ,
V_16 | V_17 | V_18 ,
0 ,
0 ,
V_10 ,
0x10 ,
200000 ) ;
if ( V_11 < 0 )
F_6 ( & V_4 -> V_6 ,
L_8 , V_11 ) ;
F_11 ( V_10 ) ;
return 0 ;
}
static int F_12 ( struct V_24 * V_7 , const struct V_25 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_13 ( sizeof( struct V_27 ) , V_13 ) ;
if ( ! V_28 )
return - V_14 ;
F_14 ( & V_28 -> V_29 ) ;
F_15 ( V_7 , V_28 ) ;
return 0 ;
}
static void F_16 ( struct V_24 * V_7 )
{
struct V_27 * V_28 = F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
F_15 ( V_7 , NULL ) ;
F_11 ( V_28 ) ;
}
static void F_19 ( struct V_3 * V_4 , int V_30 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_6 ;
int V_11 ;
F_2 ( L_9 , V_12 , V_30 ) ;
V_11 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_31 ,
V_16 | V_17 | V_18 ,
V_30 ? V_32 : V_33 ,
0 ,
NULL ,
0 ,
200000 ) ;
if ( V_11 < 0 )
F_6 ( & V_4 -> V_6 , L_10 ,
V_11 ) ;
V_11 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_31 , V_16 |
V_17 | V_18 ,
V_30 ? V_34 : V_35 ,
0 ,
NULL ,
0 ,
200000 ) ;
if ( V_11 < 0 )
F_6 ( & V_4 -> V_6 , L_11 ,
V_11 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_6 ;
int V_11 ;
F_2 ( L_12 , V_12 ) ;
V_11 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_36 , V_16 |
V_17 | V_18 ,
0x03 ,
0 ,
NULL ,
0 ,
200000 ) ;
if ( V_11 < 0 )
F_6 ( & V_4 -> V_6 , L_13 , V_11 ) ;
V_11 = F_4 ( V_6 , F_5 ( V_6 , 0 ) ,
V_21 ,
V_16 | V_17 | V_18 ,
V_37 ,
0 ,
NULL ,
0 ,
100000 ) ;
if ( V_11 < 0 )
F_6 ( & V_4 -> V_6 ,
L_14 , V_11 ) ;
F_21 ( V_4 ) ;
}
