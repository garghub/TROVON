T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 type , V_4 ;
type = V_3 & V_5 ;
V_3 &= ~ V_5 ;
F_2 ( V_3 > 0xFFFF ) ;
switch ( type ) {
case V_6 :
F_3 ( V_2 , V_7 , V_3 ) ;
V_4 = F_4 ( V_2 , V_8 ) & 0xFF ;
break;
case V_9 :
F_3 ( V_2 , V_7 , V_3 ) ;
V_4 = F_4 ( V_2 , V_8 ) ;
break;
case V_10 :
F_3 ( V_2 , V_7 , V_3 ) ;
V_4 = F_4 ( V_2 , V_11 ) ;
V_4 <<= 16 ;
V_4 |= F_4 ( V_2 , V_8 ) ;
break;
default:
F_2 ( 1 ) ;
V_4 = 0 ;
}
return V_4 ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_12 , void * V_13 )
{
T_1 type ;
T_2 * V_14 = V_13 ;
unsigned int V_15 ;
type = V_3 & V_5 ;
V_3 &= ~ V_5 ;
F_2 ( V_3 > 0xFFFF ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
switch ( type ) {
case V_6 :
* V_14 = F_4 ( V_2 , V_8 ) & 0xFF ;
V_14 ++ ;
break;
case V_9 :
* ( ( V_16 * ) V_14 ) = F_4 ( V_2 , V_8 ) ;
V_14 += 2 ;
break;
case V_10 :
* ( ( T_1 * ) V_14 ) = F_4 ( V_2 , V_11 ) ;
* ( ( T_1 * ) V_14 ) <<= 16 ;
* ( ( T_1 * ) V_14 ) |= F_4 ( V_2 , V_8 ) ;
V_14 += 4 ;
break;
default:
F_2 ( 1 ) ;
}
}
}
void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 type ;
type = V_3 & V_5 ;
V_3 &= 0xFFFF ;
switch ( type ) {
case V_6 :
F_2 ( V_4 & ~ 0xFF ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
F_3 ( V_2 , V_8 , V_4 ) ;
break;
case V_9 :
F_2 ( V_4 & ~ 0xFFFF ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
F_3 ( V_2 , V_8 , V_4 ) ;
break;
case V_10 :
F_3 ( V_2 , V_7 , V_3 ) ;
F_3 ( V_2 , V_11 , V_4 >> 16 ) ;
F_3 ( V_2 , V_8 , V_4 & 0xFFFF ) ;
break;
default:
F_2 ( 1 ) ;
}
return;
}
void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_12 , const void * V_13 )
{
T_1 type , V_4 ;
const T_2 * V_14 = V_13 ;
unsigned int V_15 ;
type = V_3 & V_5 ;
V_3 &= ~ V_5 ;
F_2 ( V_3 > 0xFFFF ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
switch ( type ) {
case V_6 :
V_4 = * V_14 ;
V_14 ++ ;
F_2 ( V_4 & ~ 0xFF ) ;
F_3 ( V_2 , V_8 , V_4 ) ;
break;
case V_9 :
V_4 = * ( ( V_16 * ) V_14 ) ;
V_14 += 2 ;
F_2 ( V_4 & ~ 0xFFFF ) ;
F_3 ( V_2 , V_8 , V_4 ) ;
break;
case V_10 :
V_4 = * ( ( T_1 * ) V_14 ) ;
V_14 += 4 ;
F_3 ( V_2 , V_11 , V_4 >> 16 ) ;
F_3 ( V_2 , V_8 ,
V_4 & 0xFFFF ) ;
break;
default:
F_2 ( 1 ) ;
}
}
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , F_10 ( 0x12 , 0 ) , V_17 ) ;
F_9 ( V_2 , F_10 ( 0x27 , 0 ) , V_18 ) ;
F_9 ( V_2 , F_10 ( 0x26 , 0 ) , V_19 ) ;
F_9 ( V_2 , F_11 ( 0x25 , 0 ) , V_20 ) ;
F_9 ( V_2 , F_11 ( 0x2f , 0 ) , V_21 ) ;
F_9 ( V_2 , F_10 ( 0x1a , 0 ) , V_22 ) ;
F_9 ( V_2 , F_10 ( 0x1b , 0 ) , V_23 ) ;
F_9 ( V_2 , F_10 ( 0x1c , 0 ) , V_24 ) ;
F_9 ( V_2 , F_11 ( 0x1a , 0x0c0 ) , V_25 ) ;
F_9 ( V_2 , F_11 ( 0x1a , 0x140 ) , V_26 ) ;
F_9 ( V_2 , F_11 ( 0x1b , 0x140 ) , V_27 ) ;
F_9 ( V_2 , F_11 ( 0x1c , 0x140 ) , V_28 ) ;
F_9 ( V_2 , F_10 ( 0x1a , 0x1c0 ) , V_29 ) ;
F_9 ( V_2 , F_10 ( 0x1b , 0x1c0 ) , V_30 ) ;
F_9 ( V_2 , F_10 ( 0x1c , 0x1c0 ) , V_31 ) ;
F_9 ( V_2 , F_10 ( 0x1a , 0x240 ) , V_32 ) ;
F_9 ( V_2 , F_10 ( 0x1b , 0x240 ) , V_33 ) ;
F_9 ( V_2 , F_10 ( 0x1c , 0x240 ) , V_34 ) ;
F_9 ( V_2 , F_11 ( 0x1f , 0 ) , V_35 ) ;
F_9 ( V_2 , F_11 ( 0x21 , 0 ) , V_36 ) ;
F_9 ( V_2 , F_11 ( 0x23 , 0 ) , V_37 ) ;
F_9 ( V_2 , F_11 ( 0x20 , 0 ) , V_38 ) ;
F_9 ( V_2 , F_11 ( 0x22 , 0 ) , V_39 ) ;
F_9 ( V_2 , F_11 ( 0x24 , 0 ) , V_40 ) ;
}
