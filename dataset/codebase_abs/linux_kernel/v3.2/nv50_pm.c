int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 ;
int V_6 , V_7 , V_8 , V_9 ;
T_1 V_10 , V_11 ;
V_9 = F_2 ( V_2 , V_3 , & V_5 ) ;
if ( V_9 )
return V_9 ;
V_10 = F_3 ( V_2 , V_5 . V_12 + 0 ) ;
V_11 = F_3 ( V_2 , V_5 . V_12 + 4 ) ;
if ( ( V_10 & 0x80000000 ) == 0 ) {
if ( V_3 == V_13 ) {
F_4 ( V_2 , L_1
L_2 ) ;
V_9 = F_1 ( V_2 , V_14 ) ;
if ( V_9 > 0 )
return V_9 << 1 ;
} else if ( V_3 == V_15 ) {
F_4 ( V_2 , L_3
L_4 ) ;
return V_5 . V_16 ;
}
}
V_6 = ( V_10 & 0x00070000 ) >> 16 ;
V_7 = ( V_11 & 0x0000ff00 ) >> 8 ;
V_8 = ( V_11 & 0x000000ff ) ;
return ( ( V_5 . V_16 * V_7 / V_8 ) >> V_6 ) ;
}
void *
F_5 ( struct V_1 * V_2 , struct V_17 * V_18 ,
T_1 V_3 , int V_19 )
{
struct V_20 * V_21 ;
int V_22 , V_9 ;
V_21 = F_6 ( sizeof( * V_21 ) , V_23 ) ;
if ( ! V_21 )
return F_7 ( - V_24 ) ;
V_21 -> type = V_3 ;
V_21 -> V_18 = V_18 ;
V_9 = F_2 ( V_2 , V_3 , & V_21 -> V_5 ) ;
if ( V_9 < 0 ) {
F_8 ( V_21 ) ;
return ( V_9 == - V_25 ) ? NULL : F_7 ( V_9 ) ;
}
V_9 = F_9 ( V_2 , & V_21 -> V_5 , V_19 , & V_21 -> V_7 , & V_21 -> V_8 ,
& V_22 , & V_22 , & V_21 -> V_6 ) ;
if ( V_9 < 0 ) {
F_8 ( V_21 ) ;
return F_7 ( V_9 ) ;
}
return V_21 ;
}
void
F_10 ( struct V_1 * V_2 , void * V_26 )
{
struct V_20 * V_21 = V_26 ;
struct V_17 * V_18 = V_21 -> V_18 ;
T_1 V_12 = V_21 -> V_5 . V_12 , V_27 ;
struct V_28 V_29 ;
T_2 V_30 ;
int V_7 = V_21 -> V_7 ;
int V_8 = V_21 -> V_8 ;
int V_6 = V_21 -> V_6 ;
if ( V_21 -> type == V_15 && V_18 -> V_31 &&
F_11 ( V_2 , 'M' , & V_29 ) == 0 &&
V_29 . V_32 == 1 && V_29 . V_33 >= 0x0b ) {
V_30 = F_12 ( V_29 . V_34 [ 0x05 ] ) ;
if ( V_30 )
F_13 ( V_2 , V_30 , NULL , - 1 ) ;
V_30 = F_12 ( V_29 . V_34 [ 0x07 ] ) ;
if ( V_30 )
F_13 ( V_2 , V_30 , NULL , - 1 ) ;
V_30 = F_12 ( V_29 . V_34 [ 0x09 ] ) ;
if ( V_30 )
F_13 ( V_2 , V_30 , NULL , - 1 ) ;
F_13 ( V_2 , V_18 -> V_31 , NULL , - 1 ) ;
}
if ( V_21 -> type == V_15 ) {
F_14 ( V_2 , 0x100210 , 0 ) ;
F_14 ( V_2 , 0x1002dc , 1 ) ;
}
V_27 = F_3 ( V_2 , V_12 + 0 ) & 0xfff8ffff ;
V_27 |= 0x80000000 | ( V_6 << 16 ) ;
F_14 ( V_2 , V_12 + 0 , V_27 ) ;
F_14 ( V_2 , V_12 + 4 , ( V_7 << 8 ) | V_8 ) ;
if ( V_21 -> type == V_15 ) {
F_14 ( V_2 , 0x1002dc , 0 ) ;
F_14 ( V_2 , 0x100210 , 0x80000000 ) ;
}
F_8 ( V_21 ) ;
}
