static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
T_2 V_14 , V_15 , V_16 ;
T_1 V_17 ;
struct {
T_1 V_17 ;
T_2 V_18 ;
} V_19 , V_20 , V_21 ;
T_1 V_22 , V_23 , V_24 ;
T_1 V_25 , V_26 , V_27 ;
int V_28 ;
V_19 . V_17 = F_2 ( V_5 , V_3 / 1000 , & V_14 , & V_19 . V_18 ,
& V_15 , & V_20 . V_18 ) ;
if ( ! V_19 . V_17 || V_14 != 0x10 || V_19 . V_18 < 0x0e ) {
F_3 ( V_2 , L_1 ) ;
return - V_29 ;
}
if ( V_12 ( V_5 , 'M' , & V_13 ) || V_13 . V_30 != 2 || V_13 . V_31 < 3 ) {
F_3 ( V_2 , L_2 ) ;
return - V_29 ;
}
V_16 = ( F_4 ( V_2 , 0x101000 ) & 0x0000003c ) >> 2 ;
V_17 = F_5 ( V_5 , V_13 . V_32 + 1 ) ;
if ( V_17 )
V_16 = F_6 ( V_5 , V_17 + V_16 ) ;
if ( V_16 >= V_15 ) {
F_3 ( V_2 , L_3 ) ;
return - V_29 ;
}
V_20 . V_17 = V_19 . V_17 + V_19 . V_18 + ( V_16 * V_20 . V_18 ) ;
if ( ! V_20 . V_17 || V_14 != 0x10 || V_20 . V_18 < 0x0e ) {
F_3 ( V_2 , L_4 ) ;
return - V_29 ;
}
V_16 = F_6 ( V_5 , V_20 . V_17 + 0x01 ) ;
if ( V_16 != 0xff ) {
V_21 . V_17 = F_7 ( V_5 , V_16 , & V_14 ,
& V_21 . V_18 ) ;
if ( ! V_21 . V_17 || V_14 != 0x10 || V_21 . V_18 < 0x19 ) {
F_3 ( V_2 , L_5 ) ;
return - V_29 ;
}
} else {
V_21 . V_17 = 0 ;
}
V_28 = V_10 ( F_8 ( V_2 ) , 0x12 , 0x4000 , V_3 , & V_11 ) ;
if ( V_28 < 0 ) {
F_3 ( V_2 , L_6 ) ;
return V_28 ;
}
V_28 = F_9 ( V_9 , V_2 ) ;
if ( V_28 )
return V_28 ;
if ( V_3 <= 750000 ) {
V_22 = 0x10000000 ;
V_23 = 0x22222222 ;
} else {
V_22 = 0x00000000 ;
V_23 = 0x00000000 ;
}
V_24 = F_10 ( V_9 , 0x004000 ) ;
if ( V_24 & 0x00000008 ) {
if ( V_11 . V_33 ) {
F_11 ( V_9 , 0x004128 , 0x00000101 , 0x00000101 ) ;
F_12 ( V_9 , 0x004004 , V_11 . V_33 ) ;
F_12 ( V_9 , 0x004000 , ( V_24 |= 0x00000001 ) ) ;
F_12 ( V_9 , 0x004000 , ( V_24 &= 0xffffffef ) ) ;
F_13 ( V_9 , 0x004000 , 0x00020000 , 0x00020000 , 64000 ) ;
F_12 ( V_9 , 0x004000 , ( V_24 |= 0x00000010 ) ) ;
F_12 ( V_9 , 0x004018 , 0x00005000 | V_22 ) ;
F_12 ( V_9 , 0x004000 , ( V_24 |= 0x00000004 ) ) ;
}
} else {
T_1 V_34 = 0x00000101 ;
if ( V_11 . V_35 )
V_34 |= V_11 . V_35 ;
else
V_34 |= 0x00080000 ;
F_11 ( V_9 , 0x004168 , 0x003f3141 , V_24 ) ;
}
if ( ( F_6 ( V_5 , V_20 . V_17 + 0x02 ) & 0x10 ) ) {
F_11 ( V_9 , 0x111104 , 0x00000600 , 0x00000000 ) ;
} else {
F_11 ( V_9 , 0x111100 , 0x40000000 , 0x40000000 ) ;
F_11 ( V_9 , 0x111104 , 0x00000180 , 0x00000000 ) ;
}
if ( ! ( F_6 ( V_5 , V_19 . V_17 + 0x04 ) & 0x02 ) )
F_11 ( V_9 , 0x100200 , 0x00000800 , 0x00000000 ) ;
F_12 ( V_9 , 0x611200 , 0x00003300 ) ;
if ( ! ( F_6 ( V_5 , V_20 . V_17 + 0x02 ) & 0x10 ) )
F_12 ( V_9 , 0x111100 , 0x4c020000 ) ;
F_12 ( V_9 , 0x1002d4 , 0x00000001 ) ;
F_12 ( V_9 , 0x1002d0 , 0x00000001 ) ;
F_12 ( V_9 , 0x1002d0 , 0x00000001 ) ;
F_12 ( V_9 , 0x100210 , 0x00000000 ) ;
F_12 ( V_9 , 0x1002dc , 0x00000001 ) ;
F_14 ( V_9 , 2000 ) ;
V_24 = F_10 ( V_9 , 0x004000 ) ;
if ( ! ( V_24 & 0x00000008 ) && V_11 . V_33 ) {
F_12 ( V_9 , 0x004000 , ( V_24 |= 0x00000008 ) ) ;
F_11 ( V_9 , 0x1110e0 , 0x00088000 , 0x00088000 ) ;
F_12 ( V_9 , 0x004018 , 0x00001000 ) ;
F_12 ( V_9 , 0x004000 , ( V_24 &= ~ 0x00000001 ) ) ;
F_12 ( V_9 , 0x004004 , V_11 . V_33 ) ;
F_12 ( V_9 , 0x004000 , ( V_24 |= 0x00000001 ) ) ;
F_15 ( 64 ) ;
F_12 ( V_9 , 0x004018 , 0x00005000 | V_22 ) ;
F_15 ( 20 ) ;
} else
if ( ! V_11 . V_33 ) {
F_11 ( V_9 , 0x004168 , 0x003f3040 , V_11 . V_35 ) ;
F_12 ( V_9 , 0x004000 , ( V_24 |= 0x00000008 ) ) ;
F_11 ( V_9 , 0x1110e0 , 0x00088000 , 0x00088000 ) ;
F_12 ( V_9 , 0x004018 , 0x0000d000 | V_22 ) ;
}
if ( ( F_6 ( V_5 , V_19 . V_17 + 0x04 ) & 0x08 ) ) {
T_1 V_36 = ( F_5 ( V_5 , V_20 . V_17 + 0x05 ) << 8 ) |
F_6 ( V_5 , V_20 . V_17 + 0x05 ) ;
T_1 V_37 = ( F_5 ( V_5 , V_20 . V_17 + 0x07 ) ) ;
T_1 V_38 = ( F_6 ( V_5 , V_20 . V_17 + 0x09 ) & 0xf0 ) << 16 |
( F_6 ( V_5 , V_20 . V_17 + 0x03 ) & 0x0f ) << 16 |
( F_6 ( V_5 , V_20 . V_17 + 0x09 ) & 0x0f ) |
0x80000000 ;
F_12 ( V_9 , 0x1005a0 , V_36 ) ;
F_12 ( V_9 , 0x1005a4 , V_37 ) ;
F_12 ( V_9 , 0x10f804 , V_38 ) ;
F_11 ( V_9 , 0x10053c , 0x00001000 , 0x00000000 ) ;
} else {
F_11 ( V_9 , 0x10053c , 0x00001000 , 0x00001000 ) ;
F_11 ( V_9 , 0x10f804 , 0x80000000 , 0x00000000 ) ;
F_11 ( V_9 , 0x100760 , 0x22222222 , V_23 ) ;
F_11 ( V_9 , 0x1007a0 , 0x22222222 , V_23 ) ;
F_11 ( V_9 , 0x1007e0 , 0x22222222 , V_23 ) ;
}
if ( V_11 . V_33 ) {
F_11 ( V_9 , 0x1110e0 , 0x00088000 , 0x00011000 ) ;
F_12 ( V_9 , 0x004000 , ( V_24 &= ~ 0x00000008 ) ) ;
}
F_12 ( V_9 , 0x1002dc , 0x00000000 ) ;
F_12 ( V_9 , 0x1002d4 , 0x00000001 ) ;
F_12 ( V_9 , 0x100210 , 0x80000000 ) ;
F_14 ( V_9 , 1000 ) ;
F_14 ( V_9 , 1000 ) ;
F_11 ( V_9 , V_39 [ 2 ] , 0x00000000 , 0x00000000 ) ;
F_14 ( V_9 , 1000 ) ;
F_16 ( V_9 , V_39 [ 0 ] ) ;
F_11 ( V_9 , V_39 [ 0 ] , 0x00000000 , 0x00000000 ) ;
F_14 ( V_9 , 1000 ) ;
F_11 ( V_9 , 0x100220 [ 3 ] , 0x00000000 , 0x00000000 ) ;
F_11 ( V_9 , 0x100220 [ 1 ] , 0x00000000 , 0x00000000 ) ;
F_11 ( V_9 , 0x100220 [ 6 ] , 0x00000000 , 0x00000000 ) ;
F_11 ( V_9 , 0x100220 [ 7 ] , 0x00000000 , 0x00000000 ) ;
F_11 ( V_9 , 0x100220 [ 2 ] , 0x00000000 , 0x00000000 ) ;
F_11 ( V_9 , 0x100220 [ 4 ] , 0x00000000 , 0x00000000 ) ;
F_11 ( V_9 , 0x100220 [ 5 ] , 0x00000000 , 0x00000000 ) ;
F_11 ( V_9 , 0x100220 [ 0 ] , 0x00000000 , 0x00000000 ) ;
F_11 ( V_9 , 0x100220 [ 8 ] , 0x00000000 , 0x00000000 ) ;
V_17 = ( F_6 ( V_5 , V_20 . V_17 + 0x02 ) & 0x08 ) ? 0x00000000 : 0x00001000 ;
F_11 ( V_9 , 0x100200 , 0x00001000 , V_17 ) ;
V_25 = F_10 ( V_9 , 0x100714 ) & ~ 0xf0000010 ;
V_26 = F_10 ( V_9 , 0x100718 ) & ~ 0x00000100 ;
V_27 = F_10 ( V_9 , 0x10071c ) & ~ 0x00000100 ;
if ( ( F_6 ( V_5 , V_20 . V_17 + 0x02 ) & 0x20 ) )
V_25 |= 0xf0000000 ;
if ( ! ( F_6 ( V_5 , V_20 . V_17 + 0x02 ) & 0x04 ) )
V_25 |= 0x00000010 ;
F_12 ( V_9 , 0x100714 , V_25 ) ;
if ( F_6 ( V_5 , V_20 . V_17 + 0x02 ) & 0x01 )
V_27 |= 0x00000100 ;
F_12 ( V_9 , 0x10071c , V_27 ) ;
if ( F_6 ( V_5 , V_20 . V_17 + 0x02 ) & 0x02 )
V_26 |= 0x00000100 ;
F_12 ( V_9 , 0x100718 , V_26 ) ;
if ( F_6 ( V_5 , V_20 . V_17 + 0x02 ) & 0x10 )
F_12 ( V_9 , 0x111100 , 0x48000000 ) ;
F_11 ( V_9 , V_39 [ 0 ] , 0x100 , 0x100 ) ;
F_14 ( V_9 , 1000 ) ;
F_11 ( V_9 , V_39 [ 0 ] , 0x100 , 0x000 ) ;
F_14 ( V_9 , 1000 ) ;
F_14 ( V_9 , 2000 ) ;
F_14 ( V_9 , 12000 ) ;
F_12 ( V_9 , 0x611200 , 0x00003330 ) ;
if ( ( F_6 ( V_5 , V_19 . V_17 + 0x04 ) & 0x02 ) )
F_11 ( V_9 , 0x100200 , 0x00000800 , 0x00000800 ) ;
if ( ( F_6 ( V_5 , V_20 . V_17 + 0x02 ) & 0x10 ) ) {
F_11 ( V_9 , 0x111104 , 0x00000180 , 0x00000180 ) ;
F_11 ( V_9 , 0x111100 , 0x40000000 , 0x00000000 ) ;
} else {
F_11 ( V_9 , 0x111104 , 0x00000600 , 0x00000600 ) ;
}
if ( V_11 . V_33 ) {
F_11 ( V_9 , 0x004168 , 0x00000001 , 0x00000000 ) ;
F_11 ( V_9 , 0x004168 , 0x00000100 , 0x00000000 ) ;
} else {
F_11 ( V_9 , 0x004000 , 0x00000001 , 0x00000000 ) ;
F_11 ( V_9 , 0x004128 , 0x00000001 , 0x00000000 ) ;
F_11 ( V_9 , 0x004128 , 0x00000100 , 0x00000000 ) ;
}
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_18 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 ;
F_19 ( V_9 , F_20 ( V_41 -> V_42 , L_7 , false ) ) ;
return 0 ;
}
static void
F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = ( void * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 ;
F_19 ( V_9 , false ) ;
}
static int
F_22 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = ( void * ) V_44 -> V_45 ;
struct V_6 * V_7 = ( void * ) V_44 ;
int V_28 , V_46 ;
V_28 = F_23 ( & V_7 -> V_47 ) ;
if ( V_28 )
return V_28 ;
switch ( V_7 -> V_47 . type ) {
case V_48 : {
static const T_1 V_49 [ 16 ] = {
0xaaaaaaaa , 0xcccccccc , 0xdddddddd , 0xeeeeeeee ,
0x00000000 , 0x11111111 , 0x44444444 , 0xdddddddd ,
0x33333333 , 0x55555555 , 0x77777777 , 0x66666666 ,
0x99999999 , 0x88888888 , 0xeeeeeeee , 0xbbbbbbbb ,
} ;
F_24 ( V_2 , 0x100538 , 0x10001ff6 ) ;
F_24 ( V_2 , 0x1005a8 , 0x0000ffff ) ;
F_25 ( V_2 , 0x10f800 , 0x00000001 , 0x00000001 ) ;
for ( V_46 = 0 ; V_46 < 0x30 ; V_46 ++ ) {
F_24 ( V_2 , 0x10f8c0 , ( V_46 << 8 ) | V_46 ) ;
F_24 ( V_2 , 0x10f8e0 , ( V_46 << 8 ) | V_46 ) ;
F_24 ( V_2 , 0x10f900 , V_49 [ V_46 % 16 ] ) ;
F_24 ( V_2 , 0x10f920 , V_49 [ V_46 % 16 ] ) ;
}
}
break;
default:
break;
}
return 0 ;
}
static int
F_26 ( struct V_43 * V_45 , struct V_43 * V_50 ,
struct V_51 * V_52 , void * V_17 , T_1 V_53 ,
struct V_43 * * V_54 )
{
struct V_6 * V_7 ;
int V_28 , V_46 ;
V_28 = F_27 ( V_45 , V_50 , V_52 , & V_7 ) ;
* V_54 = F_28 ( V_7 ) ;
if ( V_28 )
return V_28 ;
switch ( V_7 -> V_47 . type ) {
case V_48 :
V_7 -> V_47 . V_55 = F_1 ;
V_7 -> V_47 . V_56 = F_17 ;
V_7 -> V_47 . V_57 = F_21 ;
break;
default:
F_29 ( V_7 , L_8 ) ;
return 0 ;
}
V_7 -> V_9 . V_58 = F_30 ( 0x004000 ) ;
V_7 -> V_9 . V_59 = F_30 ( 0x004004 ) ;
V_7 -> V_9 . V_60 = F_30 ( 0x004018 ) ;
V_7 -> V_9 . V_61 = F_30 ( 0x004128 ) ;
V_7 -> V_9 . V_62 = F_30 ( 0x004168 ) ;
V_7 -> V_9 . V_63 = F_30 ( 0x100200 ) ;
V_7 -> V_9 . V_64 = F_30 ( 0x100210 ) ;
for ( V_46 = 0 ; V_46 < 9 ; V_46 ++ )
V_7 -> V_9 . V_65 [ V_46 ] = F_30 ( 0x100220 + ( V_46 * 4 ) ) ;
V_7 -> V_9 . V_66 = F_30 ( 0x1002d0 ) ;
V_7 -> V_9 . V_67 = F_30 ( 0x1002d4 ) ;
V_7 -> V_9 . V_68 = F_30 ( 0x1002dc ) ;
V_7 -> V_9 . V_69 = F_30 ( 0x10053c ) ;
V_7 -> V_9 . V_70 = F_30 ( 0x1005a0 ) ;
V_7 -> V_9 . V_71 = F_30 ( 0x1005a4 ) ;
V_7 -> V_9 . V_72 = F_30 ( 0x100714 ) ;
V_7 -> V_9 . V_73 = F_30 ( 0x100718 ) ;
V_7 -> V_9 . V_74 = F_30 ( 0x10071c ) ;
V_7 -> V_9 . V_75 = F_30 ( 0x100760 ) ;
V_7 -> V_9 . V_76 = F_30 ( 0x1007a0 ) ;
V_7 -> V_9 . V_77 = F_30 ( 0x1007e0 ) ;
V_7 -> V_9 . V_78 = F_30 ( 0x10f804 ) ;
V_7 -> V_9 . V_79 = F_30 ( 0x1110e0 ) ;
V_7 -> V_9 . V_80 = F_30 ( 0x111100 ) ;
V_7 -> V_9 . V_81 = F_30 ( 0x111104 ) ;
V_7 -> V_9 . V_82 = F_30 ( 0x611200 ) ;
if ( V_7 -> V_47 . V_83 > 1 ) {
V_7 -> V_9 . V_84 [ 0 ] = F_31 ( 0x1002c0 , 0x1002c8 ) ;
V_7 -> V_9 . V_84 [ 1 ] = F_31 ( 0x1002c4 , 0x1002cc ) ;
V_7 -> V_9 . V_84 [ 2 ] = F_31 ( 0x1002e0 , 0x1002e8 ) ;
V_7 -> V_9 . V_84 [ 3 ] = F_31 ( 0x1002e4 , 0x1002ec ) ;
} else {
V_7 -> V_9 . V_84 [ 0 ] = F_30 ( 0x1002c0 ) ;
V_7 -> V_9 . V_84 [ 1 ] = F_30 ( 0x1002c4 ) ;
V_7 -> V_9 . V_84 [ 2 ] = F_30 ( 0x1002e0 ) ;
V_7 -> V_9 . V_84 [ 3 ] = F_30 ( 0x1002e4 ) ;
}
return 0 ;
}
