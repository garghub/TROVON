int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
T_1 V_5 = 0 ;
T_2 V_6 = 0 ;
T_2 V_7 = 0 ;
T_2 V_8 = 0 ;
int V_9 = V_10 ;
switch ( V_2 -> V_11 ) {
case 0xbece3200 :
switch ( V_2 -> V_12 ) {
case V_13 :
V_4 = V_14 ;
V_5 = ( sizeof( V_14 ) /
sizeof( struct V_3 ) ) ;
break;
case V_15 :
V_4 = V_16 ;
V_5 = ( sizeof( V_16 ) /
sizeof( struct V_3 ) ) ;
break;
case V_17 :
V_4 = V_18 ;
V_5 = ( sizeof( V_18 ) /
sizeof( struct V_3 ) ) ;
if ( V_2 -> V_19 == V_20 )
V_8 = 0x03F13652 ;
else
V_8 = 0x03F1365B ;
break;
default:
return - V_21 ;
}
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
if ( ( V_2 -> V_11 != V_23 ) &&
( V_2 -> V_11 != V_24 ) &&
( V_2 -> V_11 != V_26 ) ) {
V_9 = F_2 ( V_2 , ( T_2 ) 0x0f000830 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_7 |= 0x44 ;
V_9 = F_4 ( V_2 , ( T_2 ) 0x0f000830 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
}
switch ( V_2 -> V_12 ) {
case V_13 :
V_4 = V_31 ;
V_5 = ( sizeof( V_32 ) /
sizeof( struct V_3 ) ) ;
break;
case V_15 :
V_4 = V_33 ;
V_5 = ( sizeof( V_34 ) /
sizeof( struct V_3 ) ) ;
break;
case V_17 :
V_4 = V_35 ;
V_5 = ( sizeof( V_36 ) /
sizeof( struct V_3 ) ) ;
if ( V_2 -> V_19 == V_20 )
V_8 = 0x03F13652 ;
else
V_8 = 0x03F1365B ;
break;
case V_37 :
V_4 = V_38 ;
V_5 = sizeof( V_38 ) / sizeof( struct V_3 ) ;
if ( V_2 -> V_19 == V_20 )
V_8 = 0x03F137D2 ;
else
V_8 = 0x03F137DB ;
}
break;
case 0xbece0110 :
case 0xbece0120 :
case 0xbece0121 :
case 0xbece0130 :
case 0xbece0300 :
F_3 ( V_2 , V_39 , V_40 , V_29 , L_2 , V_2 -> V_12 ) ;
switch ( V_2 -> V_12 ) {
case V_13 :
V_4 = V_41 ;
V_5 = ( sizeof( V_41 ) /
sizeof( struct V_3 ) ) ;
break;
case V_15 :
V_4 = V_42 ;
V_5 = ( sizeof( V_42 ) /
sizeof( struct V_3 ) ) ;
break;
case V_17 :
V_4 = V_43 ;
V_5 = ( sizeof( V_43 ) /
sizeof( struct V_3 ) ) ;
break;
default:
return - V_21 ;
}
case 0xbece0310 :
{
switch ( V_2 -> V_12 ) {
case V_13 :
V_4 = V_32 ;
V_5 = ( sizeof( V_32 ) /
sizeof( struct V_3 ) ) ;
break;
case V_15 :
V_4 = V_34 ;
V_5 = ( sizeof( V_34 ) /
sizeof( struct V_3 ) ) ;
break;
case V_17 :
if ( V_2 -> V_44 == V_45 ) {
memcpy ( V_36 , V_46 ,
sizeof( V_46 ) ) ;
V_4 = V_36 ;
V_5 = ( sizeof( V_36 ) /
sizeof( struct V_3 ) ) ;
} else {
V_4 = V_36 ;
V_5 = ( sizeof( V_36 ) /
sizeof( struct V_3 ) ) ;
if ( V_2 -> V_19 == V_20 )
V_8 = 0x07F13652 ;
else
V_8 = 0x07F1365B ;
}
break;
default:
return - V_21 ;
}
break;
}
default:
return - V_21 ;
}
V_6 = 0 ;
F_3 ( V_2 , V_39 , V_40 , V_29 , L_3 , V_5 ) ;
while ( V_5 && ! V_9 ) {
if ( V_8 && V_4 -> V_47 == V_48 )
V_6 = V_8 ;
else
V_6 = V_4 -> V_49 ;
V_9 = F_4 ( V_2 , V_4 -> V_47 , & V_6 , sizeof( V_6 ) ) ;
if ( V_10 != V_9 ) {
F_3 ( V_2 , V_50 , 0 , 0 , L_4 , V_30 , __LINE__ ) ;
break;
}
V_5 -- ;
V_4 ++ ;
}
if ( V_2 -> V_11 >= 0xbece3300 ) {
F_5 ( 3 ) ;
if ( ( V_2 -> V_11 != V_23 ) &&
( V_2 -> V_11 != V_24 ) &&
( V_2 -> V_11 != V_26 ) ) {
V_7 = 0x01010001 ;
V_9 = F_4 ( V_2 , ( T_2 ) 0x0F007018 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_7 = 0x00040020 ;
V_9 = F_4 ( V_2 , ( T_2 ) 0x0F007094 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_7 = 0x01020101 ;
V_9 = F_4 ( V_2 , ( T_2 ) 0x0F00701c , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_7 = 0x01010000 ;
V_9 = F_4 ( V_2 , ( T_2 ) 0x0F007018 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
}
F_5 ( 3 ) ;
if ( V_2 -> V_51 == V_52 ) {
V_9 = F_2 ( V_2 , ( T_2 ) 0x0f000c00 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_9 = F_2 ( V_2 , ( T_2 ) 0x0f000c00 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_7 = 0x1322a8 ;
V_9 = F_4 ( V_2 , ( T_2 ) 0x0f000d1c , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_9 = F_2 ( V_2 , ( T_2 ) 0x0f000c00 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_50 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_9 = F_2 ( V_2 , ( T_2 ) 0x0f000c00 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_7 = 0x132296 ;
V_9 = F_4 ( V_2 , ( T_2 ) 0x0f000d14 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
} else if ( V_2 -> V_51 == V_53 ) {
V_9 = F_2 ( V_2 , ( T_2 ) 0x0f000c00 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_9 = F_2 ( V_2 , ( T_2 ) 0x0f000c00 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_7 = 0x6003229a ;
V_9 = F_4 ( V_2 , ( T_2 ) 0x0f000d14 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_9 = F_2 ( V_2 , ( T_2 ) 0x0f000c00 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_9 = F_2 ( V_2 , ( T_2 ) 0x0f000c00 , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_7 = 0x1322a8 ;
V_9 = F_4 ( V_2 , ( T_2 ) 0x0f000d1c , & V_7 , sizeof( V_7 ) ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , V_27 , V_28 , V_29 , L_1 , V_30 , __LINE__ ) ;
return V_9 ;
}
}
}
V_2 -> V_54 = TRUE ;
return V_9 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
T_1 V_5 = 0 ;
unsigned long V_55 = V_56 ;
T_2 V_6 = 0 ;
int V_9 = V_10 ;
bool V_57 = false ;
switch ( V_2 -> V_11 ) {
case 0xbece3200 :
switch ( V_2 -> V_12 ) {
case V_13 :
V_4 = V_14 ;
V_5 = F_7 ( V_14 ) ;
V_5 -= V_58 ;
V_4 += V_58 ;
break;
case V_15 :
V_4 = V_16 ;
V_5 = F_7 ( V_16 ) ;
V_5 -= V_59 ;
V_4 += V_59 ;
break;
case V_17 :
V_57 = TRUE ;
V_4 = V_18 ;
V_5 = F_7 ( V_18 ) ;
V_5 -= V_60 ;
V_4 += V_60 ;
break;
default:
return - V_21 ;
}
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
switch ( V_2 -> V_12 ) {
case V_13 :
V_4 = V_31 ;
V_5 = F_7 ( V_31 ) ;
V_5 -= V_61 ;
V_4 += V_61 ;
break;
case V_15 :
V_4 = V_33 ;
V_5 = F_7 ( V_33 ) ;
V_5 -= V_62 ;
V_4 += V_62 ;
break;
case V_17 :
V_57 = TRUE ;
V_4 = V_35 ;
V_5 = F_7 ( V_35 ) ;
V_5 -= V_63 ;
V_4 += V_63 ;
break;
case V_37 :
V_57 = TRUE ;
V_4 = V_38 ;
V_5 = F_7 ( V_38 ) ;
V_5 -= V_64 ;
V_4 += V_64 ;
break;
default:
return - V_21 ;
}
break;
case 0xbece0300 :
switch ( V_2 -> V_12 ) {
case V_13 :
V_4 = V_41 ;
V_5 = F_7 ( V_41 ) ;
V_5 -= V_65 ;
V_4 += V_65 ;
break;
case V_15 :
V_4 = V_42 ;
V_5 = F_7 ( V_42 ) ;
V_5 -= V_66 ;
V_4 += V_66 ;
break;
case V_17 :
V_4 = V_43 ;
V_5 = F_7 ( V_43 ) ;
V_5 -= V_67 ;
V_4 += V_67 ;
break;
default:
return - V_21 ;
}
break;
case 0xbece0310 :
{
switch ( V_2 -> V_12 ) {
case V_13 :
V_4 = V_32 ;
V_5 = F_7 ( V_32 ) ;
V_5 -= V_68 ;
V_4 += V_68 ;
break;
case V_15 :
V_4 = V_34 ;
V_5 = F_7 ( V_34 ) ;
V_5 -= V_69 ;
V_4 += V_69 ;
break;
case V_17 :
V_57 = TRUE ;
V_4 = V_36 ;
V_5 = F_7 ( V_36 ) ;
V_5 -= V_70 ;
V_4 += V_70 ;
break;
}
break;
}
default:
return - V_21 ;
}
V_6 = V_5 ;
V_9 = F_4 ( V_2 , V_55 , & V_6 , sizeof( V_6 ) ) ;
if ( V_9 ) {
F_3 ( V_2 , V_50 , 0 , 0 , L_4 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_55 += sizeof( T_1 ) ;
V_6 = ( 0x1d1e0dd0 ) ;
V_9 = F_4 ( V_2 , V_55 , & V_6 , sizeof( V_6 ) ) ;
if ( V_9 ) {
F_3 ( V_2 , V_50 , 0 , 0 , L_4 , V_30 , __LINE__ ) ;
return V_9 ;
}
V_55 += sizeof( T_1 ) ;
V_5 *= ( sizeof( struct V_3 ) / sizeof( T_1 ) ) ;
while ( V_5 && ! V_9 ) {
V_6 = V_4 -> V_47 ;
V_9 = F_4 ( V_2 , V_55 , & V_6 , sizeof( V_6 ) ) ;
V_55 += sizeof( T_1 ) ;
if ( ! V_9 ) {
if ( V_57 && ( V_4 -> V_47 == 0x0F007018 ) ) {
V_6 = ( V_4 -> V_49 | ( 1 << 8 ) ) ;
if ( V_10 != F_4 ( V_2 , V_55 ,
& V_6 , sizeof( V_6 ) ) ) {
F_3 ( V_2 , V_50 , 0 , 0 , L_4 , V_30 , __LINE__ ) ;
break;
}
} else {
V_6 = V_4 -> V_49 ;
if ( V_10 != F_4 ( V_2 , V_55 ,
& V_6 , sizeof( V_6 ) ) ) {
F_3 ( V_2 , V_50 , 0 , 0 , L_4 , V_30 , __LINE__ ) ;
break;
}
}
}
V_55 += sizeof( T_1 ) ;
V_5 -- ;
V_4 ++ ;
}
return V_9 ;
}
