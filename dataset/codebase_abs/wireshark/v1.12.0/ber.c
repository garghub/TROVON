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
return F_4 ( V_2 , V_5 , V_9 , V_6 , V_7 ) ;
}
static T_1 F_5 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 , T_6 * V_21 )
{
T_6 V_22 ;
* V_6 = 0 ;
V_22 = F_6 ( V_1 -> V_2 ) ;
if ( V_22 != 0 )
return FALSE ;
* V_21 = V_22 ;
return F_1 ( V_1 , V_1 -> V_2 , & V_1 -> V_4 , V_1 -> V_23 , V_6 , V_7 ) ;
}
static T_1 F_7 ( T_2 * V_1 , T_6 V_24 , struct V_3 * V_4 V_25 ,
T_4 * V_5 , int * V_6 , T_5 * * V_7 )
{
if( V_24 > 0 ) {
* V_6 = 0 ;
return FALSE ;
}
if ( F_8 ( V_1 -> V_26 , V_24 , V_27 , V_6 ) == - 1 )
return FALSE ;
return F_1 ( V_1 , V_1 -> V_26 , V_4 , V_5 , V_6 , V_7 ) ;
}
int F_9 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 )
{
#define F_10 8
T_7 V_28 [ F_10 ] ;
int V_29 ;
T_7 V_30 ;
T_8 V_31 ;
T_8 V_32 ;
T_1 V_33 ;
T_7 V_34 , V_35 = 0 ;
int V_17 = 0 ;
T_6 V_8 ;
int V_22 = 0 , V_36 ;
V_29 = F_11 ( & V_28 , F_10 , V_1 -> V_2 ) ;
if ( V_29 != F_10 ) {
* V_6 = F_12 ( V_1 -> V_2 , V_7 ) ;
if ( * V_6 != 0 && * V_6 != V_37 )
return - 1 ;
return 0 ;
}
V_30 = V_28 [ V_22 ++ ] ;
V_31 = ( V_30 >> 6 ) & 0x03 ;
V_33 = ( V_30 >> 5 ) & 0x01 ;
V_32 = V_30 & 0x1F ;
if( ! ( V_33 &&
( ( ( V_31 == V_38 ) && ( ( V_32 == V_39 ) || ( V_32 == V_40 ) ) ) ||
( ( V_31 == V_41 ) && ( V_32 < 32 ) ) ) ) )
return 0 ;
V_34 = V_28 [ V_22 ++ ] ;
if( V_34 != 0x80 ) {
if( ! ( V_34 & 0x80 ) )
V_17 = V_34 ;
else {
V_35 = V_34 & 0x7F ;
if( ( V_35 > 0 ) && ( V_35 <= ( F_10 - 2 ) ) ) {
V_36 = V_35 ;
while( V_36 -- ) {
V_34 = V_28 [ V_22 ++ ] ;
V_17 = ( V_17 << 8 ) + V_34 ;
}
}
}
V_17 += ( 2 + V_35 ) ;
V_8 = F_2 ( V_1 , V_6 ) ;
if( V_17 != V_8 ) {
return 0 ;
}
} else {
}
if ( F_8 ( V_1 -> V_2 , 0 , V_27 , V_6 ) == - 1 )
return - 1 ;
V_1 -> V_42 = V_43 ;
V_1 -> V_44 = V_45 ;
V_1 -> V_46 = 0 ;
V_1 -> V_47 = F_5 ;
V_1 -> V_48 = F_7 ;
V_1 -> V_49 = V_50 ;
return 1 ;
}
