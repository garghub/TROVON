void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 * V_4 ;
T_2 * V_5 ;
T_3 * V_6 ;
F_2 ( L_1 , V_3 ) ;
V_4 = F_3 ( V_2 , V_3 & V_7 ) ;
if ( V_4 ) {
V_5 = F_4 ( F_5 ( V_4 , V_3 & V_7 ) ,
V_3 & V_7 ) ;
if ( V_5 && F_6 ( * V_5 ) ) {
V_6 = F_7 ( V_5 , V_3 & V_7 ) ;
if ( V_6 ) {
F_2 ( L_2 ,
( long ) V_4 , ( long ) V_6 , ( long ) F_8 ( * V_6 ) ) ;
#define F_9 ((long)pte_val(*pte))
F_2 ( L_3
L_4 ,
F_9 >> 12 ,
( F_9 >> 10 ) & 3 ,
( F_9 >> 3 ) & 1 ,
( F_9 >> 2 ) & 1 ,
( F_9 >> 1 ) & 1 ,
F_9 & 1
) ;
#undef F_9
}
else {
F_2 ( L_5 ) ;
}
}
else {
F_2 ( L_6 ) ;
}
}
else {
F_2 ( L_7 ) ;
}
}
int F_10 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 * V_4 ;
T_2 * V_5 ;
T_3 * V_6 ;
int V_8 = 0 ;
V_4 = F_3 ( V_2 , V_3 & V_7 ) ;
if ( V_4 ) {
V_5 = F_4 ( F_5 ( V_4 , V_3 & V_7 ) ,
V_3 & V_7 ) ;
if ( V_5 && F_6 ( * V_5 ) ) {
V_6 = F_7 ( V_5 , V_3 & V_7 ) ;
if ( V_6 ) {
V_8 = ( int ) F_8 ( * V_6 ) ;
}
}
}
return V_8 ;
}
int F_11 ( struct V_9 * V_10 )
{
T_4 V_11 , V_12 ;
T_4 V_13 , V_14 , V_15 ;
int V_8 ;
T_5 V_16 ;
T_4 * V_17 , * V_18 ;
V_8 = 0 ;
V_12 = * ( ( T_4 * ) V_10 -> V_19 ) ;
V_11 = V_12 >> 26 ;
V_13 = ( V_12 >> 21 ) & 0x1f ;
V_14 = ( V_12 >> 16 ) & 0x1f ;
V_15 = V_12 & 0xffff ;
V_17 = ( T_4 * ) ( V_10 -> V_20 [ V_14 ] + V_15 ) ;
V_18 = ( T_4 * ) & V_21 -> V_22 . V_23 ( V_13 ) ;
switch ( V_11 )
{
case V_24 :
V_16 = ( V_12 & 0xffff ) ;
V_17 = ( T_4 * ) ( V_10 -> V_20 [ V_14 ] + V_16 ) ;
if ( F_12 ( V_18 , V_17 , sizeof( double ) ) )
V_8 = - V_25 ;
break;
case V_26 :
if ( F_12 ( V_18 , V_17 , sizeof( double ) ) )
V_8 = - V_25 ;
else
V_10 -> V_20 [ V_14 ] = ( T_4 ) V_17 ;
break;
case V_27 :
V_16 = ( V_12 & 0xffff ) ;
V_17 = ( T_4 * ) ( V_10 -> V_20 [ V_14 ] + V_16 ) ;
if ( F_12 ( V_18 , V_17 , sizeof( float ) ) )
V_8 = - V_25 ;
break;
case V_28 :
V_16 = ( V_12 & 0xffff ) ;
V_17 = ( T_4 * ) ( V_10 -> V_20 [ V_14 ] + V_16 ) ;
if ( F_13 ( V_17 , V_18 , sizeof( double ) ) )
V_8 = - V_25 ;
break;
case V_29 :
if ( F_13 ( V_17 , V_18 , sizeof( double ) ) )
V_8 = - V_25 ;
else
V_10 -> V_20 [ V_14 ] = ( T_4 ) V_17 ;
break;
case V_30 :
memcpy ( V_18 , & V_21 -> V_22 . V_23 ( ( V_12 >> 11 ) & 0x1f ) ,
sizeof( double ) ) ;
break;
default:
V_8 = 1 ;
F_2 ( L_8
L_9
L_10 ,
V_21 -> V_31 , V_21 -> V_32 ,
V_10 -> V_19 ,
V_12 , V_11 ,
( V_12 >> 16 ) & 0x1f ,
( V_12 >> 11 ) & 0x1f ,
( V_12 >> 6 ) & 0x1f ,
( V_12 >> 1 ) & 0x3ff ,
V_12 & 1 ) ;
{
int V_33 ;
F_1 ( V_21 -> V_2 , V_10 -> V_19 ) ;
V_33 = F_10 ( V_21 -> V_2 , V_10 -> V_19 ) & V_7 ;
V_33 |= ( V_10 -> V_19 & ~ V_7 ) ;
V_33 = ( unsigned long ) F_14 ( V_33 ) ;
F_2 ( L_11 , V_33 ) ;
F_1 ( V_21 -> V_2 , V_33 ) ;
}
}
if ( V_8 == 0 )
V_10 -> V_19 += 4 ;
return V_8 ;
}
