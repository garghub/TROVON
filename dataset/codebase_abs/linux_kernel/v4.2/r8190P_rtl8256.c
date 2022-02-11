void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_7 -> V_8 ; V_5 ++ ) {
if ( ! F_3 ( V_2 , V_5 ) )
continue;
switch ( V_4 ) {
case V_9 :
if ( V_7 -> V_10 == V_11 ||
V_7 -> V_10 == V_12 ) {
F_4 ( V_2 ,
(enum V_13 ) V_5 ,
0x0b , V_14 , 0x100 ) ;
F_4 ( V_2 ,
(enum V_13 ) V_5 ,
0x2c , V_14 , 0x3d7 ) ;
F_4 ( V_2 ,
(enum V_13 ) V_5 ,
0x0e , V_14 , 0x021 ) ;
} else {
F_5 ( V_2 , L_1 ,
V_15 ) ;
}
break;
case V_16 :
if ( V_7 -> V_10 == V_11 ||
V_7 -> V_10 == V_12 ) {
F_4 ( V_2 ,
(enum V_13 ) V_5 ,
0x0b , V_14 , 0x300 ) ;
F_4 ( V_2 ,
(enum V_13 ) V_5 ,
0x2c , V_14 , 0x3ff ) ;
F_4 ( V_2 ,
(enum V_13 ) V_5 ,
0x0e , V_14 , 0x0e1 ) ;
} else {
F_5 ( V_2 , L_1 ,
V_15 ) ;
}
break;
default:
F_6 ( V_2 , L_2 ,
V_15 , V_4 ) ;
break;
}
}
}
bool F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_8 = V_17 ;
return F_8 ( V_2 ) ;
}
bool F_8 ( struct V_1 * V_2 )
{
T_2 V_18 = 0 ;
T_1 V_5 ;
bool V_19 = true ;
struct V_20 * V_21 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_22 = 0x3 ;
T_2 V_23 = 0x7f1 ;
T_2 V_24 = 0 ;
T_1 V_25 = 5 , V_26 = 5 ;
T_1 V_27 = 0 ;
for ( V_5 = (enum V_13 ) V_28 ;
V_5 < V_7 -> V_8 ; V_5 ++ ) {
if ( ! F_3 ( V_2 , V_5 ) )
continue;
V_21 = & V_7 -> V_29 [ V_5 ] ;
switch ( V_5 ) {
case V_28 :
case V_30 :
V_18 = F_9 ( V_2 , V_21 -> V_31 ,
V_32 ) ;
break;
case V_33 :
case V_34 :
V_18 = F_9 ( V_2 , V_21 -> V_31 ,
V_32 << 16 ) ;
break;
}
F_10 ( V_2 , V_21 -> V_35 , V_32 << 16 , 0x1 ) ;
F_10 ( V_2 , V_21 -> V_36 , V_32 , 0x1 ) ;
F_10 ( V_2 , V_21 -> V_37 ,
V_38 , 0x0 ) ;
F_10 ( V_2 , V_21 -> V_37 ,
V_39 , 0x0 ) ;
F_4 ( V_2 , (enum V_13 ) V_5 , 0x0 ,
V_14 , 0xbf ) ;
V_19 = F_11 ( V_2 , V_40 ,
(enum V_13 ) V_5 ) ;
if ( ! V_19 ) {
F_6 ( V_2 , L_3 ,
V_15 , V_5 ) ;
goto V_41;
}
V_26 = V_25 ;
V_24 = 0 ;
switch ( V_5 ) {
case V_28 :
while ( V_24 != V_23 &&
V_26 != 0 ) {
V_27 = F_12 ( V_2 ,
(enum V_13 ) V_5 ) ;
V_24 = F_13 ( V_2 ,
(enum V_13 ) V_5 ,
V_22 ,
V_14 ) ;
F_14 ( V_42 ,
L_4 ,
V_5 , V_22 ,
V_24 ) ;
V_26 -- ;
}
break;
case V_33 :
while ( V_24 != V_23 &&
V_26 != 0 ) {
V_27 = F_12 ( V_2 ,
(enum V_13 ) V_5 ) ;
V_24 = F_13 ( V_2 ,
(enum V_13 ) V_5 ,
V_22 ,
V_14 ) ;
F_14 ( V_42 ,
L_4 ,
V_5 , V_22 ,
V_24 ) ;
V_26 -- ;
}
break;
case V_30 :
while ( V_24 != V_23 &&
V_26 != 0 ) {
V_27 = F_12 ( V_2 ,
(enum V_13 ) V_5 ) ;
V_24 = F_13 ( V_2 ,
(enum V_13 ) V_5 ,
V_22 ,
V_14 ) ;
F_14 ( V_42 ,
L_4 ,
V_5 , V_22 ,
V_24 ) ;
V_26 -- ;
}
break;
case V_34 :
while ( V_24 != V_23 &&
V_26 != 0 ) {
V_27 = F_12 ( V_2 ,
(enum V_13 ) V_5 ) ;
V_24 = F_13 ( V_2 ,
(enum V_13 ) V_5 ,
V_22 , V_14 ) ;
F_14 ( V_42 ,
L_4 ,
V_5 , V_22 ,
V_24 ) ;
V_26 -- ;
}
break;
}
switch ( V_5 ) {
case V_28 :
case V_30 :
F_10 ( V_2 , V_21 -> V_31 , V_32 ,
V_18 ) ;
break;
case V_33 :
case V_34 :
F_10 ( V_2 , V_21 -> V_31 , V_32 << 16 ,
V_18 ) ;
break;
}
if ( V_27 ) {
F_6 ( V_2 ,
L_5 ,
V_15 , V_5 ) ;
goto V_41;
}
}
F_14 ( V_43 , L_6 ) ;
return true ;
V_41:
return false ;
}
void F_15 ( struct V_1 * V_2 , T_1 V_44 )
{
T_2 V_45 = 0 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_45 = V_44 ;
if ( V_7 -> V_46 ) {
if ( V_7 -> V_47 == V_48 )
V_45 = 0x22 ;
else
V_45 += V_7 -> V_49 ;
}
if ( V_45 > 0x24 )
V_45 = 0x24 ;
F_10 ( V_2 , V_50 , V_51 , V_45 ) ;
}
void F_16 ( struct V_1 * V_2 , T_1 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_52 , V_53 , V_54 , V_55 ;
T_1 V_56 = 0 ;
T_3 V_57 [ 6 ] = { 0xe00 , 0xe04 , 0xe10 , 0xe14 , 0xe18 , 0xe1c } ;
T_1 V_58 , V_59 , V_60 , V_61 ;
V_53 = V_44 + V_7 -> V_62 ;
V_53 = ( V_53 << 24 ) | ( V_53 << 16 ) |
( V_53 << 8 ) | V_53 ;
V_54 = V_44 ;
V_54 = ( V_54 << 24 ) | ( V_54 << 16 ) |
( V_54 << 8 ) | V_54 ;
for ( V_56 = 0 ; V_56 < 6 ; V_56 ++ ) {
V_52 = ( T_2 ) ( V_7 -> V_63 [ V_56 ] +
( ( V_56 < 2 ) ? V_53 : V_54 ) ) ;
V_58 = ( T_1 ) ( V_52 & 0x7f ) ;
V_59 = ( T_1 ) ( ( V_52 & 0x7f00 ) >> 8 ) ;
V_60 = ( T_1 ) ( ( V_52 & 0x7f0000 ) >> 16 ) ;
V_61 = ( T_1 ) ( ( V_52 & 0x7f000000 ) >> 24 ) ;
if ( V_58 > 0x24 )
V_58 = 0x24 ;
if ( V_59 > 0x24 )
V_59 = 0x24 ;
if ( V_60 > 0x24 )
V_60 = 0x24 ;
if ( V_61 > 0x24 )
V_61 = 0x24 ;
if ( V_56 == 3 ) {
V_55 = ( V_61 << 24 ) | ( V_60 << 16 ) |
( V_59 << 8 ) | V_58 ;
V_7 -> V_64 = V_55 ;
}
if ( V_7 -> V_65 )
V_52 = 0x03030303 ;
else
V_52 = ( V_61 << 24 ) | ( V_60 << 16 ) |
( V_59 << 8 ) | V_58 ;
F_10 ( V_2 , V_57 [ V_56 ] , 0x7f7f7f7f , V_52 ) ;
}
}
