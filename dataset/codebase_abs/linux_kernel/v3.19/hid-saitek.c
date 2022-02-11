static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned long V_5 = V_4 -> V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_2 ( & V_2 -> V_10 , sizeof( * V_8 ) , V_11 ) ;
if ( V_8 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return - V_12 ;
}
V_8 -> V_5 = V_5 ;
V_8 -> V_13 = - 1 ;
F_4 ( V_2 , V_8 ) ;
V_9 = F_5 ( V_2 ) ;
if ( V_9 ) {
F_3 ( V_2 , L_2 ) ;
return V_9 ;
}
V_9 = F_6 ( V_2 , V_14 ) ;
if ( V_9 ) {
F_3 ( V_2 , L_3 ) ;
return V_9 ;
}
return 0 ;
}
static T_1 * F_7 ( struct V_1 * V_2 , T_1 * V_15 ,
unsigned int * V_16 )
{
struct V_7 * V_8 = F_8 ( V_2 ) ;
if ( ( V_8 -> V_5 & V_17 ) && * V_16 == 137 &&
V_15 [ 20 ] == 0x09 && V_15 [ 21 ] == 0x33 &&
V_15 [ 94 ] == 0x81 && V_15 [ 95 ] == 0x03 &&
V_15 [ 110 ] == 0x81 && V_15 [ 111 ] == 0x03 ) {
F_9 ( V_2 , L_4 ) ;
V_15 [ 20 ] = 0x15 ;
V_15 [ 21 ] = 0x00 ;
V_15 [ 95 ] = 0x02 ;
V_15 [ 111 ] = 0x02 ;
}
return V_15 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_18 * V_19 , T_2 * V_20 , int V_21 )
{
struct V_7 * V_8 = F_8 ( V_2 ) ;
if ( V_8 -> V_5 & V_22 && V_21 == 7 ) {
int V_13 = - 1 ;
if ( V_20 [ 1 ] & 0x01 )
V_13 = 0 ;
else if ( V_20 [ 1 ] & 0x02 )
V_13 = 1 ;
else if ( V_20 [ 1 ] & 0x04 )
V_13 = 2 ;
V_20 [ 1 ] &= ~ 0x07 ;
if ( V_13 != V_8 -> V_13 ) {
F_11 ( V_2 , L_5 , V_13 ) ;
if ( V_8 -> V_13 != - 1 ) {
V_20 [ 1 ] |= 0x04 ;
}
V_8 -> V_13 = V_13 ;
}
} else if ( V_8 -> V_5 & V_23 && V_21 == 8 ) {
int V_13 = - 1 ;
if ( V_20 [ 1 ] & 0x80 )
V_13 = 0 ;
else if ( V_20 [ 2 ] & 0x01 )
V_13 = 1 ;
else if ( V_20 [ 2 ] & 0x02 )
V_13 = 2 ;
V_20 [ 1 ] &= ~ 0x80 ;
V_20 [ 2 ] &= ~ 0x03 ;
if ( V_13 != V_8 -> V_13 ) {
F_11 ( V_2 , L_5 , V_13 ) ;
if ( V_8 -> V_13 != - 1 ) {
V_20 [ 1 ] |= 0x80 ;
}
V_8 -> V_13 = V_13 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_26 * V_27 , T_3 V_28 )
{
struct V_7 * V_8 = F_8 ( V_2 ) ;
struct V_29 * V_30 = V_25 -> V_31 -> V_30 ;
if ( V_27 -> type == V_32 && V_28 &&
( ( ( V_8 -> V_5 & V_22 ) &&
V_27 -> V_33 - V_34 == 10 ) ||
( ( V_8 -> V_5 & V_23 ) &&
V_27 -> V_33 - V_34 == 15 ) ) ) {
F_13 ( V_30 , V_27 -> V_33 , 1 ) ;
F_13 ( V_30 , V_27 -> V_33 , 0 ) ;
return 1 ;
}
return 0 ;
}
