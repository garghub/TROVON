int F_1 ( T_1 * V_1 )
{
T_2 V_2 = NULL ;
T_3 V_3 = 0 ;
T_4 V_4 = 0 ;
T_4 V_5 = 0 ;
T_4 V_6 = 0 ;
int V_7 = V_8 ;
switch ( V_1 -> V_9 )
{
case 0xbece3200 :
switch ( V_1 -> V_10 )
{
case V_11 :
V_2 = V_12 ;
V_3 = ( sizeof( V_12 ) /
sizeof( V_13 ) ) ;
break;
case V_14 :
V_2 = V_15 ;
V_3 = ( sizeof( V_15 ) /
sizeof( V_13 ) ) ;
break;
case V_16 :
V_2 = V_17 ;
V_3 = ( sizeof( V_17 ) /
sizeof( V_13 ) ) ;
if( V_1 -> V_18 == V_19 )
{
V_6 = 0x03F13652 ;
}
else
{
V_6 = 0x03F1365B ;
}
break;
default:
return - V_20 ;
}
break;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
if( ( V_1 -> V_9 != V_22 ) &&
( V_1 -> V_9 != V_23 ) &&
( V_1 -> V_9 != V_25 ) )
{
V_7 = F_2 ( V_1 , ( T_4 ) 0x0f000830 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_5 |= 0x44 ;
V_7 = F_4 ( V_1 , ( T_4 ) 0x0f000830 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_30 , V_28 , L_2 , V_29 , __LINE__ ) ;
return V_7 ;
}
}
switch( V_1 -> V_10 )
{
case V_11 :
V_2 = V_31 ;
V_3 = ( sizeof( V_32 ) /
sizeof( V_13 ) ) ;
break;
case V_14 :
V_2 = V_33 ;
V_3 = ( sizeof( V_34 ) /
sizeof( V_13 ) ) ;
break;
case V_16 :
V_2 = V_35 ;
V_3 = ( sizeof( V_36 ) /
sizeof( V_13 ) ) ;
if( V_1 -> V_18 == V_19 )
{
V_6 = 0x03F13652 ;
}
else
{
V_6 = 0x03F1365B ;
}
break;
case V_37 :
V_2 = V_38 ;
V_3 = sizeof( V_38 ) / sizeof( V_13 ) ;
if( V_1 -> V_18 == V_19 )
{
V_6 = 0x03F137D2 ;
}
else
{
V_6 = 0x03F137DB ;
}
}
break;
case 0xbece0110 :
case 0xbece0120 :
case 0xbece0121 :
case 0xbece0130 :
case 0xbece0300 :
F_3 ( V_1 , V_39 , V_40 , V_28 , L_3 , V_1 -> V_10 ) ;
switch ( V_1 -> V_10 )
{
case V_11 :
V_2 = V_41 ;
V_3 = ( sizeof( V_41 ) /
sizeof( V_13 ) ) ;
break;
case V_14 :
V_2 = V_42 ;
V_3 = ( sizeof( V_42 ) /
sizeof( V_13 ) ) ;
break;
case V_16 :
V_2 = V_43 ;
V_3 = ( sizeof( V_43 ) /
sizeof( V_13 ) ) ;
break;
default:
return - V_20 ;
}
case 0xbece0310 :
{
switch ( V_1 -> V_10 )
{
case V_11 :
V_2 = V_32 ;
V_3 = ( sizeof( V_32 ) /
sizeof( V_13 ) ) ;
break;
case V_14 :
V_2 = V_34 ;
V_3 = ( sizeof( V_34 ) /
sizeof( V_13 ) ) ;
break;
case V_16 :
if( V_1 -> V_44 == V_45 )
{
memcpy ( V_36 , V_46 ,
sizeof( V_46 ) ) ;
V_2 = V_36 ;
V_3 = ( sizeof( V_36 ) /
sizeof( V_13 ) ) ;
}
else
{
V_2 = V_36 ;
V_3 = ( sizeof( V_36 ) /
sizeof( V_13 ) ) ;
if( V_1 -> V_18 == V_19 )
{
V_6 = 0x07F13652 ;
}
else
{
V_6 = 0x07F1365B ;
}
}
break;
default:
return - V_20 ;
}
break;
}
default:
return - V_20 ;
}
V_4 = 0 ;
F_3 ( V_1 , V_39 , V_40 , V_28 , L_4 , V_3 ) ;
while( V_3 && ! V_7 )
{
if( V_6 && V_2 -> V_47 == V_48 )
{
V_4 = V_6 ;
}
else
{
V_4 = V_2 -> V_49 ;
}
V_7 = F_4 ( V_1 , V_2 -> V_47 , & V_4 , sizeof( V_4 ) ) ;
if( V_8 != V_7 ) {
F_3 ( V_1 , V_50 , 0 , 0 , L_5 , V_29 , __LINE__ ) ;
break;
}
V_3 -- ;
V_2 ++ ;
}
if( V_1 -> V_9 >= 0xbece3300 )
{
F_5 ( 3 ) ;
if( ( V_1 -> V_9 != V_22 ) &&
( V_1 -> V_9 != V_23 ) &&
( V_1 -> V_9 != V_25 ) )
{
V_5 = 0x01010001 ;
V_7 = F_4 ( V_1 , ( T_4 ) 0x0F007018 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_5 = 0x00040020 ;
V_7 = F_4 ( V_1 , ( T_4 ) 0x0F007094 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_5 = 0x01020101 ;
V_7 = F_4 ( V_1 , ( T_4 ) 0x0F00701c , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_5 = 0x01010000 ;
V_7 = F_4 ( V_1 , ( T_4 ) 0x0F007018 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
}
F_5 ( 3 ) ;
if( V_1 -> V_51 == V_52 )
{
V_7 = F_2 ( V_1 , ( T_4 ) 0x0f000c00 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_7 = F_2 ( V_1 , ( T_4 ) 0x0f000c00 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_5 = 0x1322a8 ;
V_7 = F_4 ( V_1 , ( T_4 ) 0x0f000d1c , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_7 = F_2 ( V_1 , ( T_4 ) 0x0f000c00 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_50 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_7 = F_2 ( V_1 , ( T_4 ) 0x0f000c00 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_5 = 0x132296 ;
V_7 = F_4 ( V_1 , ( T_4 ) 0x0f000d14 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
}
else if( V_1 -> V_51 == V_53 )
{
V_7 = F_2 ( V_1 , ( T_4 ) 0x0f000c00 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_7 = F_2 ( V_1 , ( T_4 ) 0x0f000c00 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_5 = 0x6003229a ;
V_7 = F_4 ( V_1 , ( T_4 ) 0x0f000d14 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_7 = F_2 ( V_1 , ( T_4 ) 0x0f000c00 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_7 = F_2 ( V_1 , ( T_4 ) 0x0f000c00 , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_5 = 0x1322a8 ;
V_7 = F_4 ( V_1 , ( T_4 ) 0x0f000d1c , & V_5 , sizeof( V_5 ) ) ;
if( V_7 < 0 ) {
F_3 ( V_1 , V_26 , V_27 , V_28 , L_1 , V_29 , __LINE__ ) ;
return V_7 ;
}
}
}
V_1 -> V_54 = TRUE ;
return V_7 ;
}
int F_6 ( T_5 V_1 )
{
T_6 V_2 = NULL ;
T_3 V_3 = 0 ;
unsigned long V_55 = V_56 ;
T_4 V_4 = 0 ;
int V_7 = V_8 ;
BOOLEAN V_57 = FALSE ;
switch ( V_1 -> V_9 )
{
case 0xbece3200 :
switch ( V_1 -> V_10 )
{
case V_11 :
V_2 = V_12 ;
V_3 = F_7 ( V_12 ) ;
V_3 -= V_58 ;
V_2 += V_58 ;
break;
case V_14 :
V_2 = V_15 ;
V_3 = F_7 ( V_15 ) ;
V_3 -= V_59 ;
V_2 += V_59 ;
break;
case V_16 :
V_57 = TRUE ;
V_2 = V_17 ;
V_3 = F_7 ( V_17 ) ;
V_3 -= V_60 ;
V_2 += V_60 ;
break;
default:
return - V_20 ;
}
break;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
switch ( V_1 -> V_10 )
{
case V_11 :
V_2 = V_31 ;
V_3 = F_7 ( V_31 ) ;
V_3 -= V_61 ;
V_2 += V_61 ;
break;
case V_14 :
V_2 = V_33 ;
V_3 = F_7 ( V_33 ) ;
V_3 -= V_62 ;
V_2 += V_62 ;
break;
case V_16 :
V_57 = TRUE ;
V_2 = V_35 ;
V_3 = F_7 ( V_35 ) ;
V_3 -= V_63 ;
V_2 += V_63 ;
break;
case V_37 :
V_57 = TRUE ;
V_2 = V_38 ;
V_3 = F_7 ( V_38 ) ;
V_3 -= V_64 ;
V_2 += V_64 ;
break;
default:
return - V_20 ;
}
break;
case 0xbece0300 :
switch ( V_1 -> V_10 )
{
case V_11 :
V_2 = V_41 ;
V_3 = F_7 ( V_41 ) ;
V_3 -= V_65 ;
V_2 += V_65 ;
break;
case V_14 :
V_2 = V_42 ;
V_3 = F_7 ( V_42 ) ;
V_3 -= V_66 ;
V_2 += V_66 ;
break;
case V_16 :
V_2 = V_43 ;
V_3 = F_7 ( V_43 ) ;
V_3 -= V_67 ;
V_2 += V_67 ;
break;
default:
return - V_20 ;
}
break;
case 0xbece0310 :
{
switch ( V_1 -> V_10 )
{
case V_11 :
V_2 = V_32 ;
V_3 = F_7 ( V_32 ) ;
V_3 -= V_68 ;
V_2 += V_68 ;
break;
case V_14 :
V_2 = V_34 ;
V_3 = F_7 ( V_34 ) ;
V_3 -= V_69 ;
V_2 += V_69 ;
break;
case V_16 :
V_57 = TRUE ;
V_2 = V_36 ;
V_3 = F_7 ( V_36 ) ;
V_3 -= V_70 ;
V_2 += V_70 ;
break;
}
break;
}
default:
return - V_20 ;
}
V_4 = V_3 ;
V_7 = F_4 ( V_1 , V_55 , & V_4 , sizeof( V_4 ) ) ;
if( V_7 )
{
F_3 ( V_1 , V_50 , 0 , 0 , L_5 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_55 += sizeof( T_3 ) ;
V_4 = ( 0x1d1e0dd0 ) ;
V_7 = F_4 ( V_1 , V_55 , & V_4 , sizeof( V_4 ) ) ;
if( V_7 )
{
F_3 ( V_1 , V_50 , 0 , 0 , L_5 , V_29 , __LINE__ ) ;
return V_7 ;
}
V_55 += sizeof( T_3 ) ;
V_3 *= ( sizeof( V_13 ) / sizeof( T_3 ) ) ;
while( V_3 && ! V_7 )
{
V_4 = V_2 -> V_47 ;
V_7 = F_4 ( V_1 , V_55 , & V_4 , sizeof( V_4 ) ) ;
V_55 += sizeof( T_3 ) ;
if( ! V_7 )
{
if( V_57 && ( V_2 -> V_47 == 0x0F007018 ) )
{
V_4 = ( V_2 -> V_49 | ( 1 << 8 ) ) ;
if( V_8 != F_4 ( V_1 , V_55 ,
& V_4 , sizeof( V_4 ) ) ) {
F_3 ( V_1 , V_50 , 0 , 0 , L_5 , V_29 , __LINE__ ) ;
break;
}
}
else
{
V_4 = V_2 -> V_49 ;
if( V_8 != F_4 ( V_1 , V_55 ,
& V_4 , sizeof( V_4 ) ) ) {
F_3 ( V_1 , V_50 , 0 , 0 , L_5 , V_29 , __LINE__ ) ;
break;
}
}
}
V_55 += sizeof( T_3 ) ;
V_3 -- ;
V_2 ++ ;
}
return V_7 ;
}
