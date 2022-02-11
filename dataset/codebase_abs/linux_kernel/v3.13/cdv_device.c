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
if ( F_6 ( V_13 ) & V_14 ) {
F_11 ( V_2 , & V_10 -> V_12 , V_13 ) ;
if ( F_6 ( V_15 ) & V_16 )
F_12 ( V_2 , & V_10 -> V_12 , V_15 ) ;
}
if ( F_6 ( V_17 ) & V_14 ) {
F_11 ( V_2 , & V_10 -> V_12 , V_17 ) ;
if ( F_6 ( V_18 ) & V_16 )
F_12 ( V_2 , & V_10 -> V_12 , V_18 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_6 ( V_19 ) & V_20 ;
}
static T_2 F_14 ( struct V_1 * V_2 )
{
T_2 V_21 = F_6 ( V_22 ) ;
if ( V_21 == 0 ) {
F_15 ( L_1 ) ;
return 1 ;
}
V_21 >>= 16 ;
if ( F_13 ( V_2 ) )
V_21 *= 0xff ;
return V_21 ;
}
static int F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_17 ( V_24 ) ;
T_2 V_25 = F_6 ( V_22 ) & V_26 ;
if ( F_13 ( V_2 ) ) {
T_1 V_27 ;
V_25 &= ~ 1 ;
F_18 ( V_2 -> V_28 , 0xF4 , & V_27 ) ;
V_25 *= V_27 ;
}
return ( V_25 * 100 ) / F_14 ( V_2 ) ;
}
static int F_19 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_17 ( V_24 ) ;
int V_29 = V_24 -> V_30 . V_31 ;
T_2 V_32 ;
if ( V_29 < 1 )
V_29 = 1 ;
V_29 *= F_14 ( V_2 ) ;
V_29 /= 100 ;
if ( F_13 ( V_2 ) ) {
T_2 V_21 = F_14 ( V_2 ) ;
T_1 V_27 ;
V_27 = V_29 * 0xfe / V_21 + 1 ;
V_29 /= V_27 ;
F_20 ( V_2 -> V_28 , 0xF4 , V_27 ) ;
}
V_32 = F_6 ( V_22 ) & ~ V_26 ;
F_5 ( V_22 , ( V_32 |
( V_29 << V_33 ) ) ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_34 V_30 ;
memset ( & V_30 , 0 , sizeof( struct V_34 ) ) ;
V_30 . V_35 = 100 ;
V_30 . type = V_36 ;
V_37 = F_22 ( L_2 ,
NULL , ( void * ) V_2 , & V_38 , & V_30 ) ;
if ( F_23 ( V_37 ) )
return F_24 ( V_37 ) ;
V_37 -> V_30 . V_31 =
F_16 ( V_37 ) ;
F_25 ( V_37 ) ;
V_10 -> V_23 = V_37 ;
V_10 -> V_39 = true ;
return 0 ;
}
static inline T_2 F_26 ( T_3 V_40 , T_3 V_41 )
{
int V_42 = ( 0x10 << 24 ) | ( V_40 << 16 ) | ( V_41 << 8 ) ;
T_4 V_43 = 0 ;
struct V_44 * V_45 = F_27 ( 0 , 0 ) ;
F_28 ( V_45 , 0xD0 , V_42 ) ;
F_29 ( V_45 , 0xD4 , & V_43 ) ;
F_30 ( V_45 ) ;
return V_43 ;
}
static inline void F_31 ( T_3 V_40 , T_3 V_41 , T_2 V_46 )
{
int V_42 = ( 0x11 << 24 ) | ( V_40 << 16 ) | ( V_41 << 8 ) | 0xF0 ;
struct V_44 * V_45 = F_27 ( 0 , 0 ) ;
F_28 ( V_45 , 0xD4 , V_46 ) ;
F_28 ( V_45 , 0xD0 , V_42 ) ;
F_30 ( V_45 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_47 ;
int V_48 ;
V_10 -> V_49 = F_26 ( V_50 ,
V_51 ) & 0xFFFF ;
V_10 -> V_52 = F_26 ( V_50 ,
V_53 ) & 0xFFFF ;
V_47 = F_33 ( V_10 -> V_49 + V_54 ) ;
V_47 &= ~ V_55 ;
V_47 |= V_56 ;
F_34 ( V_47 , V_10 -> V_49 + V_54 ) ;
for ( V_48 = 0 ; V_48 < 5 ; V_48 ++ ) {
T_2 V_57 = F_33 ( V_10 -> V_49 + V_58 ) ;
if ( ( V_57 & V_55 ) == 0 )
return;
F_4 ( 10 ) ;
}
F_35 ( V_2 -> V_2 , L_3 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_31 ( 3 , 0x30 , 0x08027108 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_59 * V_60 = & V_10 -> V_60 ;
struct V_61 * V_62 ;
F_38 ( V_2 -> V_2 , L_4 ) ;
F_18 ( V_2 -> V_28 , 0xF4 , & V_60 -> V_63 . V_64 ) ;
V_60 -> V_63 . V_65 = F_6 ( V_66 ) ;
V_60 -> V_63 . V_67 = F_6 ( V_68 ) ;
V_60 -> V_63 . V_69 = F_6 ( V_70 ) ;
V_60 -> V_63 . V_71 [ 0 ] = F_6 ( V_72 ) ;
V_60 -> V_63 . V_71 [ 1 ] = F_6 ( V_73 ) ;
V_60 -> V_63 . V_71 [ 2 ] = F_6 ( V_74 ) ;
V_60 -> V_63 . V_71 [ 3 ] = F_6 ( V_75 ) ;
V_60 -> V_63 . V_71 [ 4 ] = F_6 ( V_76 ) ;
V_60 -> V_63 . V_71 [ 5 ] = F_6 ( V_77 ) ;
V_60 -> V_63 . V_78 = F_6 ( V_79 ) ;
V_60 -> V_63 . V_80 = F_6 ( V_81 ) ;
V_60 -> V_63 . V_82 = F_6 ( V_83 ) ;
V_60 -> V_84 = F_6 ( V_22 ) ;
V_60 -> V_85 = F_6 ( V_19 ) ;
V_60 -> V_63 . V_86 = F_6 ( V_87 ) ;
V_60 -> V_63 . V_88 = F_6 ( V_89 ) ;
V_60 -> V_63 . V_90 = F_6 ( V_91 ) ;
V_60 -> V_63 . V_92 = F_6 ( V_93 ) ;
V_60 -> V_63 . V_94 = F_6 ( V_95 ) ;
V_60 -> V_63 . V_96 = F_6 ( V_5 ) ;
V_60 -> V_63 . V_97 = F_6 ( V_98 ) ;
V_60 -> V_63 . V_99 = F_6 ( V_100 ) ;
F_39 (connector, &dev->mode_config.connector_list, head)
V_62 -> V_101 -> V_102 ( V_62 , V_103 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_59 * V_60 = & V_10 -> V_60 ;
struct V_61 * V_62 ;
T_2 V_104 ;
F_20 ( V_2 -> V_28 , 0xF4 , V_60 -> V_63 . V_64 ) ;
F_5 ( V_66 , V_60 -> V_63 . V_65 ) ;
F_5 ( V_68 , V_60 -> V_63 . V_67 ) ;
F_5 ( V_105 , 0 ) ;
F_5 ( V_105 , V_106 | V_107 ) ;
V_104 = F_6 ( V_108 ) ;
if ( ( V_104 & V_109 ) == 0 ) {
F_5 ( V_108 , V_104 | V_109 ) ;
F_6 ( V_108 ) ;
}
V_104 = F_6 ( V_110 ) ;
if ( ( V_104 & V_109 ) == 0 ) {
F_5 ( V_110 , V_104 | V_109 ) ;
F_6 ( V_110 ) ;
}
F_4 ( 500 ) ;
F_5 ( V_72 , V_60 -> V_63 . V_71 [ 0 ] ) ;
F_5 ( V_73 , V_60 -> V_63 . V_71 [ 1 ] ) ;
F_5 ( V_74 , V_60 -> V_63 . V_71 [ 2 ] ) ;
F_5 ( V_75 , V_60 -> V_63 . V_71 [ 3 ] ) ;
F_5 ( V_76 , V_60 -> V_63 . V_71 [ 4 ] ) ;
F_5 ( V_77 , V_60 -> V_63 . V_71 [ 5 ] ) ;
F_5 ( V_70 , V_60 -> V_63 . V_69 ) ;
F_5 ( V_79 , V_60 -> V_63 . V_78 ) ;
F_5 ( V_19 , V_60 -> V_85 ) ;
F_5 ( V_87 , V_60 -> V_63 . V_86 ) ;
F_5 ( V_89 , V_60 -> V_63 . V_88 ) ;
F_5 ( V_83 , V_60 -> V_63 . V_82 ) ;
F_5 ( V_22 , V_60 -> V_84 ) ;
F_5 ( V_91 , V_60 -> V_63 . V_90 ) ;
F_5 ( V_93 , V_60 -> V_63 . V_92 ) ;
F_5 ( V_95 , V_60 -> V_63 . V_94 ) ;
F_5 ( V_81 , V_60 -> V_63 . V_80 ) ;
F_5 ( V_5 , V_60 -> V_63 . V_96 ) ;
F_5 ( V_98 , V_60 -> V_63 . V_97 ) ;
F_5 ( V_100 , V_60 -> V_63 . V_99 ) ;
F_36 ( V_2 ) ;
F_41 ( V_2 ) ;
F_39 (connector, &dev->mode_config.connector_list, head)
V_62 -> V_101 -> V_102 ( V_62 , V_111 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_47 , V_112 , V_57 ;
int V_113 = 5 ;
V_47 = F_33 ( V_10 -> V_49 + V_54 ) ;
V_47 &= ~ V_55 ;
V_47 |= V_114 ;
V_112 = V_55 ;
F_34 ( V_47 , V_10 -> V_49 + V_54 ) ;
while ( V_113 -- ) {
V_57 = F_33 ( V_10 -> V_49 + V_58 ) ;
if ( ( V_57 & V_112 ) == V_115 )
return 0 ;
F_4 ( 10 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_47 , V_112 , V_57 ;
int V_113 = 5 ;
V_47 = F_33 ( V_10 -> V_49 + V_54 ) ;
V_47 &= ~ V_55 ;
V_47 |= V_56 ;
V_112 = V_55 ;
F_34 ( V_47 , V_10 -> V_49 + V_54 ) ;
while ( V_113 -- ) {
V_57 = F_33 ( V_10 -> V_49 + V_58 ) ;
if ( ( V_57 & V_112 ) == V_116 )
return 0 ;
F_4 ( 10 ) ;
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_4 clock ;
struct V_44 * V_45 = F_27 ( 0 , 0 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_28 ( V_45 , 0xD0 , 0xD0050300 ) ;
F_29 ( V_45 , 0xD4 , & clock ) ;
F_30 ( V_45 ) ;
switch ( clock & 0x07 ) {
case 0 :
V_10 -> V_117 = 100 ;
break;
case 1 :
V_10 -> V_117 = 133 ;
break;
case 2 :
V_10 -> V_117 = 150 ;
break;
case 3 :
V_10 -> V_117 = 178 ;
break;
case 4 :
V_10 -> V_117 = 200 ;
break;
case 5 :
case 6 :
case 7 :
V_10 -> V_117 = 266 ;
break;
default:
V_10 -> V_117 = 0 ;
}
}
static void F_46 ( struct V_118 * V_119 )
{
struct V_9 * V_10 = F_47 ( V_119 , struct V_9 ,
V_120 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_50 ( & V_10 -> V_120 ) ;
F_5 ( V_121 , F_6 ( V_121 ) ) ;
return 1 ;
}
static void F_51 ( struct V_1 * V_2 , bool V_122 )
{
if ( V_122 ) {
T_2 V_123 = F_6 ( V_124 ) ;
V_123 |= V_125 | V_126 |
V_127 | V_128 ;
F_5 ( V_124 , V_123 ) ;
} else {
F_5 ( V_124 , 0 ) ;
F_5 ( V_121 , F_6 ( V_121 ) ) ;
}
}
void F_52 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_129 * V_130 ;
int V_48 ;
V_130 = V_10 -> V_131 ;
if ( V_130 == NULL ) {
V_130 = F_53 ( V_2 , V_132 ,
L_5 ,
F_54 ( V_133 ) ) ;
if ( V_130 == NULL )
return;
for ( V_48 = 0 ; V_48 < F_54 ( V_133 ) ; V_48 ++ )
F_55 ( V_130 , V_48 , V_48 - 1 , V_133 [ V_48 ] ) ;
V_10 -> V_131 = V_130 ;
}
F_56 ( & V_62 -> V_134 , V_130 , 0 ) ;
}
void F_57 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_129 * V_130 ;
int V_48 ;
V_130 = V_10 -> V_135 ;
if ( V_130 == NULL ) {
V_130 = F_53 ( V_2 , V_132 ,
L_6 ,
F_54 ( V_136 ) ) ;
if ( V_130 == NULL )
return;
for ( V_48 = 0 ; V_48 < F_54 ( V_136 ) ; V_48 ++ )
F_55 ( V_130 , V_48 , V_48 , V_136 [ V_48 ] ) ;
V_10 -> V_135 = V_130 ;
}
F_56 ( & V_62 -> V_134 , V_130 , 0 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_59 ( & V_10 -> V_120 , F_46 ) ;
if ( F_60 ( V_2 -> V_28 ) )
F_61 ( V_2 -> V_2 , L_7 ) ;
V_10 -> V_137 = V_138 ;
F_45 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_51 ( V_2 , false ) ;
return 0 ;
}
