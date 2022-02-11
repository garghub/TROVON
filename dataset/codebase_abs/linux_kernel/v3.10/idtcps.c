static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 V_5 , T_1 V_6 , T_2 V_7 )
{
T_3 V_8 ;
if ( V_7 == V_9 )
V_7 = V_10 ;
if ( V_5 == V_11 ) {
F_2 ( V_2 , V_3 , V_4 ,
V_12 , V_6 ) ;
F_3 ( V_2 , V_3 , V_4 ,
V_13 , & V_8 ) ;
V_8 = ( 0xffffff00 & V_8 ) | ( T_3 ) V_7 ;
F_2 ( V_2 , V_3 , V_4 ,
V_13 , V_8 ) ;
}
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 V_5 , T_1 V_6 , T_2 * V_7 )
{
T_3 V_8 ;
if ( V_5 == V_11 ) {
F_2 ( V_2 , V_3 , V_4 ,
V_12 , V_6 ) ;
F_3 ( V_2 , V_3 , V_4 ,
V_13 , & V_8 ) ;
if ( V_10 == ( T_2 ) V_8 ||
V_14 == ( T_2 ) V_8 )
* V_7 = V_9 ;
else
* V_7 = ( T_2 ) V_8 ;
}
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 V_5 )
{
T_3 V_15 ;
if ( V_5 == V_11 ) {
for ( V_15 = 0x80000000 ; V_15 <= 0x800000ff ; ) {
F_2 ( V_2 , V_3 , V_4 ,
V_12 , V_15 ) ;
F_2 ( V_2 , V_3 , V_4 ,
V_13 ,
( V_10 << 24 ) |
( V_10 << 16 ) |
( V_10 << 8 ) | V_10 ) ;
V_15 += 4 ;
}
}
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_16 )
{
F_2 ( V_2 , V_3 , V_4 ,
V_17 , ( T_3 ) V_16 ) ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_16 )
{
T_3 V_18 ;
F_3 ( V_2 , V_3 , V_4 ,
V_17 , & V_18 ) ;
* V_16 = ( T_2 ) ( V_18 & 0xff ) ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 , int V_21 )
{
F_9 ( L_1 , V_22 , F_10 ( V_20 ) ) ;
V_20 -> V_23 -> V_24 = F_1 ;
V_20 -> V_23 -> V_25 = F_4 ;
V_20 -> V_23 -> V_26 = F_5 ;
V_20 -> V_23 -> V_27 = F_6 ;
V_20 -> V_23 -> V_28 = F_7 ;
V_20 -> V_23 -> V_29 = NULL ;
V_20 -> V_23 -> V_30 = NULL ;
if ( V_21 ) {
F_11 ( V_20 ,
V_20 -> V_31 + V_32 , 0x8e << 8 ) ;
F_11 ( V_20 ,
V_33 , V_14 ) ;
}
return 0 ;
}
