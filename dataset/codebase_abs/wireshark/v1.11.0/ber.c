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
V_4 -> V_13 = 0 ;
V_4 -> V_14 = V_9 ;
V_4 -> V_15 = V_9 ;
V_4 -> V_16 . V_17 = 0 ;
V_4 -> V_16 . V_18 = 0 ;
return F_4 ( V_2 , V_5 , V_9 , V_6 , V_7 ) ;
}
static T_1 F_5 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 , T_6 * V_19 )
{
T_6 V_20 ;
* V_6 = 0 ;
V_20 = F_6 ( V_1 -> V_2 ) ;
if ( V_20 != 0 )
return FALSE ;
* V_19 = V_20 ;
return F_1 ( V_1 , V_1 -> V_2 , & V_1 -> V_4 , V_1 -> V_21 , V_6 , V_7 ) ;
}
static T_1 F_7 ( T_2 * V_1 , T_6 V_22 , struct V_3 * V_4 V_23 ,
T_4 * V_5 , int T_7 V_23 , int * V_6 , T_5 * * V_7 )
{
if( V_22 > 0 ) {
* V_6 = 0 ;
return FALSE ;
}
if ( F_8 ( V_1 -> V_24 , V_22 , V_25 , V_6 ) == - 1 )
return FALSE ;
return F_1 ( V_1 , V_1 -> V_24 , V_4 , V_5 , V_6 , V_7 ) ;
}
int F_9 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 )
{
#define F_10 8
T_8 V_26 [ F_10 ] ;
int V_27 ;
T_8 V_28 ;
T_9 V_29 ;
T_9 V_30 ;
T_1 V_31 ;
T_8 V_32 , V_33 = 0 ;
int V_15 = 0 ;
T_6 V_8 ;
int V_20 = 0 , V_34 ;
V_27 = F_11 ( & V_26 , F_10 , V_1 -> V_2 ) ;
if ( V_27 != F_10 ) {
* V_6 = F_12 ( V_1 -> V_2 , V_7 ) ;
if ( * V_6 != 0 && * V_6 != V_35 )
return - 1 ;
return 0 ;
}
V_28 = V_26 [ V_20 ++ ] ;
V_29 = ( V_28 >> 6 ) & 0x03 ;
V_31 = ( V_28 >> 5 ) & 0x01 ;
V_30 = V_28 & 0x1F ;
if( ! ( V_31 &&
( ( ( V_29 == V_36 ) && ( ( V_30 == V_37 ) || ( V_30 == V_38 ) ) ) ||
( ( V_29 == V_39 ) && ( V_30 < 32 ) ) ) ) )
return 0 ;
V_32 = V_26 [ V_20 ++ ] ;
if( V_32 != 0x80 ) {
if( ! ( V_32 & 0x80 ) )
V_15 = V_32 ;
else {
V_33 = V_32 & 0x7F ;
if( ( V_33 > 0 ) && ( V_33 <= ( F_10 - 2 ) ) ) {
V_34 = V_33 ;
while( V_34 -- ) {
V_32 = V_26 [ V_20 ++ ] ;
V_15 = ( V_15 << 8 ) + V_32 ;
}
}
}
V_15 += ( 2 + V_33 ) ;
V_8 = F_2 ( V_1 , V_6 ) ;
if( V_15 != V_8 ) {
return 0 ;
}
} else {
}
if ( F_8 ( V_1 -> V_2 , 0 , V_25 , V_6 ) == - 1 )
return - 1 ;
V_1 -> V_40 = V_41 ;
V_1 -> V_42 = V_43 ;
V_1 -> V_44 = 0 ;
V_1 -> V_45 = F_5 ;
V_1 -> V_46 = F_7 ;
V_1 -> V_47 = V_48 ;
return 1 ;
}
