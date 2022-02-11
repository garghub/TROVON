static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_4 = V_5 ;
F_2 ( 1 , V_6 ) ;
V_3 = F_3 ( V_7 ) ;
F_2 ( V_3 | 1 << 5 , V_7 ) ;
F_4 ( 300 ) ;
F_5 ( V_4 , V_8 ) ;
F_6 ( V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_8 ( V_2 ) ;
F_1 ( V_2 ) ;
F_9 ( V_2 , & V_10 -> V_12 ) ;
F_10 ( V_2 , & V_10 -> V_12 ) ;
if ( F_6 ( V_13 ) & V_14 )
F_11 ( V_2 , & V_10 -> V_12 , V_13 ) ;
if ( F_6 ( V_15 ) & V_14 )
F_11 ( V_2 , & V_10 -> V_12 , V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_6 ( V_16 ) & V_17 ;
}
static T_2 F_13 ( struct V_1 * V_2 )
{
T_2 V_18 = F_6 ( V_19 ) ;
if ( V_18 == 0 ) {
F_14 ( L_1 ) ;
return 1 ;
}
V_18 >>= 16 ;
if ( F_12 ( V_2 ) )
V_18 *= 0xff ;
return V_18 ;
}
static int F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
T_2 V_22 = F_6 ( V_19 ) & V_23 ;
if ( F_12 ( V_2 ) ) {
T_1 V_24 ;
V_22 &= ~ 1 ;
F_17 ( V_2 -> V_25 , 0xF4 , & V_24 ) ;
V_22 *= V_24 ;
}
return ( V_22 * 100 ) / F_13 ( V_2 ) ;
}
static int F_18 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
int V_26 = V_21 -> V_27 . V_28 ;
T_2 V_29 ;
if ( V_26 < 1 )
V_26 = 1 ;
V_26 *= F_13 ( V_2 ) ;
V_26 /= 100 ;
if ( F_12 ( V_2 ) ) {
T_2 V_18 = F_13 ( V_2 ) ;
T_1 V_24 ;
V_24 = V_26 * 0xfe / V_18 + 1 ;
V_26 /= V_24 ;
F_19 ( V_2 -> V_25 , 0xF4 , V_24 ) ;
}
V_29 = F_6 ( V_19 ) & ~ V_23 ;
F_5 ( V_19 , ( V_29 |
( V_26 << V_30 ) ) ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_31 V_27 ;
memset ( & V_27 , 0 , sizeof( struct V_31 ) ) ;
V_27 . V_32 = 100 ;
V_27 . type = V_33 ;
V_34 = F_21 ( L_2 ,
NULL , ( void * ) V_2 , & V_35 , & V_27 ) ;
if ( F_22 ( V_34 ) )
return F_23 ( V_34 ) ;
V_34 -> V_27 . V_28 =
F_15 ( V_34 ) ;
F_24 ( V_34 ) ;
V_10 -> V_20 = V_34 ;
return 0 ;
}
static inline T_2 F_25 ( T_3 V_36 , T_3 V_37 )
{
int V_38 = ( 0x10 << 24 ) | ( V_36 << 16 ) | ( V_37 << 8 ) ;
T_4 V_39 = 0 ;
struct V_40 * V_41 = F_26 ( 0 , 0 ) ;
F_27 ( V_41 , 0xD0 , V_38 ) ;
F_28 ( V_41 , 0xD4 , & V_39 ) ;
F_29 ( V_41 ) ;
return V_39 ;
}
static inline void F_30 ( T_3 V_36 , T_3 V_37 , T_2 V_42 )
{
int V_38 = ( 0x11 << 24 ) | ( V_36 << 16 ) | ( V_37 << 8 ) | 0xF0 ;
struct V_40 * V_41 = F_26 ( 0 , 0 ) ;
F_27 ( V_41 , 0xD4 , V_42 ) ;
F_27 ( V_41 , 0xD0 , V_38 ) ;
F_29 ( V_41 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_43 ;
int V_44 ;
V_10 -> V_45 = F_25 ( V_46 ,
V_47 ) & 0xFFFF ;
V_10 -> V_48 = F_25 ( V_46 ,
V_49 ) & 0xFFFF ;
V_43 = F_32 ( V_10 -> V_45 + V_50 ) ;
V_43 &= ~ V_51 ;
V_43 |= V_52 ;
F_33 ( V_43 , V_10 -> V_45 + V_50 ) ;
for ( V_44 = 0 ; V_44 < 5 ; V_44 ++ ) {
T_2 V_53 = F_32 ( V_10 -> V_45 + V_54 ) ;
if ( ( V_53 & V_51 ) == 0 )
return;
F_4 ( 10 ) ;
}
F_34 ( V_2 -> V_2 , L_3 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_30 ( 3 , 0x30 , 0x08027108 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_55 * V_56 = & V_10 -> V_56 ;
struct V_57 * V_58 ;
F_37 ( V_2 -> V_2 , L_4 ) ;
F_17 ( V_2 -> V_25 , 0xF4 , & V_56 -> V_59 . V_60 ) ;
V_56 -> V_59 . V_61 = F_6 ( V_62 ) ;
V_56 -> V_59 . V_63 = F_6 ( V_64 ) ;
V_56 -> V_59 . V_65 = F_6 ( V_66 ) ;
V_56 -> V_59 . V_67 [ 0 ] = F_6 ( V_68 ) ;
V_56 -> V_59 . V_67 [ 1 ] = F_6 ( V_69 ) ;
V_56 -> V_59 . V_67 [ 2 ] = F_6 ( V_70 ) ;
V_56 -> V_59 . V_67 [ 3 ] = F_6 ( V_71 ) ;
V_56 -> V_59 . V_67 [ 4 ] = F_6 ( V_72 ) ;
V_56 -> V_59 . V_67 [ 5 ] = F_6 ( V_73 ) ;
V_56 -> V_59 . V_74 = F_6 ( V_75 ) ;
V_56 -> V_59 . V_76 = F_6 ( V_77 ) ;
V_56 -> V_59 . V_78 = F_6 ( V_79 ) ;
V_56 -> V_80 = F_6 ( V_19 ) ;
V_56 -> V_81 = F_6 ( V_16 ) ;
V_56 -> V_59 . V_82 = F_6 ( V_83 ) ;
V_56 -> V_59 . V_84 = F_6 ( V_85 ) ;
V_56 -> V_59 . V_86 = F_6 ( V_87 ) ;
V_56 -> V_59 . V_88 = F_6 ( V_89 ) ;
V_56 -> V_59 . V_90 = F_6 ( V_91 ) ;
V_56 -> V_59 . V_92 = F_6 ( V_5 ) ;
V_56 -> V_59 . V_93 = F_6 ( V_94 ) ;
V_56 -> V_59 . V_95 = F_6 ( V_96 ) ;
F_38 (connector, &dev->mode_config.connector_list, head)
V_58 -> V_97 -> V_98 ( V_58 , V_99 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_55 * V_56 = & V_10 -> V_56 ;
struct V_57 * V_58 ;
T_2 V_100 ;
F_19 ( V_2 -> V_25 , 0xF4 , V_56 -> V_59 . V_60 ) ;
F_5 ( V_62 , V_56 -> V_59 . V_61 ) ;
F_5 ( V_64 , V_56 -> V_59 . V_63 ) ;
F_5 ( V_101 , 0 ) ;
F_5 ( V_101 , V_102 | V_103 ) ;
V_100 = F_6 ( V_104 ) ;
if ( ( V_100 & V_105 ) == 0 ) {
F_5 ( V_104 , V_100 | V_105 ) ;
F_6 ( V_104 ) ;
}
V_100 = F_6 ( V_106 ) ;
if ( ( V_100 & V_105 ) == 0 ) {
F_5 ( V_106 , V_100 | V_105 ) ;
F_6 ( V_106 ) ;
}
F_4 ( 500 ) ;
F_5 ( V_68 , V_56 -> V_59 . V_67 [ 0 ] ) ;
F_5 ( V_69 , V_56 -> V_59 . V_67 [ 1 ] ) ;
F_5 ( V_70 , V_56 -> V_59 . V_67 [ 2 ] ) ;
F_5 ( V_71 , V_56 -> V_59 . V_67 [ 3 ] ) ;
F_5 ( V_72 , V_56 -> V_59 . V_67 [ 4 ] ) ;
F_5 ( V_73 , V_56 -> V_59 . V_67 [ 5 ] ) ;
F_5 ( V_66 , V_56 -> V_59 . V_65 ) ;
F_5 ( V_75 , V_56 -> V_59 . V_74 ) ;
F_5 ( V_16 , V_56 -> V_81 ) ;
F_5 ( V_83 , V_56 -> V_59 . V_82 ) ;
F_5 ( V_85 , V_56 -> V_59 . V_84 ) ;
F_5 ( V_79 , V_56 -> V_59 . V_78 ) ;
F_5 ( V_19 , V_56 -> V_80 ) ;
F_5 ( V_87 , V_56 -> V_59 . V_86 ) ;
F_5 ( V_89 , V_56 -> V_59 . V_88 ) ;
F_5 ( V_91 , V_56 -> V_59 . V_90 ) ;
F_5 ( V_77 , V_56 -> V_59 . V_76 ) ;
F_5 ( V_5 , V_56 -> V_59 . V_92 ) ;
F_5 ( V_94 , V_56 -> V_59 . V_93 ) ;
F_5 ( V_96 , V_56 -> V_59 . V_95 ) ;
F_35 ( V_2 ) ;
F_40 ( V_2 ) ;
F_38 (connector, &dev->mode_config.connector_list, head)
V_58 -> V_97 -> V_98 ( V_58 , V_107 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_43 , V_108 , V_53 ;
int V_109 = 5 ;
V_43 = F_32 ( V_10 -> V_45 + V_50 ) ;
V_43 &= ~ V_51 ;
V_43 |= V_110 ;
V_108 = V_51 ;
F_33 ( V_43 , V_10 -> V_45 + V_50 ) ;
while ( V_109 -- ) {
V_53 = F_32 ( V_10 -> V_45 + V_54 ) ;
if ( ( V_53 & V_108 ) == V_111 )
return 0 ;
F_4 ( 10 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_43 , V_108 , V_53 ;
int V_109 = 5 ;
V_43 = F_32 ( V_10 -> V_45 + V_50 ) ;
V_43 &= ~ V_51 ;
V_43 |= V_52 ;
V_108 = V_51 ;
F_33 ( V_43 , V_10 -> V_45 + V_50 ) ;
while ( V_109 -- ) {
V_53 = F_32 ( V_10 -> V_45 + V_54 ) ;
if ( ( V_53 & V_108 ) == V_112 )
return 0 ;
F_4 ( 10 ) ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
T_4 clock ;
struct V_40 * V_41 = F_26 ( 0 , 0 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_27 ( V_41 , 0xD0 , 0xD0050300 ) ;
F_28 ( V_41 , 0xD4 , & clock ) ;
F_29 ( V_41 ) ;
switch ( clock & 0x07 ) {
case 0 :
V_10 -> V_113 = 100 ;
break;
case 1 :
V_10 -> V_113 = 133 ;
break;
case 2 :
V_10 -> V_113 = 150 ;
break;
case 3 :
V_10 -> V_113 = 178 ;
break;
case 4 :
V_10 -> V_113 = 200 ;
break;
case 5 :
case 6 :
case 7 :
V_10 -> V_113 = 266 ;
default:
V_10 -> V_113 = 0 ;
}
}
static void F_45 ( struct V_114 * V_115 )
{
struct V_9 * V_10 = F_46 ( V_115 , struct V_9 ,
V_116 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_47 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_49 ( & V_10 -> V_116 ) ;
F_5 ( V_117 , F_6 ( V_117 ) ) ;
return 1 ;
}
static void F_50 ( struct V_1 * V_2 , bool V_118 )
{
if ( V_118 ) {
T_2 V_119 = F_6 ( V_120 ) ;
V_119 |= V_121 | V_122 |
V_123 | V_124 ;
F_5 ( V_120 , V_119 ) ;
} else {
F_5 ( V_120 , 0 ) ;
F_5 ( V_117 , F_6 ( V_117 ) ) ;
}
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_52 ( & V_10 -> V_116 , F_45 ) ;
if ( F_53 ( V_2 -> V_25 ) )
F_54 ( V_2 -> V_2 , L_5 ) ;
V_10 -> V_125 = V_126 ;
F_44 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_50 ( V_2 , false ) ;
return 0 ;
}
