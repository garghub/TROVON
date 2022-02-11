static T_1 F_1 ( T_2 V_1 , struct V_2 * V_3 ,
T_3 * V_4 , int * V_5 , T_4 * * V_6 )
{
T_5 * V_7 , * V_8 ;
T_6 V_9 = 0 ;
T_5 V_10 [ V_11 ] ;
T_5 V_12 , type ;
T_6 V_13 ;
T_7 V_14 = 0 ;
T_5 V_15 = V_16 ;
T_6 V_17 = 0 ;
F_2 ( V_4 , V_18 ) ;
V_7 = F_3 ( V_4 ) ;
V_8 = V_7 ;
V_7 += V_19 ;
do {
if ( ! F_4 ( V_1 , V_10 , sizeof( V_10 ) , V_5 , V_6 ) ) {
if ( V_14 != 0 ) {
if ( * V_5 == 0 )
* V_5 = V_20 ;
}
break;
}
V_12 = V_10 [ 0 ] ;
type = V_10 [ 1 ] ;
V_13 = F_5 ( & V_10 [ 2 ] ) ;
if ( V_15 == V_16 ) {
if ( F_6 ( type ) ) {
V_15 = type ;
V_17 = V_13 ;
}
}
if ( type == V_15 ) {
if ( V_9 != 0 ) {
if ( V_13 - V_9 > 200 * 100 ) {
F_7 ( V_1 , - V_11 , V_21 , V_5 ) ;
break;
}
}
* V_7 ++ = V_12 ;
V_14 ++ ;
V_9 = V_13 ;
}
else if ( F_6 ( type ) ) {
F_7 ( V_1 , - V_11 , V_21 , V_5 ) ;
break;
}
} while ( V_14 < V_22 );
if ( V_15 == V_16 )
return FALSE ;
V_8 [ 0 ] = V_23 ;
if ( V_15 == V_24 || V_15 == V_25 )
V_8 [ 1 ] = V_26 ;
else
V_8 [ 1 ] = V_27 ;
V_8 [ 2 ] = V_14 >> 8 ;
V_8 [ 3 ] = V_14 & 0xFF ;
V_3 -> V_28 = V_29 ;
V_3 -> V_30 = V_31 ;
V_3 -> V_32 = V_33 | V_34 ;
V_3 -> V_35 . V_36 = ( V_37 ) ( ( V_17 * 10 ) / ( 1000 * 1000 * 1000 ) ) ;
V_3 -> V_35 . V_38 = ( int ) ( ( V_17 * 10 ) % ( 1000 * 1000 * 1000 ) ) ;
V_3 -> V_39 = V_19 + V_14 ;
V_3 -> V_40 = V_3 -> V_39 ;
return TRUE ;
}
static T_1
F_8 ( T_8 * V_41 , int * V_5 , T_4 * * V_6 , T_9 * V_42 )
{
* V_42 = F_9 ( V_41 -> V_1 ) ;
return F_1 (
V_41 -> V_1 , & V_41 -> V_3 , V_41 -> V_43 , V_5 , V_6 ) ;
}
static T_1
F_10 ( T_8 * V_41 , T_9 V_44 , struct V_2 * V_45 ,
T_3 * V_4 , int * V_5 , T_4 * * V_6 )
{
if ( - 1 == F_7 ( V_41 -> V_46 , V_44 , V_47 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_41 -> V_46 , V_45 , V_4 , V_5 , V_6 ) ) {
if ( * V_5 == 0 )
* V_5 = V_20 ;
return FALSE ;
}
return TRUE ;
}
T_10 F_11 ( T_8 * V_41 , int * V_5 , T_4 * * V_6 )
{
T_1 V_48 ;
T_5 V_49 [ 6 ] ;
V_48 = F_12 ( V_41 -> V_1 , V_49 , 6 , V_5 , V_6 ) ;
if ( ! V_48 ) {
if ( * V_5 != V_20 )
return V_50 ;
return V_51 ;
}
if ( memcmp ( V_49 , L_1 , 6 ) != 0 )
return V_51 ;
V_41 -> V_52 = V_31 ;
V_41 -> V_53 = 0 ;
V_41 -> V_54 = V_55 ;
V_41 -> V_56 = NULL ;
V_41 -> V_57 = F_8 ;
V_41 -> V_58 = F_10 ;
V_41 -> V_59 = V_60 ;
if ( - 1 == F_7 ( V_41 -> V_1 , 0x80 , V_47 , V_5 ) )
return V_50 ;
* V_5 = 0 ;
return V_61 ;
}
