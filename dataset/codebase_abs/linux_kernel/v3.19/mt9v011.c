static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned char V_4 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
T_1 V_7 ;
int V_8 , V_9 ;
V_8 = F_5 ( V_6 , & V_4 , 1 ) ;
if ( V_8 != 1 )
F_6 ( 0 , V_10 , V_3 ,
L_1 , V_8 ) ;
F_7 ( 10 ) ;
V_8 = F_8 ( V_6 , ( char * ) & V_7 , 2 ) ;
if ( V_8 != 2 )
F_6 ( 0 , V_10 , V_3 ,
L_2 , V_8 ) ;
V_9 = F_9 ( V_7 ) ;
F_6 ( 2 , V_10 , V_3 , L_3 , V_4 , V_9 ) ;
return V_9 ;
}
static void F_10 ( struct V_2 * V_3 , unsigned char V_4 ,
T_2 V_11 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
unsigned char V_7 [ 3 ] ;
int V_8 ;
V_7 [ 0 ] = V_4 ;
V_7 [ 1 ] = V_11 >> 8 ;
V_7 [ 2 ] = V_11 & 0xff ;
F_6 ( 2 , V_10 , V_3 ,
L_4 , V_7 [ 0 ] , V_11 ) ;
V_8 = F_5 ( V_6 , V_7 , 3 ) ;
if ( V_8 != 3 )
F_6 ( 0 , V_10 , V_3 ,
L_5 , V_8 ) ;
}
static T_2 F_11 ( T_3 V_12 )
{
T_2 V_13 = 0 ;
T_2 V_14 = 0 ;
T_2 V_15 = 0 ;
if ( V_12 < 0 )
V_12 = 0 ;
V_12 += 0x0020 ;
if ( V_12 > 2047 )
V_12 = 2047 ;
if ( V_12 > 1023 ) {
V_13 = 3 ;
V_14 = 3 ;
V_15 = V_12 / 16 ;
} else if ( V_12 > 511 ) {
V_13 = 1 ;
V_14 = 3 ;
V_15 = V_12 / 8 ;
} else if ( V_12 > 255 ) {
V_14 = 3 ;
V_15 = V_12 / 4 ;
} else if ( V_12 > 127 ) {
V_14 = 1 ;
V_15 = V_12 / 2 ;
} else
V_15 = V_12 ;
return V_15 + ( V_14 << 7 ) + ( V_13 << 9 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_2 V_17 , V_18 , V_19 ;
T_2 V_20 ;
T_3 V_21 ;
V_20 = V_16 -> V_20 ;
V_17 = F_11 ( V_16 -> V_22 ) ;
V_21 = V_16 -> V_22 ;
V_21 += ( V_16 -> V_23 * V_16 -> V_22 / ( 1 << 7 ) ) ;
V_18 = F_11 ( V_21 ) ;
V_21 = V_16 -> V_22 ;
V_21 += ( V_16 -> V_24 * V_16 -> V_22 / ( 1 << 7 ) ) ;
V_19 = F_11 ( V_21 ) ;
F_10 ( V_3 , V_25 , V_17 ) ;
F_10 ( V_3 , V_26 , V_17 ) ;
F_10 ( V_3 , V_27 , V_18 ) ;
F_10 ( V_3 , V_28 , V_19 ) ;
F_10 ( V_3 , V_29 , V_20 ) ;
}
static void F_13 ( struct V_2 * V_3 , T_4 * V_30 , T_4 * V_31 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_32 , V_33 , V_34 , V_35 , V_36 ;
unsigned V_37 , V_38 ;
T_5 V_39 ;
unsigned V_40 ;
V_32 = F_3 ( V_3 , V_41 ) ;
V_33 = F_3 ( V_3 , V_42 ) ;
V_34 = F_3 ( V_3 , V_43 ) ;
V_35 = F_3 ( V_3 , V_44 ) ;
V_36 = F_3 ( V_3 , V_45 ) ;
V_37 = ( V_33 + 113 + V_34 ) * ( V_36 + 2 ) ;
V_38 = V_37 * ( V_32 + V_35 + 1 ) ;
V_39 = V_16 -> V_46 * 1000l ;
F_14 ( V_39 , V_38 ) ;
V_40 = V_39 ;
F_6 ( 1 , V_10 , V_3 , L_6 ,
V_40 / 1000 , V_40 % 1000 , V_38 ) ;
if ( V_30 && V_31 ) {
* V_30 = 1000 ;
* V_31 = ( T_4 ) V_39 ;
}
}
static T_2 F_15 ( struct V_2 * V_3 , T_4 V_30 , T_4 V_31 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_32 , V_33 , V_34 , V_35 ;
unsigned V_37 , V_47 ;
T_5 V_38 , V_36 ;
if ( ! V_30 || ! V_31 )
return 0 ;
V_32 = F_3 ( V_3 , V_41 ) ;
V_33 = F_3 ( V_3 , V_42 ) ;
V_34 = F_3 ( V_3 , V_43 ) ;
V_35 = F_3 ( V_3 , V_44 ) ;
V_37 = V_33 + 113 + V_34 ;
V_47 = V_32 + V_35 + 1 ;
V_38 = V_16 -> V_46 * ( ( T_5 ) V_30 ) ;
V_38 += V_31 / 2 ;
F_14 ( V_38 , V_31 ) ;
V_36 = V_38 ;
F_14 ( V_36 , V_37 * V_47 ) ;
if ( V_36 < 2 )
V_36 = 0 ;
else
V_36 -= 2 ;
if ( V_36 > 15 )
return 15 ;
return ( T_2 ) V_36 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_48 , V_49 ;
V_49 = 20 + ( 640 - V_16 -> V_33 ) / 2 ;
F_10 ( V_3 , V_50 , V_49 ) ;
F_10 ( V_3 , V_42 , V_16 -> V_33 ) ;
F_10 ( V_3 , V_43 , 771 - V_16 -> V_33 ) ;
V_48 = 8 + ( 480 - V_16 -> V_32 ) / 2 ;
F_10 ( V_3 , V_51 , V_48 ) ;
F_10 ( V_3 , V_41 , V_16 -> V_32 ) ;
F_10 ( V_3 , V_44 , 508 - V_16 -> V_32 ) ;
F_13 ( V_3 , NULL , NULL ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_52 = 0x1000 ;
if ( V_16 -> V_53 )
V_52 |= 0x4000 ;
if ( V_16 -> V_54 )
V_52 |= 0x8000 ;
F_10 ( V_3 , V_55 , V_52 ) ;
}
static int F_18 ( struct V_2 * V_3 , T_4 V_9 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < F_19 ( V_57 ) ; V_56 ++ )
F_10 ( V_3 , V_57 [ V_56 ] . V_58 ,
V_57 [ V_56 ] . V_11 ) ;
F_12 ( V_3 ) ;
F_16 ( V_3 ) ;
F_17 ( V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , unsigned V_59 ,
T_4 * V_60 )
{
if ( V_59 > 0 )
return - V_61 ;
* V_60 = V_62 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_63 * V_64 )
{
if ( V_64 -> V_60 != V_62 )
return - V_61 ;
F_22 ( & V_64 -> V_33 , 48 , 639 , 1 ,
& V_64 -> V_32 , 32 , 480 , 1 , 0 ) ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_69 * V_70 )
{
struct V_71 * V_72 = & V_70 -> V_73 . V_74 ;
if ( V_70 -> type != V_75 )
return - V_61 ;
memset ( V_72 , 0 , sizeof( struct V_71 ) ) ;
V_72 -> V_76 = V_77 ;
F_13 ( V_3 ,
& V_72 -> V_78 . V_30 ,
& V_72 -> V_78 . V_31 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_69 * V_70 )
{
struct V_71 * V_72 = & V_70 -> V_73 . V_74 ;
struct V_79 * V_80 = & V_72 -> V_78 ;
T_2 V_36 ;
if ( V_70 -> type != V_75 )
return - V_61 ;
if ( V_72 -> V_81 != 0 )
return - V_61 ;
V_36 = F_15 ( V_3 , V_80 -> V_30 , V_80 -> V_31 ) ;
F_10 ( V_3 , V_45 , V_36 ) ;
F_6 ( 1 , V_10 , V_3 , L_7 , V_36 ) ;
F_13 ( V_3 , & V_80 -> V_30 , & V_80 -> V_31 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_63 * V_64 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_8 ;
V_8 = F_21 ( V_3 , V_64 ) ;
if ( V_8 < 0 )
return - V_61 ;
V_16 -> V_33 = V_64 -> V_33 ;
V_16 -> V_32 = V_64 -> V_32 ;
F_16 ( V_3 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_82 * V_58 )
{
V_58 -> V_9 = F_3 ( V_3 , V_58 -> V_58 & 0xff ) ;
V_58 -> V_83 = 2 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
const struct V_82 * V_58 )
{
F_10 ( V_3 , V_58 -> V_58 & 0xff , V_58 -> V_9 & 0xffff ) ;
return 0 ;
}
static int F_28 ( struct V_84 * V_85 )
{
struct V_1 * V_16 =
F_2 ( V_85 -> V_86 , struct V_1 , V_87 ) ;
struct V_2 * V_3 = & V_16 -> V_3 ;
switch ( V_85 -> V_88 ) {
case V_89 :
V_16 -> V_22 = V_85 -> V_9 ;
break;
case V_90 :
V_16 -> V_20 = V_85 -> V_9 ;
break;
case V_91 :
V_16 -> V_24 = V_85 -> V_9 ;
break;
case V_92 :
V_16 -> V_23 = V_85 -> V_9 ;
break;
case V_93 :
V_16 -> V_53 = V_85 -> V_9 ;
F_17 ( V_3 ) ;
return 0 ;
case V_94 :
V_16 -> V_54 = V_85 -> V_9 ;
F_17 ( V_3 ) ;
return 0 ;
default:
return - V_61 ;
}
F_12 ( V_3 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 ,
const struct V_95 * V_88 )
{
T_2 V_96 ;
struct V_1 * V_16 ;
struct V_2 * V_3 ;
if ( ! F_30 ( V_6 -> V_97 ,
V_98 | V_99 ) )
return - V_100 ;
V_16 = F_31 ( & V_6 -> V_101 , sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_16 )
return - V_103 ;
V_3 = & V_16 -> V_3 ;
F_32 ( V_3 , V_6 , & V_104 ) ;
V_96 = F_3 ( V_3 , V_105 ) ;
if ( ( V_96 != V_106 ) &&
( V_96 != V_107 ) ) {
F_33 ( V_3 , L_8 ,
V_96 ) ;
return - V_61 ;
}
F_34 ( & V_16 -> V_87 , 5 ) ;
F_35 ( & V_16 -> V_87 , & V_108 ,
V_89 , 0 , ( 1 << 12 ) - 1 - 0x20 , 1 , 0x20 ) ;
F_35 ( & V_16 -> V_87 , & V_108 ,
V_90 , 0 , 2047 , 1 , 0x01fc ) ;
F_35 ( & V_16 -> V_87 , & V_108 ,
V_91 , - ( 1 << 9 ) , ( 1 << 9 ) - 1 , 1 , 0 ) ;
F_35 ( & V_16 -> V_87 , & V_108 ,
V_92 , - ( 1 << 9 ) , ( 1 << 9 ) - 1 , 1 , 0 ) ;
F_35 ( & V_16 -> V_87 , & V_108 ,
V_93 , 0 , 1 , 1 , 0 ) ;
F_35 ( & V_16 -> V_87 , & V_108 ,
V_94 , 0 , 1 , 1 , 0 ) ;
if ( V_16 -> V_87 . error ) {
int V_109 = V_16 -> V_87 . error ;
F_36 ( V_3 , L_9 , V_109 ) ;
F_37 ( & V_16 -> V_87 ) ;
return V_109 ;
}
V_16 -> V_3 . V_110 = & V_16 -> V_87 ;
V_16 -> V_22 = 0x0024 ;
V_16 -> V_20 = 0x01fc ;
V_16 -> V_33 = 640 ;
V_16 -> V_32 = 480 ;
V_16 -> V_46 = 27000000 ;
if ( V_6 -> V_101 . V_111 ) {
struct V_112 * V_113 = V_6 -> V_101 . V_111 ;
V_16 -> V_46 = V_113 -> V_46 ;
F_6 ( 1 , V_10 , V_3 , L_10 ,
V_16 -> V_46 / 1000000 , ( V_16 -> V_46 / 1000 ) % 1000 ) ;
}
F_38 ( V_6 , L_11 ,
V_6 -> V_4 << 1 , V_6 -> V_97 -> V_114 , V_96 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_40 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_6 ( 1 , V_10 , V_3 ,
L_12 ,
V_6 -> V_4 << 1 ) ;
F_41 ( V_3 ) ;
F_37 ( & V_16 -> V_87 ) ;
return 0 ;
}
