static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 V_5 , T_1 V_6 , T_2 V_7 )
{
if ( V_5 == V_8 ) {
F_2 ( V_2 , V_3 , V_4 ,
V_9 , V_6 ) ;
F_2 ( V_2 , V_3 , V_4 ,
V_10 , V_7 ) ;
} else {
F_2 ( V_2 , V_3 , V_4 ,
F_3 ( V_5 ) ,
V_6 ) ;
F_2 ( V_2 , V_3 , V_4 ,
F_4 ( V_5 ) , V_7 ) ;
}
F_5 ( 10 ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 V_5 , T_1 V_6 , T_2 * V_7 )
{
int V_11 = 0 ;
T_3 V_12 ;
if ( V_5 == V_8 ) {
F_2 ( V_2 , V_3 , V_4 ,
V_9 , V_6 ) ;
F_7 ( V_2 , V_3 , V_4 ,
V_10 , & V_12 ) ;
} else {
F_2 ( V_2 , V_3 , V_4 ,
F_3 ( V_5 ) ,
V_6 ) ;
F_7 ( V_2 , V_3 , V_4 ,
F_4 ( V_5 ) , & V_12 ) ;
}
* V_7 = V_12 ;
if ( * V_7 > 15 )
V_11 = - 1 ;
return V_11 ;
}
static int
F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 V_5 )
{
T_3 V_13 ;
T_3 V_14 ;
V_14 = ( V_2 -> V_15 ) ? 0x1ff : 0xff ;
if ( V_5 == V_8 ) {
F_2 ( V_2 , V_3 , V_4 ,
V_9 , 0x80000000 ) ;
for ( V_13 = 0 ; V_13 <= V_14 ; V_13 ++ )
F_2 ( V_2 , V_3 , V_4 ,
V_10 ,
V_16 ) ;
} else {
F_2 ( V_2 , V_3 , V_4 ,
F_3 ( V_5 ) ,
0x80000000 ) ;
for ( V_13 = 0 ; V_13 <= V_14 ; V_13 ++ )
F_2 ( V_2 , V_3 , V_4 ,
F_4 ( V_5 ) ,
V_16 ) ;
}
return 0 ;
}
static int
F_9 ( struct V_17 * V_18 )
{
T_3 V_19 ;
int V_20 ;
F_10 ( L_1 , V_21 , V_18 -> V_3 , V_18 -> V_4 ) ;
for ( V_20 = 0 ;
V_20 < F_11 ( V_18 -> V_22 ) ; V_20 ++ ) {
F_12 ( V_18 , F_13 ( V_20 ) , & V_19 ) ;
F_14 ( V_18 , F_13 ( V_20 ) ,
V_19 | V_23 ) ;
}
return 0 ;
}
static int F_15 ( struct V_17 * V_18 , int V_24 )
{
F_10 ( L_2 , V_21 , F_16 ( V_18 ) ) ;
V_18 -> V_25 -> V_26 = F_1 ;
V_18 -> V_25 -> V_27 = F_6 ;
V_18 -> V_25 -> V_28 = F_8 ;
V_18 -> V_25 -> V_29 = NULL ;
V_18 -> V_25 -> V_30 = NULL ;
V_18 -> V_25 -> V_31 = F_9 ;
V_18 -> V_25 -> V_32 = NULL ;
return 0 ;
}
