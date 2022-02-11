static T_1 F_1 ( T_2 * V_1 , T_3 V_2 , struct V_3 * V_4 ,
T_4 * V_5 , int * V_6 , T_5 * * V_7 )
{
T_6 V_8 ;
int V_9 ;
if ( ( V_8 = F_2 ( V_1 , V_6 ) ) == - 1 )
return FALSE ;
if ( V_8 > V_10 ) {
* V_6 = V_11 ;
* V_7 = F_3 ( L_1 V_12 L_2 ,
V_8 , V_10 ) ;
return FALSE ;
}
V_9 = ( int ) V_8 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = 0 ;
V_4 -> V_16 = V_9 ;
V_4 -> V_17 = V_9 ;
V_4 -> V_18 . V_19 = 0 ;
V_4 -> V_18 . V_20 = 0 ;
F_4 ( V_5 , V_9 ) ;
return F_5 ( V_2 , V_5 , V_9 , V_6 , V_7 ) ;
}
static T_1 F_6 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 , T_6 * V_21 )
{
T_6 V_22 ;
* V_6 = 0 ;
V_22 = F_7 ( V_1 -> V_2 ) ;
if ( V_22 != 0 )
return FALSE ;
* V_21 = V_22 ;
return F_1 ( V_1 , V_1 -> V_2 , & V_1 -> V_4 , V_1 -> V_23 , V_6 , V_7 ) ;
}
static T_1 F_8 ( T_2 * V_1 , T_6 V_24 , struct V_3 * V_4 V_25 ,
T_4 * V_5 , int * V_6 , T_5 * * V_7 )
{
if( V_24 > 0 ) {
* V_6 = 0 ;
return FALSE ;
}
if ( F_9 ( V_1 -> V_26 , V_24 , V_27 , V_6 ) == - 1 )
return FALSE ;
return F_1 ( V_1 , V_1 -> V_26 , V_4 , V_5 , V_6 , V_7 ) ;
}
T_7 F_10 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 )
{
#define F_11 8
T_8 V_28 [ F_11 ] ;
T_8 V_29 ;
T_9 V_30 ;
T_9 V_31 ;
T_1 V_32 ;
T_8 V_33 , V_34 = 0 ;
int V_17 = 0 ;
T_6 V_8 ;
int V_22 = 0 , V_35 ;
if ( ! F_12 ( V_1 -> V_2 , & V_28 , F_11 , V_6 , V_7 ) ) {
if ( * V_6 != V_36 )
return V_37 ;
return V_38 ;
}
V_29 = V_28 [ V_22 ++ ] ;
V_30 = ( V_29 >> 6 ) & 0x03 ;
V_32 = ( V_29 >> 5 ) & 0x01 ;
V_31 = V_29 & 0x1F ;
if( ! ( V_32 &&
( ( ( V_30 == V_39 ) && ( ( V_31 == V_40 ) || ( V_31 == V_41 ) ) ) ||
( ( ( V_30 == V_42 ) || ( V_30 == V_43 ) ) && ( V_31 < 32 ) ) ) ) )
return V_38 ;
V_33 = V_28 [ V_22 ++ ] ;
if( V_33 != 0x80 ) {
if( ! ( V_33 & 0x80 ) )
V_17 = V_33 ;
else {
V_34 = V_33 & 0x7F ;
if( ( V_34 > 0 ) && ( V_34 <= ( F_11 - 2 ) ) ) {
V_35 = V_34 ;
while( V_35 -- ) {
V_33 = V_28 [ V_22 ++ ] ;
V_17 = ( V_17 << 8 ) + V_33 ;
}
}
}
V_17 += ( 2 + V_34 ) ;
V_8 = F_2 ( V_1 , V_6 ) ;
if( V_17 != V_8 ) {
return V_38 ;
}
} else {
}
if ( F_9 ( V_1 -> V_2 , 0 , V_27 , V_6 ) == - 1 )
return V_37 ;
V_1 -> V_44 = V_45 ;
V_1 -> V_46 = V_47 ;
V_1 -> V_48 = 0 ;
V_1 -> V_49 = F_6 ;
V_1 -> V_50 = F_8 ;
V_1 -> V_51 = V_52 ;
return V_53 ;
}
